#include <stdio.h>
#include <stdbool.h>

#define MAX_VREDNOST 1000000

bool tab[MAX_VREDNOST];

int main(){

    int stPermutacij;
    stPermutacij = scanf("%d\n", &stPermutacij);
    int stevilo;
    bool flag = true;

    for(int i = 0; i < stPermutacij; i++){
        scanf("%d ", &stevilo);
        if(stevilo >= stPermutacij || stevilo < 0){
            flag = false;
            break;
        }
        tab[stevilo] = true;
    }
    
    for(int j = 0; j < stPermutacij; j++){
        if(tab[j] == false){
        flag = false;
        }
    }

    if(flag){
        printf("JA\n");
    }else printf("NE\n");

}