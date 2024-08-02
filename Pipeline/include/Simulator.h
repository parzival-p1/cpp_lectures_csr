#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Decoder.h"
#include <iostream>
#include <string>
#include "Definitions.h"
#include "Alu.h"

using namespace std;

class Simulator
{
    public:
        Simulator(string sFileName);
        ~Simulator();
        void run();

    protected:

    private:
        string sFileName;
        int iClockCounter;
        Decoder *decoder; // ptr no es obj
        InstructionList List;
};

#endif // SIMULATOR_H
