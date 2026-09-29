#include "stdio.h"

int leap_year(int x) {
    return (x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0));
}

int main(void) {
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int daysom[] = {31, 28, 31, 30, 31, 30,31, 31,30, 31, 30, 31};

    int day, month, year, k;
    scanf("%d %d %d %d", &day, &month, &year, &k);

    for(int i = 0; i < k; i++) {
        day++;
        int daytm = (daysom[month - 1] == 28 && leap_year(year)) ? 29 : daysom[month - 1];
        if(day > daytm) {
            day = 1;
            month++;
            if(month > 12) {
                month = 1;
                year++;
            }
        }
    }

    printf("%d %d %d", day, month, year);

    return 0;
}
