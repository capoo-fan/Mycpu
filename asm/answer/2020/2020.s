    .global _start
    .section text
_start:
.text
    lu12i.w   $r15, -522496      # result addr 0x80700000u
    lu12i.w	  $r11,200704>>12
    ori       $r11,$r11,274
    addi.w    $r10, $r0, 1        # r10作为i
    addi.w    $r12, $r0,0         # r12作为统计
    .align 4,54525952,4
.L3:
    add.w $r13,$r0,$r10    # j=i ，进行个数1的计算
    .Loop:
        andi $r14,$r13,1
        beq  $r14,$r0,.plus   # r14 ==0 证明为偶数，末尾为0
        addi.w $r12,$r12,1
        .plus:
        srli.w $r13,$r13,1
        bne    $r13,$r0,.Loop
    addi.w $r10,$r10,1
    bne $r10,$r11,.L3    # 最外层循环
    st.w $r12,$r15,0
    # 保留原模板返回方式
    or         $r4, $r0, $r0
    jr         $r1