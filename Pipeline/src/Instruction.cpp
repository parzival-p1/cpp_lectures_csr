#include "Instruction.h"

Instruction::Instruction()
{
    sOpcode = "";
    sSource = "";
    sDestination = "";
    iCurrentState = 0;
    next = NULL;
}

Instruction::~Instruction()
{
    //dtor
}

void Instruction::setAll(string sOpCode, string sSource, string sDestination, int iCurrentState)
{
    this->sOpcode = sOpcode;
    this->sSource = sSource;
    this->sDestination = sDestination;
    this->iCurrentState = iCurrentState;
}

void Instruction::print()
{
    // imprimir de manera directa.
    cout<<sOpcode<<" "<<sSource<<" "<<sDestination<<" "<<iCurrentState<<" ";
}
