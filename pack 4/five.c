#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char* read_line() {
    size_t capacity = 16;
    size_t len = 0;
    int ch;
    char* s = malloc(capacity * sizeof(char));
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if(len == capacity - 1) {
            capacity *= 2;
            char* temp = realloc(s, capacity);
            if(temp != NULL) s = temp;
            else {
                free(s);
                return 0;
            }
        }
        s[len++] = ch;
    }
    s[len] = '\0';
    return s;
}

bool is_letter(char c) {
    return (('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z'));
}

void world_split(char* s) {
    int cb = 0;
    int start = 0;
    for (int ind = 0; s[ind] != '\0'; ind++) {
        if (!is_letter(s[ind])) continue;
        start = ind;
        while (is_letter(s[ind]) && s[ind] != '\0') {
            cb += (('A' <= s[ind]) && (s[ind] <= 'Z'));
            ind++;
        }
        printf("%d/%d ", cb, ind - start);
        for (int i = start; i < ind; i++) {
            putchar(s[i]);
        }
        putchar('\n');
        cb = 0;
        ind--;
    }
}

int main(void) {

    if(freopen("input.txt", "r", stdin) == NULL) return -1;
    if(freopen("output.txt", "w", stdout) == NULL) return -1;

    char* string = read_line();

    world_split(string);

    free(string);
    return 0;
}
