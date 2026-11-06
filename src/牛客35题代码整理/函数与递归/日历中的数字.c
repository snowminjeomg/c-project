#include <stdio.h>

int main(void)
{
    int year, month, x;

    // 每次循环读取一组数据，读到文件结束为止
    while (scanf("%d %d %d", &year, &month, &x) == 3) {
        // days[1] 表示1月的天数，days[2] 表示2月的天数……
        int days[13] = {
            0,
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        // 闰年时，2月有29天
        if ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0)) {
            days[2] = 29;
        }

        int answer = 0;
        int day, i;
        char date[20];

        // 从1号一直数到这个月的最后一天
        for (day = 1; day <= days[month]; day++) {
            /*
             * 生成日期字符串：
             * %d  输出年份
             * %02d 输出至少两位，不足两位时前面补0
             */
            sprintf(date, "%d-%02d-%02d", year, month, day);

            // 检查日期中的每一个字符
            for (i = 0; date[i] != '\0'; i++) {
                if (date[i] - '0' == x) {
                    answer++;
                }
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
