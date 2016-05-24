#include <stdio.h>

int nth_digit(int number, int n);

int main(void) {
    int number, n;
    printf("Enter a number and the nth digit you want: ");
    scanf("%d %d", &number, &n);
    printf("Digit %d is %d\n", n, nth_digit(number, n));
}

int nth_digit(int number, int n) {
    while (--n)
        number /= 10;
    return number % 10;
}
