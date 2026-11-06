#include <stdio.h>

int main(void)
{
    int n;

    while (scanf("%d", &n) == 1) {
        for (int row = 1; row <= n + 1; row++) {
            for (int column = 1; column <= row; column++) putchar('*');
            putchar('\n');
        }

        for (int row = n; row >= 1; row--) {
            for (int column = 1; column <= row; column++) putchar('*');
            putchar('\n');
        }
    }

    return 0;
}
