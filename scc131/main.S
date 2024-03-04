@ source/eth_mult.s
        .syntax unified
        .global eth_mult
        .text
        .thumb_func
eth_mult:
    mov r2, r1 @ moving b to r2
    mov r1, r0 @ moving a to r1
    mov r0, #0 @ setting r0 to 0, it is result
    b while
while:
    mov r3, #0x00000001
    and r3, r1
    cmp r3, #1
    bne if
    b bitshifts
if:
    add r0, r2
    b bitshifts
bitshifts:
    lsr r1, 1
    lsl r2, 1
    cmp r1, #1
    bge eth_mult
    b end
end:
    bx lr