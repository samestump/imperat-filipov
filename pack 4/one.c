#include <stdio.h>
#include <stdlib.h>

int comp(const void* arg1, const void* arg2) {
    int x = *(const int*)arg1;
    int y = *(const int*)arg2;
    return x - y;
}

int main(void) {

    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    if (freopen("output.txt", "w", stdout) == NULL) return -1;

    int a, b;

    scanf("%d\n", &a);
    int* arrA = malloc(a * sizeof(int));

    for (int ind = 0; ind < a; ind++) {
        scanf("%d ", &arrA[ind]);
    }

    scanf("%d\n", &b);
    int* arrB = malloc(b * sizeof(int));

    for (int ind = 0; ind < b; ind++) {
        scanf("%d ", &arrB[ind]);
    }

    qsort(arrA, a, sizeof(int), comp);
    qsort(arrB, b, sizeof(int), comp);

    int counter = 0;
    int* answer = malloc(a * sizeof(int));

    int j = 0; // указатель на B
    for (int i = 0; i < a; i++) { // Указатель на А
        // printf("%d -- %d\t%d -- %d\n", i, arrA[i], j, arrB[j]);
        if(i > 0 && arrA[i] == arrA[i - 1]) continue;

        while (j < b && arrA[i] > arrB[j]) {
            j++;
        }

        if(j == b) {
            answer[counter++] = arrA[i];
            continue;
        }

        if(arrA[i] < arrB[j]) {
            answer[counter++] = arrA[i];
        }

        if(arrA[i] == arrB[j]) {
            j++;
            continue;
        }
    }
    printf("%d\n", counter);
    for (int ind= 0; ind < counter; ind++) {
        printf("%d ", answer[ind]);
    }

    free(answer);
    free(arrA);
    free(arrB);
    return 0;
}
