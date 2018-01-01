#include <stdio.h>

void sum(int *a) {
  int sum = 0;
  int length = sizeof(a) / sizeof(a[0]);
  for (int n = 0; n < length; n++) {
    sum += a[n];
  }
  printf("sum: %d\n", sum);
}

void max(int *a) {
  int max = a[0];
  int length = sizeof(a) / sizeof(a[0]);
  for (int n = 0; n < length; n++) {
    if (a[n] > max) {
      max = a[n];
    }
  }
  printf("max: %d\n", max);
}

int main() {
  int src[] = {23, 10, 3, 8};
  sum(src);
  max(src);
  return 0;
}