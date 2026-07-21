// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_cpu_top.h"

VL_ATTR_COLD void VminiRV_SoC_cpu_top___ctor_var_reset(VminiRV_SoC_cpu_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VminiRV_SoC_cpu_top___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__cpu_clk = VL_RAND_RESET_I(1);
    vlSelf->__PVT__cpu_rst = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_awaddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__m_axi_awlen = VL_RAND_RESET_I(8);
    vlSelf->__PVT__m_axi_awsize = VL_RAND_RESET_I(3);
    vlSelf->__PVT__m_axi_awburst = VL_RAND_RESET_I(2);
    vlSelf->__PVT__m_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__m_axi_wstrb = VL_RAND_RESET_I(4);
    vlSelf->__PVT__m_axi_wlast = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_bready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_bresp = VL_RAND_RESET_I(2);
    vlSelf->__PVT__m_axi_bvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_araddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__m_axi_arlen = VL_RAND_RESET_I(8);
    vlSelf->__PVT__m_axi_arsize = VL_RAND_RESET_I(3);
    vlSelf->__PVT__m_axi_arburst = VL_RAND_RESET_I(2);
    vlSelf->__PVT__m_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_arready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_rready = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__m_axi_rresp = VL_RAND_RESET_I(2);
    vlSelf->__PVT__m_axi_rlast = VL_RAND_RESET_I(1);
    vlSelf->__PVT__m_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ic2cpu_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__ic2cpu_inst = VL_RAND_RESET_I(32);
    vlSelf->__PVT__ic2axi_ren = VL_RAND_RESET_I(4);
    vlSelf->__PVT__ic2axi_addr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__axi2ic_rrdy = VL_RAND_RESET_I(1);
    vlSelf->__PVT__axi2ic_rvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dc2cpu_valid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dc2cpu_rdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dc2cpu_wresp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dc2axi_wen = VL_RAND_RESET_I(4);
    vlSelf->__PVT__dc2axi_waddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__dc2axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->__PVT__axi2dc_wrdy = VL_RAND_RESET_I(1);
    vlSelf->__PVT__dc2axi_ren = VL_RAND_RESET_I(4);
    vlSelf->__PVT__dc2axi_raddr = VL_RAND_RESET_I(32);
    vlSelf->__PVT__axi2dc_rrdy = VL_RAND_RESET_I(1);
    vlSelf->__PVT__axi2dc_rvalid = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_icache__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_icache__DOT__nstat = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_dcache__DOT__r_state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_dcache__DOT__r_nstat = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_dcache__DOT__ren_r = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_dcache__DOT__w_state = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_dcache__DOT__w_nstat = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_dcache__DOT__wen_r = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_dcache__DOT__wr_resp = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_axi_master__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_axi_master__DOT__read_is_data = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_axi_master__DOT__write_addr_r = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_axi_master__DOT__write_data_r = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_axi_master__DOT__write_strb_r = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_axi_master__DOT__read_addr_r = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_axi_master__DOT__read_len_r = VL_RAND_RESET_I(8);
    vlSelf->__PVT__U_axi_master__DOT__read_count = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, vlSelf->__PVT__U_axi_master__DOT__ic_read_buf);
    VL_RAND_RESET_W(128, vlSelf->__PVT__U_axi_master__DOT__dc_read_buf);
    vlSelf->__Vdly__U_axi_master__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->__Vdly__U_axi_master__DOT__read_is_data = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__U_axi_master__DOT__read_count = VL_RAND_RESET_I(2);
}
