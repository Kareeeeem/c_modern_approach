#include <stdio.h>
#include <string.h>

int day_of_year(int month, int day, int year);

int main(void) {
    int month, day, year, days;
    char suffix[3];

    printf("Give the day in the form month/day/year: ");
    scanf("%d/%d/%d", &month, &day, &year);
    days = day_of_year(month, day, year);

    switch(days) {
    case 1:
        strcpy(suffix, "st\0");
        break;
    case 2:
        strcpy(suffix, "nd\0");
        break;
    case 3:
        strcpy(suffix, "rd\0");
        break;
    default:
        strcpy(suffix, "th\0");
        break;
    }

    printf("It is now the %d%s day of the year %d\n", days, suffix, year);

}

int day_of_year(int month, int day, int year) {
    int days = day;
    int days_in_month[] = {
        31, // jan
        28, // feb
        31, // mar
        30, // apr
        31, // may
        30, // jun
        31, // jul
        31, // aug
        30, // sep
        31, // oct
        30, // nov
        31  // dec
    };

    // check if leap year
    if ((year % 100 == 0 && year % 400 == 0) || year % 4 == 0)
        days_in_month[1]++;

    for (int i = 0; i < month - 1; i++)
        days += days_in_month[i];

    return days;
}
