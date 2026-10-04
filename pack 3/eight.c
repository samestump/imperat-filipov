#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {

    if(freopen("output.txt", "w", stdout) == NULL) return -1;
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int n;
    long long water = 0;
    scanf("%d\n", &n);

    if(n == 0) {
        putchar('0');
        return 0;
    }

    int* place = malloc(n * sizeof(int));
    int* leftmax = malloc(n * sizeof(int));

    int mheig = 0;
    for (int ind = 0; ind < n; ind++) {
        scanf("%d", &place[ind]);
        mheig = max(place[ind], mheig);
        leftmax[ind] = mheig;
    }

    for (int point = 0; point < n; point++) {
        if(leftmax[point] == 0) {
            // printf("%d -- %lld, %d, %d, %d\n", point, water, leftmax[point], mheig, place[point]);
            continue;
        }

        if (mheig == place[point]) {

            int new_mheight = 0;
            for (int r = point + 1; r < n; r++) {
                if(place[r] == mheig) {
                    new_mheight = mheig;
                    break;
                }
                new_mheight = max(place[r], new_mheight);
            }
            mheig = new_mheight;
            // printf("%d -- %lld, %d, %d, %d\n", point, water, leftmax[point], mheig, place[point]);
        }
        else {
            water += min(leftmax[point], mheig) - place[point];
            // printf("%d -- %lld, %d, %d, %d\n", point, water, leftmax[point], mheig, place[point]);
        }
    }

    printf("%lld", water);

    free(place);
    free(leftmax);

    return 0;
}
