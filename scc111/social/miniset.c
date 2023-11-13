#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SET 20
#define FALSE 0
#define TRUE 1

void init_set(int set[])
{
    for (int i = 0; i < MAX_SET; i++)
        set[i] = -1;
}

int in_set(int set[], int a, int b)
{
    int i;

    for (i = 0; i < MAX_SET && set[i] >= 0 &&
                (set[i] != a || set[i + 1] != b);
         i += 2)
        ;

    return i < MAX_SET && set[i] >= 0;
}

int add_to_set(int set[], int a, int b)
{
    if (!in_set(set, a, b))
    {
        int i;

        for (i = 0; i < MAX_SET && set[i] >= 0; i++)
            ;

        if (i < MAX_SET)
        {
            set[i] = a;
            set[i + 1] = b;

            return TRUE;
        }
    }

    return FALSE;
}

int remove_from_set(int set[], int a, int b)
{
    int i;

    for (i = 0; i < MAX_SET && set[i] >= 0 &&
                (set[i] != a || set[i + 1] != b);
         i += 2)
        ;

    if (i < MAX_SET && set[i] >= 0)
    {
        // Shuffle remaining array down

        for (; i < MAX_SET - 2 && set[i + 2] >= 0; i += 2)
        {
            set[i] = set[i + 2];
            set[i + 1] = set[i + 3];
        }

        // Fill with -1 end of set markers

        set[i] = set[i + 1] = -1;

        return TRUE;
    }

    return FALSE;
}

int num_elements(int set[])
{
    int numInSet = 0, i;

    for (i = 0; i < MAX_SET && set[i] >= 0; i += 2)
        numInSet += set[i] >= 0 ? 1 : 0;

    return numInSet;
}

void print_set(int set[])
{
    int first = TRUE;

    for (int i = 0; i < MAX_SET && set[i] >= 0; i += 2)
    {
        if (!first)
            printf(", ");
        else
            first = FALSE;
        
        printf("(%d,%d)", set[i], set[i + 1]);
    }
    
    printf("\n");
}