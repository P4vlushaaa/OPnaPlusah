#include "iostream"
#include "head.h"

void reverseNumL(double&x) {

     x = 1 / x;
}

void reverseNumP(double*x) {

    double result;
    result = 1 / *x;
    *x = result;
}