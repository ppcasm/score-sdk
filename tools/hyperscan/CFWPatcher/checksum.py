#!/usr/bin/env python3
import sys

BASE = 0xA00001FC  # file offset 0 corresponds to this address

# Checksum ranges (end exclusive)
R1_START, R1_END = 0xA0001000, 0xA0035540
R2_START, R2_END = 0xA0070000, 0xA00F5B50

# Where firmware stores expected checksum (DAT_a006ffe0)
EXPECTED_ADDR = 0xA006FFE0

def u32(x): return x & 0xFFFFFFFF

def rd_u32_le(buf, addr):
    off = addr - BASE
    if off < 0 or off + 4 > len(buf):
        raise RuntimeError(f"OOB read: addr={addr:#x}, off={off:#x}, size={len(buf):#x}")
    return int.from_bytes(buf[off:off+4], "little", signed=False)

def sum_range(buf, start, end):
    total = 0
    for addr in range(start, end, 4):
        total = u32(total + rd_u32_le(buf, addr))
    return total

def peek_ascii(buf, addr, n=24):
    off = addr - BASE
    if off < 0 or off >= len(buf):
        return "<out of bounds>"
    chunk = buf[off:off+n]
    return "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} dump.bin")
        return 2

    data = open(sys.argv[1], "rb").read()

    # Ensure the dump covers the checksum ranges
    required_end_off = R2_END - BASE
    if required_end_off > len(data):
        print("ERROR: dump too small for checksum ranges")
        print(f"  dump size    : {len(data):#x}")
        print(f"  need >= off  : {required_end_off:#x}  (to reach addr {R2_END:#x})")
        return 2

    expected_dump = rd_u32_le(data, EXPECTED_ADDR)

    sum1 = sum_range(data, R1_START, R1_END)
    sum2 = sum_range(data, R2_START, R2_END)
    summed = u32(sum1 + sum2)
    computed = u32(~summed)

    print("=== SYSTEM CHECKSUM (corrected base) ===")
    print(f"Dump file       : {sys.argv[1]}")
    print(f"Base addr       : {BASE:#010x}  (file offset 0)")
    print("")
    print(f'Peek @ R1_END   : {R1_END:#010x} -> "{peek_ascii(data, R1_END)}"')
    print("")
    print(f"Range 1 sum     : {sum1:#010x}")
    print(f"Range 2 sum     : {sum2:#010x}")
    print(f"Combined sum    : {summed:#010x}")
    print(f"Computed ~sum   : {computed:#010x}")
    print("")
    print(f"Expected (dump) : {expected_dump:#010x}  (read @ {EXPECTED_ADDR:#010x})")
    print(f"Expected (known): 0x94e05e9c")
    print("")
    print("RESULT vs dump expected:", "PASS" if computed == expected_dump else "FAIL")
    print("RESULT vs 0x94E05E9C  :", "PASS" if computed == 0x94E05E9C else "FAIL")

    return 0 if computed == expected_dump else 1

if __name__ == "__main__":
    raise SystemExit(main())
