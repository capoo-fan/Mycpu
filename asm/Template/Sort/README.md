# 排序硬件加速器模板

本目录提供两个 32 位无符号整数升序排序 engine，均沿用其他 `Template` 的统一
`array_accel_engine` 控制和类 SRAM 数据接口：

- `Radix/`：稳定 LSD 基数排序。默认每轮处理 4 bit、共 16 个桶和 8 轮，时间复杂度为
  `O(d(n + 2^r))`，固定 `r` 后即通常写作的 `O(nd)`；
- `Bubble/`：稳定原地冒泡排序，固定执行 `n(n-1)/2` 次相邻比较，时间复杂度为
  `O(n^2)`。

二者都按 **unsigned 32-bit word** 比较，结果写回 `[ARRAY_BEGIN, ARRAY_END)`。
`ARRAY_END` 是独占上界，首尾地址必须 4 字节对齐。空数组和单元素数组不产生访存。

## 选择建议

基数排序具有更低的渐近时间复杂度，适合较长数组。默认 4-bit digit 只需要 16 组
32-bit 计数器和 16 组位置寄存器，相比 8-bit/256 桶更节省 FPGA 寄存器及布线资源，
代价是 32 位 key 需要 8 轮。每一轮包含一次计数扫描和一次稳定散布扫描，外部存储器
事务数为 `3nd`（每轮 `2n` 次读和 `n` 次写），另有每轮 16 周期的清零和前缀和。

冒泡排序不需要 scratch 区，硬件规模更小。它固定完成 `n(n-1)/2` 次比较；每次比较
需要两次读，仅在逆序时进行两次写。因此它适合数组很短、存储空间受限的场景，不适合
大数组。

## 参数语义

两个实现都使用：

- `ARRAY_BEGIN`：待排序数组物理首地址；
- `ARRAY_END`：待排序数组物理独占上界；
- `RESULT_ADDR`：冒泡排序中必须等于 `ARRAY_BEGIN`；基数排序中是等长 scratch 区首地址；
- `RADIX_BITS`：仅基数排序使用，可选 `1/2/4/8`，默认 `4`。

基数排序的 scratch 区间为
`[RESULT_ADDR, RESULT_ADDR + ARRAY_END - ARRAY_BEGIN)`，不得与源数组重叠。算法在源区和
scratch 区之间 ping-pong；所支持的 `RADIX_BITS` 都使 32 位 key 的轮数为偶数，因此
最终结果自然回到源数组。RTL 仍保留了末轮结果位于 scratch 时的复制回退路径。

## CPU 接入

二选一复制到 CPU 目录即可，模块名和端口与 Map/Reduction/Reverse 模板一致：

```bash
# 基数排序
cp asm/Template/Sort/Radix/array_accel_engine.v myCPU/array_accel_engine.v

# 或冒泡排序
cp asm/Template/Sort/Bubble/array_accel_engine.v myCPU/array_accel_engine.v
```

基数排序例化示例：

```verilog
array_accel_engine #(
    .ARRAY_BEGIN (32'h1c40_0000),
    .ARRAY_END   (32'h1c41_0000),
    .RESULT_ADDR (32'h1c41_0000),
    .RADIX_BITS  (4)
) u_sort (
    .clk(clk), .resetn(resetn),
    .start(accel_start), .busy(accel_busy), .done(accel_done),
    .takeover_req(accel_takeover_req),
    .takeover_grant(accel_takeover_grant),
    .mem_req(accel_mem_req), .mem_wr(accel_mem_wr),
    .mem_size(accel_mem_size), .mem_wstrb(accel_mem_wstrb),
    .mem_addr(accel_mem_addr), .mem_wdata(accel_mem_wdata),
    .mem_addr_ok(accel_mem_addr_ok),
    .mem_data_ok(accel_mem_data_ok), .mem_rdata(accel_mem_rdata)
);
```

总线仲裁、启动命令串行化及响应门控应按 `asm/Acc_Manual.md` 和 Reverse 模板 README 的
方法接入。engine 最多保留一笔 outstanding 事务；`mem_req` 在 `mem_addr_ok` 前保持，
每笔已接受请求必须严格有序地返回一次 `mem_data_ok`。`done` 只拉高一个周期。

若数据口前存在 DCache，源区和 scratch 区都必须使用 uncached 映射，或在启动前执行
clean/writeback、完成后 invalidate，否则 CPU 与加速器可能看到不一致的数据。

## 验证

自检覆盖 0、1、2、9、13 个 word，包含重复值、`0`、`0xffffffff`、最高位为 1 的无符号
值、请求背压、变化响应延迟、事务范围和边界哨兵检查：

```bash
make -C asm/Template/Sort lint
make -C asm/Template/Sort test
```

复制到 `myCPU` 并接入后，还需在完整 SoC 仿真中验证总线所有权切换和 Cache 一致性。
