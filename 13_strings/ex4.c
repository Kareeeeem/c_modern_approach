#include <stdio.h>
#include <ctype.h>

#define N 10

int read_line(char str[], int n);
int read_line_a(char str[], int n);
int read_line_b(char str[], int n);
int read_line_c(char str[], int n);
int read_line_d(char str[], int n);
void clear_string(char str[]);

int main(void)
{
    char *prompt = "Enter a message, %s.\n";
    char str[N];

    printf(prompt, "this will skip leading whitespace");
    read_line_a(str, N);
    puts(str);
    clear_string(str);

    printf(prompt, "this will stop reading at the first whitespace");
    read_line_b(str, N);
    puts(str);
    clear_string(str);

    printf(prompt, "this will store the new line");
    read_line_c(str, N);
    puts(str);
    clear_string(str);

    printf(prompt, "this will leave behind characters on the stream");
    read_line_d(str, N);
    puts(str);
    int ch;
    while ((ch = getchar()) != '\n' || ch != EOF)
        putchar(ch);
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = (char) ch;

    str[i] = '\0';

    return i;
}

int read_line_a(char str[], int n)
{
    int ch, i = 0;

    while (isspace((ch = getchar())));
    // ch now holds the first non whitespace char.

    do {
        if (i < n)
            str[i++] = (char) ch;
    } while ((ch = getchar()) != '\n');

    str[i] = '\0';

    return i;
}

int read_line_b(char str[], int n)
{
    int ch, i = 0;

    while (!isspace((ch = getchar())))
        if (i < n && !isspace(ch))
            str[i++] = (char) ch;

    while (getchar() != '\n');

    str[i] = '\0';

    return i;
}

int read_line_c(char str[], int n)
{
    int ch, i = 0;

    do {
        ch = getchar();
        if (i < n)
            str[i++] = (char) ch;
    } while (ch != '\n');

    str[i] = '\0';

    return i;
}

int read_line_d(char str[], int n)
{
    int ch, i = 0;

    while (i < n && (ch = getchar()) != '\n') {
        str[i++] = (char) ch;
    }

    str[i] = '\0';

    return i;
}

void clear_string(char str[])
{
    while (*str)
        *str = '\0';
}
