#include <stdio.h>

int x, i, j, k;


int main() {
    scanf("%d", &x);

    i = x / 10;
    j = i / 10;


    printf("%d%d%d\n", x % 10, (x / 10) % 10, x / 100);
    return 0;
}

