#include "stdio.h"

int main(void) {

    if(freopen("output.txt", "w", stdout) == NULL) return -1;
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

     int n, temp;
     scanf("%d\n", &n);

     int nums[10001] = {0};

     for (int i = 0; i < n; i++) {
         scanf("%d", &temp);
         nums[temp]++;
     }

     for (int i = 1; i <= 10000; i++) {
         if (nums[i] > 0) {
             printf("%d: %d\n", i, nums[i]);
         }
     }

    return 0;
}
