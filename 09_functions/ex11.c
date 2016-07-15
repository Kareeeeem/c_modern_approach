#include <stdio.h>

float compute_GPA(char grades[], int n);

int main(void) {
    char grades[5] = {'A', 'B', 'C', 'A', 'D'};
    printf("gpa %f", compute_GPA(grades, 5));
}

float compute_GPA(char grades[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++)
        switch(grades[i]) {
        case 'a':
        case 'A':
            total += 4;
            break;
        case 'b':
        case 'B':
            total += 3;
            break;
        case 'c':
        case 'C':
            total += 2;
            break;
        case 'd':
        case 'D':
            total += 1;
            break;
        }
    return total / (float) n;
}
