#include <stdio.h>

int main(void) {
    int n, k, m;

    if (scanf("%d %d %d", &n, &k, &m) != 3) {
        return 1;
    }

    /*
     * n 是取模的除数，必须大于 0。
     * 题目保证 n >= 2，这里额外检查以便程序更安全。
     */
    if (n <= 0 || m <= 0 || k < 0 || k >= n) {
        return 1;
    }

    int survivor = 0;

    /*
     * 循环从 i = 2 开始，且 i <= n，
     * 所以 i 永远大于 0，% i 不会除以 0。
     */
    for (int i = 2; i <= n; i++) {
        survivor = (survivor + m) % i;
    }

    /*
     * 前面已经保证 n > 0，
     * 因此这里的 % n 也是安全的。
     */
    int answer = (k + survivor) % n;

    printf("%d\n", answer);
    return 0;
}
