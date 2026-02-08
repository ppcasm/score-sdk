#!/usr/bin/env python3
"""

This prepends the LaunchApp descriptor/header to an S+Core binary expected by the MGA bratzlife SDCard loader firmware path:

This requires a 16-byte header:
  u32 le: lo32 = payload_size_bytes
  u32 le: hi32 = user-specified (default 0)
  u32 le: 0
  u32 le: 0
then payload bytes.

Usage:
  python <script_name> in.bin -o loader.bin
  python <script_name> in.bin -o loader.bin --hi32 0x00000000
"""

import argparse
import os
import struct
import sys
from pathlib import Path


def parse_u32(x: str) -> int:
    """
    Accepts decimal or hex (0x...) and clamps to uint32.
    """
    v = int(x, 0)
    if not (0 <= v <= 0xFFFFFFFF):
        raise argparse.ArgumentTypeError("value must fit in uint32")
    return v


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("input", type=Path, help="Raw payload binary (S+Core executable)")
    ap.add_argument("-o", "--output", type=Path, required=True, help="Output LaunchApp file")
    ap.add_argument("--hi32", type=parse_u32, default=0, help="High 32 bits of descriptor (default 0)")
    ap.add_argument(
        "--max-size",
        type=parse_u32,
        default=0xFFFFFFFF,
        help="Optional sanity cap on payload size (default 0xFFFFFFFF)",
    )
    args = ap.parse_args()

    payload = args.input.read_bytes()
    size = len(payload)

    if size == 0:
        print("ERROR: input payload is empty", file=sys.stderr)
        return 2
    if size > args.max_size:
        print(f"ERROR: payload size {size} exceeds --max-size {args.max_size}", file=sys.stderr)
        return 2
    if size > 0xFFFFFFFF:
        print("ERROR: payload too large for u32 length", file=sys.stderr)
        return 2

    header = struct.pack("<IIII", size & 0xFFFFFFFF, args.hi32, 0, 0)
    out = header + payload

    tmp = args.output.with_suffix(args.output.suffix + ".tmp")
    tmp.write_bytes(out)
    os.replace(tmp, args.output)

    print(f"Wrote: {args.output}")
    print(f"Payload bytes: {size} (0x{size:08X})")
    print(f"Descriptor lo32 (len): 0x{size:08X}")
    print(f"Descriptor hi32      : 0x{args.hi32:08X}")
    print("Header is 16 bytes, little-endian u32 words.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
