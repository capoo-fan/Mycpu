# Reduction 加速器模板

适用于完整读取数组、维护少量归约状态、最后只写一个 32-bit 结果的题目，例如最大值、
求和、计数和校验。Reduction 与 Map 使用相同的 engine 模块名、配置参数和
CPU/存储器端口。

## 统一 engine 接口

模块名固定为 `array_accel_engine`，配置参数固定为：

- `ARRAY_BEGIN`：输入数组首地址；
- `ARRAY_END`：输入数组独占上界；
- `RESULT_ADDR`：最终单字结果地址。

控制端口均为 `start/busy/done` 和 `takeover_req/takeover_grant`；存储器端口均为
`mem_req/mem_wr/mem_size/mem_wstrb/mem_addr/mem_wdata` 与
`mem_addr_ok/mem_data_ok/mem_rdata`。Map 中唯一不同的语义是 `RESULT_ADDR` 表示结果
数组首地址，但端口和例化方式不变。

## 连续访存约定

engine 获得总线后会持续发出从 `ARRAY_BEGIN` 到 `ARRAY_END` 的递增 word 读请求。
只要 `mem_addr_ok` 连续为 1，每拍都会接受一笔读取，中间没有人为 outstanding 上限，
也没有请求空拍；旧的 outstanding 深度参数已删除。

下游必须为每笔已接受请求恰好返回一次 `mem_data_ok`，多个响应必须严格保持请求顺序；
接口没有 transaction ID，不能接入会乱序返回的主端口。`mem_addr_ok=0` 时，engine
保持当前请求地址和载荷，直到请求被接受。

在 `accelerator_logic.v` 中分别处理 `first_valid` 和 `data_valid`。每个连续返回的
word 都会在对应周期产生其中一个 valid，因此归约逻辑必须能逐拍更新状态。

## 验证

testbench 使用 6 拍响应延迟，并检查 64 笔读请求逐拍连续、地址递增、归约结果和最终
写回：

```bash
build_dir=$(mktemp -d /tmp/reduction-template.XXXXXX)
verilator --binary --timing --top-module tb_array_accel_engine \
  --Mdir "$build_dir" \
  asm/Template/Reduction/tb_array_accel_engine.v \
  asm/Template/Reduction/array_accel_engine.v \
  asm/Template/Reduction/accelerator_logic.v
"$build_dir/Vtb_array_accel_engine"
```
