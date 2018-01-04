#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

void rand_array(int *array) {
  srand((unsigned int)time(NULL));
   for (int i = 0; i < N; i++) {
     array[i] = (int)(rand()*(N - 0 + 1.0) / (1.0 + RAND_MAX));
   }
}

void output_array(int *array) {
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void sentinel_search(int *data, int n) {
  printf("sentinel search\n");
  int tmp = 0;
  int i = 0;

  // 最後の要素を探してる値にする(番兵)
  tmp = data[N - 1];
  data[N - 1] = n;

  while(data[i] != n) {
    i++;
  }

  data[N - 1] = tmp; // 配列を元に戻す
  if (i < N - 1) {
    printf("i = %d\n", i);
  }
  if (tmp == n) {
    printf("i = %d\n", i);
  }
}

// linear search(normal)
void normal_search(int *data, int n) {
  printf("normal search\n");
  for(int i = 0;i < N; i++) {
    if (n == data[i]) {
      printf("i = %d\n", i);
    }
  }
}

int main() {
  int array[N];
  int target = 5;
  rand_array(array);
  output_array(array);
  printf("target: %d\n", target);

  normal_search(array, target);
  sentinel_search(array, target);
  return 0;
}