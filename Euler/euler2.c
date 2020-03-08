#include <stdio.h>


int main(){
    int prClen = 1;
    int clen = 2;
    int noviClen = 0;
    int vsota = 0;
    while(prClen < 4000000){
        //printf("%d ", prClen);
        if(prClen % 2 == 0){
            vsota += prClen;
        }
        noviClen = clen + prClen;
        prClen = clen;
        clen = noviClen;
    }
    printf("%d\n", vsota);
    return 0;
}