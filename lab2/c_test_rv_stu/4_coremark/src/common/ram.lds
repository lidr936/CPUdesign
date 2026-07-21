/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.
*/
OUTPUT_ARCH( "riscv" )

ENTRY( _start )

MEMORY
{
    rom  : ORIGIN = 0x00000000, LENGTH = 50K   /* IROM: .text */
    ram1 : ORIGIN = 0x0000C800, LENGTH = 50K   /* DRAM: .data, .rodata, etc. */
    ram2 : ORIGIN = 0x00019000, LENGTH = 50K   /* DRAM: HEAP and STACK */
}

SECTIONS
{
    /* 代码段：放置在 ROM 开头 */
    .text : {
        *(.init)
        *(.text)
        *(.text.*)
        _etext = .;     /* 代码段结束标记，用于复制 .data */
    } > rom

    /* 只读数据段：放在 RAM */
    .rodata : {
        *(.rodata)
        *(.rodata.*)
    } > ram1

    /* 数据段 */
    .data : {
        _data_start = .;
        *(.data)
        *(.data.*)
        _data_end = .;
    } > ram1

    /* BSS 段：零初始化，在 RAM 中 */
    .bss : {
        _bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        _bss_end = .;
    } > ram1

    _end = .; /* 标记初始数据的结束 */
    _heap_start = ORIGIN(ram2); /* 堆的起始地址 */
    _stack_top = ORIGIN(ram2) + LENGTH(ram2); /* 栈底 */
}
