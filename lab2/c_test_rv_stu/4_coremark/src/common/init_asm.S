//
	.section .init
	.globl _start
	.type _start,@function

_start:
	lui  sp, %hi(_stack_top)
	addi sp, sp, %lo(_stack_top)

	lui  t0, 0xFFFF3
	ori  t1, zero, 0x3
	sw   t1, 0xC(t0)

	call main
1: 	j    1b
