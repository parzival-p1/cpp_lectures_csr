#include "Simulator.h"

Simulator::Simulator()
{
    //ctor
    iClockCounter = 0; // cuenta los ciclos de reloj, por cada ciclo de reloj = ciclo de while
    srand(time(NULL));

}

Simulator::~Simulator()
{
    // dtor
}

void Simulator::runTest()
{
    int processes;
    char keepRunning = 'y';

    createProcesses();

    while (Exec.GetProcessCount() > 0 && keepRunning == 'y')
    {
        Exec.printList();
        processes = rand() % 10;

        if (processes == 7)
            createProcesses();
        cout<<"Continuar con el simulador (y / n): ";
        cin>>keepRunning;
    }
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

void Simulator::createProcesses()
{
    int a = 3 + rand() % 18;

    for (int i = 0; i < a; i++)
    {
        Exec.createNode();
    }
}
