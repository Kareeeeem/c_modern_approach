#include <stdio.h>

int main(void)
{
    printf("    86, 1040\n");
    printf("%6d, %4d\n\n", 86, 1040);
    printf("?\n"); /* don't know, it is 2.02530e+01*/
    printf("%14.5e\n\n", 20.253);
    printf("83.1620\n");
    printf("%.4f\n\n", 83.162);
    printf("99.79e-8\n"); /* wrong, it was 1e-6 */
    printf("%-6.2g\n\n", .0000009979);

    return 0;
}
