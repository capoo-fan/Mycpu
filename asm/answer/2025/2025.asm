	.file	"2025.c"
	.text
	.align	2
	.align	4
	.globl	count_first
	.type	count_first, @function
count_first:
	lu12i.w	$r12,-2143289344>>12			# 0xffffffff80400000
	ld.w	$r13,$r12,0
	or	$r4,$r0,$r0
	or	$r5,$r0,$r0
	or	$r6,$r0,$r0
	or	$r20,$r0,$r0
	lu12i.w	$r7,-2140143616>>12			# 0xffffffff80700000
	.align	4,54525952,4
.L2:
	ld.w	$r17,$r12,0
	ld.w	$r16,$r12,4
	ld.w	$r15,$r12,8
	ld.w	$r14,$r12,12
	ld.w	$r9,$r12,16
	ld.w	$r8,$r12,20
	ld.w	$r19,$r12,24
	ld.w	$r18,$r12,28
	xor	$r17,$r17,$r13
	xor	$r16,$r16,$r13
	xor	$r15,$r15,$r13
	xor	$r14,$r14,$r13
	xor	$r9,$r9,$r13
	xor	$r8,$r8,$r13
	xor	$r19,$r19,$r13
	xor	$r18,$r18,$r13
	sltui	$r17,$r17,1
	sltui	$r9,$r9,1
	sltui	$r16,$r16,1
	sltui	$r8,$r8,1
	sltui	$r15,$r15,1
	sltui	$r19,$r19,1
	sltui	$r14,$r14,1
	sltui	$r18,$r18,1
	add.w	$r17,$r17,$r9
	add.w	$r16,$r16,$r8
	add.w	$r15,$r15,$r19
	add.w	$r14,$r14,$r18
	addi.w	$r12,$r12,32
	add.w	$r20,$r20,$r17
	add.w	$r6,$r6,$r16
	add.w	$r5,$r5,$r15
	add.w	$r4,$r4,$r14
	bne	$r12,$r7,.L2
	add.w	$r20,$r20,$r6
	add.w	$r5,$r20,$r5
	add.w	$r4,$r5,$r4
	st.w	$r4,$r12,0
	jr	$r1
	.size	count_first, .-count_first
	.ident	"GCC: (LoongArch GNU toolchain LA32 v2.0 (20230903)) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
