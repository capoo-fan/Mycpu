// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vasm_monitor_tb__Syms.h"


void Vasm_monitor_tb___024root__trace_chg_0_sub_0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vasm_monitor_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_0\n"); );
    // Body
    Vasm_monitor_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vasm_monitor_tb___024root*>(voidSelf);
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vasm_monitor_tb___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 2>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*17:0*/, 4>, 2>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*1:0*/, 4>, 2>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 2>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 8>, 2>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar);
void Vasm_monitor_tb___024root__trace_chg_dtype____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar);
extern const VlUnpacked<CData/*2:0*/, 2048> Vasm_monitor_tb__ConstPool__TABLE_he47f3c48_0;
void Vasm_monitor_tb___024root__trace_chg_dtype____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<9>/*265:0*/, 4>& __VdtypeVar);
extern const VlUnpacked<CData/*0:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h2c364be9_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h547ba932_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0;
void Vasm_monitor_tb___024root__trace_chg_dtype____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vasm_monitor_tb___024root__trace_chg_0_sub_0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_0_sub_0\n"); );
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
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.asm_monitor_tb__DOT__load_program__Vstatic__n),32);
        bufp->chgIData(oldp+1,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__n),32);
        bufp->chgIData(oldp+2,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__mismatch_count),32);
        bufp->chgIData(oldp+3,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__addr),32);
        bufp->chgIData(oldp+4,(vlSelfRef.asm_monitor_tb__DOT__compare_results__Vstatic__actual),32);
        bufp->chgIData(oldp+5,(vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__n),32);
        bufp->chgIData(oldp+6,(vlSelfRef.asm_monitor_tb__DOT__print_report__Vstatic__addr),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[2U] 
                      | vlSelfRef.__Vm_traceActivity[3U])))) {
        bufp->chgBit(oldp+7,(vlSelfRef.asm_monitor_tb__DOT__resetn));
        bufp->chgBit(oldp+8,(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready));
        bufp->chgCData(oldp+9,(vlSelfRef.asm_monitor_tb__DOT__uart_rx_data),8);
        bufp->chgIData(oldp+10,(vlSelfRef.asm_monitor_tb__DOT__i),32);
        bufp->chgIData(oldp+11,(vlSelfRef.asm_monitor_tb__DOT__base_words),32);
        bufp->chgIData(oldp+12,(vlSelfRef.asm_monitor_tb__DOT__program_words),32);
        bufp->chgIData(oldp+13,(vlSelfRef.asm_monitor_tb__DOT__watch_words),32);
        bufp->chgIData(oldp+14,(vlSelfRef.asm_monitor_tb__DOT__data_words),32);
        bufp->chgIData(oldp+15,(vlSelfRef.asm_monitor_tb__DOT__expect_words),32);
        bufp->chgIData(oldp+16,(vlSelfRef.asm_monitor_tb__DOT__init_fd),32);
        bufp->chgIData(oldp+17,(vlSelfRef.asm_monitor_tb__DOT__init_status),32);
        bufp->chgIData(oldp+18,(vlSelfRef.asm_monitor_tb__DOT__init_line_status),32);
        bufp->chgIData(oldp+19,(vlSelfRef.asm_monitor_tb__DOT__entry_addr),32);
        bufp->chgIData(oldp+20,(vlSelfRef.asm_monitor_tb__DOT__program_addr),32);
        bufp->chgIData(oldp+21,(vlSelfRef.asm_monitor_tb__DOT__watch_addr),32);
        bufp->chgIData(oldp+22,(vlSelfRef.asm_monitor_tb__DOT__data_load_addr),32);
        bufp->chgIData(oldp+23,(vlSelfRef.asm_monitor_tb__DOT__expect_addr),32);
        bufp->chgIData(oldp+24,(vlSelfRef.asm_monitor_tb__DOT__expect_value),32);
        bufp->chgIData(oldp+25,(vlSelfRef.asm_monitor_tb__DOT__init_addr),32);
        bufp->chgIData(oldp+26,(vlSelfRef.asm_monitor_tb__DOT__init_value),32);
        bufp->chgWData(oldp+27,(vlSelfRef.asm_monitor_tb__DOT__base_file),1024);
        bufp->chgWData(oldp+59,(vlSelfRef.asm_monitor_tb__DOT__program_file),1024);
        bufp->chgWData(oldp+91,(vlSelfRef.asm_monitor_tb__DOT__data_file),1024);
        bufp->chgWData(oldp+123,(vlSelfRef.asm_monitor_tb__DOT__expect_file),1024);
        bufp->chgWData(oldp+155,(vlSelfRef.asm_monitor_tb__DOT__init_file),1024);
        bufp->chgWData(oldp+187,(vlSelfRef.asm_monitor_tb__DOT__init_line),1024);
        bufp->chgWData(oldp+219,(vlSelfRef.asm_monitor_tb__DOT__wave_file),1024);
        bufp->chgBit(oldp+251,(vlSelfRef.asm_monitor_tb__DOT__data_enabled));
        bufp->chgBit(oldp+252,(vlSelfRef.asm_monitor_tb__DOT__expect_file_enabled));
        bufp->chgBit(oldp+253,(vlSelfRef.asm_monitor_tb__DOT__expect_value_enabled));
        bufp->chgQData(oldp+254,(vlSelfRef.asm_monitor_tb__DOT__max_cycles),64);
        bufp->chgQData(oldp+256,(vlSelfRef.asm_monitor_tb__DOT__wait_cycles),64);
        bufp->chgCData(oldp+258,(vlSelfRef.asm_monitor_tb__DOT__send_rx_byte__Vstatic__value),8);
        bufp->chgIData(oldp+259,(vlSelfRef.asm_monitor_tb__DOT__wait_tx__Vstatic__wanted),32);
        bufp->chgCData(oldp+260,((0x00000020U | (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready))),8);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[2U] 
                       | vlSelfRef.__Vm_traceActivity[3U]) 
                      | vlSelfRef.__Vm_traceActivity[5U])))) {
        bufp->chgIData(oldp+261,((vlSelfRef.asm_monitor_tb__DOT__base_mem
                                  [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr] 
                                  & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_data_ok))))),32);
        bufp->chgIData(oldp+262,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                                   ? vlSelfRef.asm_monitor_tb__DOT__base_mem
                                  [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]
                                   : ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok)
                                       ? vlSelfRef.asm_monitor_tb__DOT__ext_mem
                                      [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr]
                                       : (vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg 
                                          & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid))))))),32);
        bufp->chgIData(oldp+263,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok)
                                   ? vlSelfRef.asm_monitor_tb__DOT__base_mem
                                  [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]
                                   : vlSelfRef.asm_monitor_tb__DOT__ext_mem
                                  [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr])),32);
        bufp->chgIData(oldp+264,(vlSelfRef.asm_monitor_tb__DOT__base_mem
                                 [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr]),32);
        bufp->chgIData(oldp+265,(vlSelfRef.asm_monitor_tb__DOT__ext_mem
                                 [vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr]),32);
        bufp->chgIData(oldp+266,(vlSelfRef.asm_monitor_tb__DOT__tx_count),32);
        bufp->chgIData(oldp+267,(vlSelfRef.asm_monitor_tb__DOT__write_log_count),32);
        bufp->chgQData(oldp+268,(vlSelfRef.asm_monitor_tb__DOT__cycle_count),64);
        bufp->chgBit(oldp+270,(vlSelfRef.asm_monitor_tb__DOT__command_counting));
        bufp->chgBit(oldp+271,(vlSelfRef.asm_monitor_tb__DOT__command_done));
        bufp->chgBit(oldp+272,(vlSelfRef.asm_monitor_tb__DOT__user_counting));
        bufp->chgBit(oldp+273,(vlSelfRef.asm_monitor_tb__DOT__user_done));
        bufp->chgBit(oldp+274,(vlSelfRef.asm_monitor_tb__DOT__exit_seen));
        bufp->chgIData(oldp+275,(vlSelfRef.asm_monitor_tb__DOT__exit_pc),32);
        bufp->chgQData(oldp+276,(vlSelfRef.asm_monitor_tb__DOT__command_cycles),64);
        bufp->chgQData(oldp+278,(vlSelfRef.asm_monitor_tb__DOT__command_instr),64);
        bufp->chgQData(oldp+280,(vlSelfRef.asm_monitor_tb__DOT__user_cycles),64);
        bufp->chgQData(oldp+282,(vlSelfRef.asm_monitor_tb__DOT__user_instr),64);
        bufp->chgQData(oldp+284,(vlSelfRef.asm_monitor_tb__DOT__write_count),64);
        bufp->chgBit(oldp+286,(((IData)(vlSelfRef.asm_monitor_tb__DOT__exit_seen) 
                                & (((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                     == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1)) 
                                   | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                       == vlSelfRef.asm_monitor_tb__DOT__exit_pc) 
                                      & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0))))));
        bufp->chgCData(oldp+287,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset))
                                   ? (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_data)
                                   : ((- (IData)((5U 
                                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset)))) 
                                      & (0x00000020U 
                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__uart_rx_ready))))),8);
    }
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[4U] 
                       | vlSelfRef.__Vm_traceActivity[5U]) 
                      | vlSelfRef.__Vm_traceActivity[6U])))) {
        bufp->chgBit(oldp+288,(((((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                   == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1)) 
                                 | ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                     == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc) 
                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0))) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__program_exit))));
        __Vtemp_1[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0)) 
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
                                                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0))))))))) 
                          >> 0x00000011U) | ((IData)(
                                                     ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0)) 
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
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0))) 
                                 >> 0x00000020U));
        __Vtemp_3[2U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata)) 
                                  << 0x0000000fU) | (QData)((IData)(
                                                                    (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0) 
                                                                      << 0x0000000eU) 
                                                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0))))));
        __Vtemp_3[3U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0)) 
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
                                                               | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0))))))))) 
                          << 0x0000000fU) | (IData)(
                                                    ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata)) 
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
        bufp->chgWData(oldp+289,(__Vtemp_3),185);
        bufp->chgQData(oldp+295,((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ms_alu_result_1)) 
                                   << 6U) | (QData)((IData)(
                                                            (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1) 
                                                              << 5U) 
                                                             | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)))))),38);
        bufp->chgIData(oldp+297,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)),32);
        bufp->chgIData(oldp+298,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0)),32);
        bufp->chgIData(oldp+299,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_0)),32);
        bufp->chgIData(oldp+300,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src2_0)),32);
        bufp->chgIData(oldp+301,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp
                                   : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms)
                                       ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0
                                       : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1)
                                           ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                           : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0)
                                               ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                               : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))))),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgBit(oldp+302,((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))));
        bufp->chgIData(oldp+303,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr),32);
        bufp->chgBit(oldp+304,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr_ok));
        bufp->chgBit(oldp+305,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_data_ok));
        bufp->chgBit(oldp+306,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_req));
        bufp->chgBit(oldp+307,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q));
        bufp->chgCData(oldp+308,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_half) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half))
                                    ? 1U : 2U) & (- (IData)(
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_byte) 
                                                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte)))))))),2);
        bufp->chgCData(oldp+309,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_wstrb),4);
        bufp->chgIData(oldp+310,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__paddr),32);
        bufp->chgIData(oldp+311,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_wdata),32);
        bufp->chgBit(oldp+312,((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept)) 
                                | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant) 
                                   | ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept))))));
        bufp->chgBit(oldp+313,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_data_ok));
        bufp->chgBit(oldp+314,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_fast_ready));
        bufp->chgBit(oldp+315,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg))));
        bufp->chgCData(oldp+316,((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_ready) 
                                   << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_ready))),2);
        bufp->chgIData(oldp+317,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_addr),20);
        bufp->chgIData(oldp+318,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_addr),20);
        bufp->chgIData(oldp+319,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_wdata),32);
        bufp->chgIData(oldp+320,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_wdata),32);
        bufp->chgCData(oldp+321,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_ram_be_n),4);
        bufp->chgCData(oldp+322,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_ram_be_n),4);
        bufp->chgBit(oldp+323,((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain) 
                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active))))));
        bufp->chgBit(oldp+324,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active)))));
        bufp->chgBit(oldp+325,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain)))));
        bufp->chgBit(oldp+326,((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) 
                                         | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active))))));
        bufp->chgBit(oldp+327,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active)))));
        bufp->chgBit(oldp+328,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain)))));
        bufp->chgBit(oldp+329,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rx_clear_reg));
        bufp->chgBit(oldp+330,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_start_reg));
        bufp->chgCData(oldp+331,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_tx_data_reg),8);
        bufp->chgIData(oldp+332,(vlSelfRef.asm_monitor_tb__DOT__branch_next_pc),32);
        bufp->chgCData(oldp+333,((3U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1) 
                                        + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0)))),2);
        bufp->chgBit(oldp+334,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                      >> 0x00000018U))));
        bufp->chgBit(oldp+335,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                      >> 0x00000016U))));
        bufp->chgCData(oldp+336,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state),2);
        bufp->chgBit(oldp+337,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_client_data));
        bufp->chgBit(oldp+338,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg));
        bufp->chgBit(oldp+339,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_ready_reg));
        bufp->chgIData(oldp+340,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg),32);
        bufp->chgBit(oldp+341,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_valid));
        bufp->chgIData(oldp+342,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_addr),32);
        bufp->chgIData(oldp+343,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wdata),32);
        bufp->chgCData(oldp+344,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_wstrb),4);
        bufp->chgBit(oldp+345,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_resp_valid));
        bufp->chgBit(oldp+346,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_req));
        bufp->chgBit(oldp+347,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_req))));
        bufp->chgBit(oldp+348,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain));
        bufp->chgBit(oldp+349,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_ready));
        bufp->chgBit(oldp+350,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept));
        bufp->chgBit(oldp+351,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_read));
        bufp->chgBit(oldp+352,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data));
        bufp->chgBit(oldp+353,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant));
        bufp->chgBit(oldp+354,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_state))));
        bufp->chgIData(oldp+355,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__paddr
                                   : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr_ok)
                                       ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr
                                       : vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_addr_reg))),32);
        bufp->chgBit(oldp+356,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active));
        bufp->chgBit(oldp+357,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_drain) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_read_active))));
        bufp->chgBit(oldp+358,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_grant_data) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_accept))));
        bufp->chgBit(oldp+359,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_data_data_ok));
        bufp->chgCData(oldp+360,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state),2);
        bufp->chgBit(oldp+361,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg));
        bufp->chgBit(oldp+362,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_ready_reg));
        bufp->chgIData(oldp+363,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg),32);
        bufp->chgBit(oldp+364,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_valid));
        bufp->chgIData(oldp+365,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_addr),32);
        bufp->chgIData(oldp+366,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wdata),32);
        bufp->chgCData(oldp+367,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_wstrb),4);
        bufp->chgBit(oldp+368,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_resp_valid));
        bufp->chgBit(oldp+369,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_req));
        bufp->chgBit(oldp+370,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_req))));
        bufp->chgBit(oldp+371,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain));
        bufp->chgBit(oldp+372,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_ready));
        bufp->chgBit(oldp+373,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept));
        bufp->chgBit(oldp+374,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant));
        bufp->chgBit(oldp+375,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_state))));
        bufp->chgIData(oldp+376,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__paddr
                                   : vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_addr_reg)),32);
        bufp->chgBit(oldp+377,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active));
        bufp->chgBit(oldp+378,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_drain) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_read_active))));
        bufp->chgBit(oldp+379,(((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_grant) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_accept))));
        bufp->chgBit(oldp+380,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_data_data_ok));
        bufp->chgCData(oldp+381,((7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr)),3);
        bufp->chgBit(oldp+382,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab));
        bufp->chgCData(oldp+383,((0x000000ffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_wdata)),8);
        bufp->chgBit(oldp+384,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                 >> 0x00000018U) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_req))));
        bufp->chgBit(oldp+385,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_q) 
                                & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_dlab)) 
                                   & (0U == (7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr))))));
        bufp->chgBit(oldp+386,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_pending));
        bufp->chgBit(oldp+387,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_wr));
        bufp->chgCData(oldp+388,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_offset),3);
        bufp->chgCData(oldp+389,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_req_write_byte),8);
        bufp->chgBit(oldp+390,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_grant));
        bufp->chgBit(oldp+391,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_exec_tx_write));
        bufp->chgBit(oldp+392,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_resp_valid));
        bufp->chgIData(oldp+393,(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__uart_rdata_reg),32);
        bufp->chgBit(oldp+394,((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))));
        bufp->chgIData(oldp+395,((0xfffffff0U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr)),32);
        bufp->chgBit(oldp+396,((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state))));
        bufp->chgBit(oldp+397,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r));
        bufp->chgCData(oldp+398,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r),2);
        bufp->chgIData(oldp+399,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_data_r),32);
        bufp->chgBit(oldp+400,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_allowin));
        bufp->chgBit(oldp+401,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__packet_ready_go));
        bufp->chgBit(oldp+402,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_0));
        bufp->chgBit(oldp+403,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_valid_1));
        __Vtemp_4[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                                  << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))));
        __Vtemp_4[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                          << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                                              << 0x00000020U) 
                                             | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))) 
                                            >> 0x00000020U)));
        __Vtemp_4[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                          >> 0x0000001fU) | ((IData)(
                                                     ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                                        << 0x00000020U) 
                                                       | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                                                      >> 0x00000020U)) 
                                             << 1U));
        __Vtemp_4[3U] = ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))) 
                                  >> 0x00000020U)) 
                         >> 0x0000001fU);
        bufp->chgWData(oldp+404,(__Vtemp_4),97);
        __Vtemp_5[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                                  << 0x00000020U) | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))));
        __Vtemp_5[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                          << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                                              << 0x00000020U) 
                                             | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))) 
                                            >> 0x00000020U)));
        __Vtemp_5[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                          >> 0x0000001fU) | ((IData)(
                                                     ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                                        << 0x00000020U) 
                                                       | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                                                      >> 0x00000020U)) 
                                             << 1U));
        __Vtemp_5[3U] = ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))) 
                                  >> 0x00000020U)) 
                         >> 0x0000001fU);
        bufp->chgWData(oldp+408,(__Vtemp_5),97);
        bufp->chgBit(oldp+412,((2U >= (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt))));
        bufp->chgBit(oldp+413,((2U < (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt))));
        bufp->chgBit(oldp+414,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r));
        bufp->chgBit(oldp+415,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r));
        bufp->chgWData(oldp+416,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0),266);
        bufp->chgWData(oldp+425,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1),266);
        bufp->chgCData(oldp+434,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r),5);
        bufp->chgCData(oldp+435,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0),5);
        bufp->chgCData(oldp+436,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot),5);
        bufp->chgCData(oldp+437,((0x0000001fU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                         >> 0x0000000dU)))),5);
        bufp->chgBit(oldp+438,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__pop_0));
        bufp->chgBit(oldp+439,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__pop_1));
        bufp->chgBit(oldp+440,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_to_es_valid_0));
        bufp->chgBit(oldp+441,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_to_es_valid_1));
        bufp->chgBit(oldp+442,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_to_ms_valid_0));
        bufp->chgBit(oldp+443,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_to_ms_valid_1));
        bufp->chgBit(oldp+444,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0));
        bufp->chgBit(oldp+445,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1));
        __Vtemp_7[4U] = (((IData)((((QData)((IData)(
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
                          >> 0x00000012U) | ((IData)(
                                                     ((((QData)((IData)(
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
                          << 0x00000019U) | (IData)(
                                                    ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_offs_0)) 
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
                                                               >> 4U)))))))) 
                          << 0x0000001eU) | (((IData)(
                                                      ((0x0000001ffffffff0ULL 
                                                        & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                                           << 4U)) 
                                                       | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_0)))) 
                                              >> 7U) 
                                             | ((IData)(
                                                        (((0x0000001ffffffff0ULL 
                                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                                              << 4U)) 
                                                          | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_0))) 
                                                         >> 0x00000020U)) 
                                                << 0x00000019U)));
        __Vtemp_9[3U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0)) 
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
        __Vtemp_9[4U] = (((0x3ffff000U & ((IData)((
                                                   ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
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
                             >> 2U)) | (0xc0000000U 
                                        & ((IData)(
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0)))) 
                                           << 0x0000000cU)));
        __Vtemp_9[5U] = ((((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0)))) 
                           >> 0x00000014U) | (0x3ffff000U 
                                              & ((IData)(
                                                         ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                                            << 0x00000020U) 
                                                           | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0))) 
                                                          >> 0x00000020U)) 
                                                 << 0x0000000cU))) 
                         | (0xc0000000U & ((IData)(
                                                   ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                                      << 0x00000020U) 
                                                     | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0))) 
                                                    >> 0x00000020U)) 
                                           << 0x0000000cU)));
        __Vtemp_9[6U] = ((((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0)) 
                                      << 0x00000020U) 
                                     | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0))) 
                                    >> 0x00000020U)) 
                           >> 0x00000014U) | (0x3ffff000U 
                                              & ((IData)(
                                                         (((QData)((IData)(
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
        bufp->chgWData(oldp+446,(__Vtemp_9),254);
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
                                   << 0x00000020U) 
                                  | (QData)((IData)(
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
        __Vtemp_15[4U] = (((IData)((((QData)((IData)(
                                                     (0x00000fffU 
                                                      & (IData)(
                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                                 >> 0x0000001dU))))) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1)))) 
                           << 0x00000013U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_1 
                                              >> 0x0000000dU));
        __Vtemp_15[5U] = (((IData)((((QData)((IData)(
                                                     (0x00000fffU 
                                                      & (IData)(
                                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                                 >> 0x0000001dU))))) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1)))) 
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
        bufp->chgWData(oldp+454,(__Vtemp_15),223);
        bufp->chgIData(oldp+461,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_0),32);
        bufp->chgIData(oldp+462,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src2_0),32);
        bufp->chgIData(oldp+463,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_1),32);
        bufp->chgIData(oldp+464,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src2_1),32);
        __Vtemp_20[3U] = ((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0) 
                              << 0x0000000dU) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0) 
                                                  << 0x0000000cU) 
                                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0) 
                                                    << 0x0000000bU))) 
                            | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0) 
                                 << 6U) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0) 
                                           << 5U)) 
                               | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0) 
                                    << 4U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0) 
                                               << 3U) 
                                              | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0) 
                                                 << 2U))) 
                                  | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0) 
                                      << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0))))) 
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
        __Vtemp_20[4U] = (((0x00ffffc0U & ((IData)(
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0)))) 
                                           << 6U)) 
                           | (((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0) 
                                 << 0x0000000dU) | 
                                (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0) 
                                  << 0x0000000cU) | 
                                 ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0) 
                                  << 0x0000000bU))) 
                               | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0) 
                                    << 6U) | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0) 
                                              << 5U)) 
                                  | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0) 
                                       << 4U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0) 
                                                  << 3U) 
                                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0) 
                                                    << 2U))) 
                                     | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0) 
                                         << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0))))) 
                              >> 8U)) | (0xff000000U 
                                         & ((IData)(
                                                    (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                      << 0x00000020U) 
                                                     | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0)))) 
                                            << 6U)));
        __Vtemp_20[5U] = ((((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                      << 0x00000020U) 
                                     | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0)))) 
                            >> 0x0000001aU) | (0x00ffffc0U 
                                               & ((IData)(
                                                          ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                             << 0x00000020U) 
                                                            | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))) 
                                                           >> 0x00000020U)) 
                                                  << 6U))) 
                          | (0xff000000U & ((IData)(
                                                    ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                                       << 0x00000020U) 
                                                      | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))) 
                                                     >> 0x00000020U)) 
                                            << 6U)));
        __Vtemp_20[6U] = (((0x00ffffc0U & ((IData)(
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                                     << 0x00000026U) 
                                                    | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0)) 
                                                        << 0x00000021U) 
                                                       | (((QData)((IData)(
                                                                           (1U 
                                                                            & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_49))))) 
                                                           << 0x00000020U) 
                                                          | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)))))) 
                                           << 6U)) 
                           | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0)) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0))) 
                                       >> 0x00000020U)) 
                              >> 0x0000001aU)) | (0xff000000U 
                                                  & ((IData)(
                                                             (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
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
                                     << 0x00000026U) 
                                    | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0)) 
                                        << 0x00000021U) 
                                       | (((QData)((IData)(
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
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0))));
        __Vtemp_21[1U] = (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0)) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0))) 
                                  >> 0x00000020U));
        __Vtemp_21[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(
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
                                     << 0x00000020U) 
                                    | (QData)((IData)(
                                                      ((IData)(4U) 
                                                       + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0))))) 
                           >> 0x0000000aU) | ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)) 
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
                           << 0x00000016U) | ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)) 
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
        bufp->chgWData(oldp+465,(__Vtemp_21),301);
        __Vtemp_25[3U] = (((IData)((((QData)((IData)(
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
                                        << 2U) | (QData)((IData)(
                                                                 (((0U 
                                                                    != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                                                                   << 1U) 
                                                                  | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1))))))) 
                           >> 0x0000001fU) | ((IData)(
                                                      ((((QData)((IData)(
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
                                     << 0x00000020U) 
                                    | (QData)((IData)(
                                                      ((IData)(4U) 
                                                       + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1))))) 
                           << 1U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_1));
        __Vtemp_26[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(
                                                      ((IData)(4U) 
                                                       + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1))))) 
                           >> 0x0000001fU) | ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)) 
                                                         << 0x00000020U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)))) 
                                                       >> 0x00000020U)) 
                                              << 1U));
        __Vtemp_26[2U] = (((IData)((((QData)((IData)(
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
                                            << 7U) 
                                           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1) 
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
        __Vtemp_26[5U] = ((0x000000ffU & ((IData)((
                                                   ((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                    << 0x00000020U) 
                                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1)))) 
                                          >> 0x0000000fU)) 
                          | ((0x0001ff00U & ((IData)(
                                                     (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                       << 0x00000020U) 
                                                      | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1)))) 
                                             >> 0x0000000fU)) 
                             | ((IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                           << 0x00000020U) 
                                          | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))) 
                                         >> 0x00000020U)) 
                                << 0x00000011U)));
        __Vtemp_26[6U] = ((0x000000ffU & ((IData)((
                                                   (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                     << 0x00000020U) 
                                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))) 
                                                   >> 0x00000020U)) 
                                          >> 0x0000000fU)) 
                          | (0x0001ff00U & ((IData)(
                                                    ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)) 
                                                       << 0x00000020U) 
                                                      | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))) 
                                                     >> 0x00000020U)) 
                                            >> 0x0000000fU)));
        bufp->chgWData(oldp+475,(__Vtemp_26),209);
        bufp->chgQData(oldp+482,((((QData)((IData)(
                                                   (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                                                     << 1U) 
                                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0)))) 
                                   << 0x00000027U) 
                                  | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0)) 
                                      << 0x00000026U) 
                                     | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0)) 
                                         << 0x00000025U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0)) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0))))))),41);
        bufp->chgQData(oldp+484,((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1)) 
                                   << 0x00000027U) 
                                  | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1)) 
                                      << 0x00000026U) 
                                     | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1)) 
                                         << 0x00000025U) 
                                        | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1)) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1))))))),40);
        bufp->chgQData(oldp+486,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_0),41);
        bufp->chgQData(oldp+488,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_1),40);
        bufp->chgBit(oldp+490,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__load_wakeup_valid));
        __Vtemp_28[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1)) 
                                   << 0x00000025U) 
                                  | (((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
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
        bufp->chgWData(oldp+491,(__Vtemp_28),76);
        bufp->chgBit(oldp+494,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q));
        bufp->chgIData(oldp+495,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q 
                                  & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q))))),32);
        bufp->chgBit(oldp+496,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0))));
        bufp->chgBit(oldp+497,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0))));
        bufp->chgBit(oldp+498,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_is_csr_0)) 
                                | (0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state)))));
        bufp->chgBit(oldp+499,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0))));
        bufp->chgBit(oldp+500,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_cacop_0))));
        bufp->chgBit(oldp+501,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__special_block));
        bufp->chgBit(oldp+502,(((IData)((0ULL != (0x0000000010400000ULL 
                                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2))) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_to_es_valid_0))));
        bufp->chgSData(oldp+503,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0),14);
        bufp->chgIData(oldp+504,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0))
                                   ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg)
                                   : ((0x0180U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0))
                                       ? (0xee000039U 
                                          & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg)
                                       : (0xee000039U 
                                          & ((- (IData)(
                                                        (0x0181U 
                                                         == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_num_0)))) 
                                             & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg))))),32);
        bufp->chgBit(oldp+505,((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))));
        bufp->chgSData(oldp+506,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_addr),14);
        bufp->chgIData(oldp+507,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask),32);
        bufp->chgIData(oldp+508,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_data),32);
        bufp->chgIData(oldp+509,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg),32);
        bufp->chgIData(oldp+510,((0xee000039U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg)),32);
        bufp->chgIData(oldp+511,((0xee000039U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg)),32);
        bufp->chgSData(oldp+512,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__trans_ctx_reg),14);
        bufp->chgBit(oldp+513,((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))));
        bufp->chgBit(oldp+514,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))));
        bufp->chgIData(oldp+515,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target),32);
        bufp->chgBit(oldp+516,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_flush));
        bufp->chgIData(oldp+517,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0)),32);
        bufp->chgBit(oldp+518,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__flush));
        bufp->chgIData(oldp+519,(((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state))
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_target
                                   : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_flush)
                                       ? ((IData)(4U) 
                                          + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0)
                                       : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q 
                                          & (- (IData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_flush_q))))))),32);
        bufp->chgBit(oldp+520,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_taken));
        bufp->chgIData(oldp+521,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_target),32);
        bufp->chgBit(oldp+522,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_lane));
        bufp->chgBit(oldp+523,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_lane)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_taken))));
        bufp->chgBit(oldp+524,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__id_valid));
        bufp->chgIData(oldp+525,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc),32);
        bufp->chgBit(oldp+526,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken));
        bufp->chgIData(oldp+527,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target),32);
        bufp->chgBit(oldp+528,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__icacop_req_valid));
        bufp->chgBit(oldp+529,((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))));
        bufp->chgCData(oldp+530,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_cacop_code_0),5);
        bufp->chgIData(oldp+531,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0),32);
        bufp->chgIData(oldp+532,(((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                      >> 6U) & ((7U 
                                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                                    >> 3U)) 
                                                == 
                                                (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                                 >> 0x0000001dU)))
                                     ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg)
                                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                          >> 0x0000000dU) 
                                         & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                                   >> 0x0000000aU)) 
                                            == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                                >> 0x0000001dU)))
                                         ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                            >> 7U) : 
                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                         >> 0x0000001dU))) 
                                   << 0x0000001dU) 
                                  | (0x1fffffffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0))),32);
        bufp->chgBit(oldp+533,((4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))));
        bufp->chgBit(oldp+534,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_inv_valid));
        bufp->chgIData(oldp+535,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                                  << 4U)),32);
        bufp->chgIData(oldp+536,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out),32);
        bufp->chgIData(oldp+537,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__pc_paddr),32);
        bufp->chgIData(oldp+538,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr),32);
        bufp->chgBit(oldp+539,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__if_valid));
        bufp->chgBit(oldp+540,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pl_suspend));
        bufp->chgBit(oldp+541,((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                             >> 2U)))));
        bufp->chgIData(oldp+542,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                  + ((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                   >> 2U)))
                                      ? 4U : 8U))),32);
        bufp->chgIData(oldp+543,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_taken)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_target
                                   : (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                      + ((3U == (3U 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                    >> 2U)))
                                          ? 4U : 8U)))),32);
        bufp->chgBit(oldp+544,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__got_addr_ok));
        bufp->chgBit(oldp+545,((1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                         >> 0x00000018U)))));
        bufp->chgBit(oldp+546,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__reset));
        Vasm_monitor_tb___024root__trace_chg_dtype____0(vlSelf, bufp, 547, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid);
        Vasm_monitor_tb___024root__trace_chg_dtype____1(vlSelf, bufp, 555, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem);
        Vasm_monitor_tb___024root__trace_chg_dtype____2(vlSelf, bufp, 563, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter);
        Vasm_monitor_tb___024root__trace_chg_dtype____3(vlSelf, bufp, 571, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target);
        bufp->chgIData(oldp+579,((0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                 >> 5U))),18);
        bufp->chgCData(oldp+580,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row),2);
        bufp->chgBit(oldp+581,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                      >> 2U))));
        bufp->chgBit(oldp+582,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U]
                                [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U]
                                   [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                   == (0x0003ffffU 
                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                          >> 5U))))));
        bufp->chgBit(oldp+583,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[1U]
                                [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[1U]
                                   [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                   == (0x0003ffffU 
                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                          >> 5U))))));
        bufp->chgBit(oldp+584,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid[0U]
                                 [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem[0U]
                                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                    == (0x0003ffffU 
                                        & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                           >> 5U)))) 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter[0U]
                                   [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row] 
                                   >> 1U))));
        bufp->chgBit(oldp+585,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_valid_bank1));
        bufp->chgBit(oldp+586,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken));
        bufp->chgBit(oldp+587,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken));
        bufp->chgBit(oldp+588,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane0_taken) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__lane1_taken))));
        bufp->chgBit(oldp+589,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane));
        bufp->chgIData(oldp+590,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__raw_pred_lane)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U]
                                  [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]
                                   : ((4U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out)
                                       ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[1U]
                                      [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]
                                       : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target[0U]
                                      [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__pred_row]))),32);
        bufp->chgIData(oldp+591,((0x0003ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                                 >> 5U))),18);
        bufp->chgBit(oldp+592,((1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                      >> 2U))));
        bufp->chgCData(oldp+593,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1),2);
        bufp->chgBit(oldp+594,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_valid
                               [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                       >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]));
        bufp->chgIData(oldp+595,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_tag_mem
                                 [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                         >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]),18);
        bufp->chgCData(oldp+596,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_counter
                                 [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                         >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]),2);
        bufp->chgIData(oldp+597,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__btb_target
                                 [(1U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__ex_pc 
                                         >> 2U))][vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s1]),32);
        bufp->chgBit(oldp+598,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_valid_s2));
        bufp->chgIData(oldp+599,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_tag_s2),18);
        bufp->chgBit(oldp+600,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_bank_s2));
        bufp->chgCData(oldp+601,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_row_s2),2);
        bufp->chgBit(oldp+602,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2));
        bufp->chgIData(oldp+603,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_target_s2),32);
        bufp->chgBit(oldp+604,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_valid_s2));
        bufp->chgIData(oldp+605,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_tag_s2),18);
        bufp->chgCData(oldp+606,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_counter_s2),2);
        bufp->chgIData(oldp+607,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__read_target_s2),32);
        bufp->chgBit(oldp+608,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__update_hit_s2));
        bufp->chgCData(oldp+609,((3U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__real_taken_s2)
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
        bufp->chgIData(oldp+610,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__i),32);
        bufp->chgIData(oldp+611,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_bpu__DOT__j),32);
        bufp->chgSData(oldp+612,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_reg),9);
        bufp->chgIData(oldp+613,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_reg),32);
        bufp->chgIData(oldp+614,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_reg),32);
        bufp->chgIData(oldp+615,((0x000001ffU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask)),32);
        bufp->chgIData(oldp+616,((0xee000039U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_pending_mask)),32);
        bufp->chgSData(oldp+617,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next),9);
        bufp->chgIData(oldp+618,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next),32);
        bufp->chgIData(oldp+619,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next),32);
        bufp->chgCData(oldp+620,((3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))),2);
        bufp->chgBit(oldp+621,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode));
        bufp->chgBit(oldp+622,(((((0U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next) 
                                 | ((3U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw0_next 
                                       >> 3U))) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode))));
        bufp->chgBit(oldp+623,(((((0U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next) 
                                 | ((3U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                       >> 3U))) & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode))));
        bufp->chgSData(oldp+624,((((((((0U == (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                       & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next) 
                                      | ((3U == (3U 
                                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__crmd_next))) 
                                         & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                            >> 3U))) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__next_mapped_mode)) 
                                    << 0x0000000dU) 
                                   | (((0x00000038U 
                                        & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                           >> 0x0000001aU)) 
                                       | (7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_csr__DOT__dmw1_next 
                                                >> 0x00000019U))) 
                                      << 7U)) | (((
                                                   (((0U 
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
        bufp->chgSData(oldp+625,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg),14);
        bufp->chgBit(oldp+626,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                      >> 0x0000000dU))));
        bufp->chgCData(oldp+627,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                        >> 0x0000000aU))),3);
        bufp->chgCData(oldp+628,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+629,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                      >> 6U))));
        bufp->chgCData(oldp+630,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                        >> 3U))),3);
        bufp->chgCData(oldp+631,((7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg))),3);
        bufp->chgBit(oldp+632,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                 >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                                  >> 3U)) 
                                           == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                               >> 0x0000001dU)))));
        bufp->chgBit(oldp+633,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                 >> 0x0000000dU) & 
                                ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_addr_translate__DOT__ctx_reg) 
                                        >> 0x0000000aU)) 
                                 == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr 
                                     >> 0x0000001dU)))));
        bufp->chgBit(oldp+634,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_valid));
        bufp->chgBit(oldp+635,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_store));
        bufp->chgBit(oldp+636,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_is_base));
        bufp->chgIData(oldp+637,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line),28);
        bufp->chgBit(oldp+638,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__reset));
        bufp->chgBit(oldp+639,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0));
        bufp->chgIData(oldp+640,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0),32);
        bufp->chgSData(oldp+641,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0),12);
        bufp->chgIData(oldp+642,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0),32);
        bufp->chgIData(oldp+643,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0),32);
        bufp->chgIData(oldp+644,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0),32);
        bufp->chgBit(oldp+645,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0));
        bufp->chgCData(oldp+646,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_src_0),5);
        bufp->chgBit(oldp+647,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_0));
        bufp->chgBit(oldp+648,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_0));
        bufp->chgBit(oldp+649,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_0));
        bufp->chgCData(oldp+650,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_0),5);
        bufp->chgBit(oldp+651,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_0));
        bufp->chgCData(oldp+652,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_cnt_0),2);
        bufp->chgBit(oldp+653,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_pending_0));
        bufp->chgIData(oldp+654,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0),32);
        bufp->chgIData(oldp+655,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_1),32);
        bufp->chgBit(oldp+656,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid));
        bufp->chgBit(oldp+657,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_0));
        bufp->chgBit(oldp+658,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_0));
        bufp->chgBit(oldp+659,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_0));
        bufp->chgBit(oldp+660,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_0));
        bufp->chgBit(oldp+661,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_0));
        bufp->chgBit(oldp+662,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0));
        bufp->chgIData(oldp+663,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0),32);
        bufp->chgCData(oldp+664,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0),4);
        bufp->chgIData(oldp+665,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_0),32);
        bufp->chgBit(oldp+666,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cpucfg_0));
        bufp->chgBit(oldp+667,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_cacop_0));
        bufp->chgCData(oldp+668,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_cacop_code_0),5);
        bufp->chgBit(oldp+669,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_csr_0));
        bufp->chgIData(oldp+670,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wmask_0),32);
        bufp->chgIData(oldp+671,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_csr_wvalue_0),32);
        bufp->chgBit(oldp+672,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1));
        bufp->chgIData(oldp+673,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1),32);
        bufp->chgSData(oldp+674,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1),12);
        bufp->chgIData(oldp+675,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1),32);
        bufp->chgIData(oldp+676,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1),32);
        bufp->chgIData(oldp+677,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_1),32);
        bufp->chgBit(oldp+678,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_res_from_mem_1));
        bufp->chgBit(oldp+679,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_gr_we_1));
        bufp->chgBit(oldp+680,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_mem_we_1));
        bufp->chgCData(oldp+681,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_dest_1),5);
        bufp->chgBit(oldp+682,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_is_mul_1));
        bufp->chgBit(oldp+683,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_byte_1));
        bufp->chgBit(oldp+684,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_half_1));
        bufp->chgBit(oldp+685,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_ld_sign_ext_1));
        bufp->chgBit(oldp+686,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_byte_1));
        bufp->chgBit(oldp+687,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_st_half_1));
        bufp->chgBit(oldp+688,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1));
        bufp->chgIData(oldp+689,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1),32);
        bufp->chgCData(oldp+690,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1),4);
        bufp->chgIData(oldp+691,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_offs_1),32);
        bufp->chgIData(oldp+692,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U] 
                                   << 0x0000001fU) 
                                  | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U] 
                                     >> 1U))),32);
        bufp->chgSData(oldp+693,((0x00000fffU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5 
                                                         >> 0x0000001dU)))),12);
        bufp->chgIData(oldp+694,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_0),32);
        bufp->chgIData(oldp+695,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_0),32);
        bufp->chgIData(oldp+696,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_0),32);
        bufp->chgBit(oldp+697,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_late_0));
        bufp->chgBit(oldp+698,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                              >> 5U)))));
        bufp->chgBit(oldp+699,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                              >> 4U)))));
        bufp->chgBit(oldp+700,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                              >> 3U)))));
        bufp->chgCData(oldp+701,((0x0000001fU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                         >> 8U)))),5);
        bufp->chgBit(oldp+702,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                              >> 2U)))));
        bufp->chgBit(oldp+703,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                              >> 1U)))));
        bufp->chgBit(oldp+704,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3))));
        bufp->chgBit(oldp+705,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x0000002cU)))));
        bufp->chgBit(oldp+706,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x0000002bU)))));
        bufp->chgBit(oldp+707,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x0000002aU)))));
        bufp->chgBit(oldp+708,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0 
                                              >> 0x00000020U)))));
        bufp->chgIData(oldp+709,((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0)),32);
        bufp->chgCData(oldp+710,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_0),4);
        bufp->chgIData(oldp+711,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_offs_0),32);
        bufp->chgBit(oldp+712,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x0000001dU)))));
        bufp->chgBit(oldp+713,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x0000001cU)))));
        bufp->chgCData(oldp+714,((0x0000001fU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                         >> 0x00000017U)))),5);
        bufp->chgBit(oldp+715,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x00000016U)))));
        bufp->chgBit(oldp+716,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                              >> 0x00000015U)))));
        bufp->chgSData(oldp+717,((0x00003fffU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                                         >> 7U)))),14);
        bufp->chgBit(oldp+718,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rj_0));
        bufp->chgBit(oldp+719,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_load_wakeup_rkd_0));
        bufp->chgIData(oldp+720,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[3U] 
                                   << 0x0000001fU) 
                                  | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U] 
                                     >> 1U))),32);
        bufp->chgSData(oldp+721,((0x00000fffU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5 
                                                         >> 0x0000001dU)))),12);
        bufp->chgIData(oldp+722,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src1_1),32);
        bufp->chgIData(oldp+723,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_alu_src2_1),32);
        bufp->chgIData(oldp+724,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_rkd_value_1),32);
        bufp->chgBit(oldp+725,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                              >> 5U)))));
        bufp->chgBit(oldp+726,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                              >> 4U)))));
        bufp->chgBit(oldp+727,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                              >> 3U)))));
        bufp->chgCData(oldp+728,((0x0000001fU & (IData)(
                                                        (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                         >> 8U)))),5);
        bufp->chgBit(oldp+729,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                              >> 2U)))));
        bufp->chgBit(oldp+730,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                              >> 1U)))));
        bufp->chgBit(oldp+731,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3))));
        bufp->chgBit(oldp+732,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                              >> 0x0000002cU)))));
        bufp->chgBit(oldp+733,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                              >> 0x0000002bU)))));
        bufp->chgBit(oldp+734,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                              >> 0x0000002aU)))));
        bufp->chgBit(oldp+735,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0 
                                              >> 0x00000020U)))));
        bufp->chgIData(oldp+736,((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0)),32);
        bufp->chgCData(oldp+737,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_br_op_1),4);
        bufp->chgIData(oldp+738,((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4 
                                          >> 0x0000000aU))),32);
        bufp->chgBit(oldp+739,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_packet_ready));
        bufp->chgBit(oldp+740,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_0) 
                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_valid_1))));
        bufp->chgIData(oldp+741,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_0),32);
        bufp->chgIData(oldp+742,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                  + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                       ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                       : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                     + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                              >> 1U))))),32);
        bufp->chgIData(oldp+743,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2),32);
        bufp->chgIData(oldp+744,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_1),32);
        bufp->chgIData(oldp+745,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                  + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))
                                       ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)
                                       : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1) 
                                     + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                              >> 1U))))),32);
        bufp->chgIData(oldp+746,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2),32);
        bufp->chgIData(oldp+747,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_valid)
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__mul_result_hold_0
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p2)),32);
        bufp->chgBit(oldp+748,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 1U))));
        bufp->chgCData(oldp+749,((0x000000ffU & ((2U 
                                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                                  ? 
                                                 (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                                  : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0))),8);
        bufp->chgCData(oldp+750,((0x000000ffU & (((2U 
                                                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                                   ? 
                                                  (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                                 + 
                                                 (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                  + 
                                                  (1U 
                                                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                      >> 1U)))))),8);
        bufp->chgIData(oldp+751,(((0xffffff00U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
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
                                                  >> 1U))))))),32);
        bufp->chgIData(oldp+752,(((0U != (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0)))
                                   ? ((0xffffff00U 
                                       & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                          + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                               ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                               : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                             + (1U 
                                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                   >> 1U))))) 
                                      | (0x000000ffU 
                                         & (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                              ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                              : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0) 
                                            + (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                               + (1U 
                                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                     >> 1U))))))
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_0)),32);
        bufp->chgIData(oldp+753,(((0U != (3U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1)))
                                   ? (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                      + (((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))
                                           ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)
                                           : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1) 
                                         + (1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                  >> 1U))))
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__alu_result_1)),32);
        bufp->chgIData(oldp+754,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0),32);
        bufp->chgIData(oldp+755,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1),32);
        bufp->chgIData(oldp+756,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0),32);
        bufp->chgBit(oldp+757,((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_49)))));
        bufp->chgBit(oldp+758,((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))));
        bufp->chgBit(oldp+759,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0));
        bufp->chgIData(oldp+760,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0),32);
        bufp->chgIData(oldp+761,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)),32);
        bufp->chgBit(oldp+762,((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))));
        bufp->chgBit(oldp+763,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1));
        bufp->chgIData(oldp+764,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1),32);
        bufp->chgIData(oldp+765,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_1)),32);
        bufp->chgBit(oldp+766,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                                ^ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0))));
        bufp->chgBit(oldp+767,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_0) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_0) 
                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_0 
                                      != vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_0)))));
        bufp->chgBit(oldp+768,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0));
        bufp->chgBit(oldp+769,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1) 
                                ^ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1))));
        bufp->chgBit(oldp+770,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_taken_1) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_taken_1) 
                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pred_target_1 
                                      != vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_real_target_1)))));
        bufp->chgBit(oldp+771,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_1));
        bufp->chgBit(oldp+772,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_0));
        bufp->chgBit(oldp+773,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_fwd_valid_1));
        bufp->chgBit(oldp+774,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))));
        bufp->chgBit(oldp+775,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 2U))));
        bufp->chgBit(oldp+776,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 3U))));
        bufp->chgBit(oldp+777,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 4U))));
        bufp->chgBit(oldp+778,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 5U))));
        bufp->chgBit(oldp+779,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 6U))));
        bufp->chgBit(oldp+780,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 7U))));
        bufp->chgBit(oldp+781,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 8U))));
        bufp->chgBit(oldp+782,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 9U))));
        bufp->chgBit(oldp+783,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+784,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                      >> 0x0000000bU))));
        bufp->chgIData(oldp+785,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
        bufp->chgIData(oldp+786,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                  < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
        bufp->chgIData(oldp+787,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
        bufp->chgIData(oldp+788,((~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result)),32);
        bufp->chgIData(oldp+789,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__or_result),32);
        bufp->chgIData(oldp+790,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                  ^ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
        bufp->chgIData(oldp+791,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                  << (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0))),32);
        bufp->chgQData(oldp+792,(((((QData)((IData)(
                                                    (- (IData)((IData)(
                                                                       (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                                         >> 0x0000000aU) 
                                                                        & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                                           >> 0x0000001fU))))))) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0))) 
                                  >> (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0))),64);
        bufp->chgIData(oldp+794,((IData)(((((QData)((IData)(
                                                            (- (IData)((IData)(
                                                                               (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0) 
                                                                                >> 0x0000000aU) 
                                                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                                                                >> 0x0000001fU))))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0))) 
                                          >> (0x0000001fU 
                                              & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)))),32);
        bufp->chgIData(oldp+795,(((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_0))
                                   ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)),32);
        bufp->chgBit(oldp+796,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)));
        bufp->chgBit(oldp+797,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_0 
                                < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_0)));
        bufp->chgIData(oldp+798,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0),32);
        bufp->chgIData(oldp+799,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_0__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1),32);
        bufp->chgBit(oldp+800,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))));
        bufp->chgBit(oldp+801,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 1U))));
        bufp->chgBit(oldp+802,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 2U))));
        bufp->chgBit(oldp+803,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 3U))));
        bufp->chgBit(oldp+804,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 4U))));
        bufp->chgBit(oldp+805,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 5U))));
        bufp->chgBit(oldp+806,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 6U))));
        bufp->chgBit(oldp+807,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 7U))));
        bufp->chgBit(oldp+808,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 8U))));
        bufp->chgBit(oldp+809,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 9U))));
        bufp->chgBit(oldp+810,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+811,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                      >> 0x0000000bU))));
        bufp->chgIData(oldp+812,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
        bufp->chgIData(oldp+813,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                  < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
        bufp->chgIData(oldp+814,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
        bufp->chgIData(oldp+815,((~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result)),32);
        bufp->chgIData(oldp+816,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__or_result),32);
        bufp->chgIData(oldp+817,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                  ^ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
        bufp->chgIData(oldp+818,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                  << (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1))),32);
        bufp->chgQData(oldp+819,(((((QData)((IData)(
                                                    (- (IData)((IData)(
                                                                       (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                         >> 0x0000000aU) 
                                                                        & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                                           >> 0x0000001fU))))))) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1))) 
                                  >> (0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1))),64);
        bufp->chgIData(oldp+821,((IData)(((((QData)((IData)(
                                                            (- (IData)((IData)(
                                                                               (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1) 
                                                                                >> 0x0000000aU) 
                                                                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                                                                >> 0x0000001fU))))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1))) 
                                          >> (0x0000001fU 
                                              & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)))),32);
        bufp->chgIData(oldp+822,(((2U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_op_1))
                                   ? (~ vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)),32);
        bufp->chgBit(oldp+823,(VL_LTS_III(32, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)));
        bufp->chgBit(oldp+824,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src1_1 
                                < vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_alu_src2_1)));
        bufp->chgIData(oldp+825,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p0),32);
        bufp->chgIData(oldp+826,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_alu_1__DOT__gen_multiplier__DOT__u_mult_gen_0__DOT__p1),32);
        bufp->chgBit(oldp+827,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd));
        bufp->chgBit(oldp+828,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed));
        bufp->chgBit(oldp+829,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned));
        bufp->chgIData(oldp+830,(((7U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))
                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_rkd_value_0
                                   : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_pc_0)),32);
        bufp->chgBit(oldp+831,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd) 
                                 & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_eq_rkd)) 
                                    & (2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                   | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed) 
                                       & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                      | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_signed)) 
                                          & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                         | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned) 
                                             & (5U 
                                                == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0))) 
                                            | ((9U 
                                                == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)) 
                                               | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_0__DOT__rj_lt_rkd_unsigned)) 
                                                  & (6U 
                                                     == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_0)))))))))));
        bufp->chgBit(oldp+832,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd));
        bufp->chgBit(oldp+833,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed));
        bufp->chgBit(oldp+834,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned));
        bufp->chgBit(oldp+835,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd) 
                                 & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_eq_rkd)) 
                                    & (2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                   | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed) 
                                       & (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                      | (((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_signed)) 
                                          & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                         | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned) 
                                             & (5U 
                                                == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1))) 
                                            | ((9U 
                                                == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)) 
                                               | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__u_branch_judge_1__DOT__rj_lt_rkd_unsigned)) 
                                                  & (6U 
                                                     == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_br_op_1)))))))))));
        bufp->chgCData(oldp+836,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state),2);
        bufp->chgIData(oldp+837,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_base_addr),32);
        bufp->chgCData(oldp+838,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat),2);
        bufp->chgBit(oldp+839,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                                & (1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))));
        bufp->chgBit(oldp+840,(((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_addr_ok))));
        bufp->chgBit(oldp+841,(((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                                & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__inst_sram_data_ok))));
        bufp->chgBit(oldp+842,((3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_beat))));
        bufp->chgSData(oldp+843,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg),14);
        bufp->chgBit(oldp+844,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                      >> 0x0000000dU))));
        bufp->chgCData(oldp+845,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                        >> 0x0000000aU))),3);
        bufp->chgCData(oldp+846,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                        >> 7U))),3);
        bufp->chgBit(oldp+847,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                      >> 6U))));
        bufp->chgCData(oldp+848,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                        >> 3U))),3);
        bufp->chgCData(oldp+849,((7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg))),3);
        bufp->chgBit(oldp+850,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                 >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                                  >> 3U)) 
                                           == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                               >> 0x0000001dU)))));
        bufp->chgBit(oldp+851,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                 >> 0x0000000dU) & 
                                ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icacop_addr_translate__DOT__ctx_reg) 
                                        >> 0x0000000aU)) 
                                 == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_0 
                                     >> 0x0000001dU)))));
        bufp->chgBit(oldp+852,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__reset));
        bufp->chgCData(oldp+853,((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                        >> 4U))),3);
        bufp->chgIData(oldp+854,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__pc_paddr 
                                  >> 7U)),25);
        bufp->chgCData(oldp+855,((3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                        >> 2U))),2);
        bufp->chgBit(oldp+856,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid));
        bufp->chgIData(oldp+857,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_vaddr),32);
        bufp->chgIData(oldp+858,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr),32);
        bufp->chgBit(oldp+859,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_0));
        bufp->chgIData(oldp+860,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_0),32);
        bufp->chgBit(oldp+861,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_taken_1));
        bufp->chgIData(oldp+862,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_pred_target_1),32);
        bufp->chgCData(oldp+863,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index),3);
        bufp->chgIData(oldp+864,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag),25);
        bufp->chgCData(oldp+865,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_offset_word),2);
        Vasm_monitor_tb___024root__trace_chg_dtype____4(vlSelf, bufp, 866, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid);
        Vasm_monitor_tb___024root__trace_chg_dtype____5(vlSelf, bufp, 882, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0);
        Vasm_monitor_tb___024root__trace_chg_dtype____6(vlSelf, bufp, 890, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1);
        Vasm_monitor_tb___024root__trace_chg_dtype____7(vlSelf, bufp, 898, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way0);
        Vasm_monitor_tb___024root__trace_chg_dtype____8(vlSelf, bufp, 930, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_data_way1);
        bufp->chgBit(oldp+962,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                                [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                                   [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_index] 
                                   == vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag))));
        bufp->chgBit(oldp+963,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_tag_match_way1));
        bufp->chgBit(oldp+964,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
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
        bufp->chgWData(oldp+965,(__Vtemp_29),128);
        bufp->chgCData(oldp+969,((7U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line)),3);
        bufp->chgIData(oldp+970,((0x01ffffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                                                 >> 3U))),25);
        bufp->chgBit(oldp+971,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_inv_valid) 
                                & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_valid) 
                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_data_txn_tracker__DOT__data_txn_line 
                                      == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s1_paddr 
                                          >> 4U))))));
        bufp->chgBit(oldp+972,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid));
        bufp->chgBit(oldp+973,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit));
        bufp->chgBit(oldp+974,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit_way));
        bufp->chgWData(oldp+975,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_line_data),128);
        bufp->chgIData(oldp+979,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr),32);
        bufp->chgIData(oldp+980,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr),32);
        bufp->chgBit(oldp+981,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0));
        bufp->chgIData(oldp+982,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_0),32);
        bufp->chgBit(oldp+983,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_1));
        bufp->chgIData(oldp+984,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_target_1),32);
        bufp->chgCData(oldp+985,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word),2);
        bufp->chgCData(oldp+986,((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                                        >> 4U))),3);
        bufp->chgIData(oldp+987,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_paddr 
                                  >> 7U)),25);
        bufp->chgCData(oldp+988,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state),3);
        bufp->chgCData(oldp+989,(Vasm_monitor_tb__ConstPool__TABLE_he47f3c48_0
                                 [(((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
                                        & ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
                                           & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)) 
                                              | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2)))) 
                                       << 5U) | ((0U 
                                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__ic_refill_state)) 
                                                 << 4U)) 
                                     | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_last_r) 
                                         << 2U) | (
                                                   ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_icache_refill__DOT__icache_ret_valid_r) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)))) 
                                    << 5U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold) 
                                               << 4U) 
                                              | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2) 
                                                  << 3U) 
                                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state))))]),3);
        bufp->chgWData(oldp+990,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_data_reg),128);
        bufp->chgWData(oldp+994,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_line),128);
        bufp->chgCData(oldp+998,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_beat),2);
        bufp->chgBit(oldp+999,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_poisoned));
        bufp->chgCData(oldp+1000,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr),8);
        bufp->chgCData(oldp+1001,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state),3);
        bufp->chgCData(oldp+1002,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code),5);
        bufp->chgIData(oldp+1003,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr),32);
        bufp->chgBit(oldp+1004,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way0));
        bufp->chgBit(oldp+1005,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_clear_way1));
        bufp->chgBit(oldp+1006,((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state))));
        bufp->chgWData(oldp+1007,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line),128);
        bufp->chgIData(oldp+1011,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U]
                                    : ((1U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U]
                                        : ((2U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))
                                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U]
                                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U])))),32);
        bufp->chgIData(oldp+1012,(((0U == (3U & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[0U]
                                    : ((1U == (3U & 
                                               ((IData)(1U) 
                                                + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[1U]
                                        : ((2U == (3U 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word))))
                                            ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[2U]
                                            : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_effective_line[3U])))),32);
        bufp->chgIData(oldp+1013,(((IData)(4U) + vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_vaddr)),32);
        bufp->chgBit(oldp+1014,((1U & (~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_pred_taken_0) 
                                          | (3U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_offset_word)))))));
        bufp->chgIData(oldp+1015,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0),32);
        bufp->chgIData(oldp+1016,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1),32);
        bufp->chgIData(oldp+1017,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0),32);
        bufp->chgIData(oldp+1018,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1),32);
        bufp->chgBit(oldp+1019,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0));
        bufp->chgIData(oldp+1020,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0),32);
        bufp->chgBit(oldp+1021,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1));
        bufp->chgIData(oldp+1022,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1),32);
        bufp->chgBit(oldp+1023,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way));
        bufp->chgBit(oldp+1024,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2));
        bufp->chgBit(oldp+1025,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now));
        bufp->chgBit(oldp+1026,(((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
                                 & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2)) 
                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)))));
        bufp->chgBit(oldp+1027,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_retry_now)) 
                                 & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)))));
        bufp->chgBit(oldp+1028,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready));
        bufp->chgBit(oldp+1029,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_hold));
        bufp->chgBit(oldp+1030,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_data_ready)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid))));
        bufp->chgBit(oldp+1031,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_stall));
        bufp->chgBit(oldp+1032,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_valid) 
                                 & ((0U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__state)) 
                                    & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s2_hit)) 
                                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__store_conflict_s2))))));
        bufp->chgBit(oldp+1033,((1U & VL_REDXOR_8((0xb8U 
                                                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__lfsr))))));
        bufp->chgBit(oldp+1034,((0U == (7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_code)))));
        bufp->chgBit(oldp+1035,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_direct));
        bufp->chgBit(oldp+1036,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_hit));
        bufp->chgBit(oldp+1037,((1U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr)));
        bufp->chgCData(oldp+1038,((7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                         >> 4U))),3);
        bufp->chgIData(oldp+1039,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                   >> 7U)),25);
        bufp->chgBit(oldp+1040,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint));
        bufp->chgBit(oldp+1041,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[0U]
                                  [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                          >> 4U))] 
                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way0
                                     [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                             >> 4U))] 
                                     == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                         >> 7U))) | 
                                 ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint) 
                                  & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way))))));
        bufp->chgBit(oldp+1042,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_valid[1U]
                                  [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                          >> 4U))] 
                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__cache_tag_way1
                                     [(7U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                             >> 4U))] 
                                     == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_addr 
                                         >> 7U))) | 
                                 ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__refill_hits_maint) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__miss_replace_way)))));
        bufp->chgIData(oldp+1043,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__i),32);
        bufp->chgIData(oldp+1044,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__j),32);
        bufp->chgSData(oldp+1045,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg),14);
        bufp->chgBit(oldp+1046,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                       >> 0x0000000dU))));
        bufp->chgCData(oldp+1047,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                         >> 0x0000000aU))),3);
        bufp->chgCData(oldp+1048,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                         >> 7U))),3);
        bufp->chgBit(oldp+1049,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                       >> 6U))));
        bufp->chgCData(oldp+1050,((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                         >> 3U))),3);
        bufp->chgCData(oldp+1051,((7U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg))),3);
        bufp->chgBit(oldp+1052,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                  >> 6U) & ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                                   >> 3U)) 
                                            == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                                >> 0x0000001dU)))));
        bufp->chgBit(oldp+1053,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                  >> 0x0000000dU) & 
                                 ((7U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_addr_translate__DOT__ctx_reg) 
                                         >> 0x0000000aU)) 
                                  == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__pc_out 
                                      >> 0x0000001dU)))));
        bufp->chgCData(oldp+1054,((3U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))),2);
        bufp->chgCData(oldp+1055,((3U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail)))),2);
        Vasm_monitor_tb___024root__trace_chg_dtype____9(vlSelf, bufp, 1056, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo);
        bufp->chgCData(oldp+1092,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head),2);
        bufp->chgCData(oldp+1093,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__tail),2);
        bufp->chgCData(oldp+1094,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__cnt),3);
        bufp->chgWData(oldp+1095,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                  [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head]),266);
        bufp->chgWData(oldp+1104,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                  [(3U & ((IData)(1U) 
                                          + (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head)))]),266);
        bufp->chgQData(oldp+1113,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g0),45);
        bufp->chgQData(oldp+1115,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g1),45);
        bufp->chgQData(oldp+1117,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2),45);
        bufp->chgQData(oldp+1119,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3),45);
        bufp->chgQData(oldp+1121,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4),45);
        bufp->chgQData(oldp+1123,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g5),41);
        bufp->chgQData(oldp+1125,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g0),45);
        bufp->chgQData(oldp+1127,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g1),45);
        bufp->chgQData(oldp+1129,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2),45);
        bufp->chgQData(oldp+1131,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3),45);
        bufp->chgQData(oldp+1133,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g4),45);
        bufp->chgQData(oldp+1135,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g5),41);
        bufp->chgCData(oldp+1137,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__4__03a2__KET__) 
                                    << 2U) | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_r__BRA__1__03a0__KET__))),5);
        bufp->chgBit(oldp+1138,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit1_r));
        bufp->chgBit(oldp+1139,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr2_0_hot_bit0_r));
        bufp->chgBit(oldp+1140,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_1_hot_bit0_r));
        bufp->chgBit(oldp+1141,(Vasm_monitor_tb__ConstPool__TABLE_h2c364be9_0
                                [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_50]));
        bufp->chgBit(oldp+1142,(Vasm_monitor_tb__ConstPool__TABLE_h547ba932_0
                                [vlSelfRef.__VdfgRegularize_h6e95ff9d_0_50]));
        bufp->chgCData(oldp+1143,(Vasm_monitor_tb__ConstPool__TABLE_h3486ca0a_0
                                  [(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_0_r) 
                                     << 6U) | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_valid_1_r) 
                                                << 5U) 
                                               | (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17)))]),2);
        bufp->chgBit(oldp+1144,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_we_g0_a));
        bufp->chgBit(oldp+1145,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front1_load_fifo1_g0));
        bufp->chgQData(oldp+1146,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g0),45);
        bufp->chgQData(oldp+1148,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g1),45);
        bufp->chgQData(oldp+1150,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g2),45);
        bufp->chgQData(oldp+1152,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g3),45);
        bufp->chgQData(oldp+1154,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g4),45);
        bufp->chgQData(oldp+1156,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__next_front_bus_1_g5),41);
        bufp->chgBit(oldp+1158,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_we_g0));
        bufp->chgWData(oldp+1159,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_bus_next),266);
        bufp->chgCData(oldp+1168,((0x0000001fU & ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_9)
                                                   ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)
                                                   : 
                                                  ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                    [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                                                    << 7U) 
                                                   | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__fifo
                                                      [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__head][4U] 
                                                      >> 0x00000019U))))),5);
        bufp->chgCData(oldp+1169,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front0_hot_raddr2_next),5);
        bufp->chgBit(oldp+1170,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_0));
        bufp->chgBit(oldp+1171,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_fire_1));
        bufp->chgCData(oldp+1172,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__push_count),2);
        bufp->chgWData(oldp+1173,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_0),169);
        bufp->chgWData(oldp+1179,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__dec_bus_1),169);
        __Vtemp_31[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))));
        __Vtemp_31[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                           << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_0)) 
                                               << 0x00000020U) 
                                              | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_0))) 
                                             >> 0x00000020U)));
        __Vtemp_31[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)))) 
                           >> 0x0000001fU) | ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_0)) 
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
        bufp->chgWData(oldp+1185,(__Vtemp_31),266);
        __Vtemp_33[0U] = (IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))));
        __Vtemp_33[1U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                           << 1U) | (IData)(((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_taken_1)) 
                                               << 0x00000020U) 
                                              | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pred_target_1))) 
                                             >> 0x00000020U)));
        __Vtemp_33[2U] = (((IData)((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
                                     << 0x00000020U) 
                                    | (QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)))) 
                           >> 0x0000001fU) | ((IData)(
                                                      ((((QData)((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_pc_1)) 
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
        bufp->chgWData(oldp+1194,(__Vtemp_33),266);
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
        bufp->chgWData(oldp+1203,(__Vtemp_36),169);
        __Vtemp_39[0U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[0U];
        __Vtemp_39[1U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[1U];
        __Vtemp_39[2U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U];
        __Vtemp_39[3U] = (1U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[3U]);
        bufp->chgWData(oldp+1209,(__Vtemp_39),97);
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
        bufp->chgWData(oldp+1213,(__Vtemp_42),169);
        __Vtemp_45[0U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[0U];
        __Vtemp_45[1U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[1U];
        __Vtemp_45[2U] = vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U];
        __Vtemp_45[3U] = (1U & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[3U]);
        bufp->chgWData(oldp+1219,(__Vtemp_45),97);
        bufp->chgIData(oldp+1223,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[2U] 
                                    << 0x0000001fU) 
                                   | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[1U] 
                                      >> 1U))),32);
        bufp->chgIData(oldp+1224,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[2U] 
                                    << 0x0000001fU) 
                                   | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[1U] 
                                      >> 1U))),32);
        bufp->chgIData(oldp+1225,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[7U] 
                                    << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[6U] 
                                              >> 0x0000001eU))),32);
        bufp->chgIData(oldp+1226,((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g4 
                                           >> 0x0000000aU))),32);
        bufp->chgIData(oldp+1227,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[5U] 
                                    << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_0[4U] 
                                              >> 0x0000001eU))),32);
        bufp->chgCData(oldp+1228,((0x0000001fU & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                          >> 0x00000012U)))),5);
        bufp->chgCData(oldp+1229,((0x0000001fU & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                          >> 0x0000000dU)))),5);
        bufp->chgBit(oldp+1230,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                               >> 7U)))));
        bufp->chgBit(oldp+1231,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                               >> 6U)))));
        bufp->chgBit(oldp+1232,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000029U)))));
        bufp->chgBit(oldp+1233,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000028U)))));
        bufp->chgBit(oldp+1234,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000027U)))));
        bufp->chgBit(oldp+1235,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000026U)))));
        bufp->chgBit(oldp+1236,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000025U)))));
        bufp->chgBit(oldp+1237,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000024U)))));
        bufp->chgBit(oldp+1238,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000023U)))));
        bufp->chgBit(oldp+1239,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000022U)))));
        bufp->chgBit(oldp+1240,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000021U)))));
        bufp->chgBit(oldp+1241,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x00000020U)))));
        bufp->chgBit(oldp+1242,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x0000001fU)))));
        bufp->chgBit(oldp+1243,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g2 
                                               >> 0x0000001eU)))));
        bufp->chgIData(oldp+1244,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[7U] 
                                    << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[6U] 
                                              >> 0x0000001eU))),32);
        bufp->chgIData(oldp+1245,(((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[5U] 
                                    << 2U) | (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_bus_1[4U] 
                                              >> 0x0000001eU))),32);
        bufp->chgCData(oldp+1246,((0x0000001fU & (IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                          >> 0x00000012U)))),5);
        bufp->chgBit(oldp+1247,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                               >> 7U)))));
        bufp->chgBit(oldp+1248,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                               >> 6U)))));
        bufp->chgBit(oldp+1249,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000029U)))));
        bufp->chgBit(oldp+1250,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000028U)))));
        bufp->chgBit(oldp+1251,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000027U)))));
        bufp->chgBit(oldp+1252,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000026U)))));
        bufp->chgBit(oldp+1253,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000025U)))));
        bufp->chgBit(oldp+1254,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000024U)))));
        bufp->chgBit(oldp+1255,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000023U)))));
        bufp->chgBit(oldp+1256,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000022U)))));
        bufp->chgBit(oldp+1257,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000021U)))));
        bufp->chgBit(oldp+1258,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000020U)))));
        bufp->chgBit(oldp+1259,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x0000001fU)))));
        bufp->chgBit(oldp+1260,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x0000001eU)))));
        bufp->chgBit(oldp+1261,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x0000001dU)))));
        bufp->chgBit(oldp+1262,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x0000001cU)))));
        bufp->chgBit(oldp+1263,((1U & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                               >> 0x00000016U)))));
        bufp->chgBit(oldp+1264,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_0));
        bufp->chgCData(oldp+1265,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0),5);
        bufp->chgCData(oldp+1266,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume),5);
        bufp->chgBit(oldp+1267,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_valid_1));
        bufp->chgCData(oldp+1268,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_1),5);
        bufp->chgBit(oldp+1269,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0));
        bufp->chgBit(oldp+1270,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0));
        bufp->chgBit(oldp+1271,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0));
        bufp->chgBit(oldp+1272,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume));
        bufp->chgBit(oldp+1273,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume));
        bufp->chgBit(oldp+1274,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0_consume));
        bufp->chgBit(oldp+1275,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_res_from_mem_0));
        bufp->chgCData(oldp+1276,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0),5);
        bufp->chgCData(oldp+1277,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume),5);
        bufp->chgBit(oldp+1278,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_1));
        bufp->chgBit(oldp+1279,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_1));
        bufp->chgBit(oldp+1280,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1));
        bufp->chgCData(oldp+1281,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1),5);
        bufp->chgCData(oldp+1282,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_1_consume),5);
        bufp->chgBit(oldp+1283,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0));
        bufp->chgBit(oldp+1284,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_0));
        bufp->chgBit(oldp+1285,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_valid_0));
        bufp->chgBit(oldp+1286,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0));
        bufp->chgCData(oldp+1287,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0),5);
        bufp->chgIData(oldp+1288,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_0),32);
        bufp->chgBit(oldp+1289,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1));
        bufp->chgBit(oldp+1290,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_gr_we_1));
        bufp->chgBit(oldp+1291,((1U & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)))));
        bufp->chgCData(oldp+1292,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1),5);
        bufp->chgIData(oldp+1293,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_data_1),32);
        bufp->chgBit(oldp+1294,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_valid_0));
        bufp->chgCData(oldp+1295,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ex_wait_dest_0),5);
        bufp->chgBit(oldp+1296,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0));
        bufp->chgCData(oldp+1297,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0),5);
        bufp->chgIData(oldp+1298,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0),32);
        bufp->chgBit(oldp+1299,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1));
        bufp->chgCData(oldp+1300,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1),5);
        bufp->chgIData(oldp+1301,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1),32);
        bufp->chgIData(oldp+1302,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                      == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1)) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0)) 
                                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                                        [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r])) 
                                   & (- (IData)((0U 
                                                 != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r)))))),32);
        bufp->chgIData(oldp+1303,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                                      == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)) 
                                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                                        [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0])) 
                                   & (- (IData)((0U 
                                                 != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0)))))),32);
        bufp->chgIData(oldp+1304,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                                      == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                     & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_1))
                                     ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_1
                                     : ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_0) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_we_0))
                                         ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ws_rf_wdata_0
                                         : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf
                                        [vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot])) 
                                   & (- (IData)((0U 
                                                 != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)))))),32);
        bufp->chgIData(oldp+1305,((((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_dest_1) 
                                      == (0x0000001fU 
                                          & (IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
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
                                          & (IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                     >> 0x0000000dU)))])) 
                                   & (- (IData)((0U 
                                                 != 
                                                 (0x0000001fU 
                                                  & (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                             >> 0x0000000dU)))))))),32);
        bufp->chgBit(oldp+1306,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid));
        bufp->chgBit(oldp+1307,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid));
        bufp->chgBit(oldp+1308,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid));
        bufp->chgBit(oldp+1309,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid));
        bufp->chgBit(oldp+1310,((1U & ((~ (((IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
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
        bufp->chgBit(oldp+1311,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0));
        bufp->chgBit(oldp+1312,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0));
        bufp->chgBit(oldp+1313,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1));
        bufp->chgBit(oldp+1314,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms0));
        bufp->chgBit(oldp+1315,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_ms1));
        bufp->chgBit(oldp+1316,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1))));
        bufp->chgBit(oldp+1317,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1));
        bufp->chgBit(oldp+1318,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_46) 
                                 & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0))))));
        bufp->chgBit(oldp+1319,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex));
        bufp->chgBit(oldp+1320,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1)) 
                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                                    | (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_46) 
                                        & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                           & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                              == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0)))) 
                                       | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms1))))));
        bufp->chgIData(oldp+1321,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj_value_0),32);
        bufp->chgBit(oldp+1322,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0));
        bufp->chgBit(oldp+1323,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1));
        bufp->chgBit(oldp+1324,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms0));
        bufp->chgBit(oldp+1325,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_ms1));
        bufp->chgBit(oldp+1326,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ex));
        bufp->chgBit(oldp+1327,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1))));
        bufp->chgBit(oldp+1328,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1));
        bufp->chgBit(oldp+1329,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0));
        bufp->chgBit(oldp+1330,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait))));
        bufp->chgIData(oldp+1331,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd_value_0),32);
        bufp->chgBit(oldp+1332,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0));
        bufp->chgBit(oldp+1333,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1));
        bufp->chgBit(oldp+1334,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                  & (0x0000018000000000ULL 
                                     == (0x0000018000000000ULL 
                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_0))) 
                                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))));
        bufp->chgBit(oldp+1335,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                  & (0x000000c000000000ULL 
                                     == (0x000000c000000000ULL 
                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_1))) 
                                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))));
        bufp->chgBit(oldp+1336,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))));
        bufp->chgBit(oldp+1337,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1));
        bufp->chgBit(oldp+1338,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_42))));
        bufp->chgBit(oldp+1339,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                   & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1)) 
                                  | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19) 
                                     | ((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                          == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                         & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_42)) 
                                        | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms1)))) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid))));
        bufp->chgIData(oldp+1340,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))
                                    ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1
                                    : (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                        & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0))
                                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_0
                                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_mul_src1_1))),32);
        bufp->chgBit(oldp+1341,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0));
        bufp->chgBit(oldp+1342,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1));
        bufp->chgBit(oldp+1343,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                  & (0x0000018000000000ULL 
                                     == (0x0000018000000000ULL 
                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_0))) 
                                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0)) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_0) 
                                       == (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                      >> 0x0000000dU))))))));
        bufp->chgBit(oldp+1344,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                  & (0x000000c000000000ULL 
                                     == (0x000000c000000000ULL 
                                         & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_fwd_bus_1))) 
                                 & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1)) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_dest_1) 
                                       == (0x0000001fU 
                                           & (IData)(
                                                     (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                      >> 0x0000000dU))))))));
        bufp->chgBit(oldp+1345,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1))));
        bufp->chgBit(oldp+1346,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms1));
        bufp->chgBit(oldp+1347,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0) 
                                  == (0x0000001fU & (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                             >> 0x0000000dU)))) 
                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40))));
        bufp->chgBit(oldp+1348,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
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
        bufp->chgBit(oldp+1349,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait));
        bufp->chgBit(oldp+1350,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok));
        bufp->chgBit(oldp+1351,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait));
        bufp->chgBit(oldp+1352,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1))) 
                                  | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                     & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es0) 
                                        | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es0)))) 
                                 & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                            >> 2U)))));
        bufp->chgBit(oldp+1353,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
                                   & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1) 
                                      | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1))) 
                                  | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_0) 
                                     & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es0) 
                                        | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es0)))) 
                                 & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                            >> 2U)))));
        bufp->chgBit(oldp+1354,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
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
                                          & (IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                     >> 2U))))))));
        bufp->chgBit(oldp+1355,((((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
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
        bufp->chgBit(oldp+1356,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__raw_0_to_1));
        bufp->chgBit(oldp+1357,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume));
        bufp->chgBit(oldp+1358,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume));
        bufp->chgBit(oldp+1359,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume));
        bufp->chgBit(oldp+1360,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume));
        bufp->chgBit(oldp+1361,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rj_valid) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                       & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                             == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume))))))));
        bufp->chgBit(oldp+1362,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src0_rkd_valid) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                       & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                             == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__ds_store_data_src_0))))))));
        bufp->chgBit(oldp+1363,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                       & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                             == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot))))))));
        bufp->chgBit(oldp+1364,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_valid_0_consume) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_gr_we_0_consume) 
                                       & ((0U != (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume)) 
                                          & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_dest_0_consume) 
                                             == (0x0000001fU 
                                                 & (IData)(
                                                           (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                            >> 0x0000000dU))))))))));
        bufp->chgBit(oldp+1365,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume))));
        bufp->chgBit(oldp+1366,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hit_es1_for_consume))));
        bufp->chgBit(oldp+1367,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume))));
        bufp->chgBit(oldp+1368,(((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume))));
        bufp->chgBit(oldp+1369,(((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_46) 
                                 & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__load_wakeup_usable_0)) 
                                    & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_raddr1_0_hot_r) 
                                       == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume))))));
        bufp->chgBit(oldp+1370,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume));
        bufp->chgBit(oldp+1371,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
                                  == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__front_raddr1_1_hot)) 
                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_42))));
        bufp->chgBit(oldp+1372,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__ms_wait_dest_0_consume) 
                                  == (0x0000001fU & (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                             >> 0x0000000dU)))) 
                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40))));
        bufp->chgBit(oldp+1373,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume));
        bufp->chgBit(oldp+1374,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1))));
        bufp->chgBit(oldp+1375,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume));
        bufp->chgBit(oldp+1376,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume));
        bufp->chgBit(oldp+1377,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_hit_es1_for_consume)) 
                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ex) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume)))));
        bufp->chgBit(oldp+1378,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume))));
        bufp->chgBit(oldp+1379,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19))));
        bufp->chgBit(oldp+1380,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_hit_es1_for_consume)) 
                                 | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rj_valid) 
                                     & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_19)) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume)))));
        bufp->chgBit(oldp+1381,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20))));
        bufp->chgBit(oldp+1382,((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
                                  & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_hit_es1_for_consume)) 
                                 | (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__src1_rkd_valid) 
                                     & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_20)) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume)))));
        bufp->chgBit(oldp+1383,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume));
        bufp->chgBit(oldp+1384,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume));
        bufp->chgBit(oldp+1385,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume));
        bufp->chgBit(oldp+1386,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume) 
                                 & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume)) 
                                    & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume)))));
        bufp->chgBit(oldp+1387,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
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
        bufp->chgBit(oldp+1388,(((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1) 
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
        bufp->chgBit(oldp+1389,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
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
                                          & (IData)(
                                                    (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                     >> 2U))))))));
        bufp->chgBit(oldp+1390,(((((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__es_fwd_valid_1)) 
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
        bufp->chgBit(oldp+1391,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume) 
                                 | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1)))));
        bufp->chgBit(oldp+1392,((((~ ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_wait_for_consume) 
                                      & ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_hard_wait_for_consume)) 
                                         & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_late_ok_for_consume)))) 
                                  & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms0_for_consume) 
                                     | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd0_wait_ms1))) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj0_wait_ms_for_consume))));
        bufp->chgBit(oldp+1393,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rj1_wait_ms_for_consume) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__rkd1_wait_ms_for_consume))));
        bufp->chgBit(oldp+1394,((IData)((0ULL != (0x0000000000000028ULL 
                                                  & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3)))));
        bufp->chgBit(oldp+1395,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1));
        bufp->chgBit(oldp+1396,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_0));
        bufp->chgBit(oldp+1397,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1));
        bufp->chgBit(oldp+1398,((1U & ((~ ((IData)(
                                                   (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                    >> 0x00000027U)) 
                                           | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__mem_op_1) 
                                              | ((IData)(
                                                         (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                          >> 2U)) 
                                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__special_1))))) 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                  >> 4U))))));
        bufp->chgBit(oldp+1399,((1U & ((~ (0U != (3U 
                                                  & (IData)(
                                                            (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                             >> 0x0000001fU))))) 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g2 
                                                  >> 0x00000027U))))));
        bufp->chgBit(oldp+1400,((1U & ((IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_0_g3 
                                                >> 2U)) 
                                       & (IData)((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__front_bus_1_g3 
                                                  >> 2U))))));
        bufp->chgBit(oldp+1401,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__lane1_capable));
        bufp->chgBit(oldp+1402,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__capture_ex_wait_0));
        Vasm_monitor_tb___024root__trace_chg_dtype____10(vlSelf, bufp, 1403, vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_issue__DOT__u_regfile__DOT__rf);
        bufp->chgBit(oldp+1435,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__reset));
        bufp->chgCData(oldp+1436,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind),2);
        bufp->chgBit(oldp+1437,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_result_forwardable_0));
        bufp->chgIData(oldp+1438,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0),32);
        bufp->chgIData(oldp+1439,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_0),32);
        bufp->chgBit(oldp+1440,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_ready_0));
        bufp->chgCData(oldp+1441,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_store_data_src_0),5);
        bufp->chgBit(oldp+1442,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_0));
        bufp->chgBit(oldp+1443,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_0));
        bufp->chgBit(oldp+1444,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_0));
        bufp->chgBit(oldp+1445,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0));
        bufp->chgBit(oldp+1446,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_0));
        bufp->chgBit(oldp+1447,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_0));
        bufp->chgBit(oldp+1448,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_taken_0));
        bufp->chgIData(oldp+1449,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_target_0),32);
        bufp->chgBit(oldp+1450,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_0));
        bufp->chgBit(oldp+1451,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0));
        bufp->chgIData(oldp+1452,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0),32);
        bufp->chgIData(oldp+1453,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0),32);
        bufp->chgBit(oldp+1454,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_0));
        bufp->chgBit(oldp+1455,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_cacop_0));
        bufp->chgBit(oldp+1456,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_csr_0));
        bufp->chgSData(oldp+1457,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_num_0),14);
        bufp->chgIData(oldp+1458,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wmask_0),32);
        bufp->chgIData(oldp+1459,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_csr_wvalue_0),32);
        bufp->chgBit(oldp+1460,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane0_mem_op));
        bufp->chgBit(oldp+1461,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op));
        bufp->chgBit(oldp+1462,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q));
        bufp->chgBit(oldp+1463,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q));
        bufp->chgBit(oldp+1464,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q));
        bufp->chgBit(oldp+1465,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q));
        bufp->chgBit(oldp+1466,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_lane1_mem_op_ctrl));
        bufp->chgBit(oldp+1467,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q));
        bufp->chgIData(oldp+1468,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1),32);
        bufp->chgIData(oldp+1469,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_alu_result_1),32);
        bufp->chgIData(oldp+1470,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rkd_value_1),32);
        bufp->chgBit(oldp+1471,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1));
        bufp->chgBit(oldp+1472,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_mem_we_1));
        bufp->chgBit(oldp+1473,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_byte_1));
        bufp->chgBit(oldp+1474,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_half_1));
        bufp->chgBit(oldp+1475,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1));
        bufp->chgBit(oldp+1476,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_byte_1));
        bufp->chgBit(oldp+1477,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_st_half_1));
        bufp->chgBit(oldp+1478,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_taken_1));
        bufp->chgIData(oldp+1479,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pred_target_1),32);
        bufp->chgBit(oldp+1480,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_is_bj_1));
        bufp->chgBit(oldp+1481,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1));
        bufp->chgIData(oldp+1482,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1),32);
        bufp->chgIData(oldp+1483,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1),32);
        bufp->chgBit(oldp+1484,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1));
        bufp->chgBit(oldp+1485,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_to_ms_valid_0) 
                                 & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_redirect_miss_0))));
        bufp->chgBit(oldp+1486,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_eff_valid));
        bufp->chgBit(oldp+1487,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane0_mem_op_raw));
        bufp->chgBit(oldp+1488,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__es_lane1_mem_op_raw));
        bufp->chgBit(oldp+1489,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw));
        bufp->chgBit(oldp+1490,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1) 
                                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_24))));
        bufp->chgBit(oldp+1491,((1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_final_result_0 
                                          >> 0x00000018U)))));
        bufp->chgBit(oldp+1492,((1U & (~ (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_exec_result_1 
                                          >> 0x00000018U)))));
        bufp->chgBit(oldp+1493,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                                  ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q)
                                  : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q))));
        bufp->chgBit(oldp+1494,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                                  ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_1)
                                  : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_res_from_mem_0))));
        bufp->chgIData(oldp+1495,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_rkd),32);
        bufp->chgBit(oldp+1496,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_byte));
        bufp->chgBit(oldp+1497,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_ld_half));
        bufp->chgBit(oldp+1498,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                                  ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_1)
                                  : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_ld_sign_ext_0))));
        bufp->chgBit(oldp+1499,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte));
        bufp->chgBit(oldp+1500,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half));
        bufp->chgBit(oldp+1501,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_store_data_ready));
        bufp->chgBit(oldp+1502,((1U & (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind))));
        bufp->chgBit(oldp+1503,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_wait_kind) 
                                       >> 1U))));
        bufp->chgBit(oldp+1504,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__dual_mem_phase_0));
        bufp->chgBit(oldp+1505,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_pending));
        bufp->chgBit(oldp+1506,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting));
        bufp->chgBit(oldp+1507,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_response_waiting));
        bufp->chgBit(oldp+1508,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_q));
        bufp->chgBit(oldp+1509,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid));
        bufp->chgIData(oldp+1510,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf),32);
        bufp->chgBit(oldp+1511,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent));
        bufp->chgIData(oldp+1512,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_target_q),32);
        bufp->chgBit(oldp+1513,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_data_ok));
        bufp->chgBit(oldp+1514,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fast_ready));
        bufp->chgBit(oldp+1515,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_response_waiting) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_fast_data_ok_reg) 
                                    | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_fast_data_ok_reg)))));
        bufp->chgBit(oldp+1516,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_0) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_valid_1))));
        bufp->chgBit(oldp+1517,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__cacop_req_sent) 
                                 & (4U == (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__maint_state)))));
        bufp->chgBit(oldp+1518,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_req) 
                                 & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_mem_we_ready_q) 
                                    & (((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_select_lane1_q)
                                         ? (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_1_q)
                                         : (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_addr_is_sram_0_q)) 
                                       & ((((IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__ext_store_ready) 
                                            << 1U) 
                                           | (IData)(vlSelfRef.asm_monitor_tb__DOT__bridge__DOT__base_store_ready)) 
                                          >> (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_selected_target_ext_ready_q)))))));
        bufp->chgBit(oldp+1519,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_rdata_buf_valid) 
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
        bufp->chgBit(oldp+1520,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__phase_ready_go));
        bufp->chgBit(oldp+1521,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__advance_to_lane1));
        bufp->chgBit(oldp+1522,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_fire));
        bufp->chgBit(oldp+1523,((((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_miss_1) 
                                  & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_24)) 
                                 | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw))));
        bufp->chgBit(oldp+1524,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__branch_redirect_fire));
        bufp->chgIData(oldp+1525,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_redirect_0_raw)
                                    ? ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_0)
                                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_0
                                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_0)
                                    : ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_taken_1)
                                        ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_real_target_1
                                        : vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_next_pc_1))),32);
        bufp->chgBit(oldp+1526,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__bpu_sel_lane1));
        bufp->chgCData(oldp+1527,((0x0000000fU & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_byte)
                                                   ? 
                                                  ((IData)(1U) 
                                                   << 
                                                   (3U 
                                                    & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr))
                                                   : 
                                                  (((2U 
                                                     & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__data_sram_addr)
                                                     ? 0x0cU
                                                     : 3U) 
                                                   | (- (IData)(
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_st_half))))))))),4);
        bufp->chgIData(oldp+1528,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_load_result_0_fwd),32);
        bufp->chgBit(oldp+1529,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response));
        bufp->chgBit(oldp+1530,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms));
        bufp->chgBit(oldp+1531,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1));
        bufp->chgBit(oldp+1532,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0));
        bufp->chgBit(oldp+1533,((1U & ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_response) 
                                       | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ms) 
                                          | ((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws1) 
                                             | ((~ (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_exe__DOT__es_store_data_late_0)) 
                                                | (IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__incoming_store_hit_ws0))))))));
        bufp->chgBit(oldp+1534,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws1));
        bufp->chgBit(oldp+1535,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__held_store_hit_ws0));
        bufp->chgBit(oldp+1536,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_pc__DOT__reset));
        bufp->chgBit(oldp+1537,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__reset));
        bufp->chgBit(oldp+1538,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_0));
        bufp->chgIData(oldp+1539,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_pc_0),32);
        bufp->chgIData(oldp+1540,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_alu_result_0),32);
        bufp->chgIData(oldp+1541,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_mem_result_0),32);
        bufp->chgBit(oldp+1542,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_res_from_mem_0));
        bufp->chgBit(oldp+1543,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_0));
        bufp->chgBit(oldp+1544,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_byte_0));
        bufp->chgBit(oldp+1545,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_half_0));
        bufp->chgBit(oldp+1546,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_ld_sign_ext_0));
        bufp->chgBit(oldp+1547,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_is_csr_0));
        bufp->chgSData(oldp+1548,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_num_0),14);
        bufp->chgIData(oldp+1549,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wmask_0),32);
        bufp->chgIData(oldp+1550,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_csr_wvalue_0),32);
        bufp->chgBit(oldp+1551,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_valid_1));
        bufp->chgBit(oldp+1552,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_gr_we_1));
        bufp->chgCData(oldp+1553,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__csr_state),3);
        bufp->chgIData(oldp+1554,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ws_load_result_0),32);
        bufp->chgCData(oldp+1555,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                   >> 0x0000001aU)),6);
        bufp->chgCData(oldp+1556,((0x0000000fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x00000016U))),4);
        bufp->chgCData(oldp+1557,((3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                         >> 0x00000014U))),2);
        bufp->chgCData(oldp+1558,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000000fU))),5);
        bufp->chgCData(oldp+1559,((0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0)),5);
        bufp->chgCData(oldp+1560,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 5U))),5);
        bufp->chgCData(oldp+1561,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000000aU))),5);
        bufp->chgSData(oldp+1562,((0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000000aU))),12);
        bufp->chgIData(oldp+1563,((0x000fffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 5U))),20);
        bufp->chgSData(oldp+1564,((0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000000aU))),16);
        bufp->chgIData(oldp+1565,(((0x03ff0000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   << 0x00000010U)) 
                                   | (0x0000ffffU & 
                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                       >> 0x0000000aU)))),26);
        bufp->chgQData(oldp+1566,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out),64);
        bufp->chgSData(oldp+1568,((((((((0x0fU == (0x0000000fU 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                      >> 0x00000016U))) 
                                        << 3U) | ((0x0eU 
                                                   == 
                                                   (0x0000000fU 
                                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                       >> 0x00000016U))) 
                                                  << 2U)) 
                                      | (((0x0dU == 
                                           (0x0000000fU 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x00000016U))) 
                                          << 1U) | 
                                         (0x0cU == 
                                          (0x0000000fU 
                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                              >> 0x00000016U))))) 
                                     << 0x0000000cU) 
                                    | (((((0x0bU == 
                                           (0x0000000fU 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x00000016U))) 
                                          << 3U) | 
                                         ((0x0aU == 
                                           (0x0000000fU 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                               >> 0x00000016U))) 
                                          << 2U)) | 
                                        (((9U == (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x00000016U))) 
                                          << 1U) | 
                                         (8U == (0x0000000fU 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                    >> 0x00000016U))))) 
                                       << 8U)) | ((
                                                   ((((7U 
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
        bufp->chgCData(oldp+1569,(((((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x00000014U))) 
                                     << 3U) | ((2U 
                                                == 
                                                (3U 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                    >> 0x00000014U))) 
                                               << 2U)) 
                                   | (((1U == (3U & 
                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                >> 0x00000014U))) 
                                       << 1U) | (0U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                     >> 0x00000014U)))))),4);
        bufp->chgIData(oldp+1570,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec3__DOT__out),32);
        bufp->chgBit(oldp+1571,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_add_w));
        bufp->chgBit(oldp+1572,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sub_w));
        bufp->chgBit(oldp+1573,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slt));
        bufp->chgBit(oldp+1574,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltu));
        bufp->chgBit(oldp+1575,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_nor));
        bufp->chgBit(oldp+1576,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_and));
        bufp->chgBit(oldp+1577,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_or));
        bufp->chgBit(oldp+1578,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xor));
        bufp->chgBit(oldp+1579,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w));
        bufp->chgBit(oldp+1580,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w));
        bufp->chgBit(oldp+1581,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w));
        bufp->chgBit(oldp+1582,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_addi_w));
        bufp->chgBit(oldp+1583,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w));
        bufp->chgBit(oldp+1584,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_w));
        bufp->chgBit(oldp+1585,((0x13U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1586,((0x14U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1587,((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1588,((0x16U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1589,((0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1590,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w));
        bufp->chgBit(oldp+1591,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slti));
        bufp->chgBit(oldp+1592,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sltui));
        bufp->chgBit(oldp+1593,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_andi));
        bufp->chgBit(oldp+1594,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ori));
        bufp->chgBit(oldp+1595,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xori));
        bufp->chgBit(oldp+1596,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w));
        bufp->chgBit(oldp+1597,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w));
        bufp->chgBit(oldp+1598,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w));
        bufp->chgBit(oldp+1599,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_pcaddu12i));
        bufp->chgBit(oldp+1600,((0x18U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1601,((0x19U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1602,((0x1aU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1603,((0x1bU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1604,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_b));
        bufp->chgBit(oldp+1605,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_h));
        bufp->chgBit(oldp+1606,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_bu));
        bufp->chgBit(oldp+1607,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_hu));
        bufp->chgBit(oldp+1608,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_b));
        bufp->chgBit(oldp+1609,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_st_h));
        bufp->chgBit(oldp+1610,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_mul_w));
        bufp->chgBit(oldp+1611,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cpucfg));
        bufp->chgBit(oldp+1612,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_cacop));
        bufp->chgBit(oldp+1613,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrwr));
        bufp->chgBit(oldp+1614,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrxchg));
        bufp->chgBit(oldp+1615,((((((((((((((((((((
                                                   ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_53) 
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
        bufp->chgBit(oldp+1616,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_bu) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_b))));
        bufp->chgBit(oldp+1617,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_hu) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_h))));
        bufp->chgBit(oldp+1618,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__ld_sign_ext));
        bufp->chgBit(oldp+1619,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_ui12));
        bufp->chgBit(oldp+1620,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20));
        bufp->chgBit(oldp+1621,((0U != (3U & (IData)(
                                                     (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                                      >> 0x00000014U))))));
        bufp->chgBit(oldp+1622,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4));
        bufp->chgIData(oldp+1623,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)
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
        bufp->chgIData(oldp+1624,((((0U != (3U & (IData)(
                                                         (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out 
                                                          >> 0x00000014U))))
                                     ? ((0x3c000000U 
                                         & ((- (IData)(
                                                       (1U 
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
        bufp->chgIData(oldp+1625,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__jirl_offs),32);
        bufp->chgBit(oldp+1626,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd));
        bufp->chgBit(oldp+1627,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src1_is_pc));
        bufp->chgBit(oldp+1628,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w) 
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
        bufp->chgBit(oldp+1629,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_ld_w) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_11))));
        bufp->chgBit(oldp+1630,(((~ ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__mem_we) 
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
        bufp->chgBit(oldp+1631,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__mem_we));
        bufp->chgCData(oldp+1632,(((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                              >> 0x0000001aU))
                                    ? 1U : (0x0000001fU 
                                            & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0))),5);
        bufp->chgSData(oldp+1633,(((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_lu12i_w) 
                                       << 5U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srai_w)) 
                                                  << 4U) 
                                                 | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w) 
                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srli_w)) 
                                                    << 3U))) 
                                     | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_slli_w)) 
                                         << 2U) | (
                                                   (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_xor) 
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
        bufp->chgBit(oldp+1634,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr));
        bufp->chgSData(oldp+1635,((0x00003fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                  >> 0x0000000aU))),14);
        bufp->chgCData(oldp+1636,((0x0000001fU & (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr))
                                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0
                                                   : 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_0 
                                                   >> 0x0000000aU)))),5);
        bufp->chgBit(oldp+1637,((1U & (~ (IData)(((
                                                   (0ULL 
                                                    != 
                                                    (0x0000000000300000ULL 
                                                     & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out)) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_csrwr)) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__need_si20)))))));
        bufp->chgBit(oldp+1638,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src_reg_is_rd) 
                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_53) 
                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sll_w) 
                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_srl_w) 
                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_sra_w) 
                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__inst_mul_w) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__is_csr)))))))));
        bufp->chgBit(oldp+1639,((IData)((((0ULL != 
                                           (0x0000000000c00000ULL 
                                            & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__u_dec0__DOT__out)) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__PVT__src2_is_4)) 
                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_0.__VdfgRegularize_h6e95ff9d_0_54)))));
        bufp->chgCData(oldp+1640,((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                   >> 0x0000001aU)),6);
        bufp->chgCData(oldp+1641,((0x0000000fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x00000016U))),4);
        bufp->chgCData(oldp+1642,((3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                         >> 0x00000014U))),2);
        bufp->chgCData(oldp+1643,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000000fU))),5);
        bufp->chgCData(oldp+1644,((0x0000001fU & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1)),5);
        bufp->chgCData(oldp+1645,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 5U))),5);
        bufp->chgCData(oldp+1646,((0x0000001fU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000000aU))),5);
        bufp->chgSData(oldp+1647,((0x00000fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000000aU))),12);
        bufp->chgIData(oldp+1648,((0x000fffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 5U))),20);
        bufp->chgSData(oldp+1649,((0x0000ffffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000000aU))),16);
        bufp->chgIData(oldp+1650,(((0x03ff0000U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   << 0x00000010U)) 
                                   | (0x0000ffffU & 
                                      (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                       >> 0x0000000aU)))),26);
        bufp->chgQData(oldp+1651,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out),64);
        bufp->chgSData(oldp+1653,((((((((0x0fU == (0x0000000fU 
                                                   & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                      >> 0x00000016U))) 
                                        << 3U) | ((0x0eU 
                                                   == 
                                                   (0x0000000fU 
                                                    & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                       >> 0x00000016U))) 
                                                  << 2U)) 
                                      | (((0x0dU == 
                                           (0x0000000fU 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x00000016U))) 
                                          << 1U) | 
                                         (0x0cU == 
                                          (0x0000000fU 
                                           & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                              >> 0x00000016U))))) 
                                     << 0x0000000cU) 
                                    | (((((0x0bU == 
                                           (0x0000000fU 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x00000016U))) 
                                          << 3U) | 
                                         ((0x0aU == 
                                           (0x0000000fU 
                                            & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                               >> 0x00000016U))) 
                                          << 2U)) | 
                                        (((9U == (0x0000000fU 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x00000016U))) 
                                          << 1U) | 
                                         (8U == (0x0000000fU 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                    >> 0x00000016U))))) 
                                       << 8U)) | ((
                                                   ((((7U 
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
        bufp->chgCData(oldp+1654,(((((3U == (3U & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x00000014U))) 
                                     << 3U) | ((2U 
                                                == 
                                                (3U 
                                                 & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                    >> 0x00000014U))) 
                                               << 2U)) 
                                   | (((1U == (3U & 
                                               (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                >> 0x00000014U))) 
                                       << 1U) | (0U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                     >> 0x00000014U)))))),4);
        bufp->chgIData(oldp+1655,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec3__DOT__out),32);
        bufp->chgBit(oldp+1656,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_add_w));
        bufp->chgBit(oldp+1657,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sub_w));
        bufp->chgBit(oldp+1658,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slt));
        bufp->chgBit(oldp+1659,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltu));
        bufp->chgBit(oldp+1660,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_nor));
        bufp->chgBit(oldp+1661,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_and));
        bufp->chgBit(oldp+1662,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_or));
        bufp->chgBit(oldp+1663,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xor));
        bufp->chgBit(oldp+1664,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w));
        bufp->chgBit(oldp+1665,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w));
        bufp->chgBit(oldp+1666,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w));
        bufp->chgBit(oldp+1667,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_addi_w));
        bufp->chgBit(oldp+1668,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w));
        bufp->chgBit(oldp+1669,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_w));
        bufp->chgBit(oldp+1670,((0x13U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1671,((0x14U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1672,((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1673,((0x16U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1674,((0x17U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1675,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w));
        bufp->chgBit(oldp+1676,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slti));
        bufp->chgBit(oldp+1677,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sltui));
        bufp->chgBit(oldp+1678,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_andi));
        bufp->chgBit(oldp+1679,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ori));
        bufp->chgBit(oldp+1680,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xori));
        bufp->chgBit(oldp+1681,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w));
        bufp->chgBit(oldp+1682,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w));
        bufp->chgBit(oldp+1683,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w));
        bufp->chgBit(oldp+1684,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_pcaddu12i));
        bufp->chgBit(oldp+1685,((0x18U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1686,((0x19U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1687,((0x1aU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1688,((0x1bU == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                           >> 0x0000001aU))));
        bufp->chgBit(oldp+1689,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_b));
        bufp->chgBit(oldp+1690,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_h));
        bufp->chgBit(oldp+1691,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_bu));
        bufp->chgBit(oldp+1692,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_hu));
        bufp->chgBit(oldp+1693,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_b));
        bufp->chgBit(oldp+1694,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_st_h));
        bufp->chgBit(oldp+1695,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_mul_w));
        bufp->chgBit(oldp+1696,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cpucfg));
        bufp->chgBit(oldp+1697,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_cacop));
        bufp->chgBit(oldp+1698,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrwr));
        bufp->chgBit(oldp+1699,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrxchg));
        bufp->chgBit(oldp+1700,((((((((((((((((((((
                                                   ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_57) 
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
        bufp->chgBit(oldp+1701,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_bu) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_b))));
        bufp->chgBit(oldp+1702,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_hu) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_h))));
        bufp->chgBit(oldp+1703,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__ld_sign_ext));
        bufp->chgBit(oldp+1704,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_ui12));
        bufp->chgBit(oldp+1705,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20));
        bufp->chgBit(oldp+1706,((0U != (3U & (IData)(
                                                     (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                                      >> 0x00000014U))))));
        bufp->chgBit(oldp+1707,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4));
        bufp->chgIData(oldp+1708,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)
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
        bufp->chgIData(oldp+1709,((((0U != (3U & (IData)(
                                                         (vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out 
                                                          >> 0x00000014U))))
                                     ? ((0x3c000000U 
                                         & ((- (IData)(
                                                       (1U 
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
        bufp->chgIData(oldp+1710,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__jirl_offs),32);
        bufp->chgBit(oldp+1711,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd));
        bufp->chgBit(oldp+1712,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src1_is_pc));
        bufp->chgBit(oldp+1713,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w) 
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
        bufp->chgBit(oldp+1714,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_ld_w) 
                                 | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_14))));
        bufp->chgBit(oldp+1715,(((~ ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__mem_we) 
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
        bufp->chgBit(oldp+1716,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__mem_we));
        bufp->chgCData(oldp+1717,(((0x15U == (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                              >> 0x0000001aU))
                                    ? 1U : (0x0000001fU 
                                            & vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1))),5);
        bufp->chgSData(oldp+1718,(((((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_lu12i_w) 
                                       << 5U) | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srai_w)) 
                                                  << 4U) 
                                                 | (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w) 
                                                     | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srli_w)) 
                                                    << 3U))) 
                                     | ((((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_slli_w)) 
                                         << 2U) | (
                                                   (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_xor) 
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
        bufp->chgBit(oldp+1719,(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr));
        bufp->chgSData(oldp+1720,((0x00003fffU & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                  >> 0x0000000aU))),14);
        bufp->chgCData(oldp+1721,((0x0000001fU & (((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr))
                                                   ? vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1
                                                   : 
                                                  (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_if__DOT__s3_inst_1 
                                                   >> 0x0000000aU)))),5);
        bufp->chgBit(oldp+1722,((1U & (~ (IData)(((
                                                   (0ULL 
                                                    != 
                                                    (0x0000000000300000ULL 
                                                     & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out)) 
                                                   | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_csrwr)) 
                                                  | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__need_si20)))))));
        bufp->chgBit(oldp+1723,(((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src_reg_is_rd) 
                                 | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_57) 
                                    | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sll_w) 
                                       | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_srl_w) 
                                          | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_sra_w) 
                                             | ((IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__inst_mul_w) 
                                                | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__is_csr)))))))));
        bufp->chgBit(oldp+1724,((IData)((((0ULL != 
                                           (0x0000000000c00000ULL 
                                            & vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__u_dec0__DOT__out)) 
                                          | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__PVT__src2_is_4)) 
                                         | (IData)(vlSymsp->TOP__asm_monitor_tb__DOT__cpu__DOT__u_inst_buffer__DOT__u_decoder_1.__VdfgRegularize_h6e95ff9d_0_58)))));
    }
    bufp->chgBit(oldp+1725,(vlSelfRef.asm_monitor_tb__DOT__clk));
    bufp->chgBit(oldp+1726,(vlSelfRef.asm_monitor_tb__DOT__program_exit));
    bufp->chgBit(oldp+1727,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_0) 
                             & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                 >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_0 
                                   < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)))));
    bufp->chgBit(oldp+1728,(((IData)(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_to_ws_valid_1) 
                             & ((vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                 >= vlSelfRef.asm_monitor_tb__DOT__program_addr) 
                                & (vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_pc_1 
                                   < vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3)))));
    bufp->chgIData(oldp+1729,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__selected_load_result_resp),32);
    bufp->chgIData(oldp+1730,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__ms_final_rdata),32);
    bufp->chgCData(oldp+1731,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_byte),8);
    bufp->chgSData(oldp+1732,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_mem__DOT__load_result__Vstatic__load_half),16);
    bufp->chgIData(oldp+1733,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__ms_alu_result_1),32);
    bufp->chgCData(oldp+1734,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_byte),8);
    bufp->chgSData(oldp+1735,(vlSelfRef.asm_monitor_tb__DOT__cpu__DOT__u_wb__DOT__load_result__Vstatic__load_half),16);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____0(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____0\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgBit(oldp+0,(__VdtypeVar[0U][0U]));
    bufp->chgBit(oldp+1,(__VdtypeVar[0U][1U]));
    bufp->chgBit(oldp+2,(__VdtypeVar[0U][2U]));
    bufp->chgBit(oldp+3,(__VdtypeVar[0U][3U]));
    bufp->chgBit(oldp+4,(__VdtypeVar[1U][0U]));
    bufp->chgBit(oldp+5,(__VdtypeVar[1U][1U]));
    bufp->chgBit(oldp+6,(__VdtypeVar[1U][2U]));
    bufp->chgBit(oldp+7,(__VdtypeVar[1U][3U]));
}

void Vasm_monitor_tb___024root__trace_chg_dtype____1(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*17:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____1\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0U][0U]),18);
    bufp->chgIData(oldp+1,(__VdtypeVar[0U][1U]),18);
    bufp->chgIData(oldp+2,(__VdtypeVar[0U][2U]),18);
    bufp->chgIData(oldp+3,(__VdtypeVar[0U][3U]),18);
    bufp->chgIData(oldp+4,(__VdtypeVar[1U][0U]),18);
    bufp->chgIData(oldp+5,(__VdtypeVar[1U][1U]),18);
    bufp->chgIData(oldp+6,(__VdtypeVar[1U][2U]),18);
    bufp->chgIData(oldp+7,(__VdtypeVar[1U][3U]),18);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____2(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*1:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____2\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[0U][0U]),2);
    bufp->chgCData(oldp+1,(__VdtypeVar[0U][1U]),2);
    bufp->chgCData(oldp+2,(__VdtypeVar[0U][2U]),2);
    bufp->chgCData(oldp+3,(__VdtypeVar[0U][3U]),2);
    bufp->chgCData(oldp+4,(__VdtypeVar[1U][0U]),2);
    bufp->chgCData(oldp+5,(__VdtypeVar[1U][1U]),2);
    bufp->chgCData(oldp+6,(__VdtypeVar[1U][2U]),2);
    bufp->chgCData(oldp+7,(__VdtypeVar[1U][3U]),2);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____3(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____3\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0U][0U]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[0U][1U]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[0U][2U]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[0U][3U]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[1U][0U]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[1U][1U]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[1U][2U]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[1U][3U]),32);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____4(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlUnpacked<CData/*0:0*/, 8>, 2>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____4\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgBit(oldp+0,(__VdtypeVar[0U][0U]));
    bufp->chgBit(oldp+1,(__VdtypeVar[0U][1U]));
    bufp->chgBit(oldp+2,(__VdtypeVar[0U][2U]));
    bufp->chgBit(oldp+3,(__VdtypeVar[0U][3U]));
    bufp->chgBit(oldp+4,(__VdtypeVar[0U][4U]));
    bufp->chgBit(oldp+5,(__VdtypeVar[0U][5U]));
    bufp->chgBit(oldp+6,(__VdtypeVar[0U][6U]));
    bufp->chgBit(oldp+7,(__VdtypeVar[0U][7U]));
    bufp->chgBit(oldp+8,(__VdtypeVar[1U][0U]));
    bufp->chgBit(oldp+9,(__VdtypeVar[1U][1U]));
    bufp->chgBit(oldp+10,(__VdtypeVar[1U][2U]));
    bufp->chgBit(oldp+11,(__VdtypeVar[1U][3U]));
    bufp->chgBit(oldp+12,(__VdtypeVar[1U][4U]));
    bufp->chgBit(oldp+13,(__VdtypeVar[1U][5U]));
    bufp->chgBit(oldp+14,(__VdtypeVar[1U][6U]));
    bufp->chgBit(oldp+15,(__VdtypeVar[1U][7U]));
}

void Vasm_monitor_tb___024root__trace_chg_dtype____5(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____5\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),25);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),25);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),25);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),25);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),25);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),25);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),25);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),25);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____6(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*24:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____6\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),25);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),25);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),25);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),25);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),25);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),25);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),25);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),25);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____7(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____7\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgWData(oldp+0,(__VdtypeVar[0]),128);
    bufp->chgWData(oldp+4,(__VdtypeVar[1]),128);
    bufp->chgWData(oldp+8,(__VdtypeVar[2]),128);
    bufp->chgWData(oldp+12,(__VdtypeVar[3]),128);
    bufp->chgWData(oldp+16,(__VdtypeVar[4]),128);
    bufp->chgWData(oldp+20,(__VdtypeVar[5]),128);
    bufp->chgWData(oldp+24,(__VdtypeVar[6]),128);
    bufp->chgWData(oldp+28,(__VdtypeVar[7]),128);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____8(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<4>/*127:0*/, 8>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____8\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgWData(oldp+0,(__VdtypeVar[0]),128);
    bufp->chgWData(oldp+4,(__VdtypeVar[1]),128);
    bufp->chgWData(oldp+8,(__VdtypeVar[2]),128);
    bufp->chgWData(oldp+12,(__VdtypeVar[3]),128);
    bufp->chgWData(oldp+16,(__VdtypeVar[4]),128);
    bufp->chgWData(oldp+20,(__VdtypeVar[5]),128);
    bufp->chgWData(oldp+24,(__VdtypeVar[6]),128);
    bufp->chgWData(oldp+28,(__VdtypeVar[7]),128);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____9(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<VlWide<9>/*265:0*/, 4>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____9\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgWData(oldp+0,(__VdtypeVar[0]),266);
    bufp->chgWData(oldp+9,(__VdtypeVar[1]),266);
    bufp->chgWData(oldp+18,(__VdtypeVar[2]),266);
    bufp->chgWData(oldp+27,(__VdtypeVar[3]),266);
}

void Vasm_monitor_tb___024root__trace_chg_dtype____10(Vasm_monitor_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_chg_dtype____10\n"); );
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[31]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[0]),32);
}

void Vasm_monitor_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vasm_monitor_tb___024root__trace_cleanup\n"); );
    // Body
    Vasm_monitor_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vasm_monitor_tb___024root*>(voidSelf);
    Vasm_monitor_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
