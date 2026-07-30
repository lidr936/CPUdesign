// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_cpu_core.h"

VL_INLINE_OPT void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4(VminiRV_SoC_cpu_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ifetch_addr = vlSelfRef.__PVT__pc;
}
