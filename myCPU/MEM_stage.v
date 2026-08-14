`include "mycpu.vh"

module MEM_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         es_to_ms_valid_0,
    input  wire                         es_to_ms_valid_1,
    input  wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus_0,
    input  wire [`ES_TO_MS_BUS_1_WD-1:0] es_to_ms_bus_1,
    input  wire [31:0]                  es_load_addr_fast_0,
    input  wire [31:0]                  es_load_addr_fast_1,
    input  wire [`TRANS_CTX_WD-1:0]      trans_ctx,
    input  wire                         ws_allowin,
    input  wire [`WS_TO_RF_BUS_WD-1:0]  ws_to_rf_bus,
    output wire                         ms_allowin,
    output wire                         ms_to_ws_valid_0,
    output wire                         ms_to_ws_valid_1,
    output wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus_0,
    output wire [`MS_TO_WS_BUS_1_WD-1:0] ms_to_ws_bus_1,
    output wire [`MS_FWD_BUS_WD-1:0]    ms_fwd_bus_0,
    output wire [`MS_FWD_BUS_1_WD-1:0]  ms_fwd_bus_1,
    output wire                         load_wakeup_valid,
    output wire [31:0]                  load_wakeup_data,
    output wire                         csr_busy,
    output wire                         cacop_busy,
    output wire                         br_taken,
    output wire [31:0]                  br_target,
    output wire                         bpu_valid,
    output wire                         bpu_is_bj,
    output wire [31:0]                  bpu_pc,
    output wire                         bpu_real_taken,
    output wire [31:0]                  bpu_real_target,
    output wire                         icacop_req_valid,
    output wire [ 4:0]                  icacop_req_code,
    output wire [31:0]                  icacop_req_addr,
    input  wire                         icacop_req_ready,
    input  wire                         icacop_done,
    output wire                         cacop_flush,
    output wire [31:0]                  cacop_flush_target,
    // 类SRAM 数据接口
    output wire                         data_sram_req,
    output wire                         data_sram_wr,
    output wire [ 1:0]                  data_sram_size,
    output wire [ 3:0]                  data_sram_wstrb,
    output wire [31:0]                  data_sram_addr,
    output wire [31:0]                  data_sram_wdata,
    output wire                         early_sram_load_req,
    output wire [22:0]                  early_sram_load_addr,
    input  wire                         data_sram_addr_is_sram,
    input  wire                         data_sram_store_ready,
    input  wire                         data_sram_early_read_accept,
    output wire                         data_sram_store_is_ext,
    input  wire                         data_sram_addr_ok,
    input  wire                         data_sram_data_ok,
    input  wire [31:0]                  data_sram_rdata,
    input  wire                         data_sram_fast_ready,
    input  wire                         data_sram_fast_data_ok,
    input  wire [31:0]                  data_sram_fast_rdata
  );

  reg reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ms_valid_0;
  localparam [1:0] WAIT_NONE  = 2'd0;
  localparam [1:0] WAIT_DATA  = 2'd1;
  localparam [1:0] WAIT_CACOP = 2'd2;

  reg  [ 1:0] ms_wait_kind;

  reg         ms_result_forwardable_0;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 8 *)
  reg         ms_fwd_nonload_0;
  reg  [31:0] ms_pc_0;
  reg  [31:0] ms_alu_result_0;
  reg  [31:0] ms_rkd_value_0;
  reg         ms_store_data_ready_0;
  reg  [ 4:0] ms_store_data_src_0;
  reg         ms_res_from_mem_0;
  reg         ms_gr_we_0;
  reg         ms_mem_we_0;
  reg  [ 4:0] ms_dest_0;
  reg         ms_ld_byte_0;
  reg         ms_ld_half_0;
  reg         ms_ld_sign_ext_0;
  reg         ms_st_byte_0;
  reg         ms_st_half_0;
  reg         ms_pred_taken_0;
  reg  [31:0] ms_pred_target_0;
  reg         ms_is_bj_0;
  reg         ms_real_taken_0;
  reg  [31:0] ms_real_target_0;
  reg  [31:0] ms_next_pc_0;
  reg         ms_redirect_miss_0;
  reg         ms_is_cacop_0;
  reg  [ 4:0] ms_cacop_code_0;
  reg         ms_is_csr_0;
  reg  [13:0] ms_csr_num_0;
  reg  [31:0] ms_csr_wmask_0;
  reg  [31:0] ms_csr_wvalue_0;

  reg         ms_valid_1;
  reg         ms_lane0_mem_op;
  reg         ms_lane1_mem_op;
  reg         ms_selected_mem_we_q;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 4 *)
  reg         ms_selected_store_is_ext_q;
  reg         ms_addr_is_sram_0_q;
  reg         ms_addr_is_sram_1_q;
  // lane1 访存状态的数据选择副本扇出很高；控制副本只服务双访存
  // 相位/allowin 回环，避免该回环穿过地址和数据 mux 的布线区域。
  (* keep = "true", equivalent_register_removal = "no" *)
  reg         ms_lane1_mem_op_ctrl;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 12 *)
  reg         ms_select_lane1_q;
  reg  [31:0] ms_pc_1;
  reg  [31:0] ms_alu_result_1;
  reg  [31:0] ms_rkd_value_1;
  reg         ms_res_from_mem_1;
  reg         ms_gr_we_1;
  reg         ms_mem_we_1;
  reg  [ 4:0] ms_dest_1;
  reg         ms_ld_byte_1;
  reg         ms_ld_half_1;
  reg         ms_ld_sign_ext_1;
  reg         ms_st_byte_1;
  reg         ms_st_half_1;
  reg         ms_pred_taken_1;
  reg  [31:0] ms_pred_target_1;
  reg         ms_is_bj_1;
  reg         ms_real_taken_1;
  reg  [31:0] ms_real_target_1;
  reg  [31:0] ms_next_pc_1;
  reg         ms_redirect_miss_1;

  wire        es_store_data_late_0;
  wire [ 4:0] es_store_data_src_0;
  wire        es_result_forwardable_0;
  wire [31:0] es_pc_0;
  wire [31:0] es_final_result_0;
  wire [31:0] es_rkd_value_0;
  wire        es_res_from_mem_0;
  wire        es_gr_we_0;
  wire        es_mem_we_0;
  wire [ 4:0] es_dest_0;
  wire        es_ld_byte_0;
  wire        es_ld_half_0;
  wire        es_ld_sign_ext_0;
  wire        es_st_byte_0;
  wire        es_st_half_0;
  wire        es_pred_taken_0;
  wire [31:0] es_pred_target_0;
  wire        es_is_bj_0;
  wire        es_real_taken_0;
  wire [31:0] es_real_target_0;
  wire [31:0] es_next_pc_0;
  wire        es_redirect_miss_0;
  wire        es_is_cacop_0;
  wire [ 4:0] es_cacop_code_0;
  wire        es_is_csr_0;
  wire [13:0] es_csr_num_0;
  wire [31:0] es_csr_wmask_0;
  wire [31:0] es_csr_wvalue_0;

  assign {es_store_data_late_0, es_store_data_src_0,
          es_result_forwardable_0,
          es_pc_0, es_final_result_0, es_rkd_value_0,
          es_res_from_mem_0, es_gr_we_0, es_mem_we_0, es_dest_0,
          es_ld_byte_0, es_ld_half_0, es_ld_sign_ext_0,
          es_st_byte_0, es_st_half_0,
          es_pred_taken_0, es_pred_target_0,
          es_is_bj_0, es_real_taken_0, es_real_target_0,
          es_next_pc_0, es_redirect_miss_0,
          es_is_cacop_0, es_cacop_code_0,
          es_is_csr_0, es_csr_num_0, es_csr_wmask_0,
          es_csr_wvalue_0} = es_to_ms_bus_0;

  wire [31:0] es_pc_1;
  wire [31:0] es_final_result_1;
  wire [31:0] es_rkd_value_1;
  wire        es_res_from_mem_1;
  wire        es_gr_we_1;
  wire        es_mem_we_1;
  wire [ 4:0] es_dest_1;
  wire        es_ld_byte_1;
  wire        es_ld_half_1;
  wire        es_ld_sign_ext_1;
  wire        es_st_byte_1;
  wire        es_st_half_1;
  wire        es_pred_taken_1;
  wire [31:0] es_pred_target_1;
  wire        es_is_bj_1;
  wire        es_real_taken_1;
  wire [31:0] es_real_target_1;
  wire [31:0] es_next_pc_1;
  wire        es_redirect_miss_1;

  assign {es_pc_1, es_final_result_1, es_rkd_value_1,
          es_res_from_mem_1, es_gr_we_1, es_mem_we_1, es_dest_1,
          es_ld_byte_1, es_ld_half_1, es_ld_sign_ext_1,
          es_st_byte_1, es_st_half_1,
          es_pred_taken_1, es_pred_target_1,
          es_is_bj_1, es_real_taken_1, es_real_target_1,
          es_next_pc_1, es_redirect_miss_1} = es_to_ms_bus_1;

  wire        ws_rf_we_0;
  wire [ 4:0] ws_rf_waddr_0;
  wire [31:0] ws_rf_wdata_0;
  wire        ws_rf_we_1;
  wire [ 4:0] ws_rf_waddr_1;
  wire [31:0] ws_rf_wdata_1;
  assign {ws_rf_we_0, ws_rf_waddr_0, ws_rf_wdata_0,
          ws_rf_we_1, ws_rf_waddr_1, ws_rf_wdata_1} = ws_to_rf_bus;

  assign csr_busy = ms_valid_0 && ms_is_csr_0;
  assign cacop_busy = ms_valid_0 && ms_is_cacop_0;

  // lane0 的误预测在进入 MEM 时已经杀掉 lane1，避免分支恢复信号继续
  // 参与访存选择和全流水级反压。
  wire es_redirect_0_raw = es_to_ms_valid_0 && es_is_bj_0 &&
       es_redirect_miss_0;
  wire es_lane1_eff_valid = es_to_ms_valid_1 && !es_redirect_0_raw;

  wire ms_redirect_0_raw = ms_valid_0 && ms_is_bj_0 && ms_redirect_miss_0;

  wire ms_lane1_eff_valid = ms_valid_1;
  wire ms_redirect_1_raw = ms_lane1_eff_valid && ms_is_bj_1 && ms_redirect_miss_1;

  // supervisor 的合法访存地址只有 SRAM 和 UART，两者可由
  // bit25 直接区分。DMW 只替换 bit[31:29]，所以虚地址与物理
  // 地址的该位恒等价；无需在 EX->MEM 路径上重复计算 DMW 命中。
  wire es_addr_is_sram_0 = ~es_load_addr_fast_0[25];
  wire es_addr_is_sram_1 = ~es_load_addr_fast_1[25];

  wire lane0_mem_op = ms_lane0_mem_op;

  // lane0 优先；lane0 完成后清除 ms_valid_0，选择器自然转到 lane1。
  // 复用两个 valid 位表达串行相位，不增加访存队列或第二套状态机。
  wire select_lane1 = ms_select_lane1_q;
  wire selected_addr_is_sram_q = select_lane1 ?
       ms_addr_is_sram_1_q : ms_addr_is_sram_0_q;
  wire selected_res_from_mem = select_lane1 ?
       ms_res_from_mem_1 : ms_res_from_mem_0;
       
  // 当前访存相位的 store 属性与 lane 选择同时寄存，避免 posted-store
  // ready 回环先穿过 lane0/lane1 写标志选择 LUT。
  wire selected_mem_we = ms_selected_mem_we_q;
  wire [31:0] selected_addr = select_lane1 ?
       ms_alu_result_1 : ms_alu_result_0;
  wire [31:0] selected_rkd = select_lane1 ?
       ms_rkd_value_1 : ms_rkd_value_0;
  wire selected_ld_byte = select_lane1 ? ms_ld_byte_1 : ms_ld_byte_0;
  wire selected_ld_half = select_lane1 ? ms_ld_half_1 : ms_ld_half_0;
  wire selected_ld_sign_ext = select_lane1 ?
       ms_ld_sign_ext_1 : ms_ld_sign_ext_0;
  wire selected_st_byte = select_lane1 ? ms_st_byte_1 : ms_st_byte_0;
  wire selected_st_half = select_lane1 ? ms_st_half_1 : ms_st_half_0;
  wire selected_store_data_ready = select_lane1 ?
       1'b1 : ms_store_data_ready_0;

  // WAIT_DATA/WAIT_CACOP 分别是唯一 bit0/bit1 为 1 的可达编码。
  wire ms_has_mem_op = ms_wait_kind[0];
  wire ms_has_cacop = ms_wait_kind[1];
  wire dual_mem_phase_0 = lane0_mem_op && ms_lane1_mem_op_ctrl;

  // 处理 SRAM 的握手
  reg  ms_data_pending;
  reg  ms_response_waiting;
  (* keep = "true", equivalent_register_removal = "no", max_fanout = 4 *)
  reg  ms_fast_response_waiting;
  reg  ms_addr_is_sram_q;
  reg  ms_early_load_probe;
  reg  ms_rdata_buf_valid;
  reg  [31:0] ms_rdata_buf;
  reg  cacop_req_sent;
  reg         branch_flush_q;
  reg  [31:0] branch_target_q;

  wire normal_data_req;
  wire got_normal_addr_ok = normal_data_req && data_sram_addr_ok;
  // bridge 对提前读的接受脉冲寄存一拍返回。probe 保证该脉冲只会
  // 归属于已经在同一边沿进入 MEM 的那条 load。
  // 错误路径 lane1 的无副作用读可以进入 bridge，但不得由当前 MEM
  // 包接管。只有当前相位确实是 load 时才消费寄存返回的 accept；
  // 分支误预测包为 WAIT_NONE，accept 会被自然忽略。
  wire early_load_accept = ms_early_load_probe &&
       data_sram_early_read_accept && ms_has_mem_op && !selected_mem_we;
  wire got_addr_ok = got_normal_addr_ok || early_load_accept;
  wire ms_data_ok  = ms_response_waiting && data_sram_data_ok;
  wire ms_fast_ready = ms_fast_response_waiting && data_sram_fast_ready;
  wire ms_fast_data_ok = ms_response_waiting && data_sram_fast_data_ok;
  wire mem_data_ready = ms_rdata_buf_valid;

  // DMW 仅替换地址高 3 位，BaseRAM/ExtRAM 的选择位 bit22 在 EX 已经
  // 确定。把当前相位的 bank 位同步寄存并送给桥接器，避免 posted
  // store ready 回环穿过 lane 地址 mux。
  assign data_sram_store_is_ext = ms_selected_store_is_ext_q;

  wire packet_valid = ms_valid_0 || ms_valid_1;
  wire cacop_ready_go = cacop_req_sent && icacop_done;

  // 桥接器在 addr_ok 当拍已将写请求锁存进寄存化 posted-store 槽；
  // store 因此无需等待后续 data_ok 即可退休。
  wire posted_store_ready = normal_data_req && selected_mem_we &&
       selected_addr_is_sram_q && data_sram_store_ready;
  wire selected_mem_ready = mem_data_ready || ms_fast_ready ||
       posted_store_ready;
  wire phase_ready_go = ms_has_cacop ? cacop_ready_go :
       (!ms_has_mem_op || selected_mem_ready);
  wire advance_to_lane1 = packet_valid && dual_mem_phase_0 &&
       phase_ready_go && ws_allowin;
  wire packet_ready_go = phase_ready_go && !dual_mem_phase_0;

  // WB 在本设计中恒可接收。空包和普通 ALU/分支包的 wait_kind 均为
  // WAIT_NONE，因此无需再把 packet_valid 接回全局 ready 链。
  assign ms_allowin = packet_ready_go && ws_allowin;
  wire ms_fire      = packet_valid && phase_ready_go && ws_allowin;

  assign icacop_req_valid = ms_has_cacop && !ms_data_pending &&
         !cacop_req_sent;
  assign icacop_req_code  = ms_cacop_code_0;
  assign icacop_req_addr  = ms_alu_result_0;
  assign cacop_flush      = ms_fire && ms_has_cacop;
  assign cacop_flush_target = ms_pc_0 + 32'd4;

  assign ms_to_ws_valid_0 = ms_valid_0 && phase_ready_go;
  assign ms_to_ws_valid_1 = ms_lane1_eff_valid &&
       phase_ready_go && !dual_mem_phase_0;

  wire branch_redirect_detect = ms_redirect_0_raw || ms_redirect_1_raw;
  wire branch_redirect_fire = ms_fire && branch_redirect_detect;
  wire [31:0] branch_redirect_target =
       ms_redirect_0_raw ? (ms_real_taken_0 ? ms_real_target_0 : ms_next_pc_0) :
       (ms_real_taken_1 ? ms_real_target_1 : ms_next_pc_1);

  assign br_taken  = branch_flush_q;
  assign br_target = branch_flush_q ? branch_target_q : 32'b0;

  // 发出 BPU 更新信号
  wire bpu_sel_lane1 = !ms_is_bj_0 && ms_is_bj_1 && ms_lane1_eff_valid;

  // 分支包不携带访存/CACOP，故其 wait_kind 必为 WAIT_NONE；同时 WB
  // 恒可接收。对分支而言 ms_fire 与下面的 branch valid 完全等价。
  assign bpu_valid       = (ms_valid_0 && ms_is_bj_0) ||
                           (ms_lane1_eff_valid && ms_is_bj_1);
  assign bpu_is_bj       = bpu_valid;
  assign bpu_pc          = bpu_sel_lane1 ? ms_pc_1          : ms_pc_0;
  assign bpu_real_taken  = bpu_sel_lane1 ? ms_real_taken_1  : ms_real_taken_0;
  assign bpu_real_target = bpu_sel_lane1 ? ms_real_target_1 : ms_real_target_0;

  wire [31:0] ms_st_data = selected_st_byte ? {4{selected_rkd[7:0]}} :
       selected_st_half ? {2{selected_rkd[15:0]}} :
       selected_rkd;
  wire [ 3:0] ms_st_strb = selected_st_byte ?
       (4'b0001 << selected_addr[1:0]) :
       selected_st_half ? (selected_addr[1] ? 4'b1100 : 4'b0011) :
       4'b1111;
  wire [ 1:0] ms_mem_size = (selected_ld_byte || selected_st_byte) ? 2'b00 :
       (selected_ld_half || selected_st_half) ? 2'b01 :
       2'b10;

  // ExtRAM 与取指 BaseRAM 分属独立物理 bank。当前 MEM 槽为空或只含
  // 非访存普通包时，允许即将进入 MEM 的 ExtRAM load 在 EX 拍启动。
  // load 无副作用；若 bridge 正忙而未接受，请求会在进入 MEM 后自动
  // 回退到原有 normal_data_req 路径。BaseRAM load 保持原路径，避免
  // 与 I-fetch 仲裁及历史上已观察到的 STREAM 风险相互影响。
  wire es_lane0_mem_op_in = es_to_ms_valid_0 &&
       (es_res_from_mem_0 || es_mem_we_0);
  wire early_load_lane0 = es_to_ms_valid_0 && es_res_from_mem_0 &&
       es_addr_is_sram_0 && es_load_addr_fast_0[22];
  // 提前读没有架构副作用；lane0 误预测仍在 MEM 入边沿杀掉 lane1 的
  // 架构 valid。这里使用原始 lane1 valid，避免分支目标加法/比较链
  // 进入 ExtRAM bridge 的单拍控制路径。误路径读的返回不会被接管。
  wire early_load_lane1 = !es_lane0_mem_op_in && es_to_ms_valid_1 &&
       es_res_from_mem_1 && es_addr_is_sram_1 &&
       es_load_addr_fast_1[22];
  wire early_load_select_lane1 = !early_load_lane0 && early_load_lane1;
  wire early_load_candidate = early_load_lane0 || early_load_lane1;
  // 提前读只观察 ready 条件，不直接负载全局 ms_allowin/advance_to_lane1
  // 控制网。保留独立等价锥，避免这条性能旁路扰动 ISSUE->InstBuffer
  // 的高扇出关键路径。最终访存响应拍仍可在 S_DONE 边沿接收下一包。
  (* keep = "true", max_fanout = 4 *)
  wire early_selected_mem_ready = mem_data_ready || ms_fast_ready ||
       posted_store_ready;
  (* keep = "true", max_fanout = 4 *)
  wire early_phase_ready_go = ms_has_cacop ? cacop_ready_go :
       (!ms_has_mem_op || early_selected_mem_ready);
  (* keep = "true", max_fanout = 4 *)
  wire early_mem_slot = early_phase_ready_go && !dual_mem_phase_0 &&
       ws_allowin;
  (* keep = "true", max_fanout = 4 *)
  wire early_advance_to_lane1 = packet_valid && dual_mem_phase_0 &&
       early_phase_ready_go && ws_allowin;

  // 双访存包的 lane1 已经保存在 MEM 中。lane0 load 返回并确认按序
  // 退休时，直接把 lane1 ExtRAM 地址交给 bridge 的 S_DONE 边沿；
  // 这里只提前启动请求，不提前 lane1 的架构提交。
  wire phase1_early_load = early_advance_to_lane1 && ms_lane1_eff_valid &&
       ms_res_from_mem_1 && ms_addr_is_sram_1_q && ms_alu_result_1[22];
  wire ex_early_load_req = early_load_candidate && early_mem_slot;

  assign early_sram_load_req =
       (phase1_early_load || ex_early_load_req) &&
       (!ms_data_pending || data_sram_data_ok) &&
       !ms_rdata_buf_valid && !ms_early_load_probe &&
       !branch_redirect_fire && !br_taken && resetn && !reset;
  assign early_sram_load_addr = phase1_early_load ? ms_alu_result_1[22:0] :
       early_load_select_lane1 ?
       es_load_addr_fast_1[22:0] : es_load_addr_fast_0[22:0];

  // 非 SRAM store 的返回先进入 rdata_buf，再在下一拍退休；该拍仍需
  // 阻止原指令重复发地址。Load 在 data_ok 拍直接退休，posted SRAM
  // store 则不会置 rdata_buf_valid。
  assign normal_data_req = ms_has_mem_op && !ms_data_pending &&
       !ms_rdata_buf_valid &&
       (!selected_mem_we || selected_store_data_ready);
  assign data_sram_req   = normal_data_req;
  assign data_sram_wr    = selected_mem_we;
  assign data_sram_size  = ms_mem_size;
  assign data_sram_wstrb = selected_mem_we ? ms_st_strb : 4'b0;
  assign data_sram_addr  = selected_addr;
  assign data_sram_wdata = ms_st_data;

  // data_ok 返回拍直接送 WB；若 WB 暂时不能接收，则下一拍回退到
  // 已寄存的 ms_rdata_buf。当前 WB 恒可接收，但保留后一条路径可
  // 避免接口约束变化时丢失响应。
  wire [31:0] ms_final_rdata =
       ms_fast_data_ok ? data_sram_fast_rdata : ms_rdata_buf;

  // 处理加载指令的结果
  function [31:0] load_result;
    input [31:0] alu_result;
    input [31:0] mem_result;
    input        ld_byte;
    input        ld_half;
    input        ld_sign_ext;
    reg [7:0]    load_byte;
    reg [15:0]   load_half;
    begin
      load_byte = alu_result[1] ? (alu_result[0] ? mem_result[31:24] : mem_result[23:16]) :
                (alu_result[0] ? mem_result[15:8]  : mem_result[7:0]);
      load_half = alu_result[1] ? mem_result[31:16] : mem_result[15:0];
      load_result = ld_byte ? (ld_sign_ext ? {{24{load_byte[7]}}, load_byte} :
                               {24'b0, load_byte}) :
                  ld_half ? (ld_sign_ext ? {{16{load_half[15]}}, load_half} :
                             {16'b0, load_half}) :
                  mem_result;
    end
  endfunction

  // 两路访存严格串行，因此只保留一套对齐/符号扩展逻辑。
  wire [31:0] selected_load_result_resp = load_result(
       selected_addr, ms_final_rdata,
       selected_ld_byte, selected_ld_half, selected_ld_sign_ext);
  wire [31:0] ms_load_result_0 = selected_load_result_resp;
  wire [31:0] ms_load_result_1 = selected_load_result_resp;

  assign load_wakeup_valid = !select_lane1 && ms_fast_ready;
  assign load_wakeup_data = ms_load_result_0;

  wire ms_fwd_valid_0 = ms_result_forwardable_0 &&
       (ms_fwd_nonload_0 || mem_data_ready);
  wire [31:0] ms_load_result_0_fwd = load_result(
       ms_alu_result_0, ms_rdata_buf,
       ms_ld_byte_0, ms_ld_half_0, ms_ld_sign_ext_0);
  wire [31:0] ms_fwd_data_0 = ms_res_from_mem_0 ? ms_load_result_0_fwd :
       (ms_result_forwardable_0 ? ms_alu_result_0 : 32'b0);

  wire incoming_store_hit_response =
       es_store_data_late_0 && ms_valid_0 && ms_gr_we_0 &&
       ms_res_from_mem_0 && ms_fast_ready && (ms_dest_0 != 5'b0) &&
       (ms_dest_0 == es_store_data_src_0);
  wire incoming_store_hit_ms =
       es_store_data_late_0 && ms_valid_0 && ms_gr_we_0 &&
       ms_fwd_valid_0 && (ms_dest_0 != 5'b0) &&
       (ms_dest_0 == es_store_data_src_0);
  wire incoming_store_hit_ws1 =
       es_store_data_late_0 && ws_rf_we_1 &&
       (ws_rf_waddr_1 != 5'b0) &&
       (ws_rf_waddr_1 == es_store_data_src_0);
  wire incoming_store_hit_ws0 =
       es_store_data_late_0 && ws_rf_we_0 &&
       (ws_rf_waddr_0 != 5'b0) &&
       (ws_rf_waddr_0 == es_store_data_src_0);
  wire incoming_store_data_ready =
       !es_store_data_late_0 || incoming_store_hit_response ||
       incoming_store_hit_ms || incoming_store_hit_ws1 ||
       incoming_store_hit_ws0;
  wire [31:0] incoming_store_data =
       incoming_store_hit_response ? ms_load_result_0 :
       incoming_store_hit_ms       ? ms_fwd_data_0 :
       incoming_store_hit_ws1      ? ws_rf_wdata_1 :
       incoming_store_hit_ws0      ? ws_rf_wdata_0 :
                                     es_rkd_value_0;

  wire held_store_hit_ws1 =
       ms_valid_0 && ms_mem_we_0 && !ms_store_data_ready_0 &&
       ws_rf_we_1 && (ws_rf_waddr_1 != 5'b0) &&
       (ws_rf_waddr_1 == ms_store_data_src_0);
  wire held_store_hit_ws0 =
       ms_valid_0 && ms_mem_we_0 && !ms_store_data_ready_0 &&
       ws_rf_we_0 && (ws_rf_waddr_0 != 5'b0) &&
       (ws_rf_waddr_0 == ms_store_data_src_0);

  assign ms_fwd_bus_0 = {ms_valid_0, ms_gr_we_0, ms_fwd_valid_0,
                         ms_res_from_mem_0, ms_dest_0, ms_fwd_data_0};
  wire ms_fwd_valid_1 = !ms_res_from_mem_1;
  wire [31:0] ms_fwd_data_1 = ms_res_from_mem_1 ?
       32'b0 : ms_alu_result_1;

  assign ms_fwd_bus_1 = {ms_lane1_eff_valid, ms_gr_we_1,
                         ms_fwd_valid_1, ms_dest_1, ms_fwd_data_1};

  assign ms_to_ws_bus_0 = {ms_pc_0,
                           ms_alu_result_0,
                           ms_res_from_mem_0,
                           ms_gr_we_0,
                           ms_dest_0,
                           ms_ld_byte_0,
                           ms_ld_half_0,
                           ms_ld_sign_ext_0,
                           ms_final_rdata,
                           ms_is_csr_0,
                           ms_csr_num_0,
                           ms_csr_wmask_0,
                           ms_csr_wvalue_0
                          };

  assign ms_to_ws_bus_1 = {ms_res_from_mem_1 ?
                           ms_load_result_1 : ms_alu_result_1,
                           ms_gr_we_1,
                           ms_dest_1
                          };

  always @(posedge clk)
  begin
    if (reset)
    begin
      branch_flush_q  <= 1'b0;
      branch_target_q <= 32'b0;
    end
    else
    begin
      branch_flush_q <= branch_redirect_fire;
      if (branch_redirect_fire)
        branch_target_q <= branch_redirect_target;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ms_valid_0 <= 1'b0;
      ms_valid_1 <= 1'b0;
      ms_lane0_mem_op <= 1'b0;
      ms_lane1_mem_op <= 1'b0;
      ms_selected_mem_we_q <= 1'b0;
      ms_selected_store_is_ext_q <= 1'b0;
      ms_addr_is_sram_0_q <= 1'b0;
      ms_addr_is_sram_1_q <= 1'b0;
      ms_lane1_mem_op_ctrl <= 1'b0;
      ms_select_lane1_q <= 1'b0;
    end
    else if (br_taken || branch_redirect_fire)
    begin
      ms_valid_0 <= 1'b0;
      ms_valid_1 <= 1'b0;
      ms_lane0_mem_op <= 1'b0;
      ms_lane1_mem_op <= 1'b0;
      ms_selected_mem_we_q <= 1'b0;
      ms_selected_store_is_ext_q <= 1'b0;
      ms_addr_is_sram_0_q <= 1'b0;
      ms_addr_is_sram_1_q <= 1'b0;
      ms_lane1_mem_op_ctrl <= 1'b0;
      ms_select_lane1_q <= 1'b0;
    end
    else if (ms_allowin)
    begin
      ms_valid_0 <= es_to_ms_valid_0;
      ms_valid_1 <= es_lane1_eff_valid;
      ms_lane0_mem_op <= es_to_ms_valid_0 &&
           (es_res_from_mem_0 || es_mem_we_0);
      ms_lane1_mem_op <= es_lane1_eff_valid &&
           (es_res_from_mem_1 || es_mem_we_1);
      ms_selected_mem_we_q <= (es_to_ms_valid_0 &&
           (es_res_from_mem_0 || es_mem_we_0)) ? es_mem_we_0 :
           (es_lane1_eff_valid &&
           (es_res_from_mem_1 || es_mem_we_1)) ? es_mem_we_1 : 1'b0;
      ms_selected_store_is_ext_q <= (es_to_ms_valid_0 &&
           (es_res_from_mem_0 || es_mem_we_0)) ? es_final_result_0[22] :
           (es_lane1_eff_valid &&
           (es_res_from_mem_1 || es_mem_we_1)) ? es_final_result_1[22] : 1'b0;
      ms_addr_is_sram_0_q <= es_addr_is_sram_0;
      ms_addr_is_sram_1_q <= es_addr_is_sram_1;
      ms_lane1_mem_op_ctrl <= es_lane1_eff_valid &&
           (es_res_from_mem_1 || es_mem_we_1);
      ms_select_lane1_q <= !(es_to_ms_valid_0 &&
           (es_res_from_mem_0 || es_mem_we_0)) &&
           es_to_ms_valid_1 && (es_res_from_mem_1 || es_mem_we_1);
    end
    else if (advance_to_lane1)
    begin
      ms_valid_0 <= 1'b0;
      ms_valid_1 <= ms_lane1_eff_valid;
      ms_lane0_mem_op <= 1'b0;
      ms_lane1_mem_op <= ms_lane1_mem_op;
      ms_selected_mem_we_q <= ms_mem_we_1;
      ms_selected_store_is_ext_q <= ms_alu_result_1[22];
      ms_lane1_mem_op_ctrl <= ms_lane1_mem_op_ctrl;
      ms_select_lane1_q <= 1'b1;
    end
  end

  // WAIT_DATA 表示当前包含访存；双访存切换 lane 时保持该状态。
  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      ms_wait_kind <= WAIT_NONE;
    else if (ms_allowin)
    begin
      if (es_to_ms_valid_0 && es_is_cacop_0)
        ms_wait_kind <= WAIT_CACOP;
      else if (es_to_ms_valid_0 &&
               (es_res_from_mem_0 || es_mem_we_0))
        ms_wait_kind <= WAIT_DATA;
      else if (es_lane1_eff_valid &&
               (es_res_from_mem_1 || es_mem_we_1))
        ms_wait_kind <= WAIT_DATA;
      else
        ms_wait_kind <= WAIT_NONE;
    end
  end

  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      cacop_req_sent <= 1'b0;
    else if (ms_allowin)
      cacop_req_sent <= 1'b0;
    else if (icacop_req_valid && icacop_req_ready)
      cacop_req_sent <= 1'b1;
  end

  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      ms_addr_is_sram_q <= 1'b0;
    else if (early_load_accept)
      ms_addr_is_sram_q <= 1'b1;
    else if (ms_allowin || advance_to_lane1)
      ms_addr_is_sram_q <= 1'b0;
    else if (got_addr_ok)
      ms_addr_is_sram_q <= data_sram_addr_is_sram;
  end

  // 提前请求随 EX->MEM 的边沿记录。bridge 下一拍若返回接受脉冲，
  // 当前 load 接管该事务；否则 probe 清除并继续走普通 MEM 请求。
  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      ms_early_load_probe <= 1'b0;
    else if (early_sram_load_req)
      ms_early_load_probe <= early_sram_load_req;
    else if (ms_early_load_probe)
      ms_early_load_probe <= 1'b0;
  end

  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      ms_data_pending <= 1'b0;
    else if (got_addr_ok)
      ms_data_pending <= 1'b1;
    else if (ms_data_pending && data_sram_data_ok)
      ms_data_pending <= 1'b0;
  end

  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      ms_response_waiting <= 1'b0;
    else if (early_load_accept)
      ms_response_waiting <= 1'b1;
    else if (got_normal_addr_ok)
      ms_response_waiting <= !data_sram_wr ||
                             !data_sram_addr_is_sram;
    else if (ms_data_pending && data_sram_data_ok)
      ms_response_waiting <= 1'b0;
  end

  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      ms_fast_response_waiting <= 1'b0;
    else if (early_load_accept)
      ms_fast_response_waiting <= 1'b1;
    else if (got_normal_addr_ok)
      ms_fast_response_waiting <= !data_sram_wr ||
                                  !data_sram_addr_is_sram;
    else if (ms_data_pending && data_sram_data_ok)
      ms_fast_response_waiting <= 1'b0;
  end

  always @(posedge clk)
  begin
    if (reset || br_taken || branch_redirect_fire)
      ms_rdata_buf_valid <= 1'b0;
    else if (ms_allowin || advance_to_lane1)
      ms_rdata_buf_valid <= 1'b0;
    else if (ms_data_ok)
      ms_rdata_buf_valid <= 1'b1;
  end

  always @(posedge clk)
  begin
    if (ms_data_ok)
      ms_rdata_buf <= data_sram_rdata;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      ms_result_forwardable_0 <= 1'b0;
      ms_fwd_nonload_0  <= 1'b0;
      ms_pc_0           <= 32'b0;
      ms_gr_we_0        <= 1'b0;
      ms_mem_we_0       <= 1'b0;
      ms_res_from_mem_0 <= 1'b0;
      ms_dest_0         <= 5'b0;
      ms_alu_result_0   <= 32'b0;
      ms_rkd_value_0    <= 32'b0;
      ms_store_data_ready_0 <= 1'b1;
      ms_store_data_src_0  <= 5'b0;
      ms_ld_byte_0      <= 1'b0;
      ms_ld_half_0      <= 1'b0;
      ms_ld_sign_ext_0  <= 1'b0;
      ms_st_byte_0      <= 1'b0;
      ms_st_half_0      <= 1'b0;
      ms_pred_taken_0   <= 1'b0;
      ms_pred_target_0  <= 32'b0;
      ms_is_bj_0        <= 1'b0;
      ms_real_taken_0   <= 1'b0;
      ms_real_target_0  <= 32'b0;
      ms_next_pc_0      <= 32'b0;
      ms_redirect_miss_0 <= 1'b0;
      ms_is_cacop_0     <= 1'b0;
      ms_cacop_code_0   <= 5'b0;
      ms_is_csr_0       <= 1'b0;
      ms_csr_num_0      <= 14'b0;
      ms_csr_wmask_0    <= 32'b0;
      ms_csr_wvalue_0   <= 32'b0;

      ms_pc_1           <= 32'b0;
      ms_gr_we_1        <= 1'b0;
      ms_mem_we_1       <= 1'b0;
      ms_res_from_mem_1 <= 1'b0;
      ms_dest_1         <= 5'b0;
      ms_alu_result_1   <= 32'b0;
      ms_rkd_value_1    <= 32'b0;
      ms_ld_byte_1      <= 1'b0;
      ms_ld_half_1      <= 1'b0;
      ms_ld_sign_ext_1  <= 1'b0;
      ms_st_byte_1      <= 1'b0;
      ms_st_half_1      <= 1'b0;
      ms_pred_taken_1   <= 1'b0;
      ms_pred_target_1  <= 32'b0;
      ms_is_bj_1        <= 1'b0;
      ms_real_taken_1   <= 1'b0;
      ms_real_target_1  <= 32'b0;
      ms_next_pc_1      <= 32'b0;
      ms_redirect_miss_1 <= 1'b0;
    end
    else if (br_taken || branch_redirect_fire)
    begin
      ms_fwd_nonload_0  <= 1'b0;
      ms_gr_we_0        <= 1'b0;
      ms_mem_we_0       <= 1'b0;
      ms_store_data_ready_0 <= 1'b1;
      ms_store_data_src_0  <= 5'b0;
      ms_res_from_mem_0 <= 1'b0;
      ms_is_bj_0        <= 1'b0;
      ms_redirect_miss_0 <= 1'b0;
      ms_is_cacop_0     <= 1'b0;
      ms_gr_we_1        <= 1'b0;
      ms_mem_we_1       <= 1'b0;
      ms_res_from_mem_1 <= 1'b0;
      ms_is_bj_1        <= 1'b0;
      ms_redirect_miss_1 <= 1'b0;
    end
    else if (ms_allowin)
    begin
      if (es_to_ms_valid_0)
      begin
        ms_result_forwardable_0 <= es_result_forwardable_0;
        ms_fwd_nonload_0  <= !es_res_from_mem_0;
        ms_pc_0           <= es_pc_0;
        ms_alu_result_0   <= es_final_result_0;
        ms_rkd_value_0    <= incoming_store_data;
        ms_store_data_ready_0 <= incoming_store_data_ready;
        ms_store_data_src_0  <= es_store_data_src_0;
        ms_res_from_mem_0 <= es_res_from_mem_0;
        ms_gr_we_0        <= es_gr_we_0;
        ms_mem_we_0       <= es_mem_we_0;
        ms_dest_0         <= es_dest_0;
        ms_ld_byte_0      <= es_ld_byte_0;
        ms_ld_half_0      <= es_ld_half_0;
        ms_ld_sign_ext_0  <= es_ld_sign_ext_0;
        ms_st_byte_0      <= es_st_byte_0;
        ms_st_half_0      <= es_st_half_0;
        ms_pred_taken_0   <= es_pred_taken_0;
        ms_pred_target_0  <= es_pred_target_0;
        ms_is_bj_0        <= es_is_bj_0;
        ms_real_taken_0   <= es_real_taken_0;
        ms_real_target_0  <= es_real_target_0;
        ms_next_pc_0      <= es_next_pc_0;
        ms_redirect_miss_0 <= es_redirect_miss_0;
        ms_is_cacop_0     <= es_is_cacop_0;
        ms_cacop_code_0   <= es_cacop_code_0;
        ms_is_csr_0       <= es_is_csr_0;
        ms_csr_num_0      <= es_csr_num_0;
        ms_csr_wmask_0    <= es_csr_wmask_0;
        ms_csr_wvalue_0   <= es_csr_wvalue_0;
      end
      else
      begin
        ms_result_forwardable_0 <= 1'b0;
        ms_fwd_nonload_0  <= 1'b0;
        ms_gr_we_0        <= 1'b0;
        ms_mem_we_0       <= 1'b0;
        ms_store_data_ready_0 <= 1'b1;
        ms_store_data_src_0  <= 5'b0;
        ms_res_from_mem_0 <= 1'b0;
        ms_is_bj_0        <= 1'b0;
        ms_redirect_miss_0 <= 1'b0;
        ms_is_cacop_0     <= 1'b0;
        ms_is_csr_0       <= 1'b0;
      end

      if (es_to_ms_valid_1)
      begin
        ms_pc_1           <= es_pc_1;
        ms_alu_result_1   <= es_final_result_1;
        ms_rkd_value_1    <= es_rkd_value_1;
        ms_res_from_mem_1 <= es_res_from_mem_1;
        ms_gr_we_1        <= es_gr_we_1;
        ms_mem_we_1       <= es_mem_we_1;
        ms_dest_1         <= es_dest_1;
        ms_ld_byte_1      <= es_ld_byte_1;
        ms_ld_half_1      <= es_ld_half_1;
        ms_ld_sign_ext_1  <= es_ld_sign_ext_1;
        ms_st_byte_1      <= es_st_byte_1;
        ms_st_half_1      <= es_st_half_1;
        ms_pred_taken_1   <= es_pred_taken_1;
        ms_pred_target_1  <= es_pred_target_1;
        ms_is_bj_1        <= es_is_bj_1;
        ms_real_taken_1   <= es_real_taken_1;
        ms_real_target_1  <= es_real_target_1;
        ms_next_pc_1      <= es_next_pc_1;
        ms_redirect_miss_1 <= es_redirect_miss_1;
      end
      else
      begin
        ms_gr_we_1        <= 1'b0;
        ms_mem_we_1       <= 1'b0;
        ms_res_from_mem_1 <= 1'b0;
        ms_is_bj_1        <= 1'b0;
        ms_redirect_miss_1 <= 1'b0;
      end
    end
    else if (advance_to_lane1)
    begin
      ms_result_forwardable_0 <= 1'b0;
      ms_fwd_nonload_0  <= 1'b0;
      ms_gr_we_0        <= 1'b0;
      ms_mem_we_0       <= 1'b0;
      ms_res_from_mem_0 <= 1'b0;
      ms_is_bj_0        <= 1'b0;
      ms_redirect_miss_0 <= 1'b0;
      ms_is_cacop_0     <= 1'b0;
      ms_is_csr_0       <= 1'b0;
    end
    else if (held_store_hit_ws1 || held_store_hit_ws0)
    begin
      ms_rkd_value_0 <= held_store_hit_ws1 ?
                        ws_rf_wdata_1 : ws_rf_wdata_0;
      ms_store_data_ready_0 <= 1'b1;
    end
  end

`ifndef SYNTHESIS
  always @(posedge clk)
  begin
    if (resetn)
    begin
      if (ms_valid_0 && !ms_result_forwardable_0 && ms_fwd_valid_0)
        $fatal(1, "lane0 special result entered MEM forwarding");
      if (ms_res_from_mem_0 && ms_fwd_valid_0 && !ms_rdata_buf_valid)
        $fatal(1, "lane0 load forwarded an unregistered SRAM response");
      if (data_sram_req && data_sram_wr && !selected_store_data_ready)
        $fatal(1, "store request issued before its data became ready");
      if (ms_valid_1 && ms_res_from_mem_1 && ms_fwd_valid_1)
        $fatal(1, "lane1 load became forwardable before WB");
      if (dual_mem_phase_0 && ms_to_ws_valid_1)
        $fatal(1, "lane1 retired before lane0 in a dual memory packet");
      if (data_sram_req && ms_data_pending)
        $fatal(1, "memory request overlapped an outstanding transaction");
      if (early_sram_load_req &&
          (!(phase1_early_load || ex_early_load_req) ||
           early_sram_load_addr[22] != 1'b1))
        $fatal(1, "invalid ExtRAM early-load request");
      if (early_load_accept &&
          (!ms_early_load_probe || !ms_has_mem_op || selected_mem_we))
        $fatal(1, "early-load response was not owned by a MEM load");
      if (early_load_lane1 && es_lane0_mem_op_in)
        $fatal(1, "lane1 early load bypassed an older memory operation");
    end
  end
`endif

endmodule
