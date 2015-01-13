#include <stdio.h>

int main(void)
{
    int i, j;
    float x;

    /* enter 10.3 5 6 */
    scanf("%d%f%d", &i, &x, &j);
    /* prints 10 0.300000 5 */
    printf("%d %f %d\n", i, x, j);
    return 0;
    
}
