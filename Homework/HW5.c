// Joshua Wood
// HW5
// Dr. Boustique
// COP 3223
// 3/5/19

// -----------------------------------------------------------------------------
// Write  a  C  program  that asks  the  user  to  enter  three  numbers(integres).
// A  menu  will  be displayed to let the user choose one of the three options:
// print the two highest numbers, product of the three numbers or the division of the second
// by the by the third if the third is not zero. See the sample runs.

// Required: Your code must use :
// - One function to get the numbers from the user
// - One function for each of the three options

// Add other functions as you see fit.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Pre-processor directives
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void number_input(int *, int *, int *);
  // Function that gains input from user for the three numbers they wish to work with
int display_menu(void);
  // Displays menu choices for user to choose from
int option_largest(int, int, int);
  // Function that finds the largest number
int option_second_largest(int, int, int);
  // Function that finds the second largest number
int option_product(int, int, int);
  // Function that multiplies three numbers to find the prodcut
float option_divison(int, int);
  // Function that divides the second and third number
void end();
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main()
{
 	int number_one = 0, number_two = 0, number_three = 0; // Numbers user wants to work with
	int choice; // Menu choice
	float result; // Result is a float meant for the division functon
  char *option, *keep; // option is for whether or not the user wants to keep using the same numbers or not ...
                       // keep is for whether or not the user wants to start a new set of numbers or end the program

  option = malloc (sizeof(char)); // Allocation
	keep = malloc (sizeof(char)); // Allocation

  *option = 'y'; // Must start with Y
  *keep = 'N'; // Must start with N

  while (*option == 'y' || *option == 'Y')
  {
    if (*keep == 'n' || *keep == 'N')
    {
      number_input(&number_one, &number_two, &number_three); // Number input
    }

    choice = display_menu(); // Displays options

	  switch (choice)
	  {
      case 1:

       printf("\n");
       printf("The two highest numbers are: %d and %d\n", option_largest(number_one, number_two, number_three), option_second_largest(number_one, number_two, number_three));

		   break;

		   case 2:

       printf("\n");
		   printf("%d times %d times %d = %d\n", number_one, number_two, number_three, option_product(number_one, number_two, number_three));

       break;

		   case 3:

       result = option_divison (number_two, number_three);

		   if (result == -1)
		   {
         printf("\n");
			   printf("Sorry cannot divide %d by 0!\n", number_two); // Warning in case user decides to divide by zero
		   }

		   else
		   {
         printf("\n");
         printf("%d divided by %d = %.2f\n", number_two, number_three, result);
       }

		   break;
     }

  printf("\n");
  printf("Would you like to keep working with %d, %d, and %d? y/Y or n/N: ", number_one, number_two, number_three);
  scanf(" %c", keep);

  while (*keep != 'y' && *keep != 'Y' && *keep != 'n' && *keep != 'N') // In case user tries to enter a wrong char character
  {
    printf("\n");
    printf("Sorry invalid entry! Please enter y/Y or n/N: ");
    scanf(" %c", keep);
    break;
  }

  if (*keep == 'n' || *keep == 'N') // If user chooses n/N for keep, then the user gets the option of starting over or restarting
  {
    printf("\n\n");
    printf("- - - - -\n");
    printf("Now, would you like to work with new numbers? Enter y/Y or n/N: ");
    scanf(" %c", option);

    if (*option == 'y' || *option == 'Y')
    {
      continue; // continue to the top
    }

    if (*option == 'n' || *option == 'N')
    {
      end(); // ends program
    }
  }
    else
		{
			continue; // continues to top of the program
		}
  }
  return 0;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// This function gets the three numbers the user wants to use
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void number_input (int *first_num, int *second_num, int *third_num)
{
  printf("\n");
  printf("Enter the three numbers: ");
  scanf("%d%d%d", first_num, second_num, third_num);
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// This function displays options for the user to choose
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int display_menu(void)
{
	int decision;

  printf("\n\n");

  printf("Choose from the following options:\n");

	printf("\n");
	printf("1, 2, or 3\n");
	printf("\t\t1 to print the two highest numbers\n");
	printf("\t\t2 to print the product of the three numbers\n");
	printf("\t\t3 to print the divison of the second number by the third\n");

	printf("\n");

  printf("Enter your selection: ");
	scanf("%d", &decision); // User Input

  while (decision != 1 && decision != 2 && decision != 3) // In case user enters a value greater than or less than 1, 2, or 3
  {
    printf("\n");
    printf("Sorry invalid option. Try again: ");
    scanf("%d", &decision);
  }

  return decision;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function to find largest value
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int option_largest (int n1, int n2, int n3)
{
  int largest;

  if (n1 >= n2 && n1 >= n3)
  {
    largest = n1;
  }

  if(n2 >= n1 && n2 >= n3)
  {
    largest = n2;
  }

  if(n3 >= n1 && n3 >= n2)
  {
    largest = n3;
  }

   return largest;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function to find second largest value
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int option_second_largest(int num1, int num2, int num3)
{
  int largest;
  int second_largest;

  if( num1 >= num2 && num1 >= num3 )
  {
    largest = num1;

    if (num2 >= num3)
    {
      second_largest = num2;
    }

    else
    {
      second_largest = num3;
    }

  }

  if( num2 >= num1 && num2 >= num3 )
  {
    largest = num2;

    if (num1 > num3)
    {
      second_largest = num1;
    }

    else
    {
      second_largest = num3;
    }
  }

  if( num3 >= num1 && num3 >= num2 )
  {
    largest = num3;

     if (num1 > num2)
     {
       second_largest = num1;
     }

     else
     {
       second_largest = num2;
     }
  }

  return second_largest;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function to find the product of three numbers
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int option_product(int one, int two, int three)
{
	int product;
	product = one * two * three;

	return product;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function to divide the second number by the third numbers
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
float option_divison(int second, int third)
{
	if (third == 0) return -1;
	else return(float) second / third;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Ends program
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void end()
{
  printf("\n");
  printf("Sad to see you go but don’t forget to submit your .c file and on time!\n\n");
}
