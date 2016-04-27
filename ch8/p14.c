#include <stdio.h>

#define MAXLENGTH 1024

static char sentence[MAXLENGTH];
static char term;

int main(void)
{
    int c;
    int sentence_i; // a global index for keeping track of sentence positions.

    printf("Enter a sentence: ");

    for (sentence_i = 0; sentence_i < MAXLENGTH; sentence_i++) {
        c = getchar();
        if (c == '?' || c == '.' || c == '!') {
            term = (char) c;
            break;
        } else
            sentence[sentence_i] = (char) c;
    }

    // the inital end is the end of the sentence.
    int end = sentence_i;

    for (; sentence_i >= 0; sentence_i--) {

        // we're doing -1 to look ahead so we can print from the non
        // space or new line.
        if (sentence[sentence_i-1] == ' ' ||
                sentence[sentence_i-1] == '\n' ||
                sentence_i == 0) {

            for (int j = sentence_i; j < end; j++)
                printf("%c", sentence[j]);

            // Only print a space in the sentence, not at the end.
            if (sentence_i != 0)
                printf(" ");

            // decrement sentence_i to space or new line so the for loop
            // decrements again and skips over it.
            end = --sentence_i;
        }
    }

    printf("%c\n", term);
    return 0;
}
