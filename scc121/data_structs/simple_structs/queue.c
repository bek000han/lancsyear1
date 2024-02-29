#include<stdio.h>
#include <stdlib.h>

struct element {
  int data;
  struct element *next;
};

struct element *head = NULL;

void enqueue(int data);
int dequeue();
void printQueue();

//free(el);
int dequeue() {
    if (head == NULL)
    {
        printf("No elements in queue to dequeue.\n");
        return 0;
    }
    struct element *tmp = head;
    int data = tmp->data;
    head = head->next;
    free(tmp);
    return data;
}

//struct element *el = (struct element*)malloc(sizeof(struct element));
void enqueue(int data) {
    struct element *el = (struct element*)malloc(sizeof(struct element));
    el->data = data;
    el->next = NULL;
    
    if (head == NULL)
    {
        head = el;
    }
    else
    {
        struct element *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = el;
    }
}

void printQueue(){
  struct element *tmp = head;
  printf("The resulting queue is...");
  while(NULL!=tmp) {
    printf("%d...",tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  while(1){
    printf("\n Enter operation: 1 for enqueue, 2 for dequeue...");
    int op;
    scanf("%d", &op);
    switch(op){
        case 1:
            printf("\n Enter data...");
            int data;
            scanf("%d", &data);
            enqueue(data);
            printQueue();
            break;
        case 2:
            data = dequeue();
            if(-1 != data){
                printf("Dequeued %d\n", data);
            }
            else{
                printf("Queue empty\n");
            }
            printQueue();
            break;
        default:
            return 0;
    }
  }
}
