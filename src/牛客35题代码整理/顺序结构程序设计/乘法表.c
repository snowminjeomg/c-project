#include <stdio.h>

int main(void)
{
    int row, column;

    for (row = 1; row <= 9; row++) {
        for (column = 1; column <= row; column++) {
            printf("%d*%d=%2d", column, row, column * row);
            if (column < row) {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}
