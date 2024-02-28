#include <stdio.h>

void print(int *val){
    printf("%d\n", *val);
}

int main(){
    int val = 1;

    int *ptr1 = &val;

    int **ptr2 = &ptr1;

    int ***ptr3 = &ptr2;

    printf("dereferenced ptr1: %d\n", *ptr1);
    printf("address of ptr1: %p\n", &ptr1);
    printf("dereferenced ptr2: %p\n", ptr2);
    printf("address of ptr2: %p\n", &ptr2);
    printf("dereferenced ptr3: %p\n", ptr3);
    printf("address of ptr3: %p\n", &ptr3);
    print(val);
}