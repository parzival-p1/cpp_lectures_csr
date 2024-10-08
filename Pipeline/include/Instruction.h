#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
#include "Definitions.h"

using namespace std;

class Instruction
{
    public:
        Instruction();
        ~Instruction();

        string GetsOpcode() { return sOpcode; }
        void SetsOpcode(string val) { sOpcode = val; }
        string GetsSource() { return sSource; }
        void SetsSource(string val) { sSource = val; }
        string GetsDestination() { return sDestination; }
        void SetsDestination(string val) { sDestination = val; }
        int GetiCurrentState() { return iCurrentState; }
        void SetiCurrentState(int val) { iCurrentState = val; }
        void setAll(string sOpCode, string sSource, string sDestination, string sTag, int iCurrentState);
        void SetNext (Instruction *val) { next = val; }
        Instruction *GetNext() { return next; }

        string GetsTag() { return sTag; }
        void SetsTag(string val) { sTag = val; }

        // FUNCTIONS
        void printOperator();
        void printJump();
        void printTag();
        void print();

    protected:

    private:
        string sOpcode;
        string sSource;
        string sDestination;
        string sTag;
        int iCurrentState;
        Instruction *next;
};

#endif // INSTRUCTION_H
