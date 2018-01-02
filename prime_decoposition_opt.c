#include <stdio.h>

// 素因数分解
int main() {
  int n; // 素因数分解の対象
  scanf("%d", &n);
  int m = n; // nの約数
  int i = 0;
  int pf[n]; // 素因数分解の結果を格納する

  // pfを初期化
  for(int h = 0; h < n; h++) {
    pf[h] = 0;
  }

  // nの約数を計算して、
  // 割り切れるならn/mを素因数として、nをmで更新
  while(m > 1) {
    m = m - 1;
    if (n % m == 0) {
      pf[i] = n / m;
      n = m;
      i++;
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