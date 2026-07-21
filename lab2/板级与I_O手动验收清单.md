# 板级与 I/O 手动验收清单

以下项目依赖 Vivado 图形界面、课程 IP 或物理 EGO1 开发板，未在当前环境伪造
实现或验证结果。

## 1. 工程与时钟

1. 在 `integrated_soc/miniRV_pipeline_axi` 工程中加入 `src/rtl` 的全部
   `.v/.vh` 文件、课程 Cache 的 `ICache.v` 和 `DCache.v`。
2. 创建 `clk_wiz_0`，端口名与 `miniRV_SoC.v` 一致：`clk_in1`、`clk_out1`、
   `locked`。频率按课程要求配置，流水线 SoC 目标不低于 50 MHz。
3. 建立 `blk_mem_gen_1`，单端口 RAM，深度 64、位宽 151、同步读、Write First。
   ICache 与 DCache 都实例化该模块；一个 IP 定义可被两个实例复用。
4. 在 `defines.vh` 打开 `ENABLE_ICACHE`、`ENABLE_DCACHE` 后重新综合。

## 2. AXI 地址系统

非 `RUN_TRACE` 构建中，`miniRV_SoC.v` 的 AXI 主机信号应接入 Vivado AXI
Interconnect/Crossbar。当前源代码把该处明确保留为手动接点，避免在没有 IP
生成文件的仓库中引用不存在的模块。

至少连接以下从设备及地址段：

| 从设备 | 基地址 | 说明 |
| --- | --- | --- |
| 主存/DDR3 | `0x0000_0000`、`0x2000_0000` | 课程 `bram_axi` 或 DDR3 控制器 |
| Switch GPIO | `0xFFFF_0000` | 只读 |
| LED GPIO | `0xFFFF_1000` | 写 |
| Digit GPIO | `0xFFFF_2000` | 写 |
| AXI Uartlite | `0xFFFF_3000` | RX/TX/状态/控制，115200 bps |
| Timer GPIO | `0xFFFF_4000` | 低 32 位，`0xFFFF_4008` 为高 32 位 |

低速 AXI4-Lite 外设前放置 AXI Protocol Converter。计时器由 64 位计数器和两个
AXI GPIO 输入端口提供；LED、数码管使用输出 GPIO，拨码开关使用输入 GPIO。

## 3. C_TEST 与下板

1. 下载课程提供的 `c_test_rv_stu.tar.gz` 与
   `lab2_IOtest_miniRV_ego1.bit`，先用课程 bitstream 验证串口下载流程。
2. 在 C_TEST 各目录执行 `./compile.sh`，依次运行 UART、格式化 I/O、排序、DDR、
   CoreMark 和 LLAMA2 测试。
3. 使用 115200 bps、关闭流控的串口终端；下载自身 bitstream 后复测。
4. 在 Vivado Implementation 后保存 Timing Summary、Utilization、Power 截图；
   必须无时序违例。
5. 记录 CoreMark 用时和 CPU 频率。若修改时钟，同时修改 CoreMark 的 `MHZ` 和
   UART IP 的输入时钟设置。

## 4. Trace 与硬件配置

`RUN_TRACE` 会直接实例化 `cdp-tests` 提供的 `bram_axi`，不经过 Crossbar 或
外设 IP，专用于自动差分测试。硬件构建不能定义 `RUN_TRACE`，必须使用第 2 节的
AXI 子系统替换该直接连接。
