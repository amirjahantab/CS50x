#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int len = strlen(argv[1]);
    for (int i = 0 ; i < len ; i++)
    {
        char ch = argv[1][i];
        if (!isalpha(ch))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    string key = argv[1];
    string txt = get_string("plaintext:  ");
    printf("ciphertext: ");

    int value;
    for (int i = 0 ; i < strlen(txt) ; i++)
    {
        char counter = txt[i];

        if (isalpha(counter) && isupper(counter))
        {
            value = counter - 'A';
            char temp = toupper(argv[1][value]);
            printf("%c", temp);
        }
        else if (isalpha(counter) && islower(counter))
        {
            value = counter - 'a';
            char temp = tolower(argv[1][value]);
            printf("%c", temp);
        }
        else if (!isalpha(counter))
        {
            printf("%c", counter);
        }


    }
    printf("\n");
}