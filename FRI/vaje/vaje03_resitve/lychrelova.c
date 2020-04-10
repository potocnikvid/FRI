
#include <stdio.h>
#include <stdbool.h>

#define MEJA 100000000000000000L

// Vrne zrcalno sliko podanega "stevila, npr. 2793 -> 3972.
long obrat(long stevilo) {
    long obrnjeno = 0;
    while (stevilo > 0) {
        obrnjeno = 10 * obrnjeno + (stevilo % 10);
        stevilo /= 10;
    }
    return obrnjeno;
}

// Vrne <true> natanko tedaj, ko se podano "stevilo z obeh strani bere enako.
bool jePalindrom(long stevilo) {
    return (stevilo == obrat(stevilo));
}

// Vrne <true> natanko tedaj, ko je podano "stevilo Lychrelovo (po definiciji
// iz naloge).
// maksStIteracij: maksimalno "stevilo iteracij postopka ("ce do takrat ne
// dobimo palindroma, proglasimo "stevilo za Lychrelovo)
bool jeLychrelovo(long stevilo, int maksStIteracij) {
    int i = 0;
    do {
        stevilo = stevilo + obrat(stevilo);
        i++;
    } while (i < maksStIteracij && stevilo <= MEJA && !jePalindrom(stevilo));

    return !jePalindrom(stevilo);
}

int main() {
    // preberemo vhodne podatke
    int maksStIteracij, spMeja, zgMeja;
    scanf("%d%d%d", &maksStIteracij, &spMeja, &zgMeja);

    // pre"stejemo Lychrelova "stevila na podanem intervalu
    int stLychrelovih = 0;
    for (int stevilo = spMeja;  stevilo <= zgMeja;  stevilo++) {
        if (jeLychrelovo(stevilo, maksStIteracij)) {
            stLychrelovih++;
        }
    }
    printf("%d\n", stLychrelovih);
    return 0;
}
