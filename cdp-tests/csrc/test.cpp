#include "dut.h"
#include "verilated.h"
#include <stdlib.h>
#include "VminiRV_SoC.h"
#include <stdio.h>
#include <string.h>
#define STR(x) #x
#define STR_MACRO(x) STR(x)

TESTBENCH<VminiRV_SoC>* top;
VminiRV_SoC* top_module;
int arch_on = ARCH_ON;
extern void init_cpu(const char*);
extern TRACE cpu_run_once(uint32_t, uint32_t);
double main_time = 0;
double sc_time_stamp() {
    return main_time;
}
void reset_all(){
    printf("[mycpu] Resetting ...\n");
    top_module -> fpga_rst = 1;
    for(int i = 0; i<20; i++) {
        top -> tick();
    }
    top_module -> fpga_rst = 0;
    printf("[mycpu] Reset done.\n");
}

void print_wb_info(TRACE i) {
    printf("PC=0x%8.8x, WBEn = %d, WReg = %d, WBValue = 0x%8.8x\n", i.wb_pc, i.wb_rf_we, i.wb_rf_wR, i.wb_rf_wD);
}

// sel: 0-check wb trace;  1-check mem trace
int check(TRACE stu, TRACE ref, int sel) {
    int fail = 0;
    if (sel == 1) {
        if (stu.mem_pc != ref.mem_pc) fail = 1;
        if (stu.mem_we != ref.mem_we) fail = 1;
        if (stu.mem_we == 1)
            if(stu.mem_waddr != ref.mem_waddr || stu.mem_wdata != ref.mem_wdata)
                fail = 1;
        
        if (fail) {
            printf("[difftest] Test Failed! Memory-Wirte Failed!\n");
            printf("=========== Diffrence ===========\n");
            printf("SIGNAL NAME\tREFERENCE\tMYCPU\n");
            printf("debug_mem_pc\t0x%8.8x\t0x%8.8x\n", ref.mem_pc, stu.mem_pc);
            printf("debug_mem_we\t%10x\t%10x\n", ref.mem_we, stu.mem_we);
            printf("debug_mem_waddr\t0x%8.8x\t0x%8.8x\n", ref.mem_waddr, stu.mem_waddr);
            printf("debug_mem_wdata\t0x%8.8x\t0x%8.8x\n", ref.mem_wdata, stu.mem_wdata);
        }
    } else {
        if (stu.wb_pc    != ref.wb_pc   ) fail = 1;
        if (stu.wb_rf_we != ref.wb_rf_we) fail = 1;
        if (stu.wb_rf_we == 1)
            if(stu.wb_rf_wR != ref.wb_rf_wR || stu.wb_rf_wD != ref.wb_rf_wD)
                fail = 1;

        if (fail) {
            printf("[difftest] Test Failed! Register-Write Failed!\n");
            printf("=========== Diffrence ===========\n");
            printf("SIGNAL NAME\tREFERENCE\tMYCPU\n");
            printf("debug_wb_pc\t0x%8.8x\t0x%8.8x\n", ref.wb_pc, stu.wb_pc);
            printf("debug_wb_rf_we\t%10d\t%10d\n", ref.wb_rf_we, stu.wb_rf_we);
            printf("debug_wb_rf_wR\t%10d\t%10d\n", ref.wb_rf_wR, stu.wb_rf_wR);
            printf("debug_wb_rf_wD\t0x%8.8x\t0x%8.8x\n", ref.wb_rf_wD, stu.wb_rf_wD);
        }
    }
    return fail ? -1 : 0;
}

int main(int argc, char** argv, char** env) {
    top = new TESTBENCH<VminiRV_SoC>;
    char dir[1024] = "waveform/";
    if(argc < 2 || strlen(argv[1]) > 1000) {
        printf("Bad waveform dest path.");
        exit(-1);
    }
    top -> opentrace(strcat(strcat(dir, argv[1]), ".vcd"));
    init_cpu(STR_MACRO(PATH));
    top_module = top -> dut;

    reset_all();

    printf("[difftest] Test Start!\n");
    uint32_t cmp_num = 0;
    TRACE rtl_trace, model_trace;
    for (int i = 0; i < 1000000; i++) {
        do { model_trace = cpu_run_once(cmp_num, top->sc_f);
        } while ((model_trace.wb_rf_we == 0 || model_trace.wb_rf_wR == 0) && model_trace.mem_we == 0);
        
        int j = 0;
        do {
            rtl_trace = top->tick();

            if (++j >= 1000000) {
                printf("Timed out! Please check whether your CPU got stuck.\n");
                printf("Test Point Failed! Cannot Detect Any Valid Trace!\n");
                delete top;
                exit(-1);
            }
        } while ((rtl_trace.wb_rf_we == 0 || rtl_trace.wb_rf_wR == 0) && rtl_trace.mem_we == 0);

        cmp_num++;

        if (rtl_trace.wb_rf_we && rtl_trace.wb_rf_wR) {
            if (check(rtl_trace, model_trace, 0) == -1) {
                top->tick();
                delete top;
                exit(-1);
            }

            if (rtl_trace.mem_we)
                model_trace = cpu_run_once(cmp_num++, top->sc_f);
        }

        if (rtl_trace.mem_we)
            if (check(rtl_trace, model_trace, 1) == -1) {
                top->tick();
                delete top;
                exit(-1);
            }
    }

    delete top;
    return 0;
}
