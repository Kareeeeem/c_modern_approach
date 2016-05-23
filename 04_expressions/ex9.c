#include <stdio.h>

// a combination of some excersizes

int i = 7, j = 8, k;

int main() {
    i *= j + 1;
    // 63 8
    printf("%d %d\n", i, j);

    i = j = k = 1;
    i += j += k;
    // 3 2 1
    printf("%d %d %d\n", i, j, k);

    i = 1; j = 2; k = 3;
    i -= j -= k;
    // 2 -1 3
    printf("%d %d %d\n", i, j, k);

    i = 2; j = 1; k = 0;
    i *= j *= k;
    // 0 0 0
    printf("%d %d %d\n", i, j, k);

    i = 5;
    j = ++i * 3 - 2;
    // 6 16
    printf("%d %d\n", i, j);

    i = 5;
    j = 3 - 2 * i++;
    // 6 -7
    printf("%d %d\n", i, j);

    printf("%d", 5 * 4 % 7 / 2);

    return 0;
}
