#include "Guest.h"

Guest::Guest()
{
    name = "";
    lastName = "";
    checkIn = "";
    checkOut = "";
    guessRating = 0;
}

Guest::Guest(string name, string lastName)
{
    this->name = name;
    this->lastName = lastName;
}

void Guest::printGuest()
{
    cout<<"--- Huesped ---"<<endl;
    cout<<"Nombre: "<<name<<endl;
    cout<<"Apellido: "<<lastName<<endl;
    cout<<"Chek in: "<<checkIn<<endl;
    cout<<"Check out"<<checkOut<<endl;
    cout<<"Rating: "<<guessRating<<endl;
}

void Guest::addGuest()
{
    cout<<"--- Registro del Huesped ---"<<endl;
    cout<<"Introduzca su nombre: "<<endl;
    cin>>name;
    cout<<"Introduzca su apellido: "<<endl;
    cin>>lastName;
    cout<<"Check in: "<<endl;
    cin>>checkIn;
    cout<<"Check out "<<endl;
    cin>>checkOut;
    cout<<"Rating del huesped: "<<endl;
    cin>>guessRating;
}
