#include <stdio.h>

int f(int a, int b);

// all statements are legal but there is some implicit conversion happening.
int main(void) {
    int i;
    double x;

    i = f(83, 12);
    printf("(a): %d\n", i);

    x = f(83, 12);
    printf("(b): %f\n", x);

    i = f(3.15, 9.28);
    printf("(c): %d\n", i);

    x = f(3.15, 9.28);
    printf("(d): %f\n", x);

    return 0;
}

int f(int a, int b) {
    return a * b;
}
