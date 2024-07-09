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
    string sLine, sWord;

    if (!file.is_open()) {
        cout<<"no se pudo abrir el archivo!";
        return false;
    }
    else
    {
        while(getline(file, sLine))
        {
            istringstream ssConversion(sLine);
            getline(ssConversion, sWord, ' ');
            cout<<sWord<<endl;
            getline(ssConversion, sWord, ' ');
            cout<<sWord<<endl;
            getline(ssConversion, sWord, ' ');
            cout<<sWord<<endl;
        }
        file.close();
        return true;
    }
}
