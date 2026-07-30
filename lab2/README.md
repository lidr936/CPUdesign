# 实验二工作区

本目录包含实验二的流水线 CPU、AXI SoC 和最终集成 RTL，以及课程资料、Trace 同步脚本和验收记录。

## 当前资料来源

- 课程站点首页：<https://cpu-design.p.cs-lab.top>
- 流水线 CPU 指导书：<https://cpu-design.p.cs-lab.top/lab2-A/0-overview/>
- SoC/总线/I/O 指导书：<https://cpu-design.p.cs-lab.top/lab2-B/0-overview/>
- 本地实验一基线工程：`lab1/miniRV_basic_ego1/miniRV_basic`
- 本地 Basic Trace 框架：`cdp-tests`

访问课程站点时建议走校园网直连；当前系统代理会导致该域名 TLS 握手失败。

## 文档

- `实验二指导书通读要点记录.md`：按指导书整理需求、约束、接口和附件。
- `实验二实施路线.md`：基于当前 miniRV 单周期实现的落地顺序、模块拆分和验证门。
- `实验二设计规格.md`：本次实现的接口、仲裁和验证边界。
- `验证记录.md`：Basic Trace、AXI Trace 与 Cache-on 回归结果。
- `代码审查记录.md`：按在线指导书进行的 RTL 审查、已修复问题与硬件待办。

## 工程

- `pipeline_cpu/miniRV_pipeline`：Lab2-A 五级流水线 CPU。
- `axi_soc/miniRV_axi`：Lab2-B 单周期 CPU 的 AXI SoC。
- `integrated_soc/miniRV_pipeline_axi`：流水线 CPU 接入 Cache/AXI 的最终版本。
- `miniRV_pipeline_axi/miniRV.xpr`：可直接打开的 Lab2 Vivado 工程；其 `src/` 与
  最终集成版同步。首次打开必须执行 **Reset Runs**，复制来的 Lab1 缓存和报告不代表
  Lab2 已综合通过。
- `assets/cache_reference`：课程提供的 ICache/DCache 参考源码。

## Trace

默认使用 Cache-off 配置，和课程建议的首次 AXI Trace 流程一致：

```bash
./lab2/tools/sync_pipeline_trace_sources.sh
cd cdp-tests
PATH=/usr/bin:$PATH make run TEST=addi

cd ..
./lab2/tools/sync_integrated_trace_sources.sh
cd cdp-tests
PATH=/usr/bin:$PATH make run TEST=start
```

在 `integrated_soc/miniRV_pipeline_axi/src/rtl/defines.vh` 中启用
`ENABLE_ICACHE` 和 `ENABLE_DCACHE` 后，可以使用 Trace 框架的
`vsrc/ram.v` 行为模型回归 Cache-on 配置。Vivado 工程则必须按手动清单创建
同名的 `blk_mem_gen_1` IP。
