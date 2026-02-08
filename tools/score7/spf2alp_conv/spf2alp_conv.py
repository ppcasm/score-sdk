#!/usr/bin/env python3
#####################################################
# SPF2ALP Converter - ppcasm (ppcasm@gmail.com)     #
#                                                   #
# Converts Sunplus/Genplus DRM audio into WAV using #
# a3600.dll (a3600_dec)                             #
#                                                   #
# Run with 32-bit python3 on Windows:               #
#   py -32 spf2alp_conv.py <input.bin> <out_dir>    #
#####################################################

import os
import sys
import struct
import ctypes
from enum import IntEnum
from ctypes import c_char_p, c_int, c_void_p

# ---- Enforce 32-bit Python ----
if struct.calcsize("P") != 4:
    print("ERROR: This script MUST be run with 32-bit Python.")
    print("Current Python:", sys.executable)
    print("Try: py -32 spf2alp_conv.py <input.bin> <out_dir>")
    sys.exit(1)

MAGIC_HEADER = b"SPF2ALP"
FIELD_COUNT = 5  # UNK1, UNK2, SR, SIZE, UNK4

# DEBUGGING: Map file offsets to Ghidra addresses
GHIDRA_BASE = 0x9FFFC1FC

class Spf2AlpIdx(IntEnum):
    UNK1 = 0
    UNK2 = 1
    SR   = 2    # sample rate (11025/16000/22050)
    SIZE = 3    # appears to be sample units that need *2 to become bytes
    UNK4 = 4


def ensure_dir(path: str) -> None:
    os.makedirs(path, exist_ok=True)


def load_a3600_dll():
    """
    Loads a3600.dll from the same folder as this script.
    Binds: int a3600_dec(char *inFile, char *outFile, int unknown, void *processor);
    Tries cdecl first, then stdcall.
    """
    script_dir = os.path.dirname(os.path.abspath(__file__))
    dll_path = os.path.join(script_dir, "a3600.dll")

    if not os.path.exists(dll_path):
        raise FileNotFoundError(f"Could not find DLL at: {dll_path}")

    try:
        os.add_dll_directory(script_dir)
    except Exception:
        pass

    last_err = None
    for loader in (ctypes.CDLL, ctypes.WinDLL):
        try:
            lib = loader(dll_path)
            func = lib.a3600_dec
            func.argtypes = [c_char_p, c_char_p, c_int, c_void_p]
            func.restype = c_int
            return lib, func, ("cdecl" if loader is ctypes.CDLL else "stdcall")
        except Exception as e:
            last_err = e

    raise RuntimeError(f"Failed to load a3600.dll / resolve a3600_dec: {last_err}")


def call_a3600_dec(a3600_dec_func, in_path: str, out_path: str) -> int:
    """
    Calls decoder as requested: unknown=0, processor=NULL
    """
    in_b = os.fspath(in_path).encode("utf-8")
    out_b = os.fspath(out_path).encode("utf-8")
    return a3600_dec_func(in_b, out_b, 0, None)


def patch_wav_header_inplace(wav_path: str, desired_sr: int) -> None:
    """
    Fixes broken WAVs produced by the DLL where RIFF size and data size are 0
    Also overwrites sample rate (and recomputes byte rate) to desired_sr
    Assumes standard PCM header layout: RIFF/WAVE/fmt(16)/data
    """

    with open(wav_path, "r+b") as f:
        blob = f.read()

        if len(blob) < 44:
            raise RuntimeError("WAV too small to patch")

        if blob[0:4] != b"RIFF" or blob[8:12] != b"WAVE":
            raise RuntimeError("Not a RIFF/WAVE file (unexpected header)")

        if blob[12:16] != b"fmt ":
            # Still salvageable, but this script expects classic layout
            raise RuntimeError("Unexpected WAV layout (fmt chunk not at 12)")

        fmt_size = struct.unpack_from("<I", blob, 16)[0]
        if fmt_size < 16:
            raise RuntimeError("Invalid fmt chunk size")

        audio_fmt = struct.unpack_from("<H", blob, 20)[0]
        channels  = struct.unpack_from("<H", blob, 22)[0]
        sampwidth_bits = struct.unpack_from("<H", blob, 34)[0]
        block_align = struct.unpack_from("<H", blob, 32)[0]

        # Find the 'data' chunk (don’t assume fixed offset, but typical is 36)
        data_pos = blob.find(b"data")
        if data_pos == -1:
            raise RuntimeError("No data chunk found")

        # Data chunk layout: 'data' + u32 size + raw data
        data_size_field = data_pos + 4
        data_start = data_pos + 8

        file_size = len(blob)
        data_size = max(0, file_size - data_start)
        riff_size = file_size - 8

        # Patch RIFF chunk size (offset 4)
        f.seek(4)
        f.write(struct.pack("<I", riff_size))

        # Patch sample rate (offset 24)
        f.seek(24)
        f.write(struct.pack("<I", int(desired_sr)))

        # Patch byte rate (offset 28) sr * block_align
        byte_rate = int(desired_sr) * int(block_align)
        f.seek(28)
        f.write(struct.pack("<I", byte_rate))

        # Patch data chunk size
        f.seek(data_size_field)
        f.write(struct.pack("<I", data_size))

        # print(f"Patched WAV: fmt={audio_fmt} ch={channels} bits={sampwidth_bits} "
        #       f"block_align={block_align} sr={desired_sr} data={data_size}")


def scan_and_convert(in_bin_path: str, out_dir: str, a3600_dec_func):
    ensure_dir(out_dir)

    with open(in_bin_path, "rb") as f:
        data = f.read()

    offset = 0
    pat_len = len(MAGIC_HEADER)
    found = 0
    converted = 0

    while True:
        idx = data.find(MAGIC_HEADER, offset)
        if idx == -1:
            break

        found += 1
        ghidra_addr = GHIDRA_BASE + idx

        null_pos = idx + pat_len
        base_pos = null_pos + 1  # Expects SPF2ALP\0 in file
        needed = base_pos + (FIELD_COUNT * 4)

        print(f"\nFound at file 0x{idx:08X} (GHIDRA: 0x{ghidra_addr:08X})")

        if null_pos >= len(data):
            print("  WARN: magic at EOF; skipping")
            offset = idx + 1
            continue

        if data[null_pos] != 0x00:
            print(f"  WARN: byte after magic is 0x{data[null_pos]:02X} (expected 0x00)")

        if needed > len(data):
            print("  Not enough data for fields; skipping")
            offset = idx + 1
            continue

        # Read 5 u32 fields
        fields = []
        for i in range(FIELD_COUNT):
            pos = base_pos + i * 4
            fields.append(struct.unpack_from("<I", data, pos)[0])

        sr = fields[Spf2AlpIdx.SR]
        size_units = fields[Spf2AlpIdx.SIZE]
        size_bytes = size_units * 2  # <-- per your hypothesis

        labels = ["UNK1", "UNK2", "SR", "SIZE", "UNK4"]
        for i, v in enumerate(fields):
            pos = base_pos + i * 4
            print(f"  {labels[i]:>4} @ 0x{pos:08X} = 0x{v:08X} ({v})")

        # Still not sure here
        # start at SIZE field
        size_pos = base_pos + (Spf2AlpIdx.SIZE * 4)
        start = size_pos
        end = start + size_bytes

        print(f"  Slice start = 0x{start:08X} (SIZE field offset)")
        print(f"  SIZE units = {size_units} -> bytes = {size_bytes}")
        print(f"  Slice end   = 0x{end:08X}")
        print(f"  Patch output WAV SR to {sr}")

        if size_units == 0:
            print("  WARN: SIZE is 0; skipping")
            offset = idx + 1
            continue

        if end > len(data):
            print("  WARN: slice exceeds file bounds; skipping")
            offset = idx + 1
            continue

        base_name = f"chunk_{found:05d}_off_{idx:08X}"
        tmp_in = os.path.join(out_dir, base_name + ".bin")
        tmp_wav = os.path.join(out_dir, base_name + "_raw.wav")
        final_wav = os.path.join(out_dir, base_name + f"_{sr}Hz.wav")

        with open(tmp_in, "wb") as f:
            f.write(data[start:end])

        try:
            rc = call_a3600_dec(a3600_dec_func, tmp_in, tmp_wav)
            print(f"  a3600_dec rc = {rc}")
        except OSError as e:
            print(f"  ERROR: DLL crashed/failed: {e}")
            offset = idx + 1
            continue

        if not os.path.exists(tmp_wav):
            print("  WARN: decoder produced no output WAV; skipping")
            offset = idx + 1
            continue

        try:
            # Patch the broken header and set correct sample rate
            # (writes the final WAV by copying then patching)
            with open(tmp_wav, "rb") as r, open(final_wav, "wb") as w:
                w.write(r.read())

            patch_wav_header_inplace(final_wav, sr)
            print(f"  Wrote: {final_wav} ({os.path.getsize(final_wav)} bytes)")
            converted += 1
        except Exception as e:
            print(f"  ERROR: Failed to patch WAV header: {e}")
            print(f"  Keeping raw output at: {tmp_wav}")

        offset = idx + 1

    print(f"\nDone. Found {found} headers, converted {converted}.")


def main():
    if len(sys.argv) != 3:
        print(f"Usage: py -32 {os.path.basename(sys.argv[0])} <input.bin> <out_dir>")
        sys.exit(1)

    in_bin = sys.argv[1]
    out_dir = sys.argv[2]

    _, a3600_dec, cc = load_a3600_dll()
    print(f"Loaded a3600.dll using {cc} calling convention")

    scan_and_convert(in_bin, out_dir, a3600_dec)


if __name__ == "__main__":
    main()
