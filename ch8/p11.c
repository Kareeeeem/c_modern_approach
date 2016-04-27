#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LEN 15

static char phonenumber[LEN];

int main(void) {
    int c;

    printf("Enter a phone number: ");

    fgets(phonenumber, (int) sizeof(phonenumber), stdin);
    if (phonenumber[strlen(phonenumber)-1]!= '\n')
        while ((c = getchar()) != '\n' && c != EOF);
    phonenumber[strlen(phonenumber)-1] = '\0';

    printf("In numeric form: ");
    for (int i = 0; i < LEN; i++) {
        switch(toupper(phonenumber[i])) {
            case 'A': case 'B': case 'C':
                printf("2");
                break;
            case 'D': case 'E': case 'F':
                printf("3");
                break;
            case 'G': case 'H': case 'I':
                printf("4");
                break;
            case 'J': case 'K': case 'L':
                printf("5");
                break;
            case 'M': case 'N': case 'O':
                printf("6");
                break;
            case 'P': case 'Q': case 'R': case 'S':
                printf("7");
                break;
            case 'T': case 'U': case 'V':
                printf("8");
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                printf("9");
                break;
            default:
                printf("%c", phonenumber[i]);
                break;
        }
    }

    printf("\n");

    return 0;
}
