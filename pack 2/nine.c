#include "stdio.h"

int main(void) {

    freopen("output.txt", "w", stdout);
    if (freopen("input.txt", "r", stdin) == NULL) return -1;

    char temp;
    char back_char;

    while(scanf("%c", &temp) == 1) {
        // если / проверяем не является ли это частью
        // объявления комментария, если нет
        // то просто выводим эти символы
        if(temp == '/') {
            back_char = temp;
            if(scanf("%c", &temp) != 1) {
                printf("%c", temp);
                break;
            };
            if(temp == '/') {
                while(1) {
                    if(scanf("%c", &temp) != 1) break;
                    if(temp == '\n') {
                        printf("%c", temp);
                        break;
                    }
                }
            }
            else if(temp == '*') {
                while(1) {
                    if(scanf("%c", &temp) != 1) break;
                    if(temp == '\n') printf("%c", temp);
                    if(temp == '*') {
                        if(scanf("%c", &temp) != 1) break;
                        if(temp == '/') break;
                    }
                }
            }
            else printf("%c%c", back_char, temp);
        }
        else printf("%c", temp);
    }

    return 0;
}
