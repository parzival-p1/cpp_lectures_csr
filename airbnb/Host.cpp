#include "Host.h"

Host::Host()
{
    //ctor
}

Host::Host(const Host& other)
{
    //copy ctor
}

void Host::printHost()
{
    cout<<"--- Host ---"<<endl;
    cout<<"Nombre: "<<name<<endl;
    cout<<"Apellido: "<<lastName<<endl;
    cout<<"ID: "<<Id<<endl;
}

/* void Host::addHost()
{
    cout<<"--- Registro del Casero ---"<<endl;
    cout<<"Nombre: "<<endl;
    cin>>name;
    cout<<"Apellido: "<<endl;
    cin>>lastName;
    cout<<"Introduzca su ID: "<<endl;
    cin>>Id;
} */

void Host::addHost()
{
    int opt;
    cout<<"Opcion: ";
    cin>>opt;

    //  T A R E A  mover esta linea a su respectiva clase

    // copia el host de la propiedad en index a la propiedad que esta en opt-1
    //properties.Getelement(index).Sethost(properties.Getelement(opt-1).Gethost());
}

void Host::deleteHost()
{
    //???
}