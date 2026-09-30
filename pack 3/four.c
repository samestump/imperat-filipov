#include "stdio.h"

int main(void) {

    if(freopen("output.txt", "w", stdout) == NULL) return -1;
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int l = 0, r = 0, best_l = 0, best_r = 0;
    long long now_sum = 0, best_sum = 0;
    int n;
    scanf("%d\n", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    best_sum = now_sum = arr[0];

    for (int r = 1; r < n; r++) {
            now_sum += arr[r];
            if(now_sum < arr[r]) {
                now_sum = arr[r];
                l = r;
            }
            if(now_sum > best_sum) {
                best_sum = now_sum;
                best_l = l;
                best_r = r;
            }
        }

    // for (l = 0; l < n; l++) {
    //     now_sum = 0;
    //     for(r = l; r < n; r++) {
    //         now_sum += arr[r];
    //         if(now_sum > best_sum) {
    //             best_sum = now_sum;
    //             best_l = l;
    //             best_r = r;
    //             // printf("New best -- %d %d %lld\n", best_l, best_r, best_sum);
    //         }
    //     }
    // }

    printf("%d %d %lld", best_l, best_r, best_sum);

    return 0;
}
