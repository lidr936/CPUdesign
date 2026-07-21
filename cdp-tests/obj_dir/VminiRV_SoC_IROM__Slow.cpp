// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_IROM.h"
#include "VminiRV_SoC__Syms.h"

void VminiRV_SoC_IROM___ctor_var_reset(VminiRV_SoC_IROM* vlSelf);

VminiRV_SoC_IROM::VminiRV_SoC_IROM(VminiRV_SoC__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VminiRV_SoC_IROM___ctor_var_reset(this);
}

void VminiRV_SoC_IROM::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VminiRV_SoC_IROM::~VminiRV_SoC_IROM() {
}
