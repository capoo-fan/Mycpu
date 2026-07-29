`include "mycpu.vh"

module EXE_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ds_to_es_valid_0,
    input  wire                         ds_to_es_valid_1,
    input  wire [`DS_TO_ES_BUS_WD-1:0]  ds_to_es_bus_0,
    input  wire [`DS_TO_ES_BUS_1_WD-1:0] ds_to_es_bus_1,
    input  wire                         flush,
    input  wire                         ms_allowin,
    input  wire                         load_wakeup_valid,
    input  wire [31:0]                  load_wakeup_data,
    output wire                         es_allowin,
    output wire                         es_to_ms_valid_0,
    output wire                         es_to_ms_valid_1,
    output wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus_0,
    output wire [`ES_TO_MS_BUS_1_WD-1:0] es_to_ms_bus_1,
    output wire [`ES_FWD_BUS_WD-1:0]    es_fwd_bus_0,
    output wire [`ES_FWD_BUS_1_WD-1:0]  es_fwd_bus_1,
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
  reg  [31:0] es_alu_src1_0;
  reg  [31:0] es_alu_src2_0;
  reg  [31:0] es_rkd_value_0;
  reg         es_store_data_late_0;
  reg  [ 4:0] es_store_data_src_0;
  reg         es_res_from_mem_0;
  reg         es_gr_we_0;
  reg         es_mem_we_0;
  reg  [ 4:0] es_dest_0;
  reg         es_is_mul_0;
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
  reg  [13:0] es_csr_num_0;
  reg  [31:0] es_csr_wmask_0;
  reg  [31:0] es_csr_wvalue_0;

  reg         es_valid_1;
  reg  [31:0] es_pc_1;
  reg  [11:0] es_alu_op_1;
  reg  [31:0] es_alu_src1_1;
  reg  [31:0] es_alu_src2_1;
  reg  [31:0] es_rkd_value_1;
  reg         es_gr_we_1;
  reg  [ 4:0] es_dest_1;
  reg         es_is_mul_1;
  reg         es_pred_taken_1;
  reg  [31:0] es_pred_target_1;
  reg  [ 3:0] es_br_op_1;
  reg  [31:0] es_br_offs_1;

  wire [31:0] ds_pc_0;
  wire [11:0] ds_alu_op_0;
  wire [31:0] ds_alu_src1_0;
  wire [31:0] ds_alu_src2_0;
  wire [31:0] ds_rkd_value_0;
  wire        ds_store_data_late_0;
  wire [ 4:0] ds_store_data_src_0;
  wire        ds_res_from_mem_0;
  wire        ds_gr_we_0;
  wire        ds_mem_we_0;
  wire [ 4:0] ds_dest_0;
  wire        ds_is_mul_0;
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
  wire        ds_load_wakeup_rj_0;
  wire        ds_load_wakeup_rkd_0;

  assign {ds_store_data_late_0, ds_store_data_src_0,
          ds_pc_0, ds_alu_op_0, ds_alu_src1_0, ds_alu_src2_0, ds_rkd_value_0,
          ds_res_from_mem_0, ds_gr_we_0, ds_mem_we_0, ds_dest_0,
          ds_is_mul_0,
          ds_ld_byte_0, ds_ld_half_0, ds_ld_sign_ext_0,
          ds_st_byte_0, ds_st_half_0,
          ds_pred_taken_0, ds_pred_target_0, ds_br_op_0, ds_br_offs_0,
          ds_is_cpucfg_0, ds_is_cacop_0, ds_cacop_code_0,
          ds_is_csr_0, ds_is_csrxchg_0, ds_csr_num_0,
          ds_load_wakeup_rj_0,
          ds_load_wakeup_rkd_0} = ds_to_es_bus_0;

  // 返回数据不穿过 ISSUE 的宽前递 mux，只在 EX 输入边沿做两个
  // 2:1 选择。当前开放类别不会把 rj/rkd 用作分支或 store 数据。
  wire [31:0] ds_alu_src1_final =
       ds_load_wakeup_rj_0 ? load_wakeup_data : ds_alu_src1_0;
  wire [31:0] ds_alu_src2_final =
       ds_load_wakeup_rkd_0 ? load_wakeup_data : ds_alu_src2_0;

  wire [31:0] ds_pc_1;
  wire [11:0] ds_alu_op_1;
  wire [31:0] ds_alu_src1_1;
  wire [31:0] ds_alu_src2_1;
  wire [31:0] ds_rkd_value_1;
  wire        ds_gr_we_1;
  wire [ 4:0] ds_dest_1;
  wire        ds_is_mul_1;
  wire        ds_pred_taken_1;
  wire [31:0] ds_pred_target_1;
  wire [ 3:0] ds_br_op_1;
  wire [31:0] ds_br_offs_1;

  assign {ds_pc_1, ds_alu_op_1, ds_alu_src1_1, ds_alu_src2_1, ds_rkd_value_1,
          ds_gr_we_1, ds_dest_1, ds_is_mul_1,
          ds_pred_taken_1, ds_pred_target_1,
          ds_br_op_1, ds_br_offs_1} = ds_to_es_bus_1;

  // 两个三拍乘法 IP 在指令进入 EX 的同一边沿采样 ISSUE 操作数。
  // 唯一的 mul_pending_0 作为整包等待状态，结果在 EX 再等两拍可用；
  // 不为 lane1 复制计数器或完成仲裁。
  wire mul_packet_ready = !es_valid_0 || !mul_pending_0;
  wire es_ready_go = mul_packet_ready;
  wire es_busy     = es_valid_0 || es_valid_1;

  assign es_allowin       = !es_busy || (es_ready_go && ms_allowin);
  assign es_to_ms_valid_0 = es_valid_0 && es_ready_go;
  assign es_to_ms_valid_1 = es_valid_1 && es_ready_go;

  wire [31:0] alu_result_0;
  wire [31:0] mul_product_0;
  wire [31:0] alu_result_1;
  wire [31:0] mul_product_1;

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

  wire [31:0] es_mul_result_0 = mul_product_0;
  assign csr_raddr = es_csr_num_0;
  assign csr_busy  = es_valid_0 && es_is_csr_0;
  assign cacop_busy = es_valid_0 && es_is_cacop_0;

  wire [31:0] es_exec_result_0 = es_is_mul_0 ? es_mul_result_0 : alu_result_0;
  wire [31:0] es_exec_result_1 =
       es_is_mul_1 ? mul_product_1 : alu_result_1;
  wire [31:0] es_final_result_0 = es_is_csr_0 ? csr_rdata :
       es_is_cpucfg_0 ? cpucfg_result(es_alu_src1_0) : es_exec_result_0;

  //去除掉低频指令的前递
  wire es_result_forwardable_0 =
       !(es_is_csr_0 || es_is_cpucfg_0 || es_is_cacop_0);

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

  branch_judge #(
                 .SIMPLE_ONLY (1)
               ) u_branch_judge_1(
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

  wire es_fwd_valid_0 = es_result_forwardable_0 &&
       !es_res_from_mem_0 && !mul_pending_0;

  assign es_fwd_bus_0 = {es_valid_0, es_gr_we_0, es_fwd_valid_0,
                         es_res_from_mem_0, es_dest_0, es_exec_result_0};
  assign es_fwd_bus_1 = {es_valid_1, es_gr_we_1,
                         es_dest_1, es_exec_result_1};

  assign es_to_ms_bus_0 = {es_store_data_late_0,
                           es_store_data_src_0,
                           es_result_forwardable_0,
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

  assign es_to_ms_bus_1 = {es_pc_1,
                           es_exec_result_1,
                           es_gr_we_1,
                           es_dest_1,
                           es_pred_taken_1,
                           es_pred_target_1,
                           es_is_bj_1,
                           es_real_taken_1,
                           es_real_target_1,
                           es_next_pc_1,
                           es_redirect_miss_1
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
    if (reset)
    begin
      es_pc_0           <= 32'b0;
      es_gr_we_0        <= 1'b0;
      es_mem_we_0       <= 1'b0;
      es_res_from_mem_0 <= 1'b0;
      es_dest_0         <= 5'b0;
      es_alu_op_0       <= 12'b0;
      es_alu_src1_0     <= 32'b0;
      es_alu_src2_0     <= 32'b0;
      es_rkd_value_0    <= 32'b0;
      es_store_data_late_0 <= 1'b0;
      es_store_data_src_0  <= 5'b0;
      es_is_mul_0       <= 1'b0;
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
      es_csr_num_0      <= 14'b0;
      es_csr_wmask_0    <= 32'b0;
      es_csr_wvalue_0   <= 32'b0;

      es_pc_1           <= 32'b0;
      es_gr_we_1        <= 1'b0;
      es_dest_1         <= 5'b0;
      es_is_mul_1       <= 1'b0;
      es_alu_op_1       <= 12'b0;
      es_alu_src1_1     <= 32'b0;
      es_alu_src2_1     <= 32'b0;
      es_rkd_value_1    <= 32'b0;
      es_pred_taken_1   <= 1'b0;
      es_pred_target_1  <= 32'b0;
      es_br_op_1        <= `BR_NONE;
      es_br_offs_1      <= 32'b0;
    end
    else if (flush)
    begin
      es_gr_we_0        <= 1'b0;
      es_mem_we_0       <= 1'b0;
      es_store_data_late_0 <= 1'b0;
      es_store_data_src_0  <= 5'b0;
      es_res_from_mem_0 <= 1'b0;
      es_is_mul_0       <= 1'b0;
      es_br_op_0        <= `BR_NONE;
      es_is_cpucfg_0    <= 1'b0;
      es_is_cacop_0     <= 1'b0;
      es_is_csr_0       <= 1'b0;
      es_gr_we_1        <= 1'b0;
      es_is_mul_1       <= 1'b0;
      es_br_op_1        <= `BR_NONE;
    end
    else if (es_allowin)
    begin
      es_pc_0           <= ds_pc_0;
      es_alu_op_0       <= ds_alu_op_0;
      es_alu_src1_0     <= ds_alu_src1_final;
      es_alu_src2_0     <= ds_alu_src2_final;
      es_rkd_value_0    <= ds_rkd_value_0;
      es_store_data_late_0 <=
          ds_to_es_valid_0 && ds_store_data_late_0;
      es_store_data_src_0  <= ds_store_data_src_0;
      es_res_from_mem_0 <= ds_to_es_valid_0 && ds_res_from_mem_0;
      es_gr_we_0        <= ds_to_es_valid_0 && ds_gr_we_0;
      es_mem_we_0       <= ds_to_es_valid_0 && ds_mem_we_0;
      es_dest_0         <= ds_dest_0;
      es_is_mul_0       <= ds_to_es_valid_0 && ds_is_mul_0;
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
      es_csr_num_0      <= ds_csr_num_0;
      es_csr_wmask_0    <= ds_is_csrxchg_0 ? ds_alu_src1_0 : 32'hffff_ffff;
      es_csr_wvalue_0   <= ds_rkd_value_0;

      es_pc_1           <= ds_pc_1;
      es_alu_op_1       <= ds_alu_op_1;
      es_alu_src1_1     <= ds_alu_src1_1;
      es_alu_src2_1     <= ds_alu_src2_1;
      es_rkd_value_1    <= ds_rkd_value_1;
      es_gr_we_1        <= ds_to_es_valid_1 && ds_gr_we_1;
      es_dest_1         <= ds_dest_1;
      es_is_mul_1       <= ds_to_es_valid_1 && ds_is_mul_1;
      es_pred_taken_1   <= ds_pred_taken_1;
      es_pred_target_1  <= ds_pred_target_1;
      es_br_op_1        <= ds_to_es_valid_1 ? ds_br_op_1 : `BR_NONE;
      es_br_offs_1      <= ds_br_offs_1;
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
      if (mul_cnt_0 == 2'd1)
      begin
        mul_cnt_0     <= 2'd2;
        mul_pending_0 <= 1'b0;
      end
      else
        mul_cnt_0 <= mul_cnt_0 + 2'd1;
    end
  end

  // 两路乘法器输入与普通 ALU 输入分开：MUL+MUL 发射当拍同时启动，
  // 并保证当前正在离开 EX 的普通 ALU 包仍使用其 EX 寄存器操作数。
  wire mul_launch_0 = ds_to_es_valid_0 && ds_is_mul_0;
  wire mul_launch_1 = ds_to_es_valid_1 && ds_is_mul_1;
  wire [31:0] mul_src1_0 =
       mul_launch_0 ? ds_alu_src1_final : es_alu_src1_0;
  wire [31:0] mul_src2_0 =
       mul_launch_0 ? ds_alu_src2_final : es_alu_src2_0;
  wire [31:0] mul_src1_1 =
       mul_launch_1 ? ds_alu_src1_1 : es_alu_src1_1;
  wire [31:0] mul_src2_1 =
       mul_launch_1 ? ds_alu_src2_1 : es_alu_src2_1;

  alu #(
        .HAS_MUL (1)
      ) u_alu_0(
        .clk        (clk),
        .resetn     (resetn),
        .alu_op     (es_alu_op_0),
        .alu_src1   (es_alu_src1_0),
        .alu_src2   (es_alu_src2_0),
        .mul_src1   (mul_src1_0),
        .mul_src2   (mul_src2_0),
        .alu_result (alu_result_0),
        .mul_result (mul_product_0)
      );

  alu #(
        .HAS_MUL (1)
      ) u_alu_1(
        .clk        (clk),
        .resetn     (resetn),
        .alu_op     (es_alu_op_1),
        .alu_src1   (es_alu_src1_1),
        .alu_src2   (es_alu_src2_1),
        .mul_src1   (mul_src1_1),
        .mul_src2   (mul_src2_1),
        .alu_result (alu_result_1),
        .mul_result (mul_product_1)
      );

`ifndef SYNTHESIS
  always @(posedge clk)
  begin
    if (resetn)
    begin
      if (ds_to_es_valid_0 &&
          (ds_load_wakeup_rj_0 || ds_load_wakeup_rkd_0) &&
          !load_wakeup_valid)
        $fatal(1, "EX captured load wakeup data without a valid response");
      if (es_valid_0 && mul_pending_0 && es_fwd_valid_0)
        $fatal(1, "unfinished lane0 multiply became forwardable");
      if (es_valid_0 && !es_result_forwardable_0 && es_fwd_valid_0)
        $fatal(1, "lane0 special result entered EX forwarding");
      if (ds_to_es_valid_1 && ds_is_mul_1 &&
          !(ds_to_es_valid_0 && ds_is_mul_0))
        $fatal(1, "lane1 multiply launched without lane0 multiply");
      if (es_valid_1 && es_is_mul_1 && !es_is_mul_0)
        $fatal(1, "lane1 multiply lost packet pairing in EX");
      if (ds_to_es_valid_1 &&
          ((ds_br_op_1 == `BR_JIRL) || (ds_br_op_1 == `BR_BL)))
        $fatal(1, "complex branch entered lane1 EX");
    end
  end
`endif

endmodule
