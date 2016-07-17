#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

static int contents[STACK_SIZE];
static int top = 0;

void stack_underflow(void) __attribute__ ((noreturn));
void stack_overflow(void) __attribute__ ((noreturn));
void push(int i);
int pop(void);

int main(void) {
    char ch;
    int left, right;

begin:

    printf("Enter an RPN expression: ");

    while (1) {
        scanf(" %c", &ch);

        if (isdigit(ch)) push(ch - '0');

        else
            switch (ch) {
            case '+': push(pop() + pop()); break;
            case '*': push(pop() * pop()); break;
            case '-': right = pop(), left = pop();
                      push(left / right);
                      break;
            case '/': right = pop(), left = pop();
                      push(left / right);
                      break;
            case '=': printf("Value of expression: %d\n", pop());
                      goto begin;
            case 'q':
            case 'Q': exit(EXIT_SUCCESS);
            }
    }
}

void stack_underflow(void) {
    fprintf(stderr, "Not enough operands in expression.\n");
    exit(EXIT_FAILURE);
}

void stack_overflow(void) {
    fprintf(stderr, "Expression too complex.\n");
    exit(EXIT_FAILURE);
}

void push(int i) {
    if (top == STACK_SIZE) stack_overflow();
    else contents[top++] = i;
}

int pop(void) {
    if (top == 0) stack_underflow();
    else return contents[--top];
}
