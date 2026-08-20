    .global _start
    .section .text
_start:
    .word 0x00200000
    or    $r4, $r0, $r0
    jr    $r1