#include "stdio.h"

int main(void) {

    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    const int n;
    scanf("%d\n", &n);
    int temp;

    int mass[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        mass[i] = temp;
    }

    for(int i = 0; i < n; i++) {
        temp = 0;
        for (int j = i + 1; j < n; j++) {
            if(mass[i] > mass[j]) temp++;
        }
        printf("%d", temp);
        if(i < n - 1) printf(" ");
    }

    return 0;
}
