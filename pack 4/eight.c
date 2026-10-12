#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int len_int(int x) {
    if (x == 0) { return 1; }
    int result = 0;
    while (x > 0) {
        x /= 10;
        result++;
    }
    return result;
}

void prframe(int num1, int num2, int num3) {
    putchar('+');
    for (int ind = 0; ind < num1 + 2; ind++) putchar('-');
    putchar('+');
    for (int ind = 0; ind < num2 + 2; ind++) putchar('-');
    putchar('+');
    for (int ind = 0; ind < num3 + 2; ind++) putchar('-');
    putchar('+');
    putchar('\n');
}

int main(void) {

    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    if (freopen("output.txt", "w", stdout) == NULL) return -1;

    int* id = calloc(10001, sizeof(int));
    int* duration = calloc(10001, sizeof(int));

    if (id == NULL || duration == NULL) {
        free(id);
        free(duration);
        return -1;
    }

    int temp_1, temp_2;

    int n;
    int id_max = 0, midlen = 0, mdurlen = 0, mcoulen = 0;
    scanf("%d", &n);

    for (int ind = 0; ind < n; ind++) {
        scanf("%d", &temp_1);
        scanf("%d", &temp_2);
        id[temp_1]++;
        duration[temp_1] += temp_2;
        id_max = max(id_max, temp_1);
        mdurlen = max(mdurlen, len_int(duration[temp_1]));
        mcoulen = max(mcoulen, len_int(id[temp_1]));
    }

    midlen = len_int(id_max);
    prframe(midlen, mcoulen, mdurlen);
    for (int ind = 1; ind <= id_max; ind++) {
        if(id[ind] == 0) continue;
        // printf("%d -- %d %d\n", ind, id[ind], duration[ind]);
        printf("| %*d | %*d | %*d |\n", midlen, ind, mcoulen, id[ind], mdurlen, duration[ind]);
        prframe(midlen, mcoulen, mdurlen);
    }


    free(duration);
    free(id);
    return 0;
}
