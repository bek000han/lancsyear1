#include <stdio.h>

int calc();
int permission();
int add(int first, int second);
int subtract(int first, int second);
int multiply(int first, int second);
int divide(int first, int second);

int main()
{
    int go = permission();
    int result;

    while (go != 0)
    {
        result = calc();
        printf("Result: %i\n\n", result);
        go = permission();
    }

    printf("Thanks for using the program,\nHave a nice day!");
}

int calc()
{
    int first;
    int second;
    int oprt;
    printf("Enter first number: \n");
    scanf("%d", &first);
    printf("Enter second number: \n");
    scanf("%d", &second);
    printf("Enter operator:\n  1: add\n  2: sub\n  3: mult\n  4: div \n");
    scanf("%d", &oprt);

    switch (oprt)
    {
    case 1:
        return add(first, second);
    case 2:
        return subtract(first, second);
    case 3:
        return multiply(first, second);
    case 4:
        return divide(first, second);    
    default:
        return 0;
    }

    return 0;
}

int permission()
{
    int perm;
    printf("Perform calculation?\n  1: Yes\n  0: No\n");
    scanf("%d", &perm);
    return perm;
}

int add(int first, int second)
{
    return first + second;   
}

int subtract(int first, int second)
{
    return first - second;   
}

int multiply(int first, int second)
{
    return first * second;   
}

int divide(int first, int second)
{
    return first / second;   
}