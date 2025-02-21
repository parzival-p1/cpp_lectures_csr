#include "Simulator.h"

Simulator::Simulator()
{
    //ctor
    cpuReg.cleanRegisters();
    iClockCounter = 0; // cuenta los ciclos de reloj, por cada ciclo de reloj = ciclo de while
    decoder = NULL;
}

Simulator::~Simulator()
{
    // dtor
    if (decoder)
        delete decoder;
}

void Simulator::runTest()
{
    for (int i = 0; i < 10; i++)
    {
        Process p;
    }
}

void Simulator::run()
{
    if (decoder->start(List)) // decoder es ptr, inserta las inst validas en la lista
    {
        cout<<"Iniciando el simulador"<<endl;
        while (!List.instEndState())
        {
            iClockCounter++;
            cout<<"Clock counter: "<<iClockCounter<<endl;
            List.changeInstructionState();
            List.print(myAlu, cpuReg);
            cin.ignore(); // cada ve que se presione enter = ciclo de reloj
        }
        cout<<"Terminando simulador"<<endl;
        // myAlu.execute("CMP", "$IR", "$-40", cpuReg);
        // cout<<"\nIR: "<<cpuReg.IR<<endl;
    }
    else
        cout<<"Ocurrio un error"<<endl;
}
