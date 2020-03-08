#include <stdio.h>

int main(){
    int sum = 0;
    for (int j = 1; j < 1000; j++){
        if(j % 3 == 0 || j % 5 == 0){
            sum += j;
        }
    }
    printf("%d\n", sum);
    return 0;
}