// Joshua Wood
// Project 1
// Dr. Boustique
// COP 3223
// 1/19/19


// Learning Outcomes:
// 1)Structure of a C program
// 2)#include and #define directives
// 3)Variablesand constants
// 4)Data Types
// 5)printf and scanf

// At Valence community college, a student must take exactly two courses(We’ll drop this constraint when we cover control structures). The purpose of this assignment is to construct a fee invoice for a student.This requires the input ofStudent’s id as an integer, the two course numbersas integersand the credit hours for each course.It costs 120.25 dollars per credit hour in addition to $35.00 charged forhealth and id services.After inputting all the necessary data (see sample run), a fee invoice as shown below should be printed to the screen.

// VALENCE COMMUNITY COLLEGE
// ORLANDO FL 10101
// *************************

// Fee Invoice Prepared for Student V56561

// 1 Credit Hour = $120.25
// CRN          CREDIT HOURS
// 4587         4                   $ 481.00
// 4599         3                   $ 360.75

//                 Health & id fees $  35.00
// -------------------------------------------
//                 Total Payments   $  876.75


//pre-processor directives
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Constants
	#define PRICE 120.25
        // Price is meant to symbolize the 120.25 dollars that comes with each credit hour
	
    	#define HEALTH 35.00
    	// Health is meant to symbolize the 35.00 dollar Heath and ID fee

	int student_ID;
    	// student_ID is the students ID number

    	int crn, crn_second;
    	// The crn is the class crn number the student must enter

    	int credit, credit_second;
    	// credit is the course credit that is given to the student (unique to the actual course taken)

   	float payment_without_fee, payment_without_fee_second;
    	// Payment without fee is the price without the added $120.00 and $35.00

    	float total;
    	// total is the price student has to pay after everything is added to it

	printf("Enter the Students Id: ");
	printf("\n");
	printf("\t");
	scanf("%d", &student_ID); // User input

	printf("Enter crn/credit hours for first course (like 2019/3) ");
	printf("\n");
	printf("\t");
	scanf("%d/%d", &crn, &credit); // User input *IMPORTANT* Make sure the user knows
                                // that they need to enter data in 2019/3 format

	printf("Enter crn/credit hours for Second course (like 2019/3) ");
	printf("\n");
	printf("\t");
	scanf("%d/%d", &crn_second, &credit_second); // User input

	printf("\n");

    	// PRINT fee invoice
	printf("Thank you!\n");

	printf("\n");

	printf("\t\tVALENCE COMMUNITY COLLEGE\n");
	printf("\t\tORLANDO FL 10101\n");
	printf("\t\t*************************\n");

	printf("\n");

	printf("\t\tFee Invoice Prepared for Student V%d\n", student_ID);

	printf("\n");

	printf("\t\t1 Credit Hour = $120.25\n");

	printf("\n");

	payment_without_fee = credit * PRICE; // Calulation for first course
	payment_without_fee_second = credit_second * PRICE; // calculation for second course

	printf("\t\tCRN\t\tCREDIT HOURS\n");
	printf("\t\t%d\t\t%d\t\t $ %.2f\n", crn, credit, payment_without_fee);
	printf("\t\t%d\t\t%d\t\t $ %.2f\n", crn_second, credit_second, payment_without_fee_second);

	printf("\n");

	printf("\t\t\t\tHealth & id fees $  35.00\n");

	printf("\n");

	printf("\t\t-----------------------------------------\n");

	total = payment_without_fee + payment_without_fee_second + HEALTH;
    	// Total fee invoice calculation

	printf("\t\t\t\tTotal Payments   $ %.2f\n", total);

	return 0;
}
