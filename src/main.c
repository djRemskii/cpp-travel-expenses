/* 
 * FILE: main.c
 * AUTHOR: Remi/Jeremy Ong 
 *
 * file to hold all the variables and methods that will be used by the program.
 */

#include "../include/main.h"

int numberOfDays;
int departTime;
int returnTime;
double airfare;
double carRentalCost;
int milesDriven;
double parkingFees[];
double taxiFees[];
double registrationFees;
double hotelCost;
double mealCosts[][3];

double totalExpenses;
double totalAllowable;
double reimburseAmount;
double savedAmount;

int main(){
    //Print introduction to program to terminal
    printIntro();


    //Prompt for user input to assign values to each variable
    getUserInputs();

    
    //After all variables have values, calculate 
    totalExpenses = calculateTotalExpenses(numberOfDays, airfare, carRentalCost, milesDriven, parkingFees, taxiFees, registrationFees, hotelCost, mealCosts);
    totalAllowable = calculateTotalAllowable(numberOfDays, departTime, returnTime, parkingFees, taxiFees);
    reimburseAmount = calculateReimburseAmount(totalExpenses, totalAllowable);
    savedAmount = calculateSavedAmount(totalExpenses, totalAllowable);

    /*
    //Output to user
    outputTotalExpenses();
    outputTotalALlowable();
    outputReimburseAmount();
    outputSavedAmount();
    */
    

}
