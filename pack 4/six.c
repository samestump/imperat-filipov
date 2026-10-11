#include <stdio.h>

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

}

int main(void) {

    if(freopen("input.txt", "r", stdin) == NULL) return -1;
    if(freopen("output.txt", "w", stdout) == NULL) return -1;

    char string[15];

    read_line(string, 15);

    printf("%s", string);


    return 0;
}
