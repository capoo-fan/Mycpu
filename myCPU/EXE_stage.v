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
    output wire [`ES_FWD_BUS_WD-1:0]    es_fwd_bus_0,
    output wire [`ES_FWD_BUS_WD-1:0]    es_fwd_bus_1
  );

  reg reset;
  always @(posedge clk) reset <= ~resetn;

  reg         es_valid_0;
  reg  [31:0] es_pc_0;
  reg  [11:0] es_alu_op_0;
  reg  [31:0] es_alu_src1_0;
  reg  [31:0] es_alu_src2_0;
  reg  [31:0] es_rkd_value_0;
  reg         es_res_from_mem_0;
  reg         es_gr_we_0;
  reg         es_mem_we_0;
  reg  [ 4:0] es_dest_0;
  reg         es_is_mul_0;
  reg         es_mul_signed_0;
  reg         es_mul_hi_0;
  reg  [ 2:0] mul_cnt_0;
  reg         es_ld_byte_0;
  reg         es_ld_half_0;
  reg         es_ld_sign_ext_0;
  reg         es_st_byte_0;
  reg         es_st_half_0;
  reg         es_pred_taken_0;
  reg  [31:0] es_pred_target_0;
  reg  [ 3:0] es_br_op_0;
  reg  [31:0] es_br_offs_0;

  reg         es_valid_1;
  reg  [31:0] es_pc_1;
  reg  [11:0] es_alu_op_1;
  reg  [31:0] es_alu_src1_1;
  reg  [31:0] es_alu_src2_1;
  reg  [31:0] es_rkd_value_1;
  reg         es_res_from_mem_1;
  reg         es_gr_we_1;
  reg         es_mem_we_1;
  reg  [ 4:0] es_dest_1;
  reg         es_is_mul_1;
  reg         es_mul_signed_1;
  reg         es_mul_hi_1;
  reg  [ 2:0] mul_cnt_1;
  reg         es_ld_byte_1;
  reg         es_ld_half_1;
  reg         es_ld_sign_ext_1;
  reg         es_st_byte_1;
  reg         es_st_half_1;
  reg         es_pred_taken_1;
  reg  [31:0] es_pred_target_1;
  reg  [ 3:0] es_br_op_1;
  reg  [31:0] es_br_offs_1;

  wire [31:0] ds_pc_0;
  wire [11:0] ds_alu_op_0;
  wire [31:0] ds_alu_src1_0;
  wire [31:0] ds_alu_src2_0;
  wire [31:0] ds_rkd_value_0;
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

  assign {ds_pc_0, ds_alu_op_0, ds_alu_src1_0, ds_alu_src2_0, ds_rkd_value_0,
          ds_res_from_mem_0, ds_gr_we_0, ds_mem_we_0, ds_dest_0,
          ds_is_mul_0, ds_mul_signed_0, ds_mul_hi_0,
          ds_ld_byte_0, ds_ld_half_0, ds_ld_sign_ext_0,
          ds_st_byte_0, ds_st_half_0,
          ds_pred_taken_0, ds_pred_target_0, ds_br_op_0, ds_br_offs_0} = ds_to_es_bus_0;

  wire [31:0] ds_pc_1;
  wire [11:0] ds_alu_op_1;
  wire [31:0] ds_alu_src1_1;
  wire [31:0] ds_alu_src2_1;
  wire [31:0] ds_rkd_value_1;
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

  assign {ds_pc_1, ds_alu_op_1, ds_alu_src1_1, ds_alu_src2_1, ds_rkd_value_1,
          ds_res_from_mem_1, ds_gr_we_1, ds_mem_we_1, ds_dest_1,
          ds_is_mul_1, ds_mul_signed_1, ds_mul_hi_1,
          ds_ld_byte_1, ds_ld_half_1, ds_ld_sign_ext_1,
          ds_st_byte_1, ds_st_half_1,
          ds_pred_taken_1, ds_pred_target_1, ds_br_op_1, ds_br_offs_1} = ds_to_es_bus_1;

  localparam [2:0] MUL_LATENCY = 3'd3;

  wire lane0_ready = !es_valid_0 || !es_is_mul_0 || (mul_cnt_0 == MUL_LATENCY);
  wire lane1_ready = !es_valid_1 || !es_is_mul_1 || (mul_cnt_1 == MUL_LATENCY);
  wire es_ready_go = lane0_ready && lane1_ready;
  wire es_busy     = es_valid_0 || es_valid_1;

  assign es_allowin       = !es_busy || (es_ready_go && ms_allowin);
  assign es_to_ms_valid_0 = es_valid_0 && es_ready_go;
  assign es_to_ms_valid_1 = es_valid_1 && es_ready_go;

  wire [31:0] alu_result_0;
  wire [63:0] mul_product_0;
  wire [31:0] alu_result_1;
  wire [63:0] mul_product_1;

  wire [31:0] es_final_result_0 = es_is_mul_0 ? (es_mul_hi_0 ? mul_product_0[63:32] : mul_product_0[31:0]) :
       alu_result_0;
  wire [31:0] es_final_result_1 = es_is_mul_1 ? (es_mul_hi_1 ? mul_product_1[63:32] : mul_product_1[31:0]) :
       alu_result_1;

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

  wire es_fwd_valid_0 = !es_res_from_mem_0 &&
       !(es_is_mul_0 && (mul_cnt_0 != MUL_LATENCY));
  wire es_fwd_valid_1 = !es_res_from_mem_1 &&
       !(es_is_mul_1 && (mul_cnt_1 != MUL_LATENCY));

  assign es_fwd_bus_0 = {es_valid_0, es_gr_we_0, es_fwd_valid_0,
                         es_res_from_mem_0, es_dest_0, es_final_result_0};
  assign es_fwd_bus_1 = {es_valid_1, es_gr_we_1, es_fwd_valid_1,
                         es_res_from_mem_1, es_dest_1, es_final_result_1};

  assign es_to_ms_bus_0 = {es_pc_0,
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
                           es_redirect_miss_0
                          };

  assign es_to_ms_bus_1 = {es_pc_1,
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

      es_pc_1           <= 32'b0;
      es_gr_we_1        <= 1'b0;
      es_mem_we_1       <= 1'b0;
      es_res_from_mem_1 <= 1'b0;
      es_dest_1         <= 5'b0;
      es_alu_op_1       <= 12'b0;
      es_alu_src1_1     <= 32'b0;
      es_alu_src2_1     <= 32'b0;
      es_rkd_value_1    <= 32'b0;
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
    end
    else if (flush)
    begin
      es_gr_we_0        <= 1'b0;
      es_mem_we_0       <= 1'b0;
      es_res_from_mem_0 <= 1'b0;
      es_is_mul_0       <= 1'b0;
      es_br_op_0        <= `BR_NONE;
      es_gr_we_1        <= 1'b0;
      es_mem_we_1       <= 1'b0;
      es_res_from_mem_1 <= 1'b0;
      es_is_mul_1       <= 1'b0;
      es_br_op_1        <= `BR_NONE;
    end
    else if (es_allowin)
    begin
      if (ds_to_es_valid_0)
      begin
        es_pc_0           <= ds_pc_0;
        es_alu_op_0       <= ds_alu_op_0;
        es_alu_src1_0     <= ds_alu_src1_0;
        es_alu_src2_0     <= ds_alu_src2_0;
        es_rkd_value_0    <= ds_rkd_value_0;
        es_res_from_mem_0 <= ds_res_from_mem_0;
        es_gr_we_0        <= ds_gr_we_0;
        es_mem_we_0       <= ds_mem_we_0;
        es_dest_0         <= ds_dest_0;
        es_is_mul_0       <= ds_is_mul_0;
        es_mul_signed_0   <= ds_mul_signed_0;
        es_mul_hi_0       <= ds_mul_hi_0;
        es_ld_byte_0      <= ds_ld_byte_0;
        es_ld_half_0      <= ds_ld_half_0;
        es_ld_sign_ext_0  <= ds_ld_sign_ext_0;
        es_st_byte_0      <= ds_st_byte_0;
        es_st_half_0      <= ds_st_half_0;
        es_pred_taken_0   <= ds_pred_taken_0;
        es_pred_target_0  <= ds_pred_target_0;
        es_br_op_0        <= ds_br_op_0;
        es_br_offs_0      <= ds_br_offs_0;
      end
      else
      begin
        es_gr_we_0        <= 1'b0;
        es_mem_we_0       <= 1'b0;
        es_res_from_mem_0 <= 1'b0;
        es_is_mul_0       <= 1'b0;
        es_br_op_0        <= `BR_NONE;
      end

      if (ds_to_es_valid_1)
      begin
        es_pc_1           <= ds_pc_1;
        es_alu_op_1       <= ds_alu_op_1;
        es_alu_src1_1     <= ds_alu_src1_1;
        es_alu_src2_1     <= ds_alu_src2_1;
        es_rkd_value_1    <= ds_rkd_value_1;
        es_res_from_mem_1 <= ds_res_from_mem_1;
        es_gr_we_1        <= ds_gr_we_1;
        es_mem_we_1       <= ds_mem_we_1;
        es_dest_1         <= ds_dest_1;
        es_is_mul_1       <= ds_is_mul_1;
        es_mul_signed_1   <= ds_mul_signed_1;
        es_mul_hi_1       <= ds_mul_hi_1;
        es_ld_byte_1      <= ds_ld_byte_1;
        es_ld_half_1      <= ds_ld_half_1;
        es_ld_sign_ext_1  <= ds_ld_sign_ext_1;
        es_st_byte_1      <= ds_st_byte_1;
        es_st_half_1      <= ds_st_half_1;
        es_pred_taken_1   <= ds_pred_taken_1;
        es_pred_target_1  <= ds_pred_target_1;
        es_br_op_1        <= ds_br_op_1;
        es_br_offs_1      <= ds_br_offs_1;
      end
      else
      begin
        es_gr_we_1        <= 1'b0;
        es_mem_we_1       <= 1'b0;
        es_res_from_mem_1 <= 1'b0;
        es_is_mul_1       <= 1'b0;
        es_br_op_1        <= `BR_NONE;
      end
    end
  end

  always @(posedge clk)
  begin
    if (reset || flush)
      mul_cnt_0 <= 3'd0;
    else if (es_allowin)
      mul_cnt_0 <= 3'd0;
    else if (es_valid_0 && es_is_mul_0 && (mul_cnt_0 < MUL_LATENCY))
      mul_cnt_0 <= mul_cnt_0 + 3'd1;
  end

  always @(posedge clk)
  begin
    if (reset || flush)
      mul_cnt_1 <= 3'd0;
    else if (es_allowin)
      mul_cnt_1 <= 3'd0;
    else if (es_valid_1 && es_is_mul_1 && (mul_cnt_1 < MUL_LATENCY))
      mul_cnt_1 <= mul_cnt_1 + 3'd1;
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

endmodule
