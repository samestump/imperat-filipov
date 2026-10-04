#include <stdio.h>
#include <stdbool.h>

bool is_let(char x) {
    return (('a' <= x) && (x <= 'z')) || (('A' <= x) && (x <= 'Z'));
}

int main(void) {

    if (freopen("output.txt", "w", stdout) == NULL) return -1;
    if (freopen("input.txt", "r", stdin) == NULL) return -1;

    int n;
    scanf("%d", &n);
    char a[n + 1];
    a[n] = '\0';

    int ind = 0;
    char temp;
    while (ind < n) {
        temp = getchar();
        if (is_let(temp)) {
            a[ind++] = temp;
        }
    }

    int i = n - 2;
    while (i >= 0 && a[i] > a[i + 1])
        i--;

    int j = n - 1;
    while (a[j] < a[i])
        j--;

    char t = a[i]; a[i] = a[j]; a[j] = t;

    for (int l = i + 1, r = n - 1; l < r; l++, r--) {
        t = a[l]; a[l] = a[r]; a[r] = t;
    }

    for (int ind = 0; ind < n; ind++) {
        putchar(a[ind]);
        if(ind < n - 1) putchar(' ');
    }

    return 0;
}
