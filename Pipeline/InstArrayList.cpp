#include "InstArrayList.h"

InstructionList::InstructionList()
{
    last = 0;
    MAX = 10;
    List = new Instruction[MAX];
}

InstructionList::~InstructionList()
{
    delete [] List;
}

InstructionList::InstructionList(const InstructionList& other)
{
    //copy ctor
}

bool InstructionList::isEmpty()
{
    if (last == 0)
        return true;
    else
        return false;
}

bool InstructionList::isFull()
{
    //op ternario?? last == MAX ? return true : return false;
    if (last == MAX)
        return true;
    else
        return false;
}

/*
* 0. Inicializo en NULL, newNode crece en 1 por que?
* 1. Pido mem y creo el arr temp
* 2. Copio a temp lo que tenga la lista
* 3. Borro los datos anteriores creados en la lista
* 4. Muevo el ptr de la lista
* 5. n s actualiza
*/

void InstructionList::resizeList()
{
    Instruction *temp = NULL;
    int newSize = MAX * 2;

    temp = new Instruction [newSize];
    memcpy(temp, List, sizeof(Instruction) * MAX);
    delete [] List;
    List = temp;
    MAX = newSize;
}

void InstructionList::insertLast(Instruction *newNode)
{
    // t a r e a
    if (isFull())
        resizeList();
    List[last] = *newNode; // obtenemos la instruccion sin puntero de manera directa
    last++;
}

void InstructionList::deleteFst()
{
    if (!isEmpty())
    {
        for (unsigned int i = 0; i < last; i++)
            List[i] = List[i + 1];
        last--;
    }
}

void InstructionList::deleteAll()
{
    last = 0;
}

void InstructionList::print()
{
    for (unsigned int i = 0; i < last; i++)
    {
        cout<<i+1;
        List[i].print();
    }
}
