
kernel.elf:     file format elf32-loongarch


Disassembly of section .text:

1c000000 <INITLOCATE>:
INITLOCATE():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/evec.S:7

    .p2align 2
    .section .text.init
    .global INITLOCATE
INITLOCATE:                         // 定位启动程序
    la.local     t0,START
1c000000:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c000004:	0280018c 	addi.w	$r12,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/evec.S:8
    jirl        zero,t0,0x0
1c000008:	4c000180 	jirl	$r0,$r12,0
	...

1c001000 <START>:
START():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:81
.endm

    .global START
START:                                  // kernel init
    /* 1. CPUCFG: only enable cache path when L1 I-cache or D-cache exists. */
    li.w        t0, 0x10
1c001000:	0380400c 	ori	$r12,$r0,0x10
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:82
    cpucfg      t0, t0
1c001004:	00006d8c 	cpucfg	$r12,$r12
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:83
    CPUCFG_WAIT
1c001008:	03400000 	andi	$r0,$r0,0x0
1c00100c:	03400000 	andi	$r0,$r0,0x0
1c001010:	03400000 	andi	$r0,$r0,0x0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:84
    andi        s6, t0, 0x4             // remember whether L1 D-cache exists
1c001014:	0340119d 	andi	$r29,$r12,0x4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:85
    andi        t1, t0, 0x5             // bit0: L1 I-cache, bit2: L1 D-cache
1c001018:	0340158d 	andi	$r13,$r12,0x5
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:86
    beq         t1, zero, no_cache_mmu
1c00101c:	580169a0 	beq	$r13,$r0,360(0x168) # 1c001184 <no_cache_mmu>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:87
    li.w        s7, 0x1                 // remember that DMW/cache path is active
1c001020:	0380041e 	ori	$r30,$r0,0x1
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:90

    /* 2. cache 初始化 (通过 cpucfg 动态获取参数清空 I/D Cache) */
    INIT_CACHE  0x11, 0x00, 0x1         // L1 I-cache present: CPUCFG.0x10 bit 0
1c001024:	0380400c 	ori	$r12,$r0,0x10
1c001028:	00006d8c 	cpucfg	$r12,$r12
1c00102c:	03400000 	andi	$r0,$r0,0x0
1c001030:	03400000 	andi	$r0,$r0,0x0
1c001034:	03400000 	andi	$r0,$r0,0x0
1c001038:	0340058c 	andi	$r12,$r12,0x1
1c00103c:	58006180 	beq	$r12,$r0,96(0x60) # 1c00109c <START+0x9c>
1c001040:	0380440c 	ori	$r12,$r0,0x11
1c001044:	00006d8c 	cpucfg	$r12,$r12
1c001048:	03400000 	andi	$r0,$r0,0x0
1c00104c:	03400000 	andi	$r0,$r0,0x0
1c001050:	03400000 	andi	$r0,$r0,0x0
1c001054:	0044e18f 	srli.w	$r15,$r12,0x18
1c001058:	0341fdef 	andi	$r15,$r15,0x7f
1c00105c:	0044c190 	srli.w	$r16,$r12,0x10
1c001060:	0343fe10 	andi	$r16,$r16,0xff
1c001064:	0380040e 	ori	$r14,$r0,0x1
1c001068:	001741ce 	sll.w	$r14,$r14,$r16
1c00106c:	0040c191 	slli.w	$r17,$r12,0x10
1c001070:	0044c231 	srli.w	$r17,$r17,0x10
1c001074:	0015000c 	move	$r12,$r0
1c001078:	00173d8d 	sll.w	$r13,$r12,$r15
1c00107c:	00150012 	move	$r18,$r0
1c001080:	001549b0 	or	$r16,$r13,$r18
1c001084:	06000200 	cacop	0x0,$r16,0
1c001088:	02800652 	addi.w	$r18,$r18,1(0x1)
1c00108c:	00124a33 	slt	$r19,$r17,$r18
1c001090:	5bfff260 	beq	$r19,$r0,-16(0x3fff0) # 1c001080 <START+0x80>
1c001094:	0280058c 	addi.w	$r12,$r12,1(0x1)
1c001098:	5fffe18e 	bne	$r12,$r14,-32(0x3ffe0) # 1c001078 <START+0x78>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:91
    INIT_CACHE  0x12, 0x01, 0x4         // L1 D-cache present: CPUCFG.0x10 bit 2
1c00109c:	0380400c 	ori	$r12,$r0,0x10
1c0010a0:	00006d8c 	cpucfg	$r12,$r12
1c0010a4:	03400000 	andi	$r0,$r0,0x0
1c0010a8:	03400000 	andi	$r0,$r0,0x0
1c0010ac:	03400000 	andi	$r0,$r0,0x0
1c0010b0:	0340118c 	andi	$r12,$r12,0x4
1c0010b4:	58006180 	beq	$r12,$r0,96(0x60) # 1c001114 <START+0x114>
1c0010b8:	0380480c 	ori	$r12,$r0,0x12
1c0010bc:	00006d8c 	cpucfg	$r12,$r12
1c0010c0:	03400000 	andi	$r0,$r0,0x0
1c0010c4:	03400000 	andi	$r0,$r0,0x0
1c0010c8:	03400000 	andi	$r0,$r0,0x0
1c0010cc:	0044e18f 	srli.w	$r15,$r12,0x18
1c0010d0:	0341fdef 	andi	$r15,$r15,0x7f
1c0010d4:	0044c190 	srli.w	$r16,$r12,0x10
1c0010d8:	0343fe10 	andi	$r16,$r16,0xff
1c0010dc:	0380040e 	ori	$r14,$r0,0x1
1c0010e0:	001741ce 	sll.w	$r14,$r14,$r16
1c0010e4:	0040c191 	slli.w	$r17,$r12,0x10
1c0010e8:	0044c231 	srli.w	$r17,$r17,0x10
1c0010ec:	0015000c 	move	$r12,$r0
1c0010f0:	00173d8d 	sll.w	$r13,$r12,$r15
1c0010f4:	00150012 	move	$r18,$r0
1c0010f8:	001549b0 	or	$r16,$r13,$r18
1c0010fc:	06000201 	cacop	0x1,$r16,0
1c001100:	02800652 	addi.w	$r18,$r18,1(0x1)
1c001104:	00124a33 	slt	$r19,$r17,$r18
1c001108:	5bfff260 	beq	$r19,$r0,-16(0x3fff0) # 1c0010f8 <START+0xf8>
1c00110c:	0280058c 	addi.w	$r12,$r12,1(0x1)
1c001110:	5fffe18e 	bne	$r12,$r14,-32(0x3ffe0) # 1c0010f0 <START+0xf0>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:94

    /* Save D-cache geometry before entering DMW/PG mode. */
    beq         s6, zero, dcache_regs_done
1c001114:	58003ba0 	beq	$r29,$r0,56(0x38) # 1c00114c <dcache_regs_done>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:95
    li.w        t0,0x12
1c001118:	0380480c 	ori	$r12,$r0,0x12
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:96
    cpucfg      t0,t0
1c00111c:	00006d8c 	cpucfg	$r12,$r12
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:97
    CPUCFG_WAIT
1c001120:	03400000 	andi	$r0,$r0,0x0
1c001124:	03400000 	andi	$r0,$r0,0x0
1c001128:	03400000 	andi	$r0,$r0,0x0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:98
    srli.w      s2,t0,24
1c00112c:	0044e199 	srli.w	$r25,$r12,0x18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:99
    andi        s2,s2,0x7f              // offset_bits
1c001130:	0341ff39 	andi	$r25,$r25,0x7f
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:100
    srli.w      t4,t0,16
1c001134:	0044c190 	srli.w	$r16,$r12,0x10
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:101
    andi        t4,t4,0xff              // index_bits
1c001138:	0343fe10 	andi	$r16,$r16,0xff
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:102
    li.w        s3,1
1c00113c:	0380041a 	ori	$r26,$r0,0x1
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:103
    sll.w       s3,s3,t4                // total_sets
1c001140:	0017435a 	sll.w	$r26,$r26,$r16
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:104
    slli.w      s4,t0,16
1c001144:	0040c19b 	slli.w	$r27,$r12,0x10
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:105
    srli.w      s4,s4,16                // max_way
1c001148:	0044c37b 	srli.w	$r27,$r27,0x10

1c00114c <dcache_regs_done>:
dcache_regs_done():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:109
dcache_regs_done:

    /* 3. 配置 DMW */
    li.w        t0,0x8
1c00114c:	0380200c 	ori	$r12,$r0,0x8
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:110
    li.w        t1,0x18
1c001150:	0380600d 	ori	$r13,$r0,0x18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:111
    csrxchg     t0,t1,0x0               // open da mode
1c001154:	040001ac 	csrxchg	$r12,$r13,0x0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:113

    csrwr       zero,0x180
1c001158:	04060020 	csrwr	$r0,0x180
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:114
    csrwr       zero,0x181              // clear dmw0, dmw1
1c00115c:	04060420 	csrwr	$r0,0x181
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:115
    li.w        t0,0x19
1c001160:	0380640c 	ori	$r12,$r0,0x19
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:116
    csrwr       t0,0x180                // config dmw0 (MAT=1, Cached)
1c001164:	0406002c 	csrwr	$r12,0x180
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:117
    li.w        t0,0xa0000009
1c001168:	1540000c 	lu12i.w	$r12,-393216(0xa0000)
1c00116c:	0380258c 	ori	$r12,$r12,0x9
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:118
    csrwr       t0,0x181                // config dmw1
1c001170:	0406042c 	csrwr	$r12,0x181
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:120

    li.w        t0,0x10
1c001174:	0380400c 	ori	$r12,$r0,0x10
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:121
    li.w        t1,0x18
1c001178:	0380600d 	ori	$r13,$r0,0x18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:122
    csrxchg     t0,t1,0x0               // open pg mode
1c00117c:	040001ac 	csrxchg	$r12,$r13,0x0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:123
    b           crmd_init
1c001180:	50001000 	b	16(0x10) # 1c001190 <crmd_init>

1c001184 <no_cache_mmu>:
no_cache_mmu():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:127

no_cache_mmu:
    /* No I/D cache: rely on reset direct-address mode, no CSR writes. */
    li.w        s6, 0x0
1c001184:	0015001d 	move	$r29,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:128
    li.w        s7, 0x0
1c001188:	0015001e 	move	$r30,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:129
    b           runtime_init
1c00118c:	50000c00 	b	12(0xc) # 1c001198 <runtime_init>

1c001190 <crmd_init>:
crmd_init():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:133

crmd_init:
    /* 4. 配置 CSR.CRMD */
    li.w        t1, 0x4
1c001190:	0380100d 	ori	$r13,$r0,0x4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:134
    csrxchg     t1, t1, 0x0             // csr_crmd
1c001194:	040001ad 	csrxchg	$r13,$r13,0x0

1c001198 <runtime_init>:
runtime_init():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:138

runtime_init:
    /* 5. 运行程序 */
    la.local    t0,_sbss
1c001198:	1c00fdec 	pcaddu12i	$r12,2031(0x7ef)
1c00119c:	02b9a18c 	addi.w	$r12,$r12,-408(0xe68)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:139
    la.local    t1,_ebss
1c0011a0:	1c00fded 	pcaddu12i	$r13,2031(0x7ef)
1c0011a4:	02bbe1ad 	addi.w	$r13,$r13,-264(0xef8)

1c0011a8 <bss_init>:
bss_init():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:141
bss_init:
    beq         t0,t1,bss_init_done
1c0011a8:	5800118d 	beq	$r12,$r13,16(0x10) # 1c0011b8 <bss_init_done>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:142
    st.w        zero,t0,0x0
1c0011ac:	29800180 	st.w	$r0,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:143
    addi.w      t0,t0,0x4
1c0011b0:	0280118c 	addi.w	$r12,$r12,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:144
    b           bss_init
1c0011b4:	53fff7ff 	b	-12(0xffffff4) # 1c0011a8 <bss_init>

1c0011b8 <bss_init_done>:
bss_init_done():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:148

bss_init_done:
    /* Save early CPUCFG-derived D-cache parameters for the user-test return flush path. */
    la.global   t1,CachePathFlag
1c0011b8:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c0011bc:	288611ad 	ld.w	$r13,$r13,388(0x184)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:149
    st.w        s6,t1,0x0
1c0011c0:	298001bd 	st.w	$r29,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:150
    beq         s6,zero,dcache_param_done
1c0011c4:	58002ba0 	beq	$r29,$r0,40(0x28) # 1c0011ec <dcache_param_done>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:152

    la.global   t1,DCacheOffsetBits
1c0011c8:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c0011cc:	288631ad 	ld.w	$r13,$r13,396(0x18c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:153
    st.w        s2,t1,0x0
1c0011d0:	298001b9 	st.w	$r25,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:154
    la.global   t1,DCacheTotalSets
1c0011d4:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c0011d8:	288591ad 	ld.w	$r13,$r13,356(0x164)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:155
    st.w        s3,t1,0x0
1c0011dc:	298001ba 	st.w	$r26,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:156
    la.global   t1,DCacheMaxWay
1c0011e0:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c0011e4:	288531ad 	ld.w	$r13,$r13,332(0x14c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:157
    st.w        s4,t1,0x0
1c0011e8:	298001bb 	st.w	$r27,$r13,0

1c0011ec <dcache_param_done>:
dcache_param_done():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:162

dcache_param_done:

    /* Select UART address according to whether DMW is enabled. */
    beq         s7, zero, serial_addr_direct
1c0011ec:	580033c0 	beq	$r30,$r0,48(0x30) # 1c00121c <serial_addr_direct>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:164

    la.global   t1,SerialDataAddr
1c0011f0:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c0011f4:	288561ad 	ld.w	$r13,$r13,344(0x158)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:165
    la.global   t2,SerialData
1c0011f8:	1c00002e 	pcaddu12i	$r14,1(0x1)
1c0011fc:	2884a1ce 	ld.w	$r14,$r14,296(0x128)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:166
    st.w        t2,t1,0x0
1c001200:	298001ae 	st.w	$r14,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:167
    la.global   t1,SerialStatAddr
1c001204:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001208:	288561ad 	ld.w	$r13,$r13,344(0x158)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:168
    la.global   t2,SerialStat
1c00120c:	1c00002e 	pcaddu12i	$r14,1(0x1)
1c001210:	288471ce 	ld.w	$r14,$r14,284(0x11c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:169
    st.w        t2,t1,0x0
1c001214:	298001ae 	st.w	$r14,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:170
    b           serial_addr_done
1c001218:	50002800 	b	40(0x28) # 1c001240 <serial_addr_done>

1c00121c <serial_addr_direct>:
serial_addr_direct():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:173

serial_addr_direct:
    la.global   t1,SerialDataAddr
1c00121c:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001220:	2884b1ad 	ld.w	$r13,$r13,300(0x12c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:174
    li.w        t2,0x1f000000
1c001224:	143e000e 	lu12i.w	$r14,126976(0x1f000)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:175
    st.w        t2,t1,0x0
1c001228:	298001ae 	st.w	$r14,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:176
    la.global   t1,SerialStatAddr
1c00122c:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001230:	2884c1ad 	ld.w	$r13,$r13,304(0x130)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:177
    li.w        t2,0x1f000005
1c001234:	143e000e 	lu12i.w	$r14,126976(0x1f000)
1c001238:	038015ce 	ori	$r14,$r14,0x5
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:178
    st.w        t2,t1,0x0
1c00123c:	298001ae 	st.w	$r14,$r13,0

1c001240 <serial_addr_done>:
serial_addr_done():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:181

serial_addr_done:
    la.global   sp,KERNEL_STACK_INIT    // 设置内核栈
1c001240:	1c000023 	pcaddu12i	$r3,1(0x1)
1c001244:	28843063 	ld.w	$r3,$r3,268(0x10c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:182
    or          fp,sp,zero
1c001248:	00150076 	move	$r22,$r3
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:183
    la.global   t0,USER_STACK_INIT      // 设置用户栈
1c00124c:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c001250:	2883918c 	ld.w	$r12,$r12,228(0xe4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:184
    la.global   t1,uregs_sp             // 写入用户空间备份
1c001254:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001258:	2883f1ad 	ld.w	$r13,$r13,252(0xfc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:185
    st.w        t0,t1,0x0
1c00125c:	298001ac 	st.w	$r12,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:186
    la.global   t1,uregs_fp
1c001260:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001264:	288381ad 	ld.w	$r13,$r13,224(0xe0)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:187
    st.w        t0,t1,0x0
1c001268:	298001ac 	st.w	$r12,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:190

    /* init serial */
    la.global   t1, SerialDataAddr
1c00126c:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001270:	288371ad 	ld.w	$r13,$r13,220(0xdc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:191
    ld.w        t1, t1, 0
1c001274:	288001ad 	ld.w	$r13,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:192
    li.w        t2, 0x07   
1c001278:	03801c0e 	ori	$r14,$r0,0x7
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:193
    st.b        t2, t1, 2               // FCR = 0x07 (Enable FIFO, clear RX/TX)
1c00127c:	290009ae 	st.b	$r14,$r13,2(0x2)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:194
    li.w        t2, 0x80
1c001280:	0382000e 	ori	$r14,$r0,0x80
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:195
    st.b        t2, t1, 3               // LCR = 0x80 (Enable DLAB)
1c001284:	29000dae 	st.b	$r14,$r13,3(0x3)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:196
    li.w        t2, 0x00 
1c001288:	0015000e 	move	$r14,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:197
    st.b        t2, t1, 1               // DLH = 0x00
1c00128c:	290005ae 	st.b	$r14,$r13,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:198
    li.w        t2, 0x0e
1c001290:	0380380e 	ori	$r14,$r0,0xe
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:199
    st.b        t2, t1, 0               // DLL = 0x0e (25 MHz UART clock, ~115200 baud)
1c001294:	290001ae 	st.b	$r14,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:200
    li.w        t2, 0x03 
1c001298:	03800c0e 	ori	$r14,$r0,0x3
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:201
    st.b        t2, t1, 3               // LCR = 0x03 (8 data bits, no parity, 1 stop bit)
1c00129c:	29000dae 	st.b	$r14,$r13,3(0x3)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:202
    li.w        t2, 0x00 
1c0012a0:	0015000e 	move	$r14,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:203
    st.b        t2, t1, 4               // MCR = 0x00
1c0012a4:	290011ae 	st.b	$r14,$r13,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:205

    b           WELCOME                 // 进入主线程
1c0012a8:	50000400 	b	4(0x4) # 1c0012ac <WELCOME>

1c0012ac <WELCOME>:
WELCOME():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:208

WELCOME:
    la.local    s0,monitor_version      // 装入启动信息
1c0012ac:	1c000037 	pcaddu12i	$r23,1(0x1)
1c0012b0:	028102f7 	addi.w	$r23,$r23,64(0x40)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:209
    ld.b        a0,s0,0x0
1c0012b4:	280002e4 	ld.b	$r4,$r23,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:211
.Loop0:
    addi.w      s0,s0,0x1
1c0012b8:	028006f7 	addi.w	$r23,$r23,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:212
    la.global   t0,WRITESERIAL          // 调用串口写函数
1c0012bc:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c0012c0:	2882718c 	ld.w	$r12,$r12,156(0x9c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:213
    jirl        ra,t0,0x0
1c0012c4:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:214
    ld.b        a0,s0,0x0
1c0012c8:	280002e4 	ld.b	$r4,$r23,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:215
    bne         a0,zero,.Loop0          // 打印循环至0结束符
1c0012cc:	5fffec80 	bne	$r4,$r0,-20(0x3ffec) # 1c0012b8 <WELCOME+0xc>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:216
    la.global   t0,SHELL                // 开始交互
1c0012d0:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c0012d4:	2881d18c 	ld.w	$r12,$r12,116(0x74)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/init.S:217
    jirl        zero,t0,0x0
1c0012d8:	4c000180 	jirl	$r0,$r12,0

1c0012dc <SHELL>:
SHELL():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:24
     * 
     *  用户空间寄存器：$r2-$r31依次保存在0x807F0000连续120字节
     *  用户程序入口临时存储：0x807F0078
     */
SHELL:
    la.global    t0,READSERIAL           // 读操作符
1c0012dc:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c0012e0:	2881218c 	ld.w	$r12,$r12,72(0x48)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:25
    jirl        ra,t0,0x0
1c0012e4:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:27

    sub.w       a0,a0,zero
1c0012e8:	00110084 	sub.w	$r4,$r4,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:28
    ori         t0,zero,SH_OP_R
1c0012ec:	0381480c 	ori	$r12,$r0,0x52
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:29
    beq         a0,t0,.OP_R
1c0012f0:	5800208c 	beq	$r4,$r12,32(0x20) # 1c001310 <.OP_R>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:30
    ori         t0,zero,SH_OP_D
1c0012f4:	0381100c 	ori	$r12,$r0,0x44
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:31
    beq         a0,t0,.OP_D
1c0012f8:	58005c8c 	beq	$r4,$r12,92(0x5c) # 1c001354 <.OP_D>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:32
    ori         t0,zero,SH_OP_A
1c0012fc:	0381040c 	ori	$r12,$r0,0x41
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:33
    beq         a0,t0,.OP_A
1c001300:	5800ac8c 	beq	$r4,$r12,172(0xac) # 1c0013ac <.OP_A>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:34
    ori         t0,zero,SH_OP_G
1c001304:	03811c0c 	ori	$r12,$r0,0x47
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:35
    beq         a0,t0,.OP_G
1c001308:	5801008c 	beq	$r4,$r12,256(0x100) # 1c001408 <.OP_G>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:36
    b           .DONE                   // 错误的操作符，默认忽略
1c00130c:	50024400 	b	580(0x244) # 1c001550 <.DONE>

1c001310 <.OP_R>:
.OP_R():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:40


.OP_R:                                  // 操作 - 打印用户空间寄存器
    addi.w      sp,sp,-8                // 保存s0,s1
1c001310:	02bfe063 	addi.w	$r3,$r3,-8(0xff8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:41
    st.w        s0,sp,0x0
1c001314:	29800077 	st.w	$r23,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:42
    st.w        s1,sp,0x4
1c001318:	29801078 	st.w	$r24,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:44

    la.local    s0,uregs
1c00131c:	1c00fdf7 	pcaddu12i	$r23,2031(0x7ef)
1c001320:	02b392f7 	addi.w	$r23,$r23,-796(0xce4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:45
    ori         s1,zero,0x7C            // 计数器，打印124字节
1c001324:	0381f018 	ori	$r24,$r0,0x7c
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:47
.LC0:
    ld.b        a0,s0,0x0               // 读取字节
1c001328:	280002e4 	ld.b	$r4,$r23,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:48
    addi.w      s1,s1,-1                // 滚动计数器
1c00132c:	02bfff18 	addi.w	$r24,$r24,-1(0xfff)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:49
    la.global    t0,WRITESERIAL          // 写入串口
1c001330:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c001334:	2880a18c 	ld.w	$r12,$r12,40(0x28)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:50
    jirl        ra,t0,0x0
1c001338:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:51
    addi.w      s0,s0,0x1               // 移动打印指针
1c00133c:	028006f7 	addi.w	$r23,$r23,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:52
    bne         s1,zero,.LC0            // 打印循环
1c001340:	5fffeb00 	bne	$r24,$r0,-24(0x3ffe8) # 1c001328 <.OP_R+0x18>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:54

    ld.w        s0,sp,0x0               // 恢复s0,s1
1c001344:	28800077 	ld.w	$r23,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:55
    ld.w        s1,sp,0x4
1c001348:	28801078 	ld.w	$r24,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:56
    addi.w      sp,sp,0x8
1c00134c:	02802063 	addi.w	$r3,$r3,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:57
    b           .DONE
1c001350:	50020000 	b	512(0x200) # 1c001550 <.DONE>

1c001354 <.OP_D>:
.OP_D():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:60

.OP_D:                                  // 操作 - 打印内存num字节
    addi.w      sp,sp,-8                // 保存s0,s1
1c001354:	02bfe063 	addi.w	$r3,$r3,-8(0xff8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:61
    st.w        s0,sp,0x0
1c001358:	29800077 	st.w	$r23,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:62
    st.w        s1,sp,0x4
1c00135c:	29801078 	st.w	$r24,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:64

    la.global    t0,READSERIALWORD
1c001360:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c001364:	28bf518c 	ld.w	$r12,$r12,-44(0xfd4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:65
    jirl        ra,t0,0x0
1c001368:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:66
    or          s0,a0,zero              // 获得addr
1c00136c:	00150097 	move	$r23,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:67
    la.global    t0,READSERIALWORD
1c001370:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c001374:	28bf118c 	ld.w	$r12,$r12,-60(0xfc4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:68
    jirl        ra,t0,0x0
1c001378:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:69
    or          s1,a0,zero              // 获得num
1c00137c:	00150098 	move	$r24,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:72

.LC1:
    ld.b        a0,s0,0x0               // 读取字节
1c001380:	280002e4 	ld.b	$r4,$r23,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:73
    addi.w      s1,s1,-1                // 滚动计数器
1c001384:	02bfff18 	addi.w	$r24,$r24,-1(0xfff)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:74
    la.global    t0,WRITESERIAL          // 写入串口
1c001388:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c00138c:	28bf418c 	ld.w	$r12,$r12,-48(0xfd0)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:75
    jirl        ra,t0,0x0
1c001390:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:76
    addi.w      s0,s0,0x1               // 移动打印指针
1c001394:	028006f7 	addi.w	$r23,$r23,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:77
    bne         s1,zero,.LC1            // 打印循环
1c001398:	5fffeb00 	bne	$r24,$r0,-24(0x3ffe8) # 1c001380 <.OP_D+0x2c>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:79

    ld.w        s0,sp,0x0               // 恢复s0,s1
1c00139c:	28800077 	ld.w	$r23,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:80
    ld.w        s1,sp,0x4
1c0013a0:	28801078 	ld.w	$r24,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:81
    addi.w      sp,sp,0x8
1c0013a4:	02802063 	addi.w	$r3,$r3,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:82
    b           .DONE
1c0013a8:	5001a800 	b	424(0x1a8) # 1c001550 <.DONE>

1c0013ac <.OP_A>:
.OP_A():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:85

.OP_A:                                  // 操作 - 写入内存num字节，num为4的倍数
    addi.w      sp,sp,-8                // 保存s0,s1
1c0013ac:	02bfe063 	addi.w	$r3,$r3,-8(0xff8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:86
    st.w        s0,sp,0x0
1c0013b0:	29800077 	st.w	$r23,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:87
    st.w        s1,sp,0x4
1c0013b4:	29801078 	st.w	$r24,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:89

    la.global    t0,READSERIALWORD
1c0013b8:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c0013bc:	28bdf18c 	ld.w	$r12,$r12,-132(0xf7c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:90
    jirl        ra,t0,0x0
1c0013c0:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:91
    or          s0,a0,zero              // 获得addr
1c0013c4:	00150097 	move	$r23,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:92
    la.global    t0,READSERIALWORD
1c0013c8:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c0013cc:	28bdb18c 	ld.w	$r12,$r12,-148(0xf6c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:93
    jirl        ra,t0,0x0
1c0013d0:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:94
    or          s1,a0,zero              // 获得num
1c0013d4:	00150098 	move	$r24,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:95
    srli.w      s1,s1,2                 // num除4，获得字数
1c0013d8:	00448b18 	srli.w	$r24,$r24,0x2
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:97
.LC2:                                   // 每次写入一字
    la.global    t0,READSERIALWORD       // 从串口读入一字
1c0013dc:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c0013e0:	28bd618c 	ld.w	$r12,$r12,-168(0xf58)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:98
    jirl        ra,t0,0x0
1c0013e4:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:99
    st.w        a0,s0,0x0               // 写内存一字
1c0013e8:	298002e4 	st.w	$r4,$r23,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:100
    addi.w      s1,s1,-1                // 滚动计数器
1c0013ec:	02bfff18 	addi.w	$r24,$r24,-1(0xfff)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:101
    addi.w      s0,s0,0x4               // 移动写指针
1c0013f0:	028012f7 	addi.w	$r23,$r23,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:102
    bne         s1,zero,.LC2            // 写循环
1c0013f4:	5fffeb00 	bne	$r24,$r0,-24(0x3ffe8) # 1c0013dc <.OP_A+0x30>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:104

    ld.w        s0,sp,0x0               // 恢复s0,s1
1c0013f8:	28800077 	ld.w	$r23,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:105
    ld.w        s1,sp,0x4
1c0013fc:	28801078 	ld.w	$r24,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:106
    addi.w      sp,sp,0x8
1c001400:	02802063 	addi.w	$r3,$r3,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:107
    b           .DONE
1c001404:	50014c00 	b	332(0x14c) # 1c001550 <.DONE>

1c001408 <.OP_G>:
.OP_G():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:110

.OP_G:
    la.global    t0,READSERIALWORD       // 获取addr
1c001408:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c00140c:	28bcb18c 	ld.w	$r12,$r12,-212(0xf2c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:111
    jirl        ra,t0,0x0
1c001410:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:112
    or          $r21,a0,zero
1c001414:	00150095 	move	$r21,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:114

    ori         a0,zero,TIMERSET        // 写TIMERSET(0x06)信号
1c001418:	03801804 	ori	$r4,$r0,0x6
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:115
    la.global    t0,WRITESERIAL          // 告诉终端用户程序开始运行
1c00141c:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c001420:	28bcf18c 	ld.w	$r12,$r12,-196(0xf3c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:116
    jirl        ra,t0,0x0
1c001424:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:118

    la.local    ra,uregs                // 定位用户空间寄存器备份地址
1c001428:	1c00fde1 	pcaddu12i	$r1,2031(0x7ef)
1c00142c:	02af6021 	addi.w	$r1,$r1,-1064(0xbd8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:119
    st.w        sp,ra,31<<2             // 保存栈指针
1c001430:	2981f023 	st.w	$r3,$r1,124(0x7c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:120
    ld.w        $r2,ra,1<<2             // 装入$r2-$r31
1c001434:	28801022 	ld.w	$r2,$r1,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:121
    ld.w        $r3,ra,2<<2  
1c001438:	28802023 	ld.w	$r3,$r1,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:122
    ld.w        $r4,ra,3<<2  
1c00143c:	28803024 	ld.w	$r4,$r1,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:123
    ld.w        $r5,ra,4<<2  
1c001440:	28804025 	ld.w	$r5,$r1,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:124
    ld.w        $r6,ra,5<<2  
1c001444:	28805026 	ld.w	$r6,$r1,20(0x14)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:125
    ld.w        $r7,ra,6<<2  
1c001448:	28806027 	ld.w	$r7,$r1,24(0x18)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:126
    ld.w        $r8,ra,7<<2  
1c00144c:	28807028 	ld.w	$r8,$r1,28(0x1c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:127
    ld.w        $r9,ra,8<<2  
1c001450:	28808029 	ld.w	$r9,$r1,32(0x20)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:128
    ld.w        $r10,ra,9<<2 
1c001454:	2880902a 	ld.w	$r10,$r1,36(0x24)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:129
    ld.w        $r11,ra,10<<2 
1c001458:	2880a02b 	ld.w	$r11,$r1,40(0x28)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:130
    ld.w        $r12,ra,11<<2
1c00145c:	2880b02c 	ld.w	$r12,$r1,44(0x2c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:131
    ld.w        $r13,ra,12<<2
1c001460:	2880c02d 	ld.w	$r13,$r1,48(0x30)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:132
    ld.w        $r14,ra,13<<2
1c001464:	2880d02e 	ld.w	$r14,$r1,52(0x34)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:133
    ld.w        $r15,ra,14<<2
1c001468:	2880e02f 	ld.w	$r15,$r1,56(0x38)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:134
    ld.w        $r16,ra,15<<2
1c00146c:	2880f030 	ld.w	$r16,$r1,60(0x3c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:135
    ld.w        $r17,ra,16<<2
1c001470:	28810031 	ld.w	$r17,$r1,64(0x40)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:136
    ld.w        $r18,ra,17<<2
1c001474:	28811032 	ld.w	$r18,$r1,68(0x44)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:137
    ld.w        $r19,ra,18<<2
1c001478:	28812033 	ld.w	$r19,$r1,72(0x48)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:138
    ld.w        $r20,ra,19<<2
1c00147c:	28813034 	ld.w	$r20,$r1,76(0x4c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:140
    # ld.w        $r21,ra,20<<2
    ld.w        $r22,ra,21<<2
1c001480:	28815036 	ld.w	$r22,$r1,84(0x54)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:141
    ld.w        $r23,ra,22<<2
1c001484:	28816037 	ld.w	$r23,$r1,88(0x58)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:142
    ld.w        $r24,ra,23<<2
1c001488:	28817038 	ld.w	$r24,$r1,92(0x5c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:143
    ld.w        $r25,ra,24<<2
1c00148c:	28818039 	ld.w	$r25,$r1,96(0x60)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:144
    ld.w        $r26,ra,25<<2
1c001490:	2881903a 	ld.w	$r26,$r1,100(0x64)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:145
    ld.w        $r27,ra,26<<2
1c001494:	2881a03b 	ld.w	$r27,$r1,104(0x68)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:146
    ld.w        $r28,ra,27<<2
1c001498:	2881b03c 	ld.w	$r28,$r1,108(0x6c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:147
    ld.w        $r29,ra,28<<2
1c00149c:	2881c03d 	ld.w	$r29,$r1,112(0x70)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:148
    ld.w        $r30,ra,29<<2
1c0014a0:	2881d03e 	ld.w	$r30,$r1,116(0x74)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:149
    ld.w        $r31,ra,30<<2
1c0014a4:	2881e03f 	ld.w	$r31,$r1,120(0x78)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:151

    jirl        ra,$r21,0x0
1c0014a8:	4c0002a1 	jirl	$r1,$r21,0

1c0014ac <.USERRET2>:
.USERRET2():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:153
.USERRET2:
    la.local    ra,uregs                // 定位用户空间寄存器备份地址
1c0014ac:	1c00fde1 	pcaddu12i	$r1,2031(0x7ef)
1c0014b0:	02ad5021 	addi.w	$r1,$r1,-1196(0xb54)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:154
    st.w        $r2,ra,1<<2             // 备份$r1-$r31
1c0014b4:	29801022 	st.w	$r2,$r1,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:155
    st.w        $r3,ra,2<<2  
1c0014b8:	29802023 	st.w	$r3,$r1,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:156
    st.w        $r4,ra,3<<2  
1c0014bc:	29803024 	st.w	$r4,$r1,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:157
    st.w        $r5,ra,4<<2  
1c0014c0:	29804025 	st.w	$r5,$r1,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:158
    st.w        $r6,ra,5<<2  
1c0014c4:	29805026 	st.w	$r6,$r1,20(0x14)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:159
    st.w        $r7,ra,6<<2  
1c0014c8:	29806027 	st.w	$r7,$r1,24(0x18)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:160
    st.w        $r8,ra,7<<2  
1c0014cc:	29807028 	st.w	$r8,$r1,28(0x1c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:161
    st.w        $r9,ra,8<<2  
1c0014d0:	29808029 	st.w	$r9,$r1,32(0x20)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:162
    st.w        $r10,ra,9<<2 
1c0014d4:	2980902a 	st.w	$r10,$r1,36(0x24)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:163
    st.w        $r11,ra,10<<2 
1c0014d8:	2980a02b 	st.w	$r11,$r1,40(0x28)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:164
    st.w        $r12,ra,11<<2
1c0014dc:	2980b02c 	st.w	$r12,$r1,44(0x2c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:165
    st.w        $r13,ra,12<<2
1c0014e0:	2980c02d 	st.w	$r13,$r1,48(0x30)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:166
    st.w        $r14,ra,13<<2
1c0014e4:	2980d02e 	st.w	$r14,$r1,52(0x34)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:167
    st.w        $r15,ra,14<<2
1c0014e8:	2980e02f 	st.w	$r15,$r1,56(0x38)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:168
    st.w        $r16,ra,15<<2
1c0014ec:	2980f030 	st.w	$r16,$r1,60(0x3c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:169
    st.w        $r17,ra,16<<2
1c0014f0:	29810031 	st.w	$r17,$r1,64(0x40)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:170
    st.w        $r18,ra,17<<2
1c0014f4:	29811032 	st.w	$r18,$r1,68(0x44)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:171
    st.w        $r19,ra,18<<2
1c0014f8:	29812033 	st.w	$r19,$r1,72(0x48)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:172
    st.w        $r20,ra,19<<2
1c0014fc:	29813034 	st.w	$r20,$r1,76(0x4c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:173
    st.w        $r21,ra,20<<2
1c001500:	29814035 	st.w	$r21,$r1,80(0x50)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:174
    st.w        $r22,ra,21<<2
1c001504:	29815036 	st.w	$r22,$r1,84(0x54)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:175
    st.w        $r23,ra,22<<2
1c001508:	29816037 	st.w	$r23,$r1,88(0x58)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:176
    st.w        $r24,ra,23<<2
1c00150c:	29817038 	st.w	$r24,$r1,92(0x5c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:177
    st.w        $r25,ra,24<<2
1c001510:	29818039 	st.w	$r25,$r1,96(0x60)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:178
    st.w        $r26,ra,25<<2
1c001514:	2981903a 	st.w	$r26,$r1,100(0x64)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:179
    st.w        $r27,ra,26<<2
1c001518:	2981a03b 	st.w	$r27,$r1,104(0x68)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:180
    st.w        $r28,ra,27<<2
1c00151c:	2981b03c 	st.w	$r28,$r1,108(0x6c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:181
    st.w        $r29,ra,28<<2
1c001520:	2981c03d 	st.w	$r29,$r1,112(0x70)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:182
    st.w        $r30,ra,29<<2
1c001524:	2981d03e 	st.w	$r30,$r1,116(0x74)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:183
    st.w        $r31,ra,30<<2
1c001528:	2981e03f 	st.w	$r31,$r1,120(0x78)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:184
    la.local    a0,.USERRET2
1c00152c:	1c000004 	pcaddu12i	$r4,0
1c001530:	02be0084 	addi.w	$r4,$r4,-128(0xf80)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:185
    st.w        a0,ra,0<<2
1c001534:	29800024 	st.w	$r4,$r1,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:186
    ld.w        sp,ra,31<<2
1c001538:	2881f023 	ld.w	$r3,$r1,124(0x7c)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:188
    
    ori         a0,zero,TIMETOKEN       // 发送TIMETOKEN(0x07)信号
1c00153c:	03801c04 	ori	$r4,$r0,0x7
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:189
    la.global    t0,WRITESERIAL          // 告诉终端用户程序结束运行
1c001540:	1c00002c 	pcaddu12i	$r12,1(0x1)
1c001544:	28b8618c 	ld.w	$r12,$r12,-488(0xe18)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:190
    jirl        ra,t0,0x0
1c001548:	4c000181 	jirl	$r1,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:192

    b           .DONE
1c00154c:	50000400 	b	4(0x4) # 1c001550 <.DONE>

1c001550 <.DONE>:
.DONE():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/shell.S:195

.DONE:
    b           SHELL                   // 交互循环
1c001550:	53fd8fff 	b	-628(0xffffd8c) # 1c0012dc <SHELL>

1c001554 <WRITESERIAL>:
WRITESERIAL():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:32
    .global READSERIAL
    .global READSERIALWORD

WRITESERIAL:                            // 写串口：将a0的低八位写入串口
#ifdef MACH_FPGA
    la.global    t1,SerialDataAddr
1c001554:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001558:	28b7d1ad 	ld.w	$r13,$r13,-524(0xdf4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:33
    ld.w         t1,t1,0x0
1c00155c:	288001ad 	ld.w	$r13,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:34
    addi.w       t1,t1,0x5              // LSR = UART base + 5
1c001560:	028015ad 	addi.w	$r13,$r13,5(0x5)

1c001564 <.TESTW>:
.TESTW():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:36
.TESTW:
    ld.b        t0,t1,0x0               // 查看串口状态
1c001564:	280001ac 	ld.b	$r12,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:37
    andi        t0,t0,0x20              // 截取写状态位 (THRE)
1c001568:	0340818c 	andi	$r12,$r12,0x20
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:38
    bne         t0,zero,.WSERIAL        // 状态位非零可写进入写
1c00156c:	5c000980 	bne	$r12,$r0,8(0x8) # 1c001574 <.WSERIAL>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:39
    b           .TESTW                  // 检测验证，忙等待
1c001570:	53fff7ff 	b	-12(0xffffff4) # 1c001564 <.TESTW>

1c001574 <.WSERIAL>:
.WSERIAL():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:41
.WSERIAL:
    la.global    t1,SerialDataAddr
1c001574:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c001578:	28b751ad 	ld.w	$r13,$r13,-556(0xdd4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:42
    ld.w         t1,t1,0x0
1c00157c:	288001ad 	ld.w	$r13,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:43
    st.b        a0,t1,0x0               // 写入
1c001580:	290001a4 	st.b	$r4,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:44
    jirl        zero,ra,0x0
1c001584:	4c000020 	jirl	$r0,$r1,0

1c001588 <READSERIAL>:
READSERIAL():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:51
#TODO
#endif

READSERIAL:                             // 读串口：将读到的数据写入a0低八位
#ifdef MACH_FPGA
    la.global    t1,SerialDataAddr
1c001588:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c00158c:	28b701ad 	ld.w	$r13,$r13,-576(0xdc0)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:52
    ld.w         t1,t1,0x0
1c001590:	288001ad 	ld.w	$r13,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:53
    addi.w       t1,t1,0x5              // LSR = UART base + 5
1c001594:	028015ad 	addi.w	$r13,$r13,5(0x5)

1c001598 <.TESTR>:
.TESTR():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:55
.TESTR:
    ld.b        t0,t1,0x0               // 查看串口状态
1c001598:	280001ac 	ld.b	$r12,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:56
    andi        t0,t0,0x01              // 截取读状态位 (DR)
1c00159c:	0340058c 	andi	$r12,$r12,0x1
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:57
    bne         t0,zero,.RSERIAL        // 状态位非零可读进入读
1c0015a0:	5c000980 	bne	$r12,$r0,8(0x8) # 1c0015a8 <.RSERIAL>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:58
    b           .TESTR                  // 检测验证
1c0015a4:	53fff7ff 	b	-12(0xffffff4) # 1c001598 <.TESTR>

1c0015a8 <.RSERIAL>:
.RSERIAL():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:60
.RSERIAL:
    la.global    t1,SerialDataAddr
1c0015a8:	1c00002d 	pcaddu12i	$r13,1(0x1)
1c0015ac:	28b681ad 	ld.w	$r13,$r13,-608(0xda0)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:61
    ld.w         t1,t1,0x0
1c0015b0:	288001ad 	ld.w	$r13,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:62
    ld.b        a0,t1,0x0               // 读出
1c0015b4:	280001a4 	ld.b	$r4,$r13,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:63
    jirl        zero,ra,0x0
1c0015b8:	4c000020 	jirl	$r0,$r1,0

1c0015bc <READSERIALWORD>:
READSERIALWORD():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:69
#else //ifdef MACH_FPGA             // QEMU模拟器上的读串口操作
#TODO
#endif //ifdef MACH_FPGA

READSERIALWORD:
    addi.w      sp,sp,-0x14             // 保存ra,s0
1c0015bc:	02bfb063 	addi.w	$r3,$r3,-20(0xfec)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:70
    st.w        ra,sp,0x0
1c0015c0:	29800061 	st.w	$r1,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:71
    st.w        s0,sp,0x4
1c0015c4:	29801077 	st.w	$r23,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:72
    st.w        s1,sp,0x8
1c0015c8:	29802078 	st.w	$r24,$r3,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:73
    st.w        s2,sp,0xC
1c0015cc:	29803079 	st.w	$r25,$r3,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:74
    st.w        s3,sp,0x10
1c0015d0:	2980407a 	st.w	$r26,$r3,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:76

    bl          READSERIAL
1c0015d4:	57ffb7ff 	bl	-76(0xfffffb4) # 1c001588 <READSERIAL>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:77
    or          s0,zero,a0
1c0015d8:	00151017 	or	$r23,$r0,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:78
    bl          READSERIAL
1c0015dc:	57ffafff 	bl	-84(0xfffffac) # 1c001588 <READSERIAL>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:79
    or          s1,zero,a0
1c0015e0:	00151018 	or	$r24,$r0,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:80
    bl          READSERIAL
1c0015e4:	57ffa7ff 	bl	-92(0xfffffa4) # 1c001588 <READSERIAL>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:81
    or          s2,zero,a0
1c0015e8:	00151019 	or	$r25,$r0,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:82
    bl          READSERIAL
1c0015ec:	57ff9fff 	bl	-100(0xfffff9c) # 1c001588 <READSERIAL>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:83
    or          s3,zero,a0
1c0015f0:	0015101a 	or	$r26,$r0,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:85

    andi        s0,s0,0x0FF             // 截取低八位
1c0015f4:	0343fef7 	andi	$r23,$r23,0xff
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:86
    andi        s3,s3,0x0FF
1c0015f8:	0343ff5a 	andi	$r26,$r26,0xff
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:87
    andi        s2,s2,0x0FF
1c0015fc:	0343ff39 	andi	$r25,$r25,0xff
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:88
    andi        s1,s1,0x0FF
1c001600:	0343ff18 	andi	$r24,$r24,0xff
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:89
    or          a0,zero,s3
1c001604:	00156804 	or	$r4,$r0,$r26
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:90
    slli.w      a0,a0,8
1c001608:	0040a084 	slli.w	$r4,$r4,0x8
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:91
    or          a0,a0,s2
1c00160c:	00156484 	or	$r4,$r4,$r25
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:92
    slli.w      a0,a0,8
1c001610:	0040a084 	slli.w	$r4,$r4,0x8
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:93
    or          a0,a0,s1
1c001614:	00156084 	or	$r4,$r4,$r24
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:94
    slli.w      a0,a0,8
1c001618:	0040a084 	slli.w	$r4,$r4,0x8
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:95
    or          a0,a0,s0  
1c00161c:	00155c84 	or	$r4,$r4,$r23
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:97

    ld.w        ra,sp,0x0
1c001620:	28800061 	ld.w	$r1,$r3,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:98
    ld.w        s0,sp,0x4
1c001624:	28801077 	ld.w	$r23,$r3,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:99
    ld.w        s1,sp,0x8
1c001628:	28802078 	ld.w	$r24,$r3,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:100
    ld.w        s2,sp,0xC
1c00162c:	28803079 	ld.w	$r25,$r3,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:101
    ld.w        s3,sp,0x10
1c001630:	2880407a 	ld.w	$r26,$r3,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:102
    addi.w      sp,sp,0x14
1c001634:	02805063 	addi.w	$r3,$r3,20(0x14)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/utils.S:103
    jirl        zero,ra,0x0
1c001638:	4c000020 	jirl	$r0,$r1,0
	...

1c002000 <UTEST_SIMPLE>:
UTEST_SIMPLE():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:18

    /*  Simple test program
     *  Write integer 1 to register a0
     */
UTEST_SIMPLE:
    addi.w      a0,a0,0x1
1c002000:	02800484 	addi.w	$r4,$r4,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:19
    jirl        zero,ra,0x0
1c002004:	4c000020 	jirl	$r0,$r1,0

1c002008 <UTEST_STREAM>:
UTEST_STREAM():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:26

    /*  STREAM test program
     *  Continous memory read/write
     */
UTEST_STREAM:
    li.w        a0,0x1c100000
1c002008:	14382004 	lu12i.w	$r4,114944(0x1c100)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:27
    li.w        a1,0x1c400000
1c00200c:	14388005 	lu12i.w	$r5,115712(0x1c400)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:28
    li.w        a2,0x00300000
1c002010:	14006006 	lu12i.w	$r6,768(0x300)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:29
    add.w       a2,a0,a2
1c002014:	00101886 	add.w	$r6,$r4,$r6

1c002018 <stream_next>:
stream_next():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:31
stream_next:
    ld.w        t0,a0,0x0
1c002018:	2880008c 	ld.w	$r12,$r4,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:32
    st.w        t0,a1,0x0
1c00201c:	298000ac 	st.w	$r12,$r5,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:33
    addi.w      a0,a0,0x4
1c002020:	02801084 	addi.w	$r4,$r4,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:34
    addi.w      a1,a1,0x4
1c002024:	028010a5 	addi.w	$r5,$r5,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:35
    bne         a0,a2,stream_next
1c002028:	5ffff086 	bne	$r4,$r6,-16(0x3fff0) # 1c002018 <stream_next>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:37

    b           FLUSH_DCACHE_AND_RETURN
1c00202c:	50025c00 	b	604(0x25c) # 1c002288 <FLUSH_DCACHE_AND_RETURN>

1c002030 <UTEST_MATRIX>:
UTEST_MATRIX():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:56
            }
        }
     */
UTEST_MATRIX:
    // set arguments
    li.w        a0, 0x1c400000
1c002030:	14388004 	lu12i.w	$r4,115712(0x1c400)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:57
    li.w        a1, 0x1c410000
1c002034:	14388205 	lu12i.w	$r5,115728(0x1c410)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:58
    li.w        a2, 0x1c420000
1c002038:	14388406 	lu12i.w	$r6,115744(0x1c420)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:59
    li.w        a3, 96
1c00203c:	03818007 	ori	$r7,$r0,0x60
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:68
    // a3 -> n
    // t8 -> k
    // t1 -> i
    // t3 -> j, unrolled by 4
    // t7 -> r
    or          t8,zero,zero
1c002040:	00150014 	move	$r20,$r0

1c002044 <loop1>:
loop1():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:70
loop1:
    beq         t8,a3,loop1end
1c002044:	5800aa87 	beq	$r20,$r7,168(0xa8) # 1c0020ec <loop1end>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:72

    slli.w      t0,t8,2
1c002048:	00408a8c 	slli.w	$r12,$r20,0x2
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:73
    slli.w      t2,t8,9
1c00204c:	0040a68e 	slli.w	$r14,$r20,0x9
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:74
    add.w       t0,a0,t0
1c002050:	0010308c 	add.w	$r12,$r4,$r12
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:75
    add.w       t2,a1,t2
1c002054:	001038ae 	add.w	$r14,$r5,$r14
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:76
    or          t1,zero,zero
1c002058:	0015000d 	move	$r13,$r0

1c00205c <loop2>:
loop2():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:78
loop2:
    beq         t1,a3,loop2end
1c00205c:	580089a7 	beq	$r13,$r7,136(0x88) # 1c0020e4 <loop2end>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:80

    ld.w        t7,t0,0x0
1c002060:	28800193 	ld.w	$r19,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:81
    slli.w      a4,t1,9
1c002064:	0040a5a8 	slli.w	$r8,$r13,0x9
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:82
    add.w       a4,a2,a4
1c002068:	001020c8 	add.w	$r8,$r6,$r8
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:83
    or          t4,t2,zero
1c00206c:	001501d0 	move	$r16,$r14
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:84
    or          t3,zero,zero
1c002070:	0015000f 	move	$r15,$r0

1c002074 <loop3>:
loop3():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:86
loop3:
    beq         t3,a3,loop3end
1c002074:	580065e7 	beq	$r15,$r7,100(0x64) # 1c0020d8 <loop3end>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:88

    ld.w        t5,t4,0x0
1c002078:	28800211 	ld.w	$r17,$r16,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:89
    ld.w        t6,t4,0x4
1c00207c:	28801212 	ld.w	$r18,$r16,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:90
    ld.w        s0,t4,0x8
1c002080:	28802217 	ld.w	$r23,$r16,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:91
    ld.w        s1,t4,0xc
1c002084:	28803218 	ld.w	$r24,$r16,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:92
    ld.w        s2,a4,0x0
1c002088:	28800119 	ld.w	$r25,$r8,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:93
    ld.w        s3,a4,0x4
1c00208c:	2880111a 	ld.w	$r26,$r8,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:94
    ld.w        s4,a4,0x8
1c002090:	2880211b 	ld.w	$r27,$r8,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:95
    ld.w        s5,a4,0xc
1c002094:	2880311c 	ld.w	$r28,$r8,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:96
    mul.w       t5,t7,t5
1c002098:	001c4671 	mul.w	$r17,$r19,$r17
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:97
    mul.w       t6,t7,t6
1c00209c:	001c4a72 	mul.w	$r18,$r19,$r18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:98
    mul.w       s0,t7,s0
1c0020a0:	001c5e77 	mul.w	$r23,$r19,$r23
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:99
    mul.w       s1,t7,s1
1c0020a4:	001c6278 	mul.w	$r24,$r19,$r24
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:100
    add.w       s2,s2,t5
1c0020a8:	00104739 	add.w	$r25,$r25,$r17
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:101
    add.w       s3,s3,t6
1c0020ac:	00104b5a 	add.w	$r26,$r26,$r18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:102
    add.w       s4,s4,s0
1c0020b0:	00105f7b 	add.w	$r27,$r27,$r23
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:103
    add.w       s5,s5,s1
1c0020b4:	0010639c 	add.w	$r28,$r28,$r24
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:104
    st.w        s2,a4,0x0
1c0020b8:	29800119 	st.w	$r25,$r8,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:105
    st.w        s3,a4,0x4
1c0020bc:	2980111a 	st.w	$r26,$r8,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:106
    st.w        s4,a4,0x8
1c0020c0:	2980211b 	st.w	$r27,$r8,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:107
    st.w        s5,a4,0xc
1c0020c4:	2980311c 	st.w	$r28,$r8,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:108
    addi.w      t3,t3,4
1c0020c8:	028011ef 	addi.w	$r15,$r15,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:109
    addi.w      a4,a4,16
1c0020cc:	02804108 	addi.w	$r8,$r8,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:110
    addi.w      t4,t4,16
1c0020d0:	02804210 	addi.w	$r16,$r16,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:111
    b           loop3
1c0020d4:	53ffa3ff 	b	-96(0xfffffa0) # 1c002074 <loop3>

1c0020d8 <loop3end>:
loop3end():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:114

loop3end:
    addi.w      t1,t1,1
1c0020d8:	028005ad 	addi.w	$r13,$r13,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:115
    addi.w      t0,t0,512
1c0020dc:	0288018c 	addi.w	$r12,$r12,512(0x200)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:116
    b           loop2
1c0020e0:	53ff7fff 	b	-132(0xfffff7c) # 1c00205c <loop2>

1c0020e4 <loop2end>:
loop2end():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:119

loop2end:
    addi.w      t8,t8,1
1c0020e4:	02800694 	addi.w	$r20,$r20,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:120
    b           loop1
1c0020e8:	53ff5fff 	b	-164(0xfffff5c) # 1c002044 <loop1>

1c0020ec <loop1end>:
loop1end():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:123

loop1end:
    b           FLUSH_DCACHE_AND_RETURN
1c0020ec:	50019c00 	b	412(0x19c) # 1c002288 <FLUSH_DCACHE_AND_RETURN>

1c0020f0 <UTEST_CRYPTONIGHT>:
UTEST_CRYPTONIGHT():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:152
UTEST_CRYPTONIGHT:
    // a0 -> pad
    // a1 -> a
    // a2 -> b
    // a3 -> n
    li.w        a0, 0x1c400000
1c0020f0:	14388004 	lu12i.w	$r4,115712(0x1c400)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:153
    li.w        a1, 0xdeadbeef
1c0020f4:	15bd5b65 	lu12i.w	$r5,-136485(0xdeadb)
1c0020f8:	03bbbca5 	ori	$r5,$r5,0xeef
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:154
    li.w        a2, 0xfaceb00c
1c0020fc:	15f59d66 	lu12i.w	$r6,-21269(0xfaceb)
1c002100:	038030c6 	ori	$r6,$r6,0xc
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:155
    li.w        a3, 0x100000
1c002104:	14002007 	lu12i.w	$r7,256(0x100)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:156
    or          t4,zero,a0
1c002108:	00151010 	or	$r16,$r0,$r4
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:157
    or          t3,zero,zero
1c00210c:	0015000f 	move	$r15,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:158
    li.w        t0,0x80000
1c002110:	1400100c 	lu12i.w	$r12,128(0x80)

1c002114 <fill_next>:
fill_next():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:160
fill_next:
    st.w        t3,t4,0
1c002114:	2980020f 	st.w	$r15,$r16,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:161
    addi.w      t3,t3,1
1c002118:	028005ef 	addi.w	$r15,$r15,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:162
    addi.w      t4,t4,4
1c00211c:	02801210 	addi.w	$r16,$r16,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:163
    bne         t3,t0,fill_next
1c002120:	5ffff5ec 	bne	$r15,$r12,-12(0x3fff4) # 1c002114 <fill_next>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:165

    or          t1,zero,zero
1c002124:	0015000d 	move	$r13,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:166
    li.w        t2,0x7ffff
1c002128:	14000fee 	lu12i.w	$r14,127(0x7f)
1c00212c:	03bffdce 	ori	$r14,$r14,0xfff

1c002130 <crn_hext>:
crn_hext():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:168
crn_hext:
    and         t0,a1,t2
1c002130:	0014b8ac 	and	$r12,$r5,$r14
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:169
    slli.w      t0,t0,2
1c002134:	0040898c 	slli.w	$r12,$r12,0x2
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:170
    add.w       t0,a0,t0
1c002138:	0010308c 	add.w	$r12,$r4,$r12
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:171
    ld.w        t3,t0,0
1c00213c:	2880018f 	ld.w	$r15,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:172
    srli.w      t4,a1,1
1c002140:	004484b0 	srli.w	$r16,$r5,0x1
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:173
    slli.w      t3,t3,1
1c002144:	004085ef 	slli.w	$r15,$r15,0x1
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:174
    xor         t3,t3,t4
1c002148:	0015c1ef 	xor	$r15,$r15,$r16
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:175
    and         t4,t3,t2
1c00214c:	0014b9f0 	and	$r16,$r15,$r14
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:176
    xor         a2,t3,a2
1c002150:	001599e6 	xor	$r6,$r15,$r6
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:177
    slli.w      t4,t4,2
1c002154:	00408a10 	slli.w	$r16,$r16,0x2
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:178
    st.w        a2,t0,0
1c002158:	29800186 	st.w	$r6,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:179
    add.w       t4,a0,t4
1c00215c:	00104090 	add.w	$r16,$r4,$r16
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:180
    ld.w        t0,t4,0
1c002160:	2880020c 	ld.w	$r12,$r16,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:181
    or          a2,zero,t3
1c002164:	00153c06 	or	$r6,$r0,$r15
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:182
    mul.w       t3,t3,t0
1c002168:	001c31ef 	mul.w	$r15,$r15,$r12
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:183
    addi.w      t1,t1,1
1c00216c:	028005ad 	addi.w	$r13,$r13,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:184
    add.w       a1,t3,a1
1c002170:	001015e5 	add.w	$r5,$r15,$r5
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:185
    st.w        a1,t4,0
1c002174:	29800205 	st.w	$r5,$r16,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:186
    xor         a1,t0,a1
1c002178:	00159585 	xor	$r5,$r12,$r5
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:187
    bne         a3,t1,crn_hext
1c00217c:	5fffb4ed 	bne	$r7,$r13,-76(0x3ffb4) # 1c002130 <crn_hext>

1c002180 <crn_end>:
crn_end():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:189
crn_end:
    b           FLUSH_DCACHE_AND_RETURN
1c002180:	50010800 	b	264(0x108) # 1c002288 <FLUSH_DCACHE_AND_RETURN>

1c002184 <UTEST_MIXED>:
UTEST_MIXED():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:199
     *  - sequential stores to warm/dirty D-cache
     *  - unrolled independent loads/stores for D-cache throughput
     *  - pseudo-random indexed updates and data-dependent branches
     */
UTEST_MIXED:
    li.w        a0,0x1c500000           // scratch source
1c002184:	1438a004 	lu12i.w	$r4,115968(0x1c500)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:200
    li.w        a1,0x1c510000           // scratch destination
1c002188:	1438a205 	lu12i.w	$r5,115984(0x1c510)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:201
    li.w        a2,0x4000               // 16K words = 64 KiB
1c00218c:	14000086 	lu12i.w	$r6,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:202
    or          t0,zero,zero
1c002190:	0015000c 	move	$r12,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:203
    li.w        t1,0x9e37
1c002194:	1400012d 	lu12i.w	$r13,9(0x9)
1c002198:	03b8ddad 	ori	$r13,$r13,0xe37

1c00219c <mixed_fill>:
mixed_fill():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:205
mixed_fill:
    xor         t2,t0,t1
1c00219c:	0015b58e 	xor	$r14,$r12,$r13
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:206
    slli.w      t3,t0,3
1c0021a0:	00408d8f 	slli.w	$r15,$r12,0x3
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:207
    xor         t2,t2,t3
1c0021a4:	0015bdce 	xor	$r14,$r14,$r15
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:208
    st.w        t2,a0,0x0
1c0021a8:	2980008e 	st.w	$r14,$r4,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:209
    addi.w      a0,a0,4
1c0021ac:	02801084 	addi.w	$r4,$r4,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:210
    addi.w      t0,t0,1
1c0021b0:	0280058c 	addi.w	$r12,$r12,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:211
    bne         t0,a2,mixed_fill
1c0021b4:	5fffe986 	bne	$r12,$r6,-24(0x3ffe8) # 1c00219c <mixed_fill>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:213

    li.w        a0,0x1c500000
1c0021b8:	1438a004 	lu12i.w	$r4,115968(0x1c500)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:214
    li.w        a1,0x1c510000
1c0021bc:	1438a205 	lu12i.w	$r5,115984(0x1c510)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:215
    or          t0,zero,zero
1c0021c0:	0015000c 	move	$r12,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:216
    or          s0,zero,zero
1c0021c4:	00150017 	move	$r23,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:217
    or          s1,zero,zero
1c0021c8:	00150018 	move	$r24,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:218
    or          s2,zero,zero
1c0021cc:	00150019 	move	$r25,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:219
    or          s3,zero,zero
1c0021d0:	0015001a 	move	$r26,$r0

1c0021d4 <mixed_stream>:
mixed_stream():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:221
mixed_stream:
    ld.w        t4,a0,0x0
1c0021d4:	28800090 	ld.w	$r16,$r4,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:222
    ld.w        t5,a0,0x4
1c0021d8:	28801091 	ld.w	$r17,$r4,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:223
    ld.w        t6,a0,0x8
1c0021dc:	28802092 	ld.w	$r18,$r4,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:224
    ld.w        t7,a0,0xc
1c0021e0:	28803093 	ld.w	$r19,$r4,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:225
    add.w       s0,s0,t4
1c0021e4:	001042f7 	add.w	$r23,$r23,$r16
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:226
    xor         s1,s1,t5
1c0021e8:	0015c718 	xor	$r24,$r24,$r17
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:227
    add.w       s2,s2,t6
1c0021ec:	00104b39 	add.w	$r25,$r25,$r18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:228
    xor         s3,s3,t7
1c0021f0:	0015cf5a 	xor	$r26,$r26,$r19
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:229
    st.w        s0,a1,0x0
1c0021f4:	298000b7 	st.w	$r23,$r5,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:230
    st.w        s1,a1,0x4
1c0021f8:	298010b8 	st.w	$r24,$r5,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:231
    st.w        s2,a1,0x8
1c0021fc:	298020b9 	st.w	$r25,$r5,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:232
    st.w        s3,a1,0xc
1c002200:	298030ba 	st.w	$r26,$r5,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:233
    addi.w      a0,a0,16
1c002204:	02804084 	addi.w	$r4,$r4,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:234
    addi.w      a1,a1,16
1c002208:	028040a5 	addi.w	$r5,$r5,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:235
    addi.w      t0,t0,4
1c00220c:	0280118c 	addi.w	$r12,$r12,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:236
    bne         t0,a2,mixed_stream
1c002210:	5fffc586 	bne	$r12,$r6,-60(0x3ffc4) # 1c0021d4 <mixed_stream>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:238

    li.w        a0,0x1c500000
1c002214:	1438a004 	lu12i.w	$r4,115968(0x1c500)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:239
    li.w        t0,0x2000               // indexed update iterations
1c002218:	1400004c 	lu12i.w	$r12,2(0x2)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:240
    li.w        t8,0x3fff               // 64 KiB word-index mask
1c00221c:	14000074 	lu12i.w	$r20,3(0x3)
1c002220:	03bffe94 	ori	$r20,$r20,0xfff
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:241
    xor         t1,s0,s1                // pseudo-random state
1c002224:	0015e2ed 	xor	$r13,$r23,$r24

1c002228 <mixed_stride>:
mixed_stride():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:243
mixed_stride:
    and         t2,t1,t8
1c002228:	0014d1ae 	and	$r14,$r13,$r20
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:244
    slli.w      t2,t2,2
1c00222c:	004089ce 	slli.w	$r14,$r14,0x2
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:245
    add.w       t3,a0,t2
1c002230:	0010388f 	add.w	$r15,$r4,$r14
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:246
    ld.w        t4,t3,0x0
1c002234:	288001f0 	ld.w	$r16,$r15,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:247
    xor         t1,t1,t4
1c002238:	0015c1ad 	xor	$r13,$r13,$r16
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:248
    slli.w      t5,t1,5
1c00223c:	004095b1 	slli.w	$r17,$r13,0x5
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:249
    xor         t1,t1,t5
1c002240:	0015c5ad 	xor	$r13,$r13,$r17
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:250
    srli.w      t5,t1,7
1c002244:	00449db1 	srli.w	$r17,$r13,0x7
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:251
    xor         t1,t1,t5
1c002248:	0015c5ad 	xor	$r13,$r13,$r17
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:252
    andi        t5,t1,0x1
1c00224c:	034005b1 	andi	$r17,$r13,0x1
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:253
    beq         t5,zero,mixed_even
1c002250:	58000e20 	beq	$r17,$r0,12(0xc) # 1c00225c <mixed_even>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:254
    add.w       s0,s0,t4
1c002254:	001042f7 	add.w	$r23,$r23,$r16
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:255
    b           mixed_join
1c002258:	50000800 	b	8(0x8) # 1c002260 <mixed_join>

1c00225c <mixed_even>:
mixed_even():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:257
mixed_even:
    xor         s1,s1,t4
1c00225c:	0015c318 	xor	$r24,$r24,$r16

1c002260 <mixed_join>:
mixed_join():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:259
mixed_join:
    st.w        t1,t3,0x0
1c002260:	298001ed 	st.w	$r13,$r15,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:260
    addi.w      t0,t0,-1
1c002264:	02bffd8c 	addi.w	$r12,$r12,-1(0xfff)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:261
    bne         t0,zero,mixed_stride
1c002268:	5fffc180 	bne	$r12,$r0,-64(0x3ffc0) # 1c002228 <mixed_stride>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:263

    li.w        a0,0x1c520000
1c00226c:	1438a404 	lu12i.w	$r4,116000(0x1c520)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:264
    st.w        s0,a0,0x0
1c002270:	29800097 	st.w	$r23,$r4,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:265
    st.w        s1,a0,0x4
1c002274:	29801098 	st.w	$r24,$r4,4(0x4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:266
    st.w        s2,a0,0x8
1c002278:	29802099 	st.w	$r25,$r4,8(0x8)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:267
    st.w        s3,a0,0xc
1c00227c:	2980309a 	st.w	$r26,$r4,12(0xc)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:268
    st.w        t1,a0,0x10
1c002280:	2980408d 	st.w	$r13,$r4,16(0x10)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:269
    b           FLUSH_DCACHE_AND_RETURN
1c002284:	50000400 	b	4(0x4) # 1c002288 <FLUSH_DCACHE_AND_RETURN>

1c002288 <FLUSH_DCACHE_AND_RETURN>:
FLUSH_DCACHE_AND_RETURN():
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:276

FLUSH_DCACHE_AND_RETURN:
    // CachePathFlag is non-zero only when an L1 D-cache exists. The geometry
    // values are captured by START before DMW/PG setup and written after bss
    // initialization, so this path avoids re-reading CPUCFG after user code.
    la.global   t0, CachePathFlag
1c002288:	1c00000c 	pcaddu12i	$r12,0
1c00228c:	2882d18c 	ld.w	$r12,$r12,180(0xb4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:277
    ld.w        t0, t0, 0x0
1c002290:	2880018c 	ld.w	$r12,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:278
    beq         t0, zero, 3f
1c002294:	58005580 	beq	$r12,$r0,84(0x54) # 1c0022e8 <FLUSH_DCACHE_AND_RETURN+0x60>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:280

    la.global   t0, DCacheTotalSets
1c002298:	1c00000c 	pcaddu12i	$r12,0
1c00229c:	2882818c 	ld.w	$r12,$r12,160(0xa0)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:281
    ld.w        t2, t0, 0x0             // total_sets
1c0022a0:	2880018e 	ld.w	$r14,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:282
    la.global   t0, DCacheMaxWay
1c0022a4:	1c00000c 	pcaddu12i	$r12,0
1c0022a8:	2882218c 	ld.w	$r12,$r12,136(0x88)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:283
    ld.w        t5, t0, 0x0             // max_way
1c0022ac:	28800191 	ld.w	$r17,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:284
    la.global   t0, DCacheOffsetBits
1c0022b0:	1c00000c 	pcaddu12i	$r12,0
1c0022b4:	2882918c 	ld.w	$r12,$r12,164(0xa4)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:285
    ld.w        t3, t0, 0x0             // offset_bits
1c0022b8:	2880018f 	ld.w	$r15,$r12,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:288

    // for (int set = 0; set < total_sets; set++) {
    li.w        t0, 0
1c0022bc:	0015000c 	move	$r12,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:291
1:
    //     int set_addr = set << offset_bits;
    sll.w       t1, t0, t3
1c0022c0:	00173d8d 	sll.w	$r13,$r12,$r15
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:294
    
    //     for (int way = 0; way <= max_way; way++) {
    li.w        t6, 0
1c0022c4:	00150012 	move	$r18,$r0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:297
2:
    //         int target_addr = set_addr | way;
    or          t4, t1, t6
1c0022c8:	001549b0 	or	$r16,$r13,$r18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:299
    //         cacop(0x09, target_addr); // 0x09: D-Cache Index Writeback Invalidate
    cacop       0x09, t4, 0x0
1c0022cc:	06000209 	cacop	0x9,$r16,0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:302
    
    //         way++;
    addi.w      t6, t6, 1
1c0022d0:	02800652 	addi.w	$r18,$r18,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:303
    slt         t7, t5, t6
1c0022d4:	00124a33 	slt	$r19,$r17,$r18
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:304
    beq         t7, zero, 2b
1c0022d8:	5bfff260 	beq	$r19,$r0,-16(0x3fff0) # 1c0022c8 <FLUSH_DCACHE_AND_RETURN+0x40>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:308
    //     } // end for way
    
    //     set++;
    addi.w      t0, t0, 1
1c0022dc:	0280058c 	addi.w	$r12,$r12,1(0x1)
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:309
    bne         t0, t2, 1b
1c0022e0:	5fffe18e 	bne	$r12,$r14,-32(0x3ffe0) # 1c0022c0 <FLUSH_DCACHE_AND_RETURN+0x38>
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:312
    // } // end for set

    andi        zero, zero, 0x0
1c0022e4:	03400000 	andi	$r0,$r0,0x0
/mnt/d/0Loongson/dev/nscscc_2026/remote-loongarch/la32r_soc/sdk/software/examples/supervisor/kernel/kern/test.S:314
3:
    jirl        zero,ra,0x0
1c0022e8:	4c000020 	jirl	$r0,$r1,0
