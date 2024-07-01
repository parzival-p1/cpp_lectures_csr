#ifndef EJEMPLO3_H_INCLUDED
#define EJEMPLO3_H_INCLUDED

#include <iostream>

using namespace std;

const int MAX = 20;
const int ELM = 3;

struct Cliente {
    char nombre[MAX];
    char ap_paterno[MAX];
    char ap_materno[MAX];
    int edad;
    char ciudad[MAX];
    int dia_nac;
    int mes_nac;
    int anho_nac;
    char nss[MAX];
    char curp[MAX];
};

void insertaCte(Cliente lista[])
{
    for (int i = 0; i < ELM; i++)
    {
       cout<<"Introduzca el nombre del cliente: ";
       cin>>lista[i].nombre;
       cout<<"Introduzca el apellido paterno del cliente: ";
       cin>>lista[i].ap_paterno;
       cout<<"Introduzca el apellido materno del cliente: ";
       cin>>lista[i].ap_materno;
       cout<<"Introduzca la edad del cliente: ";
       cin>>lista[i].edad;
       cout<<"Introduzca la ciudad de nacimiento: ";
       cin>>lista[i].ciudad;
       cout<<"Introduzca el dia de nacimiento: ";
       cin>>lista[i].dia_nac;
       cout<<"Introduzca el mes de nacimiento: ";
       cin>>lista[i].mes_nac;
       cout<<"Introduzca el anho de nacimiento ";
       cin>>lista[i].anho_nac;
       cout<<"Introduzca el Numero del Seguro Social del cliente ";
       cin>>lista[i].nss;
       cout<<"Introduzca el CURP del cliente: ";
       cin>>lista[i].curp;
    }
}

void imprimeBasico(Cliente lista[])
{
    cout<<"---- Impresion nivel 1 ----"<<endl;
    for (unsigned int i = 0; i < ELM; i++)
    {
       cout<<lista[i].nombre<<endl;
       cout<<lista[i].ap_paterno<<endl;
       cout<<lista[i].ap_materno<<endl;
       cout<<lista[i].edad<<endl;
    }
}

void imprimeNiv2(Cliente lista[])
{
    cout<<"---- Impresion nivel 2 ----"<<endl;
    for (unsigned int i = 0; i < ELM; i++)
    {
       cout<<lista[i].nombre<<endl;
       cout<<lista[i].ap_paterno<<endl;
       cout<<lista[i].ap_materno<<endl;
       cout<<lista[i].edad<<endl;
       cout<<lista[i].dia_nac<<endl;
       cout<<lista[i].mes_nac<<endl;
       cout<<lista[i].anho_nac<<endl;
    }
}

void imprimeNiv3(Cliente lista[])
{
    cout<<"---- Impresion nivel 3 ----"<<endl;
    for (unsigned int i = 0; i < ELM; i++)
    {
       cout<<lista[i].nombre<<endl;
       cout<<lista[i].ap_paterno<<endl;
       cout<<lista[i].ap_materno<<endl;
       cout<<lista[i].edad<<endl;
       cout<<lista[i].nss<<endl;
       cout<<lista[i].curp<<endl;
    }
}

void imprimeNiv4(Cliente lista[])
{
    cout<<"---- Impresion nivel 4 ----"<<endl;
    for (unsigned int i = 0; i < ELM; i++)
    {
       cout<<lista[i].nombre<<endl;
       cout<<lista[i].ap_paterno<<endl;
       cout<<lista[i].ap_materno<<endl;
       cout<<lista[i].edad<<endl;
       cout<<lista[i].dia_nac<<endl;
       cout<<lista[i].mes_nac<<endl;
       cout<<lista[i].anho_nac<<endl;
       cout<<lista[i].nss<<endl;
       cout<<lista[i].curp<<endl;
    }
}


void impresora(void (*ptrImpr) (Cliente[]), Cliente lista[])
{
    ptrImpr(lista);
}

void run()
{
    Cliente lista[MAX];
    int opc;

    do
    {
        cout<<"1. Imprimir nombre y apellidos "<<endl;
        cout<<"2. Imprimir nombre, apellidos y fecha de nacimieto"<<endl;
        cout<<"3. Imprimir datos y lugar de nacimiento"<<endl;
        cout<<"4. Imprimir datos de nacimiento, CURP y NSS"<<endl;
        cout<<"5. Agregar cliente"<<endl;
        cout<<"0. Presione 0 para salir"<<endl;
        cout<<"Opcion: ";
        cin>>opc;

        switch (opc)
        {
            case 1: impresora(imprimeBasico, lista); break;
            case 2: impresora(imprimeNiv2, lista); break;
            case 3: impresora(imprimeNiv3, lista); break;
            case 4: impresora(imprimeNiv4, lista); break;
            case 5: impresora(insertaCte, lista); break;
            case 0: cout<<"Gracias por utilizar el sistema"<<endl; break;
            default: cout<<"Opcion invalida!"<<endl; break;
        }
    } while (opc != 0);
}

#endif // EJEMPLO3_H_INCLUDED
