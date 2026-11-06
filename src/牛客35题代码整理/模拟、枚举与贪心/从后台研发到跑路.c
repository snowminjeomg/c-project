#include <stdio.h>
#define MAX_LEN 6000
int main(){
    char s[MAX_LEN];
    int n = 0;
    int ch;
    int i;
    int in_string = 0;
    while ((ch = getchar()) != EOF) {
        s[n] = (char)ch;
        n++;
    }
    i = 0;
    while (i < n) {
        if (in_string) {
            putchar(s[i]);
            if (s[i] == '"' && (i == 0 || s[i - 1] != '\\')) {
                in_string = 0;
            }
            i++;
        } else {
            if (s[i] == '"') {
                in_string = 1;
                putchar(s[i]);
                i++;
            } else if (i + 1 < n && s[i] == '/' && s[i + 1] == '*') {
                int j = i + 2;
                while (j + 1 < n && !(s[j] == '*' && s[j + 1] == '/')) {
                    j++;
                }
                if (j + 1 < n) {
                    i = j + 2;
                } else {
                    putchar(s[i]);
                    i++;
                }
            } else {
                putchar(s[i]);
                i++;
            }
        }
    }
    return 0;
}
