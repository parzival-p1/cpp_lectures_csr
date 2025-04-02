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
/*
 * @runTest: maneja la ejecucion de los procesos
*/

void Simulator::runTest()
{
    int processes;
    char keepRunning = 'y';

    createProcesses();

    while (Exec.GetProcessCount() > 0 && keepRunning == 'y')
    {
        Exec.printList();
        Finished.lPush(Exec.executeProcess());
        cout<<"----- Procesos terminados -----"<<endl;
        Finished.printList();

        cout<<"----- Procesos en cola -----"<<endl;
        Exec.printList();

        processes = rand() % 10;

        if (processes == 7)
            createProcesses();
        cout<<"Continuar con el simulador (y / n): ";
        cin>>keepRunning;
        fflush(stdin);
    }

}

/*
 * @run: simula 1 ciclo de reloj para pruebas
*/
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

/*
 * @createProcesses: genera procesos en cantidad aleatoria
*/

void Simulator::createProcesses()
{
    int a = 1 + rand() % 4;

    for (int i = 0; i < a; i++)
    {
        Exec.createNode();
    }
}
