#include "stdio.h"

int main(int argc, char const *argv[])
{
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int h, m, s, k;

    scanf("%d %d %d %d", &h, &m, &s, &k);
    long long total = h * 3600 + m * 60 + s + k;

    total %= 24 * 3600;

    int h2 = total / 3600;
    int m2 = (total % 3600) / 60;
    int s2 = total % 60;

    printf("%d %d %d", h2, m2, s2);

    return 0;
}
