/* 
 * FILE: main.c
 * AUTHOR: Remi/Jeremy Ong 
 *
 * file to hold all the variables and methods that will be used by the program.
 */

#include "../include/main.h"
#include <stdio.h>
#include <stdlib.h>

/*
double parkingFees[];
double taxiFees[];
double mealCosts[][3];
*/

double totalExpenses;
double totalAllowable;
double totalUsedAllowable;
double reimburseAmount;
double savedAmount;

int main(){

    // Tests
    calculateTest5();

    //Print introduction to program to terminal
    printIntro();

    double aaa[3] = {1.0,2.0,3.0};
    for (int i=0; i<3; i++){
        printf("%.2f\n",aaa[i]);
    }


    //Prompt for user input to assign values to each variable
    getUserInputs();

    double parkingFees[numberOfDays];
    double taxiFees[numberOfDays];
    double mealCosts[numberOfDays][3];

    for (int i = 0; i < numberOfDays; i++){
        int num;
        printf("What is the parking fee for day %d\n", i + 1);
        scanf("%d", &num);
        fflush(stdin);
        while (num < 0){
            printf("Invalid, try again\n");
            scanf("%f", &num);
            fflush(stdin);
        }
        parkingFees[i] = num;
    }

    //double taxiFees[numberOfDays];
    for (int i = 0; i < numberOfDays; i++){
        int num;
        printf("What is the taxi fee for day %d\n", i + 1);
        scanf("%d", &num);
        fflush(stdin);
        while (num < 0){
            printf("Invalid, try again\n");
            scanf("%d", &num);
            fflush(stdin);
        }
        taxiFees[i] = num;
    }

    //double mealCosts[numberOfDays][3];
    for (int i = 0; i < numberOfDays; i++){
        char arr[3][10] = {"Breakfast", "Lunch", "Dinner"};
        for (int j = 0; j < 3; j++){
            printf("Pick meal cost for %s for day %d\n", arr[j], i + 1);
            int num;
            scanf("%d", &num);
            fflush(stdin);
            while (num < 0){
                printf("Invalid, try again\n");
                scanf("%d", &num);
                fflush(stdin);
            }
            mealCosts[i][j] = num;
        }
    }

    //getMultidayInputs();

    //Code to make sure variables are being saved to.
    printf("Number of days: %d\n", numberOfDays);
    printf("Depart time : %d\n", departTime);
    printf("Return time: %d\n", returnTime);
    printf("Airfare: %.2f\n", airfare);
    printf("Car rental cost: %.2f\n", carRentalCost);
    printf("Miles driven: %d\n", milesDriven);

    printf("Parking Fees:\n");
    for (int i=0; i<numberOfDays; i++){
        printf("\tDay %d: %.2f\n", i+1, parkingFees[i]);
    }

    printf("Taxi Fees:\n");
    for (int i=0; i<numberOfDays; i++){
        printf("\tDay %d: %.2f\n", i+1, taxiFees[i]);
    }

    printf("Registration Fees: %.2f\n", registrationFees);
    printf("Hotel Cost: %.2f\n", hotelCost);
    printf("Meal Costs:\n");
    for (int i=0; i<numberOfDays; i++){
        printf("Day %d:\n", i+1);
        for (int j=0; j<3; j++){
            printf("\tMeal %d: %.2f", j+1, mealCosts[i][j]);
        }
        printf("\n");
    }


    //After all variables have values, calculate 
    totalExpenses = calculateTotalExpenses(numberOfDays, airfare, carRentalCost, milesDriven, parkingFees, taxiFees, registrationFees, hotelCost, mealCosts);
    totalAllowable = calculateAllowableExpenses(numberOfDays, departTime, returnTime, parkingFees, taxiFees, mealCosts); 
    totalUsedAllowable = calculateUsedAllowableExpenses(numberOfDays, departTime, returnTime, parkingFees, taxiFees, mealCosts, hotelCost); 
    reimburseAmount = calculateReimburseAmount(totalExpenses, totalUsedAllowable);
    savedAmount = calculateSavedAmount(totalAllowable, totalUsedAllowable);
    
    //TEST OUTPUT CODE
    /*
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Total Allowable: %.2f\n", totalAllowable);
    printf("Total Used Allowable: %.2f\n", totalUsedAllowable);
    printf("Total Reimbursed: %.2f\n", reimburseAmount);
    printf("Total Saved: %.2f\n", savedAmount);
    */

    //Output to user
    outputTotalExpenses(totalExpenses);
    outputTotalAllowable(totalAllowable);
    outputReimburseAmount(reimburseAmount);
    outputSavedAmount(savedAmount);


    //Test Cases code
    calculateTest4();
    calculateTest5();
}
