#include <stdio.h>

#define MAX_LENGTH 100

typedef struct {
  int array[MAX_LENGTH];
  int current;
}STACK;

void init(STACK*);
int push(STACK*, int);
int pop(STACK*, int*);

int main() {
  STACK s;
  int value;
  init(&s);
  push(&s, 1);
  push(&s, 2);
  push(&s, 3);

  while(pop(&s, &value)) {
    printf("%d ", value);
  }
  printf("\n");
  return 0;
}

void init(STACK* pStack) {
  int i;
  for(i = 0; i < MAX_LENGTH; i++) {
    pStack->array[i] = 0;
  }
  pStack->current = 0;
}

int push(STACK* pStack, int value) {
  if (pStack->current < MAX_LENGTH) {
    pStack->array[pStack->current] = value;
    pStack->current++;
    return 1;
  }
  return 0;
}

int pop(STACK* pStack, int* value) {
  if (pStack->current > 0) {
    pStack->current--;
    *value = pStack->array[pStack->current];
    return 1;
  }
  return 0;
}