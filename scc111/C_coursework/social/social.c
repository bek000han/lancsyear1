#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "miniset.h"

int is_reflexive(int set[])
{
    int count = 0;
    for (int i = 0; i < MAX_SET && set[i] >= 0; i++)
    {
        if (in_set(set, set[i], set[i]))
        {
            count++;
        }
    }
    printf("countreflexive = %d\n", count);
    if (count == num_elements(set) * 2)
    {
        return 1;
    }
    return 0;
}

int is_symmetric(int set[])
{
    int count = 0;
    for (int i = 0; i < MAX_SET && set[i] >= 0; i += 2)
    {
        if (in_set(set, set[i + 1], set[i]))
        {
            printf("in_set(%d,%d) = %d\n", set[i + 1], set[i], in_set(set, set[i + 1], set[i]));
            count++;
        }
    }
    printf("countsymmetric = %d\n", count);
    if (count == num_elements(set))
    {
        return 1;
    }
    return 0;
}

int is_transitive(int set[])
{
    return FALSE;
}

int main()
{
    int set[MAX_SET];

    init_set(set);

    add_to_set(set, 2, 1);
    add_to_set(set, 1, 2);
    add_to_set(set, 1, 1);
    add_to_set(set, 2, 2);

    print_set(set);

    printf("num_elements = %d\n", num_elements(set));
    printf("in_set(1,1) = %d\n", in_set(set, 1, 1));
    printf("reflexive = %d\n", is_reflexive(set));
    printf("symmetric = %d\n", is_symmetric(set));

    return EXIT_SUCCESS;
}