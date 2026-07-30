// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_miniRV_SoC.h"

VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___ctor_var_reset(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___ctor_var_reset\n"); );
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
}
