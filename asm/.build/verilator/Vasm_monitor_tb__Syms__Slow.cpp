// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vasm_monitor_tb__pch.h"

Vasm_monitor_tb__Syms::Vasm_monitor_tb__Syms(VerilatedContext* contextp, const char* namep, Vasm_monitor_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(4353);
    // Setup sub module instances
    TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.ctor(this, "asm_monitor_tb.cpu.u_inst_buffer.u_decoder_0");
    TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.ctor(this, "asm_monitor_tb.cpu.u_inst_buffer.u_decoder_1");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0 = &TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0;
    TOP.__PVT__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1 = &TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__Vconfigure(true);
    TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__Vconfigure(false);
    // Setup scopes
}

Vasm_monitor_tb__Syms::~Vasm_monitor_tb__Syms() {
    if (__Vm_dumping) _traceDumpClose();
    // Tear down scopes
    // Tear down sub module instances
    TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.dtor();
    TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.dtor();
}

void Vasm_monitor_tb__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vasm_monitor_tb__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        const std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vasm_monitor_tb__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}
