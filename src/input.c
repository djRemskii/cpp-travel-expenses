#include <stdio.h>
#include <stdlib.h>
#include "../include/main.h"

int numberOfDays;
int departTime;
int returnTime;
double airfare;
double carRentalCost;
int milesDriven;
double* parkingFees;
double* taxiFees;
double registrationFees;
double hotelCost;
double* mealCosts[];

void printIntro(){
    printf("Travel Expenses Simulation created by:\n");
    printf("\tNicolas Amancio\n");
    printf("\tRemi Ong\n");
    printf("\tToby Thap\n");
    printf("\tMinh Tran\n");
    printf("\tMatthew Yu\n\n");
}

int getUserInputs(){
    //int numberOfDays;
    printf("How many days did you stay?\n");
    scanf("%d", &numberOfDays);
    while (numberOfDays < 1){
        printf("Invalid, try again\n");
        scanf("%d", &numberOfDays);
    }

    double* tempMealCosts[numberOfDays];

    double* tempParkingFees = malloc(numberOfDays * sizeof(double));
    double* tempTaxiFees = malloc(numberOfDays * sizeof(double));
    for (int i=0; i<numberOfDays; i++){
        tempMealCosts[i] = (double*)malloc(3 * sizeof(double));
    }

    //int departTime;
    printf("What is the departure time (24 hour time, give hour)?\n");
    scanf("%d", &departTime);
    departTime = departTime % 12;
    fflush(stdin);
    //int returnTime;
    printf("What is the return time (24 hour time, give hour)?\n");
    scanf("%d", &returnTime);
    returnTime = returnTime % 12;
    fflush(stdin);
    //double airfare;
    printf("What is the air fare?\n");
    scanf("%f", &airfare);
    while (airfare < 0){
        printf("Invalid, try again\n");
        scanf("%f", &airfare);
    }
    fflush(stdin);
    //double carRentalCost;
    printf("What is the car rental cost?\n");
    scanf("%f", &carRentalCost);
    while (carRentalCost < 0){
        printf("Invalid, try again\n");
        scanf("%f", &carRentalCost);
    }
    fflush(stdin);
    //int milesDriven;
    printf("How many miles driven?\n");
    scanf("%d", &milesDriven);
    while (milesDriven < 0){
        printf("Invalid, try again\n");
        scanf("%d", &milesDriven);
    }
    fflush(stdin);
    //double parkingFees[numberOfDays];
    for (int i = 0; i < numberOfDays; i++){
        int num;
        printf("What is the parking fee for day %d\n", i + 1);
        scanf("%f", &parkingFees[i]);
        while (num < 0){
            printf("Invalid, try again\n");
            scanf("%f", &parkingFees[i]);
        }
    }
    fflush(stdin);
    //double taxiFees[numberOfDays];
    for (int i = 0; i < numberOfDays; i++){
        int num;
        printf("What is the taxi fee for day %d\n", i + 1);
        scanf("%f", &taxiFees[i]);
        while (num < 0){
            printf("Invalid, try again\n");
            scanf("%f", &taxiFees[i]);
        }
    }
    fflush(stdin);
    //double registrationFees;
    printf("What is the registration Fee?\n");
    scanf("%f", &registrationFees);
    while (registrationFees < 0){
        printf("Invalid, try again\n");
        scanf("%f", &registrationFees);
    }
    fflush(stdin);
    //double hotelCost;
    printf("What is the hotel cost?\n");
    scanf("%f", &hotelCost);
    while (hotelCost < 0){
        printf("Invalid, try again\n");
        scanf("%f", &hotelCost);
    }
    fflush(stdin);
    //double mealCosts[numberOfDays][3];
    for (int i = 0; i < numberOfDays; i++){
        char arr[3][10] = {"Breakfast", "Lunch", "Dinner"};
        for (int j = 0; j < 3; j++){
            printf("Pick meal cost for %s for day %d\n", arr[j], i + 1);
            int num;
            scanf("%f", &mealCosts[i][j]);
            while (num < 0){
                printf("Invalid, try again\n");
                scanf("%f", &mealCosts[i][j]);
            }
        }
    }
    fflush(stdin);
    return 0;
}