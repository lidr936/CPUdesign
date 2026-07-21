// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_Inst_ROM.h"
#include "VminiRV_SoC__Syms.h"

VL_INLINE_OPT void VminiRV_SoC_Inst_ROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC_Inst_ROM* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_Inst_ROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka 
        = vlSymsp->TOP.fpga_clk;
}

VL_INLINE_OPT void VminiRV_SoC_Inst_ROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC_Inst_ROM* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_Inst_ROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__inst_valid = ((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                                   & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req));
}
