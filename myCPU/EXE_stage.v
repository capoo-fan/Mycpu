`include "mycpu.vh"

module EXE_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ds_to_es_valid_0,
    input  wire                         ds_to_es_valid_1,
    input  wire [`DS_TO_ES_BUS_WD-1:0]  ds_to_es_bus_0,
    input  wire [`DS_TO_ES_BUS_WD-1:0]  ds_to_es_bus_1,
    input  wire                         flush,
    input  wire                         ms_allowin,
    output wire                         es_allowin,
    output wire                         es_to_ms_valid_0,
    output wire                         es_to_ms_valid_1,
    output wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus_0,
    output wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus_1,
    input  wire [`MS_FWD_BUS_WD-1:0]    ms_fwd_bus_0,
    input  wire [`MS_FWD_BUS_WD-1:0]    ms_fwd_bus_1,
    input  wire [`WS_TO_RF_BUS_WD-1:0]  ws_to_rf_bus,
    output wire                         csr_busy,
    output wire                         cacop_busy,
    output wire [13:0]                  csr_raddr,
    input  wire [31:0]                  csr_rdata
  );

  reg reset;
  always @(posedge clk) reset <= ~resetn;

  reg         es_valid_0;
  reg  [31:0] es_pc_0;
  reg  [11:0] es_alu_op_0;
  reg  [31:0] es_rf_rdata1_0;
  reg  [31:0] es_rf_rdata2_0;
  reg  [ 4:0] es_raddr1_0;
  reg  [ 4:0] es_raddr2_0;
  reg  [31:0] es_imm_0;
  reg         es_src1_is_pc_0;
  reg         es_src2_is_imm_0;
  reg         es_need_rj_0;
  reg         es_need_rkd_0;
  reg         es_res_from_mem_0;
  reg         es_gr_we_0;
  reg         es_mem_we_0;
  reg  [ 4:0] es_dest_0;
  reg         es_is_mul_0;
  reg         es_mul_signed_0;
  reg         es_mul_hi_0;
  reg  [ 1:0] mul_cnt_0;
  reg         mul_pending_0;
  reg         es_ld_byte_0;
  reg         es_ld_half_0;
  reg         es_ld_sign_ext_0;
  reg         es_st_byte_0;
  reg         es_st_half_0;
  reg         es_pred_taken_0;
  reg  [31:0] es_pred_target_0;
  reg  [ 3:0] es_br_op_0;
  reg  [31:0] es_br_offs_0;
  reg         es_is_cpucfg_0;
  reg         es_is_cacop_0;
  reg  [ 4:0] es_cacop_code_0;
  reg         es_is_csr_0;
  reg         es_is_csrxchg_0;
  reg  [13:0] es_csr_num_0;

  reg         es_valid_1;
  reg  [31:0] es_pc_1;
  reg  [11:0] es_alu_op_1;
  reg  [31:0] es_rf_rdata1_1;
  reg  [31:0] es_rf_rdata2_1;
  reg  [ 4:0] es_raddr1_1;
  reg  [ 4:0] es_raddr2_1;
  reg  [31:0] es_imm_1;
  reg         es_src1_is_pc_1;
  reg         es_src2_is_imm_1;
  reg         es_need_rj_1;
  reg         es_need_rkd_1;
  reg         es_res_from_mem_1;
  reg         es_gr_we_1;
  reg         es_mem_we_1;
  reg  [ 4:0] es_dest_1;
  reg         es_is_mul_1;
  reg         es_mul_signed_1;
  reg         es_mul_hi_1;
  reg  [ 1:0] mul_cnt_1;
  reg         mul_pending_1;
  reg         es_ld_byte_1;
  reg         es_ld_half_1;
  reg         es_ld_sign_ext_1;
  reg         es_st_byte_1;
  reg         es_st_half_1;
  reg         es_pred_taken_1;
  reg  [31:0] es_pred_target_1;
  reg  [ 3:0] es_br_op_1;
  reg  [31:0] es_br_offs_1;
  reg         es_is_cpucfg_1;
  reg         es_is_cacop_1;
  reg  [ 4:0] es_cacop_code_1;
  reg         es_is_csr_1;
  reg         es_is_csrxchg_1;
  reg  [13:0] es_csr_num_1;

  // EX 包被乘法或 MEM 反压阻塞时，MEM/WB 旁路源可能继续前进并
  // 消失。首个停顿沿锁存已经选好的操作数，保证整个 EX 驻留期间稳定。
  reg         es_operands_held;
  reg  [31:0] es_rj_hold_0;
  reg  [31:0] es_rkd_hold_0;
  reg  [31:0] es_rj_hold_1;
  reg  [31:0] es_rkd_hold_1;

  wire [31:0] ds_pc_0;
  wire [11:0] ds_alu_op_0;
  wire [31:0] ds_rf_rdata1_0;
  wire [31:0] ds_rf_rdata2_0;
  wire [ 4:0] ds_raddr1_0;
  wire [ 4:0] ds_raddr2_0;
  wire [31:0] ds_imm_0;
  wire        ds_src1_is_pc_0;
  wire        ds_src2_is_imm_0;
  wire        ds_need_rj_0;
  wire        ds_need_rkd_0;
  wire        ds_res_from_mem_0;
  wire        ds_gr_we_0;
  wire        ds_mem_we_0;
  wire [ 4:0] ds_dest_0;
  wire        ds_is_mul_0;
  wire        ds_mul_signed_0;
  wire        ds_mul_hi_0;
  wire        ds_ld_byte_0;
  wire        ds_ld_half_0;
  wire        ds_ld_sign_ext_0;
  wire        ds_st_byte_0;
  wire        ds_st_half_0;
  wire        ds_pred_taken_0;
  wire [31:0] ds_pred_target_0;
  wire [ 3:0] ds_br_op_0;
  wire [31:0] ds_br_offs_0;
  wire        ds_is_cpucfg_0;
  wire        ds_is_cacop_0;
  wire [ 4:0] ds_cacop_code_0;
  wire        ds_is_csr_0;
  wire        ds_is_csrxchg_0;
  wire [13:0] ds_csr_num_0;

  assign {ds_pc_0, ds_alu_op_0,
          ds_rf_rdata1_0, ds_rf_rdata2_0, ds_raddr1_0, ds_raddr2_0,
          ds_imm_0, ds_src1_is_pc_0, ds_src2_is_imm_0,
          ds_need_rj_0, ds_need_rkd_0,
          ds_res_from_mem_0, ds_gr_we_0, ds_mem_we_0, ds_dest_0,
          ds_is_mul_0, ds_mul_signed_0, ds_mul_hi_0,
          ds_ld_byte_0, ds_ld_half_0, ds_ld_sign_ext_0,
          ds_st_byte_0, ds_st_half_0,
          ds_pred_taken_0, ds_pred_target_0, ds_br_op_0, ds_br_offs_0,
          ds_is_cpucfg_0, ds_is_cacop_0, ds_cacop_code_0,
          ds_is_csr_0, ds_is_csrxchg_0, ds_csr_num_0} = ds_to_es_bus_0;

  wire [31:0] ds_pc_1;
  wire [11:0] ds_alu_op_1;
  wire [31:0] ds_rf_rdata1_1;
  wire [31:0] ds_rf_rdata2_1;
  wire [ 4:0] ds_raddr1_1;
  wire [ 4:0] ds_raddr2_1;
  wire [31:0] ds_imm_1;
  wire        ds_src1_is_pc_1;
  wire        ds_src2_is_imm_1;
  wire        ds_need_rj_1;
  wire        ds_need_rkd_1;
  wire        ds_res_from_mem_1;
  wire        ds_gr_we_1;
  wire        ds_mem_we_1;
  wire [ 4:0] ds_dest_1;
  wire        ds_is_mul_1;
  wire        ds_mul_signed_1;
  wire        ds_mul_hi_1;
  wire        ds_ld_byte_1;
  wire        ds_ld_half_1;
  wire        ds_ld_sign_ext_1;
  wire        ds_st_byte_1;
  wire        ds_st_half_1;
  wire        ds_pred_taken_1;
  wire [31:0] ds_pred_target_1;
  wire [ 3:0] ds_br_op_1;
  wire [31:0] ds_br_offs_1;
  wire        ds_is_cpucfg_1;
  wire        ds_is_cacop_1;
  wire [ 4:0] ds_cacop_code_1;
  wire        ds_is_csr_1;
  wire        ds_is_csrxchg_1;
  wire [13:0] ds_csr_num_1;

  assign {ds_pc_1, ds_alu_op_1,
          ds_rf_rdata1_1, ds_rf_rdata2_1, ds_raddr1_1, ds_raddr2_1,
          ds_imm_1, ds_src1_is_pc_1, ds_src2_is_imm_1,
          ds_need_rj_1, ds_need_rkd_1,
          ds_res_from_mem_1, ds_gr_we_1, ds_mem_we_1, ds_dest_1,
          ds_is_mul_1, ds_mul_signed_1, ds_mul_hi_1,
          ds_ld_byte_1, ds_ld_half_1, ds_ld_sign_ext_1,
          ds_st_byte_1, ds_st_half_1,
          ds_pred_taken_1, ds_pred_target_1, ds_br_op_1, ds_br_offs_1,
          ds_is_cpucfg_1, ds_is_cacop_1, ds_cacop_code_1,
          ds_is_csr_1, ds_is_csrxchg_1, ds_csr_num_1} = ds_to_es_bus_1;

  // 乘法 IP 的结果在进入 EX 后第三拍可用。mul_pending 在倒数一拍
  // 的时钟沿清零，使完成状态先寄存，再送往 ISSUE，切断计数器到
  // InstBuffer 的跨级组合控制链。
  wire lane0_ready = !es_valid_0 || !mul_pending_0;
  wire lane1_ready = !es_valid_1 || !mul_pending_1;
  wire es_ready_go = lane0_ready && lane1_ready;
  wire es_busy     = es_valid_0 || es_valid_1;

  assign es_allowin       = !es_busy || (es_ready_go && ms_allowin);
  assign es_to_ms_valid_0 = es_valid_0 && es_ready_go;
  assign es_to_ms_valid_1 = es_valid_1 && es_ready_go;

  wire        ms_valid_0;
  wire        ms_gr_we_0;
  wire        ms_fwd_valid_0;
  wire        ms_res_from_mem_0;
  wire [ 4:0] ms_dest_0;
  wire [31:0] ms_fwd_data_0;
  wire        ms_valid_1;
  wire        ms_gr_we_1;
  wire        ms_fwd_valid_1;
  wire        ms_res_from_mem_1;
  wire [ 4:0] ms_dest_1;
  wire [31:0] ms_fwd_data_1;

  assign {ms_valid_0, ms_gr_we_0, ms_fwd_valid_0,
          ms_res_from_mem_0, ms_dest_0, ms_fwd_data_0} = ms_fwd_bus_0;
  assign {ms_valid_1, ms_gr_we_1, ms_fwd_valid_1,
          ms_res_from_mem_1, ms_dest_1, ms_fwd_data_1} = ms_fwd_bus_1;

  wire        ws_rf_we_0;
  wire [ 4:0] ws_rf_waddr_0;
  wire [31:0] ws_rf_wdata_0;
  wire        ws_rf_we_1;
  wire [ 4:0] ws_rf_waddr_1;
  wire [31:0] ws_rf_wdata_1;

  assign {ws_rf_we_0, ws_rf_waddr_0, ws_rf_wdata_0,
          ws_rf_we_1, ws_rf_waddr_1, ws_rf_wdata_1} = ws_to_rf_bus;

  function [31:0] select_bypass_data;
    input        src_valid;
    input [ 4:0] src_addr;
    input [31:0] rf_data;
    input        mem1_valid;
    input [ 4:0] mem1_addr;
    input [31:0] mem1_data;
    input        mem0_valid;
    input [ 4:0] mem0_addr;
    input [31:0] mem0_data;
    input        wb1_valid;
    input [ 4:0] wb1_addr;
    input [31:0] wb1_data;
    input        wb0_valid;
    input [ 4:0] wb0_addr;
    input [31:0] wb0_data;
    reg          sel_mem1;
    reg          sel_mem0;
    reg          sel_wb1;
    reg          sel_wb0;
    reg          sel_rf;
    begin
      sel_mem1 = src_valid && mem1_valid && (mem1_addr == src_addr);
      sel_mem0 = !sel_mem1 && src_valid && mem0_valid &&
                 (mem0_addr == src_addr);
      sel_wb1  = !(sel_mem1 || sel_mem0) && src_valid && wb1_valid &&
                 (wb1_addr == src_addr);
      sel_wb0  = !(sel_mem1 || sel_mem0 || sel_wb1) && src_valid &&
                 wb0_valid && (wb0_addr == src_addr);
      sel_rf   = !(sel_mem1 || sel_mem0 || sel_wb1 || sel_wb0);
      select_bypass_data = ({32{sel_mem1}} & mem1_data) |
                           ({32{sel_mem0}} & mem0_data) |
                           ({32{sel_wb1 }} & wb1_data) |
                           ({32{sel_wb0 }} & wb0_data) |
                           ({32{sel_rf  }} & rf_data);
    end
  endfunction

  wire ms0_bypass_valid = ms_valid_0 && ms_gr_we_0 && ms_fwd_valid_0 &&
       (ms_dest_0 != 5'b0);
  wire ms1_bypass_valid = ms_valid_1 && ms_gr_we_1 && ms_fwd_valid_1 &&
       (ms_dest_1 != 5'b0);
  wire ws0_bypass_valid = ws_rf_we_0 && (ws_rf_waddr_0 != 5'b0);
  wire ws1_bypass_valid = ws_rf_we_1 && (ws_rf_waddr_1 != 5'b0);

  wire [31:0] es_rj_bypass_0 = select_bypass_data(
       es_need_rj_0 && (es_raddr1_0 != 5'b0), es_raddr1_0, es_rf_rdata1_0,
       ms1_bypass_valid, ms_dest_1, ms_fwd_data_1,
       ms0_bypass_valid, ms_dest_0, ms_fwd_data_0,
       ws1_bypass_valid, ws_rf_waddr_1, ws_rf_wdata_1,
       ws0_bypass_valid, ws_rf_waddr_0, ws_rf_wdata_0);
  wire [31:0] es_rkd_bypass_0 = select_bypass_data(
       es_need_rkd_0 && (es_raddr2_0 != 5'b0), es_raddr2_0, es_rf_rdata2_0,
       ms1_bypass_valid, ms_dest_1, ms_fwd_data_1,
       ms0_bypass_valid, ms_dest_0, ms_fwd_data_0,
       ws1_bypass_valid, ws_rf_waddr_1, ws_rf_wdata_1,
       ws0_bypass_valid, ws_rf_waddr_0, ws_rf_wdata_0);

  wire [31:0] es_rj_bypass_1 = select_bypass_data(
       es_need_rj_1 && (es_raddr1_1 != 5'b0), es_raddr1_1, es_rf_rdata1_1,
       ms1_bypass_valid, ms_dest_1, ms_fwd_data_1,
       ms0_bypass_valid, ms_dest_0, ms_fwd_data_0,
       ws1_bypass_valid, ws_rf_waddr_1, ws_rf_wdata_1,
       ws0_bypass_valid, ws_rf_waddr_0, ws_rf_wdata_0);
  wire [31:0] es_rkd_bypass_1 = select_bypass_data(
       es_need_rkd_1 && (es_raddr2_1 != 5'b0), es_raddr2_1, es_rf_rdata2_1,
       ms1_bypass_valid, ms_dest_1, ms_fwd_data_1,
       ms0_bypass_valid, ms_dest_0, ms_fwd_data_0,
       ws1_bypass_valid, ws_rf_waddr_1, ws_rf_wdata_1,
       ws0_bypass_valid, ws_rf_waddr_0, ws_rf_wdata_0);

  wire [31:0] es_rj_value_0 =
       es_operands_held ? es_rj_hold_0 : es_rj_bypass_0;
  wire [31:0] es_rkd_value_raw_0 =
       es_operands_held ? es_rkd_hold_0 : es_rkd_bypass_0;
  wire [31:0] es_rj_value_1 =
       es_operands_held ? es_rj_hold_1 : es_rj_bypass_1;
  wire [31:0] es_rkd_value_raw_1 =
       es_operands_held ? es_rkd_hold_1 : es_rkd_bypass_1;

  wire [31:0] es_alu_src1_0 = es_src1_is_pc_0 ? es_pc_0 : es_rj_value_0;
  wire [31:0] es_alu_src2_0 = es_src2_is_imm_0 ? es_imm_0 : es_rkd_value_raw_0;
  wire [31:0] es_rkd_value_0 =
       (es_br_op_0 == `BR_JIRL) ? es_rj_value_0 : es_rkd_value_raw_0;
  wire [31:0] es_csr_wmask_0 =
       es_is_csrxchg_0 ? es_rj_value_0 : 32'hffff_ffff;
  wire [31:0] es_csr_wvalue_0 = es_rkd_value_raw_0;

  wire [31:0] es_alu_src1_1 = es_src1_is_pc_1 ? es_pc_1 : es_rj_value_1;
  wire [31:0] es_alu_src2_1 = es_src2_is_imm_1 ? es_imm_1 : es_rkd_value_raw_1;
  wire [31:0] es_rkd_value_1 =
       (es_br_op_1 == `BR_JIRL) ? es_rj_value_1 : es_rkd_value_raw_1;
  wire [31:0] es_csr_wmask_1 =
       es_is_csrxchg_1 ? es_rj_value_1 : 32'hffff_ffff;
  wire [31:0] es_csr_wvalue_1 = es_rkd_value_raw_1;

  wire [31:0] alu_result_0;
  wire [63:0] mul_product_0;
  wire [31:0] alu_result_1;
  wire [63:0] mul_product_1;

  function [31:0] cpucfg_result;
    input [31:0] index;
    begin
      case (index)
        32'h00000000:
          cpucfg_result = 32'h00000000;
        32'h00000001:
          cpucfg_result = 32'h0001f1f0;
        32'h00000010:
          cpucfg_result = 32'h00000001;
        32'h00000011:
          cpucfg_result = 32'h04030001;
        default:
          cpucfg_result = 32'h00000000;
      endcase
    end
  endfunction

  wire [31:0] es_mul_result_0 = es_mul_hi_0 ? mul_product_0[63:32] : mul_product_0[31:0];
  wire [31:0] es_mul_result_1 = es_mul_hi_1 ? mul_product_1[63:32] : mul_product_1[31:0];
  assign csr_raddr = es_csr_num_0;
  assign csr_busy  = es_valid_0 && es_is_csr_0;
  assign cacop_busy = es_valid_0 && es_is_cacop_0;

  wire [31:0] es_exec_result_0 = es_is_mul_0 ? es_mul_result_0 : alu_result_0;
  wire [31:0] es_exec_result_1 = es_is_mul_1 ? es_mul_result_1 : alu_result_1;
  wire [31:0] es_final_result_0 = es_is_csr_0 ? csr_rdata :
       es_is_cpucfg_0 ? cpucfg_result(es_alu_src1_0) : es_exec_result_0;
  wire [31:0] es_final_result_1 = es_is_cpucfg_1 ?
       cpucfg_result(es_alu_src1_1) : es_exec_result_1;

  //去除掉低频指令的前递
  wire es_result_forwardable_0 =
       !(es_is_csr_0 || es_is_cpucfg_0 || es_is_cacop_0);
  wire es_result_forwardable_1 =
       !(es_is_csr_1 || es_is_cpucfg_1 || es_is_cacop_1);

  wire        es_is_bj_0;
  wire        es_real_taken_0;
  wire [31:0] es_real_target_0;
  wire [31:0] es_next_pc_0;

  branch_judge u_branch_judge_0(
                 .br_op       (es_br_op_0),
                 .pc          (es_pc_0),
                 .src1        (es_alu_src1_0),
                 .rkd_value   (es_rkd_value_0),
                 .br_offs     (es_br_offs_0),
                 .is_bj       (es_is_bj_0),
                 .real_taken  (es_real_taken_0),
                 .real_target (es_real_target_0),
                 .next_pc     (es_next_pc_0)
               );

  wire        es_is_bj_1;
  wire        es_real_taken_1;
  wire [31:0] es_real_target_1;
  wire [31:0] es_next_pc_1;

  branch_judge u_branch_judge_1(
                 .br_op       (es_br_op_1),
                 .pc          (es_pc_1),
                 .src1        (es_alu_src1_1),
                 .rkd_value   (es_rkd_value_1),
                 .br_offs     (es_br_offs_1),
                 .is_bj       (es_is_bj_1),
                 .real_taken  (es_real_taken_1),
                 .real_target (es_real_target_1),
                 .next_pc     (es_next_pc_1)
               );

  wire es_taken_miss_0  = es_real_taken_0 ^ es_pred_taken_0;
  wire es_target_miss_0 = es_real_taken_0 && es_pred_taken_0 &&
       (es_real_target_0 != es_pred_target_0);
  wire es_redirect_miss_0 = es_is_bj_0 && (es_taken_miss_0 || es_target_miss_0);

  wire es_taken_miss_1  = es_real_taken_1 ^ es_pred_taken_1;
  wire es_target_miss_1 = es_real_taken_1 && es_pred_taken_1 &&
       (es_real_target_1 != es_pred_target_1);
  wire es_redirect_miss_1 = es_is_bj_1 && (es_taken_miss_1 || es_target_miss_1);

  assign es_to_ms_bus_0 = {es_result_forwardable_0,
                           es_pc_0,
                           es_final_result_0,
                           es_rkd_value_0,
                           es_res_from_mem_0,
                           es_gr_we_0,
                           es_mem_we_0,
                           es_dest_0,
                           es_ld_byte_0,
                           es_ld_half_0,
                           es_ld_sign_ext_0,
                           es_st_byte_0,
                           es_st_half_0,
                           es_pred_taken_0,
                           es_pred_target_0,
                           es_is_bj_0,
                           es_real_taken_0,
                           es_real_target_0,
                           es_next_pc_0,
                           es_redirect_miss_0,
                           es_is_cacop_0,
                           es_cacop_code_0,
                           es_is_csr_0,
                           es_csr_num_0,
                           es_csr_wmask_0,
                           es_csr_wvalue_0
                          };

  assign es_to_ms_bus_1 = {es_result_forwardable_1,
                           es_pc_1,
                           es_final_result_1,
                           es_rkd_value_1,
                           es_res_from_mem_1,
                           es_gr_we_1,
                           es_mem_we_1,
                           es_dest_1,
                           es_ld_byte_1,
                           es_ld_half_1,
                           es_ld_sign_ext_1,
                           es_st_byte_1,
                           es_st_half_1,
                           es_pred_taken_1,
                           es_pred_target_1,
                           es_is_bj_1,
                           es_real_taken_1,
                           es_real_target_1,
                           es_next_pc_1,
                           es_redirect_miss_1,
                           es_is_cacop_1,
                           es_cacop_code_1,
                           es_is_csr_1,
                           es_csr_num_1,
                           es_csr_wmask_1,
                           es_csr_wvalue_1
                          };

  always @(posedge clk)
  begin
    if (reset)
    begin
      es_valid_0 <= 1'b0;
      es_valid_1 <= 1'b0;
    end
    else if (flush)
    begin
      es_valid_0 <= 1'b0;
      es_valid_1 <= 1'b0;
    end
    else if (es_allowin)
    begin
      es_valid_0 <= ds_to_es_valid_0;
      es_valid_1 <= ds_to_es_valid_1;
    end
  end

  always @(posedge clk)
  begin
    if (reset || flush)
    begin
      es_operands_held <= 1'b0;
      es_rj_hold_0     <= 32'b0;
      es_rkd_hold_0    <= 32'b0;
      es_rj_hold_1     <= 32'b0;
      es_rkd_hold_1    <= 32'b0;
    end
    else if (es_allowin)
    begin
      es_operands_held <= 1'b0;
    end
    else if (!es_operands_held && es_busy)
    begin
      es_operands_held <= 1'b1;
      es_rj_hold_0     <= es_rj_bypass_0;
      es_rkd_hold_0    <= es_rkd_bypass_0;
      es_rj_hold_1     <= es_rj_bypass_1;
      es_rkd_hold_1    <= es_rkd_bypass_1;
    end
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      es_pc_0           <= 32'b0;
      es_gr_we_0        <= 1'b0;
      es_mem_we_0       <= 1'b0;
      es_res_from_mem_0 <= 1'b0;
      es_dest_0         <= 5'b0;
      es_alu_op_0       <= 12'b0;
      es_rf_rdata1_0    <= 32'b0;
      es_rf_rdata2_0    <= 32'b0;
      es_raddr1_0       <= 5'b0;
      es_raddr2_0       <= 5'b0;
      es_imm_0          <= 32'b0;
      es_src1_is_pc_0   <= 1'b0;
      es_src2_is_imm_0  <= 1'b0;
      es_need_rj_0      <= 1'b0;
      es_need_rkd_0     <= 1'b0;
      es_is_mul_0       <= 1'b0;
      es_mul_signed_0   <= 1'b0;
      es_mul_hi_0       <= 1'b0;
      es_ld_byte_0      <= 1'b0;
      es_ld_half_0      <= 1'b0;
      es_ld_sign_ext_0  <= 1'b0;
      es_st_byte_0      <= 1'b0;
      es_st_half_0      <= 1'b0;
      es_pred_taken_0   <= 1'b0;
      es_pred_target_0  <= 32'b0;
      es_br_op_0        <= `BR_NONE;
      es_br_offs_0      <= 32'b0;
      es_is_cpucfg_0    <= 1'b0;
      es_is_cacop_0     <= 1'b0;
      es_cacop_code_0   <= 5'b0;
      es_is_csr_0       <= 1'b0;
      es_is_csrxchg_0   <= 1'b0;
      es_csr_num_0      <= 14'b0;

      es_pc_1           <= 32'b0;
      es_gr_we_1        <= 1'b0;
      es_mem_we_1       <= 1'b0;
      es_res_from_mem_1 <= 1'b0;
      es_dest_1         <= 5'b0;
      es_alu_op_1       <= 12'b0;
      es_rf_rdata1_1    <= 32'b0;
      es_rf_rdata2_1    <= 32'b0;
      es_raddr1_1       <= 5'b0;
      es_raddr2_1       <= 5'b0;
      es_imm_1          <= 32'b0;
      es_src1_is_pc_1   <= 1'b0;
      es_src2_is_imm_1  <= 1'b0;
      es_need_rj_1      <= 1'b0;
      es_need_rkd_1     <= 1'b0;
      es_is_mul_1       <= 1'b0;
      es_mul_signed_1   <= 1'b0;
      es_mul_hi_1       <= 1'b0;
      es_ld_byte_1      <= 1'b0;
      es_ld_half_1      <= 1'b0;
      es_ld_sign_ext_1  <= 1'b0;
      es_st_byte_1      <= 1'b0;
      es_st_half_1      <= 1'b0;
      es_pred_taken_1   <= 1'b0;
      es_pred_target_1  <= 32'b0;
      es_br_op_1        <= `BR_NONE;
      es_br_offs_1      <= 32'b0;
      es_is_cpucfg_1    <= 1'b0;
      es_is_cacop_1     <= 1'b0;
      es_cacop_code_1   <= 5'b0;
      es_is_csr_1       <= 1'b0;
      es_is_csrxchg_1   <= 1'b0;
      es_csr_num_1      <= 14'b0;
    end
    else if (flush)
    begin
      es_gr_we_0        <= 1'b0;
      es_mem_we_0       <= 1'b0;
      es_res_from_mem_0 <= 1'b0;
      es_is_mul_0       <= 1'b0;
      es_br_op_0        <= `BR_NONE;
      es_is_cpucfg_0    <= 1'b0;
      es_is_cacop_0     <= 1'b0;
      es_is_csr_0       <= 1'b0;
      es_is_csrxchg_0   <= 1'b0;
      es_gr_we_1        <= 1'b0;
      es_mem_we_1       <= 1'b0;
      es_res_from_mem_1 <= 1'b0;
      es_is_mul_1       <= 1'b0;
      es_br_op_1        <= `BR_NONE;
      es_is_cpucfg_1    <= 1'b0;
      es_is_cacop_1     <= 1'b0;
      es_is_csr_1       <= 1'b0;
      es_is_csrxchg_1   <= 1'b0;
    end
    else if (es_allowin)
    begin
      // Payload follows es_allowin only.  The issue decision is captured by
      // es_valid_* and must not become the CE of the wide EX register banks.
      // Architectural side-effect controls remain zero for an invalid lane.
      es_pc_0           <= ds_pc_0;
      es_alu_op_0       <= ds_alu_op_0;
      es_rf_rdata1_0    <= ds_rf_rdata1_0;
      es_rf_rdata2_0    <= ds_rf_rdata2_0;
      es_raddr1_0       <= ds_raddr1_0;
      es_raddr2_0       <= ds_raddr2_0;
      es_imm_0          <= ds_imm_0;
      es_src1_is_pc_0   <= ds_src1_is_pc_0;
      es_src2_is_imm_0  <= ds_src2_is_imm_0;
      es_need_rj_0      <= ds_need_rj_0;
      es_need_rkd_0     <= ds_need_rkd_0;
      es_res_from_mem_0 <= ds_to_es_valid_0 && ds_res_from_mem_0;
      es_gr_we_0        <= ds_to_es_valid_0 && ds_gr_we_0;
      es_mem_we_0       <= ds_to_es_valid_0 && ds_mem_we_0;
      es_dest_0         <= ds_dest_0;
      es_is_mul_0       <= ds_to_es_valid_0 && ds_is_mul_0;
      es_mul_signed_0   <= ds_mul_signed_0;
      es_mul_hi_0       <= ds_mul_hi_0;
      es_ld_byte_0      <= ds_ld_byte_0;
      es_ld_half_0      <= ds_ld_half_0;
      es_ld_sign_ext_0  <= ds_ld_sign_ext_0;
      es_st_byte_0      <= ds_st_byte_0;
      es_st_half_0      <= ds_st_half_0;
      es_pred_taken_0   <= ds_pred_taken_0;
      es_pred_target_0  <= ds_pred_target_0;
      es_br_op_0        <= ds_to_es_valid_0 ? ds_br_op_0 : `BR_NONE;
      es_br_offs_0      <= ds_br_offs_0;
      es_is_cpucfg_0    <= ds_to_es_valid_0 && ds_is_cpucfg_0;
      es_is_cacop_0     <= ds_to_es_valid_0 && ds_is_cacop_0;
      es_cacop_code_0   <= ds_cacop_code_0;
      es_is_csr_0       <= ds_to_es_valid_0 && ds_is_csr_0;
      es_is_csrxchg_0   <= ds_to_es_valid_0 && ds_is_csrxchg_0;
      es_csr_num_0      <= ds_csr_num_0;

      es_pc_1           <= ds_pc_1;
      es_alu_op_1       <= ds_alu_op_1;
      es_rf_rdata1_1    <= ds_rf_rdata1_1;
      es_rf_rdata2_1    <= ds_rf_rdata2_1;
      es_raddr1_1       <= ds_raddr1_1;
      es_raddr2_1       <= ds_raddr2_1;
      es_imm_1          <= ds_imm_1;
      es_src1_is_pc_1   <= ds_src1_is_pc_1;
      es_src2_is_imm_1  <= ds_src2_is_imm_1;
      es_need_rj_1      <= ds_need_rj_1;
      es_need_rkd_1     <= ds_need_rkd_1;
      es_res_from_mem_1 <= ds_to_es_valid_1 && ds_res_from_mem_1;
      es_gr_we_1        <= ds_to_es_valid_1 && ds_gr_we_1;
      es_mem_we_1       <= ds_to_es_valid_1 && ds_mem_we_1;
      es_dest_1         <= ds_dest_1;
      es_is_mul_1       <= ds_to_es_valid_1 && ds_is_mul_1;
      es_mul_signed_1   <= ds_mul_signed_1;
      es_mul_hi_1       <= ds_mul_hi_1;
      es_ld_byte_1      <= ds_ld_byte_1;
      es_ld_half_1      <= ds_ld_half_1;
      es_ld_sign_ext_1  <= ds_ld_sign_ext_1;
      es_st_byte_1      <= ds_st_byte_1;
      es_st_half_1      <= ds_st_half_1;
      es_pred_taken_1   <= ds_pred_taken_1;
      es_pred_target_1  <= ds_pred_target_1;
      es_br_op_1        <= ds_to_es_valid_1 ? ds_br_op_1 : `BR_NONE;
      es_br_offs_1      <= ds_br_offs_1;
      es_is_cpucfg_1    <= ds_to_es_valid_1 && ds_is_cpucfg_1;
      es_is_cacop_1     <= ds_to_es_valid_1 && ds_is_cacop_1;
      es_cacop_code_1   <= ds_cacop_code_1;
      es_is_csr_1       <= ds_to_es_valid_1 && ds_is_csr_1;
      es_is_csrxchg_1   <= ds_to_es_valid_1 && ds_is_csrxchg_1;
      es_csr_num_1      <= ds_csr_num_1;
    end
  end

  always @(posedge clk)
  begin
    if (reset || flush)
    begin
      mul_cnt_0     <= 2'd0;
      mul_pending_0 <= 1'b0;
    end
    else if (es_allowin)
    begin
      mul_cnt_0     <= 2'd0;
      mul_pending_0 <= ds_to_es_valid_0 && ds_is_mul_0;
    end
    else if (mul_pending_0)
    begin
      if (mul_cnt_0 == 2'd2)
      begin
        mul_cnt_0     <= 2'd3;
        mul_pending_0 <= 1'b0;
      end
      else
        mul_cnt_0 <= mul_cnt_0 + 2'd1;
    end
  end

  always @(posedge clk)
  begin
    if (reset || flush)
    begin
      mul_cnt_1     <= 2'd0;
      mul_pending_1 <= 1'b0;
    end
    else if (es_allowin)
    begin
      mul_cnt_1     <= 2'd0;
      mul_pending_1 <= ds_to_es_valid_1 && ds_is_mul_1;
    end
    else if (mul_pending_1)
    begin
      if (mul_cnt_1 == 2'd2)
      begin
        mul_cnt_1     <= 2'd3;
        mul_pending_1 <= 1'b0;
      end
      else
        mul_cnt_1 <= mul_cnt_1 + 2'd1;
    end
  end

  alu u_alu_0(
        .clk        (clk),
        .resetn     (resetn),
        .mul_signed (es_mul_signed_0),
        .alu_op     (es_alu_op_0),
        .alu_src1   (es_alu_src1_0),
        .alu_src2   (es_alu_src2_0),
        .alu_result (alu_result_0),
        .mul_result (mul_product_0)
      );

  alu u_alu_1(
        .clk        (clk),
        .resetn     (resetn),
        .mul_signed (es_mul_signed_1),
        .alu_op     (es_alu_op_1),
        .alu_src1   (es_alu_src1_1),
        .alu_src2   (es_alu_src2_1),
        .alu_result (alu_result_1),
        .mul_result (mul_product_1)
      );

`ifndef SYNTHESIS
  always @(posedge clk)
  begin
    if (resetn)
    begin
      if (es_valid_0 && !es_operands_held &&
          (((es_need_rj_0 && (es_raddr1_0 != 5'b0)) &&
            (((ms_valid_1 && ms_gr_we_1 && (ms_dest_1 == es_raddr1_0)) &&
              !ms_fwd_valid_1) ||
             ((ms_valid_0 && ms_gr_we_0 && (ms_dest_0 == es_raddr1_0)) &&
              !ms_fwd_valid_0))) ||
           ((es_need_rkd_0 && (es_raddr2_0 != 5'b0)) &&
            (((ms_valid_1 && ms_gr_we_1 && (ms_dest_1 == es_raddr2_0)) &&
              !ms_fwd_valid_1) ||
             ((ms_valid_0 && ms_gr_we_0 && (ms_dest_0 == es_raddr2_0)) &&
              !ms_fwd_valid_0)))))
        $fatal(1, "lane0 EX source matched an unready MEM producer");
      if (es_valid_1 && !es_operands_held &&
          (((es_need_rj_1 && (es_raddr1_1 != 5'b0)) &&
            (((ms_valid_1 && ms_gr_we_1 && (ms_dest_1 == es_raddr1_1)) &&
              !ms_fwd_valid_1) ||
             ((ms_valid_0 && ms_gr_we_0 && (ms_dest_0 == es_raddr1_1)) &&
              !ms_fwd_valid_0))) ||
           ((es_need_rkd_1 && (es_raddr2_1 != 5'b0)) &&
            (((ms_valid_1 && ms_gr_we_1 && (ms_dest_1 == es_raddr2_1)) &&
              !ms_fwd_valid_1) ||
             ((ms_valid_0 && ms_gr_we_0 && (ms_dest_0 == es_raddr2_1)) &&
              !ms_fwd_valid_0)))))
        $fatal(1, "lane1 EX source matched an unready MEM producer");
    end
  end
`endif

endmodule
