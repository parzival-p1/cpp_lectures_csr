#ifndef DECODER_H
#define DECODER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "InstLinkedList.h"

using namespace std;

class Decoder
{
    public:
        Decoder(string sFileName);
        ~Decoder();

        bool start(InstructionList &List);
        bool validComand(InstructionList &List, string sLine, int iCount);
        int wordCount(string sLine);
        bool isReservedWord(string sWord);

    protected:

    private:
        string sFileName;
};

#endif // DECODER_H
