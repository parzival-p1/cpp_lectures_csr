#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Definitions.h"
#include "InstLinkedList.h"
#include "Decoder.h"
#include "Alu.h"

using namespace std;

class Process
{
    public:
        Process();

        int Getpid() { return pid; }
        int GetinstructionCount() { return instructionCount; }
        bool Getactive() { return active; }
        void Setactive(bool val) { active = val; }
        // T A R E A hacer la funcion que imprima los daatos del proceso: pid, activo, instrucciones
        void printProcess();

    protected:

    private:
        int pid;
        string fileName;
        int instructionCount;
        InstructionList List;
        bool active;

        double f(double x);
        double random_uniform();
        double monte_carlo_sample();

};

#endif // PROCESS_H
