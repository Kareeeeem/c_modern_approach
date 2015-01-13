#include <stdio.h>

int main(void)
{
    int x, y, z;

    scanf("%d", &x);
    printf("%d\n", x);
    /* same */
    scanf(" %d", &x);
    printf("%d\n", x);

    scanf("%d-%d-%d", &x, &y, &z);
    printf("%d-%d-%d\n", x, y, z);
    /* same */
    scanf("%d -%d -%d", &x, &y, &z);
    printf("%d-%d-%d\n", x, y, z);

    float j, k;

    scanf("%f", &j);
    printf("%f\n", j);
    /* 2nd one waits for a non whitespace character to end the scanf */
    scanf("%f ", &j);
    printf("%f \n", j);

    scanf("%f,%f", &j, &k);
    printf("%f,%f \n", j, k);
    /* same */
    scanf("%f, %f", &j, &k);
    printf("%f, %f \n", j, k);

    return 0;
}
