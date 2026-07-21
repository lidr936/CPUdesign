// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_cpu_core.h"

VL_INLINE_OPT void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__U_rf__DOT__regs__v0;
    __VdlyVal__U_rf__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__U_rf__DOT__regs__v0;
    __VdlyDim0__U_rf__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__U_rf__DOT__regs__v0;
    __VdlySet__U_rf__DOT__regs__v0 = 0;
    // Body
    __VdlySet__U_rf__DOT__regs__v0 = 0U;
    if (((IData)(vlSelfRef.debug_wb_rf_we) & (0U != (IData)(vlSelfRef.__PVT__mem_wb_rd)))) {
        vlSelfRef.U_rf__DOT____Vlvbound_h55e9dbd1__0 
            = vlSelfRef.__PVT__mem_wb_data;
        if ((0x1eU >= (0x1fU & ((IData)(vlSelfRef.__PVT__mem_wb_rd) 
                                - (IData)(1U))))) {
            __VdlyVal__U_rf__DOT__regs__v0 = vlSelfRef.U_rf__DOT____Vlvbound_h55e9dbd1__0;
            __VdlyDim0__U_rf__DOT__regs__v0 = (0x1fU 
                                               & ((IData)(vlSelfRef.__PVT__mem_wb_rd) 
                                                  - (IData)(1U)));
            __VdlySet__U_rf__DOT__regs__v0 = 1U;
        }
    }
    if (__VdlySet__U_rf__DOT__regs__v0) {
        vlSelfRef.__PVT__U_rf__DOT__regs[__VdlyDim0__U_rf__DOT__regs__v0] 
            = __VdlyVal__U_rf__DOT__regs__v0;
    }
}
