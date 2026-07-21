// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_miniRV_SoC.h"

VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___eval_static__TOP__miniRV_SoC(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___eval_static__TOP__miniRV_SoC\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__U_trace_bram__DOT__read_state_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_state_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_id_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_addr_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_count_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_size_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__read_burst_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_id_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_addr_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_count_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_size_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__write_burst_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_awready_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_wready_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bid_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_arready_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rdata_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rid_pipe_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rdata_pipe_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rlast_pipe_reg = 0U;
    vlSelfRef.__PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg = 0U;
}

VL_ATTR_COLD void VminiRV_SoC_miniRV_SoC___ctor_var_reset(VminiRV_SoC_miniRV_SoC* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      VminiRV_SoC_miniRV_SoC___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->fpga_clk = VL_RAND_RESET_I(1);
    vlSelf->fpga_rst = VL_RAND_RESET_I(1);
    vlSelf->sw = VL_RAND_RESET_I(16);
    vlSelf->__PVT__led = VL_RAND_RESET_I(16);
    vlSelf->__PVT__dig_en = VL_RAND_RESET_I(8);
    vlSelf->__PVT__dig_seg = VL_RAND_RESET_I(8);
    vlSelf->__PVT__dig_seg1 = VL_RAND_RESET_I(8);
    vlSelf->rx = VL_RAND_RESET_I(1);
    vlSelf->__PVT__tx = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__read_state_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__read_state_next = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__write_state_reg = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_trace_bram__DOT__write_state_next = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_trace_bram__DOT__mem_wr_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__mem_rd_en = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__read_id_reg = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__read_id_next = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__read_addr_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__read_addr_next = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__read_count_reg = VL_RAND_RESET_I(8);
    vlSelf->__PVT__U_trace_bram__DOT__read_count_next = VL_RAND_RESET_I(8);
    vlSelf->__PVT__U_trace_bram__DOT__read_size_reg = VL_RAND_RESET_I(3);
    vlSelf->__PVT__U_trace_bram__DOT__read_size_next = VL_RAND_RESET_I(3);
    vlSelf->__PVT__U_trace_bram__DOT__read_burst_reg = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_trace_bram__DOT__read_burst_next = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_trace_bram__DOT__write_id_reg = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__write_id_next = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__write_addr_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__write_addr_next = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__write_count_reg = VL_RAND_RESET_I(8);
    vlSelf->__PVT__U_trace_bram__DOT__write_count_next = VL_RAND_RESET_I(8);
    vlSelf->__PVT__U_trace_bram__DOT__write_size_reg = VL_RAND_RESET_I(3);
    vlSelf->__PVT__U_trace_bram__DOT__write_size_next = VL_RAND_RESET_I(3);
    vlSelf->__PVT__U_trace_bram__DOT__write_burst_reg = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_trace_bram__DOT__write_burst_next = VL_RAND_RESET_I(2);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_awready_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_awready_next = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_wready_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_wready_next = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_bid_reg = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_bid_next = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_bvalid_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_bvalid_next = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_arready_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_arready_next = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rid_reg = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rid_next = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rdata_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rdata_next = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rlast_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rlast_next = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rvalid_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rvalid_next = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rid_pipe_reg = VL_RAND_RESET_I(4);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rdata_pipe_reg = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rlast_pipe_reg = VL_RAND_RESET_I(1);
    vlSelf->__PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->__PVT__U_trace_bram__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->__PVT__U_trace_bram__DOT__mem_rd[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__PVT__U_trace_bram__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->__PVT__U_trace_bram__DOT__mem_file = 0;
    vlSelf->__VdlyVal__U_trace_bram__DOT__mem__v0 = VL_RAND_RESET_I(8);
    vlSelf->__VdlyDim0__U_trace_bram__DOT__mem__v0 = VL_RAND_RESET_I(13);
    vlSelf->__VdlySet__U_trace_bram__DOT__mem__v0 = 0;
    vlSelf->__VdlyVal__U_trace_bram__DOT__mem__v1 = VL_RAND_RESET_I(8);
    vlSelf->__VdlyDim0__U_trace_bram__DOT__mem__v1 = VL_RAND_RESET_I(13);
    vlSelf->__VdlySet__U_trace_bram__DOT__mem__v1 = 0;
    vlSelf->__VdlyVal__U_trace_bram__DOT__mem__v2 = VL_RAND_RESET_I(8);
    vlSelf->__VdlyDim0__U_trace_bram__DOT__mem__v2 = VL_RAND_RESET_I(13);
    vlSelf->__VdlySet__U_trace_bram__DOT__mem__v2 = 0;
    vlSelf->__VdlyVal__U_trace_bram__DOT__mem__v3 = VL_RAND_RESET_I(8);
    vlSelf->__VdlyDim0__U_trace_bram__DOT__mem__v3 = VL_RAND_RESET_I(13);
    vlSelf->__VdlySet__U_trace_bram__DOT__mem__v3 = 0;
}
