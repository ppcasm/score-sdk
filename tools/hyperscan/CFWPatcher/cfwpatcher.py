#!/usr/bin/env python3
import argparse
from dataclasses import dataclass, field
from pathlib import Path
from datetime import datetime
import sys
import serial

CHUNK_SIZE_DEFAULT = 1

FW_BASE_DEFAULT = 0xA00001FC
REV_STRING_ADDR_DEFAULT = 0xA00383E4
CHECKSUM_PATCH_ADDR_DEFAULT = 0xA0012638
DEFAULT_REV_STRING = "UMOD 0.1 NTSC"


def resolve_address(addr: int, fw_base: int) -> int:
    return addr - fw_base


def write_u32_le(buf: bytearray, offset: int, value: int) -> None:
    if offset < 0 or offset + 4 > len(buf):
        raise ValueError(f"write_u32_le OOB: off=0x{offset:X} len=0x{len(buf):X}")
    buf[offset:offset + 4] = value.to_bytes(4, "little", signed=False)


def show_progress(sent: int, total: int) -> None:
    pct = int((sent / total) * 100) if total else 100
    sys.stdout.write(f"\rUploading: {pct}%")
    sys.stdout.flush()


def uart_upload(
    port: str,
    data: bytes,
    baud: int = 115200,
    parity: str = "E",
    stopbits: int = 1,
    chunk_size: int = CHUNK_SIZE_DEFAULT,
) -> None:
    with serial.Serial(port, baudrate=baud, parity=parity, stopbits=stopbits, timeout=5) as ser:
        total = len(data)

        ser.write(total.to_bytes(4, "little", signed=False))
        ser.flush()
        _ = ser.read(1)

        start = datetime.now()
        sent = 0
        for i in range(0, total, chunk_size):
            ser.write(data[i:i + chunk_size])
            ser.flush()
            sent = min(i + chunk_size, total)
            show_progress(sent, total)

        print()
        print("Time elapsed:", str(datetime.now() - start).split(".")[0])


def patch_byte(fw: bytearray, fw_base: int, addr: int, value: int) -> None:
    off = resolve_address(addr, fw_base)

    if off < 0 or off >= len(fw):
        raise ValueError(
            f"Byte patch OOB: addr=0x{addr:08X} off=0x{off:X}"
        )

    fw[off] = value & 0xFF

def patch_fw_revision(fw: bytearray, fw_base: int, rev_addr: int, new_rev: str) -> None:
    off = resolve_address(rev_addr, fw_base)
    data = new_rev.encode("ascii", errors="strict")
    if off < 0 or off + len(data) > len(fw):
        raise ValueError(f"Revision patch OOB: addr=0x{rev_addr:08X} off=0x{off:X}")
    fw[off:off + len(data)] = data


def patch_checksum_bypass(fw: bytearray, fw_base: int, patch_addr: int) -> None:
    patch_byte(fw, fw_base, patch_addr, 0x00)


def asm_j_insn(target_addr: int, link: bool) -> int:
    assembled_insn_l = (target_addr & 0x7FFF)
    assembled_insn_l |= (1 << 15)  # p-bit

    assembled_insn_h = ((target_addr << 1) & 0x1FFF0000)
    assembled_insn_h |= (1 << 31)
    assembled_insn_h |= (1 << 27)

    insn = (assembled_insn_h & 0xFFFF0000) | (assembled_insn_l & 0xFFFF)
    insn = (insn + (1 if link else 0)) & 0xFFFFFFFF
    return insn


def patch_jump(fw: bytearray, fw_base: int, patch_addr: int, target_addr: int, link: bool) -> None:
    off = resolve_address(patch_addr, fw_base)
    if off < 0 or off + 4 > len(fw):
        raise ValueError(f"Jump patch OOB: addr=0x{patch_addr:08X} off=0x{off:X}")
    insn = asm_j_insn(target_addr, link)
    write_u32_le(fw, off, insn)


def inject_blob(fw: bytearray, fw_base: int, addr: int, blob: bytes) -> None:
    off = resolve_address(addr, fw_base)
    end = off + len(blob)
    if off < 0 or end > len(fw):
        raise ValueError(
            f"Inject OOB: addr=0x{addr:08X} off=0x{off:X} end=0x{end:X} fw_len=0x{len(fw):X}"
        )
    fw[off:end] = blob


@dataclass
class Injection:
    path: Path
    addr: int

@dataclass
class JumpPatch:
    patch_addr: int
    target_addr: int
    link: bool  # jl if True else j


def parse_inject(spec: str) -> Injection:
    """
    Parse:  file.bin@0xA00F5D00
    """
    if "@" not in spec:
        raise argparse.ArgumentTypeError("Inject format must be FILE@ADDR (e.g., payload.bin@0xA00F5D00)")
    file_s, addr_s = spec.rsplit("@", 1)
    p = Path(file_s)
    if not p.is_file():
        raise argparse.ArgumentTypeError(f"Inject file not found: {file_s}")
    try:
        addr = int(addr_s, 0)
    except ValueError:
        raise argparse.ArgumentTypeError(f"Bad address in inject: {addr_s}")
    return Injection(path=p, addr=addr)


def parse_jump(spec: str) -> JumpPatch:
    """
    Parse:
      0xA0012360->0xA00F5D00
      0xA0012360->0xA00F5D00:jl
      0xA0012360->0xA00F5D00:j
    Default is :j (no link) unless :jl specified.
    """
    mode = "j"
    if ":" in spec:
        spec, mode = spec.rsplit(":", 1)
        mode = mode.strip().lower()
        if mode not in ("j", "jl"):
            raise argparse.ArgumentTypeError("Jump mode must be :j or :jl")

    if "->" not in spec:
        raise argparse.ArgumentTypeError("Jump format must be PATCH_ADDR->TARGET_ADDR[:j|:jl]")

    a_s, b_s = spec.split("->", 1)
    try:
        patch_addr = int(a_s.strip(), 0)
        target_addr = int(b_s.strip(), 0)
    except ValueError:
        raise argparse.ArgumentTypeError("Bad address in jump spec (use 0x... or decimal)")

    return JumpPatch(patch_addr=patch_addr, target_addr=target_addr, link=(mode == "jl"))


def apply_all_patches(
    ofw_bytes: bytes,
    fw_base: int,
    change_rev: bool,
    rev_addr: int,
    rev_string: str,
    checksum_patch: bool,
    checksum_addr: int,
    injections: list[Injection],
    jumps: list[JumpPatch],
) -> bytes:
    fw = bytearray(ofw_bytes)

    if change_rev:
        print(f'Changing FW revision to "{rev_string}" @ 0x{rev_addr:08X}')
        patch_fw_revision(fw, fw_base, rev_addr, rev_string)

    if checksum_patch:
        print(f"Applying checksum bypass @ 0x{checksum_addr:08X}")
        patch_checksum_bypass(fw, fw_base, checksum_addr)

    # Apply injections first (so jumps can target injected code confidently)
    for inj in injections:
        blob = inj.path.read_bytes()
        print(f"Inject {inj.path} ({len(blob)} bytes) @ 0x{inj.addr:08X}")
        inject_blob(fw, fw_base, inj.addr, blob)

    # Apply jump patches
    for jp in jumps:
        jtype = "jl" if jp.link else "j"
        print(f"Patch {jtype} 0x{jp.target_addr:08X} @ 0x{jp.patch_addr:08X}")
        patch_jump(fw, fw_base, jp.patch_addr, jp.target_addr, jp.link)

    return bytes(fw)


def build_argparser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser(
        prog="patcher.py",
        description="Mattel HyperScan Firmware Patcher Utility (multi-inject + multi-jump)",
    )

    sub = p.add_subparsers(dest="mode", required=True)

    def add_common(sp: argparse.ArgumentParser) -> None:
        sp.add_argument("ofw", type=Path, help="OFW.bin (RAM portion)")
        sp.add_argument("--fw-base", type=lambda s: int(s, 0), default=FW_BASE_DEFAULT,
                        help=f"RAM address corresponding to file offset 0 (default: 0x{FW_BASE_DEFAULT:08X})")

        sp.add_argument("--no-rev", action="store_true", help="Disable firmware revision patch")
        sp.add_argument("--rev-string", default=DEFAULT_REV_STRING, help=f"Revision string (default: {DEFAULT_REV_STRING})")
        sp.add_argument("--rev-addr", type=lambda s: int(s, 0), default=REV_STRING_ADDR_DEFAULT,
                        help=f"Revision string address (default: 0x{REV_STRING_ADDR_DEFAULT:08X})")

        sp.add_argument("--no-checksum", action="store_true", help="Disable checksum bypass patch")
        sp.add_argument("--checksum-addr", type=lambda s: int(s, 0), default=CHECKSUM_PATCH_ADDR_DEFAULT,
                        help=f"Checksum patch address (default: 0x{CHECKSUM_PATCH_ADDR_DEFAULT:08X})")

        # Repeatable injection(s)
        sp.add_argument(
            "--inject",
            action="append",
            type=parse_inject,
            default=[],
            metavar="FILE@ADDR",
            help="Inject binary at RAM address, e.g. --inject foo.bin@0xA00F5D00",
        )

        # Repeatable jump patch(es)
        sp.add_argument(
            "--jump",
            action="append",
            type=parse_jump,
            default=[],
            metavar="PATCH->TARGET[:j|:jl]",
            help="Patch J/JL at PATCH to jump to TARGET, e.g. --jump 0xA0012360->0xA00F5D00:jl",
        )

    sp_uart = sub.add_parser("uart", help="Upload patched firmware via UART")
    add_common(sp_uart)
    sp_uart.add_argument("port", help="Serial port (COM3 or /dev/ttyUSB0)")
    sp_uart.add_argument("--baud", type=int, default=115200)
    sp_uart.add_argument("--parity", default="E", choices=["N", "E", "O", "M", "S"])
    sp_uart.add_argument("--stopbits", type=int, default=1, choices=[1, 2])
    sp_uart.add_argument("--chunk", type=int, default=CHUNK_SIZE_DEFAULT, help="Write chunk size (default: 1)")

    sp_file = sub.add_parser("file", help="Write patched firmware to a file (CFW.bin)")
    add_common(sp_file)
    sp_file.add_argument("out", type=Path, help="Output file path (e.g., CFW.bin)")

    return p


def main() -> int:
    args = build_argparser().parse_args()

    if not args.ofw.is_file():
        raise SystemExit(f"OFW not found: {args.ofw}")

    ofw_bytes = args.ofw.read_bytes()

    patched = apply_all_patches(
        ofw_bytes=ofw_bytes,
        fw_base=args.fw_base,
        change_rev=not args.no_rev,
        rev_addr=args.rev_addr,
        rev_string=args.rev_string,
        checksum_patch=not args.no_checksum,
        checksum_addr=args.checksum_addr,
        injections=args.inject,
        jumps=args.jump,
    )

    if args.mode == "file":
        args.out.write_bytes(patched)
        print(f"Custom Firmware saved as {args.out}")
        return 0

    if args.mode == "uart":
        uart_upload(
            port=args.port,
            data=patched,
            baud=args.baud,
            parity=args.parity,
            stopbits=args.stopbits,
            chunk_size=args.chunk,
        )
        return 0

    return 1


if __name__ == "__main__":
    raise SystemExit(main())