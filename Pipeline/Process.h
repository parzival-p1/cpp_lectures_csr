#ifndef PROCESS_H
#define PROCESS_H

#include "Definitions.h"
#include "InstLinkedList.h"
#include "Decoder.h"
#include "Alu.h"

using namespace std;

class Process
{
    public:
        Process();
        ~Process();

        int Getpid() { return pid; }
        int GetinstructionCount() { return instructionCount; }
        bool Getactive() { return active; }
        void Setactive(bool val) { active = val; }
        // T A R E A hacer la funcion que imprima los daatos del proceso: pid, activo, instrucciones
        void printProcess();
        void execute();

    protected:

    private:
        int pid;
        string fileName;
        int instructionCount;
        InstructionList List; // esto es una instancia
        Registers cpuReg; // aqui se esta creando el objeto
        bool active;
        Decoder *decoder;
        Alu myAlu; // aqui se crea el obj


        double f(double x);
        double random_uniform();
        double monte_carlo_sample();
};

#endif // PROCESS_H
