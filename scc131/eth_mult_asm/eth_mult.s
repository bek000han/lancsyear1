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
    tst r1, #1 @ test last bit if it is 1
    bne if     @ if 1, it is odd, branch
    b bitshifts @ else don't
if:
    add r0, r2  @ add to result b
    b bitshifts
bitshifts:
    lsr r1, 1 @ halve a
    lsl r2, 1 @ double b
    cmp r1, #1 @ check if a is 1
    bge while
    b end
end:
    bx lr