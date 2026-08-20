# LA32R/LA32S 决赛可复用函数工具库

本目录提供一组可综合的 32 位 Verilog 函数模块，面向龙芯杯个人赛决赛的数组变换、
归约、位处理、校验和算术题。模块分为三层：

- `accelerator_logic`：所有操作共用的 Map 固定接口和固定源码集合；
- 独立核心：接口精简，适合直接接入 ALU、EX 阶段或自定义加速器；
- `contest_function_unit`：操作码和全部操作数均可逐请求变化的完整接口。

仓库当前 CPU 使用 LA32R 的 40 条精简子集；本工具库还准备了若干 LA32S 标准整数
操作。加入这些源文件不会自动扩展 CPU 指令集，译码、暂停、冲刷和写回仍需按实际
接入方式处理。

## 文件和用途

| 文件                        | 功能                           | 实现形式                 |
| --------------------------- | ------------------------------ | ------------------------ |
| `accelerator_logic.v`       | 全部操作的统一 Map 接入层      | 8 位编译期操作码         |
| `la32_divmod.v`             | 有/无符号除法和取模            | 32 轮迭代                |
| `la32_isqrt.v`              | 无符号整数开方和平方余数       | 16 轮迭代                |
| `la32_gcd.v`                | 无符号最大公约数               | 二进制 GCD，数据相关     |
| `la32_bit_count.v`          | CLZ/CLO/CTZ/CTO/Popcount       | 五级分组/加法树组合核心  |
| `la32_bit_permute.v`        | ROTR/BITREV/REVB/BYTEPICK      | 组合核心                 |
| `la32_bitfield.v`           | BSTRPICK/BSTRINS               | 组合核心                 |
| `la32_simple_ops.v`         | ANDN/ORN/MASK/ALSL/EXT         | 组合核心                 |
| `la32_mul_full.v`           | 有/无符号 32×32→64 位乘法      | 单拍寄存，推断乘法资源   |
| `la32_crc32.v`              | CRC-32/CRC-32C，8/16/32 位消息 | 8/16/32 轮迭代           |
| `contest_arithmetic_unit.v` | 原有算术模块统一入口           | 3 位兼容操作码           |
| `contest_function_unit.v`   | 全部函数统一入口               | 8 位操作码               |
| `arithmetic_map_adapter.v`  | 旧 3 位算术 Map 入口            | 兼容壳                   |
| `function_map_adapter.v`    | 旧全函数 Map 入口               | 兼容壳                   |
| `la32_arithmetic_ops.vh`    | 原算术操作码                   | 兼容保留                 |
| `la32_function_ops.vh`      | 全函数操作码                   | 推荐新代码使用           |

`la32_bit_count`、`la32_bit_permute`、`la32_bitfield` 和 `la32_simple_ops` 没有时序
状态，可单独放在已有流水级中；统一入口会在接受请求的时钟沿寄存这些组合结果。

## 运行时可变操作接口

```verilog
`include "la32_function_ops.vh"

contest_function_unit u_function_unit (
    .clk                   (clk),
    .resetn                (resetn),

    .req_valid             (function_req_valid),
    .req_ready             (function_req_ready),
    .req_operation         (function_operation),
    .req_operand_a         (operand_a),
    .req_operand_b         (operand_b),
    .req_lsb               (control_lsb),
    .req_msb               (control_msb),

    .rsp_valid             (function_rsp_valid),
    .rsp_ready             (function_rsp_ready),
    .rsp_result            (function_result),
    .rsp_auxiliary         (function_auxiliary),
    .rsp_divide_by_zero    (divide_by_zero),
    .rsp_overflow          (overflow),
    .rsp_invalid_operation (invalid_operation),
    .rsp_invalid_control   (invalid_control)
);
```

请求只在 `req_valid && req_ready` 的上升沿被接受。响应产生后，所有 `rsp_*` 信号
保持不变，直到 `rsp_valid && rsp_ready`。统一入口一次只执行一个请求。

## 操作码

### 算术和计数

| 宏                      | `result`         | `auxiliary` | 输入    |
| ----------------------- | ---------------- | ----------- | ------- |
| `LA32_FUNC_OP_UDIV`     | 无符号商         | 余数        | `a / b` |
| `LA32_FUNC_OP_SDIV`     | 有符号商         | 余数        | `a / b` |
| `LA32_FUNC_OP_UMOD`     | 无符号余数       | 商          | `a % b` |
| `LA32_FUNC_OP_SMOD`     | 有符号余数       | 商          | `a % b` |
| `LA32_FUNC_OP_ISQRT`    | `floor(sqrt(a))` | `a-result²` | `a`     |
| `LA32_FUNC_OP_GCD`      | `gcd(a,b)`       | 0           | `a,b`   |
| `LA32_FUNC_OP_CLZ`      | 前导零数量       | 0           | `a`     |
| `LA32_FUNC_OP_CLO`      | 前导一数量       | 0           | `a`     |
| `LA32_FUNC_OP_CTZ`      | 尾零数量         | 0           | `a`     |
| `LA32_FUNC_OP_CTO`      | 尾一数量         | 0           | `a`     |
| `LA32_FUNC_OP_POPCOUNT` | 置位数量         | 0           | `a`     |

对零执行 CLZ/CTZ 返回 32；对全一执行 CLO/CTO 返回 32。有符号除法向零截断，余数
符号与被除数一致。除零返回商全一、余数为被除数并置
`rsp_divide_by_zero`；`INT_MIN/-1` 置 `rsp_overflow`。

### 位重排和位域

| 宏                        | 运算                         | 控制字段           |
| ------------------------- | ---------------------------- | ------------------ |
| `LA32_FUNC_OP_ROTR`       | `ROTR(a, lsb[4:0])`          | `req_lsb` 为移位量 |
| `LA32_FUNC_OP_BITREV_W`   | 反转整个字的 32 个比特       | 无                 |
| `LA32_FUNC_OP_BITREV_4B`  | 分别反转四个字节内部的比特   | 无                 |
| `LA32_FUNC_OP_REVB_2H`    | 分别交换两个半字内部的字节   | 无                 |
| `LA32_FUNC_OP_BYTEPICK_W` | LA32S 跨字节窗口选择         | `req_lsb[1:0]=sa2` |
| `LA32_FUNC_OP_BSTRPICK_W` | 提取 `a[msb:lsb]` 并零扩展   | `req_msb/lsb`      |
| `LA32_FUNC_OP_BSTRINS_W`  | 用 `b` 低位替换 `a[msb:lsb]` | `req_msb/lsb`      |

`BYTEPICK.W` 中 `operand_a=rj`、`operand_b=rk`，四种结果为：

```text
sa2=0: rk
sa2=1: {rk[23:0], rj[31:24]}
sa2=2: {rk[15:0], rj[31:16]}
sa2=3: {rk[7:0],  rj[31:8]}
```

位域要求 `msb >= lsb`，否则返回 0 并置 `rsp_invalid_control`。`msb=31, lsb=0`
作为完整 32 位字段正常支持。

### 完整乘法、CRC 和小型逻辑操作

| 宏                          | `result`                  | `auxiliary`/说明         |
| --------------------------- | ------------------------- | ------------------------ |
| `LA32_FUNC_OP_MULU_FULL`    | 无符号积低 32 位          | 积高 32 位               |
| `LA32_FUNC_OP_MULS_FULL`    | 有符号积低 32 位          | 积高 32 位               |
| `LA32_FUNC_OP_CRC32_B/H/W`  | IEEE CRC-32               | `a` 为消息，`b` 为旧 CRC |
| `LA32_FUNC_OP_CRC32C_B/H/W` | CRC-32C                   | `a` 为消息，`b` 为旧 CRC |
| `LA32_FUNC_OP_ANDN`         | `a & ~b`                  | -                        |
| `LA32_FUNC_OP_ORN`          | `a \| ~b`                 | -                        |
| `LA32_FUNC_OP_MASKEQZ`      | `b==0 ? 0 : a`            | -                        |
| `LA32_FUNC_OP_MASKNEZ`      | `b!=0 ? 0 : a`            | -                        |
| `LA32_FUNC_OP_ALSL`         | `(a << (lsb[1:0]+1)) + b` | 移位范围 1～4            |
| `LA32_FUNC_OP_EXT_W_B`      | 符号扩展 `a[7:0]`         | -                        |
| `LA32_FUNC_OP_EXT_W_H`      | 符号扩展 `a[15:0]`        | -                        |

CRC 核采用 LoongArch 定义的 LSB-first 更新方式：IEEE 多项式为 `0xedb88320`，
Castagnoli 多项式为 `0x82f63b78`。它执行的是一条 CRC 指令的累加语义，不会自动完成
常见文件 CRC API 的初始/最终异或；软件可按协议自行处理。

## 使用同一套文件和接口接到 Map 模板

所有操作都直接实例化 `accelerator_logic`，不再区分算术 adapter 和函数 adapter。
编译时始终加入 Makefile 中 `MAP_RTL` 指定的同一套文件：

- `accelerator_logic.v` 和 `la32_function_ops.vh`；
- `la32_divmod.v`、`la32_isqrt.v`、`la32_gcd.v`；
- `la32_bit_count.v`、`la32_bit_permute.v`、`la32_bitfield.v`；
- `la32_simple_ops.v`、`la32_mul_full.v`、`la32_crc32.v`。

只有参数值随题目变化，模块端口和源码清单都不变。例如逐元素位反转：

```verilog
`include "la32_function_ops.vh"

accelerator_logic #(
    .OPERATION     (`LA32_FUNC_OP_BITREV_W),
    .OPERAND_B     (32'b0),
    .CONTROL_LSB   (5'b0),
    .CONTROL_MSB   (5'b0),
    .USE_AUXILIARY (1'b0)
) u_accelerator_logic (
    .clk       (clk),
    .resetn    (resetn),
    .in_valid  (algo_in_valid),
    .in_ready  (algo_in_ready),
    .in_data   (algo_in_data),
    .out_valid (algo_out_valid),
    .out_data  (algo_out_data)
);
```

`in_data` 固定对应 `operand_a`，其余输入来自参数常量。`USE_AUXILIARY=0` 输出表中的
`result`；设为 1 时输出 `auxiliary`，可取得除法余数、开方余数或完整乘积高 32 位。
每次 `in_valid && in_ready` 接受一个输入，之后恰好产生一次 `out_valid`。长延迟操作
执行期间会拉低 `in_ready`。

`OPERATION` 是综合展开期开关，`generate` 只例化所选类别的运算核心；未选除法、
开方、GCD、乘法或 CRC 数据通路不会进入实现。修改参数后需要重新综合和
implementation。`arithmetic_map_adapter` 与 `function_map_adapter` 仅用于兼容旧例化，
内部也转接到同一个 `accelerator_logic`。

若 `operand_b` 或位域控制需要随每个请求变化，则使用前述 `contest_function_unit`；
它和 Map 固定参数场景是两种不同用途，不需要为不同操作更换接口。

## 接入 CPU 的注意事项

1. 在译码/EX 阶段锁存操作码、两个操作数和控制字段；
2. `req_valid` 未被 `req_ready` 接受前，所有请求字段必须保持稳定；
3. 长延迟操作接受后暂停相关指令，等待且只消费一次 `rsp_valid`；
4. 分支、例外或 CSR 冲刷长延迟指令时，需要设计取消或丢弃返回机制；
5. 不要把工具单元接到 WB debug 端口，也不要让它引入 WB debug 反压；
6. `la32_mul_full` 使用 Verilog 乘法运算符推断 FPGA 乘法资源，接入后应重新检查
   DSP 使用量和乘法路径时序。

当前工具库没有直接修改 CPU 流水线，避免破坏现有双发射、WB 和 debug 约束。

## 验证

```bash
cd asm/Template/Arithmetic
make lint
make compat
make test
```

验证使用指定的 Verilator 5.050，同时保留 Icarus Verilog-2005 综合源码兼容检查。
当前自检包括：

- 原算术单元 1246 个边界/随机/反压事务；
- 全函数单元 1851 个边界/随机/反压事务；
- 统一 Map 接口覆盖 33 个有效操作、辅助结果选择和无效操作；
- 除零、符号溢出、完整位域、全部 BYTEPICK 窗口；
- 有/无符号完整乘积；
- CRC-32 与 CRC-32C 的 `123456789` 标准检查值。

testbench 中使用的 `/`、`%` 和参考乘法只用于对拍，不进入除法、开方、GCD 或 CRC
综合逻辑；`la32_mul_full` 中的 `*` 是有意保留的 FPGA 乘法资源推断点。
