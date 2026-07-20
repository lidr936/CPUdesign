# 熟悉代码及模板工程

&emsp;&emsp;本课程提供了已实现8条指令的单周期CPU demo工程，并且这8条指令的数据通路和控制信号均已包含在数据通路表的模板当中。

!!! info "demo工程已实现的8条参考指令"
    &emsp;&emsp;miniRV示例工程已实现的指令有：`addi`、`ori`、`slli`、`lui`、`lw`、`beq`、`bne`、`jal`。

    &emsp;&emsp;miniLA示例工程已实现的指令有：`addi.w`、`ori`、`slli.w`、`lu12i.w`、`ld.w`、`beq`、`bne`、`b`。

&emsp;&emsp;在开始设计你的CPU之前，<u>请使用demo工程运行功能仿真，结合仿真波形，对照实验原理、数据通路表及示例代码，分析CPU架构及工作原理，理解指令在CPU中的执行过程，体会不同指令执行时数据通路的变化</u>。

&emsp;&emsp;demo工程同时可作为模板工程，后续可在此基础上进行开发。



## 1. 下载demo工程并运行仿真

&emsp;&emsp;点击实验指导书首页的课程材料下载链接，根据需要选择下载对应的demo工程。

!!! info "有4个demo工程，我要下载哪个？"
    <center><img src = "../assets/1-1.png" width = 350></center>
    <center>图1-1 根据实际情况，选择其中一个demo工程</center>

    &emsp;&emsp;首先，选择指令集是miniRV或miniLA，然后再根据上课的实验室进行选取 —— 在T2210、T2507上课的同学，请选择文件名带有“`ego1`”后缀的工程；而在T2506、T2612上课的同学，则选择文件名带有“`minisys`”后缀的工程。

&emsp;&emsp;在Vivado界面左侧点击运行功能仿真，如图1-2所示。等待一段时间后，出现仿真波形窗口。

<center><img src = "../assets/1-2.png" width = 450></center>
<center>图1-2 运行功能仿真</center>

&emsp;&emsp;点击Run All按钮，如图1-3所示，Testbench将通过测试并停止。

<center><img src = "../assets/1-3.png" width = 320></center>
<center>图1-3 继续仿真直至结束或报错停止</center>

&emsp;&emsp;此时的仿真波形是CPU运行<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/lw.dump" target=_blank>lw.dump</a>测试程序（miniLA则是<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniLA/asm/ld.w.dump" target=_blank>ld.w.dump</a>）所产生的。

&emsp;&emsp;仿真波形窗口默认包含了复位、时钟、外设信号，以及CPU的取指信号和数据访存信号，各信号的解释和说明如图1-4所示。

<center><img src = "../assets/1-4.png" width = 320></center>
<center>图1-4 波形配置文件`soc_simple_tb.wcfg`的信号说明</center>

!!! info "外设信号的波形为什么是高阻 <font color="blue">**Z**</font>？"
    &emsp;&emsp;demo工程尚未实现外设的I/O接口电路，无法读写外设数据，相关信号也尚未连接，因此仿真波形上部分外设信号呈现高阻状态，这是正常的。



## 2. CPU模块的接口信号

&emsp;&emsp;由图1-4可知，CPU模块对外有两组接口信号，分别用于取指令和读写主存的数据，这两组接口信号的定义分别如表1-1、表1-2所示。

<center>表1-1 CPU对外的取指接口信号</center>
<center>
<table>
  <tr>
    <th align="center">信号</th>
    <th align="center">位宽</th>
    <th align="center">属性</th>
    <th align="center">功能描述</th>
  </tr>
  <tr>
    <td align="center"><code>ifetch_req</code></td>
    <td align="center">1</td>
    <td align="center">输出</td>
    <td>取指请求信号：高电平表示CPU需要取指</td>
  </tr>
  <tr>
    <td align="center"><code>ifetch_addr</code></td>
    <td align="center">32</td>
    <td align="center">输出</td>
    <td>取指的地址（字节地址）</td>
  </tr>
  <tr>
    <td align="center" style="text-align: center; vertical-align: middle;"><code>ifetch_valid</code></td>
    <td align="center" style="text-align: center; vertical-align: middle;">1</td>
    <td align="center" style="text-align: center; vertical-align: middle;">输入</td>
    <td>指令存储器返回的指令的有效信号<br><b>有效一个时钟表示返回一条指令</b></td>
  </tr>
  <tr>
    <td align="center"><code>ifetch_inst</code></td>
    <td align="center">32</td>
    <td align="center">输入</td>
    <td>指令存储器返回的指令机器码</td>
  </tr>
</table>
</center>

!!! info "取指时序解读"
    &emsp;&emsp;此处以miniRV的demo工程为例，介绍CPU的取指时序。在仿真波形上任意选取一段波形，如图1-5所示。

    <center><img src = "../assets/1-5.png" width = 480></center>
    <center>图1-5 CPU的取指波形示例</center>
    
    - 【*1320ns*】CPU需要取指时拉高`ifetch_req`信号，同时给出指令地址`ifetch_addr`。`inst_req`信号 <mark>**仅有效一个时钟周期**</mark>。  
    - 【*1340ns*】指令存储器接收指令地址，并在读取操作完成后，拉高`ifetch_valid`信号，告知CPU指令已经返回，同时把指令机器码通过`ifetch_inst`信号返回给CPU。

    &emsp;&emsp;由<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/lw.dump#L11" target=_blank>lw.dump第11行</a>可知，地址为`0x4`的指令机器码是`0x000020b7`（`lui x1, 0x2`），与波形相符。

<center>表1-2 CPU对外的数据访存接口信号</center>
<center>
<table>
  <col width=auto>
  <col width=120>
  <col width=auto>
  <col width=auto>
  <col width=auto>
  <tr>
    <th align="center">信号</th>
    <th align="center">位宽</th>
    <th align="center">属性</th>
    <th align="center">功能描述</th>
  </tr>
  <tr>
    <td align="center"><code>daccess_ren</code></td>
    <td align="center">4</td>
    <td align="center">输出</td>
    <td>读使能信号（有效：<code>4'hF</code>，无效：<code>4'h0</code>）</td>
  </tr>
  <tr>
    <td align="center"><code>daccess_addr</code></td>
    <td align="center">32</td>
    <td align="center">输出</td>
    <td>读/写地址</td>
  </tr>
  <tr>
    <td align="center" style="text-align: center; vertical-align: middle;"><code>daccess_rvalid</code></td>
    <td align="center" style="text-align: center; vertical-align: middle;">1</td>
    <td align="center" style="text-align: center; vertical-align: middle;">输入</td>
    <td>数据存储器返回的读数据有效信号<br><b>有效一个时钟表示返回一个读数据</b></td>
  </tr>
  <tr>
    <td align="center"><code>daccess_rdata</code></td>
    <td align="center">32</td>
    <td align="center">输入</td>
    <td>数据存储器返回的读数据</td>
  </tr>
  <tr>
    <td align="center" style="text-align: center; vertical-align: middle;"><code>daccess_wen</code></td>
    <td align="center" style="text-align: center; vertical-align: middle;">4</td>
    <td align="center" style="text-align: center; vertical-align: middle;">输出</td>
    <td>写使能信号，<b>支持写字、半字、字节</b><br>（有效：非零值，无效：<code>4'h0</code>）</td>
  </tr>
  <tr>
    <td align="center"><code>daccess_wdata</code></td>
    <td align="center">32</td>
    <td align="center">输出</td>
    <td>写数据</td>
  </tr>
  <tr>
    <td align="center" style="text-align: center; vertical-align: middle;"><code>daccess_wresp</code></td>
    <td align="center" style="text-align: center; vertical-align: middle;">1</td>
    <td align="center" style="text-align: center; vertical-align: middle;">输入</td>
    <td>数据存储器返回的写响应信号<br>有效则表示写操作已完成</td>
  </tr>
  </table>
</center>

!!! info "读数据时序解读"
    &emsp;&emsp;此处以miniRV的demo工程为例，介绍CPU读数据的时序。在仿真波形上任意选取一段波形，如图1-6所示。

    <center><img src = "../assets/1-6.png" width = 530></center>
    <center>图1-6 CPU的读数据波形示例</center>
    
    &emsp;&emsp;由<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/lw.dump#L13" target=_blank>lw.dump第13行</a>可知，地址为`0xC`的指令机器码是`0x0000a703`（`lw x14, 0(x1)`），是读访存指令。

    - 【*1440ns*】CPU需要读访存时令`daccess_ren`信号有效，同时给出读地址`daccess_addr`。`daccess_ren`信号 <mark>**仅有效一个时钟周期**</mark>。  
    - 【*1460ns*】数据存储器接收读地址，并在读取操作完成后，拉高`daccess_rvalid`信号，告知CPU数据已经返回，同时把数据通过`daccess_rdata`信号返回给CPU。

    &emsp;&emsp;由<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/lw.dump#L231" target=_blank>lw.dump第231行</a>可知，在数据段中，地址为`0x2000`的32位数据值是`0x00ff00ff`，与波形相符。



## 3. 实例解析

&emsp;&emsp;下面以miniRV demo工程已实现的`addi`指令为例，结合<a href="../5-ctrler/#2" target=_blank>数据通路表</a>和<a href="../5-ctrler/#3" target=_blank>控制信号表</a>示例、仿真波形、CPU示例代码以及汇编代码，解释指令在单周期CPU中的执行过程。同学们请参照此过程自行分析和理解其他指令的执行原理。此外，还可参考<a href="../3-parts" target=_blank>实验原理-2.CPU基础架构-基本功能部件</a>来理解demo工程CPU的各个功能部件的实现逻辑和代码。


!!! tip "将信号添加到仿真波形"
    &emsp;&emsp;先在左侧Scope窗口选中想要查看信号的模块，然后在旁边Objects窗口选中想要查看的信号，直接单击鼠标拖动即可将其添加到波形窗口，如图1-7所示。也可使用 ++shift++ 或 ++ctrl++ 加鼠标单击来一次选择多个信号。

    <center><img src = "../assets/1-7.png" width = 650></center>
    <center>图1-7 添加信号到仿真波形窗口</center>

&emsp;&emsp;在波形上定位到1840ns处，可见此时`ifetch_req`有效，且`ifetch_addr`的值为`32'h30`，说明此时正在对地址为`0x30`的指令进行取指。在下一拍，即1860ns处，`ifetch_valid`有效，且`ifetch_inst`的值为`32'hf0038393`，说明地址为`0x30`的指令已经取到，机器码是`0xf0038393`，如图1-8所示。

<center><img src = "../assets/1-8.png" width = 480></center>
<center>图1-8 `addi`指令仿真波形示例</center>

&emsp;&emsp;在<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/lw.dump#L24" target=_blank>lw.dump</a>中搜索指令地址可知，地址为`0x30`的指令机器码是`0xf0038393`，即`addi x7, x7, -256`指令，如图1-9所示，与仿真波形相符。

<center><img src = "../assets/1-9.png" width = 600></center>
<center>图1-9 lw.dump测试程序中的`addi`指令</center>

### 取指单元

&emsp;&emsp;`addi`指令的取指单元相关的数据通路和控制信号如图1-10所示。

<center><img src = "../assets/1-10.png" width = 300></center>
<center>图1-10 `addi`指令的数据通路和控制信号（取指单元）</center>

&emsp;&emsp;由数据通路表可知，对于`addi`指令，PC的新值由NPC模块的`npc`输出信号产生，相关代码如下：

```verilog title="cpu_core.v" linenums="89" hl_lines="4 10"
NPC U_NPC (
    .op         (npc_op),
    .pc         (pc),
    .npc        (npc),
    ......
);

PC U_PC (
    ......
    .npc        (npc),
    .pc         (pc)
);
```

&emsp;&emsp;控制器译码后产生`npc_op`控制信号，并控制NPC模块输出PC+4作为下一条指令的地址：

```verilog title="NPC.v" linenums="15" hl_lines="3"
always @(*) begin
    case (op)
        `NPC_PC4: npc = pc4;
        ......
    endcase
end
```

&emsp;&emsp;由`defines.vh`头文件可知，宏定义``NPC_PC4`的值是`2'b00`:

```verilog title="defines.vh" linenums="14"
`define NPC_PC4     2'b00
```

&emsp;&emsp;把控制器产生的`npc_op`信号、NPC产生的`npc`信号添加到波形，如图1-11所示。

<center><img src = "../assets/1-11.png" width = 450></center>
<center>图1-11 查看`addi`指令的取指单元的相关信号</center>

&emsp;&emsp;注意，**只有当`ifetch_valid`有效时，`ifetch_inst`才是有效的，相关信号也才是有效的**。因此，我们应当观察`npc_op`和`npc`信号在1860ns的值。可见`npc_op`等于`2'b00`（即``NPC_PC4`），`npc`等于`32'h34`（即当前PC值`0x30`再加4），与数据通路表、控制信号表及相关代码相符。


### 译码单元

&emsp;&emsp;`addi`指令的译码单元相关的数据通路和控制信号如图1-12所示。

<center><img src = "../assets/1-12.png" width = 480></center>
<center>图1-12 `addi`指令的数据通路和控制信号（译码单元）</center>

&emsp;&emsp;由数据通路表可知，`addi`指令的源操作数是RS1寄存器和立即数。其中，RS1寄存器的值需要使用机器码第19位到第15位来读取RF获得，相关代码如下：

```verilog title="cpu_core.v" linenums="130"
RF U_RF (
    .....
    .rR1        (inst[19:15]),
    .rD1        (rf_rd1),
    ......
);
```

&emsp;&emsp;而立即数则使用机器码第31位到第20位在SEXT中通过I类型扩展得到，相关代码如下：

```verilog title="cpu_core.v" linenums="141" hl_lines="3"
SEXT U_SEXT (
    .op         (sext_op),
    .imm        (inst[31:7]),
    .ext        (ext)
);
```

```verilog title="SEXT.v" linenums="11" hl_lines="3"
always @(*) begin
    case (op)
        `EXT_I : ext = {{20{imm[31]}}, imm[31:20]};
        ......
    endcase
end
```

&emsp;&emsp;此外，由数据通路表和控制信号表可知，`addi`指令需要把ALU的运算结果写回到目标寄存器，相关代码如下：

```verilog title="cpu_core.v" linenums="229" hl_lines="3"
always @(*) begin
    casex ({ld_st_flag, rf_wsel})
        {1'b0, `WB_ALU}: rf_wD = alu_c;
        ......
    endcase
end
```

&emsp;&emsp;由`defines.vh`头文件可知，宏定义````EXT_I```、``WB_ALU`的值分别是`3'b000`、`2'b00`:

```verilog title="defines.vh" linenums="18"
`define EXT_I       3'b000
```

```verilog title="defines.vh" linenums="23"
`define WB_ALU      2'b00
```

&emsp;&emsp;把控制器产生的`sext_op`、`rf_we`、`rf_wsel`信号，以及RS1寄存器的值（即RF的`rD1`输出信号）、扩展后的立即数（即SEXT的`ext`输出信号）添加到波形，如图1-13所示。

<center><img src = "../assets/1-13.png" width = 450></center>
<center>图1-13 查看`addi`指令的译码单元的相关信号</center>

&emsp;&emsp;同样地，我们应当观察`ifetch_valid`信号有效时的信号值。可见`sext_op`等于`3'h0`（即````EXT_I```）、`rf_wsel`等于0（即``WB_ALU`）、`rf_we`等于1表示指令要写回，与数据通路表、控制信号表及相关代码相符。

&emsp;&emsp;此外，由波形可知`addi`指令的寄存器操作数为`0xff010000`、立即数操作数为`0xffffff00`。

!!! question "在`ifetch_valid`上升沿的瞬间，信号的值不正确？"
    &emsp;&emsp;demo工程使用Block Memory IP核作为指令存储器和数据存储器。Block Memory IP核有时会在时钟信号上升沿之后稍微迟一点才会输出指令或数据。
    
    &emsp;&emsp;尽管信号发生了延迟，但指令的执行结果是在下一个时钟上升沿通过时序逻辑写回到RF的。因此，只要信号值在下一个时钟上升沿到来之前是正确的，指令的写回值就是正确的。


### 执行单元

&emsp;&emsp;`addi`指令的执行单元相关的数据通路和控制信号如图1-14所示。

<center><img src = "../assets/1-14.png" width = 350></center>
<center>图1-14 `addi`指令的数据通路和控制信号（执行单元）</center>

&emsp;&emsp;由数据通路表可知，`addi`指令需要ALU完成加法运算。加法的源数据1来自RS1寄存器，源数据2来自扩展后的立即数，相关代码如下：

```verilog title="cpu_core.v" linenums="169"
assign alu_a = rf_rd1;
assign alu_b = alub_sel ? ext : rf_rd2;
```

&emsp;&emsp;ALU在控制信号`alu_op`的控制下进行加法操作：

```verilog title="ALU.v" linenums="26" hl_lines="3"
    always @(*) begin
        case (op_r != 4'h0 ? op_r : op)
            `ALU_ADD  : c = a + b;
            ......
        endcase
    end
```

&emsp;&emsp;由`defines.vh`头文件可知，宏定义``ALU_ADD`的值是`5'h00`:

```verilog title="defines.vh" linenums="8"
`define ALU_ADD     5'h00
```

&emsp;&emsp;把控制器产生的`alu_op`、`alub_sel`信号，以及ALU的操作数`a`、`b`以及运算结果`c`添加到波形，如图1-15所示。

<center><img src = "../assets/1-15.png" width = 450></center>
<center>图1-15 查看`addi`指令的执行单元的相关信号</center>

&emsp;&emsp;由波形可知，`alu_op`等于`5'h0`（即````ALU_ADD```）、`alub_sel`等于1（即选择立即数作为源操作数2），与数据通路表、控制信号表及相关代码相符。此外，ALU的两个操作数与译码单元得到的两个源操作数相同。


### 存储单元

&emsp;&emsp;`addi`指令的存储单元相关的数据通路和控制信号如图1-16所示。

<center><img src = "../assets/1-16.png" width = 390></center>
<center>图1-16 `addi`指令的数据通路和控制信号（存储单元）</center>

&emsp;&emsp;`addi`指令是算术运算指令，不需要访存，因此控制信号表中的`ram_rop`信号为0，对应波形如图1-17所示。

<center><img src = "../assets/1-17.png" width = 450></center>
<center>图1-17 查看`addi`指令的存储单元的相关信号</center>

&emsp;&emsp;由波形可知，`ram_rop`和`daccess_ren`均为0，表示指令没有发出访存请求。
