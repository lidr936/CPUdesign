// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_IROM.h"

VL_ATTR_COLD void VminiRV_SoC_IROM___ctor_var_reset(VminiRV_SoC_IROM* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_IROM___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clka = VL_RAND_RESET_I(1);
    vlSelf->__PVT__addra = VL_RAND_RESET_I(16);
    vlSelf->__PVT__douta = VL_RAND_RESET_I(32);
    vlSelf->__PVT__i = VL_RAND_RESET_I(32);
    vlSelf->__PVT__j = VL_RAND_RESET_I(32);
    vlSelf->__PVT__mem_file = 0;
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->__PVT__mem_rd[__Vi0] = VL_RAND_RESET_I(32);
    }
}
