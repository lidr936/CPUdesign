// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC.h"
#include "VminiRV_SoC___024root.h"
#include "VminiRV_SoC_miniRV_SoC.h"
#include "VminiRV_SoC_cpu_top.h"
#include "VminiRV_SoC_Inst_ROM.h"
#include "VminiRV_SoC_cpu_core.h"
#include "VminiRV_SoC_IROM.h"

// FUNCTIONS
VminiRV_SoC__Syms::~VminiRV_SoC__Syms()
{
}

VminiRV_SoC__Syms::VminiRV_SoC__Syms(VerilatedContext* contextp, const char* namep, VminiRV_SoC* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__miniRV_SoC{this, Verilated::catName(namep, "miniRV_SoC")}
    , TOP__miniRV_SoC__U_cpu{this, Verilated::catName(namep, "miniRV_SoC.U_cpu")}
    , TOP__miniRV_SoC__U_cpu__U_core{this, Verilated::catName(namep, "miniRV_SoC.U_cpu.U_core")}
    , TOP__miniRV_SoC__U_cpu__U_irom{this, Verilated::catName(namep, "miniRV_SoC.U_cpu.U_irom")}
    , TOP__miniRV_SoC__U_cpu__U_irom__U_irom{this, Verilated::catName(namep, "miniRV_SoC.U_cpu.U_irom.U_irom")}
{
        // Check resources
        Verilated::stackCheck(371);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.miniRV_SoC = &TOP__miniRV_SoC;
    TOP__miniRV_SoC.U_cpu = &TOP__miniRV_SoC__U_cpu;
    TOP__miniRV_SoC__U_cpu.U_core = &TOP__miniRV_SoC__U_cpu__U_core;
    TOP__miniRV_SoC__U_cpu.U_irom = &TOP__miniRV_SoC__U_cpu__U_irom;
    TOP__miniRV_SoC__U_cpu__U_irom.U_irom = &TOP__miniRV_SoC__U_cpu__U_irom__U_irom;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__miniRV_SoC.__Vconfigure(true);
    TOP__miniRV_SoC__U_cpu.__Vconfigure(true);
    TOP__miniRV_SoC__U_cpu__U_core.__Vconfigure(true);
    TOP__miniRV_SoC__U_cpu__U_irom.__Vconfigure(true);
    TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__Vconfigure(true);
    // Setup scopes
    __Vscope_miniRV_SoC__U_cpu__U_core.configure(this, name(), "miniRV_SoC.U_cpu.U_core", "U_core", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_miniRV_SoC__U_cpu__U_dram__U_dram.configure(this, name(), "miniRV_SoC.U_cpu.U_dram.U_dram", "U_dram", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_miniRV_SoC__U_cpu__U_irom__U_irom.configure(this, name(), "miniRV_SoC.U_cpu.U_irom.U_irom", "U_irom", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_mem_pc", &(TOP__miniRV_SoC__U_cpu__U_core.debug_mem_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_mem_waddr", &(TOP__miniRV_SoC__U_cpu__U_core.debug_mem_waddr), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_mem_wdata", &(TOP__miniRV_SoC__U_cpu__U_core.debug_mem_wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_mem_we", &(TOP__miniRV_SoC__U_cpu__U_core.debug_mem_we), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_wb_pc", &(TOP__miniRV_SoC__U_cpu__U_core.debug_wb_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_wb_rf_wD", &(TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wD), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_wb_rf_wR", &(TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wR), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"debug_wb_rf_we", &(TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_we), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"ifetch_addr", &(TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,1 ,31,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"ifetch_req", &(TOP__miniRV_SoC__U_cpu__U_core.ifetch_req), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0);
        __Vscope_miniRV_SoC__U_cpu__U_core.varInsert(__Vfinal,"ifetch_valid", &(TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_miniRV_SoC__U_cpu__U_irom__U_irom.varInsert(__Vfinal,"clka", &(TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
    }
}
