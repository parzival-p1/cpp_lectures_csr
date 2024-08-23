#include "Simulator.h"

Simulator::Simulator(string sFileName)
{
    //ctor
    this->sFileName = sFileName;
    cpuReg.cleanRegisters();
    decoder = new Decoder(sFileName);
}

Simulator::~Simulator()
{
    // dtor
    delete decoder;
}

void Simulator::run()
{
    if (!decoder->start(List)) // decoder es ptr
    {
        cout<<"Lectura exitosa del archivo."<<endl;
        //List.print();
        myAlu.execute("ADD", "$Ax", "$12", cpuReg);
        cout<<"\nIR: "<<cpuReg.IR<<endl;

        myAlu.execute("SUB", "$Bx", "$5", cpuReg);
        cout<<"\nIR: "<<cpuReg.IR<<endl;

        myAlu.execute("IMUL", "$IR", "$8", cpuReg);
        cout<<"\nIR: "<<cpuReg.IR<<endl;

        myAlu.execute("CMP", "$IR", "$-40", cpuReg);
        cout<<"\nIR: "<<cpuReg.IR<<endl;
    }
    else
        cout<<"Ocurrio un error"<<endl;
}
