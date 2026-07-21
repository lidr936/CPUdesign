// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC_cpu_top.h"

extern const VlUnpacked<CData/*1:0*/, 32> VminiRV_SoC__ConstPool__TABLE_h0efbdda2_0;

VL_INLINE_OPT void VminiRV_SoC_cpu_top___ico_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___ico_sequent__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelfRef.__PVT__axi2ic_rvalid) 
                     << 4U) | (((IData)(vlSelfRef.__PVT__axi2ic_rrdy) 
                                << 3U) | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req) 
                                           << 2U) | (IData)(vlSelfRef.__PVT__U_icache__DOT__state))));
    vlSelfRef.__PVT__U_icache__DOT__nstat = VminiRV_SoC__ConstPool__TABLE_h0efbdda2_0
        [__Vtableidx1];
}

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__U_axi_master__DOT__read_count 
        = vlSelfRef.__PVT__U_axi_master__DOT__read_count;
    vlSelfRef.__Vdly__U_axi_master__DOT__read_is_data 
        = vlSelfRef.__PVT__U_axi_master__DOT__read_is_data;
    vlSelfRef.__Vdly__U_axi_master__DOT__state = vlSelfRef.__PVT__U_axi_master__DOT__state;
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__ic2cpu_valid = 0U;
        vlSelfRef.__PVT__dc2cpu_wresp = 0U;
        vlSelfRef.__PVT__dc2cpu_valid = 0U;
    } else {
        if ((0U == (IData)(vlSelfRef.__PVT__U_icache__DOT__state))) {
            vlSelfRef.__PVT__ic2cpu_valid = 0U;
        } else if ((1U != (IData)(vlSelfRef.__PVT__U_icache__DOT__state))) {
            vlSelfRef.__PVT__ic2cpu_valid = ((3U == (IData)(vlSelfRef.__PVT__U_icache__DOT__state)) 
                                             && (IData)(vlSelfRef.__PVT__axi2ic_rvalid));
        }
        if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state))) {
            vlSelfRef.__PVT__dc2cpu_wresp = 0U;
        } else if ((1U != (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state))) {
            vlSelfRef.__PVT__dc2cpu_wresp = ((3U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state)) 
                                             && (IData)(vlSelfRef.__PVT__U_dcache__DOT__wr_resp));
        }
        if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
            vlSelfRef.__PVT__dc2cpu_valid = 0U;
        } else if ((1U != (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
            vlSelfRef.__PVT__dc2cpu_valid = ((3U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state)) 
                                             && (IData)(vlSelfRef.__PVT__axi2dc_rvalid));
        }
    }
    if ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst)))) {
        if ((0U != (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
            if ((1U != (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
                if ((3U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
                    vlSelfRef.__PVT__dc2cpu_rdata = 
                        ((IData)(vlSelfRef.__PVT__axi2dc_rvalid)
                          ? vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[0U]
                          : 0U);
                }
            }
        }
    }
}

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid 
        = vlSelfRef.__PVT__ic2cpu_valid;
    if ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst)))) {
        if ((0U != (IData)(vlSelfRef.__PVT__U_icache__DOT__state))) {
            if ((1U != (IData)(vlSelfRef.__PVT__U_icache__DOT__state))) {
                if ((3U == (IData)(vlSelfRef.__PVT__U_icache__DOT__state))) {
                    vlSelfRef.__PVT__ic2cpu_inst = 
                        ((IData)(vlSelfRef.__PVT__axi2ic_rvalid)
                          ? vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[0U]
                          : 0U);
                }
            }
        }
    }
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__Vdly__U_axi_master__DOT__state = 0U;
        vlSelfRef.__Vdly__U_axi_master__DOT__read_is_data = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__write_addr_r = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__write_data_r = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__write_strb_r = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__read_addr_r = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__read_len_r = 0U;
        vlSelfRef.__Vdly__U_axi_master__DOT__read_count = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[0U] = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[1U] = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[2U] = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[3U] = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[0U] = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[1U] = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[2U] = 0U;
        vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[3U] = 0U;
    } else if ((8U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
        if ((4U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 0U;
        } else if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 0U;
        } else if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 0U;
        } else if (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg) {
            if (vlSelfRef.__PVT__U_axi_master__DOT__read_is_data) {
                if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_count))) {
                    if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_count))) {
                        vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[3U] 
                            = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
                    } else {
                        vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[2U] 
                            = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
                    }
                } else if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_count))) {
                    vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[1U] 
                        = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
                } else {
                    vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[0U] 
                        = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
                }
            } else if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_count))) {
                if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_count))) {
                    vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[3U] 
                        = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
                } else {
                    vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[2U] 
                        = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
                }
            } else if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_count))) {
                vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[1U] 
                    = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
            } else {
                vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[0U] 
                    = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
            }
            if (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rlast_reg) {
                vlSelfRef.__Vdly__U_axi_master__DOT__state = 9U;
            } else {
                vlSelfRef.__Vdly__U_axi_master__DOT__read_count 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__U_axi_master__DOT__read_count)));
            }
        }
    } else if ((4U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
        if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                if (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_arready_reg) {
                    vlSelfRef.__Vdly__U_axi_master__DOT__state = 8U;
                }
            } else if (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg) {
                vlSelfRef.__Vdly__U_axi_master__DOT__state = 0U;
            }
        } else if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            if (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_wready_reg) {
                vlSelfRef.__Vdly__U_axi_master__DOT__state = 6U;
            }
        } else if (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_awready_reg) {
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 5U;
        }
    } else if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
        if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            if ((0U != (IData)(vlSelfRef.__PVT__ic2axi_ren))) {
                vlSelfRef.__Vdly__U_axi_master__DOT__read_is_data = 0U;
                vlSelfRef.__PVT__U_axi_master__DOT__read_addr_r 
                    = vlSelfRef.__PVT__ic2axi_addr;
                vlSelfRef.__PVT__U_axi_master__DOT__read_len_r = 0U;
                vlSelfRef.__Vdly__U_axi_master__DOT__read_count = 0U;
                vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[0U] = 0U;
                vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[1U] = 0U;
                vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[2U] = 0U;
                vlSelfRef.__PVT__U_axi_master__DOT__ic_read_buf[3U] = 0U;
                vlSelfRef.__Vdly__U_axi_master__DOT__state = 7U;
            } else {
                vlSelfRef.__Vdly__U_axi_master__DOT__state = 0U;
            }
        } else {
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 3U;
        }
    } else if ((1U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
        if ((0U != (IData)(vlSelfRef.__PVT__dc2axi_wen))) {
            vlSelfRef.__PVT__U_axi_master__DOT__write_addr_r 
                = vlSelfRef.__PVT__dc2axi_waddr;
            vlSelfRef.__PVT__U_axi_master__DOT__write_data_r 
                = vlSelfRef.__PVT__dc2axi_wdata;
            vlSelfRef.__PVT__U_axi_master__DOT__write_strb_r 
                = vlSelfRef.__PVT__dc2axi_wen;
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 4U;
        } else if ((0U != (IData)(vlSelfRef.__PVT__dc2axi_ren))) {
            vlSelfRef.__Vdly__U_axi_master__DOT__read_is_data = 1U;
            vlSelfRef.__PVT__U_axi_master__DOT__read_addr_r 
                = vlSelfRef.__PVT__dc2axi_raddr;
            vlSelfRef.__PVT__U_axi_master__DOT__read_len_r = 0U;
            vlSelfRef.__Vdly__U_axi_master__DOT__read_count = 0U;
            vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[0U] = 0U;
            vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[1U] = 0U;
            vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[2U] = 0U;
            vlSelfRef.__PVT__U_axi_master__DOT__dc_read_buf[3U] = 0U;
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 7U;
        } else {
            vlSelfRef.__Vdly__U_axi_master__DOT__state = 2U;
        }
    } else {
        vlSelfRef.__Vdly__U_axi_master__DOT__state = 1U;
    }
    if ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst)))) {
        if ((0U == (IData)(vlSelfRef.__PVT__U_icache__DOT__state))) {
            vlSelfRef.__PVT__ic2axi_addr = ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req)
                                             ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr
                                             : 0U);
        }
        if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state))) {
            if ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))) {
                vlSelfRef.__PVT__dc2axi_wdata = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mreq_wdata;
                vlSelfRef.__PVT__dc2axi_waddr = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c;
            }
        }
        if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
            if ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren))) {
                vlSelfRef.__PVT__dc2axi_raddr = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c;
            }
        }
    }
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__ic2axi_ren = 0U;
        vlSelfRef.__PVT__dc2axi_ren = 0U;
    } else {
        vlSelfRef.__PVT__ic2axi_ren = ((0U == (IData)(vlSelfRef.__PVT__U_icache__DOT__state))
                                        ? (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req) 
                                            & (IData)(vlSelfRef.__PVT__axi2ic_rrdy))
                                            ? 0xfU : 0U)
                                        : ((1U == (IData)(vlSelfRef.__PVT__U_icache__DOT__state))
                                            ? ((IData)(vlSelfRef.__PVT__axi2ic_rrdy)
                                                ? 0xfU
                                                : 0U)
                                            : 0U));
        if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
            if ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren))) {
                if (vlSelfRef.__PVT__axi2dc_rrdy) {
                    vlSelfRef.__PVT__dc2axi_ren = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren;
                }
            } else {
                vlSelfRef.__PVT__dc2axi_ren = 0U;
            }
        } else {
            vlSelfRef.__PVT__dc2axi_ren = ((1U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))
                                            ? ((IData)(vlSelfRef.__PVT__axi2dc_rrdy)
                                                ? (IData)(vlSelfRef.__PVT__U_dcache__DOT__ren_r)
                                                : 0U)
                                            : 0U);
        }
    }
    if ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst)))) {
        if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state))) {
            if ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__axi2dc_rrdy)))) {
                    vlSelfRef.__PVT__U_dcache__DOT__ren_r 
                        = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren;
                }
            }
        }
    }
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__dc2axi_wen = 0U;
    } else if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state))) {
        if ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))) {
            if (vlSelfRef.__PVT__axi2dc_wrdy) {
                vlSelfRef.__PVT__dc2axi_wen = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen;
            }
        } else {
            vlSelfRef.__PVT__dc2axi_wen = 0U;
        }
    } else {
        vlSelfRef.__PVT__dc2axi_wen = ((1U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state))
                                        ? ((IData)(vlSelfRef.__PVT__axi2dc_wrdy)
                                            ? (IData)(vlSelfRef.__PVT__U_dcache__DOT__wen_r)
                                            : 0U) : 0U);
    }
    if ((1U & (~ (IData)(vlSymsp->TOP.fpga_rst)))) {
        if ((0U == (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state))) {
            if ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__axi2dc_wrdy)))) {
                    vlSelfRef.__PVT__U_dcache__DOT__wen_r 
                        = vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen;
                }
            }
        }
    }
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__U_icache__DOT__state = 0U;
        vlSelfRef.__PVT__U_dcache__DOT__r_state = 0U;
        vlSelfRef.__PVT__U_dcache__DOT__w_state = 0U;
    } else {
        vlSelfRef.__PVT__U_icache__DOT__state = vlSelfRef.__PVT__U_icache__DOT__nstat;
        vlSelfRef.__PVT__U_dcache__DOT__r_state = vlSelfRef.__PVT__U_dcache__DOT__r_nstat;
        vlSelfRef.__PVT__U_dcache__DOT__w_state = vlSelfRef.__PVT__U_dcache__DOT__w_nstat;
    }
    vlSelfRef.__PVT__U_axi_master__DOT__read_count 
        = vlSelfRef.__Vdly__U_axi_master__DOT__read_count;
    vlSelfRef.__PVT__U_axi_master__DOT__read_is_data 
        = vlSelfRef.__Vdly__U_axi_master__DOT__read_is_data;
    vlSelfRef.__PVT__U_axi_master__DOT__state = vlSelfRef.__Vdly__U_axi_master__DOT__state;
    vlSelfRef.__PVT__axi2ic_rvalid = 0U;
    vlSelfRef.__PVT__axi2dc_rvalid = 0U;
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
    vlSelfRef.__PVT__axi2ic_rrdy = 0U;
    vlSelfRef.__PVT__axi2dc_rrdy = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
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
        }
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
    }
}

extern const VlUnpacked<CData/*1:0*/, 256> VminiRV_SoC__ConstPool__TABLE_hef713ec2_0;

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__3(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    __Vtableidx2 = ((((IData)(vlSelfRef.__PVT__axi2dc_rvalid) 
                      << 7U) | ((IData)(vlSelfRef.__PVT__axi2dc_rrdy) 
                                << 6U)) | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren) 
                                            << 2U) 
                                           | (IData)(vlSelfRef.__PVT__U_dcache__DOT__r_state)));
    vlSelfRef.__PVT__U_dcache__DOT__r_nstat = VminiRV_SoC__ConstPool__TABLE_hef713ec2_0
        [__Vtableidx2];
    __Vtableidx1 = (((IData)(vlSelfRef.__PVT__axi2ic_rvalid) 
                     << 4U) | (((IData)(vlSelfRef.__PVT__axi2ic_rrdy) 
                                << 3U) | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req) 
                                           << 2U) | (IData)(vlSelfRef.__PVT__U_icache__DOT__state))));
    vlSelfRef.__PVT__U_icache__DOT__nstat = VminiRV_SoC__ConstPool__TABLE_h0efbdda2_0
        [__Vtableidx1];
}

extern const VlUnpacked<CData/*1:0*/, 512> VminiRV_SoC__ConstPool__TABLE_h30358298_0;

VL_INLINE_OPT void VminiRV_SoC_cpu_top___nba_comb__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___nba_comb__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*8:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    vlSelfRef.__PVT__axi2dc_wrdy = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__U_axi_master__DOT__state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.__PVT__U_axi_master__DOT__state)))) {
                    vlSelfRef.__PVT__axi2dc_wrdy = vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg;
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
    __Vtableidx3 = (((((IData)(vlSelfRef.__PVT__U_dcache__DOT__wr_resp)
                        ? 0U : 3U) << 7U) | ((IData)(vlSelfRef.__PVT__axi2dc_wrdy) 
                                             << 6U)) 
                    | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen) 
                        << 2U) | (IData)(vlSelfRef.__PVT__U_dcache__DOT__w_state)));
    vlSelfRef.__PVT__U_dcache__DOT__w_nstat = VminiRV_SoC__ConstPool__TABLE_h30358298_0
        [__Vtableidx3];
}
