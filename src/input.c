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
    char baddet; // a dummy var used merely for detecting bad scanf() conversions
    int num;
    double dec;
    printf("How many days did you stay?\n");
    scanf("%d", &num);
    while (num < 1){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    numberOfDays = num;

    //int departTime;
    printf("What is the departure time (24 hour time, give hour)?\n");
    scanf("%d", &num);
    while (num < 0 || num > 24){
        printf("Invalid, try again\n");
        scanf("%d", &num);
    }
    departTime = num;

    //int returnTime;
    printf("What is the return time (24 hour time, give hour)?\n");
    scanf("%d", &num);
    fflush(stdin);
    while (num < 0 || num > 24){
        printf("Invalid, try again\n");
        scanf("%d", &num);
        fflush(stdin);
    }
    returnTime = num;

    //double airfare;
    printf("What is the air fare?\n");
    scanf("%lf", &dec);
    fflush(stdin);
    while (dec < 0){
        printf("Invalid, try again\n");
        scanf("%lf", &dec);
        fflush(stdin);
    }
    airfare = dec;
    // printf("airfaire: %lf\n", airfare);

    //double carRentalCost;
    printf("What is the car rental cost?\n");
    scanf("%lf", &dec);
    fflush(stdin);
    while (dec < 0){
        printf("Invalid, try again\n");
        scanf("%lf", &dec);
        fflush(stdin);
    }
    carRentalCost = dec;

    //int milesDriven;
    printf("How many miles driven?\n");
    scanf("%d", &num);
    fflush(stdin);
    while (num < 0){
        printf("Invalid, try again\n");
        scanf("%d", &num);
        fflush(stdin);
    }
    milesDriven = num;

    //double registrationFees;
    printf("What is the registration Fee?\n");
    scanf("%lf", &dec);
    fflush(stdin);
    while (dec < 0){
        printf("Invalid, try again\n");
        scanf("%lf", &dec);
        fflush(stdin);
    }
    registrationFees = dec;

    //double hotelCost;
    printf("What is the hotel cost?\n");
    scanf("%lf", &dec);
    fflush(stdin);
    while (dec < 0){
        printf("Invalid, try again\n");
        scanf("%lf", &dec);
        fflush(stdin);
    }
    hotelCost = dec;
    
    return 0;
}