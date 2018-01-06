#include <stdio.h>
#include <stdlib.h>

#define N 5
int size[N] = {2, 3, 5, 6, 9};
int value[N] = {2, 4, 7, 10, 14};

#define NAP_SIZE 16

// 漸化式
int main() {
  int nap_value[NAP_SIZE + 1] = {0};
  int i, j, new_value;

  for(i = 0; i < N; i++) {
    for(j = size[i]; j < NAP_SIZE + 1; j++) {
      new_value = nap_value[j - size[i]] + value[i];
      if (new_value > nap_value[j]) {
        nap_value[j] = new_value;
      }
    }

    for(j = 1; j < NAP_SIZE + 1; j++) {
      printf("%2d ", nap_value[j]);
    }
    printf("\n");
  }
  return 0;
}