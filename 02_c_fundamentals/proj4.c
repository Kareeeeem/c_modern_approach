#include <stdio.h>

int main(void)
{
    float amount;

    printf("Enter an amount: ");
    scanf("%f", &amount);
    printf("With tax added: $%.2f\n", (amount * 1.05));

    return 0;
}
