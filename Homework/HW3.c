// Joshua Wood
// Project 3
// Dr. Boustique
// COP 3223
// 2/07/19

// Write a program that prints a table converting milesto/from kilometers, exactly as shown in the sample run.
// Your code must demonstratethe use of a while and a for loop
// (have some of the code done using a while loop and the some other using the for loop)

// Note that: One Mile = 1.6 Kilometer.

//pre-processor directives
#include <stdio.h>
#include <stdlib.h>

// Main Function
int main()
{
	int amount;
	// Amount refers to the amount of conversions the user would
	// like to print

	int i;
	// i is a placement holder for amount that goes toward the for loop for kms

	int j = 1;
	// j is a placement holder for amount of that goes toward the for loop for miles

	float kms;
	// kms is meant for the actual amount that coressponds to kms after the coversion with 1.6 and i
	
	float miles;
	// miles is meant for the actual amount that coressponds to miles afte the conversion with .63 and j


	// Introduction
	printf("\n\n");
	printf("     Welcome to the distance converter program (miles <-> kms)\n");
	printf("***************************************************************************\n\n\n");

	printf("Enter how many conversions would you like to print (up to 99): ");
	scanf("%d", &amount); // User input for amount

	while (amount < 1 || amount > 99) // Keeps the user from not entering an amount over 99 or under 1
	{
		printf("Number out of range (1 to 99 lines)! Try again: ");
		scanf("%d", &amount);
	}

	printf("\n");
	printf("\t======================================================\n");

	for (i = amount; i > 0; i--)
	{
		kms = 1.6 * i; // converts miles to kms
		miles = .63 * j; // converts kms to miles

		if (j < 10) // This function helps with allignment
		{
			printf("\t| %d miles = %.2f km\t| \t%d km  =  %.2f miles  |\n", i, kms, j, miles);
			j ++;
		}

		else
		{
			printf("\t| %d miles = %.2f km\t| \t%d km =  %.2f miles  |\n", i, kms, j, miles);
			j ++;
		}
	}

	printf("\t======================================================\n");
	printf("\n\n");

	// Ending 
	printf("\t    Thankyou for choosing our conversion program!\n");
	printf("\n");

return 0;
}
