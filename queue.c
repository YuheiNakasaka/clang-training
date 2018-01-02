#include <stdio.h>

#define MAX_LENGTH 10

typedef struct {
  int array[MAX_LENGTH];
  int first;
  int last;
} QUEUE;

void init(QUEUE*);
int enqueue(QUEUE*, int);
int dequeue(QUEUE*, int*);

int main() {
  QUEUE q;
  int value;
  init(&q);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);

  while(dequeue(&q, &value)) {
    printf("%d ", value);
  }
  printf("\n");
  return 0;
}

void init(QUEUE* pQueue) {
  int i;
  for(i = 0; i < MAX_LENGTH; i++) {
    pQueue->array[i] = 0;
  }
  pQueue->first = 0;
  pQueue->last = 0;
}

int enqueue(QUEUE* pQueue, int value) {
  // arrayにMAX_LENGTHまでvalueが入るとlastはarrayの先頭に戻る
  // つまりarrayがfullのときfirst == lastになる
  if ((pQueue->last+1) % MAX_LENGTH == pQueue->first) {
    return 0;
  }
  pQueue->array[pQueue->last] = value;
  pQueue->last = (pQueue->last+1) % MAX_LENGTH;
  return 1;
}

int dequeue(QUEUE* pQueue, int* value) {
  if (pQueue->first == pQueue->last) {
    return 0;
  }
  *value = pQueue->array[pQueue->first];
  pQueue->first = (pQueue->first+1) % MAX_LENGTH;
  return 1;
}