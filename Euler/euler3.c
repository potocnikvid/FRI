#include <stdio.h>
#include <stdbool.h>

int main(){
    long long stevilo = 600851475143;
    bool isPrime = false;

    for(long i = 2; i <= stevilo; i++){
        if(stevilo % i == 0){
            isPrime = true;
            for(long j = 2; j <= i/2; j++){
                if(i % j == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime == true){
                printf("%lo\n", i);
            }
        }
    }
    return 0;
}