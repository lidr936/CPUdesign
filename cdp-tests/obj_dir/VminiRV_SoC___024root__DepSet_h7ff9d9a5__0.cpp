// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__ico(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG

void VminiRV_SoC___024root___eval_triggers__ico(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void VminiRV_SoC_Inst_ROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC_Inst_ROM* vlSelf);
void VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);

void VminiRV_SoC___024root___eval_ico(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VminiRV_SoC_Inst_ROM___ico_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom));
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        VminiRV_SoC_cpu_core___ico_sequent__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VminiRV_SoC___024root___dump_triggers__act(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG

void VminiRV_SoC___024root___eval_triggers__act(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.fpga_clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.fpga_rst) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__0))));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_clk__0 = vlSelfRef.fpga_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__fpga_rst__0 = vlSelfRef.fpga_rst;
    vlSelfRef.__Vtrigprevexpr___TOP__miniRV_SoC__U_cpu__U_irom__U_irom__clka__0 
        = vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom.clka;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VminiRV_SoC___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0(VminiRV_SoC_cpu_top* vlSelf);
void VminiRV_SoC_Inst_ROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0(VminiRV_SoC_Inst_ROM* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__1(VminiRV_SoC_cpu_top* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__2(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__3(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2(VminiRV_SoC_cpu_top* vlSelf);
void VminiRV_SoC_IROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0(VminiRV_SoC_IROM* vlSelf);
void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4(VminiRV_SoC_cpu_core* vlSelf);
void VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1(VminiRV_SoC_cpu_core* vlSelf);

void VminiRV_SoC___024root___eval_nba(VminiRV_SoC___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VminiRV_SoC___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__0((&vlSymsp->TOP__miniRV_SoC__U_cpu));
        VminiRV_SoC_Inst_ROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom));
        VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__1((&vlSymsp->TOP__miniRV_SoC__U_cpu));
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__2((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__3((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        VminiRV_SoC_cpu_top___nba_sequent__TOP__miniRV_SoC__U_cpu__2((&vlSymsp->TOP__miniRV_SoC__U_cpu));
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VminiRV_SoC_IROM___nba_sequent__TOP__miniRV_SoC__U_cpu__U_irom__U_irom__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_irom__U_irom));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__0((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
        VminiRV_SoC_cpu_core___nba_sequent__TOP__miniRV_SoC__U_cpu__U_core__4((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VminiRV_SoC_cpu_core___nba_comb__TOP__miniRV_SoC__U_cpu__U_core__1((&vlSymsp->TOP__miniRV_SoC__U_cpu__U_core));
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}
