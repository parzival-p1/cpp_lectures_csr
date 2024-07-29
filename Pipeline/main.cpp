#include <iostream>
#include "Simulator.h"

using namespace std;

int main()
{
    Simulator simulator("assembly.txt");
    simulator.run();
    return 0;
}
