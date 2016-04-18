#include <stdio.h>
#include <ctype.h>

// Seems cleaner but the chapter is about arrays so I don't think this still
// qualifies as a solution.

static int convert_char(int c) {
    switch (c) {
        case 'a': return '4';
        case 'b': return '8';
        case 'i': return '1';
        case 'o': return '0';
        case 's': return '5';
        case 'e': return '3';
        default : return toupper(c);
    }
}

int main(void) {
    while(1) {
        int c = getchar();
        if (c == '\n' || c == EOF)
            break;
        printf("%c", convert_char(c));
    }
    printf("!!!!!!!!!!\n");
    return 0;
}
