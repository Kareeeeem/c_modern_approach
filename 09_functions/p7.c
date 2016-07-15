#include <stdio.h>
#include <stdbool.h>

int mypow(int x, int n);

int main(void) {
    printf("%d\n", mypow(2, 4));
}

int mypow(int x, int n) {
    int rv;

    if (n == 0) rv = 1;
    else if (n % 2) rv = x * mypow(x, n - 1);
    else {
        rv = mypow(x, n / 2);
        rv *= rv;
    }
     return rv;
}
