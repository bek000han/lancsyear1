#include <stdio.h>

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

