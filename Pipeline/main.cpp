#include <iostream>
#include "Simulator.h"

using namespace std;

int main()
{
    Simulator simulator("assembly.txt"); //1. construye el obj
    simulator.run(); // 2. manda llamar run
    return 0;
}
