#include <stdio.h>
#include <ctype.h>

#define EX(i) printf("Exercise %d.\n", i)
#define LF puts("")

int main()
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

    return 0;
}
