// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_CPU_TOP_H_
#define VERILATED_VMINIRV_SOC_CPU_TOP_H_  // guard

#include "verilated.h"
class VminiRV_SoC_Inst_ROM;
class VminiRV_SoC_cpu_core;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_cpu_top final : public VerilatedModule {
  public:
    // CELLS
    VminiRV_SoC_cpu_core* U_core;
    VminiRV_SoC_Inst_ROM* U_irom;

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__cpu_clk,0,0);
    VL_IN8(__PVT__cpu_rst,0,0);
    CData/*0:0*/ __PVT__dc2cpu_valid;
    CData/*0:0*/ __PVT__dc2cpu_wresp;
    IData/*31:0*/ __PVT__dc2cpu_rdata;
    IData/*31:0*/ __PVT__U_dram__DOT__U_dram__DOT__i;
    IData/*31:0*/ __PVT__U_dram__DOT__U_dram__DOT__j;
    IData/*31:0*/ __PVT__U_dram__DOT__U_dram__DOT__mem_file;
    VlUnpacked<IData/*31:0*/, 65536> __PVT__U_dram__DOT__U_dram__DOT__mem;
    VlUnpacked<IData/*31:0*/, 65536> __PVT__U_dram__DOT__U_dram__DOT__mem_rd;

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
