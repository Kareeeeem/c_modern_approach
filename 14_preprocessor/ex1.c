#include <stdio.h>

/* would fail for non numeric values for x and y.
 * if you forget about the extra parens values which are themselves arithmetic
 * such as CUBE(3+2) will fail due to operator precedence.
 */
#define CUBE(x) ((x) * (x))
#define REMAINDER4(x) ((x) % 4)
#define PLARGERT100(x, y) ((x) * (y) < 100 ? 1 : 0)

int main(void) {
    printf("cube of 6 is %d\n", CUBE(6));
    printf("remainder of 6 /  4 if %d\n", CUBE(6));
    printf("6 * 12 is%slarger than or equal to 100\n",
            PLARGERT100(6, 100) ? " NOT " : " ");
    printf("6 * 3 is%slarger than or equal to 100\n",
            PLARGERT100(6, 3) ? " NOT " : " ");
    return 0;
}
