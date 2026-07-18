# miniRV 数据通路 HTML 图设计

## 目标

新增一个可直接在浏览器打开的 `datapath.html`，用 SVG 绘制当前 `lab1/miniRV_basic_ego1/miniRV_basic/src/rtl` 源码对应的 miniRV 单周期 CPU 数据通路图。图中组件和连线支持鼠标悬浮，悬浮时展示该组件或信号在源码中的作用、端口名和实现思路。

## 范围

- 只新增静态 HTML 文件，不修改 RTL、Vivado 工程、Trace 脚本或现有实验文档。
- 图中覆盖 `cpu_top.v` 与 `cpu_core.v` 中的主数据流：IF、ID、EX、MEM、WB。
- 说明内容以已有中文文档和 Verilog 源码为准，重点引用 `PC`、`NPC`、`Controller`、`RF`、`SEXT`、`ALU`、`MREQ`、`MEXT`、`Inst_ROM`、`Data_RAM`。
- 交互方式为浏览器原生 HTML/CSS/JavaScript，不引入第三方依赖。

## 视觉与交互

- 页面首屏就是可读的数据通路图，不做落地页。
- SVG 中使用接近课程参考数据通路图的黑白原理图风格：模块矩形、虚线 ROM/RAM、明确的 MUX 符号和水平/垂直折线信号。
- 组件和连线分为数据路径、控制路径、访存握手、多周期状态四类线型，默认保持黑白，悬浮时再高亮。
- 鼠标悬浮时，高亮当前元素，并在右侧详情面板显示中文解释。
- 默认详情面板显示总体执行流程，方便打开页面后立即阅读。

## 源码讲解

页面下方提供源码实现思路，按以下结构解释：

1. `cpu_top.v` 如何连接 `cpu_core`、`Inst_ROM`、`Data_RAM`。
2. IF 阶段如何由 `PC`、`NPC`、`ifetch_req/ifetch_valid` 完成取指。
3. ID 阶段如何由 `Controller` 译码并驱动 `RF`、`SEXT`。
4. EX 阶段如何选择 `alu_a/alu_b`，由 `ALU` 产生结果和分支条件。
5. MEM 阶段如何由 `MREQ` 生成字节使能和对齐写数据，由 `MEXT` 扩展读回数据。
6. WB 阶段如何由 `rf_wsel` 和 `ld_st_flag/mul_div_flag` 决定写回时机和写回数据。
7. 访存和乘除法为什么是特殊多周期路径，以及 `inst_finished` 如何控制下一次 PC 更新。

## 验证

- 用文本检查确认 HTML 中包含每个关键模块、关键源码文件名和主要信号名。
- 用浏览器或静态方式确认文件无外部依赖，直接打开即可使用。
