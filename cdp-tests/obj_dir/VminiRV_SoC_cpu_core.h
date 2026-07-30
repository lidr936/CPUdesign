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
        CData/*1:0*/ __PVT__npc_op;
        CData/*1:0*/ __PVT__rf_wsel;
        CData/*2:0*/ __PVT__sext_op;
        CData/*4:0*/ __PVT__alu_op;
        CData/*2:0*/ __PVT__ram_rop;
        CData/*2:0*/ __PVT__ram_rop_r;
        CData/*3:0*/ __PVT__ram_wop;
        CData/*0:0*/ __PVT__is_div;
        CData/*0:0*/ __PVT__is_mul_div;
        CData/*0:0*/ __PVT__mul_div_flag;
        CData/*0:0*/ __PVT__rf_we1;
        CData/*4:0*/ __PVT__rf_wR_r;
        CData/*4:0*/ __PVT__rf_wR;
        CData/*0:0*/ __PVT__mul_div_busy;
        CData/*3:0*/ __PVT__da_wen;
        CData/*0:0*/ __PVT__is_ld_st;
        CData/*0:0*/ __PVT__ld_st_flag;
        CData/*0:0*/ __PVT__ld_st_done;
        CData/*0:0*/ __PVT__inst_finished;
        CData/*0:0*/ __PVT__inst_finished_r;
        CData/*0:0*/ __PVT__rst_r;
        CData/*6:0*/ __Vcellinp__U_CU__funct7;
        CData/*2:0*/ __Vcellinp__U_CU__funct3;
        CData/*6:0*/ __Vcellinp__U_CU__opcode;
        CData/*4:0*/ __Vcellinp__U_RF__rR2;
        CData/*4:0*/ __Vcellinp__U_RF__rR1;
        CData/*0:0*/ debug_wb_rf_we;
        CData/*4:0*/ debug_wb_rf_wR;
        CData/*3:0*/ debug_mem_we;
        CData/*0:0*/ __VdfgRegularize_h6dbabbbd_1_0;
        CData/*0:0*/ __VdfgRegularize_h6dbabbbd_1_2;
        CData/*0:0*/ __PVT__U_CU__DOT__ADDI;
        CData/*0:0*/ __PVT__U_CU__DOT__SLTI;
        CData/*0:0*/ __PVT__U_CU__DOT__SLTIU;
        CData/*0:0*/ __PVT__U_CU__DOT__XORI;
        CData/*0:0*/ __PVT__U_CU__DOT__ORI;
        CData/*0:0*/ __PVT__U_CU__DOT__ANDI;
        CData/*0:0*/ __PVT__U_CU__DOT__SLLI;
        CData/*0:0*/ __PVT__U_CU__DOT__SRLI;
        CData/*0:0*/ __PVT__U_CU__DOT__SRAI;
        CData/*0:0*/ __PVT__U_CU__DOT__ADD;
        CData/*0:0*/ __PVT__U_CU__DOT__SUB;
        CData/*0:0*/ __PVT__U_CU__DOT__SLL;
        CData/*0:0*/ __PVT__U_CU__DOT__SLT;
        CData/*0:0*/ __PVT__U_CU__DOT__SLTU;
        CData/*0:0*/ __PVT__U_CU__DOT__XOR;
        CData/*0:0*/ __PVT__U_CU__DOT__SRL;
        CData/*0:0*/ __PVT__U_CU__DOT__SRA;
        CData/*0:0*/ __PVT__U_CU__DOT__OR;
        CData/*0:0*/ __PVT__U_CU__DOT__AND;
        CData/*0:0*/ __PVT__U_CU__DOT__MUL;
        CData/*0:0*/ __PVT__U_CU__DOT__MULH;
        CData/*0:0*/ __PVT__U_CU__DOT__MULHU;
        CData/*0:0*/ __PVT__U_CU__DOT__DIV;
        CData/*0:0*/ __PVT__U_CU__DOT__DIVU;
        CData/*0:0*/ __PVT__U_CU__DOT__REM;
    };
    struct {
        CData/*0:0*/ __PVT__U_CU__DOT__REMU;
        CData/*0:0*/ __PVT__U_CU__DOT__LB;
        CData/*0:0*/ __PVT__U_CU__DOT__LH;
        CData/*0:0*/ __PVT__U_CU__DOT__LW;
        CData/*0:0*/ __PVT__U_CU__DOT__LBU;
        CData/*0:0*/ __PVT__U_CU__DOT__LHU;
        CData/*0:0*/ __PVT__U_CU__DOT__SB;
        CData/*0:0*/ __PVT__U_CU__DOT__SH;
        CData/*0:0*/ __PVT__U_CU__DOT__SW;
        CData/*0:0*/ __PVT__U_CU__DOT__BEQ;
        CData/*0:0*/ __PVT__U_CU__DOT__BNE;
        CData/*0:0*/ __PVT__U_CU__DOT__BLT;
        CData/*0:0*/ __PVT__U_CU__DOT__BGE;
        CData/*0:0*/ __PVT__U_CU__DOT__BLTU;
        CData/*0:0*/ __PVT__U_CU__DOT__BGEU;
        CData/*0:0*/ __PVT__U_CU__DOT__JALR;
        CData/*0:0*/ __PVT__U_CU__DOT__NPC_OP_BRA;
        CData/*0:0*/ __PVT__U_CU__DOT__WB_OP_PC4;
        CData/*0:0*/ __PVT__U_CU__DOT__EXT_OP_U;
        CData/*0:0*/ U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_27;
        CData/*0:0*/ U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_28;
        CData/*0:0*/ U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_29;
        CData/*0:0*/ U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_31;
        CData/*0:0*/ U_CU__DOT____VdfgRegularize_h2d1dd4ad_0_33;
        CData/*0:0*/ __PVT__U_ALU__DOT__mul_flag;
        CData/*0:0*/ __PVT__U_ALU__DOT__div_flag;
        CData/*0:0*/ __PVT__U_ALU__DOT__divu_flag;
        CData/*0:0*/ __PVT__U_ALU__DOT__div_busy;
        CData/*0:0*/ __PVT__U_ALU__DOT__divu_busy;
        CData/*4:0*/ __PVT__U_ALU__DOT__op_r;
        CData/*0:0*/ __PVT__U_ALU__DOT__div_neg_r;
        CData/*0:0*/ __PVT__U_ALU__DOT__rem_neg_r;
        CData/*0:0*/ __PVT__U_ALU__DOT__div_zero_r;
        CData/*0:0*/ __PVT__U_ALU__DOT__div_overflow_r;
        CData/*4:0*/ __PVT__U_ALU__DOT__op_eff;
        CData/*7:0*/ __PVT__U_ALU__DOT__U_mul__DOT__count;
        CData/*0:0*/ __PVT__U_ALU__DOT__U_mul__DOT__busy_r;
        CData/*7:0*/ __PVT__U_ALU__DOT__U_mulu__DOT__count;
        CData/*0:0*/ __PVT__U_ALU__DOT__U_mulu__DOT__busy_r;
        CData/*7:0*/ __PVT__U_ALU__DOT__U_div__DOT__count;
        CData/*0:0*/ __PVT__U_ALU__DOT__U_div__DOT__ge_divisor;
        CData/*7:0*/ __PVT__U_ALU__DOT__U_divu__DOT__count;
        CData/*0:0*/ __PVT__U_ALU__DOT__U_divu__DOT__ge_divisor;
        VL_OUT(ifetch_addr,31,0);
        VL_IN(__PVT__ifetch_inst,31,0);
        VL_OUT(__PVT__daccess_addr,31,0);
        VL_IN(__PVT__daccess_rdata,31,0);
        VL_OUT(__PVT__daccess_wdata,31,0);
        IData/*31:0*/ __PVT__pc;
        IData/*31:0*/ __PVT__npc;
        IData/*31:0*/ __PVT__rf_rd1;
        IData/*31:0*/ __PVT__rf_rd2;
        IData/*31:0*/ __PVT__rf_rd3;
        IData/*31:0*/ __PVT__rf_wD;
        IData/*31:0*/ __PVT__pc_r;
        IData/*31:0*/ __PVT__ext;
        IData/*31:0*/ __PVT__alu_a;
        IData/*31:0*/ __PVT__alu_b;
        IData/*31:0*/ __PVT__alu_c;
        IData/*31:0*/ __PVT__alu_c_r;
        IData/*31:0*/ __PVT__da_wdata;
        IData/*31:0*/ __PVT__store_wdata_r;
        IData/*24:0*/ __Vcellinp__U_SEXT__imm;
        IData/*31:0*/ debug_wb_pc;
    };
    struct {
        IData/*31:0*/ debug_wb_rf_wD;
        IData/*31:0*/ debug_mem_pc;
        IData/*31:0*/ debug_mem_waddr;
        IData/*31:0*/ debug_mem_wdata;
        IData/*31:0*/ U_RF__DOT____Vlvbound_h55e9dbd1__0;
        VlWide<3>/*65:0*/ __PVT__U_ALU__DOT__mulu_res;
        IData/*31:0*/ __PVT__U_ALU__DOT__div_rem;
        IData/*31:0*/ __PVT__U_ALU__DOT__divu_rem;
        IData/*31:0*/ __PVT__U_ALU__DOT__a_r;
        IData/*31:0*/ __PVT__U_ALU__DOT__a_abs;
        IData/*31:0*/ __PVT__U_ALU__DOT__b_abs;
        VlWide<3>/*65:0*/ __PVT__U_ALU__DOT__U_mul__DOT__product;
        VlWide<3>/*65:0*/ __PVT__U_ALU__DOT__U_mul__DOT__next_product;
        VlWide<3>/*67:0*/ __PVT__U_ALU__DOT__U_mulu__DOT__product;
        VlWide<3>/*67:0*/ __PVT__U_ALU__DOT__U_mulu__DOT__next_product;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_div__DOT__quotient;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_div__DOT__quotient_out;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_div__DOT__dividend;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_div__DOT__divisor;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_div__DOT__quotient_next;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_divu__DOT__quotient;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_divu__DOT__quotient_out;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_divu__DOT__dividend;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_divu__DOT__divisor;
        IData/*31:0*/ __PVT__U_ALU__DOT__U_divu__DOT__quotient_next;
        IData/*31:0*/ __PVT__U_MEM_EXT__DOT__real_din;
        IData/*31:0*/ __Vdly__pc;
        QData/*63:0*/ __PVT__U_ALU__DOT__mul_res;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_mul__DOT__x_ext_r;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_mul__DOT__next_high;
        QData/*33:0*/ __PVT__U_ALU__DOT__U_mulu__DOT__x_ext_r;
        QData/*33:0*/ __PVT__U_ALU__DOT__U_mulu__DOT__next_high;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_div__DOT__remainder;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_div__DOT__remainder_shift;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_div__DOT__remainder_next;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_divu__DOT__remainder;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_divu__DOT__remainder_shift;
        QData/*32:0*/ __PVT__U_ALU__DOT__U_divu__DOT__remainder_next;
        VlUnpacked<IData/*31:0*/, 31> __PVT__U_RF__DOT__regs;
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
