#include <stdio.h>

int num_digits(int n);
int num_digits_rec(int n);

int main(void) {
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    printf("%d has %d digits\n", i, num_digits(i * 1));
    printf("%d has %d digits\n", i, num_digits_rec(i * 1));
    return 0;
}

int num_digits(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

int num_digits_rec(int n) {
    if (n == 0)
        return 0;
    return 1 + num_digits_rec(n / 10);
}
