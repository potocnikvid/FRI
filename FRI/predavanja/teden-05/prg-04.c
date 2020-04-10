#include <stdio.h>

void nevarno (int n)
{
    printf ("### m=%d\n", n);
    int a[10000];
    // printf ("%d ", n);
    if (n > 0) nevarno (n - 1);
}

int main (int argc, char **args)
{
    printf ("argc=%d\n", argc);
    for (int i = 0; i < argc; i++)
        printf ("[%s]\n", args[i]);

    int m;
    sscanf (args[1], "%d", &m);
    printf ("m=%d\n", m);
    nevarno (m);
    printf ("\n");

    return 0;
}