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

    double parkingFee[] = {8, 8, 8, 8};
    double taxiFee[] = {0, 0, 0, 0};
    double foodFee[4][3] = {{0, 15, 15}, {15, 15, 15}, {15, 15, 15}, {15, 15, 0}};


    double totalCost = calculateTotalExpenses(4, 90.50, 30.75, 150, parkingFee, taxiFee, 50.99, 610, foodFee);
    double allowed = calculateAllowableExpenses(4, 10, 17, parkingFee, taxiFee, foodFee);
    double used = calculateUsedAllowableExpenses(4, 10, 17, parkingFee, taxiFee, foodFee, 610);
    double reimburse = calculateReimburseAmount(1004.74, 507);
    double saved = calculateSavedAmount(1004.74, 507);

    assert(totalCost == 1004.74);
    assert(allowed == 507);
    assert(reimburse == 497.74);
    assert(saved == -497.74);
}

void calculateTest2() { 
    double parkingFee[] = {8, 8};
    double taxiFee[] = {0, 0};
    double foodFee[2][3] = {{15, 15, 15}, {15, 15, 0}};

    double totalCost = calculateTotalExpenses(2, 45.99, 75.50, 50, parkingFee, taxiFee, 65.89, 995.14, foodFee);
    double allowed = calculateAllowableExpenses(2, 6, 12, parkingFee, taxiFee, foodFee);
    double used = calculateUsedAllowableExpenses(2, 6, 12, parkingFee, taxiFee, foodFee, 995.14);
    double reimburse = calculateReimburseAmount(1,287.02, 250);
    double saved = calculateSavedAmount(1004.74, 507);

    assert(totalCost == 1287.02);
    assert(allowed = 250);
    assert(reimburse == 1037.02);
    assert(saved == -1037.02);
}

void calculateTest3() { 
    double parkingFee[] = {0, 0, 0};
    double taxiFee[] = {26.54, 45.31, 28.91};
    double foodFee[3][3] = {{0, 0, 17.77}, {7, 14.50, 17.77}, {0, 0, 0}};

    double totalCost = calculateTotalExpenses(3, 104.09, 0, 0, parkingFee, taxiFee, 25, 478.34, foodFee);
    double allowed = calculateAllowableExpenses(3, 13, 5, parkingFee, taxiFee, foodFee);
    double used = calculateUsedAllowableExpenses(3, 13, 5, parkingFee, taxiFee, foodFee, 478.34);
    double reimburse = calculateReimburseAmount(765.23, 353);
    double saved = calculateSavedAmount(765.23, 353);

    printf("%.2f\n", totalCost);
    printf("%.2f\n", allowed);
    printf("%.2f\n", used);
    printf("%.2f\n", reimburse);
    printf("%.2f\n", saved);

    assert(totalCost == 740.23);
    assert(allowed == 353);
    assert(reimburse == 389.23);
    assert(saved == 2.00);
}

void calculateTest4() { 
    double parkingFee[] = {8, 8, 0, 0, 0};
    double taxiFee[] = {0, 0, 12.50, 13.75, 11.65};
    double foodFee[5][3] = {{0, 15.50, 19.50}, {12.50, 15.50, 19.50}, {12.50, 15.50, 19.50}, {12.50, 15.50, 19.50}, {0, 0, 0}};

    double totalCost = calculateTotalExpenses(5, 79.99, 25.99, 16, parkingFee, taxiFee, 55.5, 535.79, foodFee);
    double allowed = calculateAllowableExpenses(5, 10, 2, parkingFee, taxiFee, foodFee);
    double used = calculateUsedAllowableExpenses(5, 10, 2, parkingFee, taxiFee, foodFee, 535.79);
    double reimburse = calculateReimburseAmount(totalCost, used);
    double saved = calculateSavedAmount(allowed, used);

    assert(totalCost == 932.99);
    assert(allowed == 631);
    assert(reimburse == 301.99);
    assert(saved == 0);

    printf("Test 4 Successful");
}


void calculateTest5() { 
    double parkingFee[] = {7, 0, 10, 0, 7, 7};
    double taxiFee[] = {0, 26.37, 0, 14.22, 0, 0};
    double foodFee[6][3] = {{0, 13.60, 19.37}, {11.50, 13.60, 19.37}, {11.50, 13.60, 19.37}, {11.50, 13.60, 19.37}, {11.50, 13.60, 19.37}, {11.50, 13.60, 0}};

    double totalCost = calculateTotalExpenses(6, 82.59, 46.67, 56, parkingFee, taxiFee, 75.0, 792.84, foodFee); 
    double allowed = calculateAllowableExpenses(6, 11, 14, parkingFee, taxiFee, foodFee);
    double used = calculateUsedAllowableExpenses(6, 11, 14, parkingFee, taxiFee, foodFee, 792.84);
    double reimburse = calculateReimburseAmount(totalCost, used);
    double saved = calculateSavedAmount(allowed, used);

    assert(totalCost == 1319.76);
    assert(allowed == 781.00);
    assert(reimburse == 538.76);
    assert(saved == 0);

    printf("Test 5 Successful");
}



/*
    double calculateTotalExpenses(int numberOfDays, double airfare, double carRentalCost, int milesDriven, double parkingFees[], 
                                    double taxiFees[], double registrationFees, double hotelCost, double a_mealCosts[][0, 1, 2])
    double calculateAllowableExpenses(int numberOfDays, int departTime, int returnTime, double parkingFees[], double taxiFees[], double mealFees[][0, 1, 2])
    double calculateReimburseAmount(double total, double allowable)
    double calculateSavedAmount(double total, double allowable)erg ergerg ergb iklb werafgwerageragwerageragyuilbwerafguilb r
*/