#include <stdio.h>

int calcLetters(char *iStr, int *oLowerCnt, int *oUpperCnt, int *oDigitsCnt) {
    int ind = 0;
    while (iStr[ind] != '\0') {
        char a = iStr[ind];
        *oLowerCnt += ('a' <= a && a <= 'z');
        *oUpperCnt += ('A' <= a && a <= 'Z');
        *oDigitsCnt += ('0' <= a && a <= '9');
        ind++;
    }
    return ind;
}

char* clear_string(char *str) {
    int ind = 0;
    while (str[ind] <= 126 && 32 <= str[ind]) {
        // printf("%d -- %d\n", ind, str[ind]);
        ind++;
    }
    str[ind] = '\0';
    return str;
}

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

int main(void) {

    if(freopen("input.txt", "r", stdin) == NULL) return -1;
    if(freopen("output.txt", "w", stdout) == NULL) return -1;

    char s[101];
    int counter = 0;

    while (read_line(s, 101) != EOF) {
        int low = 0;
        int up = 0;
        int dec = 0;
        clear_string(s);
        int len = calcLetters(s, &low, &up, &dec);
        // if(!len) continue;
        printf(
            "Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n",
            ++counter, len, low + up, low, up, dec
        );
    }
    return 0;
}
