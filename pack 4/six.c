#include <stdio.h>
#include <stdbool.h>

int read_line(char* s, const int maxel) {
    int len = 0;
    char temp;

    while ((temp = getchar()) != '\n' && len < maxel - 1) {
        if(temp == EOF) return EOF;
        s[len++] = temp;
    }
    s[len] = '\0';

    return len;
}

int readTime(char *iStr, int *oHours, int *oMinutes, int *oSeconds) {
    *oHours = *oMinutes = *oSeconds = 0;

    char count_colon = 0;
    char count_num = 0;
    for (int ind = 0; iStr[ind] != '\0'; ind++) {

        bool correct_symbol = ('0' <= iStr[ind] && iStr[ind] <= '9') || iStr[ind] == ':';
        if (!correct_symbol) {
            *oHours = *oMinutes = *oSeconds = -1;
            return 0;
        }

        if (iStr[ind] == ':') {
            count_num = 0;
            count_colon++;
            continue;
        }
        else count_num++;
        if(count_num > 2) {
            *oHours = *oMinutes = *oSeconds = -1;
            return 0;
        }

        if (count_colon == 0 && oHours != NULL) {
            *oHours = *oHours * 10 + (iStr[ind] - '0');
        }
        else if (count_colon == 1 && oMinutes != NULL) {
            *oMinutes = *oMinutes * 10 + (iStr[ind] - '0');
        }
        else if (count_colon == 2 && oSeconds != NULL) {
            *oSeconds = *oSeconds * 10 + (iStr[ind] - '0');
        }

    }

    if (*oHours > 23 || *oMinutes > 59 || *oSeconds > 59) {
        *oHours = *oMinutes = * oSeconds = -1;
        return 0;
    }

    return 1;
}

int main(void) {

    if(freopen("input.txt", "r", stdin) == NULL) return -1;
    if(freopen("output.txt", "w", stdout) == NULL) return -1;

    char string[15];
    int h, m, s;
    read_line(string, 15);
    int result;

    result = readTime(string, &h, &m, &s);
    printf("%d %d %d %d\n", result, h, m, s);
    result = readTime(string, &h, &m, &s);
    printf("%d %d %d\n", result, h, m);
    result = readTime(string, &h, &m, &s);
    printf("%d %d", result, h);

    return 0;
}
