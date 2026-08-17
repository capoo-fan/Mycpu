// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vasm_monitor_tb.h for the primary calling header

#ifndef VERILATED_VASM_MONITOR_TB_INST_DECODER_H_
#define VERILATED_VASM_MONITOR_TB_INST_DECODER_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vasm_monitor_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vasm_monitor_tb_inst_decoder final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__inst_add_w;
    CData/*0:0*/ __PVT__inst_sub_w;
    CData/*0:0*/ __PVT__inst_slt;
    CData/*0:0*/ __PVT__inst_sltu;
    CData/*0:0*/ __PVT__inst_nor;
    CData/*0:0*/ __PVT__inst_and;
    CData/*0:0*/ __PVT__inst_or;
    CData/*0:0*/ __PVT__inst_xor;
    CData/*0:0*/ __PVT__inst_slli_w;
    CData/*0:0*/ __PVT__inst_srli_w;
    CData/*0:0*/ __PVT__inst_srai_w;
    CData/*0:0*/ __PVT__inst_addi_w;
    CData/*0:0*/ __PVT__inst_ld_w;
    CData/*0:0*/ __PVT__inst_st_w;
    CData/*0:0*/ __PVT__inst_lu12i_w;
    CData/*0:0*/ __PVT__inst_slti;
    CData/*0:0*/ __PVT__inst_sltui;
    CData/*0:0*/ __PVT__inst_andi;
    CData/*0:0*/ __PVT__inst_ori;
    CData/*0:0*/ __PVT__inst_xori;
    CData/*0:0*/ __PVT__inst_sll_w;
    CData/*0:0*/ __PVT__inst_srl_w;
    CData/*0:0*/ __PVT__inst_sra_w;
    CData/*0:0*/ __PVT__need_ui12;
    CData/*0:0*/ __PVT__need_si20;
    CData/*0:0*/ __PVT__need_si26;
    CData/*0:0*/ __PVT__src2_is_4;
    CData/*0:0*/ __PVT__src1_is_pc;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_56;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_61;
    IData/*31:0*/ inst;
    VlWide<6>/*168:0*/ dec_bus;
    VlWide<6>/*191:0*/ __VdfgRegularize_h6e95ff9d_0_59;
    VlWide<6>/*191:0*/ __VdfgRegularize_h6e95ff9d_0_64;

    // INTERNAL VARIABLES
    Vasm_monitor_tb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vasm_monitor_tb_inst_decoder();
    ~Vasm_monitor_tb_inst_decoder();
    void ctor(Vasm_monitor_tb__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vasm_monitor_tb_inst_decoder);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
