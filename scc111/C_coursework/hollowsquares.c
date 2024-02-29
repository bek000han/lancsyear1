#include <stdio.h>

int main() 
{
    int length = 0;
    int mid = 0;
    scanf("%i", &length);
    mid = (length / 2);

    for (int i = 0; i < length; i++)
    {
        if (i != mid)
        {
            for (int j = 0; j < length; j++)
            {
                printf("*");
            }
        } 
        else 
        {
            for (int j = 0; j < length; j++)
            {
                if (j != mid)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}