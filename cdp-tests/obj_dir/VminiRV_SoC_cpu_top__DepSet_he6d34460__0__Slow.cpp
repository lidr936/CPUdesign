// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_cpu_top.h"

VL_ATTR_COLD void VminiRV_SoC_cpu_top___ctor_var_reset(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__cpu_clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dc2cpu_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dc2cpu_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dc2cpu_wresp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_dram__DOT__U_dram__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_dram__DOT__U_dram__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_dram__DOT__U_dram__DOT__mem_file = 0;
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__U_dram__DOT__U_dram__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__U_dram__DOT__U_dram__DOT__mem_rd[__Vi0] = VL_RAND_RESET_I(32);
    }
}
