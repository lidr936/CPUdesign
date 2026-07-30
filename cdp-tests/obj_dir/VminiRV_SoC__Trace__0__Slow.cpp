// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VminiRV_SoC__Syms.h"


VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("miniRV_SoC", VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+253,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+256,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+257,0,"dig_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+258,0,"dig_seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+259,0,"dig_seg1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+260,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+253,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+279,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+280,0,"dig_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+281,0,"dig_seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+282,0,"dig_seg1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+260,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"sys_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"sys_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("U_cpu", VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+253,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"cpu2ic_rreq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"cpu2ic_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+118,0,"ic2cpu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"ic2cpu_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"cpu2dc_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+247,0,"cpu2dc_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+120,0,"dc2cpu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"dc2cpu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+248,0,"cpu2dc_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+249,0,"cpu2dc_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+121,0,"dc2cpu_wresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("U_core", VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("U_irom", VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("U_dram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+253,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+119,0,"data_ren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+247,0,"data_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+120,0,"data_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"data_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+248,0,"data_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+249,0,"data_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+121,0,"data_wresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("U_dram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+284,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+253,0,"clka",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+250,0,"addra",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+248,0,"wea",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+249,0,"dina",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"douta",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+2,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+3,0,"mem_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+253,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"inst_rreq",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"inst_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+118,0,"inst_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"inst_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("U_irom", VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+254,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"ifetch_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+263,0,"ifetch_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+265,0,"ifetch_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"ifetch_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"daccess_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+247,0,"daccess_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+120,0,"daccess_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"daccess_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+248,0,"daccess_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+249,0,"daccess_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+121,0,"daccess_wresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+266,0,"npc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"pc4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+267,0,"inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"npc_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+8,0,"rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+9,0,"sext_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+10,0,"alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+11,0,"alua_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"alub_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+207,0,"ram_rop_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+14,0,"ram_wop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+15,0,"is_mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"is_div",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"is_mul_div",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"mul_div_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"rf_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"rf_rd2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+285,0,"rf_rd3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+20,0,"rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"rf_we1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+208,0,"rf_wR_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+22,0,"rf_wR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+23,0,"rf_wD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"pc_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"alu_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"alu_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"alu_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"alu_c_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"br",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"mul_div_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"da_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"da_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"da_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+31,0,"da_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"ram_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"is_ld_st",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"ld_st_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+212,0,"store_wdata_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+125,0,"ld_st_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"inst_finished",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"inst_finished_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"rst_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+268,0,"first_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+269,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+270,0,"debug_wb_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+271,0,"debug_wb_rf_wR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+272,0,"debug_wb_rf_wD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"debug_mem_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"debug_mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+275,0,"debug_mem_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"debug_mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("U_ALU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+254,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+25,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"br",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"mul_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"mulu_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+127,0,"mul_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+129,0,"mulu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+132,0,"mul_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"mulu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"div_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"divu_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"div_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"divu_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"div_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"divu_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+138,0,"div_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"divu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"op_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+141,0,"a_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+142,0,"div_neg_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"rem_neg_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"div_zero_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"div_overflow_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"op_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+146,0,"div_quo_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"div_rem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"a_abs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"b_abs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("U_div", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+286,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+253,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+39,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+36,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+138,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+148,0,"quotient",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"quotient_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"dividend",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+151,0,"remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+153,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+154,0,"divisor_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+156,0,"remainder_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+158,0,"remainder_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+160,0,"ge_divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+161,0,"remainder_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+163,0,"quotient_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_divu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+286,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+253,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+135,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+139,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+164,0,"quotient",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"quotient_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"dividend",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+167,0,"remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+169,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+170,0,"divisor_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+172,0,"remainder_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+174,0,"remainder_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+176,0,"ge_divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+177,0,"remainder_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+179,0,"quotient_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+286,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+253,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+34,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+127,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+132,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+287,0,"O_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+288,0,"P_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+180,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declQuad(c+183,0,"x_ext_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+185,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+132,0,"busy_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+41,0,"x_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+186,0,"prod_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+188,0,"next_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declArray(c+190,0,"next_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_mulu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+289,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+253,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+43,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+45,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+35,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+129,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+133,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+288,0,"O_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+290,0,"P_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+193,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 67,0);
    tracep->declQuad(c+196,0,"x_ext_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBus(c+198,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+133,0,"busy_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+47,0,"x_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+199,0,"prod_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+201,0,"next_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declArray(c+203,0,"next_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 67,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("U_CU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+49,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+50,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+51,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+7,0,"npc_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+9,0,"sext_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+11,0,"alua_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"alub_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+15,0,"is_mul",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"is_div",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"ram_r_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+14,0,"ram_w_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+20,0,"rf_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"rf_wsel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+52,0,"ADDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"SLTI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"SLTIU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"XORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"ORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"ANDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"SLLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"SRLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"SRAI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"LB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"LH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"LW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"LBU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"LHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"SB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"SH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"SW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"BEQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"BNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"BLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"BGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"BLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"BGEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"NPC_OP_BRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"NPC_OP_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"NPC_OP_JMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"NPC_OP_PC4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"RF_OP_WE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"WB_OP_ALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"WB_OP_RAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"WB_OP_PC4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"WB_OP_EXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"EXT_OP_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"EXT_OP_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"EXT_OP_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"EXT_OP_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"EXT_OP_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"ALU_OP_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"ALU_OP_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"ALU_OP_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"ALU_OP_OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"ALU_OP_XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"ALU_OP_SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"ALU_OP_SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"ALU_OP_SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"ALU_OP_EQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"ALU_OP_NE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"ALU_OP_LT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"ALU_OP_GE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"ALU_OP_LTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"ALU_OP_GEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"ALU_OP_SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"ALU_OP_SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"ALU_OP_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"ALU_OP_MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"ALU_OP_MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"ALU_OP_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"ALU_OP_DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"ALU_OP_REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"ALU_OP_REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"ALU_A_SEL_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"ALU_A_SEL_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"ALU_B_SEL_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"ALU_B_SEL_EXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"RAM_EXT_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"RAM_EXT_BU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"RAM_EXT_H",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"RAM_EXT_HU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"RAM_EXT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"RAM_W_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"RAM_W_H",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"RAM_W_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("U_MEM_EXT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+207,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+206,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+214,0,"byte_offs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+211,0,"ext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+215,0,"real_din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_MEM_REQ", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"ram_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"ram_rop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+29,0,"da_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"da_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"ram_wop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+19,0,"ram_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"da_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+31,0,"da_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_NPC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+7,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+251,0,"pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"base",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"offset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"br",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+266,0,"npc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+252,0,"pc4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_PC", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+253,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+266,0,"npc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"fetch",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_RF", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+253,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"rR1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+116,0,"rR2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+21,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"wR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+23,0,"wD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"rD1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"rD2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 31; ++i) {
        tracep->declBus(c+216+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("U_SEXT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+9,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+117,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,7);
    tracep->declBus(c+24,0,"ext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+284,0,"ADDR_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+277,0,"clka",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+278,0,"addra",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+264,0,"douta",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+5,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+6,0,"mem_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_top(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VminiRV_SoC___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VminiRV_SoC___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VminiRV_SoC___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_register(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_register\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VminiRV_SoC___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VminiRV_SoC___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VminiRV_SoC___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VminiRV_SoC___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_const_0\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VminiRV_SoC___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_const_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_const_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+279,(vlSymsp->TOP__miniRV_SoC.led),16);
    bufp->fullCData(oldp+280,(vlSymsp->TOP__miniRV_SoC.dig_en),8);
    bufp->fullCData(oldp+281,(vlSymsp->TOP__miniRV_SoC.dig_seg),8);
    bufp->fullCData(oldp+282,(vlSymsp->TOP__miniRV_SoC.dig_seg1),8);
    bufp->fullBit(oldp+283,(vlSymsp->TOP__miniRV_SoC.tx));
    bufp->fullIData(oldp+284,(0x10U),32);
    bufp->fullIData(oldp+285,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_rd3),32);
    bufp->fullIData(oldp+286,(0x20U),32);
    bufp->fullIData(oldp+287,(0x40U),32);
    bufp->fullIData(oldp+288,(0x42U),32);
    bufp->fullIData(oldp+289,(0x21U),32);
    bufp->fullIData(oldp+290,(0x44U),32);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_full_0\n"); );
    // Init
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VminiRV_SoC___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_full_0_sub_0(VminiRV_SoC___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_full_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__j),32);
    bufp->fullIData(oldp+3,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dram__DOT__U_dram__DOT__mem_file),32);
    bufp->fullIData(oldp+4,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__i),32);
    bufp->fullIData(oldp+5,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__j),32);
    bufp->fullIData(oldp+6,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__mem_file),32);
    bufp->fullCData(oldp+7,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op),2);
    bufp->fullCData(oldp+8,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wsel),2);
    bufp->fullCData(oldp+9,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__sext_op),3);
    bufp->fullCData(oldp+10,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op),5);
    bufp->fullBit(oldp+11,((0x17U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
    bufp->fullBit(oldp+12,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                         | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA))))))))))))))))));
    bufp->fullCData(oldp+13,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop),3);
    bufp->fullCData(oldp+14,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_wop),4);
    bufp->fullBit(oldp+15,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                            | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29))));
    bufp->fullBit(oldp+16,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_div));
    bufp->fullBit(oldp+17,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_mul_div));
    bufp->fullIData(oldp+18,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_rd1),32);
    bufp->fullIData(oldp+19,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_rd2),32);
    bufp->fullBit(oldp+20,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))))))))) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                              | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_div))))))))))))) 
                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                               | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH) 
                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW)) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_33) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_U) 
                                        | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4))))))));
    bufp->fullBit(oldp+21,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_we1));
    bufp->fullCData(oldp+22,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wR),5);
    bufp->fullIData(oldp+23,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wD),32);
    bufp->fullIData(oldp+24,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext),32);
    bufp->fullIData(oldp+25,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a),32);
    bufp->fullIData(oldp+26,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b),32);
    bufp->fullIData(oldp+27,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c),32);
    bufp->fullBit(oldp+28,(((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                      >> 4U))) && (
                                                   (1U 
                                                    & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                       >> 3U)) 
                                                   && ((4U 
                                                        & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                        ? 
                                                       ((1U 
                                                         & (~ 
                                                            ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                             >> 1U))) 
                                                        && ((1U 
                                                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                             ? 
                                                            (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                             >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                             : 
                                                            (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                             < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                          ? 
                                                         VL_GTES_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                          : 
                                                         VL_LTS_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                          ? 
                                                         (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                          != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                          : 
                                                         (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                          == vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))))))));
    bufp->fullCData(oldp+29,(((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                               ? ((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                                   ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                                       ? ((0U == (3U 
                                                  & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c))
                                           ? 0xfU : 0U)
                                       : ((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c)
                                           ? 0U : 0xfU))
                                   : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop))
                                       ? 0xfU : ((0U 
                                                  == 
                                                  (3U 
                                                   & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c))
                                                  ? 0xfU
                                                  : 0U)))
                               : 0U)),4);
    bufp->fullCData(oldp+30,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__da_wen),4);
    bufp->fullIData(oldp+31,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__da_wdata),32);
    bufp->fullBit(oldp+32,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_ld_st));
    bufp->fullBit(oldp+33,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__inst_finished));
    bufp->fullBit(oldp+34,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__mul_flag));
    bufp->fullBit(oldp+35,((0x12U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))));
    bufp->fullBit(oldp+36,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_flag));
    bufp->fullBit(oldp+37,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__divu_flag));
    bufp->fullCData(oldp+38,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__op_eff),5);
    bufp->fullIData(oldp+39,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__a_abs),32);
    bufp->fullIData(oldp+40,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__b_abs),32);
    bufp->fullQData(oldp+41,((((QData)((IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                >> 0x1fU))) 
                               << 0x20U) | (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a)))),33);
    bufp->fullQData(oldp+43,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a))),33);
    bufp->fullQData(oldp+45,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))),33);
    bufp->fullQData(oldp+47,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a))),34);
    bufp->fullCData(oldp+49,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode),7);
    bufp->fullCData(oldp+50,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__funct3),3);
    bufp->fullCData(oldp+51,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__funct7),7);
    bufp->fullBit(oldp+52,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI));
    bufp->fullBit(oldp+53,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI));
    bufp->fullBit(oldp+54,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU));
    bufp->fullBit(oldp+55,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI));
    bufp->fullBit(oldp+56,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI));
    bufp->fullBit(oldp+57,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI));
    bufp->fullBit(oldp+58,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI));
    bufp->fullBit(oldp+59,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI));
    bufp->fullBit(oldp+60,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI));
    bufp->fullBit(oldp+61,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD));
    bufp->fullBit(oldp+62,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SUB));
    bufp->fullBit(oldp+63,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL));
    bufp->fullBit(oldp+64,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT));
    bufp->fullBit(oldp+65,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU));
    bufp->fullBit(oldp+66,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR));
    bufp->fullBit(oldp+67,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL));
    bufp->fullBit(oldp+68,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA));
    bufp->fullBit(oldp+69,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR));
    bufp->fullBit(oldp+70,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND));
    bufp->fullBit(oldp+71,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL));
    bufp->fullBit(oldp+72,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULH));
    bufp->fullBit(oldp+73,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MULHU));
    bufp->fullBit(oldp+74,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIV));
    bufp->fullBit(oldp+75,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__DIVU));
    bufp->fullBit(oldp+76,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REM));
    bufp->fullBit(oldp+77,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__REMU));
    bufp->fullBit(oldp+78,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB));
    bufp->fullBit(oldp+79,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH));
    bufp->fullBit(oldp+80,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW));
    bufp->fullBit(oldp+81,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU));
    bufp->fullBit(oldp+82,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU));
    bufp->fullBit(oldp+83,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB));
    bufp->fullBit(oldp+84,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH));
    bufp->fullBit(oldp+85,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW));
    bufp->fullBit(oldp+86,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BEQ));
    bufp->fullBit(oldp+87,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BNE));
    bufp->fullBit(oldp+88,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLT));
    bufp->fullBit(oldp+89,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGE));
    bufp->fullBit(oldp+90,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BLTU));
    bufp->fullBit(oldp+91,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__BGEU));
    bufp->fullBit(oldp+92,((0x37U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
    bufp->fullBit(oldp+93,((0x6fU == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
    bufp->fullBit(oldp+94,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR));
    bufp->fullBit(oldp+95,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA));
    bufp->fullBit(oldp+96,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR) 
                                        | (0x6fU == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))))))));
    bufp->fullBit(oldp+97,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))))))))) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                              | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__is_div))))))))))))) 
                            | (0x17U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode)))));
    bufp->fullBit(oldp+98,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH)) 
                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW) 
                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_33)))));
    bufp->fullBit(oldp+99,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__WB_OP_PC4));
    bufp->fullBit(oldp+100,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI) 
                                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))))))))) 
                             | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH)) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU) 
                                         | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR))))))));
    bufp->fullBit(oldp+101,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB) 
                              | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH)) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW))));
    bufp->fullBit(oldp+102,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__EXT_OP_U));
    bufp->fullBit(oldp+103,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADDI) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LB) 
                                | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LH) 
                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LW)) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LBU) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__LHU) 
                                         | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SB) 
                                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SH)) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SW) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                                                  | ((0x17U 
                                                      == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode)) 
                                                     | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__JALR))))))))))));
    bufp->fullBit(oldp+104,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ANDI))));
    bufp->fullBit(oldp+105,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ORI))));
    bufp->fullBit(oldp+106,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XORI))));
    bufp->fullBit(oldp+107,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLL) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLLI))));
    bufp->fullBit(oldp+108,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRLI))));
    bufp->fullBit(oldp+109,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRAI))));
    bufp->fullBit(oldp+110,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTI))));
    bufp->fullBit(oldp+111,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTIU))));
    bufp->fullBit(oldp+112,((0x17U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_CU__opcode))));
    bufp->fullBit(oldp+113,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__ADD) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLT) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SLTU) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__XOR) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRL) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__SRA) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__OR) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__AND) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__MUL) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_CU__DOT__NPC_OP_BRA))))))))))))))));
    bufp->fullCData(oldp+114,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c)),2);
    bufp->fullCData(oldp+115,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_RF__rR1),5);
    bufp->fullCData(oldp+116,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_RF__rR2),5);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__Vcellinp__U_SEXT__imm),25);
    bufp->fullBit(oldp+118,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom.__PVT__inst_valid));
    bufp->fullCData(oldp+119,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren),4);
    bufp->fullBit(oldp+120,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid));
    bufp->fullBit(oldp+121,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp));
    bufp->fullBit(oldp+122,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_flag));
    bufp->fullBit(oldp+123,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_div_busy));
    bufp->fullBit(oldp+124,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ld_st_flag));
    bufp->fullBit(oldp+125,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ld_st_done));
    bufp->fullBit(oldp+126,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__inst_finished_r));
    bufp->fullQData(oldp+127,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__mul_res),64);
    bufp->fullWData(oldp+129,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__mulu_res),66);
    bufp->fullBit(oldp+132,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__busy_r));
    bufp->fullBit(oldp+133,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__busy_r));
    bufp->fullIData(oldp+134,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_out),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__quotient_out),32);
    bufp->fullIData(oldp+136,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_rem),32);
    bufp->fullIData(oldp+137,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__divu_rem),32);
    bufp->fullBit(oldp+138,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_busy));
    bufp->fullBit(oldp+139,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__divu_busy));
    bufp->fullCData(oldp+140,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__op_r),5);
    bufp->fullIData(oldp+141,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__a_r),32);
    bufp->fullBit(oldp+142,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_neg_r));
    bufp->fullBit(oldp+143,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__rem_neg_r));
    bufp->fullBit(oldp+144,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_zero_r));
    bufp->fullBit(oldp+145,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_overflow_r));
    bufp->fullIData(oldp+146,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_neg_r)
                                ? ((IData)(1U) + (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_out))
                                : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_out)),32);
    bufp->fullIData(oldp+147,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__rem_neg_r)
                                ? ((IData)(1U) + (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_rem))
                                : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__div_rem)),32);
    bufp->fullIData(oldp+148,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient),32);
    bufp->fullIData(oldp+149,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__dividend),32);
    bufp->fullIData(oldp+150,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__divisor),32);
    bufp->fullQData(oldp+151,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder),33);
    bufp->fullCData(oldp+153,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__count),8);
    bufp->fullQData(oldp+154,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__divisor))),33);
    bufp->fullQData(oldp+156,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift),33);
    bufp->fullQData(oldp+158,((0x1ffffffffULL & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift 
                                                 - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__divisor))))),33);
    bufp->fullBit(oldp+160,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__ge_divisor));
    bufp->fullQData(oldp+161,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__remainder_next),33);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_div__DOT__quotient_next),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__quotient),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__dividend),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__divisor),32);
    bufp->fullQData(oldp+167,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder),33);
    bufp->fullCData(oldp+169,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__count),8);
    bufp->fullQData(oldp+170,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__divisor))),33);
    bufp->fullQData(oldp+172,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift),33);
    bufp->fullQData(oldp+174,((0x1ffffffffULL & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift 
                                                 - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__divisor))))),33);
    bufp->fullBit(oldp+176,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__ge_divisor));
    bufp->fullQData(oldp+177,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__remainder_next),33);
    bufp->fullIData(oldp+179,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_divu__DOT__quotient_next),32);
    bufp->fullWData(oldp+180,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__product),66);
    bufp->fullQData(oldp+183,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__x_ext_r),33);
    bufp->fullCData(oldp+185,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__count),8);
    bufp->fullQData(oldp+186,((0x1ffffffffULL & (((QData)((IData)(
                                                                  vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__product[1U])) 
                                                    >> 1U)))),33);
    bufp->fullQData(oldp+188,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__next_high),33);
    bufp->fullWData(oldp+190,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mul__DOT__next_product),66);
    bufp->fullWData(oldp+193,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__product),68);
    bufp->fullQData(oldp+196,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__x_ext_r),34);
    bufp->fullCData(oldp+198,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__count),8);
    bufp->fullQData(oldp+199,((0x3ffffffffULL & (((QData)((IData)(
                                                                  vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                                  << 0x1eU) 
                                                 | ((QData)((IData)(
                                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__product[1U])) 
                                                    >> 2U)))),34);
    bufp->fullQData(oldp+201,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__next_high),34);
    bufp->fullWData(oldp+203,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_ALU__DOT__U_mulu__DOT__next_product),68);
    bufp->fullIData(oldp+206,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata),32);
    bufp->fullCData(oldp+207,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r),3);
    bufp->fullCData(oldp+208,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_wR_r),5);
    bufp->fullIData(oldp+209,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc_r),32);
    bufp->fullIData(oldp+210,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c_r),32);
    bufp->fullIData(oldp+211,(((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                    ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din
                                    : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                        ? (0xffffU 
                                           & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din)
                                        : (((- (IData)(
                                                       (1U 
                                                        & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din 
                                                           >> 0xfU)))) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din))))
                                : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                    ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ram_rop_r))
                                        ? (0xffU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din)
                                        : (((- (IData)(
                                                       (1U 
                                                        & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din 
                                                           >> 7U)))) 
                                            << 8U) 
                                           | (0xffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din)))
                                    : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din))),32);
    bufp->fullIData(oldp+212,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__store_wdata_r),32);
    bufp->fullBit(oldp+213,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rst_r));
    bufp->fullCData(oldp+214,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_c_r)),2);
    bufp->fullIData(oldp+215,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_MEM_EXT__DOT__real_din),32);
    bufp->fullIData(oldp+216,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[0]),32);
    bufp->fullIData(oldp+217,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[1]),32);
    bufp->fullIData(oldp+218,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[2]),32);
    bufp->fullIData(oldp+219,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[3]),32);
    bufp->fullIData(oldp+220,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[4]),32);
    bufp->fullIData(oldp+221,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[5]),32);
    bufp->fullIData(oldp+222,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[6]),32);
    bufp->fullIData(oldp+223,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[7]),32);
    bufp->fullIData(oldp+224,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[8]),32);
    bufp->fullIData(oldp+225,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[9]),32);
    bufp->fullIData(oldp+226,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[10]),32);
    bufp->fullIData(oldp+227,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[11]),32);
    bufp->fullIData(oldp+228,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[12]),32);
    bufp->fullIData(oldp+229,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[13]),32);
    bufp->fullIData(oldp+230,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[14]),32);
    bufp->fullIData(oldp+231,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[15]),32);
    bufp->fullIData(oldp+232,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[16]),32);
    bufp->fullIData(oldp+233,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[17]),32);
    bufp->fullIData(oldp+234,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[18]),32);
    bufp->fullIData(oldp+235,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[19]),32);
    bufp->fullIData(oldp+236,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[20]),32);
    bufp->fullIData(oldp+237,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[21]),32);
    bufp->fullIData(oldp+238,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[22]),32);
    bufp->fullIData(oldp+239,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[23]),32);
    bufp->fullIData(oldp+240,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[24]),32);
    bufp->fullIData(oldp+241,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[25]),32);
    bufp->fullIData(oldp+242,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[26]),32);
    bufp->fullIData(oldp+243,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[27]),32);
    bufp->fullIData(oldp+244,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[28]),32);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[29]),32);
    bufp->fullIData(oldp+246,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_RF__DOT__regs[30]),32);
    bufp->fullIData(oldp+247,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr),32);
    bufp->fullCData(oldp+248,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen),4);
    bufp->fullIData(oldp+249,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wdata),32);
    bufp->fullSData(oldp+250,((0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_addr 
                                          >> 2U))),16);
    bufp->fullIData(oldp+251,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc),32);
    bufp->fullIData(oldp+252,(((IData)(4U) + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc)),32);
    bufp->fullBit(oldp+253,(vlSelfRef.fpga_clk));
    bufp->fullBit(oldp+254,(vlSelfRef.fpga_rst));
    bufp->fullSData(oldp+255,(vlSelfRef.sw),16);
    bufp->fullSData(oldp+256,(vlSelfRef.led),16);
    bufp->fullCData(oldp+257,(vlSelfRef.dig_en),8);
    bufp->fullCData(oldp+258,(vlSelfRef.dig_seg),8);
    bufp->fullCData(oldp+259,(vlSelfRef.dig_seg1),8);
    bufp->fullBit(oldp+260,(vlSelfRef.rx));
    bufp->fullBit(oldp+261,(vlSelfRef.tx));
    bufp->fullBit(oldp+262,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req));
    bufp->fullIData(oldp+263,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr),32);
    bufp->fullIData(oldp+264,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__douta),32);
    bufp->fullBit(oldp+265,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid));
    bufp->fullIData(oldp+266,(((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op))
                                ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op))
                                    ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc 
                                       + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext)
                                    : (((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                  >> 4U))) 
                                        && ((1U & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                   >> 3U)) 
                                            && ((4U 
                                                 & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                 ? 
                                                ((1U 
                                                  & (~ 
                                                     ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op) 
                                                      >> 1U))) 
                                                 && ((1U 
                                                      & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                      ? 
                                                     (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                      >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                      : 
                                                     (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                      < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                   ? 
                                                  VL_GTES_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                   : 
                                                  VL_LTS_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_op))
                                                   ? 
                                                  (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                   != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b)
                                                   : 
                                                  (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_a 
                                                   == vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__alu_b))))))
                                        ? (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc 
                                           + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext)
                                        : ((IData)(4U) 
                                           + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc)))
                                : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__npc_op))
                                    ? (0xfffffffeU 
                                       & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rf_rd1 
                                          + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ext))
                                    : ((IData)(4U) 
                                       + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pc)))),32);
    bufp->fullIData(oldp+267,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid)
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.__PVT__douta
                                : 0x13U)),32);
    bufp->fullBit(oldp+268,(((~ (IData)(vlSelfRef.fpga_rst)) 
                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__rst_r))));
    bufp->fullIData(oldp+269,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_pc),32);
    bufp->fullBit(oldp+270,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_we));
    bufp->fullCData(oldp+271,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wR),5);
    bufp->fullIData(oldp+272,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wD),32);
    bufp->fullIData(oldp+273,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_pc),32);
    bufp->fullCData(oldp+274,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_we),4);
    bufp->fullIData(oldp+275,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_waddr),32);
    bufp->fullIData(oldp+276,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_wdata),32);
    bufp->fullBit(oldp+277,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka));
    bufp->fullSData(oldp+278,((0xffffU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr 
                                          >> 2U))),16);
}
