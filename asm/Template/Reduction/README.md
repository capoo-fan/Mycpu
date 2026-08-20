# Reduction 加速器模板

适用于完整读取数组、维护少量归约状态、最后只写一个 32-bit 结果的题目，例如
最大值、求和、计数和校验。

## 使用方法

1. 设置 `ARRAY_BEGIN`、`ARRAY_END`（开区间）和 `RESULT_ADDR`。
2. 在 `accelerator_logic.v` 中分别处理 `first_valid` 和 `data_valid`。
3. 若下游只能同时处理一笔事务，设置 `MAX_OUTSTANDING=1`；若下游能按请求顺序
   返回多个读响应，可提高该参数。默认值为 4。

接口没有 transaction ID，所以 `MAX_OUTSTANDING>1` 时下游必须按顺序返回读数据。
当前 `thinpad_sram_uart_bridge` 本身只接受一笔 SRAM 读，保持默认值仍然正确，但不会
凭空提高该 bridge 的吞吐；要发挥多 outstanding，需接入支持流水地址请求的控制器。

验证命令：

```bash
build_dir=$(mktemp -d /tmp/reduction-template.XXXXXX)
verilator --binary --timing --top-module tb_array_accel_engine \
  --Mdir "$build_dir" \
  asm/Template/Reduction/tb_array_accel_engine.v \
  asm/Template/Reduction/array_accel_engine.v \
  asm/Template/Reduction/accelerator_logic.v
"$build_dir/Vtb_array_accel_engine"
```
