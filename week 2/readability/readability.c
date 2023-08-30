#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    string userInput = get_string("Text: ");
    float cl = count_letters(userInput);
    printf("count_letters: %f\n", cl);

    float cw = count_words(userInput);
    printf("count_words: %f\n", cw);

    float cs = count_sentences(userInput);
    printf("count_sentences: %f\n", cs);

    float L = (cl / cw) * 100;
    printf("L = %f\n", L);
    float S = (cs / cw) * 100;
    printf("S = %f\n", S);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int Grade = round(index);
    if (index > 16.0)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", Grade);
    }
}

float count_letters(string text)
{
    float count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            count++;
        }
    }
    return count;
}

float count_words(string text)
{
    float count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

float count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}