// Joshua Wood
// HW6
// Dr. Boustique
// COP 3223
// 3/31/19

// -----------------------------------------------------------------------------
//  The goal is to write a Cprogram that runsas shown in following sample run:
//
//  Sample Run:
//  Enter how many students do you have ( but up to 50): 6
//  Enter the 6scores: 100 85 78 90 40 65
//  Here are the scores with their corresponding grades:
//  100 A
//  85  B
//  78  C
//  90  A
//  40  F
//  65  D
//  The average score is: 76.33
//  There are 4 out 6 who scored above the average.
//  Goodbye!
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Pre-processor directives
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Define function so max number of students can be only be 50
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#define MAX_SIZE 50
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Function Prototypes
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void loadScores(int S[], int *n);
// This function asks the user to enter how many scores(into the pointee of n) and loads
// *n scores into array S(You may refer to my video on arrays)v
void printGrades(int S[], int n);
// This function prints each score and its letter grade, using the standard grade assignment
// ( A if score is between 90 and 100. B if score is between 80 and 89, ... etc)
double average(int S[], double n);
// This function returns the average of the n scores stored in array S
int countAboveAvg(int S[], double average, int n);
// This function counts and returns how many students scored above or equal to the average score(avg).
// S is the array, avg is the average score andn is how many scores to consider in S.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Main function
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int main()
{
  int n; // number of students
  double avg; // average score of students
  int amount; // amount of students who scored above average
  int score [MAX_SIZE]; // scores of students (max_size refers to the max amount of students
  loadScores (score, &n);
  printGrades (score, n);
  avg = average(score, n);
  printf("\nThe average score is: %.2f\n", avg);
  amount = countAboveAvg(score, avg, n);
  printf("\nThere are %d out of %d who scored above the average.\n", amount, n);
  printf("Goodbye!\n");
  return 0;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// This function gets the amount of students and the student scores
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void loadScores(int S[], int *n)
{
  int i;
  printf("\n");
  printf ("Enter how many students do you have (but up to 50): ");
  scanf("%d", n);
  printf ("Enter the %d scores: ", *n);

  for (i = 1; i <= *n ; i++)
  {
    scanf("%d", &S[i]);
  }
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// This function prints the corresponding grade letter with the grade
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
void printGrades(int S[], int n)
{
  int i;
  printf("\n");
  printf("Here are the scores with their corresponding grades:\n");

  for (i = 1; i <= n ; i++)
  {
    if (S[i] >= 90 && S[i] <= 100)
    {
      printf("%d\tA\n", S[i]);
    }

    else if (S[i] < 90 && S[i] >= 80)
    {
      printf("%d\tB\n", S[i]);
    }

    else if (S[i] < 80 && S[i] >= 70)
    {
      printf("%d\tC\n", S[i]);
    }

    else if (S[i] < 70 && S[i] >= 60)
    {
      printf("%d\tD\n", S[i]);
    }

    else
    {
      printf("%d\tF\n", S[i]);
    }
  }
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// This function takes the average of the students grade
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
double average(int S[], double n)
{
  int i;
  double average;
  int sum = 0;

  for (i = 0; i <= n; i++)
  {
    sum += S[i];
  }

  average = (double) sum/n;

  return average;
}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// This function finds what number of students got a score above average
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
int countAboveAvg(int S[], double average, int n)
{
  int i;
  int countAverage = 0;

  for (i = 0; i < n; i++)
  {
    if (S[i] >= average)
    {
      countAverage++;
    }
  }

  return countAverage;
}
