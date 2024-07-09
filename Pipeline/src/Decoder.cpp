#include "Decoder.h"

Decoder::Decoder(string sFileName)
{
    this->sFileName = sFileName;
}

Decoder::~Decoder()
{
    //dtor
}

int Decoder::wordCount(string sLine)
{
    // T A R E A
}

bool Decoder::start(InstructionList &List)
{
    ifstream file(sFileName);
    string sLine, sWord;
    int iCount;

    if (!file.is_open()) {
        cout<<"no se pudo abrir el archivo!";
        return false;
    }
    else
    {
        while(getline(file, sLine))
        {
            iCount = wordCount(sLine);
            cout<<"Se contaron: "<<iCount<<" palabras. "<<endl<<" En la linea: "<<sLine<<endl;
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
