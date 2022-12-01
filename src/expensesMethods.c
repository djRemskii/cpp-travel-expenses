/* 
 * FILE: expensesMethods.c
 * AUTHOR: Minh Tran
 *
 * methods for calculating total and allowable expenses
 */

#include <stdlib.h> // Used for EXIT_FAILURE
#include <stdio.h>
#include "../include/main.h"

/*
User input used in functions... :

int numberOfDays
int departTime                ---              (just get the hour, using 24-hour time)
int returnTime                 ---              (just get the hour, using 24-hour time)
double airfare
double carRentalCost
int milesDriven
double parkingFees[numberOfDays]    ---              (record parking fees per day, don't combine them)
double taxiFees[numberOfDays]           ---              (record taxi fees per day, don't combine them)
double registrationFees            ---               (ask user for total conference or seminar registration fees)
double hotelCost             ---             (total for entire trip, not per day)
double mealCosts[numberOfDays][3]              ---               (record each meal price, per day)

*/

// 4 primary methods

// double calculateTotalExpenses( ... takes in all user input ... ) { returns total amount of expenses for the businessperson }
double calculateTotalExpenses(int numberOfDays, double airfare, double carRentalCost, int milesDriven, double (*ptrParkingFees)[], double (*ptrTaxiFees)[], double registrationFees, double hotelCost, double (*ptrMealFees)[][3])
{
    double totalCost = 0.0;

    //dereference arrays
    // double parkingFees[] = *ptrParkingFees;
    // double taxiFees[] = *ptrTaxiFees;
    // double mealFees[][3] = *ptrMealFees;

    const double costPerMile = 0.27; // per mile driven = $0.27
    double parkingCosts = 0.0;
    double taxiCosts = 0.0;
    double mealCosts = 0.0;
    for (int i = 0; i < numberOfDays; i++)
    {
        parkingCosts += (*ptrParkingFees)[i];
        taxiCosts += (*ptrTaxiFees)[i];
    }


    for (int i = 0; i < numberOfDays; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            mealCosts += (*ptrMealFees)[i][k];
        }
    }

    totalCost = airfare + carRentalCost + ((double) milesDriven * costPerMile) + parkingCosts + taxiCosts + registrationFees + hotelCost + mealCosts;
    /*
    printf("---------------------\n");
    printf("The following text can befound in calculateTotalExpenses method within the expensesMethod file.\n");
    printf("Order of Variables: airfare  carRentalCost  ((double) milesDriven * costPerMile)  parkingCosts  taxiCosts  registrationFees  hotelCost  mealCosts  totalCost\n");
    printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", airfare, carRentalCost, ((double) milesDriven * costPerMile), parkingCosts, taxiCosts, registrationFees, hotelCost, mealCosts, totalCost);
    printf("---------------------\n");
    */

    return totalCost;
}


// double calculateTotalAllowable( ... takes in certain user input relevent to allowable expenses ... ) { returns total amount of the used allowable expenses the company offered }
/*
* $6 parking fee / $10 taxi fee ~ per day
* $90 lodging per night
* breakfast, lunch, dinner ...
*/
double calculateUsedAllowableExpenses(int numberOfDays, int departTime, int returnTime, double (*ptrParkingFees)[], double (*ptrTaxiFees)[], double (*ptrMealFees)[][3], double totalHotelCost)
{
    // Explicit call for addMealFee
    double totalAllowed = 0;

    /* -------- CALCULATING TRANSPORTATION COSTS -------- */

    const double allowableParkingExpense = 6.0;
    const double allowableTaxiExpense = 10.0;
    double parkingCosts = 0;
    double taxiCosts = 0;

    for (int i = 0; i < numberOfDays; i++)
    {
        if((*ptrParkingFees)[i] > 0)
        {
            double tempParkCost = (*ptrParkingFees)[i];
            if(tempParkCost > allowableParkingExpense){
                tempParkCost = allowableParkingExpense;
            }
            parkingCosts += tempParkCost;
        }
        
        if((*ptrTaxiFees)[i] > 0)
        {
            double tempTaxiCost = (*ptrTaxiFees)[i];
            if(tempTaxiCost > allowableTaxiExpense){
                tempTaxiCost = allowableTaxiExpense;
            }
            taxiCosts += tempTaxiCost;
        }
    }

    /* -------- CALCULATING TRANSPORTATION COSTS -------- */

    const double lodgingAllowance = 90.0;
    double tempHotelCost = totalHotelCost;
    if((lodgingAllowance * numberOfDays)<totalHotelCost){
        tempHotelCost = lodgingAllowance * numberOfDays;
    }
    double hotelCosts = tempHotelCost;

    /* -------- CALCULATING MEAL COSTS -------- */

    enum Meal {
        Breakfast, // 0
        Lunch,     // 1
        Dinner     // 2
    };

    const enum Meal breakfast = Breakfast;
    const enum Meal lunch = Lunch;
    const enum Meal dinner = Dinner;

    const double breakfastCost = 9.0;
    const double lunchCost = 12.0;
    const double dinnerCost = 16.0;
    double mealCosts = 0.0;
    
    for (int day = 0; day < numberOfDays; day++)
    {
        for (int mealType = 0; mealType < 3; mealType++)
        {
            if((*ptrMealFees)[day][mealType] > 0) // If the person ordered breakfast, lunch, and or dinner that day
            {
                double tempMealCosts = 0.0;
                if(mealType == breakfast) 
                {
                    tempMealCosts = addMealFee(day, numberOfDays, breakfastCost, departTime, returnTime, 7, 8);
                }
                else if (mealType == lunch)
                {
                    tempMealCosts += addMealFee(day, numberOfDays, lunchCost, departTime, returnTime, 12, 13);
                }
                else if (mealType == dinner)
                {
                    tempMealCosts += addMealFee(day, numberOfDays, dinnerCost, departTime, returnTime, 18, 19);
                }
                else
                {
                    printf("ERROR: mealFee item is not considered breakfast, lunch, or dinner.");
                    return EXIT_FAILURE;
                }

                if ((*ptrMealFees)[day][mealType] < tempMealCosts){
                        tempMealCosts = (*ptrMealFees)[day][mealType];
                }
                mealCosts += tempMealCosts;
                
            }
        }
    }

    /* -------- COMBINING ALL CALCULATIONS -------- */

    totalAllowed += parkingCosts + taxiCosts + hotelCosts + mealCosts;

    return totalAllowed;
}



// double calculateTotalAllowable( ... takes in certain user input relevent to allowable expenses ... ) { returns total amount of allowable expenses the company must offer }
/*
* $6 parking fee / $10 taxi fee ~ per day
* $90 lodging per night
* breakfast, lunch, dinner ...
*/
double calculateAllowableExpenses(int numberOfDays, int departTime, int returnTime, double (*ptrParkingFees)[], double (*ptrTaxiFees)[], double (*ptrMealFees)[][3])
{
    // Explicit call for addMealFee
    double totalAllowed = 0;

    /* -------- CALCULATING TRANSPORTATION COSTS -------- */

    const double allowableParkingExpense = 6.0;
    const double allowableTaxiExpense = 10.0;
    double parkingCosts = 0;
    double taxiCosts = 0;

    for (int i = 0; i < numberOfDays; i++)
    {
        if((*ptrParkingFees)[i] > 0)
        {
            parkingCosts += allowableParkingExpense;
        }
        
        if((*ptrTaxiFees)[i] > 0)
        {
            taxiCosts += allowableTaxiExpense;
        }
    }

    /* -------- CALCULATING TRANSPORTATION COSTS -------- */

    const double lodgingAllowance = 90.0;
    double hotelCosts = lodgingAllowance * numberOfDays;

    /* -------- CALCULATING MEAL COSTS -------- */

    enum Meal {
        Breakfast, // 0
        Lunch,     // 1
        Dinner     // 2
    };

    const enum Meal breakfast = Breakfast;
    const enum Meal lunch = Lunch;
    const enum Meal dinner = Dinner;

    const double breakfastCost = 9.0;
    const double lunchCost = 12.0;
    const double dinnerCost = 16.0;
    double mealCosts = 0.0;
    
    for (int day = 0; day < numberOfDays; day++)
    {
        for (int mealType = 0; mealType < 3; mealType++)
        {
            if((*ptrMealFees)[day][mealType] > 0) // If the person ordered breakfast, lunch, and or dinner that day
            {
                if(mealType == breakfast) 
                {
                    mealCosts += addMealFee(day, numberOfDays, breakfastCost, departTime, returnTime, 7, 8);
                }
                else if (mealType == lunch)
                {
                    mealCosts += addMealFee(day, numberOfDays, lunchCost, departTime, returnTime, 12, 13);
                }
                else if (mealType == dinner)
                {
                    mealCosts += addMealFee(day, numberOfDays, dinnerCost, departTime, returnTime, 18, 19);
                }
                else
                {
                    printf("ERROR: mealFee item is not considered breakfast, lunch, or dinner.");
                    return EXIT_FAILURE;
                }
            }
        }
    }

    /* -------- COMBINING ALL CALCULATIONS -------- */

    totalAllowed += parkingCosts + taxiCosts + hotelCosts + mealCosts;

    return totalAllowed;
}



// double calculateReimburseAmount() ~ returns total - allowable
double calculateReimburseAmount(double total, double usedAllowable)
{
    if ((total - usedAllowable) > 0){
        return (total - usedAllowable); 
    } else {
        return 0.0;
    }
}

// double calculateSavedAmount() ~ returns total allowable - allowable spent
double calculateSavedAmount(double allowable, double usedAllowable)
{
    if ((allowable - usedAllowable) > 0){
        return (allowable - usedAllowable);
    } else {
        return 0.0;
    }
}

// static methods to be used with calculateAllowableExpenses, simplifies down mealCosts if statements
// returns cost of the meal unless otherwise not allowed
double addMealFee(int day, int numberOfDays, double constMealCost, int departTime, int returnTime, int departTimeDeadline, int returnTimeDeadline)
{
    if(day == 0) // If First Day
    {
        // First day breakfast (Breakfast Allowed only if leaving before 7 AM)
        // First day lunch (Lunch Allowed only if leaving before 12 PM)
        // First day dinner (Dinner Allowed only if leaving before 6 PM)
        if(departTime >= departTimeDeadline)
        {
            return 0.0;
        }

    }
    else if(day == numberOfDays-1) // If Last Day
    {
        // Last day breakfast (Breakfast allowed only if arriving after 8 AM)
        // Last day lunch (Lunch allowed only if arriving after 1 PM)
        // Last day lunch (Lunch allowed only if arriving after 7 PM)
        if(returnTime <= returnTimeDeadline)
        {
            return 0.0;
        }
    }

    return constMealCost;
}
