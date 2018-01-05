#include <stdio.h>
#include <stdlib.h>

typedef struct tagListNode {
  struct tagListNode *prev;
  struct tagListNode *next;
  int data;
} ListNode;

// リスト
int main() {
  int buf, sum;
  ListNode *firstnode, *lastnode, *newnode, *thisnode, *removenode;
  firstnode = lastnode = NULL;

  do {
    scanf("%d", &buf);
    if (buf) {
      newnode = (ListNode*)malloc(sizeof(ListNode));
      newnode->data = buf;
      newnode->next = NULL;

      if (lastnode != NULL) {
        lastnode->next = newnode;
        newnode->prev = lastnode;
        lastnode = newnode;
      } else {
        firstnode = lastnode = newnode;
        newnode->prev = newnode;
      }
    }
  } while(buf != 0);

  // Listのループ
  for(thisnode = firstnode; thisnode != NULL; thisnode = thisnode->next) {
    printf("data: %d\n", thisnode->data);
  }

  // 削除
  for(thisnode = firstnode; thisnode != NULL;) {
    removenode = thisnode;
    thisnode = thisnode->next;
    free(thisnode);
  }
  return 0;
}