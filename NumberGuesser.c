#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int guess = 0;
int guesses = 0;
int answer = 0;
int turns = 5;
void displayResult();

int main()
{

    char keepPlaying = ' ';

    srand(time(0));
    answer = (rand() % 100 - 1);

    do
    {

        do
        {
            printf("\nGuess a number (1-100): ");
            scanf("%d", &guess);
            if (guess > answer)
            {
                printf("\nGuessed too high!");
            }
            else if (guess < answer)
            {
                printf("\nGuessed too low!");
            }
            else
            {
                break;
            }
            turns--;
            printf("\n%d/5 chances remaining", turns);
        } while (turns > 0);
        displayResult();
        printf("\nDo you want to continue? (Y/N): ");
        scanf("%c");
        scanf("%c", &keepPlaying);
        keepPlaying = toupper(keepPlaying);
        turns = 5;
    } while (keepPlaying == ' ' || keepPlaying == 'Y');
    printf("Thanks for playing");

    return 0;
}
void displayResult()
{
    if (answer == guess)
    {
        printf("\n******************************************");
        printf("\nCongratulations! the number was %d", answer);
        printf("\n******************************************");
    }
    else
    {
        printf("\nBetter luck next time!");
    }
}