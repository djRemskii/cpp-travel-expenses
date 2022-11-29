#include <stdlib.h> // Used for EXIT_FAILURE

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
double calculateTotalExpenses(int numberOfDays, double airfare, double carRentalCost, int milesDriven, double parkingFees[], double taxiFees[], double registrationFees, double hotelCost, double a_mealCosts[][3])
{
    double totalCost = 0;

    const double costPerMile = 0.27; // per mile driven = $0.27
    double parkingCosts = 0;
    double taxiCosts = 0;
    double mealCosts = 0;

    for (int i = 0; i < numberOfDays; i++)
    {
        parkingCosts += parkingFees[i];
        taxiCosts += taxiFees[i];
    }

    for (int i = 0; i < numberOfDays; i++)
    {
        for (int k = 0; k < 3; i++)
        {
            mealCosts += a_mealCosts[i][k];
        }
    }

    totalCost += 
        airfare + 
        carRentalCost + 
        ((double) milesDriven * costPerMile) + 
        parkingCosts + 
        taxiCosts + 
        registrationFees + 
        hotelCost + 
        mealCosts;

    return totalCost;
}

// double calculateTotalAllowable( ... takes in certain user input relevent to allowable expenses ... ) { returns total amount of allowable expenses the company must offer }
/*
* $6 parking fee / $10 taxi fee ~ per day
* $90 lodging per night
* breakfast, lunch, dinner ...
*/
double calculateAllowableExpenses(int numberOfDays, int departTime, int returnTime, double parkingFees[], double taxiFees[], double mealFees[][3])
{
    double totalAllowed = 0;

    /* -------- CALCULATING TRANSPORTATION COSTS -------- */

    const double allowableParkingExpense = 6.0;
    const double allowableTaxiExpense = 10.0;
    double parkingCosts = 0;
    double taxiCosts = 0;

    for (int i = 0; i < numberOfDays; i++)
    {
        if(parkingFees[i] > 0)
        {
            parkingCosts += allowableParkingExpense;
        }
        
        if(taxiFees[i] > 0)
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
    double mealCosts = 0;
    
    for (int day = 0; day < numberOfDays; day++)
    {
        for (int mealType = 0; mealType < 3; day++)
        {
            if(mealFees[day][mealType] > 0) // If the person ordered breakfast, lunch, and or dinner that day
            {
                if(mealType = breakfast) 
                {
                    mealCosts += addMealFee(day, numberOfDays, breakfastCost, departTime, returnTime, 7, 8);
                }
                else if (mealType = lunch)
                {
                    mealCosts += addMealFee(day, numberOfDays, breakfastCost, departTime, returnTime, 12, 12);
                }
                else if (mealType = dinner)
                {
                    mealCosts += mealCosts += addMealFee(day, numberOfDays, breakfastCost, departTime, returnTime, 18, 19);
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

    totalAllowed +=   
        parkingCosts + 
        taxiCosts + 
        hotelCosts + 
        mealCosts;

    return totalAllowed;
}

// double calculateReimburseAmount() ~ returns total - allowable
double calculateReimburseAmount(double total, double allowable)
{
    return (total - allowable); 
}

// double calculateSavedAmount() ~ returns allowable - total
double calculateSavedAmount(double total, double allowable)
{
    return (allowable - total);
}

// static methods to be used with calculateAllowableExpenses, simplifies down mealCosts if statements
// returns cost of the meal unless otherwise not allowed
static double addMealFee(int day, int numberOfDays, double constMealCost, int departTime, int returnTime, int departTimeDeadline, int returnTimeDeadline)
{
    if(day == 0) // If First Day
    {
        // First day breakfast (Breakfast Allowed only if arriving before 7 AM)
        // First day lunch (Lunch Allowed only if arriving before 12 PM)
        // First day dinner (Dinner Allowed only if arriving before 6 PM)
        if(departTime >= departTimeDeadline)
        {
            return 0;
        }

    }
    else if(day == numberOfDays-1) // If Last Day
    {
        // Last day breakfast (Breakfast allowed only if leaving after 8 AM)
        // Last day lunch (Lunch allowed only if leaving after 12 PM)
        // Last day lunch (Lunch allowed only if leaving after 7 PM)
        if(returnTime <= returnTimeDeadline)
        {
            return 0;
        }
    }

    return constMealCost;
}