# Lab2 Cache-off AXI 集成：Linux 交接文档

更新时间：2026-07-30

## 交接结论

Windows 侧已完成 Cache-off 所需 Vivado IP 创建与地址配置；当前 RTL 已接入 AXI Crossbar、BRAM 和五个外设。Linux 已完成静态审查，并在隔离 Verilator Trace 中回归 45/45 程序通过。当前仍未经过 Vivado Elaborate、综合、行为仿真或真实下板验收，不能表述为“硬件已通过”。

## Windows 已完成内容

硬件工程入口：

```text
lab2/miniRV_pipeline_axi/miniRV.xpr
```

已生成的 IP：

```text
bram_axi
clk_wiz_0
axi_crossbar_0
Switch
LED
Dig
Timer
axi_uartlite_0
axi_protocol_converter_0 ~ axi_protocol_converter_4
```

已核对的关键参数：

| IP | 配置 |
| --- | --- |
| `clk_wiz_0` | 输入 100 MHz，输出 50 MHz，端口 `clk_in1/clk_out1/locked` |
| `bram_axi` | AXI4、Simple Dual Port RAM、32-bit、深度 38400、`lw.coe` 初始化 |
| `axi_crossbar_0` | 1 个 Slave、6 个 Master |
| Switch | 32-bit、All Inputs |
| LED | 16-bit、All Outputs |
| Dig | 32-bit、All Outputs |
| Timer | Dual Channel、两个通道均 32-bit All Inputs |
| UARTLite | 50 MHz、115200、8-bit、No Parity |
| Protocol Converter | AXI4 -> AXI4-Lite、32-bit 地址/数据 |

Crossbar 地址表：

| Master | 外设 | 基址 | Address Width |
| --- | --- | --- | --- |
| M00 | `bram_axi` | `0x0000_0000` | 18 |
| M01 | Switch | `0xFFFF_0000` | 12 |
| M02 | LED | `0xFFFF_1000` | 12 |
| M03 | Dig | `0xFFFF_2000` | 12 |
| M04 | UART | `0xFFFF_3000` | 12 |
| M05 | Timer | `0xFFFF_4000` | 12 |

## 当前 RTL 改动（尚待 Vivado 验证）

新增：

```text
lab2/miniRV_pipeline_axi/src/rtl/axi4lite_peripheral_wrap.v
lab2/miniRV_pipeline_axi/src/rtl/axi_peripheral_subsystem.v
tools/check_lab2_axi_peripheral.py
```

修改：

```text
lab2/miniRV_pipeline_axi/src/rtl/miniRV_SoC.v
```

目标连接：

```text
cpu_top AXI Master
  -> axi_crossbar_0.S00
       M00 -> bram_axi
       M01 -> Switch
       M02 -> LED
       M03 -> Dig
       M04 -> UARTLite
       M05 -> Timer
```

其中 `axi4lite_peripheral_wrap.v` 通过 `axi_protocol_converter_0` 到 `axi_protocol_converter_4` 分别把 Switch、LED、Dig、UART、Timer 支路从 AXI4 转为 AXI4-Lite；`Timer` 使用 `sys_clk` 的 64-bit 自增计数器，低/高 32 位分别接 GPIO 通道 1/2；数码管 GPIO 采用：

```text
[7:0]   -> dig_en
[15:8]  -> dig_seg
[23:16] -> dig_seg1
[31:24] -> 保留
```

`RUN_TRACE` 分支必须仍保持原来的 `bram_axi` 直连，不能经过 Crossbar 或板级 IP。

本次 Linux 修复：

- `sys_clk` 改为直接使用 `pll_clk1`，不再以 `pll_lock & pll_clk1` 门控时钟。
- `sys_rst` 改为在 50 MHz `sys_clk` 域内、PLL lock 后同步释放，避免 100 MHz 到 50 MHz 的异步复位释放。
- `RUN_TRACE` 分支恢复 `led/dig/tx` 默认驱动，保持原 Trace 顶层行为。
- 两个新增 RTL 已正式登记到 `miniRV.xpr` 的 Design Sources；顶层不再 ``include`` 其它 `.v` 文件，避免 Linux Trace 或 Vivado 出现重复模块定义。
- `axi_protocol_converter_1` 到 `_4` 已从 `AutoDisabled` 状态启用；五个 converter 与五条外设支路一一对应。打开工程后若 Vivado 显示某个 converter 未生成，只对该 converter 使用 **Generate Output Products**，不要重跑 Crossbar 的独立综合。
- `Dig` AXI GPIO 的 32-bit 原始数值不再直接接到 EGO1 的位选/段选引脚。新增 `seven_segment_hex.v`，以 EGO1 高有效的两组四位共阴极数码管接口动态显示 8 个十六进制数字。EGO1 的 `dig_en[7:4]` 对应 `dig_seg`，`dig_en[3:0]` 对应 `dig_seg1`；该映射已由独立仿真覆盖。例如 C_TEST 向 `0xFFFF2000` 写入 `123` 时显示 `0000007B`。

## 已完成的本地检查

以下命令已经通过 Verilog 语法分析：

```powershell
D:\Xilinx\Vivado\2023.2\bin\xvlog.bat -i .\lab2\miniRV_pipeline_axi\src\rtl `
  .\lab2\miniRV_pipeline_axi\src\rtl\axi4lite_peripheral_wrap.v `
  .\lab2\miniRV_pipeline_axi\src\rtl\axi_peripheral_subsystem.v `
  .\lab2\miniRV_pipeline_axi\src\rtl\miniRV_SoC.v
```

说明：该命令只确认 Verilog 语法；Switch/LED/Dig/Timer 的生成模型是 VHDL，完整跨语言端口和 IP 黑盒检查必须由 Vivado Elaborate Design 完成。

Linux 可运行静态检查：

```bash
cd /path/to/cpu-design
python3 tools/check_lab2_axi_peripheral.py
```

预期：

```text
PASS: Cache-off AXI peripheral static contract
```

Linux 已完成的隔离 Trace 回归：

```bash
cp -a cdp-tests /tmp/cdp-tests-cache-off
install -m 644 lab2/miniRV_pipeline_axi/src/rtl/*.v \
  lab2/miniRV_pipeline_axi/src/rtl/*.vh /tmp/cdp-tests-cache-off/mySoC/
make -C /tmp/cdp-tests-cache-off run TEST=start
```

随后对 `bin/*.bin` 全量执行 `run_for_python`，结果：`pass=45 fail=0`。该结果覆盖 `RUN_TRACE` 下 CPU、AXI master 与 Trace 外设模型；不覆盖 Vivado IP 实例和板级 UART。

数码管模块还有一条独立仿真：

```bash
verilator --binary --timing --Mdir /tmp/seven-segment-obj \
  --top-module seven_segment_hex_tb \
  lab2/miniRV_pipeline_axi/tests/seven_segment_hex_tb.v \
  lab2/miniRV_pipeline_axi/src/rtl/seven_segment_hex.v
/tmp/seven-segment-obj/Vseven_segment_hex_tb
```

预期：`PASS: seven_segment_hex display protocol`。

## Windows Vivado 已知问题

创建 `axi_crossbar_0` 后，Vivado 2023.2 在 Generate Output Products/独立 IP 综合阶段发生过原生崩溃：

```text
ERROR: [Common 17-180] Spawn failed: No error
EXCEPTION_ACCESS_VIOLATION in librdi_filemgmt.dll
```

Crossbar 的 `.xci`、`synth/`、`sim/` 等输出产物已经落盘，地址配置正常。不要重新生成 Crossbar 输出产物，不要启动 `axi_crossbar_0_synth_1` 独立综合；后续使用顶层 **Elaborate Design**、**Run Synthesis** 和 **Run Implementation** 验收即可。

## Linux 侧必须做的事

1. 运行 `python3 tools/check_lab2_axi_peripheral.py`。
2. 对新增 RTL 与 Trace 版本的 `miniRV_SoC.v` 做 diff，确认：
   - `RUN_TRACE` 直连分支没有被破坏；
   - 非 Trace 分支不再把 AXI ready/valid/rdata 固定为零；
   - `0xFFFF_0000` 到 `0xFFFF_4000` 与 `defines.vh` 一致；
   - AW、W、B、AR、R 五个通道均连接。
3. 保持 Cache 宏关闭，回归 Trace：

```bash
cd /path/to/cpu-design
lab2/tools/sync_integrated_trace_sources.sh /path/to/cdp-tests
make -C /path/to/cdp-tests run TEST=start
```

4. 若 Trace 回归失败，优先恢复/检查 `RUN_TRACE` 分支，不在 Linux 端把 Vivado IP 路径或 `.xci` 作为 Trace 依赖。

## Windows 后续验收顺序

1. 打开工程后确认 `axi4lite_peripheral_wrap.v` 与 `axi_peripheral_subsystem.v` 已在 Design Sources；执行 **Update Compile Order**，不要再次以 ``include`` 方式加入它们。
2. 保持 `ENABLE_ICACHE` 与 `ENABLE_DCACHE` 注释。
3. Run Elaborate Design：确认无黑盒、无多驱动、`miniRV_SoC -> axi_peripheral_subsystem -> axi_crossbar_0` 可展开。
4. 用 `lw.coe` 跑行为仿真，观察 AR/R 握手；换 `sw.coe` 后观察 AW/W/B 握手。
5. Run Synthesis / Implementation，确认 50 MHz 下无负 slack。
6. 最后才将 `0_uart_test/main.coe` 写入 `bram_axi`，生成 bitstream 并在 COM9（115200、8N1、无流控）验证 UART。

## 不可宣称的结论

当前没有以下证据，因此不能宣称：

- Vivado Elaborate、综合、实现已通过；
- Cache-off 行为仿真已通过；
- UART/Timer/数码管/LED/拨码开关已下板通过；
- Cache-on、DDR、CoreMark 或 LLAMA2 已完成。
