#include <stdio.h>

int main(void)
{
   int gsi, group, publisher, item, check;

   printf("Enter ISBN: ");
   scanf("%d-%d-%d-%d-%d", &gsi, &group, &publisher, &item, &check);
   printf("GSI prefix: %d\n", gsi);
   printf("Group identifier: %d\n", group);
   printf("Publisher code: %d\n", publisher);
   printf("Item number: %d\n", item);
   printf("Check digit: %d\n", check);
   return 0;
}
