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

    void menu();
    void run();
    void addClient();
    void searchClient();
    void printClients();
    void removeClients();
};

Interface::Interface()
{

}

void Interface::run()
{
    menu();
}

void Interface::menu()
{
    int opt;

    do {
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"\t 1. Agregar cliente"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"\t 2. Buscar cliente"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"\t 3. Imprimir datos del cliente"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"\t 4. Borrar cliente"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"\t 5. Salir"<<endl;
        cout<<"|---------------------------------------------|"<<endl;
        cout<<"\t Opcion: ";
        //cout<<"|---------------------------------------------|";
        cin>>opt;

        switch (opt)
        {
            case 1: addClient(); break;
            case 2: searchClient(); break;
            case 3: printClients(); break;
            case 4: removeClients(); break;
            case 5: cout<<"Saliendo..."<<endl; break;
            default: cout<<"La opcion ingresada no es valida"<<endl; break;
        }
    } while (opt != 5);
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
    cout<<"\n\tEl cliente ha sido agregado...\n"<<endl;

    hashta  <<<<ble.Insert(c);
}

void Interface::searchClient()
{
    Client c;
    string name;

    cout<<"Ingrese el nombre del cliente a buscar: ";
    cin>>name;

    hashtable.Search(c);
}

void Interface::printClients()
{
    hashtable.printAll();
}

void Interface::removeClients()
{
    Client c;
    string name;

    cout<<"Ingrese el nombre del cliente a borrar: ";
    cin>>name;
    hashtable.Delete(c);
    cout<<"\n\tEl cliente ha sido borrado con exito!\n"<<endl;
}



#endif // INTERFACE_H_INCLUDED
