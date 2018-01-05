#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

void output_array(int *array) {
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// binary search
void binarySearch(int *data, int x, int left, int right) {
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (data[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
    if (left == mid) {
      printf("i: %d\n", left);
    }
  }
}

int main() {
  int array[N] = {1,2,3,4,5,6,7,8,9};
  int target = 8;
  output_array(array);
  printf("target: %d\n", target);

  binarySearch(array, target, 0, N - 1);
  return 0;
}