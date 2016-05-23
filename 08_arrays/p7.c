#include <stdio.h>

#define DIMENSION 5

int main(void) {
    int integers[DIMENSION][DIMENSION];
    int sum_rows[DIMENSION] = {0};
    int sum_columns[DIMENSION] = {0};

    for (int i = 0; i < DIMENSION; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < DIMENSION; j++) {
            scanf("%d", &integers[i][j]);
        }
    }

    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            sum_rows[i] += integers[i][j];
            sum_columns[i] += integers[j][i];
        }
    }

    printf("\nsum rows: ");
    for (int i = 0; i < DIMENSION; i++) {
        printf("%d ", sum_rows[i]);
    }
    printf("\n");

    printf("sum colums: ");
    for (int i = 0; i < DIMENSION; i++) {
        printf("%d ", sum_columns[i]);
    }
    printf("\n");

    return 0;
}
