#include <stdio.h>

/* define struct for saving some data */
struct money {
    int amount_left;
    int number_of_bills;
};

/* calculate how many bills of a certain kind fit in an amount and return the
 * previously defined struct */
struct money calculate_bills(int amount, int bill)
{
    struct money m;

    m.number_of_bills = amount / bill;
    m.amount_left = amount - bill * m.number_of_bills;

    return m;
}

int main(void)
{
    int amount, bills[4] = {20, 10, 5, 1};

    /* get the size of the bills array we need to get the size of the array in
     * bytes divided by the size of an int in bytes */
    int array_bills = sizeof(bills) / sizeof(int);

    printf("enter amount: ");
    scanf("%d", &amount);

    /* for every element in the bills array calculate money left and number of
     * bills used */
    for (int i = 0; i < array_bills; i++) {
        struct money money_after = calculate_bills(amount, bills[i]);
        printf("$%d bills: %d\n", bills[i], money_after.number_of_bills);
        amount = money_after.amount_left;
    }

    return 0;
}
