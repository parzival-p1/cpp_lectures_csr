#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

#include <iostream>

using namespace std;

class Registers {
    public:
    int Ax;
    int Bx;
    int Cx;
    int Dx;
    int IR;

    void cleanRegisters();
    void print();
};

#endif // DEFINITIONS_H_INCLUDED
