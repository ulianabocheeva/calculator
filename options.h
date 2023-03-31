#ifndef OPTIONS_H
#define OPTIONS_H
#include <QMainWindow>
#include <stdio.h>
#define ERROR 98765e-99

enum FuncType
{
    operate,
    trigOperations
};

struct options{
    double num1;
    double num2;
    char* operation;
};

double entryPoint(FuncType ft, struct options options);

#endif // OPTIONS_H
