#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <iostream>
#include "Client.h"
#include "HashTable.h"

using namespace std;

class Interface {

private:
    HashTable hashtable;

public:
    Interface();
    void addClient();
    void searchClient();
    void printClients();
};

Interface::Interface()
{

}

void Interface::addClient()
{
    Client c;
    string sInput;
    int iInput;

    cout<<"Introduzca su nombre: ";
    cin>>sInput;
    c.setName(sInput);

    cout<<"Introduzca su apellido: ";
    cin>>sInput;
    c.setLastName(sInput);

    cout<<"Introduzca su dia de nacimiento: ";
    cin>>iInput;
    c.setDay(iInput);

    cout<<"Introduzca su mes de nacimiento: ";
    cin>>iInput;
    c.setMonth(iInput);

    cout<<"Introduzca su anho de nacimiento: ";
    cin>>iInput;
    c.setYear(iInput);

    hashtable.Insert(c);
}

void Interface::searchClient()
{

}

void Interface::printClients()
{
    hashtable.printAll();
}

#endif // INTERFACE_H_INCLUDED
