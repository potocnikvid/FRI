#include <stdio.h>
#include <stdlib.h>

// int stevec = 0;
// int stNacinov(int ciljnaVsota, int k)
// {   
//     if(ciljnaVsota > k && ciljnaVsota > 0){
//         ciljnaVsota = ciljnaVsota - k;
//         if(ciljnaVsota == 0){
//             stevec++;
//             stNacinov(ciljnaVsota, ciljnaVsota - 1);
//         }
//     } 
//     else{
//         stNacinov(ciljnaVsota, k - 1);
//     }
//     return stevec;
// }


// int main()
// {
//     int n;
//     int k;
//     if (scanf("%d %d", &n, &k) == 2) {
//         printf("%d\n", stNacinov(n, k));
//     } else {
//         printf("Failed to read integer.\n");
//     }
//     return 0;
// }

long vsote(int n, int k){

    if(n <= 0 || k <= 0){
        if(n == 0 && k >= 0){
            return 1;
        }
        return 0;
    }
    long z = vsote(n-k, k);
    long brez = vsote(n, k-1);

    long rez = z + brez;
    return rez;
}

int main(){

    long n,k;
    if (scanf("%ld %ld", &n, &k) == 2) {
            printf("%ld\n", vsote(n, k));
    }else {    
        printf("Failed to read integer.\n");
    }
    return 0;
}