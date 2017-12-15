#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *message, int shift);

int main(void) {
    char message[BUFSIZ];
    int shift, c;

    printf("Enter a message to be encrypted: ");

    if (fgets(message, BUFSIZ, stdin) == NULL) {
        printf ("\nNo input\n");
        exit(EXIT_FAILURE);
    }

    // throw away the rest.
    while ((c = getchar()) != EOF && c != '\n')
        ;

    printf("Enter shift amount: ");
    scanf("%d", &shift);

    encrypt(message, shift);
    puts(message);
    return 0;
}

void encrypt(char *message, int shift) {
    for (;*message; message++) {
        if (isalpha(*message)) {
            char base = (isupper(*message)) ? 'A' : 'a';
            *message = ((*message - base) +  shift) % 26 + base;
        }
    }
}
