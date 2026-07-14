# Task Plan: 实验一单周期 CPU

## Goal
依据实验一指导书，完成需求梳理、实现、Basic Trace 验证与交付材料整理。

## Current Phase
Phase 4：调试与验证（本机静态/算法检查已通过；Vivado/Basic Trace 受工具链缺失阻塞）

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
- [ ] 使用 Vivado/Basic Trace 调试目标指令
- [ ] 完成完整 CPU 的 Vivado/Trace 测试与问题修复
- **Status:** blocked_by_missing_toolchain

### Phase 5：交付整理
- [x] 核对源码、工程和实验材料
- [x] 准备单周期源码交付包脚本
- [x] 总结本机验证结果与 Vivado/Trace 待办事项
- **Status:** complete_except_vivado_trace_evidence

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
| Vivado/Verilog 命令行工具缺失 | 多次检查 | 新增 `tools/check_vivado_env.ps1` 和 `tools/vivado_lab1_check.tcl`，将 Vivado/Basic Trace 列为用户侧验证门 |
