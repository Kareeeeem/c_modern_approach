#include <stdio.h>
#include <stdlib.h>

int my_strcmp(const char *s, const char *t);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Provide just two strings to compare.\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", my_strcmp(argv[1], argv[2]));
    return 0;
}

int my_strcmp(const char *s, const char *t)
{
    for (;*s == *t; s++, t++) {
        if (!*s) {
            return 0;
        }
    }
    return *s - *t;
}
