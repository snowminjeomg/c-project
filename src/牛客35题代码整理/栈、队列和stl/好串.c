#include <stdio.h>

int main(void) {
    char s[100005];

    scanf("%100000s", s);

    int unmatched_a = 0;  // 当前还未匹配的 a 的数量

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a') {
            unmatched_a++;
        } else if (s[i] == 'b') {
            if (unmatched_a == 0) {
                // 没有 a 可以与这个 b 配对
                printf("Bad\n");
                return 0;
            }
            unmatched_a--;
        } else {
            // 题目保证只有小写字母，但出现其他字符也不是好串
            printf("Bad\n");
            return 0;
        }
    }

    if (unmatched_a == 0) {
        printf("Good\n");
    } else {
        // 还有 a 没有与 b 配对
        printf("Bad\n");
    }

    return 0;
}
