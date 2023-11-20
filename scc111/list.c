#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int age;
};

void updateList (struct student input, struct student list[], int *ptr)
{
    list[*ptr] = input;
    *ptr++;
}

int main()
{
    struct student aStudent = {"Jim", 15};
    struct student list[10];

    int indices = 0;
    int *iptr = &indices;

    updateList(aStudent, list, iptr);

    printf("%s %d\n", list[0].name, list[0].age);
}

