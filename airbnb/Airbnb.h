#ifndef AIRBNB_H
#define AIRBNB_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include "Host.h"
#include "Guest.h"
#include "GuestArrayList.h"
#include "Property.h"
#include "PropertyArrayList.h"

class Airbnb
{
    public:
        Airbnb();
        ~Airbnb();

        void run(); // implemeentarla en .cpp (esto es inicio)
        void login();
        void airbnbMenu(); // login, propiedad, guest, user
        void propertyMenu();
        void hostMenu();
        void guestMenu();

        // Property
        void addProperty();
        void printProperty();
        void editProperty();
        int searchProperty();
        void deleteProperty();
        void showTopFive();
        void rateProperty(unsigned int property);

        // Guest
        void addGuest();
        void printGuest();
        void editGuest();
        void deleteGuest();
        void listGuest();
        void asignGuest();
        void rateGuest();

        // Host
        void addHost(unsigned int index);
        void printHostProperties();
        void printHosts();
        void editHost();
        void deleteHost();
        void createHost(unsigned int index);
        //void listHosts();


    protected:

    private:
        PropertyArrayList properties;//objeto que contiene un arrayList pero no es la lista aun, es la clase que contiene el arraylist

};


#endif // AIRBNB_H
