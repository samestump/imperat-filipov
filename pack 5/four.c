#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592653589793238462643383279502884L

typedef struct {
    long double x;
    long double y;
} pair;

typedef struct{
    pair A;
    pair B;
    pair C;
} triangle;

long double mod(long double x) {
    return (x < 0) ? -x : x;
}

long double pw(const long double x, const int y) {
    if(y == 0) return 1;
    if(y == 1) return x;
    long double answer = 1;
    for(int i = 0; i < y; i++) {
        answer *= x;
    }
    return answer;
}

long double arctan(long double x) {
    if(x == 0) return 0.0;
    if(x == 1) return PI / 4.0;
    if(x == -1) return -(PI / 4.0);
    if(x > 1) {
        return (PI / 2.0)- arctan(1.0 / x);
    }
    long double result = 0;
    for (int ind = 0; ind <= 70; ind++) {
        result += pw(-1, ind) * pw(x, 2 * ind + 1) / (2 * ind + 1);
    }
    return result;
}

long double angleA(const triangle T) {
    // Реализация нахождения угла A через arctan

    pair AB = {T.B.x - T.A.x, T.B.y - T.A.y};
    pair AC = {T.C.x - T.A.x, T.C.y - T.A.y};
    // D = Scalar product AB * AC
    long double D = AB.x * AC.x + AB.y * AC.y;
    // S = Determinant(AB, AC)
    long double S = AB.x * AC.y - AB.y * AC.x;

    if (D > 0) {
        return arctan(mod(S) / D) * (180.0 / PI);
    }
    else if (D < 0) {
        return 180.0L - arctan(mod(S) / mod(D)) * (180.0 / PI);
    }
    else {
        return PI / 2.0 * (180.0 / PI);
    }
}

int main(void) {

    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    if (freopen("output.txt", "w", stdout) == NULL) return -1;

    int n;
    scanf("%d", &n);

    triangle temp;
    for (int ind = 0; ind < n; ind++) {

        scanf("%Lf %Lf %Lf %Lf %Lf %Lf",
              &temp.A.x, &temp.A.y,
              &temp.B.x, &temp.B.y,
              &temp.C.x, &temp.C.y
        );
        if(ind != n - 1) printf("%0.20Lg\n", angleA(temp));
        else printf("%0.20Lg", angleA(temp));
    }
    return 0;
}
