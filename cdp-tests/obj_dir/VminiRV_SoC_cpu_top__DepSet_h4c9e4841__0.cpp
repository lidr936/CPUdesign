// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC_cpu_top.h"

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__dc2cpu_wresp = ((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                                     & (0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen)));
    vlSelfRef.__PVT__dc2cpu_valid = ((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                                     & (0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren)));
}

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__1(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v0;
    __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v0;
    __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__U_dram__DOT__U_dram__DOT__mem__v0;
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v1;
    __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v1 = 0;
    SData/*15:0*/ __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v1;
    __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__U_dram__DOT__U_dram__DOT__mem__v1;
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v2;
    __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v2 = 0;
    SData/*15:0*/ __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v2;
    __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__U_dram__DOT__U_dram__DOT__mem__v2;
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v3;
    __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v3 = 0;
    SData/*15:0*/ __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v3;
    __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__U_dram__DOT__U_dram__DOT__mem__v3;
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v3 = 0;
    // Body
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v0 = 0U;
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v1 = 0U;
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v2 = 0U;
    __VdlySet__U_dram__DOT__U_dram__DOT__mem__v3 = 0U;
    if ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))) {
        __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v0 
            = (0xffU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata);
        __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v0 
            = (0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                          >> 2U));
        __VdlySet__U_dram__DOT__U_dram__DOT__mem__v0 = 1U;
    }
    if ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))) {
        __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v1 
            = (0xffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata 
                        >> 8U));
        __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v1 
            = (0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                          >> 2U));
        __VdlySet__U_dram__DOT__U_dram__DOT__mem__v1 = 1U;
    }
    if ((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))) {
        __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v2 
            = (0xffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata 
                        >> 0x10U));
        __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v2 
            = (0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                          >> 2U));
        __VdlySet__U_dram__DOT__U_dram__DOT__mem__v2 = 1U;
    }
    if ((8U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))) {
        __VdlyVal__U_dram__DOT__U_dram__DOT__mem__v3 
            = (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata 
               >> 0x18U);
        __VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v3 
            = (0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                          >> 2U));
        __VdlySet__U_dram__DOT__U_dram__DOT__mem__v3 = 1U;
    }
    vlSelfRef.__PVT__dc2cpu_rdata = (((((8U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))
                                         ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata 
                                            >> 0x18U)
                                         : (vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                                            [(0xffffU 
                                              & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                                                 >> 2U))] 
                                            >> 0x18U)) 
                                       << 0x18U) | 
                                      (0xff0000U & 
                                       (((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))
                                          ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata 
                                             >> 0x10U)
                                          : (vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                                             [(0xffffU 
                                               & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                                                  >> 2U))] 
                                             >> 0x10U)) 
                                        << 0x10U))) 
                                     | ((0xff00U & 
                                         (((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))
                                            ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata 
                                               >> 8U)
                                            : (vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                                               [(0xffffU 
                                                 & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                                                    >> 2U))] 
                                               >> 8U)) 
                                          << 8U)) | 
                                        (0xffU & ((1U 
                                                   & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))
                                                   ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata
                                                   : 
                                                  vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                                                  [
                                                  (0xffffU 
                                                   & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                                                      >> 2U))]))));
    if (__VdlySet__U_dram__DOT__U_dram__DOT__mem__v0) {
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem[__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                [__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v0]) 
               | (IData)(__VdlyVal__U_dram__DOT__U_dram__DOT__mem__v0));
    }
    if (__VdlySet__U_dram__DOT__U_dram__DOT__mem__v1) {
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem[__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                [__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v1]) 
               | ((IData)(__VdlyVal__U_dram__DOT__U_dram__DOT__mem__v1) 
                  << 8U));
    }
    if (__VdlySet__U_dram__DOT__U_dram__DOT__mem__v2) {
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem[__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                [__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v2]) 
               | ((IData)(__VdlyVal__U_dram__DOT__U_dram__DOT__mem__v2) 
                  << 0x10U));
    }
    if (__VdlySet__U_dram__DOT__U_dram__DOT__mem__v3) {
        vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem[__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v3] 
            = ((0xffffffU & vlSelfRef.__PVT__U_dram__DOT__U_dram__DOT__mem
                [__VdlyDim0__U_dram__DOT__U_dram__DOT__mem__v3]) 
               | ((IData)(__VdlyVal__U_dram__DOT__U_dram__DOT__mem__v3) 
                  << 0x18U));
    }
}

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid 
        = vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom.__PVT__inst_valid;
}
