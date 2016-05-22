#include <stdio.h>
#include <stdbool.h>

#define between(i, n) (i > 0 && i < n)

bool check(int x, int y, int n);

int main(void) {
    int x, y, n;

    printf("enter three integers: ");
    scanf("%d %d %d", &x, &y, &n);

    if (check(x, y, n))
        printf("number one and two are both between 0 and %d\n", n);
    else
        printf("number one and two not both between 0 and %d\n", n);

    return 0;
}

bool check(int x, int y, int n) {
    return (between(x, n) && between(y, n));
}

