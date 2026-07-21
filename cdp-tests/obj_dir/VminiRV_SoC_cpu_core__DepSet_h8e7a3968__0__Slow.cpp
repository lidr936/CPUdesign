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
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_10;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_10 = 0;
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_13;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_13 = 0;
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_14;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_14 = 0;
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_15;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_15 = 0;
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_16;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_16 = 0;
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_17;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_17 = 0;
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_18;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_18 = 0;
    CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_19;
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_19 = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    // Body
    vlSelfRef.debug_wb_rf_wR = vlSelfRef.__PVT__mem_wb_rd;
    vlSelfRef.debug_wb_rf_wD = vlSelfRef.__PVT__mem_wb_data;
    vlSelfRef.__PVT__U_controller__DOT__LB = (IData)(
                                                     (3U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__LH = (IData)(
                                                     (0x1003U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__LW = (IData)(
                                                     (0x2003U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__ADDI = (IData)(
                                                       (0x13U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.ifetch_addr = vlSelfRef.__PVT__fetch_pc;
    vlSelfRef.debug_mem_waddr = vlSelfRef.__PVT__ex_mem_alu_c;
    vlSelfRef.debug_mem_pc = vlSelfRef.__PVT__ex_mem_pc;
    vlSelfRef.debug_mem_wdata = vlSelfRef.__PVT__ex_mem_store_data;
    vlSelfRef.debug_wb_pc = vlSelfRef.__PVT__mem_wb_pc;
    vlSelfRef.__PVT__U_mext__DOT__real_din = ((1U == 
                                               (3U 
                                                & vlSelfRef.__PVT__ex_mem_alu_c))
                                               ? (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                  >> 8U)
                                               : ((2U 
                                                   == 
                                                   (3U 
                                                    & vlSelfRef.__PVT__ex_mem_alu_c))
                                                   ? 
                                                  (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                   >> 0x10U)
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (3U 
                                                     & vlSelfRef.__PVT__ex_mem_alu_c))
                                                    ? 
                                                   (vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata 
                                                    >> 0x18U)
                                                    : vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_rdata)));
    vlSelfRef.__PVT__mreq_wdata = vlSelfRef.__PVT__ex_mem_store_data;
    vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__next_high 
        = (0x1ffffffffULL & ((1U == (3U & vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[0U]))
                              ? ((((QData)((IData)(
                                                   vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                   << 0x3fU) | (((QData)((IData)(
                                                                 vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                                 << 0x1fU) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[1U])) 
                                                   >> 1U))) 
                                 + vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__x_ext_r)
                              : ((2U == (3U & vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[0U]))
                                  ? ((((QData)((IData)(
                                                       vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                       << 0x3fU) | 
                                      (((QData)((IData)(
                                                        vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                        << 0x1fU) | 
                                       ((QData)((IData)(
                                                        vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[1U])) 
                                        >> 1U))) - vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__x_ext_r)
                                  : (((QData)((IData)(
                                                      vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[2U])) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[1U])) 
                                                      >> 1U))))));
    __Vtemp_2[0U] = (IData)((0x1ffffffffULL & (((QData)((IData)(
                                                                vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[0U])))));
    __Vtemp_2[1U] = (((IData)(vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__next_high) 
                      << 1U) | (IData)(((0x1ffffffffULL 
                                         & (((QData)((IData)(
                                                             vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__product[0U])))) 
                                        >> 0x20U)));
    __Vtemp_2[2U] = (((IData)(vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__next_high) 
                      >> 0x1fU) | ((IData)((vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__next_high 
                                            >> 0x20U)) 
                                   << 1U));
    VL_SHIFTRS_WWI(66,66,32, __Vtemp_3, __Vtemp_2, 1U);
    vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__next_product[0U] 
        = __Vtemp_3[0U];
    vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__next_product[1U] 
        = __Vtemp_3[1U];
    vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__next_product[2U] 
        = (3U & __Vtemp_3[2U]);
    vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__next_high 
        = (0x3ffffffffULL & ((1U == (3U & vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[0U]))
                              ? ((((QData)((IData)(
                                                   vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                   << 0x3eU) | (((QData)((IData)(
                                                                 vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                                 << 0x1eU) 
                                                | ((QData)((IData)(
                                                                   vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[1U])) 
                                                   >> 2U))) 
                                 + vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__x_ext_r)
                              : ((2U == (3U & vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[0U]))
                                  ? ((((QData)((IData)(
                                                       vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                       << 0x3eU) | 
                                      (((QData)((IData)(
                                                        vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                        << 0x1eU) | 
                                       ((QData)((IData)(
                                                        vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[1U])) 
                                        >> 2U))) - vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__x_ext_r)
                                  : (((QData)((IData)(
                                                      vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                      << 0x3eU) | (
                                                   ((QData)((IData)(
                                                                    vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[2U])) 
                                                    << 0x1eU) 
                                                   | ((QData)((IData)(
                                                                      vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[1U])) 
                                                      >> 2U))))));
    __Vtemp_5[0U] = (IData)((0x3ffffffffULL & (((QData)((IData)(
                                                                vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[0U])))));
    __Vtemp_5[1U] = (((IData)(vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__next_high) 
                      << 2U) | (IData)(((0x3ffffffffULL 
                                         & (((QData)((IData)(
                                                             vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__product[0U])))) 
                                        >> 0x20U)));
    __Vtemp_5[2U] = (((IData)(vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__next_high) 
                      >> 0x1eU) | ((IData)((vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__next_high 
                                            >> 0x20U)) 
                                   << 2U));
    VL_SHIFTRS_WWI(68,68,32, __Vtemp_6, __Vtemp_5, 1U);
    vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__next_product[0U] 
        = __Vtemp_6[0U];
    vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__next_product[1U] 
        = __Vtemp_6[1U];
    vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__next_product[2U] 
        = (0xfU & __Vtemp_6[2U]);
    vlSelfRef.__PVT__U_controller__DOT__JALR = (IData)(
                                                       (0x67U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__LBU = (IData)(
                                                      (0x4003U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__LHU = (IData)(
                                                      (0x5003U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__EXT_OP_U = 
        ((0x37U == (0x7fU & vlSelfRef.__PVT__if_id_inst)) 
         | (0x17U == (0x7fU & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__SB = (IData)(
                                                     (0x23U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__SH = (IData)(
                                                     (0x1023U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__SW = (IData)(
                                                     (0x2023U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__mreq_wen = 0U;
    if ((1U == (IData)(vlSelfRef.__PVT__ex_mem_ram_wop))) {
        if ((2U & vlSelfRef.__PVT__ex_mem_alu_c)) {
            if ((1U & vlSelfRef.__PVT__ex_mem_alu_c)) {
                vlSelfRef.__PVT__mreq_wdata = (vlSelfRef.__PVT__ex_mem_store_data 
                                               << 0x18U);
                vlSelfRef.__PVT__mreq_wen = 8U;
            } else {
                vlSelfRef.__PVT__mreq_wdata = (0xff0000U 
                                               & (vlSelfRef.__PVT__ex_mem_store_data 
                                                  << 0x10U));
                vlSelfRef.__PVT__mreq_wen = 4U;
            }
        } else if ((1U & vlSelfRef.__PVT__ex_mem_alu_c)) {
            vlSelfRef.__PVT__mreq_wdata = (0xff00U 
                                           & (vlSelfRef.__PVT__ex_mem_store_data 
                                              << 8U));
            vlSelfRef.__PVT__mreq_wen = 2U;
        } else {
            vlSelfRef.__PVT__mreq_wdata = (0xffU & vlSelfRef.__PVT__ex_mem_store_data);
            vlSelfRef.__PVT__mreq_wen = 1U;
        }
    } else if ((3U == (IData)(vlSelfRef.__PVT__ex_mem_ram_wop))) {
        if ((0U == (3U & vlSelfRef.__PVT__ex_mem_alu_c))) {
            vlSelfRef.__PVT__mreq_wdata = (0xffffU 
                                           & vlSelfRef.__PVT__ex_mem_store_data);
            vlSelfRef.__PVT__mreq_wen = 3U;
        } else if ((2U == (3U & vlSelfRef.__PVT__ex_mem_alu_c))) {
            vlSelfRef.__PVT__mreq_wdata = (vlSelfRef.__PVT__ex_mem_store_data 
                                           << 0x10U);
            vlSelfRef.__PVT__mreq_wen = 0xcU;
        } else {
            vlSelfRef.__PVT__mreq_wdata = 0U;
            vlSelfRef.__PVT__mreq_wen = 0U;
        }
    } else if ((0xfU == (IData)(vlSelfRef.__PVT__ex_mem_ram_wop))) {
        if ((0U == (3U & vlSelfRef.__PVT__ex_mem_alu_c))) {
            vlSelfRef.__PVT__mreq_wen = vlSelfRef.__PVT__ex_mem_ram_wop;
        }
    }
    vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__remainder_shift 
        = (((QData)((IData)(vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__remainder)) 
            << 1U) | (QData)((IData)((vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__dividend 
                                      >> 0x1fU))));
    vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift 
        = (((QData)((IData)(vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__remainder)) 
            << 1U) | (QData)((IData)((vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__dividend 
                                      >> 0x1fU))));
    vlSelfRef.__PVT__load_use_stall = ((IData)(vlSelfRef.__PVT__if_id_valid) 
                                       & ((IData)(vlSelfRef.__PVT__id_ex_valid) 
                                          & ((0U != (IData)(vlSelfRef.__PVT__id_ex_ram_rop)) 
                                             & ((0U 
                                                 != (IData)(vlSelfRef.__PVT__id_ex_rd)) 
                                                & ((((0x13U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.__PVT__if_id_inst)) 
                                                     | ((0x33U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.__PVT__if_id_inst)) 
                                                        | ((3U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelfRef.__PVT__if_id_inst)) 
                                                           | ((0x23U 
                                                               == 
                                                               (0x7fU 
                                                                & vlSelfRef.__PVT__if_id_inst)) 
                                                              | ((0x63U 
                                                                  == 
                                                                  (0x7fU 
                                                                   & vlSelfRef.__PVT__if_id_inst)) 
                                                                 | (0x67U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlSelfRef.__PVT__if_id_inst))))))) 
                                                    & ((IData)(vlSelfRef.__PVT__id_ex_rd) 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelfRef.__PVT__if_id_inst 
                                                           >> 0xfU)))) 
                                                   | (((0x33U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.__PVT__if_id_inst)) 
                                                       | ((0x23U 
                                                           == 
                                                           (0x7fU 
                                                            & vlSelfRef.__PVT__if_id_inst)) 
                                                          | (0x63U 
                                                             == 
                                                             (0x7fU 
                                                              & vlSelfRef.__PVT__if_id_inst)))) 
                                                      & ((IData)(vlSelfRef.__PVT__id_ex_rd) 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelfRef.__PVT__if_id_inst 
                                                             >> 0x14U)))))))));
    vlSelfRef.__PVT__U_controller__DOT__SLTI = (IData)(
                                                       (0x2013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__SLTIU = (IData)(
                                                        (0x3013U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__XORI = (IData)(
                                                       (0x4013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__ORI = (IData)(
                                                      (0x6013U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__ANDI = (IData)(
                                                       (0x7013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__SLLI = (IData)(
                                                       (0x1013U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__SLT = (IData)(
                                                      (0x2033U 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__BEQ = (IData)(
                                                      (0x63U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__BNE = (IData)(
                                                      (0x1063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__BLT = (IData)(
                                                      (0x4063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__BGE = (IData)(
                                                      (0x5063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__BLTU = (IData)(
                                                       (0x6063U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__U_controller__DOT__BGEU = (IData)(
                                                       (0x7063U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__ex_alu_busy = ((IData)(vlSelfRef.__PVT__U_alu__DOT__U_mul__DOT__busy_r) 
                                    | ((IData)(vlSelfRef.__PVT__U_alu__DOT__U_mulu__DOT__busy_r) 
                                       | ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_busy) 
                                          | (IData)(vlSelfRef.__PVT__U_alu__DOT__divu_busy))));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_10 
        = (IData)((0x5013U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_15 
        = (IData)((0x3033U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_13 
        = (IData)((0x33U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_14 
        = (IData)((0x1033U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_16 
        = (IData)((0x4033U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_18 
        = (IData)((0x6033U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_19 
        = (IData)((0x7033U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_17 
        = (IData)((0x5033U == (0x707fU & vlSelfRef.__PVT__if_id_inst)));
    vlSelfRef.__PVT__ex_mem_can_forward = ((IData)(vlSelfRef.__PVT__ex_mem_rf_we) 
                                           & ((IData)(vlSelfRef.__PVT__ex_mem_valid) 
                                              & ((0U 
                                                  != (IData)(vlSelfRef.__PVT__ex_mem_rd)) 
                                                 & (0U 
                                                    == (IData)(vlSelfRef.__PVT__ex_mem_ram_rop)))));
    vlSelfRef.debug_wb_rf_we = ((IData)(vlSelfRef.__PVT__mem_wb_rf_we) 
                                & (IData)(vlSelfRef.__PVT__mem_wb_valid));
    vlSelfRef.__PVT__mem_in_progress = ((IData)(vlSelfRef.__PVT__ex_mem_valid) 
                                        & ((0U != (IData)(vlSelfRef.__PVT__ex_mem_ram_rop)) 
                                           | (0U != (IData)(vlSelfRef.__PVT__ex_mem_ram_wop))));
    vlSelfRef.__PVT__U_controller__DOT__WB_OP_PC4 = 
        ((0x6fU == (0x7fU & vlSelfRef.__PVT__if_id_inst)) 
         | (IData)(vlSelfRef.__PVT__U_controller__DOT__JALR));
    vlSelfRef.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33 
        = ((IData)(vlSelfRef.__PVT__U_controller__DOT__LBU) 
           | (IData)(vlSelfRef.__PVT__U_controller__DOT__LHU));
    vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__ge_divisor 
        = (vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__remainder_shift 
           >= (QData)((IData)(vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__divisor)));
    vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__ge_divisor 
        = (vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift 
           >= (QData)((IData)(vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__divisor)));
    vlSelfRef.__PVT__U_controller__DOT__NPC_OP_BRA 
        = (((IData)(vlSelfRef.__PVT__U_controller__DOT__BEQ) 
            | (IData)(vlSelfRef.__PVT__U_controller__DOT__BNE)) 
           | ((IData)(vlSelfRef.__PVT__U_controller__DOT__BLT) 
              | ((IData)(vlSelfRef.__PVT__U_controller__DOT__BGE) 
                 | ((IData)(vlSelfRef.__PVT__U_controller__DOT__BLTU) 
                    | (IData)(vlSelfRef.__PVT__U_controller__DOT__BGEU)))));
    vlSelfRef.__PVT__U_controller__DOT__SRLI = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_10) 
                                                & (0U 
                                                   == 
                                                   (vlSelfRef.__PVT__if_id_inst 
                                                    >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__SRAI = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_10) 
                                                & (0x20U 
                                                   == 
                                                   (vlSelfRef.__PVT__if_id_inst 
                                                    >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__SLTU = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_15) 
                                                & (0U 
                                                   == 
                                                   (vlSelfRef.__PVT__if_id_inst 
                                                    >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__MULHU = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_15) 
                                                 & (1U 
                                                    == 
                                                    (vlSelfRef.__PVT__if_id_inst 
                                                     >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__ADD = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_13) 
                                               & (0U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__MUL = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_13) 
                                               & (1U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__SUB = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_13) 
                                               & (0x20U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__MULH = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_14) 
                                                & (1U 
                                                   == 
                                                   (vlSelfRef.__PVT__if_id_inst 
                                                    >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__SLL = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_14) 
                                               & (0U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__XOR = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_16) 
                                               & (0U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__DIV = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_16) 
                                               & (1U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__OR = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_18) 
                                              & (0U 
                                                 == 
                                                 (vlSelfRef.__PVT__if_id_inst 
                                                  >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__REM = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_18) 
                                               & (1U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__AND = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_19) 
                                               & (0U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__REMU = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_19) 
                                                & (1U 
                                                   == 
                                                   (vlSelfRef.__PVT__if_id_inst 
                                                    >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__SRL = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_17) 
                                               & (0U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__SRA = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_17) 
                                               & (0x20U 
                                                  == 
                                                  (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x19U)));
    vlSelfRef.__PVT__U_controller__DOT__DIVU = ((IData)(U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_17) 
                                                & (1U 
                                                   == 
                                                   (vlSelfRef.__PVT__if_id_inst 
                                                    >> 0x19U)));
    vlSelfRef.__PVT__mem_wb_can_forward = ((IData)(vlSelfRef.debug_wb_rf_we) 
                                           & (0U != (IData)(vlSelfRef.__PVT__mem_wb_rd)));
    vlSelfRef.__PVT__daccess_ren = 0U;
    vlSelfRef.__PVT__daccess_wen = 0U;
    if (((IData)(vlSelfRef.__PVT__mem_in_progress) 
         & (~ (IData)(vlSelfRef.__PVT__ex_mem_mem_started)))) {
        vlSelfRef.__PVT__daccess_ren = ((0U != (IData)(vlSelfRef.__PVT__ex_mem_ram_rop))
                                         ? ((4U & (IData)(vlSelfRef.__PVT__ex_mem_ram_rop))
                                             ? ((2U 
                                                 & (IData)(vlSelfRef.__PVT__ex_mem_ram_rop))
                                                 ? 
                                                ((0U 
                                                  == 
                                                  (3U 
                                                   & vlSelfRef.__PVT__ex_mem_alu_c))
                                                  ? 0xfU
                                                  : 0U)
                                                 : 
                                                ((1U 
                                                  & vlSelfRef.__PVT__ex_mem_alu_c)
                                                  ? 0U
                                                  : 0xfU))
                                             : ((2U 
                                                 & (IData)(vlSelfRef.__PVT__ex_mem_ram_rop))
                                                 ? 0xfU
                                                 : 
                                                ((0U 
                                                  == 
                                                  (3U 
                                                   & vlSelfRef.__PVT__ex_mem_alu_c))
                                                  ? 0xfU
                                                  : 0U)))
                                         : 0U);
        vlSelfRef.__PVT__daccess_wen = vlSelfRef.__PVT__mreq_wen;
    }
    vlSelfRef.__PVT__mem_stall = ((~ ((IData)(vlSelfRef.__PVT__ex_mem_mem_started) 
                                      & (((0U != (IData)(vlSelfRef.__PVT__ex_mem_ram_rop)) 
                                          & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_valid)) 
                                         | ((0U != (IData)(vlSelfRef.__PVT__ex_mem_ram_wop)) 
                                            & (IData)(vlSymsp->TOP__miniRV_SoC__U_cpu.__PVT__dc2cpu_wresp))))) 
                                  & (IData)(vlSelfRef.__PVT__mem_in_progress));
    vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__quotient_next 
        = ((vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__quotient 
            << 1U) | (IData)(vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__ge_divisor));
    vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__remainder_next 
        = (0x1ffffffffULL & ((IData)(vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__ge_divisor)
                              ? (vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__remainder_shift 
                                 - (QData)((IData)(vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__divisor)))
                              : vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__remainder_shift));
    vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__quotient_next 
        = ((vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__quotient 
            << 1U) | (IData)(vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__ge_divisor));
    vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__remainder_next 
        = (0x1ffffffffULL & ((IData)(vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__ge_divisor)
                              ? (vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift 
                                 - (QData)((IData)(vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__divisor)))
                              : vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__remainder_shift));
    vlSelfRef.__PVT__id_sext_op = ((1U & (- (IData)(
                                                    (((IData)(vlSelfRef.__PVT__U_controller__DOT__SB) 
                                                      | (IData)(vlSelfRef.__PVT__U_controller__DOT__SH)) 
                                                     | (IData)(vlSelfRef.__PVT__U_controller__DOT__SW))))) 
                                   | ((2U & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__NPC_OP_BRA)))) 
                                      | ((3U & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__EXT_OP_U)))) 
                                         | (4U & (- (IData)(
                                                            (0x6fU 
                                                             == 
                                                             (0x7fU 
                                                              & vlSelfRef.__PVT__if_id_inst))))))));
    vlSelfRef.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29 
        = ((IData)(vlSelfRef.__PVT__U_controller__DOT__MULH) 
           | (IData)(vlSelfRef.__PVT__U_controller__DOT__MULHU));
    vlSelfRef.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31 
        = ((IData)(vlSelfRef.__PVT__U_controller__DOT__SUB) 
           | (IData)(vlSelfRef.__PVT__U_controller__DOT__SLL));
    vlSelfRef.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_28 
        = ((IData)(vlSelfRef.__PVT__U_controller__DOT__REM) 
           | (IData)(vlSelfRef.__PVT__U_controller__DOT__REMU));
    vlSelfRef.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_27 
        = ((IData)(vlSelfRef.__PVT__U_controller__DOT__DIV) 
           | (IData)(vlSelfRef.__PVT__U_controller__DOT__DIVU));
    vlSelfRef.__PVT__id_alu_op = ((1U & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__SUB)))) 
                                  | ((2U & (- (IData)(
                                                      ((IData)(vlSelfRef.__PVT__U_controller__DOT__AND) 
                                                       | (IData)(vlSelfRef.__PVT__U_controller__DOT__ANDI))))) 
                                     | ((3U & (- (IData)(
                                                         ((IData)(vlSelfRef.__PVT__U_controller__DOT__OR) 
                                                          | (IData)(vlSelfRef.__PVT__U_controller__DOT__ORI))))) 
                                        | ((4U & (- (IData)(
                                                            ((IData)(vlSelfRef.__PVT__U_controller__DOT__XOR) 
                                                             | (IData)(vlSelfRef.__PVT__U_controller__DOT__XORI))))) 
                                           | ((5U & 
                                               (- (IData)(
                                                          ((IData)(vlSelfRef.__PVT__U_controller__DOT__SLL) 
                                                           | (IData)(vlSelfRef.__PVT__U_controller__DOT__SLLI))))) 
                                              | ((6U 
                                                  & (- (IData)(
                                                               ((IData)(vlSelfRef.__PVT__U_controller__DOT__SRL) 
                                                                | (IData)(vlSelfRef.__PVT__U_controller__DOT__SRLI))))) 
                                                 | ((7U 
                                                     & (- (IData)(
                                                                  ((IData)(vlSelfRef.__PVT__U_controller__DOT__SRA) 
                                                                   | (IData)(vlSelfRef.__PVT__U_controller__DOT__SRAI))))) 
                                                    | ((8U 
                                                        & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__BEQ)))) 
                                                       | ((9U 
                                                           & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__BNE)))) 
                                                          | ((0xaU 
                                                              & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__BLT)))) 
                                                             | ((0xbU 
                                                                 & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__BGE)))) 
                                                                | ((0xcU 
                                                                    & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__BLTU)))) 
                                                                   | ((0xdU 
                                                                       & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__BGEU)))) 
                                                                      | ((0xeU 
                                                                          & (- (IData)(
                                                                                ((IData)(vlSelfRef.__PVT__U_controller__DOT__SLT) 
                                                                                | (IData)(vlSelfRef.__PVT__U_controller__DOT__SLTI))))) 
                                                                         | ((0xfU 
                                                                             & (- (IData)(
                                                                                ((IData)(vlSelfRef.__PVT__U_controller__DOT__SLTU) 
                                                                                | (IData)(vlSelfRef.__PVT__U_controller__DOT__SLTIU))))) 
                                                                            | ((0x10U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__MUL)))) 
                                                                               | ((0x11U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__MULH)))) 
                                                                                | ((0x12U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__MULHU)))) 
                                                                                | ((0x13U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__DIV)))) 
                                                                                | ((0x14U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__DIVU)))) 
                                                                                | ((0x15U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__REM)))) 
                                                                                | (0x16U 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__U_controller__DOT__REMU)))))))))))))))))))))))));
    vlSelfRef.__PVT__ex_rs1_value = vlSelfRef.__PVT__id_ex_rs1_data;
    if (((IData)(vlSelfRef.__PVT__mem_wb_can_forward) 
         & ((IData)(vlSelfRef.__PVT__mem_wb_rd) == (IData)(vlSelfRef.__PVT__id_ex_rs1)))) {
        vlSelfRef.__PVT__ex_rs1_value = vlSelfRef.__PVT__mem_wb_data;
    }
    if (((IData)(vlSelfRef.__PVT__ex_mem_can_forward) 
         & ((IData)(vlSelfRef.__PVT__ex_mem_rd) == (IData)(vlSelfRef.__PVT__id_ex_rs1)))) {
        vlSelfRef.__PVT__ex_rs1_value = vlSelfRef.__PVT__ex_mem_alu_c;
    }
    vlSelfRef.__PVT__ex_rs2_value = vlSelfRef.__PVT__id_ex_rs2_data;
    if (((IData)(vlSelfRef.__PVT__mem_wb_can_forward) 
         & ((IData)(vlSelfRef.__PVT__mem_wb_rd) == (IData)(vlSelfRef.__PVT__id_ex_rs2)))) {
        vlSelfRef.__PVT__ex_rs2_value = vlSelfRef.__PVT__mem_wb_data;
    }
    if (((IData)(vlSelfRef.__PVT__ex_mem_can_forward) 
         & ((IData)(vlSelfRef.__PVT__ex_mem_rd) == (IData)(vlSelfRef.__PVT__id_ex_rs2)))) {
        vlSelfRef.__PVT__ex_rs2_value = vlSelfRef.__PVT__ex_mem_alu_c;
    }
    vlSelfRef.debug_mem_we = vlSelfRef.__PVT__daccess_wen;
    vlSelfRef.__PVT__mul_stall = ((~ (IData)(vlSelfRef.__PVT__mem_stall)) 
                                  & ((IData)(vlSelfRef.__PVT__id_ex_valid) 
                                     & ((~ ((~ (IData)(vlSelfRef.__PVT__ex_alu_busy)) 
                                            & (IData)(vlSelfRef.__PVT__id_ex_mul_started))) 
                                        & (IData)(vlSelfRef.__PVT__id_ex_is_muldiv))));
    vlSelfRef.__PVT__ex_alu_op = ((1U & ((~ (IData)(vlSelfRef.__PVT__id_ex_valid)) 
                                         | ((IData)(vlSelfRef.__PVT__id_ex_mul_started) 
                                            | (IData)(vlSelfRef.__PVT__mem_stall))))
                                   ? 0x1fU : (IData)(vlSelfRef.__PVT__id_ex_alu_op));
    vlSelfRef.__PVT__id_ext = ((4U & (IData)(vlSelfRef.__PVT__id_sext_op))
                                ? ((2U & (IData)(vlSelfRef.__PVT__id_sext_op))
                                    ? 0U : ((1U & (IData)(vlSelfRef.__PVT__id_sext_op))
                                             ? 0U : 
                                            ((((- (IData)(
                                                          (vlSelfRef.__PVT__if_id_inst 
                                                           >> 0x1fU))) 
                                               << 0x15U) 
                                              | (0x100000U 
                                                 & (vlSelfRef.__PVT__if_id_inst 
                                                    >> 0xbU))) 
                                             | (((0xff000U 
                                                  & vlSelfRef.__PVT__if_id_inst) 
                                                 | (0x800U 
                                                    & (vlSelfRef.__PVT__if_id_inst 
                                                       >> 9U))) 
                                                | (0x7feU 
                                                   & (vlSelfRef.__PVT__if_id_inst 
                                                      >> 0x14U))))))
                                : ((2U & (IData)(vlSelfRef.__PVT__id_sext_op))
                                    ? ((1U & (IData)(vlSelfRef.__PVT__id_sext_op))
                                        ? (0xfffff000U 
                                           & vlSelfRef.__PVT__if_id_inst)
                                        : (((- (IData)(
                                                       (vlSelfRef.__PVT__if_id_inst 
                                                        >> 0x1fU))) 
                                            << 0xdU) 
                                           | (((0x1000U 
                                                & (vlSelfRef.__PVT__if_id_inst 
                                                   >> 0x13U)) 
                                               | (0x800U 
                                                  & (vlSelfRef.__PVT__if_id_inst 
                                                     << 4U))) 
                                              | ((0x7e0U 
                                                  & (vlSelfRef.__PVT__if_id_inst 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelfRef.__PVT__if_id_inst 
                                                       >> 7U))))))
                                    : ((1U & (IData)(vlSelfRef.__PVT__id_sext_op))
                                        ? (((- (IData)(
                                                       (vlSelfRef.__PVT__if_id_inst 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelfRef.__PVT__if_id_inst 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelfRef.__PVT__if_id_inst 
                                                    >> 7U))))
                                        : (((- (IData)(
                                                       (vlSelfRef.__PVT__if_id_inst 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | (vlSelfRef.__PVT__if_id_inst 
                                              >> 0x14U)))));
    vlSelfRef.__PVT__id_is_div = ((IData)(vlSelfRef.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_27) 
                                  | (IData)(vlSelfRef.U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_28));
    vlSelfRef.__PVT__ex_alu_a = ((IData)(vlSelfRef.__PVT__id_ex_alua_sel)
                                  ? vlSelfRef.__PVT__id_ex_pc
                                  : vlSelfRef.__PVT__ex_rs1_value);
    vlSelfRef.__PVT__ex_alu_b = ((IData)(vlSelfRef.__PVT__id_ex_alub_sel)
                                  ? vlSelfRef.__PVT__id_ex_ext
                                  : vlSelfRef.__PVT__ex_rs2_value);
    vlSelfRef.__PVT__pipe_stall = ((IData)(vlSelfRef.__PVT__mem_stall) 
                                   | (IData)(vlSelfRef.__PVT__mul_stall));
    vlSelfRef.__PVT__U_alu__DOT__mul_flag = ((0x10U 
                                              == (IData)(vlSelfRef.__PVT__ex_alu_op)) 
                                             | (0x11U 
                                                == (IData)(vlSelfRef.__PVT__ex_alu_op)));
    vlSelfRef.__PVT__U_alu__DOT__div_flag = ((0x13U 
                                              == (IData)(vlSelfRef.__PVT__ex_alu_op)) 
                                             | (0x15U 
                                                == (IData)(vlSelfRef.__PVT__ex_alu_op)));
    vlSelfRef.__PVT__U_alu__DOT__divu_flag = ((0x14U 
                                               == (IData)(vlSelfRef.__PVT__ex_alu_op)) 
                                              | (0x16U 
                                                 == (IData)(vlSelfRef.__PVT__ex_alu_op)));
    vlSelfRef.__PVT__U_alu__DOT__op_eff = ((0x1fU == (IData)(vlSelfRef.__PVT__U_alu__DOT__op_r))
                                            ? (IData)(vlSelfRef.__PVT__ex_alu_op)
                                            : (IData)(vlSelfRef.__PVT__U_alu__DOT__op_r));
    vlSelfRef.__PVT__U_alu__DOT__a_abs = ((vlSelfRef.__PVT__ex_alu_a 
                                           >> 0x1fU)
                                           ? ((IData)(1U) 
                                              + (~ vlSelfRef.__PVT__ex_alu_a))
                                           : vlSelfRef.__PVT__ex_alu_a);
    vlSelfRef.__PVT__U_alu__DOT__b_abs = ((vlSelfRef.__PVT__ex_alu_b 
                                           >> 0x1fU)
                                           ? ((IData)(1U) 
                                              + (~ vlSelfRef.__PVT__ex_alu_b))
                                           : vlSelfRef.__PVT__ex_alu_b);
    vlSelfRef.__PVT__ex_redirect = ((~ (IData)(vlSelfRef.__PVT__pipe_stall)) 
                                    & ((IData)(vlSelfRef.__PVT__id_ex_valid) 
                                       & (((2U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                                           & ((1U & 
                                               (~ ((IData)(vlSelfRef.__PVT__ex_alu_op) 
                                                   >> 4U))) 
                                              && ((1U 
                                                   & ((IData)(vlSelfRef.__PVT__ex_alu_op) 
                                                      >> 3U)) 
                                                  && ((4U 
                                                       & (IData)(vlSelfRef.__PVT__ex_alu_op))
                                                       ? 
                                                      ((1U 
                                                        & (~ 
                                                           ((IData)(vlSelfRef.__PVT__ex_alu_op) 
                                                            >> 1U))) 
                                                       && ((1U 
                                                            & (IData)(vlSelfRef.__PVT__ex_alu_op))
                                                            ? 
                                                           (vlSelfRef.__PVT__ex_alu_a 
                                                            >= vlSelfRef.__PVT__ex_alu_b)
                                                            : 
                                                           (vlSelfRef.__PVT__ex_alu_a 
                                                            < vlSelfRef.__PVT__ex_alu_b)))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlSelfRef.__PVT__ex_alu_op))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelfRef.__PVT__ex_alu_op))
                                                         ? 
                                                        VL_GTES_III(32, vlSelfRef.__PVT__ex_alu_a, vlSelfRef.__PVT__ex_alu_b)
                                                         : 
                                                        VL_LTS_III(32, vlSelfRef.__PVT__ex_alu_a, vlSelfRef.__PVT__ex_alu_b))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlSelfRef.__PVT__ex_alu_op))
                                                         ? 
                                                        (vlSelfRef.__PVT__ex_alu_a 
                                                         != vlSelfRef.__PVT__ex_alu_b)
                                                         : 
                                                        (vlSelfRef.__PVT__ex_alu_a 
                                                         == vlSelfRef.__PVT__ex_alu_b))))))) 
                                          | ((3U == (IData)(vlSelfRef.__PVT__id_ex_npc_op)) 
                                             | (1U 
                                                == (IData)(vlSelfRef.__PVT__id_ex_npc_op))))));
    vlSelfRef.__PVT__ex_alu_c = ((0x10U & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                  ? ((8U & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                      ? 0U : ((4U & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                               ? ((2U 
                                                   & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                    ? 0U
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_zero_r)
                                                     ? vlSelfRef.__PVT__U_alu__DOT__a_r
                                                     : vlSelfRef.__PVT__U_alu__DOT__divu_rem))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                    ? 
                                                   ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_zero_r)
                                                     ? vlSelfRef.__PVT__U_alu__DOT__a_r
                                                     : 
                                                    ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_overflow_r)
                                                      ? 0U
                                                      : 
                                                     ((IData)(vlSelfRef.__PVT__U_alu__DOT__rem_neg_r)
                                                       ? 
                                                      ((IData)(1U) 
                                                       + 
                                                       (~ vlSelfRef.__PVT__U_alu__DOT__div_rem))
                                                       : vlSelfRef.__PVT__U_alu__DOT__div_rem)))
                                                    : 
                                                   ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_zero_r)
                                                     ? 0xffffffffU
                                                     : vlSelfRef.__PVT__U_alu__DOT__U_divu__DOT__quotient_out)))
                                               : ((2U 
                                                   & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                    ? 
                                                   ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_zero_r)
                                                     ? 0xffffffffU
                                                     : 
                                                    ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_overflow_r)
                                                      ? 0x80000000U
                                                      : 
                                                     ((IData)(vlSelfRef.__PVT__U_alu__DOT__div_neg_r)
                                                       ? 
                                                      ((IData)(1U) 
                                                       + 
                                                       (~ vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__quotient_out))
                                                       : vlSelfRef.__PVT__U_alu__DOT__U_div__DOT__quotient_out)))
                                                    : 
                                                   vlSelfRef.__PVT__U_alu__DOT__mulu_res[1U])
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                    ? (IData)(
                                                              (vlSelfRef.__PVT__U_alu__DOT__mul_res 
                                                               >> 0x20U))
                                                    : (IData)(vlSelfRef.__PVT__U_alu__DOT__mul_res)))))
                                  : ((8U & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                      ? ((4U & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                          ? ((2U & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                  ? 
                                                 ((vlSelfRef.__PVT__ex_alu_a 
                                                   < vlSelfRef.__PVT__ex_alu_b)
                                                   ? 1U
                                                   : 0U)
                                                  : 
                                                 (VL_LTS_III(32, vlSelfRef.__PVT__ex_alu_a, vlSelfRef.__PVT__ex_alu_b)
                                                   ? 1U
                                                   : 0U))
                                              : 0U)
                                          : 0U) : (
                                                   (4U 
                                                    & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__ex_alu_a, 
                                                                    (0x1fU 
                                                                     & vlSelfRef.__PVT__ex_alu_b))
                                                      : 
                                                     (vlSelfRef.__PVT__ex_alu_a 
                                                      >> 
                                                      (0x1fU 
                                                       & vlSelfRef.__PVT__ex_alu_b)))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                      ? 
                                                     (vlSelfRef.__PVT__ex_alu_a 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelfRef.__PVT__ex_alu_b))
                                                      : 
                                                     (vlSelfRef.__PVT__ex_alu_a 
                                                      ^ vlSelfRef.__PVT__ex_alu_b)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                      ? 
                                                     (vlSelfRef.__PVT__ex_alu_a 
                                                      | vlSelfRef.__PVT__ex_alu_b)
                                                      : 
                                                     (vlSelfRef.__PVT__ex_alu_a 
                                                      & vlSelfRef.__PVT__ex_alu_b))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlSelfRef.__PVT__U_alu__DOT__op_eff))
                                                      ? 
                                                     (vlSelfRef.__PVT__ex_alu_a 
                                                      - vlSelfRef.__PVT__ex_alu_b)
                                                      : 
                                                     (vlSelfRef.__PVT__ex_alu_a 
                                                      + vlSelfRef.__PVT__ex_alu_b))))));
    vlSelfRef.__VdfgRegularize_h6dbabbbd_0_6 = (1U 
                                                & ((~ (IData)(vlSelfRef.__PVT__load_use_stall)) 
                                                   & (~ (IData)(vlSelfRef.__PVT__ex_redirect))));
    vlSelfRef.__PVT__take_fetch_buf = ((~ (IData)(vlSelfRef.__PVT__pipe_stall)) 
                                       & ((IData)(vlSelfRef.__PVT__fetch_buf_valid) 
                                          & (IData)(vlSelfRef.__VdfgRegularize_h6dbabbbd_0_6)));
    vlSelfRef.ifetch_req = ((~ ((IData)(vlSymsp->TOP.fpga_rst) 
                                | (IData)(vlSelfRef.__PVT__fetch_wait))) 
                            & ((~ (IData)(vlSelfRef.__PVT__fetch_buf_valid)) 
                               & ((~ (IData)(vlSelfRef.__PVT__pipe_stall)) 
                                  & (IData)(vlSelfRef.__VdfgRegularize_h6dbabbbd_0_6))));
}
