## 1. 概述

&emsp;&emsp;处理器的例外（Exception）和中断（Interrupt）处理机制使得程序执行过程中发生意外情况时，计算机系统仍然能够正常运行，而不至于崩溃死机。

&emsp;&emsp;RISC-V架构将“意外情况”分为同步例外（或同步异常）和中断两种。同步例外指的是指令执行引发的异常情况，比如系统调用指令，或指令访问了不存在的内存地址等，这些例外与指令的执行过程同步。中断则指的是处理器外部引起的，与指令执行过程异步的异常情况，比如打印机中断、DMA中断。

&emsp;&emsp;在《计算机组成原理》课程中，我们学习了RISC-V的例外和中断处理过程 —— 使用 **`xEPC`** 寄存器记录被打断的程序控制流地址，使用 **`xCAUSE`** 寄存器记录例外原因，并跳转到统一的入口地址 **`0x1C090000`** 从而进行例外和中断的处理。

!!! question "`xEPC`、`xCAUSE`前面的`x`代表什么？ :teacher:"
    &emsp;&emsp;RISC-V支持M模式（Machine Mode，机器模式）、S模式（Supervisor Mode，监控者模式）和U模式（User Mode，用户模式）三种特权模式。其中，M模式权限最高，可以任意访问计算机硬件系统的所有硬件组成部分；S模式权限低于M模式，U模式权限最低。
    
    &emsp;&emsp;**M模式是处理器默认支持的特权模式**。如果系统要求具有一定的安全性，则需要实现M模式和U模式。如果希望运行类Unix的操作系统，则需要实现M、S、U三种模式。操作系统使用不同的特权模式来实现诸如响应外部事情、支持多任务等功能。

    &emsp;&emsp;一般地，在较低权限的特权模式下，如果发生例外和中断，处理器将进入更高权限的特权模式来处理例外和中断。不同的特权模式具有不同的控制和状态寄存器（**CSR**，Control and Status Registers）。比如，M模式具有`MEPC`、`MCAUSE`寄存器；S模式具有`SEPC`、`SCAUSE`寄存器，等等。

    &emsp;&emsp;==本课程不涉及S模式和U模式，因此在实现例外和中断处理时，应当使用`MEPC`、`MCAUSE`等M模式的CSR。==

!!! info "知识回顾 :book:"
    <embed src = "../assets/ch5_pipeline_spring2025.pdf#page=97" width="100%" height="460">



## 2. 设计任务

&emsp;&emsp;为单周期CPU设计实现基础的例外和中断处理功能（<u>不考虑嵌套中断</u>），具体包括：

&emsp;&emsp;（1）实现 **`MSTATUS`**、**`MEPC`** 和 **`MCAUSE`** 三个CSR寄存器；

&emsp;&emsp;（2）修改取指数据通路 —— 发生例外和中断时，处理器能够跳转到 **`0x1C09_0000`** 的入口地址；并且在例外和中断处理完毕后，处理器能够回到 **`MEPC`** 寄存器所记录的地址处继续执行；

&emsp;&emsp;（3）扩展IROM模块 —— 将IROM存储器IP核进行封装，并增加一个新的ROM存储器以存放例外和中断处理程序。当PC的<u>高16位</u>等于 **`0x1C09`** 时，从新的IROM存储器取指，否则从原来的IROM存储器取指；

&emsp;&emsp;（4）实现 **csrrwi**、**mret** 和 **ecall** 指令。



## 3. 例外和中断原理

### 3.1 CSR寄存器格式

&emsp;&emsp;对于32位的处理器，`MSTATUS`、`MEPC`和`MCAUSE`寄存器都是32位的。

&emsp;&emsp;`MSTATUS`寄存器的第3位是`MIE`（Machine Interrupt Enable），用于控制全局中断是否开启。当`MIE`为1时，全局中断开启；**当`MIE`为0时，全局中断被屏蔽**，此时处理器将忽略所有外部中断。

&emsp;&emsp;`MEPC`寄存器记录发生例外和中断时，被打断的控制流地址。如果是指令执行出错，则`MEPC`将记录出错的指令的地址；**如果是系统调用或外部中断，则`MEPC`将记录控制流当中当前指令的下一条指令的地址**。

&emsp;&emsp;`MCAUSE`寄存器记录例外或中断的原因。`MCAUSE`寄存器由`Interrupt`（`MCAUSE[31]`）和`Exception Code`（`MCAUSE[30:0]`）两个字段构成。其中，`Interrupt`字段记录是否发生中断，`Exception Code`字段则表示例外或中断的具体原因，详见表11-1。

<center>表11-1 `MCAUSE`寄存器格式</center>
<center><img src = "../assets/11-1.png" width = 450></center>

&emsp;&emsp;在本课程中，只需考虑M模式的外部中断和系统调用两种情况，即`MCAUSE`的有效值要么是`32'h8000000b`，要么是`32'h0000000b`。

### 3.2 例外和中断指令

&emsp;&emsp;为了实现例外与中断处理功能，需要增加如表11-2所示的三条指令。

<center>表11-2 例外与中断指令表</center>
<center><img src = "../assets/11-2.png" width = 100%></center>

&emsp;&emsp;**（1）`csrrwi` 指令**

&emsp;&emsp;`csrrwi`指令用于读写CSR寄存器。指令中的`csrno`字段表示CSR寄存器的地址。本课程涉及的CSR寄存器地址如表11-3所示。

<center>表11-3 CSR列表</center>
<center>
    
| CSR地址 | CSR名称 | CSR功能 |
| :-: | :-: | :-: |
| 0x300 | MSTATUS | 使能或关闭全局中断 |
| 0x341 | MEPC | 存储例外或中断处理的返回地址 |
| 0x342 | MCAUSE | 记录发生例外或中断的原因 |

</center>

!!! example "指令示例 :pencil:"
    &emsp;&emsp;由3.1节可知，`MSTATUS`寄存器的第3位用于控制全局中断是否开启；而由表11-3可在，`MSTATUS`寄存器的地址是`0x300`。因此，若想打开全局中断，则可执行`csrrwi zero, 0x300, 8`；若想关闭全部中断，则可执行`csrrwi zero, 0x300, 0`。

    &emsp;&emsp;类似地，若想读取`MCAUSE`寄存器的值，从而获取例外或中断的具体原因，则可执行`csrrwi t0, 0x342, 0`。

&emsp;&emsp;一般地，在进入例外和中断处理程序时，都需要首先关闭全局中断，以防止中断嵌套。为此，**`csrrwi`指令的执行不能被中断打断**。

&emsp;&emsp;**（2）`mret` 指令**
    
&emsp;&emsp;`mret`指令用于从例外和中断处理程序中返回。一般地，从例外和中断处理程序返回时，还需将特权等级恢复到发生例外或中断之前的特权等级。但由于本课程不涉及S模式和U模式，因此不需要考虑特权等级的切换问题。

&emsp;&emsp;**（3）`ecall` 指令**

&emsp;&emsp;`ecall`指令用于实现系统调用。处理器执行`ecall`指令将引起例外。一般地，`ecall`的例外处理程序将`a7`寄存器的值作为系统调用号，并使用`a0`、`a1`等寄存器传递参数，比如RARS的系统调用（RARS菜单 -> Help -> Syscalls）。注意，在RISC-V中，**例外是不可屏蔽的**。

### 3.3 例外和中断处理过程

- **例外处理过程**：

&emsp;&emsp;（1）例外的发生：处理器执行例外指令（如`ecall`）时，控制器通过译码产生例外信号。  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;例外信号有效时，硬件自动将PC寄存器的值修改为例外和中断处理程序的  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;统一入口地址`0x1C090000`，将下一条指令的地址保存到`MEPC`寄存器，并  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;将`MCAUSE`寄存器设置为`0x0000000b`；

&emsp;&emsp;（2）例外的处理：例外和中断处理程序首先关闭全局中断，并在保护现场后读取`MCAUSE`  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;寄存器，并根据例外的原因，跳转到相应的处理程序；

&emsp;&emsp;（3）例外的返回：例外处理完成后，恢复现场并重新打开全局中断，然后执行`mret`指令。  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;执行`mret`指令时，控制器通过译码产生控制信号，使得PC寄存器被更新  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;为`MEPC`寄存器的值。

- **中断处理过程**：

&emsp;&emsp;（1）中断的发生：外部中断被触发时，处理器的中断信号有效。此时，<u>如果当前全局中断未</u>  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;<u>被关闭，并且当前执行的并非是原子指令</u>，则硬件自动将PC寄存器的值修  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;改为例外和中断处理程序的统一入口地址`0x1C090000`，将下一条指令的  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;地址保存到`MEPC`寄存器，再将`MCAUSE`寄存器设置为`0x8000000b`；

&emsp;&emsp;（2）中断的处理：例外和中断处理程序首先关闭全局中断，并在保护现场后读取`MCAUSE`  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;寄存器，并根据中断的原因，跳转到相应的处理程序；

&emsp;&emsp;（3）中断的返回：中断处理完成后，恢复现场并重新打开全局中断，然后执行`mret`指令。  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;执行`mret`指令时，控制器通过译码产生控制信号，使得PC寄存器被更新  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;为`MEPC`寄存器的值。

&emsp;&emsp;例外的处理过程与中断的处理过程基本相同，区别在于例外是不可屏蔽的，而中断是可以屏蔽的。<u>只有在打开全局中断、当前执行的不是原子指令，且外部中断被触发时，才能进行中断处理</u>。



## 4. 实现步骤

&emsp;&emsp;参考以下步骤或参考Logisim中的SoC电路，实现例外和中断处理功能：

&emsp;&emsp;（1）**修改IROM模块**：以相同的参数和配置创建新的IROM IP核`IROM_t`，并将例外和中断处理程序的机器码`trap_handle.coe`导入`IROM_t`IP核，然后将`IROM_t`与现有的`IROM`一并封装起来，再根据输入的取指地址选择从哪个IROM输出指令；

&emsp;&emsp;（2）**修改控制器模块**：增加`csrrwi`、`mret`和`ecall`指令的译码逻辑，并产生所需的控制信号，如处理器内部的例外信号、例外和中断返回信号等；

&emsp;&emsp;（3）**修改NPC模块**：根据外部中断、处理器内部的例外信号、例外和中断返回等信号，更新NPC的内部逻辑；

&emsp;&emsp;（4）**新增CSR模块**：新建CSR模块，内部包含`MSTATUS`、`MEPC`和`MCAUSE`三个寄存器；CSR模块既能够通过硬件自动更新相应寄存器的值，也能够通过`csrrwi`指令对任意的CSR寄存器进行读写；

&emsp;&emsp;（5）**修改按键开关外设**：将S5（P2）开关作为外部中断源信号`intr`，将其从按键开关外设中独立开来；

&emsp;&emsp;（6）**修改CPU及SoC顶层模块**：将`intr`信号分别添加到CPU顶层模块和SoC顶层模块；

&emsp;&emsp;（7）**仿真调试及下板验证**：验证按下S5开关后，能否正常进入中断处理程序并正常返回。
