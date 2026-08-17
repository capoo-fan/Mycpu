// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vasm_monitor_tb.h for the primary calling header

#include "Vasm_monitor_tb__pch.h"

void Vasm_monitor_tb___024root___ctor_var_reset(Vasm_monitor_tb___024root* vlSelf);

Vasm_monitor_tb___024root::Vasm_monitor_tb___024root(Vasm_monitor_tb__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vasm_monitor_tb___024root___ctor_var_reset(this);
}

void Vasm_monitor_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vasm_monitor_tb___024root::~Vasm_monitor_tb___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
