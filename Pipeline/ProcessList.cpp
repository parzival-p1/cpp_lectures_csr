#include "ProcessList.h"

ProcessList::ProcessList()
{
    head = NULL;
    tail = NULL;
}

ProcessList::~ProcessList()
{
    Node *temp = head;

    if (!isEmpty())
    {
        while (temp->next != temp)
        {
            head = temp->next;
            delete temp;
            tail->next = head;
            temp = head;
        }
        delete temp;
        head = tail = NULL;
    }
    //cout<<"Nodos destruidos"<<endl;
}

bool ProcessList::isEmpty()
{
    if (head)
        return false;
    else
        return true;
}

Node *ProcessList::lPop()
{
    Node *temp = head;

    if (!isEmpty())
    {
        if (head == tail)
            head = tail = NULL;
        else {
            head = temp->next;
            tail->next = head;
        }
        return temp;
    }
    else
        return NULL;
}

void ProcessList::lPush(Node *newNode)
{
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void ProcessList::printList()
{
    Node *temp = head;

    while (temp->next != head)
    {
        temp->p.printProcess();
        temp = temp->next;
    }
    temp->p.printProcess();
}

void ProcessList::createNode()
{
    Node *newNode = new Node;
    lPush(newNode);
}
