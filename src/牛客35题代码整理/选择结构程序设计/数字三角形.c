#include <stdio.h>

int main(void)
{
    int n;
    int value = 1;

    scanf("%d", &n);
    for (int row = 1; row <= n; row++) {
        for (int column = 1; column <= row; column++) {
            printf("%4d", value++);
        }
        putchar('\n');
    }

    return 0;
}
