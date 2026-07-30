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
    VL_IN8(fpga_clk,0,0);
    VL_IN8(fpga_rst,0,0);
    VL_OUT8(dig_en,7,0);
    VL_OUT8(dig_seg,7,0);
    VL_OUT8(dig_seg1,7,0);
    VL_IN8(rx,0,0);
    VL_OUT8(tx,0,0);
    VL_IN16(sw,15,0);
    VL_OUT16(led,15,0);

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
