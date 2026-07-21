#define SW_BASE   0xFFFF0000
#define LED_BASE  0xFFFF1000
#define DLED_BASE 0xFFFF2000
#define UART_BASE 0xFFFF3000

volatile unsigned int *peri_sw     = (volatile unsigned int*) SW_BASE;
volatile unsigned int *peri_led    = (volatile unsigned int*) LED_BASE;
volatile unsigned int *peri_digled = (volatile unsigned int*) DLED_BASE;

/*  | offset | registers        |       | stat_reg | description             |      | ctrl_reg | description      |
    |--------+------------------+       |----------+-------------------------|      |----------+------------------|
    |  0x00  | rx fifo          |       | bit3     | 1: tx fifo is full      |      | bit1     | 1: clear rx fifo |
    |  0x04  | tx fifo          |       | bit2     | 1: tx fifo is empty     |      | bit0     | 1: clear tx fifo |
    |  0x08  | status register  |       | bit1     | 1: rx fifo is full      |
    |  0x0C  | control register |       | bit0     | 1: rx fifo is not empty |
*/

volatile unsigned int *uart_rx_fifo  = (volatile unsigned int*) UART_BASE;
volatile unsigned int *uart_tx_fifo  = (volatile unsigned int*)(UART_BASE + 0x4);
volatile unsigned int *uart_stat_reg = (volatile unsigned int*)(UART_BASE + 0x8);
volatile unsigned int *uart_ctrl_reg = (volatile unsigned int*)(UART_BASE + 0xC);

void uart_init()
{
    *uart_ctrl_reg = 0x3;
}

void uart_putc(char c)
{
    while (*uart_stat_reg & (1u << 3)); // 如果 TX FIFO 已满，则等待已有字符发送完毕
    *uart_tx_fifo = (unsigned int)c;    // 写入新的字符到TX FIFO
}

char uart_getc(void)
{
    while (!(*uart_stat_reg & 1u));     // 如果 RX FIFO 为空, 则等待接收上位机的字符
    return *uart_rx_fifo;               // 从RX FIFO读取一个字符
}

void print_str(char* str)
{
    while (*str) uart_putc(*str++);
}

int main()
{
    uart_init();

    print_str("2024311270 Test #0 - UART simple test:\n\r");
    print_str("<Phase 0> - Output test:\n\r");
    print_str("Hello World!\n\r");

    print_str("\n\r<Phase 1> - Input test:\n\r");
    char ch;
    while (1)
    {
        print_str("Enter a char: ");
        ch = uart_getc();

        print_str("Input received: ");
        uart_putc(ch);
        print_str("\n\r");

        // 在数码管和LED显示字符的ASCII码
        *peri_led = ch;
        *peri_digled = ch;

        // 拨码开关为0时结束测试
        if (*peri_sw == 0)
        {
            print_str("Test ended.");
            break;
        }
    }

    return 0;
}
