#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() 
{
    char *strp = "charp";
    char stra[] = "chara";
    char *strm = (char *) malloc(sizeof(char) * 100);
    strm = "charm";

    printf("%s\n", strp);
    printf("%s\n", stra);
    printf("%s", strm);
}