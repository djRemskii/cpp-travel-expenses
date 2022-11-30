/* 
 * FILE: main.h
 * AUTHOR: Remi/Jeremy Ong 
 *
 * primary structure file for program, outlines all the variables and methods
 * that will be used by the program.
 */

//Variables to get input for
extern int numberOfDays;
extern int departTime;
extern int returnTime;
extern double airfare;
extern double carRentalCost;
extern int milesDriven;
//extern double parkingFees[];
//extern double taxiFees[];
extern double registrationFees;
extern double hotelCost;
//extern double mealCosts[][3];

//Method to ask for inputs
extern void printIntro();
extern int getUserInputs();

//Method output
extern void outputTotalExpenses();
extern void outputTotalAllowable();
extern void outputReimburseAmount();
extern void outputSavedAmount();

//Variables to be calculated and output
extern double totalExpenses;
extern double totalAllowable;
extern double reimburseAmount;
extern double savedAmount;

//Calculation methods
extern double calculateTotalExpenses();
extern double calculateAllowableExpenses();
extern double calculateReimburseAmount();
extern double calculateSavedAmount();
extern double addMealFee();
