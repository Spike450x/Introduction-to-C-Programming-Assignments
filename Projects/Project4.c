// Joshua Wood
// Project 4
// Dr. Boustique
// COP 3223
// 3/03/19

// Learning Outcomes:
// Functions and Pointers

// **Read carefullybefore you start coding!**

// At Valence community college, a student can’t take more than 3 courses under
// the constraint of having no more than 7 credit hours. The purpose of this assignment
// is to construct a fee invoice for a student.This requires the input ofStudent’s
// id as integer and the course numbers. It costs 120.25 dollars per credit hour in
// addition to $35.00 charged for health and id services.

// ** In this project, functions must be used (no redundant code is allowed this time)
// A hint is provided at the end of this document.Addfunctions as you see fit.
// Bottom line: Have the cleanest (minimum lines of code possible)program.
// This is a great opportunityto work in groups by having each student taking care of
// function or two and then meet to put everything together... **

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
//pre-processor directives
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include <stdio.h>
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int student_id(int *);
void print_course_amount(int *);
void intro_invoice(void);
void mid_invoice(void);
void invoice_close(void);
char new_or_leave(char *);
int max_one(int);
int max_two(int, int);
int max_three(int, int, int);
int credit_check(int crn); // returns 1 if crn is OK, 0 otherwise
int hour_input (int crn); // returns the credit hours of crn
char * prefix (int crn); //prints the prefix of crn
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Main function
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main()
{
  int crn1, crn2, crn3;
  int s_id, option, max = 7;
  float payment_without_fee, payment_without_fee2, payment_without_fee3, total;
  char selection = 'y', decision;

  while (selection == 'y' || selection == 'Y')
  {
   student_id(&s_id);
   print_course_amount(&option);

   if (option == 0)
   {
     intro_invoice();
     printf("\t\tFee Invoice Prepared for Student V%d\n\n", s_id);
     printf("\t\t1 Credit Hour = $120.25\n");
     invoice_close();
     printf("\t\t\t\tTotal Payments   $  35.00\n\n");
   }
   if (option == 1)
   {
     printf("\n");
     printf("Enter the course number\n\t");
     scanf("%d", &crn1);

     if (credit_check(crn1) == 0)
     {
       printf("\n");
       printf ("Sorry invalid crn(s)!\n\n");
     }

     else
     {
       printf("\n");

       if (max_one(crn1) > max)
       {
         printf("Sorry we can’t process more than 7 credit hours!\n\n");
       }

       else
       {
         intro_invoice();
         printf("\t\tFee Invoice Prepared for Student V%d\n", s_id);
         mid_invoice();
         payment_without_fee = hour_input(crn1) * 120.25;
         printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn1, prefix (crn1), hour_input(crn1), payment_without_fee);
         invoice_close();
         total = payment_without_fee + 35.00;
         printf("\t\t\t\tTotal Payments   $ %.2f\n\n", total);
       }
     }
    }

   if (option == 2)
   {
     printf("\n");
     printf("Enter the 2 course number(s)\n\t");
     scanf("%d%d", &crn1, &crn2);

     if (credit_check(crn1) * credit_check(crn2) == 0)
     {
       printf("\n");
       printf ("Sorry invalid crn(s)!\n\n");
     }
     else
     {
       printf("\n");

       if (max_two(crn1, crn2) > max)
       {
         printf("\n");
         printf("Sorry we can’t process more than 7 credit hours!\n\n");
       }
       else
       {
         intro_invoice();
         printf("\t\tFee Invoice Prepared for Student V%d\n", s_id);
         mid_invoice();
         payment_without_fee = hour_input(crn1) * 120.25;
         payment_without_fee2 =  hour_input(crn2) * 120.25;
         printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn1, prefix (crn1), hour_input(crn1), payment_without_fee);
         printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn2, prefix (crn2), hour_input(crn2), payment_without_fee2);
         invoice_close();
         total = payment_without_fee + payment_without_fee2 + 35.00;
         printf("\t\t\t\tTotal Payments   $ %.2f\n\n", total);
       }
      }
    }
   if (option == 3)
   {
     printf("\n");
     printf("Enter your 3 course number(s)\n\t");
     scanf("%d%d%d", &crn1, &crn2, &crn3);

     if (credit_check(crn1) * credit_check(crn2) * credit_check(crn3) == 0)
     {
       printf("\n");
       printf ("Sorry invalid crn(s)!\n");
       printf("\n");
     }

     else
     {
       printf("\n");

       if (max_three(crn1, crn2, crn3) > max)
       {
         printf("\n");
         printf("Sorry we can’t process more than 7 credit hours!\n\n");
       }
       else
       {
         intro_invoice();
         printf("\t\tFee Invoice Prepared for Student V%d\n", s_id);
         mid_invoice();
         payment_without_fee = hour_input(crn1) * 120.25;
         payment_without_fee2 = hour_input(crn2) * 120.25;
         payment_without_fee3 = hour_input(crn3) * 120.25;
         printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn1, prefix (crn1), hour_input(crn1), payment_without_fee);
         printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn2, prefix (crn2), hour_input(crn2), payment_without_fee2);
         printf("\t\t%d\t%s\t\t%3d\t $ %.2f\n", crn3, prefix (crn3), hour_input(crn3), payment_without_fee3);
         invoice_close();
         total = payment_without_fee + payment_without_fee2 + payment_without_fee3 + 35.00;
         printf("\t\t\t\tTotal Payments   $ %.2f\n\n", total);
       }
     }
   }
     selection = new_or_leave(&decision);
 }
 return 0;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Student Id input from the user
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int student_id(int *id)
{
  printf("\n");
  printf("Enter the Students Id\n\t");
  scanf("%d", id);
  return *id;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Amount of courses
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void print_course_amount(int *amount)
{
  printf("\n");
  printf("Enter how many courses-up to 3\n\t");
  scanf("%d", amount);

  while (*amount > 3 || *amount < 0)
  {
    printf("\n");
    printf("Invalid number of courses (up to 3)\n\t");
    scanf("%d", amount);
  }
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function checks whether input from user is valid
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int credit_check (int crn)
{
   if (crn != 4587 && crn != 4599 && crn != 8997 && crn != 9696 && crn != 4580 && crn != 4581 &&
          crn != 4582 && crn != 4583 && crn != 3587 && crn != 4519 && crn != 6997 && crn != 9494) return 0;
   return 1;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function calculates hour for each crn
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int hour_input (int crn)
{
  switch (crn)
  {
    case 4587: return 4;
    case 4599: return 3;
    case 8997: return 1;
    case 9696: return 5;
    case 4580: return 3;
    case 4581: return 4;
    case 4582: return 2;
    case 4583: return 2;
    case 3587: return 4;
    case 4519: return 3;
    case 6997: return 1;
    case 9494: return 3;
    default: return 0;
  }
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function calculates the proper prefix for each crn
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
char * prefix (int crn)
{
  switch (crn)
  {
    case 4587: return "MAT 236";
    case 4599: return "COP 220";
    case 8997: return "GOL 124";
    case 9696: return "COP 100";
    case 4580: return "MAT 230";
    case 4581: return "MAT 231";
    case 4582: return "MAT 232";
    case 4583: return "MAT 233";
    case 3587: return "MAT 256";
    case 4519: return "COP 420";
    case 6997: return "GOL 127";
    case 9494: return "COP 101";
    default: return 0;
  }
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function prints first part of the fee invoice
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void intro_invoice(void)
{
  printf("\n");
  printf("Thank you!\n\n");
  printf("\t\tVALENCE COMMUNITY COLLEGE\n");
  printf("\t\tORLANDO FL 10101\n");
  printf("\t\t-------------------------\n\n");
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function prints second part of the fee invocie
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void mid_invoice(void)
{
  printf("\n");
  printf("\t\t1 Credit Hour = $120.25\n\n");
  printf("\t\tCRN\tCR_PREFIX  CR_HOURS\n");
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function prints out final part of the fee invoice
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void invoice_close(void)
{
  printf("\n");
  printf("\t\t\t\tHealth & id fees $  35.00\n\n");
  printf("\t\t--------------------------------------\n");
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// max_one, max_two, and max_three makes sure user doesn't enter more than 7 hours
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int max_one (int one)
{
  int max;
  max = hour_input(one);
  return max;
}

int max_two(int one, int two)
{
  int max;
  max = hour_input(one) + hour_input(two);
  return max;
}
int max_three(int one, int two, int three)
{
  int max;
  max = hour_input(one) + hour_input(two) + hour_input(three);
  return max;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function asks user whether they want to print another invoice or not
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
char new_or_leave(char *choice)
{
  int end = 0;
  printf("Would you like to print another invoice? Y=yes, N=No\n\t");
  scanf(" %c", choice);
  while (end == 0)
  {
    switch (*choice)
    {
      case 'N': // N for No ... exits program with "goodbye"
      printf("\n");
      printf("Goodbye!\n\n");
      end = 1;
      break;
      case 'n': // n for no ... exits program with "goodbye"
      printf("\n");
      printf("Goodbye!\n\n");
      end = 1;
      break;
      case 'Y': // Y for yes ... Starts again from the top
      end = 1;
      break;
      case 'y': // y for yes ... Starts again from the top
      end = 1;
      break;
      default:
      end = 0;
      printf("\n");
      printf("Invalid Entry (it has to be y or n): "); // Error, student entered a wrong character
      scanf(" %c", choice);
      break;
    }
  }
  return *choice;
}
