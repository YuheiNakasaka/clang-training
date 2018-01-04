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
// 分割統治で配列を２分した末端の左端の[1,2]から処理していって、[3,4]->[2,1],[4,3]->[4,3,2,1]と処理をする
// 次に右側の配列にも同様の処理をして[8,7,6,5]にする
// 最後に[4,3,2,1]と[8,7,6,5]を[8,7,6,5,4,3,2,1]にマージしておわり
int main() {
  int array[N] = {1,2,3,4,5,6,7,8};
  output_array(array);

  mergeSort(array, 0, N - 1);

  printf("Finish sorting");
  return 0;
}