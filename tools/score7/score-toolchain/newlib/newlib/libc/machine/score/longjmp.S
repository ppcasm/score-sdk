    .text
    .align  2
    .globl  longjmp
    .type   longjmp, @function

longjmp:
    lw!     r0, [r4]
    lw      r1, [r4, 4]
    lw      r2, [r4, 8]
    lw      r3, [r4, 12]
    lw      r12, [r4, 16]
    lw      r13, [r4, 20]
    lw      r14, [r4, 24]
    lw      r15, [r4, 28]
    lw      r16, [r4, 32]
    lw      r17, [r4, 36]
    lw      r18, [r4, 40]
    lw      r19, [r4, 44]
    lw      r20, [r4, 48]
    lw      r21, [r4, 52]

    cmpz.c  r5
    bne     cplin
    ldi     r5, 1

cplin:
    mv!     r4, r5
    br!     r3

    .size   longjmp, .-longjmp