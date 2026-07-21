#ifndef __DUT__
#define __DUT__

#include <sys/types.h>
#include <verilated_vcd_c.h>
#include <cpu.h>
#include "VminiRV_SoC.h"
#include "VminiRV_SoC_miniRV_SoC.h"
#include "VminiRV_SoC_cpu_top.h"
#include "VminiRV_SoC_cpu_core.h"

template<class MODULE> class TESTBENCH {
    private:
        VerilatedVcdC *vltdump;
        unsigned long count;
        unsigned int dut_ifpc;
        int dut_if_f;
        int dut_wbcnt;
    public:
        MODULE *dut;
        unsigned int sc_f;

        TESTBENCH(void) {
            Verilated::traceEverOn(true);
            dut = new MODULE;
            count = 0;
            sc_f = 0;
        }

        ~TESTBENCH(void) {
            closetrace();
            if(!vltdump) delete vltdump;
            delete dut;
        }

        // Open/create a trace file
        void opentrace(const char *vcdname) {
            if (!vltdump) {
                vltdump = new VerilatedVcdC;
                dut->trace(vltdump, 99);
                vltdump->open(vcdname);
            }
        }

        // Close a trace file
        void closetrace(void) {
            if (vltdump) {
                vltdump->close();
                vltdump = NULL;
            }
        }

        TRACE tick(void) {
            count++;

            dut->fpga_clk = 0;
            dut->eval();

            if(vltdump) vltdump->dump((vluint64_t)(10*count-1));

            // Repeat for the positive edge of the clock
            dut->fpga_clk = 1;
            dut->eval();
            if(vltdump) vltdump->dump((vluint64_t)(10*count));

            if (!sc_f) {
                if (dut->miniRV_SoC->U_cpu->U_core->ifetch_valid) {
                    dut_if_f  = 1;
                    dut_wbcnt = 0;
                }

                if (dut_if_f && dut_wbcnt < 3 && dut->miniRV_SoC->U_cpu->U_core->debug_wb_rf_we &&
                                                 dut->miniRV_SoC->U_cpu->U_core->debug_wb_pc == dut_ifpc)
                    sc_f = 1;

                if (dut_if_f) dut_wbcnt++;

                if (dut->miniRV_SoC->U_cpu->U_core->ifetch_req) {
                    dut_ifpc = dut->miniRV_SoC->U_cpu->U_core->ifetch_addr;
                    dut_if_f = 0;
                }
            }

            // Now the negative edge
            dut->fpga_clk = 0;
            dut->eval();
            if (vltdump) {
                vltdump->dump((vluint64_t)(10*count+5));
                vltdump->flush();
            }
            TRACE ret;
            ret.wb_pc    = dut->miniRV_SoC->U_cpu->U_core->debug_wb_pc;
            ret.wb_rf_we = dut->miniRV_SoC->U_cpu->U_core->debug_wb_rf_we;
            ret.wb_rf_wR = dut->miniRV_SoC->U_cpu->U_core->debug_wb_rf_wR;
            ret.wb_rf_wD = dut->miniRV_SoC->U_cpu->U_core->debug_wb_rf_wD;

            ret.mem_pc    = dut->miniRV_SoC->U_cpu->U_core->debug_mem_pc;
            ret.mem_we    = dut->miniRV_SoC->U_cpu->U_core->debug_mem_we;
            ret.mem_waddr = dut->miniRV_SoC->U_cpu->U_core->debug_mem_waddr;
            ret.mem_wdata = dut->miniRV_SoC->U_cpu->U_core->debug_mem_wdata;

            return ret;
        }
};
#endif
