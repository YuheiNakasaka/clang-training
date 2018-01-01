#include <stdio.h>

// エラトステネスのふるい
int main() {
  int m = 2;
  int n = 0;
  int arr_l = 50;
  int data[arr_l];
  int result[arr_l];

  // 初期化
  for (int i = 0; i < arr_l; i++) {
    data[i] = 1;
    result[i] = 0;
  }

  // 0, 1は0
  data[0] = 0;
  data[1] = 0;

  // 2の倍数,3の倍数,4の倍数と順にdataに0を入れてく
  // data[m]が1の場合は素数なので出力する
  int i = 0;
  while(m < arr_l) {
    i = 2 * m;
    while(i < arr_l) {
      data[i] = 0;
      i += m;
    }

    if (data[m] == 1) {
      result[n] = m;
      printf("%d\n", m);
    }
    m++;
    n++;
  }



  return 0;
}