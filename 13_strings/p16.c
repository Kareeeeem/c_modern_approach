#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *message);

int main()
{
    char message[BUFSIZ];
    fgets(message, BUFSIZ - 1, stdin);
    reverse(message);
    printf(message);
    return 0;
}

void reverse(char *message)
{
    char *begin = message, *end, temp;
    // set the end to before the newline.
    end = message + (strlen(message) - 2);
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
