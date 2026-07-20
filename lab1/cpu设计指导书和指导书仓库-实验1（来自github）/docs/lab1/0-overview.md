## 1. 实验目的

&emsp;&emsp;（1）理解单周期CPU的结构及工作原理；

&emsp;&emsp;（2）熟悉miniRV或miniLA指令集；

&emsp;&emsp;（3）掌握单周期CPU的设计与实现方法。



## 2. 实验内容

&emsp;&emsp;本实验要求在模板工程的基础上，设计实现支持miniRV或miniLA指令集的单周期CPU。

=== "miniRV"

    &emsp;&emsp;miniRV指令集如表0-1所示。其中，浅蓝色背景的是A组指令，浅橙色背景的是B组指令，绿色字体的8条指令是模板工程已经实现的示例指令。

    <center>表0-1 miniRV指令概览表</center>
    <center><img src = "../assets/t0-1.png" width = 500></center>

=== "miniLA :dragon:"

    &emsp;&emsp;miniLA指令集如表0-1A所示。其中，浅蓝色背景的是A组指令，浅橙色背景的是B组指令，绿色字体的8条指令是模板工程已经实现的示例指令。

    <center>表0-1A miniLA指令概览表</center>
    <center><img src = "../assets/t0-1A.png" width = 500></center>

&emsp;&emsp;本实验的具体要求如下：

&emsp;&emsp;（1）小组成员需各自挑选一组指令，并完成对应的数据通路表、控制信号表；

&emsp;&emsp;（2）与组员讨论协作，共同完成完整单周期CPU的数据通路图绘制；

&emsp;&emsp;（3）小组成员各自完成A、B组指令的单周期CPU设计与实现；

&emsp;&emsp;（4）小组成员各自调试，通过A、B组指令的单周期CPU的Basic Trace测试；

&emsp;&emsp;（5）与组员讨论协作，共同把代码整合成完整的单周期CPU，并通过Basic Trace测试。
