// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VminiRV_SoC.h for the primary calling header

#include "VminiRV_SoC__pch.h"
#include "VminiRV_SoC_IROM.h"
#include "VminiRV_SoC__Syms.h"

VL_ATTR_COLD void VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom(VminiRV_SoC_IROM* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    VminiRV_SoC__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            VminiRV_SoC_IROM___eval_initial__TOP__miniRV_SoC__U_cpu__U_irom__U_irom\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_3;
    // Body
    vlSelfRef.__PVT__i = 0U;
    while (VL_GTS_III(32, 0x10000U, vlSelfRef.__PVT__i)) {
        vlSelfRef.__PVT__j = vlSelfRef.__PVT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__j, ((IData)(0x100U) 
                                                   + vlSelfRef.__PVT__i))) {
            vlSelfRef.__PVT__mem[(0xffffU & vlSelfRef.__PVT__j)] = 0U;
            vlSelfRef.__PVT__j = ((IData)(1U) + vlSelfRef.__PVT__j);
        }
        vlSelfRef.__PVT__i = ((IData)(0x100U) + vlSelfRef.__PVT__i);
    }
    __Vtemp_3[0U] = 0x2e62696eU;
    __Vtemp_3[1U] = 0x696e6974U;
    __Vtemp_3[2U] = 0x6d656dU;
    vlSelfRef.__PVT__mem_file = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(3, __Vtemp_3)
                                            , std::string{"r"});
    ;
    if (VL_UNLIKELY((0U == vlSelfRef.__PVT__mem_file))) {
        VL_WRITEF_NX("[ERROR] Open file meminit.bin failed, please check whether file exists!\n\n[%0t] %%Fatal: ram.v:28: Assertion failed in %NminiRV_SoC.U_cpu.U_irom.U_irom\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("vsrc/ram.v", 28, "", false);
    }
    VL_WRITEF_NX("[INFO] Instruction ROM initialized with meminit.bin\n",0);
    (void)VL_FREAD_I(32,0,65536, &(vlSelfRef.__PVT__mem_rd)
                     , vlSelfRef.__PVT__mem_file, 0
                     , 65536);
    vlSelfRef.__PVT__i = 0U;
    while (VL_GTS_III(32, 0x10000U, vlSelfRef.__PVT__i)) {
        vlSelfRef.__PVT__j = vlSelfRef.__PVT__i;
        while (VL_LTS_III(32, vlSelfRef.__PVT__j, ((IData)(0x100U) 
                                                   + vlSelfRef.__PVT__i))) {
            vlSelfRef.__PVT__mem[(0xffffU & vlSelfRef.__PVT__j)] 
                = (((vlSelfRef.__PVT__mem_rd[(0xffffU 
                                              & vlSelfRef.__PVT__j)] 
                     << 0x18U) | (0xff0000U & (vlSelfRef.__PVT__mem_rd
                                               [(0xffffU 
                                                 & vlSelfRef.__PVT__j)] 
                                               << 8U))) 
                   | ((0xff00U & (vlSelfRef.__PVT__mem_rd
                                  [(0xffffU & vlSelfRef.__PVT__j)] 
                                  >> 8U)) | (vlSelfRef.__PVT__mem_rd
                                             [(0xffffU 
                                               & vlSelfRef.__PVT__j)] 
                                             >> 0x18U)));
            vlSelfRef.__PVT__j = ((IData)(1U) + vlSelfRef.__PVT__j);
        }
        vlSelfRef.__PVT__i = ((IData)(0x100U) + vlSelfRef.__PVT__i);
    }
    vlSelfRef.__PVT__douta = 0U;
}
