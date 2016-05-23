#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MSGLEN 80


char encrypt(char ch, int shift);

int main(void) {
    char message[MSGLEN];
    int shift;
    int ch;

    printf("Enter a message to be encrypted: ");

    if (fgets(message, MSGLEN, stdin) == NULL) {
        printf ("\nNo input\n");
        return 1;
    }

    if (message[strlen(message)-1] != '\n')
        while ((ch = getchar()) != '\n' && ch != EOF);

    message[strlen(message)-1] = '\0';

    printf("Enter shift amount: ");
    scanf("%d", &shift);
    while ((ch = getchar()) != '\n' && ch != EOF);

    for (int i = 0; i < MSGLEN; i++)
        message[i] = encrypt(message[i], shift);

    printf("%s\n", message);
    return 0;
}

char encrypt(char ch, int shift) {
    if (isalpha(ch)) {
        char base = (isupper(ch)) ? 'A' : 'a';
        return ((ch - base) +  shift) % 26 + base;
    } else
        return ch;
}
