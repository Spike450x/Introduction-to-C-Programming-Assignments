// Joshua Wood
// Project 5
// Dr. Boustique
// COP 3223
// 04/07/19

// Learning Outcomes:
// 1) Arrays and Functions

// Please read the sample runs carefully as this is quite different from the previous projects.
// In this project, the student can take as many courses as permitted.
// The list of courses to take are listed  below. This time there is no restriction on
// the total credit hours. Your code should allow the user, after you enter the student’s id, to do the following options:

// 1- Add a course for the student
// 2- Drop a course for the student
// 3- Print the fee invoice

// For every option, you must have a separate function.
// Feel free to add helper functions as needed.

// Additional Information - It costs 120.25 dollars per credit hour in addition to $35.00 charged for
// health and id services. Valence Community College offers the following course:

// CRN     Course    Credit Hours
// 4587    MAT 236		4
// 4599    COP 220    3
// 8997    GOL 124    1
// 9696    COP 100    3
// 7895    MNT 125    2
// 9658    OPT 120    3
// 4287    MAT 836    4
// 9599    COP 220    3
// 8927    GOM 124    1
// 7696    COT 100    4
// 7890    MOT 125    3
// 9008    OPT 520    5

// Your code must use functions. Bottom line: there should be no redundant code segments, neatly indent your
// code and choose meaningful names for your variables.

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Pre-Processor directives
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define MAX_LOAD 13
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int credit_hr(int crn);
char*prefix(int crn);
void catelog(void);
void id_input(int *id);
void menu(int *option);
void header(int id);
void addCourse(int []);
void printCrns(int [], int id);
void deleteCourse (int []);
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Main Function
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main()
{
  int id;
  int crn[MAX_LOAD] = {0};
  int option = 1;

  printf("\nWelcome!\n");

  id_input(&id);

  while (option != 0)
  {
    menu(&option);

    switch (option)
    {
      case 1: addCourse (crn); break;
      case 2: deleteCourse (crn); break;
      case 3: printCrns (crn, id); break;
      case 0: printf ("\nBye!\n"); break;
      default: printf("Please enter a valid option ");
    }
  }
   return 0;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Get the students ID
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void id_input(int *id)
{
  printf("Enter the Students Id: ");
  scanf("%d", id);
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Display the menu options for students
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void menu(int *option)
{
  printf("\n\n");
  printf("Choose from the following options:\n");
  printf ("\t1- Add a course for the student\n");
  printf("\t2- Drop a course for the student\n");
  printf("\t3- Print the fee invoice \n");
  printf("\t0- Exit Program\n\n");
  printf("Enter you selection: ");
  scanf("%d", option);
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Top part of the Fee Invoice
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void header(int id)
{
  printf("\n");
  printf("\t\tVALENCE COMMUNITY COLLEGE\n");
  printf("\t\tORLANDO FL 10101\n");
  printf("\t\t-------------------------\n\n");
  printf("\t\tFee Invoice Prepared for Student %d\n\n", id);
  printf("\t\t1 Credit Hour = $120.25\n\n");
  printf("\t\tCRN   CR_PREFIX  CR_HOURS\n\n");
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Bottom Part of the Fee Invoice
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void footer(float total)
{
  printf("\n");
  printf("\t\t\t\tHealth & id fees $  35.00\n\n");
  printf("\t\t------------------------------------------\n\n");
  printf("\t\t\t\tTotal payments   $  %.2f", total);
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Course options for students
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void catelog(void)
{
	printf("\nCRN\t\tCourse\t\tCredit Hours\n");
	printf("4587\t\tMAT 236\t\t 4\n");
	printf("4599\t\tCOP 220\t\t 3\n");
	printf("8997\t\tGOL 124\t\t 1\n");
	printf("9696\t\tCOP 100\t\t 3\n");
	printf("7895\t\tMNT 125\t\t 2\n");
	printf("4287\t\tOPT 120\t\t 3\n");
	printf("9599\t\tMAT 836\t\t 4\n");
	printf("4587\t\tCOP 220\t\t 3\n");
	printf("4587\t\tGOM 124\t\t 1\n");
	printf("4587\t\tCOT 100\t\t 4\n");
	printf("4587\t\tMOT 125\t\t 3\n");
	printf("4587\t\tOPT 520\t\t 5\n");
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function that adds course
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void addCourse(int crn[])
{
	int i;
  int success = 0;
	char choice;

	printf("\nWould you like to print the list of courses? (y/n): ");
	scanf(" %c", &choice);

	switch (choice)
	{
		case 'Y': catelog(); break;
    case 'y': catelog(); break;
    case 'n': break;
    case 'N': break;
    default:
    printf("Invalid Entry! Would you like to print the list of courses? (y/n): ");
    scanf(" %c", &choice);
	}

  for (i = 1; i < MAX_LOAD; i++)
  {
    if (crn[i] == 0)
    {
			printf("\nEnter the course number to add: ");
      scanf("%d", &crn[i]);
      success = 1;
      break;
	  }
  }
  if (success == 0 ) printf ("Course can't be added-you attained the max courses to take!\n\n");
  else printf("Course added!\n");
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Course Hours
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int credit_hr(int crn)
{
  switch(crn)
	{
		case 4587: return 4; break;
		case 4599: return 3; break;
		case 8997: return 1; break;
		case 9696: return 3; break;
		case 7895: return 2; break;
		case 9658: return 3; break;
		case 4287: return 4; break;
		case 9599: return 3; break;
		case 8927: return 1; break;
		case 7696: return 4; break;
		case 7890: return 3; break;
		case 9008: return 5; break;
    default: return 0;
	}
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Course Prefix
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
char *prefix(int crn)
{
  switch(crn)
  {
    case 4587: return "MAT 236"; break;
		case 4599: return "COP 220"; break;
		case 8997: return "GOL 124"; break;
		case 9696: return "COP 100"; break;
		case 7895: return "MNT 125"; break;
		case 9658: return "OPT 120"; break;
		case 4287: return "MAT 836"; break;
		case 9599: return "COP 220"; break;
		case 8927: return "GOM 124"; break;
		case 7696: return "COT 100"; break;
		case 7890: return "MOT 125"; break;
		case 9008: return "OPT 520"; break;
    default: return 0;
  }
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Print Fee Invoice
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void printCrns(int crn [], int id)
{
  int i, ch;
	float tot, cost;
	char * prx;

	header(id);

  for (i = 1; i < MAX_LOAD; i++)
   {
		if (crn[i] != 0)
     {
			ch = credit_hr(crn[i]);
			prx = prefix(crn[i]);
			cost = ch * 120.25;
			printf("\t\t%d   %s\t  %d\t\t $ %.2f\n", crn[i], prx, ch, cost);
			tot = tot + ch * 120.25;
		}
	}
	tot = tot + 35;
  footer(tot);
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function that deletes courses
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void deleteCourse (int crn [])
{
  int i ;
  int success = 0;
  int crnToDelete;

  printf ("Enter the course number to delete: ");
  scanf("%d", &crnToDelete);

  for (i = 1; i < MAX_LOAD; i++)
  {
    if (crn[i] == crnToDelete)
    {
      crn[i] = 0;
      success = 1;
      break;
    }
  }
  if (success == 0) printf ("This crn isn't valid!\n\n");
  else printf ("Course Deleted!\n");
}
