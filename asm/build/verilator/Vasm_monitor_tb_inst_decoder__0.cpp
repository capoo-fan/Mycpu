// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(Vasm_monitor_tb_inst_decoder* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __PVT__inst_pcaddu12i;
    __PVT__inst_pcaddu12i = 0;
    CData/*0:0*/ __PVT__inst_ld_b;
    __PVT__inst_ld_b = 0;
    CData/*0:0*/ __PVT__inst_ld_h;
    __PVT__inst_ld_h = 0;
    CData/*0:0*/ __PVT__inst_ld_bu;
    __PVT__inst_ld_bu = 0;
    CData/*0:0*/ __PVT__inst_ld_hu;
    __PVT__inst_ld_hu = 0;
    CData/*0:0*/ __PVT__inst_st_b;
    __PVT__inst_st_b = 0;
    CData/*0:0*/ __PVT__inst_st_h;
    __PVT__inst_st_h = 0;
    CData/*0:0*/ __PVT__inst_mul_w;
    __PVT__inst_mul_w = 0;
    CData/*0:0*/ __PVT__inst_cpucfg;
    __PVT__inst_cpucfg = 0;
    CData/*0:0*/ __PVT__inst_cacop;
    __PVT__inst_cacop = 0;
    CData/*0:0*/ __PVT__inst_csrwr;
    __PVT__inst_csrwr = 0;
    CData/*0:0*/ __PVT__inst_csrxchg;
    __PVT__inst_csrxchg = 0;
    CData/*0:0*/ __PVT__ld_sign_ext;
    __PVT__ld_sign_ext = 0;
    CData/*0:0*/ __PVT__src_reg_is_rd;
    __PVT__src_reg_is_rd = 0;
    CData/*0:0*/ __PVT__mem_we;
    __PVT__mem_we = 0;
    CData/*0:0*/ __PVT__is_csr;
    __PVT__is_csr = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_12;
    __VdfgRegularize_h6e95ff9d_0_12 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_13;
    __VdfgRegularize_h6e95ff9d_0_13 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_57;
    __VdfgRegularize_h6e95ff9d_0_57 = 0;
    // Body
    vlSelfRef.__PVT__inst_addi_w = (IData)((0x02800000U 
                                            == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_ld_w = (IData)((0x28800000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_slti = (IData)((0x02000000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_sltui = (IData)((0x02400000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_cpucfg = (IData)((0x00006c00U == (0xfffffc00U 
                                                  & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__need_si26 = ((0x14U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                             >> 0x0000001aU)) 
                                  | (0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x0000001aU)));
    vlSelfRef.__PVT__inst_andi = (IData)((0x03400000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_ori = (IData)((0x03800000U 
                                         == (0xffc00000U 
                                             & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_xori = (IData)((0x03c00000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_lu12i_w = (IData)((0x14000000U 
                                             == (0xfe000000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_csrwr = (IData)((0x04000020U == (0xff0003e0U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_csrxchg = ((4U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                   >> 0x00000018U)) 
                           & ((0U != (0x0000001fU & 
                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                       >> 5U))) & (1U 
                                                   != 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                       >> 5U)))));
    vlSelfRef.__PVT__src2_is_4 = ((0x13U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                             >> 0x0000001aU)) 
                                  | (0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x0000001aU)));
    __PVT__inst_cacop = (IData)((0x06000000U == (0xffc00000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_pcaddu12i = (IData)((0x1c000000U == 
                                     (0xfe000000U & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_st_w = (IData)((0x29800000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_ld_bu = (IData)((0x2a000000U == (0xffc00000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_ld_hu = (IData)((0x2a400000U == (0xffc00000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_ld_b = (IData)((0x28000000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_ld_h = (IData)((0x28400000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_st_b = (IData)((0x29000000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    __PVT__inst_st_h = (IData)((0x29400000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_slli_w = (IData)(((0x00008000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_14)));
    vlSelfRef.__PVT__inst_srli_w = (IData)(((0x00048000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_14)));
    vlSelfRef.__PVT__inst_srai_w = (IData)(((0x00088000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_14)));
    vlSelfRef.__PVT__inst_sll_w = (IData)(((0x00070000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_srl_w = (IData)(((0x00078000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_sra_w = (IData)(((0x00080000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    __PVT__inst_mul_w = (IData)(((0x000c0000U == (0x000f8000U 
                                                  & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                 & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_add_w = (IData)(((0U == (0x000f8000U 
                                                   & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_sub_w = (IData)(((0x00010000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_slt = (IData)(((0x00020000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_sltu = (IData)(((0x00028000U 
                                           == (0x000f8000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                          & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_nor = (IData)(((0x00040000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_and = (IData)(((0x00048000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_or = (IData)(((0x00050000U 
                                         == (0x000f8000U 
                                             & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                        & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__inst_xor = (IData)(((0x00058000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_0)));
    vlSelfRef.__PVT__need_ui12 = ((IData)(vlSelfRef.__PVT__inst_andi) 
                                  | ((IData)(vlSelfRef.__PVT__inst_xori) 
                                     | (IData)(vlSelfRef.__PVT__inst_ori)));
    __PVT__is_csr = ((IData)(__PVT__inst_csrwr) | (IData)(__PVT__inst_csrxchg));
    vlSelfRef.__PVT__need_si20 = ((IData)(__PVT__inst_pcaddu12i) 
                                  | (IData)(vlSelfRef.__PVT__inst_lu12i_w));
    vlSelfRef.__PVT__src1_is_pc = ((IData)(__PVT__inst_pcaddu12i) 
                                   | (IData)(vlSelfRef.__PVT__src2_is_4));
    __PVT__ld_sign_ext = ((IData)(__PVT__inst_ld_h) 
                          | (IData)(__PVT__inst_ld_b));
    __VdfgRegularize_h6e95ff9d_0_13 = ((IData)(__PVT__inst_st_h) 
                                       | (IData)(__PVT__inst_st_b));
    __VdfgRegularize_h6e95ff9d_0_57 = ((IData)(vlSelfRef.__PVT__inst_add_w) 
                                       | ((IData)(vlSelfRef.__PVT__inst_sub_w) 
                                          | ((IData)(vlSelfRef.__PVT__inst_slt) 
                                             | ((IData)(vlSelfRef.__PVT__inst_sltu) 
                                                | ((IData)(vlSelfRef.__PVT__inst_nor) 
                                                   | ((IData)(vlSelfRef.__PVT__inst_and) 
                                                      | ((IData)(vlSelfRef.__PVT__inst_xor) 
                                                         | (IData)(vlSelfRef.__PVT__inst_or))))))));
    __VdfgRegularize_h6e95ff9d_0_12 = ((IData)(__PVT__ld_sign_ext) 
                                       | ((IData)(__PVT__inst_ld_hu) 
                                          | (IData)(__PVT__inst_ld_bu)));
    __PVT__mem_we = ((IData)(vlSelfRef.__PVT__inst_st_w) 
                     | (IData)(__VdfgRegularize_h6e95ff9d_0_13));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_56 = ((IData)(__VdfgRegularize_h6e95ff9d_0_12) 
                                                 | ((IData)(__PVT__inst_cacop) 
                                                    | (IData)(__VdfgRegularize_h6e95ff9d_0_13)));
    __PVT__src_reg_is_rd = ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_16) 
                            | ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_15) 
                               | (IData)(__PVT__mem_we)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[0U] = (IData)(
                                                            (((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[1U] = 
        (((IData)((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                    << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
          << 1U) | (IData)(((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                              << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))) 
                            >> 0x00000020U)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[2U] = 
        (((IData)((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                    << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                        << 0x00000020U) 
                                       | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[3U] = 
        ((0xfffffffeU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[3U]) 
         | ((IData)(((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                       << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                     >> 0x00000020U)) >> 0x0000001fU));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[3U] = 
        ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[3U]) 
         | (((((((((0x17U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                              >> 0x0000001aU)) << 3U) 
                  | ((0x18U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                >> 0x0000001aU)) << 2U)) 
                 | (((0x19U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                >> 0x0000001aU)) << 1U) 
                    | (0x1aU == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                 >> 0x0000001aU)))) 
                << 0x0000000cU) | (((((0x1bU == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                 >> 0x0000001aU)) 
                                      << 3U) | ((0x13U 
                                                 == 
                                                 (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000001aU)) 
                                                << 2U)) 
                                    | (((0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU)) 
                                        << 1U) | (0x14U 
                                                  == 
                                                  (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU)))) 
                                   << 8U)) | ((((IData)(__PVT__inst_cpucfg) 
                                                << 7U) 
                                               | ((IData)(__PVT__inst_cacop) 
                                                  << 6U)) 
                                              | ((0x0000003eU 
                                                  & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     << 1U)) 
                                                 | (IData)(__PVT__is_csr)))) 
             << 0x00000010U) | (((IData)(__PVT__inst_csrxchg) 
                                 << 0x0000000fU) | 
                                (0x00007ffeU & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 9U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[4U] = 
        ((((0x000003e0U & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0) 
           | (0x0000001fU & (((IData)(__PVT__src_reg_is_rd) 
                              | (IData)(__PVT__is_csr))
                              ? vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0
                              : (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                 >> 0x0000000aU)))) 
          << 0x00000014U) | (((((0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))
                                 ? 1U : (0x0000001fU 
                                         & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                               << 0x0000000fU) | ((
                                                   (((IData)(vlSelfRef.__PVT__src1_is_pc) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelfRef.__PVT__inst_slli_w) 
                                                         | ((IData)(vlSelfRef.__PVT__inst_srli_w) 
                                                            | ((IData)(vlSelfRef.__PVT__inst_srai_w) 
                                                               | ((IData)(vlSelfRef.__PVT__inst_addi_w) 
                                                                  | ((IData)(vlSelfRef.__PVT__inst_ld_w) 
                                                                     | ((IData)(vlSelfRef.__PVT__inst_st_w) 
                                                                        | ((IData)(vlSelfRef.__PVT__inst_lu12i_w) 
                                                                           | ((IData)(vlSelfRef.__PVT__src2_is_4) 
                                                                              | ((IData)(vlSelfRef.__PVT__inst_slti) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sltui) 
                                                                                | ((IData)(vlSelfRef.__PVT__need_ui12) 
                                                                                | ((IData)(__PVT__inst_pcaddu12i) 
                                                                                | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_56))))))))))))) 
                                                        << 3U) 
                                                       | (((IData)(vlSelfRef.__PVT__inst_ld_w) 
                                                           | (IData)(__VdfgRegularize_h6e95ff9d_0_12)) 
                                                          << 2U))) 
                                                   | ((((~ 
                                                         ((IData)(__PVT__mem_we) 
                                                          | ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_16) 
                                                             | ((IData)(__PVT__inst_cacop) 
                                                                | (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_58))))) 
                                                        & ((IData)(__VdfgRegularize_h6e95ff9d_0_57) 
                                                           | ((IData)(vlSelfRef.__PVT__inst_slli_w) 
                                                              | ((IData)(vlSelfRef.__PVT__inst_srli_w) 
                                                                 | ((IData)(vlSelfRef.__PVT__inst_srai_w) 
                                                                    | ((IData)(vlSelfRef.__PVT__inst_addi_w) 
                                                                       | ((IData)(vlSelfRef.__PVT__inst_ld_w) 
                                                                          | ((IData)(vlSelfRef.__PVT__inst_st_w) 
                                                                             | ((0x17U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                                >> 0x0000001aU)) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_lu12i_w) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_slti) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sltui) 
                                                                                | ((IData)(vlSelfRef.__PVT__need_ui12) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sll_w) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_srl_w) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sra_w) 
                                                                                | ((IData)(__PVT__inst_pcaddu12i) 
                                                                                | ((IData)(__VdfgRegularize_h6e95ff9d_0_12) 
                                                                                | ((IData)(__VdfgRegularize_h6e95ff9d_0_13) 
                                                                                | ((IData)(__PVT__inst_mul_w) 
                                                                                | ((IData)(__PVT__inst_cpucfg) 
                                                                                | ((IData)(__PVT__inst_cacop) 
                                                                                | ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_15) 
                                                                                | ((0x16U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                                >> 0x0000001aU)) 
                                                                                | ((0x15U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                                >> 0x0000001aU)) 
                                                                                | ((0x14U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                                >> 0x0000001aU)) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                                >> 0x0000001aU)) 
                                                                                | (IData)(__PVT__is_csr)))))))))))))))))))))))))))) 
                                                       << 1U) 
                                                      | (IData)(__PVT__mem_we))) 
                                                  << 0x0000000aU)) 
                             | ((((((IData)(__PVT__inst_mul_w) 
                                    << 4U) | ((((IData)(__PVT__inst_ld_bu) 
                                                | (IData)(__PVT__inst_ld_b)) 
                                               << 3U) 
                                              | (((IData)(__PVT__inst_ld_hu) 
                                                  | (IData)(__PVT__inst_ld_h)) 
                                                 << 2U))) 
                                  | (((IData)(__PVT__ld_sign_ext) 
                                      << 1U) | (IData)(__PVT__inst_st_b))) 
                                 << 5U) | ((((IData)(__PVT__inst_st_h) 
                                             << 4U) 
                                            | (((2U 
                                                 & ((~ 
                                                     ((IData)(vlSelfRef.__PVT__need_si26) 
                                                      | ((IData)(__PVT__inst_csrwr) 
                                                         | (IData)(vlSelfRef.__PVT__need_si20)))) 
                                                    << 1U)) 
                                                | ((IData)(__PVT__src_reg_is_rd) 
                                                   | ((IData)(__VdfgRegularize_h6e95ff9d_0_57) 
                                                      | ((IData)(vlSelfRef.__PVT__inst_sll_w) 
                                                         | ((IData)(vlSelfRef.__PVT__inst_srl_w) 
                                                            | ((IData)(vlSelfRef.__PVT__inst_sra_w) 
                                                               | ((IData)(__PVT__inst_mul_w) 
                                                                  | (IData)(__PVT__is_csr)))))))) 
                                               << 2U)) 
                                           | ((((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_16) 
                                                | ((IData)(vlSelfRef.__PVT__src2_is_4) 
                                                   | (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_58))) 
                                               << 1U) 
                                              | (0x16U 
                                                 == 
                                                 (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000001aU)))))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_59[5U] = 
        ((0x3fff0000U & ((- (IData)((1U & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x00000019U)))) 
                         << 0x00000010U)) | (0x0000ffffU 
                                             & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x0000000aU)));
}

void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(Vasm_monitor_tb_inst_decoder* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __PVT__inst_pcaddu12i;
    __PVT__inst_pcaddu12i = 0;
    CData/*0:0*/ __PVT__inst_ld_b;
    __PVT__inst_ld_b = 0;
    CData/*0:0*/ __PVT__inst_ld_h;
    __PVT__inst_ld_h = 0;
    CData/*0:0*/ __PVT__inst_ld_bu;
    __PVT__inst_ld_bu = 0;
    CData/*0:0*/ __PVT__inst_ld_hu;
    __PVT__inst_ld_hu = 0;
    CData/*0:0*/ __PVT__inst_st_b;
    __PVT__inst_st_b = 0;
    CData/*0:0*/ __PVT__inst_st_h;
    __PVT__inst_st_h = 0;
    CData/*0:0*/ __PVT__inst_mul_w;
    __PVT__inst_mul_w = 0;
    CData/*0:0*/ __PVT__inst_cpucfg;
    __PVT__inst_cpucfg = 0;
    CData/*0:0*/ __PVT__inst_cacop;
    __PVT__inst_cacop = 0;
    CData/*0:0*/ __PVT__inst_csrwr;
    __PVT__inst_csrwr = 0;
    CData/*0:0*/ __PVT__inst_csrxchg;
    __PVT__inst_csrxchg = 0;
    CData/*0:0*/ __PVT__ld_sign_ext;
    __PVT__ld_sign_ext = 0;
    CData/*0:0*/ __PVT__src_reg_is_rd;
    __PVT__src_reg_is_rd = 0;
    CData/*0:0*/ __PVT__mem_we;
    __PVT__mem_we = 0;
    CData/*0:0*/ __PVT__is_csr;
    __PVT__is_csr = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_17;
    __VdfgRegularize_h6e95ff9d_0_17 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_18;
    __VdfgRegularize_h6e95ff9d_0_18 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_62;
    __VdfgRegularize_h6e95ff9d_0_62 = 0;
    // Body
    vlSelfRef.__PVT__inst_addi_w = (IData)((0x02800000U 
                                            == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_ld_w = (IData)((0x28800000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_slti = (IData)((0x02000000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_sltui = (IData)((0x02400000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_cpucfg = (IData)((0x00006c00U == (0xfffffc00U 
                                                  & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__need_si26 = ((0x14U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                             >> 0x0000001aU)) 
                                  | (0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x0000001aU)));
    vlSelfRef.__PVT__inst_andi = (IData)((0x03400000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_ori = (IData)((0x03800000U 
                                         == (0xffc00000U 
                                             & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_xori = (IData)((0x03c00000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_lu12i_w = (IData)((0x14000000U 
                                             == (0xfe000000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_csrwr = (IData)((0x04000020U == (0xff0003e0U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_csrxchg = ((4U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                   >> 0x00000018U)) 
                           & ((0U != (0x0000001fU & 
                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                       >> 5U))) & (1U 
                                                   != 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                       >> 5U)))));
    vlSelfRef.__PVT__src2_is_4 = ((0x13U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                             >> 0x0000001aU)) 
                                  | (0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x0000001aU)));
    __PVT__inst_cacop = (IData)((0x06000000U == (0xffc00000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_pcaddu12i = (IData)((0x1c000000U == 
                                     (0xfe000000U & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_st_w = (IData)((0x29800000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_ld_bu = (IData)((0x2a000000U == (0xffc00000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_ld_hu = (IData)((0x2a400000U == (0xffc00000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_ld_b = (IData)((0x28000000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_ld_h = (IData)((0x28400000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_st_b = (IData)((0x29000000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __PVT__inst_st_h = (IData)((0x29400000U == (0xffc00000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_slli_w = (IData)(((0x00008000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_19)));
    vlSelfRef.__PVT__inst_srli_w = (IData)(((0x00048000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_19)));
    vlSelfRef.__PVT__inst_srai_w = (IData)(((0x00088000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_19)));
    vlSelfRef.__PVT__inst_sll_w = (IData)(((0x00070000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_srl_w = (IData)(((0x00078000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_sra_w = (IData)(((0x00080000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    __PVT__inst_mul_w = (IData)(((0x000c0000U == (0x000f8000U 
                                                  & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                 & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_add_w = (IData)(((0U == (0x000f8000U 
                                                   & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_sub_w = (IData)(((0x00010000U 
                                            == (0x000f8000U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                           & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_slt = (IData)(((0x00020000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_sltu = (IData)(((0x00028000U 
                                           == (0x000f8000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                          & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_nor = (IData)(((0x00040000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_and = (IData)(((0x00048000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_or = (IData)(((0x00050000U 
                                         == (0x000f8000U 
                                             & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                        & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__inst_xor = (IData)(((0x00058000U 
                                          == (0x000f8000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                         & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_1)));
    vlSelfRef.__PVT__need_ui12 = ((IData)(vlSelfRef.__PVT__inst_andi) 
                                  | ((IData)(vlSelfRef.__PVT__inst_xori) 
                                     | (IData)(vlSelfRef.__PVT__inst_ori)));
    __PVT__is_csr = ((IData)(__PVT__inst_csrwr) | (IData)(__PVT__inst_csrxchg));
    vlSelfRef.__PVT__need_si20 = ((IData)(__PVT__inst_pcaddu12i) 
                                  | (IData)(vlSelfRef.__PVT__inst_lu12i_w));
    vlSelfRef.__PVT__src1_is_pc = ((IData)(__PVT__inst_pcaddu12i) 
                                   | (IData)(vlSelfRef.__PVT__src2_is_4));
    __PVT__ld_sign_ext = ((IData)(__PVT__inst_ld_h) 
                          | (IData)(__PVT__inst_ld_b));
    __VdfgRegularize_h6e95ff9d_0_18 = ((IData)(__PVT__inst_st_h) 
                                       | (IData)(__PVT__inst_st_b));
    __VdfgRegularize_h6e95ff9d_0_62 = ((IData)(vlSelfRef.__PVT__inst_add_w) 
                                       | ((IData)(vlSelfRef.__PVT__inst_sub_w) 
                                          | ((IData)(vlSelfRef.__PVT__inst_slt) 
                                             | ((IData)(vlSelfRef.__PVT__inst_sltu) 
                                                | ((IData)(vlSelfRef.__PVT__inst_nor) 
                                                   | ((IData)(vlSelfRef.__PVT__inst_and) 
                                                      | ((IData)(vlSelfRef.__PVT__inst_xor) 
                                                         | (IData)(vlSelfRef.__PVT__inst_or))))))));
    __VdfgRegularize_h6e95ff9d_0_17 = ((IData)(__PVT__ld_sign_ext) 
                                       | ((IData)(__PVT__inst_ld_hu) 
                                          | (IData)(__PVT__inst_ld_bu)));
    __PVT__mem_we = ((IData)(vlSelfRef.__PVT__inst_st_w) 
                     | (IData)(__VdfgRegularize_h6e95ff9d_0_18));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_61 = ((IData)(__VdfgRegularize_h6e95ff9d_0_17) 
                                                 | ((IData)(__PVT__inst_cacop) 
                                                    | (IData)(__VdfgRegularize_h6e95ff9d_0_18)));
    __PVT__src_reg_is_rd = ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_21) 
                            | ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_20) 
                               | (IData)(__PVT__mem_we)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[0U] = (IData)(
                                                            (((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[1U] = 
        (((IData)((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                    << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
          << 1U) | (IData)(((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                              << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))) 
                            >> 0x00000020U)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[2U] = 
        (((IData)((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                    << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
          >> 0x0000001fU) | ((IData)(((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                        << 0x00000020U) 
                                       | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                                      >> 0x00000020U)) 
                             << 1U));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[3U] = 
        ((0xfffffffeU & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[3U]) 
         | ((IData)(((((QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                       << 0x00000020U) | (QData)((IData)(vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                     >> 0x00000020U)) >> 0x0000001fU));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[3U] = 
        ((1U & vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[3U]) 
         | (((((((((0x17U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                              >> 0x0000001aU)) << 3U) 
                  | ((0x18U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                >> 0x0000001aU)) << 2U)) 
                 | (((0x19U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                >> 0x0000001aU)) << 1U) 
                    | (0x1aU == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                 >> 0x0000001aU)))) 
                << 0x0000000cU) | (((((0x1bU == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                 >> 0x0000001aU)) 
                                      << 3U) | ((0x13U 
                                                 == 
                                                 (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000001aU)) 
                                                << 2U)) 
                                    | (((0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU)) 
                                        << 1U) | (0x14U 
                                                  == 
                                                  (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU)))) 
                                   << 8U)) | ((((IData)(__PVT__inst_cpucfg) 
                                                << 7U) 
                                               | ((IData)(__PVT__inst_cacop) 
                                                  << 6U)) 
                                              | ((0x0000003eU 
                                                  & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     << 1U)) 
                                                 | (IData)(__PVT__is_csr)))) 
             << 0x00000010U) | (((IData)(__PVT__inst_csrxchg) 
                                 << 0x0000000fU) | 
                                (0x00007ffeU & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 9U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[4U] = 
        ((((0x000003e0U & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1) 
           | (0x0000001fU & (((IData)(__PVT__src_reg_is_rd) 
                              | (IData)(__PVT__is_csr))
                              ? vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1
                              : (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                 >> 0x0000000aU)))) 
          << 0x00000014U) | (((((0x15U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))
                                 ? 1U : (0x0000001fU 
                                         & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                               << 0x0000000fU) | ((
                                                   (((IData)(vlSelfRef.__PVT__src1_is_pc) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelfRef.__PVT__inst_slli_w) 
                                                         | ((IData)(vlSelfRef.__PVT__inst_srli_w) 
                                                            | ((IData)(vlSelfRef.__PVT__inst_srai_w) 
                                                               | ((IData)(vlSelfRef.__PVT__inst_addi_w) 
                                                                  | ((IData)(vlSelfRef.__PVT__inst_ld_w) 
                                                                     | ((IData)(vlSelfRef.__PVT__inst_st_w) 
                                                                        | ((IData)(vlSelfRef.__PVT__inst_lu12i_w) 
                                                                           | ((IData)(vlSelfRef.__PVT__src2_is_4) 
                                                                              | ((IData)(vlSelfRef.__PVT__inst_slti) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sltui) 
                                                                                | ((IData)(vlSelfRef.__PVT__need_ui12) 
                                                                                | ((IData)(__PVT__inst_pcaddu12i) 
                                                                                | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_61))))))))))))) 
                                                        << 3U) 
                                                       | (((IData)(vlSelfRef.__PVT__inst_ld_w) 
                                                           | (IData)(__VdfgRegularize_h6e95ff9d_0_17)) 
                                                          << 2U))) 
                                                   | ((((~ 
                                                         ((IData)(__PVT__mem_we) 
                                                          | ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_21) 
                                                             | ((IData)(__PVT__inst_cacop) 
                                                                | (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_63))))) 
                                                        & ((IData)(__VdfgRegularize_h6e95ff9d_0_62) 
                                                           | ((IData)(vlSelfRef.__PVT__inst_slli_w) 
                                                              | ((IData)(vlSelfRef.__PVT__inst_srli_w) 
                                                                 | ((IData)(vlSelfRef.__PVT__inst_srai_w) 
                                                                    | ((IData)(vlSelfRef.__PVT__inst_addi_w) 
                                                                       | ((IData)(vlSelfRef.__PVT__inst_ld_w) 
                                                                          | ((IData)(vlSelfRef.__PVT__inst_st_w) 
                                                                             | ((0x17U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                                >> 0x0000001aU)) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_lu12i_w) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_slti) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sltui) 
                                                                                | ((IData)(vlSelfRef.__PVT__need_ui12) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sll_w) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_srl_w) 
                                                                                | ((IData)(vlSelfRef.__PVT__inst_sra_w) 
                                                                                | ((IData)(__PVT__inst_pcaddu12i) 
                                                                                | ((IData)(__VdfgRegularize_h6e95ff9d_0_17) 
                                                                                | ((IData)(__VdfgRegularize_h6e95ff9d_0_18) 
                                                                                | ((IData)(__PVT__inst_mul_w) 
                                                                                | ((IData)(__PVT__inst_cpucfg) 
                                                                                | ((IData)(__PVT__inst_cacop) 
                                                                                | ((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_20) 
                                                                                | ((0x16U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                                >> 0x0000001aU)) 
                                                                                | ((0x15U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                                >> 0x0000001aU)) 
                                                                                | ((0x14U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                                >> 0x0000001aU)) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                                >> 0x0000001aU)) 
                                                                                | (IData)(__PVT__is_csr)))))))))))))))))))))))))))) 
                                                       << 1U) 
                                                      | (IData)(__PVT__mem_we))) 
                                                  << 0x0000000aU)) 
                             | ((((((IData)(__PVT__inst_mul_w) 
                                    << 4U) | ((((IData)(__PVT__inst_ld_bu) 
                                                | (IData)(__PVT__inst_ld_b)) 
                                               << 3U) 
                                              | (((IData)(__PVT__inst_ld_hu) 
                                                  | (IData)(__PVT__inst_ld_h)) 
                                                 << 2U))) 
                                  | (((IData)(__PVT__ld_sign_ext) 
                                      << 1U) | (IData)(__PVT__inst_st_b))) 
                                 << 5U) | ((((IData)(__PVT__inst_st_h) 
                                             << 4U) 
                                            | (((2U 
                                                 & ((~ 
                                                     ((IData)(vlSelfRef.__PVT__need_si26) 
                                                      | ((IData)(__PVT__inst_csrwr) 
                                                         | (IData)(vlSelfRef.__PVT__need_si20)))) 
                                                    << 1U)) 
                                                | ((IData)(__PVT__src_reg_is_rd) 
                                                   | ((IData)(__VdfgRegularize_h6e95ff9d_0_62) 
                                                      | ((IData)(vlSelfRef.__PVT__inst_sll_w) 
                                                         | ((IData)(vlSelfRef.__PVT__inst_srl_w) 
                                                            | ((IData)(vlSelfRef.__PVT__inst_sra_w) 
                                                               | ((IData)(__PVT__inst_mul_w) 
                                                                  | (IData)(__PVT__is_csr)))))))) 
                                               << 2U)) 
                                           | ((((IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_21) 
                                                | ((IData)(vlSelfRef.__PVT__src2_is_4) 
                                                   | (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_63))) 
                                               << 1U) 
                                              | (0x16U 
                                                 == 
                                                 (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000001aU)))))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_64[5U] = 
        ((0x3fff0000U & ((- (IData)((1U & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x00000019U)))) 
                         << 0x00000010U)) | (0x0000ffffU 
                                             & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x0000000aU)));
}
