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
    decoder->start(List);

}
