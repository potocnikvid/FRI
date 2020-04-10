    .data
    .org 0x400

A:  .word16 64
B:  .word16 8

    .code
    .org 0x0

    lh r1, A(r0)
    lh r2, B(r0)

    add r3, r2, r1
    slli r2, r2, 1
    add r3, r3, r2
    slli r2, r2, 1
    add r3, r3, r2
    srai r3, r3, 3

    sh A(r0), r3

    halt