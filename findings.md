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
- 用户反馈 Basic Trace 普通指令测试已通过；旧版 `cdp-tests` 下 `start` 失败经对比确认不是 RTL 问题。
- 旧版 `cdp-tests` 的 `start.bin` 与新版哈希一致，二进制未变；差异在测试框架和反汇编注释：新版 `golden_model/emu.c` 将 Digit 外设基址修正为 `0xffff2000`，新版 `start.dump` 也将对应注释修正为 `0xffff2000`。
- 已用远端最新 `cdp-tests` 替换旧框架目录，重新同步 RTL 到 `cdp-tests/mySoC`；`make run TEST=start` 已通过，输出 Digit 计数到 `0x25000025` 并最终 `Test Point Pass!`。
- 已新增 `lab1/实验一收尾与提交清单.md`，整理后续 Vivado 综合/实现截图、报告结构和提交包注意事项。
- 保留老师模板中的 `Inst_ROM/Data_RAM` 地址连接写法；`addra` 位宽 warning 来自 `addr[31:2]` 接入较窄 BRAM IP 地址端口，Vivado 自动截断，不影响已通过的行为仿真、Basic Trace、综合和实现。

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
| `start` 失败按框架版本问题处理 | 旧框架 Digit 外设地址与 `start.bin` 访问地址不一致；更新到最新 `cdp-tests` 后通过，不再作为 RTL 或 `start.bin` 本体错误记录 |

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
- `dist/single_cycle_20260716_093918/`
- `dist/single_cycle_20260716_093918.zip`

## Lab2 Initial Findings
- `lab2/` 已创建但目前为空目录，Git 不会跟踪空目录。
- 课程站点 `https://cpu-design.p.cs-lab.top` 在校园网直连下可访问；走系统代理会出现 TLS 握手失败。
- 实验二材料在课程站点中分为 `lab2-A` 与 `lab2-B` 两条线。
- `lab2-A` 目标是把实验一完整单周期 CPU 改造成至少五级流水线 CPU，支持 miniRV 或 miniLA 全部指令，通过 Basic Trace，并与 SoC 侧集成后通过 AXI Trace 和下板测试。
- `lab2-A` 明确要求：静态分支预测解决控制冒险，暂停与数据前递解决数据冒险，流水线 SoC 频率不低于 50MHz，单周期 SoC 频率不低于 25MHz，下板检查不能有时序违例。
- `lab2-B` 目标是在 FPGA 上基于单周期或流水线 CPU 实现可运行 CoreMark 或 LLAMA2 推理程序的 SoC。
- `lab2-B` 明确要求：实现 ICache/DCache，用状态机实现支持 AXI 协议的总线控制器，添加总线桥与主存模块，完成 I/O 接口测试程序和下板测试，实现拨码开关、LED、数码管、UART、计时器至少 5 个外设，通过 AXI Trace。
- `lab2-A/7-step` 的实施顺序：复制单周期工程；划分数据通路并实现理想流水线；用无相关、无访存、无乘除法程序仿真；增加冒险检测和默认不跳转分支预测；实现暂停法并覆盖访存/乘除取指逻辑；实现数据前递；通过 Basic Trace；再集成 SoC 进行 AXI Trace 和 CoreMark/LLAMA2 下板。
- `lab2-B/3-step` 的实施顺序：复制单周期工程；集成组成原理实验 3 的 ICache/DCache；用状态机实现 `axi_master`；添加总线桥和主存 IP；完成 C_TEST I/O 程序并用提供比特流下板；实现 5 个外设 I/O；通过单周期 SoC AXI Trace；再与流水线 CPU 集成。
- `lab2-B` 调试建议：首次使用 AXI SoC 跑 Trace 时，建议先在 `defines.vh` 禁用 Cache；AXI Trace 通过后再启用 Cache 调试。
- `lab2-B/1-sysbus` 给出 SoC 架构：`cpu_core` 经 ICache/DCache 接入 `axi_master`，`axi_master` 把 Cache/CPU 请求转换为 AXI 读写请求，再经 bridge 访问主存或外设。
- AXI4 基于 `ready`-`valid` 握手；读写地址、写数据、写响应、读数据通道独立。课程简化建议：`rready`、`bready` 复位后可一直有效，`rresp`、`bresp` 可忽略，`arid/awid/wid` 可用常量驱动。
- Cache 侧接口约定：ICache 读接口，DCache 读/写接口；`axi_master` 一般按 DCache 写请求、DCache 读请求、ICache 读请求的优先级处理。
- 外设地址表：SW `0xFFFF_0000` 只读；LED `0xFFFF_1000` 写；数码管 `0xFFFF_2000` 写；UART `0xFFFF_3000/3004/3008/300C` 分别为 RX FIFO、TX FIFO、状态、控制；计时器 `0xFFFF_4000/4008` 读低/高 32 位。

## Lab2 Implementation Findings
- 用户确认实验二所有新内容都应位于 `lab2/`；Lab1 工程只能作为只读功能基线。

## Lab2 Windows Hands-on Preflight (2026-07-28)
- 实操入口确认：`lab2/miniRV_pipeline_axi/miniRV.xpr`，当前 Cache 宏关闭、`RUN_TRACE` 未定义，符合首次 Cache-off 硬件验证要求。
- `lab2/miniRV_pipeline_axi/scripts/rebuild_with_coe.tcl` 会设置 `bram_axi` 的 `CONFIG.Coe_File`，然后重置并执行 IP 综合、顶层综合、实现和写 bitstream；不能只看旧 `.runs` 目录结果。
- `lab2/c_test_rv_stu/0_uart_test/main.coe`（115,712 bytes）和 `main.bin`（51,404 bytes）已存在，可分别用于自建 SoC 固化和课程 bitstream 串口下载验证。
- 脚本的 COE 路径是硬编码的 `F:/lab2/lab2/...`；仅当 Windows/U 盘项目实际位于该路径时可直接使用。路径不同必须在 Vivado 执行前修正该变量并再次核对 Console 的 `Using COE`/`Configured bram_axi COE` 输出。

## EGO1 JTAG Detection Diagnosis (2026-07-30)
- 用户日志已区分两个状态：`No matching targets found` 表示主机未发现 USB-JTAG；`No devices detected on target ...1234-tulA` 表示已发现 USB-JTAG 下载器，但其后的 FPGA JTAG 链为空。
- 本地《EGO1开发板用户手册》确认：EGO1 有两个 Micro-USB 接口，分别为 USB-UART 和 USB-JTAG；两者都可为板卡供电，上电成功时红色 D18 LED 点亮。FPGA 配置应走 USB-JTAG 接口 J22（或独立 6-pin JTAG J3），不是 USB-UART。
- 用户的 COM9 仅证明 CP2102 USB-UART 被系统识别，不能证明 USB-JTAG/J22 或 FPGA JTAG 链路正常。

## Lab2 Vivado Simulation Preflight (2026-07-30)
- `lab2/miniRV_pipeline_axi` 已有仿真集 `sim_1`，顶层是 `src/sim/soc_simple_tb.v`；其停止条件仅为观察 CPU 取到 `ecall`（`32'h00000073`）后打印 `Test Passed!`。
- 该 testbench 不能用于当前非 `RUN_TRACE` 硬件分支的 AXI 主存验收：`miniRV_SoC.v` 第 89-102 行把全部 AXI ready/valid/rdata 固定为零，且未实例化 `bram_axi`、Crossbar 或外设；因此 CPU 的读请求不会得到响应，仿真会停滞。
- `bram_axi.xci` 已存在且当前 COE 指向 `src/coe/lw.coe`，但在完成第 4 节 Crossbar/主存连接前，修改该 IP 的 COE 不会让当前 `soc_simple_tb` 读写通过。

## Cache-off IP Batch Verification (2026-07-30)
- 已验证生成物：`bram_axi`、`axi_crossbar_0`、`Switch`、`LED`、`Dig`、`Timer`、`axi_uartlite_0` 和 5 个 `axi_protocol_converter_*` 均有 `.xci`、`synth/` 与 `sim/` 输出目录。
- Crossbar 已验证为 1 个 Slave、6 个 Master；M00 为 `0x00000000`、地址宽度 18；M01-M05 分别为 `0xFFFF0000`、`0xFFFF1000`、`0xFFFF2000`、`0xFFFF3000`、`0xFFFF4000`，外设宽度均为 12。
- 外设 IP 已验证：Switch 32-bit input；LED 16-bit output；Dig 32-bit output；Timer 双通道、各 32-bit input；UARTLite 为 50 MHz / 115200 / 8-bit / no parity；协议转换器为 AXI4 -> AXI4-Lite、32-bit addr/data。
- Vivado 日志保留一个未解决的环境错误：创建 Crossbar 后出现 `[Common 17-180] Spawn failed: No error`，随后在 `librdi_filemgmt.dll` 的编辑器刷新线程发生 `EXCEPTION_ACCESS_VIOLATION`。Crossbar 输出产物已落盘；尚未执行或声称通过完整工程综合。
- 已在 `lab2/` 固化设计规格 `实验二设计规格.md` 和执行计划 `实验二实施计划.md`。
- 课程 `lab2-A/7-step` 的完成顺序与实现计划一致：理想流水线、冒险检测与分支预测、暂停、前递、Basic Trace、SoC 集成。
- 本地 `lab2/实验3_2026-06-07T15_26_00Z.zip` 含课程参考 `ICache.v`（8,563 字节）和 `DCache.v`（18,386 字节），可在 Lab2-B 中按原接口复用。
- 当前 Git 工作区位于普通 `main` 检出而非 linked worktree；已存在用户未提交文件，且 `.worktrees` 被 `.gitignore` 忽略。实验二 HDL 实现开始前需要用户确认是否创建隔离 worktree。
- 实验一基线复查：`python3 tools/check_minirv_static.py` 输出 `STATIC CHECK PASSED`，`python3 tools/verify_minirv_algorithms.py` 输出 `ALGORITHM CHECK PASSED (16 cases)`。
- Lab2-A 实现为保持原外设接口的五级流水线：IF 响应缓冲、IF/ID、ID/EX、EX/MEM、MEM/WB 有效位、load-use 暂停、EX/MEM/WB 前递、默认不跳转分支冲刷，以及单次启动的乘除法暂停。
- Lab2-A 的完整 Basic Trace 已在本机 Verilator 通过；`div` 初始失败来自多周期暂停期间重复保持 `mem_wb_valid`，`sb` 初始失败来自 Trace 要求保存未经字节移位的源寄存器写数据，均已修正。
- Lab2-B `axi_master` 串行化 DCache 写、DCache 读和 ICache 读，AXI 读按 `IC_BLK_LEN`/`DC_BLK_LEN` 组装数据，AXI 写按 AW/W/B 三阶段完成。`RUN_TRACE` 下 `miniRV_SoC` 直接连接 `bram_axi`。
- Cache 旁路模块在发出 `cpu_*en` 前需要先观察 `dev_*rdy`；因此 AXI 主机空闲态必须先公告可接受状态，不能把 ready 反向依赖尚未产生的 Cache 请求。
- 最终流水线 AXI SoC 的 Cache-off 和 Cache-on 配置均完成 45 个本地 Trace 程序回归。Cache-on Trace 复用框架 `vsrc/ram.v` 的 `blk_mem_gen_1` 行为模型；Vivado 下必须手动生成同名 Block Memory IP。

## Lab2 Downboard Findings (2026-07-28)
- U 盘中的实际 Vivado 工程后来加入了 `axi_peripheral_subsystem.v` 和 AXI 外设 IP；本机仓库当前 `lab2/miniRV_pipeline_axi` 没有该手写外设子系统，不能直接把两者视为同一工程版本。
- 自建 bitstream 无串口输出时，第一步应使用课程官方 `lab2_IOtest_miniRV_ego1.bit` 验证板级 UART；官方 bitstream 可复位后显示下载提示才说明 UART/COM 链路正常。
- `rebuild_with_coe.tcl` 已写死 U 盘 Windows 路径的 `0_uart_test/main.coe`，并在输出中显示实际配置给 `bram_axi` 的 COE，避免默认 `lw.coe` 被误烧录。
- 自建 SoC 首次上板应 Cache-off；这既隔离 ICache/DCache/AXI master 风险，也符合课程 Trace 的推荐调试顺序。
- Linux 使用隔离的 `/tmp/cdp-tests-lab2-axi` 副本同步 `lab2/integrated_soc/miniRV_pipeline_axi/src/rtl` 后，Verilator AXI Trace 全量 45/45 通过。该结果覆盖 CPU、AXI master、指令取数、访存、乘除和 Trace 数码管路径，但不覆盖 Vivado IP、真实 Crossbar/UARTLite、时钟复位和板级 UART。
- Cache-off 顶层的 `pll_lock & pll_clk1` 属于门控时钟，且原 `sys_rst` 在 100 MHz 域产生、被 50 MHz AXI 系统使用。已改为未门控的 `pll_clk1` 和同步释放复位，以避免上板启动随机失败。
- 为使 Vivado 和 Linux Trace 使用同一编译边界，`axi4lite_peripheral_wrap.v` 与 `axi_peripheral_subsystem.v` 已登记入 `.xpr`，顶层不再 include 它们。当前 Cache-off 源文件集重新在 `/tmp/cdp-tests-cache-off` 中全量 Trace 45/45 通过。
- 五条外设支路必须使用各自的 `axi_protocol_converter_0` 至 `_4`。原工程中 converter 1 至 4 被 `AutoDisabled`，会在 RTL 使用它们后导致 Vivado 黑盒/模块缺失；已解除这四个 XCI 的禁用标记，并写入静态检查。

## Visual/Browser Findings
- `pic/PixPin_2026-07-16_09-42-58.png`：Vivado Project Summary，显示 Synthesis Complete、Implementation Complete；Power 摘要显示 Total On-Chip Power `0.068 W`；Timing 区域 WNS/TNS 为 `NA`。
- `pic/PixPin_2026-07-16_09-47-07.png`：Post-Implementation Utilization 报告截图，显示 IO 使用 `41/210`，约 `19.52%`。
- `pic/PixPin_2026-07-16_09-49-16.png`：Post-Implementation Power 报告截图，显示 Total On-Chip Power `0.068 W`、Junction Temperature `25.3 C`、Thermal Margin `59.7 C`。
- `pic/image.png`：Implemented Design 的 Timing Summary 截图，显示 `All user specified timing constraints are met.`；WNS/TNS/失败端点为 `NA`，可解释为当前约束下无可报告的约束违例。
