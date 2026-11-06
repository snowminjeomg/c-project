#include <stdio.h>
#include <string.h>

int main(void)
{
    int T, t;

    scanf("%d", &T);

    for (t = 0; t < T; t++) {
        char s1[55], s2[55];

        /* a[i] 和 b[i] 保存数字的每一位 */
        int a[55] = {0};
        int b[55] = {0};

        /* result 保存乘积，每一位也倒着存放 */
        int result[110] = {0};

        int len1, len2;
        int i, j, len;

        scanf("%s%s", s1, s2);

        len1 = strlen(s1);
        len2 = strlen(s2);

        /*
         * 把字符串倒过来转换成数字。
         *
         * 例如输入 s1 = "233"
         * 原来：s1[0]='2', s1[1]='3', s1[2]='3'
         * 转换后：a[0]=3, a[1]=3, a[2]=2
         *
         * 这样 a[0] 就表示个位，a[1] 表示十位。
         */
        for (i = 0; i < len1; i++) {
            a[i] = s1[len1 - 1 - i] - '0';
        }

        for (i = 0; i < len2; i++) {
            b[i] = s2[len2 - 1 - i] - '0';
        }

        /*
         * 模拟竖式乘法。
         *
         * a[i] 和 b[j] 相乘后，要加到结果的 i+j 位。
         */
        for (i = 0; i < len1; i++) {
            for (j = 0; j < len2; j++) {
                result[i + j] += a[i] * b[j];
            }
        }

        /*
         * 处理进位。
         *
         * result[i] / 10 是进位；
         * result[i] % 10 是当前位保留下来的数字。
         */
        for (i = 0; i < 109; i++) {
            result[i + 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }

        /*
         * 找到最高位。
         * 例如结果是 0054289，要把前面的 00 去掉。
         */
        len = len1 + len2;
        while (len > 0 && result[len] == 0) {
            len--;
        }

        /* 从最高位开始输出 */
        for (i = len; i >= 0; i--) {
            printf("%d", result[i]);
        }
        printf("\n");
    }

    return 0;
}
