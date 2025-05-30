#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "ProcessList.h"

using namespace std;

class Simulator
{
    public:
        Simulator();
        ~Simulator();
        void run();
        void runTest();
        void createProcesses();

    protected:

    private:
        string sFileName;
        int iClockCounter;
        ProcessList Exec;
        ProcessList Finished;
};

#endif // SIMULATOR_H
