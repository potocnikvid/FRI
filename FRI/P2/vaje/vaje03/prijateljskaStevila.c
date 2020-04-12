#include <stdio.h>

int main()
{
    int stevilo;
    scanf("%d", &stevilo);
    int vsota = 0;

    // printf("%d\n", stevilo);

    for(int i = 1; i <= stevilo/2; i++)
    {
        if(stevilo % i == 0)
        {
           vsota += i;
        //    printf("%d\n", i);
        }
        
    }
    // printf("%d\n", vsota);
    
    int vsota2 = 0;

    for(int i = 1; i <= vsota/2; i++)
    {
        if(vsota % i == 0)
        {
            vsota2 += i;
            // printf("%d\n", i);
        }
    }
    if(stevilo != vsota2){
        printf("NIMA\n");
    }else printf("%d\n", vsota);

    return 0;
}