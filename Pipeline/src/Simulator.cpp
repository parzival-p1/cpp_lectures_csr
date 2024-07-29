#include "Simulator.h"

Simulator::Simulator(string sFileName)
{
    //ctor
    this->sFileName = sFileName;
    decoder = new Decoder(sFileName);

    int x = 5;
    if (x == WB)
    {
        cout<<"Fue Write Back";
    }
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
        List.print();
    }
    else
        cout<<"Ocurrio un error"<<endl;
}
