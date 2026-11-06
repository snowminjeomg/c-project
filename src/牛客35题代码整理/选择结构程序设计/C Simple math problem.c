#include <stdio.h>

int main(void)
{
    long long X, Y;

    if (scanf("%lld %lld", &X, &Y) != 2) {
        return 1;
    }

    if (X == 0) {
        printf("除数不能为 0\n");
        return 1;
    }

    long long Z;

    if (Y % X == 0) {
        Z = X + Y;
    } else {
        Z = Y - X;
    }

    printf("%lld\n", Z);

    return 0;
}
