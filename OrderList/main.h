#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <iostream>

using namespace std;

int MAX = 100;

struct address {
    string street;
    int number;
    int zip;
};

struct contact
{
    string name;
    int age;
    address addr;
};

contact c_list[MAX]

void orderContactByAge();
void orderContactByZip();

#endif // MAIN_H_INCLUDED
