# miniRV 单周期 CPU：A/B 组模块化 Verilog 实现落地方案

> 状态：**已按本文方案完成 RTL 落地、静态检查、算法边界检查，并已通过用户侧 Vivado 行为仿真**。Basic Trace、综合、实现和报告截图仍按第 7.4 节由用户在本机 Vivado/Trace 环境继续执行。

## 1. 目标与范围

在现有 EGO1 基础工程 `lab1/miniRV_basic_ego1/miniRV_basic` 上，以增量方式实现 A、B 两组共 **36 条** miniRV 指令，并保持 8 条示例指令（`addi/ori/slli/lui/lw/beq/bne/jal`）可用。

| 分组 | 指令 |
|---|---|
| A 组 | `sll`、`srl`、`srli`、`sra`、`srai`、`add`、`sub`、`auipc`、`xor`、`xori`、`lb`、`lbu`、`lh`、`lhu`、`sw`、`sb`、`sh`、`jalr` |
| B 组 | `mul`、`mulh`、`mulhu`、`div`、`divu`、`rem`、`remu`、`or`、`and`、`andi`、`blt`、`bge`、`bltu`、`bgeu`、`slt`、`slti`、`sltu`、`sltiu` |

本方案的验收目标是：

1. 控制器能唯一识别每条目标指令；
2. 数据通路中每个新增选择都由明确控制信号驱动；
3. 非乘除法指令沿用工程现有的取指/完成时序；
4. load/store、跳转和乘除法的握手、写回和 Basic Trace 信号正确；
5. A/B 两份 Excel 的每条数据通路行和控制信号行都可对应到 HDL。

指导书对当前落地的直接约束：

- 实验一按“数据通路表/控制信号表 -> 完整数据通路图 -> 模块化 Verilog -> Basic Trace”的流程验收，不能只事后补代码。
- 当前主线只覆盖 A/B 组 36 条指令与模板已有 8 条指令回归；`13-trap.md` 中的 CSR、异常、中断、`csrrwi/mret/ecall` 视为扩展任务，不纳入本轮 HDL 落地。
- Trace 验证要求保持 `miniRV_SoC -> cpu_top -> cpu_core` 层级、模块名、实例名、`cpu_core` 接口和 Trace 注释不被破坏。
- 乘除法必须自行实现硬件乘法器/除法器，不能使用 `*`、`/` 运算符或现成 IP。

对 subagent review 的采纳原则：优先服从指导书和模板工程已有机制。能让方案更贴近指导书的反馈直接吸收；如果反馈要求自定义异常、未对齐返回值或额外架构，本轮只记录为风险，不擅自扩展实验范围。

## 2. 实现策略选择

| 方案 | 做法 | 优点 | 风险 | 结论 |
|---|---|---|---|---|
| 推荐：增量扩展 | 在现有 `Controller/ALU/SEXT/NPC/MREQ/MEXT/cpu_core` 内补齐功能 | 保留已验证的总线时序、顶层与 Trace 接口；改动聚焦 | 要仔细维护模块间控制编码 | **采用** |
| 重写 `cpu_core` | 重建一套单周期 CPU，再接回顶层 | 结构可完全自定义 | 可能破坏课程模板握手和调试接口，验证成本高 | 不采用 |
| 将乘除法组合化 | 直接以 `/`、`*` 组合求值 | 代码短 | 指导书明确禁止使用运算符或 IP，且会破坏既有 busy/完成机制 | 不采用 |

## 3. 模块边界与职责

```text
指令字段 ──> Controller ─┬─> SEXT ─────────────┐
                         ├─> ALU ─> MREQ/MEXT ─┼─> 写回 MUX ─> RF
PC ──────> NPC <─────────┘                      │
  ^                                              │
  └──────────────────── 目标地址/完成握手 ──────┘
```

| 模块 | 需实现的职责 | 主要覆盖的指令 |
|---|---|---|
| `defines.vh` | 新增 ALU、立即数、NPC 和写回路径需要的宏编码；保留原编码不改义 | 全部 |
| `Controller.v` | 按 `opcode/funct3/funct7` 完整译码；输出 ALU、立即数、访存、写回、跳转和乘除法控制 | 全部 |
| `SEXT.v` | 增加 S 型立即数；现有 I/B/U/J 型保持 | `sb/sh/sw` |
| `ALU.v` | 增加算术、逻辑、移位、带符号/无符号比较及乘除余数结果选择；输出分支条件 | A/B 大多数 ALU、分支、乘除指令 |
| `multiplier.v` | 以 Booth 补码算法实现多周期乘法器的启动、busy、结果寄存；不使用 `*` | `mul/mulh/mulhu` |
| `divider.v` | 以原码恢复余数法实现多周期除法器的启动、busy、商和余数寄存；不使用 `/` | `div/divu/rem/remu` |
| `NPC.v` | 保留 `PC+4`、B/J 型 PC 相对跳转；增加 `jalr=(rs1+imm)&~1` 路径 | `jalr`、`auipc` 间接依赖 PC |
| `MREQ.v` | 生成对齐的读使能、字节/半字/字写掩码，并按地址偏移移动写数据 | `lb/lbu/lh/lhu/sb/sh/sw` |
| `MEXT.v` | 从读出的 32 位字中选 byte/half/word，再做符号或零扩展 | `lb/lbu/lh/lhu` |
| `cpu_core.v` | 连接 `jalr` 所需的寄存器基址；将 store 写数据改接 `rf_rd2`；为 `auipc` 和乘除写回选择正确数据；维持访存/乘除完成时序 | `auipc/jalr`、store、乘除 |

不修改 `RF.v`、`PC.v`、`cpu_top.v`、`miniRV_SoC.v` 的外部接口；除非仿真证明现有接口无法承载上述控制信号。

Trace 相关约束也一并作为模块边界：不改动 `RUN_TRACE` 宏相关代码，不删除或修改 `/* verilator public */` 注释，不改 `debug_wb_*`、`debug_mem_*` 的语义。若 `cpu_core.v` 内部为支持 store、`jalr` 或乘除法而增加寄存信号，只能在内部接线和状态上扩展，不改变 Trace 框架期待的外部形状。

## 4. 控制与数据通路设计

### 4.1 需要扩展的控制信息

现有控制信号继续使用：`npc_op`、`rf_we`、`rf_wsel`、`sext_op`、`alu_op`、`alua_sel`、`alub_sel`、`ram_rop`、`ram_wop`、`is_mul`、`is_div`。

模板控制器已存在 `npc_op/rf_we/rf_wsel/sext_op/alu_op/alua_sel/alub_sel/ram_rop/ram_wop/is_mul/is_div`。本轮优先扩展这些既有控制信号；确需新增的控制只保留最小集合，避免把指令判断散落在 `cpu_core`。

| 新控制 | 取值 | 用途 |
|---|---|---|
| `npc_op` 新增 `NPC_JALR` | `rs1 + I-imm` 后清零最低位 | `jalr` 的下一 PC |
| `alua_sel=ALU_A_PC` | `A=PC` | `auipc` 计算 `PC + U-imm` |

`jalr` 的 `PC` 计算不可复用当前 `NPC_JMP`：当前 `NPC_JMP` 固定为 `pc + offset`，而 `jalr` 必须使用 `rs1 + sext(I-imm)` 并令 bit 0 为 0。

### 4.2 按功能簇落实数据通路

| 功能簇 | 指令 | ALU / 数据路径 | 写回 / PC |
|---|---|---|---|
| R 型算术逻辑 | `add/sub/or/and/xor/sll/srl/sra/slt/sltu` | `RF.rD1` 与 `RF.rD2` 进入 ALU | `WB_ALU`，`PC+4` |
| I 型算术逻辑 | `xori/andi/srli/srai/slti/sltiu` | `RF.rD1` 与 I 型 `SEXT.ext` 进入 ALU | `WB_ALU`，`PC+4` |
| PC 相对计算 | `auipc` | `PC` 与 U 型 `SEXT.ext` 进入 ALU | `WB_ALU`，`PC+4` |
| 读存储器 | `lb/lbu/lh/lhu` | 地址=`rs1+I-imm`；MREQ 读，MEXT 扩展 | `WB_RAM`，`PC+4` |
| 写存储器 | `sb/sh/sw` | 地址=`rs1+S-imm`；数据=`rs2` | 不写 RF，`PC+4` |
| 条件分支 | `blt/bge/bltu/bgeu` | ALU 对 `rs1/rs2` 比较，结果至 `br` | 不写 RF；`PC+4` 或 `PC+B-imm` |
| 链接跳转 | `jalr` | `NPC` 使用 `rs1+I-imm`，最低位清零 | `WB_PC4` |
| M 扩展 | `mul/mulh/mulhu/div/divu/rem/remu` | ALU 触发乘/除模块，busy 期间保持结果/目的寄存器 | 完成时 `WB_ALU` |

### 4.3 指令到 ALU 操作的映射

| 类别 | 新增 `alu_op` |
|---|---|
| 算术/逻辑 | `SUB`、`AND`、`XOR` |
| 移位 | `SRL`、`SRA` |
| 比较/分支 | `LT`、`GE`、`LTU`、`GEU`，并保留 `EQ/NE` |
| 比较写回 | `SLT`、`SLTU`（结果必须是 `32'd0` 或 `32'd1`） |
| 乘除 | `MUL`、`MULH`、`MULHU`、`DIV`、`DIVU`、`REM`、`REMU` |

### 4.4 控制信号矩阵（实现前按此填 Excel）

指导书要求 A/B 组分别填写数据通路表和控制信号表。下面先给 HDL 实现用的指令族矩阵，正式提交表格仍以 Excel 中逐条指令行为准。

| 指令族 | 指令 | 译码关键字段 | `npc_op` | `sext_op` | `alua_sel` | `alub_sel` | `alu_op` | `ram_rop` | `ram_wop` | `rf_we/rf_wsel` | 乘除标志 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| R 算术逻辑 | `add/sub/or/and/xor/sll/srl/sra/slt/sltu` | `opcode=0110011`，由 `funct3/funct7` 区分 | `PC4` | `N` | `RS1` | `RS2` | 对应 ALU op | `N` | `N` | `1/WB_ALU` | `0` |
| I 算术逻辑 | `addi/ori/xori/andi/slli/srli/srai/slti/sltiu` | `opcode=0010011`，移位类还看 `funct7` | `PC4` | `I` | `RS1` | `EXT` | 对应 ALU op | `N` | `N` | `1/WB_ALU` | `0` |
| Load | `lb/lbu/lh/lhu/lw` | `opcode=0000011`，由 `funct3` 区分宽度/符号 | `PC4` | `I` | `RS1` | `EXT` | `ADD` | `B/BU/H/HU/W` | `N` | `1/WB_RAM` | `0` |
| Store | `sb/sh/sw` | `opcode=0100011`，由 `funct3` 区分宽度 | `PC4` | `S` | `RS1` | `EXT` | `ADD` | `N` | `B/H/W` | `0/N` | `0` |
| Branch | `beq/bne/blt/bge/bltu/bgeu` | `opcode=1100011`，由 `funct3` 区分条件 | `BRA` | `B` | `RS1` | `RS2` | `EQ/NE/LT/GE/LTU/GEU` | `N` | `N` | `0/N` | `0` |
| U 型 | `lui` | `opcode=0110111` | `PC4` | `U` | `RS1` | `RS2` | `N` | `N` | `N` | `1/WB_EXT` | `0` |
| U 型 PC 相对 | `auipc` | `opcode=0010111` | `PC4` | `U` | `PC` | `EXT` | `ADD` | `N` | `N` | `1/WB_ALU` | `0` |
| J 型 | `jal` | `opcode=1101111` | `JMP` | `J` | `RS1` | `RS2` | `N` | `N` | `N` | `1/WB_PC4` | `0` |
| I 型跳转 | `jalr` | `opcode=1100111, funct3=000` | `JALR` | `I` | `RS1` | `EXT` | `ADD` 或 `N` | `N` | `N` | `1/WB_PC4` | `0` |
| 乘法 | `mul/mulh/mulhu` | `opcode=0110011, funct7=0000001` | `PC4` | `N` | `RS1` | `RS2` | `MUL/MULH/MULHU` | `N` | `N` | `1/WB_ALU` | `is_mul=1` |
| 除余 | `div/divu/rem/remu` | `opcode=0110011, funct7=0000001` | `PC4` | `N` | `RS1` | `RS2` | `DIV/DIVU/REM/REMU` | `N` | `N` | `1/WB_ALU` | `is_div=1` |

`N` 表示对应控制信号取无操作编码，例如 `RAM_EXT_N/RAM_WE_N`，或该路径结果不会被使用。`add/sub`、`srl/sra`、`srli/srai` 必须用 `funct7` 区分；M 扩展用 `funct7=7'b0000001` 与普通 R 型区分。

### 4.5 访存控制编码与地址语义

| 指令 | `ram_rop` | `ram_wop` | 对齐规则 | 数据处理 |
|---|---|---|---|---|
| `lb` | `RAM_EXT_B` | `RAM_WE_N` | 任意 `addr[1:0]` | 取目标 byte 后符号扩展 |
| `lbu` | `RAM_EXT_BU` | `RAM_WE_N` | 任意 `addr[1:0]` | 取目标 byte 后零扩展 |
| `lh` | `RAM_EXT_H` | `RAM_WE_N` | 仅 `addr[0]==0` | 取目标 half 后符号扩展 |
| `lhu` | `RAM_EXT_HU` | `RAM_WE_N` | 仅 `addr[0]==0` | 取目标 half 后零扩展 |
| `lw` | `RAM_EXT_W` | `RAM_WE_N` | 仅 `addr[1:0]==0` | 直接返回 32 位字 |
| `sb` | `RAM_EXT_N` | `RAM_WE_B` | 任意 `addr[1:0]` | 根据偏移生成 1 位 `wen`，移动 `rs2[7:0]` |
| `sh` | `RAM_EXT_N` | `RAM_WE_H` | 仅 `addr[0]==0` | 根据 `addr[1]` 生成 2 位 `wen`，移动 `rs2[15:0]` |
| `sw` | `RAM_EXT_N` | `RAM_WE_W` | 仅 `addr[1:0]==0` | `wen=4'b1111`，写完整 `rs2` |

地址语义按模板工程处理：ALU 产生字节地址；`MREQ.da_addr/daccess_addr/debug_mem_waddr` 保留字节地址；`Data_RAM` 内部用 `data_addr[31:2]` 接 DRAM 字地址。`MEXT.byte_offs` 使用缓存的 `alu_c_r[1:0]` 定位 byte/half。

未对齐策略按指导书优先：半字/字访问不对齐时，MREQ 不发有效访存请求。本轮不实现异常/中断/CSR，因此 Basic Trace 和定向测试按“不会投放未对齐 half/word load/store”作为前提；如果自定义测试出现未对齐导致等待响应超时，视为超出本轮实验一主线，需要再向指导书/教师要求确认，而不是在本轮擅自定义返回值。

### 4.6 多周期提交协议（沿用模板）

模板 `cpu_core.v` 已按指导书实现访存和乘除法的多周期骨架，本轮只补完整接线与锁存：

| 场景 | 启动拍 | 等待期间 | 完成拍 | 写回/Trace 来源 |
|---|---|---|---|---|
| 普通单周期指令 | `ifetch_valid=1` 且非访存/乘除 | 不等待 | 同拍 `inst_finished=1` | `rf_wR=inst[11:7]`，`rf_wD` 来自 ALU/PC4/EXT |
| Load | `is_ld_st=1`，缓存 `rd/alu_c/ram_rop` | `ld_st_flag=1`，下一次取指不发起 | `daccess_rvalid=1` | `rf_wR=rf_wR_r`，`rf_wD=ram_ext` |
| Store | `is_ld_st=1`，缓存访存状态和原始 `rs2` 写数据 | `ld_st_flag=1`，下一次取指不发起 | `daccess_wresp=1` | 不写 RF，`debug_mem_we/waddr` 来自 `daccess_*`，`debug_mem_wdata` 使用原始 store 数据；实际 RAM 写入仍使用按字节/半字移位后的 `daccess_wdata` |
| Mul/Div | `is_mul_div=1`，ALU 内部 `start` 一拍，缓存 `rd` | `mul_div_flag=1`，等待 `busy` 解除，禁止重复启动 | `!mul_div_busy` | `rf_wR=rf_wR_r`，`rf_wD=alu_c`，`debug_wb_pc` 沿用当前 `pc` |

PC 更新与取指也沿用模板：`PC.fetch=inst_finished`，`ifetch_req=first_req | inst_finished_r`。因此多周期期间 PC 不应前进，下一条指令也不应进入提交。实现时不得破坏 `inst_finished/rf_we1/rf_wR/rf_wD/debug_*` 这条提交链。

### 4.7 ALU 与乘除模块边界

按模板和指导书选择“ALU 内部拥有乘除子模块”的边界：

- `cpu_core` 只负责给 ALU 提供 `op/a/b/clk/rst`，接收 `c/br/busy`，并按 `mul_div_busy` 等待完成。
- `ALU.v` 内部产生 `mul_flag/mulu_flag/div_flag/divu_flag` 作为乘除器 `start`，并用 `op_r` 锁存乘除操作类型。
- `ALU.v` 内部实例化 `multiplier #(32)`、`multiplier #(33)` 和两路 `divider #(32)`；有符号除余的取绝对值、商符号恢复、余数符号恢复在 ALU 外围完成，`busy = mul_busy | mulu_busy | div_busy | divu_busy`。
- `ALU.c` 在普通指令时由组合 ALU 结果给出；在乘除完成后由 `op_r` 选择对应乘积、商或余数。
- `mulhu` 语义固定为 `unsigned(rs1) * unsigned(rs2)` 的 `[63:32]`。若内部使用 33 位补 0 的 Booth 路径，必须明确只取对应无符号 64 位结果的高 32 位，避免误取 66 位乘积高位。

## 5. 关键实现规则（必须遵守）

1. **符号语义**：`sra/srai` 使用 `$signed(a) >>> shamt`；`slt/slti/blt/bge` 使用 `$signed` 比较；`sltu/sltiu/bltu/bgeu` 使用无符号比较。
2. **访存对齐**：`lb/lbu/sb` 可访问任意字节偏移；`lh/lhu/sh` 仅在 `addr[0]==0` 时请求；`lw/sw` 仅在 `addr[1:0]==0` 时请求。未对齐 half/word 访问按指导书“不发访存请求”，本轮不额外实现异常或自定义返回值。
3. **写数据对齐**：`sb` 依据 `addr[1:0]` 生成一位写掩码并把 `rs2[7:0]` 移到对应字节；`sh` 依据 `addr[1]` 生成两位写掩码并移动 `rs2[15:0]`；`sw` 保持 4 位写掩码和完整 `rs2`。
4. **读取扩展**：`lb/lh` 符号扩展，`lbu/lhu` 零扩展，`MEXT` 的 `byte_offs` 只用于定位，不应改变字/半字的符号位来源。
5. **`jalr`**：写回值恒为当前 `PC+4`；目标为 `(rs1 + sext(I-imm)) & 32'hffff_fffe`。
6. **`auipc`**：`SEXT` 产生 `imm<<12`，ALU A 端选择 `PC`，结果从 `WB_ALU` 写回。
7. **乘除法时序**：严格沿用指导书定义：`start` 仅在指令译码周期有效 1 拍；运算期间 `busy=1`；`busy` 由 1 变 0 时结果有效。`cpu_core` 已会缓存目的寄存器，乘除模块 busy 期间不得重复启动。
8. **乘法实现**：`mul/mulh` 使用 32 位 Booth 补码乘法器；`mulhu` 使用 33 位输入（最高位补 0）的同类乘法器。ALU 根据寄存的 `op_r` 选择低 32 位或高 32 位结果。
9. **除法实现**：选择原码恢复余数法，以“被除数/余数寄存器 + 除数寄存器 + 商寄存器 + 计数器 + 加/减与移位控制”迭代 32 次。`div/rem` 在 ALU 外围完成绝对值输入、商符号恢复与余数符号恢复；`divu/remu` 使用零扩展无符号路径。
10. **除法特殊值**：依 RISC-V 语义处理，具体如下。

| 情况 | `div` | `divu` | `rem` | `remu` |
|---|---|---|---|---|
| 除数为 0 | `32'hffff_ffff` | `32'hffff_ffff` | 被除数 | 被除数 |
| `32'h8000_0000 / -1` | `32'h8000_0000` | 无特殊 | `32'h0` | 无特殊 |

## 6. 建议的实施顺序与检查点

| 阶段 | 修改文件 | 完成标准 |
|---|---|---|
| 0. 表格/规格确认 | A/B 数据通路表、控制信号表、本方案 | 每条目标指令都有明确的数据来源、控制取值和写回/PC 行为 |
| 1. 宏与纯组合 ALU | `defines.vh`、`ALU.v`、`Controller.v` | R/I 算术逻辑和四种比较能单独仿真 |
| 2. PC/立即数 | `SEXT.v`、`NPC.v`、`Controller.v`、`cpu_core.v` | `auipc`、`jalr`、B 型分支路径正确 |
| 3. 访存 | `MREQ.v`、`MEXT.v`、`cpu_core.v`、`Controller.v` | byte/half/word 读写的地址、掩码、数据和扩展都正确 |
| 4.1 除法器单测 | `div_test` 工程中的 `divider.v` 或等价独立 testbench | 恢复余数法的 32 次迭代、busy 和商/余数通过独立仿真 |
| 4.2 乘除集成 | `multiplier.v`、`divider.v`、`ALU.v`、`Controller.v` | Booth 乘法器、除法器的 busy、结果选择和写回时刻正确 |
| 5. 回归 | 全部相关 RTL | 8 条示例 + A/B 36 条 Basic Trace 全部通过 |

每一阶段都先填对应 Excel 的数据通路/控制信号行，再编码；这样表格成为 HDL 的设计规格，而不是事后补写的材料。

实施时的节奏按指导书收敛：先小范围指令单测，确认波形和 Trace 写回点，再合并下一簇指令；乘除法在集成进 CPU 前，先按指导书要求在 `div_test` 或等价独立测试环境中验证除法器接口时序和商/余数结果。

## 7. 验证计划

### 7.1 最小定向用例

| 类别 | 代表用例 | 重点观察 |
|---|---|---|
| 算术/移位 | 负数 `sra/srai`、`sub`、大移位量 | 符号扩展、移位方向、低 5 位移位量 |
| 比较/分支 | 正负数边界下的 `blt/bge/bltu/bgeu` | signed/unsigned 分支条件与目标 PC |
| 访存 | 四个 byte offset 的 `lb/lbu/sb`、两个 half offset 的 `lh/lhu/sh` | `daccess_addr/wen/wdata`、MEXT 扩展和写回 |
| 跳转 | `jalr` 的奇数目标地址 | 目标 bit 0 清零、`rd=PC+4` |
| 乘除 | 正负数、除零、最小负数除 `-1` | 独立 `div_test` 的 32 次迭代和 busy；集成后的商/余数与最终写回 |

### 7.2 Basic Trace 观测项

- `debug_wb_pc/debug_wb_rf_we/debug_wb_rf_wR/debug_wb_rf_wD`：所有写回指令；
- `debug_mem_we/debug_mem_waddr/debug_mem_wdata`：`sb/sh/sw`；其中 `debug_mem_wdata` 按 Trace/golden model 对比语义记录原始 store 寄存器值，实际写 RAM 的 `daccess_wdata` 仍按字节使能位置移位；
- 访存响应到来时才完成 load/store，乘除 `busy` 解除时才完成写回；
- 原有 8 条示例指令必须作为回归测试，防止新增编码破坏既有路径。

### 7.3 Trace 框架使用约束

按指导书使用 Basic Trace 时，需要将 Vivado 工程 `src/rtl` 下 HDL 源文件复制到 `cdp-tests/mySoC`，但不要复制 `ip` 文件夹或 IP 核相关文件。Trace 框架中 `fpga_rst` 是高电平复位，复位后首条指令地址是 `0x00000000`。

建议验证顺序：

1. `make` 编译，先消除语法、位宽、timescale、模块名错误。
2. `make run TEST=xxx` 单独跑新实现的指令簇。
3. 出错时根据 Trace 输出的 reference/mycpu 差异定位 PC，再查 `asm/*.dump` 和 `waveform/*.vcd`。
4. 阶段完成后运行 `python3 run_all_tests.py` 批量回归。

Basic Trace 只验证 CPU 内核主存访问，不覆盖外设访问；若后续下板表现和仿真不一致，再按指导书建议排查 bit 文件、Timing Summary、Warning、RTL 规范和在线调试信号。

当前工作区未发现 `cdp-tests`/`mySoC` Trace 框架目录。等 Trace 框架放到工作区后，可用辅助脚本同步 RTL：

```powershell
powershell -ExecutionPolicy Bypass -File tools\prepare_basic_trace_sources.ps1 -TraceRoot cdp-tests
```

如果转到 Linux 环境，可用：

```bash
bash tools/prepare_basic_trace_sources.sh cdp-tests
```

如果 Trace 框架在其他位置，把 `cdp-tests` 改成实际路径。脚本只复制 `src/rtl` 顶层 `.v/.vh` 到 `mySoC`，不会复制 `src/rtl/ip` 或 Vivado 生成物。

### 7.4 需要用户在 Vivado 中执行的操作

当前本机 Vivado 环境仍在安装中，我可以先修改源码、整理文档、做静态检查和可用的文本级/Trace 准备；Vivado GUI 相关操作需要你在本机执行：

1. 打开 `lab1/miniRV_basic_ego1/miniRV_basic/miniRV.xpr`。
2. 确认修改后的 `.v/.vh` 已被 Vivado Sources 刷新；若新建文件，需要 Add Sources。
3. 运行功能仿真，先观察模板 8 条指令回归，再看新增指令波形。
4. 需要下板或报告截图时，运行 Synthesis、Implementation、Generate Bitstream。
5. 截取指导书要求的 Timing、Utilization、Power 等报告页面。
6. 若仿真过但下板异常，再按指导书使用 Warning/Timing Summary/在线调试逐步排查。

也可以在 Vivado Tcl Console 中从工作区根目录执行辅助脚本：

```tcl
cd F:/cpu-design
source tools/vivado_lab1_check.tcl
```

该脚本会打开工程、更新编译顺序、启动行为仿真并执行 `run all`；最终仍需你根据 Vivado transcript、波形和测试输出判断是否通过。Vivado Tcl Console 不是 PowerShell/CMD，`ls` 会被 Tcl 解释成不唯一的命令前缀并报 `ambiguous command name "ls": lsearch lset lsort`；如果只是想列目录，可用 `glob *`，或在系统终端里使用 `dir/ls`。

当前用户侧 Vivado 日志已确认：

- `open_project` 成功打开 `miniRV.xpr`；
- `update_compile_order` 成功执行；
- `xvlog` 已分析 `ALU/Controller/MREQ/MEXT/NPC/SEXT/cpu_core/multiplier/divider` 等核心 RTL，没有在粘贴日志中出现 Verilog 语法或宏未定义错误；
- `xelab` 已完成 elaborate，生成 `soc_simple_tb_behav` snapshot；
- XSim 已进入 simulate，`run all` 后 testbench 输出 `Test Passed!`；
- `$finish` 时间为 `11480100 ps`，位置为 `src/sim/soc_simple_tb.v` 第 22 行。

因此当前 Vivado 行为仿真可记录为 **通过**。日志中的 `VRFC 10-3091` 位宽 warning、Block Memory Generator 行为模型 warning、地址越界 warning 未阻止仿真通过；若后续 Basic Trace 或下板出现相关异常，再按 warning 逐项复查。

若不确定本机命令行环境是否配置好，可先在 PowerShell 执行：

```powershell
powershell -ExecutionPolicy Bypass -File tools\check_vivado_env.ps1
```

当前我在本环境中检查到：`vivado/xvlog/iverilog/verilator` 均不在 PATH，`D:\Vivado` 目录存在但顶层为空，因此无法在这里完成 Vivado/Trace 侧验证。

### 7.5 单周期源码交付包准备

为贴合指导书“单周期部分提交源文件，不提交完整 Vivado 工程/IP 目录”的要求，已补充源码收敛脚本：

```powershell
powershell -ExecutionPolicy Bypass -File tools\prepare_single_cycle_sources.ps1
```

默认会生成 `dist/single_cycle_时间戳/`，其中只包含：

- `rtl/*.v`、`rtl/*.vh`：`src/rtl` 顶层 RTL 源文件；
- `coe/*.asm`、`coe/*.coe`：当前工程中的指令/存储初始化材料；
- `manifest.txt`：本次打包清单和排除项说明。

脚本刻意不复制 `src/rtl/ip`、Vivado `.runs/.cache/.sim/.hw/ip_user_files` 等生成物。后续若要上传作业系统，应以该目录为基础再压缩成 zip；若 Basic Trace 需要复制到 `cdp-tests/mySoC`，也优先从该目录里的 `rtl` 文件取源。

当前已实跑一次，生成：

```text
dist/single_cycle_20260714_120705
dist/single_cycle_20260714_120705.zip
```

该目录和 zip 包包含 17 个 RTL 源文件、3 个 `coe/asm` 初始化文件和 `manifest.txt`，未包含 IP 或 Vivado 生成物。zip 包大小约 14 KB，低于指导书 100 MB 限制。

## 8. 文件变更清单（已执行）

| 文件 | 改动性质 |
|---|---|
| `src/rtl/defines.vh` | 已新增 ALU、`NPC_JALR`、`EXT_S` 等宏 |
| `src/rtl/Controller.v` | 已扩展 36 条 A/B 指令及模板指令译码、访存控制、乘除标志 |
| `src/rtl/ALU.v` | 已扩展组合运算、分支比较、乘除启动/忙等待/结果选择 |
| `src/rtl/SEXT.v` | 已新增 S 型立即数扩展 |
| `src/rtl/NPC.v` | 已新增 `jalr=(rs1+imm)&~1` 路径 |
| `src/rtl/NPC.v`、`src/rtl/SEXT.v` | 已补齐 ``include "defines.vh"`，避免 Vivado/Trace 独立编译时宏未定义 |
| `src/rtl/MREQ.v` | 已完成读写对齐、掩码与写数据对齐 |
| `src/rtl/MEXT.v` | 已完成 byte/half/word 抽取和符号/零扩展 |
| `src/rtl/multiplier.v` | 已完成多周期 Booth 补码乘法器，不使用 `*` 乘法运算 |
| `src/rtl/divider.v` | 已完成多周期恢复除法器，不使用 `/` 除法运算 |
| `src/rtl/cpu_core.v` | 已完成 store 数据、`jalr` 基址与写回整合 |
| `tools/prepare_single_cycle_sources.ps1` | 已新增单周期源码交付包准备脚本，默认排除 IP 与 Vivado 生成物 |
| `tools/prepare_basic_trace_sources.ps1` | 已新增 Basic Trace 源码同步脚本，等待 `cdp-tests/mySoC` 框架后使用 |
| `tools/prepare_basic_trace_sources.sh` | 已新增 Linux Basic Trace 源码同步脚本，转 Linux 后使用 |
| `dist/single_cycle_20260714_120705.zip` | 已生成单周期源码 zip 包，内容仅含 `rtl/`、`coe/`、`manifest.txt` |

未新增独立的“总控模块”，未改动顶层端口或 IP 文件；Vivado 工程可直接沿用。

## 8.1 当前自动验证结果

当前已新增并运行静态检查脚本：

```powershell
python tools\check_minirv_static.py
```

结果：`STATIC CHECK PASSED`。

用户侧 Vivado 行为仿真：

```tcl
cd F:/cpu-design
source tools/vivado_lab1_check.tcl
```

结果：`Test Passed!`，`$finish called at time : 11480100 ps`。

该脚本覆盖：

- 必要宏、译码 wire、访存编码、`jalr`/store 关键接线；
- `MREQ/MEXT` byte/half/word 访存扩展关键实现；
- `ALU` 目标操作和乘除 `busy` 汇总；
- R 型 `or` 必须映射到 `ALU_OR`；
- Booth 乘法器必须锁存被乘数，避免 busy 期间输入变化污染迭代；
- `cpu_core` 与 `NPC/PC/Controller/RF/SEXT/ALU/MREQ/MEXT`、`ALU` 与 `multiplier/divider` 的实例端口必须和模块定义匹配；
- 使用反引号宏的核心 RTL 文件必须显式 ``include "defines.vh"`；
- 乘除法完成链必须通过 `mul_div_flag & !mul_div_busy` 写回/完成，且子模块在 `busy` 时忽略重复 `start`；
- `multiplier.v`、`divider.v` 内不出现算法级 `*`/`/` 运算符。

补充扫描结果：

- 核心 RTL 中未检出残留 `TODO`、旧 `assign busy = 1'b0`、`is_mul/is_div` stub、`ram_wdata(32'h0)` store 旧接线。
- `multiplier.v`、`divider.v` 中仅剩 ``timescale 1ns / 1ps` 的语法斜杠，不属于除法运算。

另新增算法级边界检查：

```powershell
python tools\verify_minirv_algorithms.py
```

结果：`ALGORITHM CHECK PASSED (16 cases)`。

该脚本用 Python 参考语义对照 RTL 同构算法模型，覆盖 signed/unsigned 乘法高低位、除零、`0x8000_0000 / -1`、正负数组合和余数符号等边界。它不能替代 Vivado 仿真，但能在本机无 Verilog 仿真器时提供一层数值语义校验。

## 9. Verilog 代码规范（指导书约束）

后续所有新增或修改的 RTL 均遵循指导书 `docs/home/codingstyle.md` 与 `docs/lab1/A-macro.md`。基础工程的既有端口和模块名称属于既有接口，不为统一命名而做无关重构；新写逻辑遵守以下规则。

| 规则 | 本次落实方式 |
|---|---|
| 一文件一模块、文件与模块同名 | 仅在已有同名 `.v` 中补全对应模块；不在同一文件新增第二个模块 |
| 时间精度 | 每个修改的 Verilog 模块保留/补齐 ``timescale 1ns / 1ps` |
| 命名 | 新信号使用语义明确的小写下划线命名；宏、`parameter`、`localparam` 使用大写 |
| 控制常量 | ALU/NPC/扩展/访存等编码集中在 `defines.vh`，模块通过 ``include "defines.vh"` 使用，禁止散落的 magic number |
| 组合逻辑 | 仅用 `always @(*)`；块开头给默认值；使用阻塞赋值 `=`；每个 `if` 有 `else`，每个 `case` 有 `default`，避免锁存器 |
| 时序逻辑 | 只使用单一上升沿时钟（异步复位除外）；使用非阻塞赋值 `<=`；一个块只维护一组相关状态 |
| 初始化与常量 | 不使用 `initial` 或声明时初始化；全部由复位进入确定状态；常量标明位宽，如 `1'b0`、`32'h0` |
| 位宽与端口 | 实例化采取具名端口连接；所有数据路径显式匹配位宽；不遗留未连接端口 |
| 循环与表达式 | 乘除法采用寄存器/计数器状态机，不使用 `for/repeat/while`、`*`、`/` 或复杂不可审计表达式 |

提交前会按上述规则检查 `Controller.v`、`ALU.v`、`SEXT.v`、`NPC.v`、`MREQ.v`、`MEXT.v`、`multiplier.v`、`divider.v`、`cpu_core.v` 和 `defines.vh`。

## 10. 交付与风险边界（指导书约束）

交付侧要提前控制文件范围：

- 作业系统只支持 `.zip`，且不支持大于 100MB。
- 单周期部分提交源文件，不提交完整 Vivado 工程；后续整理时应只收敛 `single_cycle/` 下所需 `.v/.vh/.asm/.coe` 等源材料。
- 报告要求 PDF；若进入完整课程交付，还需要综合/实现后的资源使用、功耗等截图。
- 不提交 Vivado 生成物，例如 `.runs/.cache/.hw/.sim/ip_user_files`、完整 IP 目录、bitstream 临时产物等。

实现侧常见风险清单：

- 宏定义必须在使用文件中 ``include "defines.vh"`，引用时带反引号。
- 移位量统一取低 5 位，避免大于 31 或符号解释错误。
- Load 读到 0 时先查字节地址/字地址转换，再查 store 写数据是否仍被固定为 `32'h0`。
- 分支或 `jalr` 出错时优先查 PC 来源、立即数扩展、`br` 条件和 `inst_finished` 时序。
- Trace 全部 time out 时优先查复位极性、PC 初值、取指请求和模块层级是否被破坏。
- Critical Warning 若涉及时钟，重点查是否混用上升沿/下降沿或产生组合环。

## 11. 执行前确认

请你核对以下执行状态：

- [x] 以现有 `lab1/miniRV_basic_ego1/miniRV_basic` 为唯一实现工程；
- [x] A/B 两组全部 36 条指令均纳入 RTL 实现范围；
- [x] 按本文“增量扩展 + 多周期乘除法”的方案执行；
- [x] 本轮不实现 `13-trap.md` 的异常/中断/CSR 扩展任务；
- [x] 已完成本机可执行的静态检查；
- [x] 已补充 Vivado Tcl 辅助脚本 `tools/vivado_lab1_check.tcl`；
- [x] 已补充环境检查脚本 `tools/check_vivado_env.ps1`；
- [x] 已补充单周期源码交付包脚本 `tools/prepare_single_cycle_sources.ps1`；
- [x] 已生成单周期源码 zip 包 `dist/single_cycle_20260714_120705.zip`；
- [x] 用户侧 Vivado 行为仿真已通过，transcript 输出 `Test Passed!`；
- [ ] Basic Trace、综合、实现、报告截图由用户在本机继续执行，我负责给出源码和检查清单。
