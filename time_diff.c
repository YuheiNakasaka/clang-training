#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

void match(char *time1, char *h, char *m, char *s) {
  char *pattern1 = "([0-9]{2}):([0-9]{2}):([0-9]{2})";
  regex_t preg;
  size_t nmatch = 4;
  regmatch_t pmatch[nmatch];
  int i, j;

  // 正規表現のpatternコンパイル
  if (regcomp(&preg, pattern1, REG_EXTENDED|REG_NEWLINE) != 0) {
    printf("regex compile failed.\n");
    exit(1);
  }

  // h,m,sに分割
  if (regexec(&preg, time1, nmatch, pmatch, 0) != 0) {
    printf("No match\n");
  } else {
    strncpy(h, &time1[pmatch[1].rm_so], 2);
    h[2] = '\0';
    strncpy(m, &time1[pmatch[2].rm_so], 2);
    m[2] = '\0';
    strncpy(s, &time1[pmatch[3].rm_so], 2);
    s[2] = '\0';
  }
  regfree(&preg);
}

// 時間の差分を計算する
int main(int argc, char *argv[]) {
  char time1[] = "19:23:40";
  char time2[] = "21:08:32";
  char h1[3], m1[3], s1[3];
  char h2[3], m2[3], s2[3];
  match(time1, h1, m1, s1);
  match(time2, h2, m2, s2);

  printf("time1: %s:%s:%s\n", h1, m1, s1);
  printf("time2: %s:%s:%s\n", h2, m2, s2);

  // 時間を秒に直す
  int sec1 = atoi(h1) * 60 * 60 + atoi(m1) * 60 + atoi(s1);
  int sec2 = atoi(h2) * 60 * 60 + atoi(m2) * 60 + atoi(s2);
  printf("sec1: %d\n", sec1);
  printf("sec2: %d\n", sec2);

  // 差分を出す
  int diff;
  if (sec2 > sec1) {
    diff = sec2 - sec1;
  } else {
    diff = sec1 - sec2;
  }

  // 時間に戻す
  int h = diff / (60*60);
  int m = (diff % (60*60)) / 60;
  int s = (diff % (60*60)) % 60;
  printf("diff: %d:%d:%d", h, m, s);

  return 0;
}
