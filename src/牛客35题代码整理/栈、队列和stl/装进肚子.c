#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

typedef struct {
    long long morning;  // 早上吃的甜蜜值
    long long evening;  // 晚上吃的甜蜜值
    long long extra;    // 早上比晚上多吃到的甜蜜值
} Chocolate;

// 按照 extra 从大到小排序
int compare(const void *p1, const void *p2)
{
    Chocolate *x = (Chocolate *)p1;
    Chocolate *y = (Chocolate *)p2;

    if (x->extra < y->extra)
        return 1;
    if (x->extra > y->extra)
        return -1;

    return 0;
}

int main(void)
{
    int n, k;
    Chocolate chocolates[MAX_N];
    long long answer = 0;

    scanf("%d %d", &n, &k);

    // 读取每块巧克力早上的甜蜜值
    for (int i = 0; i < n; i++) {
        scanf("%lld", &chocolates[i].morning);
    }

    // 读取晚上的甜蜜值，并计算早上比晚上多出的甜蜜值
    for (int i = 0; i < n; i++) {
        scanf("%lld", &chocolates[i].evening);
        chocolates[i].extra =
            chocolates[i].morning - chocolates[i].evening;
    }

    // 按 extra 从大到小排序
    qsort(chocolates, n, sizeof(Chocolate), compare);

    // 前 k 个在早上吃，其余在晚上吃
    for (int i = 0; i < n; i++) {
        if (i < k) {
            answer += chocolates[i].morning;
        } else {
            answer += chocolates[i].evening;
        }
    }

    printf("%lld\n", answer);

    return 0;
}
