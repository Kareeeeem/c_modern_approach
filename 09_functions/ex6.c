#include <stdio.h>
#include <math.h>

int nth_digit(int number, int n);
int nth_digit_rec(int number, int n);
int nth_digit_math(int number, int n);

int main(void) {
    int number, n;
    printf("Enter a number and the nth digit you want: ");
    scanf("%d %d", &number, &n);
    printf("Digit %d is %d\n", n, nth_digit(number, n));
    printf("Digit %d is %d\n", n, nth_digit_rec(number, n));
    printf("Digit %d is %d\n", n, nth_digit_math(number, n));
}

int nth_digit(int number, int n) {
    while (--n)
        number /= 10;
    return number % 10;
}

int nth_digit_rec(int number, int n) {
    if (--n == 0)
        return number % 10;
    return nth_digit_rec(number / 10, n);
}

int nth_digit_math(int number, int n) {
    return (int) (number / pow(10, --n)) % 10;
}
