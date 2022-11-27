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
/*
* calculate everything
*/

// double calculateTotalAllowable( ... takes in certain user input relevent to allowable expenses ... ) { returns total amount of allowable expenses the company must offer }
/*
* $6 parking fee / $10 taxi fee ~ per day
* $90 lodging per night
* breakfast, lunch, dinner ...
*/

// double calculateReimburseAmount() ~ returns total - allowable
// double calculateSavedAmount() ~ returns allowable - total


// other static methods

// help calculate allowable food expenses based on time of the day maybe
