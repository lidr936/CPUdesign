// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_IROM_H_
#define VERILATED_VMINIRV_SOC_IROM_H_  // guard

#include "verilated.h"


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_IROM final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clka,0,0);
    VL_IN16(__PVT__addra,15,0);
    VL_OUT(__PVT__douta,31,0);
    IData/*31:0*/ __PVT__i;
    IData/*31:0*/ __PVT__j;
    IData/*31:0*/ __PVT__mem_file;
    VlUnpacked<IData/*31:0*/, 65536> __PVT__mem;
    VlUnpacked<IData/*31:0*/, 65536> __PVT__mem_rd;

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VminiRV_SoC_IROM(VminiRV_SoC__Syms* symsp, const char* v__name);
    ~VminiRV_SoC_IROM();
    VL_UNCOPYABLE(VminiRV_SoC_IROM);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
