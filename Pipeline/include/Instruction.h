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
        void changeState() { if (iCurrentState != END) iCurrentState++; }
        void setAll(string sOpCode, string sSource, string sDestination, string sTag, int iCurrentState);
        void SetNext (Instruction *val) { next = val; }
        Instruction *GetNext() { return next; }
        void SetPrev (Instruction *val) { prev = val; }
        Instruction *GetPrev() { return prev; }

        string GetsTag() { return sTag; }
        void SetsTag(string val) { sTag = val; }

        // FUNCTIONS
        void printOperator();
        void printJump();
        void printTag();
        bool print();
        string printState();

    protected:

    private:
        string sOpcode;
        string sSource;
        string sDestination;
        string sTag;
        bool bExecute;
        int iCurrentState;
        Instruction *next;
        Instruction *prev;
};

#endif // INSTRUCTION_H
