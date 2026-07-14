# Findings & Decisions

## Requirements
- 实验一按指导书完成单周期 CPU：准备模板、填写数据通路/控制信号表、模块化 Verilog 实现、Basic Trace 验证和整合。

## Research Findings
- 指导书 ZIP：`lab1/cpu设计指导书和指导书仓库-实验1（来自github）.zip`。
- 已通读 ZIP 内 `docs/` 下 Markdown 指导书章节，覆盖实验一主线、miniRV/miniLA 指令说明、基础部件、数据通路、控制器、多周期、乘除法、除法器、时序、Trace、代码规范、提交规范、常见问题和下板调试。
- 已形成独立中文记录：`lab1/指导书通读要点记录.md`。
- 已将指导书通读要点同步进落地方案：`lab1/A_B组模块化Verilog实现落地方案.md`，新增实验主线、Trace 禁改项、提交边界、常见风险和 trap 非当前范围说明。
- 实验步骤原文位于 ZIP 内：`docs/lab1/12-step.md`。
- 该步骤要求：各成员完成 A、B 组指令；小组整合完整数据通路与实现；分别及最终使用 Basic Trace 验证。
- 用户确认：A、B 两组均由其本人完成；采用 miniRV 材料。
- 已有工程：`lab1/miniRV_basic_ego1/miniRV_basic`，含 Vivado 工程及 RTL 源码。
- A 组 18 条：`sll/srl/srli/sra/srai/add/sub/auipc/xor/xori/lb/lbu/lh/lhu/sw/sb/sh/jalr`。
- B 组 18 条：`mul/mulh/mulhu/div/divu/rem/remu/or/and/andi/blt/bge/bltu/bgeu/slt/slti/sltu/sltiu`。
- 合计 36 条待实现；模板另含 8 条示例指令作回归基线。
- 现有 RTL 已有 `Controller/ALU/SEXT/MREQ/MEXT/NPC/cpu_core`；示例仅覆盖 `addi/ori/slli/lw/beq/bne/lui/jal`。
- `MREQ.v` 的字节/半字读写逻辑待完成，且 `cpu_core.v` 当前将 `ram_wdata` 固定为 `32'h0`。
- `multiplier.v`、`divider.v` 是空实现；乘除法也需完成或明确替代方案。
- 指导书第 7 节明确要求自行实现硬件乘/除法器，禁止使用 `*`、`/` 运算符及 IP 核；乘法器建议复用 Booth 补码乘法器。
- 指导书规定乘除模块统一时序：`start` 仅 1 个时钟周期；运行期间 `busy=1`；`busy` 从 1 变 0 时结果有效。
- 指导书第 8 节要求先在 `div_test` 工程完成并仿真除法器，再集成 CPU；除法器可采用恢复余数法或加减交替法，基于寄存器、加法器、移位器、计数器与控制逻辑实现。
- 指导书 `docs/home/codingstyle.md` 给出 Verilog 代码规范：一文件一模块且同名；信号小写、参数/宏大写；每模块带 ``timescale`；组合逻辑用 `always @(*)`、阻塞赋值、完整 `else/default`；时序逻辑用单时钟、非阻塞赋值；禁用 `initial`、声明初始化、复杂循环及未标位宽的常量。
- 指导书宏定义章节要求将控制编码等常量集中在 `.vh` 文件并通过 `include` 使用。
- Trace 章节要求：复制 `src/rtl` 下 HDL 到 `cdp-tests/mySoC`；不要复制 IP；保持 `miniRV_SoC -> cpu_top -> cpu_core` 结构和接口；不要改 `RUN_TRACE` 或 `/* verilator public */`；Trace 框架中 `fpga_rst` 为高电平复位，复位后首条指令地址为 `0x00000000`。
- 提交章节要求：只提交源文件和报告，不提交 Vivado 工程；压缩包必须为 `.zip` 且小于 100MB；报告需包含综合/实现后的资源、功耗等截图。
- Subagent review 结论：落地方案作为草案方向正确，但不建议直接进入 HDL；需先补清多周期乘除提交协议、未对齐访存策略、访存控制编码、逐指令译码/控制矩阵、ALU 与乘除模块边界、Vivado 用户操作清单，并统一工程路径名称。
- 用户确认修订方向：可以按 review 补文档，但必须优先对齐指导书要求；未对齐访存等点不擅自扩展异常/返回值。
- 已按落地文档方案完成 RTL 修改：`defines/Controller/SEXT/NPC/MREQ/MEXT/cpu_core/ALU/multiplier/divider`。
- 已新增静态检查脚本 `tools/check_minirv_static.py`，最终运行结果为 `STATIC CHECK PASSED`。
- 已新增算法级检查脚本 `tools/verify_minirv_algorithms.py`，最终运行结果为 `ALGORITHM CHECK PASSED (16 cases)`。
- 命令行环境未提供 `iverilog` 或 `verilator`；Vivado/Basic Trace 验证需用户在本机环境执行。
- 复审修复：R 型 `or` 需要进入 `ALU_OP_OR`；Booth 乘法器需要锁存被乘数，避免多周期期间输入变化影响结果。
- 静态检查已增强实例端口匹配：覆盖 `cpu_core` 到核心子模块，以及 `ALU` 到乘除模块的具名端口一致性。
- 已新增 Vivado 辅助脚本 `tools/vivado_lab1_check.tcl`，供用户在 Vivado Tcl Console 中打开工程并启动行为仿真。
- 已新增环境检查脚本 `tools/check_vivado_env.ps1`；当前环境 `vivado/xvlog/iverilog/verilator` 均不在 PATH，浅层发现 `D:\Vivado` 但目录为空。
- 已新增单周期源码交付包脚本 `tools/prepare_single_cycle_sources.ps1`；最新运行后生成 `dist/single_cycle_20260714_120705`，仅包含 `rtl/*.v/.vh`、`coe/*.asm/.coe` 和 `manifest.txt`，未复制 `src/rtl/ip` 或 Vivado 生成目录。
- 已生成单周期源码 zip：`dist/single_cycle_20260714_120705.zip`，大小 14,042 字节；zip 内部仅包含 `rtl/`、`coe/`、`manifest.txt`。
- 落地文档已修正乘除模块边界：实际 RTL 为 `multiplier #(32)`、`multiplier #(33)` 和两路 `divider #(32)`；有符号除余语义由 ALU 外围做绝对值与符号恢复。
- RTL 审计发现并修复：`NPC.v`、`SEXT.v` 使用了 ``NPC_*`/``EXT_*` 宏但未显式 ``include "defines.vh"`；已补齐 include，并在 `tools/check_minirv_static.py` 中加入宏 include 检查。
- 静态检查已增强乘除协议检查：确认 `cpu_core` 在无有效取指时保持 NOP，乘除写回/完成受 `mul_div_flag & !mul_div_busy` 控制，`multiplier/divider` 在 busy 时忽略重复 start。
- 用户侧 Vivado Tcl 日志显示：`ls` 报 `ambiguous command name` 的根因是 Tcl Console 不支持 PowerShell/CMD 风格 `ls`；这不影响后续 `source tools/vivado_lab1_check.tcl`。
- 用户侧 Vivado Tcl 日志显示：`open_project`、`update_compile_order` 成功，`xvlog` 编译/分析阶段已处理核心 RTL 与 testbench，未见 Verilog 语法/宏未定义错误。
- 用户侧 Vivado 行为仿真已通过：`xelab` 完成生成 `soc_simple_tb_behav`，XSim simulate 后执行 `run all`，testbench 输出 `Test Passed!`，`$finish` 时间为 `11480100 ps`。
- 当前工作区未发现 `cdp-tests`、`mySoC` 或 Trace 框架目录；Basic Trace 运行需要先放置/下载 Trace 框架。
- 已新增 `tools/prepare_basic_trace_sources.ps1`，用于 Trace 框架就位后将当前 RTL 顶层 `.v/.vh` 同步到 `cdp-tests/mySoC`，不复制 IP 或 Vivado 生成物。
- 用户计划后续转 Linux 跑 Basic Trace；已新增 `tools/prepare_basic_trace_sources.sh` 作为 Linux 版同步脚本。

## Technical Decisions
| Decision | Rationale |
|----------|-----------|
| 尚不创建或修改 Vivado 工程 | 课程指定的指令组、模板工程和开发板尚未确认 |
| 采用“增量扩展现有模块”的方案 | 可复用现有总线时序、Basic Trace 接口和 8 条示例行为 |
| 先修订落地文档再进入 HDL | Subagent review 发现当前文档仍缺少会影响实现正确性的关键协议/矩阵 |
| ALU 内部管理乘除子模块 | 与模板 `ALU.v` 已实例化 `multiplier/divider` 的结构一致，`cpu_core` 只等待 `busy` |
| 当前不声称 Vivado/Trace 已通过 | 本机无可用 Vivado/iverilog/verilator 命令行环境，已在文档中列为用户侧验证门 |
| 乘法器使用 Booth 迭代结构 | 与指导书对 Booth 补码乘法器的方向一致，`mulhu` 通过 33 位补 0 复用 |
| 单周期交付包使用脚本生成的时间戳目录 | 避免清理/覆盖目录导致误删，同时规避 stale 文件混入；后续按 manifest 压缩 |
| 用户侧 Vivado 行为仿真作为模板工程仿真证据 | 它证明 Vivado 能打开工程、编译/展开/运行 `soc_simple_tb` 并得到 `Test Passed!`；不替代 Basic Trace 证据 |

## Issues Encountered
| Issue | Resolution |
|-------|------------|
| 指导书目前压缩在 ZIP 中 | 已可只读访问其 Markdown 正文；按需再解压指定材料 |

## Resources
- `lab1/作业材料整理.md`
- ZIP 内 `docs/lab1/12-step.md`
- `lab1/数据通路表、控制信号取值表_miniRV - A组.xlsx`
- `lab1/数据通路表、控制信号取值表_miniRV - B组.xlsx`
- `lab1/miniRV_basic_ego1/miniRV_basic/src/rtl/`
- `dist/single_cycle_20260714_120705/`
- `dist/single_cycle_20260714_120705.zip`

## Visual/Browser Findings
- 无。
