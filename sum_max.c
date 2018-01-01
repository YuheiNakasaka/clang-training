#include <stdio.h>

void sum(int *a, int l) {
  int sum = 0;
  for (int n = 0; n < l; n++) {
    sum += a[n];
  }
  printf("sum: %d\n", sum);
}

void max(int *a, int l) {
  int max = a[0];
  for (int n = 0; n < l; n++) {
    if (a[n] > max) {
      max = a[n];
    }
  }
  printf("max: %d\n", max);
}

int main() {
  int src[4] = {23, 10, 3, 8};
  int length = sizeof(src) / sizeof(src[0]);
  sum(src, length);
  max(src, length);
  return 0;
}