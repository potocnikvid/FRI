#include <stdio.h>
#include <stdlib.h>

void izpis(int* stevila, int globina)
{    
    for(int i = 0; i < globina; i++){
        if( i != 0){
            printf(" + ");
        }
        printf("%d", stevila[i]);

    }
    printf("\n");
}

long vsote(int n, int k, int* stevila, int globina)
{
    if(n <= 0 || k <= 0){
        if(n == 0 && k >= 0){
            izpis(stevila, globina);
            return 1;
        }
        return 0;
    }
    stevila[globina] = k;

    long z = vsote(n-k, k, stevila, globina + 1);
    long brez = vsote(n, k-1, stevila, globina);

    long rez = z + brez;
    return rez;
}


int main()
{
    long n,k;
    if (scanf("%ld %ld", &n, &k) == 2) {

        int* stevila = calloc(n, sizeof(int));
        int globina = 0;
        //printf("%ld\n", vsote(n, k, stevila, globina));

    }else {    
        printf("Failed to read integer.\n");
    }
    return 0;
}