	.file	"2020.c"
	.text
	.align	2
	.globl	count
	.type	count, @function
count:
	lu12i.w	$r16,200704>>12			# 0x31000
	or	$r13,$r0,$r0
	addi.w	$r15,$r0,1			# 0x1
	ori	$r16,$r16,274
.L4:
	or	$r12,$r15,$r0
.L3:
	andi	$r14,$r12,1
	srli.w	$r12,$r12,1
	add.w	$r13,$r13,$r14
	bne	$r12,$r0,.L3
	addi.w	$r15,$r15,1
	bne	$r15,$r16,.L4
	lu12i.w	$r12,-2140143616>>12			# 0xffffffff80700000
	st.w	$r13,$r12,0
	jr	$r1
	.size	count, .-count
	.ident	"GCC: (GNU) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
