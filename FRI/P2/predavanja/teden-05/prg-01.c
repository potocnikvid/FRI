#include <stdio.h>
#include <string.h>

int length (char *str)
{
    int len = 0;
    while ((*str) != '\0') {
        len++; str++;
    }
    return len;
}

void print_all_pfxs (char *str)
{
    for (int len = 0; str[len] != '\0'; len++) {
        char c = str[len + 1];
        str[len + 1] = '\0';
        printf ("%s\n", &(str[0]));
        str[len + 1] = c;
    }
}

void print_all_sfxs (char *str)
{
    for (int len = 0; str[len] != '\0'; len++) {
        printf ("%s\n", &(str[len]));
    }
}

void f (char *s)
{
    printf ("[%s]\n", s);
    s[1] = '#';
    printf ("[%s]\n", s);
}

int main ()
{
    char str[10 + 1] = "0123456789";

    print_all_pfxs (str);
    print_all_sfxs (str);

    printf ("%d %lu\n", length (str), strlen (str));

    return 0;
}