#include <stdio.h>

int main(void)
{
    float x = .9f;

    printf("|%-8.1e|%10.6e|%-8.3f|%6f|\n", x, x, x, x);
    return 0;

}
