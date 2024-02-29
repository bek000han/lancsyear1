#include <stdio.h>
#include <unistd.h>

int main() 
{
    for (int i = 1; i <= 3; i++) 
    {
        printf("%d\n", i);
        sleep(1);
    }
    printf("Go!");
}