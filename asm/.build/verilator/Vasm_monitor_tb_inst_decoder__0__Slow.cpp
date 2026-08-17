// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

VL_ATTR_COLD void Vasm_monitor_tb_inst_decoder___ctor_var_reset(Vasm_monitor_tb_inst_decoder* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vasm_monitor_tb_inst_decoder___ctor_var_reset\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9812503827101699671ull);
    VL_SCOPED_RAND_RESET_W(169, vlSelf->dec_bus, __VscopeHash, 4157126720316931486ull);
    vlSelf->__PVT__inst_add_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1181605495554082538ull);
    vlSelf->__PVT__inst_sub_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2058198590490527356ull);
    vlSelf->__PVT__inst_slt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1424252848285665061ull);
    vlSelf->__PVT__inst_sltu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8608095025879383355ull);
    vlSelf->__PVT__inst_nor = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15507729515778162141ull);
    vlSelf->__PVT__inst_and = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 53132050024799477ull);
    vlSelf->__PVT__inst_or = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17255925534772420003ull);
    vlSelf->__PVT__inst_xor = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17280237147283980958ull);
    vlSelf->__PVT__inst_slli_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9070962544117247466ull);
    vlSelf->__PVT__inst_srli_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12878139648836561253ull);
    vlSelf->__PVT__inst_srai_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 570073842828436151ull);
    vlSelf->__PVT__inst_addi_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8082225457401133592ull);
    vlSelf->__PVT__inst_ld_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6823523439062105426ull);
    vlSelf->__PVT__inst_st_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6344327598044367749ull);
    vlSelf->__PVT__inst_lu12i_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15561065588591193568ull);
    vlSelf->__PVT__inst_slti = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14674435832682652862ull);
    vlSelf->__PVT__inst_sltui = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4321474618093049270ull);
    vlSelf->__PVT__inst_andi = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17323086110265210336ull);
    vlSelf->__PVT__inst_ori = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11196875658530466428ull);
    vlSelf->__PVT__inst_xori = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12941014304274215428ull);
    vlSelf->__PVT__inst_sll_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13067090514570673278ull);
    vlSelf->__PVT__inst_srl_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6326874368118686664ull);
    vlSelf->__PVT__inst_sra_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14668884019915075683ull);
    vlSelf->__PVT__inst_pcaddu12i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8398693387557910949ull);
    vlSelf->__PVT__inst_ld_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3577239565974344775ull);
    vlSelf->__PVT__inst_ld_h = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15996697518611068643ull);
    vlSelf->__PVT__inst_ld_bu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8906967204153802630ull);
    vlSelf->__PVT__inst_ld_hu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1257427967273118213ull);
    vlSelf->__PVT__inst_st_b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2039029556820925603ull);
    vlSelf->__PVT__inst_st_h = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14410955955928050078ull);
    vlSelf->__PVT__inst_mul_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10506228235562476337ull);
    vlSelf->__PVT__inst_cpucfg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2272737355074540795ull);
    vlSelf->__PVT__inst_cacop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4910292604265319493ull);
    vlSelf->__PVT__inst_csrwr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6135944879380235503ull);
    vlSelf->__PVT__inst_csrxchg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3721855653220673218ull);
    vlSelf->__PVT__ld_sign_ext = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3293063750390671758ull);
    vlSelf->__PVT__need_ui12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 938714721065797547ull);
    vlSelf->__PVT__need_si20 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5804729121073379811ull);
    vlSelf->__PVT__src2_is_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15677836800956444684ull);
    vlSelf->__PVT__jirl_offs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8640768345306100859ull);
    vlSelf->__PVT__src_reg_is_rd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8861873225580160430ull);
    vlSelf->__PVT__src1_is_pc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6753640944970482466ull);
    vlSelf->__PVT__mem_we = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15973559030946811212ull);
    vlSelf->__PVT__is_csr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8850692820654375401ull);
    vlSelf->__PVT__u_dec3__DOT__out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2615746132366196012ull);
    vlSelf->__PVT__u_dec0__DOT__out = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10502554092318714688ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_11 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_12 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_14 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_15 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_52 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_53 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_54 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_56 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_57 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_58 = 0;
}
