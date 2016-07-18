#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void split_date(int day_of_year, int year, int *month, int *day);
bool check_leap(int year);
int get_year(void);

int get_year(void) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    return timeinfo->tm_year + 1900;
}

int main(void) {
    int day_of_year, year, month, day;
    printf("Enter a day of the year: ");

    scanf(" %d", &day_of_year);
    while (getchar() != '\n') ;

    year = get_year();
    split_date(day_of_year, year, &month, &day);

    printf("year: %d, month: %d, day %d\n", year, month, day);
}

bool check_leap(int year) {
    int century_leap_year = (year % 100 == 0 && year % 400 == 0);
    int regular_leap_year = (year % 100 != 0 && year % 4 == 0);
    return century_leap_year || regular_leap_year;
}

void split_date(int day_of_year, int year, int *month, int *day) {
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int max_days = 365;

    if (check_leap(year)) {
        days_in_month[1]++;
        max_days++;
    }

    if (day_of_year > max_days) {
        fprintf(stderr, "Error: Day too high\n");
        exit(EXIT_FAILURE);
    }

    for (int m = 0; m < 12; m++) {
        if (day_of_year - days_in_month[m] <= 0) {
            *month = m + 1;
            *day = day_of_year;
            break;
        } else {
            day_of_year -= days_in_month[m];
        }
    }
}
