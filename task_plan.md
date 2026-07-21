# Task Plan: 实验一单周期 CPU

## Goal
依据实验一指导书，完成需求梳理、实现、Basic Trace 验证与交付材料整理。

## Current Phase
Phase 7：实验二实现与验证（所有新材料位于 `lab2/`）

## Phases

### Phase 1：需求与材料确认
- [x] 确认指导书仓库及实验步骤位置
- [x] 确认课程指定的 A、B 组指令、模板工程与提交要求
- [x] 记录现有源码、约束与分工
- **Status:** complete

### Phase 2：数据通路与控制设计
- [x] 完成 A/B 组对应的数据通路与控制信号落地方案
- [x] 确认完整数据通路、模块接口与实现顺序
- [x] 输出中文落地方案并按用户确认进入 HDL 修改
- **Status:** complete

### Phase 3：Verilog 实现
- [x] 在模板工程中实现各子模块
- [x] 整合单周期 CPU
- **Status:** complete

### Phase 4：调试与验证
- [x] 完成本机静态检查
- [x] 完成本机乘除算法边界检查
- [x] 完成用户侧 Vivado 行为仿真
- [x] 使用 Basic Trace 调试目标指令
- [x] 完成完整 CPU 的 Vivado/Trace 测试与问题修复（含新版 `cdp-tests` 下 `start` 综合测试）
- **Status:** complete

### Phase 5：交付整理
- [x] 核对源码、工程和实验材料
- [x] 准备单周期源码交付包脚本
- [x] 总结本机验证结果与 Vivado/Trace 待办事项
- [ ] 补齐综合/实现/功耗/时序截图
- [ ] 完成 PDF 实验报告
- [ ] 整理最终提交 zip
- **Status:** in_progress

### Phase 6：实验二材料探索与文档起草
- [x] 确认 `lab2/` 目录状态
- [x] 确认课程站点实验二入口
- [x] 提取 `lab2-A` 流水线 CPU 关键章节与实验步骤
- [x] 提取 `lab2-B` SoC/总线/I/O 关键章节与实验步骤
- [x] 在 `lab2/` 下输出实验二需求与路线文档
- [x] 同步更新发现记录和进度记录
- **Status:** complete

### Phase 7：实验二实现与验证
- [x] 明确全量目标、可自动化边界和实施顺序
- [x] 将实验二规格和实施计划固定在 `lab2/`
- [x] 建立三个实验二工程副本和 RTL/Trace 同步脚本
- [x] 完成 Lab2-A 五级流水线 CPU，并通过完整 Basic Trace
- [x] 完成 Lab2-B AXI SoC、Cache 路径，并通过完整 AXI Trace
- [x] 完成流水线 SoC 集成，并在 Cache-off/Cache-on 两种 AXI Trace 配置下回归
- [x] 记录 Vivado IP、I/O、C_TEST 和下板的手动验收边界
- **Status:** complete for workspace-automatable work; Vivado/downboard work remains manual

### Phase 8：C_TEST TODO 实现与编译
- [x] 确认课程原包来源、目标目录和不修改范围
- [ ] 获取 `c_test_rv_stu` 原包并定位全部 TODO
- [ ] 补齐 UART、格式化 I/O、排序和 LLAMA2 TODO
- [ ] 编译全部 C_TEST 目录并核验产物
- [ ] 提交并推送变更
- **Status:** in_progress

### Phase 9：Lab2 可直接打开的 Vivado 工程
- [x] 复制 Lab1 `miniRV_basic` 完整 Vivado 工程骨架
- [x] 以 Lab2 最终集成版 `src/` 覆盖工程源码、COE、仿真和约束
- [x] 恢复 `clk_wiz_0` 等 Lab1 IP 并登记 Cache/AXI 新增 RTL
- [x] 校验 `.xpr` 引用路径和源文件同步
- [ ] 在 Vivado 打开工程并 Reset Runs 后做综合
- **Status:** complete for filesystem preparation; Vivado verification remains manual

## Key Questions
1. A/B 组所有指令是否都以现有 miniRV EGO1 工程为唯一实现目标？（当前按“是”规划。）
2. 是否需要在提交 Excel/数据通路图之外，保留完整可综合的 HDL 工程？（当前按“需要”规划。）

## Decisions Made
| Decision | Rationale |
|----------|-----------|
| 先以指导书的 7 步流程作为主线 | 与课程要求保持一致，避免跳过设计和验证环节 |
| 计划文件放在项目根目录 | 便于跨会话持续记录 |
| 使用现有 miniRV EGO1 工程做增量实现 | 材料已解压且控制器、CPU 顶层和存储器接口均已存在 |
| 用户确认方案前不改动 HDL | 用户明确要求先审阅中文落地文档 |
| 用户要求“工作到落地方案目标完成”后进入实现 | 方案已审阅并收到继续落地指令 |
| 不声称 Vivado/Basic Trace 通过 | 当前环境缺少 `vivado/xvlog/iverilog/verilator`，只能提供用户侧运行脚本和检查清单 |

## Errors Encountered
| Error | Attempt | Resolution |
|-------|---------|------------|
| 默认恢复脚本路径不存在 | 1 | 改用实际安装目录 `C:\\Users\\CCCaiBoYu\\.codex\\skills\\skills\\planning-with-files` |
| `git` 记录不可用 | 1 | `F:\\cpu-design` 不是 Git 仓库；改为直接基于现有文件结构规划 |
| Windows 沙箱读文件/列目录报 1312 | 1 | 对必要只读操作使用已授权的 escalated 方式重跑 |
| Codex 环境 Vivado/Verilog 命令行工具缺失 | 多次检查 | 新增 `tools/check_vivado_env.ps1` 和 `tools/vivado_lab1_check.tcl`；用户侧 Vivado 已完成行为仿真，Basic Trace 仍待用户环境继续执行 |
| 课程 C_TEST 原包 HTTPS 下载 TLS 失败 | 2 | 已尝试直连和系统代理；改为检索本机已有材料，再采用不同下载方式 |
