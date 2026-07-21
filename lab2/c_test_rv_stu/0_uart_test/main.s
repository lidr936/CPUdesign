
main:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <_start>:
   0:	00026137          	lui	sp,0x26
   4:	80010113          	addi	sp,sp,-2048 # 25800 <_stack_top>
   8:	1ac000ef          	jal	ra,1b4 <main>
   c:	0000006f          	jal	zero,c <_start+0xc>
  10:	00000013          	addi	zero,zero,0

00000014 <_sbrk>:
  14:	fd010113          	addi	sp,sp,-48
  18:	02112623          	sw	ra,44(sp)
  1c:	02812423          	sw	s0,40(sp)
  20:	03010413          	addi	s0,sp,48
  24:	fca42e23          	sw	a0,-36(s0)
  28:	0000d7b7          	lui	a5,0xd
  2c:	8c47a783          	lw	a5,-1852(a5) # c8c4 <heap_end.0>
  30:	fef42623          	sw	a5,-20(s0)
  34:	00010793          	addi	a5,sp,0
  38:	fef42423          	sw	a5,-24(s0)
  3c:	0000d7b7          	lui	a5,0xd
  40:	8c47a703          	lw	a4,-1852(a5) # c8c4 <heap_end.0>
  44:	fdc42783          	lw	a5,-36(s0)
  48:	00f707b3          	add	a5,a4,a5
  4c:	fe842703          	lw	a4,-24(s0)
  50:	00f77663          	bgeu	a4,a5,5c <_sbrk+0x48>
  54:	fff00793          	addi	a5,zero,-1
  58:	0200006f          	jal	zero,78 <_sbrk+0x64>
  5c:	0000d7b7          	lui	a5,0xd
  60:	8c47a703          	lw	a4,-1852(a5) # c8c4 <heap_end.0>
  64:	fdc42783          	lw	a5,-36(s0)
  68:	00f70733          	add	a4,a4,a5
  6c:	0000d7b7          	lui	a5,0xd
  70:	8ce7a223          	sw	a4,-1852(a5) # c8c4 <heap_end.0>
  74:	fec42783          	lw	a5,-20(s0)
  78:	00078513          	addi	a0,a5,0
  7c:	02c12083          	lw	ra,44(sp)
  80:	02812403          	lw	s0,40(sp)
  84:	03010113          	addi	sp,sp,48
  88:	00008067          	jalr	zero,0(ra)

0000008c <uart_init>:
  8c:	ff010113          	addi	sp,sp,-16
  90:	00112623          	sw	ra,12(sp)
  94:	00812423          	sw	s0,8(sp)
  98:	01010413          	addi	s0,sp,16
  9c:	0000d7b7          	lui	a5,0xd
  a0:	8c07a783          	lw	a5,-1856(a5) # c8c0 <uart_ctrl_reg>
  a4:	00300713          	addi	a4,zero,3
  a8:	00e7a023          	sw	a4,0(a5)
  ac:	00000013          	addi	zero,zero,0
  b0:	00c12083          	lw	ra,12(sp)
  b4:	00812403          	lw	s0,8(sp)
  b8:	01010113          	addi	sp,sp,16
  bc:	00008067          	jalr	zero,0(ra)

000000c0 <uart_putc>:
  c0:	fe010113          	addi	sp,sp,-32
  c4:	00112e23          	sw	ra,28(sp)
  c8:	00812c23          	sw	s0,24(sp)
  cc:	02010413          	addi	s0,sp,32
  d0:	00050793          	addi	a5,a0,0
  d4:	fef407a3          	sb	a5,-17(s0)
  d8:	00000013          	addi	zero,zero,0
  dc:	0000d7b7          	lui	a5,0xd
  e0:	8bc7a783          	lw	a5,-1860(a5) # c8bc <uart_stat_reg>
  e4:	0007a783          	lw	a5,0(a5)
  e8:	0087f793          	andi	a5,a5,8
  ec:	fe0798e3          	bne	a5,zero,dc <uart_putc+0x1c>
  f0:	0000d7b7          	lui	a5,0xd
  f4:	8b87a783          	lw	a5,-1864(a5) # c8b8 <uart_tx_fifo>
  f8:	fef44703          	lbu	a4,-17(s0)
  fc:	00e7a023          	sw	a4,0(a5)
 100:	00000013          	addi	zero,zero,0
 104:	01c12083          	lw	ra,28(sp)
 108:	01812403          	lw	s0,24(sp)
 10c:	02010113          	addi	sp,sp,32
 110:	00008067          	jalr	zero,0(ra)

00000114 <uart_getc>:
 114:	ff010113          	addi	sp,sp,-16
 118:	00112623          	sw	ra,12(sp)
 11c:	00812423          	sw	s0,8(sp)
 120:	01010413          	addi	s0,sp,16
 124:	00000013          	addi	zero,zero,0
 128:	0000d7b7          	lui	a5,0xd
 12c:	8bc7a783          	lw	a5,-1860(a5) # c8bc <uart_stat_reg>
 130:	0007a783          	lw	a5,0(a5)
 134:	0017f793          	andi	a5,a5,1
 138:	fe0788e3          	beq	a5,zero,128 <uart_getc+0x14>
 13c:	0000d7b7          	lui	a5,0xd
 140:	8b47a783          	lw	a5,-1868(a5) # c8b4 <uart_rx_fifo>
 144:	0007a783          	lw	a5,0(a5)
 148:	0ff7f793          	andi	a5,a5,255
 14c:	00078513          	addi	a0,a5,0
 150:	00c12083          	lw	ra,12(sp)
 154:	00812403          	lw	s0,8(sp)
 158:	01010113          	addi	sp,sp,16
 15c:	00008067          	jalr	zero,0(ra)

00000160 <print_str>:
 160:	fe010113          	addi	sp,sp,-32
 164:	00112e23          	sw	ra,28(sp)
 168:	00812c23          	sw	s0,24(sp)
 16c:	02010413          	addi	s0,sp,32
 170:	fea42623          	sw	a0,-20(s0)
 174:	01c0006f          	jal	zero,190 <print_str+0x30>
 178:	fec42783          	lw	a5,-20(s0)
 17c:	00178713          	addi	a4,a5,1
 180:	fee42623          	sw	a4,-20(s0)
 184:	0007c783          	lbu	a5,0(a5)
 188:	00078513          	addi	a0,a5,0
 18c:	f35ff0ef          	jal	ra,c0 <uart_putc>
 190:	fec42783          	lw	a5,-20(s0)
 194:	0007c783          	lbu	a5,0(a5)
 198:	fe0790e3          	bne	a5,zero,178 <print_str+0x18>
 19c:	00000013          	addi	zero,zero,0
 1a0:	00000013          	addi	zero,zero,0
 1a4:	01c12083          	lw	ra,28(sp)
 1a8:	01812403          	lw	s0,24(sp)
 1ac:	02010113          	addi	sp,sp,32
 1b0:	00008067          	jalr	zero,0(ra)

000001b4 <main>:
 1b4:	fe010113          	addi	sp,sp,-32
 1b8:	00112e23          	sw	ra,28(sp)
 1bc:	00812c23          	sw	s0,24(sp)
 1c0:	02010413          	addi	s0,sp,32
 1c4:	ec9ff0ef          	jal	ra,8c <uart_init>
 1c8:	0000d7b7          	lui	a5,0xd
 1cc:	80078513          	addi	a0,a5,-2048 # c800 <_etext+0xc574>
 1d0:	f91ff0ef          	jal	ra,160 <print_str>
 1d4:	0000d7b7          	lui	a5,0xd
 1d8:	82c78513          	addi	a0,a5,-2004 # c82c <_etext+0xc5a0>
 1dc:	f85ff0ef          	jal	ra,160 <print_str>
 1e0:	0000d7b7          	lui	a5,0xd
 1e4:	84878513          	addi	a0,a5,-1976 # c848 <_etext+0xc5bc>
 1e8:	f79ff0ef          	jal	ra,160 <print_str>
 1ec:	0000d7b7          	lui	a5,0xd
 1f0:	85878513          	addi	a0,a5,-1960 # c858 <_etext+0xc5cc>
 1f4:	f6dff0ef          	jal	ra,160 <print_str>
 1f8:	0000d7b7          	lui	a5,0xd
 1fc:	87478513          	addi	a0,a5,-1932 # c874 <_etext+0xc5e8>
 200:	f61ff0ef          	jal	ra,160 <print_str>
 204:	f11ff0ef          	jal	ra,114 <uart_getc>
 208:	00050793          	addi	a5,a0,0
 20c:	fef407a3          	sb	a5,-17(s0)
 210:	0000d7b7          	lui	a5,0xd
 214:	88478513          	addi	a0,a5,-1916 # c884 <_etext+0xc5f8>
 218:	f49ff0ef          	jal	ra,160 <print_str>
 21c:	fef44783          	lbu	a5,-17(s0)
 220:	00078513          	addi	a0,a5,0
 224:	e9dff0ef          	jal	ra,c0 <uart_putc>
 228:	0000d7b7          	lui	a5,0xd
 22c:	89878513          	addi	a0,a5,-1896 # c898 <_etext+0xc60c>
 230:	f31ff0ef          	jal	ra,160 <print_str>
 234:	0000d7b7          	lui	a5,0xd
 238:	8ac7a783          	lw	a5,-1876(a5) # c8ac <peri_led>
 23c:	fef44703          	lbu	a4,-17(s0)
 240:	00e7a023          	sw	a4,0(a5)
 244:	0000d7b7          	lui	a5,0xd
 248:	8b07a783          	lw	a5,-1872(a5) # c8b0 <peri_digled>
 24c:	fef44703          	lbu	a4,-17(s0)
 250:	00e7a023          	sw	a4,0(a5)
 254:	0000d7b7          	lui	a5,0xd
 258:	8a87a783          	lw	a5,-1880(a5) # c8a8 <peri_sw>
 25c:	0007a783          	lw	a5,0(a5)
 260:	f8079ce3          	bne	a5,zero,1f8 <main+0x44>
 264:	0000d7b7          	lui	a5,0xd
 268:	89c78513          	addi	a0,a5,-1892 # c89c <_etext+0xc610>
 26c:	ef5ff0ef          	jal	ra,160 <print_str>
 270:	00000013          	addi	zero,zero,0
 274:	00000793          	addi	a5,zero,0
 278:	00078513          	addi	a0,a5,0
 27c:	01c12083          	lw	ra,28(sp)
 280:	01812403          	lw	s0,24(sp)
 284:	02010113          	addi	sp,sp,32
 288:	00008067          	jalr	zero,0(ra)

Disassembly of section .rodata:

0000c800 <.rodata>:
    c800:	34323032          	.word	0x34323032
    c804:	32313133          	.word	0x32313133
    c808:	54203037          	.word	0x54203037
    c80c:	20747365          	.word	0x20747365
    c810:	2d203023          	.word	0x2d203023
    c814:	52415520          	.word	0x52415520
    c818:	69732054          	.word	0x69732054
    c81c:	656c706d          	.word	0x656c706d
    c820:	73657420          	.word	0x73657420
    c824:	0d0a3a74          	.word	0x0d0a3a74
    c828:	00000000          	.word	0x00000000
    c82c:	6168503c          	.word	0x6168503c
    c830:	30206573          	.word	0x30206573
    c834:	202d203e          	.word	0x202d203e
    c838:	7074754f          	.word	0x7074754f
    c83c:	74207475          	.word	0x74207475
    c840:	3a747365          	.word	0x3a747365
    c844:	00000d0a          	.word	0x00000d0a
    c848:	6c6c6548          	.word	0x6c6c6548
    c84c:	6f57206f          	.word	0x6f57206f
    c850:	21646c72          	.word	0x21646c72
    c854:	00000d0a          	.word	0x00000d0a
    c858:	503c0d0a          	.word	0x503c0d0a
    c85c:	65736168          	.word	0x65736168
    c860:	203e3120          	.word	0x203e3120
    c864:	6e49202d          	.word	0x6e49202d
    c868:	20747570          	.word	0x20747570
    c86c:	74736574          	.word	0x74736574
    c870:	000d0a3a          	.word	0x000d0a3a
    c874:	65746e45          	.word	0x65746e45
    c878:	20612072          	.word	0x20612072
    c87c:	72616863          	.word	0x72616863
    c880:	0000203a          	.word	0x0000203a
    c884:	75706e49          	.word	0x75706e49
    c888:	65722074          	.word	0x65722074
    c88c:	76696563          	.word	0x76696563
    c890:	203a6465          	.word	0x203a6465
    c894:	00000000          	.word	0x00000000
    c898:	00000d0a          	.word	0x00000d0a
    c89c:	74736554          	.word	0x74736554
    c8a0:	646e6520          	.word	0x646e6520
    c8a4:	002e6465          	.word	0x002e6465

Disassembly of section .sdata:

0000c8a8 <peri_sw>:
    c8a8:	ffff0000                                ....

0000c8ac <peri_led>:
    c8ac:	ffff1000                                ....

0000c8b0 <peri_digled>:
    c8b0:	ffff2000                                . ..

0000c8b4 <uart_rx_fifo>:
    c8b4:	ffff3000                                .0..

0000c8b8 <uart_tx_fifo>:
    c8b8:	ffff3004                                .0..

0000c8bc <uart_stat_reg>:
    c8bc:	ffff3008                                .0..

0000c8c0 <uart_ctrl_reg>:
    c8c0:	ffff300c                                .0..

0000c8c4 <heap_end.0>:
    c8c4:	00019000                                ....
