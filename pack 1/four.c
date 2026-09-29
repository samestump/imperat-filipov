#include "stdio.h"

int perfect(unsigned int num) {
    for (int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) {
        return -1;
    }
    unsigned int temp;
    scanf("%u", &temp);
    if(temp == 1) {
        printf("NO");
        return 0;
    }

    if(perfect(temp)) printf("YES");
    else printf("NO");

    return 0;
}
