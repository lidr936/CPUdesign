# Lab2 Windows 下板接力与 Linux 排查

更新时间：2026-07-28

## 当前状态

- 本机在隔离的 `cdp-tests` 副本中重新执行最终集成 AXI RTL 的全部 45 个 Trace 程序，结果为 45/45 通过；Linux 可继续执行 RTL/Trace 类验证。
- Vivado 命令行不在 Linux PATH，综合、实现、下载和真实串口验证必须在 Windows Vivado 中执行。
- 同学在 U 盘工程中增加了 `axi_peripheral_subsystem.v`、AXI Crossbar、GPIO、UARTLite 和协议转换 IP，并生成过 `miniRV_SoC.bit`；该工程与本机仓库当前 `lab2/miniRV_pipeline_axi` 并非同一份硬件集成状态。
- 自建 bitstream 尚未得到串口输出。不能把“bitstream 生成成功”视为下板通过。

## Windows 的正确验证顺序

### 1. 先验证开发板 UART

使用课程提供的 EGO1 miniRV I/O 测试 bitstream：

`https://cpu-design.p.cs-lab.top/lab2-B/assets/lab2_IOtest_miniRV_ego1.bit`

1. 在 Hardware Manager 下载该 bitstream。
2. 串口选择开发板对应 COM，配置 `115200`、8N1、无流控。
3. 按复位键。

预期：终端出现等待下载程序的提示。

- 若没有提示：先处理板卡、COM 口、串口工具和 USB/UART 驱动；不要修改 CPU、Cache 或 COE。
- 若有提示：板级 UART 链路正常，继续验证自建 SoC。

### 2. 自建 SoC 的 COE 固化

自建 SoC 不包含课程 I/O test bitstream 的串口下载器，必须把程序固化到 `bram_axi`。

当前 U 盘中的脚本已固定使用：

`F:/lab2/lab2/c_test_rv_stu/0_uart_test/main.coe`

在打开 `F:/lab2/lab2/miniRV_pipeline_axi/miniRV.xpr` 后，于 Vivado Tcl Console 执行：

```tcl
source {F:/lab2/lab2/miniRV_pipeline_axi/scripts/rebuild_with_coe.tcl}
```

必须观察到：

```text
Using COE: F:/lab2/lab2/c_test_rv_stu/0_uart_test/main.coe
Configured bram_axi COE: ...c_test_rv_stu...0_uart_test...main.coe
DONE: F:/lab2/lab2/miniRV_pipeline_axi/miniRV.runs/impl_1/miniRV_SoC.bit
```

若 `Configured bram_axi COE` 显示 `lw.coe`，停止下载；说明 bitstream 仍然不是 C_TEST 程序。

### 3. Cache-off 首次启动

首次上板先在 `src/rtl/defines.vh` 注释：

```verilog
// `define ENABLE_ICACHE
// `define ENABLE_DCACHE
```

然后再次执行 Tcl 脚本、等待新的 `DONE`、下载新 bitstream 并按复位。课程 Trace 路径本身也建议先 Cache-off 再调试 Cache-on。

### 4. 观察结果

`0_uart_test` 启动后应立即输出测试标题和 `Hello World!`；随后停在 `Enter a char:` 等待终端输入一个字符。

- 立即有输出：UART 基本通路工作。
- 先有输出、输入无回显：查 UART RX 或终端发送设置。
- 完全无输出：进入下述分层诊断。

## 完全无输出的分层诊断

1. 官方 I/O test bitstream 也无输出：板级 UART/串口环境问题。
2. 官方 bitstream 正常，但自建 Cache-off bitstream 无输出：CPU 没有从 BRAM 正常执行，优先查复位、时钟、`bram_axi` 初始化和 AXI 读通道。
3. CPU 启动标记 LED 有变化但 UART 无输出：查 Crossbar `0xFFFF3000` 地址段、UARTLite、协议转换器和 `tx` 引脚约束。
4. Cache-off 正常、Cache-on 失败：只调 ICache/DCache/AXI master，不能把该问题归为串口故障。

## Linux 可继续完成的工作

1. 使用 `verilator` 重新运行本机 Basic/AXI Trace，保持已通过回归不退化。
2. 对从 Windows/U 盘回传的手写 RTL 做 diff 和端口/地址静态审查。
3. 检查 `bram_axi.xci` 的 `Coe_File` 和 Crossbar 地址表是否与 `0xFFFF0000` 至 `0xFFFF4000` 对齐。
4. 为 Windows 失败日志准备最小复现和修复；不能在 Linux 声称 Vivado 实现或上板已通过。

本次 Linux 回归命令在隔离目录执行，未改动当前 `cdp-tests`：

```bash
cp -a cdp-tests /tmp/cdp-tests-lab2-axi
lab2/tools/sync_integrated_trace_sources.sh /tmp/cdp-tests-lab2-axi
make -C /tmp/cdp-tests-lab2-axi run TEST=start
```

随后对 `bin/*.bin` 执行 `run_for_python`，45 个程序全部通过；汇总日志为 `/tmp/lab2-axi-trace-summary.log`。

## Windows 需要带回的证据

- Tcl Console 从 `Using COE` 到 `DONE` 的完整输出。
- `bram_axi` IP 配置页显示的 COE 文件。
- 生成 bitstream 的修改时间。
- 官方 I/O test bitstream 复位后的串口截图。
- 自建 Cache-off bitstream 的串口截图或无输出录像。
- `synth_1/runme.log`、`impl_1/runme.log` 末尾的 warning/error。
