    .data
    .org 0x12345678

A:  .byte 0x72

    .code 
    .org 0

    ;lb r2, A(r0)    ; A + r0 = A + 0 = A NE DELUJE, ker je A 32 bitov velik byte.
                    ; Najvecja vrednost za odmik lb pa je 16 bitov

    addui r1, r0, 0x1234    ; r1 = 0x0000 1234
    slli r1, r1, 16         ; r1 = 0x1234 0000
    addui r1, r1, 0x5678    ; r1 = 0x1234 5678
    
    lhi r1, 0x12345678          ; r1 = 0x1234 0000
    addui r1, r1, 0x12345678    ; r1 = 0x1234 5678

    lhi r1, A
    addui r1, r1, A 


    lb r2, 0(r1)    ; 0 + r1 = 0 + A = A
                    ; r1 <- A

    andi r3, r2, 0x53
    ; x & 0 = 0     ; x & 1 = x    FILTRIRANJE BITOV
    ; r2 = 00000...000 0111 0010 = 0x 0000 0072
    ;      00000...000 0101 0011 = 0x 0000 0053   MASKA - z njo filtriramo bite - tiste ki so 1 v njej
    ; r3 = 00000...000 0101 0010 = 0x 0000 0052

    ori r3, r2, 0x53
    ; x V 0 = x     ; x V 1 = 1    NASTAVLJANJE BITOV
    ; r2 = 00000...000 0111 0010 = 0x 0000 0072
    ;      00000...000 0101 0011 = 0x 0000 0053   MASKA - z njo nastavimo bite - tiste ki so 1 v njej
    ; r3 = 00000...000 0111 0011 = 0x 0000 0073

    xori r3, r2, 0x53
    ; x + 0 = x     ; x + 1 = -x    FLIPANJE BITOV
    ; r2 = 00000...000 0111 0010 = 0x 0000 0072
    ;      00000...000 0101 0011 = 0x 0000 0053   MASKA - z njo flipamo bite - tiste ki so 1 v njej
    ; r3 = 00000...000 0010 0001 = 0x 0000 0021

    not r3, r2, r2
    ; r2 = 00000...000 0111 0010 = 0x 0000 0072
    ; r3 = 11111...111 1000 1100

    ;sgt
    ;slt
    ;sgtu
    ;sgtui

    ; r3 <--- 1111.11111 = 0x FFFF FFFF
    not r3, r0 , r0

    sgti r4, r3, 0      ; r3 > 0  ---> r4= 0x 0000 0001 = 1
                        ; r3 <= 0 ---> r4= 0x 0000 0000 = 0
    
    ; 11111...111 > 0000...0000
    ;       -1   >   0  FALSE  r4 = 0

    sgtui r5, r3, 0
    ; 11111...111 > 0000...0000
    ;   2^32 - 1  >  0  TRUE   r4 = 1