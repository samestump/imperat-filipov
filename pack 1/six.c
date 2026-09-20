#include "stdio.h"

int main(int argc, char const *argv[])
{
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int n, temp;
    int max = -(__INT32_MAX__) - 1;
    int min = __INT32_MAX__;
    int maxind = 1, minind = 1;

    // printf("%d %d %d %d\n", min, minind, max, maxind);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if(temp < min) {
            min = temp;
            minind = i + 1;
        }

        if(temp > max) {
            max = temp;
            maxind = i + 1;
        }
    }
    
    printf("%d %d %d %d", min, minind, max, maxind);

    return 0;
}
