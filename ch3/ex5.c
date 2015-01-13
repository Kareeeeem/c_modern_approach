#include <stdio.h>

int main(void)
{
    float x, y;
    int i;

    /* enter 12.3 45.6, 789 */
    scanf("%f%d%f", &x, &i, &y);
    /* prints 12.300000 45 0.600000 */
    printf("%f, %d, %f\n", x, i, y);
    return 0;
}
