// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

VlCoroutine Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__0(Vasm_monitor_tb___024root* vlSelf);
VlCoroutine Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__1(Vasm_monitor_tb___024root* vlSelf);

void Vasm_monitor_tb___024root___eval_initial(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_initial\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(Vasm_monitor_tb___024root* vlSelf, const char* __VeventDescription);
extern const VlWide<16>/*511:0*/ Vasm_monitor_tb__ConstPool__CONST_hf291e7a9_0;
extern const VlWide<16>/*511:0*/ Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0;
void Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(Vasm_monitor_tb___024root* vlSelf, const char* __VeventDescription);
extern const VlWide<16>/*511:0*/ Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0;
extern const VlWide<16>/*511:0*/ Vasm_monitor_tb__ConstPool__CONST_h7ba9fa37_0;
extern const VlWide<16>/*511:0*/ Vasm_monitor_tb__ConstPool__CONST_h3418fe69_0;

VlCoroutine Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__0(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ asm_monitor_tb__DOT____VlemExpr_9;
    IData/*31:0*/ asm_monitor_tb__DOT____VlemExpr_8;
    IData/*31:0*/ asm_monitor_tb__DOT____VlemExpr_7;
    IData/*31:0*/ asm_monitor_tb__DOT____VlemExpr_6;
    CData/*0:0*/ asm_monitor_tb__DOT____VlemLogOr_2;
    IData/*31:0*/ asm_monitor_tb__DOT____VlemExpr_0;
    IData/*31:0*/ asm_monitor_tb__DOT__wait_cycles;
    asm_monitor_tb__DOT__wait_cycles = 0;
    CData/*7:0*/ asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__wait_tx__Vstatic__wanted;
    asm_monitor_tb__DOT__wait_tx__Vstatic__wanted = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__unnamedblk1_1__DOT____Vrepeat0;
    asm_monitor_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_asm_monitor_tb__DOT__wait_tx__0__wanted;
    __Vtask_asm_monitor_tb__DOT__wait_tx__0__wanted = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__1__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__1__message);
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__2__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__4__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__4__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__5__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__5__message);
    IData/*31:0*/ __Vtask_asm_monitor_tb__DOT__send_word_le__6__value;
    __Vtask_asm_monitor_tb__DOT__send_word_le__6__value = 0;
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__7__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__7__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__8__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__8__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__9__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__9__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__10__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__10__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__11__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__11__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__12__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__12__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__13__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__13__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__14__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__14__message);
    IData/*31:0*/ __Vtask_asm_monitor_tb__DOT__send_word_le__15__value;
    __Vtask_asm_monitor_tb__DOT__send_word_le__15__value = 0;
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__16__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__16__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__17__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__17__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__18__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__18__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__19__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__19__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__20__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__20__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__21__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__21__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__22__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__22__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__23__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__23__message);
    IData/*31:0*/ __Vtask_asm_monitor_tb__DOT__send_word_le__24__value;
    __Vtask_asm_monitor_tb__DOT__send_word_le__24__value = 0;
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__25__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__25__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__26__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__26__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__27__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__27__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__28__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__28__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__29__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__29__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__30__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__30__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__31__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__31__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__32__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__32__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__33__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__33__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__34__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__34__message);
    IData/*31:0*/ __Vtask_asm_monitor_tb__DOT__send_word_le__35__value;
    __Vtask_asm_monitor_tb__DOT__send_word_le__35__value = 0;
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__36__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__36__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__37__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__37__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__38__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__38__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__39__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__39__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__40__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__40__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__41__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__41__message);
    CData/*7:0*/ __Vtask_asm_monitor_tb__DOT__send_rx_byte__42__value;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__42__value = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__43__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__43__message);
    IData/*31:0*/ __Vtask_asm_monitor_tb__DOT__wait_tx__44__wanted;
    __Vtask_asm_monitor_tb__DOT__wait_tx__44__wanted = 0;
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__45__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__45__message);
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__46__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__46__message);
    VlWide<16>/*511:0*/ __Vtask_asm_monitor_tb__DOT__fail__47__message;
    VL_ZERO_W(512, __Vtask_asm_monitor_tb__DOT__fail__47__message);
    // Body
    asm_monitor_tb__DOT____VlemExpr_0 = VL_VALUEPLUSARGS_INW(1024, "BASE_MIF=%s"s, 
                                                             vlSelfRef.asm_monitor_tb__DOT__base_file);
    asm_monitor_tb__DOT____VlemLogOr_2 = (! asm_monitor_tb__DOT____VlemExpr_0);
    if ((1U & (~ (IData)(asm_monitor_tb__DOT____VlemLogOr_2)))) {
        vlSelfRef.asm_monitor_tb__DOT____VlemExpr_1 
            = VL_VALUEPLUSARGS_INI(32, "BASE_WORDS=%d"s, 
                                   vlSelfRef.asm_monitor_tb__DOT__base_words);
        asm_monitor_tb__DOT____VlemLogOr_2 = (! vlSelfRef.asm_monitor_tb__DOT____VlemExpr_1);
    }
    if ((1U & (~ (IData)(asm_monitor_tb__DOT____VlemLogOr_2)))) {
        vlSelfRef.asm_monitor_tb__DOT____VlemExpr_3 
            = VL_VALUEPLUSARGS_INW(1024, "PROGRAM_MIF=%s"s, 
                                   vlSelfRef.asm_monitor_tb__DOT__program_file);
        asm_monitor_tb__DOT____VlemLogOr_2 = (! vlSelfRef.asm_monitor_tb__DOT____VlemExpr_3);
    }
    if ((1U & (~ (IData)(asm_monitor_tb__DOT____VlemLogOr_2)))) {
        vlSelfRef.asm_monitor_tb__DOT____VlemExpr_4 
            = VL_VALUEPLUSARGS_INI(32, "PROGRAM_WORDS=%d"s, 
                                   vlSelfRef.asm_monitor_tb__DOT__program_words);
        asm_monitor_tb__DOT____VlemLogOr_2 = (! vlSelfRef.asm_monitor_tb__DOT____VlemExpr_4);
    }
    if ((1U & (~ (IData)(asm_monitor_tb__DOT____VlemLogOr_2)))) {
        vlSelfRef.asm_monitor_tb__DOT____VlemExpr_5 
            = VL_VALUEPLUSARGS_INI(32, "PROGRAM_ADDR=%h"s, 
                                   vlSelfRef.asm_monitor_tb__DOT__program_addr);
        asm_monitor_tb__DOT____VlemLogOr_2 = (! vlSelfRef.asm_monitor_tb__DOT____VlemExpr_5);
    }
    if (VL_UNLIKELY((asm_monitor_tb__DOT____VlemLogOr_2))) {
        VL_WRITEF_NX("[%0t] %%Fatal: asm_monitor_tb.v:264: Assertion failed in %m: required plusargs: BASE_MIF BASE_WORDS PROGRAM_MIF PROGRAM_WORDS PROGRAM_ADDR\n",3, 'M',vlSymsp->name(),"asm_monitor_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 264, "", false);
    }
    asm_monitor_tb__DOT____VlemExpr_6 = VL_VALUEPLUSARGS_INQ(64, "MAX_CYCLES=%d"s, 
                                                             vlSelfRef.asm_monitor_tb__DOT__max_cycles);
    if ((! asm_monitor_tb__DOT____VlemExpr_6)) {
        vlSelfRef.asm_monitor_tb__DOT__max_cycles = 0x0000000000989680ULL;
    }
    asm_monitor_tb__DOT____VlemExpr_7 = VL_VALUEPLUSARGS_INI(32, "ENTRY_ADDR=%h"s, 
                                                             vlSelfRef.asm_monitor_tb__DOT__entry_addr);
    if ((! asm_monitor_tb__DOT____VlemExpr_7)) {
        vlSelfRef.asm_monitor_tb__DOT__entry_addr = vlSelfRef.asm_monitor_tb__DOT__program_addr;
    }
    asm_monitor_tb__DOT____VlemExpr_8 = VL_VALUEPLUSARGS_INI(32, "WATCH_ADDR=%h"s, 
                                                             vlSelfRef.asm_monitor_tb__DOT__watch_addr);
    if ((! asm_monitor_tb__DOT____VlemExpr_8)) {
        vlSelfRef.asm_monitor_tb__DOT__watch_addr = 0U;
    }
    asm_monitor_tb__DOT____VlemExpr_9 = VL_VALUEPLUSARGS_INI(32, "WATCH_WORDS=%d"s, 
                                                             vlSelfRef.asm_monitor_tb__DOT__watch_words);
    if ((! asm_monitor_tb__DOT____VlemExpr_9)) {
        vlSelfRef.asm_monitor_tb__DOT__watch_words = 0U;
    }
    VL_READMEM_N(false, 32, 1048576, 0, VL_CVT_PACK_STR_NW(32, vlSelfRef.asm_monitor_tb__DOT__base_file)
                 ,  &(vlSelfRef.asm_monitor_tb__DOT__base_mem)
                 , 0U, (vlSelfRef.asm_monitor_tb__DOT__base_words 
                        - (IData)(1U)));
    VL_READMEM_N(false, 32, 65536, 0, VL_CVT_PACK_STR_NW(32, vlSelfRef.asm_monitor_tb__DOT__program_file)
                 ,  &(vlSelfRef.asm_monitor_tb__DOT__program_mem)
                 , 0U, (vlSelfRef.asm_monitor_tb__DOT__program_words 
                        - (IData)(1U)));
    vlSelfRef.asm_monitor_tb__DOT__clk = 0U;
    vlSelfRef.asm_monitor_tb__DOT__resetn = 0U;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = 0U;
    vlSelfRef.asm_monitor_tb__DOT__tx_count = 0U;
    vlSelfRef.asm_monitor_tb__DOT__cycle_count = 0ULL;
    vlSelfRef.asm_monitor_tb__DOT__counting = 0U;
    vlSelfRef.asm_monitor_tb__DOT__exit_seen = 0U;
    vlSelfRef.asm_monitor_tb__DOT__benchmark_done = 0U;
    vlSelfRef.asm_monitor_tb__DOT__exit_pc = 0U;
    vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles = 0ULL;
    vlSelfRef.asm_monitor_tb__DOT__commit_count = 0ULL;
    vlSelfRef.asm_monitor_tb__DOT__write_count = 0ULL;
    vlSelfRef.asm_monitor_tb__DOT__write_log_count = 0U;
    asm_monitor_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 = 8U;
    while (VL_LTS_III(32, 0U, asm_monitor_tb__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             276);
        asm_monitor_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (asm_monitor_tb__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.asm_monitor_tb__DOT__resetn = 1U;
    __Vtask_asm_monitor_tb__DOT__wait_tx__0__wanted = 0x00000026U;
    asm_monitor_tb__DOT__wait_tx__Vstatic__wanted = __Vtask_asm_monitor_tb__DOT__wait_tx__0__wanted;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while (VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__tx_count, asm_monitor_tb__DOT__wait_tx__Vstatic__wanted)) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             212);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x0007a120U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__1__message, Vasm_monitor_tb__ConstPool__CONST_hf291e7a9_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__1__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    if (VL_UNLIKELY(((0x4dU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[0U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x4fU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[1U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x4eU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[2U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x49U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[3U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x54U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[4U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x4fU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[5U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x52U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[6U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x20U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[7U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x66U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[8U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x6fU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[9U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x72U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[10U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x20U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[11U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x4cU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[12U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x6fU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[13U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x6fU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[14U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x6eU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[15U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x67U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[16U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x61U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[17U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x72U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[18U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x63U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[19U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x68U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[20U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x33U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[21U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x32U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[22U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x20U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[23U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x2dU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[24U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x20U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[25U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x69U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[26U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x6eU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[27U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x69U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[28U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x74U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[29U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x69U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[30U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x61U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[31U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x6cU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[32U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x69U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[33U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x7aU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[34U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x65U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[35U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x64U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[36U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY(((0x2eU != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[37U])))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__2__message, Vasm_monitor_tb__ConstPool__CONST_h92ab22fc_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__2__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__4__value = 0x41U;
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__4__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__5__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__5__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_word_le__6__value 
        = vlSelfRef.asm_monitor_tb__DOT__program_addr;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__7__value 
        = (0x000000ffU & __Vtask_asm_monitor_tb__DOT__send_word_le__6__value);
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__7__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__8__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__8__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__9__value 
        = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__6__value 
                          >> 8U));
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__9__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__10__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__10__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__11__value 
        = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__6__value 
                          >> 0x10U));
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__11__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__12__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__12__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__13__value 
        = (__Vtask_asm_monitor_tb__DOT__send_word_le__6__value 
           >> 0x18U);
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__13__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__14__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__14__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_word_le__15__value 
        = VL_MULS_III(32, (IData)(4U), vlSelfRef.asm_monitor_tb__DOT__program_words);
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__16__value 
        = (0x000000ffU & __Vtask_asm_monitor_tb__DOT__send_word_le__15__value);
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__16__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__17__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__17__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__18__value 
        = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__15__value 
                          >> 8U));
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__18__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__19__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__19__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__20__value 
        = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__15__value 
                          >> 0x10U));
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__20__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__21__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__21__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__22__value 
        = (__Vtask_asm_monitor_tb__DOT__send_word_le__15__value 
           >> 0x18U);
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__22__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__23__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__23__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n = 0U;
    while (VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n, vlSelfRef.asm_monitor_tb__DOT__program_words)) {
        __Vtask_asm_monitor_tb__DOT__send_word_le__24__value 
            = vlSelfRef.asm_monitor_tb__DOT__program_mem
            [(0x0000ffffU & vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n)];
        __Vtask_asm_monitor_tb__DOT__send_rx_byte__25__value 
            = (0x000000ffU & __Vtask_asm_monitor_tb__DOT__send_word_le__24__value);
        asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
            = __Vtask_asm_monitor_tb__DOT__send_rx_byte__25__value;
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             182);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_data 
            = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
        asm_monitor_tb__DOT__wait_cycles = 0U;
        while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 187);
            asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                                + asm_monitor_tb__DOT__wait_cycles);
            if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
                VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__26__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
                VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                             , '#',512,__Vtask_asm_monitor_tb__DOT__fail__26__message.data()
                             , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                             , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
            }
        }
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             191);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
        while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 193);
        }
        __Vtask_asm_monitor_tb__DOT__send_rx_byte__27__value 
            = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__24__value 
                              >> 8U));
        asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
            = __Vtask_asm_monitor_tb__DOT__send_rx_byte__27__value;
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             182);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_data 
            = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
        asm_monitor_tb__DOT__wait_cycles = 0U;
        while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 187);
            asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                                + asm_monitor_tb__DOT__wait_cycles);
            if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
                VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__28__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
                VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                             , '#',512,__Vtask_asm_monitor_tb__DOT__fail__28__message.data()
                             , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                             , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
            }
        }
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             191);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
        while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 193);
        }
        __Vtask_asm_monitor_tb__DOT__send_rx_byte__29__value 
            = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__24__value 
                              >> 0x10U));
        asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
            = __Vtask_asm_monitor_tb__DOT__send_rx_byte__29__value;
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             182);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_data 
            = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
        asm_monitor_tb__DOT__wait_cycles = 0U;
        while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 187);
            asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                                + asm_monitor_tb__DOT__wait_cycles);
            if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
                VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__30__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
                VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                             , '#',512,__Vtask_asm_monitor_tb__DOT__fail__30__message.data()
                             , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                             , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
            }
        }
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             191);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
        while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 193);
        }
        __Vtask_asm_monitor_tb__DOT__send_rx_byte__31__value 
            = (__Vtask_asm_monitor_tb__DOT__send_word_le__24__value 
               >> 0x18U);
        asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
            = __Vtask_asm_monitor_tb__DOT__send_rx_byte__31__value;
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             182);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_data 
            = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
        asm_monitor_tb__DOT__wait_cycles = 0U;
        while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 187);
            asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                                + asm_monitor_tb__DOT__wait_cycles);
            if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
                VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__32__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
                VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                             , '#',512,__Vtask_asm_monitor_tb__DOT__fail__32__message.data()
                             , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                             , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
            }
        }
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             191);
        vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
        while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
            Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                                  "@(posedge asm_monitor_tb.clk)");
            co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge asm_monitor_tb.clk)", 
                                                                 "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                                 193);
        }
        vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n 
            = ((IData)(1U) + vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__33__value = 0x47U;
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__33__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__34__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__34__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_word_le__35__value 
        = vlSelfRef.asm_monitor_tb__DOT__entry_addr;
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__36__value 
        = (0x000000ffU & __Vtask_asm_monitor_tb__DOT__send_word_le__35__value);
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__36__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__37__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__37__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__38__value 
        = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__35__value 
                          >> 8U));
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__38__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__39__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__39__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__40__value 
        = (0x000000ffU & (__Vtask_asm_monitor_tb__DOT__send_word_le__35__value 
                          >> 0x10U));
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__40__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__41__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__41__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    __Vtask_asm_monitor_tb__DOT__send_rx_byte__42__value 
        = (__Vtask_asm_monitor_tb__DOT__send_word_le__35__value 
           >> 0x18U);
    asm_monitor_tb__DOT__send_rx_byte__Vstatic__value 
        = __Vtask_asm_monitor_tb__DOT__send_rx_byte__42__value;
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         182);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_data = asm_monitor_tb__DOT__send_rx_byte__Vstatic__value;
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 1U;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg)))) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             187);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x00007530U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__43__message, Vasm_monitor_tb__ConstPool__CONST_hd46f92ae_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__43__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                          "@(negedge asm_monitor_tb.clk)");
    co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge asm_monitor_tb.clk)", 
                                                         "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                         191);
    vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready = 0U;
    while (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             193);
    }
    while ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
            != vlSelfRef.asm_monitor_tb__DOT__entry_addr)) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec29bb__0(vlSelf, 
                                                              "@(negedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec29bb__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             286);
    }
    vlSelfRef.asm_monitor_tb__DOT__counting = 1U;
    __Vtask_asm_monitor_tb__DOT__wait_tx__44__wanted = 0x00000028U;
    asm_monitor_tb__DOT__wait_tx__Vstatic__wanted = __Vtask_asm_monitor_tb__DOT__wait_tx__44__wanted;
    asm_monitor_tb__DOT__wait_cycles = 0U;
    while (VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__tx_count, asm_monitor_tb__DOT__wait_tx__Vstatic__wanted)) {
        Vasm_monitor_tb___024root____VbeforeTrig_h0bec38fa__0(vlSelf, 
                                                              "@(posedge asm_monitor_tb.clk)");
        co_await vlSelfRef.__VtrigSched_h0bec38fa__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge asm_monitor_tb.clk)", 
                                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                                             212);
        asm_monitor_tb__DOT__wait_cycles = ((IData)(1U) 
                                            + asm_monitor_tb__DOT__wait_cycles);
        if (VL_UNLIKELY((VL_LTS_III(32, 0x0007a120U, asm_monitor_tb__DOT__wait_cycles)))) {
            VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__45__message, Vasm_monitor_tb__ConstPool__CONST_hf291e7a9_0);
            VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                         , '#',512,__Vtask_asm_monitor_tb__DOT__fail__45__message.data()
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                         , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
        }
    }
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__benchmark_done)))))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__46__message, Vasm_monitor_tb__ConstPool__CONST_h7ba9fa37_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__46__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    if (VL_UNLIKELY((((6U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[38U]) 
                      | (7U != vlSelfRef.asm_monitor_tb__DOT__tx_bytes[39U]))))) {
        VL_ASSIGN_W(512, __Vtask_asm_monitor_tb__DOT__fail__47__message, Vasm_monitor_tb__ConstPool__CONST_h3418fe69_0);
        VL_WRITEF_NX("FAIL: %0s pc=%h cycle=%0d\n[%0t] %%Fatal: asm_monitor_tb.v:175: Assertion failed in %m: asm monitor test failed\n",6, 'M',vlSymsp->name(),"asm_monitor_tb.fail", 'T',-9
                     , '#',512,__Vtask_asm_monitor_tb__DOT__fail__47__message.data()
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 175, "", false);
    }
    VL_WRITEF_NX("RESULT entry=%h\nPERF cycles=%0d instr=%0d IPC=%.4f CPI=%.4f\nMEM_WRITES count=%0d logged=%0d\n",7
                 , '#',32,vlSelfRef.asm_monitor_tb__DOT__entry_addr
                 , '#',64,vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles
                 , '#',64,vlSelfRef.asm_monitor_tb__DOT__commit_count
                 , 'D',((0ULL != vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles)
                         ? ((1.0 * VL_ITOR_D_Q(64, vlSelfRef.asm_monitor_tb__DOT__commit_count)) 
                            / VL_ITOR_D_Q(64, vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles))
                         : 0.0), 'D',((0ULL != vlSelfRef.asm_monitor_tb__DOT__commit_count)
                                       ? ((1.0 * VL_ITOR_D_Q(64, vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles)) 
                                          / VL_ITOR_D_Q(64, vlSelfRef.asm_monitor_tb__DOT__commit_count))
                                       : 0.0), '#',64,vlSelfRef.asm_monitor_tb__DOT__write_count
                 , '~',32,vlSelfRef.asm_monitor_tb__DOT__write_log_count);
    vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n = 0U;
    while (VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n, vlSelfRef.asm_monitor_tb__DOT__write_log_count)) {
        VL_WRITEF_NX("WRITE addr=%h data=%h\n",2, '#',32,vlSelfRef.asm_monitor_tb__DOT__write_addr_log
                     [(0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n)]
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__write_data_log
                     [(0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n)]);
        vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n 
            = ((IData)(1U) + vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n);
    }
    if (VL_UNLIKELY((VL_LTS_III(32, 0U, vlSelfRef.asm_monitor_tb__DOT__watch_words)))) {
        VL_WRITEF_NX("MEMORY addr=%h words=%0d\n",2
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__watch_addr
                     , '~',32,vlSelfRef.asm_monitor_tb__DOT__watch_words);
        vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n = 0U;
        while (VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n, vlSelfRef.asm_monitor_tb__DOT__watch_words)) {
            vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr 
                = (vlSelfRef.asm_monitor_tb__DOT__watch_addr 
                   + (vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n 
                      << 2U));
            vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__value 
                = ((0x00400000U & vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr)
                    ? vlSelfRef.asm_monitor_tb__DOT__ext_mem
                   [(0x000fffffU & (vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr 
                                    >> 2U))] : vlSelfRef.asm_monitor_tb__DOT__base_mem
                   [(0x000fffffU & (vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr 
                                    >> 2U))]);
            VL_WRITEF_NX("MEM addr=%h data=%h\n",2, '#',32,vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr
                         , '#',32,vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__value);
            vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n 
                = ((IData)(1U) + vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n);
        }
    }
    VL_WRITEF_NX("PASS asm monitor test\n",0);
    VL_FINISH_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 293, "");
    co_return;
}

VlCoroutine Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__1(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 
                                             111);
        vlSelfRef.asm_monitor_tb__DOT__clk = (1U & 
                                              (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__clk)));
    }
    co_return;
}

bool Vasm_monitor_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vasm_monitor_tb___024root___act_comb__TOP__0(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___act_comb__TOP__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte = 0;
    SData/*15:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__Vfuncout;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__alu_result;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__alu_result = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_byte;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_byte = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_half;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_half = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_22;
    __VdfgRegularize_h6e95ff9d_0_22 = 0;
    // Body
    __VdfgRegularize_h6e95ff9d_0_22 = (vlSelfRef.asm_monitor_tb__DOT__program_addr 
                                       + (vlSelfRef.asm_monitor_tb__DOT__program_words 
                                          << 2U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting) 
            & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg) 
               | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg)))
            ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                ? vlSelfRef.asm_monitor_tb__DOT__base_mem
               [vlSelfRef.asm_monitor_tb__DOT__base_addr]
                : vlSelfRef.asm_monitor_tb__DOT__ext_mem
               [vlSelfRef.asm_monitor_tb__DOT__ext_addr])
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf);
    vlSelfRef.asm_monitor_tb__DOT__program_exit = ((IData)(vlSelfRef.asm_monitor_tb__DOT__counting) 
                                                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s1) 
                                                      & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                                                          >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                                         & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                                                             < __VdfgRegularize_h6e95ff9d_0_22) 
                                                            & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_real_target 
                                                                < vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                                               | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_real_target 
                                                                  >= __VdfgRegularize_h6e95ff9d_0_22))))));
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q) {
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_1;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_1;
    } else {
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0;
    }
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__alu_result 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr;
    if ((2U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__alu_result)) {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
            = (0x000000ffU & ((1U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__alu_result)
                               ? (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result 
                                  >> 0x18U) : (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result 
                                               >> 0x10U)));
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
            = (0x0000ffffU & (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result 
                              >> 0x10U));
    } else {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
            = (0x000000ffU & ((1U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__alu_result)
                               ? (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result 
                                  >> 8U) : __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result));
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
            = (0x0000ffffU & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result);
    }
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__Vfuncout 
        = ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_byte)
            ? ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext)
                ? (((- (IData)((1U & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte) 
                                      >> 7U)))) << 8U) 
                   | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
                : (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
            : ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_half)
                ? ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext)
                    ? (((- (IData)((1U & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half) 
                                          >> 0x0fU)))) 
                        << 0x00000010U) | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                    : (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                : __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__mem_result));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp 
        = __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__Vfuncout;
}

extern const VlUnpacked<CData/*1:0*/, 256> Vasm_monitor_tb__ConstPool__TABLE_ha0d935b3_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vasm_monitor_tb__ConstPool__TABLE_heb844438_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vasm_monitor_tb__ConstPool__TABLE_hec3c125f_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0;
extern const VlUnpacked<CData/*2:0*/, 2048> Vasm_monitor_tb__ConstPool__TABLE_he47f3c48_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h547ba932_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h2c364be9_0;
extern const VlWide<10>/*319:0*/ Vasm_monitor_tb__ConstPool__CONST_h98e43d88_0;
extern const VlUnpacked<IData/*31:0*/, 5> Vasm_monitor_tb__ConstPool__TABLE_heee294f4_0;

void Vasm_monitor_tb___024root___nba_sequent__TOP__0(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___nba_sequent__TOP__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ asm_monitor_tb__DOT__data_fast_ready;
    asm_monitor_tb__DOT__data_fast_ready = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_load_fifo1_g0;
    asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_load_fifo1_g0 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms0;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms0 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms0;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms0 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0;
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0 = 0;
    CData/*7:0*/ asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte;
    asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte = 0;
    SData/*15:0*/ asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half;
    asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_load_result_0;
    asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_load_result_0 = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire = 0;
    CData/*7:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte = 0;
    SData/*15:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half = 0;
    IData/*31:0*/ asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_load_result_0_fwd;
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_load_result_0_fwd = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint;
    asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint = 0;
    CData/*1:0*/ asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row;
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1;
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1 = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken;
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken;
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane;
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__bridge__DOT__base_data_req;
    asm_monitor_tb__DOT__bridge__DOT__base_data_req = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__bridge__DOT__base_store_ready;
    asm_monitor_tb__DOT__bridge__DOT__base_store_ready = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__bridge__DOT__base_data_read;
    asm_monitor_tb__DOT__bridge__DOT__base_data_read = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__bridge__DOT__base_read_active;
    asm_monitor_tb__DOT__bridge__DOT__base_read_active = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__bridge__DOT__ext_data_req;
    asm_monitor_tb__DOT__bridge__DOT__ext_data_req = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__bridge__DOT__ext_store_ready;
    asm_monitor_tb__DOT__bridge__DOT__ext_store_ready = 0;
    CData/*0:0*/ asm_monitor_tb__DOT__bridge__DOT__ext_read_active;
    asm_monitor_tb__DOT__bridge__DOT__ext_read_active = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__Vfuncout;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__alu_result;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__alu_result = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_byte;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_byte = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_half;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_half = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_sign_ext;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_sign_ext = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__Vfuncout;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__alu_result;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__alu_result = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_byte;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_byte = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_half;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_half = 0;
    CData/*0:0*/ __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_sign_ext;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_sign_ext = 0;
    IData/*31:0*/ __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__Vfuncout;
    __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_value;
    __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_value = 0;
    CData/*1:0*/ __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_offset;
    __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_offset = 0;
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    __VdfgRegularize_h6e95ff9d_0_6 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_25;
    __VdfgRegularize_h6e95ff9d_0_25 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_26;
    __VdfgRegularize_h6e95ff9d_0_26 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_28;
    __VdfgRegularize_h6e95ff9d_0_28 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_29;
    __VdfgRegularize_h6e95ff9d_0_29 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_30;
    __VdfgRegularize_h6e95ff9d_0_30 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_31;
    __VdfgRegularize_h6e95ff9d_0_31 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_36;
    __VdfgRegularize_h6e95ff9d_0_36 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_37;
    __VdfgRegularize_h6e95ff9d_0_37 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_38;
    __VdfgRegularize_h6e95ff9d_0_38 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_39;
    __VdfgRegularize_h6e95ff9d_0_39 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_40;
    __VdfgRegularize_h6e95ff9d_0_40 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_41;
    __VdfgRegularize_h6e95ff9d_0_41 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_42;
    __VdfgRegularize_h6e95ff9d_0_42 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_43;
    __VdfgRegularize_h6e95ff9d_0_43 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_44;
    __VdfgRegularize_h6e95ff9d_0_44 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_45;
    __VdfgRegularize_h6e95ff9d_0_45 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_46;
    __VdfgRegularize_h6e95ff9d_0_46 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_47;
    __VdfgRegularize_h6e95ff9d_0_47 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_48;
    __VdfgRegularize_h6e95ff9d_0_48 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_49;
    __VdfgRegularize_h6e95ff9d_0_49 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_50;
    __VdfgRegularize_h6e95ff9d_0_50 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_51;
    __VdfgRegularize_h6e95ff9d_0_51 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_52;
    __VdfgRegularize_h6e95ff9d_0_52 = 0;
    QData/*63:0*/ __Vdly__asm_monitor_tb__DOT__benchmark_cycles;
    __Vdly__asm_monitor_tb__DOT__benchmark_cycles = 0;
    QData/*63:0*/ __VdlyMask__asm_monitor_tb__DOT__benchmark_cycles;
    __VdlyMask__asm_monitor_tb__DOT__benchmark_cycles = 0;
    QData/*63:0*/ __Vdly__asm_monitor_tb__DOT__commit_count;
    __Vdly__asm_monitor_tb__DOT__commit_count = 0;
    QData/*63:0*/ __VdlyMask__asm_monitor_tb__DOT__commit_count;
    __VdlyMask__asm_monitor_tb__DOT__commit_count = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__counting;
    __Vdly__asm_monitor_tb__DOT__counting = 0;
    CData/*0:0*/ __VdlyMask__asm_monitor_tb__DOT__counting;
    __VdlyMask__asm_monitor_tb__DOT__counting = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__benchmark_done;
    __Vdly__asm_monitor_tb__DOT__benchmark_done = 0;
    CData/*0:0*/ __VdlyMask__asm_monitor_tb__DOT__benchmark_done;
    __VdlyMask__asm_monitor_tb__DOT__benchmark_done = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__exit_seen;
    __Vdly__asm_monitor_tb__DOT__exit_seen = 0;
    CData/*0:0*/ __VdlyMask__asm_monitor_tb__DOT__exit_seen;
    __VdlyMask__asm_monitor_tb__DOT__exit_seen = 0;
    IData/*31:0*/ __Vdly__asm_monitor_tb__DOT__exit_pc;
    __Vdly__asm_monitor_tb__DOT__exit_pc = 0;
    IData/*31:0*/ __VdlyMask__asm_monitor_tb__DOT__exit_pc;
    __VdlyMask__asm_monitor_tb__DOT__exit_pc = 0;
    QData/*63:0*/ __Vdly__asm_monitor_tb__DOT__write_count;
    __Vdly__asm_monitor_tb__DOT__write_count = 0;
    QData/*63:0*/ __VdlyMask__asm_monitor_tb__DOT__write_count;
    __VdlyMask__asm_monitor_tb__DOT__write_count = 0;
    IData/*31:0*/ __Vdly__asm_monitor_tb__DOT__write_log_count;
    __Vdly__asm_monitor_tb__DOT__write_log_count = 0;
    IData/*31:0*/ __VdlyMask__asm_monitor_tb__DOT__write_log_count;
    __VdlyMask__asm_monitor_tb__DOT__write_log_count = 0;
    QData/*63:0*/ __Vdly__asm_monitor_tb__DOT__cycle_count;
    __Vdly__asm_monitor_tb__DOT__cycle_count = 0;
    CData/*1:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head = 0;
    CData/*1:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0 = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid = 0;
    CData/*1:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = 0;
    CData/*1:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat = 0;
    CData/*2:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 = 0;
    CData/*0:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending = 0;
    CData/*2:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = 0;
    IData/*31:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr = 0;
    CData/*2:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state = 0;
    CData/*7:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr = 0;
    CData/*1:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat = 0;
    IData/*31:0*/ __Vdly__asm_monitor_tb__DOT__cpu__DOT__pc_out;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__pc_out = 0;
    CData/*1:0*/ __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state;
    __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state = 0;
    CData/*1:0*/ __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state;
    __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__ext_mem__v0;
    __VdlyVal__asm_monitor_tb__DOT__ext_mem__v0 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v0;
    __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__ext_mem__v0;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__ext_mem__v1;
    __VdlyVal__asm_monitor_tb__DOT__ext_mem__v1 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v1;
    __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v1 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__ext_mem__v1;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__ext_mem__v2;
    __VdlyVal__asm_monitor_tb__DOT__ext_mem__v2 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v2;
    __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v2 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__ext_mem__v2;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__ext_mem__v3;
    __VdlyVal__asm_monitor_tb__DOT__ext_mem__v3 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v3;
    __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v3 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__ext_mem__v3;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__base_mem__v0;
    __VdlyVal__asm_monitor_tb__DOT__base_mem__v0 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__base_mem__v0;
    __VdlyDim0__asm_monitor_tb__DOT__base_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__base_mem__v0;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__base_mem__v1;
    __VdlyVal__asm_monitor_tb__DOT__base_mem__v1 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__base_mem__v1;
    __VdlyDim0__asm_monitor_tb__DOT__base_mem__v1 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__base_mem__v1;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__base_mem__v2;
    __VdlyVal__asm_monitor_tb__DOT__base_mem__v2 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__base_mem__v2;
    __VdlyDim0__asm_monitor_tb__DOT__base_mem__v2 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__base_mem__v2;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__asm_monitor_tb__DOT__base_mem__v3;
    __VdlyVal__asm_monitor_tb__DOT__base_mem__v3 = 0;
    IData/*19:0*/ __VdlyDim0__asm_monitor_tb__DOT__base_mem__v3;
    __VdlyDim0__asm_monitor_tb__DOT__base_mem__v3 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__base_mem__v3;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v3 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v0;
    __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v0 = 0;
    CData/*7:0*/ __VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v0;
    __VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__write_addr_log__v0;
    __VdlySet__asm_monitor_tb__DOT__write_addr_log__v0 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__write_data_log__v0;
    __VdlyVal__asm_monitor_tb__DOT__write_data_log__v0 = 0;
    CData/*7:0*/ __VdlyDim0__asm_monitor_tb__DOT__write_data_log__v0;
    __VdlyDim0__asm_monitor_tb__DOT__write_data_log__v0 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v1;
    __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v1 = 0;
    CData/*7:0*/ __VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v1;
    __VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v1 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__write_addr_log__v1;
    __VdlySet__asm_monitor_tb__DOT__write_addr_log__v1 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__write_data_log__v1;
    __VdlyVal__asm_monitor_tb__DOT__write_data_log__v1 = 0;
    CData/*7:0*/ __VdlyDim0__asm_monitor_tb__DOT__write_data_log__v1;
    __VdlyDim0__asm_monitor_tb__DOT__write_data_log__v1 = 0;
    VlWide<9>/*265:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0;
    VL_ZERO_W(266, __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0);
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0 = 0;
    VlWide<9>/*265:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1;
    VL_ZERO_W(266, __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1);
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0 = 0;
    CData/*4:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1 = 0;
    CData/*4:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1 = 0;
    IData/*24:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0 = 0;
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0 = 0;
    IData/*24:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0 = 0;
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0;
    VL_ZERO_W(128, __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0);
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0;
    VL_ZERO_W(128, __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0);
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0 = 0;
    CData/*0:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 = 0;
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 = 0;
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1 = 0;
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2 = 0;
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3 = 0;
    CData/*2:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v5;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v5 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v0 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v0 = 0;
    IData/*17:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 = 0;
    IData/*17:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v0 = 0;
    CData/*1:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v0 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 = 0;
    IData/*31:0*/ __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9;
    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 = 0;
    CData/*1:0*/ __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9;
    __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 = 0;
    CData/*0:0*/ __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9;
    __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 = 0;
    CData/*0:0*/ __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 = 0;
    IData/*31:0*/ __Vtemp_1;
    // Body
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v1 = 0U;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v2 = 0U;
    __VdlySet__asm_monitor_tb__DOT__ext_mem__v3 = 0U;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v1 = 0U;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v2 = 0U;
    __VdlySet__asm_monitor_tb__DOT__base_mem__v3 = 0U;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending;
    __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state 
        = vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state;
    __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state 
        = vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 = 0U;
    __VdlySet__asm_monitor_tb__DOT__write_addr_log__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__write_addr_log__v1 = 0U;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0 = 0U;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0 = 0U;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4 = 0U;
    __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v5 = 0U;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state;
    __Vdly__asm_monitor_tb__DOT__cpu__DOT__pc_out = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out;
    __Vdly__asm_monitor_tb__DOT__cycle_count = (1ULL 
                                                + vlSelfRef.asm_monitor_tb__DOT__cycle_count);
    if (vlSelfRef.asm_monitor_tb__DOT__resetn) {
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0))) 
                          & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__load_wakeup_valid)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: EXE_stage.v:587: Assertion failed in %m: EX captured load wakeup data without a valid response\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_exe", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/EXE_stage.v", 587, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0)) 
                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: EXE_stage.v:589: Assertion failed in %m: unfinished lane0 multiply became forwardable\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_exe", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/EXE_stage.v", 589, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_53)) 
                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: EXE_stage.v:591: Assertion failed in %m: lane0 special result entered EX forwarding\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_exe", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/EXE_stage.v", 591, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                      >> 2U))) & (~ 
                                                  ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                                                   & (IData)(
                                                             (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                              >> 2U)))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: EXE_stage.v:594: Assertion failed in %m: lane1 multiply launched without lane0 multiply\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_exe", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/EXE_stage.v", 594, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1) 
                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1)) 
                          & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: EXE_stage.v:596: Assertion failed in %m: lane1 multiply lost packet pairing in EX\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_exe", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/EXE_stage.v", 596, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1) 
                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1)) 
                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: EXE_stage.v:598: Assertion failed in %m: lane1 load became forwardable in EX\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_exe", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/EXE_stage.v", 598, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                          & ((7U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1)) 
                             | (8U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: EXE_stage.v:601: Assertion failed in %m: complex branch entered lane1 EX\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_exe", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/EXE_stage.v", 601, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                           & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0))) 
                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: MEM_stage.v:837: Assertion failed in %m: lane0 special result entered MEM forwarding\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_mem", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/MEM_stage.v", 837, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0)) 
                          & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: MEM_stage.v:839: Assertion failed in %m: lane0 load forwarded an unregistered SRAM response\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_mem", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/MEM_stage.v", 839, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__data_req) 
                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q)) 
                          & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: MEM_stage.v:841: Assertion failed in %m: store request issued before its data became ready\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_mem", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/MEM_stage.v", 841, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0) 
                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: MEM_stage.v:845: Assertion failed in %m: lane1 retired before lane0 in a dual memory packet\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_mem", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/MEM_stage.v", 845, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__data_req) 
                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: MEM_stage.v:847: Assertion failed in %m: memory request overlapped an outstanding transaction\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_mem", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/MEM_stage.v", 847, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                          & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                              != (0x0000001fU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                         >> 0x00000012U)))) 
                             | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0) 
                                != (0x0000001fU & (IData)(
                                                          (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                           >> 0x0000000dU))))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:743: Assertion failed in %m: lane0 IBuffer hot fields lost synchronization\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 743, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
                          & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1) 
                              != (0x0000001fU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                         >> 0x00000012U)))) 
                             | ((0x0000001fU & (IData)(
                                                       (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                        >> 0x0000000dU))) 
                                != (0x0000001fU & (IData)(
                                                          (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                           >> 0x0000000dU))))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:747: Assertion failed in %m: lane1 IBuffer hot fields lost synchronization\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 747, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume) 
                           != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex)) 
                          | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume) 
                             != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:750: Assertion failed in %m: IBuffer consume and EX issue controls diverged\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 750, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume) 
                          != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:752: Assertion failed in %m: lane1 consume destination mirror diverged\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 752, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                          != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:754: Assertion failed in %m: lane0 consume destination mirror diverged\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 754, "", false);
        }
        if (VL_UNLIKELY((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                            != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0)) 
                           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                              != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0))) 
                          | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume) 
                             != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:758: Assertion failed in %m: lane0 consume control mirrors diverged\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 758, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) 
                           & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush))) 
                          & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
                              != ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0) 
                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0)) 
                                   & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0))) 
                                  & (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0)))) 
                             | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0) 
                                   != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0)))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:764: Assertion failed in %m: ISSUE local EX wait mirror lost synchronization local=%b/%0d es=%b/%b/%b/%0d\n",9, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',1,(IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0)
                         , '#',5,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0
                         , '#',1,(IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0)
                         , '#',1,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0
                         , '#',1,(IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0)
                         , '#',5,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0);
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 764, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                          & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__lane1_capable)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:769: Assertion failed in %m: unsupported instruction issued on lane1\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 769, "", false);
        }
        if (VL_UNLIKELY((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1) 
                             | (0ULL != (0x0000000180000000ULL 
                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:772: Assertion failed in %m: lane1 issued a forbidden side-effect class\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 772, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                      >> 2U))) & (~ (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                             >> 2U))))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:774: Assertion failed in %m: lane1 multiply issued without lane0 multiply\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 774, "", false);
        }
        if (VL_UNLIKELY((((((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume) 
                                & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume)) 
                                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume)))) 
                            & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1))) 
                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume)) 
                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:777: Assertion failed in %m: unfinished MEM producer allowed dependent lane0\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 777, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume) 
                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume)) 
                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:780: Assertion failed in %m: unfinished MEM producer allowed dependent lane1\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 780, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0)) 
                          & ((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__load_wakeup_valid)) 
                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1)) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0)) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms1)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:784: Assertion failed in %m: lane0 rj selected an invalid/older load wakeup\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 784, "", false);
        }
        if (VL_UNLIKELY(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)) 
                          & ((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__load_wakeup_valid)) 
                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1)) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0)) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms1)))))) {
            VL_WRITEF_NX("[%0t] %%Fatal: ISSUE_stage.v:788: Assertion failed in %m: lane0 rkd selected an invalid/older load wakeup\n",3, 'M',vlSymsp->name(),"asm_monitor_tb.cpu.u_issue", 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000));
            VL_STOP_MT("/Users/qianfu/Mycpu/myCPU/ISSUE_stage.v", 788, "", false);
        }
    }
    if (VL_UNLIKELY(((vlSelfRef.asm_monitor_tb__DOT__cycle_count 
                      > vlSelfRef.asm_monitor_tb__DOT__max_cycles)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: asm_monitor_tb.v:168: Assertion failed in %m: asm monitor timeout pc=%h cycles=%0d\n",5, 'M',vlSymsp->name(),"asm_monitor_tb", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000)
                     , '#',32,vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out
                     , '#',64,vlSelfRef.asm_monitor_tb__DOT__cycle_count);
        VL_STOP_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 168, "", false);
    }
    if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_start_reg) {
        vlSelfRef.asm_monitor_tb__DOT__tx_bytes[(0x000007ffU 
                                                 & vlSelfRef.asm_monitor_tb__DOT__tx_count)] 
            = vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_data_reg;
        vlSelfRef.asm_monitor_tb__DOT__tx_count = ((IData)(1U) 
                                                   + vlSelfRef.asm_monitor_tb__DOT__tx_count);
    }
    if ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset) 
          | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q)) 
         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid = 0U;
    } else {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__got_addr_ok) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending = 1U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting 
                = (1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q)) 
                         | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                            >> 0x00000018U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting 
                = (1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q)) 
                         | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                            >> 0x00000018U)));
        } else if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_data_ok))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting = 0U;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind 
                = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0))
                    ? 2U : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0)))
                             ? 1U : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_eff_valid) 
                                      & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1) 
                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1)))
                                      ? 1U : 0U)));
        } else if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__icacop_req_valid) 
                    & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent = 1U;
        }
        if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) 
             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid = 0U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_ok) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid = 1U;
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__reset) {
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v0 = 1U;
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v0 = 1U;
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v0 = 1U;
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v0 = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_valid_s2 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_tag_s2 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target_s2 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_target_s2 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2 = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2 = 0U;
    } else {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s2) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_hit_s2) {
                if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2) {
                    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target_s2;
                    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 
                        = (3U & (((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2)) 
                                 | (- (IData)((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2))))));
                } else {
                    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_target_s2;
                    __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 
                        = (3U & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2) 
                                  - (IData)(1U)) & 
                                 (- (IData)((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2))))));
                }
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8 = 1U;
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8 = 1U;
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8 = 1U;
                __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2;
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8 = 1U;
            } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2) {
                __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target_s2;
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9 = 1U;
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9 = 1U;
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9 = 1U;
                __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2;
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2;
                __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2;
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9 = 1U;
            }
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s1) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_valid_s2 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid
                [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                        >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1];
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_tag_s2 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem
                [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                        >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1];
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target_s2 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_real_target;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_target_s2 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target
                [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                        >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1];
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter
                [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                        >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1];
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2 
                = (1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                         >> 2U));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2 
                = (0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                                  >> 5U));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__bpu_sel_lane1)
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1)
                    : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0));
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__counting) {
        __Vdly__asm_monitor_tb__DOT__benchmark_cycles 
            = (1ULL + vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles);
        __VdlyMask__asm_monitor_tb__DOT__benchmark_cycles = 0xffffffffffffffffULL;
        __Vdly__asm_monitor_tb__DOT__commit_count = 
            ((vlSelfRef.asm_monitor_tb__DOT__commit_count 
              + (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0))) 
             + (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1)));
        __VdlyMask__asm_monitor_tb__DOT__commit_count = 0xffffffffffffffffULL;
        if ((((IData)(vlSelfRef.asm_monitor_tb__DOT__program_exit) 
              & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0) 
                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                     == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc)) 
                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1) 
                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                       == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc)))) 
             | ((IData)(vlSelfRef.asm_monitor_tb__DOT__exit_seen) 
                & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0) 
                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                       == vlSelfRef.asm_monitor_tb__DOT__exit_pc)) 
                   | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1) 
                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                         == vlSelfRef.asm_monitor_tb__DOT__exit_pc)))))) {
            __Vdly__asm_monitor_tb__DOT__counting = 0U;
            __VdlyMask__asm_monitor_tb__DOT__counting = 1U;
            __Vdly__asm_monitor_tb__DOT__benchmark_done = 1U;
            __VdlyMask__asm_monitor_tb__DOT__benchmark_done = 1U;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__program_exit) {
            __Vdly__asm_monitor_tb__DOT__exit_seen = 1U;
            __VdlyMask__asm_monitor_tb__DOT__exit_seen = 1U;
            __Vdly__asm_monitor_tb__DOT__exit_pc = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc;
            __VdlyMask__asm_monitor_tb__DOT__exit_pc = 0xffffffffU;
        }
    }
    __Vtableidx3 = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_cnt_0) 
                      << 6U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0) 
                                 << 5U) | (0x00000010U 
                                           & ((IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                       >> 2U)) 
                                              << 4U)))) 
                    | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                         << 3U) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) 
                                   << 2U)) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset))));
    if ((1U & Vasm_monitor_tb__ConstPool__TABLE_ha0d935b3_0
         [__Vtableidx3])) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_cnt_0 
            = Vasm_monitor_tb__ConstPool__TABLE_heb844438_0
            [__Vtableidx3];
    }
    if ((2U & Vasm_monitor_tb__ConstPool__TABLE_ha0d935b3_0
         [__Vtableidx3])) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0 
            = Vasm_monitor_tb__ConstPool__TABLE_hec3c125f_0
            [__Vtableidx3];
    }
    if ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))) {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way)))) {
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0 
                = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                   >> 7U);
            __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0 
                = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                         >> 4U));
            __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0 = 1U;
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[0U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[0U];
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[1U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[1U];
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[2U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[2U];
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[3U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[3U];
            __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0 
                = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                         >> 4U));
            __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0 = 1U;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way) {
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0 
                = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                   >> 7U);
            __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0 
                = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                         >> 4U));
            __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0 = 1U;
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[0U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[0U];
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[1U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[1U];
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[2U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[2U];
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[3U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[3U];
            __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0 
                = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                         >> 4U));
            __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0 = 1U;
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0) {
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[0U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_59[0U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[1U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_59[1U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[2U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_59[2U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[3U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_59[3U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[4U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_59[4U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[5U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_59[5U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[6U] 
            = ((0xc0000000U & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[6U]) 
               | (0x3fffffffU & ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si26)
                                  ? ((0x3c000000U & 
                                      ((- (IData)((1U 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                      >> 9U)))) 
                                       << 0x0000001aU)) 
                                     | ((0x03ff0000U 
                                         & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                            << 0x00000010U)) 
                                        | (0x0000ffffU 
                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                              >> 0x0000000aU))))
                                  : vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_59[5U])));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[6U] 
            = ((0x3fffffffU & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[6U]) 
               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)
                    ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)
                             ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               << 7U))
                             : ((((- (IData)((1U & 
                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x00000015U)))) 
                                  & (- (IData)((1U 
                                                & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12)))))) 
                                 << 0x0000000cU) | 
                                (0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x0000000aU))))) 
                  << 0x0000001eU));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[7U] 
            = ((0xc0000000U & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[7U]) 
               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)
                    ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)
                             ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               << 7U))
                             : ((((- (IData)((1U & 
                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x00000015U)))) 
                                  & (- (IData)((1U 
                                                & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12)))))) 
                                 << 0x0000000cU) | 
                                (0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x0000000aU))))) 
                  >> 2U));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[7U] 
            = ((0x3fffffffU & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[7U]) 
               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sub_w) 
                   << 0x0000001fU) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_add_w) 
                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_addi_w) 
                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w) 
                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_w) 
                                                | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src1_is_pc) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_56)))))) 
                                      << 0x0000001eU)));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[8U] 
            = (0x000003ffU & ((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w) 
                                  << 4U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w) 
                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w)) 
                                             << 3U) 
                                            | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w)) 
                                               << 2U))) 
                                | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w) 
                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w)) 
                                    << 1U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xor) 
                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xori)))) 
                               << 5U) | (((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_or) 
                                            | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ori)) 
                                           << 4U) | 
                                          (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_nor) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_and) 
                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_andi)) 
                                              << 2U))) 
                                         | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltu) 
                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltui)) 
                                             << 1U) 
                                            | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slt) 
                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slti))))));
        __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail;
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0 = 1U;
    }
    if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0) 
         & (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0)))) {
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0;
        __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0;
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0 = 1U;
    }
    if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1) 
         & (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)))) {
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1;
        __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1;
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1 = 1U;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_pc__DOT__reset) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__pc_out = 0x1c000000U;
    } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__pc_out 
            = ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target
                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__cacop_flush)
                    ? ((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0)
                    : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q 
                       & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q))))));
    } else if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__if_suspend)))) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__pc_out 
            = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_pred_taken)
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_target_0
                : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                   + ((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                    >> 2U))) ? 4U : 8U)));
    }
    vlSelfRef.asm_monitor_tb__DOT__cycle_count = __Vdly__asm_monitor_tb__DOT__cycle_count;
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_resp_valid 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__resetn) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_resp_valid 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__resetn) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_1 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset))) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1));
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1) {
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[0U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_64[0U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[1U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_64[1U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[2U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_64[2U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[3U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_64[3U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[4U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_64[4U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[5U] 
            = vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_64[5U];
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[6U] 
            = ((0xc0000000U & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[6U]) 
               | (0x3fffffffU & ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si26)
                                  ? ((0x3c000000U & 
                                      ((- (IData)((1U 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                      >> 9U)))) 
                                       << 0x0000001aU)) 
                                     | ((0x03ff0000U 
                                         & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                            << 0x00000010U)) 
                                        | (0x0000ffffU 
                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                              >> 0x0000000aU))))
                                  : vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_64[5U])));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[6U] 
            = ((0x3fffffffU & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[6U]) 
               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)
                    ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)
                             ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               << 7U))
                             : ((((- (IData)((1U & 
                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x00000015U)))) 
                                  & (- (IData)((1U 
                                                & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12)))))) 
                                 << 0x0000000cU) | 
                                (0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x0000000aU))))) 
                  << 0x0000001eU));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[7U] 
            = ((0xc0000000U & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[7U]) 
               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)
                    ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)
                             ? (0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               << 7U))
                             : ((((- (IData)((1U & 
                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x00000015U)))) 
                                  & (- (IData)((1U 
                                                & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12)))))) 
                                 << 0x0000000cU) | 
                                (0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x0000000aU))))) 
                  >> 2U));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[7U] 
            = ((0x3fffffffU & __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[7U]) 
               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sub_w) 
                   << 0x0000001fU) | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_add_w) 
                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_addi_w) 
                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w) 
                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_w) 
                                                | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src1_is_pc) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_61)))))) 
                                      << 0x0000001eU)));
        __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[8U] 
            = (0x000003ffU & ((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w) 
                                  << 4U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w) 
                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w)) 
                                             << 3U) 
                                            | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w)) 
                                               << 2U))) 
                                | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w) 
                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w)) 
                                    << 1U) | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xor) 
                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xori)))) 
                               << 5U) | (((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_or) 
                                            | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ori)) 
                                           << 4U) | 
                                          (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_nor) 
                                            << 3U) 
                                           | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_and) 
                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_andi)) 
                                              << 2U))) 
                                         | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltu) 
                                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltui)) 
                                             << 1U) 
                                            | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slt) 
                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slti))))));
        __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail)));
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1 = 1U;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_0 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset))) 
           && ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0) 
               && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0)));
    if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset) 
         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush))) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_1 = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid = 0U;
    } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid = 0U;
    } else if (((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid)) 
                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0)) 
                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0)) 
                & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0)))) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_1 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid = 1U;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_res_from_mem_0 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset))) 
           && ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0) 
               && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_1 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset))) 
           && ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1) 
               && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1)));
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_mem_result_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_half_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_byte_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_sign_ext_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1 = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target = 0U;
    } else {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_mem_result_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_half_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_byte_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_sign_ext_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1;
        }
        if ((4U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state = 0U;
        } else if ((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state 
                = ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))
                    ? 0U : 3U);
        } else if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state = 2U;
        } else if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_is_csr_0))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_num_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wmask_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wvalue_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target 
                = ((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_pc_0);
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state = 1U;
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0 = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0 = 0U;
    } else {
        if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 = 0U;
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0 = 1U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0 = 0U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_eff_valid;
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                   && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q 
                = (1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0 
                            >> 0x00000018U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q 
                = (1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1 
                            >> 0x00000018U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) 
                   && (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0 
                = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0))) 
                   || (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response) 
                             | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms) 
                                | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1) 
                                   | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0)))))));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) 
                   && ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                       & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1) 
                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1) 
                              & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1 
                                 != vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1))) 
                          | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1) 
                             ^ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1)))));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q 
                = (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw)
                          ? (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0 
                             >> 0x16U) : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw) 
                                          & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1 
                                             >> 0x16U))));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q 
                = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw)) 
                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0)
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0)
                    : 0U);
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                   && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                   && (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)));
        } else {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1) {
                __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1;
                __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q 
                    = (1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1 
                             >> 0x16U));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q = 1U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0 = 0U;
            }
            if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1)))) {
                if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1) 
                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws0))) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0 = 1U;
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
                if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1;
                }
                if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0 
                        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response)
                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                            : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0
                                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1)
                                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                    : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0)
                                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1)))) {
                if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1) 
                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws0))) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0 
                        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1)
                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0);
                }
            }
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wvalue_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_pc_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wmask_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_num_0 = 0U;
    } else {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)
                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                    : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1);
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wvalue_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_pc_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wmask_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_num_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0;
        }
    }
    if ((1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)) 
               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_res_from_mem_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume = 0U;
    } else {
        if (((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
             & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned = 0U;
        }
        if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2) 
             & (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned = 1U;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_res_from_mem_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                              >> 5U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                              >> 4U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__capture_ex_wait_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0 
                = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                          >> 8U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume 
                = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                          >> 8U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                              >> 4U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                              >> 4U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__capture_ex_wait_0)
                    ? (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                              >> 8U)))
                    : 0U);
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1 
                = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                          >> 8U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume 
                = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                          >> 8U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume 
                = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                    & (0x0000000000000010ULL == (0x0000000000000030ULL 
                                                 & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3))) 
                   & (0ULL == (0x0000000030400000ULL 
                               & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2)));
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_0 
                = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0)) 
                   & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1 
                = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1)) 
                   & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1)));
            if ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0)) 
                 & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0)))) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0;
            } else {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume = 0U;
            }
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1 
                = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) 
                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1)) 
                    & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1)))
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1)
                    : 0U);
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__resetn) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr 
            = ((0x000000feU & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr) 
                               << 1U)) | (1U & VL_REDXOR_8(
                                                           (0xb8U 
                                                            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr)))));
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail = 0U;
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt = 0U;
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state = 0U;
        } else {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail 
                = (3U & ((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count))
                          ? ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail))
                          : ((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count))
                              ? ((IData)(2U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail))
                              : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail))));
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head 
                = (3U & ((1U == Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0
                          [(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                             << 6U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
                                        << 5U) | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_23)))])
                          ? ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head))
                          : ((2U == Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0
                              [(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                                 << 6U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
                                            << 5U) 
                                           | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_23)))])
                              ? ((IData)(2U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head))
                              : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head))));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt 
                = (7U & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt) 
                          + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count)) 
                         - Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0
                         [(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                            << 6U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
                                       << 5U) | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_23)))]));
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state 
                = Vasm_monitor_tb__ConstPool__TABLE_he47f3c48_0
                [(((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
                       & ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
                          & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2)))) 
                      << 5U) | ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                                << 4U)) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r) 
                                            << 2U) 
                                           | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)))) 
                   << 5U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold) 
                              << 4U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2) 
                                         << 3U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))))];
        }
        if ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))) {
            __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 
                = (1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)));
            __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 
                = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                         >> 4U));
            __VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way;
            __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0 = 1U;
        }
        if ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way0) {
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1 
                    = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                             >> 4U));
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1 = 1U;
            }
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way1) {
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2 
                    = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                             >> 4U));
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2 = 1U;
            }
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__store_inv_valid) {
            if ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                 [(7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line)] 
                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                    [(7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line)] 
                    == (0x01ffffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                                       >> 3U))))) {
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3 
                    = (7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line);
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3 = 1U;
            }
            if ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U]
                 [(7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line)] 
                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1
                    [(7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line)] 
                    == (0x01ffffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                                       >> 3U))))) {
                __VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4 
                    = (7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line);
                __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4 = 1U;
            }
        }
    } else {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr = 0xffU;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state = 0U;
        __VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v5 = 1U;
    }
    if ((1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)) 
               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way1 = 0U;
    } else if ((4U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))) {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = 0U;
    } else if ((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))) {
        if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = 4U;
        } else {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_direct) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way0 
                    = (1U & (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way1 
                    = (1U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr);
            } else {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way0 
                    = (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit_way0)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way1 
                    = (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit_way1)));
            }
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))) {
        if (((1U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
             & (2U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = 2U;
        }
    } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__icacop_req_valid) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_cacop_code_0;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
            = ((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                   >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                    >> 3U)) == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                                >> 0x0000001dU)))
                  ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg)
                  : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                       >> 0x0000000dU) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                                 >> 0x0000000aU)) 
                                          == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                              >> 0x0000001dU)))
                      ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                         >> 7U) : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                   >> 0x0000001dU))) 
                << 0x0000001dU) | (0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0));
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = 1U;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0 
                    = (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0);
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                     >> 0x00000020U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_1 
                    = (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                               >> 0x0000000aU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                    = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0)
                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0);
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1 
                    = (0x00000fffU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                              >> 0x0000001dU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0 
                    = (0x00000fffU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 
                                              >> 0x0000001dU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0 
                    = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)
                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                        : ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                          >> 6U))) ? 
                           (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5) 
                             << 3U) | (7U & (IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4 
                                                     >> 0x0000002aU))))
                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd_value_0));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1 
                    = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                      >> 6U))) ? ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[7U] 
                                                   << 2U) 
                                                  | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[6U] 
                                                     >> 0x0000001eU))
                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1);
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_0 
                    = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                      >> 0x00000020U)))
                        ? (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4) 
                            << 0x00000016U) | (0x003fffffU 
                                               & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                          >> 0x00000017U))))
                        : (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4 
                                   >> 0x0000000aU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                    = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                      >> 7U))) ? ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[3U] 
                                                   << 0x0000001fU) 
                                                  | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[2U] 
                                                     >> 1U))
                        : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))
                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1
                            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0))
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src1_1)));
            }
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0 = 0U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                              >> 0x0000001dU)));
        }
    }
    if ((1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)) 
               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0 = 0U;
    } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1 
            = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
               & (0x0000000000000010ULL == (0x0000000000000030ULL 
                                            & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3)));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0 
            = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                & (0x0000000000000010ULL == (0x0000000000000030ULL 
                                             & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3))) 
               & (0ULL == (0x0000000030400000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2)));
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_cacop_code_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1 = 0U;
    } else {
        if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1 = 0U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw)
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0)
                    : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw) 
                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                   && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                   && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) 
                   && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1));
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0 = 0U;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw)
                    ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0)
                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0
                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0)
                    : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1)
                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1
                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1));
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0 
                    = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                       && (1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_53))));
                if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1 
                        = ((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1);
                }
                if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_cacop_code_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_cacop_code_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0;
                }
            } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0 = 0U;
            }
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_ok) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf 
            = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                ? vlSelfRef.asm_monitor_tb__DOT__base_mem
               [vlSelfRef.asm_monitor_tb__DOT__base_addr]
                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok)
                    ? vlSelfRef.asm_monitor_tb__DOT__ext_mem
                   [vlSelfRef.asm_monitor_tb__DOT__ext_addr]
                    : (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg 
                       & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid))))));
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1 
                = ((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr);
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                = ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U]
                    : ((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U]
                        : ((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U]
                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U])));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                = ((0U == (3U & ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U]
                    : ((1U == (3U & ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U]
                        : ((2U == (3U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U]
                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U])));
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1 = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1 
                = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready)) 
                   & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0) 
                         | (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word)))));
        }
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[0U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][0U];
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[1U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][1U];
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[2U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][2U];
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[3U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][3U];
            } else {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[0U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][0U];
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[1U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][1U];
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[2U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][2U];
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[3U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][3U];
            }
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_vaddr;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_offset_word;
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__resetn) {
        if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wdata 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_data;
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wstrb 
                = vlSelfRef.asm_monitor_tb__DOT__data_wstrb;
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_addr 
                = vlSelfRef.asm_monitor_tb__DOT__data_addr;
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid = 1U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid = 0U;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wdata 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_data;
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wstrb 
                = vlSelfRef.asm_monitor_tb__DOT__data_wstrb;
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_addr 
                = vlSelfRef.asm_monitor_tb__DOT__data_addr;
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid = 1U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid = 0U;
        }
        if ((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__got_addr_ok) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_is_base 
                = (0x1c000000U == (0xffc00000U & vlSelfRef.asm_monitor_tb__DOT__data_addr));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid = 1U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_store 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q;
        } else if (vlSelfRef.asm_monitor_tb__DOT__data_data_ok) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid = 0U;
        }
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1 
                    = ((0x00001fffffff8000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1) 
                       | (IData)((IData)((0x00007fffU 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1)))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1 
                    = ((0x00001fffc0007fffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1 
                                                      >> 0x0fU))))) 
                          << 0x0000000fU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1 
                    = ((0x000000003fffffffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1 
                                                      >> 0x1eU))))) 
                          << 0x0000001eU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_1_hot_bit0_r 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3 
                                     >> 0x12U)));
            }
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g1 
                    = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[2U])) 
                                                 << 0x00000013U) 
                                                | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[1U])) 
                                                   >> 0x0000000dU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__4__03a2__KET__ 
                    = (7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next) 
                             >> 2U));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit1_r 
                    = (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next) 
                             >> 1U));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit0_r 
                    = (1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r 
                    = (0x0000001fU & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10)
                                       ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)
                                       : ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                           [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                                           << 7U) | 
                                          (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                           [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                                           >> 0x00000019U))));
            }
        }
        if ((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg;
        }
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg = 0U;
        if ((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state))) {
            if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state))) {
                __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state = 0U;
            } else {
                __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state = 3U;
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg = 1U;
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state))) {
            __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state = 2U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant) {
            __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state = 1U;
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg 
                = vlSelfRef.asm_monitor_tb__DOT__data_addr;
        }
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg = 0U;
        if ((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state))) {
            if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state))) {
                __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state = 0U;
            } else {
                __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state = 3U;
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg 
                    = vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data;
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg 
                    = vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data;
            }
        } else if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state))) {
            __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state = 2U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant) {
            __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state = 1U;
            if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data) {
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data = 1U;
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg 
                    = vlSelfRef.asm_monitor_tb__DOT__data_addr;
            } else {
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data = 0U;
                vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg 
                    = vlSelfRef.asm_monitor_tb__DOT__inst_addr;
            }
        }
        if ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[0U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[0U];
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[1U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[1U];
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[2U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[2U];
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[3U] 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[3U];
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__special_block = 0U;
        } else if (((IData)((0ULL != (0x0000000010400000ULL 
                                      & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2))) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__special_block = 1U;
        }
        if ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)) 
                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2))) 
             & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way 
                = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit))
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit_way)
                    : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                       [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                               >> 4U))] & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U]
                                                      [
                                                      (7U 
                                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                                                          >> 4U))])) 
                                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr))));
        }
    } else {
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wdata = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wdata = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wstrb = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wstrb = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg = 8U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_addr = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_addr = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_is_base = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid = 0U;
        __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg = 0U;
        __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__special_block = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_store = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way = 0U;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit_way = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_vaddr = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_offset_word = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit_way 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit 
                = (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                     [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                        [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                        == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag)) 
                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1)) 
                   & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__store_inv_valid) 
                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid) 
                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                               == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr 
                                   >> 4U))))));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_taken_1;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_target_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_target_0;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_vaddr 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_0 
                = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_taken_1)) 
                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_pred_taken));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_offset_word 
                = (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                         >> 2U));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag 
                = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_paddr 
                   >> 7U);
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index 
                = (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                         >> 4U));
        }
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall)))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_valid;
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__resetn) {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                    = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[1U])) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[0U]))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 
                    = (0x000001ffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[8U])) 
                                                 << 0x0000001fU) 
                                                | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[7U])) 
                                                   >> 1U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4 
                    = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[7U])) 
                                                 << 0x0000002cU) 
                                                | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[6U])) 
                                                    << 0x0000000cU) 
                                                   | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[5U])) 
                                                      >> 0x00000014U))));
            }
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                    = ((0x00001fffffff8000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4) 
                       | (IData)((IData)((0x00007fffU 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4)))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                    = ((0x00001fffc0007fffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4 
                                                      >> 0x0fU))))) 
                          << 0x0000000fU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                    = ((0x000000003fffffffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4 
                                                      >> 0x1eU))))) 
                          << 0x0000001eU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                    = ((0x000001ffffffc000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5) 
                       | (IData)((IData)((0x00003fffU 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5)))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                    = ((0x000001fff0003fffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5) 
                       | ((QData)((IData)((0x00003fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5 
                                                      >> 0x0eU))))) 
                          << 0x0000000eU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                    = ((0x000000000fffffffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5) 
                       | ((QData)((IData)((0x00001fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5 
                                                      >> 0x1cU))))) 
                          << 0x0000001cU));
            }
        }
        if (((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
             & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)))) {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[0U] = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[1U] = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[2U] = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[3U] = 0U;
        }
        if (((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r))) {
            if ((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat))) {
                if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat))) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[3U] 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r;
                } else {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[2U] 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r;
                }
            } else if ((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat))) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[1U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r;
            } else {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[0U] 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r;
            }
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat)));
        }
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg 
            = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending) 
                 & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr))) 
                & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset))) 
               & (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready));
        if (((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending) 
             & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_exec_tx_write))) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_data_reg 
                = vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_write_byte;
        }
        if ((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending) 
              & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr)) 
             & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset)))) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab 
                = (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_write_byte) 
                         >> 7U));
        }
        if (((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending) 
             & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr)))) {
            __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_offset 
                = (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset));
            __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_value 
                = ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset))
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_data)
                    : ((- (IData)((5U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset)))) 
                       & (0x00000020U | (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready))));
            __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__Vfuncout 
                = ((0U == (IData)(__Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_offset))
                    ? (IData)(__Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_value)
                    : ((1U == (IData)(__Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_offset))
                        ? ((IData)(__Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_value) 
                           << 8U) : ((2U == (IData)(__Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_offset))
                                      ? ((IData)(__Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_value) 
                                         << 0x00000010U)
                                      : ((IData)(__Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__byte_value) 
                                         << 0x00000018U))));
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg 
                = __Vfunc_asm_monitor_tb__DOT__bridge__DOT__place_uart_byte__62__Vfuncout;
        }
        if ((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg;
        }
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r = 0U;
        if ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))) {
            if (((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                 & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))) {
                __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = 1U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_base_addr 
                    = (0xfffffff0U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr);
                __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))) {
            if (((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_inst))) {
                __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = 2U;
            }
        } else if ((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))) {
            if (((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_inst_data_ok))) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r = 1U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r 
                    = (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r 
                    = (vlSelfRef.asm_monitor_tb__DOT__base_mem
                       [vlSelfRef.asm_monitor_tb__DOT__base_addr] 
                       & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_inst_data_ok))));
                if ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat))) {
                    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = 0U;
                } else {
                    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat)));
                    __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = 1U;
                }
            }
        } else {
            __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = 0U;
        }
    } else {
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line[3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_data_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_base_addr = 0U;
        __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r = 0U;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall)))) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_paddr;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1 = 0U;
    } else {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0 = 0U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                              >> 2U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait) 
                      & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait)) 
                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok))));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex)
                    ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1)
                    : 0U);
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0;
        }
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 
                                     >> 0x00000020U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1 
                    = (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0);
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                     >> 0x0000002bU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                     >> 0x0000002aU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                     >> 0x0000002cU)));
            }
        }
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl;
    vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles 
        = ((__Vdly__asm_monitor_tb__DOT__benchmark_cycles 
            & __VdlyMask__asm_monitor_tb__DOT__benchmark_cycles) 
           | (vlSelfRef.asm_monitor_tb__DOT__benchmark_cycles 
              & (~ __VdlyMask__asm_monitor_tb__DOT__benchmark_cycles)));
    __VdlyMask__asm_monitor_tb__DOT__benchmark_cycles = 0ULL;
    vlSelfRef.asm_monitor_tb__DOT__commit_count = (
                                                   (__Vdly__asm_monitor_tb__DOT__commit_count 
                                                    & __VdlyMask__asm_monitor_tb__DOT__commit_count) 
                                                   | (vlSelfRef.asm_monitor_tb__DOT__commit_count 
                                                      & (~ __VdlyMask__asm_monitor_tb__DOT__commit_count)));
    __VdlyMask__asm_monitor_tb__DOT__commit_count = 0ULL;
    vlSelfRef.asm_monitor_tb__DOT__benchmark_done = 
        (((IData)(__Vdly__asm_monitor_tb__DOT__benchmark_done) 
          & (IData)(__VdlyMask__asm_monitor_tb__DOT__benchmark_done)) 
         | ((IData)(vlSelfRef.asm_monitor_tb__DOT__benchmark_done) 
            & (~ (IData)(__VdlyMask__asm_monitor_tb__DOT__benchmark_done))));
    __VdlyMask__asm_monitor_tb__DOT__benchmark_done = 0U;
    vlSelfRef.asm_monitor_tb__DOT__exit_seen = (((IData)(__Vdly__asm_monitor_tb__DOT__exit_seen) 
                                                 & (IData)(__VdlyMask__asm_monitor_tb__DOT__exit_seen)) 
                                                | ((IData)(vlSelfRef.asm_monitor_tb__DOT__exit_seen) 
                                                   & (~ (IData)(__VdlyMask__asm_monitor_tb__DOT__exit_seen))));
    __VdlyMask__asm_monitor_tb__DOT__exit_seen = 0U;
    vlSelfRef.asm_monitor_tb__DOT__exit_pc = ((__Vdly__asm_monitor_tb__DOT__exit_pc 
                                               & __VdlyMask__asm_monitor_tb__DOT__exit_pc) 
                                              | (vlSelfRef.asm_monitor_tb__DOT__exit_pc 
                                                 & (~ __VdlyMask__asm_monitor_tb__DOT__exit_pc)));
    __VdlyMask__asm_monitor_tb__DOT__exit_pc = 0U;
    if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__ext_be_n)))) {
            __VdlyVal__asm_monitor_tb__DOT__ext_mem__v0 
                = (0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__ext_wdata);
            __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v0 
                = vlSelfRef.asm_monitor_tb__DOT__ext_addr;
            __VdlySet__asm_monitor_tb__DOT__ext_mem__v0 = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__ext_be_n) 
                      >> 1U)))) {
            __VdlyVal__asm_monitor_tb__DOT__ext_mem__v1 
                = (0x000000ffU & (vlSelfRef.asm_monitor_tb__DOT__ext_wdata 
                                  >> 8U));
            __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v1 
                = vlSelfRef.asm_monitor_tb__DOT__ext_addr;
            __VdlySet__asm_monitor_tb__DOT__ext_mem__v1 = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__ext_be_n) 
                      >> 2U)))) {
            __VdlyVal__asm_monitor_tb__DOT__ext_mem__v2 
                = (0x000000ffU & (vlSelfRef.asm_monitor_tb__DOT__ext_wdata 
                                  >> 0x10U));
            __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v2 
                = vlSelfRef.asm_monitor_tb__DOT__ext_addr;
            __VdlySet__asm_monitor_tb__DOT__ext_mem__v2 = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__ext_be_n) 
                      >> 3U)))) {
            __VdlyVal__asm_monitor_tb__DOT__ext_mem__v3 
                = (vlSelfRef.asm_monitor_tb__DOT__ext_wdata 
                   >> 0x18U);
            __VdlyDim0__asm_monitor_tb__DOT__ext_mem__v3 
                = vlSelfRef.asm_monitor_tb__DOT__ext_addr;
            __VdlySet__asm_monitor_tb__DOT__ext_mem__v3 = 1U;
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain) {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__base_be_n)))) {
            __VdlyVal__asm_monitor_tb__DOT__base_mem__v0 
                = (0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__base_wdata);
            __VdlyDim0__asm_monitor_tb__DOT__base_mem__v0 
                = vlSelfRef.asm_monitor_tb__DOT__base_addr;
            __VdlySet__asm_monitor_tb__DOT__base_mem__v0 = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__base_be_n) 
                      >> 1U)))) {
            __VdlyVal__asm_monitor_tb__DOT__base_mem__v1 
                = (0x000000ffU & (vlSelfRef.asm_monitor_tb__DOT__base_wdata 
                                  >> 8U));
            __VdlyDim0__asm_monitor_tb__DOT__base_mem__v1 
                = vlSelfRef.asm_monitor_tb__DOT__base_addr;
            __VdlySet__asm_monitor_tb__DOT__base_mem__v1 = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__base_be_n) 
                      >> 2U)))) {
            __VdlyVal__asm_monitor_tb__DOT__base_mem__v2 
                = (0x000000ffU & (vlSelfRef.asm_monitor_tb__DOT__base_wdata 
                                  >> 0x10U));
            __VdlyDim0__asm_monitor_tb__DOT__base_mem__v2 
                = vlSelfRef.asm_monitor_tb__DOT__base_addr;
            __VdlySet__asm_monitor_tb__DOT__base_mem__v2 = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__base_be_n) 
                      >> 3U)))) {
            __VdlyVal__asm_monitor_tb__DOT__base_mem__v3 
                = (vlSelfRef.asm_monitor_tb__DOT__base_wdata 
                   >> 0x18U);
            __VdlyDim0__asm_monitor_tb__DOT__base_mem__v3 
                = vlSelfRef.asm_monitor_tb__DOT__base_addr;
            __VdlySet__asm_monitor_tb__DOT__base_mem__v3 = 1U;
        }
        if (vlSelfRef.asm_monitor_tb__DOT__counting) {
            __Vdly__asm_monitor_tb__DOT__write_count 
                = (1ULL + vlSelfRef.asm_monitor_tb__DOT__write_count);
            __VdlyMask__asm_monitor_tb__DOT__write_count = 0xffffffffffffffffULL;
            if (VL_GTS_III(32, 0x00000100U, vlSelfRef.asm_monitor_tb__DOT__write_log_count)) {
                __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v0 
                    = ((IData)(0x1c000000U) + (vlSelfRef.asm_monitor_tb__DOT__base_addr 
                                               << 2U));
                __VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v0 
                    = (0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__write_log_count);
                __VdlySet__asm_monitor_tb__DOT__write_addr_log__v0 = 1U;
                __VdlyVal__asm_monitor_tb__DOT__write_data_log__v0 
                    = vlSelfRef.asm_monitor_tb__DOT__base_wdata;
                __VdlyDim0__asm_monitor_tb__DOT__write_data_log__v0 
                    = (0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__write_log_count);
                __Vdly__asm_monitor_tb__DOT__write_log_count 
                    = ((IData)(1U) + vlSelfRef.asm_monitor_tb__DOT__write_log_count);
                __VdlyMask__asm_monitor_tb__DOT__write_log_count = 0xffffffffU;
            }
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) {
        if (vlSelfRef.asm_monitor_tb__DOT__counting) {
            __Vdly__asm_monitor_tb__DOT__write_count 
                = (1ULL + vlSelfRef.asm_monitor_tb__DOT__write_count);
            __VdlyMask__asm_monitor_tb__DOT__write_count = 0xffffffffffffffffULL;
            if (VL_GTS_III(32, 0x00000100U, vlSelfRef.asm_monitor_tb__DOT__write_log_count)) {
                __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v1 
                    = ((IData)(0x1c400000U) + (vlSelfRef.asm_monitor_tb__DOT__ext_addr 
                                               << 2U));
                __VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v1 
                    = (0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__write_log_count);
                __VdlySet__asm_monitor_tb__DOT__write_addr_log__v1 = 1U;
                __VdlyVal__asm_monitor_tb__DOT__write_data_log__v1 
                    = vlSelfRef.asm_monitor_tb__DOT__ext_wdata;
                __VdlyDim0__asm_monitor_tb__DOT__write_data_log__v1 
                    = (0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__write_log_count);
                __Vdly__asm_monitor_tb__DOT__write_log_count 
                    = ((IData)(1U) + vlSelfRef.asm_monitor_tb__DOT__write_log_count);
                __VdlyMask__asm_monitor_tb__DOT__write_log_count = 0xffffffffU;
            }
        }
    }
    vlSelfRef.asm_monitor_tb__DOT__write_count = ((__Vdly__asm_monitor_tb__DOT__write_count 
                                                   & __VdlyMask__asm_monitor_tb__DOT__write_count) 
                                                  | (vlSelfRef.asm_monitor_tb__DOT__write_count 
                                                     & (~ __VdlyMask__asm_monitor_tb__DOT__write_count)));
    __VdlyMask__asm_monitor_tb__DOT__write_count = 0ULL;
    vlSelfRef.asm_monitor_tb__DOT__write_log_count 
        = ((__Vdly__asm_monitor_tb__DOT__write_log_count 
            & __VdlyMask__asm_monitor_tb__DOT__write_log_count) 
           | (vlSelfRef.asm_monitor_tb__DOT__write_log_count 
              & (~ __VdlyMask__asm_monitor_tb__DOT__write_log_count)));
    __VdlyMask__asm_monitor_tb__DOT__write_log_count = 0U;
    vlSelfRef.asm_monitor_tb__DOT__counting = (((IData)(__Vdly__asm_monitor_tb__DOT__counting) 
                                                & (IData)(__VdlyMask__asm_monitor_tb__DOT__counting)) 
                                               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__counting) 
                                                  & (~ (IData)(__VdlyMask__asm_monitor_tb__DOT__counting))));
    __VdlyMask__asm_monitor_tb__DOT__counting = 0U;
    if (__VdlySet__asm_monitor_tb__DOT__write_addr_log__v0) {
        vlSelfRef.asm_monitor_tb__DOT__write_addr_log[__VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v0] 
            = __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v0;
        vlSelfRef.asm_monitor_tb__DOT__write_data_log[__VdlyDim0__asm_monitor_tb__DOT__write_data_log__v0] 
            = __VdlyVal__asm_monitor_tb__DOT__write_data_log__v0;
    }
    if (__VdlySet__asm_monitor_tb__DOT__write_addr_log__v1) {
        vlSelfRef.asm_monitor_tb__DOT__write_addr_log[__VdlyDim0__asm_monitor_tb__DOT__write_addr_log__v1] 
            = __VdlyVal__asm_monitor_tb__DOT__write_addr_log__v1;
        vlSelfRef.asm_monitor_tb__DOT__write_data_log[__VdlyDim0__asm_monitor_tb__DOT__write_data_log__v1] 
            = __VdlyVal__asm_monitor_tb__DOT__write_data_log__v1;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail;
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v0;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf__v1;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1__v0;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U][3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U][3U] = 0U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v8] = 1U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid__v9] = 1U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U][3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U][3U] = 0U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v8;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem__v9;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0][0U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0][1U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0][2U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0][3U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1__v0[3U];
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0][0U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0][1U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0][2U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0][3U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0__v0[3U];
    }
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state 
        = __Vdly__asm_monitor_tb__DOT__bridge__DOT__ext_state;
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state 
        = __Vdly__asm_monitor_tb__DOT__bridge__DOT__base_state;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0;
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_start_reg 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__resetn) 
           && ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending) 
               & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_exec_tx_write)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending;
    if (__VdlySet__asm_monitor_tb__DOT__ext_mem__v0) {
        vlSelfRef.asm_monitor_tb__DOT__ext_mem[__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v0] 
            = ((0xffffff00U & vlSelfRef.asm_monitor_tb__DOT__ext_mem
                [__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v0]) 
               | (IData)(__VdlyVal__asm_monitor_tb__DOT__ext_mem__v0));
    }
    if (__VdlySet__asm_monitor_tb__DOT__ext_mem__v1) {
        vlSelfRef.asm_monitor_tb__DOT__ext_mem[__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v1] 
            = ((0xffff00ffU & vlSelfRef.asm_monitor_tb__DOT__ext_mem
                [__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v1]) 
               | ((IData)(__VdlyVal__asm_monitor_tb__DOT__ext_mem__v1) 
                  << 8U));
    }
    if (__VdlySet__asm_monitor_tb__DOT__ext_mem__v2) {
        vlSelfRef.asm_monitor_tb__DOT__ext_mem[__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v2] 
            = ((0xff00ffffU & vlSelfRef.asm_monitor_tb__DOT__ext_mem
                [__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v2]) 
               | ((IData)(__VdlyVal__asm_monitor_tb__DOT__ext_mem__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__asm_monitor_tb__DOT__ext_mem__v3) {
        vlSelfRef.asm_monitor_tb__DOT__ext_mem[__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v3] 
            = ((0x00ffffffU & vlSelfRef.asm_monitor_tb__DOT__ext_mem
                [__VdlyDim0__asm_monitor_tb__DOT__ext_mem__v3]) 
               | ((IData)(__VdlyVal__asm_monitor_tb__DOT__ext_mem__v3) 
                  << 0x00000018U));
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__resetn) 
           && ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush))) 
               && Vasm_monitor_tb__ConstPool__TABLE_h547ba932_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_54]));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__resetn) 
           && ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush))) 
               && Vasm_monitor_tb__ConstPool__TABLE_h2c364be9_0
               [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_54]));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s2 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__reset))) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_pc__DOT__reset 
        = (1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head;
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][0U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][1U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][2U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][3U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[3U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][4U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[4U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][5U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[5U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][6U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[6U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][7U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[7U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0][8U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v0[8U];
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][0U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][1U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][2U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][3U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[3U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][4U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[4U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][5U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[5U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][6U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[6U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][7U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[7U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1][8U] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo__v1[8U];
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0) 
           & (2U >= (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt)));
    __VdfgRegularize_h6e95ff9d_0_30 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_resp_valid) 
           | (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state)));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid) 
           & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1) 
           & (2U >= (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1)
            ? 2U : (1U & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0)))));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_resp_valid) 
           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data) 
              & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state))));
    __VdfgRegularize_h6e95ff9d_0_36 = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid)) 
                                       & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid) 
           & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)));
    asm_monitor_tb__DOT__data_fast_ready = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg) 
                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0));
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
           | vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1;
    __VdfgRegularize_h6e95ff9d_0_6 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_1) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_1) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_1));
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_sign_ext 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_sign_ext_0;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_half 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_half_0;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_byte 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_byte_0;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_mem_result_0;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__alu_result 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0;
    if ((2U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__alu_result)) {
        asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte 
            = (0x000000ffU & ((1U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__alu_result)
                               ? (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result 
                                  >> 0x18U) : (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result 
                                               >> 0x10U)));
        asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half 
            = (0x0000ffffU & (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result 
                              >> 0x10U));
    } else {
        asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte 
            = (0x000000ffU & ((1U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__alu_result)
                               ? (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result 
                                  >> 8U) : __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result));
        asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half 
            = (0x0000ffffU & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result);
    }
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__Vfuncout 
        = ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_byte)
            ? ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_sign_ext)
                ? (((- (IData)((1U & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte) 
                                      >> 7U)))) << 8U) 
                   | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte))
                : (IData)(asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte))
            : ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_half)
                ? ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__ld_sign_ext)
                    ? (((- (IData)((1U & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half) 
                                          >> 0x0fU)))) 
                        << 0x00000010U) | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half))
                    : (IData)(asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half))
                : __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__mem_result));
    asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_load_result_0 
        = __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__52__Vfuncout;
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__resetn) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending));
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
           | vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1);
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[0U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[0U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[0U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[0U][3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U][3U] = 0U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v8;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target__v9;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[0U][0U] = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[0U][1U] = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[0U][2U] = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[0U][3U] = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[1U][0U] = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[1U][1U] = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[1U][2U] = 1U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[1U][3U] = 1U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v8;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter__v9] = 2U;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__bpu_sel_lane1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1) 
           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0)) 
              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold 
        = ((2U < (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt)) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0) 
              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__icacop_req_valid 
        = (IData)((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
                    >> 1U) & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state;
    __VdfgRegularize_h6e95ff9d_0_38 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                       & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0)) 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0)));
    __VdfgRegularize_h6e95ff9d_0_29 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0));
    vlSelfRef.asm_monitor_tb__DOT__ext_wdata = (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wdata 
                                                & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain))));
    asm_monitor_tb__DOT__bridge__DOT__ext_store_ready 
        = (1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid)) 
                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain)));
    vlSelfRef.asm_monitor_tb__DOT__base_wdata = (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wdata 
                                                 & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain))));
    asm_monitor_tb__DOT__bridge__DOT__base_store_ready 
        = (1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid)) 
                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain)));
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting) 
           & (IData)(asm_monitor_tb__DOT__data_fast_ready));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__load_wakeup_valid 
        = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)) 
           & (IData)(asm_monitor_tb__DOT__data_fast_ready));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat;
    vlSelfRef.asm_monitor_tb__DOT__data_req = (1U & 
                                               ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
                                                & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending)) 
                                                   & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid)) 
                                                      & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q)) 
                                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__4__03a2__KET__) 
            << 2U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit1_r) 
                       << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit0_r)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_res_from_mem_0)
            ? asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_load_result_0
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_hit_s2 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_valid_s2) 
           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_tag_s2 
              == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__reset 
        = (1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16 = ((0x16U 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU)) 
                                                 | (0x17U 
                                                    == 
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x0000001aU)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15 = ((0x1bU 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU)) 
                                                 | ((0x1aU 
                                                     == 
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                      >> 0x0000001aU)) 
                                                    | ((0x18U 
                                                        == 
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x0000001aU)) 
                                                       | (0x19U 
                                                          == 
                                                          (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                           >> 0x0000001aU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = (IData)(
                                                        (0x00400000U 
                                                         == 
                                                         (0xfff00000U 
                                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = (IData)(
                                                       (0x00100000U 
                                                        == 
                                                        (0xfff00000U 
                                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_21 = ((0x16U 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU)) 
                                                 | (0x17U 
                                                    == 
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x0000001aU)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20 = ((0x1bU 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU)) 
                                                 | ((0x1aU 
                                                     == 
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                      >> 0x0000001aU)) 
                                                    | ((0x18U 
                                                        == 
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x0000001aU)) 
                                                       | (0x19U 
                                                          == 
                                                          (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                           >> 0x0000001aU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19 = (IData)(
                                                        (0x00400000U 
                                                         == 
                                                         (0xfff00000U 
                                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = (IData)(
                                                       (0x00100000U 
                                                        == 
                                                        (0xfff00000U 
                                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_direct 
        = ((0U == (7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code))) 
           & ((0U == (3U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code) 
                            >> 3U))) | (1U == (3U & 
                                               ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code) 
                                                >> 3U)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit 
        = (IData)((0x10U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_38) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_29));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_29) 
           | (IData)(__VdfgRegularize_h6e95ff9d_0_30));
    __VdfgRegularize_h6e95ff9d_0_31 = (0xee000039U 
                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data 
                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset))) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_is_csr_0 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset))) 
           && ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0) 
               && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0)));
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1 = 0U;
    } else if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))))) {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0 
                    = ((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0);
            }
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1;
            }
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q) {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_1;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_1;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_1;
    } else {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_0;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_0;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__resetn) {
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 
                    = ((0x00001fffffff8000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0) 
                       | (IData)((IData)((0x00007fffU 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0)))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 
                    = ((0x00001fffc0007fffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0 
                                                      >> 0x0fU))))) 
                          << 0x0000000fU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 
                    = ((0x000000003fffffffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0 
                                                      >> 0x1eU))))) 
                          << 0x0000001eU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                    = ((0x00001fffffff8000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2) 
                       | (IData)((IData)((0x00007fffU 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2)))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                    = ((0x00001fffc0007fffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2 
                                                      >> 0x0fU))))) 
                          << 0x0000000fU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                    = ((0x000000003fffffffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2 
                                                      >> 0x1eU))))) 
                          << 0x0000001eU));
            }
        }
        if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_write_byte 
                = (0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_data);
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset 
                = (7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr);
        }
    } else {
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_write_byte = 0U;
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset = 0U;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0);
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0 = 0U;
    } else {
        if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1 = 0U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) 
                   && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1));
        }
        if ((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
                if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) {
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0;
                    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0 
                        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0;
                }
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0 
                    = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
                       && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0));
            } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0 = 0U;
            }
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__resetn) {
        if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant) {
            vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr 
                = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q;
        }
    } else {
        vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr = 0U;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1 = 0U;
    } else if (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
                | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire))) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1 = 0U;
    } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q 
            = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw)
                ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0)
                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw) 
                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1)));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1 
            = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1) 
               && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1));
    } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1;
    }
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_cacop_code_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0 = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1 = 0U;
    } else {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0 = 0U;
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1 = 0U;
        } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0 = 1U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                     >> 2U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0 
                    = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                      >> 0x00000026U)))
                        ? 1U : ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000025U)))
                                 ? 2U : ((1U & (IData)(
                                                       (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                        >> 0x00000024U)))
                                          ? 3U : ((1U 
                                                   & (IData)(
                                                             (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                              >> 0x00000023U)))
                                                   ? 4U
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                               >> 0x00000022U)))
                                                    ? 5U
                                                    : 
                                                   ((1U 
                                                     & (IData)(
                                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                                >> 0x00000021U)))
                                                     ? 6U
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                                 >> 0x00000020U)))
                                                      ? 7U
                                                      : 
                                                     ((1U 
                                                       & (IData)(
                                                                 (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                                  >> 0x0000001fU)))
                                                       ? 8U
                                                       : 
                                                      (9U 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                                                >> 0x0000001eU))))))))))))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                     >> 0x0000001cU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                     >> 4U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                     >> 5U)));
            } else {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0 = 0U;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0 = 0U;
            }
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                              >> 4U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                              >> 5U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                              >> 0x00000016U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                              >> 3U)));
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1 
                = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex) 
                   & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                              >> 3U)));
        }
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                     >> 1U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1 
                    = (1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                     >> 0x0000002aU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                     >> 0x0000002bU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0 
                    = (1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                     >> 1U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0 
                    = (1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                     >> 0x0000002cU)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0 
                    = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                              >> 8U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1 
                    = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                              >> 8U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_cacop_code_0 
                    = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x00000017U)));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1 
                    = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[3U] 
                        << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[2U] 
                                           >> 1U));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0 
                    = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_pc_0;
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0 
                    = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                      >> 0x00000015U)))
                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0
                        : 0xffffffffU);
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0 
                    = (0x00003fffU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 7U)));
            }
        }
    }
    if (vlSelfRef.asm_monitor_tb__DOT__resetn) {
        if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__got_addr_ok) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                = (vlSelfRef.asm_monitor_tb__DOT__data_addr 
                   >> 4U);
        }
        if ((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))) {
            vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg 
                = (((((((0U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                        & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next) 
                       | ((3U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                          & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                             >> 3U))) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode)) 
                     << 0x0000000dU) | (((0x00000038U 
                                          & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                             >> 0x0000001aU)) 
                                         | (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                                  >> 0x00000019U))) 
                                        << 7U)) | (
                                                   (((((0U 
                                                        == 
                                                        (3U 
                                                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                                       & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next) 
                                                      | ((3U 
                                                          == 
                                                          (3U 
                                                           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                                         & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next 
                                                            >> 3U))) 
                                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode)) 
                                                    << 6U) 
                                                   | ((0x00000038U 
                                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next 
                                                          >> 0x0000001aU)) 
                                                      | (7U 
                                                         & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next 
                                                            >> 0x00000019U)))));
        }
        if ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush)))) {
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                    = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[4U])) 
                                                 << 0x00000026U) 
                                                | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[3U])) 
                                                    << 6U) 
                                                   | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[2U])) 
                                                      >> 0x0000001aU))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                    = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[5U])) 
                                                 << 0x00000019U) 
                                                | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[4U])) 
                                                   >> 7U)));
            }
            if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a) {
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                    = ((0x00001fffffff8000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3) 
                       | (IData)((IData)((0x00007fffU 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3)))));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                    = ((0x00001fffc0007fffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3 
                                                      >> 0x0fU))))) 
                          << 0x0000000fU));
                vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                    = ((0x000000003fffffffULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3) 
                       | ((QData)((IData)((0x00007fffU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3 
                                                      >> 0x1eU))))) 
                          << 0x0000001eU));
            }
        }
    } else {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg = 0U;
    }
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
           == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed 
        = VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
           < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1);
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go 
        = (1U & ((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind))
                  ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent) 
                     & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state)))
                  : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid) 
                     | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready) 
                        | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind)) 
                           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__data_req) 
                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q) 
                                 & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                                      ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q)
                                      : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q)) 
                                    & ((((IData)(asm_monitor_tb__DOT__bridge__DOT__ext_store_ready) 
                                         << 1U) | (IData)(asm_monitor_tb__DOT__bridge__DOT__base_store_ready)) 
                                       >> (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q))))))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)))));
    __VdfgRegularize_h6e95ff9d_0_3 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0;
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready 
        = (1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0)
            ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid)
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0
                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2)
            : ((0U != (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0)))
                ? ((0xffffff00U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                   + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                        ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                      + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                               >> 1U))))) 
                   | (0x000000ffU & (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                       ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                       : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                     + (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                        + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                 >> 1U))))))
                : (((- (IData)((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 2U)))) & VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)) 
                   | (((- (IData)((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                         >> 3U)))) 
                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                          < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)) 
                      | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                          & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0 
                             & (- (IData)((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                 >> 4U)))))) 
                         | (((~ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result) 
                             & (- (IData)((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                 >> 5U))))) 
                            | ((asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result 
                                & (- (IData)((1U & 
                                              ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                               >> 6U))))) 
                               | (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                    ^ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                   & (- (IData)((1U 
                                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                    >> 7U))))) 
                                  | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0 
                                      & (- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                       >> 0x0000000bU))))) 
                                     | (((IData)(((
                                                   ((QData)((IData)(
                                                                    (- (IData)((IData)(
                                                                                (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                                                >> 0x0000000aU) 
                                                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                                                >> 0x0000001fU))))))) 
                                                    << 0x00000020U) 
                                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0))) 
                                                  >> 
                                                  (0x0000001fU 
                                                   & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0))) 
                                         & (- (IData)(
                                                      (0U 
                                                       != 
                                                       (3U 
                                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                           >> 9U)))))) 
                                        | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                            << (0x0000001fU 
                                                & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)) 
                                           & (- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                            >> 8U)))))))))))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0) 
           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0)) 
              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid)));
    __VdfgRegularize_h6e95ff9d_0_7 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1));
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
           == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed 
        = VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
           < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0);
    vlSelfRef.asm_monitor_tb__DOT__data_data_ok = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok) 
                                                   | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid) 
                                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok)));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__resetn) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_58 = ((0x14U 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU)) 
                                                 | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_63 = ((0x14U 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU)) 
                                                 | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20));
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0[__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0__v0;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[__VdlyDim1__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0] 
            = __VdlyVal__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v0;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v1] = 0U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v2] = 0U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v3] = 0U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][__VdlyDim0__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v4] = 0U;
    }
    if (__VdlySet__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid__v5) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][4U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][5U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][6U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U][7U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][0U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][1U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][2U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][3U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][4U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][5U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][6U] = 0U;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U][7U] = 0U;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
           & (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd) 
               & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
              | (((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd)) 
                  & (2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                 | (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed) 
                     & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                    | (((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed)) 
                        & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                       | (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned) 
                           & (5U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                          | ((9U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                             | ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned)) 
                                & (6U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))))))))));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_inst_data_ok 
        = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data)) 
           & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)));
    if (__VdlySet__asm_monitor_tb__DOT__base_mem__v0) {
        vlSelfRef.asm_monitor_tb__DOT__base_mem[__VdlyDim0__asm_monitor_tb__DOT__base_mem__v0] 
            = ((0xffffff00U & vlSelfRef.asm_monitor_tb__DOT__base_mem
                [__VdlyDim0__asm_monitor_tb__DOT__base_mem__v0]) 
               | (IData)(__VdlyVal__asm_monitor_tb__DOT__base_mem__v0));
    }
    if (__VdlySet__asm_monitor_tb__DOT__base_mem__v1) {
        vlSelfRef.asm_monitor_tb__DOT__base_mem[__VdlyDim0__asm_monitor_tb__DOT__base_mem__v1] 
            = ((0xffff00ffU & vlSelfRef.asm_monitor_tb__DOT__base_mem
                [__VdlyDim0__asm_monitor_tb__DOT__base_mem__v1]) 
               | ((IData)(__VdlyVal__asm_monitor_tb__DOT__base_mem__v1) 
                  << 8U));
    }
    if (__VdlySet__asm_monitor_tb__DOT__base_mem__v2) {
        vlSelfRef.asm_monitor_tb__DOT__base_mem[__VdlyDim0__asm_monitor_tb__DOT__base_mem__v2] 
            = ((0xff00ffffU & vlSelfRef.asm_monitor_tb__DOT__base_mem
                [__VdlyDim0__asm_monitor_tb__DOT__base_mem__v2]) 
               | ((IData)(__VdlyVal__asm_monitor_tb__DOT__base_mem__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__asm_monitor_tb__DOT__base_mem__v3) {
        vlSelfRef.asm_monitor_tb__DOT__base_mem[__VdlyDim0__asm_monitor_tb__DOT__base_mem__v3] 
            = ((0x00ffffffU & vlSelfRef.asm_monitor_tb__DOT__base_mem
                [__VdlyDim0__asm_monitor_tb__DOT__base_mem__v3]) 
               | ((IData)(__VdlyVal__asm_monitor_tb__DOT__base_mem__v3) 
                  << 0x00000018U));
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
    __VdfgRegularize_h6e95ff9d_0_40 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_3));
    __VdfgRegularize_h6e95ff9d_0_5 = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0)) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
           & ((7U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
              | (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd) 
                  & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                 | (((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd)) 
                     & (2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                    | (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed) 
                        & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                       | (((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed)) 
                           & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                          | (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned) 
                              & (5U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                             | ((9U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
                                | ((8U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
                                   | ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned)) 
                                      & (6U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))))))))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1)
            ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid)
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_1
                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2)
            : ((0U != (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1)))
                ? (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                   + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))
                        ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)
                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1) 
                      + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                               >> 1U)))) : (((- (IData)(
                                                        (1U 
                                                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                            >> 2U)))) 
                                             & VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)) 
                                            | (((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                               >> 3U)))) 
                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                   < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)) 
                                               | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1 
                                                      & (- (IData)(
                                                                   (1U 
                                                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                       >> 4U)))))) 
                                                  | (((~ asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result) 
                                                      & (- (IData)(
                                                                   (1U 
                                                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                       >> 5U))))) 
                                                     | ((asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result 
                                                         & (- (IData)(
                                                                      (1U 
                                                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                          >> 6U))))) 
                                                        | (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                             ^ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1) 
                                                            & (- (IData)(
                                                                         (1U 
                                                                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                             >> 7U))))) 
                                                           | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1 
                                                               & (- (IData)(
                                                                            (1U 
                                                                             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                                >> 0x0000000bU))))) 
                                                              | (((IData)(
                                                                          ((((QData)((IData)(
                                                                                (- (IData)((IData)(
                                                                                (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                                >> 0x0000000aU) 
                                                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                                                >> 0x0000001fU))))))) 
                                                                             << 0x00000020U) 
                                                                            | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1))) 
                                                                           >> 
                                                                           (0x0000001fU 
                                                                            & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1))) 
                                                                  & (- (IData)(
                                                                               (0U 
                                                                                != 
                                                                                (3U 
                                                                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                                >> 9U)))))) 
                                                                 | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                                     << 
                                                                     (0x0000001fU 
                                                                      & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)) 
                                                                    & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                                >> 8U)))))))))))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_ok 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_data_ok));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__store_inv_valid 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__data_data_ok) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_store) 
                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_is_base))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_data 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte)
            ? ((asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
                << 0x00000018U) | ((0x00ff0000U & (asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
                                                   << 0x00000010U)) 
                                   | ((0x0000ff00U 
                                       & (asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
                                          << 8U)) | 
                                      (0x000000ffU 
                                       & asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd))))
            : ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half)
                ? ((asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
                    << 0x00000010U) | (0x0000ffffU 
                                       & asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd))
                : asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd));
    __VdfgRegularize_h6e95ff9d_0_39 = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)));
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_sign_ext 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_half 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_byte 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf;
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__alu_result 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0;
    if ((2U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__alu_result)) {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
            = (0x000000ffU & ((1U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__alu_result)
                               ? (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result 
                                  >> 0x18U) : (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result 
                                               >> 0x10U)));
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
            = (0x0000ffffU & (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result 
                              >> 0x10U));
    } else {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte 
            = (0x000000ffU & ((1U & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__alu_result)
                               ? (__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result 
                                  >> 8U) : __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result));
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half 
            = (0x0000ffffU & __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result);
    }
    __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__Vfuncout 
        = ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_byte)
            ? ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_sign_ext)
                ? (((- (IData)((1U & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte) 
                                      >> 7U)))) << 8U) 
                   | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
                : (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte))
            : ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_half)
                ? ((IData)(__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__ld_sign_ext)
                    ? (((- (IData)((1U & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half) 
                                          >> 0x0fU)))) 
                        << 0x00000010U) | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                    : (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half))
                : __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__mem_result));
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_load_result_0_fwd 
        = __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__54__Vfuncout;
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__bpu_sel_lane1) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_real_target 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1;
    } else {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_real_target 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset 
        = (1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)));
    vlSelfRef.asm_monitor_tb__DOT__inst_addr = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_base_addr 
                                                + ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat) 
                                                   << 2U));
    if ((4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg[3U];
    } else {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data[3U];
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__cacop_flush 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
            >> 1U) & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1 
        = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                          >> 0x00000026U))) ? 1U : 
           ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                           >> 0x00000025U))) ? 2U : 
            ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                            >> 0x00000024U))) ? 3U : 
             ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                             >> 0x00000023U))) ? 4U
               : ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                 >> 0x00000022U))) ? 5U
                   : ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                     >> 0x00000021U)))
                       ? 6U : ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                              >> 0x00000020U)))
                                ? 7U : ((1U & (IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                       >> 0x0000001fU)))
                                         ? 8U : (9U 
                                                 & (- (IData)(
                                                              (1U 
                                                               & (IData)(
                                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                                          >> 0x0000001eU))))))))))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1 
        = (IData)((0ULL != (0x0000000030400000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src1_1 
           * vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src2_1);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0)
             ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
             : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ds_mul_src1_0) 
           * ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)
               ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
               : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ds_mul_src2_0));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1))))));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_exec_tx_write 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr) 
           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab)) 
              & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_40) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0) 
              & (IData)(__VdfgRegularize_h6e95ff9d_0_39)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_40) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
              & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready) 
                 & (IData)(__VdfgRegularize_h6e95ff9d_0_39))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__pc_out;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state 
        = __Vdly__asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0)
            ? asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_load_result_0_fwd
            : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
               & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws0 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_38) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0));
    vlSelfRef.asm_monitor_tb__DOT__data_addr = ((((
                                                   ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                                    >> 6U) 
                                                   & ((7U 
                                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                                          >> 3U)) 
                                                      == 
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                                                       >> 0x0000001dU)))
                                                   ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg)
                                                   : 
                                                  ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                                     >> 0x0000000dU) 
                                                    & ((7U 
                                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                                           >> 0x0000000aU)) 
                                                       == 
                                                       (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                                                        >> 0x0000001dU)))
                                                    ? 
                                                   ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                                    >> 7U)
                                                    : 
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                                                    >> 0x0000001dU))) 
                                                 << 0x0000001dU) 
                                                | (0x1fffffffU 
                                                   & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant 
        = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
            >> 0x00000018U) & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending)) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_req)));
    __VdfgRegularize_h6e95ff9d_0_37 = ((~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                                           >> 0x00000018U)) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_req));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U]
           [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1
              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
              == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row 
        = (3U & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                  >> 3U) ^ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                            >> 6U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next 
        = (((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)) 
            & (0x0180U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr)))
            ? (__VdfgRegularize_h6e95ff9d_0_31 | (0xee000039U 
                                                  & ((~ 
                                                      (0xee000039U 
                                                       & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask)) 
                                                     & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg)))
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
        = (((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)) 
            & (0x0181U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr)))
            ? (__VdfgRegularize_h6e95ff9d_0_31 | (0xee000039U 
                                                  & ((~ 
                                                      (0xee000039U 
                                                       & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask)) 
                                                     & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg)))
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next 
        = (0x000001ffU & (((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)) 
                           & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr)))
                           ? (((~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg)) 
                              | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data 
                                 & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask))
                           : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1 
           + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_1);
    asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint 
        = ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
           & (((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                      >> 4U)) == (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                        >> 4U))) & 
              ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                >> 7U) == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                           >> 7U))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__store_inv_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
              & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                 == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                     >> 4U))));
    asm_monitor_tb__DOT__bridge__DOT__ext_data_req 
        = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
            >> 0x00000016U) & (IData)(__VdfgRegularize_h6e95ff9d_0_37));
    asm_monitor_tb__DOT__bridge__DOT__base_data_req 
        = ((~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
               >> 0x00000016U)) & (IData)(__VdfgRegularize_h6e95ff9d_0_37));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1 
        = (1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0) 
                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1))));
    vlSelfRef.asm_monitor_tb__DOT__data_wstrb = (0x0000000fU 
                                                 & (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte)
                                                      ? 
                                                     ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr))
                                                      : 
                                                     (((2U 
                                                        & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr)
                                                        ? 0x0cU
                                                        : 3U) 
                                                      | (- (IData)(
                                                                   (1U 
                                                                    & (~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half))))))) 
                                                    & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q)))));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1 
        = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U]
            [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U]
               [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
               == (0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                  >> 5U)))) & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[1U]
                                               [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                               >> 1U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode 
        = (IData)((0x0010U == (0x0018U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1 
        = (3U & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                  >> 3U) ^ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                            >> 6U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit_way0 
        = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
            [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                    >> 4U))] & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                                [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                        >> 4U))] == 
                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                 >> 7U))) | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint) 
                                             & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit_way1 
        = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U]
            [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                    >> 4U))] & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1
                                [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                        >> 4U))] == 
                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                 >> 7U))) | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint) 
                                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_paddr 
        = ((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
               >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                >> 3U)) == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                            >> 0x0000001dU)))
              ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg)
              : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                   >> 0x0000000dU) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                             >> 0x0000000aU)) 
                                      == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                          >> 0x0000001dU)))
                  ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                     >> 7U) : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                               >> 0x0000001dU))) << 0x0000001dU) 
           | (0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept 
        = ((IData)(asm_monitor_tb__DOT__bridge__DOT__ext_store_ready) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
              & (IData)(asm_monitor_tb__DOT__bridge__DOT__ext_data_req)));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant 
        = ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state)) 
           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid)) 
              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q)) 
                 & (IData)(asm_monitor_tb__DOT__bridge__DOT__ext_data_req))));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept 
        = ((IData)(asm_monitor_tb__DOT__bridge__DOT__base_store_ready) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
              & (IData)(asm_monitor_tb__DOT__bridge__DOT__base_data_req)));
    asm_monitor_tb__DOT__bridge__DOT__base_data_read 
        = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q)) 
           & (IData)(asm_monitor_tb__DOT__bridge__DOT__base_data_req));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go 
        = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken 
        = ((~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
               >> 2U)) & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken 
        = ((4U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out)
            ? (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1)
            : ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U]
                [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U]
                   [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                   == (0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                      >> 5U)))) & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[0U]
                                                   [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                                   >> 1U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_0 
           + ((7U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))
               ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0
               : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_53 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0) 
                                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0) 
                                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0)));
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT____VlemCall_0__cpucfg_result 
            = ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0))
                ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg)
                : ((0x0180U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0))
                    ? (0xee000039U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg)
                    : (0xee000039U & ((- (IData)((0x0181U 
                                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0)))) 
                                      & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg))));
    } else if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0) {
        vlSelfRef.__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__cpucfg_result__49__index 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0;
        __Vtemp_1 = VL_MATCHMASKED_I(32, vlSelfRef.__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__cpucfg_result__49__index, Vasm_monitor_tb__ConstPool__CONST_h98e43d88_0);
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT____VlemCall_0__cpucfg_result 
            = Vasm_monitor_tb__ConstPool__TABLE_heee294f4_0
            [__Vtemp_1];
    } else {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT____VlemCall_0__cpucfg_result 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT____VlemCall_0__cpucfg_result;
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)) 
            & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))) 
           | ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2)) 
                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__reset 
        = (1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)));
    asm_monitor_tb__DOT__bridge__DOT__ext_read_active 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant));
    if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) {
        vlSelfRef.asm_monitor_tb__DOT__ext_be_n = (0x0000000fU 
                                                   & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wstrb)));
        vlSelfRef.asm_monitor_tb__DOT__ext_addr = (0x000fffffU 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_addr 
                                                      >> 2U));
    } else {
        vlSelfRef.asm_monitor_tb__DOT__ext_be_n = (0x0000000fU 
                                                   & (- (IData)(
                                                                (1U 
                                                                 & (~ (IData)(asm_monitor_tb__DOT__bridge__DOT__ext_read_active))))));
        vlSelfRef.asm_monitor_tb__DOT__ext_addr = (0x000fffffU 
                                                   & ((- (IData)((IData)(asm_monitor_tb__DOT__bridge__DOT__ext_read_active))) 
                                                      & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant)
                                                          ? 
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                                                          >> 2U)
                                                          : 
                                                         (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg 
                                                          >> 2U))));
    }
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_inst 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_36) 
           & ((~ (IData)(asm_monitor_tb__DOT__bridge__DOT__base_data_read)) 
              & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_36) 
           & (IData)(asm_monitor_tb__DOT__bridge__DOT__base_data_read));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0)) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q 
        = ((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset))) 
           && (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane 
        = ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
           & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0) 
               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0 
                     != vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0))) 
              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                 ^ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0 
        = (1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_53) 
                    | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0) 
                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready)) 
            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__got_addr_ok 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data) 
            | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept) 
               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant) 
                  | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant) 
                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept))))) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_req));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_inst));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire 
        = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1) 
             & (IData)(__VdfgRegularize_h6e95ff9d_0_30)) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open 
        = (1U & ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1))) 
                 | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_eff_valid 
        = ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0))) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_pc_0 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2) 
            << 0x00000019U) | (0x01ffffffU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g1 
                                                      >> 0x00000014U))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0 
        = (IData)((0ULL != (0x0000000030400000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                      >> 0x00000029U)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                      >> 0x00000028U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__if_suspend 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall));
    asm_monitor_tb__DOT__bridge__DOT__base_read_active 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant));
    if (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain) {
        vlSelfRef.asm_monitor_tb__DOT__base_be_n = 
            (0x0000000fU & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wstrb)));
        vlSelfRef.asm_monitor_tb__DOT__base_addr = 
            (0x000fffffU & (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_addr 
                            >> 2U));
    } else {
        vlSelfRef.asm_monitor_tb__DOT__base_be_n = 
            (0x0000000fU & (- (IData)((1U & (~ (IData)(asm_monitor_tb__DOT__bridge__DOT__base_read_active))))));
        vlSelfRef.asm_monitor_tb__DOT__base_addr = 
            (0x000fffffU & ((- (IData)((IData)(asm_monitor_tb__DOT__bridge__DOT__base_read_active))) 
                            & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data)
                                ? (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                                   >> 2U) : ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_inst)
                                              ? (vlSelfRef.asm_monitor_tb__DOT__inst_addr 
                                                 >> 2U)
                                              : (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg 
                                                 >> 2U)))));
    }
    __VdfgRegularize_h6e95ff9d_0_52 = ((0U != (0x0000001fU 
                                               & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                          >> 8U)))) 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                  >> 4U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset 
        = (1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1)) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset 
        = (1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__resetn)));
    __VdfgRegularize_h6e95ff9d_0_42 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open));
    __VdfgRegularize_h6e95ff9d_0_41 = (1U & (((IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                       >> 0x00000027U)) 
                                              & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                         >> 0x00000027U))) 
                                             | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__load_wakeup_valid) 
           & ((~ ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                           >> 5U)) | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                               >> 3U)) 
                                      | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                  >> 0x00000027U)) 
                                         | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0))))) 
              & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                         >> 4U))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
           & ((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
           & ((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0) 
                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0)) 
                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0))))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0))));
    __VdfgRegularize_h6e95ff9d_0_50 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_5));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1)))));
    __VdfgRegularize_h6e95ff9d_0_51 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
           & ((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
           & ((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0) 
                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0)) 
                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0) 
                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))));
    __VdfgRegularize_h6e95ff9d_0_48 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_5));
    __VdfgRegularize_h6e95ff9d_0_49 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_valid 
        = (1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_pc__DOT__reset) 
                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__if_suspend))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush 
        = ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)) 
           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__cacop_flush)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ds_mul_src1_0 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)) 
            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms1))
            ? asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0) 
                & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms0))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0
                : (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                      == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0)) 
                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                        [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r])) 
                   & (- (IData)((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r)))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_50) 
            & ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume)))) 
           | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_51) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_51) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ds_mul_src2_0 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)) 
            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms1))
            ? asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0) 
                & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms0))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0
                : (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                      == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                        [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0])) 
                   & (- (IData)((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_48) 
           & ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_48) 
           & ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_49) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_49) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))));
    __VdfgRegularize_h6e95ff9d_0_43 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_res_from_mem_0) 
                                       & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_pred_taken 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_valid) 
           & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken) 
              | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[0U] 
        = (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[1U] 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1) 
            << 0x0000000dU) | (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 
                                       >> 0x00000020U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[2U] 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2) 
            << 0x0000001aU) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1) 
                                >> 0x00000013U) | ((IData)(
                                                           (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1 
                                                            >> 0x00000020U)) 
                                                   << 0x0000000dU)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[3U] 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2) 
            >> 6U) | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                               >> 0x00000020U)) << 0x0000001aU));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[4U] 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3) 
            << 7U) | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                               >> 0x00000020U)) >> 6U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[5U] 
        = ((0xfff00000U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[5U]) 
           | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3) 
               >> 0x00000019U) | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                           >> 0x00000020U)) 
                                  << 7U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[5U] 
        = ((0x000fffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[5U]) 
           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4) 
              << 0x00000014U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[6U] 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4) 
            >> 0x0000000cU) | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                                        >> 0x00000020U)) 
                               << 0x00000014U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[7U] 
        = (((0x000ffffeU & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5) 
                            << 1U)) | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                                                >> 0x00000020U)) 
                                       >> 0x0000000cU)) 
           | (0xfff00000U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5) 
                             << 1U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[8U] 
        = (0x000003ffU & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5) 
                           >> 0x0000001fU) | (0x000ffffeU 
                                              & ((IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                          >> 0x00000020U)) 
                                                 << 1U))));
    __VdfgRegularize_h6e95ff9d_0_26 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0) 
                                          == (0x0000001fU 
                                              & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                         >> 0x0000000dU)))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1 
        = (IData)((0ULL != (0x0000000000000028ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid 
        = ((0U != (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                          >> 0x0000000dU)))) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                      >> 0x00000028U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1 
        = ((0x0000001eU & ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                    >> 0x00000013U)) 
                           << 1U)) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_1_hot_bit0_r));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0) 
           & ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1) 
                  | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms1) 
                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0)))) 
              & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms0)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1))
            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0
                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ds_mul_src1_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0) 
           | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
           | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0) 
           & ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1) 
                  | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms1) 
                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0)))) 
              & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms0)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd_value_0 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1))
            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0
                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ds_mul_src2_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1) 
           | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
            & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok 
        = ((((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex)) 
             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
                & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0))) 
            | (IData)(__VdfgRegularize_h6e95ff9d_0_43)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                      >> 3U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume 
        = ((((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex)) 
             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume))) 
            | (IData)(__VdfgRegularize_h6e95ff9d_0_43)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                      >> 3U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_taken_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_pred_taken) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_target_0 
        = (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane)
             ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U]
            [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]
             : ((4U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out)
                 ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U]
                [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]
                 : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[0U]
                [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row])) 
           & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_pred_taken))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__lane1_capable 
        = (1U & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1) 
                 | (((~ ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                  >> 0x00000027U)) 
                         | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1) 
                            | ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                        >> 2U)) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1))))) 
                     & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                >> 4U))) | (((~ (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                         >> 2U))) 
                                             & ((~ 
                                                 (0U 
                                                  != 
                                                  (3U 
                                                   & (IData)(
                                                             (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                              >> 0x0000001fU))))) 
                                                & (IData)(
                                                          (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                           >> 0x00000027U)))) 
                                            | ((IData)(
                                                       (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                        >> 2U)) 
                                               & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                          >> 2U)))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src2_1 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)) 
            & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
               & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                  & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1) 
                      == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                 >> 0x0000000dU)))) 
                     & (IData)(__VdfgRegularize_h6e95ff9d_0_7)))))
            ? asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0) 
                & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                   & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                      & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                          == (0x0000001fU & (IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                     >> 0x0000000dU)))) 
                         & (IData)(__VdfgRegularize_h6e95ff9d_0_3)))))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0
                : (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                      == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                 >> 0x0000000dU)))) 
                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                          == (0x0000001fU & (IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                     >> 0x0000000dU)))) 
                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                        [(0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                 >> 0x0000000dU)))])) 
                   & (- (IData)((0U != (0x0000001fU 
                                        & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                   >> 0x0000000dU)))))))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0) 
                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0)) 
                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0) 
                       == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                  >> 0x0000000dU))))))));
    __VdfgRegularize_h6e95ff9d_0_44 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_5));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1) 
                    == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                               >> 0x0000000dU)))))));
    __VdfgRegularize_h6e95ff9d_0_45 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    __VdfgRegularize_h6e95ff9d_0_25 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                      >> 0x00000029U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0 
        = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                          >> 7U))) ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_pc_0
            : asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0 
        = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                          >> 0x00000020U))) ? asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd_value_0);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex 
        = ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__special_block) 
               | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                  | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1) 
                     | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait) 
                        | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1)) 
                           | (((IData)(__VdfgRegularize_h6e95ff9d_0_50) 
                               & ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                     == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0)))) 
                              | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait)) 
                                 | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                      & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1) 
                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1))) 
                                     | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0) 
                                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0)))) 
                                    & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                               >> 2U))))))))))) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_42));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume 
        = ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__special_block) 
               | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                  | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume) 
                     | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume) 
                        | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                            & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume)) 
                           | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume)) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume)) 
                              | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                   & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume) 
                                      | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume))) 
                                  | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume) 
                                     & (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
                                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                            & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                               & ((0U 
                                                   != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                                     == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))))) 
                                        | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                                 & ((0U 
                                                     != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume))))))))) 
                                 & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                            >> 2U)))))))))) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_42));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume 
        = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
             == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                        >> 0x0000000dU)))) 
            & (IData)(__VdfgRegularize_h6e95ff9d_0_44)) 
           | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_45) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1) 
                 == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                            >> 0x0000000dU))))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_45) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume) 
                 == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                            >> 0x0000000dU))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src1_1 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)) 
            & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
               & ((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
                  & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                     & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1) 
                        == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1))))))
            ? asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0) 
                & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                   & ((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
                      & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                            == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1))))))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0
                : (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                      == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)) 
                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)) 
                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                        [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1])) 
                   & (- (IData)((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)))))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0) 
                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0)) 
                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0) 
                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1))))));
    __VdfgRegularize_h6e95ff9d_0_28 = (1U & (~ ((((
                                                   (0x0000001fU 
                                                    & (IData)(
                                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                               >> 0x0000000dU))) 
                                                   == 
                                                   (0x0000001fU 
                                                    & (IData)(
                                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                               >> 8U)))) 
                                                  & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid)) 
                                                 | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1) 
                                                     == 
                                                     (0x0000001fU 
                                                      & (IData)(
                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                 >> 8U)))) 
                                                    & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid))) 
                                                & (IData)(__VdfgRegularize_h6e95ff9d_0_52))));
    __VdfgRegularize_h6e95ff9d_0_46 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_5));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)))));
    __VdfgRegularize_h6e95ff9d_0_47 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__capture_ex_wait_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
           & (((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                        >> 5U)) | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0)) 
              & (IData)(__VdfgRegularize_h6e95ff9d_0_52)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0 
        = (1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r)) 
                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
            & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1))
            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0
                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src2_1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume 
        = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
             == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)) 
            & (IData)(__VdfgRegularize_h6e95ff9d_0_46)) 
           | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_47) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_47) 
           & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume)) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume) 
                 == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
              & ((IData)(__VdfgRegularize_h6e95ff9d_0_28) 
                 & ((~ ((((IData)(__VdfgRegularize_h6e95ff9d_0_25) 
                          | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1)) 
                             | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)) 
                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_46)) 
                                | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1)))) 
                         & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid)) 
                        | ((((IData)(__VdfgRegularize_h6e95ff9d_0_26) 
                             | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1)) 
                                | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                     == (0x0000001fU 
                                         & (IData)(
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                    >> 0x0000000dU)))) 
                                    & (IData)(__VdfgRegularize_h6e95ff9d_0_44)) 
                                   | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1)))) 
                            & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid)) 
                           | (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                 & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))) 
                                | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                   & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0)))) 
                               & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                          >> 2U))) 
                              | (IData)(__VdfgRegularize_h6e95ff9d_0_41))))) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__lane1_capable)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
              & ((IData)(__VdfgRegularize_h6e95ff9d_0_28) 
                 & ((~ ((IData)(__VdfgRegularize_h6e95ff9d_0_41) 
                        | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume) 
                           | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                               & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume)) 
                              | (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                  & (IData)(__VdfgRegularize_h6e95ff9d_0_25)) 
                                 | (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                       & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume) 
                                          | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume))) 
                                      | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume) 
                                         & (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                                   & ((0U 
                                                       != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                      & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                                         == 
                                                         (0x0000001fU 
                                                          & (IData)(
                                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                                     >> 0x0000000dU)))))))) 
                                            | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                                     & ((0U 
                                                         != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                                           == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1))))))))) 
                                     & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                >> 2U))) 
                                    | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                        & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume)) 
                                       | (((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                           & (IData)(__VdfgRegularize_h6e95ff9d_0_26)) 
                                          | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume))))))))) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__lane1_capable)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a 
        = (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume) 
                 | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume)) 
                     & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r)) 
                        | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r)) 
                           & (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt))))) 
                    | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r)) 
                        | (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt))) 
                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_23 = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume) 
                                                  << 4U) 
                                                 | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt) 
                                                     << 1U) 
                                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume)) 
                                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r));
    asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_load_fifo1_g0 
        = (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume) 
                 | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume)) 
                     & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r))) 
                    | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r)) 
                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_54 = (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_23) 
                                                  << 2U) 
                                                 | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
                                                     << 1U) 
                                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r)));
    if (vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[0U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[1U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[2U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[3U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[3U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[4U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[4U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[5U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[5U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[6U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[6U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[7U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[7U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[8U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r[8U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next 
            = (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                      >> 0x0000000dU)));
    } else {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[0U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][0U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[1U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][1U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[2U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][2U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[3U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][3U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[4U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[5U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][5U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[6U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][6U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[7U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][7U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next[8U] 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][8U];
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next 
            = (0x0000001fU & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                               [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                               << 0x0000000cU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                  [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                                                  >> 0x00000014U)));
    }
    if (asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_load_fifo1_g0) {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [
                                                         (3U 
                                                          & ((IData)(1U) 
                                                             + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][1U])) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                          [
                                                          (3U 
                                                           & ((IData)(1U) 
                                                              + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][0U]))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [
                                                         (3U 
                                                          & ((IData)(1U) 
                                                             + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][2U])) 
                                         << 0x00000033U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [
                                                            (3U 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][2U])) 
                                            << 0x00000013U) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [
                                                              (3U 
                                                               & ((IData)(1U) 
                                                                  + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][1U])) 
                                              >> 0x0000000dU))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [
                                                         (3U 
                                                          & ((IData)(1U) 
                                                             + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][4U])) 
                                         << 0x00000026U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [
                                                            (3U 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][3U])) 
                                            << 6U) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [
                                                              (3U 
                                                               & ((IData)(1U) 
                                                                  + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][2U])) 
                                              >> 0x0000001aU))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [
                                                         (3U 
                                                          & ((IData)(1U) 
                                                             + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][5U])) 
                                         << 0x00000039U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [
                                                            (3U 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][5U])) 
                                            << 0x00000019U) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [
                                                              (3U 
                                                               & ((IData)(1U) 
                                                                  + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][4U])) 
                                              >> 7U))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [
                                                         (3U 
                                                          & ((IData)(1U) 
                                                             + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][7U])) 
                                         << 0x0000002cU) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [
                                                            (3U 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][6U])) 
                                            << 0x0000000cU) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [
                                                              (3U 
                                                               & ((IData)(1U) 
                                                                  + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][5U])) 
                                              >> 0x00000014U))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5 
            = (0x000001ffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [
                                                         (3U 
                                                          & ((IData)(1U) 
                                                             + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][8U])) 
                                         << 0x0000003fU) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [
                                                            (3U 
                                                             & ((IData)(1U) 
                                                                + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][8U])) 
                                            << 0x0000001fU) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [
                                                              (3U 
                                                               & ((IData)(1U) 
                                                                  + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))][7U])) 
                                              >> 1U))));
    } else {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][1U])) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                          [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][0U]))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][2U])) 
                                         << 0x00000033U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][2U])) 
                                            << 0x00000013U) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][1U])) 
                                              >> 0x0000000dU))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U])) 
                                         << 0x00000026U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][3U])) 
                                            << 6U) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][2U])) 
                                              >> 0x0000001aU))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][5U])) 
                                         << 0x00000039U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][5U])) 
                                            << 0x00000019U) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U])) 
                                              >> 7U))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4 
            = (0x00001fffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][7U])) 
                                         << 0x0000002cU) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][6U])) 
                                            << 0x0000000cU) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][5U])) 
                                              >> 0x00000014U))));
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5 
            = (0x000001ffffffffffULL & (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                         [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][8U])) 
                                         << 0x0000003fU) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][8U])) 
                                            << 0x0000001fU) 
                                           | ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][7U])) 
                                              >> 1U))));
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
                Vasm_monitor_tb___024root___act_comb__TOP__0(vlSelf);
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

void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(Vasm_monitor_tb_inst_decoder* vlSelf);
void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(Vasm_monitor_tb_inst_decoder* vlSelf);

bool Vasm_monitor_tb___024root___eval_phase__nba(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_phase__nba\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vasm_monitor_tb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vasm_monitor_tb___024root___nba_sequent__TOP__0(vlSelf);
                Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0((&vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0));
                Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0((&vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1));
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vasm_monitor_tb___024root___act_comb__TOP__0(vlSelf);
            }
        }
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
