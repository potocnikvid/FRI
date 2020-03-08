#include <stdio.h>
#include <stdbool.h>

int main(){

    long long stevilo = 600851475143;
    int prime;
    bool isPrime;
    for(int i = 2; i <= stevilo; i++){
        if(stevilo % i == 0){
            isPrime = true;
            for(int j = 2; j <= i/2; j++){
                if(i % j == 0){
                    isPrime = false;
                    break;
                }
                //printf(".");
            }
            if(isPrime = true){
                printf("%d ", i);
            }else printf("nista");
        }
    }
    return 0;
}