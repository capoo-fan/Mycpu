	.file	"2022.c"
	.text
	.align	2
	.align	4
	.globl	sqrt
	.type	sqrt, @function
sqrt:
	lu12i.w	$r6,61440>>12			# 0xf000
	lu12i.w	$r18,-2143289344>>12			# 0xffffffff80400000
	lu12i.w	$r5,1048576>>12			# 0x100000
	lu12i.w	$r4,65536>>12			# 0x10000
	ori	$r6,$r6,4095
	lu12i.w	$r20,-2142240768>>12			# 0xffffffff80500000
	.align	4,54525952,4
.L8:
	ld.w	$r16,$r18,0
	add.w	$r19,$r18,$r5
	or	$r17,$r16,$r0
	bltu	$r16,$r4,.L2
	or	$r17,$r6,$r0
.L2:
	or	$r14,$r16,$r0
	addi.w	$r13,$r0,1			# 0x1
	beq	$r16,$r0,.L11
	.align	4,54525952,4
.L3:
	sub.w	$r12,$r14,$r13
	srli.w	$r12,$r12,1
	add.w	$r12,$r12,$r13
	mul.w	$r15,$r12,$r12
	bltu	$r16,$r15,.L5
	addi.w	$r13,$r12,1
	or	$r17,$r12,$r0
	bgeu	$r14,$r13,.L3
	st.w	$r12,$r19,0
	addi.w	$r18,$r18,4
	bne	$r18,$r20,.L8
.L15:
	jr	$r1
	.align	4,54525952,4
.L5:
	addi.w	$r14,$r12,-1
	bleu	$r13,$r14,.L3
.L11:
	or	$r12,$r17,$r0
	st.w	$r12,$r19,0
	addi.w	$r18,$r18,4
	bne	$r18,$r20,.L8
	b	.L15
	.size	sqrt, .-sqrt
	.ident	"GCC: (LoongArch GNU toolchain LA32 v2.0 (20230903)) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
