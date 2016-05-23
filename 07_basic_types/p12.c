#include <stdio.h>

int main(void) {
    double operand, result = 0;
    char operator;

    printf("enter an expression: ");

    scanf("%lf", &result);

    while((operator = getchar()) != '\n') {
        scanf("%lf", &operand);
        switch (operator) {
            case '+':
                result += operand;
                break;
            case '*':
                result *= operand;
                break;
            case '-':
                result -= operand;
                break;
            case '/':
                result /= operand;
                break;
            default:
                printf("Used an invalid operator, only + - * / allowed\n");
                return 1;
        }
    }

    printf("result: %.2f\n", result);

    return 0;
}
