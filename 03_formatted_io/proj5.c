#include <stdio.h>

int row_sums[4] = {0};
int column_sums[4] = {0};
int diag_sums[2] = {0};
int x;


int main()
{
    printf("Enter 1 to 16:\n");
    for(int i = 0; i < 16; i++) {
        scanf("%d", &x);

        if (i < 4) {
            row_sums[0] += x;
        } else if (i < 8) {
            row_sums[1] += x;
        } else if (i < 12) {
            row_sums[2] += x;
        } else {
            row_sums[3] += x;
        }

        if (!(i % 5)) {
            diag_sums[0] += x;
        } else if (!(i % 3)) {
            diag_sums[1] += x;
        }

        if ((i + 4) % 4 == 0) {
            column_sums[0] += x;
        } else if ((i + 4) % 4 == 1) {
            column_sums[1] += x;
        } else if ((i + 4) % 4 == 2) {
            column_sums[2] += x;
        } else {
            column_sums[3] += x;
        }
    }

    printf("row_sums %d %d %d %d\n", row_sums[0], row_sums[1], row_sums[2], row_sums[3]);
    printf("column_sums %d %d %d %d\n", column_sums[0], column_sums[1], column_sums[2], column_sums[3]);
    printf("diag_sums %d %d \n", diag_sums[0], diag_sums[1]);

    return 0;
}

