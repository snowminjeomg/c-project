#include <stdio.h>
#include <string.h>

typedef unsigned long long ull;

// 判断 n 是否为素数
int is_prime(ull n)
{
    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    // 大于 2 的偶数都不是素数
    if (n % 2 == 0)
        return 0;

    // 只检查奇数因子
    for (ull d = 3; d <= n / d; d += 2) {
        if (n % d == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    char s[20];

    scanf("%19s", s);

    int length = (int)strlen(s);
    ull palindrome = 0;

    // 第一步：把原来的数 t 放入 palindrome
    // 例如 "127" 变成 127
    for (int i = 0; i < length; i++) {
        palindrome = palindrome * 10 + (s[i] - '0');
    }

    // 第二步：从原数倒数第二位开始，依次加到末尾
    // 例如 "127" 接着加入 '2'、'1'，得到 12721
    for (int i = length - 2; i >= 0; i--) {
        palindrome = palindrome * 10 + (s[i] - '0');
    }

    if (is_prime(palindrome)) {
        printf("prime\n");
    } else {
        printf("noprime\n");
    }

    return 0;
}
