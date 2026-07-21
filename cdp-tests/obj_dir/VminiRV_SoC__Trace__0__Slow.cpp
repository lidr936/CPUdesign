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
    tracep->declBit(c+396,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+398,0,"sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+399,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+400,0,"dig_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+401,0,"dig_seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+402,0,"dig_seg1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+403,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+404,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
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
    tracep->declBit(c+396,0,"fpga_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"fpga_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+398,0,"sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+423,0,"led",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+424,0,"dig_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+424,0,"dig_seg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+424,0,"dig_seg1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+403,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+425,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+396,0,"sys_clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"sys_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+184,0,"axi_awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"axi_awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"axi_awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"axi_awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+185,0,"axi_awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"axi_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"axi_wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+425,0,"axi_wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"axi_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+363,0,"axi_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"axi_bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+429,0,"axi_bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+364,0,"axi_bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+190,0,"axi_araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"axi_arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"axi_arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"axi_arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+192,0,"axi_arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+365,0,"axi_arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"axi_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+366,0,"axi_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+429,0,"axi_rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+367,0,"axi_rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"axi_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("U_cpu", VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("U_trace_bram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+430,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+431,0,"DATA_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+430,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"STRB_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"ID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+433,0,"PIPELINE_OUTPUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+396,0,"s_aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+405,0,"s_aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+434,0,"s_axi_awid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+184,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"s_axi_awlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"s_axi_awsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"s_axi_awburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+435,0,"s_axi_awlock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+434,0,"s_axi_awcache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+436,0,"s_axi_awprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+185,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"s_axi_wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+425,0,"s_axi_wlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+363,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"s_axi_bid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+429,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+364,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"s_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+434,0,"s_axi_arid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+190,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"s_axi_arlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"s_axi_arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"s_axi_arburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+435,0,"s_axi_arlock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+434,0,"s_axi_arcache",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+436,0,"s_axi_arprot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+192,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+365,0,"s_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"s_axi_rid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+366,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+429,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+367,0,"s_axi_rlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"s_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+437,0,"VALID_ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"WORD_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+438,0,"WORD_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+439,0,"READ_STATE_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+440,0,"READ_STATE_BURST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+135,0,"read_state_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+371,0,"read_state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+429,0,"WRITE_STATE_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+428,0,"WRITE_STATE_BURST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+441,0,"WRITE_STATE_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+136,0,"write_state_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+372,0,"write_state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+373,0,"mem_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+374,0,"mem_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"read_id_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+375,0,"read_id_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+369,0,"read_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+376,0,"read_addr_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"read_count_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+377,0,"read_count_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+139,0,"read_size_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+378,0,"read_size_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+140,0,"read_burst_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+379,0,"read_burst_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+141,0,"write_id_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+380,0,"write_id_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+142,0,"write_addr_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+381,0,"write_addr_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+143,0,"write_count_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+382,0,"write_count_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+144,0,"write_size_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+383,0,"write_size_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+145,0,"write_burst_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+384,0,"write_burst_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+362,0,"s_axi_awready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"s_axi_awready_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+363,0,"s_axi_wready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"s_axi_wready_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"s_axi_bid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+387,0,"s_axi_bid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+364,0,"s_axi_bvalid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+388,0,"s_axi_bvalid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+365,0,"s_axi_arready_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+389,0,"s_axi_arready_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+134,0,"s_axi_rid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+390,0,"s_axi_rid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+366,0,"s_axi_rdata_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+442,0,"s_axi_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+367,0,"s_axi_rlast_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+391,0,"s_axi_rlast_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"s_axi_rvalid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+392,0,"s_axi_rvalid_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"s_axi_rid_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+147,0,"s_axi_rdata_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+148,0,"s_axi_rlast_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"s_axi_rvalid_pipe_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+194,0,"s_axi_awaddr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBus(c+195,0,"s_axi_araddr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBus(c+370,0,"read_addr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBus(c+150,0,"write_addr_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 29,0);
    tracep->declBit(c+151,0,"waddr_valid_f",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+152,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+2,0,"mem_file",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+443,0,"depth_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+396,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+184,0,"m_axi_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"m_axi_awlen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"m_axi_awsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"m_axi_awburst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+185,0,"m_axi_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"m_axi_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"m_axi_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"m_axi_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+425,0,"m_axi_wlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"m_axi_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+363,0,"m_axi_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"m_axi_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+429,0,"m_axi_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+364,0,"m_axi_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+190,0,"m_axi_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"m_axi_arlen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"m_axi_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"m_axi_arburst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+192,0,"m_axi_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+365,0,"m_axi_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"m_axi_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+366,0,"m_axi_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+429,0,"m_axi_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+367,0,"m_axi_rlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"m_axi_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+406,0,"cpu2ic_rreq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+407,0,"cpu2ic_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"ic2cpu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+196,0,"ic2cpu_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"ic2axi_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+198,0,"ic2axi_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+199,0,"axi2ic_rrdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"axi2ic_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+201,0,"axi2ic_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"cpu2dc_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+203,0,"cpu2dc_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+24,0,"dc2cpu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"dc2cpu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"cpu2dc_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"cpu2dc_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"dc2cpu_wresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"dc2axi_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+207,0,"dc2axi_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"dc2axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+393,0,"axi2dc_wrdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+209,0,"dc2axi_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+210,0,"dc2axi_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+211,0,"axi2dc_rrdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"axi2dc_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"axi2dc_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("U_core", VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_init_sub__TOP__miniRV_SoC__U_cpu__U_core__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("U_axi_master", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+396,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"areset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+199,0,"ic_dev_rrdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"ic_cpu_ren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+198,0,"ic_cpu_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+200,0,"ic_dev_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+201,0,"ic_dev_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+393,0,"dc_dev_wrdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"dc_cpu_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+207,0,"dc_cpu_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"dc_cpu_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+211,0,"dc_dev_rrdy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+209,0,"dc_cpu_ren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+210,0,"dc_cpu_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"dc_dev_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"dc_dev_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+184,0,"m_axi_awaddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"m_axi_awlen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"m_axi_awsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"m_axi_awburst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+185,0,"m_axi_awvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"m_axi_awready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"m_axi_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"m_axi_wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+425,0,"m_axi_wlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"m_axi_wvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+363,0,"m_axi_wready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"m_axi_bready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+429,0,"m_axi_bresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+364,0,"m_axi_bvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+190,0,"m_axi_araddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"m_axi_arlen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+427,0,"m_axi_arsize",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+428,0,"m_axi_arburst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+192,0,"m_axi_arvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+365,0,"m_axi_arready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"m_axi_rready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+366,0,"m_axi_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+429,0,"m_axi_rresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+367,0,"m_axi_rlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"m_axi_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+434,0,"GRANT_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+444,0,"CHECK_D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+445,0,"GRANT_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+446,0,"CHECK_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+447,0,"W_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+448,0,"W_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+449,0,"W_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+450,0,"R_AR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+451,0,"R_DAT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+452,0,"R_RSP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+214,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+215,0,"read_is_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+184,0,"write_addr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+186,0,"write_data_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"write_strb_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+190,0,"read_addr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+191,0,"read_len_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+216,0,"read_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+217,0,"ic_read_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+221,0,"dc_read_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_dcache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+396,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+202,0,"data_ren",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+203,0,"data_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+24,0,"data_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"data_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"data_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"data_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"data_wresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+393,0,"dev_wrdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"cpu_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+207,0,"cpu_waddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"cpu_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+211,0,"dev_rrdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+209,0,"cpu_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+210,0,"cpu_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"dev_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+225,0,"dev_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+229,0,"uncached",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+429,0,"R_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+428,0,"R_STAT0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+453,0,"R_STAT1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+230,0,"r_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+231,0,"r_nstat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+232,0,"ren_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+429,0,"W_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+428,0,"W_STAT0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+453,0,"W_STAT1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+233,0,"w_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+394,0,"w_nstat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+234,0,"wen_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+395,0,"wr_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("U_icache", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+396,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+406,0,"inst_rreq",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+407,0,"inst_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"inst_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+196,0,"inst_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+199,0,"dev_rrdy",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"cpu_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+198,0,"cpu_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+200,0,"dev_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+235,0,"dev_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+429,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+428,0,"STAT0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+453,0,"STAT1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+239,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+3,0,"nstat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
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
    tracep->declBit(c+397,0,"cpu_rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+396,0,"cpu_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+406,0,"ifetch_req",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+407,0,"ifetch_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+408,0,"ifetch_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+196,0,"ifetch_inst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"daccess_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+203,0,"daccess_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+24,0,"daccess_rvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"daccess_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"daccess_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"daccess_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"daccess_wresp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"fetch_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+240,0,"fetch_req_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+241,0,"fetch_wait",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+242,0,"fetch_discard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"fetch_buf_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+244,0,"fetch_buf_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+245,0,"fetch_buf_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"if_id_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+246,0,"if_id_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"if_id_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"id_ex_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+248,0,"id_ex_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"id_ex_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"id_ex_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+249,0,"id_ex_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"id_ex_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"id_ex_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+250,0,"id_ex_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+34,0,"id_ex_npc_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+35,0,"id_ex_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+36,0,"id_ex_alua_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"id_ex_alub_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"id_ex_ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+38,0,"id_ex_ram_wop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+39,0,"id_ex_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+252,0,"id_ex_rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+40,0,"id_ex_is_muldiv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"id_ex_mul_started",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"ex_mem_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+253,0,"ex_mem_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+203,0,"ex_mem_alu_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+254,0,"ex_mem_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"ex_mem_store_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+255,0,"ex_mem_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+256,0,"ex_mem_ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+44,0,"ex_mem_ram_wop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+45,0,"ex_mem_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+257,0,"ex_mem_rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+46,0,"ex_mem_mem_started",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"mem_wb_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"mem_wb_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+258,0,"mem_wb_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+259,0,"mem_wb_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+49,0,"mem_wb_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+260,0,"id_npc_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+261,0,"id_sext_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+262,0,"id_alua_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"id_alub_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"id_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+265,0,"id_is_mul",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+266,0,"id_is_div",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+267,0,"id_ram_rop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+268,0,"id_ram_wop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+269,0,"id_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+270,0,"id_rf_wsel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+409,0,"rf_rd1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"rf_rd2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"id_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"id_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+273,0,"id_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+274,0,"id_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+411,0,"id_rs1_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"id_rs2_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+275,0,"id_uses_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+276,0,"id_uses_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+277,0,"id_ex_is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+278,0,"load_use_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"ex_mem_can_forward",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"mem_wb_can_forward",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"ex_rs1_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"ex_rs2_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+280,0,"mem_in_progress",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+413,0,"mem_response",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+281,0,"mem_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"ex_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"ex_alu_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"ex_alu_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"ex_alu_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,0,"ex_br",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"ex_alu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,0,"mul_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+284,0,"pipe_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"ex_is_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"ex_is_jal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"ex_is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"ex_redirect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+414,0,"ex_redirect_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+285,0,"mreq_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+203,0,"mreq_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"mreq_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"mreq_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+287,0,"mem_ext_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+288,0,"mem_wb_input_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"take_fetch_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+415,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+416,0,"debug_wb_rf_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+417,0,"debug_wb_rf_wR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+418,0,"debug_wb_rf_wD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+419,0,"debug_mem_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+420,0,"debug_mem_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+421,0,"debug_mem_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+422,0,"debug_mem_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("U_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+397,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+396,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,0,"br",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"mul_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"mulu_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+54,0,"mul_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+56,0,"mulu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+59,0,"mul_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"mulu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"div_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"divu_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"div_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"divu_quo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"div_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"divu_rem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"div_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"divu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"op_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+68,0,"a_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"div_neg_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"rem_neg_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"div_zero_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"div_overflow_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+293,0,"op_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+73,0,"div_quo_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"div_rem_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"a_abs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"b_abs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("U_div", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+430,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+396,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+291,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"quotient",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"quotient_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"dividend",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+78,0,"remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+80,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+81,0,"divisor_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+83,0,"remainder_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+85,0,"remainder_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+87,0,"ge_divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+88,0,"remainder_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+90,0,"quotient_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_divu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+430,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+396,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+292,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+62,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+66,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"quotient",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"quotient_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"dividend",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+94,0,"remainder",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+96,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+97,0,"divisor_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+99,0,"remainder_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+101,0,"remainder_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+103,0,"ge_divisor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+104,0,"remainder_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+106,0,"quotient_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_mul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+430,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+396,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+289,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+54,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+59,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+454,0,"O_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+455,0,"P_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+107,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declQuad(c+110,0,"x_ext_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+112,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+59,0,"busy_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+15,0,"x_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+113,0,"prod_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+115,0,"next_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declArray(c+117,0,"next_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_mulu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+456,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+396,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+397,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+17,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+19,0,"y",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+290,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+56,0,"z",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+60,0,"busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+455,0,"O_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+457,0,"P_WID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+120,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 67,0);
    tracep->declQuad(c+123,0,"x_ext_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declBus(c+125,0,"count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+60,0,"busy_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+21,0,"x_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+126,0,"prod_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declQuad(c+128,0,"next_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 33,0);
    tracep->declArray(c+130,0,"next_product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 67,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("U_controller", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+294,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+295,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+296,0,"funct7",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+260,0,"npc_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+261,0,"sext_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+262,0,"alua_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"alub_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+264,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+265,0,"is_mul",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+266,0,"is_div",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+267,0,"ram_r_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+268,0,"ram_w_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+269,0,"rf_we",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+270,0,"rf_wsel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+297,0,"ADDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"SLTI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"SLTIU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+300,0,"XORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+301,0,"ORI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+302,0,"ANDI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"SLLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"SRLI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+305,0,"SRAI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+306,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+307,0,"SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+308,0,"SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+309,0,"SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+310,0,"SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+311,0,"XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+312,0,"SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+314,0,"OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+316,0,"MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+318,0,"MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+320,0,"DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+321,0,"REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+323,0,"LB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+324,0,"LH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+325,0,"LW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+326,0,"LBU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+327,0,"LHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+328,0,"SB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+329,0,"SH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"SW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"BEQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"BNE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"BLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+334,0,"BGE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+335,0,"BLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+336,0,"BGEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+337,0,"LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+338,0,"JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+339,0,"JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+340,0,"NPC_OP_BRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+339,0,"NPC_OP_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+338,0,"NPC_OP_JMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+341,0,"NPC_OP_PC4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"RF_OP_WE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"WB_OP_ALU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+343,0,"WB_OP_RAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+344,0,"WB_OP_PC4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+337,0,"WB_OP_EXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+345,0,"EXT_OP_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+346,0,"EXT_OP_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+340,0,"EXT_OP_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+347,0,"EXT_OP_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+338,0,"EXT_OP_J",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+348,0,"ALU_OP_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+307,0,"ALU_OP_SUB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+349,0,"ALU_OP_AND",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+350,0,"ALU_OP_OR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+351,0,"ALU_OP_XOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+352,0,"ALU_OP_SLL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"ALU_OP_SRL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+354,0,"ALU_OP_SRA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"ALU_OP_EQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"ALU_OP_NE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"ALU_OP_LT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+334,0,"ALU_OP_GE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+335,0,"ALU_OP_LTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+336,0,"ALU_OP_GEU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+355,0,"ALU_OP_SLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+356,0,"ALU_OP_SLTU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+316,0,"ALU_OP_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"ALU_OP_MULH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+318,0,"ALU_OP_MULHU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"ALU_OP_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+320,0,"ALU_OP_DIVU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+321,0,"ALU_OP_REM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"ALU_OP_REMU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+357,0,"ALU_A_SEL_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"ALU_A_SEL_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"ALU_B_SEL_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"ALU_B_SEL_EXT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+323,0,"RAM_EXT_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+326,0,"RAM_EXT_BU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+324,0,"RAM_EXT_H",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+327,0,"RAM_EXT_HU",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+325,0,"RAM_EXT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+328,0,"RAM_W_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+329,0,"RAM_W_H",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"RAM_W_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("U_mext", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+256,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+25,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+359,0,"byte_offs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+287,0,"ext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+360,0,"real_din",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_mreq", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+203,0,"ram_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+256,0,"ram_rop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+285,0,"da_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+203,0,"da_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"ram_wop",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+43,0,"ram_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"da_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+205,0,"da_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+359,0,"offset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("U_rf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+396,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+272,0,"rR1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+273,0,"rR2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+416,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+259,0,"wR",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+258,0,"wD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+409,0,"rD1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"rD2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 31; ++i) {
        tracep->declBus(c+153+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+1), 31,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("U_sext", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+261,0,"op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+361,0,"imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,7);
    tracep->declBus(c+271,0,"ext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
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
    bufp->fullSData(oldp+423,(0U),16);
    bufp->fullCData(oldp+424,(0xffU),8);
    bufp->fullBit(oldp+425,(1U));
    bufp->fullCData(oldp+426,(0U),8);
    bufp->fullCData(oldp+427,(2U),3);
    bufp->fullCData(oldp+428,(1U),2);
    bufp->fullCData(oldp+429,(0U),2);
    bufp->fullIData(oldp+430,(0x20U),32);
    bufp->fullIData(oldp+431,(0x2000U),32);
    bufp->fullIData(oldp+432,(4U),32);
    bufp->fullIData(oldp+433,(0U),32);
    bufp->fullCData(oldp+434,(0U),4);
    bufp->fullBit(oldp+435,(0U));
    bufp->fullCData(oldp+436,(0U),3);
    bufp->fullIData(oldp+437,(0x1eU),32);
    bufp->fullIData(oldp+438,(8U),32);
    bufp->fullBit(oldp+439,(0U));
    bufp->fullBit(oldp+440,(1U));
    bufp->fullCData(oldp+441,(2U),2);
    bufp->fullIData(oldp+442,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_next),32);
    bufp->fullIData(oldp+443,(0xdU),32);
    bufp->fullCData(oldp+444,(1U),4);
    bufp->fullCData(oldp+445,(2U),4);
    bufp->fullCData(oldp+446,(3U),4);
    bufp->fullCData(oldp+447,(4U),4);
    bufp->fullCData(oldp+448,(5U),4);
    bufp->fullCData(oldp+449,(6U),4);
    bufp->fullCData(oldp+450,(7U),4);
    bufp->fullCData(oldp+451,(8U),4);
    bufp->fullCData(oldp+452,(9U),4);
    bufp->fullCData(oldp+453,(3U),2);
    bufp->fullIData(oldp+454,(0x40U),32);
    bufp->fullIData(oldp+455,(0x42U),32);
    bufp->fullIData(oldp+456,(0x21U),32);
    bufp->fullIData(oldp+457,(0x44U),32);
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
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    bufp->fullIData(oldp+1,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__j),32);
    bufp->fullIData(oldp+2,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__mem_file),32);
    bufp->fullCData(oldp+3,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_icache__DOT__nstat),2);
    bufp->fullBit(oldp+4,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_can_forward));
    bufp->fullIData(oldp+5,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_rs1_value),32);
    bufp->fullIData(oldp+6,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_rs2_value),32);
    bufp->fullIData(oldp+7,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a),32);
    bufp->fullIData(oldp+8,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b),32);
    bufp->fullIData(oldp+9,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_c),32);
    bufp->fullBit(oldp+10,(((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op) 
                                      >> 4U))) && (
                                                   (1U 
                                                    & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op) 
                                                       >> 3U)) 
                                                   && ((4U 
                                                        & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                        ? 
                                                       ((1U 
                                                         & (~ 
                                                            ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op) 
                                                             >> 1U))) 
                                                        && ((1U 
                                                             & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                             ? 
                                                            (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                             >= vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)
                                                             : 
                                                            (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                             < vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                          ? 
                                                         VL_GTES_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)
                                                          : 
                                                         VL_LTS_III(32, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a, vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b))
                                                         : 
                                                        ((1U 
                                                          & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))
                                                          ? 
                                                         (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                          != vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b)
                                                          : 
                                                         (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                          == vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b))))))));
    bufp->fullBit(oldp+11,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_redirect));
    bufp->fullBit(oldp+12,(((~ (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pipe_stall)) 
                            & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_valid) 
                               & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__VdfgRegularize_h6dbabbbd_0_6)))));
    bufp->fullIData(oldp+13,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__a_abs),32);
    bufp->fullIData(oldp+14,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__b_abs),32);
    bufp->fullQData(oldp+15,((((QData)((IData)((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a 
                                                >> 0x1fU))) 
                               << 0x20U) | (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a)))),33);
    bufp->fullQData(oldp+17,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a))),33);
    bufp->fullQData(oldp+19,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_b))),33);
    bufp->fullQData(oldp+21,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_a))),34);
    bufp->fullBit(oldp+23,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2cpu_valid));
    bufp->fullBit(oldp+24,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid));
    bufp->fullIData(oldp+25,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata),32);
    bufp->fullBit(oldp+26,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp));
    bufp->fullIData(oldp+27,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_pc),32);
    bufp->fullBit(oldp+28,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_valid));
    bufp->fullBit(oldp+29,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_valid));
    bufp->fullIData(oldp+30,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs1_data),32);
    bufp->fullIData(oldp+31,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs2_data),32);
    bufp->fullCData(oldp+32,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs1),5);
    bufp->fullCData(oldp+33,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rs2),5);
    bufp->fullCData(oldp+34,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op),2);
    bufp->fullCData(oldp+35,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alu_op),5);
    bufp->fullBit(oldp+36,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alua_sel));
    bufp->fullBit(oldp+37,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_alub_sel));
    bufp->fullCData(oldp+38,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_wop),4);
    bufp->fullBit(oldp+39,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_we));
    bufp->fullBit(oldp+40,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_is_muldiv));
    bufp->fullBit(oldp+41,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_mul_started));
    bufp->fullBit(oldp+42,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_valid));
    bufp->fullIData(oldp+43,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_store_data),32);
    bufp->fullCData(oldp+44,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_wop),4);
    bufp->fullBit(oldp+45,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_we));
    bufp->fullBit(oldp+46,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_mem_started));
    bufp->fullBit(oldp+47,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_valid));
    bufp->fullIData(oldp+48,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_pc),32);
    bufp->fullBit(oldp+49,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rf_we));
    bufp->fullBit(oldp+50,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_busy));
    bufp->fullBit(oldp+51,((2U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
    bufp->fullBit(oldp+52,((3U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
    bufp->fullBit(oldp+53,((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))));
    bufp->fullQData(oldp+54,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__mul_res),64);
    bufp->fullWData(oldp+56,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__mulu_res),66);
    bufp->fullBit(oldp+59,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__busy_r));
    bufp->fullBit(oldp+60,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__busy_r));
    bufp->fullIData(oldp+61,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_out),32);
    bufp->fullIData(oldp+62,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__quotient_out),32);
    bufp->fullIData(oldp+63,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_rem),32);
    bufp->fullIData(oldp+64,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__divu_rem),32);
    bufp->fullBit(oldp+65,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_busy));
    bufp->fullBit(oldp+66,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__divu_busy));
    bufp->fullCData(oldp+67,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__op_r),5);
    bufp->fullIData(oldp+68,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__a_r),32);
    bufp->fullBit(oldp+69,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_neg_r));
    bufp->fullBit(oldp+70,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__rem_neg_r));
    bufp->fullBit(oldp+71,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_zero_r));
    bufp->fullBit(oldp+72,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_overflow_r));
    bufp->fullIData(oldp+73,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_neg_r)
                               ? ((IData)(1U) + (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_out))
                               : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_out)),32);
    bufp->fullIData(oldp+74,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__rem_neg_r)
                               ? ((IData)(1U) + (~ vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_rem))
                               : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_rem)),32);
    bufp->fullIData(oldp+75,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient),32);
    bufp->fullIData(oldp+76,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__dividend),32);
    bufp->fullIData(oldp+77,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__divisor),32);
    bufp->fullQData(oldp+78,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder),33);
    bufp->fullCData(oldp+80,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__count),8);
    bufp->fullQData(oldp+81,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__divisor))),33);
    bufp->fullQData(oldp+83,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder_shift),33);
    bufp->fullQData(oldp+85,((0x1ffffffffULL & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder_shift 
                                                - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__divisor))))),33);
    bufp->fullBit(oldp+87,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__ge_divisor));
    bufp->fullQData(oldp+88,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__remainder_next),33);
    bufp->fullIData(oldp+90,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_div__DOT__quotient_next),32);
    bufp->fullIData(oldp+91,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__quotient),32);
    bufp->fullIData(oldp+92,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__dividend),32);
    bufp->fullIData(oldp+93,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__divisor),32);
    bufp->fullQData(oldp+94,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder),33);
    bufp->fullCData(oldp+96,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__count),8);
    bufp->fullQData(oldp+97,((QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__divisor))),33);
    bufp->fullQData(oldp+99,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift),33);
    bufp->fullQData(oldp+101,((0x1ffffffffULL & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift 
                                                 - (QData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__divisor))))),33);
    bufp->fullBit(oldp+103,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__ge_divisor));
    bufp->fullQData(oldp+104,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__remainder_next),33);
    bufp->fullIData(oldp+106,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_divu__DOT__quotient_next),32);
    bufp->fullWData(oldp+107,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__product),66);
    bufp->fullQData(oldp+110,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__x_ext_r),33);
    bufp->fullCData(oldp+112,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__count),8);
    bufp->fullQData(oldp+113,((0x1ffffffffULL & (((QData)((IData)(
                                                                  vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__product[1U])) 
                                                    >> 1U)))),33);
    bufp->fullQData(oldp+115,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__next_high),33);
    bufp->fullWData(oldp+117,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mul__DOT__next_product),66);
    bufp->fullWData(oldp+120,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__product),68);
    bufp->fullQData(oldp+123,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__x_ext_r),34);
    bufp->fullCData(oldp+125,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__count),8);
    bufp->fullQData(oldp+126,((0x3ffffffffULL & (((QData)((IData)(
                                                                  vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                                  << 0x1eU) 
                                                 | ((QData)((IData)(
                                                                    vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__product[1U])) 
                                                    >> 2U)))),34);
    bufp->fullQData(oldp+128,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__next_high),34);
    bufp->fullWData(oldp+130,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__U_mulu__DOT__next_product),68);
    bufp->fullCData(oldp+133,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bid_reg),4);
    bufp->fullCData(oldp+134,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rid_reg),4);
    bufp->fullBit(oldp+135,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_state_reg));
    bufp->fullCData(oldp+136,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_state_reg),2);
    bufp->fullCData(oldp+137,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_id_reg),4);
    bufp->fullCData(oldp+138,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_count_reg),8);
    bufp->fullCData(oldp+139,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_size_reg),3);
    bufp->fullCData(oldp+140,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_burst_reg),2);
    bufp->fullCData(oldp+141,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_id_reg),4);
    bufp->fullIData(oldp+142,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_reg),32);
    bufp->fullCData(oldp+143,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_count_reg),8);
    bufp->fullCData(oldp+144,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_size_reg),3);
    bufp->fullCData(oldp+145,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_burst_reg),2);
    bufp->fullCData(oldp+146,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rid_pipe_reg),4);
    bufp->fullIData(oldp+147,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_pipe_reg),32);
    bufp->fullBit(oldp+148,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rlast_pipe_reg));
    bufp->fullBit(oldp+149,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rvalid_pipe_reg));
    bufp->fullIData(oldp+150,((vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_reg 
                               >> 2U)),30);
    bufp->fullBit(oldp+151,((0xffffU != (vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_reg 
                                         >> 0x10U))));
    bufp->fullIData(oldp+152,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__i),32);
    bufp->fullIData(oldp+153,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[0]),32);
    bufp->fullIData(oldp+154,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[1]),32);
    bufp->fullIData(oldp+155,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[2]),32);
    bufp->fullIData(oldp+156,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[3]),32);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[4]),32);
    bufp->fullIData(oldp+158,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[5]),32);
    bufp->fullIData(oldp+159,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[6]),32);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[7]),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[8]),32);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[9]),32);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[10]),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[11]),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[12]),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[13]),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[14]),32);
    bufp->fullIData(oldp+168,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[15]),32);
    bufp->fullIData(oldp+169,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[16]),32);
    bufp->fullIData(oldp+170,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[17]),32);
    bufp->fullIData(oldp+171,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[18]),32);
    bufp->fullIData(oldp+172,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[19]),32);
    bufp->fullIData(oldp+173,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[20]),32);
    bufp->fullIData(oldp+174,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[21]),32);
    bufp->fullIData(oldp+175,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[22]),32);
    bufp->fullIData(oldp+176,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[23]),32);
    bufp->fullIData(oldp+177,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[24]),32);
    bufp->fullIData(oldp+178,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[25]),32);
    bufp->fullIData(oldp+179,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[26]),32);
    bufp->fullIData(oldp+180,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[27]),32);
    bufp->fullIData(oldp+181,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[28]),32);
    bufp->fullIData(oldp+182,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[29]),32);
    bufp->fullIData(oldp+183,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs[30]),32);
    bufp->fullIData(oldp+184,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_addr_r),32);
    bufp->fullBit(oldp+185,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_awvalid));
    bufp->fullIData(oldp+186,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_data_r),32);
    bufp->fullCData(oldp+187,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_strb_r),4);
    bufp->fullBit(oldp+188,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_wvalid));
    bufp->fullBit(oldp+189,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_bready));
    bufp->fullIData(oldp+190,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_addr_r),32);
    bufp->fullCData(oldp+191,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_len_r),8);
    bufp->fullBit(oldp+192,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_arvalid));
    bufp->fullBit(oldp+193,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__m_axi_rready));
    bufp->fullIData(oldp+194,((vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__write_addr_r 
                               >> 2U)),30);
    bufp->fullIData(oldp+195,((vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_addr_r 
                               >> 2U)),30);
    bufp->fullIData(oldp+196,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2cpu_inst),32);
    bufp->fullCData(oldp+197,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2axi_ren),4);
    bufp->fullIData(oldp+198,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__ic2axi_addr),32);
    bufp->fullBit(oldp+199,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2ic_rrdy));
    bufp->fullBit(oldp+200,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2ic_rvalid));
    bufp->fullIData(oldp+201,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__ic_read_buf[0U]),32);
    bufp->fullCData(oldp+202,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren),4);
    bufp->fullIData(oldp+203,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c),32);
    bufp->fullCData(oldp+204,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen),4);
    bufp->fullIData(oldp+205,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mreq_wdata),32);
    bufp->fullCData(oldp+206,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_wen),4);
    bufp->fullIData(oldp+207,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_waddr),32);
    bufp->fullIData(oldp+208,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_wdata),32);
    bufp->fullCData(oldp+209,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_ren),4);
    bufp->fullIData(oldp+210,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2axi_raddr),32);
    bufp->fullBit(oldp+211,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2dc_rrdy));
    bufp->fullBit(oldp+212,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2dc_rvalid));
    bufp->fullIData(oldp+213,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__dc_read_buf[0U]),32);
    bufp->fullCData(oldp+214,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__state),4);
    bufp->fullBit(oldp+215,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_is_data));
    bufp->fullCData(oldp+216,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__read_count),2);
    bufp->fullWData(oldp+217,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__ic_read_buf),128);
    bufp->fullWData(oldp+221,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__dc_read_buf),128);
    __Vtemp_1[0U] = vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__dc_read_buf[0U];
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    __Vtemp_1[3U] = 0U;
    bufp->fullWData(oldp+225,(__Vtemp_1),128);
    bufp->fullBit(oldp+229,(((0xffffU == (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c 
                                          >> 0x10U)) 
                             & ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_ren)) 
                                | (0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__daccess_wen))))));
    bufp->fullCData(oldp+230,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__r_state),2);
    bufp->fullCData(oldp+231,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__r_nstat),2);
    bufp->fullCData(oldp+232,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__ren_r),4);
    bufp->fullCData(oldp+233,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__w_state),2);
    bufp->fullCData(oldp+234,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__wen_r),4);
    __Vtemp_2[0U] = vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_axi_master__DOT__ic_read_buf[0U];
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    __Vtemp_2[3U] = 0U;
    bufp->fullWData(oldp+235,(__Vtemp_2),128);
    bufp->fullCData(oldp+239,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_icache__DOT__state),2);
    bufp->fullIData(oldp+240,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_req_pc),32);
    bufp->fullBit(oldp+241,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_wait));
    bufp->fullBit(oldp+242,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_discard));
    bufp->fullBit(oldp+243,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_valid));
    bufp->fullIData(oldp+244,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_pc),32);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__fetch_buf_inst),32);
    bufp->fullIData(oldp+246,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_pc),32);
    bufp->fullIData(oldp+247,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst),32);
    bufp->fullIData(oldp+248,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_pc),32);
    bufp->fullIData(oldp+249,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ext),32);
    bufp->fullCData(oldp+250,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rd),5);
    bufp->fullCData(oldp+251,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_rop),3);
    bufp->fullCData(oldp+252,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_rf_wsel),2);
    bufp->fullIData(oldp+253,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_pc),32);
    bufp->fullIData(oldp+254,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ext),32);
    bufp->fullCData(oldp+255,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rd),5);
    bufp->fullCData(oldp+256,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop),3);
    bufp->fullCData(oldp+257,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel),2);
    bufp->fullIData(oldp+258,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_data),32);
    bufp->fullCData(oldp+259,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rd),5);
    bufp->fullCData(oldp+260,((3U & ((1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR)))) 
                                     | ((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA)))) 
                                        | (- (IData)(
                                                     (0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))))))),2);
    bufp->fullCData(oldp+261,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_sext_op),3);
    bufp->fullBit(oldp+262,((0x17U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
    bufp->fullBit(oldp+263,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                          | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA))))))))))))))))));
    bufp->fullCData(oldp+264,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_alu_op),5);
    bufp->fullBit(oldp+265,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29))));
    bufp->fullBit(oldp+266,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_is_div));
    bufp->fullCData(oldp+267,(((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB)))) 
                               | ((3U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU)))) 
                                  | ((4U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)))) 
                                     | ((5U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU)))) 
                                        | (1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW))))))))),3);
    bufp->fullCData(oldp+268,((0xfU & ((1U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB)))) 
                                       | ((3U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH)))) 
                                          | (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW))))))),4);
    bufp->fullBit(oldp+269,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI) 
                                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))))))))) 
                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_is_div))))))))))))) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH) 
                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW)) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__EXT_OP_U) 
                                         | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__WB_OP_PC4))))))));
    bufp->fullCData(oldp+270,((3U & ((1U & (- (IData)(
                                                      (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                                        | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)) 
                                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW) 
                                                          | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33)))))) 
                                     | ((2U & (- (IData)((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__WB_OP_PC4)))) 
                                        | (- (IData)(
                                                     (0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))))))),2);
    bufp->fullIData(oldp+271,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ext),32);
    bufp->fullCData(oldp+272,((0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+273,((0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+274,((0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                        >> 7U))),5);
    bufp->fullBit(oldp+275,(((0x13U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                             | ((0x33U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                | ((3U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                   | ((0x23U == (0x7fU 
                                                 & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                      | ((0x63U == 
                                          (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                         | (0x67U == 
                                            (0x7fU 
                                             & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))))))));
    bufp->fullBit(oldp+276,(((0x33U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                             | ((0x23U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                | (0x63U == (0x7fU 
                                             & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))))));
    bufp->fullBit(oldp+277,((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ram_rop))));
    bufp->fullBit(oldp+278,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__load_use_stall));
    bufp->fullBit(oldp+279,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_can_forward));
    bufp->fullBit(oldp+280,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_in_progress));
    bufp->fullBit(oldp+281,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_stall));
    bufp->fullCData(oldp+282,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op),5);
    bufp->fullBit(oldp+283,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mul_stall));
    bufp->fullBit(oldp+284,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__pipe_stall));
    bufp->fullCData(oldp+285,(((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                ? ((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                    ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                        ? ((0U == (3U 
                                                   & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c))
                                            ? 0xfU : 0U)
                                        : ((1U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)
                                            ? 0U : 0xfU))
                                    : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                        ? 0xfU : ((0U 
                                                   == 
                                                   (3U 
                                                    & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c))
                                                   ? 0xfU
                                                   : 0U)))
                                : 0U)),4);
    bufp->fullCData(oldp+286,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mreq_wen),4);
    bufp->fullIData(oldp+287,(((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                    ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din
                                    : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                        ? (0xffffU 
                                           & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                        : (((- (IData)(
                                                       (1U 
                                                        & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                           >> 0xfU)))) 
                                            << 0x10U) 
                                           | (0xffffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))))
                                : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                    ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                        ? (0xffU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                        : (((- (IData)(
                                                       (1U 
                                                        & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                           >> 7U)))) 
                                            << 8U) 
                                           | (0xffU 
                                              & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)))
                                    : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))),32);
    bufp->fullIData(oldp+288,(((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel))
                                ? ((4U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                    ? ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                        ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din
                                        : ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                            ? (0xffffU 
                                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                            : (((- (IData)(
                                                           (1U 
                                                            & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                               >> 0xfU)))) 
                                                << 0x10U) 
                                               | (0xffffU 
                                                  & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))))
                                    : ((2U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                        ? ((1U & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop))
                                            ? (0xffU 
                                               & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)
                                            : (((- (IData)(
                                                           (1U 
                                                            & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din 
                                                               >> 7U)))) 
                                                << 8U) 
                                               | (0xffU 
                                                  & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din)))
                                        : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din))
                                : ((2U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel))
                                    ? ((IData)(4U) 
                                       + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_pc)
                                    : ((3U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_rf_wsel))
                                        ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ext
                                        : vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)))),32);
    bufp->fullBit(oldp+289,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__mul_flag));
    bufp->fullBit(oldp+290,((0x12U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_alu_op))));
    bufp->fullBit(oldp+291,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__div_flag));
    bufp->fullBit(oldp+292,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__divu_flag));
    bufp->fullCData(oldp+293,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_alu__DOT__op_eff),5);
    bufp->fullCData(oldp+294,((0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)),7);
    bufp->fullCData(oldp+295,((7U & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+296,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                               >> 0x19U)),7);
    bufp->fullBit(oldp+297,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI));
    bufp->fullBit(oldp+298,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI));
    bufp->fullBit(oldp+299,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU));
    bufp->fullBit(oldp+300,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI));
    bufp->fullBit(oldp+301,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI));
    bufp->fullBit(oldp+302,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI));
    bufp->fullBit(oldp+303,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI));
    bufp->fullBit(oldp+304,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI));
    bufp->fullBit(oldp+305,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI));
    bufp->fullBit(oldp+306,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD));
    bufp->fullBit(oldp+307,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SUB));
    bufp->fullBit(oldp+308,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLL));
    bufp->fullBit(oldp+309,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT));
    bufp->fullBit(oldp+310,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU));
    bufp->fullBit(oldp+311,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR));
    bufp->fullBit(oldp+312,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL));
    bufp->fullBit(oldp+313,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA));
    bufp->fullBit(oldp+314,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR));
    bufp->fullBit(oldp+315,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND));
    bufp->fullBit(oldp+316,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL));
    bufp->fullBit(oldp+317,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MULH));
    bufp->fullBit(oldp+318,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MULHU));
    bufp->fullBit(oldp+319,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__DIV));
    bufp->fullBit(oldp+320,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__DIVU));
    bufp->fullBit(oldp+321,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__REM));
    bufp->fullBit(oldp+322,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__REMU));
    bufp->fullBit(oldp+323,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB));
    bufp->fullBit(oldp+324,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH));
    bufp->fullBit(oldp+325,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW));
    bufp->fullBit(oldp+326,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU));
    bufp->fullBit(oldp+327,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU));
    bufp->fullBit(oldp+328,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB));
    bufp->fullBit(oldp+329,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH));
    bufp->fullBit(oldp+330,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW));
    bufp->fullBit(oldp+331,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BEQ));
    bufp->fullBit(oldp+332,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BNE));
    bufp->fullBit(oldp+333,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BLT));
    bufp->fullBit(oldp+334,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BGE));
    bufp->fullBit(oldp+335,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BLTU));
    bufp->fullBit(oldp+336,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__BGEU));
    bufp->fullBit(oldp+337,((0x37U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
    bufp->fullBit(oldp+338,((0x6fU == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
    bufp->fullBit(oldp+339,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR));
    bufp->fullBit(oldp+340,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA));
    bufp->fullBit(oldp+341,((1U & (~ ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR) 
                                         | (0x6fU == 
                                            (0x7fU 
                                             & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))))))));
    bufp->fullBit(oldp+342,(((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI) 
                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU) 
                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI) 
                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI) 
                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI) 
                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI) 
                                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI) 
                                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))))))))) 
                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                               | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_is_div))))))))))))) 
                             | (0x17U == (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)))));
    bufp->fullBit(oldp+343,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                              | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW) 
                                | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33)))));
    bufp->fullBit(oldp+344,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__WB_OP_PC4));
    bufp->fullBit(oldp+345,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI) 
                                 | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU) 
                                    | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI) 
                                       | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI) 
                                          | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI) 
                                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI) 
                                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI) 
                                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))))))))) 
                             | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH)) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU) 
                                         | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR))))))));
    bufp->fullBit(oldp+346,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB) 
                              | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH)) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW))));
    bufp->fullBit(oldp+347,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__EXT_OP_U));
    bufp->fullBit(oldp+348,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADDI) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LB) 
                                | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LH) 
                                    | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LW)) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LBU) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__LHU) 
                                         | (((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SB) 
                                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SH)) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SW) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                                                  | ((0x17U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst)) 
                                                     | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__JALR))))))))))));
    bufp->fullBit(oldp+349,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ANDI))));
    bufp->fullBit(oldp+350,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ORI))));
    bufp->fullBit(oldp+351,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XORI))));
    bufp->fullBit(oldp+352,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLL) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLLI))));
    bufp->fullBit(oldp+353,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRLI))));
    bufp->fullBit(oldp+354,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRAI))));
    bufp->fullBit(oldp+355,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTI))));
    bufp->fullBit(oldp+356,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                             | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTIU))));
    bufp->fullBit(oldp+357,((0x17U != (0x7fU & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst))));
    bufp->fullBit(oldp+358,(((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__ADD) 
                             | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31) 
                                | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLT) 
                                   | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SLTU) 
                                      | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__XOR) 
                                         | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRL) 
                                            | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__SRA) 
                                               | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__OR) 
                                                  | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__AND) 
                                                     | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__MUL) 
                                                        | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29) 
                                                           | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                                              | ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_28) 
                                                                 | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_controller__DOT__NPC_OP_BRA))))))))))))))));
    bufp->fullCData(oldp+359,((3U & vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_alu_c)),2);
    bufp->fullIData(oldp+360,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_mext__DOT__real_din),32);
    bufp->fullIData(oldp+361,((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                               >> 7U)),25);
    bufp->fullBit(oldp+362,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_awready_reg));
    bufp->fullBit(oldp+363,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_wready_reg));
    bufp->fullBit(oldp+364,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bvalid_reg));
    bufp->fullBit(oldp+365,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_arready_reg));
    bufp->fullIData(oldp+366,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rdata_reg),32);
    bufp->fullBit(oldp+367,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rlast_reg));
    bufp->fullBit(oldp+368,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rvalid_reg));
    bufp->fullIData(oldp+369,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_addr_reg),32);
    bufp->fullIData(oldp+370,((vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_addr_reg 
                               >> 2U)),30);
    bufp->fullBit(oldp+371,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_state_next));
    bufp->fullCData(oldp+372,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_state_next),2);
    bufp->fullBit(oldp+373,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__mem_wr_en));
    bufp->fullBit(oldp+374,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__mem_rd_en));
    bufp->fullCData(oldp+375,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_id_next),4);
    bufp->fullIData(oldp+376,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_addr_next),32);
    bufp->fullCData(oldp+377,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_count_next),8);
    bufp->fullCData(oldp+378,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_size_next),3);
    bufp->fullCData(oldp+379,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__read_burst_next),2);
    bufp->fullCData(oldp+380,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_id_next),4);
    bufp->fullIData(oldp+381,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_addr_next),32);
    bufp->fullCData(oldp+382,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_count_next),8);
    bufp->fullCData(oldp+383,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_size_next),3);
    bufp->fullCData(oldp+384,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__write_burst_next),2);
    bufp->fullBit(oldp+385,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_awready_next));
    bufp->fullBit(oldp+386,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_wready_next));
    bufp->fullCData(oldp+387,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bid_next),4);
    bufp->fullBit(oldp+388,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_bvalid_next));
    bufp->fullBit(oldp+389,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_arready_next));
    bufp->fullCData(oldp+390,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rid_next),4);
    bufp->fullBit(oldp+391,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rlast_next));
    bufp->fullBit(oldp+392,(vlSymsp->TOP__miniRV_SoC.__PVT__U_trace_bram__DOT__s_axi_rvalid_next));
    bufp->fullBit(oldp+393,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__axi2dc_wrdy));
    bufp->fullCData(oldp+394,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__w_nstat),2);
    bufp->fullBit(oldp+395,(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__U_dcache__DOT__wr_resp));
    bufp->fullBit(oldp+396,(vlSelfRef.fpga_clk));
    bufp->fullBit(oldp+397,(vlSelfRef.fpga_rst));
    bufp->fullSData(oldp+398,(vlSelfRef.sw),16);
    bufp->fullSData(oldp+399,(vlSelfRef.led),16);
    bufp->fullCData(oldp+400,(vlSelfRef.dig_en),8);
    bufp->fullCData(oldp+401,(vlSelfRef.dig_seg),8);
    bufp->fullCData(oldp+402,(vlSelfRef.dig_seg1),8);
    bufp->fullBit(oldp+403,(vlSelfRef.rx));
    bufp->fullBit(oldp+404,(vlSelfRef.tx));
    bufp->fullBit(oldp+405,((1U & (~ (IData)(vlSelfRef.fpga_rst)))));
    bufp->fullBit(oldp+406,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_req));
    bufp->fullIData(oldp+407,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_addr),32);
    bufp->fullBit(oldp+408,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.ifetch_valid));
    bufp->fullIData(oldp+409,(((0U == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                >> 0xfU)))
                                ? 0U : ((0x1eU >= (0x1fU 
                                                   & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                       >> 0xfU) 
                                                      - (IData)(1U))))
                                         ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                        [(0x1fU & (
                                                   (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                    >> 0xfU) 
                                                   - (IData)(1U)))]
                                         : 0U))),32);
    bufp->fullIData(oldp+410,(((0U == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                >> 0x14U)))
                                ? 0U : ((0x1eU >= (0x1fU 
                                                   & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                       >> 0x14U) 
                                                      - (IData)(1U))))
                                         ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                        [(0x1fU & (
                                                   (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                    >> 0x14U) 
                                                   - (IData)(1U)))]
                                         : 0U))),32);
    bufp->fullIData(oldp+411,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_can_forward) 
                                & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rd) 
                                   == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                >> 0xfU))))
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_data
                                : ((0U == (0x1fU & 
                                           (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                            >> 0xfU)))
                                    ? 0U : ((0x1eU 
                                             >= (0x1fU 
                                                 & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                     >> 0xfU) 
                                                    - (IData)(1U))))
                                             ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                            [(0x1fU 
                                              & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                  >> 0xfU) 
                                                 - (IData)(1U)))]
                                             : 0U)))),32);
    bufp->fullIData(oldp+412,((((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_can_forward) 
                                & ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_rd) 
                                   == (0x1fU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                >> 0x14U))))
                                ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__mem_wb_data
                                : ((0U == (0x1fU & 
                                           (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                            >> 0x14U)))
                                    ? 0U : ((0x1eU 
                                             >= (0x1fU 
                                                 & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                     >> 0x14U) 
                                                    - (IData)(1U))))
                                             ? vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__U_rf__DOT__regs
                                            [(0x1fU 
                                              & ((vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__if_id_inst 
                                                  >> 0x14U) 
                                                 - (IData)(1U)))]
                                             : 0U)))),32);
    bufp->fullBit(oldp+413,((((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_rop)) 
                              & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid)) 
                             | ((0U != (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_mem_ram_wop)) 
                                & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp)))));
    bufp->fullIData(oldp+414,(((1U == (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_npc_op))
                                ? (0xfffffffeU & (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__ex_rs1_value 
                                                  + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ext))
                                : (vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_ext 
                                   + vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.__PVT__id_ex_pc))),32);
    bufp->fullIData(oldp+415,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_pc),32);
    bufp->fullBit(oldp+416,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_we));
    bufp->fullCData(oldp+417,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wR),5);
    bufp->fullIData(oldp+418,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_wb_rf_wD),32);
    bufp->fullIData(oldp+419,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_pc),32);
    bufp->fullCData(oldp+420,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_we),4);
    bufp->fullIData(oldp+421,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_waddr),32);
    bufp->fullIData(oldp+422,(vlSymsp->TOP__miniRV_SoC__U_cpu__U_core.debug_mem_wdata),32);
}
