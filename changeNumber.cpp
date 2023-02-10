#include "iostream"
#include "head.h"

void changeNumberL(int &x, int&y){

    if (x > y){
        x = x % y;
    }
    else{
        y = y % x;
    }
}

void changeNumberP(int *x, int*y){

    int result;
    if (x > y){
        result = *x % *y;
        *x = result;
    }
    else{
        result = *y % *x;
        *y = result;
    }
}