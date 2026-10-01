#include "stdio.h"

int main(void) {

    if(freopen("output.txt", "w", stdout) == NULL) return -1;
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    char temp;

    while ((temp = getchar()) != 0) {
        putchar(temp);
        putchar('\n');
    }

    return 0;
}
