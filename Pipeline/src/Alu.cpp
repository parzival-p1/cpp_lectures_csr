#include "Alu.h"

Alu::Alu()
{
    //ctor
}

int Alu::cmdAdd(int a, int b)
{
    return a + b;
}

int Alu::cmdSub(int a, int b)
{
    return a - b;
}

int Alu::cmdMul(int a, int b)
{
    return a * b;
}

int Alu::cmdAnd(int a, int b)
{
    return a & b;
}

int Alu::cmdOr(int a, int b)
{
    return a | b;
}

int Alu::cmdXor(int a, int b)
{
    return a ^ b;
}

int Alu::cmdCmp(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

int Alu::execute(string sOpcode, string sSource, string sDestination)
{
    int isource = stoi(sSource, nullptr, 10);
    int idestination = stoi(sDestination, nullptr, 10);
    int i = 0, res;
    bool found = false;

    while (i < cmdCount && !found)
    {
        if (validCmd[i] == sOpcode)
            found = true;
        else
            i++;
    }

    switch (i) {
        case 0: res = cmdAdd(isource, idestination); break;
        case 1: res = cmdSub(isource, idestination); break;
        case 2: cmdMul(isource, idestination); break;
        case 3: cmdAnd(isource, idestination); break;
        case 4: cmdOr(isource, idestination); break;
        case 5: cmdXor(isource, idestination); break;
        case 6: cmdCmp(isource, idestination); break;
    }

    return res;
}
