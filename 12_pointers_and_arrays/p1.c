#include <stdio.h>

#define BUFLEN 1024

int main()
{
    int c;
    char message[BUFLEN], *p = message;

    while ((c = getchar()) != '\n' && p < message + BUFLEN)
        *p++ = (char) c;

    while (p >= message)
        printf("%c", *--p);
    puts("");

    return 0;
}
