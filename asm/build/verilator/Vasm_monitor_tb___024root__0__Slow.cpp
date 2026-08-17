// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

void Vasm_monitor_tb___024root___timing_ready(Vasm_monitor_tb___024root* vlSelf);

VL_ATTR_COLD void Vasm_monitor_tb___024root___eval_static(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_static\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        CData/*7:0*/ __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte;
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte = 0;
        SData/*15:0*/ __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half;
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half = 0;
        CData/*7:0*/ __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte;
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte = 0;
        SData/*15:0*/ __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half;
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half = 0;
        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
        vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14394767476492600028ull);
        vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4164927560133606186ull);
        vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 91451409018211322ull);
        vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__value = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6323985797446257105ull);
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte = 0;
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half = 0;
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte = 0;
        __Vinline_0__eval_static__TOP_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half = 0;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0 
        = vlSelfRef.asm_monitor_tb__DOT__clk;
    Vasm_monitor_tb___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vasm_monitor_tb___024root___eval_final(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_final\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vasm_monitor_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vasm_monitor_tb___024root___eval_phase__stl(Vasm_monitor_tb___024root* vlSelf);

VL_ATTR_COLD void Vasm_monitor_tb___024root___eval_settle(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_settle\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vasm_monitor_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/qianfu/Mycpu/asm/sim/asm_monitor_tb.v", 5, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vasm_monitor_tb___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vasm_monitor_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vasm_monitor_tb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vasm_monitor_tb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vasm_monitor_tb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___trigger_anySet__stl\n"); );
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

extern const VlWide<10>/*319:0*/ Vasm_monitor_tb__ConstPool__CONST_h98e43d88_0;
extern const VlUnpacked<IData/*31:0*/, 5> Vasm_monitor_tb__ConstPool__TABLE_heee294f4_0;

VL_ATTR_COLD void Vasm_monitor_tb___024root___stl_sequent__TOP__0(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___stl_sequent__TOP__0\n"); );
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
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_6;
    __VdfgRegularize_h6e95ff9d_0_6 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_22;
    __VdfgRegularize_h6e95ff9d_0_22 = 0;
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
    IData/*31:0*/ __Vtemp_5;
    // Body
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_direct 
        = ((0U == (7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code))) 
           & ((0U == (3U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code) 
                            >> 3U))) | (1U == (3U & 
                                               ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code) 
                                                >> 3U)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit 
        = (IData)((0x10U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1 
           + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_1);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1 
        = (1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0) 
                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1))));
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
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_inst_data_ok 
        = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data)) 
           & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__icacop_req_valid 
        = (IData)((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
                    >> 1U) & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending)))));
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
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_exec_tx_write 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr) 
           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab)) 
              & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_hit_s2 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_valid_s2) 
           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_tag_s2 
              == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U]
           [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1
              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
              == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0) 
           & (2U >= (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1) 
           & (2U >= (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_pc_0 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2) 
            << 0x00000019U) | (0x01ffffffU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g1 
                                                      >> 0x00000014U))));
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
           == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed 
        = VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
           < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1);
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q) {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_1;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_1;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_1;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_1;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_1;
    } else {
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_0;
        asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_0;
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_sign_ext 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_half 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0;
        __Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__53__ld_byte 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next 
        = (0x000001ffU & (((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)) 
                           & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr)))
                           ? (((~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg)) 
                              | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data 
                                 & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask))
                           : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_53 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0) 
                                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0) 
                                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0)));
    __VdfgRegularize_h6e95ff9d_0_22 = (vlSelfRef.asm_monitor_tb__DOT__program_addr 
                                       + (vlSelfRef.asm_monitor_tb__DOT__program_words 
                                          << 2U));
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
    __VdfgRegularize_h6e95ff9d_0_39 = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)));
    __VdfgRegularize_h6e95ff9d_0_38 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                       & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0)) 
                                          & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_0 
           + ((7U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))
               ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0
               : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0));
    __VdfgRegularize_h6e95ff9d_0_31 = (0xee000039U 
                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data 
                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask));
    asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint 
        = ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
           & (((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                      >> 4U)) == (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                        >> 4U))) & 
              ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                >> 7U) == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                           >> 7U))));
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
           == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed 
        = VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
           < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0);
    __VdfgRegularize_h6e95ff9d_0_30 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1));
    __VdfgRegularize_h6e95ff9d_0_29 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__bpu_sel_lane1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1) 
           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0)) 
              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold 
        = ((2U < (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt)) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0) 
              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1)));
    vlSelfRef.asm_monitor_tb__DOT__inst_addr = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_base_addr 
                                                + ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat) 
                                                   << 2U));
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
           | vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1);
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
           | vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0);
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_resp_valid) 
           | (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16 = ((0x16U 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000001aU)) 
                                                 | (0x17U 
                                                    == 
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x0000001aU)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_21 = ((0x16U 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000001aU)) 
                                                 | (0x17U 
                                                    == 
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x0000001aU)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1 
        = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1))))));
    __VdfgRegularize_h6e95ff9d_0_26 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0) 
                                          == (0x0000001fU 
                                              & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                         >> 0x0000000dU)))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1 
        = (IData)((0ULL != (0x0000000000000028ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1 
        = (IData)((0ULL != (0x0000000030400000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_1) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_1));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row 
        = (3U & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                  >> 3U) ^ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                            >> 6U)));
    __VdfgRegularize_h6e95ff9d_0_52 = ((0U != (0x0000001fU 
                                               & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                          >> 8U)))) 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                  >> 4U)));
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
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_resp_valid) 
           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data) 
              & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state))));
    __VdfgRegularize_h6e95ff9d_0_7 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1));
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
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = (IData)(
                                                        (0x00400000U 
                                                         == 
                                                         (0xfff00000U 
                                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19 = (IData)(
                                                        (0x00400000U 
                                                         == 
                                                         (0xfff00000U 
                                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    __VdfgRegularize_h6e95ff9d_0_3 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl));
    __VdfgRegularize_h6e95ff9d_0_36 = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid)) 
                                       & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)));
    asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready 
        = (1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0))));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid) 
           & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state)));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid) 
           & (0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_0 = (IData)(
                                                       (0x00100000U 
                                                        == 
                                                        (0xfff00000U 
                                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = (IData)(
                                                       (0x00100000U 
                                                        == 
                                                        (0xfff00000U 
                                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid 
        = ((0U != (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                          >> 0x0000000dU)))) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                      >> 0x00000028U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0 
        = (IData)((0ULL != (0x0000000030400000ULL & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2)));
    __VdfgRegularize_h6e95ff9d_0_6 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_1) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_1));
    asm_monitor_tb__DOT__data_fast_ready = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg) 
                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0) 
           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0)) 
              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                      >> 0x00000029U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1 
        = ((0x0000001eU & ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                    >> 0x00000013U)) 
                           << 1U)) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_1_hot_bit0_r));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__4__03a2__KET__) 
            << 2U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit1_r) 
                       << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit0_r)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1)
            ? 2U : (1U & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0)))));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode 
        = (IData)((0x0010U == (0x0018U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0 
        = (1U & (~ ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_53) 
                    | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0) 
                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0)))));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_29));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_29) 
           | (IData)(__VdfgRegularize_h6e95ff9d_0_30));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_38) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1) 
              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0)))));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1 
        = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U]
            [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U]
               [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
               == (0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                  >> 5U)))) & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[1U]
                                               [asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                               >> 1U));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_res_from_mem_0)
            ? asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_load_result_0
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0);
    vlSelfRef.asm_monitor_tb__DOT__data_data_ok = ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok) 
                                                   | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid) 
                                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0)
            ? asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_load_result_0_fwd
            : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
               & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0)))));
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
    __VdfgRegularize_h6e95ff9d_0_40 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_3));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1));
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
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0) 
                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0)) 
                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0) 
                       == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                  >> 0x0000000dU))))))));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1) 
                    == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                               >> 0x0000000dU)))))));
    vlSelfRef.asm_monitor_tb__DOT__data_req = (1U & 
                                               ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
                                                & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending)) 
                                                   & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid)) 
                                                      & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q)) 
                                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready))))));
    __VdfgRegularize_h6e95ff9d_0_41 = (1U & (((IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                       >> 0x00000027U)) 
                                              & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                         >> 0x00000027U))) 
                                             | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0)));
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
    __VdfgRegularize_h6e95ff9d_0_45 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting) 
           & (IData)(asm_monitor_tb__DOT__data_fast_ready));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__load_wakeup_valid 
        = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)) 
           & (IData)(asm_monitor_tb__DOT__data_fast_ready));
    __VdfgRegularize_h6e95ff9d_0_5 = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0)) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_0));
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
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1) 
                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1)))));
    __VdfgRegularize_h6e95ff9d_0_51 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_6));
    __VdfgRegularize_h6e95ff9d_0_25 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                      >> 0x00000029U)));
    asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
           & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                      >> 0x00000028U)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
           & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0) 
               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0 
                     != vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0))) 
              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                 ^ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1 
        = (3U & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                  >> 3U) ^ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc 
                            >> 6U)));
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
        __Vtemp_5 = VL_MATCHMASKED_I(32, vlSelfRef.__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__cpucfg_result__49__index, Vasm_monitor_tb__ConstPool__CONST_h98e43d88_0);
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT____VlemCall_0__cpucfg_result 
            = Vasm_monitor_tb__ConstPool__TABLE_heee294f4_0
            [__Vtemp_5];
    } else {
        vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT____VlemCall_0__cpucfg_result 
            = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0;
    }
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0 
        = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT____VlemCall_0__cpucfg_result;
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_ok 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_data_ok));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__store_inv_valid 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__data_data_ok) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid) 
              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_store) 
                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_is_base))));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_40) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0) 
              & (IData)(__VdfgRegularize_h6e95ff9d_0_39)));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0)) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1)) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant 
        = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
            >> 0x00000018U) & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending)) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_req)));
    __VdfgRegularize_h6e95ff9d_0_37 = ((~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr 
                                           >> 0x00000018U)) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__data_req));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_40) 
           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
              & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready) 
                 & (IData)(__VdfgRegularize_h6e95ff9d_0_39))));
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
    __VdfgRegularize_h6e95ff9d_0_44 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_5));
    __VdfgRegularize_h6e95ff9d_0_50 = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_5));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_eff_valid 
        = ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0) 
               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0))) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1));
    asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane 
        = ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
            & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1))
            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1
            : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0))
                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0
                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src2_1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
    asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go 
        = ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume 
        = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
             == (0x0000001fU & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                        >> 0x0000000dU)))) 
            & (IData)(__VdfgRegularize_h6e95ff9d_0_44)) 
           | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_50) 
            & ((~ (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume)))) 
           | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1 
        = ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire 
        = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1) 
             & (IData)(__VdfgRegularize_h6e95ff9d_0_30)) 
            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw)) 
           & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__cacop_flush 
        = (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
            >> 1U) & (IData)(asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1) 
           & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open 
        = (1U & ((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1))) 
                 | ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready) 
                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go))));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0 
        = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                          >> 7U))) ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_pc_0
            : asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0);
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)) 
            & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))) 
           | ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2)) 
                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit))));
    asm_monitor_tb__DOT__bridge__DOT__ext_read_active 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_inst 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_36) 
           & ((~ (IData)(asm_monitor_tb__DOT__bridge__DOT__base_data_read)) 
              & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))));
    vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_36) 
           & (IData)(asm_monitor_tb__DOT__bridge__DOT__base_data_read));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pipeline_flush 
        = ((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)) 
           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q) 
              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__cacop_flush)));
    __VdfgRegularize_h6e95ff9d_0_42 = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                                       & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0 
        = ((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                          >> 0x00000020U))) ? asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0
            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd_value_0);
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall 
        = (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready)) 
            & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__if_suspend 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall));
    asm_monitor_tb__DOT__bridge__DOT__base_read_active 
        = ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state)) 
           | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant));
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__capture_ex_wait_0 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex) 
           & (((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                        >> 5U)) | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0)) 
              & (IData)(__VdfgRegularize_h6e95ff9d_0_52)));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0 
        = (1U & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r)) 
                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume)));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_valid 
        = (1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_pc__DOT__reset) 
                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__if_suspend))));
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
    vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__bpu_pred_taken 
        = ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_valid) 
           & ((IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken) 
              | (IData)(asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken)));
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

void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(Vasm_monitor_tb_inst_decoder* vlSelf);
void Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(Vasm_monitor_tb_inst_decoder* vlSelf);

VL_ATTR_COLD bool Vasm_monitor_tb___024root___eval_phase__stl(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___eval_phase__stl\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vasm_monitor_tb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vasm_monitor_tb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vasm_monitor_tb___024root___stl_sequent__TOP__0(vlSelf);
                Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0((&vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0));
                Vasm_monitor_tb_inst_decoder___nba_sequent__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0((&vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1));
            }
        }
    }
    return (__VstlExecute);
}

bool Vasm_monitor_tb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vasm_monitor_tb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vasm_monitor_tb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge asm_monitor_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge asm_monitor_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vasm_monitor_tb___024root___ctor_var_reset(Vasm_monitor_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root___ctor_var_reset\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->asm_monitor_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5555004365196235567ull);
    vlSelf->asm_monitor_tb__DOT__resetn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10224524559087289581ull);
    vlSelf->asm_monitor_tb__DOT__inst_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18062068772232485194ull);
    vlSelf->asm_monitor_tb__DOT__data_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11752083798289618719ull);
    vlSelf->asm_monitor_tb__DOT__data_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15923726431200490106ull);
    vlSelf->asm_monitor_tb__DOT__data_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8854165598243874512ull);
    vlSelf->asm_monitor_tb__DOT__data_data_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2756885829736052390ull);
    vlSelf->asm_monitor_tb__DOT__base_addr = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 11036713576813705435ull);
    vlSelf->asm_monitor_tb__DOT__ext_addr = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 5392366308053589317ull);
    vlSelf->asm_monitor_tb__DOT__base_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3727648451844991495ull);
    vlSelf->asm_monitor_tb__DOT__ext_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16672808138717528132ull);
    vlSelf->asm_monitor_tb__DOT__base_be_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2238493261706382714ull);
    vlSelf->asm_monitor_tb__DOT__ext_be_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5263739258879008749ull);
    vlSelf->asm_monitor_tb__DOT__uart_rx_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8779495847027562416ull);
    vlSelf->asm_monitor_tb__DOT__uart_rx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7515538535221610009ull);
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__base_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4143767491829162723ull);
    }
    for (int __Vi0 = 0; __Vi0 < 1048576; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__ext_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10699554381385372061ull);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__program_mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3648331146500970011ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__tx_bytes[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14788479299368958850ull);
    }
    vlSelf->asm_monitor_tb__DOT__tx_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11948302452725500725ull);
    vlSelf->asm_monitor_tb__DOT__base_words = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1695581243662536403ull);
    vlSelf->asm_monitor_tb__DOT__program_words = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15606080162037712386ull);
    vlSelf->asm_monitor_tb__DOT__watch_words = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7133947247798845696ull);
    vlSelf->asm_monitor_tb__DOT__entry_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7349306932160455873ull);
    vlSelf->asm_monitor_tb__DOT__program_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16810720696194314771ull);
    vlSelf->asm_monitor_tb__DOT__watch_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5632595386421959705ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->asm_monitor_tb__DOT__base_file, __VscopeHash, 7534418594652057164ull);
    VL_SCOPED_RAND_RESET_W(1024, vlSelf->asm_monitor_tb__DOT__program_file, __VscopeHash, 418757321192537078ull);
    vlSelf->asm_monitor_tb__DOT__cycle_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17758228177198114639ull);
    vlSelf->asm_monitor_tb__DOT__max_cycles = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3023904507160831733ull);
    vlSelf->asm_monitor_tb__DOT__counting = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17575303985465168ull);
    vlSelf->asm_monitor_tb__DOT__exit_seen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8514017704199202841ull);
    vlSelf->asm_monitor_tb__DOT__benchmark_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2678984766131636924ull);
    vlSelf->asm_monitor_tb__DOT__exit_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11777012732848755112ull);
    vlSelf->asm_monitor_tb__DOT__benchmark_cycles = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1872135188092017557ull);
    vlSelf->asm_monitor_tb__DOT__commit_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11139365840099237237ull);
    vlSelf->asm_monitor_tb__DOT__write_count = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1700463620972517888ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__write_addr_log[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4330175155909962476ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__write_data_log[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9930042501912886806ull);
    }
    vlSelf->asm_monitor_tb__DOT__write_log_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7081710971281440736ull);
    vlSelf->asm_monitor_tb__DOT__program_exit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12764219335086835942ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10669880129850834888ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__es_to_ms_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16524027667247113817ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 159762254968887884ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__ms_to_ws_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8562455832346757067ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__ds_mul_src1_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18301096693483908943ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__ds_mul_src2_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13541533173785359125ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__load_wakeup_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4557232803550751915ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__special_block = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7266440397282161213ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__cacop_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5705879236484378278ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__pipeline_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4434004321413207994ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__bpu_pred_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12446398854842080979ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__bpu_ex_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12377499651806238649ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__bpu_ex_real_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5014907917942981350ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__icacop_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7017003619048849539ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__store_inv_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4761352707003463576ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__pc_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12388560566506636057ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__if_suspend = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10238118095859903299ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(266, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo[__Vi0], __VscopeHash, 15751325688516413954ull);
    }
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6639772443267962516ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6892222254306698586ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10833297899531620187ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1881743311869588195ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11307668540857610800ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 1541315819651042563ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g1 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 16318424412380577511ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 16923300212516835031ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 5864591404988170016ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 16866642002783359768ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 = VL_SCOPED_RAND_RESET_Q(41, __VscopeHash, 5807933195254687985ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 2937033573803295135ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 14377312303492136693ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 10929944640120429738ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 2131128615427982259ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 6565538109569290409ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 = VL_SCOPED_RAND_RESET_Q(41, __VscopeHash, 3541909373939520319ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5811999476249356645ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__4__03a2__KET__ = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7230145566471933210ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12146112474704261659ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3450549224206742449ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_1_hot_bit0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9256800392032961372ull);
    VL_SCOPED_RAND_RESET_W(266, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_r, __VscopeHash, 7305778410999047782ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2174576321893604651ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 15410097249484651516ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 6709627065952845385ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 9174295229274098149ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 15682124519832101866ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4 = VL_SCOPED_RAND_RESET_Q(45, __VscopeHash, 6840119611798730996ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5 = VL_SCOPED_RAND_RESET_Q(41, __VscopeHash, 16921977739052008696ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15087547143691791442ull);
    VL_SCOPED_RAND_RESET_W(266, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next, __VscopeHash, 2364125070038014456ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13550593083129100770ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13235150704430609482ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6706966615421075535ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8222262752893037976ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13435366104181248484ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14166635941930189715ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9142766878570655289ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 12803654589708811387ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9184302686462699129ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14311558548445135397ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2328965767781413832ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15354979157452458001ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4269351253876628358ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8204058251248110658ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11941726256898143362ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13430560878497251765ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6823390243879261946ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11079925263028125122ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_cnt_0 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8068834847565176811ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14617610605401105216ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15016176440976777409ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17694337269722722180ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13366666599188357445ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12266122718044481107ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6329974510146282835ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7099022865630954329ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13557299812936389784ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11976216470434636356ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1265556137724627762ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 843241571864692648ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10095527149889468456ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1037291952111516222ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11655695996958602883ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16842072445766285298ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_cacop_code_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11902877065410058749ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6881622629495612114ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0 = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 17245653987358271402ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3127544307276790235ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9882703528961135338ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1925785696762934919ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4386094489271410292ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1 = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 9238549331631622074ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17335702068020261595ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10953046959345120274ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10875925833684056976ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15501224221578352716ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9064463519444573864ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1064532439994981507ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12770373805985363512ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9194967681453553899ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12843397294128183714ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6474191865813732943ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8934313353903956846ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7174169745545048473ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13444330124530045319ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6948352660908772432ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18042608201309921877ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4721632018432002294ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7289884415918252309ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_pc_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9249559353589858716ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8908561761338365990ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2432413362329681802ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3705820720991944274ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13421995902741008337ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7750396224177383887ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1816423085650386321ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18032426971653665399ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13724231512339010164ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3370274618128449031ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 301133041030476704ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15181826724614017617ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2663635211223960410ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5600552440291639114ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13697449548300334422ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9892601047614643889ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2258059076018389042ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17373437759436107493ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src1_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15453396327502968433ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_src2_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12872613838845103181ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13375533702537865618ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15447327377906967233ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15010243696308328886ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11654632642233289060ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11772361849676497454ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18110697885188398095ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src_raddr1_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9318995103348018852ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 65974998387980250ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 321338888332208239ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4271558673927115312ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8510877082674167344ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1384314569239124812ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15960456194757907725ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8770846430685074979ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5636859229622560739ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12830150682513047584ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7435427818223838176ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17536667960640135739ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_res_from_mem_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8250393397371442797ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6746359125980082830ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5681853819562599822ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 744420533650776309ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 40245607903995138ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10940296816897987246ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5190623823409371941ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14698109122475913472ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14023949649052514988ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1930515428384416467ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10516038659228234364ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13499088213100120862ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7557821349419199093ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4146386006541095187ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9360035102670844399ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17634143312614069838ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2016701280187875868ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10015349637803816183ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15998463357999655778ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11003409565634090664ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6864115445679716033ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6238273591650756124ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd_value_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12970709860352328610ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12065802156429854250ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13100525135793750115ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5898311966241810589ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9358518296412529365ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1024307294453176895ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4882599717421203621ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11858300919796660162ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9168141143743252029ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7240324524468059765ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16341050902062801195ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11645642933301100808ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14392362211561301848ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5128029497495518143ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__lane1_capable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7350516995699120538ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue_window_open = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17780875816396543058ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15555643892059931411ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_ex = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5740932937048688713ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue0_fire_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11369416579978329387ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__issue1_fire_for_consume = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6339056599682383632ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__capture_ex_wait_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17325265772870462674ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11216219885291825886ull);
    }
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 6136639350002155319ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 5932784974804677716ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 1100577698063029772ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8052662749459608946ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_base_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7141402718703706855ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16889791825309382704ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15740581329581931130ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14942097418918436320ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 378966397027863152ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8319242573037872056ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7327661490117215091ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_pc_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3877555365290821235ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8172436460684952288ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_mem_result_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2018751900237399907ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_res_from_mem_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7291346899652910379ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14246907680344715612ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6911506783203013389ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_byte_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11658146796635278022ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_half_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12126745622759740386ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_sign_ext_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2971501300608872885ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_is_csr_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 406965492754902684ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_num_0 = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 1591439627880678835ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wmask_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8511025452601547361ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wvalue_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7425997619567115151ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4583712476014881237ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11519068568989748757ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17726802669695608518ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7970665784606629046ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15139357332669514140ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 8364948105947118216ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18226160577392996337ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13148920793489376642ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16125860597520164415ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13586028072540718134ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1411476667505182683ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8501935710384288534ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13018339090690536829ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7070971682277814273ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2272863774545215802ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17774269526669409072ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12574397068360718906ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11656199112484413697ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8348427229986569685ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7533771061141813096ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8748970480567426093ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3319379205666500018ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5232124736569767929ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1332214001953109855ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3589421604555942913ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17938864052409854988ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5665816476056877036ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9018163133240270968ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13227800946967800932ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10937970305279561735ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17294345289376532871ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14631227588795676667ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_cacop_code_0 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10600071908356597288ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5742230822396338027ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0 = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 16744941216283440267ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9033493910921257627ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16912863221109368512ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3268487104358562628ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15691091334241024322ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9000719383657051436ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3778020653734215279ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6005909757529588730ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4606916591612387450ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12966579689823159372ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9851777756977771554ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9286435270716513126ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9193517562090289595ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7162524104383508576ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14686534753345109361ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1737696451820295100ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2249850320237090370ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17427495677270263589ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11958882124297950178ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17373485581069532307ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13648399750397349022ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 249943495993219512ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16173127300249833883ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14393378133195897997ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14797991470780442281ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 91835961547698832ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8092569788764204283ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3414568245286797525ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9523757100867339321ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_eff_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9223552982827248085ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6378043272161394362ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15384034277783527632ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8076679148915100638ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13806561569233543761ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8934796491021083374ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 590032361331221855ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9654253915281116321ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 119694289648240455ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18282755134362446386ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3197746440996689206ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2213326266249933335ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9107393246194790861ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3078204407431159262ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13453619696675597334ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__got_addr_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2398424903663037480ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1988370744759870242ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2428683054321767908ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14363292597636442162ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2314095996509939021ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__bpu_sel_lane1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16606484470403366342ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1961905801588518911ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3584968593162190099ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9783462803532215802ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5975800007907297514ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 503214512302800123ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2824469726063174443ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10588517676132891455ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6046258539650609386ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17314965222430343006ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5290104831089019331ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17498259028223567357ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_paddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8422938311592516324ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_target_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9593118623627606773ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s0_pred_taken_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7848267601618540461ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 366750162756756162ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_vaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14922706909216388182ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16487407584376478858ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7615396225805345108ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13894632245149919817ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7874457216112282647ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9835569322496142603ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5411820951815182113ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4280517991701909988ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_offset_word = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11970989985726380168ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 8; ++__Vi1) {
            vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8577905306096055806ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0[__Vi0] = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 3036857507983797900ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1[__Vi0] = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 9521149439925855148ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(128, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0[__Vi0], __VscopeHash, 1705532522747198405ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(128, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1[__Vi0], __VscopeHash, 8971151622597457658ull);
    }
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3551405950417744244ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10736371516438050098ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7877077535616335320ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit_way = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9488265966398185770ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data, __VscopeHash, 15306468067320242021ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4476369599080739763ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8548144809895296745ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10780271589497906413ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13839820242257499863ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3961035073560376501ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14956081225660960385ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9062349639017160031ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8672407636068822527ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg, __VscopeHash, 1666876264536357299ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line, __VscopeHash, 15637445623068828755ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2943201627091890250ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8116704897657509327ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13635546187630678599ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16338709455460960644ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12644529749732793730ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3871417626606339327ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7376358561390145763ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11683398214380140194ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line, __VscopeHash, 8901126145619288969ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7565733834692368713ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15212407833304543971ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14565677948773200130ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13647806410300418558ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9519947589639739047ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5243346563383460970ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9241592019735603361ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10041543685752675047ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4633223435907280855ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1112394568405013561ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10258079224191088349ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11405444095170009968ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15882161321815809887ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10399388555138550912ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3212884201719118066ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9572424133017341290ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_direct = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15976940841669176733ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16745330266388540706ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit_way0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17371603261545394417ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit_way1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7147045402093257918ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 204440277908746268ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15744131620672963059ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(18, __VscopeHash, 6709219355321887733ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8046740528398450783ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10971269223814129271ull);
        }
    }
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5552400441781806403ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5927689331171961766ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3997912860000787005ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2 = VL_SCOPED_RAND_RESET_I(18, __VscopeHash, 7495448381053653406ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7660445352378742858ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1582782355486908673ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16364209438007083415ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target_s2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8007519467280709545ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_valid_s2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16900886831152958151ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_tag_s2 = VL_SCOPED_RAND_RESET_I(18, __VscopeHash, 16562914428668779418ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2 = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16835231467629645242ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_target_s2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7431687264982722718ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_hit_s2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4687459356152124926ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_pc__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9435894864618661649ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17901681816124928471ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2458359876059369271ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7460493906956005263ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 10317217330057978196ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9333297633283489619ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14350213461871406630ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6101747542042486538ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10251122685193070032ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15071435505038447139ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9214411133988493193ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_is_base = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15752899509226749580ull);
    vlSelf->asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5371816090626999087ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3651330379756325791ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_client_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14546344065406837920ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8445514171595334820ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15264084320860099176ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_addr_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12923262781220233712ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_store_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17682848733538663371ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_store_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14167694647593922763ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_store_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4149131317122130214ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_store_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18366592956592111277ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_store_resp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3190045730821824782ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_store_drain = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1727528270670802981ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_store_accept = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16405605165521172687ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_grant_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10083490471146122987ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_grant_inst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17063855671814222929ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_grant = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10287547702108065708ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17308715066866810135ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__base_inst_data_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9699780946967230847ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6230292780006510845ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15931253799733708442ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1918511380991944405ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14396892351763402947ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_store_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 774261830847086899ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_store_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10962330651991811307ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_store_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6545413925897831385ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_store_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3225284269926515081ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_store_resp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 286862049427061666ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_store_drain = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9630919248115673670ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_store_accept = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7949892550110914417ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_grant = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 724739739862145471ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8060325853353383590ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_dlab = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4064101143841299673ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_req_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8068829694262154355ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_req_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9294541524131597637ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_req_offset = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7809872986757282402ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_req_write_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2281001983759471447ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_grant = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10502325399481291369ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_exec_tx_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10918325411297324531ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12236129966557888380ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15663370706491729051ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_tx_start_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5486242864520087093ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_tx_data_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9494634861757027965ull);
    vlSelf->asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4505975602197867049ull);
    vlSelf->__Vfunc_asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__cpucfg_result__49__index = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_0 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_1 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_10 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_14 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_15 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_16 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_19 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_20 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_21 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_23 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_53 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_54 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_58 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_63 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__asm_monitor_tb__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
