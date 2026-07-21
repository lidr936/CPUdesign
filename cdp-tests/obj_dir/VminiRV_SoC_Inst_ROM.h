// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_INST_ROM_H_
#define VERILATED_VMINIRV_SOC_INST_ROM_H_  // guard

#include "verilated.h"
class VminiRV_SoC_IROM;


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_Inst_ROM final : public VerilatedModule {
  public:
    // CELLS
    VminiRV_SoC_IROM* U_irom;

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__cpu_clk,0,0);
    VL_IN8(__PVT__cpu_rst,0,0);
    VL_IN8(__PVT__inst_rreq,0,0);
    VL_OUT8(__PVT__inst_valid,0,0);
    VL_IN(__PVT__inst_addr,31,0);
    VL_OUT(__PVT__inst_out,31,0);

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VminiRV_SoC_Inst_ROM(VminiRV_SoC__Syms* symsp, const char* v__name);
    ~VminiRV_SoC_Inst_ROM();
    VL_UNCOPYABLE(VminiRV_SoC_Inst_ROM);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
