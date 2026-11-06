#include <stdio.h>

int main(void)
{
    char c;
    scanf(" %c", &c);

    int n = c - 'A' + 1;
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n - 1 - row; column++) {
            putchar(' ');
        }
        for (int column = 0; column <= row; column++) {
            putchar('A' + column);
        }
        for (int column = row - 1; column >= 0; column--) {
            putchar('A' + column);
        }
        putchar('\n');
    }

    return 0;
}
