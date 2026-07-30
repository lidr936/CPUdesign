# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See VminiRV_SoC.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	VminiRV_SoC \
	VminiRV_SoC___024root__DepSet_h7ff9d9a5__0 \
	VminiRV_SoC___024root__DepSet_h17f7d384__0 \
	VminiRV_SoC_cpu_top__DepSet_h4c9e4841__0 \
	VminiRV_SoC_Inst_ROM__DepSet_h70169caf__0 \
	VminiRV_SoC_cpu_core__DepSet_h8e7a3968__0 \
	VminiRV_SoC_cpu_core__DepSet_ha977b339__0 \
	VminiRV_SoC_IROM__DepSet_h06e8cd77__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	VminiRV_SoC___024root__Slow \
	VminiRV_SoC___024root__DepSet_h7ff9d9a5__0__Slow \
	VminiRV_SoC___024root__DepSet_h17f7d384__0__Slow \
	VminiRV_SoC_miniRV_SoC__Slow \
	VminiRV_SoC_miniRV_SoC__DepSet_hce2e9ee6__0__Slow \
	VminiRV_SoC_cpu_top__Slow \
	VminiRV_SoC_cpu_top__DepSet_h4c9e4841__0__Slow \
	VminiRV_SoC_cpu_top__DepSet_he6d34460__0__Slow \
	VminiRV_SoC_Inst_ROM__Slow \
	VminiRV_SoC_Inst_ROM__DepSet_hee64a51d__0__Slow \
	VminiRV_SoC_cpu_core__Slow \
	VminiRV_SoC_cpu_core__DepSet_h8e7a3968__0__Slow \
	VminiRV_SoC_cpu_core__DepSet_ha977b339__0__Slow \
	VminiRV_SoC_IROM__Slow \
	VminiRV_SoC_IROM__DepSet_h35723a7d__0__Slow \
	VminiRV_SoC_IROM__DepSet_h06e8cd77__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	VminiRV_SoC__Dpi \
	VminiRV_SoC__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	VminiRV_SoC__Syms \
	VminiRV_SoC__Trace__0__Slow \
	VminiRV_SoC__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_vcd_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
