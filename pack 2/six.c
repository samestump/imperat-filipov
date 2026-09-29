#include <stdio.h>

int main(void)
{
    freopen("output.txt", "w", stdout);
    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    // l - от какого, r - до какого, k - count el on prog
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);

    long long answer = 0;

    // d - шаг прогрессии
    for (int d = 1; d <= (r - l) / (k - 1); d++) {
        int lastf = r - (k - 1) * d;
        int firstf = r - k * d + 1;

        if (firstf < l)
            firstf = l;

        if (firstf <= lastf)
            answer += lastf - firstf + 1;
        // printf("%d %d\n", firstf, lastf);
    }

    printf("%lld\n", answer);
    return 0;
}
