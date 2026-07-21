// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VminiRV_SoC__Syms.h"


void VminiRV_SoC___024root__trace_chg_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VminiRV_SoC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_chg_0\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VminiRV_SoC___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VminiRV_SoC___024root__trace_chg_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__j),32);
        bufp->chgIData(oldp+1,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__mem_file),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [4U]))) {
        bufp->chgCData(oldp+2,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_icache__DOT__nstat),2);
        bufp->chgBit(oldp+3,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_can_forward));
        bufp->chgIData(oldp+4,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_rs1_value),32);
        bufp->chgIData(oldp+5,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_rs2_value),32);
        bufp->chgIData(oldp+6,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a),32);
        bufp->chgIData(oldp+7,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b),32);
        bufp->chgIData(oldp+8,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_c),32);
        bufp->chgBit(oldp+9,(((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op) 
                                        >> 4U))) && 
                              ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op) 
                                      >> 3U)) && ((4U 
                                                   & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                   ? 
                                                  ((1U 
                                                    & (~ 
                                                       ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op) 
                                                        >> 1U))) 
                                                   && ((1U 
                                                        & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                        ? 
                                                       (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                        >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)
                                                        : 
                                                       (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                        < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                     ? 
                                                    VL_GTES_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)
                                                     : 
                                                    VL_LTS_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                     ? 
                                                    (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                     != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)
                                                     : 
                                                    (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                     == vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b))))))));
        bufp->chgBit(oldp+10,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_redirect));
        bufp->chgBit(oldp+11,(((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pipe_stall)) 
                               & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_valid) 
                                  & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6dbabbbd_0_6)))));
        bufp->chgIData(oldp+12,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__a_abs),32);
        bufp->chgIData(oldp+13,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__b_abs),32);
        bufp->chgQData(oldp+14,((((QData)((IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                   >> 0x1fU))) 
                                  << 0x20U) | (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a)))),33);
        bufp->chgQData(oldp+16,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a))),33);
        bufp->chgQData(oldp+18,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b))),33);
        bufp->chgQData(oldp+20,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a))),34);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+22,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2cpu_valid));
        bufp->chgBit(oldp+23,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid));
        bufp->chgIData(oldp+24,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata),32);
        bufp->chgBit(oldp+25,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp));
        bufp->chgIData(oldp+26,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_pc),32);
        bufp->chgBit(oldp+27,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_valid));
        bufp->chgBit(oldp+28,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_valid));
        bufp->chgIData(oldp+29,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs1_data),32);
        bufp->chgIData(oldp+30,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs2_data),32);
        bufp->chgCData(oldp+31,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs1),5);
        bufp->chgCData(oldp+32,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs2),5);
        bufp->chgCData(oldp+33,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op),2);
        bufp->chgCData(oldp+34,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alu_op),5);
        bufp->chgBit(oldp+35,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel));
        bufp->chgBit(oldp+36,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alub_sel));
        bufp->chgCData(oldp+37,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_wop),4);
        bufp->chgBit(oldp+38,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_we));
        bufp->chgBit(oldp+39,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_is_muldiv));
        bufp->chgBit(oldp+40,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_mul_started));
        bufp->chgBit(oldp+41,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_valid));
        bufp->chgIData(oldp+42,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_store_data),32);
        bufp->chgCData(oldp+43,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_wop),4);
        bufp->chgBit(oldp+44,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_we));
        bufp->chgBit(oldp+45,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_mem_started));
        bufp->chgBit(oldp+46,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_valid));
        bufp->chgIData(oldp+47,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_pc),32);
        bufp->chgBit(oldp+48,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rf_we));
        bufp->chgBit(oldp+49,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_busy));
        bufp->chgBit(oldp+50,((2U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
        bufp->chgBit(oldp+51,((3U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
        bufp->chgBit(oldp+52,((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
        bufp->chgQData(oldp+53,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__mul_res),64);
        bufp->chgWData(oldp+55,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__mulu_res),66);
        bufp->chgBit(oldp+58,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__busy_r));
        bufp->chgBit(oldp+59,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__busy_r));
        bufp->chgIData(oldp+60,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_out),32);
        bufp->chgIData(oldp+61,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__quotient_out),32);
        bufp->chgIData(oldp+62,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_rem),32);
        bufp->chgIData(oldp+63,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__divu_rem),32);
        bufp->chgBit(oldp+64,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_busy));
        bufp->chgBit(oldp+65,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__divu_busy));
        bufp->chgCData(oldp+66,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__op_r),5);
        bufp->chgIData(oldp+67,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__a_r),32);
        bufp->chgBit(oldp+68,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_neg_r));
        bufp->chgBit(oldp+69,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__rem_neg_r));
        bufp->chgBit(oldp+70,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_zero_r));
        bufp->chgBit(oldp+71,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_overflow_r));
        bufp->chgIData(oldp+72,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_neg_r)
                                  ? ((IData)(1U) + 
                                     (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_out))
                                  : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_out)),32);
        bufp->chgIData(oldp+73,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__rem_neg_r)
                                  ? ((IData)(1U) + 
                                     (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_rem))
                                  : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_rem)),32);
        bufp->chgIData(oldp+74,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient),32);
        bufp->chgIData(oldp+75,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__dividend),32);
        bufp->chgIData(oldp+76,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__divisor),32);
        bufp->chgQData(oldp+77,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder),33);
        bufp->chgCData(oldp+79,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__count),8);
        bufp->chgQData(oldp+80,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__divisor))),33);
        bufp->chgQData(oldp+82,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder_shift),33);
        bufp->chgQData(oldp+84,((0x1ffffffffULL & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder_shift 
                                                   - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__divisor))))),33);
        bufp->chgBit(oldp+86,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__ge_divisor));
        bufp->chgQData(oldp+87,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder_next),33);
        bufp->chgIData(oldp+89,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_next),32);
        bufp->chgIData(oldp+90,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__quotient),32);
        bufp->chgIData(oldp+91,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__dividend),32);
        bufp->chgIData(oldp+92,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__divisor),32);
        bufp->chgQData(oldp+93,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder),33);
        bufp->chgCData(oldp+95,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__count),8);
        bufp->chgQData(oldp+96,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__divisor))),33);
        bufp->chgQData(oldp+98,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift),33);
        bufp->chgQData(oldp+100,((0x1ffffffffULL & 
                                  (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift 
                                   - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__divisor))))),33);
        bufp->chgBit(oldp+102,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__ge_divisor));
        bufp->chgQData(oldp+103,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder_next),33);
        bufp->chgIData(oldp+105,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__quotient_next),32);
        bufp->chgWData(oldp+106,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__product),66);
        bufp->chgQData(oldp+109,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__x_ext_r),33);
        bufp->chgCData(oldp+111,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__count),8);
        bufp->chgQData(oldp+112,((0x1ffffffffULL & 
                                  (((QData)((IData)(
                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__product[1U])) 
                                                 >> 1U)))),33);
        bufp->chgQData(oldp+114,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__next_high),33);
        bufp->chgWData(oldp+116,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__next_product),66);
        bufp->chgWData(oldp+119,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__product),68);
        bufp->chgQData(oldp+122,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__x_ext_r),34);
        bufp->chgCData(oldp+124,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__count),8);
        bufp->chgQData(oldp+125,((0x3ffffffffULL & 
                                  (((QData)((IData)(
                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                    << 0x1eU) | ((QData)((IData)(
                                                                 vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__product[1U])) 
                                                 >> 2U)))),34);
        bufp->chgQData(oldp+127,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__next_high),34);
        bufp->chgWData(oldp+129,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__next_product),68);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+132,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bid_reg),4);
        bufp->chgCData(oldp+133,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rid_reg),4);
        bufp->chgBit(oldp+134,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_state_reg));
        bufp->chgCData(oldp+135,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_state_reg),2);
        bufp->chgCData(oldp+136,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_id_reg),4);
        bufp->chgCData(oldp+137,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_count_reg),8);
        bufp->chgCData(oldp+138,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_size_reg),3);
        bufp->chgCData(oldp+139,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_burst_reg),2);
        bufp->chgCData(oldp+140,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_id_reg),4);
        bufp->chgIData(oldp+141,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_reg),32);
        bufp->chgCData(oldp+142,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_count_reg),8);
        bufp->chgCData(oldp+143,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_size_reg),3);
        bufp->chgCData(oldp+144,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_burst_reg),2);
        bufp->chgCData(oldp+145,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rid_pipe_reg),4);
        bufp->chgIData(oldp+146,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_pipe_reg),32);
        bufp->chgBit(oldp+147,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rlast_pipe_reg));
        bufp->chgBit(oldp+148,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg));
        bufp->chgIData(oldp+149,((vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_reg 
                                  >> 2U)),30);
        bufp->chgBit(oldp+150,((0xffffU != (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_reg 
                                            >> 0x10U))));
        bufp->chgIData(oldp+151,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__i),32);
        bufp->chgIData(oldp+152,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[0]),32);
        bufp->chgIData(oldp+153,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[1]),32);
        bufp->chgIData(oldp+154,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[2]),32);
        bufp->chgIData(oldp+155,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[3]),32);
        bufp->chgIData(oldp+156,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[4]),32);
        bufp->chgIData(oldp+157,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[5]),32);
        bufp->chgIData(oldp+158,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[6]),32);
        bufp->chgIData(oldp+159,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[7]),32);
        bufp->chgIData(oldp+160,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[8]),32);
        bufp->chgIData(oldp+161,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[9]),32);
        bufp->chgIData(oldp+162,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[10]),32);
        bufp->chgIData(oldp+163,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[11]),32);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[12]),32);
        bufp->chgIData(oldp+165,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[13]),32);
        bufp->chgIData(oldp+166,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[14]),32);
        bufp->chgIData(oldp+167,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[15]),32);
        bufp->chgIData(oldp+168,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[16]),32);
        bufp->chgIData(oldp+169,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[17]),32);
        bufp->chgIData(oldp+170,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[18]),32);
        bufp->chgIData(oldp+171,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[19]),32);
        bufp->chgIData(oldp+172,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[20]),32);
        bufp->chgIData(oldp+173,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[21]),32);
        bufp->chgIData(oldp+174,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[22]),32);
        bufp->chgIData(oldp+175,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[23]),32);
        bufp->chgIData(oldp+176,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[24]),32);
        bufp->chgIData(oldp+177,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[25]),32);
        bufp->chgIData(oldp+178,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[26]),32);
        bufp->chgIData(oldp+179,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[27]),32);
        bufp->chgIData(oldp+180,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[28]),32);
        bufp->chgIData(oldp+181,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[29]),32);
        bufp->chgIData(oldp+182,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[30]),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+183,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_addr_r),32);
        bufp->chgBit(oldp+184,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_awvalid));
        bufp->chgIData(oldp+185,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_data_r),32);
        bufp->chgCData(oldp+186,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_strb_r),4);
        bufp->chgBit(oldp+187,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_wvalid));
        bufp->chgBit(oldp+188,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready));
        bufp->chgIData(oldp+189,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_addr_r),32);
        bufp->chgCData(oldp+190,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_len_r),8);
        bufp->chgBit(oldp+191,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_arvalid));
        bufp->chgBit(oldp+192,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_rready));
        bufp->chgIData(oldp+193,((vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_addr_r 
                                  >> 2U)),30);
        bufp->chgIData(oldp+194,((vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_addr_r 
                                  >> 2U)),30);
        bufp->chgIData(oldp+195,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2cpu_inst),32);
        bufp->chgCData(oldp+196,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2axi_ren),4);
        bufp->chgIData(oldp+197,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2axi_addr),32);
        bufp->chgBit(oldp+198,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2ic_rrdy));
        bufp->chgBit(oldp+199,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2ic_rvalid));
        bufp->chgIData(oldp+200,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__ic_read_buf[0U]),32);
        bufp->chgCData(oldp+201,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren),4);
        bufp->chgIData(oldp+202,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c),32);
        bufp->chgCData(oldp+203,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen),4);
        bufp->chgIData(oldp+204,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mreq_wdata),32);
        bufp->chgCData(oldp+205,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_wen),4);
        bufp->chgIData(oldp+206,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_waddr),32);
        bufp->chgIData(oldp+207,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_wdata),32);
        bufp->chgCData(oldp+208,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_ren),4);
        bufp->chgIData(oldp+209,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_raddr),32);
        bufp->chgBit(oldp+210,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2dc_rrdy));
        bufp->chgBit(oldp+211,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2dc_rvalid));
        bufp->chgIData(oldp+212,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__dc_read_buf[0U]),32);
        bufp->chgCData(oldp+213,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__state),4);
        bufp->chgBit(oldp+214,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_is_data));
        bufp->chgCData(oldp+215,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_count),2);
        bufp->chgWData(oldp+216,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__ic_read_buf),128);
        bufp->chgWData(oldp+220,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__dc_read_buf),128);
        __Vtemp_1[0U] = vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__dc_read_buf[0U];
        __Vtemp_1[1U] = 0U;
        __Vtemp_1[2U] = 0U;
        __Vtemp_1[3U] = 0U;
        bufp->chgWData(oldp+224,(__Vtemp_1),128);
        bufp->chgBit(oldp+228,(((0xffffU == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c 
                                             >> 0x10U)) 
                                & ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren)) 
                                   | (0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))))));
        bufp->chgCData(oldp+229,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__r_state),2);
        bufp->chgCData(oldp+230,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__r_nstat),2);
        bufp->chgCData(oldp+231,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__ren_r),4);
        bufp->chgCData(oldp+232,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__w_state),2);
        bufp->chgCData(oldp+233,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__wen_r),4);
        __Vtemp_2[0U] = vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__ic_read_buf[0U];
        __Vtemp_2[1U] = 0U;
        __Vtemp_2[2U] = 0U;
        __Vtemp_2[3U] = 0U;
        bufp->chgWData(oldp+234,(__Vtemp_2),128);
        bufp->chgCData(oldp+238,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_icache__DOT__state),2);
        bufp->chgIData(oldp+239,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_req_pc),32);
        bufp->chgBit(oldp+240,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_wait));
        bufp->chgBit(oldp+241,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_discard));
        bufp->chgBit(oldp+242,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_valid));
        bufp->chgIData(oldp+243,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_pc),32);
        bufp->chgIData(oldp+244,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_inst),32);
        bufp->chgIData(oldp+245,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_pc),32);
        bufp->chgIData(oldp+246,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst),32);
        bufp->chgIData(oldp+247,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_pc),32);
        bufp->chgIData(oldp+248,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ext),32);
        bufp->chgCData(oldp+249,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd),5);
        bufp->chgCData(oldp+250,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_rop),3);
        bufp->chgCData(oldp+251,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_wsel),2);
        bufp->chgIData(oldp+252,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_pc),32);
        bufp->chgIData(oldp+253,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ext),32);
        bufp->chgCData(oldp+254,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd),5);
        bufp->chgCData(oldp+255,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop),3);
        bufp->chgCData(oldp+256,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel),2);
        bufp->chgIData(oldp+257,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_data),32);
        bufp->chgCData(oldp+258,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rd),5);
        bufp->chgCData(oldp+259,((3U & ((1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR)))) 
                                        | ((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA)))) 
                                           | (- (IData)(
                                                        (0x6fU 
                                                         == 
                                                         (0x7fU 
                                                          & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))))))),2);
        bufp->chgCData(oldp+260,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_sext_op),3);
        bufp->chgBit(oldp+261,((0x17U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
        bufp->chgBit(oldp+262,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA))))))))))))))))));
        bufp->chgCData(oldp+263,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_alu_op),5);
        bufp->chgBit(oldp+264,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29))));
        bufp->chgBit(oldp+265,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_is_div));
        bufp->chgCData(oldp+266,(((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB)))) 
                                  | ((3U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU)))) 
                                     | ((4U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)))) 
                                        | ((5U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU)))) 
                                           | (1U & 
                                              (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW))))))))),3);
        bufp->chgCData(oldp+267,((0xfU & ((1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB)))) 
                                          | ((3U & 
                                              (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH)))) 
                                             | (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW))))))),4);
        bufp->chgBit(oldp+268,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI) 
                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI) 
                                                       | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))))))))) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                  | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_is_div))))))))))))) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                   | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH) 
                                       | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW)) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__EXT_OP_U) 
                                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__WB_OP_PC4))))))));
        bufp->chgCData(oldp+269,((3U & ((1U & (- (IData)(
                                                         (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                                           | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)) 
                                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW) 
                                                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33)))))) 
                                        | ((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__WB_OP_PC4)))) 
                                           | (- (IData)(
                                                        (0x37U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))))))),2);
        bufp->chgIData(oldp+270,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ext),32);
        bufp->chgCData(oldp+271,((0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+272,((0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+273,((0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                           >> 7U))),5);
        bufp->chgBit(oldp+274,(((0x13U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                | ((0x33U == (0x7fU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                   | ((3U == (0x7fU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                      | ((0x23U == 
                                          (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                         | ((0x63U 
                                             == (0x7fU 
                                                 & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                            | (0x67U 
                                               == (0x7fU 
                                                   & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))))))));
        bufp->chgBit(oldp+275,(((0x33U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                | ((0x23U == (0x7fU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                   | (0x63U == (0x7fU 
                                                & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))))));
        bufp->chgBit(oldp+276,((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_rop))));
        bufp->chgBit(oldp+277,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_use_stall));
        bufp->chgBit(oldp+278,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_can_forward));
        bufp->chgBit(oldp+279,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_in_progress));
        bufp->chgBit(oldp+280,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_stall));
        bufp->chgCData(oldp+281,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op),5);
        bufp->chgBit(oldp+282,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_stall));
        bufp->chgBit(oldp+283,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pipe_stall));
        bufp->chgCData(oldp+284,(((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                   ? ((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                       ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                           ? ((0U == 
                                               (3U 
                                                & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c))
                                               ? 0xfU
                                               : 0U)
                                           : ((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)
                                               ? 0U
                                               : 0xfU))
                                       : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                           ? 0xfU : 
                                          ((0U == (3U 
                                                   & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c))
                                            ? 0xfU : 0U)))
                                   : 0U)),4);
        bufp->chgCData(oldp+285,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mreq_wen),4);
        bufp->chgIData(oldp+286,(((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                   ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                       ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din
                                       : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                           ? (0xffffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                              >> 0xfU)))) 
                                               << 0x10U) 
                                              | (0xffffU 
                                                 & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))))
                                   : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                       ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                           ? (0xffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | (0xffU 
                                                 & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)))
                                       : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))),32);
        bufp->chgIData(oldp+287,(((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel))
                                   ? ((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                       ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                           ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din
                                           : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                               ? (0xffffU 
                                                  & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                               : ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                                  >> 0xfU)))) 
                                                   << 0x10U) 
                                                  | (0xffffU 
                                                     & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))))
                                       : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                           ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                               ? (0xffU 
                                                  & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                               : ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                                  >> 7U)))) 
                                                   << 8U) 
                                                  | (0xffU 
                                                     & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)))
                                           : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))
                                   : ((2U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel))
                                       ? ((IData)(4U) 
                                          + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_pc)
                                       : ((3U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel))
                                           ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ext
                                           : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)))),32);
        bufp->chgBit(oldp+288,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__mul_flag));
        bufp->chgBit(oldp+289,((0x12U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))));
        bufp->chgBit(oldp+290,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_flag));
        bufp->chgBit(oldp+291,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__divu_flag));
        bufp->chgCData(oldp+292,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__op_eff),5);
        bufp->chgCData(oldp+293,((0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)),7);
        bufp->chgCData(oldp+294,((7U & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+295,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                  >> 0x19U)),7);
        bufp->chgBit(oldp+296,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI));
        bufp->chgBit(oldp+297,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI));
        bufp->chgBit(oldp+298,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU));
        bufp->chgBit(oldp+299,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI));
        bufp->chgBit(oldp+300,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI));
        bufp->chgBit(oldp+301,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI));
        bufp->chgBit(oldp+302,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI));
        bufp->chgBit(oldp+303,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI));
        bufp->chgBit(oldp+304,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI));
        bufp->chgBit(oldp+305,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD));
        bufp->chgBit(oldp+306,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SUB));
        bufp->chgBit(oldp+307,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLL));
        bufp->chgBit(oldp+308,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT));
        bufp->chgBit(oldp+309,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU));
        bufp->chgBit(oldp+310,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR));
        bufp->chgBit(oldp+311,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL));
        bufp->chgBit(oldp+312,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA));
        bufp->chgBit(oldp+313,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR));
        bufp->chgBit(oldp+314,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND));
        bufp->chgBit(oldp+315,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL));
        bufp->chgBit(oldp+316,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MULH));
        bufp->chgBit(oldp+317,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MULHU));
        bufp->chgBit(oldp+318,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__DIV));
        bufp->chgBit(oldp+319,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__DIVU));
        bufp->chgBit(oldp+320,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__REM));
        bufp->chgBit(oldp+321,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__REMU));
        bufp->chgBit(oldp+322,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB));
        bufp->chgBit(oldp+323,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH));
        bufp->chgBit(oldp+324,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW));
        bufp->chgBit(oldp+325,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU));
        bufp->chgBit(oldp+326,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU));
        bufp->chgBit(oldp+327,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB));
        bufp->chgBit(oldp+328,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH));
        bufp->chgBit(oldp+329,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW));
        bufp->chgBit(oldp+330,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BEQ));
        bufp->chgBit(oldp+331,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BNE));
        bufp->chgBit(oldp+332,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BLT));
        bufp->chgBit(oldp+333,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BGE));
        bufp->chgBit(oldp+334,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BLTU));
        bufp->chgBit(oldp+335,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BGEU));
        bufp->chgBit(oldp+336,((0x37U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
        bufp->chgBit(oldp+337,((0x6fU == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
        bufp->chgBit(oldp+338,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR));
        bufp->chgBit(oldp+339,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA));
        bufp->chgBit(oldp+340,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR) 
                                            | (0x6fU 
                                               == (0x7fU 
                                                   & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))))))));
        bufp->chgBit(oldp+341,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI) 
                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI) 
                                                       | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))))))))) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                  | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_is_div))))))))))))) 
                                | (0x17U == (0x7fU 
                                             & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))));
        bufp->chgBit(oldp+342,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW) 
                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33)))));
        bufp->chgBit(oldp+343,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__WB_OP_PC4));
        bufp->chgBit(oldp+344,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI) 
                                                      | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))))))))) 
                                | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU) 
                                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR))))))));
        bufp->chgBit(oldp+345,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB) 
                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH)) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW))));
        bufp->chgBit(oldp+346,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__EXT_OP_U));
        bufp->chgBit(oldp+347,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                   | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH) 
                                       | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW)) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU) 
                                            | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB) 
                                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH)) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                                     | ((0x17U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                                        | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR))))))))))));
        bufp->chgBit(oldp+348,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI))));
        bufp->chgBit(oldp+349,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI))));
        bufp->chgBit(oldp+350,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI))));
        bufp->chgBit(oldp+351,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLL) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI))));
        bufp->chgBit(oldp+352,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI))));
        bufp->chgBit(oldp+353,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))));
        bufp->chgBit(oldp+354,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI))));
        bufp->chgBit(oldp+355,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU))));
        bufp->chgBit(oldp+356,((0x17U != (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
        bufp->chgBit(oldp+357,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA))))))))))))))));
        bufp->chgCData(oldp+358,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)),2);
        bufp->chgIData(oldp+359,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din),32);
        bufp->chgIData(oldp+360,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                  >> 7U)),25);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+361,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_awready_reg));
        bufp->chgBit(oldp+362,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_wready_reg));
        bufp->chgBit(oldp+363,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg));
        bufp->chgBit(oldp+364,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_arready_reg));
        bufp->chgIData(oldp+365,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg),32);
        bufp->chgBit(oldp+366,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rlast_reg));
        bufp->chgBit(oldp+367,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg));
        bufp->chgIData(oldp+368,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_addr_reg),32);
        bufp->chgIData(oldp+369,((vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_addr_reg 
                                  >> 2U)),30);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[6U])) {
        bufp->chgBit(oldp+370,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_state_next));
        bufp->chgCData(oldp+371,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_state_next),2);
        bufp->chgBit(oldp+372,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__mem_wr_en));
        bufp->chgBit(oldp+373,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__mem_rd_en));
        bufp->chgCData(oldp+374,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_id_next),4);
        bufp->chgIData(oldp+375,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_addr_next),32);
        bufp->chgCData(oldp+376,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_count_next),8);
        bufp->chgCData(oldp+377,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_size_next),3);
        bufp->chgCData(oldp+378,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_burst_next),2);
        bufp->chgCData(oldp+379,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_id_next),4);
        bufp->chgIData(oldp+380,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_next),32);
        bufp->chgCData(oldp+381,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_count_next),8);
        bufp->chgCData(oldp+382,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_size_next),3);
        bufp->chgCData(oldp+383,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_burst_next),2);
        bufp->chgBit(oldp+384,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_awready_next));
        bufp->chgBit(oldp+385,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_wready_next));
        bufp->chgCData(oldp+386,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bid_next),4);
        bufp->chgBit(oldp+387,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bvalid_next));
        bufp->chgBit(oldp+388,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_arready_next));
        bufp->chgCData(oldp+389,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rid_next),4);
        bufp->chgBit(oldp+390,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rlast_next));
        bufp->chgBit(oldp+391,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rvalid_next));
        bufp->chgBit(oldp+392,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2dc_wrdy));
        bufp->chgCData(oldp+393,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__w_nstat),2);
        bufp->chgBit(oldp+394,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__wr_resp));
    }
    bufp->chgBit(oldp+395,(vlSelfRef.fpga_clk));
    bufp->chgBit(oldp+396,(vlSelfRef.fpga_rst));
    bufp->chgSData(oldp+397,(vlSelfRef.sw),16);
    bufp->chgSData(oldp+398,(vlSelfRef.led),16);
    bufp->chgCData(oldp+399,(vlSelfRef.dig_en),8);
    bufp->chgCData(oldp+400,(vlSelfRef.dig_seg),8);
    bufp->chgCData(oldp+401,(vlSelfRef.dig_seg1),8);
    bufp->chgBit(oldp+402,(vlSelfRef.rx));
    bufp->chgBit(oldp+403,(vlSelfRef.tx));
    bufp->chgBit(oldp+404,((1U & (~ (IData)(vlSelfRef.fpga_rst)))));
    bufp->chgBit(oldp+405,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req));
    bufp->chgIData(oldp+406,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr),32);
    bufp->chgBit(oldp+407,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid));
    bufp->chgIData(oldp+408,(((0U == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                               >> 0xfU)))
                               ? 0U : ((0x1eU >= (0x1fU 
                                                  & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                      >> 0xfU) 
                                                     - (IData)(1U))))
                                        ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                       [(0x1fU & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                   >> 0xfU) 
                                                  - (IData)(1U)))]
                                        : 0U))),32);
    bufp->chgIData(oldp+409,(((0U == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                               >> 0x14U)))
                               ? 0U : ((0x1eU >= (0x1fU 
                                                  & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                      >> 0x14U) 
                                                     - (IData)(1U))))
                                        ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                       [(0x1fU & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                   >> 0x14U) 
                                                  - (IData)(1U)))]
                                        : 0U))),32);
    bufp->chgIData(oldp+410,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_can_forward) 
                               & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rd) 
                                  == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                               >> 0xfU))))
                               ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_data
                               : ((0U == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                   >> 0xfU)))
                                   ? 0U : ((0x1eU >= 
                                            (0x1fU 
                                             & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                 >> 0xfU) 
                                                - (IData)(1U))))
                                            ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                           [(0x1fU 
                                             & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                 >> 0xfU) 
                                                - (IData)(1U)))]
                                            : 0U)))),32);
    bufp->chgIData(oldp+411,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_can_forward) 
                               & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rd) 
                                  == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                               >> 0x14U))))
                               ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_data
                               : ((0U == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                   >> 0x14U)))
                                   ? 0U : ((0x1eU >= 
                                            (0x1fU 
                                             & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                 >> 0x14U) 
                                                - (IData)(1U))))
                                            ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                           [(0x1fU 
                                             & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                 >> 0x14U) 
                                                - (IData)(1U)))]
                                            : 0U)))),32);
    bufp->chgBit(oldp+412,((((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid)) 
                            | ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_wop)) 
                               & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp)))));
    bufp->chgIData(oldp+413,(((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))
                               ? (0xfffffffeU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_rs1_value 
                                                 + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ext))
                               : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ext 
                                  + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_pc))),32);
    bufp->chgIData(oldp+414,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_pc),32);
    bufp->chgBit(oldp+415,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_we));
    bufp->chgCData(oldp+416,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wR),5);
    bufp->chgIData(oldp+417,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wD),32);
    bufp->chgIData(oldp+418,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_pc),32);
    bufp->chgCData(oldp+419,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_we),4);
    bufp->chgIData(oldp+420,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_waddr),32);
    bufp->chgIData(oldp+421,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_wdata),32);
}

void VminiRV_SoC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_cleanup\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
