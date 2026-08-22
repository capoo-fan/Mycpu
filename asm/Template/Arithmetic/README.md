# LA32R/LA32S 决赛可复用函数工具库

本目录提供一组可综合的 32 位 Verilog 函数模块，面向龙芯杯个人赛决赛的数组变换、
归约、位处理、校验和算术题。模块提供两种使用方式：

- 单文件 Map：每个 `la32_*.v` 的第一段都是固定接口 `accelerator_logic`，随后紧跟
  对应核心，选择一个文件即可直接提交；
- 独立核心：定义 `LA32_CORE_ONLY` 后可同时编译全部核心，适合直接接入 ALU、EX
  阶段或自定义加速器；
- `contest_function_unit`：操作码和全部操作数均可逐请求变化的完整接口。

仓库当前 CPU 使用 LA32R 的 40 条精简子集；本工具库还准备了若干 LA32S 标准整数
操作。加入这些源文件不会自动扩展 CPU 指令集，译码、暂停、冲刷和写回仍需按实际
接入方式处理。

## 整数操作列举

### 除法/取模

- 有符号除法/取模
- 无符号除法/取模

### bit_count 类

- CLZ：统计 operand 从最高位开始连续为 0 的位数
- CLO：统计 operand 从最高位开始连续为 1 的位数
- CTZ：统计 operand 从最低位开始连续为 0 的位数
- CTO：统计 operand 从最低位开始连续为 1 的位数
- 统计 operand 的 32 个比特中值为 1 的比特总数

### 移位类型

- ROTR.W：将 operand_a 循环右移 shift_amount 位。result=`(a >> sa) | (a << (32-sa))`，其中 `sa=shift_amount[4:0]`
- BITREV.W：将 operand_a 的 32 个比特反转。result=`{a[0], a[1], ..., a[31]}`
- REVB.2H：将 operand_a 的两个半字节内的字节交换。result=`{a[15:8], a[7:0], a[31:24], a[23:16]}`
- BYTEPICK.W：从 operand_a 与 operand_b 的拼接值中选取连续四字节


### 位域类型

- BSTRPICK.W：提取 operand_a 的 [msb:lsb] 位并零扩展到 32 位
- BSTRINS.W：用 operand_b 的低位替换 operand_a 的 [msb:lsb] 位，其他位保持不变


### 最大公约数

- GCD：计算 operand_a 与 operand_b 的最大公约数,使用辗转相除法
  
### 无符号整数开方

- Sqrt: 计算 operand_a 的无符号整数平方根，返回向下取整的结果，16 周期实现

### 乘法

- MULH.WU：无符号乘法，返回高 32 位
- MULH.W ：有符号乘法，返回高 32 位
- MULU.W ：无符号乘法，返回低 32 位
- MULS.W ：有符号乘法，返回低 32 位

### 多条指令的逻辑

- ANDN: operand_a & ~operand_b
- ORN: operand_a | ~operand_b
- MASKEQZ: 如果 operand_b==0 返回 0，否则返回 operand_a
- MASKNEZ: 如果 operand_b!=0 返回 0，否则返回 operand_a
- ALSL: 将 operand_a 左移 (shift_amount[1:0]+1) 位后加上 operand_b，移位范围 1～4
- EXT.W.B：符号扩展 operand_a 的低 8 位
- EXT.W.H：符号扩展 operand_a 的低 16 位



## 文件和用途

| 文件                        | 功能                           | 实现形式                |
| --------------------------- | ------------------------------ | ----------------------- |
| `la32_divmod.v`             | 有/无符号除法和取模            | 自包含 Map + 32 轮核心  |
| `la32_isqrt.v`              | 无符号整数开方                 | 自包含 Map + 16 轮核心  |
| `la32_gcd.v`                | 无符号最大公约数               | 自包含 Map + 二进制 GCD |
| `la32_bit_count.v`          | CLZ/CLO/CTZ/CTO/Popcount       | 自包含 Map + 组合核心   |
| `la32_bit_permute.v`        | ROTR/BITREV/REVB/BYTEPICK      | 自包含 Map + 组合核心   |
| `la32_bitfield.v`           | BSTRPICK/BSTRINS               | 自包含 Map + 组合核心   |
| `la32_simple_ops.v`         | ANDN/ORN/MASK/ALSL/EXT         | 自包含 Map + 组合核心   |
| `la32_mul_full.v`           | 有/无符号 32×32→64 位乘法      | 自包含 Map + 单拍核心   |
| `la32_crc32.v`              | CRC-32/CRC-32C，8/16/32 位消息 | 自包含 Map + 迭代核心   |
| `contest_arithmetic_unit.v` | 原有算术模块统一入口           | 3 位兼容操作码          |
| `contest_function_unit.v`   | 全部函数统一入口               | 8 位操作码              |
| `arithmetic_map_adapter.v`  | 旧 3 位算术 Map 入口           | 兼容壳                  |
| `function_map_adapter.v`    | 旧全函数 Map 入口              | 兼容壳                  |
| `la32_arithmetic_ops.vh`    | 原算术操作码                   | 兼容保留                |

`la32_bit_count`、`la32_bit_permute`、`la32_bitfield` 和 `la32_simple_ops` 没有时序
状态，可单独放在已有流水级中；它们各自的 Map 接入壳会在接受请求的时钟沿寄存组合
结果。

## 运行时可变操作接口

```verilog
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

## 运行时操作编码

`contest_function_unit` 的 8 位编码直接定义在模块内部，不再依赖额外头文件。下表
沿用模块内部的 `LA32_FUNC_OP_*` 局部参数名称说明语义；调用方按模块中列出的
`8'h00`～`8'h36` 数值传入。单文件 Map 接入只使用各文件自己的短参数，不使用这套
全局编码。

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

## 单文件接到 Map 模板

从九个 `la32_*.v` 文件中只选择题目需要的一个。该文件开头已经定义固定端口的
`accelerator_logic`，后半段包含所需核心，不需要再复制接入逻辑、加入操作码头文件
或同时编译其他运算文件。例如逐元素位反转只使用 `la32_bit_permute.v`：

```verilog
accelerator_logic #(
    .OPERATION    (3'd1),
    .OPERAND_B    (32'b0),
    .SHIFT_AMOUNT (5'b0)
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

`in_data` 固定对应核心的第一个操作数，其余输入由文件顶部的参数固定。各文件参数
如下：

| 文件                 | 接入壳参数                                     |
| -------------------- | ---------------------------------------------- |
| `la32_divmod.v`      | `OPERATION`、`DIVISOR`                         |
| `la32_isqrt.v`       | 无；固定返回向下取整的平方根                   |
| `la32_gcd.v`         | `OPERAND_B`                                    |
| `la32_bit_count.v`   | `OPERATION`                                    |
| `la32_bit_permute.v` | `OPERATION`、`OPERAND_B`、`SHIFT_AMOUNT`       |
| `la32_bitfield.v`    | `OPERATION`、`OPERAND_B`、`MSB`、`LSB`         |
| `la32_simple_ops.v`  | `OPERATION`、`OPERAND_B`、`SHIFT_AMOUNT`       |
| `la32_mul_full.v`    | `SIGNED_OPERATION`、`OPERAND_B`、`RETURN_HIGH` |
| `la32_crc32.v`       | `CASTAGNOLI`、`WIDTH`、`SEED`                  |

每次 `in_valid && in_ready` 接受一个输入，之后恰好产生一次 `out_valid`。长延迟操作
执行期间会拉低 `in_ready`。参数改变后需要重新综合和 implementation。

若要在同一工程中同时使用多个核心，定义 `LA32_CORE_ONLY` 隐去各文件同名的
`accelerator_logic`，再直接实例化 `la32_*` 核心或使用 `contest_function_unit`。
`arithmetic_map_adapter` 与 `function_map_adapter` 仅用于兼容旧例化。

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
- 九个自包含文件分别以 `accelerator_logic` 为顶层通过 Verilator/Icarus 语法检查；
- 除零、符号溢出、完整位域、全部 BYTEPICK 窗口；
- 有/无符号完整乘积；
- CRC-32 与 CRC-32C 的 `123456789` 标准检查值。

testbench 中使用的 `/`、`%` 和参考乘法只用于对拍，不进入除法、开方、GCD 或 CRC
综合逻辑；`la32_mul_full` 中的 `*` 是有意保留的 FPGA 乘法资源推断点。
