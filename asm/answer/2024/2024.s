    .global _start
    .section text
_start:
.text
    lu12i.w $r12,-523264          # $r12 是起始地址
    lu12i.w $r15,-522496          # $r15 是最终地址
    # 四个独立的局部最大值
    addi.w  $r20, $r0, 0
    addi.w  $r21, $r0, 0
    addi.w  $r22, $r0, 0
    addi.w  $r23, $r0, 0
    .align 4,54525952,4
.L3:
    # 16 17 18 19 为需要对比的
    ld.w  $r16,$r12,0
    ld.w  $r17,$r12,4
    ld.w  $r18,$r12,8
    ld.w  $r19,$r12,12


    bltu  $r16,$r14,.A1
    ori   $r14,$r16,0
    .A1: 
    bltu  $r17,$r14,.A2
    ori   $r14,$r17,0
    .A2:
    bltu  $r18,$r14,.A3
    ori   $r14,$r18,0
    .A3:
    bltu  $r19,$r14,.A4
    ori   $r14,$r19,0
    .A4:
    addi.w $r12,$r12,16 
    bne $r12,$r15,.L3

    st.w $r14,$r15,0
    # 保留原模板返回方式
    or         $r4, $r0, $r0
    jr         $r1