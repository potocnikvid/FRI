
#include <stdio.h>
#include <math.h>

// Vrne vsoto pravih deliteljev podanega "stevila.

int vsotaPravihDeliteljev(int stevilo) {
    // "stevilo 1 nima pravih deliteljev
    if (stevilo <= 1) {
        return 0;
    }

    // Delitelji so simetri"cni okrog korena.  "Ce je "stevilo <a> delitelj
    // "stevila <stevilo>, potem je njegov delitelj tudi "stevilo 
    // b = stevilo / a.  Ko odkrijemo, da je <a> delitelj podanega "stevila, k
    // vsoti pri"stejemo tako <a> kot <b>, moramo pa paziti, da istega
    // delitelja ne pri"stejemo dvakrat (to bi se nam lahko zgodilo pri
    // majhnih "stevilih in popolnih kvadratih).

    int meja = (int) ceil(sqrt(stevilo));
    int vsota = 1;
    for (int a = 2;  a <= meja;  a++) {
        if (stevilo % a == 0) {
            int b = stevilo / a;
            if (b > a) {
                vsota += a + b;
            } else if (b == a) {
                vsota += a;
            }
        }
    }
    return vsota;
}

int main() {
    int n;
    scanf("%d", &n);

    // edini kandidat za prijatelja "stevila <n> je vsota pravih deliteljev
    // tega "stevila
    int kandidat = vsotaPravihDeliteljev(n);

    // preverimo, ali je <kandidat> res prijatelj "stevila <n>
    if (kandidat != n && vsotaPravihDeliteljev(kandidat) == n) {
        printf("%d\n", kandidat);
    } else {
        printf("NIMA\n");
    }
    return 0;
}
