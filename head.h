#ifndef UNTITLED_HEAD_H
#define UNTITLED_HEAD_H

void changeNumberL(int &x, int &y);
void changeNumberP(int *x, int *y);

void reverseNumL(double &x);
void reverseNumP(double *x);

void changeRP(double &x, double &y);
void changeRL(double *x, double *y);

void changeStrP(int(&matrix)[3][3], int &x, int &y);
void changeStrL(int(*matrix)[3][3], int *x, int *y);

#endif
