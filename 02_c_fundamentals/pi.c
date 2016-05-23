#include <stdio.h>
#define PI 3.14159f

int main(void)
{
    float radius;
    float volume;

    printf("radius please: ");
    scanf("%f", &radius);

    volume = (4.0f / 3.0f) * PI * radius * radius * radius;
    printf("%.2f\n", volume);

    return 0;
}
