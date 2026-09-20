#include "stdio.h"

int main(int argc, char const *argv[])
{
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) {
        return -1;
    }
    int a, b;
    scanf("%d %d", &a, &b);
    // округление вниз
    int q_floor = (a >= 0) ? (a / b) : ((a - b + 1) / b);
    // округление вверх
    int q_div_up = (a >= 0) ? ((a + b - 1) / b) : (a / b);
    // округление к нулю
    int q_trunc = a / b;
    // правильный математический отстаток
    int r = (a % b + b) % b;
    
    printf("%d %d %d %d", q_floor, q_div_up, q_trunc, r);

    return 0;
}