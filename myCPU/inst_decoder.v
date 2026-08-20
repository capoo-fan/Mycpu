`include "mycpu.vh"

module inst_decoder(
    input  wire [31:0]                    inst,
    output wire [`DS_DEC_BUS_WD-1:0]      dec_bus
  );

  // 指令字段拆解
  wire [ 5:0] op_31_26 = inst[31:26];
  wire [ 3:0] op_25_22 = inst[25:22];
  wire [ 1:0] op_21_20 = inst[21:20];
  wire [ 4:0] op_19_15 = inst[19:15];
  wire [ 4:0] rd       = inst[ 4: 0];
  wire [ 4:0] rj       = inst[ 9: 5];
  wire [ 4:0] rk       = inst[14:10];
  wire [11:0] i12      = inst[21:10];
  wire [19:0] i20      = inst[24: 5];
  wire [15:0] i16      = inst[25:10];
  wire [25:0] i26      = {inst[9:0], inst[25:10]};

  // 译码器输出
  wire [63:0] op_31_26_d;
  wire [15:0] op_25_22_d;
  wire [ 3:0] op_21_20_d;
  wire [31:0] op_19_15_d;

  // ALU 指令
  wire inst_add_w, inst_sub_w, inst_slt, inst_sltu;
  wire inst_nor, inst_and, inst_or, inst_xor;
  wire inst_slli_w, inst_srli_w, inst_srai_w;
  wire inst_addi_w, inst_ld_w, inst_st_w;
  wire inst_jirl, inst_b, inst_bl, inst_beq, inst_bne;
  wire inst_lu12i_w;
  wire inst_slti, inst_sltui, inst_andi, inst_ori, inst_xori;
  wire inst_sll_w, inst_srl_w, inst_sra_w, inst_pcaddu12i;
  wire inst_blt, inst_bge, inst_bltu, inst_bgeu;
  wire inst_ld_b, inst_ld_h, inst_ld_bu, inst_ld_hu;
  wire inst_st_b, inst_st_h;
  wire inst_mul_w;
  wire inst_cpucfg, inst_cacop;
  wire inst_csrwr, inst_csrxchg;
  wire inst_accel;

  // ALU 指令译码
  assign inst_add_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h00];
  assign inst_sub_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h02];
  assign inst_slt     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h04];
  assign inst_sltu    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h05];
  assign inst_nor     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h08];
  assign inst_and     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h09];
  assign inst_or      = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0a];
  assign inst_xor     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0b];
  assign inst_slli_w  = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h01];
  assign inst_srli_w  = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h09];
  assign inst_srai_w  = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h11];
  assign inst_addi_w  = op_31_26_d[6'h00] & op_25_22_d[4'ha];
  assign inst_ld_w    = op_31_26_d[6'h0a] & op_25_22_d[4'h2];
  assign inst_st_w    = op_31_26_d[6'h0a] & op_25_22_d[4'h6];
  assign inst_jirl    = op_31_26_d[6'h13];
  assign inst_b       = op_31_26_d[6'h14];
  assign inst_bl      = op_31_26_d[6'h15];
  assign inst_beq     = op_31_26_d[6'h16];
  assign inst_bne     = op_31_26_d[6'h17];
  assign inst_lu12i_w = op_31_26_d[6'h05] & ~inst[25];
  assign inst_slti      = op_31_26_d[6'h00] & op_25_22_d[4'h8];
  assign inst_sltui     = op_31_26_d[6'h00] & op_25_22_d[4'h9];
  assign inst_andi      = op_31_26_d[6'h00] & op_25_22_d[4'hd];
  assign inst_ori       = op_31_26_d[6'h00] & op_25_22_d[4'he];
  assign inst_xori      = op_31_26_d[6'h00] & op_25_22_d[4'hf];
  assign inst_sll_w     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0e];
  assign inst_srl_w     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0f];
  assign inst_sra_w     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h10];
  assign inst_pcaddu12i = op_31_26_d[6'h07] & ~inst[25];
  assign inst_mul_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h18];
  assign inst_blt  = op_31_26_d[6'h18];
  assign inst_bge  = op_31_26_d[6'h19];
  assign inst_bltu = op_31_26_d[6'h1a];
  assign inst_bgeu = op_31_26_d[6'h1b];
  assign inst_ld_b  = op_31_26_d[6'h0a] & op_25_22_d[4'h0];
  assign inst_ld_h  = op_31_26_d[6'h0a] & op_25_22_d[4'h1];
  assign inst_ld_bu = op_31_26_d[6'h0a] & op_25_22_d[4'h8];
  assign inst_ld_hu = op_31_26_d[6'h0a] & op_25_22_d[4'h9];
  assign inst_st_b = op_31_26_d[6'h0a] & op_25_22_d[4'h4];
  assign inst_st_h = op_31_26_d[6'h0a] & op_25_22_d[4'h5];
  assign inst_cpucfg = (inst[31:15] == 17'b0) & (rk == 5'h1b);
  assign inst_cacop  = op_31_26_d[6'h01] & op_25_22_d[4'h8];
  assign inst_csrwr   = (inst[31:24] == 8'h04) && (rj == 5'd1);
  assign inst_csrxchg = (inst[31:24] == 8'h04) &&
       (rj != 5'd0) && (rj != 5'd1);

   assign inst_accel = (inst == 32'h0020_0000);    
  // 找出未知指令
  wire inst_known = inst_add_w | inst_sub_w | inst_slt | inst_sltu |
       inst_nor | inst_and | inst_or | inst_xor |
       inst_slli_w | inst_srli_w | inst_srai_w |
       inst_addi_w | inst_ld_w | inst_st_w |
       inst_jirl | inst_b | inst_bl | inst_beq | inst_bne |
       inst_lu12i_w |
       inst_slti | inst_sltui | inst_andi | inst_ori | inst_xori |
       inst_sll_w | inst_srl_w | inst_sra_w | inst_pcaddu12i |
       inst_blt | inst_bge | inst_bltu | inst_bgeu |
       inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu |
       inst_st_b | inst_st_h |
       inst_mul_w |
       inst_cpucfg | inst_cacop | inst_csrwr | inst_csrxchg |
       inst_accel;

  wire is_mul      = inst_mul_w;
  wire ld_byte     = inst_ld_b | inst_ld_bu;
  wire ld_half     = inst_ld_h | inst_ld_hu;
  wire ld_sign_ext = inst_ld_b | inst_ld_h;
  wire st_byte     = inst_st_b;
  wire st_half     = inst_st_h;

  // 立即数生成
  wire need_ui12 = inst_andi | inst_ori | inst_xori;
  wire need_si20 = inst_lu12i_w | inst_pcaddu12i;
  wire need_si26 = inst_b | inst_bl;
  wire src2_is_4 = inst_jirl | inst_bl;

  wire [31:0] imm = src2_is_4 ? 32'h4 :
       need_si20 ? {i20[19:0], 12'b0} :
       need_ui12 ? {20'b0, i12[11:0]} :
       {{20{i12[11]}}, i12[11:0]};

  wire [31:0] br_offs   = need_si26 ? {{4{i26[25]}}, i26[25:0], 2'b0} :
       {{14{i16[15]}}, i16[15:0], 2'b0};
  wire [31:0] jirl_offs = {{14{i16[15]}}, i16[15:0], 2'b0};

  // 控制信号生成
  wire src_reg_is_rd = inst_beq | inst_bne | inst_st_w |
       inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_st_b | inst_st_h;
  wire src1_is_pc    = inst_jirl | inst_bl | inst_pcaddu12i;
  wire src2_is_imm   = inst_slli_w | inst_srli_w | inst_srai_w | inst_addi_w |
       inst_ld_w | inst_st_w | inst_lu12i_w | inst_jirl | inst_bl |
       inst_slti | inst_sltui | inst_andi | inst_ori | inst_xori |
       inst_pcaddu12i |
       inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu | inst_st_b | inst_st_h |
       inst_cacop;
  wire res_from_mem  = inst_ld_w | inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu;
  wire dst_is_r1     = inst_bl;
  wire gr_we         = inst_known & ~inst_accel &
       ~inst_st_w & ~inst_st_b & ~inst_st_h &
       ~inst_beq & ~inst_bne & ~inst_b &
       ~inst_blt & ~inst_bge & ~inst_bltu & ~inst_bgeu &
       ~inst_cacop;
  wire mem_we        = inst_st_w | inst_st_b | inst_st_h;
  wire [ 4:0] dest   = dst_is_r1 ? 5'd1 : rd;
  wire [ 4:0] cacop_code = rd;

  // ALU 操作码
  wire [11:0] alu_op;
  assign alu_op[ 0] = inst_add_w | inst_addi_w | inst_ld_w | inst_st_w | inst_jirl | inst_bl | inst_pcaddu12i | inst_ld_b | inst_ld_h | inst_ld_bu | inst_ld_hu | inst_st_b | inst_st_h | inst_cacop;
  assign alu_op[ 1] = inst_sub_w;
  assign alu_op[ 2] = inst_slt | inst_slti;
  assign alu_op[ 3] = inst_sltu | inst_sltui;
  assign alu_op[ 4] = inst_and | inst_andi;
  assign alu_op[ 5] = inst_nor;
  assign alu_op[ 6] = inst_or | inst_ori;
  assign alu_op[ 7] = inst_xor | inst_xori;
  assign alu_op[ 8] = inst_slli_w | inst_sll_w;
  assign alu_op[ 9] = inst_srli_w | inst_srl_w;
  assign alu_op[10] = inst_srai_w | inst_sra_w;
  assign alu_op[11] = inst_lu12i_w;

  wire [ 4:0] rf_raddr1 = rj;
  wire is_csr = inst_csrwr | inst_csrxchg;
  wire [13:0] csr_num = inst[23:10];
  wire [ 4:0] rf_raddr2 = (src_reg_is_rd | is_csr) ? rd : rk;

  wire ds_need_rj  = ~inst_accel &
       ~inst_b & ~inst_bl & ~inst_lu12i_w &
       ~inst_pcaddu12i & ~inst_csrwr;
  wire ds_need_rkd = inst_beq | inst_bne | inst_st_w |
       inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_st_b | inst_st_h |
       inst_add_w | inst_sub_w | inst_slt | inst_sltu |
       inst_nor | inst_and | inst_or | inst_xor |
       inst_sll_w | inst_srl_w | inst_sra_w |
       inst_mul_w | is_csr;

  wire ds_is_bj = inst_beq || inst_bne || inst_blt || inst_bge ||
       inst_bltu || inst_bgeu || inst_jirl || inst_bl || inst_b;

  assign dec_bus = {
    inst_accel,
    alu_op, imm, br_offs, jirl_offs,
    rf_raddr1, rf_raddr2, dest,
    src1_is_pc, src2_is_imm, res_from_mem, gr_we, mem_we,
    is_mul,
    ld_byte, ld_half, ld_sign_ext, st_byte, st_half,
    ds_need_rj, ds_need_rkd, ds_is_bj,
    inst_beq, inst_bne, inst_blt, inst_bge, inst_bltu, inst_bgeu,
    inst_jirl, inst_bl, inst_b,
    inst_cpucfg, inst_cacop, cacop_code,
    is_csr, inst_csrxchg, csr_num
  };

  decoder_6_64 u_dec0 (.in(op_31_26), .out(op_31_26_d));
  decoder_4_16 u_dec1 (.in(op_25_22), .out(op_25_22_d));
  decoder_2_4  u_dec2 (.in(op_21_20), .out(op_21_20_d));
  decoder_5_32 u_dec3 (.in(op_19_15), .out(op_19_15_d));

endmodule
