#include <stdio.h>

int i, j, k;

int main() {
    i = 5; j = 3;
    printf("---a\n");
    printf("%d %d\n", i / j, i % j);
    printf("1 2\n");

    i = 2; j = 3;
    printf("---b\n");
    printf("%d\n", (i + 10) % j);
    printf("0\n");

    i = 7; j = 8; k = 9;
    printf("---c\n");
    printf("%d\n", (i + 10) % k / j);
    printf("1\n");

    i = 1; j = 2; k = 3;
    printf("---d\n");
    printf("%d\n", (i + 5) % (j + 2) / k);
    printf("0\n");

    return 0;
}
