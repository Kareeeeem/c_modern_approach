#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Enter size of magic square (must be odd): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("%d is not odd\n", n);
        return 1;
    }

    int magicsquare[n][n];
    // initialize all elements to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicsquare[i][j] = 0;

    // start in the middle of the top row
    int row = 0;
    int col = (int) n / 2;

    for (int i = 0; i < (n * n); i++) {
        magicsquare[row][col] = i + 1;

        // peek at next position, one up, one to the right.
        int nextrow = (row == 0) ? n - 1 : row - 1;
        int nextcol = (col == (n - 1)) ? 0 : col + 1;

        // if the next position is unassigned then move there.
        // otherwise move one down (or wrap to the top).
        if (magicsquare[nextrow][nextcol] == 0) {
            row = nextrow;
            col = nextcol;
        } else {
            row = (row == n - 1) ? 0 : row + 1;
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%10d", magicsquare[i][j]);
        printf("\n");
    }

    return 0;
}
