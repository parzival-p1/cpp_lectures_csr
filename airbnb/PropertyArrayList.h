#ifndef PROPERTYARRAYLIST_H
#define PROPERTYARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Property.h"

class PropertyArrayList {
public:
    PropertyArrayList();
    ~PropertyArrayList();

    unsigned int Getlast(){ return last; }
    unsigned int GetMAX(){ return MAX; }

    void Setlast(unsigned int val){last = val;}
    void SetMAX(unsigned int val){MAX = val;}

    bool IsEmpty();
    bool IsFull();
    void ReSizeList();
    bool InsertLast(Property newNode);
    bool InsertBegin(Property newNode);
    bool InsertSorted(Property newNode);
    bool DeleteBegin();
    bool DeleteLast();
    void deleteCustom(unsigned int pos);
    bool DeleteAll();
    void UpdateList(Property newNode, unsigned int pos);
    void print();
    void sortByRating();

    // Property
    Property Getelement(unsigned int index);
    void printProperties(unsigned int index);
    void setGuestRate(unsigned int pIndex, unsigned int gIndex, int rate);
    void setPropertyRate(unsigned int pIndex, int rate);
    void editProperty(unsigned int pIndex);
    void deleteProperty(unsigned int pIndex);
    void showTopFive();

    // Host
    void printHosts();
    void addHost(unsigned int index);
    void deleteHost(unsigned int pIndex);
    void editHost(unsigned int pIndex);

    // Guest
    void addGuest(unsigned int index, Guest newGuest);
    void printProperty();
    void listProperties();
    void listGuests(unsigned int index);
    void editGuest(unsigned int pIndex, unsigned int gIndex);
    void deleteGuest(unsigned int pIndex, unsigned int gIndex);

private:
    unsigned int last;
    unsigned int MAX;
    Property *pList; // esto es un arreglo dinamico
};

#endif // PROPERTTYARRAYLIST_H
