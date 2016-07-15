#include <stdio.h>

void pb(int n);

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    pb(x);
    printf("\n");
}

void pb(int n) {
    if (n !=0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}
