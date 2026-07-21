#ifndef PERIPHERAL_H
#define PERIPHERAL_H

void uart_init();

int printf(const char *format, ...);

#define SCAN_BUF_SIZE 128
int scanf(const char *format, ...);

#endif
