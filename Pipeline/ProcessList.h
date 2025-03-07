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
        int GetProcessCount() { return processCount; }
        Node *executeProcess();

    private:
        Node *head;
        Node *tail;
        int processCount;
        int maxInstructions;
};

#endif // PROCESSLIST_H
