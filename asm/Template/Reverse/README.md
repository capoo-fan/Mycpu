# 原地数组反转加速器

本模板把 `[ARRAY_BEGIN, ARRAY_END)` 内的 32 位 word 数组原地反转。它交换元素顺序，
不反转 word 内的字节或位。`ARRAY_END` 是开区间上界；空数组、单元素数组不访问存储器，
奇数长度数组的中心元素保持原值且不产生无用读写。

## 接口与工作顺序

模块沿用其他模板的名称 `array_accel_engine`、控制接口和类 SRAM 数据接口，可以替换
现有 Map/Reduction engine。`RESULT_ADDR` 只为保持顶层参数兼容而保留，原地反转时必须
等于 `ARRAY_BEGIN`。

每一对元素严格执行：

```text
read A[left] -> read A[right] -> write A[left] = old A[right]
             -> write A[right] = old A[left]
```

总线上最多有一笔 outstanding 事务。`mem_req` 在 `mem_addr_ok` 前持续有效，请求地址、
写标志、byte enable 和写数据保持不变。每笔被接受的请求必须恰好返回一次
`mem_data_ok`；最后一笔写的 `mem_data_ok` 返回后，`done` 才拉高一个周期。

## 接入 CPU

若 CPU 已按 `asm/Acc_Manual.md` 接好了统一加速器接口，只需复制 engine，并把结果参数
改成数组首地址：

```bash
cp asm/Template/Reverse/array_accel_engine.v myCPU/array_accel_engine.v
```

```verilog
array_accel_engine #(
    .ARRAY_BEGIN (32'h1c40_0000),
    .ARRAY_END   (32'h1c50_0000),
    .RESULT_ADDR (32'h1c40_0000)
) u_array_reverse (
    .clk(clk),
    .resetn(resetn),
    .start(accel_start),
    .busy(accel_busy),
    .done(accel_done),
    .takeover_req(accel_takeover_req),
    .takeover_grant(accel_takeover_grant),
    .mem_req(accel_mem_req),
    .mem_wr(accel_mem_wr),
    .mem_size(accel_mem_size),
    .mem_wstrb(accel_mem_wstrb),
    .mem_addr(accel_mem_addr),
    .mem_wdata(accel_mem_wdata),
    .mem_addr_ok(accel_mem_addr_ok),
    .mem_data_ok(accel_mem_data_ok),
    .mem_rdata(accel_mem_rdata)
);
```

这里的地址是地址翻译之后的数据口物理地址，不是程序使用的虚拟地址。首尾地址都必须
4 字节对齐。

### 数据口仲裁

触发命令必须先串行化：停止发射后续普通指令，并等待 MEM 级及数据口旧事务完全排空。
`cpu_data_idle` 必须表示“没有 CPU 请求，也没有尚未返回的 CPU 响应”，不能只写成
`!cpu_data_req`。然后使用注册的所有权状态，完整切换请求和响应：

```verilog
reg accel_owns_bus;

always @(posedge clk) begin
    if (!resetn)
        accel_owns_bus <= 1'b0;
    else if (!accel_owns_bus) begin
        if (accel_takeover_req && cpu_data_idle)
            accel_owns_bus <= 1'b1;
    end
    else if (!accel_takeover_req)
        accel_owns_bus <= 1'b0;
end

assign accel_takeover_grant = accel_owns_bus;

assign data_sram_req   = accel_owns_bus ? accel_mem_req   : cpu_data_req;
assign data_sram_wr    = accel_owns_bus ? accel_mem_wr    : cpu_data_wr;
assign data_sram_size  = accel_owns_bus ? accel_mem_size  : cpu_data_size;
assign data_sram_wstrb = accel_owns_bus ? accel_mem_wstrb : cpu_data_wstrb;
assign data_sram_addr  = accel_owns_bus ? accel_mem_addr  : cpu_data_paddr;
assign data_sram_wdata = accel_owns_bus ? accel_mem_wdata : cpu_data_wdata;

assign cpu_data_addr_ok = !accel_owns_bus && data_sram_addr_ok;
assign cpu_data_data_ok = !accel_owns_bus && data_sram_data_ok;
assign cpu_data_rdata   = data_sram_rdata;

assign accel_mem_addr_ok = accel_owns_bus && data_sram_addr_ok;
assign accel_mem_data_ok = accel_owns_bus && data_sram_data_ok;
assign accel_mem_rdata   = data_sram_rdata;
```

若 CPU 数据口还有 `fast_ready`、`fast_data_ok`、`store_ready` 等旁路响应，它们也必须用
`!accel_owns_bus` 门控后再送回 CPU。不能只切换请求，否则切换所有权附近的旧响应可能被
错误的主设备消费。

`accel_start` 只拉高一个周期。CPU 在 `accel_done` 前保持长延迟命令，不做普通数据访问；
收到 `done` 后从触发指令的下一条继续。现有工程可继续精确译码自定义命令
`32'h0020_0000`，不要劫持整个 `div.w` 指令空间。

### Cache 一致性

本加速器直接占用 CPU 外部数据口。如果 DCache 位于仲裁器之前，必须把目标区间配置为
uncached，或在启动前 clean/writeback，在完成后 invalidate。否则加速器可能读到旧数据，
CPU 也可能在完成后读到旧 cache line。仲裁器应位于地址翻译之后，因此 engine 参数使用
物理地址。

## 验证

本目录的回归覆盖 0、1、8、9 个 word，检查空/单元素、偶数、奇数、请求背压、随机响应
延迟、访存次序、写回数据以及越界写：

```bash
make -C asm/Template/Reverse lint
make -C asm/Template/Reverse test
```

正式复制到 CPU 后，还应在完整 SoC 仿真中检查：启动前旧 CPU 事务已排空、加速器独占
期间 CPU 的全部数据响应为 0、最终写响应先于 `done`、以及完成后总线所有权正常归还。
