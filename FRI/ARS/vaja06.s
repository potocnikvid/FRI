        .data
        .org 0x400
TAB:    .byte 15, 20, -50, 54, -17


        .code
        .org 0x500

START:  beq r1, DALEC   ; -2^15 ... 2^15 - 1

        bne r1, BLIZU
        ;j DALEC(r0)     ; problem -> ne bo delovalo

        lhi r2, DALEC
        addi r2, r2, DALEC
        j 0 (r2)


BLIZU: ;...
        halt





        .org 0x12345678

DALEC: ;...
        halt




        addi r3, r0, 5     ;r3 hrani indeks

ZANKA2: lb r1, TAB(r3)
        addi r1, r1, 3
        sb TAB(r3), r1
        bne r3, ZANKA2
        halt


        add r3, r0, r0      ;r3 hrani indeks

ZANKA:  lb r1, TAB(r3)
        addi r1, r1, 3
        sb TAB(r3), r1

        addi r3, r3, 1
        seqi r2, r3, 5
        beq r2, ZANKA
        ; j ZANKA(r0)       ne zelimo neskoncne zanke

        halt




;BEGIN:  j OZNAKA(Rs)    ; brezpogojno skoci na neko OZNAKO + 
                        ; vrednost v registru
;        j OZNAKA(r0)
;        ...

;        beq Rd, OZNAKA  ; branch if equal - ce je vrednost v Rd 0, potem skoci na OZNAKO
;        bne Rd, OZNAKA  ; branch if not equal - ce vrednost v Rd ni 0 skoci na OZNAKO
;OZNAKA: 


        ;if(x < 5)
        ;   x = x + 1;  TRUE
        ;else
        ;   x = x - 1;  FALSE

START:  lb r1, X(r0)    ; r1 <- x
        slti r2, r1, 5
        beq r2, FALSE

TRUE:   addi r1, r1, 1
        j END(r0)

FALSE:  subi r1, r1, 1

END:    sb X(r0), r1
        halt

        
    