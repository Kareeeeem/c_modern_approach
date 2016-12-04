#include <stdio.h>
#include <stdlib.h>

int count_spaces(const char *s);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ex16 [\"message\"].\n");
        exit(EXIT_FAILURE);
    }
    printf("%d spaces in there", count_spaces(argv[1]));
}

int count_spaces(const char *s)
{
    int count = 0;

    do {
        count += (*s == ' ');
    } while (*s++);

    return count;
}
