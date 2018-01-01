#include <stdio.h>

int main() {
  int m = 128;
  int n = 48;
  int d;

  // ユークリッドの互除法
  while (1) {
    d = m % n;
    if (d == 0) {
      printf("公約数: %d", n);
      break;
    } else {
      m = n;
      n = d;
    }
  }

  return 0;
}