#include <stdio.h>

long f(char *s, char *t);

int main(void)
{
    printf("a: %ld\n", f("abcd", "babc")); // 4
    printf("b: %ld\n", f("abcd", "abcd"));  // 0
    puts("f returns the index of the first characted in s that doesn't have a "
         "match in t. If that doesn't exist then it returns the index of the "
         "NULL char.");
}

long f(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        if (*p2 == '\0') break;
    }
    return p1 - s;
}
