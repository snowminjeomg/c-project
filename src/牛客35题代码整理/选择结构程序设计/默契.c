#include <stdio.h>

int main(void)
{
    int x, y;

    scanf("%d %d", &x, &y);

    if (x == y) {
        printf("Tacit！\n");
    } else {
        printf("No Tacit!\n");
    }

    return 0;
}
