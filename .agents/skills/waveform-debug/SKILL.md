---
name: loongson-cup-personal
description: Use this skill for NSCSCC/龙芯杯 CPU 设计赛个人赛 development, including MIPS/LoongArch CPU design, C1/C2/C3 functional tests, UART, monitor program, SRAM, Cache, pipeline, exception/interrupt debugging, VCD/FST waveform analysis, FPGA bring-up, and performance optimization.
---

# 龙芯杯个人赛 CPU 设计 Skill

Use this skill whenever the task is related to 龙芯杯个人赛, NSCSCC personal track, MIPS CPU, LoongArch CPU, C1/C2/C3 功能测试, 监控程序, UART, SRAM, Cache, 流水线, 异常/中断, CP0/CSR, `.vcd`/`.fst` 波形分析, Vivado 上板调试, 或性能测试优化。

## 1. Overall Priority

Always follow this priority order:

1. Functional correctness first.
2. C1/C2/C3 functional test compatibility.
3. Monitor program compatibility.
4. Stable FPGA behavior.
5. Performance optimization.
6. Design-document clarity.

Do not suggest risky performance optimizations before the CPU passes the relevant functional tests.

## 2. Ask or Infer Track

The personal track may be MIPS or LoongArch.

If the user does not specify the track and the repository does not make it clear, ask whether they are using MIPS or LoongArch.

For MIPS, focus on:
- MIPS baseline instructions
- branch/jump and possible delay-slot behavior
- load/store byte-enable and sign/zero extension
- CP0, exception, interrupt, `eret` if required
- UART/MMIO/uncache behavior

For LoongArch, focus on:
- LoongArch 32-bit reduced baseline instructions
- `bl`, `jirl`, branch target calculation
- load/store byte-enable and sign/zero extension
- CSR, exception, interrupt, `ertn` if required
- UART/MMIO/uncache behavior

## 3. Debugging Response Structure

When debugging code or waveform, answer in this structure:

1. Problem judgment
2. Most likely causes
3. Modules/signals/files to inspect
4. Concrete fix or experiment
5. Verification method
6. Risks and edge cases

Avoid vague advice. Name concrete modules, signals, and expected values.

## 4. Functional Test Strategy

For C1:
- Check reset vector, PC update, instruction fetch, ALU, register writeback, SRAM read/write, basic branch/jump.

For C2:
- Check additional instructions, UART access, MMIO decoding, uncache access, byte/halfword access, serial output stability.

For C3:
- Check monitor program boot flow, UART interaction, program loading, SRAM address mapping, exception/interrupt behavior, stack behavior, function call/return, and long-running stability.

## 5. Pipeline Debugging

For pipeline designs, reason by stage:

- IF
- ID
- EX
- MEM
- WB

Always inspect:
- PC
- instruction
- pipeline valid bits
- stall
- flush
- branch/jump redirect
- register file read/write
- ALU result
- memory request
- writeback data

Check hazards in this order:

1. RAW data hazard
2. load-use hazard
3. branch/jump control hazard
4. exception/interrupt flush
5. memory/cache stall
6. structural hazard
7. writeback conflict

Priority rule:
- reset has highest priority
- exception/interrupt flush should override normal branch/stall unless the design explicitly defines otherwise
- branch flush should remove wrong-path instructions
- memory/cache stall should freeze affected pipeline registers
- flushed instructions must not write registers or memory

## 6. Cache and Memory System

For ICache, inspect:
- `pc`
- `inst_req`
- `inst_addr`
- `inst_addr_ok`
- `inst_data_ok`
- `tag_hit`
- `valid`
- `refill`
- `cache_state`
- pipeline stall/flush

For DCache, inspect:
- `data_req`
- `data_wr`
- `data_size`
- `data_addr`
- `data_wdata`
- `data_rdata`
- `data_addr_ok`
- `data_data_ok`
- `tag_hit`
- `dirty`
- `valid`
- `byte_enable`
- `uncache`
- refill/writeback state

Rules:
- MMIO/UART/uncache accesses must not be cached.
- Load hit should return correctly aligned and sign/zero-extended data.
- Store hit should update byte lanes correctly.
- Miss refill address should be line-aligned.
- Pipeline must stall until memory/cache response is valid.

## 7. UART/MMIO/Uncache

For UART failures, inspect:
- MMIO address range
- uncache flag
- UART tx ready
- UART rx valid
- write enable
- byte enable
- polling loop branch condition
- CPU stall until MMIO response

Common causes:
- UART address decoded incorrectly
- status/data register swapped
- UART write occurs before ready
- MMIO accidentally cached
- byte-enable wrong
- baud rate or clock mismatch
- reset leaves UART in invalid state

## 8. Waveform Analysis

When analyzing `.vcd` or `.fst`:

1. Open waveform using available MCP tools if possible.
2. Locate the scenario: instruction fetch, load/store, Cache hit/miss, UART, uncache, exception, monitor boot, benchmark.
3. List relevant signals.
4. Identify key cycle/time points.
5. For each conclusion, cite exact signal values.
6. Do not invent missing values.

For Chinese experiment reports, use concise technical language and include:
- scenario
- trigger condition
- signal values
- state transition
- conclusion

## 9. FPGA/Vivado Bring-up

If simulation works but board fails, prioritize:

1. reset polarity/duration
2. uninitialized registers
3. SRAM timing
4. UART baud rate
5. clock frequency mismatch
6. address mapping
7. MMIO uncache behavior
8. timing violations
9. CDC/asynchronous input
10. ILA probe coverage

Recommended ILA probes:
- PC
- instruction
- pipeline valid/stall/flush
- register writeback
- memory request/address/write enable/data
- Cache state
- UART state
- exception state

## 10. Performance Optimization

Only optimize after correctness is stable.

Analyze:
- frequency
- CPI
- load-use stalls
- branch penalty
- memory stalls
- ICache hit rate
- DCache hit rate
- refill penalty
- benchmark hot loops

Recommended path:
1. correct five-stage pipeline
2. full forwarding
3. precise load-use stall
4. ICache
5. DCache or simple data buffer
6. branch optimization
7. timing cleanup

## 11. Design Document

When writing design documentation, structure it as:

1. Overview
2. ISA support
3. Microarchitecture
4. Pipeline and hazard handling
5. Memory system
6. Cache and uncache design
7. UART and peripherals
8. Exception/interrupt handling
9. Verification
10. Performance optimization
11. Third-party code/IP declaration
12. Known limitations

Use precise technical Chinese.