// Write a C program that asks the user to guess a number between 1 and 15 (1 and 15 are included). The user is given three trials.

// pre-processor directives.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main Function
int main()
{
    // Variables
    char city[100] = "Orlando"; // String that user is trying to guess
    char city_guess[100]; // Users guess (input)

    // Introduction
    printf("\n");
    printf("Guess my favorite Florida city: ");
    gets(city_guess);

    if (strcasecmp(city, city_guess) == 0) printf ("That's the one!\n"); // If user input matches the random number
    else
    {
        printf("No! Try again: ");
        gets(city_guess);

        if (strcasecmp(city, city_guess) == 0) printf ("That's the one!\n"); // If the guess matches the random number
        else
        {
            printf ("No! Try again: ");
            gets(city_guess);

            if (strcasecmp(city, city_guess) == 0) printf ("That's the one!\n"); // If the guess matches the random number
            else
            {
                printf ("No! Try again: ");
                gets(city_guess);

                if (strcasecmp(city, city_guess) == 0) printf ("That's the one!\n"); // If the guess matches the random number
                else
                {
                    printf("\nSorry-my favorite Florida City is %s\n", city);
                }
            }
        }
    }
    return 0;
}
