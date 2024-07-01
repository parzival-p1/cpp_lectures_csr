#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include <iostream>
#include "GuestArrayList.h"
#include "Host.h"
using namespace std;

class Property
{
    public:
        Property();
        Property(string name, string type);

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Gettype() { return type; }
        void Settype(string val) { type = val; }
        string Getkitchen() { return kitchen; }
        void Setkitchen(string val) { kitchen = val; }
        string GetpetFriendly() { return petFriendly; }
        void SetpetFriendly(string val) { petFriendly = val; }
        int Getrooms() { return rooms; }
        void Setrooms(int val) { rooms = val; }
        string Getparking() { return parking; }
        void Setparking(string val) { parking = val; }
        float Getrating() { return rating / guests.Getlast() == 0 ? 1 : guests.Getlast(); }
        void Setrating(float val) { rating = val; }
        void Sethost(Host newHost) { host = newHost; }
        Host Gethost() { return host; }

        // Metodos de la clase
        void printProperty();
        void printGuests();
        void addProperty();
        void addGuest(Guest newGuest);
        void printHost();
        void editHost();
        void listGuests();
        void setGuestRate(unsigned int index, int rate);
        void editGuest(unsigned int gIndex);
        void deleteGuest(unsigned int gIndex);
        void editProperty(unsigned int pIndex);

    private: // Excepto rating pedir todo lo demas
        string name;
        string type;
        string kitchen;
        string petFriendly;
        int rooms;
        string parking;
        float rating;
        Host host;
        GuestArrayList guests;
};

#endif // PROPERTY_H
