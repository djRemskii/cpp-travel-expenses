/** Author: Nicholas Amancio
 *  11/30/22
 *  CS 2600
 *  
 *  Test Cases for the methods
*/

#include <stdio.h>
#include <assert.h>

void TestCase1();
void TestCase2();
void TestCase3();
void TestCase4();
void TestCase5();


void calculateTest1() { 
    Assert.IsEqual(calculateTotalExpenses(4, 90.50, 30.75, 150, [8, 8, 8, 8], [0, 0, 0, 0], 50.99, 610, [15, 15, 15][3]), 1004.74);
    Assert.IsEqual(calculateAllowableExpenses(4, 10, 17, [8, 8, 8, 8], [0, 0, 0, 0], [15, 15, 15][3]), 507);
    Assert.IsEqual(calculateReimburseAmount(1004.74, 507), 497.74);
    Assert.IsEqual(calculateSavedAmount(1004.74, 507), -497.74);
}

void calculateTest2() { 
    Assert.IsEqual(calculateTotalExpenses(2, 45.99, 75.50, 50, [8, 8], [0, 0], 65.89, 995.14, [15, 15, 15][3]), 1,287.02);
    Assert.IsEqual(calculateAllowableExpenses(2, 6, 12, [8, 8], [0, 0], [15, 15, 15][3]), 250);
    Assert.IsEqual(calculateReimburseAmount(1,287.02, 250), 1,037.02);
    Assert.IsEqual(calculateSavedAmount(1004.74, 507), -1,037.02);
}

void calculateTest3() { 
    Assert.IsEqual(calculateTotalExpenses(3, 104.09, 0, 0, [0, 0, 0], [26.54, 45.31, 28.91], 25, 478.34, [7, 14.50, 17.77][3]), 765.23);
    Assert.IsEqual(calculateAllowableExpenses(3, 13, 5, [0, 0, 0], [26.54, 45.31, 28.91], [7, 14.50, 17.77][3]), 507);
    Assert.IsEqual(calculateReimburseAmount(765.23, 353), 412.23);
    Assert.IsEqual(calculateSavedAmount(765.23, 353), -412.23);
}

void calculateTest4() { 
    Assert.IsEqual(calculateTotalExpenses(5, 79.99, 25.99, 16, [8, 8, 0, 0, 0], [0, 0, 12.50, 13.75, 11.65], 55.5, 535.79, [12.50, 15.50, 19.50][3]), 932.74);
    Assert.IsEqual(calculateAllowableExpenses(5, 10, 2, [8, 8, 0, 0, 0], [0, 0, 12.50, 13.75, 11.65], [12.50, 15.50, 19.50][3]), 631);
    Assert.IsEqual(calculateReimburseAmount(932.74, 631), 301.74);
    Assert.IsEqual(calculateSavedAmount(932.74, 631), -301.74);
}

void calculateTest5() { 
    Assert.IsEqual(calculateTotalExpenses(6, 82.59, 46.67, 56, [7, 0, 10, 0, 7, 7], [0, 26.37, 0, 14.22, 0, 0], 75, 792.84, [11.50, 13.60, 19.37][3]), 1319.76);
    Assert.IsEqual(calculateAllowableExpenses(6, 11, 14, [7, 0, 10, 0, 7, 7], [0, 26.37, 0, 14.22, 0, 0], [11.50, 13.60, 19.37][3]), 776);
    Assert.IsEqual(calculateReimburseAmount(1319.76, 776), 543.76);
    Assert.IsEqual(calculateSavedAmount(1319.76, 776), -543.76);
}



/*
    double calculateTotalExpenses(int numberOfDays, double airfare, double carRentalCost, int milesDriven, double parkingFees[], 
                                    double taxiFees[], double registrationFees, double hotelCost, double a_mealCosts[][3])
    double calculateAllowableExpenses(int numberOfDays, int departTime, int returnTime, double parkingFees[], double taxiFees[], double mealFees[][3])
    double calculateReimburseAmount(double total, double allowable)
    double calculateSavedAmount(double total, double allowable)
*/