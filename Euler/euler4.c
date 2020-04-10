#include <stdio.h>

int main(){

    int stevilo = 0;
    long long max = 92233720;


    for(int i = 2520; i < max; i++){
        int deljivo = 0;
        for(int j = 1; j <= 20; j++){
            if(i % j == 0){
                deljivo++;
            }
        }
        if(deljivo == 20){
            printf("%d\n", i);
        }
    }
    return 0;
}