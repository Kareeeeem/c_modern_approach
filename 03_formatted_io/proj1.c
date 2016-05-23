/* Write a program that accepts a date from the user in the form mm/dd/yyyy and
 * then displays in in the form yyyymmdd */

#include <stdio.h>

int main(void)
{
    int month, day, year;

    printf("enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("you entered the date %.4d%.2d%.2d\n", year, month, day);

    return 0;
}
