## 1. 单周期指令的时序

&emsp;&emsp;在模板工程中，单周期CPU的取指逻辑是：（1）复位信号撤销时，通过检测复位信号下降沿发出首次取指；（2）一条指令执行完毕之后，发出下一条指令的取指请求，如下列代码所示。

```verilog title="cpu_core.v" linenums="85"
// 复位信号发生边沿变化时首次取指; 当前指令执行完毕后取下一条指令
assign ifetch_req  = first_req | inst_finished_r;
assign ifetch_addr = pc;
```

&emsp;&emsp;单周期指令，指的是取到指令机器码之后，能够在一个时钟周期之内执行完毕的指令，比如加法指令、分支跳转指令等。这些指令的时序如图9-1所示。

<center><img src = "../assets/9-1.png" width = 420></center>
<center>图9-1 单周期指令时序图</center>

!!! info "时序解读 :teacher:"
    - 【*clk0*】`ifetch_req`有效，表示此刻CPU发出了某条指令的取指请求。  
    - 【*clk1*】`ifetch_valid`有效，表示指令存储器返回了上一次取指请求所对应的指令机器码。假设该指令是单周期    
    &emsp;&emsp;&emsp;&ensp;指令，则指令在当前的时钟周期执行完毕，因此 **指令执行完毕的标志位信号`inst_finished`** 有效。  
    - 【*clk2*】`inst_finished_r`是`inst_finished`经过CPU时钟打一拍之后得到的信号。根据上文所述的取指逻辑，  
    &emsp;&emsp;&emsp;&ensp;此时`inst_finished_r`有效，故CPU发出下一条指令的取指请求。



## 2. 多周期指令的时序

&emsp;&emsp;多周期指令，指的是取到指令机器码之后，不能在一个时钟周期之内执行完毕的指令，比如访存指令、乘除法指令。

&emsp;&emsp;访存指令的时序如图9-2所示。

<center><img src = "../assets/9-2.png" width = 580></center>
<center>图9-2 多周期指令时序图</center>

!!! info "时序解读 :teacher:"
    - 【*clk0*】`ifetch_req`有效，表示此刻CPU发出了某条指令的取指请求。  
    - 【*clk1*】`ifetch_valid`有效，表示指令已取到。此时，CPU通过译码，检测到当前指令是访存指令。  
    - 【*clk2*】CPU发出访存请求，同时访存标志位信号`ld_st_flag`有效。    
    - 【*clk3*】若干个时钟后，访存操作完成，此时`ld_st_done`信号有效。CPU检测到`ld_st_flag`和`ld_st_done`同时    
    &emsp;&emsp;&emsp;&ensp;有效时，指令执行完毕，故`inst_finished`有效。  

&emsp;&emsp;乘除法指令的时序与访存指令类似，如图9-3所示。

<center><img src = "../assets/9-3.png" width = 580></center>
<center>图9-3 多周期指令时序图</center>

!!! info "时序解读 :teacher:"
    - 【*clk0*】`ifetch_req`有效，表示此刻CPU发出了某条指令的取指请求。  
    - 【*clk1*】`ifetch_valid`有效，表示指令已取到。此时，CPU通过译码，检测到该指令是乘除法指令，乘除法器的  
    &emsp;&emsp;&emsp;&ensp;启动信号`start`被拉高。  
    - 【*clk2*】乘除法标志位信号`mul_div_flag`有效，同时`mul_div_busy`信号被乘除法器拉高。    
    - 【*clk3*】若干个时钟后，乘除法运算完成，此时`mul_div_busy`从高电平变成低电平。CPU检测到`mul_div_flag`    
    &emsp;&emsp;&emsp;&ensp;有效且`mul_div_busy`无效时，指令执行完毕，故`inst_finished`有效。  
