#include "stdio.h"

int main() {

    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int n;
    unsigned long long temp = 0;
    scanf("%d", &n);
    int nums[n];

    for (int i = 0; i < n; i++) {
        if(scanf("%d", &nums[i]) != 1) return -2;
    }

    for (int t = 1; t <= n; t++) {
        for (int k = t; k <= n; k += t) {
            temp += nums[k - 1];
        }
        printf("%llu", temp);
        if(t != n) printf("\n");
        temp = 0;
    }

    return 0;
}
