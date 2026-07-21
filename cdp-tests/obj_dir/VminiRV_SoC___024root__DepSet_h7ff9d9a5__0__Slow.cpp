// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC___024root.h"

VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___eval_static__TOP__miniRV_SoC(VminiRV_SoC_miniRV_SoC* vlSelf);
VL_ATTR_COLD void VminiRV_SoC___024root____Vm_traceActivitySetAll(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_static(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VminiRV_SoC_miniRV_SoC___eval_static__TOP__miniRV_SoC((&vlSymsp->TOP__miniRV_SoC));
    VminiRV_SoC___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void VminiRV_SoC___024root___eval_initial__TOP(VminiRV_SoC___024root* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___eval_initial__TOP__miniRV_SoC(VminiRV_SoC_miniRV_SoC* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_initial(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VminiRV_SoC___024root___eval_initial__TOP(vlSelf);
    VminiRV_SoC___024root____Vm_traceActivitySetAll(vlSelf);
    VminiRV_SoC_miniRV_SoC___eval_initial__TOP__miniRV_SoC((&vlSymsp->TOP__miniRV_SoC));
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__0 = vlSelfRef.fpga_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__0 = vlSelfRef.fpga_rst;
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

VL_ATTR_COLD void VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___stl_sequent__TOP__miniRV_SoC__0(VminiRV_SoC_miniRV_SoC* vlSelf);
VL_ATTR_COLD void VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__1(VminiRV_SoC_cpu_top* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_stl(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__0((&vlSymsp->TOP__miniRV_SoC__U_cpu));
        VminiRV_SoC___024root____Vm_traceActivitySetAll(vlSelf);
        VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
        VminiRV_SoC_miniRV_SoC___stl_sequent__TOP__miniRV_SoC__0((&vlSymsp->TOP__miniRV_SoC));
        VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__1((&vlSymsp->TOP__miniRV_SoC__U_cpu));
    }
}
