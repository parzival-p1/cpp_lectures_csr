#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>

using namespace std;

class Alu
{
    public:
        Alu();
        int execute(string sOpcode, string sSource, string sDestination);

    private:
        string validCmd [] = {"ADD", "SUB", "IMUL", "AND", "OR", "XOR", "CMP"};
        int cmdCount = 7;

        int cmdAdd(int a, int b);
        int cmdSub(int a, int b);
        int cmdMul(int a, int b);
        int cmdAnd(int a, int b);
        int cmdOr(int a, int b);
        int cmdXor(int a, int b);
        int cmdCmp(int a, int b);
};

#endif // ALU_H
