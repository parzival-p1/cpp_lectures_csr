#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

class Process
{
    public:
        Process();

        int Getpid() { return pid; }
        int GetinstructionCount() { return instructionCount; }
        bool Getactive() { return active; }
        void Setactive(bool val) { active = val; }

    protected:

    private:
        int pid;
        string fileName;
        int instructionCount;
        bool active;
};

#endif // PROCESS_H
