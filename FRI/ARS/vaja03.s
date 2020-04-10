; Vaja03 primer load/store
    .data
    .org 0x400
A:  .byte 96
B:  .byte 0x05
    .align 4
C:  .space 4
D:  .word16 -16

;   A   B           C                   D
;0x 400 401 402 403 404 405 406 407 408 409 40A

;0x 60   05          60  60  60      FF  00

    .code
    .org 0x0
    lb r1, 0x400(r0)    ;r1=0x 00 00 00 60
    sb 0x406(r0), r1    ;
    sb C(r0), r1        ;
    sb C+1(r0), r1      ;
    lb r2, 0x401(r0)    ;r2=0x 00 00 00 05
    sb C(r2), r0        ;
    lh r3, D(r0)        ;r3=0x FF FF FF 00
    sw A(r0), r3        ;
    lbu r1, B(r0)       ;r1=0x 00 00 00 FF
    sh C(r0), r1        ;
    lw r3, C(r0)        ;r3=0x 00 FF 00 ??
    halt

    ; 16= 0000 0000 0001 0000
    ;-16= 1111 1111 1110 1111
    ;  +=                   1
    ; 16= 1111 1111 1111 0000= 0xFFF0
    ; 0x60= 0000 0000 0000 0000 0000 0000 0110 0000 HIP ukaz LB/LH/LW zapolni najvecje vrednosti do 32bitov z prvim bitom,
    ;                                                        LBU/LHU/LWU zapolni do 32 bitov z niclami.
