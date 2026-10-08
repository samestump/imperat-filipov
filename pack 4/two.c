#include <stdio.h>
#include <string.h>

void reverse(char *start, int len) {
  int left = 0;
  int right = len - 1;
  char t;
  while (left < right) {
    t = start[left];
    start[left] = start[right];
    start[right] = t;
    left++;
    right--;
  }

  printf("%s\n", start);
}

int main(void) {
  if (freopen("input.txt", "r", stdin) == NULL)
    return -1;
  if (freopen("output.txt", "w", stdout) == NULL)
    return -1;
  int n;
  char string[101];
  scanf("%d\n\r", &n);

  for (int ind = 0; ind < n; ind++) {
    fgets(string, sizeof(string), stdin);

    for (int el = strlen(string) - 1; el > 0; el--) {
      if (string[el] == '\r' || string[el] == '\n') {
        string[el] = '\0';
      } else
        break;
    }
    // printf("%zu -- %s\n", strlen(string), string);

    reverse(string, strlen(string));
  }

  return 0;
}
