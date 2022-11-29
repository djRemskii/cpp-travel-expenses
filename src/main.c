/* 
 * FILE: main.c
 * AUTHOR: Remi/Jeremy Ong 
 *
 * file to hold all the variables and methods that will be used by the program.
 */

#include "../include/main.h"
#include <stdio.h>
#include <stdlib.h>


double totalExpenses;
double totalAllowable;
double reimburseAmount;
double savedAmount;

int main(){
    //Print introduction to program to terminal
    printIntro();


    //Prompt for user input to assign values to each variable
    getUserInputs();

    //Code to make sure variables are being saved to.
    printf("Number of days: %d\n", numberOfDays);
    printf("Depart time : %d\n", departTime);
    printf("Return time: %d\n", returnTime);
    printf("Airfare: %d\n", airfare);
    printf("Car rental cost: %d\n", carRentalCost);
    printf("Miles driven: %d\n", milesDriven);

    printf("Parking Fees:\n");
    for (int i=0; i<numberOfDays; i++){
        printf("\tDay %d: %d\n", i, parkingFees[i]);
    }

    printf("Taxi Fees:\n");
    for (int i=0; i<numberOfDays; i++){
        printf("\tDay %d: %d\n", i, taxiFees[i]);
    }

    printf("Registration Fees: %d\n", registrationFees);
    printf("Hotel Cost: %d\n", hotelCost);
    printf("Meal Costs:\n");
    for (int i=0; i<numberOfDays; i++){
        printf("Day %d:\n", i);
        for (int j=0; j<3; j++){
            printf("\tMeal %d: %d", j, mealCosts[i][j]);
        }
        printf("\n");
    }


    /*
    //After all variables have values, calculate 
    totalExpenses = calculateTotalExpenses(numberOfDays, airfare, carRentalCost, milesDriven, parkingFees, taxiFees, registrationFees, hotelCost, mealCosts);
    totalAllowable = calculateTotalAllowable(numberOfDays, departTime, returnTime, parkingFees, taxiFees);
    reimburseAmount = calculateReimburseAmount(totalExpenses, totalAllowable);
    savedAmount = calculateSavedAmount(totalExpenses, totalAllowable);
    */

    /*
    //Output to user
    outputTotalExpenses();
    outputTotalALlowable();
    outputReimburseAmount();
    outputSavedAmount();
    */
    
    free(parkingFees);
    free(taxiFees);
    free(mealCosts);
}
