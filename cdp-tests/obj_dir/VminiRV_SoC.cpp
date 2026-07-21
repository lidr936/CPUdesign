// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VminiRV_SoC__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VminiRV_SoC::VminiRV_SoC(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VminiRV_SoC__Syms(contextp(), _vcname__, this)}
    , fpga_clk{vlSymsp->TOP.fpga_clk}
    , fpga_rst{vlSymsp->TOP.fpga_rst}
    , dig_en{vlSymsp->TOP.dig_en}
    , dig_seg{vlSymsp->TOP.dig_seg}
    , dig_seg1{vlSymsp->TOP.dig_seg1}
    , rx{vlSymsp->TOP.rx}
    , tx{vlSymsp->TOP.tx}
    , sw{vlSymsp->TOP.sw}
    , led{vlSymsp->TOP.led}
    , miniRV_SoC{vlSymsp->TOP.miniRV_SoC}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VminiRV_SoC::VminiRV_SoC(const char* _vcname__)
    : VminiRV_SoC(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VminiRV_SoC::~VminiRV_SoC() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VminiRV_SoC___024root___eval_debug_assertions(VminiRV_SoC___024root* vlSelf);
#endif  // VL_DEBUG
void VminiRV_SoC___024root___eval_static(VminiRV_SoC___024root* vlSelf);
void VminiRV_SoC___024root___eval_initial(VminiRV_SoC___024root* vlSelf);
void VminiRV_SoC___024root___eval_settle(VminiRV_SoC___024root* vlSelf);
void VminiRV_SoC___024root___eval(VminiRV_SoC___024root* vlSelf);

void VminiRV_SoC::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VminiRV_SoC::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VminiRV_SoC___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VminiRV_SoC___024root___eval_static(&(vlSymsp->TOP));
        VminiRV_SoC___024root___eval_initial(&(vlSymsp->TOP));
        VminiRV_SoC___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VminiRV_SoC___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VminiRV_SoC::eventsPending() { return false; }

uint64_t VminiRV_SoC::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VminiRV_SoC::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VminiRV_SoC___024root___eval_final(VminiRV_SoC___024root* vlSelf);

VL_ATTR_COLD void VminiRV_SoC::final() {
    VminiRV_SoC___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VminiRV_SoC::hierName() const { return vlSymsp->name(); }
const char* VminiRV_SoC::modelName() const { return "VminiRV_SoC"; }
unsigned VminiRV_SoC::threads() const { return 1; }
void VminiRV_SoC::prepareClone() const { contextp()->prepareClone(); }
void VminiRV_SoC::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VminiRV_SoC::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VminiRV_SoC___024root__trace_decl_types(VerilatedVcd* tracep);

void VminiRV_SoC___024root__trace_init_top(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VminiRV_SoC___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VminiRV_SoC___024root*>(voidSelf);
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VminiRV_SoC___024root__trace_decl_types(tracep);
    VminiRV_SoC___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VminiRV_SoC___024root__trace_register(VminiRV_SoC___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VminiRV_SoC::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VminiRV_SoC::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VminiRV_SoC___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
