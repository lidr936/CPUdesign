&emsp;&emsp;芯片和处理器设计是制约我国科学技术进一步发展的“卡脖子”技术之一。尽管我国在军事、超级计算机和航空航天等关键领域已经逐步实现芯片和处理器的自主研发和设计，但与国外相比，我国在芯片和处理器设计以及软件生态建设等方面仍然存在较大短板。

&emsp;&emsp;为了进一步实现芯片和处理器技术的自主可控，龙芯中科基于二十多年的CPU研制和生态建设的积累，于2020年推出了<a href="https://www.loongson.cn/system/loongarch" target="_blank">LoongArch指令集架构</a>。该架构包括基础架构和向量指令、虚拟化、二进制翻译等扩展部分，具备良好的自主性、先进性和兼容性。

&emsp;&emsp;miniLA是龙芯LA32R (LoongArch32 Reduced) 指令集的子集，共包含32个通用寄存器和38条指令 (含3R型10条、2RI5型3条、2RI12型14条、1RI20型2条、2RI16型7条和I26型2条)。



## 1. miniLA通用寄存器

&emsp;&emsp;miniLA具有32个32位通用寄存器，与LA32R完全相同，如表2-1所示。

<center>表2-1 miniLA通用寄存器</center>
<center>

| 寄存器 | 助记符 | 释义 |
| :-: | :-: | :- |
| r0 | zero | 常数0，永远只返回0 (硬件0，只读不可写) |
| r1 | ra | 存放调用子程序(函数)时的返回地址 (Return Address) |
| r2 | tp | 线程指针。多线程应用程序通过该寄存器来访问某个线程的本地数据 (Thread Pointer) |
| r3 | sp | 堆栈指针。对它的调整必须显式地通过指令来实现，硬件不支持堆栈指针的调整 (Stack Pointer) |
| r4~r5 | a0~a1 | 存放子程序(函数)调用时的整型参数或返回值 |
| r6~r11 | a2~a7 | 存放子程序(函数)调用时的整型参数 |
| r12~r20 | t0~t8 | 存放临时变量，子程序(函数)使用时不自动保存这些寄存器的值，因此调用后它们的值可能被破坏 |
| r21 | u0 | 其他通用寄存器 |
| r22 | fp / s9 | 子程序用该寄存器做堆栈帧指针。子程序(函数)必须在返回前恢复这些寄存器的值以保证其没有变化 (Frame Pointer)。或作为静态寄存器 |
| r23~r31 | s0~s8 | 静态寄存器 |

</center>

&emsp;&emsp;在miniLA架构中，指令集与通用寄存器存在正交关系，即所有的32个通用寄存器都可以被任意指令使用。

&emsp;&emsp;另外，在汇编语言中，既可以通过寄存器号也可以通过助记符来引用一个寄存器。例如，汇编中的“r0”和“zero”均表示第0个寄存器；“r3”和“sp”均表示第3个寄存器。

!!! info "小贴士 :mega:"
    &emsp;&emsp;在LoongArch汇编程序使用寄存器时，有时需添加`$`符号（如`$r0`、`$zero`），否则相关汇编工具会报语法错误。



## 2. miniLA指令速查表

&emsp;&emsp;miniLA指令的格式、功能、语法及解释汇总如表2-2A所示。其中，浅蓝色背景的是A组指令，浅橙色的则是B组指令，而绿色字体的指令则是demo工程已经实现的指令。

<center>表2-2 miniLA指令速查表</center>
<center><img src = "../assets/t2-2A.png"></center>

&emsp;&emsp;下面对每条指令的格式、功能等给出详细解释，所使用的符号约定如表2-3所示。

<center>表2-3 符号释义</center>
<center>

| 符号 | 释义 |
| :-: | :- |
| rj、rk、rd | 32位通用寄存器的编号 (rj、rk存放源操作数，rd存放目的操作数) |
| ui5 | 5位无符号立即数 |
| si12 | 12位有符号立即数 |
| si20 | 20位有符号立即数 |
| offset | 指令所使用的立即数 (扩展后) |
| offsXX | 指令码中的立即数 (XX是表示位宽的数字；扩展前) |
| PC | 赋值符号右侧的PC表示当前指令的地址 |
| (rj) | 寄存器rj的值 (其他同理) |
| Mem[addr] | 地址为addr的存储单元的值 |
| sext(a) | a的符号扩展 |
| zext(a) | a的零扩展 |

</center>



## 3. 指令详解
### 3.1 3R型指令
#### add.w  
- 指令名：加法  
- 使用语法：`add.w rd, rj, rk`  
- 功能描述：把寄存器`rj`加上寄存器`rk`，结果写入寄存器`rd`。忽略算术溢出。  
- 汇编例子：
<center>
``` asm
add.w r4, r2, r3    # (x4) ← (x2) + (x3), (PC) ← (PC) + 4
```
</center>

#### sub.w  
- 指令名：减法  
- 使用语法：`sub.w rd, rj, rk`  
- 功能描述：从寄存器`rj`减去寄存器`rk`，结果写入寄存器`rd`。忽略算术溢出。  
- 汇编例子：
<center>
``` asm
sub r7, r5, r9    # (r7) ← (r5) - (r9), (PC) ← (PC) + 4
```
</center>

#### and  
- 指令名：逻辑与  
- 使用语法：`and rd, rj, rk`  
- 功能描述：将寄存器`rj`和寄存器`rk`进行按位与，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
and r6, r1, r0    # (r6) ← (r1) & (r0), (PC) ← (PC) + 4
```
</center>

#### or  
- 指令名：逻辑或  
- 使用语法：`or rd, rj, rk`  
- 功能描述：将寄存器`rj`和寄存器`rk`进行按位或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
or r12, r13, r1    # (r12) ← (r13) | (r1), (PC) ← (PC) + 4
```
</center>

#### xor  
- 指令名：逻辑异或  
- 使用语法：`xor rd, rj, rk`  
- 功能描述：将寄存器`rj`和寄存器`rk`进行按位异或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
xor r3, r3, r3    # (r3) ← (r3) ^ (r3), (PC) ← (PC) + 4
```
</center>

#### sll.w  
- 指令名: 逻辑左移  
- 使用语法：`sll.w rd, rj, rk`  
- 功能描述：把寄存器`rj`左移`rk`位，低位补0，结果写入寄存器`rd`。`rk[4:0]`表示左移位数，高位忽略。  
- 汇编例子：
<center>
``` asm
sll.w r1, r6, r2    # (r1) ← (r6) << (r2)[4:0], (PC) ← (PC) + 4
```
</center>

#### srl.w  
- 指令名: 逻辑右移  
- 使用语法：`srl.w rd, rj, rk`  
- 功能描述：把寄存器`rj`右移`rk`位，高位补0，结果写入寄存器`rd`。`rk[4:0]`表示右移位数，高位忽略。  
- 汇编例子：
<center>
``` asm
srl.w r5, r3, r4    # (r5) ← (r3) >> (r4)[4:0], (PC) ← (PC) + 4
```
</center>

#### sra.w  
- 指令名: 算术右移  
- 使用语法：`sra.w rd, rj, rk`  
- 功能描述：把寄存器`rj`右移`rk`位，高位补`rj[31]`，结果写入寄存器`rd`。`rk[4:0]`表示右移位数，高位忽略。  
- 汇编例子：
<center>
``` asm
sra.w r3, r4, r7    # (r3) ← (r4) >> (r7)[4:0], (PC) ← (PC) + 4
```
</center>

#### slt  
- 指令名: 小于则置位  
- 使用语法：`slt rd, rj, rk`  
- 功能描述：比较寄存器`rj`和寄存器`rk`，比较时视为有符号数。如果`rj`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
slt r1, r2, r0    # (r1) ← ((r2) < (r0)), (PC) ← (PC) + 4
```
</center>

#### sltu  
- 指令名: 无符号小于则置位  
- 使用语法：`sltu rd, rj, rk`  
- 功能描述：比较寄存器`rj`和寄存器`rk`，比较时视为无符号数。如果`rj`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
sltu r5, r1, r2    # (r5) ← ((r1) < (r2)), (PC) ← (PC) + 4
```
</center>

#### mul.w  
- 指令名: 乘法取低32位  
- 使用语法：`mul.w rd, rj, rk`  
- 功能描述：把寄存器`rj`和寄存器`rk`相乘，乘积的低32位写入`rd`。  
- 汇编例子：
<center>
``` asm
mul.w r5, r1, r2    # (r5) ← ((r1) × (r2))[31:0], (PC) ← (PC) + 4
```
</center>

#### mulh.w  
- 指令名: 有符号乘法取高32位  
- 使用语法：`mulh.w rd, rj, rk`  
- 功能描述：把寄存器`rj`和寄存器`rk`作有符号乘法，乘积的高32位写入`rd`。  
- 汇编例子：
<center>
``` asm
mulh.w r5, r1, r2    # (r5) ← ((r1) × (r2))[63:32], (PC) ← (PC) + 4
```
</center>

#### mulh.wu  
- 指令名: 无符号乘法取高32位  
- 使用语法：`mulh.wu rd, rj, rk`  
- 功能描述：把寄存器`rj`和寄存器`rk`作无符号乘法，乘积的高32位写入`rd`。  
- 汇编例子：
<center>
``` asm
mulh.wu r5, r1, r2    # (r5) ← ((r1) × (r2))[63:32], (PC) ← (PC) + 4
```
</center>

#### div.w  
- 指令名: 有符号除法  
- 使用语法：`div.w rd, rj, rk`  
- 功能描述：把寄存器`rj`和寄存器`rk`视为有符号数，并计算`rj` ÷ `rk`，商写入`rd`。  
- 汇编例子：
<center>
``` asm
div.w r5, r1, r2    # (r5) ← (r1) / (r2), (PC) ← (PC) + 4
```
</center>

#### div.wu  
- 指令名: 无符号除法  
- 使用语法：`div.wu rd, rj, rk`  
- 功能描述：把寄存器`rj`和寄存器`rk`视为无符号数，并计算`rj` ÷ `rk`，商写入`rd`。  
- 汇编例子：
<center>
``` asm
div.wu r5, r1, r2    # (r5) ← (r1) / (r2), (PC) ← (PC) + 4
```
</center>

#### mod.w  
- 指令名: 有符号求余  
- 使用语法：`mod.w rd, rj, rk`  
- 功能描述：把寄存器`rj`和寄存器`rk`视为有符号数，并计算`rj` ÷ `rk`，余数写入`rd`。  
- 汇编例子：
<center>
``` asm
mod.w r5, r1, r2    # (r5) ← (r1) % (r2), (PC) ← (PC) + 4
```
</center>

#### mod.wu  
- 指令名: 无符号求余 
- 使用语法：`mod.wu rd, rj, rk`  
- 功能描述：把寄存器`rj`和寄存器`rk`视为无符号数，并计算`rj` ÷ `rk`，余数写入`rd`。  
- 汇编例子：
<center>
``` asm
mod.wu r5, r1, r2    # (r5) ← (r1) % (r2), (PC) ← (PC) + 4
```
</center>


### 3.2 2RI5型指令
#### slli.w  
- 指令名：立即数逻辑左移  
- 使用语法：`slli.w rd, rj, ui5`  
- 功能描述：把寄存器`rj`左移`ui5`位，低位补0，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
slli.w r5, r3, 3    # (r5) ← (r3) << 3, (PC) ← (PC) + 4
```
</center>

#### srli.w  
- 指令名：立即数逻辑右移  
- 使用语法：`srli.w rd, rj, ui5`  
- 功能描述：把寄存器`rj`右移`ui5`位，高位补0，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
srli.w r1, r2, 1    # (r1) ← (r2) >> 1, (PC) ← (PC) + 4
```
</center>

#### srai.w  
- 指令名：立即数算术右移  
- 使用语法：`srai.w rd, rj, ui5`  
- 功能描述：把寄存器`rj`右移`ui5`位，高位补`rj[31]`，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
srai.w r3, r1, 7    # (r3) ← (r1) >> 7, (PC) ← (PC) + 4
```
</center>


### 3.3 2RI12型指令
#### addi.w  
- 指令名：立即数加法  
- 使用语法：`addi.w rd, rj, si12`  
- 功能描述：把符号扩展的立即数加到寄存器`rj`上，结果写入寄存器`rd`。忽略算术溢出。  
- 汇编例子：
<center>
``` asm
addi.w r3, r3, 4    # (r3) ← (r3) + 4, (PC) ← (PC) + 4
```
</center>

#### andi  
- 指令名：立即数逻辑与  
- 使用语法：`andi rd, rj, ui12`  
- 功能描述：把零扩展的立即数与寄存器`rj`进行按位与，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
andi r1, r3, 0xFFE    # (r1) ← (r3) & 0x0000_0FFE, (PC) ← (PC) + 4
```
</center>

#### ori  
- 指令名：立即数逻辑或  
- 使用语法：`ori rd, rj, ui12`  
- 功能描述：把零扩展的立即数与寄存器`rj`的值进行按位或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
ori r6, r2, 0x001    # (r6) ← (r2) | 0x001, (PC) ← (PC) + 4
```
</center>

#### xori  
- 指令名：立即数逻辑异或  
- 使用语法：`xori rd, rj, ui12`  
- 功能描述：把零扩展的立即数与寄存器`rj`的值进行按位异或，结果写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
xori r4, r0, 0x002    # (r4) ← (r0) ^ 0x002, (PC) ← (PC) + 4
```
</center>

#### slti  
- 指令名: 小于立即数则置位  
- 使用语法：`slti rd, rj, si12`  
- 功能描述：比较寄存器`rj`和符号扩展的立即数，比较时视为有符号数。如果`rj`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
slti r7, r5, 0    # (r7) ← ((r5) < 0), (PC) ← (PC) + 4
```
</center>

#### sltui  
- 指令名: 无符号小于立即数则置位  
- 使用语法：`sltui rd, rj, si12`  
- 功能描述：比较寄存器`rj`和符号扩展的立即数，比较时视为无符号数。如果`rj`更小，向寄存器`rd`写入1，否则写入0。  
- 汇编例子：
<center>
``` asm
sltui r3, r1, -1024    # (r3) ← ((r1) < 0xC00), (PC) ← (PC) + 4
```
</center>

#### ld.b  
- 指令名：字节加载  
- 使用语法：`ld.b rd, rj, si12`  
- 功能描述：从字节地址`(rj)+sext(si12)`处读取一个字节，经符号扩展后写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
ld.b r5, r2, -3    # (r5) ← sext(Mem[(r2) - 3][7:0]), (PC) ← (PC) + 4
```
</center>

#### ld.bu  
- 指令名：无符号字节加载  
- 使用语法：`ld.bu rd, rj, si12`  
- 功能描述：从字节地址`(rj)+sext(si12)`处读取一个字节，并写入寄存器·。  
- 汇编例子：
<center>
``` asm
ld.bu r5, r2, -3    # (r5) ← Mem[(r2) - 3][7:0], (PC) ← (PC) + 4
```
</center>

#### ld.h  
- 指令名：半字加载  
- 使用语法：`ld.h rd, rj, si12`  
- 功能描述：从半字地址`(rj)+sext(si12)`处读取2个字节，经符号扩展后写入寄存器·。  
- 汇编例子：
<center>
``` asm
ld.h r5, r2, 1    # (r5) ← sext(Mem[(r2) + 1][15:0]), (PC) ← (PC) + 4
```
</center>

#### ld.hu  
- 指令名：无符号半字加载  
- 使用语法：`ld.hu rd, rj, si12`  
- 功能描述：从半字地址`(rj)+sext(si12)`处读取2个字节，并写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
ld.hu r5, r2, 6    # (r5) ← Mem[(r2) + 6][15:0], (PC) ← (PC) + 4
```
</center>

#### ld.w  
- 指令名：字加载  
- 使用语法：`ld.w rd, rj, si12`  
- 功能描述：从字地址`(rj)+sext(si12)`处读取4个字节，并写入寄存器`rd`。  
- 汇编例子：
<center>
``` asm
ld.w r5, r2, 8    # (r5) ← Mem[(r2) + 8], (PC) ← (PC) + 4
```
</center>

#### st.b  
- 指令名：存字节  
- 使用语法：`st.b rd, rj, si12`  
- 功能描述：将寄存器`rd`的最低字节存入内存的字节地址`(rj)+sext(si12)`处。  
- 汇编例子：
<center>
``` asm
st.b r9, r11, 5    # Mem[(r11) + 5] ← (r9)[7:0], (PC) ← (PC) + 4
```
</center>

#### st.h  
- 指令名：存半字  
- 使用语法：`st.h rd, rj, si12`  
- 功能描述：将寄存器`rd`的最低2个字节存入内存的半字地址`(rj)+sext(si12)`处。  
- 汇编例子：
<center>
``` asm
st.h r9, r11, 10    # Mem[(r11) + 10] ← (r9)[15:0], (PC) ← (PC) + 4
```
</center>

#### st.w  
- 指令名：存字  
- 使用语法：`st.w rd, rj, si12`  
- 功能描述：将寄存器`rd`存入内存的字地址`(rj)+sext(si12)`处。  
- 汇编例子：
<center>
``` asm
st.w r9, r11, 4    # Mem[(r11) + 4] ← (r9), (PC) ← (PC) + 4
```
</center>


### 3.4 1RI20型指令
#### lu12i.w  
- 指令名：高位立即数加载  
- 使用语法：`lu12i.w rd, si20`  
- 功能描述：将符号扩展的20位立即数逻辑左移12位，结果写入寄存器`rd`。  
- 汇编例子：  
<center>
``` asm
lu12i.w r15, 0xABCDE    # (r15) ← 0xABCDE000, (PC) ← (PC) + 4
```
</center>

#### pcaddu12i  
- 指令名：PC加立即数  
- 使用语法：`pcaddu12i rd, si20`  
- 功能描述：把符号扩展的20位立即数逻辑左移12位，再与`PC`相加，结果写入寄存器`rd`。  
- 汇编例子：  
<center>
``` asm
pcaddu12i r6, 0x2468A    # (r6) ← (PC) + 0x2468A000, (PC) ← (PC) + 4
```
</center>


### 3.5 2RI16型指令
#### beq  
- 指令名：相等时分支  
- 使用语法：`beq rj, rd, offset`  
- 功能描述：若寄存器`rj`和寄存器`rd`的值相等，则跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs16 << 2)`。其中，`offs16`是指令码中的16位立即数。  
- 汇编例子：
<center>
``` asm
beq r0, r1, -4    # PC ← ((r0) == (r1)) ? PC - 4 : PC + 4
```
</center>

#### bne  
- 指令名：不相等时分支  
- 使用语法：`bne rj, rd, offset`  
- 功能描述：若寄存器`rj`和寄存器`rd`的值不相等，则跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs16 << 2)`。其中，`offs16`是指令码中的16位立即数。  
- 汇编例子：
<center>
``` asm
bne r0, r1, 8    # PC ← ((r0) != (r1)) ? PC + 8 : PC + 4
```
</center>

#### blt  
- 指令名：小于时分支  
- 使用语法：`blt rj, rd, offset`  
- 功能描述：若寄存器`rj`的值小于寄存器`rd`的值（比较时视为有符号数），则跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs16 << 2)`。其中，`offs16`是指令码中的16位立即数。  
- 汇编例子：
<center>
``` asm
blt r7, r0, -4    # PC ← ((r7) < (r0)) ? PC - 4 : PC + 4
```
</center>

#### bltu  
- 指令名：无符号小于时分支  
- 使用语法：`bltu rj, rd, offset`  
- 功能描述：若寄存器`rj`的值小于寄存器`rd`的值（比较时视为无符号数），则跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs16 << 2)`。其中，`offs16`是指令码中的16位立即数。  
- 汇编例子：
<center>
``` asm
bltu r7, r0, 8    # PC ← ((r7) < (r0)) ? PC + 8 : PC + 4
```
</center>

#### bge  
- 指令名：大于等于时分支  
- 使用语法：`bge rj, rd, offset`  
- 功能描述：若寄存器`rj`的值大于等于寄存器`rd`的值（比较时视为有符号数），则跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs16 << 2)`。其中，`offs16`是指令码中的16位立即数。  
- 汇编例子：
<center>
``` asm
bge r6, r0, -4    # PC ← ((r6) >= (r0)) ? PC - 4 : PC + 4
```
</center>

#### bgeu  
- 指令名：无符号大于等于时分支  
- 使用语法：`bgeu rj, rd, offset`  
- 功能描述：若寄存器`rj`的值大于等于寄存器`rd`的值（比较时视为无符号数），则跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs16 << 2)`。其中，`offs16`是指令码中的16位立即数。  
- 汇编例子：
<center>
``` asm
bgeu r10, r0, 8    # PC ← ((r10) >= (r0)) ? PC + 8 : PC + 4
```
</center>

#### jirl  
- 指令名：无条件跳转并寄存器链接  
- 使用语法：`jirl rd, rj, offset`  
- 功能描述：将`PC+4`的值写入寄存器`rd`，然后无条件跳转。跳转的目标地址是`rj`寄存器的值加上偏移量`offset = sext(offs16 << 2)`。其中，`offs16`是指令码中的16位立即数。  
- 汇编例子：
<center>
``` asm
jirl r1, r7, -4    # r1 ← (PC) + 4, (PC) ← ((r7) - 4)
```
</center>


### 3.6 I26型指令
#### b  
- 指令名：无条件跳转  
- 使用语法：`b offset`  
- 功能描述：跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs26 << 2)`。其中，`offs26`是指令码中的26位立即数。  
- 汇编例子：
<center>
``` asm
b 0x1234    # (PC) ← (PC) + 0x1234
```
</center>

#### bl  
- 指令名：无条件跳转并寄存器链接  
- 使用语法：`bl offset`  
- 功能描述：将`PC+4`的值写入寄存器`r1`，然后无条件跳转。跳转的目标地址是当前`PC`值加上偏移量`offset = sext(offs26 << 2)`。其中，`offs26`是指令码中的26位立即数。`bl`指令在功能上类似于`jirl r1, offs16`，但跳转范围大得多。  
- 汇编例子：
<center>
``` asm
bl -4    # (r1) ← (PC) + 4, (PC) ← (PC) - 4
```
</center>
