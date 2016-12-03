#include <stdio.h>
#include <ctype.h>

#define N 10

void capitalize(char str[]);

int main(void)
{
    char str[N];

    fgets(str, N, stdin);
    capitalize(str);
    puts(str);

    return 0;
}

void capitalize(char str[])
{
    while (*str) {
        *str = (char) toupper(*str);
        str++;
    }
}
