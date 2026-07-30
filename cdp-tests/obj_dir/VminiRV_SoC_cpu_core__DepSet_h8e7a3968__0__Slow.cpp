// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC__Syms.h"
#include "VminiRV_SoC_cpu_core.h"

VL_ATTR_COLD void VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0(VminiRV_SoC_cpu_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          VminiRV_SoC_cpu_core___stl_sequent__TOP__miniRV_SoC__U_cpu__U_core__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    // Body
    vlSelfRef.ifetch_addr = vlSelfRef.__PVT__pc;
    vlSelfRef.debug_mem_pc = vlSelfRef.__PVT__pc;
    vlSelfRef.debug_mem_waddr = vlSelfRef.__PVT__daccess_addr;
    vlSelfRef.debug_mem_we = vlSelfRef.__PVT__daccess_wen;
    vlSelfRef.debug_mem_wdata = vlSelfRef.__PVT__store_wdata_r;
    vlSelfRef.ifetch_req = (((~ (IData)(vlSymsp->TOP.fpga_rst)) 
                             & (IData)(vlSelfRef.__PVT__rst_r)) 
                            | (IData)(vlSelfRef.__PVT__inst_finished_r));
    vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__next_high 
        = (0x1ffffffffULL & ((1U == (3U & vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[0U]))
                              ? ((((QData)((IData)(
                                                   vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                   << 0x3fU) | (((QData)((IData)(
                                                                 vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                                 << 0x1fU) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[1U])) 
                                                   >> 1U))) 
                                 + vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__x_ext_r)
                              : ((2U == (3U & vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[0U]))
                                  ? ((((QData)((IData)(
                                                       vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                       << 0x3fU) | 
                                      (((QData)((IData)(
                                                        vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                        << 0x1fU) | 
                                       ((QData)((IData)(
                                                        vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[1U])) 
                                        >> 1U))) - vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__x_ext_r)
                                  : (((QData)((IData)(
                                                      vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[2U])) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[1U])) 
                                                      >> 1U))))));
    __Vtemp_2[0U] = (IData)((0x1ffffffffULL & (((QData)((IData)(
                                                                vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[0U])))));
    __Vtemp_2[1U] = (((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__next_high) 
                      << 1U) | (IData)(((0x1ffffffffULL 
                                         & (((QData)((IData)(
                                                             vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__product[0U])))) 
                                        >> 0x20U)));
    __Vtemp_2[2U] = (((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__next_high) 
                      >> 0x1fU) | ((IData)((vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__next_high 
                                            >> 0x20U)) 
                                   << 1U));
    VL_SHIFTRS_WWI(66,66,32, __Vtemp_3, __Vtemp_2, 1U);
    vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__next_product[0U] 
        = __Vtemp_3[0U];
    vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__next_product[1U] 
        = __Vtemp_3[1U];
    vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__next_product[2U] 
        = (3U & __Vtemp_3[2U]);
    vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__next_high 
        = (0x3ffffffffULL & ((1U == (3U & vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[0U]))
                              ? ((((QData)((IData)(
                                                   vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                   << 0x3eU) | (((QData)((IData)(
                                                                 vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                                 << 0x1eU) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[1U])) 
                                                   >> 2U))) 
                                 + vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__x_ext_r)
                              : ((2U == (3U & vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[0U]))
                                  ? ((((QData)((IData)(
                                                       vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                       << 0x3eU) | 
                                      (((QData)((IData)(
                                                        vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                        << 0x1eU) | 
                                       ((QData)((IData)(
                                                        vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[1U])) 
                                        >> 2U))) - vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__x_ext_r)
                                  : (((QData)((IData)(
                                                      vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                      << 0x3eU) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[2U])) 
                                                    << 0x1eU) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[1U])) 
                                                      >> 2U))))));
    __Vtemp_5[0U] = (IData)((0x3ffffffffULL & (((QData)((IData)(
                                                                vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[0U])))));
    __Vtemp_5[1U] = (((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__next_high) 
                      << 2U) | (IData)(((0x3ffffffffULL 
                                         & (((QData)((IData)(
                                                             vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__product[0U])))) 
                                        >> 0x20U)));
    __Vtemp_5[2U] = (((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__next_high) 
                      >> 0x1eU) | ((IData)((vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__next_high 
                                            >> 0x20U)) 
                                   << 2U));
    VL_SHIFTRS_WWI(68,68,32, __Vtemp_6, __Vtemp_5, 1U);
    vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__next_product[0U] 
        = __Vtemp_6[0U];
    vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__next_product[1U] 
        = __Vtemp_6[1U];
    vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__next_product[2U] 
        = (0xfU & __Vtemp_6[2U]);
    vlSelfRef.__PVT__ld_st_done = ((IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid) 
                                   | (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp));
    vlSelfRef.__PVT__U_MEM_EXT__DOT__real_din = ((1U 
                                                  == 
                                                  (3U 
                                                   & vlSelfRef.__PVT__alu_c_r))
                                                  ? 
                                                 (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                  >> 8U)
                                                  : 
                                                 ((2U 
                                                   == 
                                                   (3U 
                                                    & vlSelfRef.__PVT__alu_c_r))
                                                   ? 
                                                  (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                   >> 0x10U)
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (3U 
                                                     & vlSelfRef.__PVT__alu_c_r))
                                                    ? 
                                                   (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                    >> 0x18U)
                                                    : vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata)));
    vlSelfRef.__VdfgRegularize_h6dbabbbd_1_0 = ((IData)(vlSelfRef.__PVT__ld_st_flag) 
                                                | (IData)(vlSelfRef.__PVT__mul_div_flag));
    vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift 
        = (((QData)((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__remainder)) 
            << 1U) | (QData)((IData)((vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__dividend 
                                      >> 0x1fU))));
    vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift 
        = (((QData)((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__remainder)) 
            << 1U) | (QData)((IData)((vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__dividend 
                                      >> 0x1fU))));
    vlSelfRef.__PVT__mul_div_busy = ((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_mul__DOT__busy_r) 
                                     | ((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_mulu__DOT__busy_r) 
                                        | ((IData)(vlSelfRef.__PVT__U_ALU__DOT__div_busy) 
                                           | (IData)(vlSelfRef.__PVT__U_ALU__DOT__divu_busy))));
    vlSelfRef.debug_wb_pc = ((IData)(vlSelfRef.__VdfgRegularize_h6dbabbbd_1_0)
                              ? vlSelfRef.__PVT__pc_r
                              : vlSelfRef.__PVT__pc);
    vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__ge_divisor 
        = (vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift 
           >= (QData)((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__divisor)));
    vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__ge_divisor 
        = (vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift 
           >= (QData)((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__divisor)));
    vlSelfRef.__VdfgRegularize_h6dbabbbd_1_2 = ((~ (IData)(vlSelfRef.__PVT__mul_div_busy)) 
                                                & (IData)(vlSelfRef.__PVT__mul_div_flag));
    vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__quotient_next 
        = ((vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__quotient 
            << 1U) | (IData)(vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__ge_divisor));
    vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__remainder_next 
        = (0x1ffffffffULL & ((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__ge_divisor)
                              ? (vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift 
                                 - (QData)((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__divisor)))
                              : vlSelfRef.__PVT__U_ALU__DOT__U_div__DOT__remainder_shift));
    vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__quotient_next 
        = ((vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__quotient 
            << 1U) | (IData)(vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__ge_divisor));
    vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__remainder_next 
        = (0x1ffffffffULL & ((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__ge_divisor)
                              ? (vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift 
                                 - (QData)((IData)(vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__divisor)))
                              : vlSelfRef.__PVT__U_ALU__DOT__U_divu__DOT__remainder_shift));
}
