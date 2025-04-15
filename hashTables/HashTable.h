#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include <iostream>
#include "Client.h"

using namespace std;

#define MAX 10

class HashTable {

private:
    Client clients[MAX];
    unsigned int getKey(Client c);

public:
    HashTable();
    ~HashTable();

    void Insert(Client c);
    void Delete(Client c);
    void Search(Client c);
    void printAll();
};

HashTable::HashTable()
{

}
HashTable::~HashTable()
{

}

unsigned int HashTable::getKey(Client c)
{
    unsigned int total = c.getDay() + c.getMonth() + c.getYear() + c.getName()[0] + c.getLastName()[0];
    unsigned int key = total % MAX;
    return key;
}

void HashTable::Insert(Client c)
{
    unsigned int key = getKey(c);
    clients[key] = c;
}

void HashTable::Delete(Client c)
{
    Client temp;
    unsigned int key = getKey(c);
    clients[key] = temp;
}

void HashTable::Search(Client c)
{
    unsigned int key = getKey(c);
    cout<<"\n\tEl cliente se encontro en el indice: "<<key<<endl;
}

void HashTable::printAll()
{
    for(int i = 0; i < MAX; ++i)
    {
        clients[i].print();
    }
}

#endif // HASHTABLE_H_INCLUDED
