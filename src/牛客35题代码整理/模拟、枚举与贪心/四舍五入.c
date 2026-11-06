#include <stdio.h>
#include <string.h>

#define MAXN 200005

char s[MAXN];

void addOne(int *length)
{
    int i = *length - 1;
    while (i >= 0 && s[i] == '9') {
        s[i] = '0';
        i--;
    }

    if (i >= 0) {
        s[i]++;
    } else {
        for (i = *length; i >= 0; i--) {
            s[i + 1] = s[i];
        }
        s[0] = '1';
        (*length)++;
    }
}

int main(void)
{
    int n;
    int length;
    long long t;

    scanf("%d%lld", &n, &t);
    scanf("%s", s);
    length = (int)strlen(s);

    char *dotPointer = strchr(s, '.');
    if (dotPointer == NULL) {
        puts(s);
        return 0;
    }

    int dot = (int)(dotPointer - s);
    int p = dot + 1;
    while (p < length && s[p] < '5') {
        p++;
    }
    if (p == length) p = -1;

    while (p != -1 && t > 0) {
        t--;

        if (p == dot + 1) {
            s[dot] = '\0';
            length = dot;
            addOne(&length);
            p = -1;
        } else {
            s[p] = '\0';
            length = p;

            int i = p - 1;
            while (i > dot && s[i] == '9') {
                s[i] = '0';
                i--;
            }

            if (i == dot) {
                s[dot] = '\0';
                length = dot;
                addOne(&length);
                p = -1;
            } else {
                s[i]++;
                p = s[i] >= '5' ? i : -1;
            }
        }
    }

    if (strchr(s, '.') != NULL) {
        length = (int)strlen(s);
        while (length > 0 && s[length - 1] == '0') length--;
        if (length > 0 && s[length - 1] == '.') length--;
        s[length] = '\0';
    }

    puts(s);
    return 0;
}
