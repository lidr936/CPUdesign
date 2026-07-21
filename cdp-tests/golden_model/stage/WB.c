#include <cpu.h>
extern riscv32_CPU_state cpu;
TRACE WB(MEM2WB mem_info) {
    TRACE ret;
    if(mem_info.branch_taken) {
        cpu.npc = mem_info.target_pc;
    } 
    uint32_t wb_val;
    if(mem_info.wb_en) {
        switch(mem_info.wb_sel) {
            case WB_ALU: wb_val = mem_info.alu_out; break;
            case WB_PC: wb_val = mem_info.pc + 4; break;
            case WB_LOAD: wb_val = mem_info.load_out; break;
            default: wb_val = 0; break;
        }
        cpu.gpr[mem_info.dst] = wb_val;
    }

    ret.wb_pc    = mem_info.pc;
    ret.wb_rf_we = mem_info.wb_en;
    ret.wb_rf_wR = mem_info.dst;
    ret.wb_rf_wD = wb_val;
    
    ret.mem_pc    = mem_info.pc;
    ret.mem_we    = mem_info.mem_we;
    ret.mem_waddr = mem_info.mem_waddr;
    ret.mem_wdata = mem_info.mem_wdata;
    
    cpu.gpr[0] = 0;
    Log("WB Stage:");
    Log("PC = %8.8x", mem_info.pc);
    if(mem_info.wb_en) {
        Log("WB value = %8.8x, WReg = %d, npc = 0x%8.8x", wb_val, mem_info.dst, cpu.npc);
    }
    if(mem_info.branch_taken) {
        Log("Branch Taken, target is %8.8x", mem_info.target_pc);
    }
    return ret;
}
