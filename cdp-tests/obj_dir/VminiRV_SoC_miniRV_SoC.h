// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_MINIRV_SOC_H_
#define VERILATED_VMINIRV_SOC_MINIRV_SOC_H_  // guard

#include "verilated.h"
class VminiRV_SoC_cpu_top;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_miniRV_SoC final : public VerilatedModule {
  public:
    // CELLS
    VminiRV_SoC_cpu_top* U_cpu;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(fpga_clk,0,0);
        VL_IN8(fpga_rst,0,0);
        VL_OUT8(__PVT__dig_en,7,0);
        VL_OUT8(__PVT__dig_seg,7,0);
        VL_OUT8(__PVT__dig_seg1,7,0);
        VL_IN8(rx,0,0);
        VL_OUT8(__PVT__tx,0,0);
        CData/*0:0*/ __PVT__U_trace_bram__DOT__read_state_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__read_state_next;
        CData/*1:0*/ __PVT__U_trace_bram__DOT__write_state_reg;
        CData/*1:0*/ __PVT__U_trace_bram__DOT__write_state_next;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__mem_wr_en;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__mem_rd_en;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__read_id_reg;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__read_id_next;
        CData/*7:0*/ __PVT__U_trace_bram__DOT__read_count_reg;
        CData/*7:0*/ __PVT__U_trace_bram__DOT__read_count_next;
        CData/*2:0*/ __PVT__U_trace_bram__DOT__read_size_reg;
        CData/*2:0*/ __PVT__U_trace_bram__DOT__read_size_next;
        CData/*1:0*/ __PVT__U_trace_bram__DOT__read_burst_reg;
        CData/*1:0*/ __PVT__U_trace_bram__DOT__read_burst_next;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__write_id_reg;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__write_id_next;
        CData/*7:0*/ __PVT__U_trace_bram__DOT__write_count_reg;
        CData/*7:0*/ __PVT__U_trace_bram__DOT__write_count_next;
        CData/*2:0*/ __PVT__U_trace_bram__DOT__write_size_reg;
        CData/*2:0*/ __PVT__U_trace_bram__DOT__write_size_next;
        CData/*1:0*/ __PVT__U_trace_bram__DOT__write_burst_reg;
        CData/*1:0*/ __PVT__U_trace_bram__DOT__write_burst_next;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_awready_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_awready_next;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_wready_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_wready_next;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__s_axi_bid_reg;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__s_axi_bid_next;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_bvalid_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_bvalid_next;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_arready_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_arready_next;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__s_axi_rid_reg;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__s_axi_rid_next;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_rlast_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_rlast_next;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_rvalid_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_rvalid_next;
        CData/*3:0*/ __PVT__U_trace_bram__DOT__s_axi_rid_pipe_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_rlast_pipe_reg;
        CData/*0:0*/ __PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg;
        CData/*7:0*/ __VdlyVal__U_trace_bram__DOT__mem__v0;
        CData/*0:0*/ __VdlySet__U_trace_bram__DOT__mem__v0;
        CData/*7:0*/ __VdlyVal__U_trace_bram__DOT__mem__v1;
        CData/*0:0*/ __VdlySet__U_trace_bram__DOT__mem__v1;
        CData/*7:0*/ __VdlyVal__U_trace_bram__DOT__mem__v2;
        CData/*0:0*/ __VdlySet__U_trace_bram__DOT__mem__v2;
        CData/*7:0*/ __VdlyVal__U_trace_bram__DOT__mem__v3;
        CData/*0:0*/ __VdlySet__U_trace_bram__DOT__mem__v3;
        VL_IN16(sw,15,0);
        VL_OUT16(__PVT__led,15,0);
        SData/*12:0*/ __VdlyDim0__U_trace_bram__DOT__mem__v0;
        SData/*12:0*/ __VdlyDim0__U_trace_bram__DOT__mem__v1;
        SData/*12:0*/ __VdlyDim0__U_trace_bram__DOT__mem__v2;
        SData/*12:0*/ __VdlyDim0__U_trace_bram__DOT__mem__v3;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__read_addr_reg;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__read_addr_next;
    };
    struct {
        IData/*31:0*/ __PVT__U_trace_bram__DOT__write_addr_reg;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__write_addr_next;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__s_axi_rdata_reg;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__s_axi_rdata_next;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__s_axi_rdata_pipe_reg;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__i;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__j;
        IData/*31:0*/ __PVT__U_trace_bram__DOT__mem_file;
        VlUnpacked<IData/*31:0*/, 8192> __PVT__U_trace_bram__DOT__mem;
        VlUnpacked<IData/*31:0*/, 8192> __PVT__U_trace_bram__DOT__mem_rd;
    };

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VminiRV_SoC_miniRV_SoC(VminiRV_SoC__Syms* symsp, const char* v__name);
    ~VminiRV_SoC_miniRV_SoC();
    VL_UNCOPYABLE(VminiRV_SoC_miniRV_SoC);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
