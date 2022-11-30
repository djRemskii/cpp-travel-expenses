#include <stdio.h>
#include <stdlib.h>
#include "../include/main.h"

int numberOfDays;
int departTime;
int returnTime;
double airfare;
double carRentalCost;
int milesDriven;
double registrationFees;
double hotelCost;

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
    int num;
    printf("How many days did you stay?\n");
    scanf("%d", &num);
    while (num < 1){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    numberOfDays = num;

    //int departTime;
    printf("What is the departure time (24 hour time, give hour)?\n");
    scanf("%d", &departTime);
    departTime = num;

    //int returnTime;
    printf("What is the return time (24 hour time, give hour)?\n");
    scanf("%d", &num);
    returnTime = num;

    //double airfare;
    printf("What is the air fare?\n");
    scanf("%d", &num);
    while (num < 0){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    airfare = num;

    //double carRentalCost;
    printf("What is the car rental cost?\n");
    scanf("%d", &carRentalCost);
    while (num < 0){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    carRentalCost = num;

    //int milesDriven;
    printf("How many miles driven?\n");
    scanf("%d", &num);
    while (num < 0){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    milesDriven = num;

    //double registrationFees;
    printf("What is the registration Fee?\n");
    scanf("%d", &num);
    while (num < 0){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    registrationFees = num;

    //double hotelCost;
    printf("What is the hotel cost?\n");
    scanf("%d", &num);
    while (num < 0){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    hotelCost = num;
    
    return 0;
}

/*
int getMultidayInputs(){
    for (int i = 0; i < numberOfDays; i++){
        int num;
        printf("What is the parking fee for day %d\n", i + 1);
        scanf("%d", &num);
        while (num < 0){
            printf("Invalid, try again\n");
            scanf("%d", &num);
        }
        parkingFees[i] = num;
    }

    //double taxiFees[numberOfDays];
    for (int i = 0; i < numberOfDays; i++){
        int num;
        printf("What is the taxi fee for day %d\n", i + 1);
        scanf("%d", &num);
        while (num < 0){
            printf("Invalid, try again\n");
            scanf("%d", &num);
        }
        taxiFees[i] = num;
    }

    //double mealCosts[numberOfDays][3];
    for (int i = 0; i < numberOfDays; i++){
        char arr[3][10] = {"Breakfast", "Lunch", "Dinner"};
        for (int j = 0; j < 3; j++){
            printf("Pick meal cost for %s for day %d\n", arr[j], i + 1);
            int num;
            scanf("%d", &num);
            while (num < 0){
                printf("Invalid, try again\n");
                scanf("%d", &num);
            }
            mealCosts[i][j] = num;
        }
    }

    return 0;
}
*/