#include <stdio.h>
#include <string.h>
#include <ctype.h>

// http://stackoverflow.com/a/7672607
// This solution contains an idea I got from the above stackoverflow link.
// fgets and such are not discussion in the book yet at this point but seems
// like a safer way to handle input data.

#define OK               0
#define NO_INPUT         1
#define TOO_LONG         2
#define MAX_LENGTH_INPUT 1024

static char convert_char(int c) {
    char converted;

    switch (c) {
        case 'a':
            converted = '4'; break;
        case 'b':
            converted = '8'; break;
        case 'i':
            converted = '1'; break;
        case 'o':
            converted = '0'; break;
        case 's':
            converted = '5'; break;
        case 'e':
            converted = '3'; break;
        default:
            converted = (char) toupper(c); break;
    }

    return converted;
}

static int getLine (char *prmpt, char *buff, size_t sz) {
    if (prmpt != NULL) {
        printf ("%s", prmpt);
        // What's this for?
        fflush (stdout);
    }
    if (fgets(buff, (int) sz, stdin) == NULL)
        return NO_INPUT;

    // if input is too long, there won't be a new line.
    if (buff[strlen(buff)-1]!= '\n') {
        int ch, extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra ==1) ? TOO_LONG : OK;
    }
    // remove the new line and make the string null terminated
    buff[strlen(buff)-1] = '\0';
    return OK;
}

int main(void) {
    int return_code;
    char buff[MAX_LENGTH_INPUT];

    return_code = getLine("Enter string> ", buff, sizeof(buff));

    if (return_code == NO_INPUT) {
        printf ("\nNo input\n");
        return 1;
    }

    if (return_code == TOO_LONG) {
        printf ("Input too long");
        return 1;
    }

    for (int i = 0; i < (int) (sizeof(buff) / sizeof(buff[0])); i++) {
        buff[i] = convert_char(buff[i]);
    }

    printf ("%s\n", buff);

    return 0;
}
