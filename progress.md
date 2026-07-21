# Progress Log

## Session: 2026-07-14

### Phase 1-5：需求、方案、实现、验证准备与交付整理
- **Status:** RTL 已落地；本机静态/算法/交付包验证已完成；用户侧 Vivado 行为仿真已通过；Basic Trace 含新版 `cdp-tests` 下 `start` 综合测试已通过；进入报告/截图收尾
- **Started:** 2026-07-14
- Actions taken:
  - 确认实验指导书 ZIP 与作业材料整理文件存在。
  - 阅读实验步骤章节，确认共有 7 个主步骤。
  - 建立持续任务计划、发现记录与进度记录。
  - 读取 A/B 作业材料、B 组模板和 miniRV EGO1 的核心 RTL。
  - 确认 A/B 组合计 36 条目标指令，且基础工程中有明确待完成的访存和乘除法模块。
  - 阅读指导书的多周期、乘除法和除法器章节，确认乘除法不得使用运算符/IP，并应先单测除法器。
  - 阅读指导书 Verilog 代码规范和宏定义章节，并把要求纳入落地方案。
  - 通读指导书 ZIP 内 `docs/` 下 Markdown 章节，补充 Trace、提交、常见问题、下板调试等要求。
  - 新增中文通读记录 `lab1/指导书通读要点记录.md`，作为后续 HDL 落地约束清单。
  - 按用户要求同步更新 `lab1/A_B组模块化Verilog实现落地方案.md`，补入指导书通读后的 Trace、提交、风险和非当前范围约束。
  - 按用户要求启动 subagent review 落地文档；review 返回结论：方向正确，但需先补多周期提交、未对齐访存、控制矩阵、ALU/乘除边界和 Vivado 用户操作清单。
  - 按用户“优先对齐指导书要求”的方向修订落地文档：补控制矩阵、访存编码、地址语义、多周期提交协议、ALU/乘除边界、Vivado 用户操作清单，并清理文末残留备注。
  - 创建 `tools/check_minirv_static.py`，先观察模板 RED 失败，再完成 RTL 后观察 GREEN：`STATIC CHECK PASSED`。
  - 创建 `tools/verify_minirv_algorithms.py`，用 Python 参考语义对照 RTL 同构算法模型，最终 `ALGORITHM CHECK PASSED (16 cases)`。
  - 复审并修复 R 型 `or` 控制器映射，以及 Booth 乘法器未锁存被乘数的问题。
  - 新增 `tools/vivado_lab1_check.tcl`，方便用户在 Vivado Tcl Console 里打开工程并运行行为仿真。
  - 新增 `tools/check_vivado_env.ps1`，用于检查 Vivado/Verilog 命令行工具可用性；当前环境未发现可用工具。
  - 修正 `multiplier.v` 端口宽度对内部 `localparam` 的前向引用，降低 Vivado 语法兼容风险。
  - 增强 `tools/check_minirv_static.py`，加入模块实例具名端口匹配检查；增强后仍 `STATIC CHECK PASSED`。
  - 完成 A/B 组 36 条指令相关 RTL 落地：控制器、立即数、NPC、访存、ALU、乘法器、除法器和 cpu_core 接线。
  - 更新落地文档状态为“已按本文方案完成 RTL 落地与静态检查；Vivado/Trace 待用户本机执行”。
  - 修正落地文档中 `divider #(33)` 的早期表述，使其与当前 RTL 中两路 `divider #(32)` 保持一致。
  - 新增 `tools/prepare_single_cycle_sources.ps1`，按指导书交付边界生成单周期源码包，排除 IP 与 Vivado 生成物。
  - 运行交付包脚本，生成 `dist/single_cycle_20260714_114311`，内容为 `rtl/*.v/.vh`、`coe/*.asm/.coe` 和 `manifest.txt`。
  - 继续审计 RTL 与落地文档要求的证据链，发现 `NPC.v`、`SEXT.v` 使用宏但缺少 ``include "defines.vh"`，已补齐。
  - 增强 `tools/check_minirv_static.py`：新增宏 include 检查、乘除 NOP 抑制/完成链检查、子模块 busy 时忽略重复 start 检查。
  - 重新运行静态检查，结果仍为 `STATIC CHECK PASSED`。
  - 重新生成最新单周期源码包 `dist/single_cycle_20260714_120705`，包含修复后的 RTL。
  - 生成 `dist/single_cycle_20260714_120705.zip`，并检查 zip 内部仅含 `rtl/`、`coe/`、`manifest.txt`，大小 14,042 字节。
  - 读取用户贴出的 Vivado Tcl 日志：确认 `ls` 报错只是 Tcl Console 命令前缀歧义，不是工程/RTL 错误；`source tools/vivado_lab1_check.tcl` 已打开工程并完成 `xvlog` 源码分析阶段。
  - 将用户侧 Vivado 部分验证证据同步到落地文档：目前证明“Vivado 编译分析阶段未见 RTL 语法/宏错误”，但尚未证明 `xelab/run all/Test Passed`。
  - 根据用户再次运行脚本的日志修复 `tools/vivado_lab1_check.tcl`：当目标 `miniRV.xpr` 已经打开时复用当前工程，避免 `ERROR: [Coretcl 2-101] Project ... is already open` 阻断后续仿真流程。
  - 读取用户最新 Vivado transcript：`xvlog` compile、`xelab` elaborate、XSim simulate 均完成，`run all` 后输出 `Test Passed!`，`$finish` 时间为 `11480100 ps`。
  - 更新落地文档、发现记录和进度记录：Vivado 行为仿真状态改为已通过；Basic Trace、综合/实现/报告截图仍保留为后续门。
  - 检查当前工作区，未发现 `cdp-tests`、`mySoC` 或 Trace 框架目录。
  - 新增 `tools/prepare_basic_trace_sources.ps1`，用于 Trace 框架就位后把 `src/rtl` 顶层 `.v/.vh` 同步到 `cdp-tests/mySoC`，并排除 IP/生成物。
  - 用户确认后续转 Linux 跑 Basic Trace；新增 `tools/prepare_basic_trace_sources.sh`，提供 Linux 版 RTL 同步脚本。
  - 用户反馈 Basic Trace 除旧框架下 `start` 综合测试外全部通过；初步记录为外部测试框架异常。
  - 新增 `lab1/实验一收尾与提交清单.md`，整理下一步综合/实现截图、报告结构、提交包边界和 `start.bin` 异常说明。
  - 对 `Data_RAM.v`、`Inst_ROM.v` 保持老师模板原始地址连接：恢复 `.addra(data_addr[31:2])` 与 `.addra(inst_addr[31:2])`，不为清理 warning 修改模板封装。
  - 恢复后重新运行静态检查：`STATIC CHECK PASSED`。
  - 重新生成恢复模板后的最新源码包和 zip：`dist/single_cycle_20260716_093918.zip`，大小 14,056 字节。
  - 对比旧版 `cdp-tests` 与远端最新 `miniRV` 分支：`start.bin` 哈希不变，`start.dump` 注释与 `golden_model/emu.c` 中 Digit 外设地址已从旧版不一致状态修正为 `0xffff2000`。
  - 用远端最新 `cdp-tests` 替换旧框架目录，重新同步 RTL 到 `cdp-tests/mySoC`，删除临时 `cdp-tests.clean` 目录。
  - 运行 `make clean && make run TEST=start`：新版框架输出 Digit 计数至 `0x25000025`，最终 `Test Point Pass!`。
  - 验证后执行 `make -C cdp-tests clean`，清除 `obj_dir`、`waveform`、`meminit.bin`，工作区仅保留正式 `cdp-tests` 目录。
  - 对照指导书和 `pic/` 截图：现有截图已覆盖 Vivado 综合/实现完成、Post-Implementation Utilization、Power 和 Timing Summary；Timing Summary 显示 `All user specified timing constraints are met.`。
  - 新增 `lab1/课堂验收恶补.md`：整理课堂验收缺口、现场打开文件、模块解释、截图说明、Trace 命令和高频问答，供用户短时间补基础和准备现场口径。
- Files created/modified:
  - `task_plan.md`（创建）
  - `findings.md`（创建）
  - `progress.md`（创建）
  - `lab1/指导书通读要点记录.md`（创建）
  - `lab1/实验一收尾与提交清单.md`（创建）
  - `lab1/课堂验收恶补.md`（创建）
  - `lab1/A_B组模块化Verilog实现落地方案.md`（更新）
  - `tools/check_minirv_static.py`（创建）
  - `tools/verify_minirv_algorithms.py`（创建）
  - `tools/vivado_lab1_check.tcl`（创建）
  - `tools/check_vivado_env.ps1`（创建）
  - `tools/prepare_single_cycle_sources.ps1`（创建）
  - `tools/prepare_basic_trace_sources.ps1`（创建）
  - `tools/prepare_basic_trace_sources.sh`（创建）
  - `dist/single_cycle_20260716_093918/`（最新生成的交付包目录）
  - `dist/single_cycle_20260716_093918.zip`（最新单周期源码 zip 包）
  - `docs/superpowers/plans/2026-07-14-minirv-ab-implementation.md`（创建）
  - `lab1/miniRV_basic_ego1/miniRV_basic/src/rtl/*.v/.vh`（实现修改）

## Test Results
| Test | Input | Expected | Actual | Status |
|------|-------|----------|--------|--------|
| 指导书步骤读取 | ZIP 内 `docs/lab1/12-step.md` | 可读到实验步骤 | 成功读到 7 步 | ✓ |
| B 组模板读取 | B 组 `.xlsx` 的两张工作表 | 得到指令和控制字段 | 成功读到 18 条和字段 | ✓ |
| EGO1 核心 RTL 阅读 | `Controller/ALU/SEXT/MREQ/MEXT/cpu_core` | 确定接口与缺口 | 成功定位 | ✓ |
| 乘除法指导书阅读 | 第 6、7、8 节 | 确认算法与时序要求 | 已确认硬性限制及集成顺序 | ✓ |
| 代码规范阅读 | `codingstyle.md`、`A-macro.md` | 形成 RTL 约束清单 | 已写入落地方案第 9 节 | ✓ |
| 指导书通读 | ZIP 内 `docs/**/*.md` | 形成中文要点记录 | 已写入 `lab1/指导书通读要点记录.md` | ✓ |
| 静态 RTL 检查 | `python tools\check_minirv_static.py` | 覆盖关键宏、译码、接线、访存、乘除禁用运算符 | `STATIC CHECK PASSED` | ✓ |
| 算法边界检查 | `python tools\verify_minirv_algorithms.py` | 覆盖乘除特殊值和边界样例 | `ALGORITHM CHECK PASSED (16 cases)` | ✓ |
| Vivado 环境检查 | `powershell -ExecutionPolicy Bypass -File tools\check_vivado_env.ps1` | 找到 Vivado/Verilog 命令行或给出用户侧验证路径 | Codex 环境工具缺失；用户侧 Vivado 可用 | ⚠ |
| 单周期源码包准备 | `powershell -ExecutionPolicy Bypass -File tools\prepare_single_cycle_sources.ps1` | 生成不含 IP/生成物的源码包 | `dist/single_cycle_20260714_114311`，含 RTL/COE/manifest | ✓ |
| 补强静态检查 | `python tools\check_minirv_static.py` | 覆盖宏 include、多周期乘除完成链与 busy 抑制 | `STATIC CHECK PASSED` | ✓ |
| 最新单周期源码包准备 | `powershell -ExecutionPolicy Bypass -File tools\prepare_single_cycle_sources.ps1` | 生成包含最新 RTL 的源码包 | `dist/single_cycle_20260714_120705`，含 RTL/COE/manifest | ✓ |
| 单周期源码 zip | `Compress-Archive -Path dist\single_cycle_20260714_120705\* -DestinationPath dist\single_cycle_20260714_120705.zip -Force` | 生成小于 100MB 且不含 IP/生成物的 zip | 14,042 字节，仅含 `rtl/`、`coe/`、`manifest.txt` | ✓ |
| 用户侧 Vivado 行为仿真 | `source tools/vivado_lab1_check.tcl` | Vivado 打开工程、编译、展开并运行 testbench | `xvlog`/`xelab`/XSim 完成，`run all` 输出 `Test Passed!`，`$finish` at `11480100 ps` | ✓ |
| 用户侧 Basic Trace | Linux Trace 框架批量测试 | A/B 组与模板指令回归通过 | 用户反馈普通指令批测通过；旧框架 `start` 失败已定位为框架版本问题 | ✓ |
| 新版 start 综合测试 | `make run TEST=start` | Digit 计数到 `0x25000025` 并输出 `Test Point Pass!` | 通过，退出码 0 | ✓ |

## Error Log
| Timestamp | Error | Attempt | Resolution |
|-----------|-------|---------|------------|
| 2026-07-14 | 默认 session-catchup.py 路径不存在 | 1 | 改用实际安装目录，恢复检查成功 |
| 2026-07-14 | `git log/status` 失败：工作区不是 Git 仓库 | 1 | 不依赖版本记录，按磁盘现有材料探索 |
| 2026-07-14 | Windows 沙箱读文件/列目录报 1312 | 1 | 对必要只读操作使用授权方式重跑并成功 |
| 2026-07-14 | `vivado/xvlog/iverilog/verilator` 不在 PATH | 多次检查 | 保留 Vivado Tcl 与环境检查脚本，等待用户本机 Vivado/Trace 执行 |
| 2026-07-14 | Vivado Tcl Console 输入 `ls` 报 `ambiguous command name "ls": lsearch lset lsort` | 用户侧日志 | 根因是 Tcl 命令前缀歧义；Vivado Tcl 中列目录用 `glob *`，或在系统终端使用 `dir/ls` |
| 2026-07-14 | `source tools/vivado_lab1_check.tcl` 报 `Project ... is already open` | 用户侧日志 | 修复 Tcl 脚本：若当前已打开目标工程则复用；若打开的是其他工程则先 `close_project` 再打开目标工程 |
| 2026-07-17 | 旧 `cdp-tests` 运行 `start` 报 `Memory access out of bound` | 只读对比新旧框架 | 根因是旧框架 Digit 外设地址与 `start.bin` 实际访问地址不一致；替换为最新 `cdp-tests` 后 `start` 通过 |

## 5-Question Reboot Check
| Question | Answer |
|----------|--------|
| Where am I? | RTL 已落地，本机静态/算法/交付包验证已完成，用户侧 Vivado 行为仿真已通过，Basic Trace 含新版 `start` 已通过 |
| Where am I going? | 继续综合/实现、报告截图和最终提交包整理 |
| What's the goal? | 完成实验一单周期 CPU 的设计、实现、验证和交付整理 |
| What have I learned? | 见 findings.md |
| What have I done? | 已定位并阅读实验步骤，建立计划文件 |

## Session: 2026-07-22

### Lab2：C_TEST TODO 与编译
- **Status:** in progress
- 已从 `https://cpu-design.p.cs-lab.top/lab2-B/assets/c_test_rv_stu.tar.gz` 下载官方原包。必须同时清除大小写代理环境变量后直连课程站点；系统代理会导致 TLS `unexpected eof`。
- 已解压到 `lab2/c_test_rv_stu`，补完 UART、格式化 I/O、排序和 LLAMA2 的所有 TODO，并统一写入学号 `2024311270`；`3_ddr_test`、`4_coremark` 未改动。
- 静态 TODO 检查通过。本机缺少 `riscv32-unknown-elf-*` 工具链且无无密码管理员权限；待用户安装后运行各目录的 `compile.sh` 并验证 `main.s`、`main.coe`、`main.bin`。
- 用户已安装 GNU RISC-V 与 Picolibc 工具链。Picolibc 开启 `--gc-sections` 且要求双下划线堆符号，因此为四个目标脚本增加兼容参数 `-Wl,-e,_start`、Picolibc specs 和堆边界别名；另修复课程排序源码的 `CLKS_PER_SEC` 宏名及 LLAMA2 的 `<stdint.h>` 缺失、裸机 `fflush(stdout)` 调用。
- `0_uart_test`、`1_formatIO_test`、`2_sort_test`、`5_llama2.c` 均成功生成非空 `main.s`、`main.coe`、`main.bin`。在线文档确认：测试 0 至 2 可按 EGO1 C_TEST 流程下板；LLAMA2 必须使用 Minisys、DDR/MIG、112640 x 32-bit BRAM 和 7 主设备 Crossbar。

### Lab2：Vivado 工程骨架
- **Status:** prepared; waiting for Vivado verification
- 已将 `lab1/miniRV_basic_ego1/miniRV_basic` 完整复制为 `lab2/miniRV_pipeline_axi`，以 `lab2/integrated_soc/miniRV_pipeline_axi/src` 覆盖工程源文件，并保留 Lab1 的 `.xpr`、IP、缓存、仿真和运行目录。
- `miniRV.xpr` 已登记 Lab2 新增的 `DCache.v`、`ICache.v`、`axi_master.v`；工程 XML 与文件引用路径检查通过，所有 Lab2 RTL 均已纳入工程文件集。
- 本环境未发现 `vivado` 命令，未实际打开或综合；首次在 Vivado 打开后应先执行 `Reset Runs`，再按 C_TEST/Vivado 清单创建 Lab2 AXI 外设 IP 并综合。

### Lab2：材料探索与文档起草
- **Status:** first-pass complete
- **Started:** 2026-07-22
- Actions taken:
  - 确认 `lab2/` 目录已存在但为空。
  - 直连校园网访问课程站点成功，确认系统代理会导致 TLS 失败。
  - 从课程站点首页导航定位实验二章节：`lab2-A/*` 与 `lab2-B/*`。
  - 初读 `lab2-A/0-overview/` 与 `lab2-B/0-overview/`，确认 A 侧聚焦流水线 CPU，B 侧聚焦 SoC、AXI、I/O 与下板。
  - 读取 `lab2-A/7-step/` 与 `lab2-B/3-step/`，提取两条线的实施顺序。
  - 读取 `lab2-B/1-sysbus/`、外设地址表和本地实验一 RTL/Trace 目录，确认后续文档可直接围绕现有 miniRV 单周期实现展开。
  - 在 `lab2/` 下创建 `README.md`、`实验二指导书通读要点记录.md`、`实验二实施路线.md`。
  - 运行文档轻量检查：3 个文档共 453 行；关键术语 `Lab2-A/Lab2-B/Basic Trace/AXI Trace/axi_master/0xFFFF_3000/debug_wb_pc` 均可检索。

### Lab2：实施设计与执行准备
- **Status:** in progress; waiting for worktree consent before RTL changes.
- Actions taken:
  - 用户确认实验二产物统一放置在 `lab2/`。
  - 新建设计规格 `lab2/实验二设计规格.md` 和实施计划 `lab2/实验二实施计划.md`，覆盖流水线、AXI SoC、Cache、I/O、最终集成及手动验收边界。
  - 读取 Lab2-A/Lab2-B 关键页面并确认现有 Lab1 `cpu_core` 对外取指、访存及 Trace 接口。
  - 确认本地实验三压缩包提供 `ICache.v` 和 `DCache.v` 参考实现。
  - 复查 Git 状态：当前是带用户未提交改动的 `main` 普通检出，`.worktrees` 已被忽略。
  - 复跑 Lab1 静态与算法基线：分别输出 `STATIC CHECK PASSED`、`ALGORITHM CHECK PASSED (16 cases)`。

### Lab2：RTL 实现与 Trace 验证
- **Status:** workspace implementation complete; Vivado/C_TEST/downboard items documented for manual execution.
- Actions taken:
  - 创建三个 Lab2 工程副本及 `create_lab2_workspace.sh`、`sync_pipeline_trace_sources.sh`、`sync_integrated_trace_sources.sh`。
  - 完成五级流水线 `cpu_core`，实现前递、暂停、冲刷、访存/乘除多周期控制和 Trace 提交对齐。
  - 完成单周期 AXI SoC：ICache/DCache、`axi_master`、`cpu_top` AXI 接口及 `RUN_TRACE` 下的 `bram_axi` 连接。
  - 将流水线核、Cache 和 AXI SoC 合并为 `integrated_soc/miniRV_pipeline_axi`。
  - 完整 Basic Trace、单周期 AXI Trace、最终流水线 Cache-off AXI Trace 和 Cache-on AXI Trace 均通过 45 个程序；`start` 的数码管序列到 `0x25000025` 后通过。
  - 新增板级/IP/I-O/C_TEST 手动验收清单，明确未执行 Vivado、下板和性能测试。
