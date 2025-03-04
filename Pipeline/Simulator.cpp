#include "Simulator.h"

Simulator::Simulator()
{
    //ctor
    iClockCounter = 0; // cuenta los ciclos de reloj, por cada ciclo de reloj = ciclo de while
}

Simulator::~Simulator()
{
    // dtor
}

void Simulator::runTest()
{
    srand(time(NULL));

    for (int i = 0; i < 3; i++)
    {
        Exec.createNode();
    }
    Exec.printList();
}

void Simulator::run()
{
    cout<<"Iniciando el simulador"<<endl;
    iClockCounter++;
    cout<<"Clock counter: "<<iClockCounter<<endl;

    cout<<"Terminando simulador"<<endl;
    // myAlu.execute("CMP", "$IR", "$-40", cpuReg);
    // cout<<"\nIR: "<<cpuReg.IR<<endl;
    cout<<"Ocurrio un error"<<endl;
}
