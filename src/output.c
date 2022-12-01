/** FILE: output.c
 *  AUTHOR: Toby Thap
 *  Outputting data back to the user after being calculated
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "../include/main.h"
 
//total expenses incurred by the businessperson
void outputTotalExpenses(double totalExpense)
{
    printf("Total Expenses: %.2f\n", totalExpense);
}

//total allowable expenses for the trip
void outputTotalAllowable(double totalAllowed)
{
    printf("Total Allowable Expenses: %.2f\n", totalAllowed);
}
 

//excess amount that must be reimbursed by the businessperson, if any
void outputReimburseAmount(double reimburseAmount)
{
    printf("Amount to be Reimbursed: %.2f\n", reimburseAmount);
}
 
//the amount saved by the businessperson if the expenses were under the total amount allowed
void outputSavedAmount(double savedAmount)
{
    printf("Amount Saved: %.2f\n", savedAmount);
}