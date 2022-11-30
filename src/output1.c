/** FILE: output.c
 *  AUTHOR: Toby Thap 
 *  Outputting data back to the user after being calculated
*/

#include <stdio.h>

//total expenses incurred by the businessperson
printf("Total Expenses: %f", calculateTotalExpenses());

//total allowable expenses for the trip
printf("Total Allowable Expenses: %f", calculateTotalAllowable());

//excess amount that must be reimbursed by the businessperson, if any
printf("Reimbursed Amount: %f", calculateReimburseAmount());

//the amount saved by the businessperson if the expenses were under the total amount allowed
printf("Amount Saved: %f", calculateSavedAmount());






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

