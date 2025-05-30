#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H
#include "Instruction.h"
#include "Alu.h"

using namespace std;

class InstructionList
{
    public:
        InstructionList();
        ~InstructionList();

        Instruction *Gethead() { return head; }
        void Sethead(Instruction *val) { head = val; }

        bool isEmpty();
        void insertLast(Instruction *newNode);
        void deleteBegin();
        void deleteAll();
        void print(Alu &alu, Registers &registers);
        Instruction *getNextNode(Instruction *currentNode);
        bool instEndState ();
        void changeInstructionState();
        int GetInstructionCount(){ return instructionCount; }
        int GetTotalCount(){ return totalCount; }
        void configListToExecute(int maxInstructions);
        void resetList();

    protected:

    private:
        Instruction *head;
        int instructionCount;
        int totalCount;
        Instruction *waitList;
};

#endif // INSTRUCTIONLIST_H
