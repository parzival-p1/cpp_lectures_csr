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
}

bool ProcessList::isEmpty()
{
    if (head)
        return false;
    else
        return true;
}

Node *ProcessList::pop()
{
    Node *temp = head;

    if (!isEmpty())
    {
        head = temp->next;
        tail->next = head;
        return temp;
    }
    else
        return NULL;
}

void ProcessList::push(Node *newNode)
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

void ProcessList::print()
{

}
