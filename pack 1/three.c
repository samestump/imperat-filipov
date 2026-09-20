#include "stdio.h"

int count_nine(unsigned long long num) {
    int answer = 0;
    while(num > 0) {
        if(num % 10 == 9) answer++;
        num /= 10;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    if(freopen("input.txt", "r", stdin) == NULL) {
        return -1;
    }
    freopen("output.txt", "w", stdout);

    int N;
    unsigned int answer = 0;
    unsigned long long temp;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%llu", &temp);
        answer += count_nine(temp * 100 - 1) - count_nine(temp);
    }
   printf("%u", answer);
    return 0;
}