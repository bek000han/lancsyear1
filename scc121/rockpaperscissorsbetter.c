#include <stdio.h>

#define R 0
#define P 1
#define S 2

#define W 1
#define L -1
#define T 0

#define CHOICES 3

int results[CHOICES][CHOICES] ={{T,L,W}, {W,T,L}, {L,W,T}};
char *convertResults[] = {"Loss", "Tie", "Win"};

int main()
{
    int p1 = R;
    int p2 = S;

    printf("Match result: %s", convertResults[++results[p1][p2]]);
}