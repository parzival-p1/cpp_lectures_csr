#ifndef PROCESSLIST_H
#define PROCESSLIST_H
#include "Process.h"

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
        void print();

    private:
        Node *head;
        Node *tail;
};

#endif // PROCESSLIST_H
