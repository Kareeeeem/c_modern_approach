#include <stdio.h>
#include <ctype.h>

#define BUFLEN 1024

int main() {
    int c, message[BUFLEN], *p = message, *q = p;

    printf("Enter a message: ");

    while ((c = getchar()) != '\n' && p < message + BUFLEN)
        if (isalpha(c))
            *p++ = c;
    p--; // set p back to the last character inserted.

    while (p > q)
        if (*p-- != *q++)
            break;

    // If the loop broke before the pointers met it is not a palindrom
    puts(p - q ? "not a palindrome" : "palindrome");
}
