#include "stdio.h"

int char_to_int(char x) {
    return ('a' <= x && x <= 'z') ? x - 'a' + 10 : x - '0';
}

char int_to_char(int x) {
    return (x < 10) ? '0' + x : 'a' + x - 10;
}

char* translator(int from_base, int to_base, char* srt[]) {
    return 0;
}

int main(void) {

    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int from_base, to_base;
    int decimal = 0;
    char temp;
    char number[32];
    scanf("%d %d ", &from_base, &to_base);

    while(scanf("%c", &temp) == 1) {
        if(temp == '\r' || temp == '\n') continue;
        decimal = decimal * from_base + char_to_int(temp);
    }
    int i = 0;
    while(decimal > 0) {
        number[i] = int_to_char(decimal % to_base);
        decimal /= to_base;
        i++;
    }
    for(i = i - 1;i >= 0; i--) printf("%c", number[i]);
    return 0;
}
