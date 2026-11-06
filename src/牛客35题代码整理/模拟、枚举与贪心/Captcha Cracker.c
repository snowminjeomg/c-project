#include <stdio.h>
#include <string.h>
#define MAX_LEN 100005
int main(){
    char s[MAX_LEN];
    char digits[5] = {'0', '2', '4', '6', '9'};
    char words[5][5] = {"zero", "two", "four", "six", "nine"};
    int word_len[5] = {4, 3, 4, 3, 4};
    int T;
    int test;
    scanf("%d", &T);
    for (test = 0; test < T; test++) {
        int i;
        scanf("%100004s", s);
        for (i = 0; s[i] != '\0'; i++) {
            int k;
            for (k = 0; k < 5; k++) {
                if (s[i] == digits[k] ||
                    strncmp(&s[i], words[k], word_len[k]) == 0) {
                    putchar(digits[k]);
                    break;
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
