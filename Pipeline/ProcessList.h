#ifndef PROCESSLIST_H
#define PROCESSLIST_H
#include "Process.h"

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
        Node *lPop();
        void lPush(Node *newNode);
        void printList();
        void createNode();

    private:
        Node *head;
        Node *tail;
};

#endif // PROCESSLIST_H
