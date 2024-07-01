#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Decoder.h"
#include <iostream>
#include <string>
using namespace std;

class Simulator
{
    public:
        Simulator(string sFileName);
        ~Simulator();
        void run();

    protected:

    private:
        Decoder decoder(sFileName);
        string sFileName;
};

#endif // SIMULATOR_H
