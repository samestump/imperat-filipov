#include <stdio.h>
#include <string.h>

char *clear_string(char *str) {
    for (int el = strlen(str) - 1; el > 0; el--) {
        if (str[el] == '\r' || str[el] == '\n') {
            str[el] = '\0';
        } else break;
    }
    return str;
}

char *concat(char *pref, char *suff) {
    char *end = pref;

    while (*end != '\0') {
        end++;
    }

    while (*suff != '\0') {
        *end = *suff;
        end++;
        suff++;
    }

    *end = '\0';
    return end;
}

int main(void) {

    if(freopen("input.txt", "r", stdin) == NULL) return -1;
    if(freopen("output.txt", "w", stdout) == NULL) return -1;

    int n;
    scanf("%d", &n);
    getchar();

    char result[1000001] = "";
    char s[101];

    for (int i = 0; i < n; i++) {
        fgets(s, sizeof(s), stdin);
        clear_string(s);

        concat(result, s);
    }

    printf("%s", result);

    return 0;
}
