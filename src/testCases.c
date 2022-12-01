/** Author: Nicholas Amancio
 *  11/30/22
 *  CS 2600
 *  
 *  Test Cases for the methods
*/
#include "../include/main.h"
#include <stdio.h>
#include <assert.h>

/*
void TestCase1();
void TestCase2();
void TestCase3();
void TestCase4();
void TestCase5();
*/

void calculateTest1() { 

    numberOfDays = 4;
    departTime = 10;
    returnTime =  17;
    airfare = 90.50;
    carRentalCost = 30.75;
    milesDriven = 150;
    registrationFees = 50.99;
    hotelCost = 610;

    double parkingFee[] = {8, 8, 8, 8};
    double taxiFee[] = {0, 0, 0, 0};
    double foodFee[4][3] = {0, 15, 15}, {15, 15, 15}, {15, 15, 15} {15, 15, 0};

    double totalExpenses = calculateTotalExpenses(numberOfDays, airfare, carRentalCost, milesDriven, parkingFees, taxiFees, registrationFees, hotelCost, mealCosts);
    double totalAllowable = calculateAllowableExpenses(numberOfDays, departTime, returnTime, parkingFees, taxiFees, mealCosts); 
    double totalUsedAllowable = calculateUsedAllowableExpenses(numberOfDays, departTime, returnTime, parkingFees, taxiFees, mealCosts, hotelCost); 
    double reimburseAmount = calculateReimburseAmount(totalExpenses, totalUsedAllowable);
    double savedAmount = calculateSavedAmount(totalAllowable, totalUsedAllowable);

    Assert.IsEqual(calculateTotalExpenses(4, 90.50, 30.75, 150, parkingFee, taxiFee, 50.99, 610, foodFee), 1004.74);
    Assert.IsEqual(calculateAllowableExpenses(4, 10, 17, parkingFee, taxiFee, foodFee), 507);
    Assert.IsEqual(calculateUsedAllowableExpenses(4, 10, 17, parkingFee, taxiFee, foodFee, 90.50), [EXPECTED HERE])
    Assert.IsEqual(calculateReimburseAmount(1004.74, 507), 497.74);
    Assert.IsEqual(calculateSavedAmount(507, UAE HERE), -497.74);
}

void calculateTest2() { 
    double parkingFee[] = {8, 8};
    double taxiFee[] = {0, 0};
    double foodFee[2][3] = {15, 15, 15}, {15, 15, 0};

    Assert.IsEqual(calculateTotalExpenses(2, 45.99, 75.50, 50, parkingFee, taxiFee, 65.89, 995.14, foodFee), 1,287.02);
    Assert.IsEqual(calculateAllowableExpenses(2, 6, 12, parkingFee, taxiFee, foodFee), 250);
    Assert.IsEqual(calculateReimburseAmount(1,287.02, 250), 1,037.02);
    Assert.IsEqual(calculateSavedAmount(1004.74, 507), -1,037.02);
}

void calculateTest3() { 
    double parkingFee[] = {0, 0, 0};
    double taxiFee[] = {26.54, 45.31, 28.91};
    double foodFee[3][3] = {0, 0, 17.77}, {7, 14.50, 17.77}, {0, 0, 0};

    Assert.IsEqual(calculateTotalExpenses(3, 104.09, 0, 0, parkingFee, taxiFee, 25, 478.34, foodFee), 765.23);
    Assert.IsEqual(calculateAllowableExpenses(3, 13, 5, parkingFee, taxiFee, foodFee), 507);
    Assert.IsEqual(calculateReimburseAmount(765.23, 353), 412.23);
    Assert.IsEqual(calculateSavedAmount(765.23, 353), -412.23);
}

void calculateTest4() { 
    double parkingFee[] = {8, 8, 0, 0, 0};
    double taxiFee[] = {0, 0, 12.50, 13.75, 11.65};
    double foodFee[5][3] = {0, 15.50, 19.50}, {12.50, 15.50, 19.50}, {12.50, 15.50, 19.50}, {12.50, 15.50, 19.50}, {0, 0, 0};

    Assert.IsEqual(calculateTotalExpenses(5, 79.99, 25.99, 16, parkingFee, taxiFee, 55.5, 535.79, foodFee), 932.74);
    Assert.IsEqual(calculateAllowableExpenses(5, 10, 2, parkingFee, taxiFee, foodFee), 631);
    Assert.IsEqual(calculateReimburseAmount(932.74, 631), 301.74);
    Assert.IsEqual(calculateSavedAmount(932.74, 631), -301.74);
}

void calculateTest5() { 
    double parkingFee[] = {7, 0, 10, 0, 7, 7};
    double taxiFee[] = {0, 26.37, 0, 14.22, 0, 0};
    double foodFee[6][3] = {0, 13.60, 19.37} {11.50, 13.60, 19.37} {11.50, 13.60, 19.37} {11.50, 13.60, 19.37} {11.50, 13.60, 19.37} {11.50, 13.60, 0};

    Assert.IsEqual(calculateTotalExpenses(6, 82.59, 46.67, 56, parkingFee, taxiFee, 75, 792.84, foodFee), 1319.76);
    Assert.IsEqual(calculateAllowableExpenses(6, 11, 14, parkingFee, taxiFee, foodFee), 776);
    Assert.IsEqual(calculateReimburseAmount(1319.76, 776), 543.76);
    Assert.IsEqual(calculateSavedAmount(1319.76, 776), -543.76);
}



/*
    double calculateTotalExpenses(int numberOfDays, double airfare, double carRentalCost, int milesDriven, double parkingFees[], 
                                    double taxiFees[], double registrationFees, double hotelCost, double a_mealCosts[][0, 1, 2])
    double calculateAllowableExpenses(int numberOfDays, int departTime, int returnTime, double parkingFees[], double taxiFees[], double mealFees[][0, 1, 2])
    double calculateReimburseAmount(double total, double allowable)
    double calculateSavedAmount(double total, double allowable)erg ergerg ergb iklb werafgwerageragwerageragyuilbwerafguilb r
*/