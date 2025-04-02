#include <iostream>
#include "Interface.h"

using namespace std;

int main()
{
    Interface interface;
    interface.addClient();
    interface.printClients();

    interface.addClient();
    interface.printClients();

    interface.addClient();
    interface.printClients();

    return 0;
}
