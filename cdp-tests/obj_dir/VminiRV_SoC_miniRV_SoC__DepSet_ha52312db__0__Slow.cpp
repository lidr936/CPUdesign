// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC_miniRV_SoC.h"

VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___eval_initial__TOP__miniRV_SoC(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___eval_initial__TOP__miniRV_SoC\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_3;
    // Body
    vlSelfRef.__PVT__U_trace_bram__DOT__i = 0U;
    while (VL_GTS_III(32, 0x2000U, vlSelfRef.__PVT__U_trace_bram__DOT__i)) {
        vlSelfRef.__PVT__U_trace_bram__DOT__j = vlSelfRef.__PVT__U_trace_bram__DOT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__U_trace_bram__DOT__j, 
                          ((IData)(0x40U) + vlSelfRef.__PVT__U_trace_bram__DOT__i))) {
            vlSelfRef.__PVT__U_trace_bram__DOT__mem[(0x1fffU 
                                                     & vlSelfRef.__PVT__U_trace_bram__DOT__j)] = 0U;
            vlSelfRef.__PVT__U_trace_bram__DOT__j = 
                ((IData)(1U) + vlSelfRef.__PVT__U_trace_bram__DOT__j);
        }
        vlSelfRef.__PVT__U_trace_bram__DOT__i = ((IData)(0x40U) 
                                                 + vlSelfRef.__PVT__U_trace_bram__DOT__i);
    }
    __Vtemp_3[0U] = 0x2e62696eU;
    __Vtemp_3[1U] = 0x696e6974U;
    __Vtemp_3[2U] = 0x6d656dU;
    vlSelfRef.__PVT__U_trace_bram__DOT__mem_file = VL_FOPEN_NN(
                                                               VL_CVT_PACK_STR_NW(3, __Vtemp_3)
                                                               , 
                                                               std::string{"r"});
    ;
    if (VL_UNLIKELY((0U == vlSelfRef.__PVT__U_trace_bram__DOT__mem_file))) {
        VL_WRITEF_NX("[ERROR] Open file meminit.bin failed, please check whether file exists!\n\n[%0t] %%Fatal: bram_axi.v:186: Assertion failed in %NminiRV_SoC.U_trace_bram\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("vsrc/bram_axi.v", 186, "", false);
    }
    VL_WRITEF_NX("[INFO] Instruction ROM initialized with meminit.bin\n",0);
    (void)VL_FREAD_I(32,0,8192, &(vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd)
                     , vlSelfRef.__PVT__U_trace_bram__DOT__mem_file
                     , 0, 8192);
    vlSelfRef.__PVT__U_trace_bram__DOT__i = 0U;
    while (VL_GTS_III(32, 0x2000U, vlSelfRef.__PVT__U_trace_bram__DOT__i)) {
        vlSelfRef.__PVT__U_trace_bram__DOT__j = vlSelfRef.__PVT__U_trace_bram__DOT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__U_trace_bram__DOT__j, 
                          ((IData)(0x40U) + vlSelfRef.__PVT__U_trace_bram__DOT__i))) {
            vlSelfRef.__PVT__U_trace_bram__DOT__mem[(0x1fffU 
                                                     & vlSelfRef.__PVT__U_trace_bram__DOT__j)] 
                = (((vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd
                     [(0x1fffU & vlSelfRef.__PVT__U_trace_bram__DOT__j)] 
                     << 0x18U) | (0xff0000U & (vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd
                                               [(0x1fffU 
                                                 & vlSelfRef.__PVT__U_trace_bram__DOT__j)] 
                                               << 8U))) 
                   | ((0xff00U & (vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd
                                  [(0x1fffU & vlSelfRef.__PVT__U_trace_bram__DOT__j)] 
                                  >> 8U)) | (vlSelfRef.__PVT__U_trace_bram__DOT__mem_rd
                                             [(0x1fffU 
                                               & vlSelfRef.__PVT__U_trace_bram__DOT__j)] 
                                             >> 0x18U)));
            vlSelfRef.__PVT__U_trace_bram__DOT__j = 
                ((IData)(1U) + vlSelfRef.__PVT__U_trace_bram__DOT__j);
        }
        vlSelfRef.__PVT__U_trace_bram__DOT__i = ((IData)(0x40U) 
                                                 + vlSelfRef.__PVT__U_trace_bram__DOT__i);
    }
}

VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___stl_sequent__TOP__miniRV_SoC__0(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___stl_sequent__TOP__miniRV_SoC__0\n"); );
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
}
