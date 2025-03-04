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

    protected:

    private:
        string sFileName;
        int iClockCounter;
        ProcessList Exec;
        ProcessList Done;
};

#endif // SIMULATOR_H
