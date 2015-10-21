#include <ctype.h>
#include <stdio.h>

int main(void) {
    int points = 0;
    char c;

    printf("Enter a word: ");

    while ((c = getchar()) != '\n') {
        switch(toupper(c)) {
            case 'D': case 'G':
                points += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                points += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                points += 4;
                break;
            case 'K':
                points += 5;
                break;
            case 'J': case 'X':
                points += 8;
                break;
            case 'Q': case 'Z':
                points += 10;
                break;
            default:
                points++;
                break;
        }
    }

    printf("points: %d\n", points);

    return 0;
}
