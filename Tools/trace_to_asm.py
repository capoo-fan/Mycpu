#!/usr/bin/env python3
"""
将 golden_trace.txt 转换为带汇编指令的格式，方便调试。

使用方法：
    # 转换单个实验
    python3 trace_to_asm.py exp8
    
    # 转换多个实验
    python3 trace_to_asm.py exp8 exp9 exp10
    
    # 转换 exp8 到 exp23 的所有实验
    python3 trace_to_asm.py all
    
    # 使用自定义路径
    python3 trace_to_asm.py --trace golden_trace.txt --disasm test.s --output trace_with_asm.txt
"""

import sys
import re
import os
import argparse
from pathlib import Path

def parse_disasm(disasm_file):
    """
    解析反汇编文件 (objdump 输出)，提取 PC -> 指令 的映射。
    返回: dict[pc_hex_str] = (机器码, 汇编指令)
    """
    pc_to_asm = {}
    
    # 匹配格式: 1c000000:	02bffc0c 	addi.w	$r12,$r0,-1(0xfff)
    pattern = re.compile(r'^\s*([0-9a-fA-F]+):\s+([0-9a-fA-F]+)\s+(.*)$')
    
    with open(disasm_file, 'r') as f:
        for line in f:
            match = pattern.match(line)
            if match:
                pc = match.group(1).lower()
                machine_code = match.group(2)
                asm_instr = match.group(3).strip()
                pc_to_asm[pc] = (machine_code, asm_instr)
    
    return pc_to_asm

def parse_golden_trace(trace_file):
    """
    解析 golden_trace.txt 文件。
    格式: valid pc reg_num reg_value
    例如: 1 1c000000 0c ffffffff
    返回: list of (valid, pc, reg_num, reg_value)
    """
    traces = []
    with open(trace_file, 'r') as f:
        for line_num, line in enumerate(f, 1):
            line = line.strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) != 4:
                continue
            valid, pc, reg_num, reg_value = parts
            traces.append((valid, pc.lower(), reg_num, reg_value))
    return traces

def reg_name(reg_num_hex):
    """
    将寄存器编号（十六进制字符串）转换为 LoongArch 寄存器名称。
    """
    reg_num = int(reg_num_hex, 16)
    if reg_num == 0:
        return "$zero"
    elif reg_num == 1:
        return "$ra"
    elif reg_num == 2:
        return "$tp"
    elif reg_num == 3:
        return "$sp"
    elif 4 <= reg_num <= 11:
        return f"$a{reg_num - 4}"
    elif 12 <= reg_num <= 20:
        return f"$t{reg_num - 12}"
    elif reg_num == 21:
        return "$fp"
    elif 22 <= reg_num <= 31:
        return f"$s{reg_num - 22}"
    else:
        return f"$r{reg_num}"

def convert_trace(trace_file, disasm_file, output_file):
    """
    将 golden_trace.txt 转换为带汇编指令的格式。
    """
    print(f"  Loading disassembly: {disasm_file}")
    pc_to_asm = parse_disasm(disasm_file)
    print(f"    Found {len(pc_to_asm)} instructions")
    
    print(f"  Loading trace: {trace_file}")
    traces = parse_golden_trace(trace_file)
    print(f"    Found {len(traces)} trace entries")
    
    print(f"  Writing output: {output_file}")
    
    not_found_count = 0
    
    with open(output_file, 'w') as f:
        # 写入表头
        f.write("=" * 120 + "\n")
        f.write(f"{'Line':>6} | {'PC':>10} | {'Reg':>6} | {'Value':>10} | {'MachCode':>10} | Instruction\n")
        f.write("=" * 120 + "\n")
        
        for i, (valid, pc, reg_num, reg_value) in enumerate(traces, 1):
            # 查找对应的汇编指令
            if pc in pc_to_asm:
                machine_code, asm_instr = pc_to_asm[pc]
            else:
                machine_code = "????????"
                asm_instr = "<not found>"
                not_found_count += 1
            
            # 格式化寄存器名称
            reg_display = reg_name(reg_num)
            
            # 写入一行
            f.write(f"{i:>6} | 0x{pc:>8} | {reg_display:>6} | 0x{reg_value:>8} | {machine_code:>10} | {asm_instr}\n")
    
    if not_found_count > 0:
        print(f"    Warning: {not_found_count} PCs not found in disassembly")
    
    print(f"  Done!")
    return True

def convert_experiment(base_dir, exp_name):
    """
    转换指定实验的 golden_trace.txt。
    """
    exp_dir = Path(base_dir) / exp_name
    trace_file = exp_dir / "gettrace" / "golden_trace.txt"
    disasm_file = exp_dir / "func" / "obj" / "test.s"
    output_file = exp_dir / "gettrace" / "trace_with_asm.txt"
    
    if not trace_file.exists():
        print(f"[{exp_name}] Skipping: golden_trace.txt not found")
        return False
    
    if not disasm_file.exists():
        print(f"[{exp_name}] Skipping: test.s not found (run 'make' in func/ first)")
        return False
    
    print(f"[{exp_name}] Converting...")
    return convert_trace(str(trace_file), str(disasm_file), str(output_file))

def main():
    parser = argparse.ArgumentParser(description='Convert golden_trace.txt to assembly format')
    parser.add_argument('experiments', nargs='*', default=[], 
                        help='Experiment names (e.g., exp8 exp9) or "all" for exp8-exp23')
    parser.add_argument('--trace', help='Custom trace file path')
    parser.add_argument('--disasm', help='Custom disassembly file path')
    parser.add_argument('--output', help='Custom output file path')
    parser.add_argument('--base-dir', default=None, help='Base directory (default: script location)')
    
    args = parser.parse_args()
    
    # 确定基础目录
    if args.base_dir:
        base_dir = args.base_dir
    else:
        base_dir = Path(__file__).parent
    
    # 如果指定了自定义路径，直接转换
    if args.trace and args.disasm and args.output:
        convert_trace(args.trace, args.disasm, args.output)
        return
    
    # 确定要转换的实验列表
    if not args.experiments:
        parser.print_help()
        print("\nExamples:")
        print("  python3 trace_to_asm.py exp8")
        print("  python3 trace_to_asm.py exp8 exp9 exp10")
        print("  python3 trace_to_asm.py all")
        return
    
    if 'all' in args.experiments:
        # exp8 到 exp23（跳过 exp17 和 exp20，它们没有 gettrace）
        experiments = [f"exp{i}" for i in range(8, 24) if i not in [17, 20]]
    else:
        experiments = args.experiments
    
    # 批量转换
    success_count = 0
    fail_count = 0
    
    print(f"Converting {len(experiments)} experiments...\n")
    
    for exp in experiments:
        if convert_experiment(base_dir, exp):
            success_count += 1
        else:
            fail_count += 1
        print()
    
    print("=" * 60)
    print(f"Summary: {success_count} succeeded, {fail_count} skipped/failed")

if __name__ == "__main__":
    main()
