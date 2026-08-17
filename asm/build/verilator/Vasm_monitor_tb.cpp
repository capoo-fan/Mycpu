// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vasm_monitor_tb__pch.h"

//============================================================
// Constructors

Vasm_monitor_tb::Vasm_monitor_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vasm_monitor_tb__Syms(contextp(), _vcname__, this)}
    , __PVT__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0{vlSymsp->TOP.__PVT__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0}
    , __PVT__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1{vlSymsp->TOP.__PVT__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vasm_monitor_tb::Vasm_monitor_tb(const char* _vcname__)
    : Vasm_monitor_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vasm_monitor_tb::~Vasm_monitor_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vasm_monitor_tb___024root___eval_debug_assertions(Vasm_monitor_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vasm_monitor_tb___024root___eval_static(Vasm_monitor_tb___024root* vlSelf);
void Vasm_monitor_tb___024root___eval_initial(Vasm_monitor_tb___024root* vlSelf);
void Vasm_monitor_tb___024root___eval_settle(Vasm_monitor_tb___024root* vlSelf);
void Vasm_monitor_tb___024root___eval(Vasm_monitor_tb___024root* vlSelf);

void Vasm_monitor_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vasm_monitor_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vasm_monitor_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vasm_monitor_tb___024root___eval_static(&(vlSymsp->TOP));
        Vasm_monitor_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vasm_monitor_tb___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vasm_monitor_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vasm_monitor_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vasm_monitor_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vasm_monitor_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vasm_monitor_tb___024root___eval_final(Vasm_monitor_tb___024root* vlSelf);

VL_ATTR_COLD void Vasm_monitor_tb::final() {
    contextp()->executingFinal(true);
    Vasm_monitor_tb___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vasm_monitor_tb::hierName() const { return vlSymsp->name(); }
const char* Vasm_monitor_tb::modelName() const { return "Vasm_monitor_tb"; }
unsigned Vasm_monitor_tb::threads() const { return 1; }
void Vasm_monitor_tb::prepareClone() const { contextp()->prepareClone(); }
void Vasm_monitor_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
