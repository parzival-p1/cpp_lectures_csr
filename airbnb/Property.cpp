#include "Property.h"


Property::Property()
{
    // variables de clase
    name = "";
    type = "";
    kitchen  = "No";
    petFriendly = "No";
    rooms = 0;
    parking = "No";
    rating = 0.0;
}

Property::Property(string name, string type)
{
    this->name = name;
    this->type = type;
}

void Property::printProperty()
{
    cout<<"--- Propiedad ---"<<endl;
    cout<<"Nombre: "<<name<<endl;
    cout<<"Tipo: "<<type<<endl;
    cout<<"Cocina: "<<kitchen<<endl;
    cout<<"Mascotas permitidas: "<<petFriendly<<endl;
    cout<<"Numero de habittaciones: "<<rooms<<endl;
    cout<<"Estacionamiento: "<<parking<<endl;
    cout<<"Calificacion: "<<rating / guests.Getlast() == 0 ? 1 : guests.Getlast()<<endl;
    cout<<"Encargado de llaves: "<<endl;
    host.printHost();
}

 // Hacer print, terminarlo de Property
// Hacer printt the Guest y Host

void Property::addProperty()
{
    cout<<"--- Registro de Propiedad ---"<<endl;
    cout<<"Introduzca el nombre de la propiedad: "<<endl;
    cin>>name;
    cout<<"Introduzca el tipo de propiedad: "<<endl;
    cin>>type;
    cout<<"Cuenta con cocina?: "<<endl;
    cin>>kitchen;
    cout<<"La propiedad es pet friendly? "<<endl;
    cin>>petFriendly;
    cout<<"Numero de habitaciones: "<<endl;
    cin>>rooms;
    cout<<"Cuenta con estacionamiento?: "<<endl;
    cin>>parking;
}

void Property::printGuests()
{
    guests.printGuests();
}

void Property::addGuest(Guest newGuest)
{
    guests.addGuest(newGuest);
}

void Property::printHost()
{
    host.printHost();
}

void Property::listGuests()
{
    guests.printGuests();
}

void Property::setGuestRate(unsigned int index, int rate)
{
    guests.setGuestRate(index, rate);
}

void Property::editGuest(unsigned int gIndex)
{
    guests.editGuest(gIndex);
}

void Property::deleteGuest(unsigned int gIndex)
{
    guests.deleteGuest(gIndex);
}

void Property::editHost()
{
    string name, lastname;

    cout<<"Introduzca el nombre a editar: ";
    cin>>name;

    cout<<"Introduzca el apellido a editar: ";
    cin>>lastname;

    host.Setname(name);
    host.SetlastName(lastname);
}
