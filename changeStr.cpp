#include "iostream"
#include "head.h"

void changeStrL(int(&matrix)[3][3], int &x, int &y){

    for (int i = 0; i < 3; ++i) {
        int vrem = matrix[x][i];
        matrix[x][i] = matrix[y][i];
        matrix[y][i] = vrem;
    }
}

void changeStrP(int(*matrix)[3][3], int *x, int *y){

    for (int i = 0; i < 3; ++i) {
        int vrem = *matrix[*x][i];
        *matrix[*x][i] = *matrix[*y][i];
        *matrix[*y][i] = vrem;
    }
}