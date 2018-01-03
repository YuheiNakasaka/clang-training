#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000

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

// 軸の値を決める
// 左端(lower)と右端(upper)から中央に向かって走査する
// data[lower] > data[upper]になる値があれば交換する
// 左のdataと右のdataで同様の処理を繰り返す
void quickSort(int bottom, int top, int *data) {
  int lower, upper, div, temp;
  if (bottom >= top) {
    return;
  }
  div = data[bottom];

  for (lower = bottom, upper = top; lower < upper;) {
    while (lower <= upper && data[lower] <= div) {
      lower++;
    }
    while (lower <= upper && data[upper] > div) {
      upper--;
    }

    if (lower < upper) {
      temp = data[lower];
      data[lower] = data[upper];
      data[upper] = temp;
    }
  }

  // upper > lowerになってるのでdiv未満の左側dataの一番右の添え字はupper
  // divはdataの添え字0のところにあるので、bottomとupperの値交換をすればdivを中央に持ってこれる
  temp = data[bottom];
  data[bottom] = data[upper];
  data[upper] = temp;

  // divより小さいdata組とdivより大きいdata組で同様のことを繰り返す
  quickSort(bottom, upper - 1, data);
  quickSort(upper + 1, top, data);
}

// クイックソート
int main() {
  int array[N];
  rand_array(array);
  // output_array(array);

  quickSort(0, N - 1, array);

  // output_array(array);

  printf("Finish sorting");
  return 0;
}