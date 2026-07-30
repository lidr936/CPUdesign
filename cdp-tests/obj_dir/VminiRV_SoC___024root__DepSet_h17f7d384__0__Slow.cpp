// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC___024root.h"

VL_ATTR_COLD void VminiRV_SoC___024root___eval_static(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VminiRV_SoC___024root___eval_final(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VminiRV_SoC___024root___eval_phase__stl(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD void VminiRV_SoC___024root___eval_settle(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VminiRV_SoC___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("mySoC/miniRV_SoC.v", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VminiRV_SoC___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__stl(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VminiRV_SoC___024root___eval_triggers__stl(VminiRV_SoC___024root* vlSelf);
VL_ATTR_COLD void VminiRV_SoC___024root___eval_stl(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD bool VminiRV_SoC___024root___eval_phase__stl(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VminiRV_SoC___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VminiRV_SoC___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__ico(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__act(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge fpga_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge fpga_rst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge miniRV_SoC.U_cpu.U_irom.U_irom.clka)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__nba(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge fpga_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge fpga_rst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge miniRV_SoC.U_cpu.U_irom.U_irom.clka)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VminiRV_SoC___024root____Vm_traceActivitySetAll(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
}

VL_ATTR_COLD void VminiRV_SoC___024root___ctor_var_reset(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->fpga_clk = VL_RAND_RESET_I(1);
    vlSelf->fpga_rst = VL_RAND_RESET_I(1);
    vlSelf->sw = VL_RAND_RESET_I(16);
    vlSelf->led = VL_RAND_RESET_I(16);
    vlSelf->dig_en = VL_RAND_RESET_I(8);
    vlSelf->dig_seg = VL_RAND_RESET_I(8);
    vlSelf->dig_seg1 = VL_RAND_RESET_I(8);
    vlSelf->rx = VL_RAND_RESET_I(1);
    vlSelf->tx = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__fpga_rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
