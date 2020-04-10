#include <stdio.h>
#include <stdbool.h>

int preberiStevilo(){
    int stevilo = 0;
    int a = 0;
    bool jeNegativno = false;
    do{
        stevilo *= 10;
        a = getchar() - '0';
        if(a == -3){
            jeNegativno = true;
            continue;
        }
        stevilo += a;
        // printf("%d %d\n", a, stevilo);
        if(a + '0'== 32){
            stevilo += 16;
            stevilo /= 10;
            break;
        }else if(a + '0' == '\n'){
            stevilo += 38;
            stevilo /= 10;
            break;
        }
    }while(a + '0' != '\n');
    
    if(jeNegativno){
        return(stevilo*(-1));
    }else return stevilo;
}

void izpisiStevilo(int stevilo){
    if(stevilo != 0){
        izpisiStevilo(stevilo/10);
        putchar((stevilo % 10) + '0');    
    }
}
int main(){
    int a = preberiStevilo() ;
    // printf("%d\n", a);
    int b = preberiStevilo() ;
    // printf("%d\n", b);

    int sestevek = a + b;
    //printf("%d\n",a + b);
    if(sestevek < 0){
        putchar(45);
        sestevek *= -1;
    }
    izpisiStevilo(sestevek);
    putchar('\n');
    return 0;
}