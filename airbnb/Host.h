#ifndef HOST_H
#define HOST_H

#include <iostream>
#include <string>

using namespace std;

class Host
{
    public:
        Host();
        Host(const Host& other);

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string GetlastName() { return lastName; }
        void SetlastName(string val) { lastName = val; }
        int GetId() { return Id; }
        void SetId(int val) { Id = val; }

        // Metodos de la clase
        void printHost();
        void addHost();
        void deleteHost();

    private:

        string name;
        string lastName;
        int Id;

};

#endif // HOST_H
