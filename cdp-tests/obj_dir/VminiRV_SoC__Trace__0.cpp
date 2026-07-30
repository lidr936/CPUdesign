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
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__i),32);
        bufp->chgIData(oldp+1,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__j),32);
        bufp->chgIData(oldp+2,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__mem_file),32);
        bufp->chgIData(oldp+3,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__i),32);
        bufp->chgIData(oldp+4,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__j),32);
        bufp->chgIData(oldp+5,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__mem_file),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [5U]))) {
        bufp->chgCData(oldp+6,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op),2);
        bufp->chgCData(oldp+7,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wsel),2);
        bufp->chgCData(oldp+8,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__sext_op),3);
        bufp->chgCData(oldp+9,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op),5);
        bufp->chgBit(oldp+10,((0x17U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
        bufp->chgBit(oldp+11,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA))))))))))))))))));
        bufp->chgCData(oldp+12,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop),3);
        bufp->chgCData(oldp+13,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_wop),4);
        bufp->chgBit(oldp+14,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29))));
        bufp->chgBit(oldp+15,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_div));
        bufp->chgBit(oldp+16,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_mul_div));
        bufp->chgIData(oldp+17,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_rd1),32);
        bufp->chgIData(oldp+18,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_rd2),32);
        bufp->chgBit(oldp+19,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                      | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))))))))) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_div))))))))))))) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                                  | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH) 
                                      | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW)) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_33) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_U) 
                                           | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4))))))));
        bufp->chgBit(oldp+20,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_we1));
        bufp->chgCData(oldp+21,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wR),5);
        bufp->chgIData(oldp+22,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wD),32);
        bufp->chgIData(oldp+23,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext),32);
        bufp->chgIData(oldp+24,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a),32);
        bufp->chgIData(oldp+25,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b),32);
        bufp->chgIData(oldp+26,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c),32);
        bufp->chgBit(oldp+27,(((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                         >> 4U))) && 
                               ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                       >> 3U)) && (
                                                   (4U 
                                                    & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                    ? 
                                                   ((1U 
                                                     & (~ 
                                                        ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                         >> 1U))) 
                                                    && ((1U 
                                                         & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                         ? 
                                                        (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                         >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                         : 
                                                        (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                         < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                      ? 
                                                     VL_GTES_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                      : 
                                                     VL_LTS_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                      ? 
                                                     (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                      != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                      : 
                                                     (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                      == vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))))))));
        bufp->chgCData(oldp+28,(((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                                  ? ((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                                      ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                                          ? ((0U == 
                                              (3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c))
                                              ? 0xfU
                                              : 0U)
                                          : ((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c)
                                              ? 0U : 0xfU))
                                      : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                                          ? 0xfU : 
                                         ((0U == (3U 
                                                  & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c))
                                           ? 0xfU : 0U)))
                                  : 0U)),4);
        bufp->chgCData(oldp+29,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__da_wen),4);
        bufp->chgIData(oldp+30,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__da_wdata),32);
        bufp->chgBit(oldp+31,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_ld_st));
        bufp->chgBit(oldp+32,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__inst_finished));
        bufp->chgBit(oldp+33,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__mul_flag));
        bufp->chgBit(oldp+34,((0x12U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))));
        bufp->chgBit(oldp+35,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_flag));
        bufp->chgBit(oldp+36,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__divu_flag));
        bufp->chgCData(oldp+37,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__op_eff),5);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__a_abs),32);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__b_abs),32);
        bufp->chgQData(oldp+40,((((QData)((IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                   >> 0x1fU))) 
                                  << 0x20U) | (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a)))),33);
        bufp->chgQData(oldp+42,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a))),33);
        bufp->chgQData(oldp+44,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))),33);
        bufp->chgQData(oldp+46,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a))),34);
        bufp->chgCData(oldp+48,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode),7);
        bufp->chgCData(oldp+49,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__funct3),3);
        bufp->chgCData(oldp+50,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__funct7),7);
        bufp->chgBit(oldp+51,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI));
        bufp->chgBit(oldp+52,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI));
        bufp->chgBit(oldp+53,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU));
        bufp->chgBit(oldp+54,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI));
        bufp->chgBit(oldp+55,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI));
        bufp->chgBit(oldp+56,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI));
        bufp->chgBit(oldp+57,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI));
        bufp->chgBit(oldp+58,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI));
        bufp->chgBit(oldp+59,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI));
        bufp->chgBit(oldp+60,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD));
        bufp->chgBit(oldp+61,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB));
        bufp->chgBit(oldp+62,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL));
        bufp->chgBit(oldp+63,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT));
        bufp->chgBit(oldp+64,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU));
        bufp->chgBit(oldp+65,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR));
        bufp->chgBit(oldp+66,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL));
        bufp->chgBit(oldp+67,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA));
        bufp->chgBit(oldp+68,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR));
        bufp->chgBit(oldp+69,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND));
        bufp->chgBit(oldp+70,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL));
        bufp->chgBit(oldp+71,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULH));
        bufp->chgBit(oldp+72,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULHU));
        bufp->chgBit(oldp+73,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIV));
        bufp->chgBit(oldp+74,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIVU));
        bufp->chgBit(oldp+75,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REM));
        bufp->chgBit(oldp+76,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REMU));
        bufp->chgBit(oldp+77,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB));
        bufp->chgBit(oldp+78,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH));
        bufp->chgBit(oldp+79,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW));
        bufp->chgBit(oldp+80,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU));
        bufp->chgBit(oldp+81,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU));
        bufp->chgBit(oldp+82,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB));
        bufp->chgBit(oldp+83,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH));
        bufp->chgBit(oldp+84,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW));
        bufp->chgBit(oldp+85,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BEQ));
        bufp->chgBit(oldp+86,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BNE));
        bufp->chgBit(oldp+87,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLT));
        bufp->chgBit(oldp+88,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGE));
        bufp->chgBit(oldp+89,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLTU));
        bufp->chgBit(oldp+90,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGEU));
        bufp->chgBit(oldp+91,((0x37U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
        bufp->chgBit(oldp+92,((0x6fU == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
        bufp->chgBit(oldp+93,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR));
        bufp->chgBit(oldp+94,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA));
        bufp->chgBit(oldp+95,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR) 
                                           | (0x6fU 
                                              == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))))))));
        bufp->chgBit(oldp+96,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                      | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))))))))) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_div))))))))))))) 
                               | (0x17U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode)))));
        bufp->chgBit(oldp+97,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH)) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW) 
                                  | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_33)))));
        bufp->chgBit(oldp+98,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4));
        bufp->chgBit(oldp+99,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                     | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))))))))) 
                               | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH)) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU) 
                                           | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR))))))));
        bufp->chgBit(oldp+100,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB) 
                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH)) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW))));
        bufp->chgBit(oldp+101,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_U));
        bufp->chgBit(oldp+102,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                                   | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH) 
                                       | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW)) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU) 
                                            | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB) 
                                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH)) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                                     | ((0x17U 
                                                         == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode)) 
                                                        | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR))))))))))));
        bufp->chgBit(oldp+103,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI))));
        bufp->chgBit(oldp+104,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI))));
        bufp->chgBit(oldp+105,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI))));
        bufp->chgBit(oldp+106,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI))));
        bufp->chgBit(oldp+107,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI))));
        bufp->chgBit(oldp+108,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))));
        bufp->chgBit(oldp+109,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI))));
        bufp->chgBit(oldp+110,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU))));
        bufp->chgBit(oldp+111,((0x17U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
        bufp->chgBit(oldp+112,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA))))))))))))))));
        bufp->chgCData(oldp+113,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c)),2);
        bufp->chgCData(oldp+114,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_RF__rR1),5);
        bufp->chgCData(oldp+115,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_RF__rR2),5);
        bufp->chgIData(oldp+116,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_SEXT__imm),25);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+117,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom.__PVT__inst_valid));
        bufp->chgCData(oldp+118,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren),4);
        bufp->chgBit(oldp+119,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid));
        bufp->chgBit(oldp+120,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp));
        bufp->chgBit(oldp+121,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_flag));
        bufp->chgBit(oldp+122,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_busy));
        bufp->chgBit(oldp+123,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ld_st_flag));
        bufp->chgBit(oldp+124,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ld_st_done));
        bufp->chgBit(oldp+125,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__inst_finished_r));
        bufp->chgQData(oldp+126,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__mul_res),64);
        bufp->chgWData(oldp+128,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__mulu_res),66);
        bufp->chgBit(oldp+131,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__busy_r));
        bufp->chgBit(oldp+132,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__busy_r));
        bufp->chgIData(oldp+133,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_out),32);
        bufp->chgIData(oldp+134,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__quotient_out),32);
        bufp->chgIData(oldp+135,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_rem),32);
        bufp->chgIData(oldp+136,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__divu_rem),32);
        bufp->chgBit(oldp+137,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_busy));
        bufp->chgBit(oldp+138,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__divu_busy));
        bufp->chgCData(oldp+139,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__op_r),5);
        bufp->chgIData(oldp+140,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__a_r),32);
        bufp->chgBit(oldp+141,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_neg_r));
        bufp->chgBit(oldp+142,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__rem_neg_r));
        bufp->chgBit(oldp+143,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_zero_r));
        bufp->chgBit(oldp+144,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_overflow_r));
        bufp->chgIData(oldp+145,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_neg_r)
                                   ? ((IData)(1U) + 
                                      (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_out))
                                   : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_out)),32);
        bufp->chgIData(oldp+146,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__rem_neg_r)
                                   ? ((IData)(1U) + 
                                      (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_rem))
                                   : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_rem)),32);
        bufp->chgIData(oldp+147,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient),32);
        bufp->chgIData(oldp+148,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__dividend),32);
        bufp->chgIData(oldp+149,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__divisor),32);
        bufp->chgQData(oldp+150,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder),33);
        bufp->chgCData(oldp+152,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__count),8);
        bufp->chgQData(oldp+153,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__divisor))),33);
        bufp->chgQData(oldp+155,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift),33);
        bufp->chgQData(oldp+157,((0x1ffffffffULL & 
                                  (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift 
                                   - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__divisor))))),33);
        bufp->chgBit(oldp+159,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__ge_divisor));
        bufp->chgQData(oldp+160,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder_next),33);
        bufp->chgIData(oldp+162,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_next),32);
        bufp->chgIData(oldp+163,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__quotient),32);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__dividend),32);
        bufp->chgIData(oldp+165,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__divisor),32);
        bufp->chgQData(oldp+166,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder),33);
        bufp->chgCData(oldp+168,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__count),8);
        bufp->chgQData(oldp+169,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__divisor))),33);
        bufp->chgQData(oldp+171,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift),33);
        bufp->chgQData(oldp+173,((0x1ffffffffULL & 
                                  (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift 
                                   - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__divisor))))),33);
        bufp->chgBit(oldp+175,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__ge_divisor));
        bufp->chgQData(oldp+176,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder_next),33);
        bufp->chgIData(oldp+178,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__quotient_next),32);
        bufp->chgWData(oldp+179,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__product),66);
        bufp->chgQData(oldp+182,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__x_ext_r),33);
        bufp->chgCData(oldp+184,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__count),8);
        bufp->chgQData(oldp+185,((0x1ffffffffULL & 
                                  (((QData)((IData)(
                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__product[1U])) 
                                                 >> 1U)))),33);
        bufp->chgQData(oldp+187,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__next_high),33);
        bufp->chgWData(oldp+189,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__next_product),66);
        bufp->chgWData(oldp+192,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__product),68);
        bufp->chgQData(oldp+195,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__x_ext_r),34);
        bufp->chgCData(oldp+197,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__count),8);
        bufp->chgQData(oldp+198,((0x3ffffffffULL & 
                                  (((QData)((IData)(
                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                    << 0x1eU) | ((QData)((IData)(
                                                                 vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__product[1U])) 
                                                 >> 2U)))),34);
        bufp->chgQData(oldp+200,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__next_high),34);
        bufp->chgWData(oldp+202,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__next_product),68);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+205,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata),32);
        bufp->chgCData(oldp+206,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r),3);
        bufp->chgCData(oldp+207,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wR_r),5);
        bufp->chgIData(oldp+208,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc_r),32);
        bufp->chgIData(oldp+209,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c_r),32);
        bufp->chgIData(oldp+210,(((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                   ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                       ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din
                                       : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                           ? (0xffffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din)
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din 
                                                              >> 0xfU)))) 
                                               << 0x10U) 
                                              | (0xffffU 
                                                 & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din))))
                                   : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                       ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                           ? (0xffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din)
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | (0xffU 
                                                 & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din)))
                                       : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din))),32);
        bufp->chgIData(oldp+211,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__store_wdata_r),32);
        bufp->chgBit(oldp+212,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rst_r));
        bufp->chgCData(oldp+213,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c_r)),2);
        bufp->chgIData(oldp+214,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din),32);
        bufp->chgIData(oldp+215,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[0]),32);
        bufp->chgIData(oldp+216,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[1]),32);
        bufp->chgIData(oldp+217,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[2]),32);
        bufp->chgIData(oldp+218,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[3]),32);
        bufp->chgIData(oldp+219,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[4]),32);
        bufp->chgIData(oldp+220,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[5]),32);
        bufp->chgIData(oldp+221,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[6]),32);
        bufp->chgIData(oldp+222,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[7]),32);
        bufp->chgIData(oldp+223,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[8]),32);
        bufp->chgIData(oldp+224,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[9]),32);
        bufp->chgIData(oldp+225,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[10]),32);
        bufp->chgIData(oldp+226,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[11]),32);
        bufp->chgIData(oldp+227,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[12]),32);
        bufp->chgIData(oldp+228,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[13]),32);
        bufp->chgIData(oldp+229,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[14]),32);
        bufp->chgIData(oldp+230,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[15]),32);
        bufp->chgIData(oldp+231,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[16]),32);
        bufp->chgIData(oldp+232,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[17]),32);
        bufp->chgIData(oldp+233,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[18]),32);
        bufp->chgIData(oldp+234,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[19]),32);
        bufp->chgIData(oldp+235,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[20]),32);
        bufp->chgIData(oldp+236,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[21]),32);
        bufp->chgIData(oldp+237,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[22]),32);
        bufp->chgIData(oldp+238,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[23]),32);
        bufp->chgIData(oldp+239,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[24]),32);
        bufp->chgIData(oldp+240,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[25]),32);
        bufp->chgIData(oldp+241,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[26]),32);
        bufp->chgIData(oldp+242,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[27]),32);
        bufp->chgIData(oldp+243,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[28]),32);
        bufp->chgIData(oldp+244,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[29]),32);
        bufp->chgIData(oldp+245,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[30]),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+246,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr),32);
        bufp->chgCData(oldp+247,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen),4);
        bufp->chgIData(oldp+248,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata),32);
        bufp->chgSData(oldp+249,((0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                                             >> 2U))),16);
        bufp->chgIData(oldp+250,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc),32);
        bufp->chgIData(oldp+251,(((IData)(4U) + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc)),32);
    }
    bufp->chgBit(oldp+252,(vlSelfRef.fpga_clk));
    bufp->chgBit(oldp+253,(vlSelfRef.fpga_rst));
    bufp->chgSData(oldp+254,(vlSelfRef.sw),16);
    bufp->chgSData(oldp+255,(vlSelfRef.led),16);
    bufp->chgCData(oldp+256,(vlSelfRef.dig_en),8);
    bufp->chgCData(oldp+257,(vlSelfRef.dig_seg),8);
    bufp->chgCData(oldp+258,(vlSelfRef.dig_seg1),8);
    bufp->chgBit(oldp+259,(vlSelfRef.rx));
    bufp->chgBit(oldp+260,(vlSelfRef.tx));
    bufp->chgBit(oldp+261,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req));
    bufp->chgIData(oldp+262,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr),32);
    bufp->chgIData(oldp+263,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__douta),32);
    bufp->chgBit(oldp+264,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid));
    bufp->chgIData(oldp+265,(((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op))
                               ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op))
                                   ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc 
                                      + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext)
                                   : (((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                 >> 4U))) 
                                       && ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                  >> 3U)) 
                                           && ((4U 
                                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                ? (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                        >> 1U))) 
                                                   && ((1U 
                                                        & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                        ? 
                                                       (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                        >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                        : 
                                                       (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                        < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                     ? 
                                                    VL_GTES_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                     : 
                                                    VL_LTS_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                     ? 
                                                    (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                     != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                     : 
                                                    (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                     == vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))))))
                                       ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc 
                                          + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext)
                                       : ((IData)(4U) 
                                          + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc)))
                               : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op))
                                   ? (0xfffffffeU & 
                                      (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_rd1 
                                       + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext))
                                   : ((IData)(4U) + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc)))),32);
    bufp->chgIData(oldp+266,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid)
                               ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__douta
                               : 0x13U)),32);
    bufp->chgBit(oldp+267,(((~ (IData)(vlSelfRef.fpga_rst)) 
                            & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rst_r))));
    bufp->chgIData(oldp+268,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_pc),32);
    bufp->chgBit(oldp+269,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_we));
    bufp->chgCData(oldp+270,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wR),5);
    bufp->chgIData(oldp+271,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wD),32);
    bufp->chgIData(oldp+272,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_pc),32);
    bufp->chgCData(oldp+273,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_we),4);
    bufp->chgIData(oldp+274,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_waddr),32);
    bufp->chgIData(oldp+275,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_wdata),32);
    bufp->chgBit(oldp+276,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka));
    bufp->chgSData(oldp+277,((0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr 
                                         >> 2U))),16);
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
}
