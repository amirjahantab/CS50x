#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("start size: ");
    }
    while (startSize < 9);
    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("end size: ");
    }
    while (endSize < startSize);
    // TODO: Calculate number of years until we reach threshold

    int new_llamas_Born;
    int llamas_pass_away;
    int count = 0;
    while (startSize < endSize)
    {
        new_llamas_Born = startSize / 3;
        llamas_pass_away = startSize / 4;
        startSize += new_llamas_Born - llamas_pass_away;
        count++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", count);
}
