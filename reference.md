# mycpu_ref CPU 架构分析

## 一、整体架构概览

mycpu_ref 实现了一款 **双发射超标量、五级流水线** 的 LA32R (LoongArch32 Reduced) 指令集处理器，采用哈佛架构（指令与数据分离的缓存体系）。

### 核心参数

| 特性 | 说明 |
|------|------|
| ISA | LA32R (LoongArch 32-bit Reduced) |
| 流水线 | 5 级：IF → ID → EX → MEM → WB |
| 发射宽度 | 双发射（每周期最多 2 条指令） |
| 缓存 | 哈佛架构：I-Cache + D-Cache |
| 分支预测 | BPU 紧耦合在 IF 阶段 |
| PC 复位值 | `0x80000000` |
| 主频 | 10MHz (PLL 从 50MHz 分频) |

### 顶层模块层次

```
thinpad_top.v          ← FPGA 顶层（PLL、引脚映射、VGA、数码管）
  └── mycpu_top.v      ← CPU + SRAM 仲裁 + UART
        ├── mycpu.v    ← CPU 核心（五级流水线）
        ├── sram_master.v  ← SRAM/UART 总线仲裁器
        ├── async_receiver  ← UART 接收
        └── async_transmitter ← UART 发送
```

---

## 二、五级流水线详解

### 流水线结构图

```
         ┌──────────┐     ┌──────────┐     ┌──────────┐     ┌──────────┐     ┌──────────┐
         │    IF    │ ──→ │    ID    │ ──→ │    EX    │ ──→ │   MEM    │ ──→ │    WB    │
         │ 取指阶段 │     │ 译码阶段 │     │ 执行阶段 │     │ 访存阶段 │     │ 写回阶段 │
         └──────────┘     └──────────┘     └──────────┘     └──────────┘     └──────────┘
              ↑                                                            │
              │                      数据前递 (data_forward)                 │
              └────────────────────────────────────────────────────────────┘
              │                      分支预测更新 (BPU update)               │
              └────────────────────────────────────────────────────────────┘
```

### 流水线寄存器

| 阶段间寄存器 | 位置 | 功能 |
|-------------|------|------|
| inst_buffer | IF → ID | 缓冲取出的指令对（最多缓存若干条） |
| ID_EX | ID → EX | 传递译码结果、寄存器值、立即数、控制信号 |
| EX_MEM | EX → MEM | 传递 ALU 结果、访存信息、分支判断结果 |
| MEM_WB | MEM → WB | 传递最终写回数据和控制信号 |

---

### 2.1 IF 阶段（取指）

**核心模块：PC.v, BPU.v, inst_cache.v, inst_buffer.v**

数据流：
```
PC.v  ──→  BPU.v  ──→  inst_cache.v  ──→  inst_buffer.v  ──→  ID 阶段
│            │              │                    │
│            │              │                    └─ 缓冲两路 97-bit 指令包
│            │              └─ 每次取 64-bit（2 条指令）
│            └─ 分支预测，给出 pred_taken / pred_target
└─ 程序计数器，支持 flush 重定向、suspend 暂停
```

- **PC.v**：程序计数器。输入 `BPU_pred_target`（预测目标地址），受 `Icache_full` 暂停、`flush` 冲刷控制。支持分支预测错误后的 PC 重定向。
- **BPU.v**：分支预测单元。在 IF 阶段根据历史预测分支方向和目标地址。在 EX/MEM 阶段根据实际分支结果更新预测状态。
- **inst_cache.v**：指令缓存。每次请求 64-bit 数据（2 条 32-bit 指令），输出两个指令字及其 PC 和预测信息。支持 `flush` 冲刷。
- **inst_buffer.v**：指令缓冲队列。吸收 I-Cache 输出与 ID 阶段消费速率不匹配。维护 front1/front2 两个 slot，由 `pop0`/`pop1` 信号控制出队。

---

### 2.2 ID 阶段（译码）

**核心模块：CU.v, inst_decoder.v, EXT.v, RF.v, data_forward.v**

数据流（双路并行）：
```
inst_buffer front1 ──→ inst_decoder ──→ CU 控制信号 (25-bit)
                    │                  └─→ EXT0 立即数扩展
                    └─→ RF 读寄存器 (rR1, rR2) ──→ data_forward 前递选择
                    
inst_buffer front2 ──→ inst_decoder ──→ CU 控制信号 (25-bit)
                    │                  └─→ EXT1 立即数扩展
                    └─→ RF 读寄存器 (rR3, rR4) ──→ data_forward 前递选择
```

- **CU.v**：控制单元（15KB，最大模块）。根据指令的 `op` 字段（bit[16:11]）和 `func7` 字段（bit[6:0]）译码，产生 13 种控制信号：`branch_inst_flag`, `ext_op`, `ram_ext_op`, `alu_op`, `rf_we`, `ram_we`, `r2_sel`, `wr_sel`, `wd_sel`, `rR1_re`, `rR2_re`, `alua_sel`, `alub_sel`。支持的指令类型包括：
  - **算术逻辑**：ADD.W, SUB.W, AND, OR, XOR, NOR, SLT, SLTU, SLL.W, SRL.W, SRA.W, MUL.W, MULH.W, MULHU.W, DIV.W, DIVU.W, MOD.W, MODU.W
  - **立即数运算**：ADDI, ANDI, ORI, XORI, SLTI, SLTUI, SLLI.W, SRLI.W, SRAI.W
  - **访存**：LD.B, LD.BU, LD.H, LD.HU, LD.W, ST.B, ST.H, ST.W
  - **分支跳转**：BEQ, BNE, BLT, BLTU, BGE, BGEU, JIRL, B, BL
  - **PC 相关**：PCADDU12I, LUI12
- **inst_decoder.v**：指令译码器包装层。例化 CU，将原始指令包（97-bit）与 CU 控制信号（25-bit）拼接成 `DECODED_PACKET_WIDTH`=123-bit 的解码包。
- **EXT.v**：立即数扩展单元。支持 6 种扩展模式：`EXT_26`, `EXT_16`, `EXT_20`, `EXT_12`, `EXT_U12`, `EXT_5`。
- **RF.v**：寄存器堆。32×32-bit，4 读口 2 写口。`r[0]` 硬连线为 0。读端口内建 WB 阶段写数据的前递逻辑（写优先于读，解决同一周期写后读）。
- **data_forward.v**：数据前递单元。检测 ID 阶段与 EX/MEM 阶段之间的数据冒险（RAW），产生前递选择信号和 Load-Use 暂停信号。前递优先级：EX1 > EX0 > MEM1 > MEM0（最新数据优先）。

**双发射限制条件（pop1 信号）**：
1. 两条指令不能同时为分支指令
2. 两条指令不能同时为访存指令（`wd_sel == WD_RAM`）
3. 指令 0 不能与指令 1 存在 RAW 冒险（写后读）
4. 指令 0 必须可发射（pop0 为真）

---

### 2.3 EX 阶段（执行）

**核心模块：ALU.v, branch_judge.v, ID_EX.v（流水线寄存器）**

数据流（双路独立 ALU + 分支判断）：
```
ID_EX0 ──→ ALU0 ──→ ALU0_C ──→ EX_MEM0
        │          │
        └─→ branch_judge0 ──→ actual_taken, actual_target
        └─→ ex_ld_req（提前发起 Load 请求）
        
ID_EX1 ──→ ALU1 ──→ ALU1_C ──→ EX_MEM1
        │
        └─→ branch_judge1 ──→ actual_taken, actual_target
```

- **ALU.v**：算术逻辑单元。支持 25 种 ALU 操作（包括加减、逻辑、移位、比较、乘法、除法等）。乘法通过 Xilinx `mult_gen_0` IP 核实现（1 周期延迟），多周期乘法有状态机控制（`S_IDLE` → `S_BUSY` → back），产生 `suspend` 信号暂停流水线。JIRL 和 BL 指令输出 `PC+4` 作为返回地址。
- **branch_judge.v**：分支判定单元。在 EX 阶段根据寄存器值和 ALU 操作码计算实际分支方向和目标地址。支持的条件：EQ/NEQ、有符号/无符号比较（LT/GE）、无条件跳转、间接跳转（JIRL）。
- **ID_EX.v**：ID→EX 流水线寄存器。优先级：reset → flush → suspend → load_use 无效 → 正常传入。同时传递 `is_load`, `is_store`, `is_mult` 标志以及 load-use 冒险标记。

**EX 阶段特殊的 Load 提前发起**：
```verilog
assign ex_ld_req = ID_EX0_is_load_o && !ex_ld_addr[29] && !ex_suspend && !mem0_req && !mem1_req;
assign ex_ld_addr = ID_EX0_rD1_out + ID_EX0_ext_out;
```
只有 Pipe 0 的 Load 可以在 EX 阶段提前发起（地址非 UART 空间且无 MEM 阶段待处理请求时）。

---

### 2.4 MEM 阶段（访存）

**核心模块：MEM_REQ_easy.v, mem_branch_judge.v, EX_MEM.v（流水线寄存器）**

数据流：
```
EX_MEM0 ──→ mem_branch_judge0 ──→ flush/flush_pc/real_taken
        │
        └─→ (Pipe 选择) ──→ MEM_REQ_easy ──→ daccess_ren/wen/addr/wdata
                                             ──→ mem_final_load_data
EX_MEM1 ──→ mem_branch_judge1 ──→ flush/flush_pc/real_taken
```

- **MEM_REQ_easy.v**：访存请求处理单元。由于只有一组 D-Cache 接口，MEM 阶段采用 **优先级仲裁**：Pipe 1 优先于 Pipe 0。
  - **Load**：发出读请求，等 `dcache_read_valid` 返回后根据 `offset` 和 `ram_ext_op` 对齐/扩展数据
  - **Store**：根据 `ram_we` 生成字节掩码（`store_mask_reg`），格式化写数据（字节/半字复制到全字）
  - 产生 `suspend` 信号等待 D-Cache 响应
- **mem_branch_judge.v**：分支预测验证单元。比较 EX 阶段计算的实际分支结果与 IF 阶段 BPU 的预测结果。若 `mispredicted`（方向错误或目标地址错误），则产生 `flush` 冲刷流水线。
- **EX_MEM.v**：EX→MEM 流水线寄存器。优先级：reset → suspend（全局）→ ex_suspend 或 flush → 正常传入。传递 ALU 结果、访存信息、分支判断信息（实际+预测）。

---

### 2.5 WB 阶段（写回）

**核心模块：MEM_WB.v（流水线寄存器）**

```verilog
// 写回数据选择
case (MEM_WB0_wd_sel_out)
    WD_RAM: wb_wd_fd0 = MEM_WB0_ram_ext_out;   // Load 数据
    WD_ALU: wb_wd_fd0 = MEM_WB0_alu_C_out;     // ALU 结果
    default: wb_wd_fd0 = 32'haabbccdd;          // 调试标记
endcase
```

- 两条流水线各有一个 MEM_WB 寄存器
- 数据写回 RF 的两个写端口（`we1`/`wD1`, `we2`/`wD2`）
- MEM_WB1 在 `MEM_BJ0_flush_o` 时也会被冲刷（当 Pipe 0 发生分支预测错误时，Pipe 1 的结果也应无效化）

---

## 三、数据前递网络（data_forward.v）

### 冒险检测矩阵

对于每条 ID 指令的每个源寄存器（inst0.rR1, inst0.rR2, inst1.rR1, inst1.rR2），检测与 EX0/EX1/MEM0/MEM1 阶段目标寄存器的匹配：

```
         EX0_wr   EX1_wr   MEM0_wr   MEM1_wr
inst0.rR1   ✓        ✓        ✓         ✓
inst0.rR2   ✓        ✓        ✓         ✓
inst1.rR1   ✓        ✓        ✓         ✓
inst1.rR2   ✓        ✓        ✓         ✓
```

### 前递优先级

最新数据优先：**EX1 > EX0 > MEM1 > MEM0**

```verilog
wire fwd_ex1_0_1  = ex1_hazard_0_1;                                           // EX1 最高优先
wire fwd_ex0_0_1  = ex0_hazard_0_1  && !ex1_hazard_0_1;                       // EX0 次之
wire fwd_mem1_0_1 = mem1_hazard_0_1 && !ex1_hazard_0_1 && !ex0_hazard_0_1;    // MEM1 再次
wire fwd_mem0_0_1 = mem0_hazard_0_1 && !ex1_hazard_0_1 && !ex0_hazard_0_1
                                      && !mem1_hazard_0_1;                     // MEM0 最低
```

### Load-Use 冒险

当 EX 阶段有 Load 指令且其目标寄存器与 ID 阶段的源寄存器冲突时，必须暂停流水线（无法前递，因为 Load 数据要到 MEM 阶段才可用）：

```verilog
load_use_stall_0 = (ex0_is_load && ex0_hazard_0_x) || (ex1_is_load && ex1_hazard_0_x)
```

`load_use_stall_0` 会导致 `pop0 = 0`（不弹出新指令），ID_EX 寄存器传入 `load_use_i=1` 使该槽位无效。

---

## 四、分支处理流程

```
IF: BPU 预测 ──→ 预测结果随指令流动
       │
ID: 识别分支指令 (branch_inst_flag)
       │
EX: branch_judge 计算实际方向和目标
       │
MEM: mem_branch_judge 比较实际 vs 预测
       │
       ├── 预测正确 → 正常执行
       └── 预测错误 → flush=1 → 冲刷 IF/ID/EX 阶段
                    → flush_pc 重定向 PC
                    → BPU.update_valid=1 → 更新 BPU 历史
```

---

## 五、存储器映射

由 `sram_master.v` 中的地址译码决定：

| 地址范围 | 区域 | 说明 |
|----------|------|------|
| `addr[22]=0, addr[29]=0` | BaseRAM | 基础 SRAM，用于 I-Cache 填充、D-Cache 读写 |
| `addr[22]=1, addr[29]=0` | ExtRAM | 扩展 SRAM，用于外设/D-Cache |
| `addr[29]=1, addr[2]=0` | UART 数据 | `0xBFD003F8`，读写串口数据 |
| `addr[29]=1, addr[2]=1` | UART 状态 | `0xBFD003FC`，读状态（ready/busy） |

**SRAM 仲裁优先级**（`sram_master.v`）：
- BaseRAM：DRead > IRead > DWrite
- ExtRAM：DRead > DWrite
- I-Cache 读请求为 **4-beat 突发模式**（一次取 4×32-bit = 128-bit）

---

## 六、流水线暂停与冲刷机制

### 暂停源（suspend）

| 信号 | 来源 | 影响范围 |
|------|------|----------|
| `Icache_full` | inst_cache | 暂停 PC（IF 阶段） |
| `ex_suspend` | ALU0/ALU1 | 当乘法正在计算时，暂停 ID_EX 和 EX_MEM 寄存器更新 |
| `mem_suspend` | MEM_REQ_easy | Load/Store 等待 D-Cache 响应时，暂停 EX_MEM 和 MEM_WB 寄存器更新 |
| `load_use_stall` | data_forward | Load-Use 冒险，暂停 inst_buffer pop 和 ID_EX 写入 |

### 冲刷源（flush）

| 信号 | 来源 | 说明 |
|------|------|------|
| `MEM_BJ0_flush_o` | mem_branch_judge0 | Pipe 0 分支预测错误 |
| `MEM_BJ1_flush_o` | mem_branch_judge1 | Pipe 1 分支预测错误 |

`flush` 信号同时作用于：PC、I-Cache、inst_buffer、ID_EX0/1、EX_MEM0/1。

---

## 七、各文件职责速查表

| 文件 | 层次 | 职责 |
|------|------|------|
| **thinpad_top.v** | FPGA 顶层 | PLL 时钟生成（50M→10M/20M）、复位同步、BaseRAM/ExtRAM 双向 IO 控制、VGA 输出、数码管、LED |
| **mycpu_top.v** | 系统集成 | 例化 CPU + SRAM 仲裁 + UART 收发器，连接所有 IO 接口 |
| **myCPU.v** | CPU 核心 | 五级流水线全部模块例化与互联（33KB，最大单文件） |
| **defines.vh** | 全局定义 | ALU op、扩展 op、访存 op、译码包字段范围等宏定义 |
| **PC.v** | IF | 程序计数器，支持 flush 重定向和 suspend 暂停 |
| **BPU.v** | IF | 分支预测单元，紧耦合在 IF，根据 MEM 阶段反馈更新 |
| **inst_cache.v** | IF | 指令缓存，每次取 64-bit（两条指令），支持 flush |
| **inst_buffer.v** | IF→ID | 指令缓冲队列，吸收取指与译码速率差异 |
| **CU.v** | ID | 控制单元，指令译码产生 13 种控制信号（15KB） |
| **inst_decoder.v** | ID | 译码器封装，将原始指令包 + CU 控制信号拼接为解码包 |
| **EXT.v** | ID | 立即数扩展（6 种模式） |
| **RF.v** | ID/WB | 寄存器堆，4 读 2 写，内建 WB 前递 |
| **data_forward.v** | ID | 数据前递网络，冒险检测 + Load-Use 暂停 + 前递数据选择 |
| **ID_EX.v** | ID→EX | ID/EX 流水线寄存器，含分支预测信息和 load-use 标记 |
| **ALU.v** | EX | ALU，支持 25 种操作，Xilinx IP 乘法器，多周期乘法状态机 |
| **branch_judge.v** | EX | 分支判定，计算实际分支方向与目标地址 |
| **EX_MEM.v** | EX→MEM | EX/MEM 流水线寄存器，含分支预测/实际结果 |
| **MEM_REQ_easy.v** | MEM | 访存请求处理，Load 对齐/扩展，Store 字节掩码，UART 地址过滤 |
| **mem_branch_judge.v** | MEM | 分支预测验证，比较预测 vs 实际，产生 flush |
| **MEM_WB.v** | MEM→WB | MEM/WB 流水线寄存器 |
| **sram_master.v** | 总线 | SRAM/UART 总线仲裁器，BaseRAM 与 ExtRAM 访问控制，UART 寄存器映射 |
| **async.v** | 外设 | UART 异步收发器（RS-232，9600 baud） |
| **SEG7_LUT.v** | 外设 | 七段数码管译码 |
| **vga.v** | 外设 | VGA 时序生成（800×600@75Hz） |
| **xilinx_ip/** | IP 核 | Xilinx IP：`mult_gen_0`（乘法器）、`blk_mem_gen_0`（Block RAM）、`pll_example`（PLL） |

---

## 八、关键设计决策与权衡

1. **双发射但共享资源**：两条流水线共享一套 D-Cache 接口，MEM 阶段通过优先级仲裁串行化访存请求（Pipe 1 > Pipe 0）。

2. **Load 提前发起**：Pipe 0 的 Load 指令在 EX 阶段（而非 MEM 阶段）就发出地址，隐藏部分访存延迟。

3. **BPU 紧耦合**：BPU 与 IF 阶段同拍工作，预测结果直接驱动 PC 选择，无额外延迟。

4. **乘法多周期**：乘法器延迟 1 周期，通过状态机产生 `suspend` 暂停 EX 阶段及之前的流水线（2 个额外周期）。

5. **RF 内建前递**：RF 的读端口在同一周期内检查 WB 写端口，若地址匹配则直接返回写数据，解决 WB 阶段的写后读冒险。

6. **代码风格**：全部使用 Verilog 结构化描述，无 IP 核依赖（乘法器除外），模块接口清晰，适合 FPGA 综合。
