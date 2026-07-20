## 1. 注意事项

&emsp;:star: **严禁将开发板带出实验室！**

&emsp;:star: **禁止用手接触电路板上的芯片、金属线路等！** 人手有静电、汗液和灰尘，可能损坏开发板。

&emsp;:star: 使用开发板时，**注意防水防尘，禁止在旁饮食！**

&emsp;:star: **禁止随意拔出** 开发板上的 **跳线帽**！

<center><img src = "../assets/b-1.png" width = 100%></center>
<center>图1 装袋后，^^把袋口折起来^^</center>

&emsp;:star: **禁止丢弃防静电袋！** 使用完毕时，**将开发板正确装入防静电袋**（如有），如图1所示。

&emsp;:star: **不要将USB线装入防静电袋！** 袋中只装开发板，USB线放袋外。

<!-- &emsp;:star::star: 对于T2507和T2608，请 **将电源适配器和USB线单独放在** 大纸箱旁边的 **小纸箱**！ -->

<!-- &emsp;:star::star: 将开发板放回大纸箱时，不管有无防静电袋，都应当 **将有拨码开关的一边朝下，竖立放置**，如图5所示。 -->

<!-- <center><img src = "../assets/b-5.png" width = 350></center>
<center>图5 开发板放置时，拨码开关一侧朝下，竖立放置</center> -->



## 2. 开发板使用须知

&emsp;&emsp;在 <span style="background-color: #df9bff;">**T2507、T2210**</span> 上课的同学们，使用的是 <span style="background-color: #df9bff;">**EGO1开发板**</span>。

&emsp;&emsp;在 <span style="background-color: #ff9bb2;">**T2506、T2612**</span> 上课的同学们，使用的是 <span style="background-color: #ff9bb2;">**Minisys开发板**</span>。

&emsp;&emsp;请根据课表标注的实验室，点击查看对应开发板的使用说明。


=== "EGO1使用说明"

    &emsp;&emsp;EGO1开发板的主芯片型号是<font color = blue>**XC7A35TCSG324-1**</font>，具有5200个逻辑Slice、50个36Kb的Block RAM存储器、90个DSP48E1数字信号处理器、5个时钟管理模块，内部时钟最高可达450MHz。

    &emsp;&emsp;使用USB-TypeC线连接JTAG接口，打开电源开关即可使用。==<font color = red>**插拔线材时，禁止使用蛮力**</font>==。

    <center><img src = "../assets/b-2.jpg" width = 100%></center>
    <center>图2 EGO1开发板实物图</center>

    &emsp;&emsp;**【时钟】**：100MHz晶振时钟，连接到FPGA的`P17`引脚。

    &emsp;&emsp;**【复位】**：S6按键开关，连接到FPGA的`P15`引脚，^^低电平复位^^。

    &emsp;&emsp;**【拨码开关】**：8个拨码开关，及其相邻的8位数码开关，^^往上拨为高电平^^。

    &emsp;&emsp;**【按键开关】**：S0~S4共5个通用按键开关，^^按下为高电平^^。

    &emsp;&emsp;**【数码管】**：共阴极数码管，高4位是1组，低4位是另1组；^^段选、位选信号均为高电平有效^^。

    &emsp;&emsp;**【LED】**：16位LED，^^高电平点亮^^。

    &emsp;&emsp;上述基本外设对应的引脚约束文件：<a href="../assets/ego1_pin.xdc" target=_blank>ego1_pin.xdc</a>。

    &emsp;&emsp;更多关于EGO1开发板的信息，请参考《<a href="../assets/EGO1开发板用户手册.pdf" target=_blank>EGO1开发板用户手册</a>》。

=== "Minisys使用说明"

    &emsp;&emsp;Minisys开发板的主芯片型号是<font color = blue>**XC7A100TFGG484-1**</font>，具有15850个逻辑Slice、135个36Kb的Block RAM存储器、240个DSP48E1数字信号处理器、6个时钟管理模块，内部时钟最高可达450MHz。

    &emsp;&emsp;使用USB-TypeC线连接JTAG接口，打开电源开关即可使用。==<font color = red>**插拔线材时，禁止使用蛮力**</font>==。

    &emsp;&emsp;Minisys有2个版本，其中一个版本的 ^^JTAG接口在电源开关旁边^^，请注意甄别。

    <center><img src = "../assets/b-3.jpg" width = 100%></center>
    <center>图3 Minisys开发板实物图</center>

    &emsp;&emsp;**【时钟】**：100MHz晶振时钟，连接到FPGA的`Y18`引脚。

    &emsp;&emsp;**【复位】**：S6按键开关，连接到FPGA的`P20`引脚，^^高电平复位^^。

    &emsp;&emsp;**【拨码开关】**：24个拨码开关，^^往上拨为高电平^^。

    &emsp;&emsp;**【按键开关】**：S1~S5共5个通用按键开关，^^按下为高电平^^。

    &emsp;&emsp;**【数码管】**：共阳极数码管，^^段选、位选信号均为低电平有效^^。

    &emsp;&emsp;**【LED】**：24位LED，^^高电平点亮^^。

    &emsp;&emsp;上述基本外设对应的引脚约束文件：<a href="../assets/minisys_pin.xdc" target=_blank>minisys_pin.xdc</a>。

    &emsp;&emsp;更多关于Minisys开发板的信息，请参考《<a href="../assets/Minisys开发板用户手册.pdf" target=_blank>Minisys开发板用户手册</a>》。


