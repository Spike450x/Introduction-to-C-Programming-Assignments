// Joshua Wood
// Project 3
// Dr. Boustique
// COP 3223
// 1/27/19

// Learning Outcomes:
// 1)Operators
// 2)if/else statements
// 3)switchstructure

// At Valence community college, a student cantake up totwo courses. The purpose of this assignment is to construct a fee invoice for a student.This requires the input ofStudent’s id as an integerand (up to) the two course numbersas integers.It costs 120.25 dollars per credit hour in addition to $35.00 charged forhealth and id services.Here isthe list of all courses offered at Valence Community College:

//    CRN       Course Prefix       Credit Hours
//    4587      MAT 236             4
//    4599      COP 220             3
//    8997      GOL 124             1
//    9696      COP 100             3

// pre-processor directives.
#include <stdio.h>


// Main Function
int main()
{
	// Constants
   	#define PRICE 120.25
	#define HEALTH 35.00
    
    
    
    	// Variables:
	// student_id = Student number
	// courses_taken = number of courses taken by the student
	// crn1 and crn2 = course numbers
	// credit1 and credit2 = credit gained by courses taken
	// invalid_input = Variable to exit program if input is invalid

	int student_id, courses_taken, crn1, crn2, credit1, credit2;
   	float payment_without_fee, payment_without_fee2, total;
    	int invalid_input = 0;
    
    	// Introduction
	printf("\n");
	printf("Enter the Students Id:\n");
	printf("\t");
    	scanf("%d", &student_id); // User input for students id

	printf("\n");

    	printf("Enter how may courses taken (up to 2):\n");
	printf("\t");
	scanf("%d", &courses_taken); // User input for courses taken

  	if (courses_taken > 2 || courses_taken < 0) // If statement for an invalid entry
	{
		printf("\n");
		printf("Sorry, we can't process your request this time-invalid number of courses.\n");
		printf("\n\n");
		printf("\t\t\tTry again. Goodbye!\n");
		printf("\n\n");
  	}

  	else if (courses_taken == 0) // if statement for a student that is not taking any classes
	{
		printf("\n");
		printf("Thank you!\n");

		// Fee Invoice for no courses

		printf("\n");
		printf("\t\tVALENCE COMMUNITY COLLEGE\n");
		printf("\t\tORLANDO FL 10101\n");
		printf("\t\t*************************\n");

		printf("\n");

		printf("\t\tFee Invoice Prepared for Student V%d\n", student_id);

		printf("\n");

		printf("\t\t\t    Health & id fees  $  35.00\n");

		printf("\n");

		printf("\t\t--------------------------------------\n");

		total = HEALTH;

		printf("\t\t\t    Total Payments    $  %.2f\n", total);

	 	printf("\n");

 	}

	else if (courses_taken == 1) // if statment for a student with one course
	{
		printf("\n\n");
		printf("Enter the course number:\n");
		printf("\t");
	 	scanf("%d", &crn1); // input for credit hours earned

     		switch (crn1) // Credit hour options
     		{
        	 	case 4587: credit1 = 4;
         	 	break;

         	 	case 4599: credit1 = 3;
         	 	break;

	 	 	case 8997: credit1 = 1;
	 	 	break;

	 	 	case 9696: credit1 = 3;
	 	 	break;

	 	 	default: invalid_input = 1;
     		}

     if (invalid_input == 1) // Invalid entry
     {
		printf("\n");
		printf ("Sorry invalid entry!\n");
		printf("\n\n\t\t\tTry again. Goodbye!\n\n");
     }

     else
     {
   		// Fee Invoice for one course

		printf("\n");
		printf("Thank you!\n");

		printf("\n");
		printf("\t\tVALENCE COMMUNITY COLLEGE\n");
		printf("\t\tORLANDO FL 10101\n");
		printf("\t\t*************************\n");

		printf("\n");

		printf("\t\tFee Invoice Prepared for Student V%d\n", student_id);

		printf("\n");

		printf("\t\t1 Credit Hour = $120.25\n");
	
		printf("\n");

		payment_without_fee = credit1 * PRICE;

		printf("\t\tCRN\t\tCREDIT HOURS\n");
		printf("\t\t%d\t\t%d\t\t $ %.2f\n", crn1, credit1, payment_without_fee);

		printf("\n");

		printf("\t\t\t\tHealth & id fees $  35.00\n");

		printf("\n");

		printf("\t\t-----------------------------------------\n");

		total = payment_without_fee + HEALTH;

		printf("\t\t\t\tTotal Payments   $ %.2f\n", total);

		return 0;
     	}
  }
    else
    {
		printf("\n\n");
		printf ("Enter the two course numbers seperated by - : (like 2356-8954)\n");
		printf("\t");
		scanf("%d-%d", &crn1, &crn2); // Input for two courses

   		switch (crn1) // Credit hours options
       		{
          	 	case 4587: credit1 = 4;
         		break;

          		case 4599: credit1 = 3;
          		break;

	  		case 8997: credit1 = 1;
	  		break;

	  		case 9696: credit1 = 3;

          		default: invalid_input = 1;
       	 	}

		switch (crn2)
       		{
       			case 4587: credit2 = 4;
           		break;
		
           		case 4599: credit2 = 3;
          		break;

			case 8997: credit2 = 1;
			break;

			case 9696: credit2 = 3;

           		default: invalid_input = 1;
       		}
	if (invalid_input == 1) // If statement for invalid input
	{
		printf("\n");
	 	printf ("Sorry invalid entry!\n");
		printf("\n\n\t\tTry again. Goodbye!\n\n");
	}
 	else
 	{

		printf("\n");
		printf("Thank you!\n");

		// Fee Invoice for two courses

	   	printf("\n");
		printf("\t\tVALENCE COMMUNITY COLLEGE\n");
		printf("\t\tORLANDO FL 10101\n");
		printf("\t\t*************************\n");

		printf("\n");

		printf("\t\tFee Invoice Prepared for Student V%d\n", student_id);

		printf("\n");

		printf("\t\t1 Credit Hour = $120.25\n");

		printf("\n");

		payment_without_fee = credit1 * PRICE;
		payment_without_fee2 = credit2 * PRICE;

		printf("\t\tCRN\t\tCREDIT HOURS\n");
		printf("\t\t%d\t\t%d\t\t $ %.2f\n", crn1, credit1, payment_without_fee);
		printf("\t\t%d\t\t%d\t\t $ %.2f\n", crn2, credit2, payment_without_fee2);

		printf("\n");

		printf("\t\t\t\tHealth & id fees $  35.00\n");

		printf("\n");

		printf("\t\t-----------------------------------------\n");

		total = payment_without_fee + payment_without_fee2 + HEALTH;

		printf("\t\t\t\tTotal Payments   $ %.2f\n", total);
	}
    }
return 0;
}
