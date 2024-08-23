#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>
#include "Definitions.h"

using namespace std;

class Alu
{
    public:
        Alu();
        void execute(string sOpcode, string sSource, string sDestination, Registers &cpuReg);

    private:
        Registers cpuReg;
        int cmdCount = 7;
        string validCmd [7] = {"ADD", "SUB", "IMUL", "AND", "OR", "XOR", "CMP"};
        int cmdAdd(int a, int b);
        int cmdSub(int a, int b);
        int cmdMul(int a, int b);
        int cmdAnd(int a, int b);
        int cmdOr(int a, int b);
        int cmdXor(int a, int b);
        int cmdCmp(int a, int b);
        int parseValue (string sValue, Registers &cpuReg);
        void assignValue(string sSource, int iDestination, Registers &cpuReg);
};

#endif // ALU_H
