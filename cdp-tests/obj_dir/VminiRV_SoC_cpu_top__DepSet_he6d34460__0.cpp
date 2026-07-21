// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_cpu_top.h"

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<5>/*150:0*/ __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0;
    VL_ZERO_W(151, __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0);
    CData/*5:0*/ __VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0;
    __VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__U_icache__DOT__U_isram__DOT__mem__v0;
    __VdlySet__U_icache__DOT__U_isram__DOT__mem__v0 = 0;
    VlWide<5>/*150:0*/ __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0;
    VL_ZERO_W(151, __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0);
    CData/*5:0*/ __VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0;
    __VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__U_dcache__DOT__U_dsram__DOT__mem__v0;
    __VdlySet__U_dcache__DOT__U_dsram__DOT__mem__v0 = 0;
    // Body
    __VdlySet__U_icache__DOT__U_isram__DOT__mem__v0 = 0U;
    __VdlySet__U_dcache__DOT__U_dsram__DOT__mem__v0 = 0U;
    if (vlSelfRef.__PVT__U_icache__DOT__cache_we) {
        __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[0U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[0U];
        __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[1U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[1U];
        __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[2U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[2U];
        __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[3U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[3U];
        __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[4U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[4U];
        __VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0 
            = vlSelfRef.__PVT__U_icache__DOT__cache_index;
        __VdlySet__U_icache__DOT__U_isram__DOT__mem__v0 = 1U;
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[0U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[0U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[1U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[1U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[2U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[2U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[3U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[3U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[4U] 
            = vlSelfRef.__PVT__U_icache__DOT__cache_line_w[4U];
    } else {
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[0U] 
            = vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem
            [vlSelfRef.__PVT__U_icache__DOT__cache_index][0U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[1U] 
            = vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem
            [vlSelfRef.__PVT__U_icache__DOT__cache_index][1U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[2U] 
            = vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem
            [vlSelfRef.__PVT__U_icache__DOT__cache_index][2U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[3U] 
            = vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem
            [vlSelfRef.__PVT__U_icache__DOT__cache_index][3U];
        vlSelfRef.__PVT__U_icache__DOT__cache_line_r[4U] 
            = vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem
            [vlSelfRef.__PVT__U_icache__DOT__cache_index][4U];
    }
    if (vlSelfRef.__PVT__U_dcache__DOT__cache_we) {
        __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[0U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[0U];
        __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[1U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[1U];
        __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[2U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[2U];
        __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[3U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[3U];
        __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[4U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[4U];
        __VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_index;
        __VdlySet__U_dcache__DOT__U_dsram__DOT__mem__v0 = 1U;
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[0U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[0U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[1U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[1U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[2U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[2U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[3U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[3U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[4U] 
            = vlSelfRef.__PVT__U_dcache__DOT__cache_line_w[4U];
    } else {
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[0U] 
            = vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem
            [vlSelfRef.__PVT__U_dcache__DOT__cache_index][0U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[1U] 
            = vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem
            [vlSelfRef.__PVT__U_dcache__DOT__cache_index][1U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[2U] 
            = vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem
            [vlSelfRef.__PVT__U_dcache__DOT__cache_index][2U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[3U] 
            = vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem
            [vlSelfRef.__PVT__U_dcache__DOT__cache_index][3U];
        vlSelfRef.__PVT__U_dcache__DOT__cache_line_r[4U] 
            = vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem
            [vlSelfRef.__PVT__U_dcache__DOT__cache_index][4U];
    }
    if (__VdlySet__U_icache__DOT__U_isram__DOT__mem__v0) {
        vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem[__VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0][0U] 
            = __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[0U];
        vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem[__VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0][1U] 
            = __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[1U];
        vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem[__VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0][2U] 
            = __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[2U];
        vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem[__VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0][3U] 
            = __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[3U];
        vlSelfRef.__PVT__U_icache__DOT__U_isram__DOT__mem[__VdlyDim0__U_icache__DOT__U_isram__DOT__mem__v0][4U] 
            = __VdlyVal__U_icache__DOT__U_isram__DOT__mem__v0[4U];
    }
    if (__VdlySet__U_dcache__DOT__U_dsram__DOT__mem__v0) {
        vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem[__VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0][0U] 
            = __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[0U];
        vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem[__VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0][1U] 
            = __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[1U];
        vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem[__VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0][2U] 
            = __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[2U];
        vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem[__VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0][3U] 
            = __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[3U];
        vlSelfRef.__PVT__U_dcache__DOT__U_dsram__DOT__mem[__VdlyDim0__U_dcache__DOT__U_dsram__DOT__mem__v0][4U] 
            = __VdlyVal__U_dcache__DOT__U_dsram__DOT__mem__v0[4U];
    }
}
