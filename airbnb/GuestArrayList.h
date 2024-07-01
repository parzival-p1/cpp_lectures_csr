#ifndef GUESTARRAYLIST_H
#define GUESTARRAYLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "Guest.h"

class GuestArrayList {
public:
    GuestArrayList();
    ~GuestArrayList();

    unsigned int Getlast(){ return last;}
    unsigned int GetMAX(){ return MAX; }

    void Setlast(unsigned int val){last = val;}
    void SetMAX(unsigned int val){MAX = val;}

    bool IsEmpty();
    bool IsFull();
    void ReSizeList();
    bool InsertLast(Guest newNode);
    bool InsertBegin(Guest newNode);
    bool DeleteBegin();
    bool DeleteLast();
    void deleteCustom(unsigned int pos);
    bool DeleteAll();
    void UpdateList(Guest newNode, unsigned int pos);
    void printGuests();
    void setGuestRate(unsigned int index, int rate);
    void addGuest(Guest newGuest);
    int searchGuest(string name, string lastname);
    void editGuest(unsigned int gIndex);
    void deleteGuest(unsigned int gIndex);


private:
    unsigned int last;
    unsigned int MAX;
    Guest *gList;
};

#endif // GUESTARRAYLIST_H
