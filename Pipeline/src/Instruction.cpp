#include "Instruction.h"

Instruction::Instruction()
{
    sOpcode = "";
    sSource = "";
    sDestination = "";
    sTag = "";
    iCurrentState = INIT;    next = NULL;
}

Instruction::~Instruction()
{
    //dtor
}

void Instruction::setAll(string sOpCode, string sSource, string sDestination, string sTag, int iCurrentState)
{
    this->sOpcode = sOpcode;
    this->sSource = sSource;
    this->sDestination = sDestination;
    this->sTag = sTag;
    this->iCurrentState = iCurrentState;
}

void Instruction::printOperator()
{
    // imprimir de manera directa.
    cout<<sOpcode<<" "<<sSource<<" "<<sDestination<<" "<<iCurrentState<<" "<<endl;
}

void Instruction::printJump()
{
    // imprimir de manera directa.
    cout<<sOpcode<<" "<<sTag<<" "<<iCurrentState<<" "<<endl;
}

void Instruction::printTag()
{
    // imprimir de manera directa.
    cout<<sTag<<" "<<iCurrentState<<" "<<endl;
}

void Instruction::print()
{
    if (sOpcode == "")
        printTag();
    else if (sOpcode == "JMP")
        printJump();
    else
        printOperator();
}
