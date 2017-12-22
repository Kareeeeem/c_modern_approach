/*
 * This extercise is about predicting what a file will look like after the
 * preprocessor is done with it. It is filled with errors but that was the
 * point.
 *
 * #define N = 10
 * #define INC(x) x+1
 * #define SUB (x,y) x-y
 * #define SQR(x) ((x) * (x))
 * #define CUBE(x) (SQR(x) * (x))
 * #define M1(x,y) x##y
 * #define M2(x,y) #x #y
 *
 * int main(void) {
 *     int a[N], i, j, k, m;
 * #ifdef N
 *     i = j;
 * #else
 *     j = i;
 * #endif
 *
 *     i = 10 * INC(j);
 *     i = SUB(j, k);
 *     i = CUBE(j);
 *     i = M1(j, k);
 *     puts(M2(i, j));
 *
 * #undef SQR
 *     i = SQR(j);
 * #define SQR
 *     i = SQR(j);
 *
 *     return 0;
 * }
 */
int main(void) {
    int a[= 10], i, j, k, m;  // a[= 10] is obvously wrong.
    i = j;

    i = 10 * j+1;  // j does not have a value, undefined behavior.
    i = (x,y) x-y(j, k);  // x and y not defined, plus syntax errors
    i = (((j) * (j)) * (j));
    i = jk;  // jk not defined.
    puts("i" "y");  // puts not declared, should have included stdio.h

    i = SQR(j);  // SQR not defined
    i = (j);  // undefined behavior

    return 0;
}
