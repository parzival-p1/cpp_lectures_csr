#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <iostream>

using namespace std;

class Client {

private:
    string name;
    string lastName;
    int day;
    int month;
    int year;

public:
    Client()
    {
        name = lastName = "";
        day = month = year = 0;
    }

    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setLastName(string lastName) { this->lastName = lastName; }
    string getLastName() { return lastName; }
    void setDay(int day) { this->day = day; }
    int getDay() { return day; }
    void setMonth(int month) { this->month = month; }
    int getMonth() { return month; }
    void setYear(int year) { this->year = year; }
    int getYear() { return year; }

    void print() {
        cout<<name<<" "<<lastName<<": "<<day<<"/"<<month<<"/"<<year<<endl;
    }
};


#endif // CLIENT_H_INCLUDED
