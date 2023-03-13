#ifndef OPTIONS_H
#define OPTIONS_H
#include <QMainWindow>
#include <stdio.h>
#define ERROR 98765e-99

struct options{
    double num1;
    double num2;
    char* operation;
};

struct Result {
    char error[20];
    double value;
    int code;
};

double operate(struct options options);
double trigOperations(struct options options);

#endif // OPTIONS_H
