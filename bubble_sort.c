#include <stdio.h>

// バブルソート
int main() {
  int array[] = {2,5,4,7,8,3,1,7,9,0,6};
  int length = sizeof(array) / sizeof(array[0]);

  int sorted = length;
  while(sorted > 1) {
    sorted = length;
    for (int i = 0; i < length; i++) {
      // 最後の要素の一つ前の要素まで
      if (i + 1 < length) {
        if (array[i] > array[i + 1]) {
          int tmp = array[i];
          array[i] = array[i + 1];
          array[i + 1] = tmp;
        } else {
          // ソートしてない回数をかぞえる、0になったらすべてソートされたことを意味する
          sorted--;
        }
      }
    }
  }

  for(int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}