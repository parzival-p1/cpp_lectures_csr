#include "InstLinkedList.h"

InstructionList::InstructionList()
{
    head = NULL;
    instructionCount = 0;
}

InstructionList::~InstructionList()
{
    deleteAll();
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
        while (temp->GetNext() != NULL) // busca el ultimo nodo
            temp = temp->GetNext();
        temp->SetNext(newNode);
        newNode->SetPrev(temp);
    }
    instructionCount++;
}

void InstructionList::deleteBegin()
{
    Instruction *temp = head;

    if (!isEmpty())
    {
        head = head->GetNext();
        head->SetPrev(NULL);
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

void InstructionList::print(Alu &alu, Registers &registers)
{
    bool bExecute;

    for (Instruction *aux = head; aux != NULL; aux = aux->GetNext())
    {
       bExecute = aux->print();
       if (bExecute)
       {
           alu.execute(aux->GetsOpcode(), aux->GetsSource(), aux->GetsDestination(), registers);
       }
    }


}

Instruction *InstructionList::getNextNode(Instruction *currentNode)
{
    if (currentNode == NULL)
        return head;
    else
        return currentNode->GetNext();
}

bool InstructionList::instEndState ()
{
    Instruction *aux = head;
    bool bContinue = true;

    if (isEmpty())
        return true;
    else
    {
        while (aux != NULL && bContinue)
        {
            if (aux->GetiCurrentState() != END)
                bContinue = false;
            else
                aux = aux->GetNext();
        }
        return bContinue;
    }
}

void InstructionList::changeInstructionState()
{
    Instruction *temp = head;

    if (!isEmpty())
    {
        temp->changeState();
        temp = temp->GetNext();

        while (temp != NULL && temp->GetPrev()->GetiCurrentState() != IF)
        {
            temp->changeState();
            temp = temp->GetNext();
        }
    }
}

