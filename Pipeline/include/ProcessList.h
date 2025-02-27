#ifndef PROCESSLIST_H
#define PROCESSLIST_H
#include <iostream>
#include "Process.h"
#include <string>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct Node
{
    Process p;
    Node *next;
};

class ProcessList
{
    public:
        ProcessList();
        ~ProcessList();
        bool isEmpty();
        Node *pop();
        void push(Node *newNode);
        void printProcessList(Node *head);

    private:
        Node *head;
        Node *tail;
};

#endif // PROCESSLIST_H
