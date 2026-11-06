#include <stdio.h>

int main(void)
{
    int testCase;
    scanf("%d", &testCase);

    while (testCase--) {
        int n;
        scanf("%d", &n);

        int middle = n / 2;
        for (int row = 0; row < n; row++) {
            int stars = row <= middle ? 2 * row + 1 : 2 * (n - 1 - row) + 1;
            int spaces = (n - stars) / 2;

            for (int i = 0; i < spaces; i++) putchar(' ');
            for (int i = 0; i < stars; i++) putchar('*');
            putchar('\n');
        }
    }

    return 0;
}
