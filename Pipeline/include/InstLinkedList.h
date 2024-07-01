#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H
#include "Instruction.h"

class InstructionList
{
    public:
        InstructionList();
        ~InstructionList();
        InstructionList(const InstructionList& other);

        Instruction *Gethead() { return head; }
        void Sethead(Instruction *val) { head = val; }

        bool isEmpty();
        void insertLast(Instruction *newNode);
        void deleteBegin();
        void deleteAll();
        void print();

    protected:

    private:
        Instruction *head;
};

#endif // INSTRUCTIONLIST_H
