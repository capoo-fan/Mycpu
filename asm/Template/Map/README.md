# Map 加速器模板

适用于 `dst[i] = F(src[i])`：每读一个 32-bit 元素，按原顺序写一个结果。

## 使用方法

1. 在 `array_map_engine.v` 参数中设置 `SRC_BEGIN`、`SRC_END`（开区间）和
   `DST_BEGIN`。三者必须与接入总线使用同一地址层级。
2. 只在 `accelerator_logic.v` 的 USER MODIFY REGION 中实现 `F(x)`。
3. 每次接受 `in_valid && in_ready` 后，必须恰好产生一次 `out_valid`；结果顺序
   必须与输入顺序一致。

engine 内含一个输入预取缓冲和一个输出缓冲，会把下一次读取与当前元素的计算、
已接受的写事务重叠。总线上仍最多只有一个未完成事务，因此可直接接普通
SRAM-like bridge。若目标数组从源数组内部的更高地址开始，engine 会自动关闭预取，
保留逐项读后写的重叠数组语义；也可以设置 `ENABLE_PREFETCH=0` 手动关闭。

验证命令：

```bash
build_dir=$(mktemp -d /tmp/map-template.XXXXXX)
verilator --binary --timing --top-module tb_array_map_engine \
  --Mdir "$build_dir" \
  asm/Template/Map/tb_array_map_engine.v \
  asm/Template/Map/array_map_engine.v \
  asm/Template/Map/accelerator_logic.v
"$build_dir/Vtb_array_map_engine"
```
