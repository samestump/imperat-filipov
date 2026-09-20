#include "stdio.h"

int main(int argc, char const *argv[])
{
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    unsigned long long x, answer = 0;
    scanf("%llu", &x);

    for (long long a = 1; a * a * a <= x; a++) {
        for(long long b = a; a * b * b <= x; b++) {
            // int c = (x / (a * b)) - b + 1;
            answer += (x / (a * b)) - b + 1;
            // printf("a = %d\tb = %d\tc = %d\n", a, b, c);
        }
    }
    printf("%llu", answer);

    return 0;
}
