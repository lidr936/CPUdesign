# cdp-tests 波形操作说明

> 说明：目录名是 `cdp-tests`，不是 `cpd-test`。指导书中有一处写成 `cdp-test`，实际操作按本工程目录 `cdp-tests` 执行。

## 1. 波形文件从哪里来

cdp-tests 的 Trace 测试框架会先用 Verilator 编译 `cdp-tests/mySoC` 里的 CPU/SoC Verilog 代码，再运行某个指令测试用例。运行后会在：

```text
cdp-tests/waveform/
```

下生成对应的 `.vcd` 波形文件。例如：

```text
cdp-tests/waveform/addi.vcd
cdp-tests/waveform/lw.vcd
cdp-tests/waveform/start.vcd
```

本工程里已经有多条指令的波形文件，可以直接打开查看。

## 2. 运行单条指令测试并生成波形

进入测试目录：

```bash
cd /run/media/caige/File/cpu-design/cdp-tests
```

重新编译：

```bash
make
```

运行某一条测试，例如 `addi`：

```bash
make run TEST=addi
```

运行完成后查看：

```bash
ls waveform
```

如果运行的是 `addi`，正常会生成或刷新：

```text
waveform/addi.vcd
```

其他测试把 `TEST=addi` 换成对应名字即可，例如：

```bash
make run TEST=lw
make run TEST=beq
make run TEST=mul
make run TEST=start
```

## 3. 批量测试

如果想一次跑所有测试，先保证 `make` 没有报错，然后执行：

```bash
python3 run_all_tests.py
```

脚本最后会列出哪些测试通过、哪些测试失败。失败的测试再去打开对应的：

```text
waveform/测试名.vcd
asm/测试名.dump
```

结合波形和反汇编定位问题。

## 4. 用 Surfer 打开波形

指导书推荐用 Surfer 查看 VCD。

操作顺序：

1. 打开 Surfer。
2. 把 `cdp-tests/waveform/某条指令.vcd` 拖进 Surfer。
3. 再把 `cdp-tests/sim_simple.surf.ron` 拖进 Surfer。
4. 如果是流水线 CPU，使用 `cdp-tests/sim_pipeline.surf.ron`。
5. 修改 HDL 后重新 `make run TEST=xxx`，在 Surfer 左上角点刷新按钮，就能看到最新波形。

你当前这个单周期工程优先用：

```text
cdp-tests/sim_simple.surf.ron
```

例如查看 `lw`：

```text
先拖入 cdp-tests/waveform/lw.vcd
再拖入 cdp-tests/sim_simple.surf.ron
```

现在我已经额外给本工程添加了一个命令式信号配置：

```text
cdp-tests/sim_simple_core.sucl
```

推荐直接这样启动，波形和关键信号会一起加载：

```bash
cd /run/media/caige/File/cpu-design/cdp-tests
surfer waveform/addi.vcd --command-file sim_simple_core.sucl
```

查看其他测试时，把 `addi.vcd` 换成对应文件即可：

```bash
surfer waveform/lw.vcd --command-file sim_simple_core.sucl
surfer waveform/beq.vcd --command-file sim_simple_core.sucl
surfer waveform/start.vcd --command-file sim_simple_core.sucl
```

## 5. Surfer 基本操作

添加信号：

1. 左侧 `Scopes` 里选模块。
2. 右侧先选中想插入信号的位置。
3. 在 `Variables` 里点击信号，信号会加入右侧波形区。
4. 可以在 `Variables` 的 `Filter` 搜索框输入信号名过滤。

删除信号：

```text
选中右侧波形区里的信号，按 Delete
```

缩放波形：

```text
按住 Ctrl 滚动鼠标滚轮
```

左右移动：

```text
直接滚动鼠标滚轮
```

定位信号变化：

```text
选中信号后，按键盘 Left / Right
```

显示格式：

```text
右键某个信号，可以改成十六进制、十进制、有符号数等显示格式
```

## 6. 出错时怎么看

Trace 报错时会打印两边结果：

```text
左边：golden_model 的正确结果
右边：你的 CPU 输出结果
```

重点看这些信息：

```text
debug_wb_pc
debug_wb_rf_we
debug_wb_rf_wR
debug_wb_rf_wD
debug_mem_pc
debug_mem_we
debug_mem_waddr
debug_mem_wdata
```

如果报错里显示 `debug_wb_pc = 0x000018f8`，就打开：

```text
cdp-tests/asm/start.dump
```

搜索：

```text
000018f8
```

就能找到是哪一条指令执行错了。然后再回到 `waveform/start.vcd`，定位同一个 PC 附近的波形。

## 7. 单周期 CPU 建议重点看哪些信号

对于当前 `cdp-tests/mySoC` 里的单周期 CPU，建议先看这些信号：

| 类型 | 信号 | 作用 |
|---|---|---|
| 取指 | `pc`、`npc`、`ifetch_inst`、`inst` | 看当前执行到哪条指令，下一条 PC 是否正确 |
| 控制 | `npc_op`、`rf_we`、`rf_wsel`、`sext_op`、`alu_op` | 看控制器译码是否正确 |
| 寄存器 | `rf_rD1`、`rf_rD2`、`rf_wR`、`rf_wD` | 看读写寄存器编号和值是否正确 |
| 立即数 | `ext` | 看 I/S/B/U/J 立即数是否扩展正确 |
| ALU | `alu_a`、`alu_b`、`alu_c`、`br` | 看计算结果和分支判断是否正确 |
| 访存 | `daccess_addr`、`daccess_ren`、`daccess_wen`、`daccess_wdata`、`daccess_rdata` | 看 load/store 地址、写掩码、读写数据 |
| Trace | `debug_wb_*`、`debug_mem_*` | 看测试框架真正拿去比对的信号 |

调试顺序建议：

```text
先看 pc/inst
-> 看 Controller 译码控制信号
-> 看 RF 读出的操作数
-> 看 SEXT 生成的立即数
-> 看 ALU 结果或 br 分支结果
-> load/store 再看 MREQ/Data_RAM/MEXT
-> 最后看 debug_wb_* 或 debug_mem_* 是否和预期一致
```

## 8. 常见问题

### 8.1 运行后没有波形

先检查命令是否在 `cdp-tests` 目录执行：

```bash
pwd
```

应当显示：

```text
/run/media/caige/File/cpu-design/cdp-tests
```

再检查是否运行了：

```bash
make run TEST=测试名
```

只执行 `make` 只会编译，不一定生成新的测试波形。

### 8.2 make 报 Verilator 错

优先检查：

1. `cdp-tests/mySoC` 下是否只放 HDL 源码，没有拷贝 Vivado 的 `ip` 文件夹。
2. 顶层模块是否仍叫 `miniRV_SoC`。
3. `miniRV_SoC -> cpu_top -> cpu_core` 的层次和接口名是否被改动。
4. `RUN_TRACE` 相关代码是否被删改。
5. 带 `/* verilator public */` 的 Trace 信号注释是否被删改。

### 8.3 波形太乱

先加载 `sim_simple.surf.ron` 配置文件，不要一开始手动加很多信号。定位到出错指令后，再根据需要补充模块内部信号。

### 8.4 测试通过但下板不对

cdp-tests 的 Trace 主要检查主存访问和 CPU 执行行为，不检查所有外设访问。若仿真通过但下板异常，还要检查：

```text
复位极性
时钟
外设地址译码
未初始化寄存器
X/Z 不定态
Vivado 综合/实现 warning
```

下板抓波形属于 Vivado ILA 在线调试流程，和这里的 VCD/Surfer 仿真波形不是同一个操作。
