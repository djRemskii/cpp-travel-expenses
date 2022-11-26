/* 
 * FILE: main.h
 * AUTHOR: Remi/Jeremy Ong 
 *
 * primary structure file for program, outlines all the variables and methods
 * that will be used by the program.
 */

//Variables to get input for
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

//Variables to be calculated and output
double totalExpenses;
double totalAllowable;
double reimburseAmount;
double savedAmount;

//Calculation methods
void calculateTotalExpenses();
void calculateTotalAllowable();
void calculateReimburseAmount();
void calculateSavedAmount();

