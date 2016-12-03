#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFLEN 1024
#define NO_PUNC_ERROR "A sentence must end with '?', '.' or '?'"

#define is_punctuation(C) (C == '?' || C == '.' || C == '!')

int main(void)
{
    char sentence[BUFLEN] = {'\0'},
         *p = sentence,
         *end,
         *punctuation;

    printf("Enter a sentence: ");

    while (p < sentence + BUFLEN - 1) {
        *p = (char) getchar();
        if (is_punctuation(*p)) {
            break;
        }
        p++;
    }

    if (!is_punctuation(*p)) {
        fprintf(stderr, NO_PUNC_ERROR);
        exit(1);
    } else {
        punctuation = p;
    }

    do {
        end = p;

        while (!isspace(*(p - 1)) && p != sentence)
            p--;

        for (int i = 0; i < end - p; i++)
            putchar(*(p + i));

        putchar(' ');

    } while (p-- > sentence);

    printf("\b%c\n", *punctuation);
    return 0;
}
