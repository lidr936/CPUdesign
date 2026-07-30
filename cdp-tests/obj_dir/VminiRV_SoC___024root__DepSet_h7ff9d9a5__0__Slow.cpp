// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC___024root.h"

VL_ATTR_COLD void VminiRV_SoC_cpu_top___eval_initial__TOP__miniRV_SoC__U_cpu(VminiRV_SoC_cpu_top* vlSelf);
VL_ATTR_COLD void VminiRV_SoC___024root____Vm_traceActivitySetAll(VminiRV_SoC___024root* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom(VminiRV_SoC_IROM* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_initial(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VminiRV_SoC_cpu_top___eval_initial__TOP__miniRV_SoC__U_cpu((&vlSymsp->TOP__miniRV_SoC__U_cpu));
    VminiRV_SoC___024root____Vm_traceActivitySetAll(vlSelf);
    VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom));
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__0 = vlSelfRef.fpga_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__0 = vlSelfRef.fpga_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0 
        = vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VminiRV_SoC___024root___eval_triggers__stl(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void VminiRV_SoC___024root___stl_sequent__TOP__0(VminiRV_SoC___024root* vlSelf);
void VminiRV_SoC_Inst_ROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC_Inst_ROM* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2(VminiRV_SoC_cpu_top* vlSelf);
void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_stl(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VminiRV_SoC___024root___stl_sequent__TOP__0(vlSelf);
        VminiRV_SoC___024root____Vm_traceActivitySetAll(vlSelf);
        VminiRV_SoC_Inst_ROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom));
        VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2((&vlSymsp->TOP__miniRV_SoC__U_cpu));
        VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
    }
}

VL_ATTR_COLD void VminiRV_SoC___024root___stl_sequent__TOP__0(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tx = vlSymsp->TOP__miniRV_SoC.tx;
    vlSelfRef.dig_seg1 = vlSymsp->TOP__miniRV_SoC.dig_seg1;
    vlSelfRef.dig_seg = vlSymsp->TOP__miniRV_SoC.dig_seg;
    vlSelfRef.dig_en = vlSymsp->TOP__miniRV_SoC.dig_en;
    vlSelfRef.led = vlSymsp->TOP__miniRV_SoC.led;
}
