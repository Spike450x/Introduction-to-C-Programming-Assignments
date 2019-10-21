// Joshua Wood
// HW1
// Dr. Boustique
// COP 3223
// 1/19/19

// Implement a simple weekly payroll program. The input will consist of the employee number
// (an  integer), the  number  of  hours  worked  (a float),  the  hourly  rate (afloat),
// the tax is 6%. Your program should calculate the total gross pay, and the net payand display a paycheck exactly like it’s shown below.
//
// Employee’s number:                  1200
// Hourly rate of pay:                 10.50
// Hours worked:                       36
// Total Gross Pay:                    378.00 Dollars
//
//      Deductions
//      Tax (6 %): 22.68
//
// Net Pay:                             355.32 Dollars

// Pre-processor directives
#include <stdio.h>
#include <stdlib.h>

// Main Function
int main()
{
	// Constant
	#define TAX .06

	int employee_number;
   	 // Employee's Number

    	float pay_rate;
    	// Pay rate per hour

   	 float hours;
	// Regular Hours per week

    	float gross_pay;
	// total that is calculated from the amount of hours and the pay rate

    	float deduction_tax;
    	// deductions tax is 6% so we must multiply the total by .06

    	float net_pay;
    	// net pay is the value that the employee actually gets paid

	printf("Enter the Employee's number:  ");
	scanf("%d", &employee_number); // User input

	printf("Enter the pay rate per hour: ");
	scanf("%f", &pay_rate); // User Input

	printf("Enter the regular hours per week: ");
	scanf("%f", &hours); // User Input


	printf("\n");
	printf("Thank you!");
	printf("Here is your paycheck!\n");
	printf("\n");

    	// Table of information
	printf("\t--------------------------------------\n");
	printf("\tEmployee's number: \t%d\n", employee_number);
	printf("\tHourly rate of pay: \t%.2f\n", pay_rate);
	printf("\tHours worked: \t\t%.0f\n", hours);

	gross_pay = pay_rate * hours;

	printf("\tTotal Gross Pay: \t%.2f Dollars\n", gross_pay);

	deduction_tax = gross_pay * TAX;

	printf("\n");
	printf("\t\tDeductions\n");
	printf("\t\tTax (6 %%): %.2f\n", deduction_tax);

	net_pay = gross_pay - deduction_tax;

	printf("\n");
	printf("\tNet Pay: \t\t%.2f Dollars\n", net_pay);
	printf("\t--------------------------------------\n");
	printf("Bye!\n");
	printf("\n");

	return 0;
}
