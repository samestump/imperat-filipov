#include "stdio.h"

int main(int argc, char const *argv[])
{
    if(freopen("input.txt", "r", stdin) == NULL) {
        printf("Errror open file!\n");
        return -1;
    }
    freopen("output.txt", "w", stdout);

    int a, b, c;
    scanf("%d", &a); 
    scanf("%d", &b); 
    scanf("%d", &c); 

    if(a <= 0) {
        printf("%d", -1);
    } 
    else if (b <= 0) {
        printf("%d", -2);
    }
    else if (c <= 0) {
        printf("%d", -3);
    }
    else {
        printf("%d", 2 * (a * b + b * c + a * c));
    }

    return 0;
}
