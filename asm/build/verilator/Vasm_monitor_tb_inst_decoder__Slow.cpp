// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

void Vasm_monitor_tb_inst_decoder___ctor_var_reset(Vasm_monitor_tb_inst_decoder* vlSelf);

Vasm_monitor_tb_inst_decoder::Vasm_monitor_tb_inst_decoder() = default;
Vasm_monitor_tb_inst_decoder::~Vasm_monitor_tb_inst_decoder() = default;

void Vasm_monitor_tb_inst_decoder::ctor(Vasm_monitor_tb__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vasm_monitor_tb_inst_decoder___ctor_var_reset(this);
}

void Vasm_monitor_tb_inst_decoder::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vasm_monitor_tb_inst_decoder::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
