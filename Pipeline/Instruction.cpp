#include "Instruction.h"

Instruction::Instruction()
{
    sOpcode = "";
    sSource = "";
    sDestination = "";
    sTag = "";
    iCurrentState = INIT;
    next = NULL;
    prev = NULL;
    bExecute = false;
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
    cout<<"\t-- "<<sOpcode<<" "<<sSource<<" "<<sDestination<<" - State: "<<printState()<<endl;
}

void Instruction::printJump()
{
    // imprimir de manera directa.
    cout<<"\t-- "<<sOpcode<<" "<<sTag<<" - State: "<<printState()<<endl;
}

void Instruction::printTag()
{
    // imprimir de manera directa.
    cout<<"\t-- "<<sTag<<" - State: "<<printState()<<endl;
}

bool Instruction::print()
{
    if (sOpcode == "")
        printTag();
    else if (sOpcode == "JMP")
        printJump();
    else
        printOperator();

    return bExecute;
}

string Instruction::printState()
{
    string strCurrentState;
    bExecute = false;

    switch (iCurrentState)
    {
        case INIT: strCurrentState = "INIT State"; break;
        case IF: strCurrentState = "IF Instruction Fetch"; break;
        case ID: strCurrentState = "ID Instruction Decode"; break;
        case EX: strCurrentState = "EX Execute"; bExecute = true; break;
        case MEM: strCurrentState = "MEM Memory"; break;
        case WB: strCurrentState = "WB Write Back"; break;
        case CO: strCurrentState = "CO Commit"; break;
        case END: strCurrentState = "END State"; break;
        default: strCurrentState = "Error State"; break;
    }
    return strCurrentState;
}


