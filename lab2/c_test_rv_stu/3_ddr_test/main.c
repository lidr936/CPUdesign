#define DDR_BASE    0x20000000
#define DDR_SIZE    0x8000000   // 512MB = 128M * 32bit
#define TEST_SIZE   0x10000

#define SW_BASE     0xFFFF0000
#define LED_BASE    0xFFFF1000
#define DIGLED_BASE 0xFFFF2000

volatile unsigned int *mem_ddr     = (volatile unsigned int*)DDR_BASE;
volatile unsigned int *peri_sw     = (volatile unsigned int*)SW_BASE;
volatile unsigned int *peri_led    = (volatile unsigned int*)LED_BASE;
volatile unsigned int *peri_digled = (volatile unsigned int*)DIGLED_BASE;

// int main()
// {
//     for (unsigned int i = 0; i < DDR_SIZE; i++)
//         mem_ddr[i] = DDR_SIZE - i;

//     *peri_led = 0x1;    // 写操作结束亮最低位绿灯

//     // DDR数据正确性校验
//     unsigned int err = 0;
//     for (unsigned int i = 0; i < DDR_SIZE; i++)
//         if (mem_ddr[i] != (DDR_SIZE - i))
//         {
//             err = 1;
//             break;
//         }

//     // 校验失败亮最高位红灯; 校验成功亮次低位绿灯
//     *peri_led = err ? 0x800001 : 0x3;

//     // 以拨码开关为字地址读取DDR数据并显示
//     while (1)
//     {
//         unsigned int addr = *peri_sw;
//         unsigned int data = mem_ddr[addr];
//         *peri_digled = data;
//     }
// }

// 基于LFSR生成伪随机数
unsigned int lfsr = 0xACE1u;
unsigned int my_rand()
{
    unsigned int bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
    return lfsr = (lfsr >> 1) | (bit << 15);
}

void error_signal(int code)
{
    *peri_led = 0x800000 | code; // 最高位红灯，低位显示错误代码
    while(1);
}

int main()
{
    // Phase 0: 写后读测试
    for (int i = 0; i < TEST_SIZE; i++)
    {
        unsigned int val = i + 0xDEADBEEF;
        mem_ddr[i] = val;

        if (mem_ddr[i] != val)
        {
            *peri_digled = mem_ddr[i];  // 数码管显示错值
            error_signal(0x1);
        }
    }

    *peri_led = 0x1;    // Phase 0 Passed

    // Phase 1: 字节/半字写测试
    volatile unsigned char *mem_ddr_b = (volatile unsigned char*)DDR_BASE;
    unsigned int base_addr = 0x0 + TEST_SIZE; 
    
    for (int i = 0; i < TEST_SIZE; i++)
    {
        unsigned int  val = i + 0xDEADBEEF;
        mem_ddr_b[(base_addr + i)*4 + 0] = val & 0xFF;
        mem_ddr_b[(base_addr + i)*4 + 1] = (val >>  8) & 0xFF;
        mem_ddr_b[(base_addr + i)*4 + 2] = (val >> 16) & 0xFF;
        mem_ddr_b[(base_addr + i)*4 + 3] = (val >> 24) & 0xFF;

        if (mem_ddr[base_addr + i] != val)
        {
            *peri_digled = mem_ddr[base_addr + i];  // 数码管显示错值
            error_signal(0x2);
        }
    }

    *peri_led = 0x3;    // Phase 1 Passed

    // Phase 2: 随机访存
    base_addr = TEST_SIZE + TEST_SIZE; 
    for (int i = 0; i < TEST_SIZE; i++)
    {
        unsigned int val = i ^ 0x55AA55AA;

        unsigned int idx = my_rand() % 4096;
        mem_ddr[base_addr + idx] = val;

        if (mem_ddr[base_addr + idx] != val)
        {
            *peri_digled = base_addr + idx; // 数码管显示错误地址
            error_signal(0x4);
        }
    }

    *peri_led = 0x7;    // Phase 2 Passed
}
