#include "ProcessList.h"

ProcessList::ProcessList()
{
    head = NULL;
    tail = NULL;
    processCount = 0;
    maxInstructions = 3;
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
        processCount--;
        return temp;
    }
    else
        return NULL;
}

void ProcessList::lPush(Node *newNode)
{
    if (newNode != NULL)
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
        processCount++;
    }
}

void ProcessList::printList()
{
    Node *temp = head;
    cout<<"Process count: "<<processCount<<endl;

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

Node *ProcessList::executeProcess()
{
    Node *currentNode = lPop();
    bool finished;

    if(!isEmpty())
    {
        finished = currentNode->p.execute(maxInstructions);
        if (finished)
            return currentNode;
        else
        {
            lPush(currentNode);
            return NULL;
        }
    }
    else
        return NULL;
}
