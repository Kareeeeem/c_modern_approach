#include <stdbool.h>
#include <stdio.h>

void count_digits(long number) {
    int digit, digit_seen[10] = {0};

    while (number > 0) {
        digit = number % 10;
        digit_seen[digit]++;
        number /= 10;
    }

    printf("Digit: \t\t");
    for (int i = 0; i < 10; i++)
        printf("%d ", i);

    printf("\nOccurances: \t");
    for (int i = 0; i < 10; i++)
        printf("%d ", digit_seen[i]);

    printf("\n\n");
}

long get_number() {
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    return n;
}

int main(void) {
    long n;
    while ((n = get_number())) count_digits(n);
    return 0;
}

