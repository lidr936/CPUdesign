// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_Inst_ROM.h"

VL_ATTR_COLD void VminiRV_SoC_Inst_ROM___ctor_var_reset(VminiRV_SoC_Inst_ROM* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_Inst_ROM___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__cpu_clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inst_rreq = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inst_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__inst_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__inst_out = VL_RAND_RESET_I(32);
}
