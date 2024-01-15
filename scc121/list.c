#include <stdio.h>

typedef struct element{
    int data;
    struct element *next;
    struct element *prev;
}element;

typedef struct list{
    element *head;
}list;

void add(list list, element e){
    e.next = list.head;

    if (list.head != NULL){
        list.head.prev = e;
    }
    list.head = e;
    e.prev = NULL;
}

list createList(){
    list list;
    list.head = NULL;
    return list;
}

int main(){
    list list = createList();
}

