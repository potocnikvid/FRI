        .data
        .org 0x400

STEV1:  .word16 2323
STEV2:  .word16 4343
STEV3:  .byte -127
STEV4:  .byte 6
        .align 4
STEV5:  .word 23456
STEV6:  .word 43210

SUM16:    .space 4
MUL:    .space 4
DIV:    .space 4
SUM:    .space 4
DIF:    .space 4    

        .code 
        .org 0x0

        lhu r1, STEV1(r0)
        lhu r2, STEV2(r0)
        addu r1, r1, r2
        sh SUM16(r0), r1

        lb r3, STEV3(r0)
        lb r4, STEV4(r0)
        sll r5, r3, r4
        sw MUL(r0), r5

        srai r6, r3, 5
        sb DIV(r0), r6

        lw r5, STEV5(r0)
        lw r6, STEV6(r0)
        add r7, r5, r6
        sw SUM(r0), r7
        
        sub r7, r6, r5
        sw DIF(r0), r7

        halt

