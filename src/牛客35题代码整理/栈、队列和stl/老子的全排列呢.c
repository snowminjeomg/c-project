#include <stdio.h>

int main(void)
{
    int p1, p2, p3, p4, p5, p6, p7, p8;

    for (p1 = 1; p1 <= 8; p1++) {
        for (p2 = 1; p2 <= 8; p2++) {
            for (p3 = 1; p3 <= 8; p3++) {
                for (p4 = 1; p4 <= 8; p4++) {
                    for (p5 = 1; p5 <= 8; p5++) {
                        for (p6 = 1; p6 <= 8; p6++) {
                            for (p7 = 1; p7 <= 8; p7++) {
                                for (p8 = 1; p8 <= 8; p8++) {

                                    // 检查 8 个数字是否全部不同
                                    if (p1 != p2 && p1 != p3 && p1 != p4 &&
                                        p1 != p5 && p1 != p6 && p1 != p7 &&
                                        p1 != p8 && p2 != p3 && p2 != p4 &&
                                        p2 != p5 && p2 != p6 && p2 != p7 &&
                                        p2 != p8 && p3 != p4 && p3 != p5 &&
                                        p3 != p6 && p3 != p7 && p3 != p8 &&
                                        p4 != p5 && p4 != p6 && p4 != p7 &&
                                        p4 != p8 && p5 != p6 && p5 != p7 &&
                                        p5 != p8 && p6 != p7 && p6 != p8 &&
                                        p7 != p8) {

                                        printf("%d %d %d %d %d %d %d %d\n",
                                               p1, p2, p3, p4,
                                               p5, p6, p7, p8);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
