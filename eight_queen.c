#include <stdio.h>

int board[8][8];

int check(int x, int y) {
  int p, q;

  // 左方向
  for(p = 0; p < x; p++) {
    if (board[p][y] == 1) {
      return 0;
    }
  }

  // 左上方向
  p = x; q = y;
  while(p > 0 && q > 0) {
    if (board[--p][--q] == 1) {
      return 0;
    }
  }

  // 左下方向
  p = x; q = y;
  while(p > 0 && q < 7) {
    if (board[--p][++q] == 1) {
      return 0;
    }
  }
  return 1;
}

void showboard() {
  int x, y;
  for(y = 0; y < 8; y++) {
    for(x = 0; x < 8; x++) {
      printf("%c ", board[x][y]? 'Q' : '.');
    }
    printf("\n");
  }
}

int solve(int x) {
  int i;
  if (x == 8) {
    return 1;
  }

  // 1列目(0, y)から探索
  // 可能な経路が見つかれば次の列(1, y)へ
  // ダメなら(0, y+1)で再度探索
  for (i = 0; i < 8; i++) {
    if (check(x, i)) {
      board[x][i] = 1;
      if (solve(x + 1)) {
        return 1;
      } else {
        board[x][i] = 0;
      }
    }
  }
  return 0;
}

int main() {
  if (solve(0)) {
    showboard();
  }
  return 0;
}