// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VASM_MONITOR_TB__SYMS_H_
#define VERILATED_VASM_MONITOR_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vasm_monitor_tb.h"

// INCLUDE MODULE CLASSES
#include "Vasm_monitor_tb___024root.h"
#include "Vasm_monitor_tb_inst_decoder.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vasm_monitor_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vasm_monitor_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vasm_monitor_tb___024root      TOP;
    Vasm_monitor_tb_inst_decoder   TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0;
    Vasm_monitor_tb_inst_decoder   TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1;

    // CONSTRUCTORS
    Vasm_monitor_tb__Syms(VerilatedContext* contextp, const char* namep, Vasm_monitor_tb* modelp);
    ~Vasm_monitor_tb__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
