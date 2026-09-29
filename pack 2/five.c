#include "stdio.h"

int pw(int x, int y) {
    int answer = 1;
    for(int i = 0; i < y; i++) {
        answer *= x;
    }
    return answer;
}

int main(void) {
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    char temp;
    int n;
    int eight = 0, number = 0;

    scanf("%d", &n);
    // scanf("%c", &temp);
    // printf("%d\n", n);
    while(scanf("%c", &temp) == 1) {
        // scanf("%c", &temp)
        if(temp == '\n' || temp == '\r') continue;
        int tn = temp - '0';
        // printf("%c", temp);
        if(eight > 7) {
           printf("%d ", number);
           eight = number = 0;
        }
        number += (tn * pw(2, eight));
        eight++;
    }
    // printf("%d", pw(2, 8));
    if(eight != 0) printf("%d", number);
    return 0;
}
