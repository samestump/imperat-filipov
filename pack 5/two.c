#include <stdio.h>
#include <stdlib.h>

long double pw(const double x, const int y) {
    if(y == 0) return 1;
    if(y == 1) return x;
    long double answer = 1;
    for(int i = 0; i < y; i++) {
        answer *= x;
    }
    return answer;
}

unsigned long long factorial(int x) {
    if(x == 0 || x == 1) return 1;
    unsigned long long arr = 1;
    for (int ind = 2; ind <= x; ind++) {
        arr *= ind;
    }
    return arr;
}

long double isin(double x) {
    if(x == 0) return 0;
    long double result = 0;
    for (int ind = 0; ind <= 9; ind++) {
        result += pw(-1, ind) * pw(x, 2 * ind + 1) / factorial(2 * ind + 1);
    }
    return result;
}

int main(void) {

    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    if (freopen("output.txt", "w", stdout) == NULL) return -1;

    int n;
    scanf("%d", &n);
    double temp;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        printf("%.15Lf\n", isin(temp));
    }

    return 0;
}
