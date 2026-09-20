#include "stdio.h"

int div_up(int a, int b) {
    return (a + b - 1) / b;
}

int main(int argc, char const *argv[])
{
    freopen("output.txt", "w", stdout);
    if(freopen("input.txt", "r", stdin) == NULL) return -1;

    int n, m, p, k, l;
    // m - номер квартиры
    // p - подъезд 
    // k - этаж
    // l - этажей в доме
    
    scanf("%d", &n);
    scanf("%d %d %d %d", &m, &p, &k, &l);
    
    // сколько приходиться квартир на один пролёт
    int i = div_up(m, (p - 1) * l + k);
    // номер подъезда для квартиры n
    int _p = div_up(n, i * l);
    // этаж кв n
    int _k = div_up(n - (_p - 1) * i * l, i);
    printf(
        "%d %d",
        _p,
        _k
    );
    
    return 0;
}