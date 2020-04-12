#include <stdio.h>
#include <stdlib.h>

int *ptr1D; // na tabelo 10ih intov
int **ptr2D; // na tabelo 10x20ih intov

int main ()
{
    // ptr1D je tipa int*
    // ptr1D[0] je tipa int
    ptr1D = (int*)malloc (10 * sizeof (int));
    for (int i = 0; i < 10; i++)
        ptr1D[i] = 0;
    // ptr1D --> [[ ptr1D[0], ptr1D[1], ... ptr1D[9] ]]

    // ptr2D je tipa int**
    // ptr2D[0] je tipa int*
    // ptr2D[0][0] je tipa int
    ptr2D = (int**)malloc (10 * sizeof (int*));
    for (int i = 0; i < 10; i++)
        ptr2D[i] = (int*)malloc (20 * sizeof (int));
    // ptr2D --> [[ ptr2D[0], ptr2D[1], ... ptr2D[9] ]]
    //               |        |             |
    //               |        |             +-> [[ ptr2D[9][0], ptr2D[9][1], ... ptr2D[9][19] ]]
    //               |        |
    //               |        +-> [[ ptr2D[1][0], ptr2D[1][1], ... ptr2D[1][19] ]]
    //               |
    //               +-> [[ ptr2D[0][0], ptr2D[0][1], ... ptr2D[0][19] ]]

    ptr2D[1][19] = 4;
    // ptr2D je kazalec na tabelo kazalcev na tabele intov
    // ptr2D[1] je kazalec na tabelo intov
    // ptr2D[1][19] je int

    for (int i = 0; 10; i++)
        free (ptr2D[i]);
    free (ptr2D);

    free (ptr1D);
    return 0;
}