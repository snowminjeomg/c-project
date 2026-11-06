#include <stdio.h>

int main(void)
{
    int m, n;

    if (scanf("%d %d", &m, &n) != 2) {
        return 1;
    }

    if (n == 0) {
        printf("除数不能为 0\n");
        return 1;
    }

    if (m % n == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
