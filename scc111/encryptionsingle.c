#include <stdio.h>
#include <stdlib.h>

int vowels_to_numbers(FILE *plain, FILE *cipher);

int remove_vowels(FILE *plain, FILE *cipher);

int caesar_cipher(FILE *plain, FILE *cipher);

int main()
{
    FILE *fpr = fopen("plain.txt", "r");
    FILE *fpw = fopen("cipher.txt", "w");

    if (fpr == NULL)
    {
        printf("File doesn't exist");
        return 0;
    }

    printf("Which encryption algorithm to apply? (enter corresponding index)\n1: Vowels to numbers\n2: Remove all vowels\n3: Caesar cipher\nUser input: ");
    int functionIndex;
    scanf("%d", &functionIndex);

    switch (functionIndex)
    {
        case 1:
            vowels_to_numbers(fpr, fpw);
            printf("Text encrypted!\nFile saved as 'cipher.txt'\n");
            break;
        case 2:
            remove_vowels(fpr, fpw);
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


int vowels_to_numbers(FILE *plain, FILE *cipher)
{
    int c;
    while((c = getc(plain)) != EOF)
    {
        switch (c)
        {
            case 'a':
                c = '2';
                break;
            case 'e':
                c = '3';
                break;
            case 'i':
                c = '1';
                break;
            case 'o':
                c = '0';
                break;
            case 'u':
                c = '4';
                break;
            default:
                break;
        }

        putc(c, cipher);
    }
}

int remove_vowels(FILE *plain, FILE *cipher)
{
    int c;
    while((c = getc(plain)) != EOF)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            continue;

        putc(c, cipher);
    }
}

int caesar_cipher(FILE *plain, FILE *cipher)
{
    int c;
    while((c = getc(plain)) != EOF)
    {
        if (c >= 96 && c <= 121)
            c++;
        if (c == 122)
            c = 96;

        putc(c, cipher);
    }
}

