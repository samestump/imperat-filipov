#include "stdio.h"

int main(void) {

    if(freopen("output.txt", "w", stdout) == NULL) return -1;
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int n, m;
    int temp1, temp2;
    scanf("%d %d\n", &n, &m);

    int countx[301] = {0};
    int county[301] = {0};

    _Bool one = 1, two = 1, three = 1, four = 1;

    for (int ind = 0; ind < m; ind++) {
        scanf("%d %d\n", &temp1, &temp2);
        countx[temp1] += 1;
        county[temp2] += 1;
    }

    for (int ind = 1; ind <= n; ind++) {
        // printf("%d %d\n", countx[ind], county[ind]);
        if(countx[ind] > 1) one = 0;
        if(countx[ind] == 0) two = 0;
        if(county[ind] > 1) three = 0;
        if(county[ind] == 0) four = 0;
    }

    // printf("%d %d %d %d %d", one, one && two, one && three, one && four, one && four && three);
    if(!one) {
        printf("0");
    }
    else {
        putchar('1');
        if(two) printf(" 2");
        if(three) printf(" 3");
        if(four) printf(" 4");
        if(three && four) printf(" 5");
    }

    return 0;
}
