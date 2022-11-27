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
double calculateTotalExpenses(double airfare, double carRentalCost, int milesDriven, double parkingFees[], double taxiFees[], double registrationFees, double hotelCost, double a_mealCosts[][3])
{
    double totalCost = 0;

    const double costPerMile = 0.27; // per mile driven = $0.27
    double parkingCosts = 0;
    double taxiCosts = 0;
    double mealCosts = 0;
    int sizeP = sizeof(parkingFees)/sizeof(parkingFees[0]);
    int sizeT = sizeof(taxiFees)/sizeof(taxiFees[0]);
    int sizeM = sizeof(sizeM)/sizeof(taxiFees[0]);

    for (int i = 0; i < sizeP; i++)
    {
        /* code */
        parkingCosts += parkingFees[i];
    }

    for (int i = 0; i < sizeT; i++)
    {
        /* code */
        taxiCosts += taxiFees[i];
    }

    for (int i = 0; i < sizeM; i++)
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
double calculateAllowableExpenses(int numberOfDays, int departTime, int returnTime, int milesDriven)
{
    return 0.0;
}

// double calculateReimburseAmount() ~ returns total - allowable
// double calculateSavedAmount() ~ returns allowable - total
double calculateReimburseAmount(double total, double allowable)
{
    return (total - allowable); 
}

// double calculateSavedAmount() ~ returns allowable - total
double calculateSavedAmount(double total, double allowable)
{
    return (allowable - total);
}
