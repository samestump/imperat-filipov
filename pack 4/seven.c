#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int unucle_prefix_len(char* arr[], int main_word, int count) {
    int len = strlen(arr[main_word]);
    int unicle_prefix = 1;

    while (unicle_prefix <= len) {
        bool is_unicle = true;

        for (int j = 0; j < count; j++) {
            if (main_word == j) continue;

            if (strncmp(arr[main_word], arr[j], unicle_prefix) == 0) {
                is_unicle = false;
                break;
            }
        }

        if (is_unicle) {
            return unicle_prefix;
        }

        unicle_prefix++;
    }

    return len;
}

int main(void) {
    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    if (freopen("output.txt", "w", stdout) == NULL) return -1;

    char word[100][101];
    char* words[100];
    int count = 0;

    while (count < 100) {
        if (scanf("%100s", word[count]) != 1) {
            break;
        }

        words[count] = word[count];
        count++;
    }

    for (int ind = count - 1; ind >= 0; ind--) {
        int prefix_len = unucle_prefix_len(words, ind, count);

        if (ind != count - 1) printf("#");
        printf("%.*s", prefix_len, words[ind]);
    }

    printf("\n");
    return 0;
}
