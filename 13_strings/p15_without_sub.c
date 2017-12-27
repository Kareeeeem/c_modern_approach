/*
 * A Version without support for sub expressions. It was a cool exersize in
 * recursion but not needed for RPN caculators.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

long double pop(long double *stack, long double **top);
void push(long double *stack, long double **top, long double value);

int eval_rpn(const char *expression, long double *result);
void read_expression(char *expression, size_t n);
bool is_operator(char operator);

int main(void) {
    char expression[BUFSIZ];
    long double result;

    for (;;) {
        printf(">>> ");
        read_expression(expression, BUFSIZ - 1);
        if (eval_rpn(expression, &result) == 0) {
            printf("%Lf\n", result);
        } else {
            puts("Syntax error.");
        }
    }
    return 0;
}

int eval_rpn(const char *expression, long double *result) {
    char *__expression;
    long double stack[STACK_SIZE] = {0},
         *top = stack,
         val,
         left,
         right;

    while (*expression) {
        // attempt to extract a long double
        val = strtold(expression, &__expression);
        if (expression != __expression) {
            // If __expression is advanced beyond expression then a long double
            // was found.
            push(stack, &top, val);
            // advance expression beyond the found value.
            expression = __expression;
        } else if (is_operator(*expression)) {
            right = pop(stack, &top);
            left = pop(stack, &top);
            switch (*expression++) {
                case '+':
                    push(stack, &top, left + right);
                    break;
                case '-':
                    push(stack, &top, left - right);
                    break;
                case '*':
                    push(stack, &top, left * right);
                    break;
                case '/':
                    push(stack, &top, left / right);
                    break;
            }
        } else if (isspace(*expression)) {
            expression++;
        } else {
            return -1;
        }
    }

    *result = *--top;
    return 0;
}

void read_expression(char *expression, size_t n) {
    int c;
    char *p = expression;
    while ((c = getchar()) != '=' && c != EOF) {
        if (p < expression + n) {
            *p++ = c;
            if (c == '\n') {
                printf("    ");
            }
        }
    }
    *p = '\0';

    // flush
    while ((c = getchar()) != EOF && c != '\n')
        ;
}

long double pop(long double *stack, long double **top) {
    if (*top == stack) {
        fprintf(stderr, "Not enough operands in expression.\n");
        exit(EXIT_FAILURE);
    }
    return *(--*top);
}

void push(long double *stack, long double **top, long double value) {
    if (*top == &stack[STACK_SIZE - 1]) {
        fprintf(stderr, "Expression too complex");
        exit(EXIT_FAILURE);
    }
    **top = value;
    (*top)++;
}

bool is_operator(char operator) {
    static const char operators[] = "+-*/";
    for (const char *p = operators; *p; p++) {
        if (*p == operator) {
            return true;
        }
    }
    return false;
}
