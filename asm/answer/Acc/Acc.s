    .global _start
    .section text
_start:
.text
    .word 0x00200000        //div.w $r0, $r0, $r0 机器码
    .align 4,54525952,4
.L3:
    # 保留原模板返回方式
    or         $r4, $r0, $r0
    jr         $r1