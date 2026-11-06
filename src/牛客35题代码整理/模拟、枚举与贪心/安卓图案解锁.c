#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char password[35];
    int used[10];
    while (scanf("%34s", password) == 1) {
        memset(used, 0, sizeof(used));
        int valid = 1;
        int length = (int)strlen(password);
        for (int i = 0; i < length && valid; ++i) {
            int current = password[i] - '0';
            if (current < 1 || current > 9 || used[current]) {
                valid = 0;
                break;
            }
            if (i > 0) {
                int previous = password[i - 1] - '0';
                int previous_row = (previous - 1) / 3;
                int previous_column = (previous - 1) % 3;
                int current_row = (current - 1) / 3;
                int current_column = (current - 1) % 3;
                int row_distance = abs(previous_row - current_row);
                int column_distance = abs(previous_column - current_column);

                if (row_distance % 2 == 0 && column_distance % 2 == 0) {
                    int middle = (previous + current) / 2;

                    if (!used[middle]) {
                        valid = 0;
                        break;
                    }
                }
            }

            used[current] = 1;
        }

        puts(valid ? "YES" : "NO");
    }

    return 0;
}
