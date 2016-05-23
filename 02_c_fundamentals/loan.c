#include <stdio.h>

int main(void)
{
    float loan, interest, monthly_playment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_playment);

    for (int i = 0; i < 3; i++) {
        /* loan times montly interest minus monthy payment */
        loan = loan * (interest * 0.01 / 12 + 1) - monthly_playment;
        printf("Balance after payment #%d: $%.2f\n", (i + 1), loan);
    }
    return 0;
}
