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
        Decoder *decoder; // ptr no es obj (no es una instancia) no se manda llamar el CTOR
        InstructionList List; // esto es una instancia
        Registers cpuReg; // aqui se esta creando el objeto
        Alu myAlu; // aqui se crea el obj
};

#endif // SIMULATOR_H
