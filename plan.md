myCPU IF 阶段四级流水线改造计划

Context

myCPU 当前 IF 阶段是一个简单的单级取指设计（PC + 请求 + 等待数据 + 传递给
ID），ICache 使用 FSM
方式处理（IDLE→LOOKUP→REPLACE→REFILL），非流水线化，每个周期最多取 1 条指令。

参考设计 mycpu_ref 的 inst_cache.v
内部实现了四级流水线（S0→S1→S2→S3），配合独立的 PC.v 和 BPU.v
模块，形成完整的流水线化取指通路。本次改造要求参照 mycpu_ref 的设计思路，将
myCPU 的 IF 阶段拆分为四级流水线，但保持单发射（不实现双发射）。

架构决策

1.  合并 IF_stage + icache：将 Cache 存储和流水线控制合入
    IF_stage.v，移除独立的 icache.v。这与 mycpu_ref 将流水线集成在 inst_cache.v
    内部的模式一致。
2.  提取独立 PC.v 模块：参照 mycpu_ref 的 PC.v，将 PC 逻辑从 IF_stage
    中独立出来，接口为 flush/suspend/din → pc/inst_req。
3.  保持 128-bit Cache Line：当前 myCPU icache 使用 128-bit 行（4 条 32-bit
    指令），单发射每周期取其中 1 条，宽行保留空间局部性优势。
4.  保持现有 BPU.v 不变：BPU 的组合预测 + 2 周期延迟训练机制无需修改。
5.  保持 icache_refill.v 不变：外部 SRAM 重填协议不变。
6.  flush 使用 br_taken：myCPU 在 ID 阶段解析分支，br_taken/br_target
    作为流水线冲刷信号，冲刷 S1/S2/S3 并重置 miss FSM。

文件变更清单

┌───────────────────────┬──────┬──────────────────────────────────────────┐
│ 文件 │ 动作 │ 说明 │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/PC.v │ 新建 │ 独立 PC 模块，从 IF_stage 提取 │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/IF_stage.v │ 重写 │ 四级流水线 + 集成 2-way 组相联 Cache + │
│ │ │ miss FSM │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/icache.v │ 删除 │ 功能合入 IF_stage.v │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/mycpu_top.v │ 修改 │ 新增 PC 实例，移除 icache 实例，更新连线 │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/mycpu.vh │ 不改 │ FS_TO_DS_BUS_WD=96 保持不变 │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/BPU.v │ 不改 │ 接口和预测逻辑不变 │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/ID_stage.v │ 不改 │ 接口不变 │
├───────────────────────┼──────┼──────────────────────────────────────────┤
│ myCPU/icache_refill.v │ 不改 │ 外部 SRAM 接口不变 │
└───────────────────────┴──────┴──────────────────────────────────────────┘

四级流水线详细设计

S0 — 请求生成（组合逻辑）

s0_valid = pc_inst_req // 来自 PC 模块
s0_addr = pc // 来自 PC 模块
s0_pred_target = bpu_pred_target
s0_index = s0_addr[11:4] // 8-bit, 256 组
s0_tag = s0_addr[31:12] // 20-bit
s0_offset = s0_addr[3:0]

S0 为组合逻辑，无寄存器。PC 在 S1 不阻塞时自动推进。

S1 — 地址锁存 + Cache Tag 查找

寄存器： s1_valid, s1_addr, s1_pred_target, s1_index, s1_tag,
s1_offset_word[1:0]

组合逻辑 Tag 查找（使用 s1_index）：
s1_tag_match_way0 = cache_valid[0][s1_index] && (cache_tag[0][s1_index] ==
s1_tag);
s1_tag_match_way1 = cache_valid[1][s1_index] && (cache_tag[1][s1_index] ==
s1_tag);
s1_hit = s1_tag_match_way0 || s1_tag_match_way1;
s1_hit_way = s1_tag_match_way1;
s1_hit_line = s1_hit_way ? cache_data[1][s1_index] : cache_data[0][s1_index];

S1 在 !s1_stall 时从 S0 采样。

S2 — Hit/Miss 处理 + 字选择

寄存器： s2_valid, s2_hit, s2_hit_way, s2_line_data[127:0], s2_addr,
s2_pred_target, s2_offset_word[1:0]

字提取（组合逻辑）：
function [31:0] extract_word(input [127:0] line, input [1:0] sel);
case (sel)
2'b00: extract_word = line[31:0];
2'b01: extract_word = line[63:32];
2'b10: extract_word = line[95:64];
default: extract_word = line[127:96];
endcase
endfunction

Hit 时从 s2_line_data 提取，Miss 完成时从 refill_data_reg 提取。

S2 在 !s2_stall 时从 S1 采样。

S3 — 输出寄存器

寄存器： s3_valid, s3_inst[31:0], s3_pc[31:0], s3_pred_target[31:0]

输出到 ID：
assign fs_to_ds_valid = s3_valid;
assign fs_to_ds_bus = {s3_pc, s3_inst, s3_pred_target};

S3 在 !s3_stall 时从 S2 采样。

阻塞链

wire s3_stall = !ds_allowin && s3_valid;
wire s2_stall = s3_stall || (s2_valid && !s2_hit && state != FSM_DONE);
wire s1_stall = s2_stall;
assign full = s1_stall; // 反馈给 PC.suspend

正常 Hit 时：S0→S1→S2→S3 每周期推进，每周期输出 1 条指令。
Miss 时：S2 检测 !s2_hit，冻结 S2/S1，miss FSM 并行运行，完成后解除阻塞。

Cache Miss FSM 设计

状态： FSM_IDLE → FSM_MISS_REQ → FSM_MISS_REFILL → FSM_RECOVERY → FSM_DONE

- FSM_IDLE：等待，trigger_miss = s2_valid && !s2_hit 时跳转到 MISS_REQ
- FSM_MISS_REQ：向 icache_refill 发送读请求（rd_req=1,
  rd_addr={s2_addr[31:4], 4'b0000}），等待 rd_rdy
- FSM_MISS_REFILL：收集 4 拍 32-bit 数据组装 128-bit line，ret_valid &&
  ret_last[0] 时跳转到 RECOVERY
- FSM_RECOVERY：写入 Cache（valid + tag + data），锁存
  refill_data_reg，下一周期到 DONE
- FSM_DONE：S2 使用 refill_data_reg 输出正确数据，!s3_stall 后回到 IDLE

替换策略： LFSR 随机替换（与当前 icache.v 一致）
assign miss_replace_way = !cache_valid[0][s2_index] ? 1'b0 :
!cache_valid[1][s2_index] ? 1'b1 :
lfsr[0];

分支冲刷处理

br_taken 为 1 时：

1.  S1/S2/S3 的 valid 位清零
2.  Miss FSM 重置为 FSM_IDLE
3.  PC.v 在时钟沿更新为 br_target
4.  下一周期 PC 从正确目标地址重新取指

冲刷代价：1 个时钟周期。

PC.v 模块接口

module PC(
input wire clk, resetn,
input wire flush, // = br_taken
input wire [31:0] flush_pc, // = br_target
input wire suspend, // = if_full
input wire [31:0] din, // = bpu_pred_target
output reg [31:0] pc, // 初始值 32'h1c000000
output wire inst_req
);

mycpu_top.v 连线变更

- 新增： PC u_pc 实例，接收 br_taken/br_target/if_full/bpu_pred_target，输出
  pc_out/pc_inst_req
- 修改： BPU u_bpu 的 if_pc 改为 pc_out，if_valid 改为 pc_inst_req &&
  !if_full
- 修改： IF_stage u_if 接口变更：接收 pc_inst_req/pc/bpu_pred_target，输出
  full，增加 rd_req/rd_addr/rd_rdy/ret_valid/ret_last/ret_data 接口连接
  icache_refill
- 移除： icache u*icache 实例，if_inst_sram*\* 中间信号
- 不变： icache_refill、ID_stage、EXE_stage、MEM_stage、WB_stage 实例

关键路径与时序考虑

1.  BPU 组合环路：PC(reg Q) → BPU(comb pred_target) → PC.din，频率目标
    ~200-300MHz 时应满足时序
2.  S1 Tag 比较：s1_index/tag(reg Q) → Cache 数组读取(LUT MUX) → Tag 比较 →
    s1_hit，256 条目 20-bit tag 在 FPGA 上可满足时序
3.  S2 stall 使能路径：s2_hit(reg Q) → s2_stall(comb) → S2
    寄存器使能，门数少（2-3 级 LUT）

验证方案

1.  独立 IF_stage 仿真：驱动 pc_inst_req/pc 递增模式，验证 S0→S1→S2→S3
    推进、阻塞链、miss FSM、flush
2.  PC + BPU + IF_stage 集成仿真：验证 PC 序列、BPU 预测、if_valid 时序
3.  全流水线回归测试：运行 make clean && make 于
    test/soc_verify/soc_hs_bram/testbench，对比现有正确结果
4.  边界条件测试：分支命中 miss 中的 cache line、连续 miss、分支到同一 cache
    line、PC 回绕、icache_refill 反压

实现顺序

1.  创建 PC.v
2.  重写 IF_stage.v（骨架流水线 → 加入 Cache hit 通路 → 加入 miss FSM → 加入
    flush 处理）
3.  修改 mycpu_top.v（移除 icache 实例、新增 PC 实例、重新连线）
4.  移除 icache.v 引用
5.  运行 make clean && make 验证
