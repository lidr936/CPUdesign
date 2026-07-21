// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VminiRV_SoC.h for the primary calling header

#ifndef VERILATED_VMINIRV_SOC_CPU_CORE_H_
#define VERILATED_VMINIRV_SOC_CPU_CORE_H_  // guard

#include "verilated.h"


class VminiRV_SoC__Syms;

class alignas(VL_CACHE_LINE_BYTES) VminiRV_SoC_cpu_core final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(__PVT__cpu_rst,0,0);
        VL_IN8(__PVT__cpu_clk,0,0);
        VL_OUT8(ifetch_req,0,0);
        VL_IN8(ifetch_valid,0,0);
        VL_OUT8(__PVT__daccess_ren,3,0);
        VL_IN8(__PVT__daccess_rvalid,0,0);
        VL_OUT8(__PVT__daccess_wen,3,0);
        VL_IN8(__PVT__daccess_wresp,0,0);
        CData/*0:0*/ __PVT__fetch_wait;
        CData/*0:0*/ __PVT__fetch_discard;
        CData/*0:0*/ __PVT__fetch_buf_valid;
        CData/*0:0*/ __PVT__if_id_valid;
        CData/*0:0*/ __PVT__id_ex_valid;
        CData/*4:0*/ __PVT__id_ex_rs1;
        CData/*4:0*/ __PVT__id_ex_rs2;
        CData/*4:0*/ __PVT__id_ex_rd;
        CData/*1:0*/ __PVT__id_ex_npc_op;
        CData/*4:0*/ __PVT__id_ex_alu_op;
        CData/*0:0*/ __PVT__id_ex_alua_sel;
        CData/*0:0*/ __PVT__id_ex_alub_sel;
        CData/*2:0*/ __PVT__id_ex_ram_rop;
        CData/*3:0*/ __PVT__id_ex_ram_wop;
        CData/*0:0*/ __PVT__id_ex_rf_we;
        CData/*1:0*/ __PVT__id_ex_rf_wsel;
        CData/*0:0*/ __PVT__id_ex_is_muldiv;
        CData/*0:0*/ __PVT__id_ex_mul_started;
        CData/*0:0*/ __PVT__ex_mem_valid;
        CData/*4:0*/ __PVT__ex_mem_rd;
        CData/*2:0*/ __PVT__ex_mem_ram_rop;
        CData/*3:0*/ __PVT__ex_mem_ram_wop;
        CData/*0:0*/ __PVT__ex_mem_rf_we;
        CData/*1:0*/ __PVT__ex_mem_rf_wsel;
        CData/*0:0*/ __PVT__ex_mem_mem_started;
        CData/*0:0*/ __PVT__mem_wb_valid;
        CData/*4:0*/ __PVT__mem_wb_rd;
        CData/*0:0*/ __PVT__mem_wb_rf_we;
        CData/*2:0*/ __PVT__id_sext_op;
        CData/*4:0*/ __PVT__id_alu_op;
        CData/*0:0*/ __PVT__id_is_div;
        CData/*0:0*/ __PVT__load_use_stall;
        CData/*0:0*/ __PVT__ex_mem_can_forward;
        CData/*0:0*/ __PVT__mem_wb_can_forward;
        CData/*0:0*/ __PVT__mem_in_progress;
        CData/*0:0*/ __PVT__mem_stall;
        CData/*4:0*/ __PVT__ex_alu_op;
        CData/*0:0*/ __PVT__ex_alu_busy;
        CData/*0:0*/ __PVT__mul_stall;
        CData/*0:0*/ __PVT__pipe_stall;
        CData/*0:0*/ __PVT__ex_redirect;
        CData/*3:0*/ __PVT__mreq_wen;
        CData/*0:0*/ __PVT__take_fetch_buf;
        CData/*0:0*/ debug_wb_rf_we;
        CData/*4:0*/ debug_wb_rf_wR;
        CData/*3:0*/ debug_mem_we;
        CData/*0:0*/ __VdfgRegularize_h6dbabbbd_0_6;
        CData/*0:0*/ __PVT__U_controller__DOT__ADDI;
        CData/*0:0*/ __PVT__U_controller__DOT__SLTI;
        CData/*0:0*/ __PVT__U_controller__DOT__SLTIU;
        CData/*0:0*/ __PVT__U_controller__DOT__XORI;
        CData/*0:0*/ __PVT__U_controller__DOT__ORI;
        CData/*0:0*/ __PVT__U_controller__DOT__ANDI;
        CData/*0:0*/ __PVT__U_controller__DOT__SLLI;
        CData/*0:0*/ __PVT__U_controller__DOT__SRLI;
        CData/*0:0*/ __PVT__U_controller__DOT__SRAI;
    };
    struct {
        CData/*0:0*/ __PVT__U_controller__DOT__ADD;
        CData/*0:0*/ __PVT__U_controller__DOT__SUB;
        CData/*0:0*/ __PVT__U_controller__DOT__SLL;
        CData/*0:0*/ __PVT__U_controller__DOT__SLT;
        CData/*0:0*/ __PVT__U_controller__DOT__SLTU;
        CData/*0:0*/ __PVT__U_controller__DOT__XOR;
        CData/*0:0*/ __PVT__U_controller__DOT__SRL;
        CData/*0:0*/ __PVT__U_controller__DOT__SRA;
        CData/*0:0*/ __PVT__U_controller__DOT__OR;
        CData/*0:0*/ __PVT__U_controller__DOT__AND;
        CData/*0:0*/ __PVT__U_controller__DOT__MUL;
        CData/*0:0*/ __PVT__U_controller__DOT__MULH;
        CData/*0:0*/ __PVT__U_controller__DOT__MULHU;
        CData/*0:0*/ __PVT__U_controller__DOT__DIV;
        CData/*0:0*/ __PVT__U_controller__DOT__DIVU;
        CData/*0:0*/ __PVT__U_controller__DOT__REM;
        CData/*0:0*/ __PVT__U_controller__DOT__REMU;
        CData/*0:0*/ __PVT__U_controller__DOT__LB;
        CData/*0:0*/ __PVT__U_controller__DOT__LH;
        CData/*0:0*/ __PVT__U_controller__DOT__LW;
        CData/*0:0*/ __PVT__U_controller__DOT__LBU;
        CData/*0:0*/ __PVT__U_controller__DOT__LHU;
        CData/*0:0*/ __PVT__U_controller__DOT__SB;
        CData/*0:0*/ __PVT__U_controller__DOT__SH;
        CData/*0:0*/ __PVT__U_controller__DOT__SW;
        CData/*0:0*/ __PVT__U_controller__DOT__BEQ;
        CData/*0:0*/ __PVT__U_controller__DOT__BNE;
        CData/*0:0*/ __PVT__U_controller__DOT__BLT;
        CData/*0:0*/ __PVT__U_controller__DOT__BGE;
        CData/*0:0*/ __PVT__U_controller__DOT__BLTU;
        CData/*0:0*/ __PVT__U_controller__DOT__BGEU;
        CData/*0:0*/ __PVT__U_controller__DOT__JALR;
        CData/*0:0*/ __PVT__U_controller__DOT__NPC_OP_BRA;
        CData/*0:0*/ __PVT__U_controller__DOT__WB_OP_PC4;
        CData/*0:0*/ __PVT__U_controller__DOT__EXT_OP_U;
        CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_27;
        CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_28;
        CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_29;
        CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_31;
        CData/*0:0*/ U_controller__DOT____VdfgRegularize_h2d1dd4ad_0_33;
        CData/*0:0*/ __PVT__U_alu__DOT__mul_flag;
        CData/*0:0*/ __PVT__U_alu__DOT__div_flag;
        CData/*0:0*/ __PVT__U_alu__DOT__divu_flag;
        CData/*0:0*/ __PVT__U_alu__DOT__div_busy;
        CData/*0:0*/ __PVT__U_alu__DOT__divu_busy;
        CData/*4:0*/ __PVT__U_alu__DOT__op_r;
        CData/*0:0*/ __PVT__U_alu__DOT__div_neg_r;
        CData/*0:0*/ __PVT__U_alu__DOT__rem_neg_r;
        CData/*0:0*/ __PVT__U_alu__DOT__div_zero_r;
        CData/*0:0*/ __PVT__U_alu__DOT__div_overflow_r;
        CData/*4:0*/ __PVT__U_alu__DOT__op_eff;
        CData/*7:0*/ __PVT__U_alu__DOT__U_mul__DOT__count;
        CData/*0:0*/ __PVT__U_alu__DOT__U_mul__DOT__busy_r;
        CData/*7:0*/ __PVT__U_alu__DOT__U_mulu__DOT__count;
        CData/*0:0*/ __PVT__U_alu__DOT__U_mulu__DOT__busy_r;
        CData/*7:0*/ __PVT__U_alu__DOT__U_div__DOT__count;
        CData/*0:0*/ __PVT__U_alu__DOT__U_div__DOT__ge_divisor;
        CData/*7:0*/ __PVT__U_alu__DOT__U_divu__DOT__count;
        CData/*0:0*/ __PVT__U_alu__DOT__U_divu__DOT__ge_divisor;
        CData/*0:0*/ __Vdly__fetch_discard;
        VL_OUT(ifetch_addr,31,0);
        VL_IN(__PVT__ifetch_inst,31,0);
        VL_OUT(__PVT__daccess_addr,31,0);
        VL_IN(__PVT__daccess_rdata,31,0);
    };
    struct {
        VL_OUT(__PVT__daccess_wdata,31,0);
        IData/*31:0*/ __PVT__fetch_pc;
        IData/*31:0*/ __PVT__fetch_req_pc;
        IData/*31:0*/ __PVT__fetch_buf_pc;
        IData/*31:0*/ __PVT__fetch_buf_inst;
        IData/*31:0*/ __PVT__if_id_pc;
        IData/*31:0*/ __PVT__if_id_inst;
        IData/*31:0*/ __PVT__id_ex_pc;
        IData/*31:0*/ __PVT__id_ex_rs1_data;
        IData/*31:0*/ __PVT__id_ex_rs2_data;
        IData/*31:0*/ __PVT__id_ex_ext;
        IData/*31:0*/ __PVT__ex_mem_pc;
        IData/*31:0*/ __PVT__ex_mem_alu_c;
        IData/*31:0*/ __PVT__ex_mem_ext;
        IData/*31:0*/ __PVT__ex_mem_store_data;
        IData/*31:0*/ __PVT__mem_wb_pc;
        IData/*31:0*/ __PVT__mem_wb_data;
        IData/*31:0*/ __PVT__id_ext;
        IData/*31:0*/ __PVT__ex_rs1_value;
        IData/*31:0*/ __PVT__ex_rs2_value;
        IData/*31:0*/ __PVT__ex_alu_a;
        IData/*31:0*/ __PVT__ex_alu_b;
        IData/*31:0*/ __PVT__ex_alu_c;
        IData/*31:0*/ __PVT__mreq_wdata;
        IData/*31:0*/ debug_wb_pc;
        IData/*31:0*/ debug_wb_rf_wD;
        IData/*31:0*/ debug_mem_pc;
        IData/*31:0*/ debug_mem_waddr;
        IData/*31:0*/ debug_mem_wdata;
        IData/*31:0*/ U_rf__DOT____Vlvbound_h55e9dbd1__0;
        VlWide<3>/*65:0*/ __PVT__U_alu__DOT__mulu_res;
        IData/*31:0*/ __PVT__U_alu__DOT__div_rem;
        IData/*31:0*/ __PVT__U_alu__DOT__divu_rem;
        IData/*31:0*/ __PVT__U_alu__DOT__a_r;
        IData/*31:0*/ __PVT__U_alu__DOT__a_abs;
        IData/*31:0*/ __PVT__U_alu__DOT__b_abs;
        VlWide<3>/*65:0*/ __PVT__U_alu__DOT__U_mul__DOT__product;
        VlWide<3>/*65:0*/ __PVT__U_alu__DOT__U_mul__DOT__next_product;
        VlWide<3>/*67:0*/ __PVT__U_alu__DOT__U_mulu__DOT__product;
        VlWide<3>/*67:0*/ __PVT__U_alu__DOT__U_mulu__DOT__next_product;
        IData/*31:0*/ __PVT__U_alu__DOT__U_div__DOT__quotient;
        IData/*31:0*/ __PVT__U_alu__DOT__U_div__DOT__quotient_out;
        IData/*31:0*/ __PVT__U_alu__DOT__U_div__DOT__dividend;
        IData/*31:0*/ __PVT__U_alu__DOT__U_div__DOT__divisor;
        IData/*31:0*/ __PVT__U_alu__DOT__U_div__DOT__quotient_next;
        IData/*31:0*/ __PVT__U_alu__DOT__U_divu__DOT__quotient;
        IData/*31:0*/ __PVT__U_alu__DOT__U_divu__DOT__quotient_out;
        IData/*31:0*/ __PVT__U_alu__DOT__U_divu__DOT__dividend;
        IData/*31:0*/ __PVT__U_alu__DOT__U_divu__DOT__divisor;
        IData/*31:0*/ __PVT__U_alu__DOT__U_divu__DOT__quotient_next;
        IData/*31:0*/ __PVT__U_mext__DOT__real_din;
        IData/*31:0*/ __Vdly__fetch_req_pc;
        QData/*63:0*/ __PVT__U_alu__DOT__mul_res;
        QData/*32:0*/ __PVT__U_alu__DOT__U_mul__DOT__x_ext_r;
        QData/*32:0*/ __PVT__U_alu__DOT__U_mul__DOT__next_high;
        QData/*33:0*/ __PVT__U_alu__DOT__U_mulu__DOT__x_ext_r;
        QData/*33:0*/ __PVT__U_alu__DOT__U_mulu__DOT__next_high;
        QData/*32:0*/ __PVT__U_alu__DOT__U_div__DOT__remainder;
        QData/*32:0*/ __PVT__U_alu__DOT__U_div__DOT__remainder_shift;
        QData/*32:0*/ __PVT__U_alu__DOT__U_div__DOT__remainder_next;
        QData/*32:0*/ __PVT__U_alu__DOT__U_divu__DOT__remainder;
        QData/*32:0*/ __PVT__U_alu__DOT__U_divu__DOT__remainder_shift;
        QData/*32:0*/ __PVT__U_alu__DOT__U_divu__DOT__remainder_next;
        VlUnpacked<IData/*31:0*/, 31> __PVT__U_rf__DOT__regs;
    };

    // INTERNAL VARIABLES
    VminiRV_SoC__Syms* const vlSymsp;

    // CONSTRUCTORS
    VminiRV_SoC_cpu_core(VminiRV_SoC__Syms* symsp, const char* v__name);
    ~VminiRV_SoC_cpu_core();
    VL_UNCOPYABLE(VminiRV_SoC_cpu_core);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
