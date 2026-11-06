#include <stdio.h>

int main(void)
{
    int L, M;
    int removed[10005] = {0};
    int l, r;
    int x;
    int answer = 0;

    scanf("%d%d", &L, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &l, &r);
        for (x = l; x <= r; x++) {
            removed[x] = 1;
        }
    }

    for (x = 0; x <= L; x++) {
        if (removed[x] == 0) answer++;
    }

    printf("%d\n", answer);
    return 0;
}
