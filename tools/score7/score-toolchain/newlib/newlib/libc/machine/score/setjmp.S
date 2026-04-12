    .text
    .align  2
    .globl  setjmp
    .type   setjmp, @function

setjmp:
    sw      r0, [r4, 0]
    sw      r1, [r4, 4]
    sw      r2, [r4, 8]
    sw      r3, [r4, 12]
    sw      r12, [r4, 16]
    sw      r13, [r4, 20]
    sw      r14, [r4, 24]
    sw      r15, [r4, 28]
    sw      r16, [r4, 32]
    sw      r17, [r4, 36]
    sw      r18, [r4, 40]
    sw      r19, [r4, 44]
    sw      r20, [r4, 48]
    sw      r21, [r4, 52]
    ldi     r4, 0
    br!     r3

    .size   setjmp, .-setjmp