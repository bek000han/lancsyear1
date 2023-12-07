#include<stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *prev;
};

struct element *top = NULL;

int pop() {
  if (top == NULL)
    return -1;

  int popData = top->data;
  top = top->prev;

  return popData;
}

void push(int data) {
  struct element *el = (struct element*)malloc(sizeof(struct element));
  el->data = data;

  el->prev = top;
  top = el;
}

/*
void printStack(){
  printf("\n Current stack elements: ");

  struct element *ptr = top;
  while (ptr != NULL)
    {
      printf("... %d", ptr->data);
      ptr->prev = ptr;
    }
  printf("\n");
}
*/

int main() {
  while(1){
    //printStack();
    printf("\n Enter operation: 1 for push, 2 for pop...");
    int op;
    scanf("%d", &op);
    switch(op){
    case 1:
      printf("\n Enter data...");
      int data;
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      printf("\n Popped %d \n", pop());
      break;
    default:
      return 0;
    }
  }
}

