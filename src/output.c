/** FILE: output.c
 *  AUTHOR: Toby Thap
 *  Outputting data back to the user after being calculated
*/
 
#include <stdio.h>
#include <stdlib.h>
#include "../include/main.h"
 
//total expenses incurred by the businessperson
printf("Total Expenses: %f", calculateTotalExpenses(numberOfDays, airfare, carRentalCost, milesDriven, parkingFees[], taxiFees[], registrationFees, hotelCost, a_mealCosts[][3]));
 
//total allowable expenses for the trip
printf("Total Allowable Expenses: %f", calculateTotalAllowable(numberOfDays, departTime, returnTime, parkingFees[], taxiFees[], mealFees[][3]));
 
//excess amount that must be reimbursed by the businessperson, if any
printf("Reimbursed Amount: %f", calculateReimburseAmount(total, allowable));
 
//the amount saved by the businessperson if the expenses were under the total amount allowed
printf("Amount Saved: %f", calculateSavedAmount(total, allowable));
 
 
 
 
 
 
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
 
 

