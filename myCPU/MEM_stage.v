`include "mycpu.vh"

module MEM_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         es_to_ms_valid_0,
    input  wire                         es_to_ms_valid_1,
    input  wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus_0,
    input  wire [`ES_TO_MS_BUS_1_WD-1:0] es_to_ms_bus_1,
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
    input  wire                         data_sram_addr_is_sram,
    input  wire                         data_sram_addr_ok,
    input  wire                         data_sram_data_ok,
    input  wire [31:0]                  data_sram_rdata
  );

  reg reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ms_valid_0;
  localparam [1:0] WAIT_NONE  = 2'd0;
  localparam [1:0] WAIT_DATA  = 2'd1;
  localparam [1:0] WAIT_CACOP = 2'd2;

  reg  [ 1:0] ms_wait_kind;

  reg         ms_result_forwardable_0;
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

  wire lane0_mem_op = ms_valid_0 &&
       (ms_res_from_mem_0 || ms_mem_we_0);
  wire lane1_mem_op = ms_lane1_eff_valid &&
       (ms_res_from_mem_1 || ms_mem_we_1);
  // lane0 优先；lane0 完成后清除 ms_valid_0，选择器自然转到 lane1。
  // 复用两个 valid 位表达串行相位，不增加访存队列或第二套状态机。
  wire select_lane1 = !lane0_mem_op && lane1_mem_op;
  wire selected_res_from_mem = select_lane1 ?
       ms_res_from_mem_1 : ms_res_from_mem_0;
  wire selected_mem_we = select_lane1 ? ms_mem_we_1 : ms_mem_we_0;
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
  wire ms_has_mem_op = lane0_mem_op || lane1_mem_op;
  wire ms_has_cacop = (ms_wait_kind == WAIT_CACOP);
  wire dual_mem_phase_0 = lane0_mem_op && lane1_mem_op;

  // 处理 SRAM 的握手
  reg  ms_data_pending;
  reg  ms_response_waiting;
  reg  ms_addr_is_sram_q;
  reg  ms_rdata_buf_valid;
  reg  [31:0] ms_rdata_buf;
  reg  cacop_req_sent;
  reg         branch_flush_q;
  reg  [31:0] branch_target_q;

  wire got_addr_ok = data_sram_req && data_sram_addr_ok;
  wire ms_data_ok  = ms_response_waiting && data_sram_data_ok;
  wire mem_data_ready = ms_rdata_buf_valid;

  wire packet_valid = ms_valid_0 || ms_valid_1;
  wire cacop_ready_go = cacop_req_sent && icacop_done;

  // SRAM bridge 在 addr_ok 时已经锁存了 store 的地址、数据和字节使能。
  wire posted_store_ready = selected_mem_we && ms_addr_is_sram_q;
  wire selected_mem_ready =
       selected_res_from_mem ? (mem_data_ready || ms_data_ok) :
       selected_mem_we ? (posted_store_ready || mem_data_ready) :
       1'b1;
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
  // CACOP retire 使用独立控制锥，避免把 SRAM data_ok 经由普通 MEM
  // phase_ready_go 组合路径带到全局 pipeline_flush。
  wire cacop_retire_fire = packet_valid && ms_has_cacop &&
       cacop_ready_go && ws_allowin;
  assign cacop_flush      = cacop_retire_fire;
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

  assign bpu_valid       = ms_fire &&
                           ((ms_valid_0 && ms_is_bj_0) ||
                            (ms_lane1_eff_valid && ms_is_bj_1));
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

  // 非 SRAM store 的返回先进入 rdata_buf，再在下一拍退休；该拍仍需
  // 阻止原指令重复发地址。Load 在 data_ok 拍直接退休，posted SRAM
  // store 则不会置 rdata_buf_valid。
  assign data_sram_req   = ms_has_mem_op && !ms_data_pending &&
       !ms_rdata_buf_valid &&
       (!selected_mem_we || selected_store_data_ready);
  assign data_sram_wr    = selected_mem_we;
  assign data_sram_size  = ms_mem_size;
  assign data_sram_wstrb = selected_mem_we ? ms_st_strb : 4'b0;
  assign data_sram_addr  = selected_addr;
  assign data_sram_wdata = ms_st_data;

  // data_ok 返回拍直接送 WB；若 WB 暂时不能接收，则下一拍回退到
  // 已寄存的 ms_rdata_buf。当前 WB 恒可接收，但保留后一条路径可
  // 避免接口约束变化时丢失响应。
  wire [31:0] ms_final_rdata =
       ms_data_ok ? data_sram_rdata : ms_rdata_buf;

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

  // 受控 Load 返回拍唤醒：只对片上 SRAM 的普通 lane0 Load 产生一次
  // 瞬时事件。ISSUE 复用普通 MEM 前递中的目的 tag 做精确 RAW
  // 放行，数据单独直达 EX 输入寄存器，不进入宽前递网络。
  assign load_wakeup_valid = !select_lane1 && ms_valid_0 && ms_data_ok &&
       ms_res_from_mem_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) &&
       ms_addr_is_sram_q;
  assign load_wakeup_data = ms_load_result_0;

  // 特殊结果只进入 WB；load 的 ISSUE 前递只能使用已经寄存的
  // ms_rdata_buf。ms_final_rdata 虽可在完成拍读取 SRAM 返回值，
  // 但 ms_fwd_valid_0 此时保持为 0，避免外部 SRAM 返回路径在
  // 同一周期穿过 MEM 前递网到达年轻指令的 EX 输入。
  wire ms_fwd_valid_0 = ms_result_forwardable_0 &&
       (!ms_res_from_mem_0 || mem_data_ready);
  wire [31:0] ms_load_result_0_fwd = load_result(
       ms_alu_result_0, ms_rdata_buf,
       ms_ld_byte_0, ms_ld_half_0, ms_ld_sign_ext_0);
  wire [31:0] ms_fwd_data_0 = ms_res_from_mem_0 ? ms_load_result_0_fwd :
       (ms_result_forwardable_0 ? ms_alu_result_0 : 32'b0);

  // 晚到 store data 只进入 MEM 本地寄存器，不参与 ISSUE 前递或
  // ms_allowin 的控制判定。Load 完成快路径下，后继 store 可在
  // data_ok 边沿直接锁存 load 结果；已寄存的 MEM 前递和 WB 前递
  // 则是等待/排队情况下的回退。
  wire incoming_store_hit_response =
       es_store_data_late_0 && ms_valid_0 && ms_gr_we_0 &&
       ms_res_from_mem_0 && ms_data_ok && (ms_dest_0 != 5'b0) &&
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
    end
    else if (br_taken || branch_redirect_fire)
    begin
      ms_valid_0 <= 1'b0;
      ms_valid_1 <= 1'b0;
    end
    else if (ms_allowin)
    begin
      ms_valid_0 <= es_to_ms_valid_0;
      ms_valid_1 <= es_lane1_eff_valid;
    end
    else if (advance_to_lane1)
    begin
      ms_valid_0 <= 1'b0;
      ms_valid_1 <= ms_lane1_eff_valid;
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
    else if (ms_allowin || advance_to_lane1)
      ms_addr_is_sram_q <= 1'b0;
    else if (got_addr_ok)
      ms_addr_is_sram_q <= data_sram_addr_is_sram;
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
    else if (got_addr_ok)
      ms_response_waiting <= !selected_mem_we ||
                             !data_sram_addr_is_sram;
    else if (ms_data_pending && data_sram_data_ok)
      ms_response_waiting <= 1'b0;
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
    end
  end
`endif

endmodule
