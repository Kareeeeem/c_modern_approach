#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
    int twenties, tens, fives, ones, amount;

    printf("enter amount: ");
    scanf("%d", &amount);

    pay_amount(amount, &twenties, &tens, &fives, &ones);

    printf("$%d bills: %d\n", 20, twenties);
    printf("$%d bills: %d\n", 10, tens);
    printf("$%d bills: %d\n", 5, fives);
    printf("$%d bills: %d\n", 1, ones);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = dollars / 20;
    dollars -= *twenties * 20;

    *tens = dollars / 10;
    dollars -= *tens * 10;

    *fives = dollars / 5;
    dollars -= *fives * 5;

    *ones = dollars / 1;
    dollars -= *ones * 1;
}
