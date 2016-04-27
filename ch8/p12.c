#include <ctype.h>
#include <stdio.h>

static int scores[26];

int main(void) {
    int c;
    int points = 0;
    char letter = 'A';

    for (int i = 0; i < 26; i++, letter++) {
        switch(letter) {
        case 'D': case 'G':
            scores[i] = 2;
            break;
        case 'B': case 'C': case 'M': case 'P':
            scores[i] = 3;
            break;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            scores[i] = 4;
            break;
        case 'K':
            scores[i] = 5;
            break;
        case 'J': case 'X':
            scores[i] = 8;
            break;
        case 'Q': case 'Z':
            scores[i] = 10;
            break;
        default:
            scores[i] = 1;
            break;
        }
    }

    printf("Enter a word: ");
    while ((c = getchar()) != '\n')
        points += scores[toupper(c) - 'A'];

    printf("points: %d\n", points);

    return 0;
}
