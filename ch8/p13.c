#include <stdio.h>

int main(void)
{
    char last[20] = {0};
    int initial;
    int c;

    printf("Enter a first and last name: ");

    while ((c = getchar()) == ' ');

    initial = c;

    while ((c = getchar()) != ' ');

    for (int i = 0; i < 20; c = getchar(), i++) {
        if (c == ' ' || c == EOF || c == '\n')
            break;
        last[i] = (char) c;
    }

    printf("%c. %s\n", initial, last);

    return 0;
}
