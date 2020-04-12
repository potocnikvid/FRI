#include <stdio.h>
#include <stdbool.h>

#define ZGORNJA_MEJA 100000000000000000L
long obrat(long stevilo) {
    long obrnjeno = 0;
    while (stevilo > 0) {
        obrnjeno = 10 * obrnjeno + (stevilo % 10);
        stevilo /= 10;
    }
    return obrnjeno;
}

// long obrat(int stevilo, int rezultat){
//     while(true){
//         if(stevilo == 0){
//             return rezultat;
//         } else{
//             int novoStevilo = stevilo /10;
//             int novRezultat = rezultat * 10 + stevilo % 10;
//             stevilo = novoStevilo;
//             rezultat = novRezultat;
//         }
//     }
// }

bool jePalindrom(int stevilo){
    return(stevilo == obrat(stevilo));
}

bool jeLychrelovo(int stevilo, int maxIteracij){
    int i = 0;
    do {
        stevilo = stevilo + obrat(stevilo);
        i++;
    } while (i < maxIteracij && stevilo <= ZGORNJA_MEJA && !jePalindrom(stevilo));
    // while(maxIteracij > 0 && stevilo < ZGORNJA_MEJA && !jePalindrom(stevilo)){
    //     stevilo = stevilo + obrat(stevilo, 0);
    //     maxIteracij--;
    // }
    return !jePalindrom(stevilo);
}

int main(){

    
    int maxIteracij;
    int spMeja;
    int zgMeja;

    scanf("%d %d %d", &maxIteracij, &spMeja, &zgMeja);
    int stLychrelovih = 0;
    for(int i = spMeja; i <= zgMeja; i++){
        if(jeLychrelovo(i, maxIteracij)){
            printf("%d\n", i);
            stLychrelovih++;
        }
    }
    printf("%d\n", stLychrelovih);
    return 0;
}
