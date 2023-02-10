#include "iostream"
#include "head.h"

void changeRL(double &x, double &y) {

    if (x > y){

        x = x - y;
    }
    else {

        std::cout << "Error";
    }
}

void changeRP(double *x, double *y) {

    if (*x > *y){

        double result;
        result = *x - *y;
        *x = result;
    }
    else {

        std::cout << "Error";
    }
}