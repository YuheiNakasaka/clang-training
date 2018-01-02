#include <stdio.h>

void primes(int *result, int arr_l) {
  int m = 2;
  int n = 0;
  int data[arr_l];

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
    }
    m++;
    n++;
  }
}

// 素因数分解
int main() {
  int n; // 素因数分解の対象
  scanf("%d", &n);

  int result[n]; // 0~nまでの素数一覧。素数以外は0が格納されてる。
  int pf[n]; // 素因数分解の結果を格納する
  int i = 0;
  int j = 0;

  // pfを初期化
  for(int h = 0; h < n; h++) {
    pf[h] = 0;
  }

  // resultにnまでの素数のリスト作る
  primes(result, n);
  result[n-1] = n; // nが素数の可能性あるので追加する

  // 素数リストでnを割っていき、割り切れるならnを更新
  // 割り切れないならiをインクリメント
  // n-1より大きくなったらiをまた0に戻して、更新したnを素数リストの最初の値から割っていく
  while(1) {
    int prime = result[i];
    if (prime != 0) {
      if (n % prime == 0) {
        pf[j] = prime;
        n = n / prime;
        if (n == 1) {
          break;
        }
        j++;
      }
    }
    i++;
    if (i > n - 1) {
      i = 0;
    }
  }

  // 0で初期化してるのでpf[k]の値が0より大きい値のみ出力
  int length = sizeof(pf) / sizeof(pf[0]);
  printf("N: %d\n", length);
  for(int k = 0; k < length; k++) {
    if (pf[k] != 0) {
      printf("%d ", pf[k]);
    }
  }
  return 0;
}