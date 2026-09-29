#include <stdio.h>

int starts_with(const char *s, const char *day) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] != day[i])
            return 0;
        i++;
    }
    return 1;
}

int main(void) {
    freopen("output.txt", "w", stdout);
    if (freopen("input.txt", "r", stdin) == NULL) return -1;

    char string[11];
    scanf("%s", string);

    char *days[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    int count = 0;
    int answer = -1;

    for (int i = 0; i < 7; i++) {
        if (starts_with(string, days[i])) {
            count++;
            answer = i + 1;
        }
        // printf("%d %d\n", count, answer);
    }

    if (count == 0) printf("Invalid");
    else if (count > 1) printf("Ambiguous");
    else printf("%d", answer);

    return 0;
}
