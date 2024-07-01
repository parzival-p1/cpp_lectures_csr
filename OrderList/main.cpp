#include <stdio.h>
#include <iostream>

using namespace std;

const int MAX = 100;

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

contact c_list[MAX];

void orderContactByAge();
void orderContactByZip();

int main()
{
    cout << "Hello world!" << endl;

    orderContactByAge();
    orderContactByZip();
    return 0;
}

void orderContactByAge()
{
    int i = 0;
    int j;
    contact aux;

    while(i < MAX)
    {
        j = i+1;
        while(j < MAX)
        {
            if(c_list[i].age < c_list[j].age)
            {
                aux = c_list[i];
                c_list[i] = c_list[j];
                c_list[j] = aux;
            }
            j++;
        }
        i++;
    }
}

void orderContactByZip()
{
    int i = 0, j;
    contact aux;

    while(i < MAX)
    {
        j = i+1;
        while(j < MAX)
        {
            if(c_list[i].addr.zip < c_list[j].addr.zip)
            {
                aux = c_list[i];
                c_list[i] = c_list[j];
                c_list[j] = aux;
            }
            j++;
        }
        i++;
    }
}
