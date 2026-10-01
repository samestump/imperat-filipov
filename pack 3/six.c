#include "stdio.h"
#include "stdbool.h"

int main(void) {

    if(freopen("output.txt", "w", stdout) == NULL) return -1;
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int a, b, temp;
    int countel = 0;

    scanf("%d\n", &a);
    bool arr[100001] = {false};
    for (int i = 0; i < a; i++) {
        if(scanf("%d", &temp) != 1) return -2;
        arr[temp] = true;
    }

    scanf("%d\n", &b);
    bool brr[100001] = {false};
    for (int i = 0; i < b; i++) {
        if(scanf("%d", &temp) != 1) return -2;
        brr[temp] = true;
    }

    for (int ind = 0; ind <= 100000; ind++) {
        if(arr[ind] && !brr[ind]) {
            countel++;
            // printf("%d ", ind);
        }
    }

    printf("%d\n", countel);

    for (int ind = 0; ind <= 100000; ind++) {
        if(arr[ind] && !brr[ind]) {
            // countel++;
            printf("%d ", ind);
        }
    }

    return 0;
}
