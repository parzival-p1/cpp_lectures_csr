#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED
#include <iostream>

using std::cout;
using std::endl;

// Init = Inicio, IF = Instruction Fetch, ID = Instruction Decode, EX = Execute, MEM = Memory, WB = Write back, CO = Commit, END = Final
enum STATUS { INIT, IF, ID, EX, MEM, WB, CO, END };

class Registers {
    public:
    int Ax;
    int Bx;
    int Cx;
    int Dx;
    int IR;

    void cleanRegisters()
    {
        Ax = Bx = Cx = Dx = IR = 0;
    }

    void print()
    {
        cout<<"Ax: "<<Ax<<endl;
        cout<<"Bx: "<<Bx<<endl;
        cout<<"Cx: "<<Cx<<endl;
        cout<<"Dx: "<<Dx<<endl;
        cout<<"IR: "<<IR<<endl;
    }
};

#endif // DEFINITIONS_H_INCLUDED
