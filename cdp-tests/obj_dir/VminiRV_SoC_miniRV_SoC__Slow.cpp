// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC_miniRV_SoC.h"

void VminiRV_SoC_miniRV_SoC___ctor_var_reset(VminiRV_SoC_miniRV_SoC* vlSelf);

VminiRV_SoC_miniRV_SoC::VminiRV_SoC_miniRV_SoC(VminiRV_SoC__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VminiRV_SoC_miniRV_SoC___ctor_var_reset(this);
}

void VminiRV_SoC_miniRV_SoC::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VminiRV_SoC_miniRV_SoC::~VminiRV_SoC_miniRV_SoC() {
}
