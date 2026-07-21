
main:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <_start>:
       0:	00026137          	lui	sp,0x26
       4:	80010113          	addi	sp,sp,-2048 # 25800 <_stack_top>
       8:	084000ef          	jal	ra,8c <main>
       c:	0000006f          	jal	zero,c <_start+0xc>
      10:	00000013          	addi	zero,zero,0

00000014 <_sbrk>:
      14:	fd010113          	addi	sp,sp,-48
      18:	02112623          	sw	ra,44(sp)
      1c:	02812423          	sw	s0,40(sp)
      20:	03010413          	addi	s0,sp,48
      24:	fca42e23          	sw	a0,-36(s0)
      28:	0000d7b7          	lui	a5,0xd
      2c:	aa87a783          	lw	a5,-1368(a5) # caa8 <heap_end.0>
      30:	fef42623          	sw	a5,-20(s0)
      34:	00010793          	addi	a5,sp,0
      38:	fef42423          	sw	a5,-24(s0)
      3c:	0000d7b7          	lui	a5,0xd
      40:	aa87a703          	lw	a4,-1368(a5) # caa8 <heap_end.0>
      44:	fdc42783          	lw	a5,-36(s0)
      48:	00f707b3          	add	a5,a4,a5
      4c:	fe842703          	lw	a4,-24(s0)
      50:	00f77663          	bgeu	a4,a5,5c <_sbrk+0x48>
      54:	fff00793          	addi	a5,zero,-1
      58:	0200006f          	jal	zero,78 <_sbrk+0x64>
      5c:	0000d7b7          	lui	a5,0xd
      60:	aa87a703          	lw	a4,-1368(a5) # caa8 <heap_end.0>
      64:	fdc42783          	lw	a5,-36(s0)
      68:	00f70733          	add	a4,a4,a5
      6c:	0000d7b7          	lui	a5,0xd
      70:	aae7a423          	sw	a4,-1368(a5) # caa8 <heap_end.0>
      74:	fec42783          	lw	a5,-20(s0)
      78:	00078513          	addi	a0,a5,0
      7c:	02c12083          	lw	ra,44(sp)
      80:	02812403          	lw	s0,40(sp)
      84:	03010113          	addi	sp,sp,48
      88:	00008067          	jalr	zero,0(ra)

0000008c <main>:
      8c:	fa010113          	addi	sp,sp,-96
      90:	04112e23          	sw	ra,92(sp)
      94:	04812c23          	sw	s0,88(sp)
      98:	06010413          	addi	s0,sp,96
      9c:	138000ef          	jal	ra,1d4 <uart_init>
      a0:	0000d7b7          	lui	a5,0xd
      a4:	80078513          	addi	a0,a5,-2048 # c800 <_etext+0xb344>
      a8:	7a4000ef          	jal	ra,84c <printf>
      ac:	0000d7b7          	lui	a5,0xd
      b0:	83478513          	addi	a0,a5,-1996 # c834 <_etext+0xb378>
      b4:	798000ef          	jal	ra,84c <printf>
      b8:	0000d7b7          	lui	a5,0xd
      bc:	9287a703          	lw	a4,-1752(a5) # c928 <_etext+0xb46c>
      c0:	92c7a783          	lw	a5,-1748(a5)
      c4:	00070813          	addi	a6,a4,0
      c8:	00078893          	addi	a7,a5,0
      cc:	0000d7b7          	lui	a5,0xd
      d0:	85878713          	addi	a4,a5,-1960 # c858 <_etext+0xb39c>
      d4:	06300693          	addi	a3,zero,99
      d8:	45600613          	addi	a2,zero,1110
      dc:	07b00593          	addi	a1,zero,123
      e0:	0000d7b7          	lui	a5,0xd
      e4:	86878513          	addi	a0,a5,-1944 # c868 <_etext+0xb3ac>
      e8:	764000ef          	jal	ra,84c <printf>
      ec:	0000d7b7          	lui	a5,0xd
      f0:	87c78513          	addi	a0,a5,-1924 # c87c <_etext+0xb3c0>
      f4:	758000ef          	jal	ra,84c <printf>
      f8:	0000d7b7          	lui	a5,0xd
      fc:	8a078513          	addi	a0,a5,-1888 # c8a0 <_etext+0xb3e4>
     100:	74c000ef          	jal	ra,84c <printf>
     104:	fa840693          	addi	a3,s0,-88
     108:	feb40713          	addi	a4,s0,-21
     10c:	fec40793          	addi	a5,s0,-20
     110:	00070613          	addi	a2,a4,0
     114:	00078593          	addi	a1,a5,0
     118:	0000d7b7          	lui	a5,0xd
     11c:	8e078513          	addi	a0,a5,-1824 # c8e0 <_etext+0xb424>
     120:	581000ef          	jal	ra,ea0 <scanf>
     124:	fec42783          	lw	a5,-20(s0)
     128:	feb44703          	lbu	a4,-21(s0)
     12c:	00070613          	addi	a2,a4,0
     130:	fa840713          	addi	a4,s0,-88
     134:	00070693          	addi	a3,a4,0
     138:	00078593          	addi	a1,a5,0
     13c:	0000d7b7          	lui	a5,0xd
     140:	8ec78513          	addi	a0,a5,-1812 # c8ec <_etext+0xb430>
     144:	708000ef          	jal	ra,84c <printf>
     148:	fa844703          	lbu	a4,-88(s0)
     14c:	06500793          	addi	a5,zero,101
     150:	02f71a63          	bne	a4,a5,184 <main+0xf8>
     154:	fa944703          	lbu	a4,-87(s0)
     158:	06e00793          	addi	a5,zero,110
     15c:	02f71463          	bne	a4,a5,184 <main+0xf8>
     160:	faa44703          	lbu	a4,-86(s0)
     164:	06400793          	addi	a5,zero,100
     168:	00f71e63          	bne	a4,a5,184 <main+0xf8>
     16c:	fab44783          	lbu	a5,-85(s0)
     170:	00079a63          	bne	a5,zero,184 <main+0xf8>
     174:	0000d7b7          	lui	a5,0xd
     178:	91c78513          	addi	a0,a5,-1764 # c91c <_etext+0xb460>
     17c:	6d0000ef          	jal	ra,84c <printf>
     180:	03c0006f          	jal	zero,1bc <main+0x130>
     184:	fec42783          	lw	a5,-20(s0)
     188:	00078713          	addi	a4,a5,0
     18c:	0000d7b7          	lui	a5,0xd
     190:	aa07a783          	lw	a5,-1376(a5) # caa0 <peri_led>
     194:	01f75713          	srli	a4,a4,0x1f
     198:	00e7a023          	sw	a4,0(a5)
     19c:	fec42783          	lw	a5,-20(s0)
     1a0:	41f7d713          	srai	a4,a5,0x1f
     1a4:	00f747b3          	xor	a5,a4,a5
     1a8:	40e787b3          	sub	a5,a5,a4
     1ac:	0000d737          	lui	a4,0xd
     1b0:	aa472703          	lw	a4,-1372(a4) # caa4 <peri_digled>
     1b4:	00f72023          	sw	a5,0(a4)
     1b8:	f41ff06f          	jal	zero,f8 <main+0x6c>
     1bc:	00000793          	addi	a5,zero,0
     1c0:	00078513          	addi	a0,a5,0
     1c4:	05c12083          	lw	ra,92(sp)
     1c8:	05812403          	lw	s0,88(sp)
     1cc:	06010113          	addi	sp,sp,96
     1d0:	00008067          	jalr	zero,0(ra)

000001d4 <uart_init>:
     1d4:	ff010113          	addi	sp,sp,-16
     1d8:	00112623          	sw	ra,12(sp)
     1dc:	00812423          	sw	s0,8(sp)
     1e0:	01010413          	addi	s0,sp,16
     1e4:	0000d7b7          	lui	a5,0xd
     1e8:	ab87a783          	lw	a5,-1352(a5) # cab8 <uart_ctrl_reg>
     1ec:	00300713          	addi	a4,zero,3
     1f0:	00e7a023          	sw	a4,0(a5)
     1f4:	0000d7b7          	lui	a5,0xd
     1f8:	ca07ae23          	sw	zero,-836(a5) # ccbc <rx_buf_cnt>
     1fc:	0000d7b7          	lui	a5,0xd
     200:	cc07a023          	sw	zero,-832(a5) # ccc0 <rx_buf_ptr>
     204:	00000013          	addi	zero,zero,0
     208:	00c12083          	lw	ra,12(sp)
     20c:	00812403          	lw	s0,8(sp)
     210:	01010113          	addi	sp,sp,16
     214:	00008067          	jalr	zero,0(ra)

00000218 <uart_putc>:
     218:	fe010113          	addi	sp,sp,-32
     21c:	00112e23          	sw	ra,28(sp)
     220:	00812c23          	sw	s0,24(sp)
     224:	02010413          	addi	s0,sp,32
     228:	00050793          	addi	a5,a0,0
     22c:	fef407a3          	sb	a5,-17(s0)
     230:	00000013          	addi	zero,zero,0
     234:	0000d7b7          	lui	a5,0xd
     238:	ab47a783          	lw	a5,-1356(a5) # cab4 <uart_stat_reg>
     23c:	0007a783          	lw	a5,0(a5)
     240:	0087f793          	andi	a5,a5,8
     244:	fe0798e3          	bne	a5,zero,234 <uart_putc+0x1c>
     248:	0000d7b7          	lui	a5,0xd
     24c:	ab07a783          	lw	a5,-1360(a5) # cab0 <uart_tx_fifo>
     250:	fef44703          	lbu	a4,-17(s0)
     254:	00e7a023          	sw	a4,0(a5)
     258:	00000013          	addi	zero,zero,0
     25c:	01c12083          	lw	ra,28(sp)
     260:	01812403          	lw	s0,24(sp)
     264:	02010113          	addi	sp,sp,32
     268:	00008067          	jalr	zero,0(ra)

0000026c <uart_getc>:
     26c:	ff010113          	addi	sp,sp,-16
     270:	00112623          	sw	ra,12(sp)
     274:	00812423          	sw	s0,8(sp)
     278:	01010413          	addi	s0,sp,16
     27c:	0000d7b7          	lui	a5,0xd
     280:	cc07a703          	lw	a4,-832(a5) # ccc0 <rx_buf_ptr>
     284:	0000d7b7          	lui	a5,0xd
     288:	cbc7a783          	lw	a5,-836(a5) # ccbc <rx_buf_cnt>
     28c:	08f74463          	blt	a4,a5,314 <uart_getc+0xa8>
     290:	0000d7b7          	lui	a5,0xd
     294:	cc07a023          	sw	zero,-832(a5) # ccc0 <rx_buf_ptr>
     298:	0000d7b7          	lui	a5,0xd
     29c:	ca07ae23          	sw	zero,-836(a5) # ccbc <rx_buf_cnt>
     2a0:	00000013          	addi	zero,zero,0
     2a4:	0000d7b7          	lui	a5,0xd
     2a8:	ab47a783          	lw	a5,-1356(a5) # cab4 <uart_stat_reg>
     2ac:	0007a783          	lw	a5,0(a5)
     2b0:	0017f793          	andi	a5,a5,1
     2b4:	fe0788e3          	beq	a5,zero,2a4 <uart_getc+0x38>
     2b8:	0380006f          	jal	zero,2f0 <uart_getc+0x84>
     2bc:	0000d7b7          	lui	a5,0xd
     2c0:	aac7a783          	lw	a5,-1364(a5) # caac <uart_rx_fifo>
     2c4:	0007a603          	lw	a2,0(a5)
     2c8:	0000d7b7          	lui	a5,0xd
     2cc:	cbc7a783          	lw	a5,-836(a5) # ccbc <rx_buf_cnt>
     2d0:	00178693          	addi	a3,a5,1
     2d4:	0000d737          	lui	a4,0xd
     2d8:	cad72e23          	sw	a3,-836(a4) # ccbc <rx_buf_cnt>
     2dc:	0ff67713          	andi	a4,a2,255
     2e0:	0000d6b7          	lui	a3,0xd
     2e4:	abc68693          	addi	a3,a3,-1348 # cabc <rx_buf>
     2e8:	00f687b3          	add	a5,a3,a5
     2ec:	00e78023          	sb	a4,0(a5)
     2f0:	0000d7b7          	lui	a5,0xd
     2f4:	ab47a783          	lw	a5,-1356(a5) # cab4 <uart_stat_reg>
     2f8:	0007a783          	lw	a5,0(a5)
     2fc:	0017f793          	andi	a5,a5,1
     300:	00078a63          	beq	a5,zero,314 <uart_getc+0xa8>
     304:	0000d7b7          	lui	a5,0xd
     308:	cbc7a703          	lw	a4,-836(a5) # ccbc <rx_buf_cnt>
     30c:	1ff00793          	addi	a5,zero,511
     310:	fae7d6e3          	bge	a5,a4,2bc <uart_getc+0x50>
     314:	0000d7b7          	lui	a5,0xd
     318:	cc07a783          	lw	a5,-832(a5) # ccc0 <rx_buf_ptr>
     31c:	00178693          	addi	a3,a5,1
     320:	0000d737          	lui	a4,0xd
     324:	ccd72023          	sw	a3,-832(a4) # ccc0 <rx_buf_ptr>
     328:	0000d737          	lui	a4,0xd
     32c:	abc70713          	addi	a4,a4,-1348 # cabc <rx_buf>
     330:	00f707b3          	add	a5,a4,a5
     334:	0007c783          	lbu	a5,0(a5)
     338:	00078513          	addi	a0,a5,0
     33c:	00c12083          	lw	ra,12(sp)
     340:	00812403          	lw	s0,8(sp)
     344:	01010113          	addi	sp,sp,16
     348:	00008067          	jalr	zero,0(ra)

0000034c <print_char>:
     34c:	fe010113          	addi	sp,sp,-32
     350:	00112e23          	sw	ra,28(sp)
     354:	00812c23          	sw	s0,24(sp)
     358:	02010413          	addi	s0,sp,32
     35c:	00050793          	addi	a5,a0,0
     360:	fef407a3          	sb	a5,-17(s0)
     364:	fef44783          	lbu	a5,-17(s0)
     368:	00078513          	addi	a0,a5,0
     36c:	eadff0ef          	jal	ra,218 <uart_putc>
     370:	fef44703          	lbu	a4,-17(s0)
     374:	00a00793          	addi	a5,zero,10
     378:	00f71663          	bne	a4,a5,384 <print_char+0x38>
     37c:	00d00513          	addi	a0,zero,13
     380:	e99ff0ef          	jal	ra,218 <uart_putc>
     384:	00000013          	addi	zero,zero,0
     388:	01c12083          	lw	ra,28(sp)
     38c:	01812403          	lw	s0,24(sp)
     390:	02010113          	addi	sp,sp,32
     394:	00008067          	jalr	zero,0(ra)

00000398 <print_string>:
     398:	fe010113          	addi	sp,sp,-32
     39c:	00112e23          	sw	ra,28(sp)
     3a0:	00812c23          	sw	s0,24(sp)
     3a4:	02010413          	addi	s0,sp,32
     3a8:	fea42623          	sw	a0,-20(s0)
     3ac:	01c0006f          	jal	zero,3c8 <print_string+0x30>
     3b0:	fec42783          	lw	a5,-20(s0)
     3b4:	00178713          	addi	a4,a5,1
     3b8:	fee42623          	sw	a4,-20(s0)
     3bc:	0007c783          	lbu	a5,0(a5)
     3c0:	00078513          	addi	a0,a5,0
     3c4:	f89ff0ef          	jal	ra,34c <print_char>
     3c8:	fec42783          	lw	a5,-20(s0)
     3cc:	0007c783          	lbu	a5,0(a5)
     3d0:	fe0790e3          	bne	a5,zero,3b0 <print_string+0x18>
     3d4:	00000013          	addi	zero,zero,0
     3d8:	00000013          	addi	zero,zero,0
     3dc:	01c12083          	lw	ra,28(sp)
     3e0:	01812403          	lw	s0,24(sp)
     3e4:	02010113          	addi	sp,sp,32
     3e8:	00008067          	jalr	zero,0(ra)

000003ec <print_number>:
     3ec:	fa010113          	addi	sp,sp,-96
     3f0:	04112e23          	sw	ra,92(sp)
     3f4:	04812c23          	sw	s0,88(sp)
     3f8:	06010413          	addi	s0,sp,96
     3fc:	faa42623          	sw	a0,-84(s0)
     400:	fab42423          	sw	a1,-88(s0)
     404:	fac42223          	sw	a2,-92(s0)
     408:	fcc40793          	addi	a5,s0,-52
     40c:	fef42623          	sw	a5,-20(s0)
     410:	0000d7b7          	lui	a5,0xd
     414:	93078793          	addi	a5,a5,-1744 # c930 <_etext+0xb474>
     418:	0007a583          	lw	a1,0(a5)
     41c:	0047a603          	lw	a2,4(a5)
     420:	0087a683          	lw	a3,8(a5)
     424:	00c7a703          	lw	a4,12(a5)
     428:	fab42c23          	sw	a1,-72(s0)
     42c:	fac42e23          	sw	a2,-68(s0)
     430:	fcd42023          	sw	a3,-64(s0)
     434:	fce42223          	sw	a4,-60(s0)
     438:	0107c783          	lbu	a5,16(a5)
     43c:	fcf40423          	sb	a5,-56(s0)
     440:	fa442783          	lw	a5,-92(s0)
     444:	02078063          	beq	a5,zero,464 <print_number+0x78>
     448:	fac42783          	lw	a5,-84(s0)
     44c:	0007dc63          	bge	a5,zero,464 <print_number+0x78>
     450:	02d00513          	addi	a0,zero,45
     454:	ef9ff0ef          	jal	ra,34c <print_char>
     458:	fac42783          	lw	a5,-84(s0)
     45c:	40f007b3          	sub	a5,zero,a5
     460:	faf42623          	sw	a5,-84(s0)
     464:	fac42703          	lw	a4,-84(s0)
     468:	fa842783          	lw	a5,-88(s0)
     46c:	02f77733          	remu	a4,a4,a5
     470:	fec42783          	lw	a5,-20(s0)
     474:	00178693          	addi	a3,a5,1
     478:	fed42623          	sw	a3,-20(s0)
     47c:	ff070713          	addi	a4,a4,-16
     480:	00870733          	add	a4,a4,s0
     484:	fc874703          	lbu	a4,-56(a4)
     488:	00e78023          	sb	a4,0(a5)
     48c:	fac42703          	lw	a4,-84(s0)
     490:	fa842783          	lw	a5,-88(s0)
     494:	02f757b3          	divu	a5,a4,a5
     498:	faf42623          	sw	a5,-84(s0)
     49c:	fac42783          	lw	a5,-84(s0)
     4a0:	fc0792e3          	bne	a5,zero,464 <print_number+0x78>
     4a4:	0200006f          	jal	zero,4c4 <print_number+0xd8>
     4a8:	fec42783          	lw	a5,-20(s0)
     4ac:	fff78793          	addi	a5,a5,-1
     4b0:	fef42623          	sw	a5,-20(s0)
     4b4:	fec42783          	lw	a5,-20(s0)
     4b8:	0007c783          	lbu	a5,0(a5)
     4bc:	00078513          	addi	a0,a5,0
     4c0:	e8dff0ef          	jal	ra,34c <print_char>
     4c4:	fcc40793          	addi	a5,s0,-52
     4c8:	fec42703          	lw	a4,-20(s0)
     4cc:	fce7eee3          	bltu	a5,a4,4a8 <print_number+0xbc>
     4d0:	00000013          	addi	zero,zero,0
     4d4:	00000013          	addi	zero,zero,0
     4d8:	05c12083          	lw	ra,92(sp)
     4dc:	05812403          	lw	s0,88(sp)
     4e0:	06010113          	addi	sp,sp,96
     4e4:	00008067          	jalr	zero,0(ra)

000004e8 <print_float>:
     4e8:	fc010113          	addi	sp,sp,-64
     4ec:	02112e23          	sw	ra,60(sp)
     4f0:	02812c23          	sw	s0,56(sp)
     4f4:	04010413          	addi	s0,sp,64
     4f8:	fca42623          	sw	a0,-52(s0)
     4fc:	fcb42423          	sw	a1,-56(s0)
     500:	fc842783          	lw	a5,-56(s0)
     504:	0007c863          	blt	a5,zero,514 <print_float+0x2c>
     508:	fc842703          	lw	a4,-56(s0)
     50c:	00600793          	addi	a5,zero,6
     510:	00e7d663          	bge	a5,a4,51c <print_float+0x34>
     514:	00600793          	addi	a5,zero,6
     518:	fcf42423          	sw	a5,-56(s0)
     51c:	00000593          	addi	a1,zero,0
     520:	fcc42503          	lw	a0,-52(s0)
     524:	1ed000ef          	jal	ra,f10 <__lesf2>
     528:	00050793          	addi	a5,a0,0
     52c:	0007de63          	bge	a5,zero,548 <print_float+0x60>
     530:	02d00513          	addi	a0,zero,45
     534:	ce5ff0ef          	jal	ra,218 <uart_putc>
     538:	fcc42703          	lw	a4,-52(s0)
     53c:	800007b7          	lui	a5,0x80000
     540:	00f747b3          	xor	a5,a4,a5
     544:	fcf42623          	sw	a5,-52(s0)
     548:	0000d7b7          	lui	a5,0xd
     54c:	99c7a583          	lw	a1,-1636(a5) # c99c <_etext+0xb4e0>
     550:	fcc42503          	lw	a0,-52(s0)
     554:	25d000ef          	jal	ra,fb0 <__mulsf3>
     558:	00050793          	addi	a5,a0,0
     55c:	fef42223          	sw	a5,-28(s0)
     560:	fcc42503          	lw	a0,-52(s0)
     564:	55d000ef          	jal	ra,12c0 <__fixunssfsi>
     568:	00050793          	addi	a5,a0,0
     56c:	fef42023          	sw	a5,-32(s0)
     570:	fe442503          	lw	a0,-28(s0)
     574:	54d000ef          	jal	ra,12c0 <__fixunssfsi>
     578:	00050693          	addi	a3,a0,0
     57c:	fe042703          	lw	a4,-32(s0)
     580:	000f47b7          	lui	a5,0xf4
     584:	24078793          	addi	a5,a5,576 # f4240 <_stack_top+0xcea40>
     588:	02f707b3          	mul	a5,a4,a5
     58c:	40f687b3          	sub	a5,a3,a5
     590:	fef42623          	sw	a5,-20(s0)
     594:	00000613          	addi	a2,zero,0
     598:	00a00593          	addi	a1,zero,10
     59c:	fe042503          	lw	a0,-32(s0)
     5a0:	e4dff0ef          	jal	ra,3ec <print_number>
     5a4:	fc842783          	lw	a5,-56(s0)
     5a8:	00f04663          	blt	zero,a5,5b4 <print_float+0xcc>
     5ac:	fec42783          	lw	a5,-20(s0)
     5b0:	00078663          	beq	a5,zero,5bc <print_float+0xd4>
     5b4:	02e00513          	addi	a0,zero,46
     5b8:	c61ff0ef          	jal	ra,218 <uart_putc>
     5bc:	fc042c23          	sw	zero,-40(s0)
     5c0:	fc041e23          	sh	zero,-36(s0)
     5c4:	fc040f23          	sb	zero,-34(s0)
     5c8:	00500793          	addi	a5,zero,5
     5cc:	fef42423          	sw	a5,-24(s0)
     5d0:	06c0006f          	jal	zero,63c <print_float+0x154>
     5d4:	fec42683          	lw	a3,-20(s0)
     5d8:	ccccd7b7          	lui	a5,0xccccd
     5dc:	ccd78793          	addi	a5,a5,-819 # cccccccd <_stack_top+0xccca74cd>
     5e0:	02f6b7b3          	mulhu	a5,a3,a5
     5e4:	0037d713          	srli	a4,a5,0x3
     5e8:	00070793          	addi	a5,a4,0
     5ec:	00279793          	slli	a5,a5,0x2
     5f0:	00e787b3          	add	a5,a5,a4
     5f4:	00179793          	slli	a5,a5,0x1
     5f8:	40f68733          	sub	a4,a3,a5
     5fc:	0ff77793          	andi	a5,a4,255
     600:	03078793          	addi	a5,a5,48
     604:	0ff7f713          	andi	a4,a5,255
     608:	fe842783          	lw	a5,-24(s0)
     60c:	ff078793          	addi	a5,a5,-16
     610:	008787b3          	add	a5,a5,s0
     614:	fee78423          	sb	a4,-24(a5)
     618:	fec42703          	lw	a4,-20(s0)
     61c:	ccccd7b7          	lui	a5,0xccccd
     620:	ccd78793          	addi	a5,a5,-819 # cccccccd <_stack_top+0xccca74cd>
     624:	02f737b3          	mulhu	a5,a4,a5
     628:	0037d793          	srli	a5,a5,0x3
     62c:	fef42623          	sw	a5,-20(s0)
     630:	fe842783          	lw	a5,-24(s0)
     634:	fff78793          	addi	a5,a5,-1
     638:	fef42423          	sw	a5,-24(s0)
     63c:	fe842783          	lw	a5,-24(s0)
     640:	f807dae3          	bge	a5,zero,5d4 <print_float+0xec>
     644:	fc842783          	lw	a5,-56(s0)
     648:	ff078793          	addi	a5,a5,-16
     64c:	008787b3          	add	a5,a5,s0
     650:	fe078423          	sb	zero,-24(a5)
     654:	fd840793          	addi	a5,s0,-40
     658:	00078513          	addi	a0,a5,0
     65c:	d3dff0ef          	jal	ra,398 <print_string>
     660:	00000013          	addi	zero,zero,0
     664:	03c12083          	lw	ra,60(sp)
     668:	03812403          	lw	s0,56(sp)
     66c:	04010113          	addi	sp,sp,64
     670:	00008067          	jalr	zero,0(ra)

00000674 <vprintf>:
     674:	fd010113          	addi	sp,sp,-48
     678:	02112623          	sw	ra,44(sp)
     67c:	02812423          	sw	s0,40(sp)
     680:	03010413          	addi	s0,sp,48
     684:	fca42e23          	sw	a0,-36(s0)
     688:	fcb42c23          	sw	a1,-40(s0)
     68c:	fdc42783          	lw	a5,-36(s0)
     690:	fef42623          	sw	a5,-20(s0)
     694:	1840006f          	jal	zero,818 <vprintf+0x1a4>
     698:	feb44703          	lbu	a4,-21(s0)
     69c:	02500793          	addi	a5,zero,37
     6a0:	00f70a63          	beq	a4,a5,6b4 <vprintf+0x40>
     6a4:	feb44783          	lbu	a5,-21(s0)
     6a8:	00078513          	addi	a0,a5,0
     6ac:	ca1ff0ef          	jal	ra,34c <print_char>
     6b0:	1680006f          	jal	zero,818 <vprintf+0x1a4>
     6b4:	fec42783          	lw	a5,-20(s0)
     6b8:	00178713          	addi	a4,a5,1
     6bc:	fee42623          	sw	a4,-20(s0)
     6c0:	0007c783          	lbu	a5,0(a5)
     6c4:	fef405a3          	sb	a5,-21(s0)
     6c8:	feb44783          	lbu	a5,-21(s0)
     6cc:	02500713          	addi	a4,zero,37
     6d0:	12e78263          	beq	a5,a4,7f4 <vprintf+0x180>
     6d4:	02500713          	addi	a4,zero,37
     6d8:	12e7c463          	blt	a5,a4,800 <vprintf+0x18c>
     6dc:	07800713          	addi	a4,zero,120
     6e0:	12f74063          	blt	a4,a5,800 <vprintf+0x18c>
     6e4:	06300713          	addi	a4,zero,99
     6e8:	10e7cc63          	blt	a5,a4,800 <vprintf+0x18c>
     6ec:	f9d78793          	addi	a5,a5,-99
     6f0:	01500713          	addi	a4,zero,21
     6f4:	10f76663          	bltu	a4,a5,800 <vprintf+0x18c>
     6f8:	00279713          	slli	a4,a5,0x2
     6fc:	0000d7b7          	lui	a5,0xd
     700:	94478793          	addi	a5,a5,-1724 # c944 <_etext+0xb488>
     704:	00f707b3          	add	a5,a4,a5
     708:	0007a783          	lw	a5,0(a5)
     70c:	00078067          	jalr	zero,0(a5)
     710:	fd842783          	lw	a5,-40(s0)
     714:	00478713          	addi	a4,a5,4
     718:	fce42c23          	sw	a4,-40(s0)
     71c:	0007a783          	lw	a5,0(a5)
     720:	0ff7f793          	andi	a5,a5,255
     724:	00078513          	addi	a0,a5,0
     728:	c25ff0ef          	jal	ra,34c <print_char>
     72c:	0ec0006f          	jal	zero,818 <vprintf+0x1a4>
     730:	fd842783          	lw	a5,-40(s0)
     734:	00478713          	addi	a4,a5,4
     738:	fce42c23          	sw	a4,-40(s0)
     73c:	0007a783          	lw	a5,0(a5)
     740:	00078513          	addi	a0,a5,0
     744:	c55ff0ef          	jal	ra,398 <print_string>
     748:	0d00006f          	jal	zero,818 <vprintf+0x1a4>
     74c:	fd842783          	lw	a5,-40(s0)
     750:	00478713          	addi	a4,a5,4
     754:	fce42c23          	sw	a4,-40(s0)
     758:	0007a783          	lw	a5,0(a5)
     75c:	00100613          	addi	a2,zero,1
     760:	00a00593          	addi	a1,zero,10
     764:	00078513          	addi	a0,a5,0
     768:	c85ff0ef          	jal	ra,3ec <print_number>
     76c:	0ac0006f          	jal	zero,818 <vprintf+0x1a4>
     770:	fd842783          	lw	a5,-40(s0)
     774:	00478713          	addi	a4,a5,4
     778:	fce42c23          	sw	a4,-40(s0)
     77c:	0007a783          	lw	a5,0(a5)
     780:	00000613          	addi	a2,zero,0
     784:	00a00593          	addi	a1,zero,10
     788:	00078513          	addi	a0,a5,0
     78c:	c61ff0ef          	jal	ra,3ec <print_number>
     790:	0880006f          	jal	zero,818 <vprintf+0x1a4>
     794:	fd842783          	lw	a5,-40(s0)
     798:	00478713          	addi	a4,a5,4
     79c:	fce42c23          	sw	a4,-40(s0)
     7a0:	0007a783          	lw	a5,0(a5)
     7a4:	00000613          	addi	a2,zero,0
     7a8:	01000593          	addi	a1,zero,16
     7ac:	00078513          	addi	a0,a5,0
     7b0:	c3dff0ef          	jal	ra,3ec <print_number>
     7b4:	0640006f          	jal	zero,818 <vprintf+0x1a4>
     7b8:	fd842783          	lw	a5,-40(s0)
     7bc:	00778793          	addi	a5,a5,7
     7c0:	ff87f793          	andi	a5,a5,-8
     7c4:	00878713          	addi	a4,a5,8
     7c8:	fce42c23          	sw	a4,-40(s0)
     7cc:	0007a703          	lw	a4,0(a5)
     7d0:	0047a783          	lw	a5,4(a5)
     7d4:	00070513          	addi	a0,a4,0
     7d8:	00078593          	addi	a1,a5,0
     7dc:	34d000ef          	jal	ra,1328 <__truncdfsf2>
     7e0:	00050793          	addi	a5,a0,0
     7e4:	00600593          	addi	a1,zero,6
     7e8:	00078513          	addi	a0,a5,0
     7ec:	cfdff0ef          	jal	ra,4e8 <print_float>
     7f0:	0280006f          	jal	zero,818 <vprintf+0x1a4>
     7f4:	02500513          	addi	a0,zero,37
     7f8:	b55ff0ef          	jal	ra,34c <print_char>
     7fc:	01c0006f          	jal	zero,818 <vprintf+0x1a4>
     800:	02500513          	addi	a0,zero,37
     804:	b49ff0ef          	jal	ra,34c <print_char>
     808:	feb44783          	lbu	a5,-21(s0)
     80c:	00078513          	addi	a0,a5,0
     810:	b3dff0ef          	jal	ra,34c <print_char>
     814:	00000013          	addi	zero,zero,0
     818:	fec42783          	lw	a5,-20(s0)
     81c:	00178713          	addi	a4,a5,1
     820:	fee42623          	sw	a4,-20(s0)
     824:	0007c783          	lbu	a5,0(a5)
     828:	fef405a3          	sb	a5,-21(s0)
     82c:	feb44783          	lbu	a5,-21(s0)
     830:	e60794e3          	bne	a5,zero,698 <vprintf+0x24>
     834:	00000793          	addi	a5,zero,0
     838:	00078513          	addi	a0,a5,0
     83c:	02c12083          	lw	ra,44(sp)
     840:	02812403          	lw	s0,40(sp)
     844:	03010113          	addi	sp,sp,48
     848:	00008067          	jalr	zero,0(ra)

0000084c <printf>:
     84c:	fb010113          	addi	sp,sp,-80
     850:	02112623          	sw	ra,44(sp)
     854:	02812423          	sw	s0,40(sp)
     858:	03010413          	addi	s0,sp,48
     85c:	fca42e23          	sw	a0,-36(s0)
     860:	00b42223          	sw	a1,4(s0)
     864:	00c42423          	sw	a2,8(s0)
     868:	00d42623          	sw	a3,12(s0)
     86c:	00e42823          	sw	a4,16(s0)
     870:	00f42a23          	sw	a5,20(s0)
     874:	01042c23          	sw	a6,24(s0)
     878:	01142e23          	sw	a7,28(s0)
     87c:	02040793          	addi	a5,s0,32
     880:	fcf42c23          	sw	a5,-40(s0)
     884:	fd842783          	lw	a5,-40(s0)
     888:	fe478793          	addi	a5,a5,-28
     88c:	fef42423          	sw	a5,-24(s0)
     890:	fe842783          	lw	a5,-24(s0)
     894:	00078593          	addi	a1,a5,0
     898:	fdc42503          	lw	a0,-36(s0)
     89c:	dd9ff0ef          	jal	ra,674 <vprintf>
     8a0:	fea42623          	sw	a0,-20(s0)
     8a4:	fec42783          	lw	a5,-20(s0)
     8a8:	00078513          	addi	a0,a5,0
     8ac:	02c12083          	lw	ra,44(sp)
     8b0:	02812403          	lw	s0,40(sp)
     8b4:	05010113          	addi	sp,sp,80
     8b8:	00008067          	jalr	zero,0(ra)

000008bc <readline>:
     8bc:	fd010113          	addi	sp,sp,-48
     8c0:	02112623          	sw	ra,44(sp)
     8c4:	02812423          	sw	s0,40(sp)
     8c8:	03010413          	addi	s0,sp,48
     8cc:	fca42e23          	sw	a0,-36(s0)
     8d0:	fcb42c23          	sw	a1,-40(s0)
     8d4:	fdc42783          	lw	a5,-36(s0)
     8d8:	fef42623          	sw	a5,-20(s0)
     8dc:	991ff0ef          	jal	ra,26c <uart_getc>
     8e0:	00050793          	addi	a5,a0,0
     8e4:	fef405a3          	sb	a5,-21(s0)
     8e8:	feb44703          	lbu	a4,-21(s0)
     8ec:	00d00793          	addi	a5,zero,13
     8f0:	00f70863          	beq	a4,a5,900 <readline+0x44>
     8f4:	feb44703          	lbu	a4,-21(s0)
     8f8:	00a00793          	addi	a5,zero,10
     8fc:	00f71c63          	bne	a4,a5,914 <readline+0x58>
     900:	00a00513          	addi	a0,zero,10
     904:	a49ff0ef          	jal	ra,34c <print_char>
     908:	fec42783          	lw	a5,-20(s0)
     90c:	00078023          	sb	zero,0(a5)
     910:	08c0006f          	jal	zero,99c <readline+0xe0>
     914:	feb44703          	lbu	a4,-21(s0)
     918:	00800793          	addi	a5,zero,8
     91c:	00f70863          	beq	a4,a5,92c <readline+0x70>
     920:	feb44703          	lbu	a4,-21(s0)
     924:	07f00793          	addi	a5,zero,127
     928:	02f71c63          	bne	a4,a5,960 <readline+0xa4>
     92c:	fec42703          	lw	a4,-20(s0)
     930:	fdc42783          	lw	a5,-36(s0)
     934:	02e7f663          	bgeu	a5,a4,960 <readline+0xa4>
     938:	fec42783          	lw	a5,-20(s0)
     93c:	fff78793          	addi	a5,a5,-1
     940:	fef42623          	sw	a5,-20(s0)
     944:	00800513          	addi	a0,zero,8
     948:	a05ff0ef          	jal	ra,34c <print_char>
     94c:	02000513          	addi	a0,zero,32
     950:	9fdff0ef          	jal	ra,34c <print_char>
     954:	00800513          	addi	a0,zero,8
     958:	9f5ff0ef          	jal	ra,34c <print_char>
     95c:	03c0006f          	jal	zero,998 <readline+0xdc>
     960:	fec42703          	lw	a4,-20(s0)
     964:	fdc42783          	lw	a5,-36(s0)
     968:	40f70733          	sub	a4,a4,a5
     96c:	fd842783          	lw	a5,-40(s0)
     970:	fff78793          	addi	a5,a5,-1
     974:	f6f754e3          	bge	a4,a5,8dc <readline+0x20>
     978:	feb44783          	lbu	a5,-21(s0)
     97c:	00078513          	addi	a0,a5,0
     980:	9cdff0ef          	jal	ra,34c <print_char>
     984:	fec42783          	lw	a5,-20(s0)
     988:	00178713          	addi	a4,a5,1
     98c:	fee42623          	sw	a4,-20(s0)
     990:	feb44703          	lbu	a4,-21(s0)
     994:	00e78023          	sb	a4,0(a5)
     998:	f45ff06f          	jal	zero,8dc <readline+0x20>
     99c:	02c12083          	lw	ra,44(sp)
     9a0:	02812403          	lw	s0,40(sp)
     9a4:	03010113          	addi	sp,sp,48
     9a8:	00008067          	jalr	zero,0(ra)

000009ac <str2int>:
     9ac:	fd010113          	addi	sp,sp,-48
     9b0:	02112623          	sw	ra,44(sp)
     9b4:	02812423          	sw	s0,40(sp)
     9b8:	03010413          	addi	s0,sp,48
     9bc:	fca42e23          	sw	a0,-36(s0)
     9c0:	fdc42783          	lw	a5,-36(s0)
     9c4:	0007a783          	lw	a5,0(a5)
     9c8:	fef42623          	sw	a5,-20(s0)
     9cc:	fe042423          	sw	zero,-24(s0)
     9d0:	00100793          	addi	a5,zero,1
     9d4:	fef42223          	sw	a5,-28(s0)
     9d8:	0100006f          	jal	zero,9e8 <str2int+0x3c>
     9dc:	fec42783          	lw	a5,-20(s0)
     9e0:	00178793          	addi	a5,a5,1
     9e4:	fef42623          	sw	a5,-20(s0)
     9e8:	fec42783          	lw	a5,-20(s0)
     9ec:	0007c703          	lbu	a4,0(a5)
     9f0:	02000793          	addi	a5,zero,32
     9f4:	fef704e3          	beq	a4,a5,9dc <str2int+0x30>
     9f8:	fec42783          	lw	a5,-20(s0)
     9fc:	0007c703          	lbu	a4,0(a5)
     a00:	00900793          	addi	a5,zero,9
     a04:	fcf70ce3          	beq	a4,a5,9dc <str2int+0x30>
     a08:	fec42783          	lw	a5,-20(s0)
     a0c:	0007c703          	lbu	a4,0(a5)
     a10:	02d00793          	addi	a5,zero,45
     a14:	00f71e63          	bne	a4,a5,a30 <str2int+0x84>
     a18:	fff00793          	addi	a5,zero,-1
     a1c:	fef42223          	sw	a5,-28(s0)
     a20:	fec42783          	lw	a5,-20(s0)
     a24:	00178793          	addi	a5,a5,1
     a28:	fef42623          	sw	a5,-20(s0)
     a2c:	0580006f          	jal	zero,a84 <str2int+0xd8>
     a30:	fec42783          	lw	a5,-20(s0)
     a34:	0007c703          	lbu	a4,0(a5)
     a38:	02b00793          	addi	a5,zero,43
     a3c:	04f71463          	bne	a4,a5,a84 <str2int+0xd8>
     a40:	fec42783          	lw	a5,-20(s0)
     a44:	00178793          	addi	a5,a5,1
     a48:	fef42623          	sw	a5,-20(s0)
     a4c:	0380006f          	jal	zero,a84 <str2int+0xd8>
     a50:	fe842783          	lw	a5,-24(s0)
     a54:	00379713          	slli	a4,a5,0x3
     a58:	fe842783          	lw	a5,-24(s0)
     a5c:	00179793          	slli	a5,a5,0x1
     a60:	00f70733          	add	a4,a4,a5
     a64:	fec42783          	lw	a5,-20(s0)
     a68:	0007c783          	lbu	a5,0(a5)
     a6c:	fd078793          	addi	a5,a5,-48
     a70:	00f707b3          	add	a5,a4,a5
     a74:	fef42423          	sw	a5,-24(s0)
     a78:	fec42783          	lw	a5,-20(s0)
     a7c:	00178793          	addi	a5,a5,1
     a80:	fef42623          	sw	a5,-20(s0)
     a84:	fec42783          	lw	a5,-20(s0)
     a88:	0007c703          	lbu	a4,0(a5)
     a8c:	02f00793          	addi	a5,zero,47
     a90:	00e7fa63          	bgeu	a5,a4,aa4 <str2int+0xf8>
     a94:	fec42783          	lw	a5,-20(s0)
     a98:	0007c703          	lbu	a4,0(a5)
     a9c:	03900793          	addi	a5,zero,57
     aa0:	fae7f8e3          	bgeu	a5,a4,a50 <str2int+0xa4>
     aa4:	fdc42783          	lw	a5,-36(s0)
     aa8:	fec42703          	lw	a4,-20(s0)
     aac:	00e7a023          	sw	a4,0(a5)
     ab0:	fe842703          	lw	a4,-24(s0)
     ab4:	fe442783          	lw	a5,-28(s0)
     ab8:	02f707b3          	mul	a5,a4,a5
     abc:	00078513          	addi	a0,a5,0
     ac0:	02c12083          	lw	ra,44(sp)
     ac4:	02812403          	lw	s0,40(sp)
     ac8:	03010113          	addi	sp,sp,48
     acc:	00008067          	jalr	zero,0(ra)

00000ad0 <vscanf>:
     ad0:	fc010113          	addi	sp,sp,-64
     ad4:	02112e23          	sw	ra,60(sp)
     ad8:	02812c23          	sw	s0,56(sp)
     adc:	04010413          	addi	s0,sp,64
     ae0:	fca42623          	sw	a0,-52(s0)
     ae4:	fcb42423          	sw	a1,-56(s0)
     ae8:	0180006f          	jal	zero,b00 <vscanf+0x30>
     aec:	0000d7b7          	lui	a5,0xd
     af0:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     af4:	00178713          	addi	a4,a5,1
     af8:	0000d7b7          	lui	a5,0xd
     afc:	cce7a223          	sw	a4,-828(a5) # ccc4 <input_ptr.2>
     b00:	0000d7b7          	lui	a5,0xd
     b04:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     b08:	0007c703          	lbu	a4,0(a5)
     b0c:	02000793          	addi	a5,zero,32
     b10:	fcf70ee3          	beq	a4,a5,aec <vscanf+0x1c>
     b14:	0000d7b7          	lui	a5,0xd
     b18:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     b1c:	0007c703          	lbu	a4,0(a5)
     b20:	00900793          	addi	a5,zero,9
     b24:	fcf704e3          	beq	a4,a5,aec <vscanf+0x1c>
     b28:	0000d7b7          	lui	a5,0xd
     b2c:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     b30:	0007c703          	lbu	a4,0(a5)
     b34:	00a00793          	addi	a5,zero,10
     b38:	faf70ae3          	beq	a4,a5,aec <vscanf+0x1c>
     b3c:	0000d7b7          	lui	a5,0xd
     b40:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     b44:	00078a63          	beq	a5,zero,b58 <vscanf+0x88>
     b48:	0000d7b7          	lui	a5,0xd
     b4c:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     b50:	0007c783          	lbu	a5,0(a5)
     b54:	02079863          	bne	a5,zero,b84 <vscanf+0xb4>
     b58:	08000593          	addi	a1,zero,128
     b5c:	0000d7b7          	lui	a5,0xd
     b60:	cc878513          	addi	a0,a5,-824 # ccc8 <input_buffer.1>
     b64:	d59ff0ef          	jal	ra,8bc <readline>
     b68:	0000d7b7          	lui	a5,0xd
     b6c:	0000d737          	lui	a4,0xd
     b70:	cc870713          	addi	a4,a4,-824 # ccc8 <input_buffer.1>
     b74:	cce7a223          	sw	a4,-828(a5) # ccc4 <input_ptr.2>
     b78:	0000d7b7          	lui	a5,0xd
     b7c:	00100713          	addi	a4,zero,1
     b80:	d4e7a423          	sw	a4,-696(a5) # cd48 <buffer_filled.0>
     b84:	fcc42783          	lw	a5,-52(s0)
     b88:	fef42623          	sw	a5,-20(s0)
     b8c:	fe042423          	sw	zero,-24(s0)
     b90:	2dc0006f          	jal	zero,e6c <vscanf+0x39c>
     b94:	fec42783          	lw	a5,-20(s0)
     b98:	0007c703          	lbu	a4,0(a5)
     b9c:	02500793          	addi	a5,zero,37
     ba0:	20f71263          	bne	a4,a5,da4 <vscanf+0x2d4>
     ba4:	fec42783          	lw	a5,-20(s0)
     ba8:	00178793          	addi	a5,a5,1
     bac:	fef42623          	sw	a5,-20(s0)
     bb0:	0180006f          	jal	zero,bc8 <vscanf+0xf8>
     bb4:	0000d7b7          	lui	a5,0xd
     bb8:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     bbc:	00178713          	addi	a4,a5,1
     bc0:	0000d7b7          	lui	a5,0xd
     bc4:	cce7a223          	sw	a4,-828(a5) # ccc4 <input_ptr.2>
     bc8:	0000d7b7          	lui	a5,0xd
     bcc:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     bd0:	0007c703          	lbu	a4,0(a5)
     bd4:	02000793          	addi	a5,zero,32
     bd8:	fcf70ee3          	beq	a4,a5,bb4 <vscanf+0xe4>
     bdc:	0000d7b7          	lui	a5,0xd
     be0:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     be4:	0007c703          	lbu	a4,0(a5)
     be8:	00900793          	addi	a5,zero,9
     bec:	fcf704e3          	beq	a4,a5,bb4 <vscanf+0xe4>
     bf0:	0000d7b7          	lui	a5,0xd
     bf4:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     bf8:	0007c703          	lbu	a4,0(a5)
     bfc:	00a00793          	addi	a5,zero,10
     c00:	faf70ae3          	beq	a4,a5,bb4 <vscanf+0xe4>
     c04:	0000d7b7          	lui	a5,0xd
     c08:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     c0c:	0007c783          	lbu	a5,0(a5)
     c10:	26078663          	beq	a5,zero,e7c <vscanf+0x3ac>
     c14:	fec42783          	lw	a5,-20(s0)
     c18:	0007c783          	lbu	a5,0(a5)
     c1c:	07300713          	addi	a4,zero,115
     c20:	0ae78863          	beq	a5,a4,cd0 <vscanf+0x200>
     c24:	07300713          	addi	a4,zero,115
     c28:	16f74a63          	blt	a4,a5,d9c <vscanf+0x2cc>
     c2c:	06400713          	addi	a4,zero,100
     c30:	02e78063          	beq	a5,a4,c50 <vscanf+0x180>
     c34:	06400713          	addi	a4,zero,100
     c38:	16f74263          	blt	a4,a5,d9c <vscanf+0x2cc>
     c3c:	02500713          	addi	a4,zero,37
     c40:	12e78a63          	beq	a5,a4,d74 <vscanf+0x2a4>
     c44:	06300713          	addi	a4,zero,99
     c48:	04e78263          	beq	a5,a4,c8c <vscanf+0x1bc>
     c4c:	1500006f          	jal	zero,d9c <vscanf+0x2cc>
     c50:	fc842783          	lw	a5,-56(s0)
     c54:	00478713          	addi	a4,a5,4
     c58:	fce42423          	sw	a4,-56(s0)
     c5c:	0007a783          	lw	a5,0(a5)
     c60:	fef42023          	sw	a5,-32(s0)
     c64:	0000d7b7          	lui	a5,0xd
     c68:	cc478513          	addi	a0,a5,-828 # ccc4 <input_ptr.2>
     c6c:	d41ff0ef          	jal	ra,9ac <str2int>
     c70:	00050713          	addi	a4,a0,0
     c74:	fe042783          	lw	a5,-32(s0)
     c78:	00e7a023          	sw	a4,0(a5)
     c7c:	fe842783          	lw	a5,-24(s0)
     c80:	00178793          	addi	a5,a5,1
     c84:	fef42423          	sw	a5,-24(s0)
     c88:	1d80006f          	jal	zero,e60 <vscanf+0x390>
     c8c:	fc842783          	lw	a5,-56(s0)
     c90:	00478713          	addi	a4,a5,4
     c94:	fce42423          	sw	a4,-56(s0)
     c98:	0007a783          	lw	a5,0(a5)
     c9c:	fcf42e23          	sw	a5,-36(s0)
     ca0:	0000d7b7          	lui	a5,0xd
     ca4:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     ca8:	00178693          	addi	a3,a5,1
     cac:	0000d737          	lui	a4,0xd
     cb0:	ccd72223          	sw	a3,-828(a4) # ccc4 <input_ptr.2>
     cb4:	0007c703          	lbu	a4,0(a5)
     cb8:	fdc42783          	lw	a5,-36(s0)
     cbc:	00e78023          	sb	a4,0(a5)
     cc0:	fe842783          	lw	a5,-24(s0)
     cc4:	00178793          	addi	a5,a5,1
     cc8:	fef42423          	sw	a5,-24(s0)
     ccc:	1940006f          	jal	zero,e60 <vscanf+0x390>
     cd0:	fc842783          	lw	a5,-56(s0)
     cd4:	00478713          	addi	a4,a5,4
     cd8:	fce42423          	sw	a4,-56(s0)
     cdc:	0007a783          	lw	a5,0(a5)
     ce0:	fef42223          	sw	a5,-28(s0)
     ce4:	02c0006f          	jal	zero,d10 <vscanf+0x240>
     ce8:	0000d7b7          	lui	a5,0xd
     cec:	cc47a703          	lw	a4,-828(a5) # ccc4 <input_ptr.2>
     cf0:	00170693          	addi	a3,a4,1
     cf4:	0000d7b7          	lui	a5,0xd
     cf8:	ccd7a223          	sw	a3,-828(a5) # ccc4 <input_ptr.2>
     cfc:	fe442783          	lw	a5,-28(s0)
     d00:	00178693          	addi	a3,a5,1
     d04:	fed42223          	sw	a3,-28(s0)
     d08:	00074703          	lbu	a4,0(a4)
     d0c:	00e78023          	sb	a4,0(a5)
     d10:	0000d7b7          	lui	a5,0xd
     d14:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     d18:	0007c783          	lbu	a5,0(a5)
     d1c:	04078063          	beq	a5,zero,d5c <vscanf+0x28c>
     d20:	0000d7b7          	lui	a5,0xd
     d24:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     d28:	0007c703          	lbu	a4,0(a5)
     d2c:	00900793          	addi	a5,zero,9
     d30:	02f70663          	beq	a4,a5,d5c <vscanf+0x28c>
     d34:	0000d7b7          	lui	a5,0xd
     d38:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     d3c:	0007c703          	lbu	a4,0(a5)
     d40:	00a00793          	addi	a5,zero,10
     d44:	00f70c63          	beq	a4,a5,d5c <vscanf+0x28c>
     d48:	0000d7b7          	lui	a5,0xd
     d4c:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     d50:	0007c703          	lbu	a4,0(a5)
     d54:	00d00793          	addi	a5,zero,13
     d58:	f8f718e3          	bne	a4,a5,ce8 <vscanf+0x218>
     d5c:	fe442783          	lw	a5,-28(s0)
     d60:	00078023          	sb	zero,0(a5)
     d64:	fe842783          	lw	a5,-24(s0)
     d68:	00178793          	addi	a5,a5,1
     d6c:	fef42423          	sw	a5,-24(s0)
     d70:	0f00006f          	jal	zero,e60 <vscanf+0x390>
     d74:	0000d7b7          	lui	a5,0xd
     d78:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     d7c:	00178693          	addi	a3,a5,1
     d80:	0000d737          	lui	a4,0xd
     d84:	ccd72223          	sw	a3,-828(a4) # ccc4 <input_ptr.2>
     d88:	0007c703          	lbu	a4,0(a5)
     d8c:	02500793          	addi	a5,zero,37
     d90:	0cf70663          	beq	a4,a5,e5c <vscanf+0x38c>
     d94:	fe842783          	lw	a5,-24(s0)
     d98:	0f40006f          	jal	zero,e8c <vscanf+0x3bc>
     d9c:	fe842783          	lw	a5,-24(s0)
     da0:	0ec0006f          	jal	zero,e8c <vscanf+0x3bc>
     da4:	fec42783          	lw	a5,-20(s0)
     da8:	0007c703          	lbu	a4,0(a5)
     dac:	02000793          	addi	a5,zero,32
     db0:	02f70e63          	beq	a4,a5,dec <vscanf+0x31c>
     db4:	fec42783          	lw	a5,-20(s0)
     db8:	0007c703          	lbu	a4,0(a5)
     dbc:	00900793          	addi	a5,zero,9
     dc0:	02f70663          	beq	a4,a5,dec <vscanf+0x31c>
     dc4:	fec42783          	lw	a5,-20(s0)
     dc8:	0007c703          	lbu	a4,0(a5)
     dcc:	00a00793          	addi	a5,zero,10
     dd0:	04f71e63          	bne	a4,a5,e2c <vscanf+0x35c>
     dd4:	0180006f          	jal	zero,dec <vscanf+0x31c>
     dd8:	0000d7b7          	lui	a5,0xd
     ddc:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     de0:	00178713          	addi	a4,a5,1
     de4:	0000d7b7          	lui	a5,0xd
     de8:	cce7a223          	sw	a4,-828(a5) # ccc4 <input_ptr.2>
     dec:	0000d7b7          	lui	a5,0xd
     df0:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     df4:	0007c703          	lbu	a4,0(a5)
     df8:	02000793          	addi	a5,zero,32
     dfc:	fcf70ee3          	beq	a4,a5,dd8 <vscanf+0x308>
     e00:	0000d7b7          	lui	a5,0xd
     e04:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     e08:	0007c703          	lbu	a4,0(a5)
     e0c:	00900793          	addi	a5,zero,9
     e10:	fcf704e3          	beq	a4,a5,dd8 <vscanf+0x308>
     e14:	0000d7b7          	lui	a5,0xd
     e18:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     e1c:	0007c703          	lbu	a4,0(a5)
     e20:	00a00793          	addi	a5,zero,10
     e24:	faf70ae3          	beq	a4,a5,dd8 <vscanf+0x308>
     e28:	0380006f          	jal	zero,e60 <vscanf+0x390>
     e2c:	fec42783          	lw	a5,-20(s0)
     e30:	0007c703          	lbu	a4,0(a5)
     e34:	0000d7b7          	lui	a5,0xd
     e38:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     e3c:	0007c783          	lbu	a5,0(a5)
     e40:	04f71263          	bne	a4,a5,e84 <vscanf+0x3b4>
     e44:	0000d7b7          	lui	a5,0xd
     e48:	cc47a783          	lw	a5,-828(a5) # ccc4 <input_ptr.2>
     e4c:	00178713          	addi	a4,a5,1
     e50:	0000d7b7          	lui	a5,0xd
     e54:	cce7a223          	sw	a4,-828(a5) # ccc4 <input_ptr.2>
     e58:	0080006f          	jal	zero,e60 <vscanf+0x390>
     e5c:	00000013          	addi	zero,zero,0
     e60:	fec42783          	lw	a5,-20(s0)
     e64:	00178793          	addi	a5,a5,1
     e68:	fef42623          	sw	a5,-20(s0)
     e6c:	fec42783          	lw	a5,-20(s0)
     e70:	0007c783          	lbu	a5,0(a5)
     e74:	d20790e3          	bne	a5,zero,b94 <vscanf+0xc4>
     e78:	0100006f          	jal	zero,e88 <vscanf+0x3b8>
     e7c:	00000013          	addi	zero,zero,0
     e80:	0080006f          	jal	zero,e88 <vscanf+0x3b8>
     e84:	00000013          	addi	zero,zero,0
     e88:	fe842783          	lw	a5,-24(s0)
     e8c:	00078513          	addi	a0,a5,0
     e90:	03c12083          	lw	ra,60(sp)
     e94:	03812403          	lw	s0,56(sp)
     e98:	04010113          	addi	sp,sp,64
     e9c:	00008067          	jalr	zero,0(ra)

00000ea0 <scanf>:
     ea0:	fb010113          	addi	sp,sp,-80
     ea4:	02112623          	sw	ra,44(sp)
     ea8:	02812423          	sw	s0,40(sp)
     eac:	03010413          	addi	s0,sp,48
     eb0:	fca42e23          	sw	a0,-36(s0)
     eb4:	00b42223          	sw	a1,4(s0)
     eb8:	00c42423          	sw	a2,8(s0)
     ebc:	00d42623          	sw	a3,12(s0)
     ec0:	00e42823          	sw	a4,16(s0)
     ec4:	00f42a23          	sw	a5,20(s0)
     ec8:	01042c23          	sw	a6,24(s0)
     ecc:	01142e23          	sw	a7,28(s0)
     ed0:	02040793          	addi	a5,s0,32
     ed4:	fcf42c23          	sw	a5,-40(s0)
     ed8:	fd842783          	lw	a5,-40(s0)
     edc:	fe478793          	addi	a5,a5,-28
     ee0:	fef42423          	sw	a5,-24(s0)
     ee4:	fe842783          	lw	a5,-24(s0)
     ee8:	00078593          	addi	a1,a5,0
     eec:	fdc42503          	lw	a0,-36(s0)
     ef0:	be1ff0ef          	jal	ra,ad0 <vscanf>
     ef4:	fea42623          	sw	a0,-20(s0)
     ef8:	fec42783          	lw	a5,-20(s0)
     efc:	00078513          	addi	a0,a5,0
     f00:	02c12083          	lw	ra,44(sp)
     f04:	02812403          	lw	s0,40(sp)
     f08:	05010113          	addi	sp,sp,80
     f0c:	00008067          	jalr	zero,0(ra)

00000f10 <__lesf2>:
     f10:	00800737          	lui	a4,0x800
     f14:	fff70713          	addi	a4,a4,-1 # 7fffff <_stack_top+0x7da7ff>
     f18:	01755693          	srli	a3,a0,0x17
     f1c:	00a77633          	and	a2,a4,a0
     f20:	01f55793          	srli	a5,a0,0x1f
     f24:	0ff6f693          	andi	a3,a3,255
     f28:	0175d513          	srli	a0,a1,0x17
     f2c:	0ff00813          	addi	a6,zero,255
     f30:	00b77733          	and	a4,a4,a1
     f34:	0ff57513          	andi	a0,a0,255
     f38:	01f5d593          	srli	a1,a1,0x1f
     f3c:	01069463          	bne	a3,a6,f44 <__lesf2+0x34>
     f40:	02061e63          	bne	a2,zero,f7c <__lesf2+0x6c>
     f44:	01051463          	bne	a0,a6,f4c <__lesf2+0x3c>
     f48:	02071a63          	bne	a4,zero,f7c <__lesf2+0x6c>
     f4c:	04069863          	bne	a3,zero,f9c <__lesf2+0x8c>
     f50:	02051a63          	bne	a0,zero,f84 <__lesf2+0x74>
     f54:	04061663          	bne	a2,zero,fa0 <__lesf2+0x90>
     f58:	02070063          	beq	a4,zero,f78 <__lesf2+0x68>
     f5c:	00159513          	slli	a0,a1,0x1
     f60:	fff50513          	addi	a0,a0,-1
     f64:	00008067          	jalr	zero,0(ra)
     f68:	fea6cae3          	blt	a3,a0,f5c <__lesf2+0x4c>
     f6c:	02c76263          	bltu	a4,a2,f90 <__lesf2+0x80>
     f70:	00000513          	addi	a0,zero,0
     f74:	fee664e3          	bltu	a2,a4,f5c <__lesf2+0x4c>
     f78:	00008067          	jalr	zero,0(ra)
     f7c:	00200513          	addi	a0,zero,2
     f80:	00008067          	jalr	zero,0(ra)
     f84:	fc060ce3          	beq	a2,zero,f5c <__lesf2+0x4c>
     f88:	00f59e63          	bne	a1,a5,fa4 <__lesf2+0x94>
     f8c:	fcd55ee3          	bge	a0,a3,f68 <__lesf2+0x58>
     f90:	40b005b3          	sub	a1,zero,a1
     f94:	0015e513          	ori	a0,a1,1
     f98:	00008067          	jalr	zero,0(ra)
     f9c:	fe0516e3          	bne	a0,zero,f88 <__lesf2+0x78>
     fa0:	fe0714e3          	bne	a4,zero,f88 <__lesf2+0x78>
     fa4:	40f00533          	sub	a0,zero,a5
     fa8:	00156513          	ori	a0,a0,1
     fac:	00008067          	jalr	zero,0(ra)

00000fb0 <__mulsf3>:
     fb0:	fe010113          	addi	sp,sp,-32
     fb4:	01212823          	sw	s2,16(sp)
     fb8:	01755913          	srli	s2,a0,0x17
     fbc:	00912a23          	sw	s1,20(sp)
     fc0:	01312623          	sw	s3,12(sp)
     fc4:	01412423          	sw	s4,8(sp)
     fc8:	00951493          	slli	s1,a0,0x9
     fcc:	00112e23          	sw	ra,28(sp)
     fd0:	00812c23          	sw	s0,24(sp)
     fd4:	01512223          	sw	s5,4(sp)
     fd8:	0ff97913          	andi	s2,s2,255
     fdc:	00058a13          	addi	s4,a1,0
     fe0:	0094d493          	srli	s1,s1,0x9
     fe4:	01f55993          	srli	s3,a0,0x1f
     fe8:	14090a63          	beq	s2,zero,113c <__mulsf3+0x18c>
     fec:	0ff00793          	addi	a5,zero,255
     ff0:	16f90663          	beq	s2,a5,115c <__mulsf3+0x1ac>
     ff4:	00349493          	slli	s1,s1,0x3
     ff8:	040007b7          	lui	a5,0x4000
     ffc:	00f4e4b3          	or	s1,s1,a5
    1000:	f8190913          	addi	s2,s2,-127
    1004:	00000a93          	addi	s5,zero,0
    1008:	017a5793          	srli	a5,s4,0x17
    100c:	009a1413          	slli	s0,s4,0x9
    1010:	0ff7f793          	andi	a5,a5,255
    1014:	00945413          	srli	s0,s0,0x9
    1018:	01fa5a13          	srli	s4,s4,0x1f
    101c:	14078e63          	beq	a5,zero,1178 <__mulsf3+0x1c8>
    1020:	0ff00713          	addi	a4,zero,255
    1024:	16e78a63          	beq	a5,a4,1198 <__mulsf3+0x1e8>
    1028:	00341413          	slli	s0,s0,0x3
    102c:	04000737          	lui	a4,0x4000
    1030:	00e46433          	or	s0,s0,a4
    1034:	f8178793          	addi	a5,a5,-127 # 3ffff81 <_stack_top+0x3fda781>
    1038:	00000693          	addi	a3,zero,0
    103c:	00f90933          	add	s2,s2,a5
    1040:	002a9793          	slli	a5,s5,0x2
    1044:	00d7e7b3          	or	a5,a5,a3
    1048:	00a00613          	addi	a2,zero,10
    104c:	00190713          	addi	a4,s2,1
    1050:	1af64463          	blt	a2,a5,11f8 <__mulsf3+0x248>
    1054:	00200593          	addi	a1,zero,2
    1058:	0149c9b3          	xor	s3,s3,s4
    105c:	00100613          	addi	a2,zero,1
    1060:	14f5ca63          	blt	a1,a5,11b4 <__mulsf3+0x204>
    1064:	fff78793          	addi	a5,a5,-1
    1068:	16f67663          	bgeu	a2,a5,11d4 <__mulsf3+0x224>
    106c:	0104d693          	srli	a3,s1,0x10
    1070:	01045793          	srli	a5,s0,0x10
    1074:	01049493          	slli	s1,s1,0x10
    1078:	01041413          	slli	s0,s0,0x10
    107c:	0104d493          	srli	s1,s1,0x10
    1080:	01045413          	srli	s0,s0,0x10
    1084:	029405b3          	mul	a1,s0,s1
    1088:	02868433          	mul	s0,a3,s0
    108c:	02f686b3          	mul	a3,a3,a5
    1090:	029787b3          	mul	a5,a5,s1
    1094:	00878633          	add	a2,a5,s0
    1098:	0105d793          	srli	a5,a1,0x10
    109c:	00c787b3          	add	a5,a5,a2
    10a0:	0087f663          	bgeu	a5,s0,10ac <__mulsf3+0xfc>
    10a4:	00010637          	lui	a2,0x10
    10a8:	00c686b3          	add	a3,a3,a2
    10ac:	01059593          	slli	a1,a1,0x10
    10b0:	01079613          	slli	a2,a5,0x10
    10b4:	0105d593          	srli	a1,a1,0x10
    10b8:	00b60633          	add	a2,a2,a1
    10bc:	0107d793          	srli	a5,a5,0x10
    10c0:	00661413          	slli	s0,a2,0x6
    10c4:	00d787b3          	add	a5,a5,a3
    10c8:	00679793          	slli	a5,a5,0x6
    10cc:	00803433          	sltu	s0,zero,s0
    10d0:	01a65613          	srli	a2,a2,0x1a
    10d4:	00c46433          	or	s0,s0,a2
    10d8:	00479693          	slli	a3,a5,0x4
    10dc:	0087e433          	or	s0,a5,s0
    10e0:	1206da63          	bge	a3,zero,1214 <__mulsf3+0x264>
    10e4:	00145793          	srli	a5,s0,0x1
    10e8:	00147413          	andi	s0,s0,1
    10ec:	0087e433          	or	s0,a5,s0
    10f0:	07f70793          	addi	a5,a4,127 # 400007f <_stack_top+0x3fda87f>
    10f4:	12f05463          	bge	zero,a5,121c <__mulsf3+0x26c>
    10f8:	00747693          	andi	a3,s0,7
    10fc:	00068a63          	beq	a3,zero,1110 <__mulsf3+0x160>
    1100:	00f47693          	andi	a3,s0,15
    1104:	00400613          	addi	a2,zero,4
    1108:	00c68463          	beq	a3,a2,1110 <__mulsf3+0x160>
    110c:	00c40433          	add	s0,s0,a2
    1110:	00441693          	slli	a3,s0,0x4
    1114:	0006da63          	bge	a3,zero,1128 <__mulsf3+0x178>
    1118:	f80007b7          	lui	a5,0xf8000
    111c:	fff78793          	addi	a5,a5,-1 # f7ffffff <_stack_top+0xf7fda7ff>
    1120:	00f47433          	and	s0,s0,a5
    1124:	08070793          	addi	a5,a4,128
    1128:	0fe00713          	addi	a4,zero,254
    112c:	00345413          	srli	s0,s0,0x3
    1130:	14f75a63          	bge	a4,a5,1284 <__mulsf3+0x2d4>
    1134:	00000413          	addi	s0,zero,0
    1138:	1480006f          	jal	zero,1280 <__mulsf3+0x2d0>
    113c:	02048863          	beq	s1,zero,116c <__mulsf3+0x1bc>
    1140:	00048513          	addi	a0,s1,0
    1144:	32c000ef          	jal	ra,1470 <__clzsi2>
    1148:	ffb50793          	addi	a5,a0,-5
    114c:	f8a00913          	addi	s2,zero,-118
    1150:	00f494b3          	sll	s1,s1,a5
    1154:	40a90933          	sub	s2,s2,a0
    1158:	eadff06f          	jal	zero,1004 <__mulsf3+0x54>
    115c:	00200a93          	addi	s5,zero,2
    1160:	ea0484e3          	beq	s1,zero,1008 <__mulsf3+0x58>
    1164:	00300a93          	addi	s5,zero,3
    1168:	ea1ff06f          	jal	zero,1008 <__mulsf3+0x58>
    116c:	00000913          	addi	s2,zero,0
    1170:	00100a93          	addi	s5,zero,1
    1174:	e95ff06f          	jal	zero,1008 <__mulsf3+0x58>
    1178:	02040863          	beq	s0,zero,11a8 <__mulsf3+0x1f8>
    117c:	00040513          	addi	a0,s0,0
    1180:	2f0000ef          	jal	ra,1470 <__clzsi2>
    1184:	ffb50793          	addi	a5,a0,-5
    1188:	00f41433          	sll	s0,s0,a5
    118c:	f8a00793          	addi	a5,zero,-118
    1190:	40a787b3          	sub	a5,a5,a0
    1194:	ea5ff06f          	jal	zero,1038 <__mulsf3+0x88>
    1198:	00200693          	addi	a3,zero,2
    119c:	ea0400e3          	beq	s0,zero,103c <__mulsf3+0x8c>
    11a0:	00300693          	addi	a3,zero,3
    11a4:	e99ff06f          	jal	zero,103c <__mulsf3+0x8c>
    11a8:	00000793          	addi	a5,zero,0
    11ac:	00100693          	addi	a3,zero,1
    11b0:	e8dff06f          	jal	zero,103c <__mulsf3+0x8c>
    11b4:	00f617b3          	sll	a5,a2,a5
    11b8:	5307f613          	andi	a2,a5,1328
    11bc:	04061663          	bne	a2,zero,1208 <__mulsf3+0x258>
    11c0:	2407f613          	andi	a2,a5,576
    11c4:	0a061663          	bne	a2,zero,1270 <__mulsf3+0x2c0>
    11c8:	0887f793          	andi	a5,a5,136
    11cc:	ea0780e3          	beq	a5,zero,106c <__mulsf3+0xbc>
    11d0:	000a0993          	addi	s3,s4,0
    11d4:	00200793          	addi	a5,zero,2
    11d8:	f4f68ee3          	beq	a3,a5,1134 <__mulsf3+0x184>
    11dc:	00300793          	addi	a5,zero,3
    11e0:	08f68c63          	beq	a3,a5,1278 <__mulsf3+0x2c8>
    11e4:	00100793          	addi	a5,zero,1
    11e8:	f0f694e3          	bne	a3,a5,10f0 <__mulsf3+0x140>
    11ec:	00000413          	addi	s0,zero,0
    11f0:	00000793          	addi	a5,zero,0
    11f4:	0900006f          	jal	zero,1284 <__mulsf3+0x2d4>
    11f8:	00f00613          	addi	a2,zero,15
    11fc:	06c78a63          	beq	a5,a2,1270 <__mulsf3+0x2c0>
    1200:	00b00613          	addi	a2,zero,11
    1204:	fcc786e3          	beq	a5,a2,11d0 <__mulsf3+0x220>
    1208:	00048413          	addi	s0,s1,0
    120c:	000a8693          	addi	a3,s5,0
    1210:	fc5ff06f          	jal	zero,11d4 <__mulsf3+0x224>
    1214:	00090713          	addi	a4,s2,0
    1218:	ed9ff06f          	jal	zero,10f0 <__mulsf3+0x140>
    121c:	00100693          	addi	a3,zero,1
    1220:	40f687b3          	sub	a5,a3,a5
    1224:	01b00693          	addi	a3,zero,27
    1228:	fcf6c2e3          	blt	a3,a5,11ec <__mulsf3+0x23c>
    122c:	09e70713          	addi	a4,a4,158
    1230:	00e41733          	sll	a4,s0,a4
    1234:	00f457b3          	srl	a5,s0,a5
    1238:	00e03733          	sltu	a4,zero,a4
    123c:	00e7e433          	or	s0,a5,a4
    1240:	00747793          	andi	a5,s0,7
    1244:	00078a63          	beq	a5,zero,1258 <__mulsf3+0x2a8>
    1248:	00f47793          	andi	a5,s0,15
    124c:	00400713          	addi	a4,zero,4
    1250:	00e78463          	beq	a5,a4,1258 <__mulsf3+0x2a8>
    1254:	00e40433          	add	s0,s0,a4
    1258:	00541793          	slli	a5,s0,0x5
    125c:	00345413          	srli	s0,s0,0x3
    1260:	f807d8e3          	bge	a5,zero,11f0 <__mulsf3+0x240>
    1264:	00000413          	addi	s0,zero,0
    1268:	00100793          	addi	a5,zero,1
    126c:	0180006f          	jal	zero,1284 <__mulsf3+0x2d4>
    1270:	00000993          	addi	s3,zero,0
    1274:	00400437          	lui	s0,0x400
    1278:	004007b7          	lui	a5,0x400
    127c:	00f46433          	or	s0,s0,a5
    1280:	0ff00793          	addi	a5,zero,255
    1284:	00941413          	slli	s0,s0,0x9
    1288:	00945413          	srli	s0,s0,0x9
    128c:	01779793          	slli	a5,a5,0x17
    1290:	01c12083          	lw	ra,28(sp)
    1294:	0087e7b3          	or	a5,a5,s0
    1298:	01812403          	lw	s0,24(sp)
    129c:	01f99513          	slli	a0,s3,0x1f
    12a0:	01412483          	lw	s1,20(sp)
    12a4:	01012903          	lw	s2,16(sp)
    12a8:	00c12983          	lw	s3,12(sp)
    12ac:	00812a03          	lw	s4,8(sp)
    12b0:	00412a83          	lw	s5,4(sp)
    12b4:	00a7e533          	or	a0,a5,a0
    12b8:	02010113          	addi	sp,sp,32
    12bc:	00008067          	jalr	zero,0(ra)

000012c0 <__fixunssfsi>:
    12c0:	008005b7          	lui	a1,0x800
    12c4:	01755793          	srli	a5,a0,0x17
    12c8:	fff58693          	addi	a3,a1,-1 # 7fffff <_stack_top+0x7da7ff>
    12cc:	0ff7f793          	andi	a5,a5,255
    12d0:	07e00613          	addi	a2,zero,126
    12d4:	00a6f6b3          	and	a3,a3,a0
    12d8:	01f55713          	srli	a4,a0,0x1f
    12dc:	04f65263          	bge	a2,a5,1320 <__fixunssfsi+0x60>
    12e0:	09f00613          	addi	a2,zero,159
    12e4:	40e60633          	sub	a2,a2,a4
    12e8:	fff70513          	addi	a0,a4,-1
    12ec:	02c7dc63          	bge	a5,a2,1324 <__fixunssfsi+0x64>
    12f0:	00000513          	addi	a0,zero,0
    12f4:	02071863          	bne	a4,zero,1324 <__fixunssfsi+0x64>
    12f8:	09500713          	addi	a4,zero,149
    12fc:	00b6e533          	or	a0,a3,a1
    1300:	00f75863          	bge	a4,a5,1310 <__fixunssfsi+0x50>
    1304:	f6a78793          	addi	a5,a5,-150 # 3fff6a <_stack_top+0x3da76a>
    1308:	00f51533          	sll	a0,a0,a5
    130c:	00008067          	jalr	zero,0(ra)
    1310:	09600713          	addi	a4,zero,150
    1314:	40f707b3          	sub	a5,a4,a5
    1318:	00f55533          	srl	a0,a0,a5
    131c:	00008067          	jalr	zero,0(ra)
    1320:	00000513          	addi	a0,zero,0
    1324:	00008067          	jalr	zero,0(ra)

00001328 <__truncdfsf2>:
    1328:	0145d713          	srli	a4,a1,0x14
    132c:	7ff77713          	andi	a4,a4,2047
    1330:	00c59793          	slli	a5,a1,0xc
    1334:	00170613          	addi	a2,a4,1
    1338:	0097d793          	srli	a5,a5,0x9
    133c:	01d55693          	srli	a3,a0,0x1d
    1340:	7fe67613          	andi	a2,a2,2046
    1344:	00f6e6b3          	or	a3,a3,a5
    1348:	01f5d593          	srli	a1,a1,0x1f
    134c:	00351793          	slli	a5,a0,0x3
    1350:	0c060063          	beq	a2,zero,1410 <__truncdfsf2+0xe8>
    1354:	c8070613          	addi	a2,a4,-896
    1358:	0fe00813          	addi	a6,zero,254
    135c:	10c84663          	blt	a6,a2,1468 <__truncdfsf2+0x140>
    1360:	06c04c63          	blt	zero,a2,13d8 <__truncdfsf2+0xb0>
    1364:	fe900513          	addi	a0,zero,-23
    1368:	0ea64a63          	blt	a2,a0,145c <__truncdfsf2+0x134>
    136c:	00800537          	lui	a0,0x800
    1370:	01e00813          	addi	a6,zero,30
    1374:	00a6e6b3          	or	a3,a3,a0
    1378:	40c80833          	sub	a6,a6,a2
    137c:	01f00513          	addi	a0,zero,31
    1380:	03054463          	blt	a0,a6,13a8 <__truncdfsf2+0x80>
    1384:	c8270713          	addi	a4,a4,-894
    1388:	0107d833          	srl	a6,a5,a6
    138c:	00e797b3          	sll	a5,a5,a4
    1390:	00f037b3          	sltu	a5,zero,a5
    1394:	00e696b3          	sll	a3,a3,a4
    1398:	00d7e7b3          	or	a5,a5,a3
    139c:	00f867b3          	or	a5,a6,a5
    13a0:	00000713          	addi	a4,zero,0
    13a4:	0500006f          	jal	zero,13f4 <__truncdfsf2+0xcc>
    13a8:	ffe00513          	addi	a0,zero,-2
    13ac:	40c50533          	sub	a0,a0,a2
    13b0:	02000893          	addi	a7,zero,32
    13b4:	00a6d533          	srl	a0,a3,a0
    13b8:	00000613          	addi	a2,zero,0
    13bc:	01180663          	beq	a6,a7,13c8 <__truncdfsf2+0xa0>
    13c0:	ca270613          	addi	a2,a4,-862
    13c4:	00c69633          	sll	a2,a3,a2
    13c8:	00f66633          	or	a2,a2,a5
    13cc:	00c03633          	sltu	a2,zero,a2
    13d0:	00c567b3          	or	a5,a0,a2
    13d4:	fcdff06f          	jal	zero,13a0 <__truncdfsf2+0x78>
    13d8:	00651713          	slli	a4,a0,0x6
    13dc:	00e03733          	sltu	a4,zero,a4
    13e0:	00369693          	slli	a3,a3,0x3
    13e4:	00d76733          	or	a4,a4,a3
    13e8:	01d7d793          	srli	a5,a5,0x1d
    13ec:	00f767b3          	or	a5,a4,a5
    13f0:	00060713          	addi	a4,a2,0 # 10000 <_bss_end+0x32b4>
    13f4:	0077f693          	andi	a3,a5,7
    13f8:	00068863          	beq	a3,zero,1408 <__truncdfsf2+0xe0>
    13fc:	00f7f693          	andi	a3,a5,15
    1400:	00400613          	addi	a2,zero,4
    1404:	00c69e63          	bne	a3,a2,1420 <__truncdfsf2+0xf8>
    1408:	0037d793          	srli	a5,a5,0x3
    140c:	03c0006f          	jal	zero,1448 <__truncdfsf2+0x120>
    1410:	00f6e7b3          	or	a5,a3,a5
    1414:	02071263          	bne	a4,zero,1438 <__truncdfsf2+0x110>
    1418:	02078863          	beq	a5,zero,1448 <__truncdfsf2+0x120>
    141c:	00100793          	addi	a5,zero,1
    1420:	00478793          	addi	a5,a5,4
    1424:	00579693          	slli	a3,a5,0x5
    1428:	fe06d0e3          	bge	a3,zero,1408 <__truncdfsf2+0xe0>
    142c:	00170713          	addi	a4,a4,1
    1430:	00000793          	addi	a5,zero,0
    1434:	0140006f          	jal	zero,1448 <__truncdfsf2+0x120>
    1438:	0ff00713          	addi	a4,zero,255
    143c:	00078663          	beq	a5,zero,1448 <__truncdfsf2+0x120>
    1440:	004007b7          	lui	a5,0x400
    1444:	00f6e7b3          	or	a5,a3,a5
    1448:	01771713          	slli	a4,a4,0x17
    144c:	00f76733          	or	a4,a4,a5
    1450:	01f59513          	slli	a0,a1,0x1f
    1454:	00a76533          	or	a0,a4,a0
    1458:	00008067          	jalr	zero,0(ra)
    145c:	00100793          	addi	a5,zero,1
    1460:	00000713          	addi	a4,zero,0
    1464:	fbdff06f          	jal	zero,1420 <__truncdfsf2+0xf8>
    1468:	0ff00713          	addi	a4,zero,255
    146c:	fc5ff06f          	jal	zero,1430 <__truncdfsf2+0x108>

00001470 <__clzsi2>:
    1470:	000107b7          	lui	a5,0x10
    1474:	02f57a63          	bgeu	a0,a5,14a8 <__clzsi2+0x38>
    1478:	10053793          	sltiu	a5,a0,256
    147c:	0017b793          	sltiu	a5,a5,1
    1480:	00379793          	slli	a5,a5,0x3
    1484:	02000713          	addi	a4,zero,32
    1488:	40f70733          	sub	a4,a4,a5
    148c:	00f55533          	srl	a0,a0,a5
    1490:	0000b797          	auipc	a5,0xb
    1494:	51078793          	addi	a5,a5,1296 # c9a0 <__clz_tab>
    1498:	00a787b3          	add	a5,a5,a0
    149c:	0007c503          	lbu	a0,0(a5)
    14a0:	40a70533          	sub	a0,a4,a0
    14a4:	00008067          	jalr	zero,0(ra)
    14a8:	01000737          	lui	a4,0x1000
    14ac:	01800793          	addi	a5,zero,24
    14b0:	fce57ae3          	bgeu	a0,a4,1484 <__clzsi2+0x14>
    14b4:	01000793          	addi	a5,zero,16
    14b8:	fcdff06f          	jal	zero,1484 <__clzsi2+0x14>

Disassembly of section .rodata:

0000c800 <__clz_tab-0x1a0>:
    c800:	34323032          	.word	0x34323032
    c804:	32313133          	.word	0x32313133
    c808:	54203037          	.word	0x54203037
    c80c:	20747365          	.word	0x20747365
    c810:	2d203123          	.word	0x2d203123
    c814:	726f4620          	.word	0x726f4620
    c818:	7474616d          	.word	0x7474616d
    c81c:	69206465          	.word	0x69206465
    c820:	7475706e          	.word	0x7475706e
    c824:	74756f2f          	.word	0x74756f2f
    c828:	20747570          	.word	0x20747570
    c82c:	74736574          	.word	0x74736574
    c830:	00000a3a          	.word	0x00000a3a
    c834:	6168503c          	.word	0x6168503c
    c838:	30206573          	.word	0x30206573
    c83c:	202d203e          	.word	0x202d203e
    c840:	6d726f46          	.word	0x6d726f46
    c844:	65747461          	.word	0x65747461
    c848:	756f2064          	.word	0x756f2064
    c84c:	74757074          	.word	0x74757074
    c850:	73657420          	.word	0x73657420
    c854:	000a3a74          	.word	0x000a3a74
    c858:	6c6c6548          	.word	0x6c6c6548
    c85c:	6f57206f          	.word	0x6f57206f
    c860:	21646c72          	.word	0x21646c72
    c864:	00000000          	.word	0x00000000
    c868:	300a6425          	.word	0x300a6425
    c86c:	0a782578          	.word	0x0a782578
    c870:	250a6325          	.word	0x250a6325
    c874:	66250a73          	.word	0x66250a73
    c878:	0000000a          	.word	0x0000000a
    c87c:	68503c0a          	.word	0x68503c0a
    c880:	20657361          	.word	0x20657361
    c884:	2d203e31          	.word	0x2d203e31
    c888:	726f4620          	.word	0x726f4620
    c88c:	7474616d          	.word	0x7474616d
    c890:	69206465          	.word	0x69206465
    c894:	7475706e          	.word	0x7475706e
    c898:	73657420          	.word	0x73657420
    c89c:	000a3a74          	.word	0x000a3a74
    c8a0:	65746e45          	.word	0x65746e45
    c8a4:	6e612072          	.word	0x6e612072
    c8a8:	746e6920          	.word	0x746e6920
    c8ac:	72656765          	.word	0x72656765
    c8b0:	2061202c          	.word	0x2061202c
    c8b4:	72616863          	.word	0x72616863
    c8b8:	6e61202c          	.word	0x6e61202c
    c8bc:	20612064          	.word	0x20612064
    c8c0:	69727473          	.word	0x69727473
    c8c4:	2820676e          	.word	0x2820676e
    c8c8:	2e672e65          	.word	0x2e672e65
    c8cc:	3231202c          	.word	0x3231202c
    c8d0:	20782033          	.word	0x20782033
    c8d4:	6c6c6568          	.word	0x6c6c6568
    c8d8:	203a296f          	.word	0x203a296f
    c8dc:	0000000a          	.word	0x0000000a
    c8e0:	25206425          	.word	0x25206425
    c8e4:	73252063          	.word	0x73252063
    c8e8:	00000000          	.word	0x00000000
    c8ec:	75706e49          	.word	0x75706e49
    c8f0:	65722074          	.word	0x65722074
    c8f4:	76696563          	.word	0x76696563
    c8f8:	203a6465          	.word	0x203a6465
    c8fc:	3d746e69          	.word	0x3d746e69
    c900:	202c6425          	.word	0x202c6425
    c904:	72616863          	.word	0x72616863
    c908:	6325273d          	.word	0x6325273d
    c90c:	73202c27          	.word	0x73202c27
    c910:	6e697274          	.word	0x6e697274
    c914:	25223d67          	.word	0x25223d67
    c918:	000a2273          	.word	0x000a2273
    c91c:	74736554          	.word	0x74736554
    c920:	646e6520          	.word	0x646e6520
    c924:	002e6465          	.word	0x002e6465
    c928:	504816f0          	.word	0x504816f0
    c92c:	4058b0fc          	.word	0x4058b0fc
    c930:	33323130          	.word	0x33323130
    c934:	37363534          	.word	0x37363534
    c938:	42413938          	.word	0x42413938
    c93c:	46454443          	.word	0x46454443
    c940:	00000000          	.word	0x00000000
    c944:	00000710          	.word	0x00000710
    c948:	0000074c          	.word	0x0000074c
    c94c:	00000800          	.word	0x00000800
    c950:	000007b8          	.word	0x000007b8
    c954:	00000800          	.word	0x00000800
    c958:	00000800          	.word	0x00000800
    c95c:	00000800          	.word	0x00000800
    c960:	00000800          	.word	0x00000800
    c964:	00000800          	.word	0x00000800
    c968:	00000800          	.word	0x00000800
    c96c:	00000800          	.word	0x00000800
    c970:	00000800          	.word	0x00000800
    c974:	00000800          	.word	0x00000800
    c978:	00000800          	.word	0x00000800
    c97c:	00000800          	.word	0x00000800
    c980:	00000800          	.word	0x00000800
    c984:	00000730          	.word	0x00000730
    c988:	00000800          	.word	0x00000800
    c98c:	00000770          	.word	0x00000770
    c990:	00000800          	.word	0x00000800
    c994:	00000800          	.word	0x00000800
    c998:	00000794          	.word	0x00000794
    c99c:	49742400          	.word	0x49742400

0000c9a0 <__clz_tab>:
    c9a0:	02020100 03030303 04040404 04040404     ................
    c9b0:	05050505 05050505 05050505 05050505     ................
    c9c0:	06060606 06060606 06060606 06060606     ................
    c9d0:	06060606 06060606 06060606 06060606     ................
    c9e0:	07070707 07070707 07070707 07070707     ................
    c9f0:	07070707 07070707 07070707 07070707     ................
    ca00:	07070707 07070707 07070707 07070707     ................
    ca10:	07070707 07070707 07070707 07070707     ................
    ca20:	08080808 08080808 08080808 08080808     ................
    ca30:	08080808 08080808 08080808 08080808     ................
    ca40:	08080808 08080808 08080808 08080808     ................
    ca50:	08080808 08080808 08080808 08080808     ................
    ca60:	08080808 08080808 08080808 08080808     ................
    ca70:	08080808 08080808 08080808 08080808     ................
    ca80:	08080808 08080808 08080808 08080808     ................
    ca90:	08080808 08080808 08080808 08080808     ................

Disassembly of section .sdata:

0000caa0 <peri_led>:
    caa0:	ffff1000                                ....

0000caa4 <peri_digled>:
    caa4:	ffff2000                                . ..

0000caa8 <heap_end.0>:
    caa8:	00019000                                ....

0000caac <uart_rx_fifo>:
    caac:	ffff3000                                .0..

0000cab0 <uart_tx_fifo>:
    cab0:	ffff3004                                .0..

0000cab4 <uart_stat_reg>:
    cab4:	ffff3008                                .0..

0000cab8 <uart_ctrl_reg>:
    cab8:	ffff300c                                .0..
