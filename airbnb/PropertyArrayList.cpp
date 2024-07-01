#include "PropertyArrayList.h"

PropertyArrayList::PropertyArrayList()
{
    pList = NULL;
}

PropertyArrayList::~PropertyArrayList()
{
    if (pList != NULL)
        delete [] pList;
}

/**
 * ArrIsEmpty - valida si la lista esta vacia
 * @last: primer espacio disponible de la lista
 * Return: true si la lista esta vacia, false si la lista no esta vacia
 * que ha
 */

bool PropertyArrayList::IsEmpty()
{
    if (last == 0)
        return true;
    else
        return false;
}

/**
 * ArrIsFull - valida si la lista esta llena
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 * Return: true si la lista esta llena, false si la lista no esta llena
 */

bool PropertyArrayList::IsFull()
{
    bool check = true;

    if (last != MAX) // la lista NO esta llena
        check = false;
    return check;
}

/**
 * ArrResizeList - redimensiona la lista
 * @List: Struct Node []
 * @n: numero de espacios disponibles que contiene la lista
 */

void PropertyArrayList::ReSizeList()
{
    Property *temp = NULL; // buena practica inicializar en NULL
    int newN = MAX * 2; // crece el doble

    // Paso 1: Pido memoria (creo el arr temp)
    temp = new Property [newN];

    // Paso 2: Copio a temp lo que tenga lista
    memcpy(temp, pList, sizeof(Property) * MAX);

    // Paso 3: Borrar los datos anteriores de la lista
    delete [] pList;

    // Paso 4: Muevo el ptr de lista
    pList = temp;

    // Paso 5: n se actualiza
    MAX = newN;
}

/**
 * ArrInsertLast - inserta un nodo al final de la lista
 * @List: Struct Node []
 * @newNode: nuevo nodo a insertar al final de la lista
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 */

bool PropertyArrayList::InsertLast(Property newNode)
{
    bool ok = false;
    // paso 1: validar
    if (IsFull()) // si no esta llena continua el programa
        ReSizeList(); // redimensiona la lista

    pList[last] = newNode;
    ++last;
    ok = true;

    return ok; // si no entra el if return ok = false
}

/**
 * ArrInsertBegin - inserta un nodo al inicio de la lista
 * @List Struct Node []
 * @newNode: nuevo nodo a insertar
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 */

bool PropertyArrayList::InsertBegin(Property newNode)
{
    bool check = false;

    if (IsFull()) // paso 1: validar
        ReSizeList(); // redimensiona la lista

    for (int i = last -1; i >= 0; --i) //  i se mueve hacia la izq para poder insertar el newNode
        pList[i + 1] = pList[i]; // Corrimiento de nodos hacia la derecha
    pList[0] = newNode;
    ++last;
    check = true;

    return check;
}

bool PropertyArrayList::InsertSorted(Property newNode)
{
    bool check = true, stop = false;
    unsigned int i = 0;
    unsigned int j = last;

    // mueve i a la pos que se debe insertar el nuevo nodo
    while (i < last && !stop)
    {
        if (newNode.Getrating() > pList[i].Getrating())
            stop = true;
        else
            i++;
    }

    // recorrer a partir de i
    while (j > i)
    {
        pList[j] = pList[j-1]; // corrimiento a la derecha y while se mueve a la izq
        j--;
    }

    // ahora insertar
    pList[i] = newNode;
    last++;

    return check;
}


/**
 * ArrDeleteBegin - borra el primer nodo de la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 */

bool PropertyArrayList::DeleteBegin()
{
    bool check = false;
    // paso 1: validar
    if (!IsEmpty())
    {
        for (unsigned int i = 0; i < last - 1; ++i)
            pList[i] = pList[i+1];
        --last;
        check = true;
    }
    return check;
}

/**
 * ArrDeleteLast - borra un elemento al final de la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 */

bool PropertyArrayList::DeleteLast()
{
    bool check = false;
    if (!IsEmpty())
    {
        --last;
        check = true;
    }
    return check;
}

/**
 * ArrDeleteCustom: elimina un nodo en la lista
 * @List: Struct Node []
 * @pos: posicion dada para la insercion del nuevo nodo
 * @last: primer espacio disponible de la lista
 */

void PropertyArrayList::deleteCustom(unsigned int pos)
{
    if (!IsEmpty())
        if (!(pos < 0 || pos >= last)){
            for (unsigned int i = pos; i < last -1; ++i)
                pList[i] = pList[i+1];
            --last;
        }
}

/**
 * ArrDeleteAll - borra todos los nodos de la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 */

bool PropertyArrayList::DeleteAll()
{
    bool check = false;

    if (!IsEmpty())
    {
        last = 0;
        check = true;
    }
    return check;
}

/**
 * ArrUpdateList - modifica la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 * @pos: posicion dada para la actualizacion del nodo
 */

void PropertyArrayList::UpdateList(Property newNode, unsigned int pos)
{
    if (!IsEmpty()) {
        if (!(pos < 0 || pos >= last))
            pList[pos] = newNode;
    }
}

void PropertyArrayList::print() // Hacer lo mismo para GuestArrayList
{
    for(unsigned int i = 0; i < last; ++i)
        pList[i].printProperty(); // manda a llamar la propiedad print
}

void PropertyArrayList::sortByRating()
{
    Property temp;

    for (unsigned int i = 0; i < last; ++i)
    {
        for (unsigned int j = i+1; j < last; j++)
        {
            if (pList[i].Getrating() > pList[j].Getrating())
            {
                temp = pList[i];
                pList[i] = pList[j];
                pList[j] = temp;
            }
        }
    }
}

Property PropertyArrayList::Getelement(unsigned int index)
{
    return pList [index];
}

void PropertyArrayList::printProperties(unsigned int index)
{
    for (unsigned int i = 0; i < last; i++)
    {
        if (pList[index].Gethost().Getname() == pList[i].Gethost().Getname()
            && pList[index].Gethost().GetlastName() == pList[i].Gethost().GetlastName())
            {
                cout<<i+1<<". "<<pList[i].Getname()<<endl;
            }
    }
}

void PropertyArrayList::printHosts()
{
    for (unsigned int i = 0; i < last; i++)
    {
        cout<<i+1<<". ";
        pList[i].printHost();
        cout<<endl;
    }
}

void PropertyArrayList::printProperty()
{
    int opt;
    cout<<"Opcion: ";
    cin>>opt;
    pList[opt-1].printProperty();
}

void PropertyArrayList::listProperties()
{
    for (unsigned int i = 0; i < last; i++)
        cout<<i+1<<". "<<pList[i].Getname()<<endl;
}

void PropertyArrayList::addHost(unsigned int index)
{
    int opt;
    cout<<"Opcion: ";
    cin>>opt;

    // copia el host de la propiedad en index a la propiedad que esta en opt-1
    pList[index].Sethost(pList[opt-1].Gethost());
}

void PropertyArrayList::listGuests(unsigned int index)
{
    pList[index].printGuests();
}

void PropertyArrayList::setGuestRate(unsigned int pIndex, unsigned int gIndex, int rate)
{
    pList[pIndex].setGuestRate(gIndex, rate);
}

void PropertyArrayList::setPropertyRate(unsigned int pIndex, int rate)
{
    float newRating = pList[pIndex].Getrating() + rate;
    pList[pIndex].Setrating(newRating);
}

void PropertyArrayList::addGuest(unsigned int index, Guest newGuest)
{
    pList[index].addGuest(newGuest);
}


void PropertyArrayList::editGuest(unsigned int pIndex, unsigned int gIndex)
{
    pList[pIndex].editGuest(gIndex);
}

void PropertyArrayList::deleteGuest(unsigned int pIndex, unsigned int gIndex)
{
    pList[pIndex].deleteGuest(gIndex);
}

void PropertyArrayList::editProperty(unsigned int pIndex)
{
    string name;
    string type;
    string kitchen;
    string petFriendly;
    int rooms;
    string parking;

    cout<<"Introduzca el nombre: ";
    cin>>name;

    cout<<"Introduzca el tipo de propiedad: ";
    cin>>type;

    cout<<"Introduzca si cuenta con cocina: ";
    cin>>kitchen;

    cout<<"Introduzca si es petfriendly: ";
    cin>>petFriendly;

    cout<<"Introduzca las habitaciones: ";
    cin>>rooms;

    cout<<"introduzca si tiene estacionamiento: ";
    cin>>parking;

    pList[pIndex].Setname(name);
    pList[pIndex].Settype(type);
    pList[pIndex].Setkitchen(kitchen);
    pList[pIndex].SetpetFriendly(petFriendly);
    pList[pIndex].Setrooms(rooms);
    pList[pIndex].Setparking(parking);

    cout<<"Se edito la propiedad con exito!"<<endl;
}

void PropertyArrayList::deleteProperty(unsigned int pIndex)
{
    deleteCustom(pIndex);
}

void PropertyArrayList::deleteHost(unsigned int pIndex)
{
    deleteCustom(pIndex);
}

void PropertyArrayList::editHost(unsigned int pIndex)
{
    pList[pIndex].editHost();
}

void PropertyArrayList::showTopFive()
{

}
