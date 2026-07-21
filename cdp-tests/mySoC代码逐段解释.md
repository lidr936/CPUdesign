# `cdp-tests/mySoC` 代码逐段解释

本文解释 `/run/media/caige/File/cpu-design/cdp-tests/mySoC` 目录下的 Verilog 代码。阅读顺序建议为：`defines.vh -> miniRV_SoC.v -> cpu_top.v -> cpu_core.v -> Controller.v -> ALU.v -> PC/NPC/RF/SEXT/MREQ/MEXT/ROM/RAM/乘除器`。

## 1. 整体结构

这套代码实现的是 miniRV 单周期 CPU 的测试版 SoC。外层 `miniRV_SoC` 处理板级时钟复位，`cpu_top` 把 CPU 核心、指令 ROM、数据 RAM 接起来，`cpu_core` 是 CPU 主体。CPU 内部按数据通路可分为：

| 阶段 | 主要模块 | 作用 |
| --- | --- | --- |
| IF | `PC`、`NPC`、`Inst_ROM` | 保存当前 PC，计算下一 PC，读取指令 |
| ID | `Controller`、`RF`、`SEXT` | 译码、读寄存器、扩展立即数 |
| EX | `ALU`、`multiplier`、`divider` | 运算、比较、乘除法 |
| MEM | `MREQ`、`Data_RAM`、`MEXT` | 发起访存请求，读写内存，扩展 load 数据 |
| WB | `RF` 写端 | 把 ALU/RAM/PC+4/立即数写回寄存器 |

普通算术逻辑指令基本是 `RF -> ALU -> RF`。Load 是 `RF + imm -> ALU -> RAM -> MEXT -> RF`。Store 是 `RF + imm -> ALU -> RAM`，不写回 RF。分支/跳转是 `RF/imm/PC -> ALU/NPC -> PC`。乘除法虽然接在 ALU 里，但内部需要多个时钟完成，所以 `cpu_core` 用 `mul_div_flag` 和 `busy` 等信号等待结果。

## 2. `defines.vh`

`defines.vh` 是全工程共享的宏定义文件。

开头的 `RUN_TRACE`、`ENABLE_ICACHE`、`ENABLE_DCACHE` 是编译开关。目前 `RUN_TRACE` 被注释掉，表示默认面向 Vivado/板级工程；如果打开它，顶层会直接使用输入时钟，且导出 Verilator Trace 所需的 debug 信号。

`PC_INIT_VAL` 定义 PC 初始值，但当前 `PC.v` 复位时直接写 `32'h0`，没有实际引用这个宏。

`ALU_*` 宏定义 ALU 操作码，包括加减、逻辑、移位、比较、乘除和空操作。`Controller` 输出这些编码，`ALU` 根据编码选择实际运算。

`NPC_*` 宏定义下一 PC 的来源：`PC4` 表示顺序执行，`JALR` 表示寄存器间接跳转，`BRA` 表示条件分支，`JMP` 表示 `jal` 直接跳转。

`EXT_*` 宏定义立即数扩展类型：I/S/B/U/J 五种格式分别对应不同的指令编码拼接方式。

`WB_*` 宏定义寄存器写回来源：ALU 结果、RAM 读数据、`PC+4`、扩展后的立即数。对应数据通路图里的 RF 写回多路器。

`ALU_A_*`、`ALU_B_*` 定义 ALU 两个输入端的多路选择。A 端可选 `rs1` 或 `PC`，B 端可选 `rs2` 或立即数。

`RAM_EXT_*` 定义 load 数据扩展方式，区分 `lw/lb/lbu/lh/lhu`。`RAM_WE_*` 定义 store 写使能掩码，区分不写、写字节、写半字、写字。

地址空间宏定义了块 RAM、DDR3 和外设地址，但当前 `cdp-tests/mySoC` 里的 `Data_RAM` 只接了一个简单 DRAM IP，没有真正实现这些外设地址译码。

## 3. `miniRV_SoC.v`

`miniRV_SoC` 是板级最外层模块，端口包含 FPGA 时钟复位、拨码开关、LED、数码管和串口。当前这些外设信号没有接到 CPU 内部，只保留了接口。

在 `RUN_TRACE` 打开时，`sys_clk` 直接等于 `fpga_clk`，`sys_rst` 直接等于 `fpga_rst`。这是为了仿真/Trace 环境简单稳定。

在 `RUN_TRACE` 未打开时，代码例化 `clk_wiz_0` 产生 PLL 时钟。`fpga_rst` 是低有效复位，`sys_rst` 被转换成高有效复位，并且 PLL 未锁定时也保持复位。

最后例化 `cpu_top U_cpu`，只把 `sys_clk` 和 `sys_rst` 接给 CPU 系统。也就是说，真正 CPU、ROM、RAM 的连接都在下一层 `cpu_top`。

## 4. `cpu_top.v`

`cpu_top` 是 CPU 核心和存储器之间的封装层。

第一段 wire 定义的是指令接口：`cpu2ic_rreq` 表示 CPU 请求取指，`cpu2ic_addr` 是取指地址，`ic2cpu_valid` 表示 ROM 返回的指令有效，`ic2cpu_inst` 是指令内容。

第二段 wire 定义的是数据访存接口：`cpu2dc_ren` 是读使能，`cpu2dc_addr` 是访存地址，`dc2cpu_valid` 是读数据有效，`dc2cpu_rdata` 是读数据；`cpu2dc_wen`、`cpu2dc_wdata`、`dc2cpu_wresp` 对应写使能、写数据和写响应。

`cpu_core U_core` 例化真正的 CPU 核心，并把上述指令/数据接口全部接进去。

`Inst_ROM U_irom` 例化指令存储器，接收 CPU 的取指请求并返回指令。

`Data_RAM U_dram` 例化数据存储器，接收 CPU 的 load/store 请求并返回读数据或写响应。

## 5. `cpu_core.v`

`cpu_core` 是核心文件，内部按照 IF、ID、EX、MEM、WB 几段组织。

### 5.1 端口

输入 `cpu_rst/cpu_clk` 是高有效复位和 CPU 时钟。

Instruction Fetch Interface 是取指接口：核心输出 `ifetch_req/ifetch_addr`，外部 ROM 返回 `ifetch_valid/ifetch_inst`。

Data Access Interface 是数据访存接口：核心输出读写使能、地址、写数据，外部 RAM 返回读有效、读数据和写响应。

带 `/* verilator public */` 的信号用于 Trace 仿真工具从 Verilator 模型外部观察内部状态，不影响综合逻辑本身。

### 5.2 内部信号分组

`pc/npc/pc4/inst` 是取指和 PC 更新相关信号。

`npc_op/rf_wsel/sext_op/alu_op/alua_sel/alub_sel/ram_rop/ram_wop` 是控制器产生的控制信号，分别控制下一 PC、写回来源、立即数扩展、ALU 运算、ALU 输入选择和访存类型。

`is_mul/is_div/is_mul_div/mul_div_flag` 用于识别乘除法指令。乘除法不能马上完成，所以要把“正在执行乘除法”保存下来。

`rf_rd1/rf_rd2/rf_we/rf_wR/rf_wD` 是寄存器堆读写相关信号。`rf_wR_r` 用来缓存多周期指令的目标寄存器。

`ext` 是 `SEXT` 输出的扩展立即数。

`alu_a/alu_b/alu_c/br/mul_div_busy` 是 ALU 输入、输出、分支比较结果和乘除忙信号。

`da_ren/da_addr/da_wen/da_wdata/ram_ext/ld_st_flag/ld_st_done` 是访存请求、访存返回和 load/store 多周期控制相关信号。

### 5.3 IF 取指段

`rst_r` 保存上一拍复位值，`first_req = rst_r & !cpu_rst` 用于在复位刚解除时发起第一次取指。

`ifetch_req = first_req | inst_finished_r` 表示两种情况发起取指：复位解除后的第一次取指，或者上一条指令完成后取下一条。

`ifetch_addr = pc`，说明指令 ROM 的地址总是当前 PC。

`NPC U_NPC` 根据 `npc_op`、`pc`、`rf_rd1`、`ext` 和 `br` 计算下一条 PC，同时输出 `pc4`。

`PC U_PC` 在 `inst_finished` 有效时把 `npc` 写入 `pc`。如果指令还没完成，例如 load/store 等待 RAM、乘除法等待 `busy` 拉低，PC 会保持不变。

### 5.4 ID 译码段

`inst = ifetch_valid ? ifetch_inst : 32'h13` 表示只有 ROM 返回有效时才使用真实指令，否则用 `addi x0, x0, 0` 这种 NOP 避免无效指令扰乱组合逻辑。

`Controller U_CU` 从 `opcode/funct3/funct7` 译码，输出所有控制信号。

`RF U_RF` 用 `inst[19:15]` 读 `rs1`，用 `inst[24:20]` 读 `rs2`，用 `inst[11:7]` 作为默认写回寄存器 `rd`。

`SEXT U_SEXT` 接收 `inst[31:7]`，根据 `sext_op` 生成 I/S/B/U/J 型立即数。

`is_ld_st` 判断当前指令是否是 load 或 store。只要 `ram_rop` 不是无读，或者 `ram_wop` 不是无写，就认为是访存指令。

`ld_st_flag` 是访存指令的执行中标志。遇到访存指令时置 1，直到外部 RAM 给出 `daccess_rvalid` 或 `daccess_wresp` 后清 0。

`is_mul_div` 判断当前指令是否是乘除法。`mul_div_flag` 遇到乘除法时置 1，直到 ALU 里的乘除器 `busy` 拉低后清 0。

`rf_wR_r` 和 `pc_r` 在遇到访存或乘除指令时缓存 `rd` 和当前 PC。原因是这些指令完成时可能已经不是取到指令的那一拍，必须保留原指令的写回寄存器和 Trace PC。

### 5.5 EX 执行段

`alu_a = alua_sel ? pc : rf_rd1`，A 端默认用 `rs1`，只有 `auipc` 需要用 `PC`。

`alu_b = alub_sel ? ext : rf_rd2`，B 端可选立即数或 `rs2`。I 型、load/store、`auipc/jalr` 等选立即数；R 型和分支比较选 `rs2`。

`ALU U_ALU` 根据 `alu_op` 完成算术逻辑、移位、比较、乘除等操作。普通运算直接输出 `alu_c`，分支比较输出 `br`，乘除法还输出 `mul_div_busy`。

### 5.6 MEM 访存段

`MREQ U_MEM_REQ` 把 CPU 内部的访存意图转换成 RAM 接口信号。地址来自 `alu_c`，因为 load/store 地址都是 `rs1 + imm` 的 ALU 结果。store 写数据来自 `rf_rd2`。

`MEXT U_MEM_EXT` 对 RAM 读回的 32 位数据做 load 扩展。`lb/lbu/lh/lhu/lw` 的差异主要体现在这里。

`alu_c_r` 缓存 load/store 的地址，用于 load 返回后仍能知道低两位 `byte_offs`。`ram_rop_r` 缓存 load 类型，用于返回后仍能按正确方式扩展。

`store_wdata_r` 缓存 store 写数据，主要用于 Trace 的 `debug_mem_wdata`。

总线接口 always 块把 `da_ren/da_addr/da_wen/da_wdata` 在时钟沿注册到 `daccess_*` 输出。复位时清掉读写使能。

`ld_st_done = daccess_rvalid | daccess_wresp`，表示读数据回来或写响应回来，访存指令就完成。

### 5.7 WB 写回段

`rf_we1` 是最终送给 RF 的写使能。Load 只有在 `daccess_rvalid` 有效时写回；乘除法只有在 `mul_div_busy` 结束时写回；其他普通指令在 `ifetch_valid` 有效并且本身需要写回时立即写回。

`rf_wR` 在访存或乘除法期间使用缓存的 `rf_wR_r`，普通指令直接使用当前指令的 `inst[11:7]`。

`rf_wD` 根据 `rf_wsel` 选择写回数据。普通情况下可选 `ALU.C`、`NPC.pc4`、`SEXT.ext`；只要 `ld_st_flag=1`，写回数据强制来自 `ram_ext`。

`inst_finished` 决定一条指令是否结束。访存指令等 `ld_st_done`，乘除法等 `mul_div_busy` 拉低，其他指令在 `ifetch_valid` 有效时结束。

`inst_finished_r` 把完成信号打一拍，用来触发下一次 `ifetch_req`。

### 5.8 Trace 调试信号

`RUN_TRACE` 打开时，代码导出写回阶段和访存阶段的 debug 信号。

`debug_wb_pc` 对普通指令使用当前 `pc`，对访存和乘除使用缓存的 `pc_r`，避免多周期完成时 PC 对不上原指令。

`debug_wb_rf_we/debug_wb_rf_wR/debug_wb_rf_wD` 分别反映写回使能、目标寄存器和写回数据。

`debug_mem_pc/debug_mem_we/debug_mem_waddr/debug_mem_wdata` 用于记录 store 行为。

## 6. `Controller.v`

`Controller` 是组合译码模块，没有时序寄存器。

第一大段 wire 按指令编码识别每条指令。例如 I 型算术逻辑都用 `opcode=0010011`，R 型都用 `opcode=0110011`，再由 `funct3/funct7` 区分具体操作。

第二段把单条指令归并成控制类别。比如所有条件分支组成 `NPC_OP_BRA`，`jalr` 组成 `NPC_OP_JALR`，`jal` 组成 `NPC_OP_JMP`，其他指令默认 `NPC_OP_PC4`。

`RF_OP_WE` 列出所有需要写回寄存器的指令。store 和 branch 不写回，所以不在这个集合里。

`WB_OP_ALU/WB_OP_RAM/WB_OP_PC4/WB_OP_EXT` 决定 RF 写回数据来源。算术逻辑、乘除、`auipc` 写 ALU；load 写 RAM；`jal/jalr` 写 `PC+4`；`lui` 写立即数。

`EXT_OP_I/S/B/U/J` 决定立即数扩展格式。这个分类直接对应 RISC-V 指令格式。

`ALU_OP_*` 决定 ALU 做什么运算。load/store 和 `jalr` 都用 ADD，因为它们需要计算 `rs1 + imm`；分支用 EQ/NE/LT/GE 等比较操作；乘除用 MUL/DIV/REM 系列。

`ALU_A_SEL_PC` 只给 `auipc` 使用，因为 `auipc = PC + U-imm`。其他指令 ALU A 端默认选 `rs1`。

`ALU_B_SEL_RS2` 包含 R 型、乘除和分支，因为它们第二操作数来自 `rs2`。其余需要 ALU 的指令默认选扩展立即数。

`ram_r_op` 只由 load 指令产生，用来告诉 `MEXT` 如何扩展读回数据。

`ram_w_op` 只由 store 指令产生，用来告诉 `MREQ` 写字节、半字还是整字。

最后的 `assign` 使用按位掩码方式生成具体编码。例如 `{2{WB_OP_ALU}} & \`WB_ALU` 表示若 `WB_OP_ALU` 为 1，就输出 `WB_ALU` 对应编码，否则输出 0；多个候选再按位或起来。

## 7. `ALU.v`

`ALU` 同时负责普通组合运算、分支比较和乘除法调度。

输入 `op/a/b` 是操作码和两个操作数。输出 `c` 是普通结果或乘除结果，`br` 是分支条件结果，`busy` 表示乘除法仍在运行。

前面的 wire/reg 分成三组：乘法相关的 `mul_flag/mulu_flag/mul_res/mulu_res/mul_busy`，除法相关的 `div_flag/divu_flag/div_quo/div_rem/...`，以及用于保存多周期运算状态的 `op_r/a_r/div_neg_r/rem_neg_r/div_zero_r/div_overflow_r`。

`op_eff = (op_r != ALU_NOP) ? op_r : op` 的作用是：乘除法开始后即使外部 `op` 变化，ALU 仍按启动时保存的 `op_r` 输出最终结果。

第一个 `always @(*)` 根据 `op_eff` 产生 `c`。普通加减逻辑移位直接组合输出；`slt/sltu` 输出 0 或 1；乘法从乘法器结果中取低 32 位或高 32 位；除法处理除 0、溢出、有符号商和余数。

第二个 `always @(*)` 根据当前 `op` 产生 `br`。`beq/bne/blt/bge/bltu/bgeu` 分别对应相等、不等、有符号小于/大于等于、无符号小于/大于等于。

`mul_flag/mulu_flag/div_flag/divu_flag` 根据 ALU 操作码启动对应子模块。`busy` 是四个子模块 busy 信号的或。

时序 always 块在复位时清状态；遇到乘除操作时保存 `op/a` 和符号、除 0、溢出信息；当 `busy` 结束后把 `op_r` 清回 `ALU_NOP`。

`multiplier #(32) U_mul` 用于 `mul/mulh`，输入保持原符号位，支持有符号 Booth 乘法。

`multiplier #(33) U_mulu` 用于 `mulhu`，把两个操作数前面补 0 变成无符号乘法，再取高 32 位。

`divider #(32) U_div` 用于 `div/rem`。ALU 先把有符号数转绝对值送入除法器，除完再根据保存的符号修正商和余数。

`divider #(32) U_divu` 用于 `divu/remu`，直接按无符号数相除。

## 8. `PC.v`

`PC` 是程序计数器寄存器。

复位时 `pc <= 32'h0`，CPU 从地址 0 开始执行。

非复位时，如果 `fetch` 为 1，就把 `npc` 写入 `pc`；如果 `fetch` 为 0，PC 保持不变。这里的 `fetch` 在 `cpu_core` 中接的是 `inst_finished`，表示当前指令完成后才更新 PC。

## 9. `NPC.v`

`NPC` 是下一 PC 计算模块。

`pc4 = pc + 4` 是顺序执行地址，也是 `jal/jalr` 写回链接寄存器的返回地址。

`NPC_PC4` 输出 `pc4`，用于普通非跳转指令。

`NPC_JALR` 输出 `(base + offset) & 32'hffff_fffe`。`base` 来自 `rs1`，`offset` 来自 I 型立即数，最低位清零符合 RISC-V `jalr` 规则。

`NPC_BRA` 根据 `br` 选择 `pc + offset` 或 `pc4`，用于条件分支。

`NPC_JMP` 输出 `pc + offset`，用于 `jal`。

## 10. `RF.v`

`RF` 是 32 个通用寄存器的寄存器堆，但数组只声明了 `regs[1:31]`，没有存 `x0`。

读端是组合读：如果读寄存器编号为 0，就直接返回 0；否则返回 `regs[rR1]` 或 `regs[rR2]`。

写端是同步写：时钟上升沿，如果 `we=1` 且 `wR != 0`，就把 `wD` 写入目标寄存器。这样保证 `x0` 永远为 0。

## 11. `SEXT.v`

`SEXT` 是立即数扩展模块。

输入 `imm` 是 `inst[31:7]`，也就是去掉 opcode 后的高 25 位。不同指令格式从这 25 位里取不同字段。

`EXT_I` 取 `imm[31:20]` 并符号扩展，用于 I 型算术、load、`jalr`。

`EXT_S` 拼接 `imm[31:25]` 和 `imm[11:7]`，用于 store。

`EXT_B` 按 B 型格式拼接分支偏移，并在最低位补 0，因为分支目标按 2 字节对齐。

`EXT_U` 输出 `{imm[31:12], 12'h0}`，用于 `lui/auipc`。

`EXT_J` 按 J 型格式拼接跳转偏移，并在最低位补 0，用于 `jal`。

## 12. `MREQ.v`

`MREQ` 把 CPU 内部的访存操作转换成 RAM 的字节写使能和读使能。

`ram_addr` 是 ALU 算出的字节地址，`offset = ram_addr[1:0]` 表示这个地址落在 32 位字的哪个字节位置。

`da_addr = ram_addr` 直接把地址传给 RAM。实际 `Data_RAM` 内部会使用 `data_addr[31:2]` 作为字地址。

写请求 always 块先默认不写，然后根据 `ram_wop` 处理 `sb/sh/sw`。

`sb` 根据 `offset` 选择 4 个字节写使能中的一个，并把 `ram_wdata[7:0]` 移到对应字节位置。

`sh` 只允许半字对齐地址，即 `offset=00` 或 `10`；其他 offset 输出 0，表示不写。

`sw` 只允许字对齐地址，即 `offset=00`；对齐时 `da_wen=1111`。

读请求 always 块根据 `ram_rop` 产生 `da_ren`。`lb/lbu` 任意字节地址都读整字；`lh/lhu` 要求半字对齐；`lw` 要求字对齐。不满足对齐时读使能为 0。

## 13. `MEXT.v`

`MEXT` 对 RAM 读回数据做 load 扩展。

第一段 always 根据 `byte_offs` 把目标字节或半字移动到低位，生成 `real_din`。例如 `byte_offs=2'b10` 时，取原始数据的高半部分放到低 16 位。

第二段 always 根据 `op` 扩展低位数据。`RAM_EXT_B` 做 8 位符号扩展，`RAM_EXT_BU` 做 8 位零扩展，`RAM_EXT_H` 做 16 位符号扩展，`RAM_EXT_HU` 做 16 位零扩展，默认整字返回。

## 14. `Inst_ROM.v`

`Inst_ROM` 是指令存储器封装。

`inst_valid` 在时钟沿等于上一拍的 `inst_rreq`，表示取指请求打一拍后指令有效。

`IROM U_irom` 是 Vivado IP，地址接 `inst_addr[31:2]`。因为指令按 4 字节对齐，低 2 位不用作 ROM 字地址。

## 15. `Data_RAM.v`

`Data_RAM` 是数据存储器封装。

`data_valid` 在时钟沿等于 `|data_ren`，只要有读使能，下一拍就认为读数据有效。

`data_wresp` 在时钟沿等于 `|data_wen`，只要有写使能，下一拍就认为写完成。

`DRAM U_dram` 是 Vivado IP，地址接 `data_addr[31:2]`，写使能 `wea` 是 4 位字节使能，写数据 `dina` 是 32 位。

## 16. `multiplier.v`

`multiplier` 是参数化 Booth 乘法器，`WIDTH` 默认 32。

`O_WID = WIDTH + WIDTH` 是输出乘积宽度，`P_WID = O_WID + 2` 是 Booth 算法内部 product 寄存器宽度。

`product` 保存 Booth 迭代中的部分积和乘数。`x_ext_r` 保存被乘数的符号扩展版本。`count` 记录已经迭代多少位，`busy_r` 表示乘法正在进行。

组合 always 根据 `product[1:0]` 判断本轮 Booth 操作：`01` 加被乘数，`10` 减被乘数，其他保持。然后把 `{next_high, product[WIDTH:0]}` 算术右移一位，得到下一轮 product。

时序 always 复位时清零。`start & !busy_r` 时装载初值：高位清零，低位放乘数 `y`，最低补 0，然后置 `busy_r=1`。

当 `busy_r=1` 时每拍迭代一次。迭代到 `WIDTH-1` 时，把最终 product 的有效位输出到 `z`，并清 `busy_r`。

## 17. `divider.v`

`divider` 是参数化无符号恢复/移位除法器，`WIDTH` 默认 32。

`quotient` 是迭代中的商，`quotient_out` 是最终输出商，`dividend` 是被除数移位寄存器，`divisor` 是除数，`remainder` 是余数，`count` 是迭代计数。

组合信号 `remainder_shift` 表示把余数左移并引入被除数最高位。`remainder_sub` 是尝试减去除数后的结果。`ge_divisor` 判断当前余数是否够减。`quotient_next` 把这一轮商位追加到最低位。

时序 always 复位时清零。`start & !busy` 时开始除法：如果除数为 0，直接输出全 1 商、余数为被除数，并且不进入 busy；否则装载被除数、除数并置 `busy=1`。

`busy=1` 时每拍完成一轮移位减法。如果够减，就用减法后的余数并把当前商位记为 1；否则保留移位后的余数并把商位记为 0。

迭代到 `WIDTH-1` 后输出最终商和余数，并清 `busy`。

注意：这个 `divider` 本身只做无符号除法。有符号 `div/rem` 的取绝对值、符号修正、除 0 和溢出处理都在 `ALU.v` 中完成。

## 18. 一条指令如何穿过这些代码

以 `lw rd, imm(rs1)` 为例：

1. `PC` 输出当前 `pc`，`cpu_core` 发出 `ifetch_req/ifetch_addr`。
2. `Inst_ROM` 根据 `pc[31:2]` 读出指令，并在下一拍给出 `ifetch_valid`。
3. `Controller` 识别 `opcode=0000011`、`funct3=010`，输出 `sext_op=EXT_I`、`alu_op=ALU_ADD`、`alub_sel=ALU_B_EXT`、`ram_r_op=RAM_EXT_W`、`rf_wsel=WB_RAM`、`rf_we=1`。
4. `RF` 读出 `rs1`，`SEXT` 扩展 I 型立即数。
5. `ALU` 计算 `rs1 + imm`，得到 load 地址。
6. `MREQ` 根据 `ram_r_op` 产生 RAM 读使能和读地址。
7. `Data_RAM` 返回读数据并拉高 `data_valid`。
8. `MEXT` 根据地址低两位和 load 类型扩展读数据。
9. `cpu_core` 在 `daccess_rvalid` 有效时拉高 `rf_we1`，把 `ram_ext` 写回 `rd`。
10. `inst_finished` 拉高，`PC` 在下一拍更新为 `NPC` 给出的 `PC+4`。

以 `add rd, rs1, rs2` 为例，路径更短：`PC -> Inst_ROM -> Controller/RF -> ALU -> RF`，没有 MEM 等待，也不需要 `MEXT`。

以 `beq rs1, rs2, offset` 为例：`RF` 读两个源寄存器，`ALU` 判断是否相等并输出 `br`，`SEXT` 生成 B 型偏移，`NPC` 根据 `br` 选择 `pc + offset` 或 `pc + 4`，最后 `PC` 更新。
