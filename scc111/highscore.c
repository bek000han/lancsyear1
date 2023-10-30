#include <stdio.h>
#include <stdbool.h>

int askInput();
void printScores(int scores[]);
void sortScores (int scores[]);
int smallest(int scores[]);

int main()
{
    int input = 1;
    int scores[] = {0,0,0,0,0,0,0,0,0,0};
    int pos = 0;
    while (input != 0 && pos < 10)
    {
        input = askInput();
        if (input != 0)
        {
            scores[pos] = input;
            pos++;
            sortScores(scores);
            printScores(scores);
        }
    }
    printf("Highest score:%d \n", scores[0]);
    printf("Lowest score:%d \n", smallest(scores));
    
}

int askInput()
{
    int input;
    printf("Enter high score (0 to exit): ");
    scanf("%d", &input);
    return input;
}

void printScores(int scores[])
{
    printf("*** HIGH SCORE TABLE ***\n");
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

void sortScores (int scores[])
{
    for (int i = 10; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (scores[j - 1] < scores[j])
            {
                int swap = scores[j - 1];
                scores[j - 1] = scores[j];
                scores[j] = swap;
            }
        }
    }
}

int smallest(int scores[])
{
    int smallest = __INT32_MAX__;
    for (int i = 0; i < 10; i++)
    {
        if (scores[i] < smallest && scores[i] > 0)
        {
            smallest = scores[i];
        }
    }

    return smallest;
}