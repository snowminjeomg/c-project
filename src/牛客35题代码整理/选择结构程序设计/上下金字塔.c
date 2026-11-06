#include <stdio.h>

void print_pyramid(int n)
{
    for (int row = 1; row <= n; row++) {
        for (int spaces = 1; spaces <= n - row; spaces++) {
            printf(" ");
        }
        for (int stars = 1; stars <= 2 * row - 1; stars++) {
            printf("*");
        }
        printf("\n");
    }

    for (int row = n - 1; row >= 1; row--) {
        for (int spaces = 1; spaces <= n - row; spaces++) {
            printf(" ");
        }
        for (int stars = 1; stars <= 2 * row - 1; stars++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    int n1, n2;

    if (scanf("%d %d", &n1, &n2) != 2) {
        return 1;
    }

    print_pyramid(n1);
    putchar('\n');       // 两个图形之间空一行，可删除
    print_pyramid(n2);

    return 0;
}
