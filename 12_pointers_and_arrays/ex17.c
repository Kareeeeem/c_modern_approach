#include <stdio.h>

#define LEN 10

int sum_two_dimensional_array(const int a[][LEN], int n);

int main() {
    int a[2][LEN] = {
        {3, 1, 3, 4, 6, 1, 7, 0, 7, 10}, // 42
        {5, 1, 0, 4, 7, 1, 5, 5, 7, 13}, // 48
    };                                   // 90

    printf("%d\n", sum_two_dimensional_array(a, 2));

    return 0;
}

int sum_two_dimensional_array(const int a[][LEN], int n) {
    n *= LEN;
    const int *p = a[0];

    int sum = 0;
    while (n--)
        sum += *p++;

    return sum;
}
