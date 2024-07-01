#include "Decoder.h"

Decoder::Decoder(string sFileName)
{
    this->sFileName = sFileName;
}

Decoder::~Decoder()
{
    //dtor
}

bool Decoder::start(InstructionList &List)
{
    ifstream file(sFileName);

    if (!file.is_open())
        return false;
    else
    {

    }
}

