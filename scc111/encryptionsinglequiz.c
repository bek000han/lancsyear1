#include <stdio.h>
#include <stdlib.h>

int letters_to_numbers(FILE *plain, FILE *cipher);
int remove_letters(FILE *plain, FILE *cipher);
int caesar_cipher(FILE *plain, FILE *cipher);
int fileNull(FILE *fpr);

int main()
{
    FILE *fpr = fopen("plain.txt", "r");
    FILE *fpw = fopen("cipher.txt", "w");

    if (!fileNull(fpr))
        return(0);

    printf("Which encryption algorithm to apply? (enter corresponding index)\n1: Vowels to numbers\n2: Remove all vowels\n3: Caesar cipher\nUser input: ");
    int functionIndex;
    scanf("%d", &functionIndex);

    switch (functionIndex)
    {
        case 1:
            letters_to_numbers(fpr, fpw);
            printf("Text encrypted!\nFile saved as 'cipher.txt'\n");
            break;
        case 2:
            remove_letters(fpr, fpw);
            printf("Text encrypted!\nFile saved as 'cipher.txt'\n");
            break;
        case 3:
            caesar_cipher(fpr, fpw);
            printf("Text encrypted!\nFile saved as 'cipher.txt'\n");
            break;
        default:
            printf("Incorrect input.");
            break;
    }

    fclose(fpr),(fpw);
}

int fileNull(FILE *fpr)
{
    if (fpr == NULL)
    {
        printf("File doesn't exist");
        return 0;
    }
    return 1;
}

int letters_to_numbers(FILE *plain, FILE *cipher)
{
    int c;
    while((c = getc(plain)) != EOF)
    {
        switch (c)
        {
            case 'l':
                c = '1';
                break;
            case 'e':
                c = '3';
                break;
            case 't':
                c = '7';
                break;
            case 'a':
                c = '4';
                break;
            case 's':
                c = '5';
                break;
            default:
                break;
        }
        putc(c, cipher);
    }
    return 1;
}

int remove_letters(FILE *plain, FILE *cipher)
{
    int c;
    while((c = getc(plain)) != EOF)
    {
        if (c == 's' || c == 't' || c == 'o' || c == 'p' || c == 'q')
            continue;

        putc(c, cipher);
    }
    return 1;
}

int caesar_cipher(FILE *plain, FILE *cipher)
{
    if (plain == NULL)
        return 0;
    
    int c;
    while((c = getc(plain)) != EOF)
    {
        if (c >= 96 && c <= 121)
        {
            c--;
        }
        if (c == 95)
        {
            c = 121;
        }

        putc(c, cipher);
    }
    return 1;
}

