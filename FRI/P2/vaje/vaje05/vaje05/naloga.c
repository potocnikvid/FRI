#include <stdio.h>
#include <stdlib.h>

int vsota(int* zac, int* kon)
{
    int vsota = 0;
        
    for(int* p = zac; p <= kon; p++){
        vsota += *p;
    }
    return vsota;
}
// int indeksElementa(int* t, int* kazalec)
// {   
//     int i = 0;
//     while(t == kazalec){
//         i++;
//         t++;
//     }
//     return i ;
// }
void indeksInKazalec(int* t, int* indeks, int** kazalec)
{   
    if(*indeks == -1){
        *indeks = *kazalec - t; 
    } else{
        *kazalec = *indeks + t;
    }
}

void frekvenceCrk(char* niz, int** frekvence)
{  
    int* crke = calloc(26, sizeof(int));

    char* p = niz;
    while(*p != '\0'){
        if(*p >= 'a' && *p <= 'z'){
            int ind = *p - 'a';
            crke[ind]++;
        }
        else if(*p >= 'A' && *p <= 'Z'){
            int ind = *p - 'A';
            crke[ind]++;
        }
        p++;
    }

    *frekvence = crke;
}



int main(){
    // int *a; // kazalec je na skladu
    // a = (int*) malloc(1000 * sizeof (int)); 
    // int* zac = &a[0];
    // int* kon = &a[5];
    // int sum;
    // sum = vsota(zac, kon);
    // printf("%d\n", sum);
    int a[] = {1,2,3,4,5,6,7};

    int vs = vsota(a+1, a+5);
    printf("%d\n", vs);
    return 0;
}