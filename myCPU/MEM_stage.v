`include "mycpu.vh"

module MEM_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         es_to_ms_valid_0,
    input  wire                         es_to_ms_valid_1,
    input  wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus_0,
    input  wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus_1,
    input  wire                         ws_allowin,
    output wire                         ms_allowin,
    output wire                         ms_to_ws_valid_0,
    output wire                         ms_to_ws_valid_1,
    output wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus_0,
    output wire [`MS_TO_WS_BUS_WD-1:0]  ms_to_ws_bus_1,
    output wire [`MS_FWD_BUS_WD-1:0]    ms_fwd_bus_0,
    output wire [`MS_FWD_BUS_WD-1:0]    ms_fwd_bus_1,
    output wire                         ms_wait_valid_0,
    output wire [ 4:0]                  ms_wait_dest_0,
    output wire                         ms_wait_valid_1,
    output wire [ 4:0]                  ms_wait_dest_1,
    output wire                         csr_busy,
    output wire                         br_taken,
    output wire [31:0]                  br_target,
    output wire                         bpu_valid,
    output wire                         bpu_is_bj,
    output wire [31:0]                  bpu_pc,
    output wire                         bpu_real_taken,
    output wire [31:0]                  bpu_real_target,
    output wire                         icacop_valid,
    output wire [ 4:0]                  icacop_code,
    output wire [31:0]                  icacop_addr,
    // 类SRAM 数据接口
    output wire                         data_sram_req,
    output wire                         data_sram_wr,
    output wire [ 1:0]                  data_sram_size,
    output wire [ 3:0]                  data_sram_wstrb,
    output wire [31:0]                  data_sram_addr,
    output wire [31:0]                  data_sram_wdata,
    input  wire                         data_sram_addr_ok,
    input  wire                         data_sram_data_ok,
    input  wire [31:0]                  data_sram_rdata
  );

  reg reset;
  always @(posedge clk) reset <= ~resetn;

  reg         ms_valid_0;
  reg  [31:0] ms_pc_0;
  reg  [31:0] ms_alu_result_0;
  reg  [31:0] ms_rkd_value_0;
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
  reg         ms_is_cacop_1;
  reg  [ 4:0] ms_cacop_code_1;
  reg         ms_is_csr_1;
  reg  [13:0] ms_csr_num_1;
  reg  [31:0] ms_csr_wmask_1;
  reg  [31:0] ms_csr_wvalue_1;

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

  assign {es_pc_0, es_final_result_0, es_rkd_value_0,
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
  wire        es_is_cacop_1;
  wire [ 4:0] es_cacop_code_1;
  wire        es_is_csr_1;
  wire [13:0] es_csr_num_1;
  wire [31:0] es_csr_wmask_1;
  wire [31:0] es_csr_wvalue_1;

  assign {es_pc_1, es_final_result_1, es_rkd_value_1,
          es_res_from_mem_1, es_gr_we_1, es_mem_we_1, es_dest_1,
          es_ld_byte_1, es_ld_half_1, es_ld_sign_ext_1,
          es_st_byte_1, es_st_half_1,
          es_pred_taken_1, es_pred_target_1,
          es_is_bj_1, es_real_taken_1, es_real_target_1,
          es_next_pc_1, es_redirect_miss_1,
          es_is_cacop_1, es_cacop_code_1,
          es_is_csr_1, es_csr_num_1, es_csr_wmask_1,
          es_csr_wvalue_1} = es_to_ms_bus_1;

  assign csr_busy = ms_valid_0 && ms_is_csr_0;

  wire ms_redirect_0_raw = ms_valid_0 && ms_is_bj_0 && ms_redirect_miss_0; // 分支预测错误，刷掉 lane1 的指令

  wire ms_lane1_eff_valid = ms_valid_1 && !ms_redirect_0_raw;  // 如果 lane0 分支预测错误，lane1 的指令就无效了
  wire ms_redirect_1_raw = ms_lane1_eff_valid && ms_is_bj_1 && ms_redirect_miss_1;

  wire lane0_mem_op = ms_valid_0 && (ms_res_from_mem_0 || ms_mem_we_0 || ms_is_cacop_0);
  wire lane1_mem_op = ms_lane1_eff_valid && (ms_res_from_mem_1 || ms_mem_we_1 || ms_is_cacop_1);
  wire select_lane1 = lane1_mem_op;

  wire selected_valid          = select_lane1 ? ms_lane1_eff_valid   : ms_valid_0;
  wire selected_res_from_mem   = select_lane1 ? ms_res_from_mem_1    : ms_res_from_mem_0;
  wire selected_mem_we         = select_lane1 ? ms_mem_we_1          : ms_mem_we_0;
  wire [31:0] selected_addr    = select_lane1 ? ms_alu_result_1      : ms_alu_result_0;
  wire [31:0] selected_rkd     = select_lane1 ? ms_rkd_value_1       : ms_rkd_value_0;
  wire        selected_ld_byte = select_lane1 ? ms_ld_byte_1         : ms_ld_byte_0;
  wire        selected_ld_half = select_lane1 ? ms_ld_half_1         : ms_ld_half_0;
  wire        selected_st_byte = select_lane1 ? ms_st_byte_1         : ms_st_byte_0;
  wire        selected_st_half = select_lane1 ? ms_st_half_1         : ms_st_half_0;
  wire        selected_is_cacop = select_lane1 ? ms_is_cacop_1       : ms_is_cacop_0;
  wire [ 4:0] selected_cacop_code = select_lane1 ? ms_cacop_code_1   : ms_cacop_code_0;

  wire ms_has_mem_op = selected_valid && !selected_is_cacop &&
       (selected_res_from_mem || selected_mem_we);

  // 处理 SRAM 的握手
  reg  ms_addr_sent;
  reg  ms_data_pending;
  reg  ms_rdata_buf_valid;
  reg  [31:0] ms_rdata_buf;

  wire got_addr_ok = data_sram_req && data_sram_addr_ok;
  wire ms_data_ok  = ms_addr_sent && data_sram_data_ok;
  wire mem_data_ready = ms_rdata_buf_valid;

  wire packet_valid = ms_valid_0 || ms_valid_1;
  wire ms_ready_go  = !ms_has_mem_op || mem_data_ready;
  assign ms_allowin = !packet_valid || (ms_ready_go && ws_allowin);
  wire ms_fire      = packet_valid && ms_ready_go && ws_allowin;

  assign icacop_valid = ms_fire && selected_valid && selected_is_cacop;
  assign icacop_code  = selected_cacop_code;
  assign icacop_addr  = selected_addr;

  assign ms_to_ws_valid_0 = ms_valid_0 && ms_ready_go;
  assign ms_to_ws_valid_1 = ms_lane1_eff_valid && ms_ready_go;

  // 分支预测与重定向
  assign br_taken  = ms_fire && (ms_redirect_0_raw || ms_redirect_1_raw);
  assign br_target = !br_taken ? 32'b0 :
         ms_redirect_0_raw ? (ms_real_taken_0 ? ms_real_target_0 : ms_next_pc_0) :
         (ms_real_taken_1 ? ms_real_target_1 : ms_next_pc_1);

  // 发出 BPU 更新信号
  wire bpu_sel_lane1 = !ms_is_bj_0 && ms_is_bj_1 && ms_lane1_eff_valid;

  assign bpu_valid       = ms_fire && ((ms_valid_0 && ms_is_bj_0) || (ms_lane1_eff_valid && ms_is_bj_1));
  assign bpu_is_bj       = bpu_valid;
  assign bpu_pc          = bpu_sel_lane1 ? ms_pc_1          : ms_pc_0;
  assign bpu_real_taken  = bpu_sel_lane1 ? ms_real_taken_1  : ms_real_taken_0;
  assign bpu_real_target = bpu_sel_lane1 ? ms_real_target_1 : ms_real_target_0;

  wire [31:0] ms_st_data = selected_st_byte ? {4{selected_rkd[7:0]}} :
       selected_st_half ? {2{selected_rkd[15:0]}} :
       selected_rkd;
  wire [ 3:0] ms_st_strb = selected_st_byte ? (4'b0001 << selected_addr[1:0]) :
       selected_st_half ? (selected_addr[1] ? 4'b1100 : 4'b0011) :
       4'b1111;
  wire [ 1:0] ms_mem_size = (selected_ld_byte || selected_st_byte) ? 2'b00 :
       (selected_ld_half || selected_st_half) ? 2'b01 :
       2'b10;

  assign data_sram_req   = ms_has_mem_op && !ms_addr_sent && !ms_data_pending;
  assign data_sram_wr    = selected_mem_we;
  assign data_sram_size  = ms_mem_size;
  assign data_sram_wstrb = selected_mem_we ? ms_st_strb : 4'b0;
  assign data_sram_addr  = selected_addr;
  assign data_sram_wdata = ms_st_data;

  wire [31:0] ms_final_rdata = ms_rdata_buf;

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

  wire [31:0] ms_load_result_0 = load_result(ms_alu_result_0, ms_final_rdata,
       ms_ld_byte_0, ms_ld_half_0, ms_ld_sign_ext_0);
  wire [31:0] ms_load_result_1 = load_result(ms_alu_result_1, ms_final_rdata,
       ms_ld_byte_1, ms_ld_half_1, ms_ld_sign_ext_1);

  wire ms_fwd_valid_0 = !ms_res_from_mem_0 || mem_data_ready;
  wire ms_fwd_valid_1 = !ms_res_from_mem_1 || mem_data_ready;
  wire [31:0] ms_fwd_data_0 = ms_res_from_mem_0 ? ms_load_result_0 : ms_alu_result_0;
  wire [31:0] ms_fwd_data_1 = ms_res_from_mem_1 ? ms_load_result_1 : ms_alu_result_1;

  assign ms_wait_valid_0 = ms_valid_0 && ms_gr_we_0 && (ms_dest_0 != 5'b0) &&
         ms_res_from_mem_0 && !mem_data_ready;
  assign ms_wait_dest_0  = ms_dest_0;
  assign ms_wait_valid_1 = ms_lane1_eff_valid && ms_gr_we_1 && (ms_dest_1 != 5'b0) &&
         ms_res_from_mem_1 && !mem_data_ready;
  assign ms_wait_dest_1  = ms_dest_1;

  assign ms_fwd_bus_0 = {ms_valid_0, ms_gr_we_0, ms_fwd_valid_0,
                         ms_res_from_mem_0, ms_dest_0, ms_fwd_data_0};
  assign ms_fwd_bus_1 = {ms_lane1_eff_valid, ms_gr_we_1, ms_fwd_valid_1,
                         ms_res_from_mem_1, ms_dest_1, ms_fwd_data_1};

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

  assign ms_to_ws_bus_1 = {ms_pc_1,
                           ms_alu_result_1,
                           ms_res_from_mem_1,
                           ms_gr_we_1,
                           ms_dest_1,
                           ms_ld_byte_1,
                           ms_ld_half_1,
                           ms_ld_sign_ext_1,
                           ms_final_rdata,
                           ms_is_csr_1,
                           ms_csr_num_1,
                           ms_csr_wmask_1,
                           ms_csr_wvalue_1
                          };

  always @(posedge clk)
  begin
    if (reset)
    begin
      ms_valid_0 <= 1'b0;
      ms_valid_1 <= 1'b0;
    end
    else if (br_taken)
    begin
      ms_valid_0 <= 1'b0;
      ms_valid_1 <= 1'b0;
    end
    else if (ms_allowin)
    begin
      ms_valid_0 <= es_to_ms_valid_0;
      ms_valid_1 <= es_to_ms_valid_1;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
      ms_addr_sent <= 1'b0;
    else if (ms_allowin || br_taken)
      ms_addr_sent <= 1'b0;
    else if (got_addr_ok)
      ms_addr_sent <= 1'b1;
  end

  always @(posedge clk)
  begin
    if (reset || br_taken)
      ms_data_pending <= 1'b0;
    else if (got_addr_ok)
      ms_data_pending <= 1'b1;
    else if (ms_data_pending && data_sram_data_ok)
      ms_data_pending <= 1'b0;
  end

  always @(posedge clk)
  begin
    if (reset || br_taken)
      ms_rdata_buf_valid <= 1'b0;
    else if (ms_allowin)
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
      ms_pc_0           <= 32'b0;
      ms_gr_we_0        <= 1'b0;
      ms_mem_we_0       <= 1'b0;
      ms_res_from_mem_0 <= 1'b0;
      ms_dest_0         <= 5'b0;
      ms_alu_result_0   <= 32'b0;
      ms_rkd_value_0    <= 32'b0;
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
      ms_is_cacop_1     <= 1'b0;
      ms_cacop_code_1   <= 5'b0;
      ms_is_csr_1       <= 1'b0;
      ms_csr_num_1      <= 14'b0;
      ms_csr_wmask_1    <= 32'b0;
      ms_csr_wvalue_1   <= 32'b0;
    end
    else if (br_taken)
    begin
      ms_gr_we_0        <= 1'b0;
      ms_mem_we_0       <= 1'b0;
      ms_res_from_mem_0 <= 1'b0;
      ms_is_bj_0        <= 1'b0;
      ms_redirect_miss_0 <= 1'b0;
      ms_is_cacop_0     <= 1'b0;
      ms_gr_we_1        <= 1'b0;
      ms_mem_we_1       <= 1'b0;
      ms_res_from_mem_1 <= 1'b0;
      ms_is_bj_1        <= 1'b0;
      ms_redirect_miss_1 <= 1'b0;
      ms_is_cacop_1     <= 1'b0;
    end
    else if (ms_allowin)
    begin
      if (es_to_ms_valid_0)
      begin
        ms_pc_0           <= es_pc_0;
        ms_alu_result_0   <= es_final_result_0;
        ms_rkd_value_0    <= es_rkd_value_0;
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
        ms_gr_we_0        <= 1'b0;
        ms_mem_we_0       <= 1'b0;
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
        ms_is_cacop_1     <= es_is_cacop_1;
        ms_cacop_code_1   <= es_cacop_code_1;
        ms_is_csr_1       <= es_is_csr_1;
        ms_csr_num_1      <= es_csr_num_1;
        ms_csr_wmask_1    <= es_csr_wmask_1;
        ms_csr_wvalue_1   <= es_csr_wvalue_1;
      end
      else
      begin
        ms_gr_we_1        <= 1'b0;
        ms_mem_we_1       <= 1'b0;
        ms_res_from_mem_1 <= 1'b0;
        ms_is_bj_1        <= 1'b0;
        ms_redirect_miss_1 <= 1'b0;
        ms_is_cacop_1     <= 1'b0;
        ms_is_csr_1       <= 1'b0;
      end
    end
  end

endmodule
