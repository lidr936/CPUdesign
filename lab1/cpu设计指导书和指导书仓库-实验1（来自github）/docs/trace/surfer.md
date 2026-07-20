&emsp;&emsp;<a href="https://surfer-project.org/" target=_blank>Surfer</a>是一个开源、可扩展、跨平台的数字电路波形查看工具。

## 1. 打开文件

&emsp;&emsp;波形文件和配置文件都可以直接拖拽打开，如下图所示。

<center><img src = "../assets/trace-5.png" width = 600></center>

<center><img src = "../assets/trace-6.png" width = 100%></center>

## 2. 添加和删除信号

&emsp;&emsp;首先在左上方的Scopes区域找到想要查看信号的模块，单击选中；然后右侧选择想要把信号添加到哪个信号下面；最后再点击Variables区域下的信号，如下图所示。

<center><img src = "../assets/surfer-1.png" width = 400></center>

&emsp;&emsp;只要鼠标点击Variables内的信号，这些信号就会被添加到右侧被选中的信号下方。比如在上图中，如果点击Variables内的`is_mul_div`信号，则该信号就会被添加到右侧的`ifetch_inst`信号的下方。

&emsp;&emsp;建议先在右侧选好希望添加信号的位置，再点击Variables内的信号，否则容易使得波形中的信号杂乱无章，不利于分析和调试。

&emsp;&emsp;添加信号时，还可以在上图“Variables”字样右侧的“Filter”搜索框内输入信号名称进行搜索。

&emsp;&emsp;删除信号时，只需点击上图右侧的某个信号，按下 ++delete++ 键即可。

## 3. 波形缩放

&emsp;&emsp;Surfer支持两种波形缩放方式，第一种是按住 ++ctrl++ 键，再滚动鼠标滚轮。此时，Surfer将以鼠标指针指向的竖直线为中心，缩放波形。

&emsp;&emsp;第二种方法是点击工具栏的放大、缩小按钮，如下图所示。

<center><img src = "../assets/surfer-2.png" width = 500></center>

## 4. 波形定位

&emsp;&emsp;Surfer支持滚动鼠标滚轮来左右移动波形，比Vivado方便许多。但用鼠标点击波形信号线，虽然能够查看信号在对应时刻的值，但不能选中信号。

&emsp;&emsp;此外，可以点击选中某个信号之后，点击工具栏的“吸边”工具，从而定位到信号发生变化的上一个或下一个时刻，如下图所示。

<center><img src = "../assets/surfer-3.png" width = 500></center>

&emsp;&emsp;点击选中某个信号之后，也可以通过键盘的 ++left++ 和 ++right++ 方向键来定位信号发生变化的时刻。

&emsp;&emsp;点击菜单栏的“Go to start”或“Go to end”按钮，可快速定位到波形的最开始或最末尾，如下图所示。

<center><img src = "../assets/surfer-4.png" width = 500></center>

## 5. 波形设置

&emsp;&emsp;在某个信号上右键，可设置波形的显示格式、颜色、设置分组等等，如下图所示。

<center><img src = "../assets/surfer-5.png" width = 550></center>
