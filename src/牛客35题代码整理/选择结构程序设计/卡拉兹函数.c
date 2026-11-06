#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    if (n % 2 != 0) {
        printf("%d\n", 3 * n + 1);
    } else {
        printf("%d\n", n / 2);
    }

    return 0;
}
