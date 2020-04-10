#include <stdio.h>
#include <stdlib.h>

//long MEMO[401][401];

long vsote(int n, int k, long** MEMO){

    if(n <= 0 || k <= 0){
        if(n == 0 && k >= 0){
            return 1;
        }
        return 0;
    }
    if(MEMO[n][k] != 0){
        return (MEMO[n][k]);
    }
    long z = vsote(n-k, k, MEMO);
    long brez = vsote(n, k-1, MEMO);

    long rez = z + brez;
    MEMO[n][k] = rez;
    return rez;
}

int main(){

    long n,k;
    if (scanf("%ld %ld", &n, &k) == 2) {
        long** MEMO = calloc(401, sizeof(long *));

        for(int i = 0; i < 401; i++){
            MEMO[i] = calloc(401, sizeof(long));
        }

        printf("%ld\n", vsote(n, k, MEMO));

        for(int i = 0; i < 401; i++){
            free(MEMO[i]);
        }
    }else {    
        printf("Failed to read integer.\n");
    }
    return 0;
}