#include "encryptionfuncs.h"

int main()
{
    FILE *fpr = fopen("plain.txt", "r");
    FILE *fpw = fopen("cipher.txt", "w");

    if (fpr == NULL)
    {
        printf("File doesn't exist");
        return 0;
    }

    printf("Which encryption algorithm to apply? (input corresponding index)\n1: Vowels to numbers\n2: Remove all vowels\n3: Caesar cipher\nUser input: ");
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

