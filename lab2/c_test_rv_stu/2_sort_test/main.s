
main:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <_start>:
       0:	00026137          	lui	sp,0x26
       4:	80010113          	addi	sp,sp,-2048 # 25800 <__heap_end>
       8:	2b4000ef          	jal	ra,2bc <main>
       c:	0000006f          	jal	zero,c <_start+0xc>
      10:	00000013          	addi	zero,zero,0

00000014 <_sbrk>:
      14:	fd010113          	addi	sp,sp,-48
      18:	02112623          	sw	ra,44(sp)
      1c:	02812423          	sw	s0,40(sp)
      20:	03010413          	addi	s0,sp,48
      24:	fca42e23          	sw	a0,-36(s0)
      28:	0000d7b7          	lui	a5,0xd
      2c:	af47a783          	lw	a5,-1292(a5) # caf4 <heap_end.0>
      30:	fef42623          	sw	a5,-20(s0)
      34:	00010793          	addi	a5,sp,0
      38:	fef42423          	sw	a5,-24(s0)
      3c:	0000d7b7          	lui	a5,0xd
      40:	af47a703          	lw	a4,-1292(a5) # caf4 <heap_end.0>
      44:	fdc42783          	lw	a5,-36(s0)
      48:	00f707b3          	add	a5,a4,a5
      4c:	fe842703          	lw	a4,-24(s0)
      50:	00f77663          	bgeu	a4,a5,5c <_sbrk+0x48>
      54:	fff00793          	addi	a5,zero,-1
      58:	0200006f          	jal	zero,78 <_sbrk+0x64>
      5c:	0000d7b7          	lui	a5,0xd
      60:	af47a703          	lw	a4,-1292(a5) # caf4 <heap_end.0>
      64:	fdc42783          	lw	a5,-36(s0)
      68:	00f70733          	add	a4,a4,a5
      6c:	0000d7b7          	lui	a5,0xd
      70:	aee7aa23          	sw	a4,-1292(a5) # caf4 <heap_end.0>
      74:	fec42783          	lw	a5,-20(s0)
      78:	00078513          	addi	a0,a5,0
      7c:	02c12083          	lw	ra,44(sp)
      80:	02812403          	lw	s0,40(sp)
      84:	03010113          	addi	sp,sp,48
      88:	00008067          	jalr	zero,0(ra)

0000008c <swap>:
      8c:	fd010113          	addi	sp,sp,-48
      90:	02112623          	sw	ra,44(sp)
      94:	02812423          	sw	s0,40(sp)
      98:	03010413          	addi	s0,sp,48
      9c:	fca42e23          	sw	a0,-36(s0)
      a0:	fcb42c23          	sw	a1,-40(s0)
      a4:	fdc42783          	lw	a5,-36(s0)
      a8:	0007a783          	lw	a5,0(a5)
      ac:	fef42623          	sw	a5,-20(s0)
      b0:	fd842783          	lw	a5,-40(s0)
      b4:	0007a703          	lw	a4,0(a5)
      b8:	fdc42783          	lw	a5,-36(s0)
      bc:	00e7a023          	sw	a4,0(a5)
      c0:	fd842783          	lw	a5,-40(s0)
      c4:	fec42703          	lw	a4,-20(s0)
      c8:	00e7a023          	sw	a4,0(a5)
      cc:	00000013          	addi	zero,zero,0
      d0:	02c12083          	lw	ra,44(sp)
      d4:	02812403          	lw	s0,40(sp)
      d8:	03010113          	addi	sp,sp,48
      dc:	00008067          	jalr	zero,0(ra)

000000e0 <partition>:
      e0:	fd010113          	addi	sp,sp,-48
      e4:	02112623          	sw	ra,44(sp)
      e8:	02812423          	sw	s0,40(sp)
      ec:	03010413          	addi	s0,sp,48
      f0:	fca42e23          	sw	a0,-36(s0)
      f4:	fcb42c23          	sw	a1,-40(s0)
      f8:	fcc42a23          	sw	a2,-44(s0)
      fc:	fd442783          	lw	a5,-44(s0)
     100:	00279793          	slli	a5,a5,0x2
     104:	fdc42703          	lw	a4,-36(s0)
     108:	00f707b3          	add	a5,a4,a5
     10c:	0007a783          	lw	a5,0(a5)
     110:	fef42223          	sw	a5,-28(s0)
     114:	fd842783          	lw	a5,-40(s0)
     118:	fff78793          	addi	a5,a5,-1
     11c:	fef42623          	sw	a5,-20(s0)
     120:	fd842783          	lw	a5,-40(s0)
     124:	fef42423          	sw	a5,-24(s0)
     128:	0640006f          	jal	zero,18c <partition+0xac>
     12c:	fe842783          	lw	a5,-24(s0)
     130:	00279793          	slli	a5,a5,0x2
     134:	fdc42703          	lw	a4,-36(s0)
     138:	00f707b3          	add	a5,a4,a5
     13c:	0007a783          	lw	a5,0(a5)
     140:	fe442703          	lw	a4,-28(s0)
     144:	02f74e63          	blt	a4,a5,180 <partition+0xa0>
     148:	fec42783          	lw	a5,-20(s0)
     14c:	00178793          	addi	a5,a5,1
     150:	fef42623          	sw	a5,-20(s0)
     154:	fec42783          	lw	a5,-20(s0)
     158:	00279793          	slli	a5,a5,0x2
     15c:	fdc42703          	lw	a4,-36(s0)
     160:	00f706b3          	add	a3,a4,a5
     164:	fe842783          	lw	a5,-24(s0)
     168:	00279793          	slli	a5,a5,0x2
     16c:	fdc42703          	lw	a4,-36(s0)
     170:	00f707b3          	add	a5,a4,a5
     174:	00078593          	addi	a1,a5,0
     178:	00068513          	addi	a0,a3,0
     17c:	f11ff0ef          	jal	ra,8c <swap>
     180:	fe842783          	lw	a5,-24(s0)
     184:	00178793          	addi	a5,a5,1
     188:	fef42423          	sw	a5,-24(s0)
     18c:	fd442703          	lw	a4,-44(s0)
     190:	fe842783          	lw	a5,-24(s0)
     194:	f8e7cce3          	blt	a5,a4,12c <partition+0x4c>
     198:	fec42783          	lw	a5,-20(s0)
     19c:	00178793          	addi	a5,a5,1
     1a0:	00279793          	slli	a5,a5,0x2
     1a4:	fdc42703          	lw	a4,-36(s0)
     1a8:	00f706b3          	add	a3,a4,a5
     1ac:	fd442783          	lw	a5,-44(s0)
     1b0:	00279793          	slli	a5,a5,0x2
     1b4:	fdc42703          	lw	a4,-36(s0)
     1b8:	00f707b3          	add	a5,a4,a5
     1bc:	00078593          	addi	a1,a5,0
     1c0:	00068513          	addi	a0,a3,0
     1c4:	ec9ff0ef          	jal	ra,8c <swap>
     1c8:	fec42783          	lw	a5,-20(s0)
     1cc:	00178793          	addi	a5,a5,1
     1d0:	00078513          	addi	a0,a5,0
     1d4:	02c12083          	lw	ra,44(sp)
     1d8:	02812403          	lw	s0,40(sp)
     1dc:	03010113          	addi	sp,sp,48
     1e0:	00008067          	jalr	zero,0(ra)

000001e4 <quick_sort>:
     1e4:	fd010113          	addi	sp,sp,-48
     1e8:	02112623          	sw	ra,44(sp)
     1ec:	02812423          	sw	s0,40(sp)
     1f0:	03010413          	addi	s0,sp,48
     1f4:	fca42e23          	sw	a0,-36(s0)
     1f8:	fcb42c23          	sw	a1,-40(s0)
     1fc:	fcc42a23          	sw	a2,-44(s0)
     200:	fd842703          	lw	a4,-40(s0)
     204:	fd442783          	lw	a5,-44(s0)
     208:	04f75463          	bge	a4,a5,250 <quick_sort+0x6c>
     20c:	fd442603          	lw	a2,-44(s0)
     210:	fd842583          	lw	a1,-40(s0)
     214:	fdc42503          	lw	a0,-36(s0)
     218:	ec9ff0ef          	jal	ra,e0 <partition>
     21c:	fea42623          	sw	a0,-20(s0)
     220:	fec42783          	lw	a5,-20(s0)
     224:	fff78793          	addi	a5,a5,-1
     228:	00078613          	addi	a2,a5,0
     22c:	fd842583          	lw	a1,-40(s0)
     230:	fdc42503          	lw	a0,-36(s0)
     234:	fb1ff0ef          	jal	ra,1e4 <quick_sort>
     238:	fec42783          	lw	a5,-20(s0)
     23c:	00178793          	addi	a5,a5,1
     240:	fd442603          	lw	a2,-44(s0)
     244:	00078593          	addi	a1,a5,0
     248:	fdc42503          	lw	a0,-36(s0)
     24c:	f99ff0ef          	jal	ra,1e4 <quick_sort>
     250:	00000013          	addi	zero,zero,0
     254:	02c12083          	lw	ra,44(sp)
     258:	02812403          	lw	s0,40(sp)
     25c:	03010113          	addi	sp,sp,48
     260:	00008067          	jalr	zero,0(ra)

00000264 <fast_rand>:
     264:	fe010113          	addi	sp,sp,-32
     268:	00112e23          	sw	ra,28(sp)
     26c:	00812c23          	sw	s0,24(sp)
     270:	02010413          	addi	s0,sp,32
     274:	fea42623          	sw	a0,-20(s0)
     278:	fec42783          	lw	a5,-20(s0)
     27c:	0007a703          	lw	a4,0(a5)
     280:	7a5b47b7          	lui	a5,0x7a5b4
     284:	c1d78793          	addi	a5,a5,-995 # 7a5b3c1d <__heap_end+0x7a58e41d>
     288:	00f70733          	add	a4,a4,a5
     28c:	123457b7          	lui	a5,0x12345
     290:	67878793          	addi	a5,a5,1656 # 12345678 <__heap_end+0x1231fe78>
     294:	00f74733          	xor	a4,a4,a5
     298:	fec42783          	lw	a5,-20(s0)
     29c:	00e7a023          	sw	a4,0(a5)
     2a0:	fec42783          	lw	a5,-20(s0)
     2a4:	0007a783          	lw	a5,0(a5)
     2a8:	00078513          	addi	a0,a5,0
     2ac:	01c12083          	lw	ra,28(sp)
     2b0:	01812403          	lw	s0,24(sp)
     2b4:	02010113          	addi	sp,sp,32
     2b8:	00008067          	jalr	zero,0(ra)

000002bc <main>:
     2bc:	fa010113          	addi	sp,sp,-96
     2c0:	04112e23          	sw	ra,92(sp)
     2c4:	04812c23          	sw	s0,88(sp)
     2c8:	06010413          	addi	s0,sp,96
     2cc:	3f0000ef          	jal	ra,6bc <uart_init>
     2d0:	0000d7b7          	lui	a5,0xd
     2d4:	80078513          	addi	a0,a5,-2048 # c800 <_etext+0xa1d8>
     2d8:	3c9000ef          	jal	ra,ea0 <printf>
     2dc:	0000d7b7          	lui	a5,0xd
     2e0:	82478513          	addi	a0,a5,-2012 # c824 <_etext+0xa1fc>
     2e4:	3bd000ef          	jal	ra,ea0 <printf>
     2e8:	0000d7b7          	lui	a5,0xd
     2ec:	84c78513          	addi	a0,a5,-1972 # c84c <_etext+0xa224>
     2f0:	3b1000ef          	jal	ra,ea0 <printf>
     2f4:	fe042623          	sw	zero,-20(s0)
     2f8:	0300006f          	jal	zero,328 <main+0x6c>
     2fc:	fac40713          	addi	a4,s0,-84
     300:	fec42783          	lw	a5,-20(s0)
     304:	00279793          	slli	a5,a5,0x2
     308:	00f707b3          	add	a5,a4,a5
     30c:	00078593          	addi	a1,a5,0
     310:	0000d7b7          	lui	a5,0xd
     314:	86078513          	addi	a0,a5,-1952 # c860 <_etext+0xa238>
     318:	1dc010ef          	jal	ra,14f4 <scanf>
     31c:	fec42783          	lw	a5,-20(s0)
     320:	00178793          	addi	a5,a5,1
     324:	fef42623          	sw	a5,-20(s0)
     328:	fec42703          	lw	a4,-20(s0)
     32c:	00700793          	addi	a5,zero,7
     330:	fce7d6e3          	bge	a5,a4,2fc <main+0x40>
     334:	500000ef          	jal	ra,834 <get_time>
     338:	fca42c23          	sw	a0,-40(s0)
     33c:	fcb42e23          	sw	a1,-36(s0)
     340:	fac40793          	addi	a5,s0,-84
     344:	00700613          	addi	a2,zero,7
     348:	00000593          	addi	a1,zero,0
     34c:	00078513          	addi	a0,a5,0
     350:	e95ff0ef          	jal	ra,1e4 <quick_sort>
     354:	4e0000ef          	jal	ra,834 <get_time>
     358:	fca42823          	sw	a0,-48(s0)
     35c:	fcb42a23          	sw	a1,-44(s0)
     360:	0000d7b7          	lui	a5,0xd
     364:	86478513          	addi	a0,a5,-1948 # c864 <_etext+0xa23c>
     368:	339000ef          	jal	ra,ea0 <printf>
     36c:	fe042423          	sw	zero,-24(s0)
     370:	0340006f          	jal	zero,3a4 <main+0xe8>
     374:	fe842703          	lw	a4,-24(s0)
     378:	fac40793          	addi	a5,s0,-84
     37c:	00271713          	slli	a4,a4,0x2
     380:	00f707b3          	add	a5,a4,a5
     384:	0007a783          	lw	a5,0(a5)
     388:	00078593          	addi	a1,a5,0
     38c:	0000d7b7          	lui	a5,0xd
     390:	87478513          	addi	a0,a5,-1932 # c874 <_etext+0xa24c>
     394:	30d000ef          	jal	ra,ea0 <printf>
     398:	fe842783          	lw	a5,-24(s0)
     39c:	00178793          	addi	a5,a5,1
     3a0:	fef42423          	sw	a5,-24(s0)
     3a4:	fe842703          	lw	a4,-24(s0)
     3a8:	00700793          	addi	a5,zero,7
     3ac:	fce7d4e3          	bge	a5,a4,374 <main+0xb8>
     3b0:	fd042703          	lw	a4,-48(s0)
     3b4:	fd442783          	lw	a5,-44(s0)
     3b8:	fd842503          	lw	a0,-40(s0)
     3bc:	fdc42583          	lw	a1,-36(s0)
     3c0:	40a70633          	sub	a2,a4,a0
     3c4:	00060813          	addi	a6,a2,0
     3c8:	01073833          	sltu	a6,a4,a6
     3cc:	40b786b3          	sub	a3,a5,a1
     3d0:	410687b3          	sub	a5,a3,a6
     3d4:	00078693          	addi	a3,a5,0
     3d8:	00060713          	addi	a4,a2,0
     3dc:	00068793          	addi	a5,a3,0
     3e0:	00070513          	addi	a0,a4,0
     3e4:	00078593          	addi	a1,a5,0
     3e8:	259010ef          	jal	ra,1e40 <__floatundisf>
     3ec:	00050713          	addi	a4,a0,0
     3f0:	0000d7b7          	lui	a5,0xd
     3f4:	9387a583          	lw	a1,-1736(a5) # c938 <_etext+0xa310>
     3f8:	00070513          	addi	a0,a4,0
     3fc:	5bc010ef          	jal	ra,19b8 <__mulsf3>
     400:	00050793          	addi	a5,a0,0
     404:	00078713          	addi	a4,a5,0
     408:	0000d7b7          	lui	a5,0xd
     40c:	93c7a583          	lw	a1,-1732(a5) # c93c <_etext+0xa314>
     410:	00070513          	addi	a0,a4,0
     414:	150010ef          	jal	ra,1564 <__divsf3>
     418:	00050793          	addi	a5,a0,0
     41c:	00078513          	addi	a0,a5,0
     420:	375010ef          	jal	ra,1f94 <__extendsfdf2>
     424:	00050713          	addi	a4,a0,0
     428:	00058793          	addi	a5,a1,0
     42c:	00070613          	addi	a2,a4,0
     430:	00078693          	addi	a3,a5,0
     434:	0000d7b7          	lui	a5,0xd
     438:	87878513          	addi	a0,a5,-1928 # c878 <_etext+0xa250>
     43c:	265000ef          	jal	ra,ea0 <printf>
     440:	0000d7b7          	lui	a5,0xd
     444:	89078513          	addi	a0,a5,-1904 # c890 <_etext+0xa268>
     448:	259000ef          	jal	ra,ea0 <printf>
     44c:	0000d7b7          	lui	a5,0xd
     450:	8ac78513          	addi	a0,a5,-1876 # c8ac <_etext+0xa284>
     454:	24d000ef          	jal	ra,ea0 <printf>
     458:	fa840793          	addi	a5,s0,-88
     45c:	00078593          	addi	a1,a5,0
     460:	0000d7b7          	lui	a5,0xd
     464:	86078513          	addi	a0,a5,-1952 # c860 <_etext+0xa238>
     468:	08c010ef          	jal	ra,14f4 <scanf>
     46c:	fa842783          	lw	a5,-88(s0)
     470:	00279793          	slli	a5,a5,0x2
     474:	00078513          	addi	a0,a5,0
     478:	068020ef          	jal	ra,24e0 <__malloc_malloc>
     47c:	00050793          	addi	a5,a0,0
     480:	fcf42623          	sw	a5,-52(s0)
     484:	fcc42783          	lw	a5,-52(s0)
     488:	00079863          	bne	a5,zero,498 <main+0x1dc>
     48c:	0000d7b7          	lui	a5,0xd
     490:	8cc78513          	addi	a0,a5,-1844 # c8cc <_etext+0xa2a4>
     494:	20d000ef          	jal	ra,ea0 <printf>
     498:	fcc42783          	lw	a5,-52(s0)
     49c:	fa0788e3          	beq	a5,zero,44c <main+0x190>
     4a0:	fa842783          	lw	a5,-88(s0)
     4a4:	00279793          	slli	a5,a5,0x2
     4a8:	00078613          	addi	a2,a5,0
     4ac:	00000593          	addi	a1,zero,0
     4b0:	fcc42503          	lw	a0,-52(s0)
     4b4:	68d010ef          	jal	ra,2340 <memset>
     4b8:	0000d7b7          	lui	a5,0xd
     4bc:	8fc78513          	addi	a0,a5,-1796 # c8fc <_etext+0xa2d4>
     4c0:	1e1000ef          	jal	ra,ea0 <printf>
     4c4:	370000ef          	jal	ra,834 <get_time>
     4c8:	00050713          	addi	a4,a0,0
     4cc:	00058793          	addi	a5,a1,0
     4d0:	00070793          	addi	a5,a4,0
     4d4:	faf42223          	sw	a5,-92(s0)
     4d8:	fe042223          	sw	zero,-28(s0)
     4dc:	07c0006f          	jal	zero,558 <main+0x29c>
     4e0:	fa440793          	addi	a5,s0,-92
     4e4:	00078513          	addi	a0,a5,0
     4e8:	d7dff0ef          	jal	ra,264 <fast_rand>
     4ec:	00050793          	addi	a5,a0,0
     4f0:	00078693          	addi	a3,a5,0
     4f4:	fe442783          	lw	a5,-28(s0)
     4f8:	00279793          	slli	a5,a5,0x2
     4fc:	fcc42703          	lw	a4,-52(s0)
     500:	00f707b3          	add	a5,a4,a5
     504:	0ff6f713          	andi	a4,a3,255
     508:	00e7a023          	sw	a4,0(a5)
     50c:	fe442783          	lw	a5,-28(s0)
     510:	00279793          	slli	a5,a5,0x2
     514:	fcc42703          	lw	a4,-52(s0)
     518:	00f707b3          	add	a5,a4,a5
     51c:	0007a783          	lw	a5,0(a5)
     520:	00078593          	addi	a1,a5,0
     524:	0000d7b7          	lui	a5,0xd
     528:	87478513          	addi	a0,a5,-1932 # c874 <_etext+0xa24c>
     52c:	175000ef          	jal	ra,ea0 <printf>
     530:	fe442783          	lw	a5,-28(s0)
     534:	0077f713          	andi	a4,a5,7
     538:	00700793          	addi	a5,zero,7
     53c:	00f71863          	bne	a4,a5,54c <main+0x290>
     540:	0000d7b7          	lui	a5,0xd
     544:	91078513          	addi	a0,a5,-1776 # c910 <_etext+0xa2e8>
     548:	159000ef          	jal	ra,ea0 <printf>
     54c:	fe442783          	lw	a5,-28(s0)
     550:	00178793          	addi	a5,a5,1
     554:	fef42223          	sw	a5,-28(s0)
     558:	fa842783          	lw	a5,-88(s0)
     55c:	fe442703          	lw	a4,-28(s0)
     560:	f8f740e3          	blt	a4,a5,4e0 <main+0x224>
     564:	2d0000ef          	jal	ra,834 <get_time>
     568:	fca42c23          	sw	a0,-40(s0)
     56c:	fcb42e23          	sw	a1,-36(s0)
     570:	fa842783          	lw	a5,-88(s0)
     574:	fff78793          	addi	a5,a5,-1
     578:	00078613          	addi	a2,a5,0
     57c:	00000593          	addi	a1,zero,0
     580:	fcc42503          	lw	a0,-52(s0)
     584:	c61ff0ef          	jal	ra,1e4 <quick_sort>
     588:	2ac000ef          	jal	ra,834 <get_time>
     58c:	fca42823          	sw	a0,-48(s0)
     590:	fcb42a23          	sw	a1,-44(s0)
     594:	0000d7b7          	lui	a5,0xd
     598:	91478513          	addi	a0,a5,-1772 # c914 <_etext+0xa2ec>
     59c:	105000ef          	jal	ra,ea0 <printf>
     5a0:	fe042023          	sw	zero,-32(s0)
     5a4:	0500006f          	jal	zero,5f4 <main+0x338>
     5a8:	fe042783          	lw	a5,-32(s0)
     5ac:	00279793          	slli	a5,a5,0x2
     5b0:	fcc42703          	lw	a4,-52(s0)
     5b4:	00f707b3          	add	a5,a4,a5
     5b8:	0007a783          	lw	a5,0(a5)
     5bc:	00078593          	addi	a1,a5,0
     5c0:	0000d7b7          	lui	a5,0xd
     5c4:	87478513          	addi	a0,a5,-1932 # c874 <_etext+0xa24c>
     5c8:	0d9000ef          	jal	ra,ea0 <printf>
     5cc:	fe042783          	lw	a5,-32(s0)
     5d0:	0077f713          	andi	a4,a5,7
     5d4:	00700793          	addi	a5,zero,7
     5d8:	00f71863          	bne	a4,a5,5e8 <main+0x32c>
     5dc:	0000d7b7          	lui	a5,0xd
     5e0:	91078513          	addi	a0,a5,-1776 # c910 <_etext+0xa2e8>
     5e4:	0bd000ef          	jal	ra,ea0 <printf>
     5e8:	fe042783          	lw	a5,-32(s0)
     5ec:	00178793          	addi	a5,a5,1
     5f0:	fef42023          	sw	a5,-32(s0)
     5f4:	fa842783          	lw	a5,-88(s0)
     5f8:	fe042703          	lw	a4,-32(s0)
     5fc:	faf746e3          	blt	a4,a5,5a8 <main+0x2ec>
     600:	fd042703          	lw	a4,-48(s0)
     604:	fd442783          	lw	a5,-44(s0)
     608:	fd842503          	lw	a0,-40(s0)
     60c:	fdc42583          	lw	a1,-36(s0)
     610:	40a70633          	sub	a2,a4,a0
     614:	00060813          	addi	a6,a2,0
     618:	01073833          	sltu	a6,a4,a6
     61c:	40b786b3          	sub	a3,a5,a1
     620:	410687b3          	sub	a5,a3,a6
     624:	00078693          	addi	a3,a5,0
     628:	00060713          	addi	a4,a2,0
     62c:	00068793          	addi	a5,a3,0
     630:	00070513          	addi	a0,a4,0
     634:	00078593          	addi	a1,a5,0
     638:	009010ef          	jal	ra,1e40 <__floatundisf>
     63c:	00050713          	addi	a4,a0,0
     640:	0000d7b7          	lui	a5,0xd
     644:	9387a583          	lw	a1,-1736(a5) # c938 <_etext+0xa310>
     648:	00070513          	addi	a0,a4,0
     64c:	36c010ef          	jal	ra,19b8 <__mulsf3>
     650:	00050793          	addi	a5,a0,0
     654:	00078713          	addi	a4,a5,0
     658:	0000d7b7          	lui	a5,0xd
     65c:	93c7a583          	lw	a1,-1732(a5) # c93c <_etext+0xa314>
     660:	00070513          	addi	a0,a4,0
     664:	701000ef          	jal	ra,1564 <__divsf3>
     668:	00050793          	addi	a5,a0,0
     66c:	00078513          	addi	a0,a5,0
     670:	125010ef          	jal	ra,1f94 <__extendsfdf2>
     674:	00050713          	addi	a4,a0,0
     678:	00058793          	addi	a5,a1,0
     67c:	00070613          	addi	a2,a4,0
     680:	00078693          	addi	a3,a5,0
     684:	0000d7b7          	lui	a5,0xd
     688:	87878513          	addi	a0,a5,-1928 # c878 <_etext+0xa250>
     68c:	015000ef          	jal	ra,ea0 <printf>
     690:	fcc42503          	lw	a0,-52(s0)
     694:	4c9010ef          	jal	ra,235c <__malloc_free>
     698:	0000d7b7          	lui	a5,0xd
     69c:	92478513          	addi	a0,a5,-1756 # c924 <_etext+0xa2fc>
     6a0:	001000ef          	jal	ra,ea0 <printf>
     6a4:	00000793          	addi	a5,zero,0
     6a8:	00078513          	addi	a0,a5,0
     6ac:	05c12083          	lw	ra,92(sp)
     6b0:	05812403          	lw	s0,88(sp)
     6b4:	06010113          	addi	sp,sp,96
     6b8:	00008067          	jalr	zero,0(ra)

000006bc <uart_init>:
     6bc:	ff010113          	addi	sp,sp,-16
     6c0:	00112623          	sw	ra,12(sp)
     6c4:	00812423          	sw	s0,8(sp)
     6c8:	01010413          	addi	s0,sp,16
     6cc:	0000d7b7          	lui	a5,0xd
     6d0:	b0c7a783          	lw	a5,-1268(a5) # cb0c <uart_ctrl_reg>
     6d4:	00300713          	addi	a4,zero,3
     6d8:	00e7a023          	sw	a4,0(a5)
     6dc:	0000d7b7          	lui	a5,0xd
     6e0:	d007aa23          	sw	zero,-748(a5) # cd14 <rx_buf_cnt>
     6e4:	0000d7b7          	lui	a5,0xd
     6e8:	d007ac23          	sw	zero,-744(a5) # cd18 <rx_buf_ptr>
     6ec:	00000013          	addi	zero,zero,0
     6f0:	00c12083          	lw	ra,12(sp)
     6f4:	00812403          	lw	s0,8(sp)
     6f8:	01010113          	addi	sp,sp,16
     6fc:	00008067          	jalr	zero,0(ra)

00000700 <uart_putc>:
     700:	fe010113          	addi	sp,sp,-32
     704:	00112e23          	sw	ra,28(sp)
     708:	00812c23          	sw	s0,24(sp)
     70c:	02010413          	addi	s0,sp,32
     710:	00050793          	addi	a5,a0,0
     714:	fef407a3          	sb	a5,-17(s0)
     718:	00000013          	addi	zero,zero,0
     71c:	0000d7b7          	lui	a5,0xd
     720:	b087a783          	lw	a5,-1272(a5) # cb08 <uart_stat_reg>
     724:	0007a783          	lw	a5,0(a5)
     728:	0087f793          	andi	a5,a5,8
     72c:	fe0798e3          	bne	a5,zero,71c <uart_putc+0x1c>
     730:	0000d7b7          	lui	a5,0xd
     734:	b047a783          	lw	a5,-1276(a5) # cb04 <uart_tx_fifo>
     738:	fef44703          	lbu	a4,-17(s0)
     73c:	00e7a023          	sw	a4,0(a5)
     740:	00000013          	addi	zero,zero,0
     744:	01c12083          	lw	ra,28(sp)
     748:	01812403          	lw	s0,24(sp)
     74c:	02010113          	addi	sp,sp,32
     750:	00008067          	jalr	zero,0(ra)

00000754 <uart_getc>:
     754:	ff010113          	addi	sp,sp,-16
     758:	00112623          	sw	ra,12(sp)
     75c:	00812423          	sw	s0,8(sp)
     760:	01010413          	addi	s0,sp,16
     764:	0000d7b7          	lui	a5,0xd
     768:	d187a703          	lw	a4,-744(a5) # cd18 <rx_buf_ptr>
     76c:	0000d7b7          	lui	a5,0xd
     770:	d147a783          	lw	a5,-748(a5) # cd14 <rx_buf_cnt>
     774:	08f74463          	blt	a4,a5,7fc <uart_getc+0xa8>
     778:	0000d7b7          	lui	a5,0xd
     77c:	d007ac23          	sw	zero,-744(a5) # cd18 <rx_buf_ptr>
     780:	0000d7b7          	lui	a5,0xd
     784:	d007aa23          	sw	zero,-748(a5) # cd14 <rx_buf_cnt>
     788:	00000013          	addi	zero,zero,0
     78c:	0000d7b7          	lui	a5,0xd
     790:	b087a783          	lw	a5,-1272(a5) # cb08 <uart_stat_reg>
     794:	0007a783          	lw	a5,0(a5)
     798:	0017f793          	andi	a5,a5,1
     79c:	fe0788e3          	beq	a5,zero,78c <uart_getc+0x38>
     7a0:	0380006f          	jal	zero,7d8 <uart_getc+0x84>
     7a4:	0000d7b7          	lui	a5,0xd
     7a8:	b007a783          	lw	a5,-1280(a5) # cb00 <uart_rx_fifo>
     7ac:	0007a603          	lw	a2,0(a5)
     7b0:	0000d7b7          	lui	a5,0xd
     7b4:	d147a783          	lw	a5,-748(a5) # cd14 <rx_buf_cnt>
     7b8:	00178693          	addi	a3,a5,1
     7bc:	0000d737          	lui	a4,0xd
     7c0:	d0d72a23          	sw	a3,-748(a4) # cd14 <rx_buf_cnt>
     7c4:	0ff67713          	andi	a4,a2,255
     7c8:	0000d6b7          	lui	a3,0xd
     7cc:	b1468693          	addi	a3,a3,-1260 # cb14 <rx_buf>
     7d0:	00f687b3          	add	a5,a3,a5
     7d4:	00e78023          	sb	a4,0(a5)
     7d8:	0000d7b7          	lui	a5,0xd
     7dc:	b087a783          	lw	a5,-1272(a5) # cb08 <uart_stat_reg>
     7e0:	0007a783          	lw	a5,0(a5)
     7e4:	0017f793          	andi	a5,a5,1
     7e8:	00078a63          	beq	a5,zero,7fc <uart_getc+0xa8>
     7ec:	0000d7b7          	lui	a5,0xd
     7f0:	d147a703          	lw	a4,-748(a5) # cd14 <rx_buf_cnt>
     7f4:	1ff00793          	addi	a5,zero,511
     7f8:	fae7d6e3          	bge	a5,a4,7a4 <uart_getc+0x50>
     7fc:	0000d7b7          	lui	a5,0xd
     800:	d187a783          	lw	a5,-744(a5) # cd18 <rx_buf_ptr>
     804:	00178693          	addi	a3,a5,1
     808:	0000d737          	lui	a4,0xd
     80c:	d0d72c23          	sw	a3,-744(a4) # cd18 <rx_buf_ptr>
     810:	0000d737          	lui	a4,0xd
     814:	b1470713          	addi	a4,a4,-1260 # cb14 <rx_buf>
     818:	00f707b3          	add	a5,a4,a5
     81c:	0007c783          	lbu	a5,0(a5)
     820:	00078513          	addi	a0,a5,0
     824:	00c12083          	lw	ra,12(sp)
     828:	00812403          	lw	s0,8(sp)
     82c:	01010113          	addi	sp,sp,16
     830:	00008067          	jalr	zero,0(ra)

00000834 <get_time>:
     834:	fe010113          	addi	sp,sp,-32
     838:	00112e23          	sw	ra,28(sp)
     83c:	00812c23          	sw	s0,24(sp)
     840:	02010413          	addi	s0,sp,32
     844:	0000d837          	lui	a6,0xd
     848:	af882803          	lw	a6,-1288(a6) # caf8 <timer_low>
     84c:	00082803          	lw	a6,0(a6)
     850:	ff042423          	sw	a6,-24(s0)
     854:	fe042623          	sw	zero,-20(s0)
     858:	0000d837          	lui	a6,0xd
     85c:	afc82803          	lw	a6,-1284(a6) # cafc <timer_high>
     860:	00082803          	lw	a6,0(a6)
     864:	ff042023          	sw	a6,-32(s0)
     868:	fe042223          	sw	zero,-28(s0)
     86c:	fe042803          	lw	a6,-32(s0)
     870:	00081693          	slli	a3,a6,0x0
     874:	00000613          	addi	a2,zero,0
     878:	fe842803          	lw	a6,-24(s0)
     87c:	fff87713          	andi	a4,a6,-1
     880:	fec42803          	lw	a6,-20(s0)
     884:	00087793          	andi	a5,a6,0
     888:	00e66533          	or	a0,a2,a4
     88c:	00f6e5b3          	or	a1,a3,a5
     890:	00050713          	addi	a4,a0,0
     894:	00058793          	addi	a5,a1,0
     898:	00070513          	addi	a0,a4,0
     89c:	00078593          	addi	a1,a5,0
     8a0:	01c12083          	lw	ra,28(sp)
     8a4:	01812403          	lw	s0,24(sp)
     8a8:	02010113          	addi	sp,sp,32
     8ac:	00008067          	jalr	zero,0(ra)

000008b0 <delay_ms>:
     8b0:	fc010113          	addi	sp,sp,-64
     8b4:	02112e23          	sw	ra,60(sp)
     8b8:	02812c23          	sw	s0,56(sp)
     8bc:	04010413          	addi	s0,sp,64
     8c0:	fca42623          	sw	a0,-52(s0)
     8c4:	f71ff0ef          	jal	ra,834 <get_time>
     8c8:	fea42423          	sw	a0,-24(s0)
     8cc:	feb42623          	sw	a1,-20(s0)
     8d0:	fe842703          	lw	a4,-24(s0)
     8d4:	fec42783          	lw	a5,-20(s0)
     8d8:	fee42023          	sw	a4,-32(s0)
     8dc:	fef42223          	sw	a5,-28(s0)
     8e0:	00000793          	addi	a5,zero,0
     8e4:	fcf42e23          	sw	a5,-36(s0)
     8e8:	f4dff0ef          	jal	ra,834 <get_time>
     8ec:	fea42023          	sw	a0,-32(s0)
     8f0:	feb42223          	sw	a1,-28(s0)
     8f4:	fe042703          	lw	a4,-32(s0)
     8f8:	fe442783          	lw	a5,-28(s0)
     8fc:	fe842503          	lw	a0,-24(s0)
     900:	fec42583          	lw	a1,-20(s0)
     904:	40a70633          	sub	a2,a4,a0
     908:	00060813          	addi	a6,a2,0
     90c:	01073833          	sltu	a6,a4,a6
     910:	40b786b3          	sub	a3,a5,a1
     914:	410687b3          	sub	a5,a3,a6
     918:	00078693          	addi	a3,a5,0
     91c:	00060713          	addi	a4,a2,0
     920:	00068793          	addi	a5,a3,0
     924:	00070513          	addi	a0,a4,0
     928:	00078593          	addi	a1,a5,0
     92c:	514010ef          	jal	ra,1e40 <__floatundisf>
     930:	00050713          	addi	a4,a0,0
     934:	0000d7b7          	lui	a5,0xd
     938:	9ac7a583          	lw	a1,-1620(a5) # c9ac <_etext+0xa384>
     93c:	00070513          	addi	a0,a4,0
     940:	078010ef          	jal	ra,19b8 <__mulsf3>
     944:	00050793          	addi	a5,a0,0
     948:	00078713          	addi	a4,a5,0
     94c:	0000d7b7          	lui	a5,0xd
     950:	9b07a583          	lw	a1,-1616(a5) # c9b0 <_etext+0xa388>
     954:	00070513          	addi	a0,a4,0
     958:	40d000ef          	jal	ra,1564 <__divsf3>
     95c:	00050793          	addi	a5,a0,0
     960:	fcf42e23          	sw	a5,-36(s0)
     964:	fcc42503          	lw	a0,-52(s0)
     968:	3c8010ef          	jal	ra,1d30 <__floatsisf>
     96c:	00050793          	addi	a5,a0,0
     970:	00078593          	addi	a1,a5,0
     974:	fdc42503          	lw	a0,-36(s0)
     978:	701000ef          	jal	ra,1878 <__gesf2>
     97c:	00050793          	addi	a5,a0,0
     980:	00f04463          	blt	zero,a5,988 <delay_ms+0xd8>
     984:	f65ff06f          	jal	zero,8e8 <delay_ms+0x38>
     988:	00000013          	addi	zero,zero,0
     98c:	00000013          	addi	zero,zero,0
     990:	03c12083          	lw	ra,60(sp)
     994:	03812403          	lw	s0,56(sp)
     998:	04010113          	addi	sp,sp,64
     99c:	00008067          	jalr	zero,0(ra)

000009a0 <print_char>:
     9a0:	fe010113          	addi	sp,sp,-32
     9a4:	00112e23          	sw	ra,28(sp)
     9a8:	00812c23          	sw	s0,24(sp)
     9ac:	02010413          	addi	s0,sp,32
     9b0:	00050793          	addi	a5,a0,0
     9b4:	fef407a3          	sb	a5,-17(s0)
     9b8:	fef44783          	lbu	a5,-17(s0)
     9bc:	00078513          	addi	a0,a5,0
     9c0:	d41ff0ef          	jal	ra,700 <uart_putc>
     9c4:	fef44703          	lbu	a4,-17(s0)
     9c8:	00a00793          	addi	a5,zero,10
     9cc:	00f71663          	bne	a4,a5,9d8 <print_char+0x38>
     9d0:	00d00513          	addi	a0,zero,13
     9d4:	d2dff0ef          	jal	ra,700 <uart_putc>
     9d8:	00000013          	addi	zero,zero,0
     9dc:	01c12083          	lw	ra,28(sp)
     9e0:	01812403          	lw	s0,24(sp)
     9e4:	02010113          	addi	sp,sp,32
     9e8:	00008067          	jalr	zero,0(ra)

000009ec <print_string>:
     9ec:	fe010113          	addi	sp,sp,-32
     9f0:	00112e23          	sw	ra,28(sp)
     9f4:	00812c23          	sw	s0,24(sp)
     9f8:	02010413          	addi	s0,sp,32
     9fc:	fea42623          	sw	a0,-20(s0)
     a00:	01c0006f          	jal	zero,a1c <print_string+0x30>
     a04:	fec42783          	lw	a5,-20(s0)
     a08:	00178713          	addi	a4,a5,1
     a0c:	fee42623          	sw	a4,-20(s0)
     a10:	0007c783          	lbu	a5,0(a5)
     a14:	00078513          	addi	a0,a5,0
     a18:	f89ff0ef          	jal	ra,9a0 <print_char>
     a1c:	fec42783          	lw	a5,-20(s0)
     a20:	0007c783          	lbu	a5,0(a5)
     a24:	fe0790e3          	bne	a5,zero,a04 <print_string+0x18>
     a28:	00000013          	addi	zero,zero,0
     a2c:	00000013          	addi	zero,zero,0
     a30:	01c12083          	lw	ra,28(sp)
     a34:	01812403          	lw	s0,24(sp)
     a38:	02010113          	addi	sp,sp,32
     a3c:	00008067          	jalr	zero,0(ra)

00000a40 <print_number>:
     a40:	fa010113          	addi	sp,sp,-96
     a44:	04112e23          	sw	ra,92(sp)
     a48:	04812c23          	sw	s0,88(sp)
     a4c:	06010413          	addi	s0,sp,96
     a50:	faa42623          	sw	a0,-84(s0)
     a54:	fab42423          	sw	a1,-88(s0)
     a58:	fac42223          	sw	a2,-92(s0)
     a5c:	fcc40793          	addi	a5,s0,-52
     a60:	fef42623          	sw	a5,-20(s0)
     a64:	0000d7b7          	lui	a5,0xd
     a68:	94078793          	addi	a5,a5,-1728 # c940 <_etext+0xa318>
     a6c:	0007a583          	lw	a1,0(a5)
     a70:	0047a603          	lw	a2,4(a5)
     a74:	0087a683          	lw	a3,8(a5)
     a78:	00c7a703          	lw	a4,12(a5)
     a7c:	fab42c23          	sw	a1,-72(s0)
     a80:	fac42e23          	sw	a2,-68(s0)
     a84:	fcd42023          	sw	a3,-64(s0)
     a88:	fce42223          	sw	a4,-60(s0)
     a8c:	0107c783          	lbu	a5,16(a5)
     a90:	fcf40423          	sb	a5,-56(s0)
     a94:	fa442783          	lw	a5,-92(s0)
     a98:	02078063          	beq	a5,zero,ab8 <print_number+0x78>
     a9c:	fac42783          	lw	a5,-84(s0)
     aa0:	0007dc63          	bge	a5,zero,ab8 <print_number+0x78>
     aa4:	02d00513          	addi	a0,zero,45
     aa8:	ef9ff0ef          	jal	ra,9a0 <print_char>
     aac:	fac42783          	lw	a5,-84(s0)
     ab0:	40f007b3          	sub	a5,zero,a5
     ab4:	faf42623          	sw	a5,-84(s0)
     ab8:	fac42703          	lw	a4,-84(s0)
     abc:	fa842783          	lw	a5,-88(s0)
     ac0:	02f77733          	remu	a4,a4,a5
     ac4:	fec42783          	lw	a5,-20(s0)
     ac8:	00178693          	addi	a3,a5,1
     acc:	fed42623          	sw	a3,-20(s0)
     ad0:	ff070713          	addi	a4,a4,-16
     ad4:	00870733          	add	a4,a4,s0
     ad8:	fc874703          	lbu	a4,-56(a4)
     adc:	00e78023          	sb	a4,0(a5)
     ae0:	fac42703          	lw	a4,-84(s0)
     ae4:	fa842783          	lw	a5,-88(s0)
     ae8:	02f757b3          	divu	a5,a4,a5
     aec:	faf42623          	sw	a5,-84(s0)
     af0:	fac42783          	lw	a5,-84(s0)
     af4:	fc0792e3          	bne	a5,zero,ab8 <print_number+0x78>
     af8:	0200006f          	jal	zero,b18 <print_number+0xd8>
     afc:	fec42783          	lw	a5,-20(s0)
     b00:	fff78793          	addi	a5,a5,-1
     b04:	fef42623          	sw	a5,-20(s0)
     b08:	fec42783          	lw	a5,-20(s0)
     b0c:	0007c783          	lbu	a5,0(a5)
     b10:	00078513          	addi	a0,a5,0
     b14:	e8dff0ef          	jal	ra,9a0 <print_char>
     b18:	fcc40793          	addi	a5,s0,-52
     b1c:	fec42703          	lw	a4,-20(s0)
     b20:	fce7eee3          	bltu	a5,a4,afc <print_number+0xbc>
     b24:	00000013          	addi	zero,zero,0
     b28:	00000013          	addi	zero,zero,0
     b2c:	05c12083          	lw	ra,92(sp)
     b30:	05812403          	lw	s0,88(sp)
     b34:	06010113          	addi	sp,sp,96
     b38:	00008067          	jalr	zero,0(ra)

00000b3c <print_float>:
     b3c:	fc010113          	addi	sp,sp,-64
     b40:	02112e23          	sw	ra,60(sp)
     b44:	02812c23          	sw	s0,56(sp)
     b48:	04010413          	addi	s0,sp,64
     b4c:	fca42623          	sw	a0,-52(s0)
     b50:	fcb42423          	sw	a1,-56(s0)
     b54:	fc842783          	lw	a5,-56(s0)
     b58:	0007c863          	blt	a5,zero,b68 <print_float+0x2c>
     b5c:	fc842703          	lw	a4,-56(s0)
     b60:	00600793          	addi	a5,zero,6
     b64:	00e7d663          	bge	a5,a4,b70 <print_float+0x34>
     b68:	00600793          	addi	a5,zero,6
     b6c:	fcf42423          	sw	a5,-56(s0)
     b70:	00000593          	addi	a1,zero,0
     b74:	fcc42503          	lw	a0,-52(s0)
     b78:	5a1000ef          	jal	ra,1918 <__lesf2>
     b7c:	00050793          	addi	a5,a0,0
     b80:	0007de63          	bge	a5,zero,b9c <print_float+0x60>
     b84:	02d00513          	addi	a0,zero,45
     b88:	b79ff0ef          	jal	ra,700 <uart_putc>
     b8c:	fcc42703          	lw	a4,-52(s0)
     b90:	800007b7          	lui	a5,0x80000
     b94:	00f747b3          	xor	a5,a4,a5
     b98:	fcf42623          	sw	a5,-52(s0)
     b9c:	0000d7b7          	lui	a5,0xd
     ba0:	9b47a583          	lw	a1,-1612(a5) # c9b4 <_etext+0xa38c>
     ba4:	fcc42503          	lw	a0,-52(s0)
     ba8:	611000ef          	jal	ra,19b8 <__mulsf3>
     bac:	00050793          	addi	a5,a0,0
     bb0:	fef42223          	sw	a5,-28(s0)
     bb4:	fcc42503          	lw	a0,-52(s0)
     bb8:	110010ef          	jal	ra,1cc8 <__fixunssfsi>
     bbc:	00050793          	addi	a5,a0,0
     bc0:	fef42023          	sw	a5,-32(s0)
     bc4:	fe442503          	lw	a0,-28(s0)
     bc8:	100010ef          	jal	ra,1cc8 <__fixunssfsi>
     bcc:	00050693          	addi	a3,a0,0
     bd0:	fe042703          	lw	a4,-32(s0)
     bd4:	000f47b7          	lui	a5,0xf4
     bd8:	24078793          	addi	a5,a5,576 # f4240 <__heap_end+0xcea40>
     bdc:	02f707b3          	mul	a5,a4,a5
     be0:	40f687b3          	sub	a5,a3,a5
     be4:	fef42623          	sw	a5,-20(s0)
     be8:	00000613          	addi	a2,zero,0
     bec:	00a00593          	addi	a1,zero,10
     bf0:	fe042503          	lw	a0,-32(s0)
     bf4:	e4dff0ef          	jal	ra,a40 <print_number>
     bf8:	fc842783          	lw	a5,-56(s0)
     bfc:	00f04663          	blt	zero,a5,c08 <print_float+0xcc>
     c00:	fec42783          	lw	a5,-20(s0)
     c04:	00078663          	beq	a5,zero,c10 <print_float+0xd4>
     c08:	02e00513          	addi	a0,zero,46
     c0c:	af5ff0ef          	jal	ra,700 <uart_putc>
     c10:	fc042c23          	sw	zero,-40(s0)
     c14:	fc041e23          	sh	zero,-36(s0)
     c18:	fc040f23          	sb	zero,-34(s0)
     c1c:	00500793          	addi	a5,zero,5
     c20:	fef42423          	sw	a5,-24(s0)
     c24:	06c0006f          	jal	zero,c90 <print_float+0x154>
     c28:	fec42683          	lw	a3,-20(s0)
     c2c:	ccccd7b7          	lui	a5,0xccccd
     c30:	ccd78793          	addi	a5,a5,-819 # cccccccd <__heap_end+0xccca74cd>
     c34:	02f6b7b3          	mulhu	a5,a3,a5
     c38:	0037d713          	srli	a4,a5,0x3
     c3c:	00070793          	addi	a5,a4,0
     c40:	00279793          	slli	a5,a5,0x2
     c44:	00e787b3          	add	a5,a5,a4
     c48:	00179793          	slli	a5,a5,0x1
     c4c:	40f68733          	sub	a4,a3,a5
     c50:	0ff77793          	andi	a5,a4,255
     c54:	03078793          	addi	a5,a5,48
     c58:	0ff7f713          	andi	a4,a5,255
     c5c:	fe842783          	lw	a5,-24(s0)
     c60:	ff078793          	addi	a5,a5,-16
     c64:	008787b3          	add	a5,a5,s0
     c68:	fee78423          	sb	a4,-24(a5)
     c6c:	fec42703          	lw	a4,-20(s0)
     c70:	ccccd7b7          	lui	a5,0xccccd
     c74:	ccd78793          	addi	a5,a5,-819 # cccccccd <__heap_end+0xccca74cd>
     c78:	02f737b3          	mulhu	a5,a4,a5
     c7c:	0037d793          	srli	a5,a5,0x3
     c80:	fef42623          	sw	a5,-20(s0)
     c84:	fe842783          	lw	a5,-24(s0)
     c88:	fff78793          	addi	a5,a5,-1
     c8c:	fef42423          	sw	a5,-24(s0)
     c90:	fe842783          	lw	a5,-24(s0)
     c94:	f807dae3          	bge	a5,zero,c28 <print_float+0xec>
     c98:	fc842783          	lw	a5,-56(s0)
     c9c:	ff078793          	addi	a5,a5,-16
     ca0:	008787b3          	add	a5,a5,s0
     ca4:	fe078423          	sb	zero,-24(a5)
     ca8:	fd840793          	addi	a5,s0,-40
     cac:	00078513          	addi	a0,a5,0
     cb0:	d3dff0ef          	jal	ra,9ec <print_string>
     cb4:	00000013          	addi	zero,zero,0
     cb8:	03c12083          	lw	ra,60(sp)
     cbc:	03812403          	lw	s0,56(sp)
     cc0:	04010113          	addi	sp,sp,64
     cc4:	00008067          	jalr	zero,0(ra)

00000cc8 <vprintf>:
     cc8:	fd010113          	addi	sp,sp,-48
     ccc:	02112623          	sw	ra,44(sp)
     cd0:	02812423          	sw	s0,40(sp)
     cd4:	03010413          	addi	s0,sp,48
     cd8:	fca42e23          	sw	a0,-36(s0)
     cdc:	fcb42c23          	sw	a1,-40(s0)
     ce0:	fdc42783          	lw	a5,-36(s0)
     ce4:	fef42623          	sw	a5,-20(s0)
     ce8:	1840006f          	jal	zero,e6c <vprintf+0x1a4>
     cec:	feb44703          	lbu	a4,-21(s0)
     cf0:	02500793          	addi	a5,zero,37
     cf4:	00f70a63          	beq	a4,a5,d08 <vprintf+0x40>
     cf8:	feb44783          	lbu	a5,-21(s0)
     cfc:	00078513          	addi	a0,a5,0
     d00:	ca1ff0ef          	jal	ra,9a0 <print_char>
     d04:	1680006f          	jal	zero,e6c <vprintf+0x1a4>
     d08:	fec42783          	lw	a5,-20(s0)
     d0c:	00178713          	addi	a4,a5,1
     d10:	fee42623          	sw	a4,-20(s0)
     d14:	0007c783          	lbu	a5,0(a5)
     d18:	fef405a3          	sb	a5,-21(s0)
     d1c:	feb44783          	lbu	a5,-21(s0)
     d20:	02500713          	addi	a4,zero,37
     d24:	12e78263          	beq	a5,a4,e48 <vprintf+0x180>
     d28:	02500713          	addi	a4,zero,37
     d2c:	12e7c463          	blt	a5,a4,e54 <vprintf+0x18c>
     d30:	07800713          	addi	a4,zero,120
     d34:	12f74063          	blt	a4,a5,e54 <vprintf+0x18c>
     d38:	06300713          	addi	a4,zero,99
     d3c:	10e7cc63          	blt	a5,a4,e54 <vprintf+0x18c>
     d40:	f9d78793          	addi	a5,a5,-99
     d44:	01500713          	addi	a4,zero,21
     d48:	10f76663          	bltu	a4,a5,e54 <vprintf+0x18c>
     d4c:	00279713          	slli	a4,a5,0x2
     d50:	0000d7b7          	lui	a5,0xd
     d54:	95478793          	addi	a5,a5,-1708 # c954 <_etext+0xa32c>
     d58:	00f707b3          	add	a5,a4,a5
     d5c:	0007a783          	lw	a5,0(a5)
     d60:	00078067          	jalr	zero,0(a5)
     d64:	fd842783          	lw	a5,-40(s0)
     d68:	00478713          	addi	a4,a5,4
     d6c:	fce42c23          	sw	a4,-40(s0)
     d70:	0007a783          	lw	a5,0(a5)
     d74:	0ff7f793          	andi	a5,a5,255
     d78:	00078513          	addi	a0,a5,0
     d7c:	c25ff0ef          	jal	ra,9a0 <print_char>
     d80:	0ec0006f          	jal	zero,e6c <vprintf+0x1a4>
     d84:	fd842783          	lw	a5,-40(s0)
     d88:	00478713          	addi	a4,a5,4
     d8c:	fce42c23          	sw	a4,-40(s0)
     d90:	0007a783          	lw	a5,0(a5)
     d94:	00078513          	addi	a0,a5,0
     d98:	c55ff0ef          	jal	ra,9ec <print_string>
     d9c:	0d00006f          	jal	zero,e6c <vprintf+0x1a4>
     da0:	fd842783          	lw	a5,-40(s0)
     da4:	00478713          	addi	a4,a5,4
     da8:	fce42c23          	sw	a4,-40(s0)
     dac:	0007a783          	lw	a5,0(a5)
     db0:	00100613          	addi	a2,zero,1
     db4:	00a00593          	addi	a1,zero,10
     db8:	00078513          	addi	a0,a5,0
     dbc:	c85ff0ef          	jal	ra,a40 <print_number>
     dc0:	0ac0006f          	jal	zero,e6c <vprintf+0x1a4>
     dc4:	fd842783          	lw	a5,-40(s0)
     dc8:	00478713          	addi	a4,a5,4
     dcc:	fce42c23          	sw	a4,-40(s0)
     dd0:	0007a783          	lw	a5,0(a5)
     dd4:	00000613          	addi	a2,zero,0
     dd8:	00a00593          	addi	a1,zero,10
     ddc:	00078513          	addi	a0,a5,0
     de0:	c61ff0ef          	jal	ra,a40 <print_number>
     de4:	0880006f          	jal	zero,e6c <vprintf+0x1a4>
     de8:	fd842783          	lw	a5,-40(s0)
     dec:	00478713          	addi	a4,a5,4
     df0:	fce42c23          	sw	a4,-40(s0)
     df4:	0007a783          	lw	a5,0(a5)
     df8:	00000613          	addi	a2,zero,0
     dfc:	01000593          	addi	a1,zero,16
     e00:	00078513          	addi	a0,a5,0
     e04:	c3dff0ef          	jal	ra,a40 <print_number>
     e08:	0640006f          	jal	zero,e6c <vprintf+0x1a4>
     e0c:	fd842783          	lw	a5,-40(s0)
     e10:	00778793          	addi	a5,a5,7
     e14:	ff87f793          	andi	a5,a5,-8
     e18:	00878713          	addi	a4,a5,8
     e1c:	fce42c23          	sw	a4,-40(s0)
     e20:	0007a703          	lw	a4,0(a5)
     e24:	0047a783          	lw	a5,4(a5)
     e28:	00070513          	addi	a0,a4,0
     e2c:	00078593          	addi	a1,a5,0
     e30:	250010ef          	jal	ra,2080 <__truncdfsf2>
     e34:	00050793          	addi	a5,a0,0
     e38:	00600593          	addi	a1,zero,6
     e3c:	00078513          	addi	a0,a5,0
     e40:	cfdff0ef          	jal	ra,b3c <print_float>
     e44:	0280006f          	jal	zero,e6c <vprintf+0x1a4>
     e48:	02500513          	addi	a0,zero,37
     e4c:	b55ff0ef          	jal	ra,9a0 <print_char>
     e50:	01c0006f          	jal	zero,e6c <vprintf+0x1a4>
     e54:	02500513          	addi	a0,zero,37
     e58:	b49ff0ef          	jal	ra,9a0 <print_char>
     e5c:	feb44783          	lbu	a5,-21(s0)
     e60:	00078513          	addi	a0,a5,0
     e64:	b3dff0ef          	jal	ra,9a0 <print_char>
     e68:	00000013          	addi	zero,zero,0
     e6c:	fec42783          	lw	a5,-20(s0)
     e70:	00178713          	addi	a4,a5,1
     e74:	fee42623          	sw	a4,-20(s0)
     e78:	0007c783          	lbu	a5,0(a5)
     e7c:	fef405a3          	sb	a5,-21(s0)
     e80:	feb44783          	lbu	a5,-21(s0)
     e84:	e60794e3          	bne	a5,zero,cec <vprintf+0x24>
     e88:	00000793          	addi	a5,zero,0
     e8c:	00078513          	addi	a0,a5,0
     e90:	02c12083          	lw	ra,44(sp)
     e94:	02812403          	lw	s0,40(sp)
     e98:	03010113          	addi	sp,sp,48
     e9c:	00008067          	jalr	zero,0(ra)

00000ea0 <printf>:
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
     ef0:	dd9ff0ef          	jal	ra,cc8 <vprintf>
     ef4:	fea42623          	sw	a0,-20(s0)
     ef8:	fec42783          	lw	a5,-20(s0)
     efc:	00078513          	addi	a0,a5,0
     f00:	02c12083          	lw	ra,44(sp)
     f04:	02812403          	lw	s0,40(sp)
     f08:	05010113          	addi	sp,sp,80
     f0c:	00008067          	jalr	zero,0(ra)

00000f10 <readline>:
     f10:	fd010113          	addi	sp,sp,-48
     f14:	02112623          	sw	ra,44(sp)
     f18:	02812423          	sw	s0,40(sp)
     f1c:	03010413          	addi	s0,sp,48
     f20:	fca42e23          	sw	a0,-36(s0)
     f24:	fcb42c23          	sw	a1,-40(s0)
     f28:	fdc42783          	lw	a5,-36(s0)
     f2c:	fef42623          	sw	a5,-20(s0)
     f30:	825ff0ef          	jal	ra,754 <uart_getc>
     f34:	00050793          	addi	a5,a0,0
     f38:	fef405a3          	sb	a5,-21(s0)
     f3c:	feb44703          	lbu	a4,-21(s0)
     f40:	00d00793          	addi	a5,zero,13
     f44:	00f70863          	beq	a4,a5,f54 <readline+0x44>
     f48:	feb44703          	lbu	a4,-21(s0)
     f4c:	00a00793          	addi	a5,zero,10
     f50:	00f71c63          	bne	a4,a5,f68 <readline+0x58>
     f54:	00a00513          	addi	a0,zero,10
     f58:	a49ff0ef          	jal	ra,9a0 <print_char>
     f5c:	fec42783          	lw	a5,-20(s0)
     f60:	00078023          	sb	zero,0(a5)
     f64:	08c0006f          	jal	zero,ff0 <readline+0xe0>
     f68:	feb44703          	lbu	a4,-21(s0)
     f6c:	00800793          	addi	a5,zero,8
     f70:	00f70863          	beq	a4,a5,f80 <readline+0x70>
     f74:	feb44703          	lbu	a4,-21(s0)
     f78:	07f00793          	addi	a5,zero,127
     f7c:	02f71c63          	bne	a4,a5,fb4 <readline+0xa4>
     f80:	fec42703          	lw	a4,-20(s0)
     f84:	fdc42783          	lw	a5,-36(s0)
     f88:	02e7f663          	bgeu	a5,a4,fb4 <readline+0xa4>
     f8c:	fec42783          	lw	a5,-20(s0)
     f90:	fff78793          	addi	a5,a5,-1
     f94:	fef42623          	sw	a5,-20(s0)
     f98:	00800513          	addi	a0,zero,8
     f9c:	a05ff0ef          	jal	ra,9a0 <print_char>
     fa0:	02000513          	addi	a0,zero,32
     fa4:	9fdff0ef          	jal	ra,9a0 <print_char>
     fa8:	00800513          	addi	a0,zero,8
     fac:	9f5ff0ef          	jal	ra,9a0 <print_char>
     fb0:	03c0006f          	jal	zero,fec <readline+0xdc>
     fb4:	fec42703          	lw	a4,-20(s0)
     fb8:	fdc42783          	lw	a5,-36(s0)
     fbc:	40f70733          	sub	a4,a4,a5
     fc0:	fd842783          	lw	a5,-40(s0)
     fc4:	fff78793          	addi	a5,a5,-1
     fc8:	f6f754e3          	bge	a4,a5,f30 <readline+0x20>
     fcc:	feb44783          	lbu	a5,-21(s0)
     fd0:	00078513          	addi	a0,a5,0
     fd4:	9cdff0ef          	jal	ra,9a0 <print_char>
     fd8:	fec42783          	lw	a5,-20(s0)
     fdc:	00178713          	addi	a4,a5,1
     fe0:	fee42623          	sw	a4,-20(s0)
     fe4:	feb44703          	lbu	a4,-21(s0)
     fe8:	00e78023          	sb	a4,0(a5)
     fec:	f45ff06f          	jal	zero,f30 <readline+0x20>
     ff0:	02c12083          	lw	ra,44(sp)
     ff4:	02812403          	lw	s0,40(sp)
     ff8:	03010113          	addi	sp,sp,48
     ffc:	00008067          	jalr	zero,0(ra)

00001000 <str2int>:
    1000:	fd010113          	addi	sp,sp,-48
    1004:	02112623          	sw	ra,44(sp)
    1008:	02812423          	sw	s0,40(sp)
    100c:	03010413          	addi	s0,sp,48
    1010:	fca42e23          	sw	a0,-36(s0)
    1014:	fdc42783          	lw	a5,-36(s0)
    1018:	0007a783          	lw	a5,0(a5)
    101c:	fef42623          	sw	a5,-20(s0)
    1020:	fe042423          	sw	zero,-24(s0)
    1024:	00100793          	addi	a5,zero,1
    1028:	fef42223          	sw	a5,-28(s0)
    102c:	0100006f          	jal	zero,103c <str2int+0x3c>
    1030:	fec42783          	lw	a5,-20(s0)
    1034:	00178793          	addi	a5,a5,1
    1038:	fef42623          	sw	a5,-20(s0)
    103c:	fec42783          	lw	a5,-20(s0)
    1040:	0007c703          	lbu	a4,0(a5)
    1044:	02000793          	addi	a5,zero,32
    1048:	fef704e3          	beq	a4,a5,1030 <str2int+0x30>
    104c:	fec42783          	lw	a5,-20(s0)
    1050:	0007c703          	lbu	a4,0(a5)
    1054:	00900793          	addi	a5,zero,9
    1058:	fcf70ce3          	beq	a4,a5,1030 <str2int+0x30>
    105c:	fec42783          	lw	a5,-20(s0)
    1060:	0007c703          	lbu	a4,0(a5)
    1064:	02d00793          	addi	a5,zero,45
    1068:	00f71e63          	bne	a4,a5,1084 <str2int+0x84>
    106c:	fff00793          	addi	a5,zero,-1
    1070:	fef42223          	sw	a5,-28(s0)
    1074:	fec42783          	lw	a5,-20(s0)
    1078:	00178793          	addi	a5,a5,1
    107c:	fef42623          	sw	a5,-20(s0)
    1080:	0580006f          	jal	zero,10d8 <str2int+0xd8>
    1084:	fec42783          	lw	a5,-20(s0)
    1088:	0007c703          	lbu	a4,0(a5)
    108c:	02b00793          	addi	a5,zero,43
    1090:	04f71463          	bne	a4,a5,10d8 <str2int+0xd8>
    1094:	fec42783          	lw	a5,-20(s0)
    1098:	00178793          	addi	a5,a5,1
    109c:	fef42623          	sw	a5,-20(s0)
    10a0:	0380006f          	jal	zero,10d8 <str2int+0xd8>
    10a4:	fe842783          	lw	a5,-24(s0)
    10a8:	00379713          	slli	a4,a5,0x3
    10ac:	fe842783          	lw	a5,-24(s0)
    10b0:	00179793          	slli	a5,a5,0x1
    10b4:	00f70733          	add	a4,a4,a5
    10b8:	fec42783          	lw	a5,-20(s0)
    10bc:	0007c783          	lbu	a5,0(a5)
    10c0:	fd078793          	addi	a5,a5,-48
    10c4:	00f707b3          	add	a5,a4,a5
    10c8:	fef42423          	sw	a5,-24(s0)
    10cc:	fec42783          	lw	a5,-20(s0)
    10d0:	00178793          	addi	a5,a5,1
    10d4:	fef42623          	sw	a5,-20(s0)
    10d8:	fec42783          	lw	a5,-20(s0)
    10dc:	0007c703          	lbu	a4,0(a5)
    10e0:	02f00793          	addi	a5,zero,47
    10e4:	00e7fa63          	bgeu	a5,a4,10f8 <str2int+0xf8>
    10e8:	fec42783          	lw	a5,-20(s0)
    10ec:	0007c703          	lbu	a4,0(a5)
    10f0:	03900793          	addi	a5,zero,57
    10f4:	fae7f8e3          	bgeu	a5,a4,10a4 <str2int+0xa4>
    10f8:	fdc42783          	lw	a5,-36(s0)
    10fc:	fec42703          	lw	a4,-20(s0)
    1100:	00e7a023          	sw	a4,0(a5)
    1104:	fe842703          	lw	a4,-24(s0)
    1108:	fe442783          	lw	a5,-28(s0)
    110c:	02f707b3          	mul	a5,a4,a5
    1110:	00078513          	addi	a0,a5,0
    1114:	02c12083          	lw	ra,44(sp)
    1118:	02812403          	lw	s0,40(sp)
    111c:	03010113          	addi	sp,sp,48
    1120:	00008067          	jalr	zero,0(ra)

00001124 <vscanf>:
    1124:	fc010113          	addi	sp,sp,-64
    1128:	02112e23          	sw	ra,60(sp)
    112c:	02812c23          	sw	s0,56(sp)
    1130:	04010413          	addi	s0,sp,64
    1134:	fca42623          	sw	a0,-52(s0)
    1138:	fcb42423          	sw	a1,-56(s0)
    113c:	0180006f          	jal	zero,1154 <vscanf+0x30>
    1140:	0000d7b7          	lui	a5,0xd
    1144:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1148:	00178713          	addi	a4,a5,1
    114c:	0000d7b7          	lui	a5,0xd
    1150:	d0e7ae23          	sw	a4,-740(a5) # cd1c <input_ptr.2>
    1154:	0000d7b7          	lui	a5,0xd
    1158:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    115c:	0007c703          	lbu	a4,0(a5)
    1160:	02000793          	addi	a5,zero,32
    1164:	fcf70ee3          	beq	a4,a5,1140 <vscanf+0x1c>
    1168:	0000d7b7          	lui	a5,0xd
    116c:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1170:	0007c703          	lbu	a4,0(a5)
    1174:	00900793          	addi	a5,zero,9
    1178:	fcf704e3          	beq	a4,a5,1140 <vscanf+0x1c>
    117c:	0000d7b7          	lui	a5,0xd
    1180:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1184:	0007c703          	lbu	a4,0(a5)
    1188:	00a00793          	addi	a5,zero,10
    118c:	faf70ae3          	beq	a4,a5,1140 <vscanf+0x1c>
    1190:	0000d7b7          	lui	a5,0xd
    1194:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1198:	00078a63          	beq	a5,zero,11ac <vscanf+0x88>
    119c:	0000d7b7          	lui	a5,0xd
    11a0:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    11a4:	0007c783          	lbu	a5,0(a5)
    11a8:	02079863          	bne	a5,zero,11d8 <vscanf+0xb4>
    11ac:	08000593          	addi	a1,zero,128
    11b0:	0000d7b7          	lui	a5,0xd
    11b4:	d2078513          	addi	a0,a5,-736 # cd20 <input_buffer.1>
    11b8:	d59ff0ef          	jal	ra,f10 <readline>
    11bc:	0000d7b7          	lui	a5,0xd
    11c0:	0000d737          	lui	a4,0xd
    11c4:	d2070713          	addi	a4,a4,-736 # cd20 <input_buffer.1>
    11c8:	d0e7ae23          	sw	a4,-740(a5) # cd1c <input_ptr.2>
    11cc:	0000d7b7          	lui	a5,0xd
    11d0:	00100713          	addi	a4,zero,1
    11d4:	dae7a023          	sw	a4,-608(a5) # cda0 <buffer_filled.0>
    11d8:	fcc42783          	lw	a5,-52(s0)
    11dc:	fef42623          	sw	a5,-20(s0)
    11e0:	fe042423          	sw	zero,-24(s0)
    11e4:	2dc0006f          	jal	zero,14c0 <vscanf+0x39c>
    11e8:	fec42783          	lw	a5,-20(s0)
    11ec:	0007c703          	lbu	a4,0(a5)
    11f0:	02500793          	addi	a5,zero,37
    11f4:	20f71263          	bne	a4,a5,13f8 <vscanf+0x2d4>
    11f8:	fec42783          	lw	a5,-20(s0)
    11fc:	00178793          	addi	a5,a5,1
    1200:	fef42623          	sw	a5,-20(s0)
    1204:	0180006f          	jal	zero,121c <vscanf+0xf8>
    1208:	0000d7b7          	lui	a5,0xd
    120c:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1210:	00178713          	addi	a4,a5,1
    1214:	0000d7b7          	lui	a5,0xd
    1218:	d0e7ae23          	sw	a4,-740(a5) # cd1c <input_ptr.2>
    121c:	0000d7b7          	lui	a5,0xd
    1220:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1224:	0007c703          	lbu	a4,0(a5)
    1228:	02000793          	addi	a5,zero,32
    122c:	fcf70ee3          	beq	a4,a5,1208 <vscanf+0xe4>
    1230:	0000d7b7          	lui	a5,0xd
    1234:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1238:	0007c703          	lbu	a4,0(a5)
    123c:	00900793          	addi	a5,zero,9
    1240:	fcf704e3          	beq	a4,a5,1208 <vscanf+0xe4>
    1244:	0000d7b7          	lui	a5,0xd
    1248:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    124c:	0007c703          	lbu	a4,0(a5)
    1250:	00a00793          	addi	a5,zero,10
    1254:	faf70ae3          	beq	a4,a5,1208 <vscanf+0xe4>
    1258:	0000d7b7          	lui	a5,0xd
    125c:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1260:	0007c783          	lbu	a5,0(a5)
    1264:	26078663          	beq	a5,zero,14d0 <vscanf+0x3ac>
    1268:	fec42783          	lw	a5,-20(s0)
    126c:	0007c783          	lbu	a5,0(a5)
    1270:	07300713          	addi	a4,zero,115
    1274:	0ae78863          	beq	a5,a4,1324 <vscanf+0x200>
    1278:	07300713          	addi	a4,zero,115
    127c:	16f74a63          	blt	a4,a5,13f0 <vscanf+0x2cc>
    1280:	06400713          	addi	a4,zero,100
    1284:	02e78063          	beq	a5,a4,12a4 <vscanf+0x180>
    1288:	06400713          	addi	a4,zero,100
    128c:	16f74263          	blt	a4,a5,13f0 <vscanf+0x2cc>
    1290:	02500713          	addi	a4,zero,37
    1294:	12e78a63          	beq	a5,a4,13c8 <vscanf+0x2a4>
    1298:	06300713          	addi	a4,zero,99
    129c:	04e78263          	beq	a5,a4,12e0 <vscanf+0x1bc>
    12a0:	1500006f          	jal	zero,13f0 <vscanf+0x2cc>
    12a4:	fc842783          	lw	a5,-56(s0)
    12a8:	00478713          	addi	a4,a5,4
    12ac:	fce42423          	sw	a4,-56(s0)
    12b0:	0007a783          	lw	a5,0(a5)
    12b4:	fef42023          	sw	a5,-32(s0)
    12b8:	0000d7b7          	lui	a5,0xd
    12bc:	d1c78513          	addi	a0,a5,-740 # cd1c <input_ptr.2>
    12c0:	d41ff0ef          	jal	ra,1000 <str2int>
    12c4:	00050713          	addi	a4,a0,0
    12c8:	fe042783          	lw	a5,-32(s0)
    12cc:	00e7a023          	sw	a4,0(a5)
    12d0:	fe842783          	lw	a5,-24(s0)
    12d4:	00178793          	addi	a5,a5,1
    12d8:	fef42423          	sw	a5,-24(s0)
    12dc:	1d80006f          	jal	zero,14b4 <vscanf+0x390>
    12e0:	fc842783          	lw	a5,-56(s0)
    12e4:	00478713          	addi	a4,a5,4
    12e8:	fce42423          	sw	a4,-56(s0)
    12ec:	0007a783          	lw	a5,0(a5)
    12f0:	fcf42e23          	sw	a5,-36(s0)
    12f4:	0000d7b7          	lui	a5,0xd
    12f8:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    12fc:	00178693          	addi	a3,a5,1
    1300:	0000d737          	lui	a4,0xd
    1304:	d0d72e23          	sw	a3,-740(a4) # cd1c <input_ptr.2>
    1308:	0007c703          	lbu	a4,0(a5)
    130c:	fdc42783          	lw	a5,-36(s0)
    1310:	00e78023          	sb	a4,0(a5)
    1314:	fe842783          	lw	a5,-24(s0)
    1318:	00178793          	addi	a5,a5,1
    131c:	fef42423          	sw	a5,-24(s0)
    1320:	1940006f          	jal	zero,14b4 <vscanf+0x390>
    1324:	fc842783          	lw	a5,-56(s0)
    1328:	00478713          	addi	a4,a5,4
    132c:	fce42423          	sw	a4,-56(s0)
    1330:	0007a783          	lw	a5,0(a5)
    1334:	fef42223          	sw	a5,-28(s0)
    1338:	02c0006f          	jal	zero,1364 <vscanf+0x240>
    133c:	0000d7b7          	lui	a5,0xd
    1340:	d1c7a703          	lw	a4,-740(a5) # cd1c <input_ptr.2>
    1344:	00170693          	addi	a3,a4,1
    1348:	0000d7b7          	lui	a5,0xd
    134c:	d0d7ae23          	sw	a3,-740(a5) # cd1c <input_ptr.2>
    1350:	fe442783          	lw	a5,-28(s0)
    1354:	00178693          	addi	a3,a5,1
    1358:	fed42223          	sw	a3,-28(s0)
    135c:	00074703          	lbu	a4,0(a4)
    1360:	00e78023          	sb	a4,0(a5)
    1364:	0000d7b7          	lui	a5,0xd
    1368:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    136c:	0007c783          	lbu	a5,0(a5)
    1370:	04078063          	beq	a5,zero,13b0 <vscanf+0x28c>
    1374:	0000d7b7          	lui	a5,0xd
    1378:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    137c:	0007c703          	lbu	a4,0(a5)
    1380:	00900793          	addi	a5,zero,9
    1384:	02f70663          	beq	a4,a5,13b0 <vscanf+0x28c>
    1388:	0000d7b7          	lui	a5,0xd
    138c:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1390:	0007c703          	lbu	a4,0(a5)
    1394:	00a00793          	addi	a5,zero,10
    1398:	00f70c63          	beq	a4,a5,13b0 <vscanf+0x28c>
    139c:	0000d7b7          	lui	a5,0xd
    13a0:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    13a4:	0007c703          	lbu	a4,0(a5)
    13a8:	00d00793          	addi	a5,zero,13
    13ac:	f8f718e3          	bne	a4,a5,133c <vscanf+0x218>
    13b0:	fe442783          	lw	a5,-28(s0)
    13b4:	00078023          	sb	zero,0(a5)
    13b8:	fe842783          	lw	a5,-24(s0)
    13bc:	00178793          	addi	a5,a5,1
    13c0:	fef42423          	sw	a5,-24(s0)
    13c4:	0f00006f          	jal	zero,14b4 <vscanf+0x390>
    13c8:	0000d7b7          	lui	a5,0xd
    13cc:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    13d0:	00178693          	addi	a3,a5,1
    13d4:	0000d737          	lui	a4,0xd
    13d8:	d0d72e23          	sw	a3,-740(a4) # cd1c <input_ptr.2>
    13dc:	0007c703          	lbu	a4,0(a5)
    13e0:	02500793          	addi	a5,zero,37
    13e4:	0cf70663          	beq	a4,a5,14b0 <vscanf+0x38c>
    13e8:	fe842783          	lw	a5,-24(s0)
    13ec:	0f40006f          	jal	zero,14e0 <vscanf+0x3bc>
    13f0:	fe842783          	lw	a5,-24(s0)
    13f4:	0ec0006f          	jal	zero,14e0 <vscanf+0x3bc>
    13f8:	fec42783          	lw	a5,-20(s0)
    13fc:	0007c703          	lbu	a4,0(a5)
    1400:	02000793          	addi	a5,zero,32
    1404:	02f70e63          	beq	a4,a5,1440 <vscanf+0x31c>
    1408:	fec42783          	lw	a5,-20(s0)
    140c:	0007c703          	lbu	a4,0(a5)
    1410:	00900793          	addi	a5,zero,9
    1414:	02f70663          	beq	a4,a5,1440 <vscanf+0x31c>
    1418:	fec42783          	lw	a5,-20(s0)
    141c:	0007c703          	lbu	a4,0(a5)
    1420:	00a00793          	addi	a5,zero,10
    1424:	04f71e63          	bne	a4,a5,1480 <vscanf+0x35c>
    1428:	0180006f          	jal	zero,1440 <vscanf+0x31c>
    142c:	0000d7b7          	lui	a5,0xd
    1430:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1434:	00178713          	addi	a4,a5,1
    1438:	0000d7b7          	lui	a5,0xd
    143c:	d0e7ae23          	sw	a4,-740(a5) # cd1c <input_ptr.2>
    1440:	0000d7b7          	lui	a5,0xd
    1444:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1448:	0007c703          	lbu	a4,0(a5)
    144c:	02000793          	addi	a5,zero,32
    1450:	fcf70ee3          	beq	a4,a5,142c <vscanf+0x308>
    1454:	0000d7b7          	lui	a5,0xd
    1458:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    145c:	0007c703          	lbu	a4,0(a5)
    1460:	00900793          	addi	a5,zero,9
    1464:	fcf704e3          	beq	a4,a5,142c <vscanf+0x308>
    1468:	0000d7b7          	lui	a5,0xd
    146c:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1470:	0007c703          	lbu	a4,0(a5)
    1474:	00a00793          	addi	a5,zero,10
    1478:	faf70ae3          	beq	a4,a5,142c <vscanf+0x308>
    147c:	0380006f          	jal	zero,14b4 <vscanf+0x390>
    1480:	fec42783          	lw	a5,-20(s0)
    1484:	0007c703          	lbu	a4,0(a5)
    1488:	0000d7b7          	lui	a5,0xd
    148c:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    1490:	0007c783          	lbu	a5,0(a5)
    1494:	04f71263          	bne	a4,a5,14d8 <vscanf+0x3b4>
    1498:	0000d7b7          	lui	a5,0xd
    149c:	d1c7a783          	lw	a5,-740(a5) # cd1c <input_ptr.2>
    14a0:	00178713          	addi	a4,a5,1
    14a4:	0000d7b7          	lui	a5,0xd
    14a8:	d0e7ae23          	sw	a4,-740(a5) # cd1c <input_ptr.2>
    14ac:	0080006f          	jal	zero,14b4 <vscanf+0x390>
    14b0:	00000013          	addi	zero,zero,0
    14b4:	fec42783          	lw	a5,-20(s0)
    14b8:	00178793          	addi	a5,a5,1
    14bc:	fef42623          	sw	a5,-20(s0)
    14c0:	fec42783          	lw	a5,-20(s0)
    14c4:	0007c783          	lbu	a5,0(a5)
    14c8:	d20790e3          	bne	a5,zero,11e8 <vscanf+0xc4>
    14cc:	0100006f          	jal	zero,14dc <vscanf+0x3b8>
    14d0:	00000013          	addi	zero,zero,0
    14d4:	0080006f          	jal	zero,14dc <vscanf+0x3b8>
    14d8:	00000013          	addi	zero,zero,0
    14dc:	fe842783          	lw	a5,-24(s0)
    14e0:	00078513          	addi	a0,a5,0
    14e4:	03c12083          	lw	ra,60(sp)
    14e8:	03812403          	lw	s0,56(sp)
    14ec:	04010113          	addi	sp,sp,64
    14f0:	00008067          	jalr	zero,0(ra)

000014f4 <scanf>:
    14f4:	fb010113          	addi	sp,sp,-80
    14f8:	02112623          	sw	ra,44(sp)
    14fc:	02812423          	sw	s0,40(sp)
    1500:	03010413          	addi	s0,sp,48
    1504:	fca42e23          	sw	a0,-36(s0)
    1508:	00b42223          	sw	a1,4(s0)
    150c:	00c42423          	sw	a2,8(s0)
    1510:	00d42623          	sw	a3,12(s0)
    1514:	00e42823          	sw	a4,16(s0)
    1518:	00f42a23          	sw	a5,20(s0)
    151c:	01042c23          	sw	a6,24(s0)
    1520:	01142e23          	sw	a7,28(s0)
    1524:	02040793          	addi	a5,s0,32
    1528:	fcf42c23          	sw	a5,-40(s0)
    152c:	fd842783          	lw	a5,-40(s0)
    1530:	fe478793          	addi	a5,a5,-28
    1534:	fef42423          	sw	a5,-24(s0)
    1538:	fe842783          	lw	a5,-24(s0)
    153c:	00078593          	addi	a1,a5,0
    1540:	fdc42503          	lw	a0,-36(s0)
    1544:	be1ff0ef          	jal	ra,1124 <vscanf>
    1548:	fea42623          	sw	a0,-20(s0)
    154c:	fec42783          	lw	a5,-20(s0)
    1550:	00078513          	addi	a0,a5,0
    1554:	02c12083          	lw	ra,44(sp)
    1558:	02812403          	lw	s0,40(sp)
    155c:	05010113          	addi	sp,sp,80
    1560:	00008067          	jalr	zero,0(ra)

00001564 <__divsf3>:
    1564:	fe010113          	addi	sp,sp,-32
    1568:	00912a23          	sw	s1,20(sp)
    156c:	01755493          	srli	s1,a0,0x17
    1570:	01212823          	sw	s2,16(sp)
    1574:	01312623          	sw	s3,12(sp)
    1578:	01412423          	sw	s4,8(sp)
    157c:	00951993          	slli	s3,a0,0x9
    1580:	00112e23          	sw	ra,28(sp)
    1584:	00812c23          	sw	s0,24(sp)
    1588:	01512223          	sw	s5,4(sp)
    158c:	0ff4f493          	andi	s1,s1,255
    1590:	00058a13          	addi	s4,a1,0
    1594:	0099d993          	srli	s3,s3,0x9
    1598:	01f55913          	srli	s2,a0,0x1f
    159c:	08048663          	beq	s1,zero,1628 <__divsf3+0xc4>
    15a0:	0ff00793          	addi	a5,zero,255
    15a4:	0af48263          	beq	s1,a5,1648 <__divsf3+0xe4>
    15a8:	00399993          	slli	s3,s3,0x3
    15ac:	040007b7          	lui	a5,0x4000
    15b0:	00f9e9b3          	or	s3,s3,a5
    15b4:	f8148493          	addi	s1,s1,-127
    15b8:	00000a93          	addi	s5,zero,0
    15bc:	017a5793          	srli	a5,s4,0x17
    15c0:	009a1413          	slli	s0,s4,0x9
    15c4:	0ff7f793          	andi	a5,a5,255
    15c8:	00945413          	srli	s0,s0,0x9
    15cc:	01fa5a13          	srli	s4,s4,0x1f
    15d0:	08078a63          	beq	a5,zero,1664 <__divsf3+0x100>
    15d4:	0ff00713          	addi	a4,zero,255
    15d8:	0ae78663          	beq	a5,a4,1684 <__divsf3+0x120>
    15dc:	00341413          	slli	s0,s0,0x3
    15e0:	04000737          	lui	a4,0x4000
    15e4:	00e46433          	or	s0,s0,a4
    15e8:	f8178793          	addi	a5,a5,-127 # 3ffff81 <__heap_end+0x3fda781>
    15ec:	00000713          	addi	a4,zero,0
    15f0:	40f484b3          	sub	s1,s1,a5
    15f4:	002a9793          	slli	a5,s5,0x2
    15f8:	00e7e7b3          	or	a5,a5,a4
    15fc:	fff78793          	addi	a5,a5,-1
    1600:	00e00693          	addi	a3,zero,14
    1604:	01494533          	xor	a0,s2,s4
    1608:	08f6ec63          	bltu	a3,a5,16a0 <__divsf3+0x13c>
    160c:	0000b697          	auipc	a3,0xb
    1610:	3ac68693          	addi	a3,a3,940 # c9b8 <_etext+0xa390>
    1614:	00279793          	slli	a5,a5,0x2
    1618:	00d787b3          	add	a5,a5,a3
    161c:	0007a783          	lw	a5,0(a5)
    1620:	00d787b3          	add	a5,a5,a3
    1624:	00078067          	jalr	zero,0(a5)
    1628:	02098863          	beq	s3,zero,1658 <__divsf3+0xf4>
    162c:	00098513          	addi	a0,s3,0
    1630:	409000ef          	jal	ra,2238 <__clzsi2>
    1634:	ffb50793          	addi	a5,a0,-5
    1638:	f8a00493          	addi	s1,zero,-118
    163c:	00f999b3          	sll	s3,s3,a5
    1640:	40a484b3          	sub	s1,s1,a0
    1644:	f75ff06f          	jal	zero,15b8 <__divsf3+0x54>
    1648:	00200a93          	addi	s5,zero,2
    164c:	f60988e3          	beq	s3,zero,15bc <__divsf3+0x58>
    1650:	00300a93          	addi	s5,zero,3
    1654:	f69ff06f          	jal	zero,15bc <__divsf3+0x58>
    1658:	00000493          	addi	s1,zero,0
    165c:	00100a93          	addi	s5,zero,1
    1660:	f5dff06f          	jal	zero,15bc <__divsf3+0x58>
    1664:	02040863          	beq	s0,zero,1694 <__divsf3+0x130>
    1668:	00040513          	addi	a0,s0,0
    166c:	3cd000ef          	jal	ra,2238 <__clzsi2>
    1670:	ffb50793          	addi	a5,a0,-5
    1674:	00f41433          	sll	s0,s0,a5
    1678:	f8a00793          	addi	a5,zero,-118
    167c:	40a787b3          	sub	a5,a5,a0
    1680:	f6dff06f          	jal	zero,15ec <__divsf3+0x88>
    1684:	00200713          	addi	a4,zero,2
    1688:	f60404e3          	beq	s0,zero,15f0 <__divsf3+0x8c>
    168c:	00300713          	addi	a4,zero,3
    1690:	f61ff06f          	jal	zero,15f0 <__divsf3+0x8c>
    1694:	00000793          	addi	a5,zero,0
    1698:	00100713          	addi	a4,zero,1
    169c:	f55ff06f          	jal	zero,15f0 <__divsf3+0x8c>
    16a0:	00541713          	slli	a4,s0,0x5
    16a4:	0e89f663          	bgeu	s3,s0,1790 <__divsf3+0x22c>
    16a8:	fff48493          	addi	s1,s1,-1
    16ac:	00000793          	addi	a5,zero,0
    16b0:	01075613          	srli	a2,a4,0x10
    16b4:	02c9d833          	divu	a6,s3,a2
    16b8:	01071693          	slli	a3,a4,0x10
    16bc:	0106d693          	srli	a3,a3,0x10
    16c0:	0107d793          	srli	a5,a5,0x10
    16c4:	02c9f9b3          	remu	s3,s3,a2
    16c8:	00080413          	addi	s0,a6,0
    16cc:	030685b3          	mul	a1,a3,a6
    16d0:	01099993          	slli	s3,s3,0x10
    16d4:	0137e7b3          	or	a5,a5,s3
    16d8:	00b7fe63          	bgeu	a5,a1,16f4 <__divsf3+0x190>
    16dc:	00f707b3          	add	a5,a4,a5
    16e0:	fff80413          	addi	s0,a6,-1
    16e4:	00e7e863          	bltu	a5,a4,16f4 <__divsf3+0x190>
    16e8:	00b7f663          	bgeu	a5,a1,16f4 <__divsf3+0x190>
    16ec:	ffe80413          	addi	s0,a6,-2
    16f0:	00e787b3          	add	a5,a5,a4
    16f4:	40b787b3          	sub	a5,a5,a1
    16f8:	02c7d5b3          	divu	a1,a5,a2
    16fc:	02c7f7b3          	remu	a5,a5,a2
    1700:	00058613          	addi	a2,a1,0
    1704:	02b686b3          	mul	a3,a3,a1
    1708:	01079793          	slli	a5,a5,0x10
    170c:	02d7f263          	bgeu	a5,a3,1730 <__divsf3+0x1cc>
    1710:	00e78833          	add	a6,a5,a4
    1714:	00f838b3          	sltu	a7,a6,a5
    1718:	fff58613          	addi	a2,a1,-1
    171c:	00080793          	addi	a5,a6,0
    1720:	00089863          	bne	a7,zero,1730 <__divsf3+0x1cc>
    1724:	00d87663          	bgeu	a6,a3,1730 <__divsf3+0x1cc>
    1728:	ffe58613          	addi	a2,a1,-2
    172c:	00e807b3          	add	a5,a6,a4
    1730:	01041413          	slli	s0,s0,0x10
    1734:	40d787b3          	sub	a5,a5,a3
    1738:	00c46433          	or	s0,s0,a2
    173c:	00f037b3          	sltu	a5,zero,a5
    1740:	00f46433          	or	s0,s0,a5
    1744:	07f48793          	addi	a5,s1,127
    1748:	08f05663          	bge	zero,a5,17d4 <__divsf3+0x270>
    174c:	00747713          	andi	a4,s0,7
    1750:	00070a63          	beq	a4,zero,1764 <__divsf3+0x200>
    1754:	00f47713          	andi	a4,s0,15
    1758:	00400693          	addi	a3,zero,4
    175c:	00d70463          	beq	a4,a3,1764 <__divsf3+0x200>
    1760:	00d40433          	add	s0,s0,a3
    1764:	00441713          	slli	a4,s0,0x4
    1768:	00075a63          	bge	a4,zero,177c <__divsf3+0x218>
    176c:	f80007b7          	lui	a5,0xf8000
    1770:	fff78793          	addi	a5,a5,-1 # f7ffffff <__heap_end+0xf7fda7ff>
    1774:	00f47433          	and	s0,s0,a5
    1778:	08048793          	addi	a5,s1,128
    177c:	0fe00713          	addi	a4,zero,254
    1780:	00345413          	srli	s0,s0,0x3
    1784:	0af75c63          	bge	a4,a5,183c <__divsf3+0x2d8>
    1788:	00000413          	addi	s0,zero,0
    178c:	0ac0006f          	jal	zero,1838 <__divsf3+0x2d4>
    1790:	01f99793          	slli	a5,s3,0x1f
    1794:	0019d993          	srli	s3,s3,0x1
    1798:	f19ff06f          	jal	zero,16b0 <__divsf3+0x14c>
    179c:	00090513          	addi	a0,s2,0
    17a0:	00098413          	addi	s0,s3,0
    17a4:	000a8713          	addi	a4,s5,0
    17a8:	00200793          	addi	a5,zero,2
    17ac:	fcf70ee3          	beq	a4,a5,1788 <__divsf3+0x224>
    17b0:	00300793          	addi	a5,zero,3
    17b4:	06f70e63          	beq	a4,a5,1830 <__divsf3+0x2cc>
    17b8:	00100793          	addi	a5,zero,1
    17bc:	f8f714e3          	bne	a4,a5,1744 <__divsf3+0x1e0>
    17c0:	00000413          	addi	s0,zero,0
    17c4:	00000793          	addi	a5,zero,0
    17c8:	0740006f          	jal	zero,183c <__divsf3+0x2d8>
    17cc:	000a0513          	addi	a0,s4,0
    17d0:	fd9ff06f          	jal	zero,17a8 <__divsf3+0x244>
    17d4:	00100713          	addi	a4,zero,1
    17d8:	40f707b3          	sub	a5,a4,a5
    17dc:	01b00713          	addi	a4,zero,27
    17e0:	fef740e3          	blt	a4,a5,17c0 <__divsf3+0x25c>
    17e4:	09e48493          	addi	s1,s1,158
    17e8:	009414b3          	sll	s1,s0,s1
    17ec:	00f457b3          	srl	a5,s0,a5
    17f0:	009034b3          	sltu	s1,zero,s1
    17f4:	0097e433          	or	s0,a5,s1
    17f8:	00747793          	andi	a5,s0,7
    17fc:	00078a63          	beq	a5,zero,1810 <__divsf3+0x2ac>
    1800:	00f47793          	andi	a5,s0,15
    1804:	00400713          	addi	a4,zero,4
    1808:	00e78463          	beq	a5,a4,1810 <__divsf3+0x2ac>
    180c:	00e40433          	add	s0,s0,a4
    1810:	00541793          	slli	a5,s0,0x5
    1814:	00345413          	srli	s0,s0,0x3
    1818:	fa07d6e3          	bge	a5,zero,17c4 <__divsf3+0x260>
    181c:	00000413          	addi	s0,zero,0
    1820:	00100793          	addi	a5,zero,1
    1824:	0180006f          	jal	zero,183c <__divsf3+0x2d8>
    1828:	00000513          	addi	a0,zero,0
    182c:	00400437          	lui	s0,0x400
    1830:	004007b7          	lui	a5,0x400
    1834:	00f46433          	or	s0,s0,a5
    1838:	0ff00793          	addi	a5,zero,255
    183c:	00941413          	slli	s0,s0,0x9
    1840:	00945413          	srli	s0,s0,0x9
    1844:	01779793          	slli	a5,a5,0x17
    1848:	01c12083          	lw	ra,28(sp)
    184c:	0087e7b3          	or	a5,a5,s0
    1850:	01812403          	lw	s0,24(sp)
    1854:	01f51513          	slli	a0,a0,0x1f
    1858:	01412483          	lw	s1,20(sp)
    185c:	01012903          	lw	s2,16(sp)
    1860:	00c12983          	lw	s3,12(sp)
    1864:	00812a03          	lw	s4,8(sp)
    1868:	00412a83          	lw	s5,4(sp)
    186c:	00a7e533          	or	a0,a5,a0
    1870:	02010113          	addi	sp,sp,32
    1874:	00008067          	jalr	zero,0(ra)

00001878 <__gesf2>:
    1878:	00800737          	lui	a4,0x800
    187c:	fff70713          	addi	a4,a4,-1 # 7fffff <__heap_end+0x7da7ff>
    1880:	01755693          	srli	a3,a0,0x17
    1884:	00a77633          	and	a2,a4,a0
    1888:	01f55793          	srli	a5,a0,0x1f
    188c:	0ff6f693          	andi	a3,a3,255
    1890:	0175d513          	srli	a0,a1,0x17
    1894:	0ff00813          	addi	a6,zero,255
    1898:	00b77733          	and	a4,a4,a1
    189c:	0ff57513          	andi	a0,a0,255
    18a0:	01f5d593          	srli	a1,a1,0x1f
    18a4:	01069463          	bne	a3,a6,18ac <__gesf2+0x34>
    18a8:	02061e63          	bne	a2,zero,18e4 <__gesf2+0x6c>
    18ac:	01051463          	bne	a0,a6,18b4 <__gesf2+0x3c>
    18b0:	02071a63          	bne	a4,zero,18e4 <__gesf2+0x6c>
    18b4:	04069863          	bne	a3,zero,1904 <__gesf2+0x8c>
    18b8:	02051a63          	bne	a0,zero,18ec <__gesf2+0x74>
    18bc:	04061663          	bne	a2,zero,1908 <__gesf2+0x90>
    18c0:	02070063          	beq	a4,zero,18e0 <__gesf2+0x68>
    18c4:	00159513          	slli	a0,a1,0x1
    18c8:	fff50513          	addi	a0,a0,-1
    18cc:	00008067          	jalr	zero,0(ra)
    18d0:	fea6cae3          	blt	a3,a0,18c4 <__gesf2+0x4c>
    18d4:	02c76263          	bltu	a4,a2,18f8 <__gesf2+0x80>
    18d8:	00000513          	addi	a0,zero,0
    18dc:	fee664e3          	bltu	a2,a4,18c4 <__gesf2+0x4c>
    18e0:	00008067          	jalr	zero,0(ra)
    18e4:	ffe00513          	addi	a0,zero,-2
    18e8:	00008067          	jalr	zero,0(ra)
    18ec:	fc060ce3          	beq	a2,zero,18c4 <__gesf2+0x4c>
    18f0:	00f59e63          	bne	a1,a5,190c <__gesf2+0x94>
    18f4:	fcd55ee3          	bge	a0,a3,18d0 <__gesf2+0x58>
    18f8:	40b005b3          	sub	a1,zero,a1
    18fc:	0015e513          	ori	a0,a1,1
    1900:	00008067          	jalr	zero,0(ra)
    1904:	fe0516e3          	bne	a0,zero,18f0 <__gesf2+0x78>
    1908:	fe0714e3          	bne	a4,zero,18f0 <__gesf2+0x78>
    190c:	40f00533          	sub	a0,zero,a5
    1910:	00156513          	ori	a0,a0,1
    1914:	00008067          	jalr	zero,0(ra)

00001918 <__lesf2>:
    1918:	00800737          	lui	a4,0x800
    191c:	fff70713          	addi	a4,a4,-1 # 7fffff <__heap_end+0x7da7ff>
    1920:	01755693          	srli	a3,a0,0x17
    1924:	00a77633          	and	a2,a4,a0
    1928:	01f55793          	srli	a5,a0,0x1f
    192c:	0ff6f693          	andi	a3,a3,255
    1930:	0175d513          	srli	a0,a1,0x17
    1934:	0ff00813          	addi	a6,zero,255
    1938:	00b77733          	and	a4,a4,a1
    193c:	0ff57513          	andi	a0,a0,255
    1940:	01f5d593          	srli	a1,a1,0x1f
    1944:	01069463          	bne	a3,a6,194c <__lesf2+0x34>
    1948:	02061e63          	bne	a2,zero,1984 <__lesf2+0x6c>
    194c:	01051463          	bne	a0,a6,1954 <__lesf2+0x3c>
    1950:	02071a63          	bne	a4,zero,1984 <__lesf2+0x6c>
    1954:	04069863          	bne	a3,zero,19a4 <__lesf2+0x8c>
    1958:	02051a63          	bne	a0,zero,198c <__lesf2+0x74>
    195c:	04061663          	bne	a2,zero,19a8 <__lesf2+0x90>
    1960:	02070063          	beq	a4,zero,1980 <__lesf2+0x68>
    1964:	00159513          	slli	a0,a1,0x1
    1968:	fff50513          	addi	a0,a0,-1
    196c:	00008067          	jalr	zero,0(ra)
    1970:	fea6cae3          	blt	a3,a0,1964 <__lesf2+0x4c>
    1974:	02c76263          	bltu	a4,a2,1998 <__lesf2+0x80>
    1978:	00000513          	addi	a0,zero,0
    197c:	fee664e3          	bltu	a2,a4,1964 <__lesf2+0x4c>
    1980:	00008067          	jalr	zero,0(ra)
    1984:	00200513          	addi	a0,zero,2
    1988:	00008067          	jalr	zero,0(ra)
    198c:	fc060ce3          	beq	a2,zero,1964 <__lesf2+0x4c>
    1990:	00f59e63          	bne	a1,a5,19ac <__lesf2+0x94>
    1994:	fcd55ee3          	bge	a0,a3,1970 <__lesf2+0x58>
    1998:	40b005b3          	sub	a1,zero,a1
    199c:	0015e513          	ori	a0,a1,1
    19a0:	00008067          	jalr	zero,0(ra)
    19a4:	fe0516e3          	bne	a0,zero,1990 <__lesf2+0x78>
    19a8:	fe0714e3          	bne	a4,zero,1990 <__lesf2+0x78>
    19ac:	40f00533          	sub	a0,zero,a5
    19b0:	00156513          	ori	a0,a0,1
    19b4:	00008067          	jalr	zero,0(ra)

000019b8 <__mulsf3>:
    19b8:	fe010113          	addi	sp,sp,-32
    19bc:	01212823          	sw	s2,16(sp)
    19c0:	01755913          	srli	s2,a0,0x17
    19c4:	00912a23          	sw	s1,20(sp)
    19c8:	01312623          	sw	s3,12(sp)
    19cc:	01412423          	sw	s4,8(sp)
    19d0:	00951493          	slli	s1,a0,0x9
    19d4:	00112e23          	sw	ra,28(sp)
    19d8:	00812c23          	sw	s0,24(sp)
    19dc:	01512223          	sw	s5,4(sp)
    19e0:	0ff97913          	andi	s2,s2,255
    19e4:	00058a13          	addi	s4,a1,0
    19e8:	0094d493          	srli	s1,s1,0x9
    19ec:	01f55993          	srli	s3,a0,0x1f
    19f0:	14090a63          	beq	s2,zero,1b44 <__mulsf3+0x18c>
    19f4:	0ff00793          	addi	a5,zero,255
    19f8:	16f90663          	beq	s2,a5,1b64 <__mulsf3+0x1ac>
    19fc:	00349493          	slli	s1,s1,0x3
    1a00:	040007b7          	lui	a5,0x4000
    1a04:	00f4e4b3          	or	s1,s1,a5
    1a08:	f8190913          	addi	s2,s2,-127
    1a0c:	00000a93          	addi	s5,zero,0
    1a10:	017a5793          	srli	a5,s4,0x17
    1a14:	009a1413          	slli	s0,s4,0x9
    1a18:	0ff7f793          	andi	a5,a5,255
    1a1c:	00945413          	srli	s0,s0,0x9
    1a20:	01fa5a13          	srli	s4,s4,0x1f
    1a24:	14078e63          	beq	a5,zero,1b80 <__mulsf3+0x1c8>
    1a28:	0ff00713          	addi	a4,zero,255
    1a2c:	16e78a63          	beq	a5,a4,1ba0 <__mulsf3+0x1e8>
    1a30:	00341413          	slli	s0,s0,0x3
    1a34:	04000737          	lui	a4,0x4000
    1a38:	00e46433          	or	s0,s0,a4
    1a3c:	f8178793          	addi	a5,a5,-127 # 3ffff81 <__heap_end+0x3fda781>
    1a40:	00000693          	addi	a3,zero,0
    1a44:	00f90933          	add	s2,s2,a5
    1a48:	002a9793          	slli	a5,s5,0x2
    1a4c:	00d7e7b3          	or	a5,a5,a3
    1a50:	00a00613          	addi	a2,zero,10
    1a54:	00190713          	addi	a4,s2,1
    1a58:	1af64463          	blt	a2,a5,1c00 <__mulsf3+0x248>
    1a5c:	00200593          	addi	a1,zero,2
    1a60:	0149c9b3          	xor	s3,s3,s4
    1a64:	00100613          	addi	a2,zero,1
    1a68:	14f5ca63          	blt	a1,a5,1bbc <__mulsf3+0x204>
    1a6c:	fff78793          	addi	a5,a5,-1
    1a70:	16f67663          	bgeu	a2,a5,1bdc <__mulsf3+0x224>
    1a74:	0104d693          	srli	a3,s1,0x10
    1a78:	01045793          	srli	a5,s0,0x10
    1a7c:	01049493          	slli	s1,s1,0x10
    1a80:	01041413          	slli	s0,s0,0x10
    1a84:	0104d493          	srli	s1,s1,0x10
    1a88:	01045413          	srli	s0,s0,0x10
    1a8c:	029405b3          	mul	a1,s0,s1
    1a90:	02868433          	mul	s0,a3,s0
    1a94:	02f686b3          	mul	a3,a3,a5
    1a98:	029787b3          	mul	a5,a5,s1
    1a9c:	00878633          	add	a2,a5,s0
    1aa0:	0105d793          	srli	a5,a1,0x10
    1aa4:	00c787b3          	add	a5,a5,a2
    1aa8:	0087f663          	bgeu	a5,s0,1ab4 <__mulsf3+0xfc>
    1aac:	00010637          	lui	a2,0x10
    1ab0:	00c686b3          	add	a3,a3,a2
    1ab4:	01059593          	slli	a1,a1,0x10
    1ab8:	01079613          	slli	a2,a5,0x10
    1abc:	0105d593          	srli	a1,a1,0x10
    1ac0:	00b60633          	add	a2,a2,a1
    1ac4:	0107d793          	srli	a5,a5,0x10
    1ac8:	00661413          	slli	s0,a2,0x6
    1acc:	00d787b3          	add	a5,a5,a3
    1ad0:	00679793          	slli	a5,a5,0x6
    1ad4:	00803433          	sltu	s0,zero,s0
    1ad8:	01a65613          	srli	a2,a2,0x1a
    1adc:	00c46433          	or	s0,s0,a2
    1ae0:	00479693          	slli	a3,a5,0x4
    1ae4:	0087e433          	or	s0,a5,s0
    1ae8:	1206da63          	bge	a3,zero,1c1c <__mulsf3+0x264>
    1aec:	00145793          	srli	a5,s0,0x1
    1af0:	00147413          	andi	s0,s0,1
    1af4:	0087e433          	or	s0,a5,s0
    1af8:	07f70793          	addi	a5,a4,127 # 400007f <__heap_end+0x3fda87f>
    1afc:	12f05463          	bge	zero,a5,1c24 <__mulsf3+0x26c>
    1b00:	00747693          	andi	a3,s0,7
    1b04:	00068a63          	beq	a3,zero,1b18 <__mulsf3+0x160>
    1b08:	00f47693          	andi	a3,s0,15
    1b0c:	00400613          	addi	a2,zero,4
    1b10:	00c68463          	beq	a3,a2,1b18 <__mulsf3+0x160>
    1b14:	00c40433          	add	s0,s0,a2
    1b18:	00441693          	slli	a3,s0,0x4
    1b1c:	0006da63          	bge	a3,zero,1b30 <__mulsf3+0x178>
    1b20:	f80007b7          	lui	a5,0xf8000
    1b24:	fff78793          	addi	a5,a5,-1 # f7ffffff <__heap_end+0xf7fda7ff>
    1b28:	00f47433          	and	s0,s0,a5
    1b2c:	08070793          	addi	a5,a4,128
    1b30:	0fe00713          	addi	a4,zero,254
    1b34:	00345413          	srli	s0,s0,0x3
    1b38:	14f75a63          	bge	a4,a5,1c8c <__mulsf3+0x2d4>
    1b3c:	00000413          	addi	s0,zero,0
    1b40:	1480006f          	jal	zero,1c88 <__mulsf3+0x2d0>
    1b44:	02048863          	beq	s1,zero,1b74 <__mulsf3+0x1bc>
    1b48:	00048513          	addi	a0,s1,0
    1b4c:	6ec000ef          	jal	ra,2238 <__clzsi2>
    1b50:	ffb50793          	addi	a5,a0,-5
    1b54:	f8a00913          	addi	s2,zero,-118
    1b58:	00f494b3          	sll	s1,s1,a5
    1b5c:	40a90933          	sub	s2,s2,a0
    1b60:	eadff06f          	jal	zero,1a0c <__mulsf3+0x54>
    1b64:	00200a93          	addi	s5,zero,2
    1b68:	ea0484e3          	beq	s1,zero,1a10 <__mulsf3+0x58>
    1b6c:	00300a93          	addi	s5,zero,3
    1b70:	ea1ff06f          	jal	zero,1a10 <__mulsf3+0x58>
    1b74:	00000913          	addi	s2,zero,0
    1b78:	00100a93          	addi	s5,zero,1
    1b7c:	e95ff06f          	jal	zero,1a10 <__mulsf3+0x58>
    1b80:	02040863          	beq	s0,zero,1bb0 <__mulsf3+0x1f8>
    1b84:	00040513          	addi	a0,s0,0 # 400000 <__heap_end+0x3da800>
    1b88:	6b0000ef          	jal	ra,2238 <__clzsi2>
    1b8c:	ffb50793          	addi	a5,a0,-5
    1b90:	00f41433          	sll	s0,s0,a5
    1b94:	f8a00793          	addi	a5,zero,-118
    1b98:	40a787b3          	sub	a5,a5,a0
    1b9c:	ea5ff06f          	jal	zero,1a40 <__mulsf3+0x88>
    1ba0:	00200693          	addi	a3,zero,2
    1ba4:	ea0400e3          	beq	s0,zero,1a44 <__mulsf3+0x8c>
    1ba8:	00300693          	addi	a3,zero,3
    1bac:	e99ff06f          	jal	zero,1a44 <__mulsf3+0x8c>
    1bb0:	00000793          	addi	a5,zero,0
    1bb4:	00100693          	addi	a3,zero,1
    1bb8:	e8dff06f          	jal	zero,1a44 <__mulsf3+0x8c>
    1bbc:	00f617b3          	sll	a5,a2,a5
    1bc0:	5307f613          	andi	a2,a5,1328
    1bc4:	04061663          	bne	a2,zero,1c10 <__mulsf3+0x258>
    1bc8:	2407f613          	andi	a2,a5,576
    1bcc:	0a061663          	bne	a2,zero,1c78 <__mulsf3+0x2c0>
    1bd0:	0887f793          	andi	a5,a5,136
    1bd4:	ea0780e3          	beq	a5,zero,1a74 <__mulsf3+0xbc>
    1bd8:	000a0993          	addi	s3,s4,0
    1bdc:	00200793          	addi	a5,zero,2
    1be0:	f4f68ee3          	beq	a3,a5,1b3c <__mulsf3+0x184>
    1be4:	00300793          	addi	a5,zero,3
    1be8:	08f68c63          	beq	a3,a5,1c80 <__mulsf3+0x2c8>
    1bec:	00100793          	addi	a5,zero,1
    1bf0:	f0f694e3          	bne	a3,a5,1af8 <__mulsf3+0x140>
    1bf4:	00000413          	addi	s0,zero,0
    1bf8:	00000793          	addi	a5,zero,0
    1bfc:	0900006f          	jal	zero,1c8c <__mulsf3+0x2d4>
    1c00:	00f00613          	addi	a2,zero,15
    1c04:	06c78a63          	beq	a5,a2,1c78 <__mulsf3+0x2c0>
    1c08:	00b00613          	addi	a2,zero,11
    1c0c:	fcc786e3          	beq	a5,a2,1bd8 <__mulsf3+0x220>
    1c10:	00048413          	addi	s0,s1,0
    1c14:	000a8693          	addi	a3,s5,0
    1c18:	fc5ff06f          	jal	zero,1bdc <__mulsf3+0x224>
    1c1c:	00090713          	addi	a4,s2,0
    1c20:	ed9ff06f          	jal	zero,1af8 <__mulsf3+0x140>
    1c24:	00100693          	addi	a3,zero,1
    1c28:	40f687b3          	sub	a5,a3,a5
    1c2c:	01b00693          	addi	a3,zero,27
    1c30:	fcf6c2e3          	blt	a3,a5,1bf4 <__mulsf3+0x23c>
    1c34:	09e70713          	addi	a4,a4,158
    1c38:	00e41733          	sll	a4,s0,a4
    1c3c:	00f457b3          	srl	a5,s0,a5
    1c40:	00e03733          	sltu	a4,zero,a4
    1c44:	00e7e433          	or	s0,a5,a4
    1c48:	00747793          	andi	a5,s0,7
    1c4c:	00078a63          	beq	a5,zero,1c60 <__mulsf3+0x2a8>
    1c50:	00f47793          	andi	a5,s0,15
    1c54:	00400713          	addi	a4,zero,4
    1c58:	00e78463          	beq	a5,a4,1c60 <__mulsf3+0x2a8>
    1c5c:	00e40433          	add	s0,s0,a4
    1c60:	00541793          	slli	a5,s0,0x5
    1c64:	00345413          	srli	s0,s0,0x3
    1c68:	f807d8e3          	bge	a5,zero,1bf8 <__mulsf3+0x240>
    1c6c:	00000413          	addi	s0,zero,0
    1c70:	00100793          	addi	a5,zero,1
    1c74:	0180006f          	jal	zero,1c8c <__mulsf3+0x2d4>
    1c78:	00000993          	addi	s3,zero,0
    1c7c:	00400437          	lui	s0,0x400
    1c80:	004007b7          	lui	a5,0x400
    1c84:	00f46433          	or	s0,s0,a5
    1c88:	0ff00793          	addi	a5,zero,255
    1c8c:	00941413          	slli	s0,s0,0x9
    1c90:	00945413          	srli	s0,s0,0x9
    1c94:	01779793          	slli	a5,a5,0x17
    1c98:	01c12083          	lw	ra,28(sp)
    1c9c:	0087e7b3          	or	a5,a5,s0
    1ca0:	01812403          	lw	s0,24(sp)
    1ca4:	01f99513          	slli	a0,s3,0x1f
    1ca8:	01412483          	lw	s1,20(sp)
    1cac:	01012903          	lw	s2,16(sp)
    1cb0:	00c12983          	lw	s3,12(sp)
    1cb4:	00812a03          	lw	s4,8(sp)
    1cb8:	00412a83          	lw	s5,4(sp)
    1cbc:	00a7e533          	or	a0,a5,a0
    1cc0:	02010113          	addi	sp,sp,32
    1cc4:	00008067          	jalr	zero,0(ra)

00001cc8 <__fixunssfsi>:
    1cc8:	008005b7          	lui	a1,0x800
    1ccc:	01755793          	srli	a5,a0,0x17
    1cd0:	fff58693          	addi	a3,a1,-1 # 7fffff <__heap_end+0x7da7ff>
    1cd4:	0ff7f793          	andi	a5,a5,255
    1cd8:	07e00613          	addi	a2,zero,126
    1cdc:	00a6f6b3          	and	a3,a3,a0
    1ce0:	01f55713          	srli	a4,a0,0x1f
    1ce4:	04f65263          	bge	a2,a5,1d28 <__fixunssfsi+0x60>
    1ce8:	09f00613          	addi	a2,zero,159
    1cec:	40e60633          	sub	a2,a2,a4
    1cf0:	fff70513          	addi	a0,a4,-1
    1cf4:	02c7dc63          	bge	a5,a2,1d2c <__fixunssfsi+0x64>
    1cf8:	00000513          	addi	a0,zero,0
    1cfc:	02071863          	bne	a4,zero,1d2c <__fixunssfsi+0x64>
    1d00:	09500713          	addi	a4,zero,149
    1d04:	00b6e533          	or	a0,a3,a1
    1d08:	00f75863          	bge	a4,a5,1d18 <__fixunssfsi+0x50>
    1d0c:	f6a78793          	addi	a5,a5,-150 # 3fff6a <__heap_end+0x3da76a>
    1d10:	00f51533          	sll	a0,a0,a5
    1d14:	00008067          	jalr	zero,0(ra)
    1d18:	09600713          	addi	a4,zero,150
    1d1c:	40f707b3          	sub	a5,a4,a5
    1d20:	00f55533          	srl	a0,a0,a5
    1d24:	00008067          	jalr	zero,0(ra)
    1d28:	00000513          	addi	a0,zero,0
    1d2c:	00008067          	jalr	zero,0(ra)

00001d30 <__floatsisf>:
    1d30:	ff010113          	addi	sp,sp,-16
    1d34:	00112623          	sw	ra,12(sp)
    1d38:	00812423          	sw	s0,8(sp)
    1d3c:	00912223          	sw	s1,4(sp)
    1d40:	00050793          	addi	a5,a0,0
    1d44:	0e050463          	beq	a0,zero,1e2c <__floatsisf+0xfc>
    1d48:	41f55713          	srai	a4,a0,0x1f
    1d4c:	00a74433          	xor	s0,a4,a0
    1d50:	40e40433          	sub	s0,s0,a4
    1d54:	01f55493          	srli	s1,a0,0x1f
    1d58:	00040513          	addi	a0,s0,0 # 400000 <__heap_end+0x3da800>
    1d5c:	4dc000ef          	jal	ra,2238 <__clzsi2>
    1d60:	09e00793          	addi	a5,zero,158
    1d64:	40a787b3          	sub	a5,a5,a0
    1d68:	09600713          	addi	a4,zero,150
    1d6c:	04f74063          	blt	a4,a5,1dac <__floatsisf+0x7c>
    1d70:	00800693          	addi	a3,zero,8
    1d74:	0cd50263          	beq	a0,a3,1e38 <__floatsisf+0x108>
    1d78:	ff850513          	addi	a0,a0,-8
    1d7c:	00a41433          	sll	s0,s0,a0
    1d80:	00941413          	slli	s0,s0,0x9
    1d84:	00945413          	srli	s0,s0,0x9
    1d88:	01779793          	slli	a5,a5,0x17
    1d8c:	00c12083          	lw	ra,12(sp)
    1d90:	0087e7b3          	or	a5,a5,s0
    1d94:	00812403          	lw	s0,8(sp)
    1d98:	01f49513          	slli	a0,s1,0x1f
    1d9c:	00a7e533          	or	a0,a5,a0
    1da0:	00412483          	lw	s1,4(sp)
    1da4:	01010113          	addi	sp,sp,16
    1da8:	00008067          	jalr	zero,0(ra)
    1dac:	09900713          	addi	a4,zero,153
    1db0:	06f75463          	bge	a4,a5,1e18 <__floatsisf+0xe8>
    1db4:	01b50713          	addi	a4,a0,27
    1db8:	00500693          	addi	a3,zero,5
    1dbc:	00e41733          	sll	a4,s0,a4
    1dc0:	40a686b3          	sub	a3,a3,a0
    1dc4:	00e03733          	sltu	a4,zero,a4
    1dc8:	00d45433          	srl	s0,s0,a3
    1dcc:	00876733          	or	a4,a4,s0
    1dd0:	fc000437          	lui	s0,0xfc000
    1dd4:	fff40413          	addi	s0,s0,-1 # fbffffff <__heap_end+0xfbfda7ff>
    1dd8:	00777693          	andi	a3,a4,7
    1ddc:	00877433          	and	s0,a4,s0
    1de0:	04068263          	beq	a3,zero,1e24 <__floatsisf+0xf4>
    1de4:	00f77713          	andi	a4,a4,15
    1de8:	00400693          	addi	a3,zero,4
    1dec:	02d70c63          	beq	a4,a3,1e24 <__floatsisf+0xf4>
    1df0:	00d40433          	add	s0,s0,a3
    1df4:	00541693          	slli	a3,s0,0x5
    1df8:	00345713          	srli	a4,s0,0x3
    1dfc:	0206d463          	bge	a3,zero,1e24 <__floatsisf+0xf4>
    1e00:	1f800437          	lui	s0,0x1f800
    1e04:	09f00793          	addi	a5,zero,159
    1e08:	fff40413          	addi	s0,s0,-1 # 1f7fffff <__heap_end+0x1f7da7ff>
    1e0c:	40a787b3          	sub	a5,a5,a0
    1e10:	00877433          	and	s0,a4,s0
    1e14:	f6dff06f          	jal	zero,1d80 <__floatsisf+0x50>
    1e18:	ffb50713          	addi	a4,a0,-5
    1e1c:	00e41733          	sll	a4,s0,a4
    1e20:	fb1ff06f          	jal	zero,1dd0 <__floatsisf+0xa0>
    1e24:	00345413          	srli	s0,s0,0x3
    1e28:	f59ff06f          	jal	zero,1d80 <__floatsisf+0x50>
    1e2c:	00000493          	addi	s1,zero,0
    1e30:	00000413          	addi	s0,zero,0
    1e34:	f4dff06f          	jal	zero,1d80 <__floatsisf+0x50>
    1e38:	00070793          	addi	a5,a4,0
    1e3c:	f45ff06f          	jal	zero,1d80 <__floatsisf+0x50>

00001e40 <__floatundisf>:
    1e40:	fe010113          	addi	sp,sp,-32
    1e44:	00112e23          	sw	ra,28(sp)
    1e48:	00812c23          	sw	s0,24(sp)
    1e4c:	00912a23          	sw	s1,20(sp)
    1e50:	01212823          	sw	s2,16(sp)
    1e54:	01312623          	sw	s3,12(sp)
    1e58:	01412423          	sw	s4,8(sp)
    1e5c:	00b567b3          	or	a5,a0,a1
    1e60:	12078063          	beq	a5,zero,1f80 <__floatundisf+0x140>
    1e64:	00050493          	addi	s1,a0,0
    1e68:	00058a13          	addi	s4,a1,0
    1e6c:	08058863          	beq	a1,zero,1efc <__floatundisf+0xbc>
    1e70:	00058513          	addi	a0,a1,0
    1e74:	3c4000ef          	jal	ra,2238 <__clzsi2>
    1e78:	0be00913          	addi	s2,zero,190
    1e7c:	00050993          	addi	s3,a0,0
    1e80:	40a90933          	sub	s2,s2,a0
    1e84:	01b98613          	addi	a2,s3,27
    1e88:	00048513          	addi	a0,s1,0
    1e8c:	000a0593          	addi	a1,s4,0
    1e90:	370000ef          	jal	ra,2200 <__ashldi3>
    1e94:	00b56533          	or	a0,a0,a1
    1e98:	02500613          	addi	a2,zero,37
    1e9c:	00a03433          	sltu	s0,zero,a0
    1ea0:	41360633          	sub	a2,a2,s3
    1ea4:	00048513          	addi	a0,s1,0
    1ea8:	000a0593          	addi	a1,s4,0
    1eac:	31c000ef          	jal	ra,21c8 <__lshrdi3>
    1eb0:	00a467b3          	or	a5,s0,a0
    1eb4:	fc000437          	lui	s0,0xfc000
    1eb8:	fff40413          	addi	s0,s0,-1 # fbffffff <__heap_end+0xfbfda7ff>
    1ebc:	0077f713          	andi	a4,a5,7
    1ec0:	0087f433          	and	s0,a5,s0
    1ec4:	0a070a63          	beq	a4,zero,1f78 <__floatundisf+0x138>
    1ec8:	00f7f793          	andi	a5,a5,15
    1ecc:	00400713          	addi	a4,zero,4
    1ed0:	0ae78463          	beq	a5,a4,1f78 <__floatundisf+0x138>
    1ed4:	00e40433          	add	s0,s0,a4
    1ed8:	00541713          	slli	a4,s0,0x5
    1edc:	00345793          	srli	a5,s0,0x3
    1ee0:	08075c63          	bge	a4,zero,1f78 <__floatundisf+0x138>
    1ee4:	1f800437          	lui	s0,0x1f800
    1ee8:	0bf00913          	addi	s2,zero,191
    1eec:	fff40413          	addi	s0,s0,-1 # 1f7fffff <__heap_end+0x1f7da7ff>
    1ef0:	41390933          	sub	s2,s2,s3
    1ef4:	0087f433          	and	s0,a5,s0
    1ef8:	0300006f          	jal	zero,1f28 <__floatundisf+0xe8>
    1efc:	00050413          	addi	s0,a0,0
    1f00:	338000ef          	jal	ra,2238 <__clzsi2>
    1f04:	02050993          	addi	s3,a0,32
    1f08:	0be00913          	addi	s2,zero,190
    1f0c:	41390933          	sub	s2,s2,s3
    1f10:	09600793          	addi	a5,zero,150
    1f14:	0527c263          	blt	a5,s2,1f58 <__floatundisf+0x118>
    1f18:	02800713          	addi	a4,zero,40
    1f1c:	06e98863          	beq	s3,a4,1f8c <__floatundisf+0x14c>
    1f20:	ff850513          	addi	a0,a0,-8
    1f24:	00a49433          	sll	s0,s1,a0
    1f28:	00941413          	slli	s0,s0,0x9
    1f2c:	01791513          	slli	a0,s2,0x17
    1f30:	00945413          	srli	s0,s0,0x9
    1f34:	01c12083          	lw	ra,28(sp)
    1f38:	00856533          	or	a0,a0,s0
    1f3c:	01812403          	lw	s0,24(sp)
    1f40:	01412483          	lw	s1,20(sp)
    1f44:	01012903          	lw	s2,16(sp)
    1f48:	00c12983          	lw	s3,12(sp)
    1f4c:	00812a03          	lw	s4,8(sp)
    1f50:	02010113          	addi	sp,sp,32
    1f54:	00008067          	jalr	zero,0(ra)
    1f58:	09900793          	addi	a5,zero,153
    1f5c:	f327c4e3          	blt	a5,s2,1e84 <__floatundisf+0x44>
    1f60:	02500713          	addi	a4,zero,37
    1f64:	00048793          	addi	a5,s1,0
    1f68:	f4e986e3          	beq	s3,a4,1eb4 <__floatundisf+0x74>
    1f6c:	ffb50513          	addi	a0,a0,-5
    1f70:	00a497b3          	sll	a5,s1,a0
    1f74:	f41ff06f          	jal	zero,1eb4 <__floatundisf+0x74>
    1f78:	00345413          	srli	s0,s0,0x3
    1f7c:	fadff06f          	jal	zero,1f28 <__floatundisf+0xe8>
    1f80:	00000413          	addi	s0,zero,0
    1f84:	00000913          	addi	s2,zero,0
    1f88:	fa1ff06f          	jal	zero,1f28 <__floatundisf+0xe8>
    1f8c:	00078913          	addi	s2,a5,0
    1f90:	f99ff06f          	jal	zero,1f28 <__floatundisf+0xe8>

00001f94 <__extendsfdf2>:
    1f94:	01755713          	srli	a4,a0,0x17
    1f98:	0ff77713          	andi	a4,a4,255
    1f9c:	fe010113          	addi	sp,sp,-32
    1fa0:	00170793          	addi	a5,a4,1
    1fa4:	00812c23          	sw	s0,24(sp)
    1fa8:	00912a23          	sw	s1,20(sp)
    1fac:	00951413          	slli	s0,a0,0x9
    1fb0:	00112e23          	sw	ra,28(sp)
    1fb4:	01212823          	sw	s2,16(sp)
    1fb8:	01312623          	sw	s3,12(sp)
    1fbc:	0fe7f793          	andi	a5,a5,254
    1fc0:	00945413          	srli	s0,s0,0x9
    1fc4:	01f55493          	srli	s1,a0,0x1f
    1fc8:	04078663          	beq	a5,zero,2014 <__extendsfdf2+0x80>
    1fcc:	00345793          	srli	a5,s0,0x3
    1fd0:	38070713          	addi	a4,a4,896
    1fd4:	01d41413          	slli	s0,s0,0x1d
    1fd8:	00c79793          	slli	a5,a5,0xc
    1fdc:	00c7d793          	srli	a5,a5,0xc
    1fe0:	01471713          	slli	a4,a4,0x14
    1fe4:	01f49513          	slli	a0,s1,0x1f
    1fe8:	00f76733          	or	a4,a4,a5
    1fec:	01c12083          	lw	ra,28(sp)
    1ff0:	00a767b3          	or	a5,a4,a0
    1ff4:	00040513          	addi	a0,s0,0
    1ff8:	01812403          	lw	s0,24(sp)
    1ffc:	01412483          	lw	s1,20(sp)
    2000:	01012903          	lw	s2,16(sp)
    2004:	00c12983          	lw	s3,12(sp)
    2008:	00078593          	addi	a1,a5,0
    200c:	02010113          	addi	sp,sp,32
    2010:	00008067          	jalr	zero,0(ra)
    2014:	04071663          	bne	a4,zero,2060 <__extendsfdf2+0xcc>
    2018:	00000793          	addi	a5,zero,0
    201c:	fa040ee3          	beq	s0,zero,1fd8 <__extendsfdf2+0x44>
    2020:	00040513          	addi	a0,s0,0
    2024:	214000ef          	jal	ra,2238 <__clzsi2>
    2028:	00a00793          	addi	a5,zero,10
    202c:	02a7c263          	blt	a5,a0,2050 <__extendsfdf2+0xbc>
    2030:	00b00793          	addi	a5,zero,11
    2034:	40a787b3          	sub	a5,a5,a0
    2038:	01550713          	addi	a4,a0,21
    203c:	00f457b3          	srl	a5,s0,a5
    2040:	00e41433          	sll	s0,s0,a4
    2044:	38900713          	addi	a4,zero,905
    2048:	40a70733          	sub	a4,a4,a0
    204c:	f8dff06f          	jal	zero,1fd8 <__extendsfdf2+0x44>
    2050:	ff550793          	addi	a5,a0,-11
    2054:	00f417b3          	sll	a5,s0,a5
    2058:	00000413          	addi	s0,zero,0
    205c:	fe9ff06f          	jal	zero,2044 <__extendsfdf2+0xb0>
    2060:	00000793          	addi	a5,zero,0
    2064:	00040a63          	beq	s0,zero,2078 <__extendsfdf2+0xe4>
    2068:	00345793          	srli	a5,s0,0x3
    206c:	00080737          	lui	a4,0x80
    2070:	01d41413          	slli	s0,s0,0x1d
    2074:	00e7e7b3          	or	a5,a5,a4
    2078:	7ff00713          	addi	a4,zero,2047
    207c:	f5dff06f          	jal	zero,1fd8 <__extendsfdf2+0x44>

00002080 <__truncdfsf2>:
    2080:	0145d713          	srli	a4,a1,0x14
    2084:	7ff77713          	andi	a4,a4,2047
    2088:	00c59793          	slli	a5,a1,0xc
    208c:	00170613          	addi	a2,a4,1 # 80001 <__heap_end+0x5a801>
    2090:	0097d793          	srli	a5,a5,0x9
    2094:	01d55693          	srli	a3,a0,0x1d
    2098:	7fe67613          	andi	a2,a2,2046
    209c:	00f6e6b3          	or	a3,a3,a5
    20a0:	01f5d593          	srli	a1,a1,0x1f
    20a4:	00351793          	slli	a5,a0,0x3
    20a8:	0c060063          	beq	a2,zero,2168 <__truncdfsf2+0xe8>
    20ac:	c8070613          	addi	a2,a4,-896
    20b0:	0fe00813          	addi	a6,zero,254
    20b4:	10c84663          	blt	a6,a2,21c0 <__truncdfsf2+0x140>
    20b8:	06c04c63          	blt	zero,a2,2130 <__truncdfsf2+0xb0>
    20bc:	fe900513          	addi	a0,zero,-23
    20c0:	0ea64a63          	blt	a2,a0,21b4 <__truncdfsf2+0x134>
    20c4:	00800537          	lui	a0,0x800
    20c8:	01e00813          	addi	a6,zero,30
    20cc:	00a6e6b3          	or	a3,a3,a0
    20d0:	40c80833          	sub	a6,a6,a2
    20d4:	01f00513          	addi	a0,zero,31
    20d8:	03054463          	blt	a0,a6,2100 <__truncdfsf2+0x80>
    20dc:	c8270713          	addi	a4,a4,-894
    20e0:	0107d833          	srl	a6,a5,a6
    20e4:	00e797b3          	sll	a5,a5,a4
    20e8:	00f037b3          	sltu	a5,zero,a5
    20ec:	00e696b3          	sll	a3,a3,a4
    20f0:	00d7e7b3          	or	a5,a5,a3
    20f4:	00f867b3          	or	a5,a6,a5
    20f8:	00000713          	addi	a4,zero,0
    20fc:	0500006f          	jal	zero,214c <__truncdfsf2+0xcc>
    2100:	ffe00513          	addi	a0,zero,-2
    2104:	40c50533          	sub	a0,a0,a2
    2108:	02000893          	addi	a7,zero,32
    210c:	00a6d533          	srl	a0,a3,a0
    2110:	00000613          	addi	a2,zero,0
    2114:	01180663          	beq	a6,a7,2120 <__truncdfsf2+0xa0>
    2118:	ca270613          	addi	a2,a4,-862
    211c:	00c69633          	sll	a2,a3,a2
    2120:	00f66633          	or	a2,a2,a5
    2124:	00c03633          	sltu	a2,zero,a2
    2128:	00c567b3          	or	a5,a0,a2
    212c:	fcdff06f          	jal	zero,20f8 <__truncdfsf2+0x78>
    2130:	00651713          	slli	a4,a0,0x6
    2134:	00e03733          	sltu	a4,zero,a4
    2138:	00369693          	slli	a3,a3,0x3
    213c:	00d76733          	or	a4,a4,a3
    2140:	01d7d793          	srli	a5,a5,0x1d
    2144:	00f767b3          	or	a5,a4,a5
    2148:	00060713          	addi	a4,a2,0 # 10000 <__lock___libc_recursive_mutex+0x3250>
    214c:	0077f693          	andi	a3,a5,7
    2150:	00068863          	beq	a3,zero,2160 <__truncdfsf2+0xe0>
    2154:	00f7f693          	andi	a3,a5,15
    2158:	00400613          	addi	a2,zero,4
    215c:	00c69e63          	bne	a3,a2,2178 <__truncdfsf2+0xf8>
    2160:	0037d793          	srli	a5,a5,0x3
    2164:	03c0006f          	jal	zero,21a0 <__truncdfsf2+0x120>
    2168:	00f6e7b3          	or	a5,a3,a5
    216c:	02071263          	bne	a4,zero,2190 <__truncdfsf2+0x110>
    2170:	02078863          	beq	a5,zero,21a0 <__truncdfsf2+0x120>
    2174:	00100793          	addi	a5,zero,1
    2178:	00478793          	addi	a5,a5,4
    217c:	00579693          	slli	a3,a5,0x5
    2180:	fe06d0e3          	bge	a3,zero,2160 <__truncdfsf2+0xe0>
    2184:	00170713          	addi	a4,a4,1
    2188:	00000793          	addi	a5,zero,0
    218c:	0140006f          	jal	zero,21a0 <__truncdfsf2+0x120>
    2190:	0ff00713          	addi	a4,zero,255
    2194:	00078663          	beq	a5,zero,21a0 <__truncdfsf2+0x120>
    2198:	004007b7          	lui	a5,0x400
    219c:	00f6e7b3          	or	a5,a3,a5
    21a0:	01771713          	slli	a4,a4,0x17
    21a4:	00f76733          	or	a4,a4,a5
    21a8:	01f59513          	slli	a0,a1,0x1f
    21ac:	00a76533          	or	a0,a4,a0
    21b0:	00008067          	jalr	zero,0(ra)
    21b4:	00100793          	addi	a5,zero,1
    21b8:	00000713          	addi	a4,zero,0
    21bc:	fbdff06f          	jal	zero,2178 <__truncdfsf2+0xf8>
    21c0:	0ff00713          	addi	a4,zero,255
    21c4:	fc5ff06f          	jal	zero,2188 <__truncdfsf2+0x108>

000021c8 <__lshrdi3>:
    21c8:	02060063          	beq	a2,zero,21e8 <__lshrdi3+0x20>
    21cc:	02000793          	addi	a5,zero,32
    21d0:	40c787b3          	sub	a5,a5,a2
    21d4:	00f04c63          	blt	zero,a5,21ec <__lshrdi3+0x24>
    21d8:	fe060613          	addi	a2,a2,-32
    21dc:	00c5d533          	srl	a0,a1,a2
    21e0:	00000713          	addi	a4,zero,0
    21e4:	00070593          	addi	a1,a4,0
    21e8:	00008067          	jalr	zero,0(ra)
    21ec:	00c5d733          	srl	a4,a1,a2
    21f0:	00c55533          	srl	a0,a0,a2
    21f4:	00f595b3          	sll	a1,a1,a5
    21f8:	00b56533          	or	a0,a0,a1
    21fc:	fe9ff06f          	jal	zero,21e4 <__lshrdi3+0x1c>

00002200 <__ashldi3>:
    2200:	02060063          	beq	a2,zero,2220 <__ashldi3+0x20>
    2204:	02000793          	addi	a5,zero,32
    2208:	40c787b3          	sub	a5,a5,a2
    220c:	00f04c63          	blt	zero,a5,2224 <__ashldi3+0x24>
    2210:	fe060613          	addi	a2,a2,-32
    2214:	00c515b3          	sll	a1,a0,a2
    2218:	00000713          	addi	a4,zero,0
    221c:	00070513          	addi	a0,a4,0
    2220:	00008067          	jalr	zero,0(ra)
    2224:	00c51733          	sll	a4,a0,a2
    2228:	00c595b3          	sll	a1,a1,a2
    222c:	00f55533          	srl	a0,a0,a5
    2230:	00a5e5b3          	or	a1,a1,a0
    2234:	fe9ff06f          	jal	zero,221c <__ashldi3+0x1c>

00002238 <__clzsi2>:
    2238:	000107b7          	lui	a5,0x10
    223c:	02f57a63          	bgeu	a0,a5,2270 <__clzsi2+0x38>
    2240:	10053793          	sltiu	a5,a0,256
    2244:	0017b793          	sltiu	a5,a5,1
    2248:	00379793          	slli	a5,a5,0x3
    224c:	02000713          	addi	a4,zero,32
    2250:	40f70733          	sub	a4,a4,a5
    2254:	00f55533          	srl	a0,a0,a5
    2258:	0000a797          	auipc	a5,0xa
    225c:	79c78793          	addi	a5,a5,1948 # c9f4 <__clz_tab>
    2260:	00a787b3          	add	a5,a5,a0
    2264:	0007c503          	lbu	a0,0(a5)
    2268:	40a70533          	sub	a0,a4,a0
    226c:	00008067          	jalr	zero,0(ra)
    2270:	01000737          	lui	a4,0x1000
    2274:	01800793          	addi	a5,zero,24
    2278:	fce57ae3          	bgeu	a0,a4,224c <__clzsi2+0x14>
    227c:	01000793          	addi	a5,zero,16
    2280:	fcdff06f          	jal	zero,224c <__clzsi2+0x14>

00002284 <__riscv_save_12>:
    2284:	fc010113          	addi	sp,sp,-64
    2288:	00000313          	addi	t1,zero,0
    228c:	01b12623          	sw	s11,12(sp)
    2290:	00c0006f          	jal	zero,229c <__riscv_save_10+0x8>

00002294 <__riscv_save_10>:
    2294:	fc010113          	addi	sp,sp,-64
    2298:	ff000313          	addi	t1,zero,-16
    229c:	01a12823          	sw	s10,16(sp)
    22a0:	01912a23          	sw	s9,20(sp)
    22a4:	01812c23          	sw	s8,24(sp)
    22a8:	01712e23          	sw	s7,28(sp)
    22ac:	00c0006f          	jal	zero,22b8 <__riscv_save_4+0x8>

000022b0 <__riscv_save_4>:
    22b0:	fc010113          	addi	sp,sp,-64
    22b4:	fe000313          	addi	t1,zero,-32
    22b8:	03612023          	sw	s6,32(sp)
    22bc:	03512223          	sw	s5,36(sp)
    22c0:	03412423          	sw	s4,40(sp)
    22c4:	03312623          	sw	s3,44(sp)
    22c8:	03212823          	sw	s2,48(sp)
    22cc:	02912a23          	sw	s1,52(sp)
    22d0:	02812c23          	sw	s0,56(sp)
    22d4:	02112e23          	sw	ra,60(sp)
    22d8:	40610133          	sub	sp,sp,t1
    22dc:	00028067          	jalr	zero,0(t0)

000022e0 <__riscv_save_0>:
    22e0:	ff010113          	addi	sp,sp,-16
    22e4:	01212023          	sw	s2,0(sp)
    22e8:	00912223          	sw	s1,4(sp)
    22ec:	00812423          	sw	s0,8(sp)
    22f0:	00112623          	sw	ra,12(sp)
    22f4:	00028067          	jalr	zero,0(t0)

000022f8 <__riscv_restore_12>:
    22f8:	00c12d83          	lw	s11,12(sp)
    22fc:	01010113          	addi	sp,sp,16

00002300 <__riscv_restore_10>:
    2300:	00012d03          	lw	s10,0(sp)
    2304:	00412c83          	lw	s9,4(sp)
    2308:	00812c03          	lw	s8,8(sp)
    230c:	00c12b83          	lw	s7,12(sp)
    2310:	01010113          	addi	sp,sp,16

00002314 <__riscv_restore_4>:
    2314:	00012b03          	lw	s6,0(sp)
    2318:	00412a83          	lw	s5,4(sp)
    231c:	00812a03          	lw	s4,8(sp)
    2320:	00c12983          	lw	s3,12(sp)
    2324:	01010113          	addi	sp,sp,16

00002328 <__riscv_restore_0>:
    2328:	00012903          	lw	s2,0(sp)
    232c:	00412483          	lw	s1,4(sp)
    2330:	00812403          	lw	s0,8(sp)
    2334:	00c12083          	lw	ra,12(sp)
    2338:	01010113          	addi	sp,sp,16
    233c:	00008067          	jalr	zero,0(ra)

00002340 <memset>:
    2340:	00050313          	addi	t1,a0,0 # 800000 <__heap_end+0x7da800>
    2344:	00060a63          	beq	a2,zero,2358 <memset+0x18>
    2348:	00b30023          	sb	a1,0(t1)
    234c:	fff60613          	addi	a2,a2,-1
    2350:	00130313          	addi	t1,t1,1
    2354:	fe061ae3          	bne	a2,zero,2348 <memset+0x8>
    2358:	00008067          	jalr	zero,0(ra)

0000235c <__malloc_free>:
    235c:	0a050463          	beq	a0,zero,2404 <__malloc_free+0xa8>
    2360:	f81ff2ef          	jal	t0,22e0 <__riscv_save_0>
    2364:	0000d4b7          	lui	s1,0xd
    2368:	00052023          	sw	zero,0(a0)
    236c:	00050413          	addi	s0,a0,0
    2370:	db048513          	addi	a0,s1,-592 # cdb0 <__lock___libc_recursive_mutex>
    2374:	25c000ef          	jal	ra,25d0 <__retarget_lock_acquire_recursive>
    2378:	0000d737          	lui	a4,0xd
    237c:	dac72783          	lw	a5,-596(a4) # cdac <__malloc_free_list>
    2380:	dac70713          	addi	a4,a4,-596
    2384:	00079863          	bne	a5,zero,2394 <__malloc_free+0x38>
    2388:	00f42023          	sw	a5,0(s0)
    238c:	00872023          	sw	s0,0(a4)
    2390:	0440006f          	jal	zero,23d4 <__malloc_free+0x78>
    2394:	0087ee63          	bltu	a5,s0,23b0 <__malloc_free+0x54>
    2398:	fef418e3          	bne	s0,a5,2388 <__malloc_free+0x2c>
    239c:	00c00713          	addi	a4,zero,12
    23a0:	00e22023          	sw	a4,0(tp) # 0 <_start>
    23a4:	db048513          	addi	a0,s1,-592
    23a8:	22c000ef          	jal	ra,25d4 <__retarget_lock_release_recursive>
    23ac:	f7dff06f          	jal	zero,2328 <__riscv_restore_0>
    23b0:	ffc7a603          	lw	a2,-4(a5)
    23b4:	0007a683          	lw	a3,0(a5)
    23b8:	00c78733          	add	a4,a5,a2
    23bc:	02e41e63          	bne	s0,a4,23f8 <__malloc_free+0x9c>
    23c0:	ffc42703          	lw	a4,-4(s0)
    23c4:	00078413          	addi	s0,a5,0
    23c8:	00c70733          	add	a4,a4,a2
    23cc:	fee7ae23          	sw	a4,-4(a5)
    23d0:	00068793          	addi	a5,a3,0
    23d4:	ffc42683          	lw	a3,-4(s0)
    23d8:	00d40733          	add	a4,s0,a3
    23dc:	fce794e3          	bne	a5,a4,23a4 <__malloc_free+0x48>
    23e0:	ffc7a703          	lw	a4,-4(a5)
    23e4:	0007a783          	lw	a5,0(a5)
    23e8:	00d70733          	add	a4,a4,a3
    23ec:	fee42e23          	sw	a4,-4(s0)
    23f0:	00f42023          	sw	a5,0(s0)
    23f4:	fb1ff06f          	jal	zero,23a4 <__malloc_free+0x48>
    23f8:	00078713          	addi	a4,a5,0
    23fc:	00068793          	addi	a5,a3,0
    2400:	f85ff06f          	jal	zero,2384 <__malloc_free+0x28>
    2404:	00008067          	jalr	zero,0(ra)

00002408 <__malloc_sbrk_aligned>:
    2408:	ea9ff2ef          	jal	t0,22b0 <__riscv_save_4>
    240c:	00055863          	bge	a0,zero,241c <__malloc_sbrk_aligned+0x14>
    2410:	fff00913          	addi	s2,zero,-1
    2414:	00090513          	addi	a0,s2,0
    2418:	efdff06f          	jal	zero,2314 <__riscv_restore_4>
    241c:	00050413          	addi	s0,a0,0
    2420:	1b8000ef          	jal	ra,25d8 <sbrk>
    2424:	fff00793          	addi	a5,zero,-1
    2428:	fef504e3          	beq	a0,a5,2410 <__malloc_sbrk_aligned+0x8>
    242c:	01350913          	addi	s2,a0,19
    2430:	00850433          	add	s0,a0,s0
    2434:	0000d9b7          	lui	s3,0xd
    2438:	ff097913          	andi	s2,s2,-16
    243c:	da89a223          	sw	s0,-604(s3) # cda4 <__malloc_sbrk_top>
    2440:	ffc90913          	addi	s2,s2,-4
    2444:	01250e63          	beq	a0,s2,2460 <__malloc_sbrk_aligned+0x58>
    2448:	40a904b3          	sub	s1,s2,a0
    244c:	00048513          	addi	a0,s1,0
    2450:	188000ef          	jal	ra,25d8 <sbrk>
    2454:	faa41ee3          	bne	s0,a0,2410 <__malloc_sbrk_aligned+0x8>
    2458:	00940433          	add	s0,s0,s1
    245c:	da89a223          	sw	s0,-604(s3)
    2460:	0000d7b7          	lui	a5,0xd
    2464:	da87a703          	lw	a4,-600(a5) # cda8 <__malloc_sbrk_start>
    2468:	fa0716e3          	bne	a4,zero,2414 <__malloc_sbrk_aligned+0xc>
    246c:	db27a423          	sw	s2,-600(a5)
    2470:	fa5ff06f          	jal	zero,2414 <__malloc_sbrk_aligned+0xc>

00002474 <__malloc_grow_chunk>:
    2474:	e6dff2ef          	jal	t0,22e0 <__riscv_save_0>
    2478:	ffc52783          	lw	a5,-4(a0)
    247c:	0000d737          	lui	a4,0xd
    2480:	da472703          	lw	a4,-604(a4) # cda4 <__malloc_sbrk_top>
    2484:	ffc78913          	addi	s2,a5,-4
    2488:	01250933          	add	s2,a0,s2
    248c:	05271663          	bne	a4,s2,24d8 <__malloc_grow_chunk+0x64>
    2490:	40f58433          	sub	s0,a1,a5
    2494:	00800793          	addi	a5,zero,8
    2498:	00050493          	addi	s1,a0,0
    249c:	00f47463          	bgeu	s0,a5,24a4 <__malloc_grow_chunk+0x30>
    24a0:	00078413          	addi	s0,a5,0
    24a4:	00040513          	addi	a0,s0,0
    24a8:	f61ff0ef          	jal	ra,2408 <__malloc_sbrk_aligned>
    24ac:	00a91c63          	bne	s2,a0,24c4 <__malloc_grow_chunk+0x50>
    24b0:	ffc4a783          	lw	a5,-4(s1)
    24b4:	00100513          	addi	a0,zero,1
    24b8:	008787b3          	add	a5,a5,s0
    24bc:	fef4ae23          	sw	a5,-4(s1)
    24c0:	e69ff06f          	jal	zero,2328 <__riscv_restore_0>
    24c4:	fff00793          	addi	a5,zero,-1
    24c8:	00f50863          	beq	a0,a5,24d8 <__malloc_grow_chunk+0x64>
    24cc:	00852023          	sw	s0,0(a0)
    24d0:	00450513          	addi	a0,a0,4
    24d4:	e89ff0ef          	jal	ra,235c <__malloc_free>
    24d8:	00000513          	addi	a0,zero,0
    24dc:	fe5ff06f          	jal	zero,24c0 <__malloc_grow_chunk+0x4c>

000024e0 <__malloc_malloc>:
    24e0:	dd1ff2ef          	jal	t0,22b0 <__riscv_save_4>
    24e4:	fdb00793          	addi	a5,zero,-37
    24e8:	00a7fc63          	bgeu	a5,a0,2500 <__malloc_malloc+0x20>
    24ec:	00c00713          	addi	a4,zero,12
    24f0:	00e22023          	sw	a4,0(tp) # 0 <_start>
    24f4:	00000413          	addi	s0,zero,0
    24f8:	00040513          	addi	a0,s0,0
    24fc:	e19ff06f          	jal	zero,2314 <__riscv_restore_4>
    2500:	00f50513          	addi	a0,a0,15
    2504:	0000da37          	lui	s4,0xd
    2508:	ff057493          	andi	s1,a0,-16
    250c:	0000d9b7          	lui	s3,0xd
    2510:	db0a0513          	addi	a0,s4,-592 # cdb0 <__lock___libc_recursive_mutex>
    2514:	01048913          	addi	s2,s1,16
    2518:	0b8000ef          	jal	ra,25d0 <__retarget_lock_acquire_recursive>
    251c:	dac98993          	addi	s3,s3,-596 # cdac <__malloc_free_list>
    2520:	0009a403          	lw	s0,0(s3)
    2524:	02041463          	bne	s0,zero,254c <__malloc_malloc+0x6c>
    2528:	00090513          	addi	a0,s2,0
    252c:	eddff0ef          	jal	ra,2408 <__malloc_sbrk_aligned>
    2530:	fff00793          	addi	a5,zero,-1
    2534:	08f51863          	bne	a0,a5,25c4 <__malloc_malloc+0xe4>
    2538:	00c00713          	addi	a4,zero,12
    253c:	db0a0513          	addi	a0,s4,-592
    2540:	00e22023          	sw	a4,0(tp) # 0 <_start>
    2544:	090000ef          	jal	ra,25d4 <__retarget_lock_release_recursive>
    2548:	fadff06f          	jal	zero,24f4 <__malloc_malloc+0x14>
    254c:	ffc42783          	lw	a5,-4(s0)
    2550:	00042703          	lw	a4,0(s0)
    2554:	0527e463          	bltu	a5,s2,259c <__malloc_malloc+0xbc>
    2558:	412787b3          	sub	a5,a5,s2
    255c:	00700693          	addi	a3,zero,7
    2560:	02f6fa63          	bgeu	a3,a5,2594 <__malloc_malloc+0xb4>
    2564:	012406b3          	add	a3,s0,s2
    2568:	fef6ae23          	sw	a5,-4(a3)
    256c:	00e6a023          	sw	a4,0(a3)
    2570:	00d9a023          	sw	a3,0(s3)
    2574:	ff242e23          	sw	s2,-4(s0)
    2578:	db0a0513          	addi	a0,s4,-592
    257c:	058000ef          	jal	ra,25d4 <__retarget_lock_release_recursive>
    2580:	00c48613          	addi	a2,s1,12
    2584:	00000593          	addi	a1,zero,0
    2588:	00040513          	addi	a0,s0,0
    258c:	db5ff0ef          	jal	ra,2340 <memset>
    2590:	f69ff06f          	jal	zero,24f8 <__malloc_malloc+0x18>
    2594:	00e9a023          	sw	a4,0(s3)
    2598:	fe1ff06f          	jal	zero,2578 <__malloc_malloc+0x98>
    259c:	02071063          	bne	a4,zero,25bc <__malloc_malloc+0xdc>
    25a0:	00090593          	addi	a1,s2,0
    25a4:	00040513          	addi	a0,s0,0
    25a8:	ecdff0ef          	jal	ra,2474 <__malloc_grow_chunk>
    25ac:	00050863          	beq	a0,zero,25bc <__malloc_malloc+0xdc>
    25b0:	00042783          	lw	a5,0(s0)
    25b4:	00f9a023          	sw	a5,0(s3)
    25b8:	fc1ff06f          	jal	zero,2578 <__malloc_malloc+0x98>
    25bc:	00040993          	addi	s3,s0,0
    25c0:	f61ff06f          	jal	zero,2520 <__malloc_malloc+0x40>
    25c4:	00450413          	addi	s0,a0,4
    25c8:	01252023          	sw	s2,0(a0)
    25cc:	fadff06f          	jal	zero,2578 <__malloc_malloc+0x98>

000025d0 <__retarget_lock_acquire_recursive>:
    25d0:	00008067          	jalr	zero,0(ra)

000025d4 <__retarget_lock_release_recursive>:
    25d4:	00008067          	jalr	zero,0(ra)

000025d8 <sbrk>:
    25d8:	00050793          	addi	a5,a0,0
    25dc:	0000d6b7          	lui	a3,0xd
    25e0:	b106a503          	lw	a0,-1264(a3) # cb10 <__brk>
    25e4:	0207d463          	bge	a5,zero,260c <sbrk+0x34>
    25e8:	00019737          	lui	a4,0x19
    25ec:	00070713          	addi	a4,a4,0 # 19000 <__heap_start>
    25f0:	40e50733          	sub	a4,a0,a4
    25f4:	40f00633          	sub	a2,zero,a5
    25f8:	02c77263          	bgeu	a4,a2,261c <sbrk+0x44>
    25fc:	00c00713          	addi	a4,zero,12
    2600:	00e22023          	sw	a4,0(tp) # 0 <_start>
    2604:	fff00513          	addi	a0,zero,-1
    2608:	00008067          	jalr	zero,0(ra)
    260c:	00026737          	lui	a4,0x26
    2610:	80070713          	addi	a4,a4,-2048 # 25800 <__heap_end>
    2614:	40a70733          	sub	a4,a4,a0
    2618:	fef762e3          	bltu	a4,a5,25fc <sbrk+0x24>
    261c:	00f507b3          	add	a5,a0,a5
    2620:	b0f6a823          	sw	a5,-1264(a3)
    2624:	00008067          	jalr	zero,0(ra)

Disassembly of section .rodata:

0000c800 <__clz_tab-0x1f4>:
    c800:	34323032          	.word	0x34323032
    c804:	32313133          	.word	0x32313133
    c808:	54203037          	.word	0x54203037
    c80c:	20747365          	.word	0x20747365
    c810:	2d203223          	.word	0x2d203223
    c814:	726f5320          	.word	0x726f5320
    c818:	676e6974          	.word	0x676e6974
    c81c:	73657420          	.word	0x73657420
    c820:	000a3a74          	.word	0x000a3a74
    c824:	6168503c          	.word	0x6168503c
    c828:	30206573          	.word	0x30206573
    c82c:	202d203e          	.word	0x202d203e
    c830:	65786946          	.word	0x65786946
    c834:	69732064          	.word	0x69732064
    c838:	7320657a          	.word	0x7320657a
    c83c:	6974726f          	.word	0x6974726f
    c840:	7420676e          	.word	0x7420676e
    c844:	3a747365          	.word	0x3a747365
    c848:	0000000a          	.word	0x0000000a
    c84c:	65746e45          	.word	0x65746e45
    c850:	20382072          	.word	0x20382072
    c854:	65746e69          	.word	0x65746e69
    c858:	73726567          	.word	0x73726567
    c85c:	00000a3a          	.word	0x00000a3a
    c860:	00006425          	.word	0x00006425
    c864:	74726f53          	.word	0x74726f53
    c868:	61206465          	.word	0x61206465
    c86c:	79617272          	.word	0x79617272
    c870:	00000a3a          	.word	0x00000a3a
    c874:	00206425          	.word	0x00206425
    c878:	6d69540a          	.word	0x6d69540a
    c87c:	6f632065          	.word	0x6f632065
    c880:	6d75736e          	.word	0x6d75736e
    c884:	203a6465          	.word	0x203a6465
    c888:	6d206625          	.word	0x6d206625
    c88c:	00000a73          	.word	0x00000a73
    c890:	68503c0a          	.word	0x68503c0a
    c894:	20657361          	.word	0x20657361
    c898:	2d203e31          	.word	0x2d203e31
    c89c:	6c614d20          	.word	0x6c614d20
    c8a0:	20636f6c          	.word	0x20636f6c
    c8a4:	74736574          	.word	0x74736574
    c8a8:	00000a3a          	.word	0x00000a3a
    c8ac:	65746e45          	.word	0x65746e45
    c8b0:	68742072          	.word	0x68742072
    c8b4:	69732065          	.word	0x69732065
    c8b8:	6f20657a          	.word	0x6f20657a
    c8bc:	68742066          	.word	0x68742066
    c8c0:	72612065          	.word	0x72612065
    c8c4:	3a796172          	.word	0x3a796172
    c8c8:	0000000a          	.word	0x0000000a
    c8cc:	6c6c616d          	.word	0x6c6c616d
    c8d0:	6620636f          	.word	0x6620636f
    c8d4:	656c6961          	.word	0x656c6961
    c8d8:	6c500a64          	.word	0x6c500a64
    c8dc:	65736165          	.word	0x65736165
    c8e0:	706e6920          	.word	0x706e6920
    c8e4:	61207475          	.word	0x61207475
    c8e8:	616d7320          	.word	0x616d7320
    c8ec:	72656c6c          	.word	0x72656c6c
    c8f0:	6d756e20          	.word	0x6d756e20
    c8f4:	0a726562          	.word	0x0a726562
    c8f8:	00000000          	.word	0x00000000
    c8fc:	61727261          	.word	0x61727261
    c900:	65672079          	.word	0x65672079
    c904:	6172656e          	.word	0x6172656e
    c908:	3a646574          	.word	0x3a646574
    c90c:	0000000a          	.word	0x0000000a
    c910:	0000000a          	.word	0x0000000a
    c914:	726f530a          	.word	0x726f530a
    c918:	20646574          	.word	0x20646574
    c91c:	61727261          	.word	0x61727261
    c920:	000a3a79          	.word	0x000a3a79
    c924:	6c616d0a          	.word	0x6c616d0a
    c928:	20636f6c          	.word	0x20636f6c
    c92c:	656c6572          	.word	0x656c6572
    c930:	64657361          	.word	0x64657361
    c934:	00000a2e          	.word	0x00000a2e
    c938:	447a0000          	.word	0x447a0000
    c93c:	4c3ebc20          	.word	0x4c3ebc20
    c940:	33323130          	.word	0x33323130
    c944:	37363534          	.word	0x37363534
    c948:	42413938          	.word	0x42413938
    c94c:	46454443          	.word	0x46454443
    c950:	00000000          	.word	0x00000000
    c954:	00000d64          	.word	0x00000d64
    c958:	00000da0          	.word	0x00000da0
    c95c:	00000e54          	.word	0x00000e54
    c960:	00000e0c          	.word	0x00000e0c
    c964:	00000e54          	.word	0x00000e54
    c968:	00000e54          	.word	0x00000e54
    c96c:	00000e54          	.word	0x00000e54
    c970:	00000e54          	.word	0x00000e54
    c974:	00000e54          	.word	0x00000e54
    c978:	00000e54          	.word	0x00000e54
    c97c:	00000e54          	.word	0x00000e54
    c980:	00000e54          	.word	0x00000e54
    c984:	00000e54          	.word	0x00000e54
    c988:	00000e54          	.word	0x00000e54
    c98c:	00000e54          	.word	0x00000e54
    c990:	00000e54          	.word	0x00000e54
    c994:	00000d84          	.word	0x00000d84
    c998:	00000e54          	.word	0x00000e54
    c99c:	00000dc4          	.word	0x00000dc4
    c9a0:	00000e54          	.word	0x00000e54
    c9a4:	00000e54          	.word	0x00000e54
    c9a8:	00000de8          	.word	0x00000de8
    c9ac:	447a0000          	.word	0x447a0000
    c9b0:	4c3ebc20          	.word	0x4c3ebc20
    c9b4:	49742400          	.word	0x49742400
    c9b8:	ffff4dd0          	.word	0xffff4dd0
    c9bc:	ffff4e08          	.word	0xffff4e08
    c9c0:	ffff4e14          	.word	0xffff4e14
    c9c4:	ffff4e08          	.word	0xffff4e08
    c9c8:	ffff4e70          	.word	0xffff4e70
    c9cc:	ffff4e08          	.word	0xffff4e08
    c9d0:	ffff4e14          	.word	0xffff4e14
    c9d4:	ffff4dd0          	.word	0xffff4dd0
    c9d8:	ffff4dd0          	.word	0xffff4dd0
    c9dc:	ffff4e70          	.word	0xffff4e70
    c9e0:	ffff4e14          	.word	0xffff4e14
    c9e4:	ffff4de4          	.word	0xffff4de4
    c9e8:	ffff4de4          	.word	0xffff4de4
    c9ec:	ffff4de4          	.word	0xffff4de4
    c9f0:	ffff4e70          	.word	0xffff4e70

0000c9f4 <__clz_tab>:
    c9f4:	02020100 03030303 04040404 04040404     ................
    ca04:	05050505 05050505 05050505 05050505     ................
    ca14:	06060606 06060606 06060606 06060606     ................
    ca24:	06060606 06060606 06060606 06060606     ................
    ca34:	07070707 07070707 07070707 07070707     ................
    ca44:	07070707 07070707 07070707 07070707     ................
    ca54:	07070707 07070707 07070707 07070707     ................
    ca64:	07070707 07070707 07070707 07070707     ................
    ca74:	08080808 08080808 08080808 08080808     ................
    ca84:	08080808 08080808 08080808 08080808     ................
    ca94:	08080808 08080808 08080808 08080808     ................
    caa4:	08080808 08080808 08080808 08080808     ................
    cab4:	08080808 08080808 08080808 08080808     ................
    cac4:	08080808 08080808 08080808 08080808     ................
    cad4:	08080808 08080808 08080808 08080808     ................
    cae4:	08080808 08080808 08080808 08080808     ................

Disassembly of section .sdata:

0000caf4 <heap_end.0>:
    caf4:	00019000                                ....

0000caf8 <timer_low>:
    caf8:	ffff4000                                .@..

0000cafc <timer_high>:
    cafc:	ffff4008                                .@..

0000cb00 <uart_rx_fifo>:
    cb00:	ffff3000                                .0..

0000cb04 <uart_tx_fifo>:
    cb04:	ffff3004                                .0..

0000cb08 <uart_stat_reg>:
    cb08:	ffff3008                                .0..

0000cb0c <uart_ctrl_reg>:
    cb0c:	ffff300c                                .0..

0000cb10 <__brk>:
    cb10:	00019000                                ....
