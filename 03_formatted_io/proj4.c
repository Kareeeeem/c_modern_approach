#include <stdio.h>

int main(void)
{
   int intl, area_code, number;

   printf("Enter phone number [(xxx) xxx-xxxx]: ");
   scanf("(%d) %d-%d", &intl, &area_code, &number);
   printf("You entered : %d.%d.%d\n", intl, area_code, number);
   return 0;
}
