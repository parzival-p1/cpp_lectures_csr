#include <iostream>
enum STATUS { INIT, IF, ID, EX, MEM, WB, CO, END };
#include "Simulator.h"

using namespace std;

int main()
{
    Simulator simulator("assembly.txt");
    simulator.run();
    return 0;
}
