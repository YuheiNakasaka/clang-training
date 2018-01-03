#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void rand_array(int *array) {
  srand((unsigned int)time(NULL));
   for (int i = 0; i < N; i++) {
     array[i] = rand();
   }
}

void output_array(int *array) {
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// バブルソート
int main() {
  int array[N];
  rand_array(array);
  output_array(array);

  int flag;
  int k = 0;
  do {
    flag = 0;
    for (int i = 0; i < N - 1 - k; i++) {
      if (array[i] > array[i + 1]) {
        int tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
        flag = 1;
      }
    }
    k++;
  } while(flag == 1);

  output_array(array);
  return 0;
}