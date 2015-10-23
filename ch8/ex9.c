#include <stdio.h>

#define DAYS 30
#define HOURS 24

float temperature_readings[DAYS][HOURS] = {
    {34, 32, 19, 17, 22, 17, 31, 29, 15, 26, 25, 33, 33, 24, 35, 30, 19, 27, 22, 23, 17, 33, 30, 28},
    {18, 33, 29, 35, 15, 27, 26, 16, 30, 29, 21, 28, 20, 32, 34, 18, 21, 19, 24, 32, 34, 15, 16, 22},
    {24, 19, 21, 21, 28, 33, 15, 21, 18, 34, 19, 30, 16, 29, 30, 16, 30, 34, 31, 24, 19, 22, 15, 17},
    {15, 31, 20, 27, 16, 24, 18, 15, 29, 28, 15, 34, 21, 27, 17, 31, 32, 27, 22, 30, 28, 30, 34, 30},
    {24, 32, 21, 34, 18, 22, 31, 22, 16, 23, 15, 33, 25, 35, 18, 30, 31, 18, 22, 25, 32, 34, 21, 26},
    {29, 15, 25, 15, 19, 20, 29, 23, 29, 32, 26, 17, 26, 17, 20, 25, 16, 23, 25, 19, 20, 30, 30, 28},
    {22, 19, 32, 33, 18, 28, 25, 17, 20, 31, 26, 33, 21, 29, 18, 29, 25, 18, 33, 34, 32, 35, 28, 32},
    {23, 34, 19, 27, 26, 26, 20, 21, 33, 17, 16, 21, 23, 24, 17, 24, 19, 32, 19, 35, 21, 29, 28, 24},
    {29, 30, 17, 24, 22, 15, 29, 23, 16, 34, 19, 19, 19, 25, 33, 15, 31, 22, 34, 33, 23, 23, 20, 18},
    {15, 32, 33, 22, 16, 21, 24, 28, 33, 29, 21, 28, 30, 26, 26, 34, 28, 32, 15, 32, 16, 34, 32, 19},
    {26, 21, 18, 15, 35, 25, 28, 20, 29, 15, 26, 33, 25, 33, 20, 20, 18, 22, 16, 30, 22, 16, 28, 26},
    {22, 22, 32, 22, 33, 32, 25, 33, 24, 19, 19, 34, 21, 28, 31, 26, 32, 23, 32, 34, 32, 31, 22, 17},
    {26, 15, 26, 32, 26, 32, 27, 17, 23, 15, 26, 35, 17, 25, 21, 30, 15, 17, 33, 22, 24, 24, 29, 34},
    {23, 26, 20, 28, 23, 16, 17, 15, 20, 17, 26, 15, 27, 31, 33, 29, 25, 27, 21, 28, 24, 28, 32, 20},
    {25, 29, 20, 30, 30, 24, 33, 32, 25, 21, 34, 23, 22, 15, 27, 17, 19, 26, 27, 35, 23, 27, 19, 30},
    {16, 18, 31, 35, 25, 29, 35, 26, 26, 23, 20, 20, 28, 35, 23, 20, 20, 18, 28, 17, 21, 17, 23, 22},
    {33, 30, 30, 33, 30, 31, 32, 21, 28, 25, 21, 28, 33, 24, 34, 15, 26, 17, 25, 20, 23, 22, 34, 17},
    {18, 15, 15, 28, 22, 33, 16, 28, 33, 31, 24, 16, 19, 32, 32, 31, 20, 27, 15, 27, 16, 19, 23, 27},
    {22, 28, 26, 18, 23, 20, 22, 28, 18, 27, 22, 35, 16, 17, 34, 21, 16, 18, 28, 35, 27, 19, 35, 26},
    {18, 22, 15, 33, 30, 26, 16, 26, 34, 20, 20, 17, 17, 24, 31, 17, 25, 24, 35, 26, 31, 20, 34, 28},
    {23, 21, 25, 21, 30, 22, 15, 15, 31, 33, 17, 31, 27, 25, 27, 16, 18, 32, 28, 20, 15, 29, 31, 28},
    {31, 28, 23, 23, 33, 24, 17, 35, 35, 15, 31, 27, 19, 26, 34, 19, 24, 32, 34, 29, 35, 23, 24, 25},
    {33, 24, 20, 27, 31, 33, 29, 15, 23, 21, 18, 21, 17, 24, 33, 35, 16, 24, 16, 18, 32, 35, 17, 30},
    {18, 24, 25, 25, 25, 32, 29, 26, 28, 28, 28, 35, 25, 30, 27, 35, 23, 28, 21, 32, 22, 18, 25, 33},
    {29, 24, 31, 23, 16, 35, 19, 29, 16, 27, 24, 20, 29, 32, 30, 23, 19, 30, 19, 22, 15, 32, 24, 31},
    {33, 23, 29, 26, 28, 22, 20, 15, 29, 19, 15, 21, 19, 32, 32, 23, 26, 34, 27, 26, 22, 16, 31, 24},
    {26, 20, 27, 19, 22, 19, 28, 17, 22, 30, 27, 18, 28, 22, 18, 21, 18, 25, 16, 19, 31, 30, 30, 19},
    {21, 15, 17, 29, 18, 19, 26, 29, 18, 32, 35, 32, 26, 33, 20, 22, 17, 34, 32, 24, 26, 25, 31, 20},
    {33, 25, 15, 33, 28, 33, 32, 18, 17, 17, 23, 24, 22, 18, 16, 23, 32, 25, 15, 34, 20, 30, 27, 34},
    {21, 15, 18, 23, 29, 23, 28, 30, 34, 20, 35, 26, 23, 33, 28, 15, 33, 35, 33, 29, 21, 21, 34, 23}
};

int main(void) {
    int sum = 0;
    double average;

    for (int i = 0; i < DAYS; i++) {
        for (int j = 0; j < HOURS; j++)
            sum += temperature_readings[i][j];
    }

    average = (double) sum / (DAYS * HOURS);

    printf("%.2f\n", average);

    return 0;
}
