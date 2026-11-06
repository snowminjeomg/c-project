#include <stdio.h>
#include <string.h>

#define MAX_N 20
#define MAX_LEN 100

int main(void)
{
    char nums[MAX_N][MAX_LEN + 1];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", nums[i]);
    }

    /* 冒泡排序 */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            char first[2 * MAX_LEN + 1];
            char second[2 * MAX_LEN + 1];

            /* first = nums[j] + nums[j+1] */
            strcpy(first, nums[j]);
            strcat(first, nums[j + 1]);

            /* second = nums[j+1] + nums[j] */
            strcpy(second, nums[j + 1]);
            strcat(second, nums[j]);

            /* 如果前后拼接结果更小，就交换 */
            if (strcmp(first, second) < 0) {
                char temp[MAX_LEN + 1];

                strcpy(temp, nums[j]);
                strcpy(nums[j], nums[j + 1]);
                strcpy(nums[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s", nums[i]);
    }
    printf("\n");

    return 0;
}
