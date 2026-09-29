#include "stdio.h"

int main(void) {

    freopen("output.txt", "w", stdout);
    if (freopen("input.txt", "r", stdin) == NULL) return -1;


    return 0;
}
