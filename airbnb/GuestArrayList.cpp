#include "GuestArrayList.h"

GuestArrayList::GuestArrayList()
{
    gList = NULL;
}

GuestArrayList::~GuestArrayList()
{
    if(gList != NULL)
        delete[] gList;
}

/**
 * ArrIsEmpty - valida si la lista esta vacia
 * @last: primer espacio disponible de la lista
 * Return: true si la lista esta vacia, false si la lista no esta vacia
 * que ha
 */

bool GuestArrayList::IsEmpty()
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

bool GuestArrayList::IsFull()
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

void GuestArrayList::ReSizeList()
{
    Guest *temp = NULL; // buena practica inicializar en NULL
    int newN = MAX * 2; // crece el doble

    // Paso 1: Pido memoria (creo el arr temp)
    temp = new Guest [newN];

    // Paso 2: Copio a temp lo que tenga lista
    memcpy(temp, gList, sizeof(Guest) * MAX);

    // Paso 3: Borrar los datos anteriores de la lista
    delete [] gList;

    // Paso 4: Muevo el ptr de lista
    gList = temp;

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

bool GuestArrayList::InsertLast(Guest newNode)
{
    bool ok = false;
    // paso 1: validar
    if (IsFull()) // si no esta llena continua el programa
        ReSizeList(); // redimensiona la lista
    gList[last] = newNode;
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

bool GuestArrayList::InsertBegin(Guest newNode)
{
    bool check = false;

    if (IsFull()) // paso 1: validar
        ReSizeList(); // redimensiona la lista

    for (int i = last -1; i >= 0; --i) //  i se mueve hacia la izq para poder insertar el newNode
        gList[i + 1] = gList[i]; // Corrimiento de nodos hacia la derecha
    gList[0] = newNode;
    ++last;
    check = true;

    return check;
}


/**
 * ArrDeleteBegin - borra el primer nodo de la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 */

bool GuestArrayList::DeleteBegin()
{
    bool check = false;
    // paso 1: validar
    if (!IsEmpty())
    {
        for (unsigned int i = 0; i < last - 1; ++i)
            gList[i] = gList[i+1];
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

bool GuestArrayList::DeleteLast()
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

void GuestArrayList::deleteCustom(unsigned int pos)
{
    if (!IsEmpty())
        if (!(pos < 0 || pos >= last)){
            for (unsigned int i = pos; i < last -1; ++i)
                gList[i] = gList[i+1];
            --last;
        }
}

/**
 * ArrDeleteAll - borra todos los nodos de la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 */

bool GuestArrayList::DeleteAll()
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

void GuestArrayList::UpdateList(Guest newNode, unsigned int pos)
{
    if (!IsEmpty()) {
        if (!(pos < 0 || pos >= last))
            gList[pos] = newNode;
    }
}

void GuestArrayList::printGuests()
{
    for(unsigned int i = 0; i < last; i++)
    {
        cout<<i+1<<". ";
        gList[i].printGuest();
    }
}

void GuestArrayList::setGuestRate(unsigned int index, int rate)
{
    gList[index].SetguessRating(rate);
}

void GuestArrayList::addGuest(Guest newGuest)
{
    InsertLast(newGuest);
}

int GuestArrayList::searchGuest(string name, string lastname)
{
    bool found = false;
    unsigned int cont = 0;

    while (cont < last && !found)
        if (gList[cont].Getname() == name && gList[cont].GetlastName() == lastname)
            found = true;
        else
            cont++;
    if (found)
        return cont;
    else
        return -1;
}

void GuestArrayList::editGuest(unsigned int gIndex)
{
    string name, lastName, CheckIn, CheckOut;

    cout<<"Introduzca su nombre: ";
    cin>>name;

    cout<<"Introduzca su apellido: ";
    cin>>lastName;

    cout<<"Introduzca la fecha de llegada: ";
    cin>>CheckIn;

    cout<<"Introuduzca la fecha de salida: ";
    cin>>CheckOut;

    gList[gIndex].Setname(name);
    gList[gIndex].SetlastName(lastName);
    gList[gIndex].SetcheckIn(CheckIn);
    gList[gIndex].SetcheckOut(CheckOut);

    cout<<"Se ha editado exitosamente!"<<endl;
}

void GuestArrayList::deleteGuest(unsigned int gIndex)
{
    deleteCustom(gIndex);
}

