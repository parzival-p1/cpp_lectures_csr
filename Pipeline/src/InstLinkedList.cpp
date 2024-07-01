#include "InstLinkedList.h"

InstructionList::InstructionList()
{
    head = NULL;
}

InstructionList::~InstructionList()
{
    deleteAll();
}

InstructionList::InstructionList(const InstructionList& other)
{
    //copy ctor
}

bool InstructionList::isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

void InstructionList::insertLast(Instruction *newNode)
{
    Instruction *temp = head;

    if (isEmpty())
        head = newNode;
    else
    {
        while (temp->GetNext() != NULL)
            temp = temp->GetNext();
        temp->SetNext(newNode);
    }
}

void InstructionList::deleteBegin()
{
    Instruction *temp = head;

    if (!isEmpty())
    {
        head = head->GetNext();
        delete temp;
    }
}
/* Otra manera de hacer deleteAll()
* void InstructionList::deleteAll() {
*   while (!isEmpty())
*       deleteBegin();
* }
*/
void InstructionList::deleteAll()
{
    Instruction *temp = head;

    if (!isEmpty())
    {
        while (head != NULL)
        {
            head = head->GetNext();
            delete temp;
            temp = head;
        }
    }
}

void InstructionList::print()
{
    for (Instruction *aux = head; aux != NULL; aux = aux->GetNext())
    {
        cout>>aux->print();
    }
}
