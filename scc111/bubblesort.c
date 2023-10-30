#include <stdio.h>

int main()
{   
    int scores[] = {4,6,7,1,8,3,5,10,9,2};
    for (int i = 10; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (scores[j - 1] > scores[j])
            {
                int swap = scores[j - 1];
                scores[j - 1] = scores[j];
                scores[j] = swap;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (i < 9)
        {
            printf(" %d - %d\n",i + 1, scores[i]);
        }
        else
        {
            printf("%d - %d\n",i + 1, scores[i]);
        }
    }
}