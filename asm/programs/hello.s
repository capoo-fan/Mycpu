    .text
    .globl _start
_start:
    lu12i.w $r12, 0x12345
    ori     $r12, $r12, 0x678
    lu12i.w $r13, -2140143616>>12
    st.w    $r12, $r13, 0
    jr      $r1
