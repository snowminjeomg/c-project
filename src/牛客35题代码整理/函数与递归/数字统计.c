#include <stdio.h>

int main(void)
{
    int left, right;
    int answer = 0;

    scanf("%d %d", &left, &right);
    for (int value = left; value <= right; value++) {
        int current = value;
        while (current > 0) {
            if (current % 10 == 2) answer++;
            current /= 10;
        }
    }

    printf("%d\n", answer);
    return 0;
}
