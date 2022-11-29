/** Author: Nicholas Amancio
 *  11/30/22
 *  CS 2600
 *  
 *  Test Cases for the methods
*/

#include <stdio.h>

int main {
    void TestCase1();
    void TestCase2();
    void TestCase3();
    void TestCase4();
    void TestCase5();

    void calculateTest1() { 
    Assert.IsEqual(calculateTotalExpenses(), [EXPECTED ANSWER]);
    Assert.IsEqual(calculateTotalAllowable(), [EXPECTED ANSWER]);
    Assert.IsEqual(calculateReimburseAmount(), [EXPECTED ANSWER]);
    Assert.IsEqual(calculateSavedAmount(), [EXPECTED ANSWER]);
 }
    return 0;
}

/*
    totalExpenses = calculateTotalExpenses(numberOfDays, airfare, carRentalCost, milesDriven, parkingFees, taxiFees, registrationFees, hotelCost, mealCosts);
    totalAllowable = calculateTotalAllowable(numberOfDays, departTime, returnTime, parkingFees, taxiFees);
    reimburseAmount = calculateReimburseAmount(totalExpenses, totalAllowable);
    savedAmount = calculateSavedAmount(totalExpenses, totalAllowable);
*/