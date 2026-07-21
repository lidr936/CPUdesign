// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC_cpu_top.h"

VL_ATTR_COLD void VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid 
        = vlSelfRef.__PVT__ic2cpu_valid;
    vlSelfRef.__PVT__axi2ic_rrdy = 0U;
    vlSelfRef.__PVT__axi2dc_rrdy = 0U;
    vlSelfRef.__PVT__axi2ic_rvalid = 0U;
    vlSelfRef.__PVT__axi2dc_rvalid = 0U;
    vlSelfRef.__PVT__axi2dc_wrdy = 0U;
    vlSelfRef.__PVT__m_axi_bready = 0U;
    vlSelfRef.__PVT__m_axi_arvalid = 0U;
    vlSelfRef.__PVT__m_axi_rready = 0U;
    if ((8U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
        if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_is_data)))) {
                        vlSelfRef.__PVT__axi2ic_rvalid = 1U;
                    }
                    if (vlSelfRef.__PVT__U_axi_master__DOT__read_is_data) {
                        vlSelfRef.__PVT__axi2dc_rvalid = 1U;
                    }
                }
                if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
                    vlSelfRef.__PVT__m_axi_rready = 1U;
                }
            }
        }
    }
    vlSelfRef.__PVT__m_axi_awvalid = 0U;
    vlSelfRef.__PVT__m_axi_wvalid = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
                    vlSelfRef.__PVT__axi2ic_rrdy = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
                    vlSelfRef.__PVT__axi2dc_rrdy = 1U;
                }
            }
        }
        if ((4U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
                    vlSelfRef.__PVT__axi2dc_wrdy = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg;
                    vlSelfRef.__PVT__m_axi_bready = 1U;
                }
                if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                    vlSelfRef.__PVT__m_axi_arvalid = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
                    vlSelfRef.__PVT__m_axi_awvalid = 1U;
                }
                if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                    vlSelfRef.__PVT__m_axi_wvalid = 1U;
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                             >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
                vlSelfRef.__PVT__axi2dc_wrdy = 1U;
            }
        }
    }
    vlSelfRef.__PVT__U_dcache__DOT__wr_resp = ((IData)(vlSelfRef.__PVT__axi2dc_wrdy) 
                                               & (0U 
                                                  == (IData)(vlSelfRef.__PVT__dc2axi_wen)));
}

extern const VlUnpacked<CData/*1:0*/, 256> VminiRV_SoC__ConstPool__TABLE_hef713ec2_0;
extern const VlUnpacked<CData/*1:0*/, 512> VminiRV_SoC__ConstPool__TABLE_h30358298_0;
extern const VlUnpacked<CData/*1:0*/, 32> VminiRV_SoC__ConstPool__TABLE_h0efbdda2_0;

VL_ATTR_COLD void VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__1(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___stl_sequent__TOP__miniRV_SoC__U_cpu__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    SData/*8:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    __Vtableidx2 = ((((IData)(vlSelfRef.__PVT__axi2dc_rvalid) 
                      << 7U) | ((IData)(vlSelfRef.__PVT__axi2dc_rrdy) 
                                << 6U)) | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren) 
                                            << 2U) 
                                           | (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state)));
    vlSelfRef.__PVT__U_dcache__DOT__r_nstat = VminiRV_SoC__ConstPool__TABLE_hef713ec2_0
        [__Vtableidx2];
    __Vtableidx3 = (((((IData)(vlSelfRef.__PVT__U_dcache__DOT__wr_resp)
                        ? 0U : 3U) << 7U) | ((IData)(vlSelfRef.__PVT__axi2dc_wrdy) 
                                             << 6U)) 
                    | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen) 
                        << 2U) | (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state)));
    vlSelfRef.__PVT__U_dcache__DOT__w_nstat = VminiRV_SoC__ConstPool__TABLE_h30358298_0
        [__Vtableidx3];
    __Vtableidx1 = (((IData)(vlSelfRef.__PVT__axi2ic_rvalid) 
                     << 4U) | (((IData)(vlSelfRef.__PVT__axi2ic_rrdy) 
                                << 3U) | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req) 
                                           << 2U) | (IData)(vlSelfRef.__PVT__U_icache__DOT__state))));
    vlSelfRef.__PVT__U_icache__DOT__nstat = VminiRV_SoC__ConstPool__TABLE_h0efbdda2_0
        [__Vtableidx1];
}
