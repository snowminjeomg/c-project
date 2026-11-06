#include <stdio.h>

int main(void) {
    int n, x;
    long long count = 0;

    scanf("%d %d", &n, &x);

    for (int i = 1; i <= n; i++) {
        int number = i;

        while (number > 0) {
            if (number % 10 == x) {
                count++;
            }
            number /= 10;
        }
    }

    printf("%lld\n", count);
    return 0;
}
