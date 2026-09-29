#include "stdio.h"

int cube(int a1, int a2, int b1, int b2, int c1, int c2) {
    // b и c рядом
    if (b1 + c1 <= a1 && b2 <= a2 && c2 <= a2)
        return 1;
    // b и c друг над другом
    if (b1 <= a1 && c1 <= a1 && b2 + c2 <= a2)
        return 1;
    return 0;
}

int main(void) {
    freopen("output.txt", "w", stdout);
    if (freopen("input.txt", "r", stdin) == NULL) return -1;

    int a1, a2, b1, b2, c1, c2;
    scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);

    if (
        cube(a1, a2, b1, b2, c1, c2) ||
        cube(a1, a2, b2, b1, c1, c2) ||
        cube(a1, a2, b1, b2, c2, c1) ||
        cube(a1, a2, b2, b1, c2, c1)
    ) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
