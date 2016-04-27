#include <stdio.h>
#include <stdlib.h>

static int depatures[8][2] = {
    {8, 0},
    {9, 43},
    {11, 19},
    {12, 47},
    {14, 0},
    {15, 45},
    {19, 0},
    {21, 45},
};

static int arrivals[8][2] = {
    {10, 16},
    {11, 52},
    {13, 31},
    {15, 0},
    {16, 8},
    {17, 55},
    {21, 20},
    {23, 58},
};

static int convert_to_minutes(int time[2]) {
    return 60 * time[0] + time[1];
}

int main(void) {
    int hours;
    int minutes;
    int time_in_minutes;
    int dtime_in_minutes;
    int smallest_difference;
    int difference;
    int closest;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);
    time_in_minutes = convert_to_minutes((int[2]){hours, minutes});

    dtime_in_minutes = convert_to_minutes(depatures[0]);
    smallest_difference = abs(time_in_minutes - dtime_in_minutes);
    closest = 0;

    for (int i = 1; i < (int) (sizeof(depatures) / sizeof(depatures[0])); i++) {
        dtime_in_minutes = convert_to_minutes(depatures[i]);
        difference = abs(time_in_minutes - dtime_in_minutes);
        if (difference < smallest_difference) {
            closest = i;
            smallest_difference = difference;
        }
    }

    printf("%.2d:%.2d\n", depatures[closest][0], depatures[closest][1]);
    printf("%.2d:%.2d\n", arrivals[closest][0], arrivals[closest][1]);

    return 0;
}
