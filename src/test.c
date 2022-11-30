#include <stdio.h>
#include <stdlib.h>
#include "../include/main.h"
#include <assert.h>
#define NDEBUG
void TestAllExpense1(){
    double parkingfee[2] = {2.4, 3.4};
    double taxingfee[2] = {2.0, 3.8};
    double mealcost[2][3] = {
            2.1, 2.2, 2.3,
            2.3, 8.7, 5.0
    };
    
    assert(calculateTotalAllowable(2, 3, 4, 5, parkingfee, taxingfee, 1, 2, mealcost)==5);
}
int main(){
    TestAllExpense1();
    return 0;
}