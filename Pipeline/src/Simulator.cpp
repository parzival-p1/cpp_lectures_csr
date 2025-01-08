#include "Simulator.h"

Simulator::Simulator(string sFileName)
{
    //ctor
    this->sFileName = sFileName;
    cpuReg.cleanRegisters();
    decoder = new Decoder(sFileName);
    iClockCounter = 0; // cuenta los ciclos de reloj, por cada ciclo de reloj = ciclo de while
}

Simulator::~Simulator()
{
    // dtor
    delete decoder;
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
