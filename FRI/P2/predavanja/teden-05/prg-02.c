#include <stdio.h>
#include <stdlib.h>

int a[10][20]; // med stat.podatki v pomnilniku

int main ()
{
    int c = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 20; j++)
            a[i][j] = c++;

    /*

    a[0][0] = 0  a[0][1] = 1 a[0][2] = 2 ... a[0][19] = 19
    a[1][0] = 20 a[1][1] = 21 a[1][2] = 22 ... a[1][19] = 39
    ...

    vpra"sanje:
      pomnilnik:    0 1 2 3 ... 19 20 21 22 ... 39 40 41 42 ...
         ali
      pomnilnik:    0 20 40 ... 1 21 31 41 ... 2 22 32 42 ...

    */

    // tabela a je med stat.podatki v pomnilniku
    // kazalec b je na skladu
    // kazalec b kaze na tabelo a,
    // zato kazalec b kaze na blok podatkov, ki je med stat.podatki v pomnilniku
    int *b = &(a[0][0]);
    for (int i = 0; i < 200; i++)
        printf ("%d ", b[i]);
    printf ("\n");
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 20; j++)
            printf ("%d ", b[i * 20 + j]);
    printf ("\n");

    int d1, d2, d3;
    scanf ("%d", &d1);
    scanf ("%d", &d2);
    scanf ("%d", &d3);
    // kazalec m je na skladu
    // blok podatkov, na katerega kaze m, je na kopici
    int *m;
    m = (int*)malloc (d1 * d2 * d3 * sizeof (int));

    // za dostop do elementa z indeksom i,j,k:
    // m[((i * d2 * d3) + j * d3) + k]

    free (m);

    return 0;
}


/*

int a[10][20];
int *b;

b = a;

*/