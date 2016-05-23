#include <stdio.h>

int x;

int main() {
    scanf("%d", &x);
    printf("%d%d\n", x % 10, x / 10);
    return 0;
}
