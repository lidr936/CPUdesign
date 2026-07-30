# Lab2 Cache-off AXI 外设集成设计

## 目标

将 `lab2/miniRV_pipeline_axi` 的非 `RUN_TRACE` 分支从 AXI 零响应占位实现替换为可综合的 Cache-off 硬件路径：流水线 CPU 经 `axi_crossbar_0` 访问 AXI BRAM 与五个 I/O 外设。保留 `RUN_TRACE` 的 `bram_axi` 直连行为，避免改变现有 Trace 回归路径。

## 范围与非目标

- 范围：主存、Switch、LED、数码管、UART、Timer 的 AXI 接线和 wrapper；顶层板级 I/O 连接；Cache-off 静态检查。
- 不在范围：启用 ICache/DCache、DDR/MIG、CoreMark/LLAMA2、bitstream 下载、板级串口验收。
- 不改动：`lab1/`、`cdp-tests/`、现有 IP 配置和 `RUN_TRACE` 分支。

## 架构

```text
cpu_top AXI master
  -> axi_crossbar_0.S00_AXI
       M00 -> bram_axi
       M01 -> switch_wrap -> axi_protocol_converter_0 -> Switch AXI GPIO
       M02 -> led_wrap    -> axi_protocol_converter_1 -> LED AXI GPIO
       M03 -> digled_wrap -> axi_protocol_converter_2 -> Dig AXI GPIO
       M04 -> uart_wrap   -> axi_protocol_converter_3 -> axi_uartlite_0
       M05 -> timer_wrap  -> axi_protocol_converter_4 -> Timer AXI GPIO
```

所有组件使用 `sys_clk` 与低有效复位 `!sys_rst`。Crossbar 是唯一连接 CPU AXI 主机的互连；各 wrapper 对外提供完整 AXI4 Slave 端口，对内使用相应 Protocol Converter 的 AXI4-Lite Master 端口。

## 地址与外设规则

| Crossbar master | 设备 | 基址 | 行为 |
| --- | --- | --- | --- |
| M00 | `bram_axi` | `0x0000_0000` | 程序与数据主存 |
| M01 | Switch | `0xFFFF_0000` | 只读 32-bit GPIO |
| M02 | LED | `0xFFFF_1000` | 写 16-bit GPIO |
| M03 | Dig | `0xFFFF_2000` | 写 32-bit GPIO |
| M04 | UART | `0xFFFF_3000` | UARTLite 标准寄存器窗口 |
| M05 | Timer | `0xFFFF_4000` | `+0x0` 低 32 位、`+0x8` 高 32 位 |

数码管 GPIO 的 32-bit 输出采用以下固定打包：`gpio_io_o[7:0] -> dig_en`、`[15:8] -> dig_seg`、`[23:16] -> dig_seg1`、`[31:24]` 保留为零。Timer 以 `sys_clk` 每拍递增的 64-bit 计数器驱动 Timer GPIO 的两个输入通道。

## 顶层改动

`miniRV_SoC.v` 的 ``ifndef RUN_TRACE`` 分支将：

1. 删除 AXI ready/valid/rdata 固定零赋值；
2. 实例化 `axi_crossbar_0`，将 CPU AXI 接到 S00，并将 M00-M05 接往 BRAM 和 wrapper；
3. 实例化 `bram_axi` 与五个 wrapper；
4. 将 `sw/led/dig_en/dig_seg/dig_seg1/rx/tx` 连接至 wrapper。

`RUN_TRACE` 分支继续直连 Trace 的行为模型，不经过 Crossbar 或外设 IP。

## 验证策略

1. 在实现前新增静态检查：验证六个基址、`RUN_TRACE` 直连保留、非 Trace 分支不再含 AXI 零响应赋值，以及各 IP/wrapper 实例存在。
2. 先运行该检查，确认其因 wrapper/互连缺失而失败。
3. 最小实现后重跑静态检查；再用 Vivado Elaborate Design 与行为仿真验证编译/展开。
4. 硬件验收保持手动：Cache-off 使用 `0_uart_test/main.coe` 重新生成 bitstream，在 COM9 115200 观察 UART 输出。

## 风险与处理

- Vivado 2023.2 在 IP 生成中曾崩溃：不重新生成现有 Crossbar，不启动独立 IP 综合；RTL 更改后仅执行顶层 Elaborate/综合。
- IP 端口名由已生成 `.veo` 模板为准；实现前从模板逐项复制端口，避免靠记忆简化 AXI 通道。
- 若现有 U 盘 `axi_peripheral_subsystem.v` 与本设计冲突，以本文件中的地址映射和单主机 Crossbar 结构为准，并在接入前先做 diff。
