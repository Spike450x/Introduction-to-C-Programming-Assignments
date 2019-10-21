// Joshua Wood
// HW4
// Dr. Boustique
// COP 3223
// 2/17/19

// Write  a  C  program  that asks  the  user  to  enter  three  numbers(integres).
// A  menu  will  be displayed to let the user choose one of the three options:
// show the sum of the two highest numbers, product of the three numbers, or the largest of the three numbers.

// Required: Your code must use pointers ONLY!
// Consequently, the function malloc should be used to allocate memory spaces for the user’s input and possibly for other data.

//pre-processor directives
#include <stdio.h>
#include <stdlib.h>

// Main Function
int main()
{
	int *pointer1, *pointer2, *pointer3, *choice;

	// *pointer1, *pointer2, and *pointer3 represent the values the user enters. *Choice represents which selection (1, 2, or 3)
	// that the user wants to choose

	float *answer;

	// *answer is used for a couple different outcomes ... *answer is used when to find the product of three numbers, to find
	// the answer to *pointer2 / *pointer3, and it is used to find the highest two numbers

	char *option, *keep;

	// *option is used at the end when the user decides if they either want to choose a new set of numbers or to leave the program
	// *keep is used when the user decides to keep the previously set values or to move on to either the end of the program
	// or to choose a new set of numbers

	// This allocates memory for the user's input and other data
	// *malloc is essential*
	pointer1 = malloc (sizeof(int));
	pointer2 = malloc (sizeof(int));
	pointer3 = malloc (sizeof(int));
	choice = malloc (sizeof(int));
	answer = malloc (2*sizeof (int));

	option = malloc (sizeof(char));
	keep = malloc (sizeof(char));

	// These need to be previously set so the function can start its initial run through
	*option = 'y';
	*keep = 'N';

	while (*option == 'y' || *option == 'Y')
	{
		if (*keep == 'n' || *keep == 'N')
		{
			printf("\n\n");
			printf("Enter the three numbers: ");
			scanf("%d %d %d", pointer1, pointer2, pointer3); // Users input (ONLY three numbers)
		}
		printf("\n");

		printf("Choose from the following options:\n");

		printf("\n");

		// This is the list of options for the user to make ...
		printf("1, 2 or 3?\n");
		printf("\t1 to print the two highest numbers\n");
		printf("\t2 to print product of the three numbers\n");
		printf("\t3 to print the divison of the second number by the third\n");

		printf("\n");

		printf("Enter your selection: ");
		scanf("%d", choice); // User input for which choice to make (either 1, 2, or 3)

		while (*choice != 1 && *choice != 2 && *choice != 3) // In case user enters a value greater than or less than 1, 2, or 3
		{
			printf("\n");
			printf("Sorry invalid option. Try again: ");
			scanf("%d", choice);
			break;
		}

		switch(*choice)
		{
			case 1: // Case one determines which two numbers are the highest and then prints them for the user to see

			if (*pointer1 > *pointer2)
			{
				*answer = *pointer1;
				answer++;

				if (*pointer2 > *pointer3)
				{
					*answer = *pointer2;
				}
				if (*pointer3 > *pointer2)
				{
					*answer = *pointer3;
				}
			}

			else if (*pointer1 < *pointer2)
			{
				*answer = *pointer2;
				answer++;

				if (*pointer1 > *pointer3)
				{
					*answer = *pointer1;
				}

				if (*pointer1 < *pointer3)
				{
					*answer = *pointer3;
				}
			}

			printf("\n\n");
			printf("The two highest numbers are: %.0f and", *answer);
			answer--;
			printf(" %.0f\n", *answer);
			printf("\n");
			break;

			case 2: // Case two multiplies all three numbers and prints the solution for the user

			*answer = *pointer1 * *pointer2 * *pointer3;
			printf("\n\n");
			printf("%d times %d times %d = %.0f\n", *pointer1, *pointer2, *pointer3, *answer);
			break;

			case 3: // Case three divides *pointer 2 by *pointer 3

			if (*pointer3 == 0) // NO NUMBER can be divided by zero ... if user enters 0 as their *pointer3, option 3 cannot be used
			{
				printf("\n");
				printf("Sorry cannot %d divide by zero!\n", *pointer2);
			}

			else // Divides *pointer2 and *pointer3
			{
				*answer = *pointer2 / *pointer3;

				printf("\n\n");
				printf("%d divided by %d = %.2f\n", *pointer2, *pointer3, *answer);
				break;
			}
		}

		printf("\n");
		printf("Would you like to keep working with %d, %d, and %d? y/Y or n/N: ", *pointer1, *pointer2, *pointer3);
		scanf(" %c", keep); // Gives the user a chance to work with new numbers or not ... if user chooses y/Y, the program Starts
												// from the top. If the user chooses n/N, the program keeps going

		while (*keep != 'y' && *keep != 'Y' && *keep!= 'n' && *keep != 'N') // In case user tries to enter a wrong char character
		{
			printf("\n");
			printf("Sorry invalid entry! Please enter y/Y or n/N: ");
			scanf(" %c", keep);
			break;
		}

		if (*keep == 'n' || *keep == 'N') // If user chooses n/N for *keep, then the user gets the option of starting over or restarting
		{
			printf("\n\n");
			printf("- - - - -\n");
			printf("Now, would you like to work with new numbers? Enter y/Y or n/N: ");
			scanf(" %c", option);

			if (*option == 'y' || *option == 'Y')
			{
				continue; // continue to the top
			}
			if (*option == 'n' || *option == 'N') // Ends program!
			{
				printf("\n\n");
				printf("Sad to see you go but don't forget to submit your .c file and on time!\n");
				break;
			}
		}

		else
		{
			continue;
		}
	}
return 0;
}
