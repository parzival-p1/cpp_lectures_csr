#include "Simulator.h"

Simulator::Simulator(string sFileName)
{
    //ctor
    this->sFileName = sFileName;
    decoder = new Decoder(sFileName);
}

Simulator::~Simulator()
{
    //dtor
    delete decoder;
}

void Simulator::run()
{
    if (!decoder->start(List))
    {
        cout<<"Lectura exitosa del archivo."<<endl;
        //List.print();
        myAlu.execute("ADD", "$Ax", "$12", cpuReg);
        cout<<"\nIR: "<<cpuReg.IR<<endl;
    }
    else
        cout<<"Ocurrio un error"<<endl;
}
