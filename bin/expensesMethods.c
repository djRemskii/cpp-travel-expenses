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
double calculateAllowableExpenses(int numberOfDays, int departTime, int returnTime, double parkingFees[], double taxiFees[])
{
    double totalAllowed = 0;

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
            parkingCosts += allowableTaxiExpense;
        }
    }

    double hotelCosts = 90 * numberOfDays;

    const double breakfastCost = 9.0;
    const double lunchCost = 12.0;
    const double dinnerCost = 16.0;
    const double costOfMealsPerDay = breakfastCost + lunchCost + dinnerCost;
    double mealCosts = costOfMealsPerDay * (numberOfDays - 2); // excluding first and last day

    // First day meals
    if(departTime < 7)
    {
        mealCosts += breakfastCost + lunchCost + dinnerCost;
    }
    else if(departTime < 12)
    {
        mealCosts += lunchCost + dinnerCost;
    }
    else if(departTime < 18)
    {
        mealCosts += dinnerCost;
    } 

    // Last day meals
    if(departTime > 19) 
    {
        mealCosts += breakfastCost + lunchCost + dinnerCost;
    }
    else if(departTime > 12)
    {
        mealCosts += breakfastCost + lunchCost;
    }
    else if(departTime > 8)
    {
        mealCosts += breakfastCost;
    }


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
