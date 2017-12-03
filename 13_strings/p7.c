#include <stdio.h>

int main(void) {
    char *numbers[] = {
        // Single digits
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        // Special cases
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen",
        // multiples of 10
        "twenty", "thirty", "forty", "fifty",
        "sixty", "seventy", "eighty", "ninety",
    };
    int i, j;

    printf("Enter a two digit number: ");
    scanf("%2d", &i);
    printf("You entered ");

    if (i < 20) {
        printf("%s.\n", numbers[i - 1]);
    } else {
        // split the two digit number into two single digit numbers for easy
        // indexing in the array.
        j = i % 10;
        i = (i - j) / 10;
        printf("%s-%s.\n", numbers[i + 17], numbers[j - 1]);
    }
    return 0;
}
