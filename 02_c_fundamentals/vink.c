#include <stdio.h>

int main(void)
{
    int space = 32;

    for (int i = 6; i > 0; i--) {

        switch(i) {
        case 3:
            printf("*%c%c%c", (char)space, (char)space, (char)space);
            break;
        case 2:
            printf("%c*%c", (char)space, (char)space);
            break;
        case 1:
            printf("%c%c", (char)space, (char)space);
            break;
        default:
            for (int a = i + 1; a > 0; a--) {
                printf("%c", (char)space);
            }
        }
        printf("*\n");
    }

    return 0;
}
