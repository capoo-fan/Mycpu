#!/usr/bin/env python3

"""Extract and disassemble the four supervisor performance programs."""

import argparse
import hashlib
import subprocess
from pathlib import Path


KERNEL_BASE = 0x1C000000
TEST_RANGES = (
    ("stream", "UTEST_STREAM", "UTEST_MATRIX"),
    ("matrix", "UTEST_MATRIX", "UTEST_CRYPTONIGHT"),
    ("cryptonight", "UTEST_CRYPTONIGHT", "UTEST_MIXED"),
    ("mixed", "UTEST_MIXED", "FLUSH_DCACHE"),
)


def command_output(command):
    return subprocess.run(
        command,
        check=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    ).stdout


def read_symbols(nm, elf):
    symbols = {}
    for line in command_output([nm, "-n", str(elf)]).splitlines():
        fields = line.split()
        if len(fields) >= 3:
            try:
                symbols[fields[2]] = int(fields[0], 16)
            except ValueError:
                pass
    return symbols


def main():
    parser = argparse.ArgumentParser(
        description="Extract UTEST binaries and generate LA32R disassembly."
    )
    parser.add_argument("--elf", type=Path, required=True)
    parser.add_argument("--kernel-bin", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    parser.add_argument("--nm", default="loongarch32r-linux-gnusf-nm")
    parser.add_argument("--objdump", default="loongarch32r-linux-gnusf-objdump")
    args = parser.parse_args()

    elf = args.elf.resolve()
    kernel_bin = args.kernel_bin.resolve()
    output_dir = args.output_dir.resolve()
    output_dir.mkdir(parents=True, exist_ok=True)

    image = kernel_bin.read_bytes()
    symbols = read_symbols(args.nm, elf)
    manifest = ["name start end size sha256\n"]

    for name, start_symbol, end_symbol in TEST_RANGES:
        if start_symbol not in symbols or end_symbol not in symbols:
            raise SystemExit(f"missing symbol: {start_symbol} or {end_symbol}")
        start = symbols[start_symbol]
        end = symbols[end_symbol]
        if start < KERNEL_BASE or end <= start:
            raise SystemExit(f"invalid range for {name}: 0x{start:x}-0x{end:x}")

        start_offset = start - KERNEL_BASE
        end_offset = end - KERNEL_BASE
        if end_offset > len(image):
            raise SystemExit(
                f"{name} range exceeds kernel.bin: 0x{end_offset:x} > 0x{len(image):x}"
            )

        binary = image[start_offset:end_offset]
        binary_path = output_dir / f"{name}.bin"
        disasm_path = output_dir / f"{name}.disasm"
        binary_path.write_bytes(binary)

        disassembly = command_output(
            [
                args.objdump,
                "-d",
                f"--start-address=0x{start:x}",
                f"--stop-address=0x{end:x}",
                str(elf),
            ]
        )
        disasm_path.write_text(disassembly, encoding="utf-8")

        digest = hashlib.sha256(binary).hexdigest()
        manifest.append(
            f"{name} {start:08x} {end:08x} {len(binary):#x} {digest}\n"
        )
        print(
            f"{name:11s} 0x{start:08x}-0x{end:08x} "
            f"({len(binary)} bytes) -> {disasm_path.name}"
        )

    (output_dir / "MANIFEST.txt").write_text("".join(manifest), encoding="ascii")


if __name__ == "__main__":
    main()

