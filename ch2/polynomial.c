#include <stdio.h>

int main(void)
{
    float x;
    float calulated_value;

    printf("enter a x: ");
    scanf("%f", &x);

    /* calulated_value = 3 * (x*x*x*x*x) + 2 * (x*x*x*x) - 5 * (x*x*x) - x * x */
    /*                   + 7 * x - 6; */

    calulated_value = ((((3 * x + 2) * x - 5 ) * x - 1) * x + 7) * x - 6;

    printf("result of 3 * %.2f^5 + 2 * %.2f^4 - 5 * %.2f^3 - %.2f^2 + 7 * %.2f"
           " - 6 = %.2f\n",
           x, x, x, x, x, calulated_value);

    return 0;
}
