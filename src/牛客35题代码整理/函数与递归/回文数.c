#include <stdio.h>

int main(void)
{
    int count[10];
    int odd_count = 0;
    int odd_digit = -1;
    int d;
    int k;
    int half_count[10];
    int half_len = 0;
    int first = -1;
    char left[55];
    int device = 0; /* 当前写到 left 数组的哪个位置 */

    for (d = 0; d <= 9; d++) {
        scanf("%d", &count[d]);

        if (count[d] % 2 != 0) {
            odd_count++;
            odd_digit = d;
        }
    }

    /* 回文数最多只能有一个数码出现奇数次。 */
    if (odd_count > 1) {
        printf("-1\n");
        return 0;
    }

    /* 每种数码放一半到左半边，剩下的由镜像产生。 */
    for (d = 0; d <= 9; d++) {
        half_count[d] = count[d] / 2;
        half_len += half_count[d];
    }

    if (half_len > 0) {
        /* 首位不能是 0，所以先选最小的非零数码。 */
        for (d = 1; d <= 9; d++) {
            if (half_count[d] > 0) {
                first = d;
                break;
            }
        }

        /* 左半边全是 0，无法组成没有前导 0 的数。 */
        if (first == -1) {
            printf("-1\n");
            return 0;
        }

        left[device] = (char)('0' + first);
        device++;
        half_count[first]--;

        /* 其余数码从小到大排列，使整个数最小。 */
        for (d = 0; d <= 9; d++) {
            for (k = 0; k < half_count[d]; k++) {
                left[device] = (char)('0' + d);
                device++;
            }
        }
    }

    if (device == 0) {
        /* 只剩一个数码时，它本身就是一位回文数。 */
        printf("%d\n", odd_digit);
        return 0;
    }

    /* 输出左半边和可能的中间数码。 */
    for (d = 0; d < device; d++) {
        putchar(left[d]);
    }
    if (odd_count == 1) {
        putchar((char)('0' + odd_digit));
    }

    /* 按相反顺序输出左半边，得到回文的右半边。 */
    for (d = device - 1; d >= 0; d--) {
        putchar(left[d]);
    }
    putchar('\n');

    return 0;
}
