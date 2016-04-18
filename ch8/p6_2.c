#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Seems cleaner but the chapter is about arrays so I don't think this still
// qualifies as a solution.

static char convert_char(int c) {
    char converted;

    switch (c) {
        case 'A':
            converted = '4';
            break;
        case 'B':
            converted = '8';
            break;
        case 'I':
            converted = '1';
            break;
        case 'O':
            converted = '0';
            break;
        case 'S':
            converted = '5';
            break;
        case 'E':
            converted = '3';
            break;
        default:
            converted = (char) toupper(c);
            break;
    }

    return converted;
}

int main(void) {
    int  c;
    do {
        c = getchar();
        printf("%c", convert_char(c));

    } while (c != '\n' || c != EOF);

    printf("!!!!!!!!!!\n");

    return 0;
}
