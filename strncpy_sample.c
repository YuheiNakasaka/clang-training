#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // strncpy(src, dst, n)
  char a1[] = "abcd";
  char b1[10];
  strncpy(b1, a1, 2);
  printf("%s", b1);

  printf("\n");

  // dstをn文字切り出してsrcにコピーする
  // 注意1: srcは終端文字の\0の分も確保する必要があるのでn+1分用意する
  char a2[] = "abcd";
  char b2[3];
  strncpy(b2, a2, 3);
  printf("%s", b2); // absabcdが表示される。おかしい

  printf("\n");

  // 注意2: nがdstの文字数以下だとバグる
  char a3[] = "ab";
  char b3[3];
  strncpy(b3, a3, 2);
  b3[2] = '\0'; // 最後に終端文字を埋めるといい感じ
  printf("%s", b3);
  return 0;
}