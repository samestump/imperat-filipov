#include "stdio.h"

int main(void) {

    if(freopen("output.txt", "w", stdout) == NULL) return -1;
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    char string[1001];
    int temp;
    int ind = -1;
    while ((temp = getchar()) != EOF) {
        if(temp == '\n' || temp == '\r') continue;
        *(string + (++ind)) = temp;
    }

    *(string + ind + 1) = ' ';


    for (int r = 0; r <= ind; r++) {
        while (r <= ind && *(string + r) == ' ') {
            r++;
        }

        int l = r;

        while (*(string + r) != ' ') {
            r++;
        }

        int wl = r - l;

        if(wl == 1) {
            putchar(*(string + l));
            if(r <= ind) putchar(' ');
        }
        else if(wl > 0){
            printf("%c%d%c", *(string + l), wl - 2, *(string + r - 1));
            if(r <= ind) putchar(' ');
        }

    }
    return 0;
}
