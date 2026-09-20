#include "stdio.h"

int main(int argc, char const *argv[])
{

    if(freopen("input.txt", "r", stdin) == NULL) {
        printf("Error open file\n");
        return -1;   
    }

    freopen("output.txt", "w", stdout);

    int answer = 0;
    int temp, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if(temp % 2 != 0) {
            answer += temp;
        }
    }
    
    printf("%d", answer);
    return 0;
}

