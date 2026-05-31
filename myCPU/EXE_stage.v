`include "mycpu.vh"

module EXE_stage(
    input  wire                         clk,
    input  wire                         resetn,
    input  wire                         ds_to_es_valid,
    input  wire [`DS_TO_ES_BUS_WD-1:0]  ds_to_es_bus,
    input  wire                         ms_allowin,
    output wire                         es_allowin,
    output wire                         es_to_ms_valid,
    output wire [`ES_TO_MS_BUS_WD-1:0]  es_to_ms_bus,
    output wire [`ES_FWD_BUS_WD-1:0]    es_fwd_bus,
    output wire                         br_taken,
    output wire [31:0]                  br_target,
    output wire                         bpu_valid,
    output wire                         bpu_is_bj,
    output wire [31:0]                  bpu_pc,
    output wire                         bpu_real_taken,
    output wire [31:0]                  bpu_real_target,
    output wire                         bpu_is_call,
    output wire                         bpu_is_ret,
    output wire [31:0]                  bpu_ret_addr
  );

  reg         reset;
  always @(posedge clk) reset <= ~resetn;

  // EX 级寄存器
  reg         es_valid;
  reg  [31:0] es_pc;
  reg  [11:0] es_alu_op;
  reg  [31:0] es_alu_src1;
  reg  [31:0] es_alu_src2;
  reg  [31:0] es_rkd_value;
  reg         es_res_from_mem;
  reg         es_gr_we;
  reg         es_mem_we;
  reg  [ 4:0] es_dest;
  reg         es_is_mul;
  reg         es_mul_signed;
  reg         es_mul_hi;
  reg  [2:0]  mul_cnt;
  reg         es_ld_byte;
  reg         es_ld_half;
  reg         es_ld_sign_ext;
  reg         es_st_byte;
  reg         es_st_half;
  reg         es_pred_taken;
  reg  [31:0] es_pred_target;
  reg  [ 3:0] es_br_op;
  reg  [31:0] es_br_offs;
  reg         es_is_call;
  reg         es_is_ret;


  wire [31:0] ds_pc;
  wire [11:0] ds_alu_op;
  wire [31:0] ds_alu_src1;
  wire [31:0] ds_alu_src2;
  wire [31:0] ds_rkd_value;
  wire        ds_res_from_mem;
  wire        ds_gr_we;
  wire        ds_mem_we;
  wire [ 4:0] ds_dest;
  wire        ds_is_mul;
  wire        ds_mul_signed;
  wire        ds_mul_hi;
  wire        ds_ld_byte;
  wire        ds_ld_half;
  wire        ds_ld_sign_ext;
  wire        ds_st_byte;
  wire        ds_st_half;
  wire        ds_pred_taken;
  wire [31:0] ds_pred_target;
  wire [ 3:0] ds_br_op;
  wire [31:0] ds_br_offs;
  wire        ds_is_call;
  wire        ds_is_ret;
  assign {ds_pc, ds_alu_op, ds_alu_src1, ds_alu_src2, ds_rkd_value,
          ds_res_from_mem, ds_gr_we, ds_mem_we, ds_dest,
          ds_is_mul, ds_mul_signed, ds_mul_hi,
          ds_ld_byte, ds_ld_half, ds_ld_sign_ext,
          ds_st_byte, ds_st_half,
          ds_pred_taken, ds_pred_target, ds_br_op, ds_br_offs,
          ds_is_call, ds_is_ret} = ds_to_es_bus;


  wire [31:0] alu_result;

  // 乘法
  wire [63:0] mul_product;

  localparam [2:0] MUL_LATENCY = 3'd1;


  // 流水线控制
  wire   mul_result_ready = !es_is_mul       || (mul_cnt == MUL_LATENCY);
  wire   es_ready_go      = mul_result_ready;
  assign es_allowin       = !es_valid        || (es_ready_go && ms_allowin);
  assign es_to_ms_valid   = es_valid         && es_ready_go;
  wire   es_fire          = es_valid         && es_ready_go && ms_allowin;

  // EXE 的结果
  wire [31:0] es_final_result = es_is_mul ? (es_mul_hi ? mul_product[63:32] : mul_product[31:0]) :
       alu_result;

  // 前递信号
  wire es_fwd_valid = !es_res_from_mem &&
       !(es_is_mul && (mul_cnt != MUL_LATENCY));
  assign es_fwd_bus = {es_valid, es_gr_we, es_fwd_valid,
                       es_res_from_mem, es_dest, es_final_result};
  assign es_to_ms_bus = {es_pc,
                         es_final_result,
                         es_rkd_value,
                         es_res_from_mem,
                         es_gr_we,
                         es_mem_we,
                         es_dest,
                         es_ld_byte,
                         es_ld_half,
                         es_ld_sign_ext,
                         es_st_byte,
                         es_st_half
                        };

  wire es_is_bj = (es_br_op != `BR_NONE);
  wire es_rj_eq_rkd          = (es_alu_src1 == es_rkd_value);
  wire es_rj_lt_rkd_signed   = ($signed(es_alu_src1) < $signed(es_rkd_value));
  wire es_rj_lt_rkd_unsigned = (es_alu_src1 < es_rkd_value);

  wire es_real_taken = ((es_br_op == `BR_BEQ)  &&  es_rj_eq_rkd          ||
                        (es_br_op == `BR_BNE)  && !es_rj_eq_rkd          ||
                        (es_br_op == `BR_BLT)  &&  es_rj_lt_rkd_signed   ||
                        (es_br_op == `BR_BGE)  && !es_rj_lt_rkd_signed   ||
                        (es_br_op == `BR_BLTU) &&  es_rj_lt_rkd_unsigned ||
                        (es_br_op == `BR_BGEU) && !es_rj_lt_rkd_unsigned ||
                        (es_br_op == `BR_JIRL) ||
                        (es_br_op == `BR_BL)   ||
                        (es_br_op == `BR_B)) && es_is_bj;
  wire [31:0] es_pc_br_target   = es_pc + es_br_offs;
  wire [31:0] es_jirl_br_target = es_rkd_value + es_br_offs;
  wire [31:0] es_real_target    = (es_br_op == `BR_JIRL) ? es_jirl_br_target :
       es_pc_br_target;

  wire es_taken_miss  = es_real_taken ^ es_pred_taken;
  wire es_target_miss = es_real_taken && es_pred_taken &&
       (es_real_target != es_pred_target);
  wire es_redirect = es_fire && es_is_bj && (es_taken_miss || es_target_miss);

  assign br_taken  = es_redirect;
  assign br_target = es_redirect ? (es_real_taken ? es_real_target : (es_pc + 32'h4)) :
         32'b0;

  assign bpu_valid       = es_fire;
  assign bpu_is_bj       = es_fire && es_is_bj;
  assign bpu_pc          = es_pc;
  assign bpu_real_taken  = es_real_taken;
  assign bpu_real_target = es_real_target;
  assign bpu_is_call     = es_fire && es_is_bj && es_real_taken && es_is_call;
  assign bpu_is_ret      = es_fire && es_is_bj && es_real_taken && es_is_ret;
  assign bpu_ret_addr    = es_pc + 32'h4;

  always @(posedge clk)
  begin
    if (reset)
      es_valid <= 1'b0;
    else if (es_allowin)
      es_valid <= ds_to_es_valid;
  end

  always @(posedge clk)
  begin
    if (reset)
    begin
      es_pc           <= 32'b0;
      es_gr_we        <= 1'b0;
      es_mem_we       <= 1'b0;
      es_res_from_mem <= 1'b0;
      es_dest         <= 5'b0;
      es_alu_op       <= 12'b0;
      es_alu_src1     <= 32'b0;
      es_alu_src2     <= 32'b0;
      es_rkd_value    <= 32'b0;
      es_is_mul       <= 1'b0;
      es_mul_signed   <= 1'b0;
      es_mul_hi       <= 1'b0;
      es_ld_byte      <= 1'b0;
      es_ld_half      <= 1'b0;
      es_ld_sign_ext  <= 1'b0;
      es_st_byte      <= 1'b0;
      es_st_half      <= 1'b0;
      es_pred_taken   <= 1'b0;
      es_pred_target  <= 32'b0;
      es_br_op        <= `BR_NONE;
      es_br_offs      <= 32'b0;
      es_is_call      <= 1'b0;
      es_is_ret       <= 1'b0;
    end
    else if (es_allowin)
    begin
      if (ds_to_es_valid)
      begin
        es_pc           <= ds_pc;
        es_alu_op       <= ds_alu_op;
        es_alu_src1     <= ds_alu_src1;
        es_alu_src2     <= ds_alu_src2;
        es_rkd_value    <= ds_rkd_value;
        es_res_from_mem <= ds_res_from_mem;
        es_gr_we        <= ds_gr_we;
        es_mem_we       <= ds_mem_we;
        es_dest         <= ds_dest;
        es_is_mul       <= ds_is_mul;
        es_mul_signed   <= ds_mul_signed;
        es_mul_hi       <= ds_mul_hi;
        es_ld_byte      <= ds_ld_byte;
        es_ld_half      <= ds_ld_half;
        es_ld_sign_ext  <= ds_ld_sign_ext;
        es_st_byte      <= ds_st_byte;
        es_st_half      <= ds_st_half;
        es_pred_taken   <= ds_pred_taken;
        es_pred_target  <= ds_pred_target;
        es_br_op        <= ds_br_op;
        es_br_offs      <= ds_br_offs;
        es_is_call      <= ds_is_call;
        es_is_ret       <= ds_is_ret;
      end
      else //如果没有新信号，赋0防止误操作
      begin
        es_gr_we        <= 1'b0;
        es_mem_we       <= 1'b0;
        es_is_mul       <= 1'b0;
        es_br_op        <= `BR_NONE;
        es_is_call      <= 1'b0;
        es_is_ret       <= 1'b0;
      end
    end
  end

  //乘法流水线计数器
  always @(posedge clk)
  begin
    if (reset)
      mul_cnt <= 3'd0;
    else if (es_allowin)
      mul_cnt <= 3'd0;
    else if (es_is_mul && (mul_cnt < MUL_LATENCY))
      mul_cnt <= mul_cnt + 3'd1;
  end

  alu u_alu(
        .clk        (clk        ),
        .resetn     (resetn     ),
        .mul_signed (es_mul_signed),
        .alu_op     (es_alu_op  ),
        .alu_src1   (es_alu_src1),
        .alu_src2   (es_alu_src2),
        .alu_result (alu_result ),
        .mul_result (mul_product)
      );

endmodule
