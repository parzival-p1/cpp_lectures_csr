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

    if (!file.is_open()) {
        cout<<"no se pudo abrir el archivo!";
        return false;
    }
    else
    {
        cout<<"Si abrio!";
        // t a r e a: LEER EL ARCHIVO
        file.close();
        return true;
    }
}

