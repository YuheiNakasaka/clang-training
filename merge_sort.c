#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 6

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

void mergeSort(int *data, int start, int end) {
  static int tmp[N];
  int m, i, j, k;
  if (start >= end) {
    return;
  }

  m = (start + end) / 2;
  mergeSort(data, start, m);
  mergeSort(data, m + 1, end);

  k = 0;
  for (i = start; i <= m; i++) {
    tmp[k] = data[i];
    k++;
  }
  for (j = end; j >= m; j--) {
    tmp[k] = data[j];
    k++;
  }

  i = 0;
  j = end - start;
  printf("m=%d, i=%d, j=%d, k=%d\n", m, i, j, k);
  for (k = start; k <= end; k++) {
    if (tmp[i] >= tmp[j]) {
      data[k] = tmp[i];
      i++;
    } else {
      data[k] = tmp[j];
      j--;
    }
  }

  output_array(data);
}

// マージソート
int main() {
  int array[N];
  rand_array(array);
  output_array(array);

  mergeSort(array, 0, N - 1);

  printf("Finish sorting");
  return 0;
}