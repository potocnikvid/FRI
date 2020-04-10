#include <stdio.h>

int a;
int *pa;

int main ()
{
    a = 5;
    pa = &a;
    printf ("%3d (%3d) %18p\n", a, *pa, pa);
    a = 7;
    printf ("%3d (%3d) %18p\n", a, *pa, pa);
    *pa = 9;
    printf ("%3d (%3d) %18p\n", a, *pa, pa);

    return 0;
}