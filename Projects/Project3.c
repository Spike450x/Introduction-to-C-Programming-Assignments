// Joshua Wood
// Project 3
// Dr. Boustique
// COP 3223
// 2/07/19

// Learning Outcomes:
// Selection
// structuresLoops


// Description: At Valence community college, a student can’t take more than 3
// courses under the constraint of having no more than 7 credit hours.
// The purpose of this assignment is to construct a fee invoice for a student.
// This requires the input of Student’s id as integer and the course numbers.
// It costs 120.25 dollars per credit hour in addition to $35.00 charged for health and id services.

// Here is the list of all courses Valence Community College offers:

// CRN			CoursePrefix		Credit Hours
// 4587			MAT 236					4
// 4599			COP 220					3
// 8997			GOL 124					1
// 9696			COP 100					5
// 4580			MAT 230					3
// 4581			MAT 231					4
// 4582			MAT 232					2
// 4583			MAT 233					2
// 3587			MAT 256					4
// 4519			COP 420					3
// 6997			GOL 127					1
// 9494			COP 101					3


//pre-processor directives
#include <stdio.h>

// Main function
int main()
{
	// Variables

	int student_id, courses_taken;
	// student_id is the students id number and the courses_taken is number of courses the student is taking
	// **Can only take 3 courses**

	int crn1, crn2, crn3;
	// The crn's are the class crn number that the student has to enter. Since the student can only take
	// three classes, there are only three crn's

	int credit_hours1, credit_hours2, credit_hours3;
	// The credit_hours are the actual credit hours students receive for each class
	// Since the student can only take a max of three classes, there only three credit_hours

	char * prefix1, * prefix2, * prefix3;
	// Each class has a prefix like "COP 3223" that corresponds with the crn. Since there are
	// three classes, there are only three prefix

	int invalid_input = 0;
	// This variable is meant to represent the error message that will pop up as a default if there input is invalid

	char choice = 'Y';
	// This variable will allow the student to enter whether or not they would like to print another fee invoice. It starts out already
	// set to Y (yes)

	float payment_without_fee, payment_without_fee2, payment_without_fee3, total;
	// payment_without_fee is the price for the student without having the
	// extra $35.00 added onto it

	// total is the price with all courses, $35.00 health and id fees, and the $120.00 per credit hour added up together

	int max;
	// Max is designed to make sure the student can't enter any more than 7 credit hours in their fee invoice

	int end = 0;
	// End is designed as a pathway to display an error code every time the user enters any letter but
	// Y/y or N/n

	// -------------------------------------------------------------------------------------------------------------------------------
	// -------------------------------------------------------------------------------------------------------------------------------

	// Introduction {Goal: Obtain the students ID, courses taken, and crn numbers}

	// This while loops gives user an unlimited amout of fee invoices as long as they say yes
	while (choice == 'Y' || choice == 'y')
	{
		invalid_input = 0;
		printf("\n");
		printf("Enter the Students Id\n");
		printf("\t");
		scanf("%d", &student_id); // User input for students id

		printf("\n");

		printf("Enter how may courses-up to 3\n");
		printf("\t");
		scanf("%d", &courses_taken); // User input for courses taken

		// This while loop will recognize that the amount of courses entered is invalid and will continue to repeat the
		// same message until input is between 0 and 3

		while (courses_taken > 3 || courses_taken < 0)
		{
			printf("\n");
			printf("Invalid number of courses (up to 3)\n");
			printf("\t");
			scanf("%d", &courses_taken);
		}

		// This if statement will take effect if and only if the student is not taking any courses at all. It will generate a
		// fee invoice that will portray the price without any classes

		if (courses_taken == 0)
		{
			printf("\n");
			printf("Thank you!\n");

			// Fee Invoice for 0 courses

			printf("\n");
			printf("\t\tVALENCE COMMUNITY COLLEGE\n");
			printf("\t\tORLANDO FL 10101\n");
			printf("\t\t*************************\n");

			printf("\n");

			printf("\t\tFee Invoice Prepared for Student V%d\n", student_id);

			printf("\n");

			printf("\t\t1 Credit Hour = $120.25\n");

			printf("\n");

			printf("\t\tCRN\tCR_PREFIX  CR_HOURS\n");

			printf("\n");

			printf("\n");

			printf("\t\t\t    Health & id fees  $  35.00\n");

			printf("\n");

			printf("\t\t--------------------------------------\n");

			total = 35.00;

			printf("\t\t\t    Total Payments    $  %.2f\n", total);

			printf("\n");
		}

		// This if statement will take effect if and only if the student is taking one course. It will generate a
		// fee invoice that will portray the price with one class
		else if (courses_taken == 1)
		{
			// Fee Invoice for one course

			printf("\n");
			printf("Enter the course number(s)\n");
			printf("\t");
			scanf("%d", &crn1); // input for credit hours earned

			switch (crn1)
			{
			 	case 4587: prefix1 = "MAT 236"; credit_hours1 = 4;
			 	break;
				case 4599: prefix1 = "COP 220"; credit_hours1 = 3;
				break;
				case 8997: prefix1 = "GOL 124"; credit_hours1 = 1;
			 	break;
			 	case 9696: prefix1 = "COP 100"; credit_hours1 = 5;
			 	break;
				case 4580: prefix1 = "MAT 230"; credit_hours1 = 3;
				break;
				case 4581: prefix1 = "MAT 231"; credit_hours1 = 4;
				break;
			  case 4582: prefix1 = "MAT 232"; credit_hours1 = 2;
				break;
				case 4583: prefix1 = "MAT 233"; credit_hours1 = 2;
				break;
			 	case 3587: prefix1 = "MAT 256"; credit_hours1 = 4;
				break;
			 	case 4519: prefix1 = "COP 420"; credit_hours1 = 3;
			 	break;
			 	case 6997: prefix1 = "GOL 127"; credit_hours1 = 1;
				break;
				case 9494: prefix1 = "COP 101"; credit_hours1 = 3;
				break;

				default : invalid_input = 1;
			}

			if (invalid_input == 1) // Activates if the student enters a wrong crn number
			{
				printf("\n");
				printf("Sorry Invald crn(s)!\n");
			}

			else
			{
				max = credit_hours1;

				if (max > 7) // Activates if student enters more than 7 credit hours
				{
					printf("\n");
					printf("Sorry we can't process more than 7 credit hours!\n");
				}

				else // Print actual fee invoice
				{
					printf("\n");
					printf("Thank you!\n");

					printf("\n");
			  	printf("\t\tVALENCE COMMUNITY COLLEGE\n");
					printf("\t\tORLANDO FL 10101\n");
					printf("\t\t-------------------------\n");

				  printf("\n");
					printf("\t\tFee Invoice Prepared for Student V%d\n", student_id);

					printf("\n");

					printf("\t\t1 Credit Hour = $120.25\n");

					printf("\n");

					payment_without_fee = credit_hours1 * 120.25;

					printf("\t\tCRN\tCR_PREFIX  CR_HOURS\n");
					printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn1, prefix1, credit_hours1, payment_without_fee);

					printf("\n");

	 				printf("\t\t\t\tHealth & id fees $  35.00\n");

					printf("\n");

					printf("\t\t-----------------------------------------\n");

					total = payment_without_fee + 35.00;

					printf("\t\t\t\tTotal Payments   $ %.2f\n", total);
				}
			}
		}

			// This if statement will take effect if and only if the student is taking two courses. It will generate a
			// fee invoice that will portray the price with two classes
			else if (courses_taken == 2)
			{
				// Fee Invoice for two courses

				printf("\n");
				printf("Enter the course number(s)\n");
				printf("\t");
				scanf("%d %d", &crn1, &crn2); // input for credit hours earned

				switch (crn1)
				{
			 		case 4587: prefix1 = "MAT 236"; credit_hours1 = 4;
			 		break;
			 		case 4599: prefix1 = "COP 220"; credit_hours1 = 3;
			 		break;
			 		case 8997: prefix1 = "GOL 124"; credit_hours1 = 1;
			 		break;
			 		case 9696: prefix1 =	"COP 100"; credit_hours1 = 5;
			 		break;
			 		case 4580: prefix1 = "MAT 230"; credit_hours1 = 3;
			 		break;
			 		case 4581: prefix1 = "MAT 231"; credit_hours1 = 4;
			 		break;
			 		case 4582: prefix1 = "MAT 232"; credit_hours1 = 2;
			 		break;
			 		case 4583: prefix1 = "MAT 233"; credit_hours1 = 2;
			 		break;
			 		case 3587: prefix1 = "MAT 256"; credit_hours1 = 4;
			 		break;
			 		case 4519: prefix1 = "COP 420"; credit_hours1 = 3;
			 		break;
			 		case 6997: prefix1 = "GOL 127"; credit_hours1 = 1;
			 		break;
			 		case 9494: prefix1 = "COP 101"; credit_hours1 = 3;
			 		break;

			 	default : invalid_input = 1;
			}

			switch (crn2)
			{
			 	case 4587: prefix2 = "MAT 236"; credit_hours2 = 4;
			 	break;
			 	case 4599: prefix2 = "COP 220"; credit_hours2 = 3;
			 	break;
			 	case 8997: prefix2 = "GOL 124"; credit_hours2 = 1;
			 	break;
			 	case 9696: prefix2 =	"COP 100"; credit_hours2 = 5;
			 	break;
			 	case 4580: prefix2 = "MAT 230"; credit_hours2 = 3;
			 	break;
			 	case 4581: prefix2 = "MAT 231"; credit_hours2 = 4;
			 	break;
			 	case 4582: prefix2 = "MAT 232"; credit_hours2 = 2;
			 	break;
			 	case 4583: prefix2 = "MAT 233"; credit_hours2 = 2;
			 	break;
			 	case 3587: prefix2 = "MAT 256"; credit_hours2 = 4;
			 	break;
			 	case 4519: prefix2 = "COP 420"; credit_hours2 = 3;
				break;
			 	case 6997: prefix2 = "GOL 127"; credit_hours2 = 1;
			 	break;
			 	case 9494: prefix2 = "COP 101"; credit_hours2 = 3;
			 	break;

			 default : invalid_input = 1;
		}

		if (invalid_input == 1) // Activates if the student enters a wrong crn number
		{
			printf("\n");
			printf("Sorry Invald crn(s)!\n");
		}

		else
		{
			max = credit_hours1 + credit_hours2;

			if (max > 7) // Activates if student enters more than 7 credit hours
			{
				printf("\n");
				printf("Sorry we can't process more than 7 credit hours!\n");
			}

			else // Prints actual fee invoice
			{
				printf("\n");
				printf("Thank you!\n");

				printf("\n");
				printf("\t\tVALENCE COMMUNITY COLLEGE\n");
				printf("\t\tORLANDO FL 10101\n");
				printf("\t\t-------------------------\n");
				printf("\n");

				printf("\t\tFee Invoice Prepared for Student V%d\n", student_id);

				printf("\n");

		 		printf("\t\t1 Credit Hour = $120.25\n");

		 		printf("\n");

				payment_without_fee = credit_hours1 * 120.25;
				payment_without_fee2 = credit_hours2 * 120.25;


				printf("\t\tCRN\tCR_PREFIX  CR_HOURS\n");
 		 		printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn1, prefix1, credit_hours1, payment_without_fee);
	 			printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn2, prefix2, credit_hours2, payment_without_fee2);
				printf("\n");
 				printf("\t\t\t\tHealth & id fees $  35.00\n");

 				printf("\n");
				printf("\t\t-----------------------------------------\n");

				total = payment_without_fee + payment_without_fee2 + 35.00;

				printf("\t\t\t\tTotal Payments   $ %.2f\n", total);
			}
		}
	}
			// This if statement will take effect if and only if the student is taking three courses. It will generate a
			// fee invoice that will portray the price with three classes
			else if (courses_taken == 3)
 			{
 			 	// Fee Invoice for three courses

				printf("\n");
				printf("Enter the course number(s)\n");
				printf("\t");
				scanf("%d %d %d", &crn1, &crn2, &crn3); // input for credit hours earned

				switch (crn1)
	 			{
	 			 case 4587: prefix1 = "MAT 236"; credit_hours1 = 4;
	 		 	 break;
	 		 	 case 4599: prefix1 = "COP 220"; credit_hours1 = 3;
	 			 break;
	 			 case 8997: prefix1 = "GOL 124"; credit_hours1 = 1;
	 			 break;
	 			 case 9696: prefix1 =	"COP 100"; credit_hours1 = 5;
	 			 break;
	 			 case 4580: prefix1 = "MAT 230"; credit_hours1 = 3;
	 			 break;
	 			 case 4581: prefix1 = "MAT 231"; credit_hours1 = 4;
	 			 break;
	 			 case 4582: prefix1 = "MAT 232"; credit_hours1 = 2;
	 			 break;
	 			 case 4583: prefix1 = "MAT 233"; credit_hours1 = 2;
	 			 break;
	 			 case 3587: prefix1 = "MAT 256"; credit_hours1 = 4;
	 			 break;
	 			 case 4519: prefix1 = "COP 420"; credit_hours1 = 3;
	 			 break;
	 			 case 6997: prefix1 = "GOL 127"; credit_hours1 = 1;
	 			 break;
	 			 case 9494: prefix1 = "COP 101"; credit_hours1 = 3;
	 			 break;

	 			 default : invalid_input = 1;
	 		}

	 		switch (crn2)
	 		{
	 			 case 4587: prefix2 = "MAT 236"; credit_hours2 = 4;
	 			 break;
	 			 case 4599: prefix2 = "COP 220"; credit_hours2 = 3;
	 			 break;
	 			 case 8997: prefix2 = "GOL 124"; credit_hours2 = 1;
	 			 break;
	 			 case 9696: prefix2 =	"COP 100"; credit_hours2 = 5;
	 			 break;
	 			 case 4580: prefix2 = "MAT 230"; credit_hours2 = 3;
	 			 break;
	 			 case 4581: prefix2 = "MAT 231"; credit_hours2 = 4;
	 			 break;
	 			 case 4582: prefix2 = "MAT 232"; credit_hours2 = 2;
	 			 break;
	 			 case 4583: prefix2 = "MAT 233"; credit_hours2 = 2;
	 			 break;
	 			 case 3587: prefix2 = "MAT 256"; credit_hours2 = 4;
	 			 break;
	 			 case 4519: prefix2 = "COP 420"; credit_hours2 = 3;
	 			 break;
	 			 case 6997: prefix2 = "GOL 127"; credit_hours2 = 1;
	 			 break;
	 			 case 9494: prefix2 = "COP 101"; credit_hours2 = 3;
	 			 break;

	 			 default : invalid_input = 1;
	 		}

			switch (crn3)
	 		{
	 			 case 4587: prefix3 = "MAT 236"; credit_hours3 = 4;
	 			 break;
	 			 case 4599: prefix3 = "COP 220"; credit_hours3 = 3;
	 			 break;
	 			 case 8997: prefix3 = "GOL 124"; credit_hours3 = 1;
	 			 break;
	 			 case 9696: prefix3 =	"COP 100"; credit_hours3 = 5;
	 			 break;
	 			 case 4580: prefix3 = "MAT 230"; credit_hours3 = 3;
	 			 break;
	 			 case 4581: prefix3 = "MAT 231"; credit_hours3 = 4;
	 			 break;
	 			 case 4582: prefix3 = "MAT 232"; credit_hours3 = 2;
	 			 break;
	 			 case 4583: prefix3 = "MAT 233"; credit_hours3 = 2;
	 			 break;
	 			 case 3587: prefix3 = "MAT 256"; credit_hours3 = 4;
	 			 break;
	 			 case 4519: prefix3 = "COP 420"; credit_hours3 = 3;
	 			 break;
	 			 case 6997: prefix3 = "GOL 127"; credit_hours3 = 1;
	 			 break;
	 			 case 9494: prefix3 = "COP 101"; credit_hours3 = 3;
	 			 break;

	 			 default : invalid_input = 1;
	 		}

			if (invalid_input == 1) // Activates if the student enters a wrong crn number
			{
				printf("\n");
				printf("Sorry Invald crn(s)!\n");
			}

			else
			{
				max = credit_hours1 + credit_hours2 + credit_hours3;

				if (max > 7) // Activates if student enters more than 7 credit hours
				{
					printf("\n");
					printf("Sorry we can't process more than 7 credit hours!\n");
				}

			 	else // Prints actual fee invoice
	 		 	{
						printf("\n");
	 	 				printf("Thank you!\n");

 		 	 			printf("\n");
 		 				printf("\t\tVALENCE COMMUNITY COLLEGE\n");
 		 				printf("\t\tORLANDO FL 10101\n");
 	   				printf("\t\t-------------------------\n");
 						printf("\n");

 		 	 			printf("\t\tFee Invoice Prepared for Student V%d\n", student_id);

 		 	 			printf("\n");
 		 	 			printf("\t\t1 Credit Hour = $120.25\n");

 		 	 			printf("\n");
						payment_without_fee = credit_hours1 * 120.25;
 		 				payment_without_fee2 = credit_hours2 * 120.25;
		 	 			payment_without_fee3 = credit_hours3 * 120.25;


 						printf("\t\tCRN\tCR_PREFIX  CR_HOURS\n");
	 	 				printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn1, prefix1, credit_hours1, payment_without_fee);
						printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn2, prefix2, credit_hours2, payment_without_fee2);
						printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn3, prefix3, credit_hours3, payment_without_fee3);

		 				printf("\n");

 	 					printf("\t\t\t\tHealth & id fees $  35.00\n");

 		 	 			printf("\n");

 		 				printf("\t\t-----------------------------------------\n");
 		 				total = payment_without_fee + payment_without_fee2 + payment_without_fee3 + 35.00;

 		 	 			printf("\t\t\t\tTotal Payments   $ %.2f\n", total);
 					}
 				}
			}

		printf("\n\n");

		// If user would like to print another fee invoice, they can choose y for yes or n for no

		printf ("Would you like to start a new invoice? Y = yes, N = No");

		printf("\n");
		printf("\t");
		scanf(" %c", &choice); // Input from user to choose y or n

		while (end == 0)
		{
			switch (choice)
			{
				case 'N': // N for No ... exits program with "goodbye"

				printf("\n");
				printf("Goodbye!\n");
				printf("\n");

				end = 1;
				break;

				case 'n': // n for no ... exits program with "goodbye"

				printf("\n");
				printf("Goodbye!\n");
				printf("\n");

				end = 1;
				break;

				case 'Y': // Y for yes ... Starts again from the top

				end = 2;
				break;

				case 'y': // y for yes ... Starts again from the top

				end = 2;
				break;

				default:	printf("Invalid Entry (it has to be y or n): "); // Error, student entered a wrong character
									scanf(" %c", &choice);
									end = 0;
				break;
			}
		}
	}
}
