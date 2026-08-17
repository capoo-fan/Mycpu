// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vasm_monitor_tb__Syms.h"


VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_sub__TOP__0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_sub__TOP__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "asm_monitor_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1736,0,"BOOT_LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1737,0,"BASE_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1737,0,"EXT_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1737,0,"PROGRAM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+1738,0,"BOOT_MESSAGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 303,0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"inst_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1748,0,"inst_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1749,0,"inst_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1750,0,"inst_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"inst_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1751,0,"inst_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"inst_addr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"inst_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"inst_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"data_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"data_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"data_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"data_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"data_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"data_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+312,0,"data_addr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"data_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+262,0,"data_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+314,0,"data_fast_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+315,0,"data_fast_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+263,0,"data_fast_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+316,0,"data_store_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+317,0,"base_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 19,0);
    VL_TRACE_DECL_BUS(tracep,c+318,0,"ext_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 19,0);
    VL_TRACE_DECL_BUS(tracep,c+319,0,"base_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+320,0,"ext_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+321,0,"base_be_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+322,0,"ext_be_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+323,0,"base_ce_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+324,0,"base_oe_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+325,0,"base_we_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+326,0,"ext_ce_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+327,0,"ext_oe_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+328,0,"ext_we_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"uart_rx_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"uart_rx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+329,0,"uart_rx_clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+330,0,"uart_tx_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"uart_tx_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+264,0,"base_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+265,0,"ext_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+266,0,"tx_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"base_words",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"program_words",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+13,0,"watch_words",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"data_words",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"expect_words",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+267,0,"write_log_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"init_fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"init_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+18,0,"init_line_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+19,0,"entry_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+20,0,"program_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"watch_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"data_load_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"expect_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+24,0,"expect_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+25,0,"init_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"init_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+27,0,"base_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_WIDE(tracep,c+59,0,"program_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_WIDE(tracep,c+91,0,"data_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_WIDE(tracep,c+123,0,"expect_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_WIDE(tracep,c+155,0,"init_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_WIDE(tracep,c+187,0,"init_line",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_WIDE(tracep,c+219,0,"wave_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1023,0);
    VL_TRACE_DECL_BIT(tracep,c+251,0,"data_enabled",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+252,0,"expect_file_enabled",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+253,0,"expect_value_enabled",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+268,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+254,0,"max_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+256,0,"wait_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BIT(tracep,c+270,0,"command_counting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+271,0,"command_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+272,0,"user_counting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+273,0,"user_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+274,0,"exit_seen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+275,0,"exit_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_QUAD(tracep,c+276,0,"command_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+278,0,"command_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+280,0,"user_cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+282,0,"user_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_QUAD(tracep,c+284,0,"write_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+332,0,"branch_next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1726,0,"program_exit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+333,0,"commit_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+1727,0,"user_commit_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1728,0,"user_commit_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+288,0,"exit_commit_now",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+286,0,"exit_commit_later",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+258,0,"send_rx_byte__Vstatic__value",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+259,0,"wait_tx__Vstatic__wanted",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"load_program__Vstatic__n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"compare_results__Vstatic__n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"compare_results__Vstatic__mismatch_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"compare_results__Vstatic__addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"compare_results__Vstatic__actual",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"print_report__Vstatic__n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"print_report__Vstatic__addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "bridge", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"inst_sram_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1748,0,"inst_sram_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1749,0,"inst_sram_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1750,0,"inst_sram_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"inst_sram_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1751,0,"inst_sram_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"inst_sram_addr_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"inst_sram_data_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"inst_sram_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"data_sram_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"data_sram_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"data_sram_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"data_sram_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"data_sram_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"data_sram_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+312,0,"data_sram_addr_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"data_sram_data_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+262,0,"data_sram_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+314,0,"data_sram_fast_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+315,0,"data_sram_fast_data_ok",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+263,0,"data_sram_fast_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+316,0,"data_sram_store_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+317,0,"base_ram_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 19,0);
    VL_TRACE_DECL_BUS(tracep,c+319,0,"base_ram_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+321,0,"base_ram_be_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+323,0,"base_ram_ce_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+324,0,"base_ram_oe_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+325,0,"base_ram_we_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+264,0,"base_ram_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+318,0,"ext_ram_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 19,0);
    VL_TRACE_DECL_BUS(tracep,c+320,0,"ext_ram_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+322,0,"ext_ram_be_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+326,0,"ext_ram_ce_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+327,0,"ext_ram_oe_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+328,0,"ext_ram_we_n",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+265,0,"ext_ram_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"uart_rx_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"uart_rx_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1748,0,"uart_tx_busy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+329,0,"uart_rx_clear",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+330,0,"uart_tx_start",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"uart_tx_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1752,0,"S_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1753,0,"S_ACCESS0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1754,0,"S_ACCESS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1755,0,"S_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+334,0,"data_targets_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+335,0,"data_targets_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+336,0,"base_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+337,0,"base_client_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+338,0,"base_fast_data_ok_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+339,0,"base_fast_ready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+340,0,"base_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+341,0,"base_store_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+342,0,"base_store_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+343,0,"base_store_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+344,0,"base_store_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+345,0,"base_store_resp_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+346,0,"base_data_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+347,0,"base_data_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+348,0,"base_store_drain",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+349,0,"base_store_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+350,0,"base_store_accept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+351,0,"base_data_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"base_inst_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+352,0,"base_grant_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"base_grant_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+353,0,"base_grant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+354,0,"base_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+355,0,"base_cur_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+356,0,"base_read_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+357,0,"base_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+358,0,"base_data_addr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+359,0,"base_data_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"base_inst_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+360,0,"ext_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+361,0,"ext_fast_data_ok_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+362,0,"ext_fast_ready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+363,0,"ext_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+364,0,"ext_store_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+365,0,"ext_store_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+366,0,"ext_store_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+367,0,"ext_store_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+368,0,"ext_store_resp_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+369,0,"ext_data_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+370,0,"ext_data_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+371,0,"ext_store_drain",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+372,0,"ext_store_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+373,0,"ext_store_accept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+374,0,"ext_grant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+375,0,"ext_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+376,0,"ext_cur_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+377,0,"ext_read_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+378,0,"ext_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+379,0,"ext_data_addr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+380,0,"ext_data_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+381,0,"uart_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+382,0,"uart_dlab",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+383,0,"uart_write_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+384,0,"uart_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+385,0,"uart_tx_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+386,0,"uart_req_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+387,0,"uart_req_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+388,0,"uart_req_offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+389,0,"uart_req_write_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+390,0,"uart_grant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+386,0,"uart_exec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+391,0,"uart_exec_tx_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+260,0,"uart_status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+287,0,"uart_read_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+392,0,"uart_resp_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+393,0,"uart_rdata_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+330,0,"uart_tx_start_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"uart_tx_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+329,0,"uart_rx_clear_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+390,0,"uart_data_addr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+392,0,"uart_data_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1756,0,"unused_cpu_bus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "cpu", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"inst_sram_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1748,0,"inst_sram_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1749,0,"inst_sram_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1750,0,"inst_sram_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"inst_sram_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1751,0,"inst_sram_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"inst_sram_addr_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"inst_sram_data_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"inst_sram_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"data_sram_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"data_sram_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"data_sram_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"data_sram_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"data_sram_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"data_sram_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+312,0,"data_sram_addr_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"data_sram_data_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+262,0,"data_sram_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+314,0,"data_sram_fast_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+315,0,"data_sram_fast_data_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+263,0,"data_sram_fast_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+316,0,"data_sram_store_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1751,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1750,0,"debug_wb_rf_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1757,0,"debug_wb_rf_wnum",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1751,0,"debug_wb_rf_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+394,0,"icache_rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+395,0,"icache_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+396,0,"icache_rd_rdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+397,0,"icache_ret_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+398,0,"icache_ret_last",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+399,0,"icache_ret_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"es_allowin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"ms_allowin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1758,0,"ws_allowin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+402,0,"if_to_ibuf_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"if_to_ibuf_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+404,0,"if_to_ibuf_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_WIDE(tracep,c+408,0,"if_to_ibuf_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_BIT(tracep,c+412,0,"ibuf_push_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+413,0,"ibuf_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"ibuf_front_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+415,0,"ibuf_front_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+416,0,"ibuf_front_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_WIDE(tracep,c+425,0,"ibuf_front_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"ibuf_front_raddr1_0_hot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"ibuf_front_raddr2_0_hot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"ibuf_front_raddr1_1_hot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"ibuf_front_raddr2_1_hot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+438,0,"issue_pop_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+439,0,"issue_pop_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+440,0,"ds_to_es_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+441,0,"ds_to_es_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+442,0,"es_to_ms_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+443,0,"es_to_ms_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+444,0,"ms_to_ws_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+445,0,"ms_to_ws_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+446,0,"ds_to_es_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 253,0);
    VL_TRACE_DECL_WIDE(tracep,c+454,0,"ds_to_es_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 222,0);
    VL_TRACE_DECL_BUS(tracep,c+461,0,"ds_mul_src1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+462,0,"ds_mul_src2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"ds_mul_src1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"ds_mul_src2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+465,0,"es_to_ms_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 300,0);
    VL_TRACE_DECL_WIDE(tracep,c+475,0,"es_to_ms_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 208,0);
    VL_TRACE_DECL_WIDE(tracep,c+289,0,"ms_to_ws_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 184,0);
    VL_TRACE_DECL_QUAD(tracep,c+295,0,"ms_to_ws_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 37,0);
    VL_TRACE_DECL_QUAD(tracep,c+482,0,"es_fwd_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_QUAD(tracep,c+484,0,"es_fwd_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 39,0);
    VL_TRACE_DECL_QUAD(tracep,c+486,0,"ms_fwd_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_QUAD(tracep,c+488,0,"ms_fwd_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 39,0);
    VL_TRACE_DECL_BIT(tracep,c+490,0,"load_wakeup_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1729,0,"load_wakeup_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+491,0,"ws_to_rf_bus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 75,0);
    VL_TRACE_DECL_BIT(tracep,c+494,0,"br_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+495,0,"br_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+496,0,"es_csr_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+497,0,"ms_csr_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+498,0,"ws_csr_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+499,0,"es_cacop_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+500,0,"ms_cacop_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+501,0,"special_block",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+502,0,"special_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+503,0,"csr_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+504,0,"csr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+505,0,"csr_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+506,0,"csr_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+507,0,"csr_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+508,0,"csr_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+509,0,"csr_crmd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+510,0,"csr_dmw0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+511,0,"csr_dmw1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"csr_trans_ctx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"csr_ctx_update",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+514,0,"csr_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+515,0,"csr_flush_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+516,0,"cacop_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+517,0,"cacop_flush_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"pipeline_flush",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+519,0,"pipeline_flush_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+520,0,"bpu_pred_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"bpu_pred_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"bpu_pred_lane",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+523,0,"bpu_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"bpu_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"bpu_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"bpu_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"bpu_ex_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"bpu_ex_is_bj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+525,0,"bpu_ex_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+526,0,"bpu_ex_real_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+527,0,"bpu_ex_real_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+528,0,"icacop_req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+529,0,"icacop_req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"icacop_req_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"icacop_req_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"icacop_paddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+533,0,"icacop_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+534,0,"store_inv_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"store_inv_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"pc_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+537,0,"pc_paddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+538,0,"data_sram_vaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+539,0,"pc_inst_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+540,0,"if_suspend",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+541,0,"pc_cross_line",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"pc_next_seq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"data_txn_accept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+545,0,"data_sram_addr_is_sram",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_bpu", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"if_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+539,0,"if_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"id_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+540,0,"pl_suspend",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+520,0,"pred_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"pred_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"pred_lane",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"ex_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"ex_is_bj",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+525,0,"ex_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+526,0,"real_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+527,0,"real_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1759,0,"BPU_ROW_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1759,0,"BPU_BANKS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1760,0,"BPU_ROWS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1761,0,"BPU_TAG_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+546,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);

    Vasm_monitor_tb___024root__trace_init_dtype____0(vlSelf, tracep, "btb_valid", 0, c+547, VerilatedTraceSigDirection::NONE);

    Vasm_monitor_tb___024root__trace_init_dtype____1(vlSelf, tracep, "btb_tag_mem", 0, c+555, VerilatedTraceSigDirection::NONE);

    Vasm_monitor_tb___024root__trace_init_dtype____2(vlSelf, tracep, "btb_counter", 0, c+563, VerilatedTraceSigDirection::NONE);

    Vasm_monitor_tb___024root__trace_init_dtype____3(vlSelf, tracep, "btb_target", 0, c+571, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"pred_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+580,0,"pred_row",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+581,0,"pred_bank",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+582,0,"pred_hit_bank0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+583,0,"pred_hit_bank1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+584,0,"pred_valid_bank0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+585,0,"pred_valid_bank1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+586,0,"lane0_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+587,0,"lane1_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+588,0,"raw_pred_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+589,0,"raw_pred_lane",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+590,0,"raw_pred_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"update_valid_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"update_tag_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BIT(tracep,c+592,0,"update_bank_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"update_row_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+594,0,"read_valid_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+595,0,"read_tag_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"read_counter_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"read_target_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"update_valid_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+599,0,"update_tag_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BIT(tracep,c+600,0,"update_bank_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"update_row_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+602,0,"real_taken_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+603,0,"real_target_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"read_valid_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"read_tag_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"read_counter_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+607,0,"read_target_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+608,0,"update_hit_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"next_counter_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+611,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_csr", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+503,0,"raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+504,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+505,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+506,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+507,0,"wmask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+508,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+509,0,"crmd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+510,0,"dmw0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+511,0,"dmw1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"trans_ctx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1762,0,"CSR_CRMD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1763,0,"CSR_DMW0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1764,0,"CSR_DMW1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1765,0,"CRMD_WRITABLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1766,0,"DMW_WRITABLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"crmd_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 8,0);
    VL_TRACE_DECL_BUS(tracep,c+613,0,"dmw0_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+614,0,"dmw1_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"trans_ctx_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+509,0,"crmd_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+510,0,"dmw0_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+511,0,"dmw1_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+615,0,"crmd_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+616,0,"dmw_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"crmd_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 8,0);
    VL_TRACE_DECL_BUS(tracep,c+618,0,"dmw0_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+619,0,"dmw1_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+620,0,"next_plv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+621,0,"next_mapped_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+622,0,"dmw0_active_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+623,0,"dmw1_active_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+624,0,"trans_ctx_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_data_addr_translate", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"ctx_update",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"ctx_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+538,0,"vaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"paddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"ctx_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BIT(tracep,c+626,0,"dmw1_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"dmw1_vseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+628,0,"dmw1_pseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+629,0,"dmw0_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+630,0,"dmw0_vseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+631,0,"dmw0_pseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+632,0,"dmw0_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+633,0,"dmw1_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_data_txn_tracker", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"txn_accept",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"txn_store",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"txn_paddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"txn_data_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+534,0,"store_inv_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"store_inv_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+634,0,"data_txn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+635,0,"data_txn_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+636,0,"data_txn_is_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"data_txn_line",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 27,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_exe", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+440,0,"ds_to_es_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+441,0,"ds_to_es_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+446,0,"ds_to_es_bus_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 253,0);
    VL_TRACE_DECL_WIDE(tracep,c+454,0,"ds_to_es_bus_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 222,0);
    VL_TRACE_DECL_BUS(tracep,c+461,0,"ds_mul_src1_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+462,0,"ds_mul_src2_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"ds_mul_src1_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"ds_mul_src2_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"ms_allowin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+490,0,"load_wakeup_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1729,0,"load_wakeup_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"es_allowin",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+442,0,"es_to_ms_valid_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+443,0,"es_to_ms_valid_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+465,0,"es_to_ms_bus_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 300,0);
    VL_TRACE_DECL_WIDE(tracep,c+475,0,"es_to_ms_bus_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 208,0);
    VL_TRACE_DECL_QUAD(tracep,c+482,0,"es_fwd_bus_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_QUAD(tracep,c+484,0,"es_fwd_bus_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 39,0);
    VL_TRACE_DECL_BIT(tracep,c+496,0,"csr_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+499,0,"cacop_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+503,0,"csr_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+504,0,"csr_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+638,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+639,0,"es_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"es_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+641,0,"es_alu_op_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+642,0,"es_alu_src1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"es_alu_src2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+644,0,"es_rkd_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+645,0,"es_store_data_late_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+646,0,"es_store_data_src_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+647,0,"es_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+648,0,"es_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+649,0,"es_mem_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+650,0,"es_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+651,0,"es_is_mul_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+652,0,"mul_cnt_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+653,0,"mul_pending_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+654,0,"mul_result_hold_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+655,0,"mul_result_hold_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+656,0,"mul_result_hold_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+657,0,"es_ld_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+658,0,"es_ld_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+659,0,"es_ld_sign_ext_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+660,0,"es_st_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+661,0,"es_st_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+662,0,"es_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+663,0,"es_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+664,0,"es_br_op_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"es_br_offs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+666,0,"es_is_cpucfg_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+667,0,"es_is_cacop_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+668,0,"es_cacop_code_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+669,0,"es_is_csr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+503,0,"es_csr_num_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+670,0,"es_csr_wmask_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+671,0,"es_csr_wvalue_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+672,0,"es_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+673,0,"es_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+674,0,"es_alu_op_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+675,0,"es_alu_src1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+676,0,"es_alu_src2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+677,0,"es_rkd_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+678,0,"es_res_from_mem_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+679,0,"es_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+680,0,"es_mem_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+681,0,"es_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+682,0,"es_is_mul_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+683,0,"es_ld_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+684,0,"es_ld_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+685,0,"es_ld_sign_ext_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+686,0,"es_st_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+687,0,"es_st_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+688,0,"es_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+689,0,"es_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+690,0,"es_br_op_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+691,0,"es_br_offs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+692,0,"ds_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+693,0,"ds_alu_op_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+694,0,"ds_alu_src1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+695,0,"ds_alu_src2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+696,0,"ds_rkd_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+697,0,"ds_store_data_late_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"ds_store_data_src_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+698,0,"ds_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+699,0,"ds_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+700,0,"ds_mem_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+701,0,"ds_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+702,0,"ds_is_mul_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+703,0,"ds_ld_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+704,0,"ds_ld_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+705,0,"ds_ld_sign_ext_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+706,0,"ds_st_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+707,0,"ds_st_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+708,0,"ds_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+709,0,"ds_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+710,0,"ds_br_op_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+711,0,"ds_br_offs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+712,0,"ds_is_cpucfg_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+713,0,"ds_is_cacop_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+714,0,"ds_cacop_code_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+715,0,"ds_is_csr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+716,0,"ds_is_csrxchg_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+717,0,"ds_csr_num_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BIT(tracep,c+718,0,"ds_load_wakeup_rj_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+719,0,"ds_load_wakeup_rkd_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+297,0,"ds_alu_src1_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+298,0,"ds_alu_src2_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"ds_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+721,0,"ds_alu_op_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"ds_alu_src1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+723,0,"ds_alu_src2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+724,0,"ds_rkd_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+725,0,"ds_res_from_mem_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+726,0,"ds_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+727,0,"ds_mem_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+728,0,"ds_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+729,0,"ds_is_mul_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+730,0,"ds_ld_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"ds_ld_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+732,0,"ds_ld_sign_ext_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+733,0,"ds_st_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+734,0,"ds_st_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+735,0,"ds_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+736,0,"ds_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+737,0,"ds_br_op_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"ds_br_offs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+739,0,"mul_packet_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+739,0,"es_ready_go",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+740,0,"es_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"alu_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"alu_fast_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"mul_product_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+744,0,"alu_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+745,0,"alu_fast_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+746,0,"mul_product_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+747,0,"es_mul_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+748,0,"lane1_fwd_sub_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+749,0,"lane1_fwd_add_b_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+750,0,"lane1_fwd_add_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+751,0,"alu_fast_result_0_timing",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+752,0,"es_alu_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+753,0,"es_alu_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+754,0,"es_exec_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+755,0,"es_exec_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+754,0,"es_fwd_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+755,0,"es_fwd_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+756,0,"es_final_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+757,0,"es_result_forwardable_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+758,0,"es_is_bj_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+759,0,"es_real_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+760,0,"es_real_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+761,0,"es_next_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+762,0,"es_is_bj_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+763,0,"es_real_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+764,0,"es_real_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+765,0,"es_next_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+766,0,"es_taken_miss_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+767,0,"es_target_miss_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+768,0,"es_redirect_miss_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+769,0,"es_taken_miss_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+770,0,"es_target_miss_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+771,0,"es_redirect_miss_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+772,0,"es_fwd_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+773,0,"es_fwd_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"mul_src1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+300,0,"mul_src2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"mul_src1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"mul_src2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_alu_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1767,0,"HAS_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+641,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+642,0,"alu_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"alu_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"mul_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+300,0,"mul_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"alu_fast_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"mul_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+774,0,"op_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+748,0,"op_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+775,0,"op_slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+776,0,"op_sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+777,0,"op_and",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+778,0,"op_nor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+779,0,"op_or",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+780,0,"op_xor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+781,0,"op_sll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+782,0,"op_srl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+783,0,"op_sra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+784,0,"op_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"add_sub_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+785,0,"slt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+786,0,"sltu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+787,0,"and_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+788,0,"nor_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+789,0,"or_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+790,0,"xor_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"lui_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+791,0,"sll_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_QUAD(tracep,c+792,0,"sr64_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+794,0,"sr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"mul_low_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+748,0,"do_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+795,0,"addsub_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+796,0,"signed_less",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+797,0,"unsigned_less",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_multiplier", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_mult_gen_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+300,0,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"P",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+798,0,"p0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+799,0,"p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_alu_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1767,0,"HAS_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+674,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+675,0,"alu_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+676,0,"alu_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"mul_src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"mul_src2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+744,0,"alu_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+745,0,"alu_fast_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+746,0,"mul_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+800,0,"op_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+801,0,"op_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+802,0,"op_slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+803,0,"op_sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+804,0,"op_and",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+805,0,"op_nor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+806,0,"op_or",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+807,0,"op_xor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+808,0,"op_sll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+809,0,"op_srl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+810,0,"op_sra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+811,0,"op_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+745,0,"add_sub_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+812,0,"slt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+813,0,"sltu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+814,0,"and_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+815,0,"nor_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+816,0,"or_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+817,0,"xor_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+676,0,"lui_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+818,0,"sll_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_QUAD(tracep,c+819,0,"sr64_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+821,0,"sr_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+746,0,"mul_low_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+801,0,"do_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+822,0,"addsub_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+823,0,"signed_less",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+824,0,"unsigned_less",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_multiplier", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_mult_gen_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"CLK",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"A",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"B",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+746,0,"P",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+825,0,"p0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+826,0,"p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+746,0,"p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_branch_judge_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1768,0,"SIMPLE_ONLY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+664,0,"br_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+642,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+644,0,"rkd_value",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"br_offs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+758,0,"is_bj",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+759,0,"real_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+760,0,"real_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+761,0,"next_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+827,0,"rj_eq_rkd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+828,0,"rj_lt_rkd_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+829,0,"rj_lt_rkd_unsigned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+830,0,"target_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+831,0,"simple_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_branch_judge_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1767,0,"SIMPLE_ONLY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+690,0,"br_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+673,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+675,0,"src1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+677,0,"rkd_value",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+691,0,"br_offs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+762,0,"is_bj",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+763,0,"real_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+764,0,"real_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+765,0,"next_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+832,0,"rj_eq_rkd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+833,0,"rj_lt_rkd_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+834,0,"rj_lt_rkd_unsigned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+673,0,"target_base",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+835,0,"simple_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_icache_refill", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+394,0,"icache_rd_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+395,0,"icache_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+396,0,"icache_rd_rdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+397,0,"icache_ret_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+398,0,"icache_ret_last",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+399,0,"icache_ret_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"inst_sram_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1748,0,"inst_sram_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1749,0,"inst_sram_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1750,0,"inst_sram_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"inst_sram_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1751,0,"inst_sram_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"inst_sram_addr_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"inst_sram_data_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"inst_sram_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1752,0,"IC_REFILL_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1753,0,"IC_REFILL_REQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1754,0,"IC_REFILL_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+836,0,"ic_refill_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+837,0,"ic_refill_base_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+838,0,"ic_refill_beat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+397,0,"icache_ret_valid_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+398,0,"icache_ret_last_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+399,0,"icache_ret_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+839,0,"icache_rd_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+840,0,"inst_addr_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+841,0,"inst_data_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+842,0,"icache_last_beat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_icacop_addr_translate", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"ctx_update",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"ctx_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"vaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"paddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+843,0,"ctx_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BIT(tracep,c+844,0,"dmw1_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+845,0,"dmw1_vseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+846,0,"dmw1_pseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+847,0,"dmw0_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+848,0,"dmw0_vseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+849,0,"dmw0_pseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+850,0,"dmw0_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+851,0,"dmw1_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_if", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+539,0,"pc_inst_req",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+537,0,"pc_paddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+523,0,"bpu_pred_taken_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"bpu_pred_target_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"bpu_pred_taken_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"bpu_pred_target_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"br_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+528,0,"icacop_req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"icacop_req_code",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"icacop_req_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+529,0,"icacop_req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+533,0,"icacop_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+534,0,"store_inv_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"store_inv_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+412,0,"ibuf_allowin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+402,0,"fs_to_ds_valid_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"fs_to_ds_valid_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+404,0,"fs_to_ds_bus_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_WIDE(tracep,c+408,0,"fs_to_ds_bus_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_BIT(tracep,c+540,0,"if_suspend",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+394,0,"rd_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+395,0,"rd_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+396,0,"rd_rdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+397,0,"ret_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+398,0,"ret_last",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+399,0,"ret_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+852,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+539,0,"s0_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"s0_vaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+537,0,"s0_paddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+523,0,"s0_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"s0_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"s0_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"s0_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+853,0,"s0_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+854,0,"s0_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BUS(tracep,c+855,0,"s0_offset_word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+856,0,"s1_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+857,0,"s1_vaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+858,0,"s1_paddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+859,0,"s1_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+860,0,"s1_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+861,0,"s1_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+862,0,"s1_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+863,0,"s1_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+864,0,"s1_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BUS(tracep,c+865,0,"s1_offset_word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);

    Vasm_monitor_tb___024root__trace_init_dtype____4(vlSelf, tracep, "cache_valid", 0, c+866, VerilatedTraceSigDirection::NONE);

    Vasm_monitor_tb___024root__trace_init_dtype____5(vlSelf, tracep, "cache_tag_way0", 0, c+882, VerilatedTraceSigDirection::NONE);

    Vasm_monitor_tb___024root__trace_init_dtype____6(vlSelf, tracep, "cache_tag_way1", 0, c+890, VerilatedTraceSigDirection::NONE);

    Vasm_monitor_tb___024root__trace_init_dtype____7(vlSelf, tracep, "cache_data_way0", 0, c+898, VerilatedTraceSigDirection::NONE);

    Vasm_monitor_tb___024root__trace_init_dtype____8(vlSelf, tracep, "cache_data_way1", 0, c+930, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BIT(tracep,c+962,0,"s1_tag_match_way0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+963,0,"s1_tag_match_way1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+964,0,"s1_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+963,0,"s1_hit_way",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+965,0,"s1_hit_line",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+969,0,"store_inv_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+970,0,"store_inv_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BIT(tracep,c+971,0,"store_conflict_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+972,0,"s2_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+973,0,"s2_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+974,0,"s2_hit_way",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+975,0,"s2_line_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+979,0,"s2_vaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+980,0,"s2_paddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+981,0,"s2_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+982,0,"s2_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+983,0,"s2_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+984,0,"s2_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+985,0,"s2_offset_word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+986,0,"s2_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+987,0,"s2_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BUS(tracep,c+1769,0,"FSM_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1770,0,"FSM_MISS_REQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1771,0,"FSM_MISS_REFILL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1772,0,"FSM_RECOVERY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1773,0,"FSM_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+988,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+989,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_WIDE(tracep,c+990,0,"refill_data_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_WIDE(tracep,c+994,0,"refill_line",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+998,0,"refill_beat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+999,0,"refill_poisoned",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1000,0,"lfsr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1769,0,"MAINT_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1770,0,"MAINT_WAIT_REFILL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1771,0,"MAINT_LOOKUP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1772,0,"MAINT_APPLY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1773,0,"MAINT_DONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1001,0,"maint_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1002,0,"maint_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1003,0,"maint_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1004,0,"maint_clear_way0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1005,0,"maint_clear_way1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1006,0,"maint_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+1007,0,"s2_effective_line",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+1011,0,"s2_effective_inst_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1012,0,"s2_effective_inst_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1013,0,"s2_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1014,0,"s2_can_take_two",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+402,0,"s3_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"s3_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1015,0,"s3_inst_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1016,0,"s3_inst_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1017,0,"s3_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1018,0,"s3_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1019,0,"s3_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1020,0,"s3_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1021,0,"s3_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1022,0,"s3_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1023,0,"miss_replace_way",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1024,0,"store_conflict_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1025,0,"refill_retry_now",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1026,0,"s2_cache_hit_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1027,0,"s2_refill_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1028,0,"s2_data_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1029,0,"s3_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1030,0,"miss_hold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1031,0,"s2_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1031,0,"s1_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1032,0,"trigger_miss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1033,0,"lfsr_feedback",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1034,0,"maint_is_icache",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1035,0,"maint_direct",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1036,0,"maint_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1037,0,"maint_way",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1038,0,"maint_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1039,0,"maint_tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 24,0);
    VL_TRACE_DECL_BIT(tracep,c+1040,0,"refill_hits_maint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1041,0,"maint_hit_way0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1042,0,"maint_hit_way1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1043,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1044,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_inst_addr_translate", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"ctx_update",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"ctx_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"vaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+537,0,"paddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1045,0,"ctx_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BIT(tracep,c+1046,0,"dmw1_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1047,0,"dmw1_vseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1048,0,"dmw1_pseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1049,0,"dmw0_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1050,0,"dmw0_vseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"dmw0_pseg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1052,0,"dmw0_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1053,0,"dmw1_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_inst_buffer", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+402,0,"push_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+404,0,"push_bus_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"push_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+408,0,"push_bus_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_BIT(tracep,c+412,0,"push_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+413,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+438,0,"pop_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+439,0,"pop_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"front_valid_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+416,0,"front_bus_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"front_raddr1_0_hot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"front_raddr2_0_hot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+415,0,"front_valid_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+425,0,"front_bus_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"front_raddr1_1_hot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"front_raddr2_1_hot",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1759,0,"pointer_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1769,0,"CNT_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1770,0,"CNT_ONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1054,0,"head_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"tail_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);

    Vasm_monitor_tb___024root__trace_init_dtype____9(vlSelf, tracep, "fifo", 0, c+1056, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+1092,0,"head",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1093,0,"tail",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1094,0,"cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_WIDE(tracep,c+1095,0,"fifo_front_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_WIDE(tracep,c+1104,0,"fifo_front_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"front_valid_0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+415,0,"front_valid_1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+1113,0,"front_bus_0_g0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1115,0,"front_bus_0_g1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1117,0,"front_bus_0_g2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1119,0,"front_bus_0_g3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1121,0,"front_bus_0_g4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1123,0,"front_bus_0_g5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_QUAD(tracep,c+1125,0,"front_bus_1_g0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1127,0,"front_bus_1_g1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1129,0,"front_bus_1_g2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1131,0,"front_bus_1_g3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1133,0,"front_bus_1_g4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1135,0,"front_bus_1_g5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"front_raddr1_0_hot_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1137,0,"front_raddr2_0_hot_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1138,0,"front_raddr2_0_hot_bit1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1139,0,"front_raddr2_0_hot_bit0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1140,0,"front_raddr1_1_hot_bit0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1774,0,"HOT_RADDR1_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1775,0,"HOT_RADDR2_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+416,0,"front_bus_0_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_WIDE(tracep,c+425,0,"front_bus_1_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BIT(tracep,c+1141,0,"next_front_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1142,0,"next_front_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1143,0,"head_step",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g0_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g0_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g0_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1145,0,"front1_load_fifo1_g0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g1_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g1_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g1_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1145,0,"front1_load_fifo1_g1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g2_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g2_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g2_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1145,0,"front1_load_fifo1_g2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g3_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g3_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g3_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1145,0,"front1_load_fifo1_g3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g4_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g4_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g4_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1145,0,"front1_load_fifo1_g4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g5_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g5_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1144,0,"front1_we_g5_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1145,0,"front1_load_fifo1_g5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+1146,0,"next_front_bus_1_g0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1148,0,"next_front_bus_1_g1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1150,0,"next_front_bus_1_g2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1152,0,"next_front_bus_1_g3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1154,0,"next_front_bus_1_g4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 44,0);
    VL_TRACE_DECL_QUAD(tracep,c+1156,0,"next_front_bus_1_g5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_we_g0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_we_g1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_we_g2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_we_g3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_we_g4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_we_g5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_hot_raddr1_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1158,0,"front0_hot_raddr2_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+1159,0,"front0_hot_bus_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BUS(tracep,c+1168,0,"front0_hot_raddr1_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1169,0,"front0_hot_raddr2_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1170,0,"push_fire_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1171,0,"push_fire_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1172,0,"push_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_WIDE(tracep,c+1173,0,"dec_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 168,0);
    VL_TRACE_DECL_WIDE(tracep,c+1179,0,"dec_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 168,0);
    VL_TRACE_DECL_WIDE(tracep,c+1185,0,"push_entry_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_WIDE(tracep,c+1194,0,"push_entry_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_decoder_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_decoder_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_issue", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"front_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+416,0,"front_bus_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"front_raddr1_0_hot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"front_raddr2_0_hot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+415,0,"front_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+425,0,"front_bus_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 265,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"front_raddr1_1_hot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"front_raddr2_1_hot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+438,0,"pop_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+439,0,"pop_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+502,0,"special_fire",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"br_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+501,0,"special_block",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"es_allowin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"ms_allowin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+442,0,"es_to_ms_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+443,0,"es_to_ms_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_QUAD(tracep,c+482,0,"es_fwd_bus_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_QUAD(tracep,c+484,0,"es_fwd_bus_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 39,0);
    VL_TRACE_DECL_QUAD(tracep,c+486,0,"ms_fwd_bus_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_QUAD(tracep,c+488,0,"ms_fwd_bus_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 39,0);
    VL_TRACE_DECL_WIDE(tracep,c+491,0,"ws_to_rf_bus",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 75,0);
    VL_TRACE_DECL_BIT(tracep,c+490,0,"load_wakeup_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+440,0,"ds_to_es_valid_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+441,0,"ds_to_es_valid_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+446,0,"ds_to_es_bus_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 253,0);
    VL_TRACE_DECL_WIDE(tracep,c+454,0,"ds_to_es_bus_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 222,0);
    VL_TRACE_DECL_BUS(tracep,c+461,0,"ds_mul_src1_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+462,0,"ds_mul_src2_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"ds_mul_src1_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"ds_mul_src2_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+1203,0,"dec_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 168,0);
    VL_TRACE_DECL_WIDE(tracep,c+1209,0,"fs_bus_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_WIDE(tracep,c+1213,0,"dec_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 168,0);
    VL_TRACE_DECL_WIDE(tracep,c+1219,0,"fs_bus_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 96,0);
    VL_TRACE_DECL_BUS(tracep,c+692,0,"ds_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1223,0,"ds_inst_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+708,0,"ds_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+709,0,"ds_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"ds_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1224,0,"ds_inst_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+735,0,"ds_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+736,0,"ds_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+693,0,"alu_op_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+1225,0,"imm_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1226,0,"br_offs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1227,0,"jirl_offs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1228,0,"rf_raddr1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1229,0,"rf_raddr2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+701,0,"dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1230,0,"src1_is_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1231,0,"src2_is_imm_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+698,0,"res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+699,0,"gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+700,0,"mem_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+702,0,"is_mul_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+703,0,"ld_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+704,0,"ld_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+705,0,"ld_sign_ext_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+706,0,"st_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+707,0,"st_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1232,0,"need_rj_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1233,0,"need_rkd_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1234,0,"is_bj_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1235,0,"inst_beq_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1236,0,"inst_bne_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1237,0,"inst_blt_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1238,0,"inst_bge_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1239,0,"inst_bltu_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1240,0,"inst_bgeu_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1241,0,"inst_jirl_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1242,0,"inst_bl_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1243,0,"inst_b_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+712,0,"is_cpucfg_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+713,0,"is_cacop_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+714,0,"cacop_code_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+715,0,"is_csr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+716,0,"is_csrxchg_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+717,0,"csr_num_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+721,0,"alu_op_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+1244,0,"imm_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"br_offs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1245,0,"jirl_offs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1246,0,"rf_raddr1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"rf_raddr2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+728,0,"dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1247,0,"src1_is_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1248,0,"src2_is_imm_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+725,0,"res_from_mem_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+726,0,"gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+727,0,"mem_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+729,0,"is_mul_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+730,0,"ld_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"ld_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+732,0,"ld_sign_ext_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+733,0,"st_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+734,0,"st_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1249,0,"need_rj_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1250,0,"need_rkd_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1251,0,"is_bj_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1252,0,"inst_beq_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1253,0,"inst_bne_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1254,0,"inst_blt_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1255,0,"inst_bge_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1256,0,"inst_bltu_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1257,0,"inst_bgeu_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1258,0,"inst_jirl_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1259,0,"inst_bl_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1260,0,"inst_b_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1261,0,"is_cpucfg_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1262,0,"is_cacop_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1263,0,"is_csr_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"src_raddr1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"src_raddr2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"src_raddr1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"src_raddr2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+639,0,"es_bus_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+648,0,"es_bus_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+772,0,"es_bus_fwd_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+647,0,"es_bus_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+650,0,"es_bus_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+754,0,"es_fwd_data_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+672,0,"es_bus_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+679,0,"es_bus_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+773,0,"es_bus_fwd_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+681,0,"es_bus_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+755,0,"es_fwd_data_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1264,0,"ms_wait_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1265,0,"ms_wait_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1266,0,"ms_wait_dest_0_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1267,0,"ms_wait_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1268,0,"ms_wait_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1269,0,"es_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1270,0,"es_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1271,0,"es_fwd_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1272,0,"es_valid_0_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1273,0,"es_gr_we_0_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1274,0,"es_fwd_valid_0_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1275,0,"es_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1276,0,"es_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1277,0,"es_dest_0_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1278,0,"es_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1279,0,"es_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1280,0,"es_fwd_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1281,0,"es_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1282,0,"es_dest_1_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1283,0,"ms_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1284,0,"ms_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1285,0,"ms_fwd_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1286,0,"ms_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1287,0,"ms_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1288,0,"ms_fwd_data_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1289,0,"ms_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1290,0,"ms_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1291,0,"ms_fwd_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1292,0,"ms_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1293,0,"ms_fwd_data_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1294,0,"ex_wait_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1295,0,"ex_wait_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1296,0,"ws_rf_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1297,0,"ws_rf_waddr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1298,0,"ws_rf_wdata_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1299,0,"ws_rf_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1300,0,"ws_rf_waddr_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1301,0,"ws_rf_wdata_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1302,0,"rf_rdata1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1303,0,"rf_rdata2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1304,0,"rf_rdata1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1305,0,"rf_rdata2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1306,0,"src0_rj_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1307,0,"src0_rkd_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1308,0,"src1_rj_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1309,0,"src1_rkd_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1310,0,"load_wakeup_consumer_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1311,0,"load_wakeup_usable_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1312,0,"rj0_hit_es0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1313,0,"rj0_hit_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1314,0,"rj0_hit_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1315,0,"rj0_hit_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1316,0,"rj0_wait_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1317,0,"rj0_wait_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1318,0,"rj0_wait_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1319,0,"rj0_wait_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1320,0,"rj0_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+718,0,"rj0_use_load_wakeup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1321,0,"rj_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1322,0,"rkd0_hit_es0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1323,0,"rkd0_hit_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1324,0,"rkd0_hit_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1325,0,"rkd0_hit_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1326,0,"rkd0_wait_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1327,0,"rkd0_wait_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1328,0,"rkd0_wait_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1329,0,"rkd0_wait_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1330,0,"rkd0_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+719,0,"rkd0_use_load_wakeup",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1331,0,"rkd_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1332,0,"rj1_hit_es0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1333,0,"rj1_hit_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1334,0,"rj1_hit_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1335,0,"rj1_hit_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1336,0,"rj1_wait_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1337,0,"rj1_wait_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1338,0,"rj1_wait_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1339,0,"rj1_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1340,0,"rj_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1341,0,"rkd1_hit_es0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1342,0,"rkd1_hit_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1343,0,"rkd1_hit_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1344,0,"rkd1_hit_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1345,0,"rkd1_wait_es1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1346,0,"rkd1_wait_ms1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1347,0,"rkd1_wait_ms0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1348,0,"rkd1_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+724,0,"rkd_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1349,0,"rkd0_hard_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1350,0,"rkd0_late_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1351,0,"rkd0_late_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+697,0,"store_data_late_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1352,0,"mul0_dep_es",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1353,0,"mul1_dep_es",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1354,0,"stall_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1355,0,"stall_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1356,0,"raw_0_to_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1306,0,"src0_rj_valid_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1307,0,"src0_rkd_valid_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1308,0,"src1_rj_valid_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1309,0,"src1_rkd_valid_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1357,0,"rj0_hit_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1358,0,"rkd0_hit_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1359,0,"rj1_hit_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1360,0,"rkd1_hit_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1361,0,"rj0_hit_es0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1362,0,"rkd0_hit_es0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1363,0,"rj1_hit_es0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1364,0,"rkd1_hit_es0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1365,0,"rj0_wait_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1366,0,"rkd0_wait_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1367,0,"rj1_wait_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1368,0,"rkd1_wait_es1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1369,0,"rj0_wait_ms0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1317,0,"rj0_wait_ms1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1370,0,"rkd0_wait_ms0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1328,0,"rkd0_wait_ms1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1371,0,"rj1_wait_ms0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1337,0,"rj1_wait_ms1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1372,0,"rkd1_wait_ms0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1346,0,"rkd1_wait_ms1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1373,0,"rj0_wait_ms_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1374,0,"rkd0_wait_ms_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1375,0,"rj1_wait_ms_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1376,0,"rkd1_wait_ms_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1319,0,"rj0_wait_ex_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1377,0,"rj0_wait_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1326,0,"rkd0_wait_ex_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1378,0,"rkd0_wait_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1379,0,"rj1_wait_ex_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1380,0,"rj1_wait_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1381,0,"rkd1_wait_ex_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1382,0,"rkd1_wait_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1383,0,"rkd0_hard_wait_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1384,0,"rkd0_late_ok_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1385,0,"rkd0_late_wait_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1386,0,"store_data_late_0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1387,0,"mul0_dep_es_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1388,0,"mul1_dep_es_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1389,0,"stall_0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1390,0,"stall_1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1391,0,"ms_stall_0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1392,0,"blocking_ms_stall_0_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1393,0,"ms_stall_1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1356,0,"raw_0_to_1_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1394,0,"mem_op_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1395,0,"mem_op_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1396,0,"special_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1397,0,"special_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1398,0,"lane1_regular_alu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1399,0,"lane1_simple_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1400,0,"mul_pair",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1401,0,"lane1_capable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"issue_window_open",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+440,0,"issue0_fire_for_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+441,0,"issue1_fire_for_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+438,0,"issue0_fire_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+439,0,"issue1_fire_for_consume",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1402,0,"capture_ex_wait_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+694,0,"ds_alu_src1_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+695,0,"ds_alu_src2_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+696,0,"ds_rkd_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"ds_alu_src1_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+723,0,"ds_alu_src2_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+724,0,"ds_rkd_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+710,0,"ds_br_op_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+711,0,"ds_br_offs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+737,0,"ds_br_op_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"ds_br_offs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_regfile", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1302,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1303,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"raddr3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1304,0,"rdata3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"raddr4",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1305,0,"rdata4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1296,0,"we0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1297,0,"waddr0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1298,0,"wdata0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1299,0,"we1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1300,0,"waddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1301,0,"wdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);

    Vasm_monitor_tb___024root__trace_init_dtype____10(vlSelf, tracep, "rf", 0, c+1403, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_mem", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+442,0,"es_to_ms_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+443,0,"es_to_ms_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+465,0,"es_to_ms_bus_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 300,0);
    VL_TRACE_DECL_WIDE(tracep,c+475,0,"es_to_ms_bus_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 208,0);
    VL_TRACE_DECL_BIT(tracep,c+1758,0,"ws_allowin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+491,0,"ws_to_rf_bus",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 75,0);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"ms_allowin",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+444,0,"ms_to_ws_valid_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+445,0,"ms_to_ws_valid_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+289,0,"ms_to_ws_bus_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 184,0);
    VL_TRACE_DECL_QUAD(tracep,c+295,0,"ms_to_ws_bus_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 37,0);
    VL_TRACE_DECL_QUAD(tracep,c+486,0,"ms_fwd_bus_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 40,0);
    VL_TRACE_DECL_QUAD(tracep,c+488,0,"ms_fwd_bus_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 39,0);
    VL_TRACE_DECL_BIT(tracep,c+490,0,"load_wakeup_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1729,0,"load_wakeup_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+497,0,"csr_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+500,0,"cacop_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+494,0,"br_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+495,0,"br_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"bpu_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"bpu_is_bj",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+525,0,"bpu_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+526,0,"bpu_real_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+527,0,"bpu_real_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+528,0,"icacop_req_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"icacop_req_code",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"icacop_req_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+529,0,"icacop_req_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+533,0,"icacop_done",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+516,0,"cacop_flush",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+517,0,"cacop_flush_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"data_sram_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"data_sram_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"data_sram_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"data_sram_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+538,0,"data_sram_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"data_sram_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+545,0,"data_sram_addr_is_sram",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+316,0,"data_sram_store_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+312,0,"data_sram_addr_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"data_sram_data_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+262,0,"data_sram_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+314,0,"data_sram_fast_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+315,0,"data_sram_fast_data_ok",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+263,0,"data_sram_fast_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1435,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1283,0,"ms_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1752,0,"WAIT_NONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1753,0,"WAIT_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1754,0,"WAIT_CACOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1436,0,"ms_wait_kind",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+1437,0,"ms_result_forwardable_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1438,0,"ms_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"ms_alu_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1439,0,"ms_rkd_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1440,0,"ms_store_data_ready_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1441,0,"ms_store_data_src_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1286,0,"ms_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1284,0,"ms_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1442,0,"ms_mem_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1287,0,"ms_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1443,0,"ms_ld_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1444,0,"ms_ld_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1445,0,"ms_ld_sign_ext_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1446,0,"ms_st_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1447,0,"ms_st_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1448,0,"ms_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1449,0,"ms_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1450,0,"ms_is_bj_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1451,0,"ms_real_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1452,0,"ms_real_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1453,0,"ms_next_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1454,0,"ms_redirect_miss_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1455,0,"ms_is_cacop_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"ms_cacop_code_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1456,0,"ms_is_csr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1457,0,"ms_csr_num_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1458,0,"ms_csr_wmask_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1459,0,"ms_csr_wvalue_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1289,0,"ms_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1460,0,"ms_lane0_mem_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1461,0,"ms_lane1_mem_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"ms_selected_mem_we_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1462,0,"ms_selected_mem_we_ready_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1463,0,"ms_selected_target_ext_ready_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1464,0,"ms_addr_is_sram_0_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1465,0,"ms_addr_is_sram_1_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1466,0,"ms_lane1_mem_op_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1467,0,"ms_select_lane1_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1468,0,"ms_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1469,0,"ms_alu_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1470,0,"ms_rkd_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1471,0,"ms_res_from_mem_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1290,0,"ms_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1472,0,"ms_mem_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1292,0,"ms_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1473,0,"ms_ld_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1474,0,"ms_ld_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1475,0,"ms_ld_sign_ext_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1476,0,"ms_st_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1477,0,"ms_st_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1478,0,"ms_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1479,0,"ms_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1480,0,"ms_is_bj_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1481,0,"ms_real_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1482,0,"ms_real_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1483,0,"ms_next_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1484,0,"ms_redirect_miss_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+645,0,"es_store_data_late_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+646,0,"es_store_data_src_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+757,0,"es_result_forwardable_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"es_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+756,0,"es_final_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+644,0,"es_rkd_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+647,0,"es_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+648,0,"es_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+649,0,"es_mem_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+650,0,"es_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+657,0,"es_ld_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+658,0,"es_ld_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+659,0,"es_ld_sign_ext_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+660,0,"es_st_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+661,0,"es_st_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+662,0,"es_pred_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+663,0,"es_pred_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+758,0,"es_is_bj_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+759,0,"es_real_taken_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+760,0,"es_real_target_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+761,0,"es_next_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+768,0,"es_redirect_miss_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+667,0,"es_is_cacop_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+668,0,"es_cacop_code_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+669,0,"es_is_csr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+503,0,"es_csr_num_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+670,0,"es_csr_wmask_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+671,0,"es_csr_wvalue_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+673,0,"es_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+755,0,"es_final_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+677,0,"es_rkd_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+678,0,"es_res_from_mem_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+679,0,"es_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+680,0,"es_mem_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+681,0,"es_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+683,0,"es_ld_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+684,0,"es_ld_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+685,0,"es_ld_sign_ext_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+686,0,"es_st_byte_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+687,0,"es_st_half_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+688,0,"es_pred_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+689,0,"es_pred_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+762,0,"es_is_bj_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+763,0,"es_real_taken_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+764,0,"es_real_target_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+765,0,"es_next_pc_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+771,0,"es_redirect_miss_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1296,0,"ws_rf_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1297,0,"ws_rf_waddr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1298,0,"ws_rf_wdata_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1299,0,"ws_rf_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1300,0,"ws_rf_waddr_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1301,0,"ws_rf_wdata_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1485,0,"es_redirect_0_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1486,0,"es_lane1_eff_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1487,0,"es_lane0_mem_op_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1488,0,"es_lane1_mem_op_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1489,0,"ms_redirect_0_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1289,0,"ms_lane1_eff_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1490,0,"ms_redirect_1_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1491,0,"es_addr_is_sram_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1492,0,"es_addr_is_sram_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1460,0,"lane0_mem_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1467,0,"select_lane1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1493,0,"selected_addr_is_sram_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1494,0,"selected_res_from_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"selected_mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+538,0,"selected_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1495,0,"selected_rkd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1496,0,"selected_ld_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1497,0,"selected_ld_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1498,0,"selected_ld_sign_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1499,0,"selected_st_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1500,0,"selected_st_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1501,0,"selected_store_data_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1502,0,"ms_has_mem_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1503,0,"ms_has_cacop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1504,0,"dual_mem_phase_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1505,0,"ms_data_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1506,0,"ms_response_waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1507,0,"ms_fast_response_waiting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1508,0,"ms_addr_is_sram_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1509,0,"ms_rdata_buf_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1510,0,"ms_rdata_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1511,0,"cacop_req_sent",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+494,0,"branch_flush_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1512,0,"branch_target_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"got_addr_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1513,0,"ms_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1514,0,"ms_fast_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1515,0,"ms_fast_data_ok",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1509,0,"mem_data_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1516,0,"packet_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1517,0,"cacop_ready_go",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1518,0,"posted_store_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1519,0,"selected_mem_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1520,0,"phase_ready_go",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1521,0,"advance_to_lane1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"packet_ready_go",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1522,0,"ms_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1523,0,"branch_redirect_detect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1524,0,"branch_redirect_fire",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1525,0,"branch_redirect_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1526,0,"bpu_sel_lane1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"ms_st_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1527,0,"ms_st_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"ms_mem_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1730,0,"ms_final_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1731,0,"load_result__Vstatic__load_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1732,0,"load_result__Vstatic__load_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+1729,0,"selected_load_result_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1729,0,"ms_load_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1729,0,"ms_load_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1285,0,"ms_fwd_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1528,0,"ms_load_result_0_fwd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1288,0,"ms_fwd_data_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1529,0,"incoming_store_hit_response",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1530,0,"incoming_store_hit_ms",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1531,0,"incoming_store_hit_ws1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1532,0,"incoming_store_hit_ws0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1533,0,"incoming_store_data_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+301,0,"incoming_store_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1534,0,"held_store_hit_ws1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1535,0,"held_store_hit_ws0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1291,0,"ms_fwd_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1293,0,"ms_fwd_data_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_pc", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+519,0,"flush_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+540,0,"suspend",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+539,0,"inst_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1536,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_wb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1725,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"resetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+444,0,"ms_to_ws_valid_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+445,0,"ms_to_ws_valid_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+289,0,"ms_to_ws_bus_0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 184,0);
    VL_TRACE_DECL_QUAD(tracep,c+295,0,"ms_to_ws_bus_1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 37,0);
    VL_TRACE_DECL_BIT(tracep,c+1758,0,"ws_allowin",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+491,0,"ws_to_rf_bus",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 75,0);
    VL_TRACE_DECL_BIT(tracep,c+498,0,"csr_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+505,0,"csr_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+506,0,"csr_waddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+507,0,"csr_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+508,0,"csr_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"csr_ctx_update",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+514,0,"csr_flush",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+515,0,"csr_flush_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1537,0,"reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1538,0,"ws_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1539,0,"ws_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1540,0,"ws_alu_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1541,0,"ws_mem_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1542,0,"ws_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1543,0,"ws_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1297,0,"ws_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1544,0,"ws_ld_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1545,0,"ws_ld_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1546,0,"ws_ld_sign_ext_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1547,0,"ws_is_csr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1548,0,"ws_csr_num_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1549,0,"ws_csr_wmask_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1550,0,"ws_csr_wvalue_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1551,0,"ws_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1301,0,"ws_alu_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1552,0,"ws_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1300,0,"ws_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1769,0,"CSR_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1770,0,"CSR_APPLY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1771,0,"CSR_DISTRIBUTE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1772,0,"CSR_FLUSH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1553,0,"csr_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+506,0,"csr_pending_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+507,0,"csr_pending_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+508,0,"csr_pending_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+515,0,"csr_pending_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1438,0,"ms_pc_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"ms_alu_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1286,0,"ms_res_from_mem_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1284,0,"ms_gr_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1287,0,"ms_dest_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1443,0,"ms_ld_byte_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1444,0,"ms_ld_half_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1445,0,"ms_ld_sign_ext_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1730,0,"ms_mem_rdata_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1456,0,"ms_is_csr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1457,0,"ms_csr_num_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1458,0,"ms_csr_wmask_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1459,0,"ms_csr_wvalue_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1733,0,"ms_alu_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1290,0,"ms_gr_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1292,0,"ms_dest_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1734,0,"load_result__Vstatic__load_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1735,0,"load_result__Vstatic__load_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+1554,0,"ws_load_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1298,0,"final_result_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1301,0,"final_result_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1296,0,"ws_rf_we_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1297,0,"ws_rf_waddr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1298,0,"ws_rf_wdata_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1299,0,"ws_rf_we_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1300,0,"ws_rf_waddr_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1301,0,"ws_rf_wdata_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 1);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BIT(tracep,c+0,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BIT(tracep,c+4,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____1\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____1(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____1\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 1);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+3,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BUS(tracep,c+4,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+5,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+6,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_DECL_BUS(tracep,c+7,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 17,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____2\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____2(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____2\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 1);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+3,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BUS(tracep,c+4,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+5,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+6,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+7,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____3\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____3(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____3\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 1);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+3,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    VL_TRACE_DECL_BUS(tracep,c+4,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+6,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+7,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____4\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____4(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____4\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 1);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 7);
    VL_TRACE_DECL_BIT(tracep,c+0,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,fidx,"[4]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,fidx,"[5]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,fidx,"[6]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,fidx,"[7]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 7);
    VL_TRACE_DECL_BIT(tracep,c+8,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+9,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+10,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+11,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+12,fidx,"[4]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+13,fidx,"[5]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+14,fidx,"[6]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+15,fidx,"[7]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____5\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____5(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____5\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 7);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 24,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____6\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____6(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____6\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 7);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 24,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____7\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____7(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____7\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 7);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_WIDE_ARRAY(tracep,c+0+i*4,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 127,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____8\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____8(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____8\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 7);
    for (int i = 0; i < 8; ++i) {
        VL_TRACE_DECL_WIDE_ARRAY(tracep,c+0+i*4,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 127,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____9\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____9(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____9\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 3);
    for (int i = 0; i < 4; ++i) {
        VL_TRACE_DECL_WIDE_ARRAY(tracep,c+0+i*9,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 265,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype____10\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_dtype_sub____10(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_dtype_sub____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_dtype_sub____10\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 31, 0);
    for (int i = 0; i < 32; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (31 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+1015,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+1173,0,"dec_bus",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 168,0);
    VL_TRACE_DECL_BUS(tracep,c+1555,0,"op_31_26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+1556,0,"op_25_22",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1557,0,"op_21_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1558,0,"op_19_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1559,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1560,0,"rj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1561,0,"rk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1562,0,"i12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+1563,0,"i20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 19,0);
    VL_TRACE_DECL_BUS(tracep,c+1564,0,"i16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+1565,0,"i26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 25,0);
    VL_TRACE_DECL_QUAD(tracep,c+1566,0,"op_31_26_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+1568,0,"op_25_22_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+1569,0,"op_21_20_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1570,0,"op_19_15_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1571,0,"inst_add_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1572,0,"inst_sub_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1573,0,"inst_slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1574,0,"inst_sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1575,0,"inst_nor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1576,0,"inst_and",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1577,0,"inst_or",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1578,0,"inst_xor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1579,0,"inst_slli_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1580,0,"inst_srli_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1581,0,"inst_srai_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1582,0,"inst_addi_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1583,0,"inst_ld_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1584,0,"inst_st_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1585,0,"inst_jirl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1586,0,"inst_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1587,0,"inst_bl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1588,0,"inst_beq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1589,0,"inst_bne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1590,0,"inst_lu12i_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1591,0,"inst_slti",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1592,0,"inst_sltui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1593,0,"inst_andi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1594,0,"inst_ori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1595,0,"inst_xori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1596,0,"inst_sll_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1597,0,"inst_srl_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1598,0,"inst_sra_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1599,0,"inst_pcaddu12i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1600,0,"inst_blt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1601,0,"inst_bge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1602,0,"inst_bltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1603,0,"inst_bgeu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1604,0,"inst_ld_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1605,0,"inst_ld_h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1606,0,"inst_ld_bu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1607,0,"inst_ld_hu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1608,0,"inst_st_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1609,0,"inst_st_h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1610,0,"inst_mul_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1611,0,"inst_cpucfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1612,0,"inst_cacop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1613,0,"inst_csrwr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1614,0,"inst_csrxchg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1615,0,"inst_known",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1610,0,"is_mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1616,0,"ld_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1617,0,"ld_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1618,0,"ld_sign_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1608,0,"st_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1609,0,"st_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1619,0,"need_ui12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1620,0,"need_si20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1621,0,"need_si26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1622,0,"src2_is_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1623,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1624,0,"br_offs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1625,0,"jirl_offs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1626,0,"src_reg_is_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1627,0,"src1_is_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1628,0,"src2_is_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1629,0,"res_from_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1587,0,"dst_is_r1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1630,0,"gr_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1631,0,"mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1632,0,"dest",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1559,0,"cacop_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1633,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+1560,0,"rf_raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1634,0,"is_csr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1635,0,"csr_num",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1636,0,"rf_raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1637,0,"ds_need_rj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1638,0,"ds_need_rkd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1639,0,"ds_is_bj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1555,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_QUAD(tracep,c+1566,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1556,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1568,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1557,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1569,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec3", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1558,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1570,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_sub__TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1__0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+1016,0,"inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_WIDE(tracep,c+1179,0,"dec_bus",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 168,0);
    VL_TRACE_DECL_BUS(tracep,c+1640,0,"op_31_26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+1641,0,"op_25_22",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1642,0,"op_21_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1643,0,"op_19_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1644,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1645,0,"rj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1646,0,"rk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1647,0,"i12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+1648,0,"i20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 19,0);
    VL_TRACE_DECL_BUS(tracep,c+1649,0,"i16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+1650,0,"i26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 25,0);
    VL_TRACE_DECL_QUAD(tracep,c+1651,0,"op_31_26_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+1653,0,"op_25_22_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+1654,0,"op_21_20_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1655,0,"op_19_15_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1656,0,"inst_add_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1657,0,"inst_sub_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1658,0,"inst_slt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1659,0,"inst_sltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1660,0,"inst_nor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1661,0,"inst_and",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1662,0,"inst_or",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1663,0,"inst_xor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1664,0,"inst_slli_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1665,0,"inst_srli_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1666,0,"inst_srai_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1667,0,"inst_addi_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1668,0,"inst_ld_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1669,0,"inst_st_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1670,0,"inst_jirl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1671,0,"inst_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1672,0,"inst_bl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1673,0,"inst_beq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1674,0,"inst_bne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1675,0,"inst_lu12i_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1676,0,"inst_slti",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1677,0,"inst_sltui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1678,0,"inst_andi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1679,0,"inst_ori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1680,0,"inst_xori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1681,0,"inst_sll_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1682,0,"inst_srl_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1683,0,"inst_sra_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1684,0,"inst_pcaddu12i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1685,0,"inst_blt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1686,0,"inst_bge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1687,0,"inst_bltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1688,0,"inst_bgeu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1689,0,"inst_ld_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1690,0,"inst_ld_h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1691,0,"inst_ld_bu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1692,0,"inst_ld_hu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1693,0,"inst_st_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1694,0,"inst_st_h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1695,0,"inst_mul_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1696,0,"inst_cpucfg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1697,0,"inst_cacop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1698,0,"inst_csrwr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1699,0,"inst_csrxchg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1700,0,"inst_known",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1695,0,"is_mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1701,0,"ld_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1702,0,"ld_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1703,0,"ld_sign_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1693,0,"st_byte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1694,0,"st_half",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1704,0,"need_ui12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1705,0,"need_si20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1706,0,"need_si26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1707,0,"src2_is_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1708,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1709,0,"br_offs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1710,0,"jirl_offs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1711,0,"src_reg_is_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1712,0,"src1_is_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1713,0,"src2_is_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1714,0,"res_from_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1672,0,"dst_is_r1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1715,0,"gr_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1716,0,"mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1717,0,"dest",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1644,0,"cacop_code",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1718,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+1645,0,"rf_raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1719,0,"is_csr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1720,0,"csr_num",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 13,0);
    VL_TRACE_DECL_BUS(tracep,c+1721,0,"rf_raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1722,0,"ds_need_rj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1723,0,"ds_need_rkd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1724,0,"ds_is_bj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1640,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_QUAD(tracep,c+1651,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1641,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1653,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1642,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1654,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_dec3", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1643,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1655,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_init_top(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_init_top\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vasm_monitor_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vasm_monitor_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vasm_monitor_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_register(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_register\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vasm_monitor_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vasm_monitor_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vasm_monitor_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vasm_monitor_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_const_0_sub_0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_const_0\n"); );
    // Body
    Vasm_monitor_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vasm_monitor_tb___024root*>(voidSelf);
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vasm_monitor_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<10>/*319:0*/ Vasm_monitor_tb__ConstPool__CONST_h2933a6b8_0;

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_const_0_sub_0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_const_0_sub_0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1736,(0x00000026U),32);
    bufp->fullIData(oldp+1737,(0x00100000U),32);
    bufp->fullWData(oldp+1738,(Vasm_monitor_tb__ConstPool__CONST_h2933a6b8_0),304);
    bufp->fullBit(oldp+1748,(0U));
    bufp->fullCData(oldp+1749,(2U),2);
    bufp->fullCData(oldp+1750,(0U),4);
    bufp->fullIData(oldp+1751,(0U),32);
    bufp->fullCData(oldp+1752,(0U),2);
    bufp->fullCData(oldp+1753,(1U),2);
    bufp->fullCData(oldp+1754,(2U),2);
    bufp->fullCData(oldp+1755,(3U),2);
    bufp->fullBit(oldp+1756,(1U));
    bufp->fullCData(oldp+1757,(0U),5);
    bufp->fullBit(oldp+1758,(1U));
    bufp->fullIData(oldp+1759,(2U),32);
    bufp->fullIData(oldp+1760,(4U),32);
    bufp->fullIData(oldp+1761,(0x00000012U),32);
    bufp->fullSData(oldp+1762,(0U),14);
    bufp->fullSData(oldp+1763,(0x0180U),14);
    bufp->fullSData(oldp+1764,(0x0181U),14);
    bufp->fullIData(oldp+1765,(0x000001ffU),32);
    bufp->fullIData(oldp+1766,(0xee000039U),32);
    bufp->fullIData(oldp+1767,(1U),32);
    bufp->fullIData(oldp+1768,(0U),32);
    bufp->fullCData(oldp+1769,(0U),3);
    bufp->fullCData(oldp+1770,(1U),3);
    bufp->fullCData(oldp+1771,(2U),3);
    bufp->fullCData(oldp+1772,(3U),3);
    bufp->fullCData(oldp+1773,(4U),3);
    bufp->fullIData(oldp+1774,(0x00000099U),32);
    bufp->fullIData(oldp+1775,(0x00000094U),32);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_0_sub_0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_0\n"); );
    // Body
    Vasm_monitor_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vasm_monitor_tb___024root*>(voidSelf);
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vasm_monitor_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 2>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*17:0*/, 4>, 2>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*1:0*/, 4>, 2>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 2>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 8>, 2>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar);
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar);
extern const VlUnpacked<CData/*2:0*/, 2048> Vasm_monitor_tb__ConstPool__TABLE_he47f3c48_0;
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<9>/*265:0*/, 4>& __VdtypeVar);
extern const VlUnpacked<CData/*0:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h2c364be9_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h547ba932_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0;
VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_0_sub_0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_0_sub_0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<6>/*191:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_5;
    VlWide<5>/*159:0*/ __Vtemp_7;
    VlWide<8>/*255:0*/ __Vtemp_9;
    VlWide<5>/*159:0*/ __Vtemp_14;
    VlWide<7>/*223:0*/ __Vtemp_15;
    VlWide<8>/*255:0*/ __Vtemp_20;
    VlWide<10>/*319:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<7>/*223:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<4>/*127:0*/ __Vtemp_29;
    VlWide<9>/*287:0*/ __Vtemp_31;
    VlWide<9>/*287:0*/ __Vtemp_33;
    VlWide<6>/*191:0*/ __Vtemp_36;
    VlWide<4>/*127:0*/ __Vtemp_39;
    VlWide<6>/*191:0*/ __Vtemp_42;
    VlWide<4>/*127:0*/ __Vtemp_45;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n),32);
    bufp->fullIData(oldp+1,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__n),32);
    bufp->fullIData(oldp+2,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__mismatch_count),32);
    bufp->fullIData(oldp+3,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__addr),32);
    bufp->fullIData(oldp+4,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__actual),32);
    bufp->fullIData(oldp+5,(vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n),32);
    bufp->fullIData(oldp+6,(vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr),32);
    bufp->fullBit(oldp+7,(vlSelfRef.asm_monitor_tb__DOT__resetn));
    bufp->fullBit(oldp+8,(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready));
    bufp->fullCData(oldp+9,(vlSelfRef.asm_monitor_tb__DOT__uart_rx_data),8);
    bufp->fullIData(oldp+10,(vlSelfRef.asm_monitor_tb__DOT__i),32);
    bufp->fullIData(oldp+11,(vlSelfRef.asm_monitor_tb__DOT__base_words),32);
    bufp->fullIData(oldp+12,(vlSelfRef.asm_monitor_tb__DOT__program_words),32);
    bufp->fullIData(oldp+13,(vlSelfRef.asm_monitor_tb__DOT__watch_words),32);
    bufp->fullIData(oldp+14,(vlSelfRef.asm_monitor_tb__DOT__data_words),32);
    bufp->fullIData(oldp+15,(vlSelfRef.asm_monitor_tb__DOT__expect_words),32);
    bufp->fullIData(oldp+16,(vlSelfRef.asm_monitor_tb__DOT__init_fd),32);
    bufp->fullIData(oldp+17,(vlSelfRef.asm_monitor_tb__DOT__init_status),32);
    bufp->fullIData(oldp+18,(vlSelfRef.asm_monitor_tb__DOT__init_line_status),32);
    bufp->fullIData(oldp+19,(vlSelfRef.asm_monitor_tb__DOT__entry_addr),32);
    bufp->fullIData(oldp+20,(vlSelfRef.asm_monitor_tb__DOT__program_addr),32);
    bufp->fullIData(oldp+21,(vlSelfRef.asm_monitor_tb__DOT__watch_addr),32);
    bufp->fullIData(oldp+22,(vlSelfRef.asm_monitor_tb__DOT__data_load_addr),32);
    bufp->fullIData(oldp+23,(vlSelfRef.asm_monitor_tb__DOT__expect_addr),32);
    bufp->fullIData(oldp+24,(vlSelfRef.asm_monitor_tb__DOT__expect_value),32);
    bufp->fullIData(oldp+25,(vlSelfRef.asm_monitor_tb__DOT__init_addr),32);
    bufp->fullIData(oldp+26,(vlSelfRef.asm_monitor_tb__DOT__init_value),32);
    bufp->fullWData(oldp+27,(vlSelfRef.asm_monitor_tb__DOT__base_file),1024);
    bufp->fullWData(oldp+59,(vlSelfRef.asm_monitor_tb__DOT__program_file),1024);
    bufp->fullWData(oldp+91,(vlSelfRef.asm_monitor_tb__DOT__data_file),1024);
    bufp->fullWData(oldp+123,(vlSelfRef.asm_monitor_tb__DOT__expect_file),1024);
    bufp->fullWData(oldp+155,(vlSelfRef.asm_monitor_tb__DOT__init_file),1024);
    bufp->fullWData(oldp+187,(vlSelfRef.asm_monitor_tb__DOT__init_line),1024);
    bufp->fullWData(oldp+219,(vlSelfRef.asm_monitor_tb__DOT__wave_file),1024);
    bufp->fullBit(oldp+251,(vlSelfRef.asm_monitor_tb__DOT__data_enabled));
    bufp->fullBit(oldp+252,(vlSelfRef.asm_monitor_tb__DOT__expect_file_enabled));
    bufp->fullBit(oldp+253,(vlSelfRef.asm_monitor_tb__DOT__expect_value_enabled));
    bufp->fullQData(oldp+254,(vlSelfRef.asm_monitor_tb__DOT__max_cycles),64);
    bufp->fullQData(oldp+256,(vlSelfRef.asm_monitor_tb__DOT__wait_cycles),64);
    bufp->fullCData(oldp+258,(vlSelfRef.asm_monitor_tb__DOT__send_rx_byte__Vstatic__value),8);
    bufp->fullIData(oldp+259,(vlSelfRef.asm_monitor_tb__DOT__wait_tx__Vstatic__wanted),32);
    bufp->fullCData(oldp+260,((0x00000020U | (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready))),8);
    bufp->fullIData(oldp+261,((vlSelfRef.asm_monitor_tb__DOT__base_mem
                               [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr] 
                               & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_data_ok))))),32);
    bufp->fullIData(oldp+262,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                                ? vlSelfRef.asm_monitor_tb__DOT__base_mem
                               [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]
                                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok)
                                    ? vlSelfRef.asm_monitor_tb__DOT__ext_mem
                                   [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr]
                                    : (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg 
                                       & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid))))))),32);
    bufp->fullIData(oldp+263,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                                ? vlSelfRef.asm_monitor_tb__DOT__base_mem
                               [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]
                                : vlSelfRef.asm_monitor_tb__DOT__ext_mem
                               [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr])),32);
    bufp->fullIData(oldp+264,(vlSelfRef.asm_monitor_tb__DOT__base_mem
                              [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]),32);
    bufp->fullIData(oldp+265,(vlSelfRef.asm_monitor_tb__DOT__ext_mem
                              [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr]),32);
    bufp->fullIData(oldp+266,(vlSelfRef.asm_monitor_tb__DOT__tx_count),32);
    bufp->fullIData(oldp+267,(vlSelfRef.asm_monitor_tb__DOT__write_log_count),32);
    bufp->fullQData(oldp+268,(vlSelfRef.asm_monitor_tb__DOT__cycle_count),64);
    bufp->fullBit(oldp+270,(vlSelfRef.asm_monitor_tb__DOT__command_counting));
    bufp->fullBit(oldp+271,(vlSelfRef.asm_monitor_tb__DOT__command_done));
    bufp->fullBit(oldp+272,(vlSelfRef.asm_monitor_tb__DOT__user_counting));
    bufp->fullBit(oldp+273,(vlSelfRef.asm_monitor_tb__DOT__user_done));
    bufp->fullBit(oldp+274,(vlSelfRef.asm_monitor_tb__DOT__exit_seen));
    bufp->fullIData(oldp+275,(vlSelfRef.asm_monitor_tb__DOT__exit_pc),32);
    bufp->fullQData(oldp+276,(vlSelfRef.asm_monitor_tb__DOT__command_cycles),64);
    bufp->fullQData(oldp+278,(vlSelfRef.asm_monitor_tb__DOT__command_instr),64);
    bufp->fullQData(oldp+280,(vlSelfRef.asm_monitor_tb__DOT__user_cycles),64);
    bufp->fullQData(oldp+282,(vlSelfRef.asm_monitor_tb__DOT__user_instr),64);
    bufp->fullQData(oldp+284,(vlSelfRef.asm_monitor_tb__DOT__write_count),64);
    bufp->fullBit(oldp+286,(((IData)(vlSelfRef.asm_monitor_tb__DOT__exit_seen) 
                             & (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                  == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1)) 
                                | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                    == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0))))));
    bufp->fullCData(oldp+287,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset))
                                ? (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_data)
                                : ((- (IData)((5U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset)))) 
                                   & (0x00000020U | (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready))))),8);
    bufp->fullBit(oldp+288,(((((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1)) 
                              | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                  == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0))) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__program_exit))));
    __Vtemp_1[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0)) 
                                << 0x0000000aU) | (QData)((IData)(
                                                                  ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
                                                                     << 9U) 
                                                                    | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0) 
                                                                       << 8U)) 
                                                                   | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0))))))))) 
                      >> 0x00000011U) | ((IData)(((
                                                   ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0)) 
                                                    << 0x0000000aU) 
                                                   | (QData)((IData)(
                                                                     ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
                                                                        << 9U) 
                                                                       | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0) 
                                                                          << 8U)) 
                                                                      | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                                                                          << 3U) 
                                                                         | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0) 
                                                                             << 2U) 
                                                                            | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0) 
                                                                                << 1U) 
                                                                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0)))))))) 
                                                  >> 0x00000020U)) 
                                         << 0x0000000fU));
    __Vtemp_3[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0)) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0))));
    __Vtemp_3[1U] = (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0)) 
                               << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0))) 
                             >> 0x00000020U));
    __Vtemp_3[2U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata)) 
                              << 0x0000000fU) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0) 
                                                                  << 0x0000000eU) 
                                                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0))))));
    __Vtemp_3[3U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0)) 
                                << 0x0000000aU) | (QData)((IData)(
                                                                  ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0) 
                                                                     << 9U) 
                                                                    | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0) 
                                                                       << 8U)) 
                                                                   | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                                                                       << 3U) 
                                                                      | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0) 
                                                                          << 2U) 
                                                                         | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0) 
                                                                             << 1U) 
                                                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0))))))))) 
                      << 0x0000000fU) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata)) 
                                                   << 0x0000000fU) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0) 
                                                                      << 0x0000000eU) 
                                                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0))))) 
                                                 >> 0x00000020U)));
    __Vtemp_3[4U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                      << 0x00000019U) | __Vtemp_1[2U]);
    __Vtemp_3[5U] = (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                     >> 7U);
    bufp->fullWData(oldp+289,(__Vtemp_3),185);
    bufp->fullQData(oldp+295,((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ms_alu_result_1)) 
                                << 6U) | (QData)((IData)(
                                                         (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1) 
                                                           << 5U) 
                                                          | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)))))),38);
    bufp->fullIData(oldp+297,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)),32);
    bufp->fullIData(oldp+298,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0)),32);
    bufp->fullIData(oldp+299,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_0)),32);
    bufp->fullIData(oldp+300,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src2_0)),32);
    bufp->fullIData(oldp+301,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms)
                                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0
                                    : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1)
                                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                        : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0)
                                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))))),32);
    bufp->fullBit(oldp+302,((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))));
    bufp->fullIData(oldp+303,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr),32);
    bufp->fullBit(oldp+304,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr_ok));
    bufp->fullBit(oldp+305,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_data_ok));
    bufp->fullBit(oldp+306,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_req));
    bufp->fullBit(oldp+307,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q));
    bufp->fullCData(oldp+308,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_half) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half))
                                 ? 1U : 2U) & (- (IData)(
                                                         (1U 
                                                          & (~ 
                                                             ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_byte) 
                                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte)))))))),2);
    bufp->fullCData(oldp+309,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_wstrb),4);
    bufp->fullIData(oldp+310,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__paddr),32);
    bufp->fullIData(oldp+311,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_wdata),32);
    bufp->fullBit(oldp+312,((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept)) 
                             | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant) 
                                | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant) 
                                   | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept))))));
    bufp->fullBit(oldp+313,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_data_ok));
    bufp->fullBit(oldp+314,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_fast_ready));
    bufp->fullBit(oldp+315,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg))));
    bufp->fullCData(oldp+316,((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_ready) 
                                << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_ready))),2);
    bufp->fullIData(oldp+317,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr),20);
    bufp->fullIData(oldp+318,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr),20);
    bufp->fullIData(oldp+319,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_wdata),32);
    bufp->fullIData(oldp+320,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_wdata),32);
    bufp->fullCData(oldp+321,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_be_n),4);
    bufp->fullCData(oldp+322,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_be_n),4);
    bufp->fullBit(oldp+323,((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active))))));
    bufp->fullBit(oldp+324,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active)))));
    bufp->fullBit(oldp+325,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain)))));
    bufp->fullBit(oldp+326,((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active))))));
    bufp->fullBit(oldp+327,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active)))));
    bufp->fullBit(oldp+328,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain)))));
    bufp->fullBit(oldp+329,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg));
    bufp->fullBit(oldp+330,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_start_reg));
    bufp->fullCData(oldp+331,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_data_reg),8);
    bufp->fullIData(oldp+332,(vlSelfRef.asm_monitor_tb__DOT__branch_next_pc),32);
    bufp->fullCData(oldp+333,((3U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1) 
                                     + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0)))),2);
    bufp->fullBit(oldp+334,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                   >> 0x00000018U))));
    bufp->fullBit(oldp+335,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                   >> 0x00000016U))));
    bufp->fullCData(oldp+336,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state),2);
    bufp->fullBit(oldp+337,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data));
    bufp->fullBit(oldp+338,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg));
    bufp->fullBit(oldp+339,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg));
    bufp->fullIData(oldp+340,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg),32);
    bufp->fullBit(oldp+341,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid));
    bufp->fullIData(oldp+342,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_addr),32);
    bufp->fullIData(oldp+343,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wdata),32);
    bufp->fullCData(oldp+344,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wstrb),4);
    bufp->fullBit(oldp+345,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_resp_valid));
    bufp->fullBit(oldp+346,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_req));
    bufp->fullBit(oldp+347,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_req))));
    bufp->fullBit(oldp+348,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain));
    bufp->fullBit(oldp+349,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_ready));
    bufp->fullBit(oldp+350,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept));
    bufp->fullBit(oldp+351,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_read));
    bufp->fullBit(oldp+352,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data));
    bufp->fullBit(oldp+353,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant));
    bufp->fullBit(oldp+354,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state))));
    bufp->fullIData(oldp+355,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__paddr
                                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr_ok)
                                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr
                                    : vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg))),32);
    bufp->fullBit(oldp+356,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active));
    bufp->fullBit(oldp+357,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active))));
    bufp->fullBit(oldp+358,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept))));
    bufp->fullBit(oldp+359,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok));
    bufp->fullCData(oldp+360,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state),2);
    bufp->fullBit(oldp+361,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg));
    bufp->fullBit(oldp+362,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg));
    bufp->fullIData(oldp+363,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg),32);
    bufp->fullBit(oldp+364,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid));
    bufp->fullIData(oldp+365,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_addr),32);
    bufp->fullIData(oldp+366,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wdata),32);
    bufp->fullCData(oldp+367,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wstrb),4);
    bufp->fullBit(oldp+368,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_resp_valid));
    bufp->fullBit(oldp+369,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_req));
    bufp->fullBit(oldp+370,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_req))));
    bufp->fullBit(oldp+371,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain));
    bufp->fullBit(oldp+372,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_ready));
    bufp->fullBit(oldp+373,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept));
    bufp->fullBit(oldp+374,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant));
    bufp->fullBit(oldp+375,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state))));
    bufp->fullIData(oldp+376,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__paddr
                                : vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg)),32);
    bufp->fullBit(oldp+377,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active));
    bufp->fullBit(oldp+378,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active))));
    bufp->fullBit(oldp+379,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept))));
    bufp->fullBit(oldp+380,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok));
    bufp->fullCData(oldp+381,((7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr)),3);
    bufp->fullBit(oldp+382,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab));
    bufp->fullCData(oldp+383,((0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_wdata)),8);
    bufp->fullBit(oldp+384,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                              >> 0x00000018U) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_req))));
    bufp->fullBit(oldp+385,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
                             & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab)) 
                                & (0U == (7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr))))));
    bufp->fullBit(oldp+386,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending));
    bufp->fullBit(oldp+387,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr));
    bufp->fullCData(oldp+388,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset),3);
    bufp->fullCData(oldp+389,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_write_byte),8);
    bufp->fullBit(oldp+390,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant));
    bufp->fullBit(oldp+391,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_exec_tx_write));
    bufp->fullBit(oldp+392,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid));
    bufp->fullIData(oldp+393,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg),32);
    bufp->fullBit(oldp+394,((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))));
    bufp->fullIData(oldp+395,((0xfffffff0U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr)),32);
    bufp->fullBit(oldp+396,((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))));
    bufp->fullBit(oldp+397,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r));
    bufp->fullCData(oldp+398,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r),2);
    bufp->fullIData(oldp+399,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r),32);
    bufp->fullBit(oldp+400,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_allowin));
    bufp->fullBit(oldp+401,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go));
    bufp->fullBit(oldp+402,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0));
    bufp->fullBit(oldp+403,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1));
    __Vtemp_4[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))));
    __Vtemp_4[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                      << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))) 
                                        >> 0x00000020U)));
    __Vtemp_4[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                      >> 0x0000001fU) | ((IData)(((
                                                   ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                                    << 0x00000020U) 
                                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                                                  >> 0x00000020U)) 
                                         << 1U));
    __Vtemp_4[3U] = ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                              >> 0x00000020U)) >> 0x0000001fU);
    bufp->fullWData(oldp+404,(__Vtemp_4),97);
    __Vtemp_5[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                              << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))));
    __Vtemp_5[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                      << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                                          << 0x00000020U) 
                                         | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))) 
                                        >> 0x00000020U)));
    __Vtemp_5[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                      >> 0x0000001fU) | ((IData)(((
                                                   ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                                    << 0x00000020U) 
                                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                                                  >> 0x00000020U)) 
                                         << 1U));
    __Vtemp_5[3U] = ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                              >> 0x00000020U)) >> 0x0000001fU);
    bufp->fullWData(oldp+408,(__Vtemp_5),97);
    bufp->fullBit(oldp+412,((2U >= (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt))));
    bufp->fullBit(oldp+413,((2U < (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt))));
    bufp->fullBit(oldp+414,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r));
    bufp->fullBit(oldp+415,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r));
    bufp->fullWData(oldp+416,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0),266);
    bufp->fullWData(oldp+425,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1),266);
    bufp->fullCData(oldp+434,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r),5);
    bufp->fullCData(oldp+435,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0),5);
    bufp->fullCData(oldp+436,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot),5);
    bufp->fullCData(oldp+437,((0x0000001fU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                      >> 0x0000000dU)))),5);
    bufp->fullBit(oldp+438,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__pop_0));
    bufp->fullBit(oldp+439,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__pop_1));
    bufp->fullBit(oldp+440,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_to_es_valid_0));
    bufp->fullBit(oldp+441,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_to_es_valid_1));
    bufp->fullBit(oldp+442,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_to_ms_valid_0));
    bufp->fullBit(oldp+443,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_to_ms_valid_1));
    bufp->fullBit(oldp+444,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0));
    bufp->fullBit(oldp+445,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1));
    __Vtemp_7[4U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_late_0) 
                                                  << 5U) 
                                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))) 
                                << 0x0000002cU) | (
                                                   ((QData)((IData)(
                                                                    ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U] 
                                                                      << 0x0000001fU) 
                                                                     | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U] 
                                                                        >> 1U)))) 
                                                    << 0x0000000cU) 
                                                   | (QData)((IData)(
                                                                     (0x00000fffU 
                                                                      & (IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 
                                                                                >> 0x0000001dU)))))))) 
                      >> 0x00000012U) | ((IData)(((
                                                   ((QData)((IData)(
                                                                    (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_late_0) 
                                                                      << 5U) 
                                                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))) 
                                                    << 0x0000002cU) 
                                                   | (((QData)((IData)(
                                                                       ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U] 
                                                                         << 0x0000001fU) 
                                                                        | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U] 
                                                                           >> 1U)))) 
                                                       << 0x0000000cU) 
                                                      | (QData)((IData)(
                                                                        (0x00000fffU 
                                                                         & (IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 
                                                                                >> 0x0000001dU))))))) 
                                                  >> 0x00000020U)) 
                                         << 0x0000000eU));
    __Vtemp_9[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_offs_0)) 
                              << 0x00000019U) | (QData)((IData)(
                                                                ((0x01fffffcU 
                                                                  & ((IData)(
                                                                             (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                                              >> 7U)) 
                                                                     << 2U)) 
                                                                 | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0) 
                                                                     << 1U) 
                                                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)))))));
    __Vtemp_9[1U] = (((IData)(((0x0000001ffffffff0ULL 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                   << 4U)) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_0)))) 
                      << 0x00000019U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_offs_0)) 
                                                   << 0x00000019U) 
                                                  | (QData)((IData)(
                                                                    ((0x01fffffcU 
                                                                      & ((IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                                                >> 7U)) 
                                                                         << 2U)) 
                                                                     | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0) 
                                                                         << 1U) 
                                                                        | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)))))) 
                                                 >> 0x00000020U)));
    __Vtemp_9[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0)) 
                                << 0x0000000eU) | (QData)((IData)(
                                                                  ((0x00003800U 
                                                                    & ((IData)(
                                                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                                >> 3U)) 
                                                                       << 0x0000000bU)) 
                                                                   | ((0x000007c0U 
                                                                       & ((IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                                >> 8U)) 
                                                                          << 6U)) 
                                                                      | (0x0000003fU 
                                                                         & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                                                                            >> 4U)))))))) 
                      << 0x0000001eU) | (((IData)((
                                                   (0x0000001ffffffff0ULL 
                                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                                       << 4U)) 
                                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_0)))) 
                                          >> 7U) | 
                                         ((IData)((
                                                   ((0x0000001ffffffff0ULL 
                                                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                                        << 4U)) 
                                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_0))) 
                                                   >> 0x00000020U)) 
                                          << 0x00000019U)));
    __Vtemp_9[3U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0)) 
                                << 0x0000000eU) | (QData)((IData)(
                                                                  ((0x00003800U 
                                                                    & ((IData)(
                                                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                                >> 3U)) 
                                                                       << 0x0000000bU)) 
                                                                   | ((0x000007c0U 
                                                                       & ((IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                                >> 8U)) 
                                                                          << 6U)) 
                                                                      | (0x0000003fU 
                                                                         & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                                                                            >> 4U)))))))) 
                      >> 2U) | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0)) 
                                           << 0x0000000eU) 
                                          | (QData)((IData)(
                                                            ((0x00003800U 
                                                              & ((IData)(
                                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                          >> 3U)) 
                                                                 << 0x0000000bU)) 
                                                             | ((0x000007c0U 
                                                                 & ((IData)(
                                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                             >> 8U)) 
                                                                    << 6U)) 
                                                                | (0x0000003fU 
                                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                                                                      >> 4U))))))) 
                                         >> 0x00000020U)) 
                                << 0x0000001eU));
    __Vtemp_9[4U] = (((0x3ffff000U & ((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0)))) 
                                      << 0x0000000cU)) 
                      | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0)) 
                                    << 0x0000000eU) 
                                   | (QData)((IData)(
                                                     ((0x00003800U 
                                                       & ((IData)(
                                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                   >> 3U)) 
                                                          << 0x0000000bU)) 
                                                      | ((0x000007c0U 
                                                          & ((IData)(
                                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                                      >> 8U)) 
                                                             << 6U)) 
                                                         | (0x0000003fU 
                                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                                                               >> 4U))))))) 
                                  >> 0x00000020U)) 
                         >> 2U)) | (0xc0000000U & ((IData)(
                                                           (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0)))) 
                                                   << 0x0000000cU)));
    __Vtemp_9[5U] = ((((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0)))) 
                       >> 0x00000014U) | (0x3ffff000U 
                                          & ((IData)(
                                                     ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                                        << 0x00000020U) 
                                                       | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0))) 
                                                      >> 0x00000020U)) 
                                             << 0x0000000cU))) 
                     | (0xc0000000U & ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0))) 
                                                >> 0x00000020U)) 
                                       << 0x0000000cU)));
    __Vtemp_9[6U] = ((((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                  << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0))) 
                                >> 0x00000020U)) >> 0x00000014U) 
                      | (0x3ffff000U & ((IData)((((QData)((IData)(
                                                                  (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_late_0) 
                                                                    << 5U) 
                                                                   | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))) 
                                                  << 0x0000002cU) 
                                                 | (((QData)((IData)(
                                                                     ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U] 
                                                                       << 0x0000001fU) 
                                                                      | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U] 
                                                                         >> 1U)))) 
                                                     << 0x0000000cU) 
                                                    | (QData)((IData)(
                                                                      (0x00000fffU 
                                                                       & (IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 
                                                                                >> 0x0000001dU)))))))) 
                                        << 0x0000000cU))) 
                     | (__Vtemp_7[4U] << 0x0000001eU));
    __Vtemp_9[7U] = (__Vtemp_7[4U] >> 2U);
    bufp->fullWData(oldp+446,(__Vtemp_9),254);
    __Vtemp_14[3U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_1 
                       << 0x00000013U) | (((IData)(
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1)) 
                                                     << 8U) 
                                                    | (QData)((IData)(
                                                                      ((0x000000e0U 
                                                                        & ((IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                                                >> 3U)) 
                                                                           << 5U)) 
                                                                       | (0x0000001fU 
                                                                          & (IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                                                >> 8U)))))))) 
                                           >> 0x00000015U) 
                                          | ((IData)(
                                                     ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1)) 
                                                        << 8U) 
                                                       | (QData)((IData)(
                                                                         ((0x000000e0U 
                                                                           & ((IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                                                >> 3U)) 
                                                                              << 5U)) 
                                                                          | (0x0000001fU 
                                                                             & (IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                                                >> 8U))))))) 
                                                      >> 0x00000020U)) 
                                             << 0x0000000bU)));
    __Vtemp_15[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1)) 
                               << 0x00000020U) | (QData)((IData)(
                                                                 (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                                                                  >> 0x0000000aU)))));
    __Vtemp_15[1U] = (((IData)((0x00000001ffffffffULL 
                                & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0)) 
                       << 4U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                                                             >> 0x0000000aU)))) 
                                         >> 0x00000020U)));
    __Vtemp_15[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1)) 
                                 << 8U) | (QData)((IData)(
                                                          ((0x000000e0U 
                                                            & ((IData)(
                                                                       (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                                        >> 3U)) 
                                                               << 5U)) 
                                                           | (0x0000001fU 
                                                              & (IData)(
                                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                                         >> 8U)))))))) 
                       << 0x0000000bU) | ((0x000007e0U 
                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[4U] 
                                              << 1U)) 
                                          | (((IData)(
                                                      (0x00000001ffffffffULL 
                                                       & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0)) 
                                              >> 0x0000001cU) 
                                             | ((IData)(
                                                        ((0x00000001ffffffffULL 
                                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0) 
                                                         >> 0x00000020U)) 
                                                << 4U))));
    __Vtemp_15[3U] = __Vtemp_14[3U];
    __Vtemp_15[4U] = (((IData)((((QData)((IData)((0x00000fffU 
                                                  & (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                             >> 0x0000001dU))))) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1)))) 
                       << 0x00000013U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_1 
                                          >> 0x0000000dU));
    __Vtemp_15[5U] = (((IData)((((QData)((IData)((0x00000fffU 
                                                  & (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                             >> 0x0000001dU))))) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1)))) 
                       >> 0x0000000dU) | (((0xfffff000U 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U] 
                                               << 0x0000000bU)) 
                                           | (IData)(
                                                     ((((QData)((IData)(
                                                                        (0x00000fffU 
                                                                         & (IData)(
                                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                                                >> 0x0000001dU))))) 
                                                        << 0x00000020U) 
                                                       | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1))) 
                                                      >> 0x00000020U))) 
                                          << 0x00000013U));
    __Vtemp_15[6U] = ((((0xfffff000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U] 
                                        << 0x0000000bU)) 
                        | (IData)(((((QData)((IData)(
                                                     (0x00000fffU 
                                                      & (IData)(
                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                                 >> 0x0000001dU))))) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1))) 
                                   >> 0x00000020U))) 
                       >> 0x0000000dU) | (((0x00000800U 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[3U] 
                                               << 0x0000000bU)) 
                                           | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U] 
                                              >> 0x00000015U)) 
                                          << 0x00000013U));
    bufp->fullWData(oldp+454,(__Vtemp_15),223);
    bufp->fullIData(oldp+461,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_0),32);
    bufp->fullIData(oldp+462,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src2_0),32);
    bufp->fullIData(oldp+463,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_1),32);
    bufp->fullIData(oldp+464,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src2_1),32);
    __Vtemp_20[3U] = ((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0) 
                          << 0x0000000dU) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0) 
                                              << 0x0000000cU) 
                                             | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0) 
                                                << 0x0000000bU))) 
                        | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0) 
                             << 6U) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0) 
                                       << 5U)) | ((
                                                   ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0) 
                                                    << 4U) 
                                                   | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0) 
                                                       << 3U) 
                                                      | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0) 
                                                         << 2U))) 
                                                  | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0) 
                                                      << 1U) 
                                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0))))) 
                       << 0x00000018U) | (((IData)(
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0)) 
                                                     << 2U) 
                                                    | (QData)((IData)(
                                                                      (((0U 
                                                                         != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
                                                                        << 1U) 
                                                                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0)))))) 
                                           >> 0x0000000aU) 
                                          | ((IData)(
                                                     ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0)) 
                                                        << 2U) 
                                                       | (QData)((IData)(
                                                                         (((0U 
                                                                            != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
                                                                           << 1U) 
                                                                          | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0))))) 
                                                      >> 0x00000020U)) 
                                             << 0x00000016U)));
    __Vtemp_20[4U] = (((0x00ffffc0U & ((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0)))) 
                                       << 6U)) | ((
                                                   (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0) 
                                                     << 0x0000000dU) 
                                                    | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0) 
                                                        << 0x0000000cU) 
                                                       | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0) 
                                                          << 0x0000000bU))) 
                                                   | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0) 
                                                        << 6U) 
                                                       | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0) 
                                                          << 5U)) 
                                                      | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0) 
                                                           << 4U) 
                                                          | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0) 
                                                              << 3U) 
                                                             | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0) 
                                                                << 2U))) 
                                                         | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0) 
                                                             << 1U) 
                                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0))))) 
                                                  >> 8U)) 
                      | (0xff000000U & ((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                  << 0x00000020U) 
                                                 | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0)))) 
                                        << 6U)));
    __Vtemp_20[5U] = ((((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                  << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0)))) 
                        >> 0x0000001aU) | (0x00ffffc0U 
                                           & ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                         << 0x00000020U) 
                                                        | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))) 
                                                       >> 0x00000020U)) 
                                              << 6U))) 
                      | (0xff000000U & ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))) 
                                                 >> 0x00000020U)) 
                                        << 6U)));
    __Vtemp_20[6U] = (((0x00ffffc0U & ((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                                 << 0x00000026U) 
                                                | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0)) 
                                                    << 0x00000021U) 
                                                   | (((QData)((IData)(
                                                                       (1U 
                                                                        & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_49))))) 
                                                       << 0x00000020U) 
                                                      | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)))))) 
                                       << 6U)) | ((IData)(
                                                          ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))) 
                                                           >> 0x00000020U)) 
                                                  >> 0x0000001aU)) 
                      | (0xff000000U & ((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                                  << 0x00000026U) 
                                                 | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0)) 
                                                     << 0x00000021U) 
                                                    | (((QData)((IData)(
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_49))))) 
                                                        << 0x00000020U) 
                                                       | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)))))) 
                                        << 6U)));
    __Vtemp_20[7U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                 << 0x00000026U) | 
                                (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0)) 
                                  << 0x00000021U) | 
                                 (((QData)((IData)(
                                                   (1U 
                                                    & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_49))))) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)))))) 
                       >> 0x0000001aU) | (0x00ffffc0U 
                                          & ((IData)(
                                                     ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                                        << 0x00000026U) 
                                                       | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0)) 
                                                           << 0x00000021U) 
                                                          | (((QData)((IData)(
                                                                              (1U 
                                                                               & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_49))))) 
                                                              << 0x00000020U) 
                                                             | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0))))) 
                                                      >> 0x00000020U)) 
                                             << 6U)));
    __Vtemp_21[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0)) 
                               << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0))));
    __Vtemp_21[1U] = (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0)) 
                                << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0))) 
                              >> 0x00000020U));
    __Vtemp_21[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)) 
                                 << 0x00000020U) | (QData)((IData)(
                                                                   ((IData)(4U) 
                                                                    + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0))))) 
                       << 0x00000016U) | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0) 
                                            << 0x00000015U) 
                                           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0) 
                                              << 0x00000014U)) 
                                          | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_cacop_code_0) 
                                              << 0x0000000fU) 
                                             | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0) 
                                                 << 0x0000000eU) 
                                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0)))));
    __Vtemp_21[3U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)) 
                                 << 0x00000020U) | (QData)((IData)(
                                                                   ((IData)(4U) 
                                                                    + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0))))) 
                       >> 0x0000000aU) | ((IData)((
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)))) 
                                                   >> 0x00000020U)) 
                                          << 0x00000016U));
    __Vtemp_21[4U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0)) 
                                 << 2U) | (QData)((IData)(
                                                          (((0U 
                                                             != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
                                                            << 1U) 
                                                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0)))))) 
                       << 0x00000016U) | ((IData)((
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)))) 
                                                   >> 0x00000020U)) 
                                          >> 0x0000000aU));
    __Vtemp_21[5U] = __Vtemp_20[3U];
    __Vtemp_21[6U] = __Vtemp_20[4U];
    __Vtemp_21[7U] = __Vtemp_20[5U];
    __Vtemp_21[8U] = __Vtemp_20[6U];
    __Vtemp_21[9U] = __Vtemp_20[7U];
    bufp->fullWData(oldp+465,(__Vtemp_21),301);
    __Vtemp_25[3U] = (((IData)((((QData)((IData)(((
                                                   ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1) 
                                                    << 4U) 
                                                   | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1) 
                                                       << 3U) 
                                                      | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1) 
                                                         << 2U))) 
                                                  | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1) 
                                                      << 1U) 
                                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1))))) 
                                 << 0x00000022U) | 
                                (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1)) 
                                  << 2U) | (QData)((IData)(
                                                           (((0U 
                                                              != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                                                             << 1U) 
                                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1))))))) 
                       >> 0x0000001fU) | ((IData)((
                                                   (((QData)((IData)(
                                                                     ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1) 
                                                                        << 4U) 
                                                                       | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1) 
                                                                           << 3U) 
                                                                          | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1) 
                                                                             << 2U))) 
                                                                      | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1) 
                                                                          << 1U) 
                                                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1))))) 
                                                     << 0x00000022U) 
                                                    | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1)) 
                                                        << 2U) 
                                                       | (QData)((IData)(
                                                                         (((0U 
                                                                            != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                                                                           << 1U) 
                                                                          | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1)))))) 
                                                   >> 0x00000020U)) 
                                          << 1U));
    __Vtemp_26[0U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)) 
                                 << 0x00000020U) | (QData)((IData)(
                                                                   ((IData)(4U) 
                                                                    + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1))))) 
                       << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_1));
    __Vtemp_26[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)) 
                                 << 0x00000020U) | (QData)((IData)(
                                                                   ((IData)(4U) 
                                                                    + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1))))) 
                       >> 0x0000001fU) | ((IData)((
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)))) 
                                                   >> 0x00000020U)) 
                                          << 1U));
    __Vtemp_26[2U] = (((IData)((((QData)((IData)(((
                                                   ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1) 
                                                    << 4U) 
                                                   | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1) 
                                                       << 3U) 
                                                      | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1) 
                                                         << 2U))) 
                                                  | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1) 
                                                      << 1U) 
                                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1))))) 
                                 << 0x00000022U) | 
                                (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1)) 
                                  << 2U) | (QData)((IData)(
                                                           (((0U 
                                                              != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                                                             << 1U) 
                                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1))))))) 
                       << 1U) | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(
                                                             ((IData)(4U) 
                                                              + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)))) 
                                          >> 0x00000020U)) 
                                 >> 0x0000001fU));
    __Vtemp_26[3U] = (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1 
                        << 0x00000011U) | (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1) 
                                              << 8U) 
                                             | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1) 
                                                 << 7U) 
                                                | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1) 
                                                   << 6U))) 
                                            | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1) 
                                                << 1U) 
                                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1))) 
                                           << 8U)) 
                      | __Vtemp_25[3U]);
    __Vtemp_26[4U] = (((0x000000ffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1 
                                       >> 0x0000000fU)) 
                       | (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1) 
                             << 8U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1) 
                                        << 7U) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1) 
                                                  << 6U))) 
                           | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1) 
                               << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1))) 
                          >> 0x00000018U)) | ((0x0001ff00U 
                                               & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1 
                                                  >> 0x0000000fU)) 
                                              | ((IData)(
                                                         (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                           << 0x00000020U) 
                                                          | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1)))) 
                                                 << 0x00000011U)));
    __Vtemp_26[5U] = ((0x000000ffU & ((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1)))) 
                                      >> 0x0000000fU)) 
                      | ((0x0001ff00U & ((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1)))) 
                                         >> 0x0000000fU)) 
                         | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                       << 0x00000020U) 
                                      | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))) 
                                     >> 0x00000020U)) 
                            << 0x00000011U)));
    __Vtemp_26[6U] = ((0x000000ffU & ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))) 
                                               >> 0x00000020U)) 
                                      >> 0x0000000fU)) 
                      | (0x0001ff00U & ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))) 
                                                 >> 0x00000020U)) 
                                        >> 0x0000000fU)));
    bufp->fullWData(oldp+475,(__Vtemp_26),209);
    bufp->fullQData(oldp+482,((((QData)((IData)((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                                                  << 1U) 
                                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0)))) 
                                << 0x00000027U) | (
                                                   ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0)) 
                                                    << 0x00000026U) 
                                                   | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0)) 
                                                       << 0x00000025U) 
                                                      | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0)) 
                                                          << 0x00000020U) 
                                                         | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0))))))),41);
    bufp->fullQData(oldp+484,((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1)) 
                                << 0x00000027U) | (
                                                   ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1)) 
                                                    << 0x00000026U) 
                                                   | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1)) 
                                                       << 0x00000025U) 
                                                      | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1)) 
                                                          << 0x00000020U) 
                                                         | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))))))),40);
    bufp->fullQData(oldp+486,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_0),41);
    bufp->fullQData(oldp+488,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_1),40);
    bufp->fullBit(oldp+490,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__load_wakeup_valid));
    __Vtemp_28[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1)) 
                               << 0x00000025U) | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                                                   << 0x00000020U) 
                                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1)))));
    __Vtemp_28[1U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0 
                       << 6U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1)) 
                                           << 0x00000025U) 
                                          | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                                              << 0x00000020U) 
                                             | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1)))) 
                                         >> 0x00000020U)));
    __Vtemp_28[2U] = ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0) 
                        << 0x0000000bU) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                                           << 6U)) 
                      | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0 
                         >> 0x0000001aU));
    bufp->fullWData(oldp+491,(__Vtemp_28),76);
    bufp->fullBit(oldp+494,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q));
    bufp->fullIData(oldp+495,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q 
                               & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q))))),32);
    bufp->fullBit(oldp+496,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0))));
    bufp->fullBit(oldp+497,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0))));
    bufp->fullBit(oldp+498,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_is_csr_0)) 
                             | (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)))));
    bufp->fullBit(oldp+499,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0))));
    bufp->fullBit(oldp+500,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_cacop_0))));
    bufp->fullBit(oldp+501,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__special_block));
    bufp->fullBit(oldp+502,(((IData)((0ULL != (0x0000000010400000ULL 
                                               & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2))) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_to_es_valid_0))));
    bufp->fullSData(oldp+503,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0),14);
    bufp->fullIData(oldp+504,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0))
                                ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg)
                                : ((0x0180U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0))
                                    ? (0xee000039U 
                                       & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg)
                                    : (0xee000039U 
                                       & ((- (IData)(
                                                     (0x0181U 
                                                      == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0)))) 
                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg))))),32);
    bufp->fullBit(oldp+505,((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))));
    bufp->fullSData(oldp+506,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr),14);
    bufp->fullIData(oldp+507,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask),32);
    bufp->fullIData(oldp+508,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data),32);
    bufp->fullIData(oldp+509,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg),32);
    bufp->fullIData(oldp+510,((0xee000039U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg)),32);
    bufp->fullIData(oldp+511,((0xee000039U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg)),32);
    bufp->fullSData(oldp+512,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg),14);
    bufp->fullBit(oldp+513,((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))));
    bufp->fullBit(oldp+514,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))));
    bufp->fullIData(oldp+515,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target),32);
    bufp->fullBit(oldp+516,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_flush));
    bufp->fullIData(oldp+517,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0)),32);
    bufp->fullBit(oldp+518,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__flush));
    bufp->fullIData(oldp+519,(((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target
                                : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_flush)
                                    ? ((IData)(4U) 
                                       + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0)
                                    : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q 
                                       & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q))))))),32);
    bufp->fullBit(oldp+520,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_taken));
    bufp->fullIData(oldp+521,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_target),32);
    bufp->fullBit(oldp+522,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_lane));
    bufp->fullBit(oldp+523,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_lane)) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_taken))));
    bufp->fullBit(oldp+524,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__id_valid));
    bufp->fullIData(oldp+525,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc),32);
    bufp->fullBit(oldp+526,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken));
    bufp->fullIData(oldp+527,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target),32);
    bufp->fullBit(oldp+528,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__icacop_req_valid));
    bufp->fullBit(oldp+529,((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))));
    bufp->fullCData(oldp+530,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_cacop_code_0),5);
    bufp->fullIData(oldp+531,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0),32);
    bufp->fullIData(oldp+532,(((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                   >> 6U) & ((7U & 
                                              ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                               >> 3U)) 
                                             == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                                 >> 0x0000001dU)))
                                  ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg)
                                  : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                       >> 0x0000000dU) 
                                      & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                                >> 0x0000000aU)) 
                                         == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                             >> 0x0000001dU)))
                                      ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                         >> 7U) : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                                   >> 0x0000001dU))) 
                                << 0x0000001dU) | (0x1fffffffU 
                                                   & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0))),32);
    bufp->fullBit(oldp+533,((4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))));
    bufp->fullBit(oldp+534,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_inv_valid));
    bufp->fullIData(oldp+535,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                               << 4U)),32);
    bufp->fullIData(oldp+536,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out),32);
    bufp->fullIData(oldp+537,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__pc_paddr),32);
    bufp->fullIData(oldp+538,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr),32);
    bufp->fullBit(oldp+539,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__if_valid));
    bufp->fullBit(oldp+540,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pl_suspend));
    bufp->fullBit(oldp+541,((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                          >> 2U)))));
    bufp->fullIData(oldp+542,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                               + ((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                >> 2U)))
                                   ? 4U : 8U))),32);
    bufp->fullIData(oldp+543,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_taken)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_target
                                : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                   + ((3U == (3U & 
                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                               >> 2U)))
                                       ? 4U : 8U)))),32);
    bufp->fullBit(oldp+544,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__got_addr_ok));
    bufp->fullBit(oldp+545,((1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                      >> 0x00000018U)))));
    bufp->fullBit(oldp+546,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__reset));
    Vasm_monitor_tb___024root__trace_full_dtype____0(vlSelf, bufp, 547, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid);
    Vasm_monitor_tb___024root__trace_full_dtype____1(vlSelf, bufp, 555, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem);
    Vasm_monitor_tb___024root__trace_full_dtype____2(vlSelf, bufp, 563, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter);
    Vasm_monitor_tb___024root__trace_full_dtype____3(vlSelf, bufp, 571, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target);
    bufp->fullIData(oldp+579,((0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                              >> 5U))),18);
    bufp->fullCData(oldp+580,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row),2);
    bufp->fullBit(oldp+581,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                   >> 2U))));
    bufp->fullBit(oldp+582,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U]
                             [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U]
                                [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                == (0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                   >> 5U))))));
    bufp->fullBit(oldp+583,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U]
                             [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U]
                                [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                == (0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                   >> 5U))))));
    bufp->fullBit(oldp+584,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U]
                              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                              & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U]
                                 [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                 == (0x0003ffffU & 
                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                      >> 5U)))) & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[0U]
                                                   [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                                   >> 1U))));
    bufp->fullBit(oldp+585,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1));
    bufp->fullBit(oldp+586,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken));
    bufp->fullBit(oldp+587,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken));
    bufp->fullBit(oldp+588,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken))));
    bufp->fullBit(oldp+589,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane));
    bufp->fullIData(oldp+590,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U]
                               [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]
                                : ((4U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out)
                                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U]
                                   [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]
                                    : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[0U]
                                   [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]))),32);
    bufp->fullIData(oldp+591,((0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                              >> 5U))),18);
    bufp->fullBit(oldp+592,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                   >> 2U))));
    bufp->fullCData(oldp+593,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1),2);
    bufp->fullBit(oldp+594,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid
                            [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                    >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]));
    bufp->fullIData(oldp+595,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem
                              [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                      >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]),18);
    bufp->fullCData(oldp+596,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter
                              [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                      >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]),2);
    bufp->fullIData(oldp+597,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target
                              [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                      >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]),32);
    bufp->fullBit(oldp+598,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s2));
    bufp->fullIData(oldp+599,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2),18);
    bufp->fullBit(oldp+600,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2));
    bufp->fullCData(oldp+601,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2),2);
    bufp->fullBit(oldp+602,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2));
    bufp->fullIData(oldp+603,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target_s2),32);
    bufp->fullBit(oldp+604,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_valid_s2));
    bufp->fullIData(oldp+605,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_tag_s2),18);
    bufp->fullCData(oldp+606,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2),2);
    bufp->fullIData(oldp+607,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_target_s2),32);
    bufp->fullBit(oldp+608,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_hit_s2));
    bufp->fullCData(oldp+609,((3U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2)
                                      ? (((IData)(1U) 
                                          + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2)) 
                                         | (- (IData)(
                                                      (3U 
                                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2)))))
                                      : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2) 
                                          - (IData)(1U)) 
                                         & (- (IData)(
                                                      (0U 
                                                       != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2)))))))),2);
    bufp->fullIData(oldp+610,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__i),32);
    bufp->fullIData(oldp+611,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__j),32);
    bufp->fullSData(oldp+612,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg),9);
    bufp->fullIData(oldp+613,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg),32);
    bufp->fullIData(oldp+614,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg),32);
    bufp->fullIData(oldp+615,((0x000001ffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask)),32);
    bufp->fullIData(oldp+616,((0xee000039U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask)),32);
    bufp->fullSData(oldp+617,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next),9);
    bufp->fullIData(oldp+618,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next),32);
    bufp->fullIData(oldp+619,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next),32);
    bufp->fullCData(oldp+620,((3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))),2);
    bufp->fullBit(oldp+621,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode));
    bufp->fullBit(oldp+622,(((((0U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                               & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next) 
                              | ((3U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next 
                                    >> 3U))) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode))));
    bufp->fullBit(oldp+623,(((((0U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                               & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next) 
                              | ((3U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                    >> 3U))) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode))));
    bufp->fullSData(oldp+624,((((((((0U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                    & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next) 
                                   | ((3U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                         >> 3U))) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode)) 
                                 << 0x0000000dU) | 
                                (((0x00000038U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                                  >> 0x0000001aU)) 
                                  | (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                           >> 0x00000019U))) 
                                 << 7U)) | ((((((0U 
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
                                                     >> 0x00000019U)))))),14);
    bufp->fullSData(oldp+625,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg),14);
    bufp->fullBit(oldp+626,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                   >> 0x0000000dU))));
    bufp->fullCData(oldp+627,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                     >> 0x0000000aU))),3);
    bufp->fullCData(oldp+628,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                     >> 7U))),3);
    bufp->fullBit(oldp+629,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                   >> 6U))));
    bufp->fullCData(oldp+630,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                     >> 3U))),3);
    bufp->fullCData(oldp+631,((7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg))),3);
    bufp->fullBit(oldp+632,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                              >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                               >> 3U)) 
                                        == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                            >> 0x0000001dU)))));
    bufp->fullBit(oldp+633,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                              >> 0x0000000dU) & ((7U 
                                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                                     >> 0x0000000aU)) 
                                                 == 
                                                 (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                                  >> 0x0000001dU)))));
    bufp->fullBit(oldp+634,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid));
    bufp->fullBit(oldp+635,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_store));
    bufp->fullBit(oldp+636,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_is_base));
    bufp->fullIData(oldp+637,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line),28);
    bufp->fullBit(oldp+638,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset));
    bufp->fullBit(oldp+639,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0));
    bufp->fullIData(oldp+640,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0),32);
    bufp->fullSData(oldp+641,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0),12);
    bufp->fullIData(oldp+642,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0),32);
    bufp->fullIData(oldp+643,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0),32);
    bufp->fullIData(oldp+644,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0),32);
    bufp->fullBit(oldp+645,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0));
    bufp->fullCData(oldp+646,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0),5);
    bufp->fullBit(oldp+647,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0));
    bufp->fullBit(oldp+648,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0));
    bufp->fullBit(oldp+649,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0));
    bufp->fullCData(oldp+650,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0),5);
    bufp->fullBit(oldp+651,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0));
    bufp->fullCData(oldp+652,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_cnt_0),2);
    bufp->fullBit(oldp+653,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0));
    bufp->fullIData(oldp+654,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0),32);
    bufp->fullIData(oldp+655,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_1),32);
    bufp->fullBit(oldp+656,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid));
    bufp->fullBit(oldp+657,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0));
    bufp->fullBit(oldp+658,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0));
    bufp->fullBit(oldp+659,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0));
    bufp->fullBit(oldp+660,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0));
    bufp->fullBit(oldp+661,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0));
    bufp->fullBit(oldp+662,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0));
    bufp->fullIData(oldp+663,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0),32);
    bufp->fullCData(oldp+664,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0),4);
    bufp->fullIData(oldp+665,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_0),32);
    bufp->fullBit(oldp+666,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0));
    bufp->fullBit(oldp+667,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0));
    bufp->fullCData(oldp+668,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_cacop_code_0),5);
    bufp->fullBit(oldp+669,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0));
    bufp->fullIData(oldp+670,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0),32);
    bufp->fullIData(oldp+671,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0),32);
    bufp->fullBit(oldp+672,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1));
    bufp->fullIData(oldp+673,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1),32);
    bufp->fullSData(oldp+674,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1),12);
    bufp->fullIData(oldp+675,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1),32);
    bufp->fullIData(oldp+676,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1),32);
    bufp->fullIData(oldp+677,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1),32);
    bufp->fullBit(oldp+678,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1));
    bufp->fullBit(oldp+679,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1));
    bufp->fullBit(oldp+680,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1));
    bufp->fullCData(oldp+681,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1),5);
    bufp->fullBit(oldp+682,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1));
    bufp->fullBit(oldp+683,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1));
    bufp->fullBit(oldp+684,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1));
    bufp->fullBit(oldp+685,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1));
    bufp->fullBit(oldp+686,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1));
    bufp->fullBit(oldp+687,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1));
    bufp->fullBit(oldp+688,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1));
    bufp->fullIData(oldp+689,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1),32);
    bufp->fullCData(oldp+690,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1),4);
    bufp->fullIData(oldp+691,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_1),32);
    bufp->fullIData(oldp+692,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U] 
                                << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U] 
                                                   >> 1U))),32);
    bufp->fullSData(oldp+693,((0x00000fffU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 
                                                      >> 0x0000001dU)))),12);
    bufp->fullIData(oldp+694,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0),32);
    bufp->fullIData(oldp+695,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0),32);
    bufp->fullIData(oldp+696,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0),32);
    bufp->fullBit(oldp+697,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_late_0));
    bufp->fullBit(oldp+698,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                           >> 5U)))));
    bufp->fullBit(oldp+699,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                           >> 4U)))));
    bufp->fullBit(oldp+700,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                           >> 3U)))));
    bufp->fullCData(oldp+701,((0x0000001fU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                      >> 8U)))),5);
    bufp->fullBit(oldp+702,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                           >> 2U)))));
    bufp->fullBit(oldp+703,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                           >> 1U)))));
    bufp->fullBit(oldp+704,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3))));
    bufp->fullBit(oldp+705,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                           >> 0x0000002cU)))));
    bufp->fullBit(oldp+706,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                           >> 0x0000002bU)))));
    bufp->fullBit(oldp+707,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                           >> 0x0000002aU)))));
    bufp->fullBit(oldp+708,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                           >> 0x00000020U)))));
    bufp->fullIData(oldp+709,((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0)),32);
    bufp->fullCData(oldp+710,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_0),4);
    bufp->fullIData(oldp+711,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_offs_0),32);
    bufp->fullBit(oldp+712,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                           >> 0x0000001dU)))));
    bufp->fullBit(oldp+713,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                           >> 0x0000001cU)))));
    bufp->fullCData(oldp+714,((0x0000001fU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                      >> 0x00000017U)))),5);
    bufp->fullBit(oldp+715,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                           >> 0x00000016U)))));
    bufp->fullBit(oldp+716,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                           >> 0x00000015U)))));
    bufp->fullSData(oldp+717,((0x00003fffU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                      >> 7U)))),14);
    bufp->fullBit(oldp+718,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0));
    bufp->fullBit(oldp+719,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0));
    bufp->fullIData(oldp+720,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[3U] 
                                << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U] 
                                                   >> 1U))),32);
    bufp->fullSData(oldp+721,((0x00000fffU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                      >> 0x0000001dU)))),12);
    bufp->fullIData(oldp+722,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1),32);
    bufp->fullIData(oldp+723,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_1),32);
    bufp->fullIData(oldp+724,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1),32);
    bufp->fullBit(oldp+725,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                           >> 5U)))));
    bufp->fullBit(oldp+726,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                           >> 4U)))));
    bufp->fullBit(oldp+727,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                           >> 3U)))));
    bufp->fullCData(oldp+728,((0x0000001fU & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                      >> 8U)))),5);
    bufp->fullBit(oldp+729,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                           >> 2U)))));
    bufp->fullBit(oldp+730,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                           >> 1U)))));
    bufp->fullBit(oldp+731,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3))));
    bufp->fullBit(oldp+732,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                           >> 0x0000002cU)))));
    bufp->fullBit(oldp+733,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                           >> 0x0000002bU)))));
    bufp->fullBit(oldp+734,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                           >> 0x0000002aU)))));
    bufp->fullBit(oldp+735,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 
                                           >> 0x00000020U)))));
    bufp->fullIData(oldp+736,((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0)),32);
    bufp->fullCData(oldp+737,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1),4);
    bufp->fullIData(oldp+738,((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                                       >> 0x0000000aU))),32);
    bufp->fullBit(oldp+739,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready));
    bufp->fullBit(oldp+740,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1))));
    bufp->fullIData(oldp+741,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_0),32);
    bufp->fullIData(oldp+742,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                               + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                    ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                    : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                  + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                           >> 1U))))),32);
    bufp->fullIData(oldp+743,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2),32);
    bufp->fullIData(oldp+744,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_1),32);
    bufp->fullIData(oldp+745,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                               + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))
                                    ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)
                                    : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1) 
                                  + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                           >> 1U))))),32);
    bufp->fullIData(oldp+746,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2),32);
    bufp->fullIData(oldp+747,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid)
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2)),32);
    bufp->fullBit(oldp+748,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 1U))));
    bufp->fullCData(oldp+749,((0x000000ffU & ((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                               ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                               : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0))),8);
    bufp->fullCData(oldp+750,((0x000000ffU & (((2U 
                                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                                ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                              + (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                 + 
                                                 (1U 
                                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                     >> 1U)))))),8);
    bufp->fullIData(oldp+751,(((0xffffff00U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                               + ((
                                                   (2U 
                                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                                    ? 
                                                   (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                                    : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                                  + 
                                                  (1U 
                                                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                      >> 1U))))) 
                               | (0x000000ffU & (((2U 
                                                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                                   ? 
                                                  (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                                 + 
                                                 (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                  + 
                                                  (1U 
                                                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                      >> 1U))))))),32);
    bufp->fullIData(oldp+752,(((0U != (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0)))
                                ? ((0xffffff00U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                   + 
                                                   (((2U 
                                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                                      ? 
                                                     (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                                      : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                                    + 
                                                    (1U 
                                                     & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                        >> 1U))))) 
                                   | (0x000000ffU & 
                                      (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                         ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                       + (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                          + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                   >> 1U))))))
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_0)),32);
    bufp->fullIData(oldp+753,(((0U != (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1)))
                                ? (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                   + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))
                                        ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)
                                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1) 
                                      + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                               >> 1U))))
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_1)),32);
    bufp->fullIData(oldp+754,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0),32);
    bufp->fullIData(oldp+755,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1),32);
    bufp->fullIData(oldp+756,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0),32);
    bufp->fullBit(oldp+757,((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_49)))));
    bufp->fullBit(oldp+758,((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))));
    bufp->fullBit(oldp+759,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0));
    bufp->fullIData(oldp+760,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0),32);
    bufp->fullIData(oldp+761,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)),32);
    bufp->fullBit(oldp+762,((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))));
    bufp->fullBit(oldp+763,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1));
    bufp->fullIData(oldp+764,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1),32);
    bufp->fullIData(oldp+765,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)),32);
    bufp->fullBit(oldp+766,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                             ^ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0))));
    bufp->fullBit(oldp+767,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0) 
                             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0 
                                   != vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)))));
    bufp->fullBit(oldp+768,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0));
    bufp->fullBit(oldp+769,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1) 
                             ^ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1))));
    bufp->fullBit(oldp+770,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1) 
                             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1) 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1 
                                   != vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)))));
    bufp->fullBit(oldp+771,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_1));
    bufp->fullBit(oldp+772,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0));
    bufp->fullBit(oldp+773,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1));
    bufp->fullBit(oldp+774,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))));
    bufp->fullBit(oldp+775,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 2U))));
    bufp->fullBit(oldp+776,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 3U))));
    bufp->fullBit(oldp+777,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 4U))));
    bufp->fullBit(oldp+778,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 5U))));
    bufp->fullBit(oldp+779,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 6U))));
    bufp->fullBit(oldp+780,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 7U))));
    bufp->fullBit(oldp+781,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 8U))));
    bufp->fullBit(oldp+782,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 9U))));
    bufp->fullBit(oldp+783,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 0x0000000aU))));
    bufp->fullBit(oldp+784,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                   >> 0x0000000bU))));
    bufp->fullIData(oldp+785,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
    bufp->fullIData(oldp+786,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                               < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
    bufp->fullIData(oldp+787,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                               & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
    bufp->fullIData(oldp+788,((~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result)),32);
    bufp->fullIData(oldp+789,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result),32);
    bufp->fullIData(oldp+790,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                               ^ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
    bufp->fullIData(oldp+791,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                               << (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0))),32);
    bufp->fullQData(oldp+792,(((((QData)((IData)((- (IData)((IData)(
                                                                    (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                                      >> 0x0000000aU) 
                                                                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                                        >> 0x0000001fU))))))) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0))) 
                               >> (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0))),64);
    bufp->fullIData(oldp+794,((IData)(((((QData)((IData)(
                                                         (- (IData)((IData)(
                                                                            (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                                              >> 0x0000000aU) 
                                                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                                                >> 0x0000001fU))))))) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0))) 
                                       >> (0x0000001fU 
                                           & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)))),32);
    bufp->fullIData(oldp+795,(((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
    bufp->fullBit(oldp+796,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)));
    bufp->fullBit(oldp+797,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                             < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)));
    bufp->fullIData(oldp+798,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0),32);
    bufp->fullIData(oldp+799,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1),32);
    bufp->fullBit(oldp+800,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))));
    bufp->fullBit(oldp+801,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 1U))));
    bufp->fullBit(oldp+802,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 2U))));
    bufp->fullBit(oldp+803,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 3U))));
    bufp->fullBit(oldp+804,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 4U))));
    bufp->fullBit(oldp+805,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 5U))));
    bufp->fullBit(oldp+806,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 6U))));
    bufp->fullBit(oldp+807,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 7U))));
    bufp->fullBit(oldp+808,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 8U))));
    bufp->fullBit(oldp+809,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 9U))));
    bufp->fullBit(oldp+810,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 0x0000000aU))));
    bufp->fullBit(oldp+811,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                   >> 0x0000000bU))));
    bufp->fullIData(oldp+812,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
    bufp->fullIData(oldp+813,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                               < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
    bufp->fullIData(oldp+814,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                               & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
    bufp->fullIData(oldp+815,((~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result)),32);
    bufp->fullIData(oldp+816,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result),32);
    bufp->fullIData(oldp+817,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                               ^ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
    bufp->fullIData(oldp+818,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                               << (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1))),32);
    bufp->fullQData(oldp+819,(((((QData)((IData)((- (IData)((IData)(
                                                                    (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                      >> 0x0000000aU) 
                                                                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                                        >> 0x0000001fU))))))) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1))) 
                               >> (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1))),64);
    bufp->fullIData(oldp+821,((IData)(((((QData)((IData)(
                                                         (- (IData)((IData)(
                                                                            (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                              >> 0x0000000aU) 
                                                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                                                >> 0x0000001fU))))))) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1))) 
                                       >> (0x0000001fU 
                                           & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)))),32);
    bufp->fullIData(oldp+822,(((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))
                                ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
    bufp->fullBit(oldp+823,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)));
    bufp->fullBit(oldp+824,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                             < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)));
    bufp->fullIData(oldp+825,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0),32);
    bufp->fullIData(oldp+826,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1),32);
    bufp->fullBit(oldp+827,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd));
    bufp->fullBit(oldp+828,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed));
    bufp->fullBit(oldp+829,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned));
    bufp->fullIData(oldp+830,(((7U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))
                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0
                                : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)),32);
    bufp->fullBit(oldp+831,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd) 
                              & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                             | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd)) 
                                 & (2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed) 
                                    & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                   | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed)) 
                                       & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                      | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned) 
                                          & (5U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                         | ((9U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
                                            | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned)) 
                                               & (6U 
                                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)))))))))));
    bufp->fullBit(oldp+832,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd));
    bufp->fullBit(oldp+833,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed));
    bufp->fullBit(oldp+834,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned));
    bufp->fullBit(oldp+835,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd) 
                              & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                             | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd)) 
                                 & (2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed) 
                                    & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                   | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed)) 
                                       & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                      | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned) 
                                          & (5U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                         | ((9U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                                            | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned)) 
                                               & (6U 
                                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)))))))))));
    bufp->fullCData(oldp+836,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state),2);
    bufp->fullIData(oldp+837,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_base_addr),32);
    bufp->fullCData(oldp+838,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat),2);
    bufp->fullBit(oldp+839,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                             & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))));
    bufp->fullBit(oldp+840,(((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr_ok))));
    bufp->fullBit(oldp+841,(((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                             & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_data_ok))));
    bufp->fullBit(oldp+842,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat))));
    bufp->fullSData(oldp+843,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg),14);
    bufp->fullBit(oldp+844,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                   >> 0x0000000dU))));
    bufp->fullCData(oldp+845,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                     >> 0x0000000aU))),3);
    bufp->fullCData(oldp+846,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                     >> 7U))),3);
    bufp->fullBit(oldp+847,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                   >> 6U))));
    bufp->fullCData(oldp+848,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                     >> 3U))),3);
    bufp->fullCData(oldp+849,((7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg))),3);
    bufp->fullBit(oldp+850,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                              >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                               >> 3U)) 
                                        == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                            >> 0x0000001dU)))));
    bufp->fullBit(oldp+851,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                              >> 0x0000000dU) & ((7U 
                                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                                     >> 0x0000000aU)) 
                                                 == 
                                                 (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                                  >> 0x0000001dU)))));
    bufp->fullBit(oldp+852,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__reset));
    bufp->fullCData(oldp+853,((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                     >> 4U))),3);
    bufp->fullIData(oldp+854,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__pc_paddr 
                               >> 7U)),25);
    bufp->fullCData(oldp+855,((3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                     >> 2U))),2);
    bufp->fullBit(oldp+856,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid));
    bufp->fullIData(oldp+857,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_vaddr),32);
    bufp->fullIData(oldp+858,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr),32);
    bufp->fullBit(oldp+859,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_0));
    bufp->fullIData(oldp+860,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_0),32);
    bufp->fullBit(oldp+861,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_1));
    bufp->fullIData(oldp+862,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_1),32);
    bufp->fullCData(oldp+863,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index),3);
    bufp->fullIData(oldp+864,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag),25);
    bufp->fullCData(oldp+865,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_offset_word),2);
    Vasm_monitor_tb___024root__trace_full_dtype____4(vlSelf, bufp, 866, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid);
    Vasm_monitor_tb___024root__trace_full_dtype____5(vlSelf, bufp, 882, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0);
    Vasm_monitor_tb___024root__trace_full_dtype____6(vlSelf, bufp, 890, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1);
    Vasm_monitor_tb___024root__trace_full_dtype____7(vlSelf, bufp, 898, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0);
    Vasm_monitor_tb___024root__trace_full_dtype____8(vlSelf, bufp, 930, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1);
    bufp->fullBit(oldp+962,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                             [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                                [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                                == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag))));
    bufp->fullBit(oldp+963,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1));
    bufp->fullBit(oldp+964,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                              [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                              & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                                 [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                                 == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag)) 
                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1))));
    if (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1) {
        __Vtemp_29[0U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][0U];
        __Vtemp_29[1U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][1U];
        __Vtemp_29[2U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][2U];
        __Vtemp_29[3U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][3U];
    } else {
        __Vtemp_29[0U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][0U];
        __Vtemp_29[1U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][1U];
        __Vtemp_29[2U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][2U];
        __Vtemp_29[3U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0
            [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index][3U];
    }
    bufp->fullWData(oldp+965,(__Vtemp_29),128);
    bufp->fullCData(oldp+969,((7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line)),3);
    bufp->fullIData(oldp+970,((0x01ffffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                                              >> 3U))),25);
    bufp->fullBit(oldp+971,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_inv_valid) 
                             & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid) 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                                   == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr 
                                       >> 4U))))));
    bufp->fullBit(oldp+972,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid));
    bufp->fullBit(oldp+973,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit));
    bufp->fullBit(oldp+974,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit_way));
    bufp->fullWData(oldp+975,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data),128);
    bufp->fullIData(oldp+979,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr),32);
    bufp->fullIData(oldp+980,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr),32);
    bufp->fullBit(oldp+981,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0));
    bufp->fullIData(oldp+982,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_0),32);
    bufp->fullBit(oldp+983,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_1));
    bufp->fullIData(oldp+984,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_1),32);
    bufp->fullCData(oldp+985,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word),2);
    bufp->fullCData(oldp+986,((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                                     >> 4U))),3);
    bufp->fullIData(oldp+987,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                               >> 7U)),25);
    bufp->fullCData(oldp+988,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state),3);
    bufp->fullCData(oldp+989,(Vasm_monitor_tb__ConstPool__TABLE_he47f3c48_0
                              [(((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
                                     & ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
                                        & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)) 
                                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2)))) 
                                    << 5U) | ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                                              << 4U)) 
                                  | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r) 
                                      << 2U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r) 
                                                 << 1U) 
                                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)))) 
                                 << 5U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold) 
                                            << 4U) 
                                           | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2) 
                                               << 3U) 
                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))))]),3);
    bufp->fullWData(oldp+990,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg),128);
    bufp->fullWData(oldp+994,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line),128);
    bufp->fullCData(oldp+998,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat),2);
    bufp->fullBit(oldp+999,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned));
    bufp->fullCData(oldp+1000,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr),8);
    bufp->fullCData(oldp+1001,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state),3);
    bufp->fullCData(oldp+1002,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code),5);
    bufp->fullIData(oldp+1003,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr),32);
    bufp->fullBit(oldp+1004,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way0));
    bufp->fullBit(oldp+1005,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way1));
    bufp->fullBit(oldp+1006,((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))));
    bufp->fullWData(oldp+1007,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line),128);
    bufp->fullIData(oldp+1011,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                                 ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U]
                                 : ((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U]
                                     : ((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U]
                                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U])))),32);
    bufp->fullIData(oldp+1012,(((0U == (3U & ((IData)(1U) 
                                              + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                                 ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U]
                                 : ((1U == (3U & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U]
                                     : ((2U == (3U 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U]
                                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U])))),32);
    bufp->fullIData(oldp+1013,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr)),32);
    bufp->fullBit(oldp+1014,((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0) 
                                       | (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word)))))));
    bufp->fullIData(oldp+1015,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0),32);
    bufp->fullIData(oldp+1016,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1),32);
    bufp->fullIData(oldp+1017,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0),32);
    bufp->fullIData(oldp+1018,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1),32);
    bufp->fullBit(oldp+1019,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0));
    bufp->fullIData(oldp+1020,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0),32);
    bufp->fullBit(oldp+1021,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1));
    bufp->fullIData(oldp+1022,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1),32);
    bufp->fullBit(oldp+1023,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way));
    bufp->fullBit(oldp+1024,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2));
    bufp->fullBit(oldp+1025,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now));
    bufp->fullBit(oldp+1026,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
                              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)))));
    bufp->fullBit(oldp+1027,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)) 
                              & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))));
    bufp->fullBit(oldp+1028,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready));
    bufp->fullBit(oldp+1029,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold));
    bufp->fullBit(oldp+1030,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid))));
    bufp->fullBit(oldp+1031,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall));
    bufp->fullBit(oldp+1032,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
                              & ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
                                 & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2))))));
    bufp->fullBit(oldp+1033,((1U & VL_REDXOR_8((0xb8U 
                                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr))))));
    bufp->fullBit(oldp+1034,((0U == (7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code)))));
    bufp->fullBit(oldp+1035,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_direct));
    bufp->fullBit(oldp+1036,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit));
    bufp->fullBit(oldp+1037,((1U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr)));
    bufp->fullCData(oldp+1038,((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                      >> 4U))),3);
    bufp->fullIData(oldp+1039,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                >> 7U)),25);
    bufp->fullBit(oldp+1040,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint));
    bufp->fullBit(oldp+1041,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                               [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                       >> 4U))] & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                                                   [
                                                   (7U 
                                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                                       >> 4U))] 
                                                   == 
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                                    >> 7U))) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint) 
                                 & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way))))));
    bufp->fullBit(oldp+1042,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U]
                               [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                       >> 4U))] & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1
                                                   [
                                                   (7U 
                                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                                       >> 4U))] 
                                                   == 
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                                    >> 7U))) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way)))));
    bufp->fullIData(oldp+1043,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__i),32);
    bufp->fullIData(oldp+1044,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__j),32);
    bufp->fullSData(oldp+1045,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg),14);
    bufp->fullBit(oldp+1046,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                    >> 0x0000000dU))));
    bufp->fullCData(oldp+1047,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                      >> 0x0000000aU))),3);
    bufp->fullCData(oldp+1048,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                      >> 7U))),3);
    bufp->fullBit(oldp+1049,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                    >> 6U))));
    bufp->fullCData(oldp+1050,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                      >> 3U))),3);
    bufp->fullCData(oldp+1051,((7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg))),3);
    bufp->fullBit(oldp+1052,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                               >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                                >> 3U)) 
                                         == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                             >> 0x0000001dU)))));
    bufp->fullBit(oldp+1053,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                               >> 0x0000000dU) & ((7U 
                                                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                                      >> 0x0000000aU)) 
                                                  == 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                   >> 0x0000001dU)))));
    bufp->fullCData(oldp+1054,((3U & ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))),2);
    bufp->fullCData(oldp+1055,((3U & ((IData)(1U) + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail)))),2);
    Vasm_monitor_tb___024root__trace_full_dtype____9(vlSelf, bufp, 1056, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo);
    bufp->fullCData(oldp+1092,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head),2);
    bufp->fullCData(oldp+1093,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail),2);
    bufp->fullCData(oldp+1094,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt),3);
    bufp->fullWData(oldp+1095,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                               [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head]),266);
    bufp->fullWData(oldp+1104,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                               [(3U & ((IData)(1U) 
                                       + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))]),266);
    bufp->fullQData(oldp+1113,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0),45);
    bufp->fullQData(oldp+1115,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g1),45);
    bufp->fullQData(oldp+1117,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2),45);
    bufp->fullQData(oldp+1119,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3),45);
    bufp->fullQData(oldp+1121,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4),45);
    bufp->fullQData(oldp+1123,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5),41);
    bufp->fullQData(oldp+1125,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0),45);
    bufp->fullQData(oldp+1127,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1),45);
    bufp->fullQData(oldp+1129,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2),45);
    bufp->fullQData(oldp+1131,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3),45);
    bufp->fullQData(oldp+1133,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4),45);
    bufp->fullQData(oldp+1135,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5),41);
    bufp->fullCData(oldp+1137,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__4__03a2__KET__) 
                                 << 2U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__1__03a0__KET__))),5);
    bufp->fullBit(oldp+1138,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit1_r));
    bufp->fullBit(oldp+1139,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit0_r));
    bufp->fullBit(oldp+1140,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_1_hot_bit0_r));
    bufp->fullBit(oldp+1141,(Vasm_monitor_tb__ConstPool__TABLE_h2c364be9_0
                             [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_50]));
    bufp->fullBit(oldp+1142,(Vasm_monitor_tb__ConstPool__TABLE_h547ba932_0
                             [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_50]));
    bufp->fullCData(oldp+1143,(Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0
                               [(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                                  << 6U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
                                             << 5U) 
                                            | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17)))]),2);
    bufp->fullBit(oldp+1144,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a));
    bufp->fullBit(oldp+1145,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_load_fifo1_g0));
    bufp->fullQData(oldp+1146,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0),45);
    bufp->fullQData(oldp+1148,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1),45);
    bufp->fullQData(oldp+1150,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2),45);
    bufp->fullQData(oldp+1152,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3),45);
    bufp->fullQData(oldp+1154,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4),45);
    bufp->fullQData(oldp+1156,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5),41);
    bufp->fullBit(oldp+1158,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0));
    bufp->fullWData(oldp+1159,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next),266);
    bufp->fullCData(oldp+1168,((0x0000001fU & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9)
                                                ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)
                                                : (
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                                                    << 7U) 
                                                   | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                      [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                                                      >> 0x00000019U))))),5);
    bufp->fullCData(oldp+1169,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next),5);
    bufp->fullBit(oldp+1170,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0));
    bufp->fullBit(oldp+1171,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1));
    bufp->fullCData(oldp+1172,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count),2);
    bufp->fullWData(oldp+1173,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0),169);
    bufp->fullWData(oldp+1179,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1),169);
    __Vtemp_31[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                               << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))));
    __Vtemp_31[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                       << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))) 
                                         >> 0x00000020U)));
    __Vtemp_31[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                       >> 0x0000001fU) | ((IData)((
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                                                   >> 0x00000020U)) 
                                          << 1U));
    __Vtemp_31[3U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[0U] 
                       << 1U) | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                                          >> 0x00000020U)) 
                                 >> 0x0000001fU));
    __Vtemp_31[4U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[0U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[1U] 
                                          << 1U));
    __Vtemp_31[5U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[1U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[2U] 
                                          << 1U));
    __Vtemp_31[6U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[2U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[3U] 
                                          << 1U));
    __Vtemp_31[7U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[3U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[4U] 
                                          << 1U));
    __Vtemp_31[8U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[4U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0[5U] 
                                          << 1U));
    bufp->fullWData(oldp+1185,(__Vtemp_31),266);
    __Vtemp_33[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                               << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))));
    __Vtemp_33[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                       << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))) 
                                         >> 0x00000020U)));
    __Vtemp_33[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                 << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                       >> 0x0000001fU) | ((IData)((
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                                                   >> 0x00000020U)) 
                                          << 1U));
    __Vtemp_33[3U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[0U] 
                       << 1U) | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                                          >> 0x00000020U)) 
                                 >> 0x0000001fU));
    __Vtemp_33[4U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[0U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[1U] 
                                          << 1U));
    __Vtemp_33[5U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[1U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[2U] 
                                          << 1U));
    __Vtemp_33[6U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[2U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[3U] 
                                          << 1U));
    __Vtemp_33[7U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[3U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[4U] 
                                          << 1U));
    __Vtemp_33[8U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[4U] 
                       >> 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1[5U] 
                                          << 1U));
    bufp->fullWData(oldp+1194,(__Vtemp_33),266);
    __Vtemp_36[0U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U] 
                                          >> 1U));
    __Vtemp_36[1U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[5U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                                          >> 1U));
    __Vtemp_36[2U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[6U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[5U] 
                                          >> 1U));
    __Vtemp_36[3U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[7U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[6U] 
                                          >> 1U));
    __Vtemp_36[4U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[8U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[7U] 
                                          >> 1U));
    __Vtemp_36[5U] = (0x000001ffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[8U] 
                                     >> 1U));
    bufp->fullWData(oldp+1203,(__Vtemp_36),169);
    __Vtemp_39[0U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[0U];
    __Vtemp_39[1U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[1U];
    __Vtemp_39[2U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U];
    __Vtemp_39[3U] = (1U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U]);
    bufp->fullWData(oldp+1209,(__Vtemp_39),97);
    __Vtemp_42[0U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[4U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[3U] 
                                          >> 1U));
    __Vtemp_42[1U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[5U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[4U] 
                                          >> 1U));
    __Vtemp_42[2U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[6U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[5U] 
                                          >> 1U));
    __Vtemp_42[3U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[7U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[6U] 
                                          >> 1U));
    __Vtemp_42[4U] = ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[8U] 
                       << 0x0000001fU) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[7U] 
                                          >> 1U));
    __Vtemp_42[5U] = (0x000001ffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[8U] 
                                     >> 1U));
    bufp->fullWData(oldp+1213,(__Vtemp_42),169);
    __Vtemp_45[0U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[0U];
    __Vtemp_45[1U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[1U];
    __Vtemp_45[2U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U];
    __Vtemp_45[3U] = (1U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[3U]);
    bufp->fullWData(oldp+1219,(__Vtemp_45),97);
    bufp->fullIData(oldp+1223,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[1U] 
                                 >> 1U))),32);
    bufp->fullIData(oldp+1224,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U] 
                                 << 0x0000001fU) | 
                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[1U] 
                                 >> 1U))),32);
    bufp->fullIData(oldp+1225,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[7U] 
                                 << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[6U] 
                                           >> 0x0000001eU))),32);
    bufp->fullIData(oldp+1226,((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4 
                                        >> 0x0000000aU))),32);
    bufp->fullIData(oldp+1227,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[5U] 
                                 << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                                           >> 0x0000001eU))),32);
    bufp->fullCData(oldp+1228,((0x0000001fU & (IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                       >> 0x00000012U)))),5);
    bufp->fullCData(oldp+1229,((0x0000001fU & (IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                       >> 0x0000000dU)))),5);
    bufp->fullBit(oldp+1230,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                            >> 7U)))));
    bufp->fullBit(oldp+1231,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                            >> 6U)))));
    bufp->fullBit(oldp+1232,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000029U)))));
    bufp->fullBit(oldp+1233,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000028U)))));
    bufp->fullBit(oldp+1234,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000027U)))));
    bufp->fullBit(oldp+1235,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000026U)))));
    bufp->fullBit(oldp+1236,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000025U)))));
    bufp->fullBit(oldp+1237,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000024U)))));
    bufp->fullBit(oldp+1238,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000023U)))));
    bufp->fullBit(oldp+1239,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000022U)))));
    bufp->fullBit(oldp+1240,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000021U)))));
    bufp->fullBit(oldp+1241,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x00000020U)))));
    bufp->fullBit(oldp+1242,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x0000001fU)))));
    bufp->fullBit(oldp+1243,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                            >> 0x0000001eU)))));
    bufp->fullIData(oldp+1244,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[7U] 
                                 << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[6U] 
                                           >> 0x0000001eU))),32);
    bufp->fullIData(oldp+1245,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[5U] 
                                 << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[4U] 
                                           >> 0x0000001eU))),32);
    bufp->fullCData(oldp+1246,((0x0000001fU & (IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                       >> 0x00000012U)))),5);
    bufp->fullBit(oldp+1247,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                            >> 7U)))));
    bufp->fullBit(oldp+1248,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                            >> 6U)))));
    bufp->fullBit(oldp+1249,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000029U)))));
    bufp->fullBit(oldp+1250,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000028U)))));
    bufp->fullBit(oldp+1251,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000027U)))));
    bufp->fullBit(oldp+1252,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000026U)))));
    bufp->fullBit(oldp+1253,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000025U)))));
    bufp->fullBit(oldp+1254,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000024U)))));
    bufp->fullBit(oldp+1255,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000023U)))));
    bufp->fullBit(oldp+1256,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000022U)))));
    bufp->fullBit(oldp+1257,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000021U)))));
    bufp->fullBit(oldp+1258,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000020U)))));
    bufp->fullBit(oldp+1259,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x0000001fU)))));
    bufp->fullBit(oldp+1260,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x0000001eU)))));
    bufp->fullBit(oldp+1261,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x0000001dU)))));
    bufp->fullBit(oldp+1262,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x0000001cU)))));
    bufp->fullBit(oldp+1263,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                            >> 0x00000016U)))));
    bufp->fullBit(oldp+1264,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_0));
    bufp->fullCData(oldp+1265,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0),5);
    bufp->fullCData(oldp+1266,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume),5);
    bufp->fullBit(oldp+1267,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1));
    bufp->fullCData(oldp+1268,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1),5);
    bufp->fullBit(oldp+1269,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0));
    bufp->fullBit(oldp+1270,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0));
    bufp->fullBit(oldp+1271,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0));
    bufp->fullBit(oldp+1272,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume));
    bufp->fullBit(oldp+1273,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume));
    bufp->fullBit(oldp+1274,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume));
    bufp->fullBit(oldp+1275,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_res_from_mem_0));
    bufp->fullCData(oldp+1276,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0),5);
    bufp->fullCData(oldp+1277,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume),5);
    bufp->fullBit(oldp+1278,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_1));
    bufp->fullBit(oldp+1279,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_1));
    bufp->fullBit(oldp+1280,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1));
    bufp->fullCData(oldp+1281,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1),5);
    bufp->fullCData(oldp+1282,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume),5);
    bufp->fullBit(oldp+1283,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0));
    bufp->fullBit(oldp+1284,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0));
    bufp->fullBit(oldp+1285,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0));
    bufp->fullBit(oldp+1286,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0));
    bufp->fullCData(oldp+1287,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0),5);
    bufp->fullIData(oldp+1288,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0),32);
    bufp->fullBit(oldp+1289,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1));
    bufp->fullBit(oldp+1290,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1));
    bufp->fullBit(oldp+1291,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)))));
    bufp->fullCData(oldp+1292,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1),5);
    bufp->fullIData(oldp+1293,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1),32);
    bufp->fullBit(oldp+1294,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0));
    bufp->fullCData(oldp+1295,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0),5);
    bufp->fullBit(oldp+1296,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0));
    bufp->fullCData(oldp+1297,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0),5);
    bufp->fullIData(oldp+1298,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0),32);
    bufp->fullBit(oldp+1299,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1));
    bufp->fullCData(oldp+1300,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1),5);
    bufp->fullIData(oldp+1301,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1),32);
    bufp->fullIData(oldp+1302,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                   == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                                  ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                  : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0)) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                                      ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                      : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                                     [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r])) 
                                & (- (IData)((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r)))))),32);
    bufp->fullIData(oldp+1303,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                                   == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                                  ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                  : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                                      ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                      : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                                     [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0])) 
                                & (- (IData)((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))))),32);
    bufp->fullIData(oldp+1304,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                                   == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                                  ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                  : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                                      ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                      : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                                     [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot])) 
                                & (- (IData)((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)))))),32);
    bufp->fullIData(oldp+1305,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                                   == (0x0000001fU 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                  >> 0x0000000dU)))) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                                  ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                  : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                                       == (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                      >> 0x0000000dU)))) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                                      ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                      : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                                     [(0x0000001fU 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                  >> 0x0000000dU)))])) 
                                & (- (IData)((0U != 
                                              (0x0000001fU 
                                               & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                          >> 0x0000000dU)))))))),32);
    bufp->fullBit(oldp+1306,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid));
    bufp->fullBit(oldp+1307,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid));
    bufp->fullBit(oldp+1308,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid));
    bufp->fullBit(oldp+1309,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid));
    bufp->fullBit(oldp+1310,((1U & ((~ (((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                  >> 3U)) 
                                         | (IData)(
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                    >> 5U))) 
                                        | ((IData)(
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                    >> 0x00000027U)) 
                                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0)))) 
                                    & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                               >> 4U))))));
    bufp->fullBit(oldp+1311,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0));
    bufp->fullBit(oldp+1312,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0));
    bufp->fullBit(oldp+1313,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1));
    bufp->fullBit(oldp+1314,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms0));
    bufp->fullBit(oldp+1315,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms1));
    bufp->fullBit(oldp+1316,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1))));
    bufp->fullBit(oldp+1317,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1));
    bufp->fullBit(oldp+1318,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_46) 
                              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0))))));
    bufp->fullBit(oldp+1319,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex));
    bufp->fullBit(oldp+1320,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1)) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                                 | (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_46) 
                                     & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                           == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0)))) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1))))));
    bufp->fullIData(oldp+1321,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0),32);
    bufp->fullBit(oldp+1322,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0));
    bufp->fullBit(oldp+1323,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1));
    bufp->fullBit(oldp+1324,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms0));
    bufp->fullBit(oldp+1325,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms1));
    bufp->fullBit(oldp+1326,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex));
    bufp->fullBit(oldp+1327,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1))));
    bufp->fullBit(oldp+1328,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1));
    bufp->fullBit(oldp+1329,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0));
    bufp->fullBit(oldp+1330,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait))));
    bufp->fullIData(oldp+1331,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd_value_0),32);
    bufp->fullBit(oldp+1332,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0));
    bufp->fullBit(oldp+1333,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1));
    bufp->fullBit(oldp+1334,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                               & (0x0000018000000000ULL 
                                  == (0x0000018000000000ULL 
                                      & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_0))) 
                              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))));
    bufp->fullBit(oldp+1335,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                               & (0x000000c000000000ULL 
                                  == (0x000000c000000000ULL 
                                      & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_1))) 
                              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1) 
                                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))));
    bufp->fullBit(oldp+1336,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))));
    bufp->fullBit(oldp+1337,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1));
    bufp->fullBit(oldp+1338,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                               == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                              & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_42))));
    bufp->fullBit(oldp+1339,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1)) 
                               | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19) 
                                  | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_42)) 
                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1)))) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid))));
    bufp->fullIData(oldp+1340,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))
                                 ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1
                                 : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0))
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0
                                     : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_1))),32);
    bufp->fullBit(oldp+1341,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0));
    bufp->fullBit(oldp+1342,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1));
    bufp->fullBit(oldp+1343,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                               & (0x0000018000000000ULL 
                                  == (0x0000018000000000ULL 
                                      & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_0))) 
                              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                                    == (0x0000001fU 
                                        & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                   >> 0x0000000dU))))))));
    bufp->fullBit(oldp+1344,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                               & (0x000000c000000000ULL 
                                  == (0x000000c000000000ULL 
                                      & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_1))) 
                              & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1) 
                                    == (0x0000001fU 
                                        & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                   >> 0x0000000dU))))))));
    bufp->fullBit(oldp+1345,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1))));
    bufp->fullBit(oldp+1346,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1));
    bufp->fullBit(oldp+1347,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                               == (0x0000001fU & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                          >> 0x0000000dU)))) 
                              & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40))));
    bufp->fullBit(oldp+1348,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1)) 
                               | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20) 
                                  | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                       == (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                      >> 0x0000000dU)))) 
                                      & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40)) 
                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1)))) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid))));
    bufp->fullBit(oldp+1349,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait));
    bufp->fullBit(oldp+1350,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok));
    bufp->fullBit(oldp+1351,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait));
    bufp->fullBit(oldp+1352,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1) 
                                   | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1))) 
                               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0) 
                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0)))) 
                              & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                         >> 2U)))));
    bufp->fullBit(oldp+1353,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1) 
                                   | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))) 
                               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0) 
                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0)))) 
                              & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                         >> 2U)))));
    bufp->fullBit(oldp+1354,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1)) 
                               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                                  | (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_46) 
                                      & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                            == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0)))) 
                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1)))) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait) 
                                 | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok)) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait)) 
                                    | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1) 
                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1))) 
                                        | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0) 
                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0)))) 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                  >> 2U))))))));
    bufp->fullBit(oldp+1355,((((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1)) 
                                | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19) 
                                   | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                        == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_42)) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1)))) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid)) 
                              | (((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1)) 
                                   | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20) 
                                      | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                           == (0x0000001fU 
                                               & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                          >> 0x0000000dU)))) 
                                          & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40)) 
                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1)))) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid)) 
                                 | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                      & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1) 
                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))) 
                                     | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0) 
                                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0)))) 
                                    & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                               >> 2U)))))));
    bufp->fullBit(oldp+1356,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__raw_0_to_1));
    bufp->fullBit(oldp+1357,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume));
    bufp->fullBit(oldp+1358,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume));
    bufp->fullBit(oldp+1359,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume));
    bufp->fullBit(oldp+1360,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume));
    bufp->fullBit(oldp+1361,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                    & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume))))))));
    bufp->fullBit(oldp+1362,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                    & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))))))));
    bufp->fullBit(oldp+1363,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                    & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))))));
    bufp->fullBit(oldp+1364,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                    & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                       & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                          == (0x0000001fU 
                                              & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                         >> 0x0000000dU))))))))));
    bufp->fullBit(oldp+1365,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume))));
    bufp->fullBit(oldp+1366,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume))));
    bufp->fullBit(oldp+1367,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume))));
    bufp->fullBit(oldp+1368,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume))));
    bufp->fullBit(oldp+1369,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_46) 
                              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume))))));
    bufp->fullBit(oldp+1370,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume));
    bufp->fullBit(oldp+1371,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
                               == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                              & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_42))));
    bufp->fullBit(oldp+1372,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
                               == (0x0000001fU & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                          >> 0x0000000dU)))) 
                              & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40))));
    bufp->fullBit(oldp+1373,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume));
    bufp->fullBit(oldp+1374,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1))));
    bufp->fullBit(oldp+1375,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume));
    bufp->fullBit(oldp+1376,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume));
    bufp->fullBit(oldp+1377,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume)) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume)))));
    bufp->fullBit(oldp+1378,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume))));
    bufp->fullBit(oldp+1379,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                              & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19))));
    bufp->fullBit(oldp+1380,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume)) 
                              | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                  & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19)) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume)))));
    bufp->fullBit(oldp+1381,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                              & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20))));
    bufp->fullBit(oldp+1382,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                               & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume)) 
                              | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                  & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20)) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume)))));
    bufp->fullBit(oldp+1383,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume));
    bufp->fullBit(oldp+1384,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume));
    bufp->fullBit(oldp+1385,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume));
    bufp->fullBit(oldp+1386,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume) 
                              & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume)))));
    bufp->fullBit(oldp+1387,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume) 
                                   | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume))) 
                               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume) 
                                  & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
                                      & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                            & ((0U 
                                                != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))))) 
                                     | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                              & ((0U 
                                                  != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume))))))))) 
                              & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                         >> 2U)))));
    bufp->fullBit(oldp+1388,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume) 
                                   | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume))) 
                               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume) 
                                  & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
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
                                     | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                              & ((0U 
                                                  != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                                    == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))))))) 
                              & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                         >> 2U)))));
    bufp->fullBit(oldp+1389,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume)) 
                               | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                                  | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume))) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume) 
                                 | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume)) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume)) 
                                    | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                         & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume) 
                                            | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume))) 
                                        | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume) 
                                           & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
                                               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                                     & ((0U 
                                                         != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                        & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                                           == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))))) 
                                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                                       & ((0U 
                                                           != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                                             == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume))))))))) 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                  >> 2U))))))));
    bufp->fullBit(oldp+1390,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume)) 
                               | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19)) 
                                  | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume))) 
                              | (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume) 
                                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume))) 
                                   | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume) 
                                      & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
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
                                         | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                            & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                                  & ((0U 
                                                      != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                                     & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                                        == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))))))) 
                                  & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                             >> 2U))) 
                                 | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume)) 
                                    | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                        & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20)) 
                                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume)))))));
    bufp->fullBit(oldp+1391,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1)))));
    bufp->fullBit(oldp+1392,((((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume) 
                                   & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume)) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume)))) 
                               & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
                                  | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1))) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume))));
    bufp->fullBit(oldp+1393,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume))));
    bufp->fullBit(oldp+1394,((IData)((0ULL != (0x0000000000000028ULL 
                                               & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3)))));
    bufp->fullBit(oldp+1395,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1));
    bufp->fullBit(oldp+1396,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0));
    bufp->fullBit(oldp+1397,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1));
    bufp->fullBit(oldp+1398,((1U & ((~ ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                 >> 0x00000027U)) 
                                        | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1) 
                                           | ((IData)(
                                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                       >> 2U)) 
                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1))))) 
                                    & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                               >> 4U))))));
    bufp->fullBit(oldp+1399,((1U & ((~ (0U != (3U & (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                             >> 0x0000001fU))))) 
                                    & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000027U))))));
    bufp->fullBit(oldp+1400,((1U & ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                             >> 2U)) 
                                    & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                               >> 2U))))));
    bufp->fullBit(oldp+1401,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__lane1_capable));
    bufp->fullBit(oldp+1402,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__capture_ex_wait_0));
    Vasm_monitor_tb___024root__trace_full_dtype____10(vlSelf, bufp, 1403, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf);
    bufp->fullBit(oldp+1435,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset));
    bufp->fullCData(oldp+1436,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind),2);
    bufp->fullBit(oldp+1437,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0));
    bufp->fullIData(oldp+1438,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0),32);
    bufp->fullIData(oldp+1439,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0),32);
    bufp->fullBit(oldp+1440,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0));
    bufp->fullCData(oldp+1441,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0),5);
    bufp->fullBit(oldp+1442,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0));
    bufp->fullBit(oldp+1443,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0));
    bufp->fullBit(oldp+1444,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0));
    bufp->fullBit(oldp+1445,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0));
    bufp->fullBit(oldp+1446,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_0));
    bufp->fullBit(oldp+1447,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_0));
    bufp->fullBit(oldp+1448,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_taken_0));
    bufp->fullIData(oldp+1449,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_target_0),32);
    bufp->fullBit(oldp+1450,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0));
    bufp->fullBit(oldp+1451,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0));
    bufp->fullIData(oldp+1452,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0),32);
    bufp->fullIData(oldp+1453,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0),32);
    bufp->fullBit(oldp+1454,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0));
    bufp->fullBit(oldp+1455,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_cacop_0));
    bufp->fullBit(oldp+1456,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0));
    bufp->fullSData(oldp+1457,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0),14);
    bufp->fullIData(oldp+1458,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0),32);
    bufp->fullIData(oldp+1459,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0),32);
    bufp->fullBit(oldp+1460,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op));
    bufp->fullBit(oldp+1461,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op));
    bufp->fullBit(oldp+1462,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q));
    bufp->fullBit(oldp+1463,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q));
    bufp->fullBit(oldp+1464,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q));
    bufp->fullBit(oldp+1465,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q));
    bufp->fullBit(oldp+1466,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl));
    bufp->fullBit(oldp+1467,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q));
    bufp->fullIData(oldp+1468,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1),32);
    bufp->fullIData(oldp+1469,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1),32);
    bufp->fullIData(oldp+1470,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_1),32);
    bufp->fullBit(oldp+1471,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1));
    bufp->fullBit(oldp+1472,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1));
    bufp->fullBit(oldp+1473,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_1));
    bufp->fullBit(oldp+1474,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_1));
    bufp->fullBit(oldp+1475,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1));
    bufp->fullBit(oldp+1476,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_1));
    bufp->fullBit(oldp+1477,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_1));
    bufp->fullBit(oldp+1478,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_taken_1));
    bufp->fullIData(oldp+1479,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_target_1),32);
    bufp->fullBit(oldp+1480,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1));
    bufp->fullBit(oldp+1481,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1));
    bufp->fullIData(oldp+1482,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1),32);
    bufp->fullIData(oldp+1483,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1),32);
    bufp->fullBit(oldp+1484,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1));
    bufp->fullBit(oldp+1485,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_to_ms_valid_0) 
                              & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0))));
    bufp->fullBit(oldp+1486,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_eff_valid));
    bufp->fullBit(oldp+1487,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw));
    bufp->fullBit(oldp+1488,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw));
    bufp->fullBit(oldp+1489,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw));
    bufp->fullBit(oldp+1490,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1) 
                              & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_24))));
    bufp->fullBit(oldp+1491,((1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0 
                                       >> 0x00000018U)))));
    bufp->fullBit(oldp+1492,((1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1 
                                       >> 0x00000018U)))));
    bufp->fullBit(oldp+1493,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                               ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q)
                               : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q))));
    bufp->fullBit(oldp+1494,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                               ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)
                               : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0))));
    bufp->fullIData(oldp+1495,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd),32);
    bufp->fullBit(oldp+1496,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_byte));
    bufp->fullBit(oldp+1497,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_half));
    bufp->fullBit(oldp+1498,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                               ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1)
                               : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0))));
    bufp->fullBit(oldp+1499,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte));
    bufp->fullBit(oldp+1500,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half));
    bufp->fullBit(oldp+1501,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready));
    bufp->fullBit(oldp+1502,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind))));
    bufp->fullBit(oldp+1503,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
                                    >> 1U))));
    bufp->fullBit(oldp+1504,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0));
    bufp->fullBit(oldp+1505,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending));
    bufp->fullBit(oldp+1506,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting));
    bufp->fullBit(oldp+1507,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting));
    bufp->fullBit(oldp+1508,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_q));
    bufp->fullBit(oldp+1509,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid));
    bufp->fullIData(oldp+1510,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf),32);
    bufp->fullBit(oldp+1511,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent));
    bufp->fullIData(oldp+1512,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q),32);
    bufp->fullBit(oldp+1513,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_ok));
    bufp->fullBit(oldp+1514,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready));
    bufp->fullBit(oldp+1515,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting) 
                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg)))));
    bufp->fullBit(oldp+1516,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1))));
    bufp->fullBit(oldp+1517,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent) 
                              & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state)))));
    bufp->fullBit(oldp+1518,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_req) 
                              & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q) 
                                 & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                                      ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q)
                                      : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q)) 
                                    & ((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_ready) 
                                         << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_ready)) 
                                       >> (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q)))))));
    bufp->fullBit(oldp+1519,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid) 
                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready) 
                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_req) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q) 
                                       & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                                            ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q)
                                            : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q)) 
                                          & ((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_ready) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_ready)) 
                                             >> (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q)))))))));
    bufp->fullBit(oldp+1520,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
    bufp->fullBit(oldp+1521,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1));
    bufp->fullBit(oldp+1522,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire));
    bufp->fullBit(oldp+1523,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1) 
                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_24)) 
                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw))));
    bufp->fullBit(oldp+1524,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire));
    bufp->fullIData(oldp+1525,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw)
                                 ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0)
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0
                                     : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0)
                                 : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1)
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1
                                     : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1))),32);
    bufp->fullBit(oldp+1526,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__bpu_sel_lane1));
    bufp->fullCData(oldp+1527,((0x0000000fU & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte)
                                                ? ((IData)(1U) 
                                                   << 
                                                   (3U 
                                                    & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr))
                                                : (
                                                   ((2U 
                                                     & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr)
                                                     ? 0x0cU
                                                     : 3U) 
                                                   | (- (IData)(
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half))))))))),4);
    bufp->fullIData(oldp+1528,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_load_result_0_fwd),32);
    bufp->fullBit(oldp+1529,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response));
    bufp->fullBit(oldp+1530,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms));
    bufp->fullBit(oldp+1531,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1));
    bufp->fullBit(oldp+1532,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0));
    bufp->fullBit(oldp+1533,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response) 
                                    | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms) 
                                       | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1) 
                                          | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0))))))));
    bufp->fullBit(oldp+1534,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1));
    bufp->fullBit(oldp+1535,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws0));
    bufp->fullBit(oldp+1536,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_pc__DOT__reset));
    bufp->fullBit(oldp+1537,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset));
    bufp->fullBit(oldp+1538,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0));
    bufp->fullIData(oldp+1539,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_pc_0),32);
    bufp->fullIData(oldp+1540,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0),32);
    bufp->fullIData(oldp+1541,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_mem_result_0),32);
    bufp->fullBit(oldp+1542,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_res_from_mem_0));
    bufp->fullBit(oldp+1543,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_0));
    bufp->fullBit(oldp+1544,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_byte_0));
    bufp->fullBit(oldp+1545,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_half_0));
    bufp->fullBit(oldp+1546,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_sign_ext_0));
    bufp->fullBit(oldp+1547,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_is_csr_0));
    bufp->fullSData(oldp+1548,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_num_0),14);
    bufp->fullIData(oldp+1549,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wmask_0),32);
    bufp->fullIData(oldp+1550,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wvalue_0),32);
    bufp->fullBit(oldp+1551,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_1));
    bufp->fullBit(oldp+1552,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_1));
    bufp->fullCData(oldp+1553,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state),3);
    bufp->fullIData(oldp+1554,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_load_result_0),32);
    bufp->fullCData(oldp+1555,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                >> 0x0000001aU)),6);
    bufp->fullCData(oldp+1556,((0x0000000fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x00000016U))),4);
    bufp->fullCData(oldp+1557,((3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                      >> 0x00000014U))),2);
    bufp->fullCData(oldp+1558,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x0000000fU))),5);
    bufp->fullCData(oldp+1559,((0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)),5);
    bufp->fullCData(oldp+1560,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 5U))),5);
    bufp->fullCData(oldp+1561,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x0000000aU))),5);
    bufp->fullSData(oldp+1562,((0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x0000000aU))),12);
    bufp->fullIData(oldp+1563,((0x000fffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 5U))),20);
    bufp->fullSData(oldp+1564,((0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x0000000aU))),16);
    bufp->fullIData(oldp+1565,(((0x03ff0000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                << 0x00000010U)) 
                                | (0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000000aU)))),26);
    bufp->fullQData(oldp+1566,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out),64);
    bufp->fullSData(oldp+1568,((((((((0x0fU == (0x0000000fU 
                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x00000016U))) 
                                     << 3U) | ((0x0eU 
                                                == 
                                                (0x0000000fU 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                    >> 0x00000016U))) 
                                               << 2U)) 
                                   | (((0x0dU == (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x00000016U))) 
                                       << 1U) | (0x0cU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x00000016U))))) 
                                  << 0x0000000cU) | 
                                 (((((0x0bU == (0x0000000fU 
                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x00000016U))) 
                                     << 3U) | ((0x0aU 
                                                == 
                                                (0x0000000fU 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                    >> 0x00000016U))) 
                                               << 2U)) 
                                   | (((9U == (0x0000000fU 
                                               & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x00000016U))) 
                                       << 1U) | (8U 
                                                 == 
                                                 (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x00000016U))))) 
                                  << 8U)) | ((((((7U 
                                                  == 
                                                  (0x0000000fU 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                      >> 0x00000016U))) 
                                                 << 3U) 
                                                | ((6U 
                                                    == 
                                                    (0x0000000fU 
                                                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x00000016U))) 
                                                   << 2U)) 
                                               | (((5U 
                                                    == 
                                                    (0x0000000fU 
                                                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                        >> 0x00000016U))) 
                                                   << 1U) 
                                                  | (4U 
                                                     == 
                                                     (0x0000000fU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x00000016U))))) 
                                              << 4U) 
                                             | ((((3U 
                                                   == 
                                                   (0x0000000fU 
                                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                       >> 0x00000016U))) 
                                                  << 3U) 
                                                 | ((2U 
                                                     == 
                                                     (0x0000000fU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x00000016U))) 
                                                    << 2U)) 
                                                | (((1U 
                                                     == 
                                                     (0x0000000fU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                         >> 0x00000016U))) 
                                                    << 1U) 
                                                   | (0U 
                                                      == 
                                                      (0x0000000fU 
                                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                          >> 0x00000016U)))))))),16);
    bufp->fullCData(oldp+1569,(((((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x00000014U))) 
                                  << 3U) | ((2U == 
                                             (3U & 
                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x00000014U))) 
                                            << 2U)) 
                                | (((1U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x00000014U))) 
                                    << 1U) | (0U == 
                                              (3U & 
                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x00000014U)))))),4);
    bufp->fullIData(oldp+1570,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec3__DOT__out),32);
    bufp->fullBit(oldp+1571,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_add_w));
    bufp->fullBit(oldp+1572,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sub_w));
    bufp->fullBit(oldp+1573,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slt));
    bufp->fullBit(oldp+1574,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltu));
    bufp->fullBit(oldp+1575,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_nor));
    bufp->fullBit(oldp+1576,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_and));
    bufp->fullBit(oldp+1577,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_or));
    bufp->fullBit(oldp+1578,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xor));
    bufp->fullBit(oldp+1579,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w));
    bufp->fullBit(oldp+1580,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w));
    bufp->fullBit(oldp+1581,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w));
    bufp->fullBit(oldp+1582,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_addi_w));
    bufp->fullBit(oldp+1583,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w));
    bufp->fullBit(oldp+1584,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_w));
    bufp->fullBit(oldp+1585,((0x13U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1586,((0x14U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1587,((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1588,((0x16U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1589,((0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1590,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w));
    bufp->fullBit(oldp+1591,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slti));
    bufp->fullBit(oldp+1592,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltui));
    bufp->fullBit(oldp+1593,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_andi));
    bufp->fullBit(oldp+1594,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ori));
    bufp->fullBit(oldp+1595,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xori));
    bufp->fullBit(oldp+1596,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w));
    bufp->fullBit(oldp+1597,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w));
    bufp->fullBit(oldp+1598,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w));
    bufp->fullBit(oldp+1599,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_pcaddu12i));
    bufp->fullBit(oldp+1600,((0x18U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1601,((0x19U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1602,((0x1aU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1603,((0x1bU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1604,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_b));
    bufp->fullBit(oldp+1605,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_h));
    bufp->fullBit(oldp+1606,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_bu));
    bufp->fullBit(oldp+1607,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_hu));
    bufp->fullBit(oldp+1608,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_b));
    bufp->fullBit(oldp+1609,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_h));
    bufp->fullBit(oldp+1610,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_mul_w));
    bufp->fullBit(oldp+1611,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cpucfg));
    bufp->fullBit(oldp+1612,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cacop));
    bufp->fullBit(oldp+1613,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrwr));
    bufp->fullBit(oldp+1614,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrxchg));
    bufp->fullBit(oldp+1615,((((((((((((((((((((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_53) 
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
                                | (0ULL != (0x000000000f780000ULL 
                                            & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out))) 
                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr)) 
                              | (0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU)))));
    bufp->fullBit(oldp+1616,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_bu) 
                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_b))));
    bufp->fullBit(oldp+1617,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_hu) 
                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_h))));
    bufp->fullBit(oldp+1618,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__ld_sign_ext));
    bufp->fullBit(oldp+1619,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12));
    bufp->fullBit(oldp+1620,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20));
    bufp->fullBit(oldp+1621,((0U != (3U & (IData)((vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                                   >> 0x00000014U))))));
    bufp->fullBit(oldp+1622,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4));
    bufp->fullIData(oldp+1623,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)
                                 ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)
                                          ? (0xfffff000U 
                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                << 7U))
                                          : ((((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                              >> 0x00000015U)))) 
                                               & (- (IData)(
                                                            (1U 
                                                             & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12)))))) 
                                              << 0x0000000cU) 
                                             | (0x00000fffU 
                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000000aU)))))),32);
    bufp->fullIData(oldp+1624,((((0U != (3U & (IData)(
                                                      (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                                       >> 0x00000014U))))
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
                                  : (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs 
                                     >> 2U)) << 2U)),32);
    bufp->fullIData(oldp+1625,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs),32);
    bufp->fullBit(oldp+1626,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd));
    bufp->fullBit(oldp+1627,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src1_is_pc));
    bufp->fullBit(oldp+1628,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w) 
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
                                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_52)))))))))))))));
    bufp->fullBit(oldp+1629,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w) 
                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_11))));
    bufp->fullBit(oldp+1630,(((~ ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__mem_we) 
                                    | (0ULL != (0x0000000000c00000ULL 
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
                                   | (0ULL != (0x000000000f780000ULL 
                                               & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out))) 
                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr)) 
                                 | (0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                              >> 0x0000001aU))))));
    bufp->fullBit(oldp+1631,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__mem_we));
    bufp->fullCData(oldp+1632,(((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))
                                 ? 1U : (0x0000001fU 
                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))),5);
    bufp->fullSData(oldp+1633,(((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w) 
                                    << 5U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w)) 
                                               << 4U) 
                                              | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w)) 
                                                 << 3U))) 
                                  | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w) 
                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w)) 
                                      << 2U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xor) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xori)) 
                                                 << 1U) 
                                                | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_or) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ori))))) 
                                 << 6U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_nor) 
                                             << 5U) 
                                            | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_and) 
                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_andi)) 
                                                << 4U) 
                                               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltu) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltui)) 
                                                  << 3U))) 
                                           | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slt) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slti)) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sub_w) 
                                                  << 1U) 
                                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_add_w) 
                                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_addi_w) 
                                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w) 
                                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_w) 
                                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src1_is_pc) 
                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_52))))))))))),12);
    bufp->fullBit(oldp+1634,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr));
    bufp->fullSData(oldp+1635,((0x00003fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x0000000aU))),14);
    bufp->fullCData(oldp+1636,((0x0000001fU & (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr))
                                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0
                                                : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000000aU)))),5);
    bufp->fullBit(oldp+1637,((1U & (~ (IData)((((0ULL 
                                                 != 
                                                 (0x0000000000300000ULL 
                                                  & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out)) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrwr)) 
                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)))))));
    bufp->fullBit(oldp+1638,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd) 
                              | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_53) 
                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w) 
                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w) 
                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w) 
                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_mul_w) 
                                             | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr)))))))));
    bufp->fullBit(oldp+1639,((IData)((((0ULL != (0x0000000000c00000ULL 
                                                 & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out)) 
                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)) 
                                      | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_54)))));
    bufp->fullCData(oldp+1640,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                >> 0x0000001aU)),6);
    bufp->fullCData(oldp+1641,((0x0000000fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x00000016U))),4);
    bufp->fullCData(oldp+1642,((3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                      >> 0x00000014U))),2);
    bufp->fullCData(oldp+1643,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x0000000fU))),5);
    bufp->fullCData(oldp+1644,((0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)),5);
    bufp->fullCData(oldp+1645,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 5U))),5);
    bufp->fullCData(oldp+1646,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x0000000aU))),5);
    bufp->fullSData(oldp+1647,((0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x0000000aU))),12);
    bufp->fullIData(oldp+1648,((0x000fffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 5U))),20);
    bufp->fullSData(oldp+1649,((0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x0000000aU))),16);
    bufp->fullIData(oldp+1650,(((0x03ff0000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                << 0x00000010U)) 
                                | (0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000000aU)))),26);
    bufp->fullQData(oldp+1651,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out),64);
    bufp->fullSData(oldp+1653,((((((((0x0fU == (0x0000000fU 
                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x00000016U))) 
                                     << 3U) | ((0x0eU 
                                                == 
                                                (0x0000000fU 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                    >> 0x00000016U))) 
                                               << 2U)) 
                                   | (((0x0dU == (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x00000016U))) 
                                       << 1U) | (0x0cU 
                                                 == 
                                                 (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x00000016U))))) 
                                  << 0x0000000cU) | 
                                 (((((0x0bU == (0x0000000fU 
                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x00000016U))) 
                                     << 3U) | ((0x0aU 
                                                == 
                                                (0x0000000fU 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                    >> 0x00000016U))) 
                                               << 2U)) 
                                   | (((9U == (0x0000000fU 
                                               & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x00000016U))) 
                                       << 1U) | (8U 
                                                 == 
                                                 (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x00000016U))))) 
                                  << 8U)) | ((((((7U 
                                                  == 
                                                  (0x0000000fU 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                      >> 0x00000016U))) 
                                                 << 3U) 
                                                | ((6U 
                                                    == 
                                                    (0x0000000fU 
                                                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x00000016U))) 
                                                   << 2U)) 
                                               | (((5U 
                                                    == 
                                                    (0x0000000fU 
                                                     & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                        >> 0x00000016U))) 
                                                   << 1U) 
                                                  | (4U 
                                                     == 
                                                     (0x0000000fU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x00000016U))))) 
                                              << 4U) 
                                             | ((((3U 
                                                   == 
                                                   (0x0000000fU 
                                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                       >> 0x00000016U))) 
                                                  << 3U) 
                                                 | ((2U 
                                                     == 
                                                     (0x0000000fU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x00000016U))) 
                                                    << 2U)) 
                                                | (((1U 
                                                     == 
                                                     (0x0000000fU 
                                                      & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                         >> 0x00000016U))) 
                                                    << 1U) 
                                                   | (0U 
                                                      == 
                                                      (0x0000000fU 
                                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                          >> 0x00000016U)))))))),16);
    bufp->fullCData(oldp+1654,(((((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x00000014U))) 
                                  << 3U) | ((2U == 
                                             (3U & 
                                              (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x00000014U))) 
                                            << 2U)) 
                                | (((1U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x00000014U))) 
                                    << 1U) | (0U == 
                                              (3U & 
                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x00000014U)))))),4);
    bufp->fullIData(oldp+1655,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec3__DOT__out),32);
    bufp->fullBit(oldp+1656,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_add_w));
    bufp->fullBit(oldp+1657,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sub_w));
    bufp->fullBit(oldp+1658,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slt));
    bufp->fullBit(oldp+1659,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltu));
    bufp->fullBit(oldp+1660,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_nor));
    bufp->fullBit(oldp+1661,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_and));
    bufp->fullBit(oldp+1662,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_or));
    bufp->fullBit(oldp+1663,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xor));
    bufp->fullBit(oldp+1664,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w));
    bufp->fullBit(oldp+1665,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w));
    bufp->fullBit(oldp+1666,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w));
    bufp->fullBit(oldp+1667,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_addi_w));
    bufp->fullBit(oldp+1668,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w));
    bufp->fullBit(oldp+1669,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_w));
    bufp->fullBit(oldp+1670,((0x13U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1671,((0x14U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1672,((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1673,((0x16U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1674,((0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1675,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w));
    bufp->fullBit(oldp+1676,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slti));
    bufp->fullBit(oldp+1677,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltui));
    bufp->fullBit(oldp+1678,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_andi));
    bufp->fullBit(oldp+1679,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ori));
    bufp->fullBit(oldp+1680,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xori));
    bufp->fullBit(oldp+1681,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w));
    bufp->fullBit(oldp+1682,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w));
    bufp->fullBit(oldp+1683,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w));
    bufp->fullBit(oldp+1684,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_pcaddu12i));
    bufp->fullBit(oldp+1685,((0x18U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1686,((0x19U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1687,((0x1aU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1688,((0x1bU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                        >> 0x0000001aU))));
    bufp->fullBit(oldp+1689,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_b));
    bufp->fullBit(oldp+1690,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_h));
    bufp->fullBit(oldp+1691,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_bu));
    bufp->fullBit(oldp+1692,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_hu));
    bufp->fullBit(oldp+1693,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_b));
    bufp->fullBit(oldp+1694,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_h));
    bufp->fullBit(oldp+1695,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_mul_w));
    bufp->fullBit(oldp+1696,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cpucfg));
    bufp->fullBit(oldp+1697,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cacop));
    bufp->fullBit(oldp+1698,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrwr));
    bufp->fullBit(oldp+1699,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrxchg));
    bufp->fullBit(oldp+1700,((((((((((((((((((((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_57) 
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
                                | (0ULL != (0x000000000f780000ULL 
                                            & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out))) 
                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr)) 
                              | (0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU)))));
    bufp->fullBit(oldp+1701,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_bu) 
                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_b))));
    bufp->fullBit(oldp+1702,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_hu) 
                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_h))));
    bufp->fullBit(oldp+1703,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__ld_sign_ext));
    bufp->fullBit(oldp+1704,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12));
    bufp->fullBit(oldp+1705,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20));
    bufp->fullBit(oldp+1706,((0U != (3U & (IData)((vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                                   >> 0x00000014U))))));
    bufp->fullBit(oldp+1707,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4));
    bufp->fullIData(oldp+1708,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)
                                 ? 4U : ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)
                                          ? (0xfffff000U 
                                             & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                << 7U))
                                          : ((((- (IData)(
                                                          (1U 
                                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                              >> 0x00000015U)))) 
                                               & (- (IData)(
                                                            (1U 
                                                             & (~ (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12)))))) 
                                              << 0x0000000cU) 
                                             | (0x00000fffU 
                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000000aU)))))),32);
    bufp->fullIData(oldp+1709,((((0U != (3U & (IData)(
                                                      (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                                       >> 0x00000014U))))
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
                                  : (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs 
                                     >> 2U)) << 2U)),32);
    bufp->fullIData(oldp+1710,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs),32);
    bufp->fullBit(oldp+1711,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd));
    bufp->fullBit(oldp+1712,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src1_is_pc));
    bufp->fullBit(oldp+1713,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w) 
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
                                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_56)))))))))))))));
    bufp->fullBit(oldp+1714,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w) 
                              | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_14))));
    bufp->fullBit(oldp+1715,(((~ ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__mem_we) 
                                    | (0ULL != (0x0000000000c00000ULL 
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
                                   | (0ULL != (0x000000000f780000ULL 
                                               & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out))) 
                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr)) 
                                 | (0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                              >> 0x0000001aU))))));
    bufp->fullBit(oldp+1716,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__mem_we));
    bufp->fullCData(oldp+1717,(((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))
                                 ? 1U : (0x0000001fU 
                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))),5);
    bufp->fullSData(oldp+1718,(((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w) 
                                    << 5U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w)) 
                                               << 4U) 
                                              | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w)) 
                                                 << 3U))) 
                                  | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w) 
                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w)) 
                                      << 2U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xor) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xori)) 
                                                 << 1U) 
                                                | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_or) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ori))))) 
                                 << 6U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_nor) 
                                             << 5U) 
                                            | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_and) 
                                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_andi)) 
                                                << 4U) 
                                               | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltu) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltui)) 
                                                  << 3U))) 
                                           | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slt) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slti)) 
                                               << 2U) 
                                              | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sub_w) 
                                                  << 1U) 
                                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_add_w) 
                                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_addi_w) 
                                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w) 
                                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_w) 
                                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src1_is_pc) 
                                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_56))))))))))),12);
    bufp->fullBit(oldp+1719,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr));
    bufp->fullSData(oldp+1720,((0x00003fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x0000000aU))),14);
    bufp->fullCData(oldp+1721,((0x0000001fU & (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr))
                                                ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1
                                                : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000000aU)))),5);
    bufp->fullBit(oldp+1722,((1U & (~ (IData)((((0ULL 
                                                 != 
                                                 (0x0000000000300000ULL 
                                                  & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out)) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrwr)) 
                                               | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)))))));
    bufp->fullBit(oldp+1723,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd) 
                              | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_57) 
                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w) 
                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w) 
                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w) 
                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_mul_w) 
                                             | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr)))))))));
    bufp->fullBit(oldp+1724,((IData)((((0ULL != (0x0000000000c00000ULL 
                                                 & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out)) 
                                       | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)) 
                                      | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_58)))));
    bufp->fullBit(oldp+1725,(vlSelfRef.asm_monitor_tb__DOT__clk));
    bufp->fullBit(oldp+1726,(vlSelfRef.asm_monitor_tb__DOT__program_exit));
    bufp->fullBit(oldp+1727,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0) 
                              & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                  >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                    < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)))));
    bufp->fullBit(oldp+1728,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1) 
                              & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                  >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                    < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)))));
    bufp->fullIData(oldp+1729,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp),32);
    bufp->fullIData(oldp+1730,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata),32);
    bufp->fullCData(oldp+1731,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte),8);
    bufp->fullSData(oldp+1732,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half),16);
    bufp->fullIData(oldp+1733,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ms_alu_result_1),32);
    bufp->fullCData(oldp+1734,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte),8);
    bufp->fullSData(oldp+1735,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half),16);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullBit(oldp+0,(__VdtypeVar[0U][0U]));
    bufp->fullBit(oldp+1,(__VdtypeVar[0U][1U]));
    bufp->fullBit(oldp+2,(__VdtypeVar[0U][2U]));
    bufp->fullBit(oldp+3,(__VdtypeVar[0U][3U]));
    bufp->fullBit(oldp+4,(__VdtypeVar[1U][0U]));
    bufp->fullBit(oldp+5,(__VdtypeVar[1U][1U]));
    bufp->fullBit(oldp+6,(__VdtypeVar[1U][2U]));
    bufp->fullBit(oldp+7,(__VdtypeVar[1U][3U]));
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*17:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____1\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0U][0U]),18);
    bufp->fullIData(oldp+1,(__VdtypeVar[0U][1U]),18);
    bufp->fullIData(oldp+2,(__VdtypeVar[0U][2U]),18);
    bufp->fullIData(oldp+3,(__VdtypeVar[0U][3U]),18);
    bufp->fullIData(oldp+4,(__VdtypeVar[1U][0U]),18);
    bufp->fullIData(oldp+5,(__VdtypeVar[1U][1U]),18);
    bufp->fullIData(oldp+6,(__VdtypeVar[1U][2U]),18);
    bufp->fullIData(oldp+7,(__VdtypeVar[1U][3U]),18);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*1:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____2\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[0U][0U]),2);
    bufp->fullCData(oldp+1,(__VdtypeVar[0U][1U]),2);
    bufp->fullCData(oldp+2,(__VdtypeVar[0U][2U]),2);
    bufp->fullCData(oldp+3,(__VdtypeVar[0U][3U]),2);
    bufp->fullCData(oldp+4,(__VdtypeVar[1U][0U]),2);
    bufp->fullCData(oldp+5,(__VdtypeVar[1U][1U]),2);
    bufp->fullCData(oldp+6,(__VdtypeVar[1U][2U]),2);
    bufp->fullCData(oldp+7,(__VdtypeVar[1U][3U]),2);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____3\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0U][0U]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[0U][1U]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[0U][2U]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[0U][3U]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[1U][0U]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[1U][1U]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[1U][2U]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[1U][3U]),32);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 8>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____4\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullBit(oldp+0,(__VdtypeVar[0U][0U]));
    bufp->fullBit(oldp+1,(__VdtypeVar[0U][1U]));
    bufp->fullBit(oldp+2,(__VdtypeVar[0U][2U]));
    bufp->fullBit(oldp+3,(__VdtypeVar[0U][3U]));
    bufp->fullBit(oldp+4,(__VdtypeVar[0U][4U]));
    bufp->fullBit(oldp+5,(__VdtypeVar[0U][5U]));
    bufp->fullBit(oldp+6,(__VdtypeVar[0U][6U]));
    bufp->fullBit(oldp+7,(__VdtypeVar[0U][7U]));
    bufp->fullBit(oldp+8,(__VdtypeVar[1U][0U]));
    bufp->fullBit(oldp+9,(__VdtypeVar[1U][1U]));
    bufp->fullBit(oldp+10,(__VdtypeVar[1U][2U]));
    bufp->fullBit(oldp+11,(__VdtypeVar[1U][3U]));
    bufp->fullBit(oldp+12,(__VdtypeVar[1U][4U]));
    bufp->fullBit(oldp+13,(__VdtypeVar[1U][5U]));
    bufp->fullBit(oldp+14,(__VdtypeVar[1U][6U]));
    bufp->fullBit(oldp+15,(__VdtypeVar[1U][7U]));
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____5\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),25);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),25);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),25);
    bufp->fullIData(oldp+3,(__VdtypeVar[3]),25);
    bufp->fullIData(oldp+4,(__VdtypeVar[4]),25);
    bufp->fullIData(oldp+5,(__VdtypeVar[5]),25);
    bufp->fullIData(oldp+6,(__VdtypeVar[6]),25);
    bufp->fullIData(oldp+7,(__VdtypeVar[7]),25);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____6\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),25);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),25);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),25);
    bufp->fullIData(oldp+3,(__VdtypeVar[3]),25);
    bufp->fullIData(oldp+4,(__VdtypeVar[4]),25);
    bufp->fullIData(oldp+5,(__VdtypeVar[5]),25);
    bufp->fullIData(oldp+6,(__VdtypeVar[6]),25);
    bufp->fullIData(oldp+7,(__VdtypeVar[7]),25);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____7\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullWData(oldp+0,(__VdtypeVar[0]),128);
    bufp->fullWData(oldp+4,(__VdtypeVar[1]),128);
    bufp->fullWData(oldp+8,(__VdtypeVar[2]),128);
    bufp->fullWData(oldp+12,(__VdtypeVar[3]),128);
    bufp->fullWData(oldp+16,(__VdtypeVar[4]),128);
    bufp->fullWData(oldp+20,(__VdtypeVar[5]),128);
    bufp->fullWData(oldp+24,(__VdtypeVar[6]),128);
    bufp->fullWData(oldp+28,(__VdtypeVar[7]),128);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____8\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullWData(oldp+0,(__VdtypeVar[0]),128);
    bufp->fullWData(oldp+4,(__VdtypeVar[1]),128);
    bufp->fullWData(oldp+8,(__VdtypeVar[2]),128);
    bufp->fullWData(oldp+12,(__VdtypeVar[3]),128);
    bufp->fullWData(oldp+16,(__VdtypeVar[4]),128);
    bufp->fullWData(oldp+20,(__VdtypeVar[5]),128);
    bufp->fullWData(oldp+24,(__VdtypeVar[6]),128);
    bufp->fullWData(oldp+28,(__VdtypeVar[7]),128);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<9>/*265:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____9\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullWData(oldp+0,(__VdtypeVar[0]),266);
    bufp->fullWData(oldp+9,(__VdtypeVar[1]),266);
    bufp->fullWData(oldp+18,(__VdtypeVar[2]),266);
    bufp->fullWData(oldp+27,(__VdtypeVar[3]),266);
}

VL_ATTR_COLD void Vasm_monitor_tb___024root__trace_full_dtype____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_full_dtype____10\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[31]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[30]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[29]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[28]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[27]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[26]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[25]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[24]),32);
    bufp->fullIData(oldp+8,(__VdtypeVar[23]),32);
    bufp->fullIData(oldp+9,(__VdtypeVar[22]),32);
    bufp->fullIData(oldp+10,(__VdtypeVar[21]),32);
    bufp->fullIData(oldp+11,(__VdtypeVar[20]),32);
    bufp->fullIData(oldp+12,(__VdtypeVar[19]),32);
    bufp->fullIData(oldp+13,(__VdtypeVar[18]),32);
    bufp->fullIData(oldp+14,(__VdtypeVar[17]),32);
    bufp->fullIData(oldp+15,(__VdtypeVar[16]),32);
    bufp->fullIData(oldp+16,(__VdtypeVar[15]),32);
    bufp->fullIData(oldp+17,(__VdtypeVar[14]),32);
    bufp->fullIData(oldp+18,(__VdtypeVar[13]),32);
    bufp->fullIData(oldp+19,(__VdtypeVar[12]),32);
    bufp->fullIData(oldp+20,(__VdtypeVar[11]),32);
    bufp->fullIData(oldp+21,(__VdtypeVar[10]),32);
    bufp->fullIData(oldp+22,(__VdtypeVar[9]),32);
    bufp->fullIData(oldp+23,(__VdtypeVar[8]),32);
    bufp->fullIData(oldp+24,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+25,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+26,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+27,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+28,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+29,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+30,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+31,(__VdtypeVar[0]),32);
}
