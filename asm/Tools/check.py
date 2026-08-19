#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
check.py - 检查 LoongArch/LA32R 汇编文件是否使用了当前 myCPU 不支持的指令。

推荐用法：
    python3 check.py --input 2025.asm
    python3 check.py -i 2025.asm
    python3 check.py --input asm/
    python3 check.py -i a.s -i b.asm
    python3 check.py -i 2025.asm --list-supported
    python3 check.py -i 2025.asm --strict
    python3 check.py -i 2025.asm --decoder ~/Mycpu/myCPU/inst_decoder.v

退出码：
    0  未发现不支持指令
    1  发现不支持/无法确认的指令
    2  参数、输入文件或 decoder 读取错误

设计原则：
1. 优先从最终参赛 CPU 的 myCPU/inst_decoder.v 中 inst_known 自动提取支持列表。
2. 不读取 mycpu_ref；参考 CPU 不能作为参赛 CPU 的支持列表。
3. 如果找不到 decoder，则回退到脚本内置的当前 myCPU 白名单。
4. 支持 .s / .S / .asm / .disasm。
5. 默认允许能安全展开成已支持真实指令的常见伪指令；--strict 会把伪指令也报告出来。
"""

from __future__ import annotations

import argparse
import re
import sys
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


# ---------------------------------------------------------------------------
# 当前 myCPU 回退白名单
#
# 依据当前最终参赛 CPU 的 inst_decoder.v -> inst_known。
# 若能读取真实 inst_decoder.v，则以 RTL 自动提取结果为准。
# ---------------------------------------------------------------------------

FALLBACK_SUPPORTED = {
    # 算术 / 比较
    "add.w", "addi.w", "sub.w",
    "slt", "sltu", "slti", "sltui",

    # 逻辑
    "nor", "and", "or", "xor",
    "andi", "ori", "xori",

    # 移位
    "sll.w", "srl.w", "sra.w",
    "slli.w", "srli.w", "srai.w",

    # 高位立即数 / PC 相对
    "lu12i.w", "pcaddu12i",

    # 乘法
    "mul.w",

    # Load / Store
    "ld.b", "ld.bu", "ld.h", "ld.hu", "ld.w",
    "st.b", "st.h", "st.w",

    # 分支 / 跳转
    "b", "bl", "jirl",
    "beq", "bne", "blt", "bge", "bltu", "bgeu",

    # 系统 / Cache / CSR
    "cpucfg", "cacop", "csrwr", "csrxchg",
}


# ---------------------------------------------------------------------------
# 常见安全伪指令
#
# key: 汇编中出现的伪指令
# value: 汇编器展开后所依赖的“真实指令集合”
# ---------------------------------------------------------------------------

PSEUDO_REQUIREMENTS = {
    "move": {"or"},
    "jr": {"jirl"},
    "ret": {"jirl"},

    "beqz": {"beq"},
    "bnez": {"bne"},
    "bltz": {"blt"},
    "bgez": {"bge"},
    "bgtz": {"blt"},
    "blez": {"bge"},

    "bgt": {"blt"},
    "ble": {"bge"},
    "bgtu": {"bltu"},
    "bleu": {"bgeu"},

    "li": {"addi.w", "ori", "lu12i.w"},
    "li.w": {"addi.w", "ori", "lu12i.w"},

    "neg": {"sub.w"},
    "not": {"nor"},

    # GNU assembler 常见展开可由普通立即数/逻辑指令实现。
    "nop": {"andi"},
}


SOURCE_EXTENSIONS = {".s", ".S", ".asm", ".disasm"}

# 这些 directive 可能直接把机器码塞入 text 段。
# 仅靠助记符检查无法确认其中是否隐藏了 CPU 不支持的编码。
RAW_ENCODING_DIRECTIVES = {".word", ".long", ".4byte", ".inst"}


@dataclass
class Issue:
    lineno: int
    mnemonic: str
    raw: str
    reason: str


@dataclass
class FileResult:
    filename: Path
    used: Counter
    native: Counter
    pseudo: Counter
    issues: list[Issue]
    raw_encoding_lines: list[tuple[int, str]]


def rtl_name_to_mnemonic(name: str) -> str:
    """
    把 RTL 信号名转换成汇编助记符。

    例如：
        inst_add_w      -> add.w
        inst_ld_bu      -> ld.bu
        inst_mul_w      -> mul.w
        inst_pcaddu12i  -> pcaddu12i
    """
    if name.startswith("inst_"):
        name = name[5:]

    # 从长后缀开始匹配，避免 _wu 被 _w 干扰。
    suffixes = ("_wu", "_bu", "_hu", "_w", "_d", "_b", "_h")

    for suffix in suffixes:
        if name.endswith(suffix):
            return name[:-len(suffix)] + "." + suffix[1:]

    return name


def extract_supported_from_decoder(decoder: Path) -> set[str]:
    """
    从 inst_decoder.v 中：
        wire inst_known = ...;
    或：
        assign inst_known = ...;
    自动提取 inst_xxx 信号并转换为助记符。
    """
    text = decoder.read_text(encoding="utf-8", errors="ignore")

    match = re.search(
        r"\b(?:wire\s+|assign\s+)?inst_known\s*=\s*(.*?);",
        text,
        flags=re.S,
    )
    if not match:
        raise ValueError(
            f"{decoder}: 找不到 inst_known = ... ;，无法自动提取支持指令"
        )

    rtl_names = re.findall(r"\binst_[A-Za-z0-9_]+\b", match.group(1))

    supported = {
        rtl_name_to_mnemonic(name).lower()
        for name in rtl_names
        if name != "inst_known"
    }

    if not supported:
        raise ValueError(f"{decoder}: inst_known 中没有提取到任何指令")

    return supported


def path_is_reference_cpu(path: Path) -> bool:
    return any(part.lower() == "mycpu_ref" for part in path.parts)


def find_default_decoder() -> Path | None:
    """
    自动寻找最终 myCPU 的 inst_decoder.v。
    明确不使用 mycpu_ref。
    """
    script_dir = Path(__file__).resolve().parent

    candidates = [
        Path.home() / "Mycpu" / "myCPU" / "inst_decoder.v",
        Path.home() / "MyCPU" / "myCPU" / "inst_decoder.v",

        Path.cwd() / "myCPU" / "inst_decoder.v",
        Path.cwd() / "src" / "soc" / "inst_decoder.v",
        Path.cwd() / "src" / "soc" / "myCPU" / "inst_decoder.v",

        script_dir / ".." / "myCPU" / "inst_decoder.v",
        script_dir / ".." / "src" / "soc" / "inst_decoder.v",
        script_dir / ".." / "src" / "soc" / "myCPU" / "inst_decoder.v",
    ]

    seen = set()
    for candidate in candidates:
        candidate = candidate.expanduser().resolve()
        if candidate in seen:
            continue
        seen.add(candidate)

        if path_is_reference_cpu(candidate):
            continue

        if candidate.is_file():
            return candidate

    return None


def load_supported(decoder_arg: Path | None) -> tuple[set[str], str]:
    """
    返回：
        supported: CPU 原生支持指令集合
        source:    支持列表来源说明
    """
    if decoder_arg is not None:
        decoder = decoder_arg.expanduser().resolve()

        if path_is_reference_cpu(decoder):
            raise ValueError(
                "--decoder 指向 mycpu_ref。该脚本只允许分析最终参赛 myCPU，"
                "不能用参考 CPU 的指令集代替。"
            )

        if not decoder.is_file():
            raise FileNotFoundError(f"decoder 不存在: {decoder}")

        supported = extract_supported_from_decoder(decoder)
        return supported, f"RTL 自动提取: {decoder}"

    decoder = find_default_decoder()
    if decoder is not None:
        try:
            supported = extract_supported_from_decoder(decoder)
            return supported, f"RTL 自动提取: {decoder}"
        except (OSError, ValueError) as exc:
            print(f"[WARN] 自动读取 decoder 失败: {exc}", file=sys.stderr)

    return set(FALLBACK_SUPPORTED), "脚本内置回退白名单（当前 myCPU）"


def remove_block_comments(text: str) -> str:
    return re.sub(r"/\*.*?\*/", "", text, flags=re.S)


def remove_line_comment(line: str) -> str:
    """
    去掉常见行注释：
        # ...
        // ...
    """
    hash_pos = line.find("#")
    slash_pos = line.find("//")

    positions = [p for p in (hash_pos, slash_pos) if p >= 0]
    if positions:
        return line[:min(positions)]

    return line


LABEL_RE = re.compile(
    r"^\s*(?:[A-Za-z_.$][A-Za-z0-9_.$]*|\d+)\s*:\s*"
)

DISASM_RE = re.compile(
    r"^\s*[0-9a-fA-F]+:\s+"
    r"(?:[0-9a-fA-F]{8}|[0-9a-fA-F]{2}(?:\s+[0-9a-fA-F]{2}){3})"
    r"\s+([A-Za-z_.$][A-Za-z0-9_.$]*)"
)

TOKEN_RE = re.compile(r"^([A-Za-z_.$][A-Za-z0-9_.$]*)")


def collect_macro_names(text: str) -> set[str]:
    macros = set()
    for line in text.splitlines():
        match = re.match(
            r"^\s*\.macro\s+([A-Za-z_.$][A-Za-z0-9_.$]*)",
            line,
            flags=re.I,
        )
        if match:
            macros.add(match.group(1).lower())
    return macros


def detect_raw_encoding_directive(line: str) -> str | None:
    clean = remove_line_comment(line).strip()
    if not clean:
        return None

    # 去掉 label
    while True:
        match = LABEL_RE.match(clean)
        if not match:
            break
        clean = clean[match.end():].strip()
        if not clean:
            return None

    token_match = TOKEN_RE.match(clean)
    if not token_match:
        return None

    token = token_match.group(1).lower()
    if token in RAW_ENCODING_DIRECTIVES:
        return token

    return None


def parse_instruction(line: str, macros: set[str]) -> str | None:
    """
    从一行源码/反汇编中提取助记符。
    返回 None 表示不是普通指令行。
    """
    line = remove_line_comment(line).strip()
    if not line:
        return None

    # objdump:
    # 1c002018: 2880008c   ld.w   $r12,$r4,0
    match = DISASM_RE.match(line)
    if match:
        return match.group(1).lower()

    # 去掉一个或多个 label
    while True:
        match = LABEL_RE.match(line)
        if not match:
            break
        line = line[match.end():].strip()
        if not line:
            return None

    # assembler directive
    if line.startswith("."):
        return None

    # symbol = ...
    if re.match(r"^[A-Za-z_.$][A-Za-z0-9_.$]*\s*=", line):
        return None

    match = TOKEN_RE.match(line)
    if not match:
        return None

    token = match.group(1).lower()

    # 用户自定义宏调用不是 CPU 助记符。
    # 宏定义内部的真实指令仍会被逐行检查。
    if token in macros:
        return None

    return token


def pseudo_status(
    mnemonic: str,
    supported: set[str],
) -> tuple[bool, set[str], set[str]]:
    """
    返回：
        known_pseudo
        required_real_insts
        missing_real_insts
    """
    required = PSEUDO_REQUIREMENTS.get(mnemonic)
    if required is None:
        return False, set(), set()

    missing = required - supported
    return True, required, missing


def iter_input_files(inputs: Iterable[Path]) -> list[Path]:
    files: list[Path] = []

    for input_path in inputs:
        path = input_path.expanduser()

        if not path.exists():
            print(f"[ERROR] 输入不存在: {path}", file=sys.stderr)
            continue

        if path.is_file():
            files.append(path)
            continue

        for child in sorted(path.rglob("*")):
            if child.is_file() and child.suffix in SOURCE_EXTENSIONS:
                files.append(child)

    # 去重且保序
    result = []
    seen = set()

    for file in files:
        resolved = file.resolve()
        if resolved in seen:
            continue
        seen.add(resolved)
        result.append(resolved)

    return result


def analyze_file(
    filename: Path,
    supported: set[str],
    strict: bool,
) -> FileResult:
    text = filename.read_text(encoding="utf-8", errors="ignore")
    text = remove_block_comments(text)
    macros = collect_macro_names(text)

    used: Counter = Counter()
    native: Counter = Counter()
    pseudo: Counter = Counter()
    issues: list[Issue] = []
    raw_encoding_lines: list[tuple[int, str]] = []

    for lineno, raw_line in enumerate(text.splitlines(), start=1):
        raw_directive = detect_raw_encoding_directive(raw_line)
        if raw_directive is not None:
            raw_encoding_lines.append((lineno, raw_line.rstrip()))

        mnemonic = parse_instruction(raw_line, macros)
        if mnemonic is None:
            continue

        used[mnemonic] += 1

        # 原生支持
        if mnemonic in supported:
            native[mnemonic] += 1
            continue

        # 常见伪指令
        known_pseudo, required, missing = pseudo_status(mnemonic, supported)
        if known_pseudo:
            pseudo[mnemonic] += 1

            if missing:
                issues.append(
                    Issue(
                        lineno,
                        mnemonic,
                        raw_line.rstrip(),
                        "伪指令展开需要 CPU 不支持的真实指令: "
                        + ", ".join(sorted(missing)),
                    )
                )
            elif strict:
                issues.append(
                    Issue(
                        lineno,
                        mnemonic,
                        raw_line.rstrip(),
                        "严格模式：该助记符是伪指令；可展开为已支持真实指令: "
                        + ", ".join(sorted(required)),
                    )
                )
            continue

        # 完全未知 / CPU 不支持
        issues.append(
            Issue(
                lineno,
                mnemonic,
                raw_line.rstrip(),
                "当前 myCPU 原生支持列表中不存在，且不是脚本已知的安全伪指令",
            )
        )

    return FileResult(
        filename=filename,
        used=used,
        native=native,
        pseudo=pseudo,
        issues=issues,
        raw_encoding_lines=raw_encoding_lines,
    )


def print_supported(supported: set[str]) -> None:
    groups = [
        ("算术/比较", [
            "add.w", "addi.w", "sub.w",
            "slt", "sltu", "slti", "sltui",
        ]),
        ("逻辑", [
            "nor", "and", "or", "xor",
            "andi", "ori", "xori",
        ]),
        ("移位", [
            "sll.w", "srl.w", "sra.w",
            "slli.w", "srli.w", "srai.w",
        ]),
        ("立即数/PC", [
            "lu12i.w", "pcaddu12i",
        ]),
        ("乘法", [
            "mul.w", "mulh.w", "mulh.wu",
        ]),
        ("访存", [
            "ld.b", "ld.bu", "ld.h", "ld.hu", "ld.w",
            "st.b", "st.h", "st.w",
        ]),
        ("分支/跳转", [
            "b", "bl", "jirl",
            "beq", "bne", "blt", "bge", "bltu", "bgeu",
        ]),
        ("系统/Cache/CSR", [
            "cpucfg", "cacop", "csrwr", "csrxchg",
        ]),
    ]

    print()
    print(f"CPU 原生支持指令：{len(supported)} 条")

    grouped = set()
    for title, candidates in groups:
        items = [inst for inst in candidates if inst in supported]
        grouped.update(items)
        if items:
            print(f"  {title:<14}: " + ", ".join(items))

    extra = sorted(supported - grouped)
    if extra:
        print("  其它          : " + ", ".join(extra))


def format_counter(counter: Counter) -> str:
    if not counter:
        return "(无)"

    return ", ".join(
        f"{mnemonic}×{count}"
        for mnemonic, count in sorted(
            counter.items(),
            key=lambda item: (-item[1], item[0]),
        )
    )


def print_file_result(result: FileResult, strict: bool) -> None:
    print()
    print("=" * 72)
    print(f"文件: {result.filename}")
    print("=" * 72)

    total = sum(result.used.values())
    native_count = sum(result.native.values())
    pseudo_count = sum(result.pseudo.values())

    print(f"[INFO] 共识别汇编指令 {total} 条")
    print(f"[INFO] CPU 原生指令     {native_count} 条")
    print(f"[INFO] 已知伪指令       {pseudo_count} 条")

    print(f"[USED] {format_counter(result.used)}")

    if result.raw_encoding_lines:
        print(
            "[WARN] 发现直接写机器码的 directive。"
            "脚本无法仅凭助记符确认这些编码是否被 CPU 支持："
        )
        for lineno, raw in result.raw_encoding_lines:
            print(f"       L{lineno:<5} {raw.strip()}")

    if not result.issues:
        print("[PASS] 未发现当前 myCPU 不支持的助记符")
        if result.pseudo and not strict:
            print(
                "[INFO] 其中存在伪指令，但其已知展开所需的真实指令均在 CPU 支持列表中"
            )
        return

    print(f"[FAIL] 发现 {len(result.issues)} 处不支持/非原生问题")

    for issue in result.issues:
        print(
            f"       L{issue.lineno:<5} {issue.mnemonic:<14} {issue.reason}\n"
            f"              {issue.raw.strip()}"
        )


def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "分析 LoongArch 汇编文件，并检查是否包含当前最终参赛 myCPU "
            "不支持的指令"
        )
    )

    parser.add_argument(
        "-i",
        "--input",
        dest="inputs",
        action="append",
        required=True,
        type=Path,
        metavar="FILE_OR_DIR",
        help=(
            "输入汇编文件或目录；支持 .s/.S/.asm/.disasm。"
            "可重复使用，例如：-i a.s -i b.asm"
        ),
    )

    parser.add_argument(
        "--decoder",
        type=Path,
        metavar="INST_DECODER_V",
        help=(
            "显式指定最终参赛 myCPU/inst_decoder.v。"
            "不允许指向 mycpu_ref"
        ),
    )

    parser.add_argument(
        "--strict",
        action="store_true",
        help=(
            "严格模式：move/jr/ret/li/bgtu 等伪指令即使可安全展开，"
            "也作为非原生指令报告"
        ),
    )

    parser.add_argument(
        "--list-supported",
        action="store_true",
        help="打印从当前 myCPU 得到的原生支持指令列表",
    )

    return parser


def main() -> int:
    parser = build_arg_parser()
    args = parser.parse_args()

    try:
        supported, source = load_supported(args.decoder)
    except (OSError, ValueError) as exc:
        print(f"[ERROR] {exc}", file=sys.stderr)
        return 2

    print(f"[INFO] 指令支持来源: {source}")
    print(f"[INFO] 原生支持指令数: {len(supported)}")

    if args.list_supported:
        print_supported(supported)

    files = iter_input_files(args.inputs)
    if not files:
        print(
            "[ERROR] --input 没有找到任何可分析的汇编文件",
            file=sys.stderr,
        )
        return 2

    print(f"[INFO] 将分析 {len(files)} 个文件")

    all_used: Counter = Counter()
    all_issues: list[tuple[Path, Issue]] = []
    raw_encoding_total = 0

    for filename in files:
        try:
            result = analyze_file(filename, supported, args.strict)
        except OSError as exc:
            print(f"[ERROR] 无法读取 {filename}: {exc}", file=sys.stderr)
            return 2

        print_file_result(result, args.strict)

        all_used.update(result.used)
        all_issues.extend((filename, issue) for issue in result.issues)
        raw_encoding_total += len(result.raw_encoding_lines)

    print()
    print("=" * 72)
    print("总分析结果")
    print("=" * 72)
    print(f"输入文件数: {len(files)}")
    print(f"识别指令数: {sum(all_used.values())}")
    print(f"使用的助记符种类数: {len(all_used)}")
    print(f"不支持/非原生问题数: {len(all_issues)}")

    if raw_encoding_total:
        print(
            f"直接机器码 directive: {raw_encoding_total} 处 "
            "(需要反汇编后才能做最终确认)"
        )

    if all_issues:
        unsupported_counter = Counter(
            issue.mnemonic for _, issue in all_issues
        )

        print()
        print("不支持/非原生助记符汇总：")
        for mnemonic, count in sorted(
            unsupported_counter.items(),
            key=lambda item: (-item[1], item[0]),
        ):
            print(f"  {mnemonic:<16} × {count}")

        print()
        print("FAIL: 汇编文件包含当前 myCPU 不能直接确认支持的指令")
        return 1

    print()
    print("PASS: 未发现当前 myCPU 不支持的汇编助记符")
    return 0


if __name__ == "__main__":
    sys.exit(main())
