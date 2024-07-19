#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "Instruction.h"

class InstructionList
{
    public:
        InstructionList();
        ~InstructionList();
        InstructionList(const InstructionList& other);

        unsigned int Getlast() { return last; }
        void Setlast(unsigned int val) { last = val; }
        unsigned int GetMAX() { return MAX; }
        void SetMAX (unsigned int val) { MAX = val; }

        // FUNCTIONS
        bool isFull();
        bool isEmpty();
        void resizeList();
        void insertLast(Instruction *newNode);
        void deleteFst();
        void deleteAll();
        void print();

    protected:

    private:
        unsigned int last;
        unsigned int MAX;
        Instruction *List;
};

#endif // INSTRUCTIONLIST_H
