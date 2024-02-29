#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int arr[10];

    for (int i = 0; i < 10; i++) 
    {
        arr[i] = rand() % 100;
    }

    int min = __INT32_MAX__;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < min) 
        {
            min = arr[i];
        }
    }

    for (int i = 0; i < 10; i++) 
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    printf("%d\n", min);
}