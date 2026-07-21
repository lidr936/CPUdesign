// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC_miniRV_SoC.h"

VL_INLINE_OPT void VminiRV_SoC_miniRV_SoC___nba_sequent__TOP__miniRV_SoC__0(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___nba_sequent__TOP__miniRV_SoC__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v0 = 0U;
    vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v1 = 0U;
    vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v2 = 0U;
    vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v3 = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__i = 4U;
    if ((((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__mem_wr_en) 
          & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_strb_r)) 
         & (0xffffU != (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                        >> 0x10U)))) {
        vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v0 
            = (0xffU & vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_data_r);
        vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v0 
            = (0x1fffU & (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                          >> 2U));
        vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v0 = 1U;
    }
    if ((((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__mem_wr_en) 
          & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_strb_r) 
             >> 1U)) & (0xffffU != (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                                    >> 0x10U)))) {
        vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v1 
            = (0xffU & (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_data_r 
                        >> 8U));
        vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v1 
            = (0x1fffU & (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                          >> 2U));
        vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v1 = 1U;
    }
    if ((((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__mem_wr_en) 
          & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_strb_r) 
             >> 2U)) & (0xffffU != (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                                    >> 0x10U)))) {
        vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v2 
            = (0xffU & (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_data_r 
                        >> 0x10U));
        vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v2 
            = (0x1fffU & (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                          >> 2U));
        vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v2 = 1U;
    }
    if ((((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__mem_wr_en) 
          & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_strb_r) 
             >> 3U)) & (0xffffU != (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                                    >> 0x10U)))) {
        vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v3 
            = (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_data_r 
               >> 0x18U);
        vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v3 
            = (0x1fffU & (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                          >> 2U));
        vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v3 = 1U;
    }
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bid_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bid_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_id_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_id_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_id_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_id_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_burst_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_burst_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_size_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_size_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_burst_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_burst_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_size_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_size_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_count_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_count_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_count_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_count_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_state_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_state_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next;
    if ((1U & ((~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg)) 
               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_rready)))) {
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_pipe_reg 
            = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_reg;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rdata_pipe_reg 
            = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rdata_reg;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_pipe_reg 
            = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_reg;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg 
            = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg;
    }
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__U_trace_bram__DOT__read_state_reg = 0U;
        vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg = 0U;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg = 0U;
    }
    vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_next;
}

VL_INLINE_OPT void VminiRV_SoC_miniRV_SoC___nba_sequent__TOP__miniRV_SoC__1(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___nba_sequent__TOP__miniRV_SoC__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_next;
    if (vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd_en) {
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rdata_reg 
            = vlSelfRef.__PVT__U_trace_bram__DOT__mem
            [(0x1fffU & (vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_reg 
                         >> 2U))];
    }
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_next;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_next;
    if (vlSymsp->TOP.fpga_rst) {
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_reg = 0U;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg = 0U;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg = 0U;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_reg = 0U;
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_reg = 0U;
    }
    if (vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v0) {
        vlSelfRef.__PVT__U_trace_bram__DOT__mem[vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.__PVT__U_trace_bram__DOT__mem
                [vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v0]) 
               | (IData)(vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v0));
    }
    if (vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v1) {
        vlSelfRef.__PVT__U_trace_bram__DOT__mem[vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.__PVT__U_trace_bram__DOT__mem
                [vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v1]) 
               | ((IData)(vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v1) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v2) {
        vlSelfRef.__PVT__U_trace_bram__DOT__mem[vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.__PVT__U_trace_bram__DOT__mem
                [vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v2]) 
               | ((IData)(vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v2) 
                  << 0x10U));
    }
    if (vlSelfRef.__VdlySet__U_trace_bram__DOT__mem__v3) {
        vlSelfRef.__PVT__U_trace_bram__DOT__mem[vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v3] 
            = ((0xffffffU & vlSelfRef.__PVT__U_trace_bram__DOT__mem
                [vlSelfRef.__VdlyDim0__U_trace_bram__DOT__mem__v3]) 
               | ((IData)(vlSelfRef.__VdlyVal__U_trace_bram__DOT__mem__v3) 
                  << 0x18U));
    }
    vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_reg 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_next;
}

VL_INLINE_OPT void VminiRV_SoC_miniRV_SoC___nba_comb__TOP__miniRV_SoC__0(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___nba_comb__TOP__miniRV_SoC__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__U_trace_bram__DOT__read_id_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_id_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_size_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_size_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_burst_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_burst_reg;
    if ((1U & (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__read_state_reg)))) {
        if (((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_reg) 
             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_arvalid))) {
            vlSelfRef.__PVT__U_trace_bram__DOT__read_id_next = 0U;
            vlSelfRef.__PVT__U_trace_bram__DOT__read_size_next = 2U;
            vlSelfRef.__PVT__U_trace_bram__DOT__read_burst_next = 1U;
        }
    }
    vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd_en = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_next 
        = ((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg) 
           & (~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_rready)));
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_next = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_state_next = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_count_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_count_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_burst_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_burst_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_id_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_id_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_size_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_size_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__mem_wr_en = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_next = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_count_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_count_reg;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_next 
        = ((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg) 
           & (~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready)));
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_next = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bid_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bid_reg;
    if ((0U != (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg))) {
        if ((1U == (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg))) {
            if (((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_reg) 
                 & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_wvalid))) {
                vlSelfRef.__PVT__U_trace_bram__DOT__mem_wr_en = 1U;
                if ((0U >= (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_count_reg))) {
                    if ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready) 
                               | (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg))))) {
                        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_next = 1U;
                        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bid_next 
                            = vlSelfRef.__PVT__U_trace_bram__DOT__write_id_reg;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg))) {
            if ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready) 
                       | (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg))))) {
                vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_next = 1U;
                vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bid_next 
                    = vlSelfRef.__PVT__U_trace_bram__DOT__write_id_reg;
            }
        }
    }
    vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg;
    if ((0U == (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg))) {
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_next = 1U;
        if (((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_reg) 
             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_awvalid))) {
            vlSelfRef.__PVT__U_trace_bram__DOT__write_burst_next = 1U;
            vlSelfRef.__PVT__U_trace_bram__DOT__write_id_next = 0U;
            vlSelfRef.__PVT__U_trace_bram__DOT__write_size_next = 2U;
            vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_next = 1U;
            vlSelfRef.__PVT__U_trace_bram__DOT__write_count_next = 0U;
            vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_next = 0U;
            vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next = 1U;
            vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_next 
                = vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_addr_r;
        } else {
            vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next = 0U;
        }
    } else if ((1U == (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg))) {
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_next = 1U;
        if (((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_reg) 
             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_wvalid))) {
            if ((0U >= (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_count_reg))) {
                vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_next = 0U;
                if ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready) 
                           | (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg))))) {
                    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_next = 1U;
                }
            }
            vlSelfRef.__PVT__U_trace_bram__DOT__write_count_next 
                = (0xffU & ((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_count_reg) 
                            - (IData)(1U)));
            vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next 
                = ((0U < (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_count_reg))
                    ? 1U : ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready) 
                                   | (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg))))
                             ? 0U : 2U));
            if ((0U != (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_burst_reg))) {
                vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_next 
                    = (vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg 
                       + ((IData)(1U) << (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_size_reg)));
            }
        } else {
            vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next = 1U;
        }
    } else if ((2U == (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg))) {
        if ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready) 
                   | (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg))))) {
            vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_next = 1U;
            vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next = 0U;
        } else {
            vlSelfRef.__PVT__U_trace_bram__DOT__write_state_next = 2U;
        }
    }
    vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_next 
        = vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_reg;
    if (vlSelfRef.__PVT__U_trace_bram__DOT__read_state_reg) {
        if (vlSelfRef.__PVT__U_trace_bram__DOT__read_state_reg) {
            if ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_rready) 
                       | (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg))))) {
                vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd_en = 1U;
                vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_next = 1U;
                vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_next 
                    = vlSelfRef.__PVT__U_trace_bram__DOT__read_id_reg;
                vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_next 
                    = (0U == (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__read_count_reg));
                if ((0U >= (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__read_count_reg))) {
                    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_next = 1U;
                }
                vlSelfRef.__PVT__U_trace_bram__DOT__read_count_next 
                    = (0xffU & ((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__read_count_reg) 
                                - (IData)(1U)));
                if ((0U != (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__read_burst_reg))) {
                    vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_next 
                        = (vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_reg 
                           + ((IData)(1U) << (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__read_size_reg)));
                }
            }
            vlSelfRef.__PVT__U_trace_bram__DOT__read_state_next 
                = ((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_rready) 
                             | (~ (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg))))) 
                   || (0U < (IData)(vlSelfRef.__PVT__U_trace_bram__DOT__read_count_reg)));
        }
    } else {
        vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_next = 1U;
        if (((IData)(vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_reg) 
             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_arvalid))) {
            vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_next = 0U;
            vlSelfRef.__PVT__U_trace_bram__DOT__read_count_next 
                = vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_len_r;
            vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_next 
                = vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_addr_r;
            vlSelfRef.__PVT__U_trace_bram__DOT__read_state_next = 1U;
        } else {
            vlSelfRef.__PVT__U_trace_bram__DOT__read_state_next = 0U;
        }
    }
}
