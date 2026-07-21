
export ABI   			?=ilp32
export ARCH				?=i
export ITERATIONS	?=700
# Paths
export root_dir := $(shell pwd)
export tst_dir  := $(root_dir)/src
export inc_dir  := $(tst_dir)/common
export bld_dir  := $(root_dir)/build



# Environment
export CROSS_PREFIX  ?= riscv32-unknown-elf-
export RISCV_GCC     ?= $(CROSS_PREFIX)gcc
export RISCV_OBJDUMP ?= $(CROSS_PREFIX)objdump -D
export RISCV_OBJCOPY ?= $(CROSS_PREFIX)objcopy -O verilog
export RISCV_READELF ?= $(CROSS_PREFIX)readelf -s
#--
coremark: | $(bld_dir)
	-$(MAKE) -C $(tst_dir)/coremark ARCH=$(ARCH)

	@echo "memory_initialization_radix=16;\nmemory_initialization_vector=" > main.coe
	@cat $(bld_dir)/coremark.hex >> main.coe
	@cp $(bld_dir)/coremark.dump ./main.s
	@rm -rf build

$(bld_dir):
	mkdir -p $(bld_dir)

.PHONY: clean 	
clean:
	$(RM) -R $(root_dir)/build/*
