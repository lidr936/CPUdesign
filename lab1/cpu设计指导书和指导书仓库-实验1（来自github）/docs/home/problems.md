&emsp;&emsp;本页面汇总了历届同学在本课程中可能会出现的问题及其解决办法，仅供参考。

!!! info "特别说明 :book:"
    &emsp;&emsp;以下罗列的问题并无特别的顺序，建议同学们先大体浏览各个问题。在实验中遇到问题时，先寻找类似的问题看看能否找到解决方法。



## 1. CPU设计

#### 1.1 数据通路图用什么软件画？

&emsp;&emsp;可以使用<a href="http://ms.hitsz.edu.cn/#" target="_blank">Visio</a>、<a href="https://online.visual-paradigm.com/drive/#infoart:proj=0&dashboard" target="_blank">Visual Paradigm</a>、
<a href="https://www.iodraw.com/" target="_blank">ioDraw</a>、<a href="https://app.diagrams.net/" target="_blank">draw.io</a>、<a href="https://www.processon.com/?utm_source=baidu&utm_medium=sem&utm_term=120470957204&utm_content=49530906908&uc_pagenum=1&uc_adposition=cl2&bd_vid=7544670811206821952" target="_blank">ProcessOn</a>等

#### 1.2 定义了宏，但报错显示未定义？

&emsp;&emsp;在每一个需要使用宏定义的`.v`文件内添加``include "defines.vh"`语句。此外，引用宏定义时需在前面加上 **``` ` ```** 符号。例如，`#define MACRO1 111`，则引用时应该是````MACRO1```。

#### 1.3 移位运算的移位位数超过`'d32`，或者是个负数，怎么办？

&emsp;&emsp;把移位位数看成是无符号数，截取最低5位才是有效的移位位数。

#### 1.4 load指令从DRAM取数据时，取到的是0

&emsp;&emsp;ALU计算得到的是字节地址，DRAM的地址是字地址，需排查接线是否有误。此外，也可能是前面的store指令往该存储单元写了0的数据。

#### 1.5 出现跟时钟有关的Critical Warning

&emsp;&emsp;检查是否同时使用了时钟信号的上升沿和下降沿。

#### 1.6 AXI Trace测试通过，但下板失败

&emsp;&emsp;Trace框架只会测试SoC的主存访问，不会测试外设访问。如果Trace测试通过，但下板测试不通过，首先应检查DCache的Uncached访问、SoC的外设访问是否存在问题。调试时，可通过把C_TEST程序的.coe文件导入主存然后进行功能仿真或下板抓取波形进行分析。

#### 1.7 如何提高CPU主频？

&emsp;&emsp;<u>优化措施需要针对瓶颈展开，才能事半功倍</u>。从理论上分析，单周期CPU的频率取决于执行最耗时的指令，流水线CPU的频率取决于最耗时的流水线阶段。因此，想要提高频率，需要找出数据通路中最耗时的部分。

&emsp;&emsp;在实践中，可借助Vivado综合后生成的时序报告来找出关键路径，然后通过逻辑优化或切割等方法来降低关键路径的延迟，详情可参考《<a href="https://blog.csdn.net/dengfenglai123/article/details/115598250?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-1-115598250-blog-126041215.pc_relevant_multi_platform_featuressortv2dupreplace&spm=1001.2101.3001.4242.2&utm_relevant_index=4" target="_blank">FPGA时序分析之关键路径-CSDN Blog</a>》。

&emsp;&emsp;使用Vivado查看关键路径的具体操作步骤如下：

&emsp;&emsp;**Step1**：更改时钟IP核设置（或修改分频器参数），提高CPU主时钟的频率至期望值；

&emsp;&emsp;**Step2**：通过快捷键`F11`或GUI操作，对工程进行综合（Synthesis）；

&emsp;&emsp;**Step3**：综合完成后，在Vivado默认界面左侧的`Flow Navigator`下，找到并展开`SYNTHESIS`下的`Open Synthesized Design`，点击`Report Timing Summary`，如下图所示。

<center><img src = "../assets/p-1.7-1.png" width = 200></center>

&emsp;&emsp;随后将弹出`Report Timing Summary`的对话框，直接点击`OK`按钮，即可在Vivado默认界面下方的区域查看时序总结报告。工程中的时序违例相关信息将被红色字体标注，如下图所示。

<center><img src = "../assets/p-1.7-2.png"></center>

&emsp;&emsp;**Step4**：展开标红的子项，查看关键路径，如下图所示。

<center><img src = "../assets/p-1.7-3.png"></center>

&emsp;&emsp;若想借助电路图分析，可在某条关键路径上打开右键菜单并点击`Schematic`，如下图所示。

<center><img src = "../assets/p-1.7-4.png"></center>

!!! info "补充说明 :book:"
    &emsp;&emsp;Step1并非必须 —— 当CPU主频较低时，工程中不存在时序违例，此时Step3的时序报告仍会显示关键路径，但并非以红色字显示。

#### 1.8 只做完单周期能不能及格？

- 如果是2人小组，则需要：

&emsp;&emsp;（1）单周期CPU实现所有指令，能够跑通Basic Trace；

&emsp;&emsp;（2）完成理想流水线CPU，通过<a href="../../lab2-A/2-idealpl/#3-cpu" target=_blank>功能仿真</a>，并在课上通过现场检查；

&emsp;&emsp;（3）为单周期CPU实现AXI总线，跑通<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/lw.dump" target=_blank>lw.dump</a>、<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/sw.dump" target=_blank>sw.dump</a>的功能仿真测试。

&emsp;&emsp;完成以上内容，并且还要认真完成报告，才能及格。

- 如果实在找不到人小组合作（比如重修的同学），则需要：

&emsp;&emsp;（1）完成A组或B组指令的单周期CPU，跑通Basic Trace；

&emsp;&emsp;（2）完成理想流水线CPU，通过<a href="../../lab2-A/2-idealpl/#3-cpu" target=_blank>功能仿真</a>，并在课上通过现场检查；

&emsp;&emsp;（3）完成<a href="../../lab2-B/5-ioupg" target=_blank>实验2的I/O接口编程任务</a>，并在课上通过现场检查；

&emsp;&emsp;完成以上内容，并且还要认真完成报告，才能及格。



## 2. Trace验证

#### 2.1 虚拟机启动不了，一直转圈

&emsp;&emsp;重启电脑后，3分钟内启动虚拟机。或更换座位。

#### 2.2 MobaXTerm连接时一直报错`Network error, connect refused`

&emsp;&emsp;建议换用实验室的WSL2虚拟机环境。

&emsp;&emsp;关闭防火墙和杀毒软件，重启电脑。

#### 2.3 VSCode连接远程Trace平台，报错`Bad owner or permissions on .ssh/config`

&emsp;&emsp;建议换用实验室的WSL2虚拟机环境。

&emsp;&emsp;解决方法可参考《<a href="https://cloud.tencent.com/developer/article/1643437" target="_blank">Win10下Bad owner or permissions on .ssh/config的解决办法-腾讯云</a>》。

#### 2.4 编译报错提示“multiple target patterns”

&emsp;&emsp;检查mySoC目录下是否有Zone.Identifier文件，将其全部删除后重试。

#### 2.5 build的时候报错`Timescale missing on this module`

&emsp;&emsp;在相应的`.v文件`里加上`/* verilator lint_off TIMESCALEMOD */`或删除所有文件里的``timescale 1ns / 1ps`语句。

#### 2.6 明明在虚拟机里修改过代码了，但波形还是原来的波形

&emsp;&emsp;尝试在`make`前先执行`make clean`命令。

#### 2.7 Trace验证时，所有指令都显示Time out

&emsp;&emsp;仔细按照<a href="../../trace/trace/#2" target="_blank">Trace测试说明</a>逐一检查debug信号、模块名、存储器参数设置等是否符合要求。

&emsp;&emsp;此外Time out可能是因为CPU本身陷入了长时间等待状态，比如发出了取指请求，但一直没有收到指令；或者一条指令执行完之后，一直没有取下一条指令；又或者数据访存出问题等等。此种情况，可结合Trace测试的仿真波形进行分析。

#### 2.8 复位信号到底是低电平还是高电平？

&emsp;&emsp;Trace验证时提供的复位信号是高电平复位。EGO1开发板的复位按钮是低电平复位，Minisys开发板则是高电平复位。

#### 2.9 Trace验证时，`REFERENCE`的PC和`MYCPU`的PC不一致

&emsp;&emsp;检查复位逻辑，务必保证复位后取第一条指令的PC为`32'h0`。

&emsp;&emsp;对于流水线CPU，确保一条指令比对完后、下一条指令比对前，拉低`debug_wb_have_inst`。

&emsp;&emsp;检查程序是否出现了错误的跳转，或检查PC的更新逻辑是否有bug。

#### 2.10 输入命令查看波形，结果没反应？

&emsp;&emsp;不要使用root用户。

#### 2.11 Trace测试用例的汇编代码在哪里可以找到？

&emsp;&emsp;看Trace测试包下的`asm`目录，即 `cdp-tests` / `asm`，或者根据指令集点击查看：<a href="https://gitee.com/hitsz-cslab/cdp-tests/tree/miniRV/asm" target=_blank>miniRV</a>、<a href="https://gitee.com/hitsz-cslab/cdp-tests/tree/miniLA/asm" target=_blank>miniLA</a>。

#### 2.12 仿真Trace通过所有指令，但下板卡在某一条指令的测例

&emsp;&emsp;检查CPU和主存（`IROM`、`DRAM`或`bram_axi`）是否使用不同的时钟。

#### 2.13 怎么保证提交代码后Trace自动评测一定能过

&emsp;&emsp;只要你自己在虚拟机里能够通过Trace测试，就把mySoC目录压缩提交就行。就算评测真的有问题，也会有人工复核，必要时会通过课程群联系你。

#### 2.14 VSCode连接Trace远程平台问题

&emsp;&emsp;建议换用实验室的WSL2虚拟机环境。

<center><img src = "../assets/p-2.14-1.png" width=550></center>

&emsp;&emsp;推荐用MobaXTerm来连接Trace远程平台，而不是用VSCode连接 —— VSCode连接远程服务器会占用较多网络资源，尤其是本课程有很多同学同时使用远程平台！

#### 2.15 执行make提示“No rule to make”

<center><img src = "../assets/p-2.15-1.png" width=650></center>

&emsp;&emsp;执行make前，先确保已经通过`cd`命令进入了`cdp-tests`目录。如果目录没问题，则检查`cdp-tests`目录是否包含`Makefile`文件。如果包含，但仍然提示“No rule to make”，则备份好个人代码，删除现有`cdp-tests`目录并重新下载和编译。

#### 2.16 我的Cache和乘法器已经通过测试，为什么Trace测试过不了

&emsp;&emsp;如果ICache、DCache、乘法器模块都能跑通计算机组成原理实验的测试，但是在Trace测试时不通过，是正常现象，毕竟不同测试的严格程度不一样。与其怀疑测试框架有问题，不如根据波形细心完成调试。



## 3. 下板

#### 3.1 开发板Auto Connect失败，是开发板坏了吗？

&emsp;&emsp;确保USB数据线正确连接开发板的JTAG接口 —— 对于Micro USB接口的Minisys开发板，JTAG接口在数码管右上方。

&emsp;&emsp;确保电源连接无误 —— 对于Micro USB接口的Minisys开发板，需额外连接5V的电源适配器；对于USB TypeC接口的Minisys开发板，使用USB数据线供电即可。

&emsp;&emsp;确保开发板右上角的电源拨码开关处于`ON`的状态。

&emsp;&emsp;排除以上硬件连接问题后，若Vivado中Auto Connect仍然失败，则按以下步骤操作：

&emsp;&emsp;**Step1**：关闭`Hardware`窗口的`server`，如下图所示。

<center><img src = "../assets/p-3.1-1.png" width = 400></center>

&emsp;&emsp;**Step2**：点击`Open target` -> `Open New Target...`，如下图所示。

<center><img src = "../assets/p-3.1-2.png" width = 330></center>

&emsp;&emsp;随后将弹出一个窗口，点击`Next`按钮。

&emsp;&emsp;**Step3**：确保`Connect to:`选择的是`Local server`，并继续点击`Next`按钮，如下图所示。

<center><img src = "../assets/p-3.1-3.png" width = 600></center>

&emsp;&emsp;等待进度条走完，将显示当前连接的`Hardware Targets`，如下图所示。

<center><img src = "../assets/p-3.1-4.png"></center>

&emsp;&emsp;实际操作中，若上图所示的界面未显示有`Hardware Targets`，则点击`Back`按钮，并重新尝试Step3 —— Micro USB接口的开发板版本较老，有时需多重复尝试几次才能连上。

&emsp;&emsp;若重复尝试Step3若干次，仍然连接失败，则先更换数据线，再从Step2开始重新尝试；若更换数据线后仍然连接失败，则换一块开发板再尝试。若更换开发板仍然连不上，可能是电脑尚未安装驱动。打开`C:\Xilinx\Vivado\2018.3\data\xicom\cable_drivers\nt64\digilent`目录，双击`install_digilent.exe`安装驱动程序，再重新尝试连接。若仍然连接不上，则将该开发板交给任课老师并说明相关情况。

&emsp;&emsp;**Step4**：继续点击`Next`按钮，并点击`Finish`按钮，即可连接开发板。

<!-- #### 3.2 导入综合好的IP核仿真时报错`Module <progrom> not found`

&emsp;&emsp;所提供的`.xci`格式的IP核只能用于生成比特流，不支持仿真。需要仿真时，可自己重新建立IP核，导入相应的`.coe文件`，然后再跑仿真。 -->

#### 3.2 综合/实现/比特流跑了半天跑不出来，怎么办？

&emsp;&emsp;首先代码越复杂，IROM里的程序越大，综合/实现/比特流是会越慢的，甚至可能需要几十分钟，请耐心等待。

&emsp;&emsp;检查工程名、所在路径是否有中文或空格。

&emsp;&emsp;尝试先关闭工程，找到工程所在目录，将除`project_name.xpr`和`project_name.srcs`之外的文件和文件夹删掉，再尝试生成比特流。

&emsp;&emsp;也有可能是代码有bug，导致Vivado出bug，从而跑不出来。这种情况下，需要检查代码中不规范不合理的地方，一一改过来。

#### 3.3 综合/实现/比特流报错`Combinational Loop Alert`

&emsp;&emsp;设计中存在组合逻辑环路，需要根据报错信息提示的信号/模块，找出这个环并解决之。

#### 3.4 跑实现的时候跑了很久，底下显示有红色数字的负数

&emsp;&emsp;检查CPU和DRAM是否使用不同的时钟。

#### 3.5 仿真和下板不一致，怎么办？

&emsp;&emsp;仿真和下板出现不一致的情况，可能是以下几个原因：

&emsp;&emsp;（1）<a href="../codingstyle/" target="_blank">代码规范性</a>问题，比如寄存器未赋初值、阻塞赋值和非阻塞赋值混用、多驱动等；  
&emsp;&emsp;（2）关键路径延迟太长，导致不满足`Setup time`或`Hold time` —— 可尝试优化关键路径或降低CPU主频；  
&emsp;&emsp;（3）组合逻辑出现竞争或冒险。

&emsp;&emsp;常见的问题包括：阻塞赋值和非阻塞赋值混用、组合逻辑的`if`语句没有`else`、`case`语句没有`default`、时钟频率不合适，或下板用的汇编程序有bug等等。

&emsp;&emsp;仿真和下板不一致时，问题可能比较隐晦，<u>需要耐心排查代码</u>。查错时，也可以参考Vivado的Warning信息、log日志等；当然也可使用<a href="../../verify/online-debug/" target="_blank">FPGA在线调试方法</a>抓取运行时波形进行分析。

#### 3.6 `Timing Report`中的`WNS`、`TNS`等几个时间都显示`NA`

&emsp;&emsp;IP核的分频器不要设置成Global buffer。如果是自己实现分频器，不能有复位信号。

&emsp;&emsp;检查时钟信号是否使用有误，比如是否同时使用`fpga_clk`和`cpu_clk`来驱动除了时钟模块以外的多个模块。
