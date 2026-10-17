#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

char* sumstr(char* a, char* b) {
    // Return reverse arr asnwer a + b
    // a and will be also reverse
    int num = 0;
    int lenA = strlen(a);
    int lenB = strlen(b);
    char* result = calloc(max(lenA, lenB) + 2, sizeof(char));
    int ind;

    for (ind = 0; ind < max(lenA, lenB); ind++) {
        // num += (a[ind] - '0') + (b[ind] - '0');
        if (ind >= lenA) {
            num += (b[ind] - '0');
        }
        else if (ind >= lenB) {
            num += (a[ind] - '0');
        }
        else {
            num += (a[ind] - '0') + (b[ind] - '0');
        }

        result[ind] = (num % 10) + '0';
        num /= 10;
    }

    if (num != 0) {
        result[ind] = num + '0';
        ind++;
    }

    result[ind] = '\0';
    return result;
}

char* febonachi(int n) {
    if(n == 1 || n == 2) return "1";
    char** arr = malloc((n + 1) * sizeof(char*));
    arr[1] = "1";
    arr[2] = "1";
    for (int ind = 3; ind <= n; ind++) {
        arr[ind] = sumstr(arr[ind - 1], arr[ind - 2]);
    }

    int l = strlen(arr[n]);

    for (int ind = 0; ind < l / 2; ind++) {
        char temp = arr[n][ind];
        arr[n][ind] = arr[n][l - ind - 1];
        arr[n][l - ind - 1] = temp;
    }

    for (int ind = 3; ind < n; ind++) {
        free(arr[ind]);
    }

    return arr[n];

}

int main(void) {

    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    if (freopen("output.txt", "w", stdout) == NULL) return -1;

    int num;
    scanf("%d", &num);

    printf("%s", febonachi(num));

    return 0;
}
