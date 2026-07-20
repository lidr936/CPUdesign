&emsp;&emsp;在前面的章节中，我们在虚拟机上使用Trace测试框架对CPU进行了功能上的仿真验证。在下板时，我们也可以使用Trace测试程序来调试，即将Trace比对测试的汇编程序导入IROM存储器并生成比特流下板运行。

&emsp;&emsp;本课程提供可在FPGA上运行Trace比对的汇编测试程序，该程序的源码见测试包的<a href="https://gitee.com/hitsz-cslab/cdp-tests/blob/miniRV/asm/start.dump" target="_blank">`cdp-tests / asm / start.dump`</a>。

!!! note "关于下板运行Trace的说明 :loudspeaker:"
    &emsp;&emsp;本节所介绍的下板运行Trace并非必做内容，而是一种在FPGA板上运行的调试手段。

    &emsp;&emsp;miniLA无start.dump测试程序。如果需要下板测试Trace框架中的测试用例，则只能单个进行下板测试。

## 1. 导入测试程序

&emsp;&emsp;按照<a href="../../lab2-A/7-step" target=_blank>流水线CPU实验步骤</a>，使用bin2coe.py脚本把 `cdp-tests` / `bin` 目录下的start.bin转换成.coe文件并导入`bram_axi`的IP核。

&emsp;&emsp;接着，运行综合、实现、生成比特流，最终下板运行Trace测试。



## 2. 测试结果说明

&emsp;&emsp;cdp-tests测试包提供了37条指令（不含乘除法指令）的测试程序。每通过一个测试点，数码管显示的数值会加1，直至测试完毕。测试完毕时，数码管将以16进制形式显示测试总数和通过了的测试数量。

!!! example "举例说明 :chestnut:"
    &emsp;&emsp;以miniRV为例，如果实现了21条必做指令并通过了测试，数码管将显示`0x25000015`。数码管高2位显示`0x25`，表示共有`37`个测试点，数码管低2位显示`0x15`，表示通过了`21`个测试点。

&emsp;&emsp;需要注意的是，对于测试不通过的情形，如果数码管显示的值停在n，则表示第n+1条指令的测试失败。测试失败时，可查看start.dump的测试代码以定位出错指令，并进行相应的调试。

&emsp;&emsp;在下板测试中，如果数码管显示卡在某一个功能点，没有继续计数，一种方法是采用虚拟机中的Trace测试框架来进一步定位错误点。

- ***Step1***：进入`cdp-test`目录，输入`make`命令以重新编译；

- ***Step2***：输入`make run TEST=start`以运行start测试。

&emsp;&emsp;例如，某次测试时报错，`debug_wb_pc`显示了`0x000018f8`，如下图所示。

<center><img src = "../assets/t-1.png" width = 400></center>

&emsp;&emsp;打开start.dump文件，找到PC值为`0x000018f8`的指令，即可定位到具体出错的指令，如下图所示。

<center><img src = "../assets/t-2.png" width = 650></center>

&emsp;&emsp;显然，在上述例子中，mycpu执行到auipc指令时出错。

&emsp;&emsp;如果在虚拟机的Trace测试框架中通过了测试，但下板运行Trace测试程序时出错，即出现仿真和下板不一致的情况，请参考<a href="../../home/problems/#36" target="_blank">常见问题汇总之3.6</a>。
