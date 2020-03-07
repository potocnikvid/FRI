#include <stdio.h>
#include <stdbool.h>

int main(){
    int a;
    while(getchar() - '0' == 0){
        continue;
        // if(a == '1'){
        //     break;
        // }
    }
    int stevec = 0;
    bool pristej1 = false;
    int c = getchar() - '0';
    // printf("%d", c);

    // while(getchar() != '\n'){
    //     if(getchar() == '1'){
    //         pristej1 = true;
    //     }
    //     stevec++;
    // }
    do{
        char a = getchar();
        // printf("%c", a);
        stevec++;
        if(a == '1'){
            pristej1 = true;
        }else if(a == '\n'){
            break;
        }
    }while(a != '\n');

    if(pristej1 == true){
        stevec++;
    }
    printf ("%d", stevec);
}