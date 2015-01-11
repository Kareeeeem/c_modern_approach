/* Converts a Fahrenheit temperature to Celcius */
#include <stdio.h>
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f/9.0f)

int main(void)
{
    float fahrenheit, celcius;

    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);

    celcius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;

    printf("Celcius equivalent: %.1f\n", celcius);

    return 0;
}
