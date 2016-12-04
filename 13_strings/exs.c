#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 20
#define EX(i) printf("Exercise %d.\n", i)
#define LF puts("")

int main(void)
{
    EX(1);
    printf("%c", '\n');    // a
    // printf("%c", "\n"); // b %c expects a char, "" makes char *
    // printf("%s", '\n'); // c %s expects char *, '' makes char
    printf("%s", "\n");    // d
    // printf('\n');       // e printf expects char *, '' makes char
    printf("\n");          // f
    putchar('\n');         // g
    // putchar("\n");      // h putchar expects a char
    // puts('\n');         // i puts expects char *
    // puts("\n");         // j this works but prints two new lines.
    puts("");              // k
    LF;

    EX(2);
    char *p = "abc";
    // putchar(p);         // a p is a pointer to char not a char
    putchar(*p);           // b
    puts(p);               // c
    // puts(*p);           // *p is char not a string

    EX(3);
    int i, j;
    char s[10];

    printf("Enter [number][string][number]: ");
    scanf("%d%s%d", &i, s, &j);
    // user enters: 12abc34 56def78
    // i == 12
    // s == "abc34"
    // j == 56
    printf("i == %d\n"
           "s == \"%s\"\n"
           "j == %d\n",
           i, s, j);
    LF;

    EX(7);
    char str7[N] = "hello man";

    *str7 = 0;
    str7[0] = '\0';
    strcpy(str7, "");
    strcat(str7, "");
    puts("(d) concats to the end of str, the others make str.");
    LF;

    EX(8);

    char str8[N];
    strcpy(str8, "tire-bouchon"); // str points to "tire-bouchon"
    puts(str8);
    strcpy(&str8[4], "d-or-wi"); // str points to "tired-or-wi"
    puts(str8);
    strcat(str8, "red?"); // str points to "tired-or-wired?"
    puts(str8);

    EX(9);
    char str9[N];
    char str9_1[N];
    // str9 will say computers
    strcpy(str9, "computer");
    strcpy(str9_1, "science");
    if (strcmp(str9, str9_1) < 0) {
        strcat(str9, str9_1);
    } else {
        strcat(str9_1, str9);
    }
    str9[strlen(str9) - 6] = '\0';
    puts(str9);

    EX(10);
    puts("q is a local variable which will be released after the function is "
         "done executing. Returning it causes undefined behavior. It is also "
         "not initialized. To fix initialize and declare static.");

    return 0;
}
