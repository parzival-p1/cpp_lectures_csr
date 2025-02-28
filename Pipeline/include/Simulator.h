#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Decoder.h"
#include <iostream>
#include <string>
#include "Alu.h"
#include "Process.h"
#include "ProcessList.h"

using namespace std;

class Simulator
{
    public:
        Simulator();
        ~Simulator();
        void run();
        void runTest();

    protected:

    private:
        string sFileName;
        int iClockCounter;
        Decoder *decoder; // ptr no es obj (no es una instancia) no se manda llamar el CTOR
        InstructionList List; // esto es una instancia
        Registers cpuReg; // aqui se esta creando el objeto
        Alu myAlu; // aqui se crea el obj
        ProcessList Exec;
        ProcessList Done;
};

#endif // SIMULATOR_H
