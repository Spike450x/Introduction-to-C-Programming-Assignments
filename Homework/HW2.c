// Joshua Wood
// Project 3
// Dr. Boustique
// COP 3223
// 1/27/19

// Write a C program that asks the user to guess a number between 1 and 15 (1 and 15 are included). The user is given three trials.

// pre-processor directives.
#include <stdio.h>
#include <stdlib.h>

// Main Function
int main()
{
	// Variables

	int guess; // Guess from user input
    	int random = 8; // Number user is trying to guess

	// Introduction

	printf("\n");
	printf("Welcome to the guess-a-number-game!\n");
    	printf("I'm thinking of a number between 1 and 15! What is it? ");
    	scanf("%d", &guess);

	if (guess > 15 || guess < 1) // If user enters invalid input
	{
		printf("Error!! Invalid Entry! Please try again!\n");
	}

	else if (guess == random) printf ("That's right!\n"); // If user input matches the random number
    		else
    		{
			if (guess > random) printf ("No, try something lower: ");
            		// If user input is greater than random number
      				else printf ("No, try something higher: ");
            			// If user input is lower than random number

      				scanf("%d", &guess);

			if (guess == random) printf ("That's right!\n");
            		// If the guess matches the random number
        			else
       				 {
					if (guess > random) printf ("No, try something lower: ");
                   			 // second guess is too high
          					else printf ("No, try something higher: ");
            					// second guess it too low

          					scanf("%d", &guess);

			if (guess == random) printf ("That's right!\n");
		        	else
		        	{
		         		printf ("Sorry-you missed it! It was %d\n", random);
                			// If you miss all three attempts 
				}
    			}
		}
return 0;
}
