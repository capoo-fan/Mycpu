// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(Vasm_monitor_tb_inst_decoder* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_dec3__DOT__out = (((((((((0x1fU 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x0000000fU))) 
                                                << 3U) 
                                               | ((0x1eU 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                       >> 0x0000000fU))) 
                                                  << 2U)) 
                                              | (((0x1dU 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                       >> 0x0000000fU))) 
                                                  << 1U) 
                                                 | (0x1cU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x0000000fU))))) 
                                             << 0x0000000cU) 
                                            | (((((0x1bU 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                       >> 0x0000000fU))) 
                                                  << 3U) 
                                                 | ((0x1aU 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000000fU))) 
                                                    << 2U)) 
                                                | (((0x19U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000000fU))) 
                                                    << 1U) 
                                                   | (0x18U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))))) 
                                               << 8U)) 
                                           | ((((((0x17U 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                       >> 0x0000000fU))) 
                                                  << 3U) 
                                                 | ((0x16U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000000fU))) 
                                                    << 2U)) 
                                                | (((0x15U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000000fU))) 
                                                    << 1U) 
                                                   | (0x14U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))))) 
                                               << 4U) 
                                              | ((((0x13U 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x0000000fU))) 
                                                   << 3U) 
                                                  | ((0x12U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))) 
                                                     << 2U)) 
                                                 | (((0x11U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))) 
                                                     << 1U) 
                                                    | (0x10U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                           >> 0x0000000fU))))))) 
                                          << 0x00000010U) 
                                         | (((((((0x0fU 
                                                  == 
                                                  (0x0000001fU 
                                                   & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                      >> 0x0000000fU))) 
                                                 << 3U) 
                                                | ((0x0eU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x0000000fU))) 
                                                   << 2U)) 
                                               | (((0x0dU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x0000000fU))) 
                                                   << 1U) 
                                                  | (0x0cU 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000000fU))))) 
                                              << 0x0000000cU) 
                                             | (((((0x0bU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x0000000fU))) 
                                                   << 3U) 
                                                  | ((0x0aU 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))) 
                                                     << 2U)) 
                                                 | (((9U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))) 
                                                     << 1U) 
                                                    | (8U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                           >> 0x0000000fU))))) 
                                                << 8U)) 
                                            | ((((((7U 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x0000000fU))) 
                                                   << 3U) 
                                                  | ((6U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))) 
                                                     << 2U)) 
                                                 | (((5U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x0000000fU))) 
                                                     << 1U) 
                                                    | (4U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                           >> 0x0000000fU))))) 
                                                << 4U) 
                                               | ((((3U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000000fU))) 
                                                    << 3U) 
                                                   | ((2U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                           >> 0x0000000fU))) 
                                                      << 2U)) 
                                                  | (((1U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                           >> 0x0000000fU))) 
                                                      << 1U) 
                                                     | (0U 
                                                        == 
                                                        (0x0000001fU 
                                                         & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                            >> 0x0000000fU))))))));
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
    vlSelfRef.__PVT__inst_cpucfg = (IData)((0x00006c00U 
                                            == (0xfffffc00U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__jirl_offs = (((- (IData)((1U & 
                                               (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x00000019U)))) 
                                   << 0x00000012U) 
                                  | (0x0003fffcU & 
                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                      >> 8U)));
    vlSelfRef.__PVT__inst_lu12i_w = (IData)((0x14000000U 
                                             == (0xfe000000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_csrwr = (IData)((0x04000020U 
                                           == (0xff0003e0U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_csrxchg = ((4U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                             >> 0x00000018U)) 
                                     & ((0U != (0x0000001fU 
                                                & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 5U))) 
                                        & (1U != (0x0000001fU 
                                                  & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 5U)))));
    vlSelfRef.__PVT__src2_is_4 = ((0x13U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
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
    vlSelfRef.__PVT__inst_cacop = (IData)((0x06000000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_st_w = (IData)((0x29800000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_pcaddu12i = (IData)((0x1c000000U 
                                               == (0xfe000000U 
                                                   & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__u_dec0__DOT__out = (((QData)((IData)(
                                                          (((((((((0x3fU 
                                                                   == 
                                                                   (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                    >> 0x0000001aU)) 
                                                                  << 3U) 
                                                                 | ((0x3eU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                      >> 0x0000001aU)) 
                                                                    << 2U)) 
                                                                | (((0x3dU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                      >> 0x0000001aU)) 
                                                                    << 1U) 
                                                                   | (0x3cU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)))) 
                                                               << 0x0000000cU) 
                                                              | (((((0x3bU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                      >> 0x0000001aU)) 
                                                                    << 3U) 
                                                                   | ((0x3aU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 2U)) 
                                                                  | (((0x39U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 1U) 
                                                                     | (0x38U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)))) 
                                                                 << 8U)) 
                                                             | ((((((0x37U 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                      >> 0x0000001aU)) 
                                                                    << 3U) 
                                                                   | ((0x36U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 2U)) 
                                                                  | (((0x35U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 1U) 
                                                                     | (0x34U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)))) 
                                                                 << 4U) 
                                                                | ((((0x33U 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x32U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x31U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x30U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)))))) 
                                                            << 0x00000010U) 
                                                           | (((((((0x2fU 
                                                                    == 
                                                                    (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                     >> 0x0000001aU)) 
                                                                   << 3U) 
                                                                  | ((0x2eU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 2U)) 
                                                                 | (((0x2dU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 1U) 
                                                                    | (0x2cU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)))) 
                                                                << 0x0000000cU) 
                                                               | (((((0x2bU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x2aU 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x29U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x28U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)))) 
                                                                  << 8U)) 
                                                              | ((((((0x27U 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x26U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x25U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x24U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)))) 
                                                                  << 4U) 
                                                                 | ((((0x23U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((0x22U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((0x21U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (0x20U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                           >> 0x0000001aU))))))))) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(
                                                           (((((((((0x1fU 
                                                                    == 
                                                                    (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                     >> 0x0000001aU)) 
                                                                   << 3U) 
                                                                  | ((0x1eU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 2U)) 
                                                                 | (((0x1dU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 1U) 
                                                                    | (0x1cU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)))) 
                                                                << 0x0000000cU) 
                                                               | (((((0x1bU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x1aU 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x19U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x18U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)))) 
                                                                  << 8U)) 
                                                              | ((((((0x17U 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x16U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x15U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x14U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)))) 
                                                                  << 4U) 
                                                                 | ((((0x13U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((0x12U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((0x11U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (0x10U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                           >> 0x0000001aU)))))) 
                                                             << 0x00000010U) 
                                                            | (((((((0x0fU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                      >> 0x0000001aU)) 
                                                                    << 3U) 
                                                                   | ((0x0eU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 2U)) 
                                                                  | (((0x0dU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 1U) 
                                                                     | (0x0cU 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)))) 
                                                                 << 0x0000000cU) 
                                                                | (((((0x0bU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((0x0aU 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((9U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (8U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                           >> 0x0000001aU)))) 
                                                                   << 8U)) 
                                                               | ((((((7U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((6U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((5U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (4U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                           >> 0x0000001aU)))) 
                                                                   << 4U) 
                                                                  | ((((3U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                         >> 0x0000001aU)) 
                                                                       << 3U) 
                                                                      | ((2U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                           >> 0x0000001aU)) 
                                                                         << 2U)) 
                                                                     | (((1U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                           >> 0x0000001aU)) 
                                                                         << 1U) 
                                                                        | (0U 
                                                                           == 
                                                                           (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                                            >> 0x0000001aU))))))))));
    vlSelfRef.__PVT__inst_ld_bu = (IData)((0x2a000000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_ld_hu = (IData)((0x2a400000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_ld_b = (IData)((0x28000000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_ld_h = (IData)((0x28400000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_st_b = (IData)((0x29000000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_st_h = (IData)((0x29400000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__PVT__inst_slli_w = (IData)(((0x00008000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_13)));
    vlSelfRef.__PVT__inst_srli_w = (IData)(((0x00048000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_13)));
    vlSelfRef.__PVT__inst_srai_w = (IData)(((0x00088000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_13)));
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
    vlSelfRef.__PVT__inst_mul_w = (IData)(((0x000c0000U 
                                            == (0x000f8000U 
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
    vlSelfRef.__PVT__is_csr = ((IData)(vlSelfRef.__PVT__inst_csrwr) 
                               | (IData)(vlSelfRef.__PVT__inst_csrxchg));
    vlSelfRef.__PVT__need_ui12 = ((IData)(vlSelfRef.__PVT__inst_andi) 
                                  | ((IData)(vlSelfRef.__PVT__inst_xori) 
                                     | (IData)(vlSelfRef.__PVT__inst_ori)));
    vlSelfRef.__PVT__need_si20 = ((IData)(vlSelfRef.__PVT__inst_pcaddu12i) 
                                  | (IData)(vlSelfRef.__PVT__inst_lu12i_w));
    vlSelfRef.__PVT__src1_is_pc = ((IData)(vlSelfRef.__PVT__inst_pcaddu12i) 
                                   | (IData)(vlSelfRef.__PVT__src2_is_4));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_54 = (IData)(
                                                        ((0ULL 
                                                          != 
                                                          (0x000000000f000000ULL 
                                                           & vlSelfRef.__PVT__u_dec0__DOT__out)) 
                                                         | (0x14U 
                                                            == 
                                                            (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                             >> 0x0000001aU))));
    vlSelfRef.__PVT__ld_sign_ext = ((IData)(vlSelfRef.__PVT__inst_ld_h) 
                                    | (IData)(vlSelfRef.__PVT__inst_ld_b));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12 = ((IData)(vlSelfRef.__PVT__inst_st_h) 
                                                 | (IData)(vlSelfRef.__PVT__inst_st_b));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_53 = ((IData)(vlSelfRef.__PVT__inst_add_w) 
                                                 | ((IData)(vlSelfRef.__PVT__inst_sub_w) 
                                                    | ((IData)(vlSelfRef.__PVT__inst_slt) 
                                                       | ((IData)(vlSelfRef.__PVT__inst_sltu) 
                                                          | ((IData)(vlSelfRef.__PVT__inst_nor) 
                                                             | ((IData)(vlSelfRef.__PVT__inst_and) 
                                                                | ((IData)(vlSelfRef.__PVT__inst_xor) 
                                                                   | (IData)(vlSelfRef.__PVT__inst_or))))))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11 = ((IData)(vlSelfRef.__PVT__ld_sign_ext) 
                                                 | ((IData)(vlSelfRef.__PVT__inst_ld_hu) 
                                                    | (IData)(vlSelfRef.__PVT__inst_ld_bu)));
    vlSelfRef.__PVT__mem_we = ((IData)(vlSelfRef.__PVT__inst_st_w) 
                               | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_52 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11) 
                                                 | ((IData)(vlSelfRef.__PVT__inst_cacop) 
                                                    | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12)));
    vlSelfRef.__PVT__src_reg_is_rd = (IData)(((0ULL 
                                               != (0x000000000fc00000ULL 
                                                   & vlSelfRef.__PVT__u_dec0__DOT__out)) 
                                              | (IData)(vlSelfRef.__PVT__mem_we)));
}

void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(Vasm_monitor_tb_inst_decoder* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__u_dec3__DOT__out = (((((((((0x1fU 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x0000000fU))) 
                                                << 3U) 
                                               | ((0x1eU 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                       >> 0x0000000fU))) 
                                                  << 2U)) 
                                              | (((0x1dU 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                       >> 0x0000000fU))) 
                                                  << 1U) 
                                                 | (0x1cU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x0000000fU))))) 
                                             << 0x0000000cU) 
                                            | (((((0x1bU 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                       >> 0x0000000fU))) 
                                                  << 3U) 
                                                 | ((0x1aU 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000000fU))) 
                                                    << 2U)) 
                                                | (((0x19U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000000fU))) 
                                                    << 1U) 
                                                   | (0x18U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))))) 
                                               << 8U)) 
                                           | ((((((0x17U 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                       >> 0x0000000fU))) 
                                                  << 3U) 
                                                 | ((0x16U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000000fU))) 
                                                    << 2U)) 
                                                | (((0x15U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000000fU))) 
                                                    << 1U) 
                                                   | (0x14U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))))) 
                                               << 4U) 
                                              | ((((0x13U 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x0000000fU))) 
                                                   << 3U) 
                                                  | ((0x12U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))) 
                                                     << 2U)) 
                                                 | (((0x11U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))) 
                                                     << 1U) 
                                                    | (0x10U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                           >> 0x0000000fU))))))) 
                                          << 0x00000010U) 
                                         | (((((((0x0fU 
                                                  == 
                                                  (0x0000001fU 
                                                   & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                      >> 0x0000000fU))) 
                                                 << 3U) 
                                                | ((0x0eU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x0000000fU))) 
                                                   << 2U)) 
                                               | (((0x0dU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x0000000fU))) 
                                                   << 1U) 
                                                  | (0x0cU 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000000fU))))) 
                                              << 0x0000000cU) 
                                             | (((((0x0bU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x0000000fU))) 
                                                   << 3U) 
                                                  | ((0x0aU 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))) 
                                                     << 2U)) 
                                                 | (((9U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))) 
                                                     << 1U) 
                                                    | (8U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                           >> 0x0000000fU))))) 
                                                << 8U)) 
                                            | ((((((7U 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x0000000fU))) 
                                                   << 3U) 
                                                  | ((6U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))) 
                                                     << 2U)) 
                                                 | (((5U 
                                                      == 
                                                      (0x0000001fU 
                                                       & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x0000000fU))) 
                                                     << 1U) 
                                                    | (4U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                           >> 0x0000000fU))))) 
                                                << 4U) 
                                               | ((((3U 
                                                     == 
                                                     (0x0000001fU 
                                                      & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000000fU))) 
                                                    << 3U) 
                                                   | ((2U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                           >> 0x0000000fU))) 
                                                      << 2U)) 
                                                  | (((1U 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                           >> 0x0000000fU))) 
                                                      << 1U) 
                                                     | (0U 
                                                        == 
                                                        (0x0000001fU 
                                                         & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                            >> 0x0000000fU))))))));
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
    vlSelfRef.__PVT__inst_cpucfg = (IData)((0x00006c00U 
                                            == (0xfffffc00U 
                                                & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__jirl_offs = (((- (IData)((1U & 
                                               (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x00000019U)))) 
                                   << 0x00000012U) 
                                  | (0x0003fffcU & 
                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                      >> 8U)));
    vlSelfRef.__PVT__inst_lu12i_w = (IData)((0x14000000U 
                                             == (0xfe000000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_csrwr = (IData)((0x04000020U 
                                           == (0xff0003e0U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_csrxchg = ((4U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                             >> 0x00000018U)) 
                                     & ((0U != (0x0000001fU 
                                                & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 5U))) 
                                        & (1U != (0x0000001fU 
                                                  & (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 5U)))));
    vlSelfRef.__PVT__src2_is_4 = ((0x13U == (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
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
    vlSelfRef.__PVT__inst_cacop = (IData)((0x06000000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_st_w = (IData)((0x29800000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_pcaddu12i = (IData)((0x1c000000U 
                                               == (0xfe000000U 
                                                   & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__u_dec0__DOT__out = (((QData)((IData)(
                                                          (((((((((0x3fU 
                                                                   == 
                                                                   (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                    >> 0x0000001aU)) 
                                                                  << 3U) 
                                                                 | ((0x3eU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                      >> 0x0000001aU)) 
                                                                    << 2U)) 
                                                                | (((0x3dU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                      >> 0x0000001aU)) 
                                                                    << 1U) 
                                                                   | (0x3cU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)))) 
                                                               << 0x0000000cU) 
                                                              | (((((0x3bU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                      >> 0x0000001aU)) 
                                                                    << 3U) 
                                                                   | ((0x3aU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 2U)) 
                                                                  | (((0x39U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 1U) 
                                                                     | (0x38U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)))) 
                                                                 << 8U)) 
                                                             | ((((((0x37U 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                      >> 0x0000001aU)) 
                                                                    << 3U) 
                                                                   | ((0x36U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 2U)) 
                                                                  | (((0x35U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 1U) 
                                                                     | (0x34U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)))) 
                                                                 << 4U) 
                                                                | ((((0x33U 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x32U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x31U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x30U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)))))) 
                                                            << 0x00000010U) 
                                                           | (((((((0x2fU 
                                                                    == 
                                                                    (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                     >> 0x0000001aU)) 
                                                                   << 3U) 
                                                                  | ((0x2eU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 2U)) 
                                                                 | (((0x2dU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 1U) 
                                                                    | (0x2cU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)))) 
                                                                << 0x0000000cU) 
                                                               | (((((0x2bU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x2aU 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x29U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x28U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)))) 
                                                                  << 8U)) 
                                                              | ((((((0x27U 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x26U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x25U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x24U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)))) 
                                                                  << 4U) 
                                                                 | ((((0x23U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((0x22U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((0x21U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (0x20U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                           >> 0x0000001aU))))))))) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(
                                                           (((((((((0x1fU 
                                                                    == 
                                                                    (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                     >> 0x0000001aU)) 
                                                                   << 3U) 
                                                                  | ((0x1eU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 2U)) 
                                                                 | (((0x1dU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 1U) 
                                                                    | (0x1cU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)))) 
                                                                << 0x0000000cU) 
                                                               | (((((0x1bU 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x1aU 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x19U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x18U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)))) 
                                                                  << 8U)) 
                                                              | ((((((0x17U 
                                                                      == 
                                                                      (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                       >> 0x0000001aU)) 
                                                                     << 3U) 
                                                                    | ((0x16U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 2U)) 
                                                                   | (((0x15U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 1U) 
                                                                      | (0x14U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)))) 
                                                                  << 4U) 
                                                                 | ((((0x13U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((0x12U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((0x11U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (0x10U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                           >> 0x0000001aU)))))) 
                                                             << 0x00000010U) 
                                                            | (((((((0x0fU 
                                                                     == 
                                                                     (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                      >> 0x0000001aU)) 
                                                                    << 3U) 
                                                                   | ((0x0eU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 2U)) 
                                                                  | (((0x0dU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 1U) 
                                                                     | (0x0cU 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)))) 
                                                                 << 0x0000000cU) 
                                                                | (((((0x0bU 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((0x0aU 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((9U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (8U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                           >> 0x0000001aU)))) 
                                                                   << 8U)) 
                                                               | ((((((7U 
                                                                       == 
                                                                       (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                        >> 0x0000001aU)) 
                                                                      << 3U) 
                                                                     | ((6U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 2U)) 
                                                                    | (((5U 
                                                                         == 
                                                                         (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                          >> 0x0000001aU)) 
                                                                        << 1U) 
                                                                       | (4U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                           >> 0x0000001aU)))) 
                                                                   << 4U) 
                                                                  | ((((3U 
                                                                        == 
                                                                        (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                         >> 0x0000001aU)) 
                                                                       << 3U) 
                                                                      | ((2U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                           >> 0x0000001aU)) 
                                                                         << 2U)) 
                                                                     | (((1U 
                                                                          == 
                                                                          (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                           >> 0x0000001aU)) 
                                                                         << 1U) 
                                                                        | (0U 
                                                                           == 
                                                                           (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                                            >> 0x0000001aU))))))))));
    vlSelfRef.__PVT__inst_ld_bu = (IData)((0x2a000000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_ld_hu = (IData)((0x2a400000U 
                                           == (0xffc00000U 
                                               & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_ld_b = (IData)((0x28000000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_ld_h = (IData)((0x28400000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_st_b = (IData)((0x29000000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_st_h = (IData)((0x29400000U 
                                          == (0xffc00000U 
                                              & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__PVT__inst_slli_w = (IData)(((0x00008000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_16)));
    vlSelfRef.__PVT__inst_srli_w = (IData)(((0x00048000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_16)));
    vlSelfRef.__PVT__inst_srai_w = (IData)(((0x00088000U 
                                             == (0x000f8000U 
                                                 & vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)) 
                                            & (IData)(vlSymsp->TOP.__VdfgRegularize_h6e95ff9d_0_16)));
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
    vlSelfRef.__PVT__inst_mul_w = (IData)(((0x000c0000U 
                                            == (0x000f8000U 
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
    vlSelfRef.__PVT__is_csr = ((IData)(vlSelfRef.__PVT__inst_csrwr) 
                               | (IData)(vlSelfRef.__PVT__inst_csrxchg));
    vlSelfRef.__PVT__need_ui12 = ((IData)(vlSelfRef.__PVT__inst_andi) 
                                  | ((IData)(vlSelfRef.__PVT__inst_xori) 
                                     | (IData)(vlSelfRef.__PVT__inst_ori)));
    vlSelfRef.__PVT__need_si20 = ((IData)(vlSelfRef.__PVT__inst_pcaddu12i) 
                                  | (IData)(vlSelfRef.__PVT__inst_lu12i_w));
    vlSelfRef.__PVT__src1_is_pc = ((IData)(vlSelfRef.__PVT__inst_pcaddu12i) 
                                   | (IData)(vlSelfRef.__PVT__src2_is_4));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_58 = (IData)(
                                                        ((0ULL 
                                                          != 
                                                          (0x000000000f000000ULL 
                                                           & vlSelfRef.__PVT__u_dec0__DOT__out)) 
                                                         | (0x14U 
                                                            == 
                                                            (vlSymsp->TOP.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                             >> 0x0000001aU))));
    vlSelfRef.__PVT__ld_sign_ext = ((IData)(vlSelfRef.__PVT__inst_ld_h) 
                                    | (IData)(vlSelfRef.__PVT__inst_ld_b));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15 = ((IData)(vlSelfRef.__PVT__inst_st_h) 
                                                 | (IData)(vlSelfRef.__PVT__inst_st_b));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_57 = ((IData)(vlSelfRef.__PVT__inst_add_w) 
                                                 | ((IData)(vlSelfRef.__PVT__inst_sub_w) 
                                                    | ((IData)(vlSelfRef.__PVT__inst_slt) 
                                                       | ((IData)(vlSelfRef.__PVT__inst_sltu) 
                                                          | ((IData)(vlSelfRef.__PVT__inst_nor) 
                                                             | ((IData)(vlSelfRef.__PVT__inst_and) 
                                                                | ((IData)(vlSelfRef.__PVT__inst_xor) 
                                                                   | (IData)(vlSelfRef.__PVT__inst_or))))))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = ((IData)(vlSelfRef.__PVT__ld_sign_ext) 
                                                 | ((IData)(vlSelfRef.__PVT__inst_ld_hu) 
                                                    | (IData)(vlSelfRef.__PVT__inst_ld_bu)));
    vlSelfRef.__PVT__mem_we = ((IData)(vlSelfRef.__PVT__inst_st_w) 
                               | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_56 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14) 
                                                 | ((IData)(vlSelfRef.__PVT__inst_cacop) 
                                                    | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15)));
    vlSelfRef.__PVT__src_reg_is_rd = (IData)(((0ULL 
                                               != (0x000000000fc00000ULL 
                                                   & vlSelfRef.__PVT__u_dec0__DOT__out)) 
                                              | (IData)(vlSelfRef.__PVT__mem_we)));
}
