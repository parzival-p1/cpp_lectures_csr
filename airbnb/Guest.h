#ifndef GUEST_H
#define GUEST_H

#include <iostream>
#include <string>
using namespace std;

class Guest
{
    public:
        Guest();
        Guest(string name, string lastName);

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string GetlastName() { return lastName; }
        void SetlastName(string val) { lastName = val; }
        string GetcheckIn() { return checkIn; }
        void SetcheckIn(string val) { checkIn = val; }
        string GetcheckOut() { return checkOut; }
        void SetcheckOut(string val) { checkOut = val; }
        int GetguessRating() { return guessRating; }
        void SetguessRating(int val) { guessRating = val; }

        // Metodos de la clase
        void printGuest();
        void addGuest();

    private:
        string name;
        string lastName;
        string checkIn;
        string checkOut;
        int guessRating;
};

#endif // GUEST_H
