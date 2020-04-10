#include <stdio.h>
#include <stdbool.h>-

int preberiStevilo(){
    int stevilo = 0;
    int a = 0;
    bool jeNegativno = false;
    int znak = 0;
    bool naSredini = false;
    do{
        stevilo *= 10;
        a = getchar() - '0';
        
        if(a == -3){
            if(stevilo > 0){
                znak++;
            }
            jeNegativno = true;
            znak++;
            continue;
        }else if(a == -5){
            if(stevilo > 0){
                znak++;
            }
            znak++;
            continue;
        }else if(a + '0' == 32 || a + '0' == 10){
            break;
        }
        stevilo += a;

    }while(a + '0' != 32);

    char nic = '0';
    char ena = '1';

    if(znak > 1){
        return nic;
    }else return ena;
}

int main(){
    char a;
    do{
       a = preberiStevilo();
       putchar(a);
    }while(a != '\n');
}