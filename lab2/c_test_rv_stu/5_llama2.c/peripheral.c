#define TIMER_BASE  0xFFFF4000

/*  | offset | read op               | write op      |
    |--------+-----------------------+---------------|
    | 0x00   | read timer (low 32b)  | undefined     |
    | 0x08   | read timer (high 32b) | undefined     |
*/

// read op
volatile unsigned int *timer_low  = (volatile unsigned int*) TIMER_BASE;
volatile unsigned int *timer_high = (volatile unsigned int*)(TIMER_BASE + 8);

#define UART_BASE 0xFFFF3000

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

#define RX_FIFO_SIZE  512

static char rx_buf[RX_FIFO_SIZE];
static int rx_buf_cnt = 0;          // 缓冲区中的有效字符个数
static int rx_buf_ptr = 0;          // 当前读取到的缓冲区的位置

void uart_init()
{
    *uart_ctrl_reg = 0x3;
    rx_buf_cnt = 0;
    rx_buf_ptr = 0;
}

void uart_putc(char c)
{
    while (*uart_stat_reg & (1u << 3)); // 如果 TX FIFO 已满，则等待已有字符发送完毕
    *uart_tx_fifo = (unsigned int)c;    // 写入新的字符到TX FIFO
}

static char uart_getc(void)
{
    if (rx_buf_ptr >= rx_buf_cnt)
    {
        rx_buf_ptr = 0;
        rx_buf_cnt = 0;

        while (!(*uart_stat_reg & 1u)); // 如果 RX FIFO 为空, 则等待接收上位机的字符

        // 只要 RX FIFO 非空且 rx_buf 未满，则不断读取 RX FIFO 中的字符到 rx_buf 中
        while ((*uart_stat_reg & 1u) && rx_buf_cnt < RX_FIFO_SIZE)
            rx_buf[rx_buf_cnt++] = *uart_rx_fifo;
    }

    return rx_buf[rx_buf_ptr++];
}

#include <stdarg.h>
#include "peripheral.h"

time_l get_time(void)
{
    time_l t_l = *timer_low;
    time_l t_h = *timer_high;
    return (t_h << 32) | (t_l & 0x00000000FFFFFFFFLL);
}

static void print_char(char c)
{
    uart_putc(c);
    if (c == '\n') uart_putc('\r');
}

static void print_string(const char *s)
{
    while (*s) print_char(*s++);
}

static void print_number(unsigned int num, unsigned int base, int is_signed)
{
    char buffer[32];
    char *ptr = buffer;
    char digits[] = "0123456789ABCDEF";
    
    if (is_signed && (int)num < 0)
    {
        print_char('-');
        num = -(int)num;
    }
    
    do
    {
        *ptr++ = digits[num % base];
        num /= base;
    } while (num > 0);
    
    while (ptr > buffer) print_char(*--ptr);
}

static void print_float(float num, int precision)
{
    if (precision < 0 || precision > 6) precision = 6;
    
    if (num < 0)
    {
        uart_putc('-');
        num = -num;
    }

    float tmp = num * 1000000;
    unsigned int integer_part = (unsigned int)num;
    unsigned int fractional_part = (unsigned int)tmp - integer_part*1000000;
    
    print_number(integer_part, 10, 0);
    
    if (precision > 0 || fractional_part > 0) uart_putc('.');
    
    char fractional_str[7] = { '\0' };
    for (int i = 5; i >= 0; i--)
    {
        fractional_str[i] = '0' + (fractional_part % 10);
        fractional_part /= 10;
    }
    fractional_str[precision] = '\0';
    print_string(fractional_str);
}

int vprintf(const char *format, va_list ap)
{
    const char *p = format;
    char c;
    
    while ((c = *p++) != '\0')
    {
        if (c != '%')
        {
            print_char(c);
            continue;
        }
        
        c = *p++;
        switch (c)
        {
            case 'c': { print_char((char)va_arg(ap, int));                  break; }
            case 's': { print_string(va_arg(ap, char*));                    break; }
            case 'd': { print_number((unsigned int)va_arg(ap, int), 10, 1); break; }
            case 'u': { print_number(va_arg(ap, unsigned int), 10, 0);      break; }
            case 'x': { print_number(va_arg(ap, unsigned int), 16, 0);      break; }
            case 'f': { print_float((float)va_arg(ap, double), 6);          break; }
            case '%': { print_char('%');                                    break; }
            default : { print_char('%'); print_char(c);                     break; }
        }
    }

    return 0;
}

int printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = vprintf(format, ap);
    va_end(ap);
    return ret;
}

static void readline(char *buf, int max_len)
{
    char *p = buf;
    char c;
    while (1)
    {
        c = uart_getc();
        if (c == '\r' || c == '\n')
        {
            print_char('\n');
            *p = '\0';
            return;
        }
        else if ((c == '\b' || c == 127) && p > buf) // 退格键
        {
            p--;
            print_char('\b'); // 光标后退
            print_char(' ');
            print_char('\b');
        }
        else if ((p - buf) < (max_len - 1))
        {
            print_char(c); // 回显字符
            *p++ = c;
        }
    }
}

static int str2int(const char **s)
{
    const char *p = *s;
    int val = 0;
    int sign = 1;

    while (*p == ' ' || *p == '\t') p++;

    if (*p == '-')
    {
        sign = -1;
        p++;
    }
    else if (*p == '+')
        p++;

    while (*p >= '0' && *p <= '9')
    {
        val = (val << 3) + (val << 1) + (*p - '0');
        p++;
    }
    *s = p;
    return val * sign;
}

int vscanf(const char *format, va_list ap)
{
    static char input_buffer[SCAN_BUF_SIZE];
    static char *input_ptr = 0;
    static int buffer_filled = 0;

    while (*input_ptr == ' ' || *input_ptr == '\t' || *input_ptr == '\n') input_ptr++;
    if (input_ptr == 0 || *input_ptr == '\0')
    {
        readline(input_buffer, SCAN_BUF_SIZE);
        input_ptr = input_buffer;
        buffer_filled = 1;
    }

    const char *p_fmt = format;
    int count = 0;

    while (*p_fmt)
    {
        if (*p_fmt == '%')
        {
            p_fmt++;
            while (*input_ptr == ' ' || *input_ptr == '\t' || *input_ptr == '\n') input_ptr++;
            if (*input_ptr == '\0') break;

            switch (*p_fmt)
            {
                case 'd':
                {
                    int *val = va_arg(ap, int *);
                    *val = str2int((const char**)&input_ptr);
                    count++;
                    break;
                }
                case 'c':
                {
                    char *c = va_arg(ap, char *);
                    *c = *input_ptr++;
                    count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(ap, char*);
                    while (*input_ptr && *input_ptr != '\t' && *input_ptr != '\n' && *input_ptr != '\r')
                        *s++ = *input_ptr++;
                    *s = '\0';
                    count++;
                    break;
                }
                case '%':
                {
                    if (*input_ptr++ != '%') return count;
                    break;
                }
                default: return count;
            }
        }
        else if (*p_fmt == ' ' || *p_fmt == '\t' || *p_fmt == '\n')
            while (*input_ptr == ' ' || *input_ptr == '\t' || *input_ptr == '\n') input_ptr++;
        else
        {
            if (*p_fmt != *input_ptr) break;
            input_ptr++;
        }
        p_fmt++;
    }

    return count;
}

int scanf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = vscanf(format, ap);
    va_end(ap);
    return ret;
}
