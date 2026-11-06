#include <stdio.h>

int main(void) {
    int n;
    long long a[105];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // 枚举三个下标互不相同的元素
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                long long x = a[i];
                long long y = a[j];
                long long z = a[k];

                // 任意两边之和都大于第三边
                if (x + y > z && x + z > y && y + z > x) {
                    printf("%lld %lld %lld\n", x, y, z);
                    return 0;
                }
            }
        }
    }

    printf("No solution\n");
    return 0;
}
