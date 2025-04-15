#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
#include "Student.h"

class StudentList {
    private:
        Student *head;
        int totalStudents;

    public:
        StudentList();
        ~StudentList();

        bool isEmpty();
        void insertStudent(Student *s);
        void deleteStudent(Student *s);
        void printStudent(Student *s);
        void printAllStudents();
        void printAllStudentsIds();
        Student *searchStudent(int studentId);
        void deletAllStudents();
        int getTotalStudents() { return totalStudents; }
};

StudentList::StudentList()
{
    head = NULL;
    totalStudents = 0;
}

StudentList::~StudentList()
{
    deletAllStudents();|
}

bool StudentList::isEmpty()
{
    if(head)
        return false;
    else
        return true;
}

void StudentList::insertStudent(Student *s)
{
    s->setNext(head);
    head = s;
    totalStudents++;
}

void StudentList::deleteStudent(Student *s)
{
    Student *temp = head;

    if(!isEmpty())
    {
        if (s == head){
            head = head->getNext();
            delete s;
        }
        else
        {
            while (temp->getNext() != s && temp->getNext() != NULL)
                temp = temp->getNext();
            temp->setNext(s->getNext()); // tmp actualiza el nodo sig para que apunte al sig nodo de s
            delete s;
        }
        totalStudents--;
    }
}

void StudentList::printStudent(Student *s)
{
    s->print();
}

void StudentList::printAllStudentsIds()
{
    Student *s = head;

    while (s != NULL)
    {
        s->printId();
        cout<<", ";
        s = s->getNext();
    }
    cout<<endl;
}

void StudentList::printAllStudents()
{
    Student *temp = head;

    while(temp != NULL)
    {
        temp->print();
        temp = temp->getNext();
    }
}

Student *StudentList::searchStudent(int studentId)
{
    Student *temp = head;
    bool found = false;

    while (temp != NULL && !found)
    {
        if (temp->getStudentId() == studentId)
            found = true;
        else
            temp = temp->getNext();
    }
    return temp; // temp puede tener o NULL o el nodo
}

void StudentList::deletAllStudents()
{
    while (!isEmpty())
    {
        deleteStudent(head);
    }
}

#endif // LINKEDLIST_H_INCLUDED
