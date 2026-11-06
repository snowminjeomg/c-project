#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    // 保证 a 比较小，b 比较大
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int answer = 0;

    // 依次检查 a 到 b 的每个数
    for (int i = a; i <= b; i++) {
        int number = i;
        int sum = 0;

        // 取出每一位，并累加
        while (number > 0) {
            sum = sum + number % 10;
            number = number / 10;
        }

        // 判断各位数字之和是否为 5 的倍数
        if (sum % 5 == 0) {
            answer++;
        }
    }

    printf("%d\n", answer);
    return 0;
}
