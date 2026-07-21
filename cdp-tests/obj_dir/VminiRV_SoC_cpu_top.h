// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_CPU_TOP_H_
#define VERILATED_VMINIRV_SOC_CPU_TOP_H_  // guard

#include "verilated.h"
class VminiRV_SoC_cpu_core;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_cpu_top final : public VerilatedModule {
  public:
    // CELLS
    VminiRV_SoC_cpu_core* U_core;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(__PVT__cpu_clk,0,0);
        VL_IN8(__PVT__cpu_rst,0,0);
        VL_OUT8(__PVT__m_axi_awlen,7,0);
        VL_OUT8(__PVT__m_axi_awsize,2,0);
        VL_OUT8(__PVT__m_axi_awburst,1,0);
        VL_OUT8(__PVT__m_axi_awvalid,0,0);
        VL_IN8(__PVT__m_axi_awready,0,0);
        VL_OUT8(__PVT__m_axi_wstrb,3,0);
        VL_OUT8(__PVT__m_axi_wlast,0,0);
        VL_OUT8(__PVT__m_axi_wvalid,0,0);
        VL_IN8(__PVT__m_axi_wready,0,0);
        VL_OUT8(__PVT__m_axi_bready,0,0);
        VL_IN8(__PVT__m_axi_bresp,1,0);
        VL_IN8(__PVT__m_axi_bvalid,0,0);
        VL_OUT8(__PVT__m_axi_arlen,7,0);
        VL_OUT8(__PVT__m_axi_arsize,2,0);
        VL_OUT8(__PVT__m_axi_arburst,1,0);
        VL_OUT8(__PVT__m_axi_arvalid,0,0);
        VL_IN8(__PVT__m_axi_arready,0,0);
        VL_OUT8(__PVT__m_axi_rready,0,0);
        VL_IN8(__PVT__m_axi_rresp,1,0);
        VL_IN8(__PVT__m_axi_rlast,0,0);
        VL_IN8(__PVT__m_axi_rvalid,0,0);
        CData/*0:0*/ __PVT__ic2cpu_valid;
        CData/*3:0*/ __PVT__ic2axi_ren;
        CData/*0:0*/ __PVT__axi2ic_rrdy;
        CData/*0:0*/ __PVT__axi2ic_rvalid;
        CData/*0:0*/ __PVT__dc2cpu_valid;
        CData/*0:0*/ __PVT__dc2cpu_wresp;
        CData/*3:0*/ __PVT__dc2axi_wen;
        CData/*0:0*/ __PVT__axi2dc_wrdy;
        CData/*3:0*/ __PVT__dc2axi_ren;
        CData/*0:0*/ __PVT__axi2dc_rrdy;
        CData/*0:0*/ __PVT__axi2dc_rvalid;
        CData/*1:0*/ __PVT__U_icache__DOT__state;
        CData/*1:0*/ __PVT__U_icache__DOT__nstat;
        CData/*1:0*/ __PVT__U_dcache__DOT__r_state;
        CData/*1:0*/ __PVT__U_dcache__DOT__r_nstat;
        CData/*3:0*/ __PVT__U_dcache__DOT__ren_r;
        CData/*1:0*/ __PVT__U_dcache__DOT__w_state;
        CData/*1:0*/ __PVT__U_dcache__DOT__w_nstat;
        CData/*3:0*/ __PVT__U_dcache__DOT__wen_r;
        CData/*0:0*/ __PVT__U_dcache__DOT__wr_resp;
        CData/*3:0*/ __PVT__U_axi_master__DOT__state;
        CData/*0:0*/ __PVT__U_axi_master__DOT__read_is_data;
        CData/*3:0*/ __PVT__U_axi_master__DOT__write_strb_r;
        CData/*7:0*/ __PVT__U_axi_master__DOT__read_len_r;
        CData/*1:0*/ __PVT__U_axi_master__DOT__read_count;
        CData/*3:0*/ __Vdly__U_axi_master__DOT__state;
        CData/*0:0*/ __Vdly__U_axi_master__DOT__read_is_data;
        CData/*1:0*/ __Vdly__U_axi_master__DOT__read_count;
        VL_OUT(__PVT__m_axi_awaddr,31,0);
        VL_OUT(__PVT__m_axi_wdata,31,0);
        VL_OUT(__PVT__m_axi_araddr,31,0);
        VL_IN(__PVT__m_axi_rdata,31,0);
        IData/*31:0*/ __PVT__ic2cpu_inst;
        IData/*31:0*/ __PVT__ic2axi_addr;
        IData/*31:0*/ __PVT__dc2cpu_rdata;
        IData/*31:0*/ __PVT__dc2axi_waddr;
        IData/*31:0*/ __PVT__dc2axi_wdata;
        IData/*31:0*/ __PVT__dc2axi_raddr;
        IData/*31:0*/ __PVT__U_axi_master__DOT__write_addr_r;
        IData/*31:0*/ __PVT__U_axi_master__DOT__write_data_r;
        IData/*31:0*/ __PVT__U_axi_master__DOT__read_addr_r;
    };
    struct {
        VlWide<4>/*127:0*/ __PVT__U_axi_master__DOT__ic_read_buf;
        VlWide<4>/*127:0*/ __PVT__U_axi_master__DOT__dc_read_buf;
    };

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VminiRV_SoC_cpu_top(VminiRV_SoC__Syms* symsp, const char* v__name);
    ~VminiRV_SoC_cpu_top();
    VL_UNCOPYABLE(VminiRV_SoC_cpu_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
