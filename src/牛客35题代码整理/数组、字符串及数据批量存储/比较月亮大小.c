#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int previous = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        previous = last;
        scanf("%d", &last);
    }

    if (n == 1) {
        if (last == 0) {
            puts("UP");
        } else if (last == 15) {
            puts("DOWN");
        } else {
            puts("-1");
        }
    } else if (last == 15) {
        puts("DOWN");
    } else if (last == 0) {
        puts("UP");
    } else if (previous < last) {
        puts("UP");
    } else {
        puts("DOWN");
    }

    return 0;
}
