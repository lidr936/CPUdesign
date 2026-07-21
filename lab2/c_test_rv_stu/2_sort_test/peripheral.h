#ifndef PERIPHERAL_H
#define PERIPHERAL_H

typedef unsigned long long time_l;

#define CPU_CLK_FREQ 50     // MHz
#define CLKS_PER_SEC (1000000 * CPU_CLK_FREQ)

time_l get_time(void);

void delay_ms(int ms);

void uart_init();

int printf(const char *format, ...);

#define SCAN_BUF_SIZE 128
int scanf(const char *format, ...);

#endif
