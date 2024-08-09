#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

enum STATUS { INIT, IF, ID, EX, MEM, WB, CO, END };

struct Registers {
int Ax;
int Bx;
int Cx;
int Dx;
int IR;
};


#endif // DEFINITIONS_H_INCLUDED
