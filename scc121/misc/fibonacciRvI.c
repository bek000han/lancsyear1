#include <stdio.h>
long fibonacci(int n);
long fibonacciRec(int n);

int main(){
    int n;
    printf("Enter number of index: ");
    scanf("%d", &n);

    printf("Iterative: Number at index %d of fibonacci is %d\n", n, fibonacci(n));
    printf("Recursive: Number at index %d of fibonacci is %d\n", n, fibonacciRec(n));
}

long fibonacci(int n){
    if (n <= 1)
        return n;

    long arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n + 1; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

long fibonacciRec(int n){
    if (n <= 1)
        return n;
    
    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}
