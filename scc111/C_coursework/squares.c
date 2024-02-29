#include <stdio.h>

int main() 
{
    int length = 0;
    scanf("%i", &length);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}