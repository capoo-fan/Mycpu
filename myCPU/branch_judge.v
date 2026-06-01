`include "mycpu.vh"

module branch_judge(
    input  wire [ 3:0] br_op,
    input  wire [31:0] pc,
    input  wire [31:0] src1,
    input  wire [31:0] rkd_value,
    input  wire [31:0] br_offs,
    output wire        is_bj,
    output wire        real_taken,
    output wire [31:0] real_target,
    output wire [31:0] next_pc
  );

  wire rj_eq_rkd          = (src1 == rkd_value);
  wire rj_lt_rkd_signed   = ($signed(src1) < $signed(rkd_value));
  wire rj_lt_rkd_unsigned = (src1 < rkd_value);

  wire [31:0] target_base = (br_op == `BR_JIRL) ? rkd_value : pc;

  assign is_bj = (br_op != `BR_NONE);

  assign real_taken = ((br_op == `BR_BEQ)  &&  rj_eq_rkd          ||
                       (br_op == `BR_BNE)  && !rj_eq_rkd          ||
                       (br_op == `BR_BLT)  &&  rj_lt_rkd_signed   ||
                       (br_op == `BR_BGE)  && !rj_lt_rkd_signed   ||
                       (br_op == `BR_BLTU) &&  rj_lt_rkd_unsigned ||
                       (br_op == `BR_BGEU) && !rj_lt_rkd_unsigned ||
                       (br_op == `BR_JIRL) ||
                       (br_op == `BR_BL)   ||
                       (br_op == `BR_B)) && is_bj;

  assign real_target = target_base + br_offs;
  assign next_pc     = pc + 32'h4;

endmodule
