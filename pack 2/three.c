#include "stdio.h"

int main(void) {

    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    double neg = 0;
    double zer = 0;
    double pol = 0;
    int n, temp;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(temp > 0) pol++;
        else if(temp == 0) zer++;
        else neg++;
    }

    double answer_1 = neg / (double) n;
    double answer_2 = zer / (double) n;
    double answer_3 = pol / (double) n;

    printf("%0.5lf %0.5lf %0.5lf", answer_1, answer_2, answer_3);
    return 0;
}
