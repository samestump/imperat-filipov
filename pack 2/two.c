#include "stdio.h"

char upper(char sym) {
    if('a' <= sym && sym <= 'z') sym -= 32;
    return sym;
}

int validator(char sym) {
    if(
        (('0' <= sym) && (sym <= '9')) ||
        (('A' <= sym) && (sym <= 'F'))
    ) return 0;
    else return 1;
}

int hexti(char f) {
    return ('A' <= f && f <= 'F') ? f - 'A' + 10: f - '0';
}

int main(int argc, char const *argv[])
{
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int lenght = 0;
    char hex[6];
    char temp;

    while(scanf("%c", &temp) == 1) {
        // if(scanf("%c", &temp) == -1) break;
        if(temp == '\n' || temp == '\r') break;
        temp = upper(temp);
        lenght++;
        if(lenght > 6 || validator(temp)) {
            printf("-1 -1 -1");
            return 0;
        }
        else hex[lenght - 1] = temp;
    }
    if(lenght < 6){
        printf("-1 -1 -1");
        return 0;
    }

    int r = hexti(hex[0]) * 16 + hexti(hex[1]);
    int g = hexti(hex[2]) * 16 + hexti(hex[3]);
    int b = hexti(hex[4]) * 16 + hexti(hex[5]);

    printf("%d %d %d", r, g, b);
    return 0;
}
