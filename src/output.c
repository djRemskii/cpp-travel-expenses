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
void outputReimburseAmount(double total, double allowable)
{
    printf("Reimbursed Amount: %.2f\n", calculateReimburseAmount(total, allowable));
}
 
//the amount saved by the businessperson if the expenses were under the total amount allowed
void outputSavedAmount(double total, double allowable)
{
    printf("Amount Saved: %.2f\n", calculateSavedAmount(total, allowable));
}
 
 
 
 
 
 
/** Output to user
    outputTotalExpenses();
    outputTotalALlowable();
    outputReimburseAmount();
    outputSavedAmount();
 
 
double totalExpenses
double totalAllowable
double reimburseAmount
double savedAmount
*/
 
 

