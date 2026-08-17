// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

void Vasm_monitor_tb___024root___nba_sequent__TOP__1(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___nba_sequent__TOP__1\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[0U] 
        = (((((((((0x16U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                             >> 0x0000001aU)) << 3U) 
                 | ((0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                               >> 0x0000001aU)) << 2U)) 
                | (((0x18U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                               >> 0x0000001aU)) << 1U) 
                   | (0x19U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                >> 0x0000001aU)))) 
               << 0x0000000cU) | (((0x1aU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                              >> 0x0000001aU)) 
                                   << 0x0000000bU) 
                                  | (((0x1bU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                 >> 0x0000001aU)) 
                                      << 0x0000000aU) 
                                     | ((0x13U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU)) 
                                        << 9U)))) | 
             ((0x00000180U & ((IData)((vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                       >> 0x00000014U)) 
                              << 7U)) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cpucfg) 
                                          << 6U) | 
                                         (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cacop) 
                                           << 5U) | 
                                          (0x0000001fU 
                                           & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))))) 
            << 0x00000010U) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr) 
                                << 0x0000000fU) | (
                                                   ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrxchg) 
                                                    << 0x0000000eU) 
                                                   | (0x00003fffU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000000aU)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[1U] 
        = ((0xe0000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[1U]) 
           | ((((0x00007c00U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                << 5U)) | ((0x000003e0U 
                                            & ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd) 
                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr))
                                                 ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0
                                                 : 
                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                 >> 0x0000000aU)) 
                                               << 5U)) 
                                           | ((0x15U 
                                               == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU))
                                               ? 1U
                                               : (0x0000001fU 
                                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
               << 0x0000000eU) | (((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src1_is_pc) 
                                       << 3U) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w) 
                                                  | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w) 
                                                     | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w) 
                                                        | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_addi_w) 
                                                           | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w) 
                                                              | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_w) 
                                                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w) 
                                                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4) 
                                                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slti) 
                                                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltui) 
                                                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12) 
                                                                                | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_pcaddu12i) 
                                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_52))))))))))))) 
                                                 << 2U)) 
                                     | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_11)) 
                                         << 1U) | (
                                                   (~ 
                                                    ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__mem_we) 
                                                       | (0ULL 
                                                          != 
                                                          (0x0000000000c00000ULL 
                                                           & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out))) 
                                                      | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cacop)) 
                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_54))) 
                                                   & (((((((((((((((((((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_53) 
                                                                           | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w)) 
                                                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w)) 
                                                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w)) 
                                                                        | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_addi_w)) 
                                                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w)) 
                                                                      | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_w)) 
                                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w)) 
                                                                    | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slti)) 
                                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltui)) 
                                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12)) 
                                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w)) 
                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w)) 
                                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w)) 
                                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_pcaddu12i)) 
                                                             | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_11)) 
                                                            | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_12)) 
                                                           | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_mul_w)) 
                                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cpucfg)) 
                                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cacop)) 
                                                        | (0ULL 
                                                           != 
                                                           (0x000000000f780000ULL 
                                                            & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out))) 
                                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr)) 
                                                      | (0x17U 
                                                         == 
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000001aU)))))) 
                                    << 0x0000000aU) 
                                   | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__mem_we) 
                                       << 9U) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_mul_w) 
                                                  << 8U) 
                                                 | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_bu) 
                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_b)) 
                                                    << 7U)))) 
                                  | (((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_hu) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_h)) 
                                         << 3U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__ld_sign_ext) 
                                                   << 2U)) 
                                       | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_b) 
                                           << 1U) | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_h))) 
                                      << 3U) | ((4U 
                                                 & ((~ (IData)(
                                                               (((0ULL 
                                                                  != 
                                                                  (0x0000000000300000ULL 
                                                                   & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out)) 
                                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrwr)) 
                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)))) 
                                                    << 2U)) 
                                                | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd) 
                                                     | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_53) 
                                                        | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w) 
                                                           | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w) 
                                                              | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w) 
                                                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_mul_w) 
                                                                    | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr))))))) 
                                                    << 1U) 
                                                   | ((0U 
                                                       != 
                                                       (3U 
                                                        & (IData)(
                                                                  (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                                                   >> 0x00000016U)))) 
                                                      | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4) 
                                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_54)))))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[1U] 
        = ((0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[1U]) 
           | ((IData)((QData)((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs))) 
              << 0x0000001dU));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[2U] 
        = ((0x80000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[2U]) 
           | (((IData)((QData)((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs))) 
               >> 3U) | ((IData)(((QData)((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs)) 
                                  >> 0x00000020U)) 
                         << 0x0000001dU)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[2U] 
        = ((0x7fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[2U]) 
           | (((0U != (3U & (IData)((vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                     >> 0x00000014U))))
                ? ((0x3c000000U & ((- (IData)((1U & 
                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 9U)))) 
                                   << 0x0000001aU)) 
                   | ((0x03ff0000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                      << 0x00000010U)) 
                      | (0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000000aU))))
                : (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs 
                   >> 2U)) << 0x0000001fU));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[3U] 
        = ((0xe0000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[3U]) 
           | (0x1fffffffU & (((0U != (3U & (IData)(
                                                   (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                                    >> 0x00000014U))))
                               ? ((0x3c000000U & ((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                 >> 9U)))) 
                                                  << 0x0000001aU)) 
                                  | ((0x03ff0000U & 
                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                       << 0x00000010U)) 
                                     | (0x0000ffffU 
                                        & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000000aU))))
                               : (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs 
                                  >> 2U)) >> 1U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[3U] 
        = ((0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[3U]) 
           | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)
                ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)
                         ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           << 7U)) : 
                        ((((- (IData)((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                             >> 0x00000015U)))) 
                           & (- (IData)((1U & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12)))))) 
                          << 0x0000000cU) | (0x00000fffU 
                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x0000000aU))))) 
              << 0x0000001dU));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[4U] 
        = ((0xe0000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[4U]) 
           | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)
                ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)
                         ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           << 7U)) : 
                        ((((- (IData)((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                             >> 0x00000015U)))) 
                           & (- (IData)((1U & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12)))))) 
                          << 0x0000000cU) | (0x00000fffU 
                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x0000000aU))))) 
              >> 3U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[4U] 
        = ((0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[4U]) 
           | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slt) 
                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slti)) 
               << 0x0000001fU) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sub_w) 
                                   << 0x0000001eU) 
                                  | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_add_w) 
                                      | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_addi_w) 
                                         | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w) 
                                            | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_w) 
                                               | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src1_is_pc) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_52)))))) 
                                     << 0x0000001dU))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[5U] 
        = (0x000001ffU & ((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w) 
                              << 4U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w)) 
                                         << 3U) | (
                                                   ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w) 
                                                    | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w)) 
                                                   << 2U))) 
                            | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w)) 
                                << 1U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xor) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xori)))) 
                           << 4U) | (((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_or) 
                                        | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ori)) 
                                       << 3U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_nor) 
                                                 << 2U)) 
                                     | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_and) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_andi)) 
                                         << 1U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltu) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltui))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[0U] 
        = (((((((((0x16U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                             >> 0x0000001aU)) << 3U) 
                 | ((0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                               >> 0x0000001aU)) << 2U)) 
                | (((0x18U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                               >> 0x0000001aU)) << 1U) 
                   | (0x19U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                >> 0x0000001aU)))) 
               << 0x0000000cU) | (((0x1aU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                              >> 0x0000001aU)) 
                                   << 0x0000000bU) 
                                  | (((0x1bU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                 >> 0x0000001aU)) 
                                      << 0x0000000aU) 
                                     | ((0x13U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU)) 
                                        << 9U)))) | 
             ((0x00000180U & ((IData)((vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                       >> 0x00000014U)) 
                              << 7U)) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cpucfg) 
                                          << 6U) | 
                                         (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cacop) 
                                           << 5U) | 
                                          (0x0000001fU 
                                           & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))))) 
            << 0x00000010U) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr) 
                                << 0x0000000fU) | (
                                                   ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrxchg) 
                                                    << 0x0000000eU) 
                                                   | (0x00003fffU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000000aU)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[1U] 
        = ((0xe0000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[1U]) 
           | ((((0x00007c00U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                << 5U)) | ((0x000003e0U 
                                            & ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd) 
                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr))
                                                 ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1
                                                 : 
                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                 >> 0x0000000aU)) 
                                               << 5U)) 
                                           | ((0x15U 
                                               == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU))
                                               ? 1U
                                               : (0x0000001fU 
                                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
               << 0x0000000eU) | (((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src1_is_pc) 
                                       << 3U) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w) 
                                                  | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w) 
                                                     | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w) 
                                                        | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_addi_w) 
                                                           | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w) 
                                                              | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_w) 
                                                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w) 
                                                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4) 
                                                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slti) 
                                                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltui) 
                                                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12) 
                                                                                | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_pcaddu12i) 
                                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_56))))))))))))) 
                                                 << 2U)) 
                                     | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_14)) 
                                         << 1U) | (
                                                   (~ 
                                                    ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__mem_we) 
                                                       | (0ULL 
                                                          != 
                                                          (0x0000000000c00000ULL 
                                                           & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out))) 
                                                      | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cacop)) 
                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_58))) 
                                                   & (((((((((((((((((((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_57) 
                                                                           | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w)) 
                                                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w)) 
                                                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w)) 
                                                                        | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_addi_w)) 
                                                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w)) 
                                                                      | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_w)) 
                                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w)) 
                                                                    | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slti)) 
                                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltui)) 
                                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12)) 
                                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w)) 
                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w)) 
                                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w)) 
                                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_pcaddu12i)) 
                                                             | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_14)) 
                                                            | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_15)) 
                                                           | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_mul_w)) 
                                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cpucfg)) 
                                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cacop)) 
                                                        | (0ULL 
                                                           != 
                                                           (0x000000000f780000ULL 
                                                            & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out))) 
                                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr)) 
                                                      | (0x17U 
                                                         == 
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000001aU)))))) 
                                    << 0x0000000aU) 
                                   | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__mem_we) 
                                       << 9U) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_mul_w) 
                                                  << 8U) 
                                                 | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_bu) 
                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_b)) 
                                                    << 7U)))) 
                                  | (((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_hu) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_h)) 
                                         << 3U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__ld_sign_ext) 
                                                   << 2U)) 
                                       | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_b) 
                                           << 1U) | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_h))) 
                                      << 3U) | ((4U 
                                                 & ((~ (IData)(
                                                               (((0ULL 
                                                                  != 
                                                                  (0x0000000000300000ULL 
                                                                   & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out)) 
                                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrwr)) 
                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)))) 
                                                    << 2U)) 
                                                | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd) 
                                                     | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_57) 
                                                        | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w) 
                                                           | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w) 
                                                              | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w) 
                                                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_mul_w) 
                                                                    | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr))))))) 
                                                    << 1U) 
                                                   | ((0U 
                                                       != 
                                                       (3U 
                                                        & (IData)(
                                                                  (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                                                   >> 0x00000016U)))) 
                                                      | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4) 
                                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_58)))))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[1U] 
        = ((0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[1U]) 
           | ((IData)((QData)((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs))) 
              << 0x0000001dU));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[2U] 
        = ((0x80000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[2U]) 
           | (((IData)((QData)((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs))) 
               >> 3U) | ((IData)(((QData)((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs)) 
                                  >> 0x00000020U)) 
                         << 0x0000001dU)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[2U] 
        = ((0x7fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[2U]) 
           | (((0U != (3U & (IData)((vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                     >> 0x00000014U))))
                ? ((0x3c000000U & ((- (IData)((1U & 
                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 9U)))) 
                                   << 0x0000001aU)) 
                   | ((0x03ff0000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                      << 0x00000010U)) 
                      | (0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000000aU))))
                : (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs 
                   >> 2U)) << 0x0000001fU));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[3U] 
        = ((0xe0000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[3U]) 
           | (0x1fffffffU & (((0U != (3U & (IData)(
                                                   (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                                    >> 0x00000014U))))
                               ? ((0x3c000000U & ((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                 >> 9U)))) 
                                                  << 0x0000001aU)) 
                                  | ((0x03ff0000U & 
                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                       << 0x00000010U)) 
                                     | (0x0000ffffU 
                                        & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000000aU))))
                               : (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs 
                                  >> 2U)) >> 1U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[3U] 
        = ((0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[3U]) 
           | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)
                ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)
                         ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           << 7U)) : 
                        ((((- (IData)((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                             >> 0x00000015U)))) 
                           & (- (IData)((1U & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12)))))) 
                          << 0x0000000cU) | (0x00000fffU 
                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x0000000aU))))) 
              << 0x0000001dU));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[4U] 
        = ((0xe0000000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[4U]) 
           | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)
                ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)
                         ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           << 7U)) : 
                        ((((- (IData)((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                             >> 0x00000015U)))) 
                           & (- (IData)((1U & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12)))))) 
                          << 0x0000000cU) | (0x00000fffU 
                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x0000000aU))))) 
              >> 3U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[4U] 
        = ((0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[4U]) 
           | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slt) 
                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slti)) 
               << 0x0000001fU) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sub_w) 
                                   << 0x0000001eU) 
                                  | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_add_w) 
                                      | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_addi_w) 
                                         | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w) 
                                            | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_w) 
                                               | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src1_is_pc) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_56)))))) 
                                     << 0x0000001dU))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[5U] 
        = (0x000001ffU & ((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w) 
                              << 4U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w)) 
                                         << 3U) | (
                                                   ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w) 
                                                    | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w)) 
                                                   << 2U))) 
                            | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w)) 
                                << 1U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xor) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xori)))) 
                           << 4U) | (((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_or) 
                                        | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ori)) 
                                       << 3U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_nor) 
                                                 << 2U)) 
                                     | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_and) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_andi)) 
                                         << 1U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltu) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltui))))));
}

void Vasm_monitor_tb___024root___nba_sequent__TOP__0(Vasm_monitor_tb___024root* vlSelf);
void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(Vasm_monitor_tb_inst_decoder* vlSelf);
void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(Vasm_monitor_tb_inst_decoder* vlSelf);

void Vasm_monitor_tb___024root___eval_nba(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_nba\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vasm_monitor_tb___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
        Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0((&vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0));
        Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0((&vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1));
        Vasm_monitor_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            IData/*31:0*/ __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout = 0;
            IData/*31:0*/ __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result = 0;
            IData/*31:0*/ __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result = 0;
            CData/*0:0*/ __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte = 0;
            CData/*0:0*/ __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half = 0;
            CData/*0:0*/ __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext = 0;
            vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 
                = (vlSelfRef.asm_monitor_tb__DOT__program_addr 
                   + (vlSelfRef.asm_monitor_tb__DOT__program_words 
                      << 2U));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata 
                = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting) 
                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg) 
                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg)))
                    ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                        ? vlSelfRef.asm_monitor_tb__DOT__base_mem
                       [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]
                        : vlSelfRef.asm_monitor_tb__DOT__ext_mem
                       [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr])
                    : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf);
            vlSelfRef.asm_monitor_tb__DOT__exit_commit_later 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__exit_seen) 
                   & (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                        == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1)) 
                      | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                          == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0))));
            vlSelfRef.asm_monitor_tb__DOT__program_exit 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__user_counting) 
                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__id_valid) 
                      & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                          >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                         & ((~ ((vlSelfRef.asm_monitor_tb__DOT__branch_next_pc 
                                 >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                & (vlSelfRef.asm_monitor_tb__DOT__branch_next_pc 
                                   < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))) 
                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                               < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)))));
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1)
                    : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0));
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_half;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_byte;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata;
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr;
            if ((2U & __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result)) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
                    = (0x000000ffU & ((1U & __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result)
                                       ? (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                          >> 0x18U)
                                       : (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                          >> 0x10U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
                    = (0x0000ffffU & (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                      >> 0x10U));
            } else {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
                    = (0x000000ffU & ((1U & __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result)
                                       ? (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                          >> 8U) : __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
                    = (0x0000ffffU & __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result);
            }
            __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout 
                = (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte
                    ? (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext
                        ? (((- (IData)((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte) 
                                              >> 7U)))) 
                            << 8U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
                        : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
                    : (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half
                        ? (__Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext
                            ? (((- (IData)((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half) 
                                                  >> 0x0fU)))) 
                                << 0x00000010U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                            : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                        : __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp 
                = __Vinline_0__nba_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ms_alu_result_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)
                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                    : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1);
        }
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
}

void Vasm_monitor_tb___024root___timing_ready(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___timing_ready\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready("@(posedge asm_monitor_tb.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready("@(negedge asm_monitor_tb.clk)");
    }
}

void Vasm_monitor_tb___024root___timing_resume(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___timing_resume\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h0bec38fa__0.moveToResumeQueue(
                                                          "@(posedge asm_monitor_tb.clk)");
    vlSelfRef.__VtrigSched_h0bec29bb__0.moveToResumeQueue(
                                                          "@(negedge asm_monitor_tb.clk)");
    vlSelfRef.__VtrigSched_h0bec38fa__0.resume("@(posedge asm_monitor_tb.clk)");
    vlSelfRef.__VtrigSched_h0bec29bb__0.resume("@(negedge asm_monitor_tb.clk)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vasm_monitor_tb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vasm_monitor_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vasm_monitor_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vasm_monitor_tb___024root___eval_phase__act(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_phase__act\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                          << 2U) 
                                                         | ((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__clk)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.asm_monitor_tb__DOT__clk) 
                                                               & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0)))))));
        vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0 
            = vlSelfRef.asm_monitor_tb__DOT__clk;
    }
    Vasm_monitor_tb___024root___timing_ready(vlSelf);
    Vasm_monitor_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vasm_monitor_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vasm_monitor_tb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vasm_monitor_tb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vasm_monitor_tb___024root___timing_resume(vlSelf);
        {
            // Inlined CFunc: _eval_act
            if ((3ULL & vlSelfRef.__VactTriggered[0U])) {
                {
                    // Inlined CFunc: _act_comb__TOP__0
                    IData/*31:0*/ __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout = 0;
                    IData/*31:0*/ __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result = 0;
                    IData/*31:0*/ __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result = 0;
                    CData/*0:0*/ __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte = 0;
                    CData/*0:0*/ __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half = 0;
                    CData/*0:0*/ __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext = 0;
                    vlSelfRef.asm_monitor_tb__DOT__exit_commit_later 
                        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__exit_seen) 
                           & (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1)) 
                              | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                  == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0))));
                    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 
                        = (vlSelfRef.asm_monitor_tb__DOT__program_addr 
                           + (vlSelfRef.asm_monitor_tb__DOT__program_words 
                              << 2U));
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata 
                        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting) 
                            & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg) 
                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg)))
                            ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                                ? vlSelfRef.asm_monitor_tb__DOT__base_mem
                               [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]
                                : vlSelfRef.asm_monitor_tb__DOT__ext_mem
                               [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr])
                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf);
                    vlSelfRef.asm_monitor_tb__DOT__program_exit 
                        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__user_counting) 
                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__id_valid) 
                              & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                  >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                 & ((~ ((vlSelfRef.asm_monitor_tb__DOT__branch_next_pc 
                                         >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                        & (vlSelfRef.asm_monitor_tb__DOT__branch_next_pc 
                                           < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3))) 
                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                       < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)))));
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext 
                        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                            ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1)
                            : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0));
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_half;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_byte;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata;
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr;
                    if ((2U & __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result)) {
                        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
                            = (0x000000ffU & ((1U & __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result)
                                               ? (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                                  >> 0x18U)
                                               : (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                                  >> 0x10U)));
                        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
                            = (0x0000ffffU & (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                              >> 0x10U));
                    } else {
                        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
                            = (0x000000ffU & ((1U & __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__alu_result)
                                               ? (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result 
                                                  >> 8U)
                                               : __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result));
                        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
                            = (0x0000ffffU & __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result);
                    }
                    __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout 
                        = (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_byte
                            ? (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext
                                ? (((- (IData)((1U 
                                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte) 
                                                   >> 7U)))) 
                                    << 8U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
                                : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
                            : (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_half
                                ? (__Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__ld_sign_ext
                                    ? (((- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half) 
                                                       >> 0x0fU)))) 
                                        << 0x00000010U) 
                                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                                    : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                                : __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__mem_result));
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp 
                        = __Vinline_0__eval_act___Vinline_0__act_comb__TOP__0___Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__98__Vfuncout;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ms_alu_result_1 
                        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)
                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1);
                }
                vlSelfRef.__Vm_traceActivity[4U] = 1U;
            }
        }
    }
    return (__VactExecute);
}

bool Vasm_monitor_tb___024root___eval_phase__inact(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_phase__inact\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 5, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vasm_monitor_tb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vasm_monitor_tb___024root___eval_phase__nba(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_phase__nba\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vasm_monitor_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vasm_monitor_tb___024root___eval_nba(vlSelf);
        Vasm_monitor_tb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vasm_monitor_tb___024root___eval(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vasm_monitor_tb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 5, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 5, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vasm_monitor_tb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 5, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vasm_monitor_tb___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vasm_monitor_tb___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vasm_monitor_tb___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(Vasm_monitor_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0)) 
                                   << 1U) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0 
        = vlSelfRef.asm_monitor_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
    }
    if ((2ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

void Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(Vasm_monitor_tb___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__clk)) 
                                    & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0)) 
                                   << 1U) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__clk) 
                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0 
        = vlSelfRef.asm_monitor_tb__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec38fa__0.ready(__VeventDescription);
    }
    if ((2ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h0bec29bb__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vasm_monitor_tb___024root___eval_debug_assertions(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_debug_assertions\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
