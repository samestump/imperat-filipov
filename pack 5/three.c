#include <string.h>
#include <stdio.h>

typedef struct {
    char name[16];
    int age;
} Label;

typedef struct {
    int cntTotal;
    int cntLong;
} NameStats;

typedef struct {
    int cntTotal;
    int cntAdult;
    int cntKids;
} AgeStats;

void calcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges) {
    oNames->cntLong = 0;
    oNames->cntTotal = 0;
    oAges->cntTotal = 0;
    oAges->cntAdult = 0;
    oAges->cntKids = 0;
    for (int ind = 0; ind < cnt; ind++) {
        if(arr[ind].age < 14) oAges->cntKids++;
        if(arr[ind].age >= 18) oAges->cntAdult++;
        if(strlen(arr[ind].name) > 10) oNames->cntLong++;
        if(strlen(arr[ind].name) > 0) oNames->cntTotal++;
        if(arr[ind].age > 0) oAges->cntTotal++;
    }
}


int main(void) {

    if (freopen("input.txt", "r", stdin) == NULL) return -1;
    if (freopen("output.txt", "w", stdout) == NULL) return -1;
    int n;
    scanf("%d", &n);

    Label arr[n];
    char name[16];
    int age;
    int i = 0;
    for (int ind = 0; ind < n; ind++) {
        scanf("%s %d %*s", name, &age);
        arr[ind].age = age;
        while (name[i] != '\0') {
            arr[ind].name[i] = name[i];
            i++;
        }
        name[i] = '\0';
        i = 0;
    }

    NameStats answer1;
    AgeStats answer2;

    calcStats(arr, n, &answer1, &answer2);
    // names: total = 7
    // names: long = 2
    // ages: total = 7
    // ages: adult = 3
    // ages: kid = 2
    printf(
        "names: total = %d\nnames: long = %d\nages: total = %d\nages: adult = %d\nages: kid = %d",
        answer1.cntTotal,
        answer1.cntLong,
        answer2.cntTotal,
        answer2.cntAdult,
        answer2.cntKids
    );

    return 0;
}
