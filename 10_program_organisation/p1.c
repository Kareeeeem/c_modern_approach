#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void stack_underflow() {
    printf("Stack underflow\n");
    exit(1);
}

void stack_overflow() {
    printf("Stack overflow\n");
    exit(1);
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void) {
    if (is_empty()) {
        stack_underflow();
    } else
        return contents[--top];
}

int main(void) {
    int c, match;

    while ((c = getchar()) != '\n') {
        switch (c) {
        case '(': case '{':
            push(c);
            break;
        case ')': case '}':
            match = pop();
            if ((c == '}' && match != '{') || (c == ')' && match != '(')) {
                printf("syntax error");
                exit(1);
            }
            break;
        }
    }
    if (is_empty())
        printf("good stuff");
    else
        printf("syntax error");
}
