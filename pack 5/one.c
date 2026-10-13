
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

long double iexp(double x) {
    if (x < 0) return 1.0 / iexp(-x);
    if (x > 1) {
        double r = iexp(x / 2.0);
        return r * r;
    };
    long double result = 0.0;

    for (int i = 0; i <= 20; i++) {
        result += pw(x, i) / factorial(i);
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
        printf("%.15Lg\n", iexp(temp));
    }

    // printf("%Lf", pw(100.0, 12));
    return 0;
}
