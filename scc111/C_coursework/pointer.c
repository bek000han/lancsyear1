#include <stdio.h>
void changeY(int x, int *p);

int main()
{
    int x = 5;
    int y = 6;

    int *p = &y;

    changeY(x, p);

    printf("%d", y);
}

void changeY(int x, int *p)
{
    printf("%p\n", p);
    *p = x;
}