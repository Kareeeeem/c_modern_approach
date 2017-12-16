#include <stdio.h>

char *months[] = {
    "Januari",
    "Februari",
    "March",
    "April",
    "May",
    "June",
    "Juli",
    "August",
    "September",
    "Oktober",
    "November",
    "December",
};

int main(void)
{
    unsigned short month, day, year;
    printf("Enter a date in the form \"mm/dd/yyyy\": ");
    scanf("%2hu/%2hu/%4hu", &month, &day, &year);
    printf("%s %hu, %hu\n", months[month - 1], day, year);
    return 0;
}
