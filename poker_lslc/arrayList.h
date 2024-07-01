//
//  arrayList.h
//  Created by Paco Hdez on 09/11/23.
//

#ifndef lista_h

// Las enum son constantes que estan en un solo sitio
enum Errores // esto es una declaracion de constantes
{
    // POR DEFAULT LA ENUM AUMMENTA DE MANERA ASCENDENTE DE UNO EN UNO
    E_OK = -999,
    E_LIST_FULL = -500, // POR DEFAULT SI NO PONGO NADA EMPIEZA EN CERO
    E_LIST_EMPTY,
    E_INVALID_POS
};

/**
 * ArrIsEmpty - valida si la lista esta vacia
 * @last: primer espacio disponible de la lista
 * Return: true si la lista esta vacia, false si la lista no esta vacia
 * que ha
 */

bool ArrIsEmpty(int last)
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

bool ArrIsFull (int last, int n)
{
    bool check = true;

    if (last != n) // la lista NO esta llena
        check = false;
    return check;
}

/**
 * ArrResizeList - redimensiona la lista
 * @List: Struct Node []
 * @n: numero de espacios disponibles que contiene la lista
 */

void ArrReSizeList(Node *(&List), int &n)
{
    Node *temp = NULL; // buena practica inicializar en NULL
    int newN = n * 2; // crece en 1

    // Paso 1: Pido memoria (creo el arr temp)
    temp = new Node [newN];

    // Paso 2: Copio a temp lo que tenga lista
    memcpy(temp, List, sizeof(Node) * n);

    // Paso 3: Borrar los datos anteriores de la lista
    delete [] List;

    // Paso 4: Muevo el ptr de lista
    List = temp;

    // Paso 5: n se actualiza
    n = newN;
}

/**
 * ArrInsertLast - inserta un nodo al final de la lista
 * @List: Struct Node []
 * @newNode: nuevo nodo a insertar al final de la lista
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 */

bool ArrInsertLast(Node *(&List), Node newNode, int &last, int &n)
{
    bool ok = false;
    // paso 1: validar
    if (ArrIsFull(last, n)) // si no esta llena continua el programa
        ArrReSizeList(List, n); // redimensiona la lista

    List[last] = newNode;
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

bool ArrInsertBegin (Node *List, Node newNode, int &last, int &n)
{
    bool check = false;

    if (ArrIsFull(last, n)) // paso 1: validar
        ArrReSizeList(List, n); // redimensiona la lista

    for (int i = last -1; i >= 0; --i) //  i se mueve hacia la izq para poder insertar el newNode
        List[i + 1] = List[i]; // Corrimiento de nodos hacia la derecha
    List[0] = newNode;
    ++last;
    check = true;

    return check;
}

/**
 * ArrInsertCustom: inserta un nodo en la lista
 * @lista: Struct Node [] arreglo de nodos
 * @newNode: nuevo nodo a insertar
 * @pos: posicion dada para la insercion del nuevo nodo
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 */

// 1. mover i hacia la izq para insertar el nuevov nodo
// 2. corrimiento de nodos hacia la izquierda

int ArrInsertCustom (Node List[], Node newNode, int pos, int &last, int &n)
{
    Errores e = E_OK; // tipo de dato Errores var e

    // 1- validar
    if (ArrIsFull(last, n))
        ArrReSizeList(List, n); // redimensiona la lista
    if (pos < 0 || pos >= n)
        e = E_INVALID_POS;
    else
    {
        for (int i = last; i > pos; --i)
            List[i] = List[i - 1];
        List[pos] = newNode;
        ++last;
    }
    return e;
}

/**
 * ArrDeleteBegin - borra el primer nodo de la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 * @n: numero de espacios disponibles que contiene la lista
 */

bool ArrDeleteBegin(Node List[], int &last, int n)
{
    bool check = false;
    // paso 1: validar
    if (!ArrIsEmpty(last))
    {
        for (int i = 0; i < last - 1; ++i)
            List[i] = List[i+1];
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

bool ArrDeleteLast(Node List[], int &last)
{
    bool check = false;
    if (!ArrIsEmpty(last))
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

Errores ArrDeleteCustom(Node List[], int pos, int &last)
{
    Errores e;

    if (ArrIsEmpty(last))
        e = E_LIST_EMPTY;
    else if (pos < 0 || pos >= last)
        e = E_INVALID_POS;
    else
    {
        for (int i = pos; i < last -1; ++i)
            List[i] = List[i+1];
        --last;
        e = E_OK;
    }

    return e;
}

/**
 * ArrDeleteAll - borra todos los nodos de la lista
 * @List: Struct Node []
 * @last: primer espacio disponible de la lista
 */

bool ArrDeleteAll(Node List[], int &last)
{
    bool check = false;

    if (!ArrIsEmpty(last))
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

Errores ArrUpdateList(Node List[], Node newNode, int last, int pos)
{
    Errores e;

    if (ArrIsEmpty(last))
        e = E_LIST_EMPTY;
    else if (pos < 0 || pos >= last)
        e = E_INVALID_POS;
    else
    {
        List[pos] = newNode;
        e = E_OK;
    }
    return e;
}

#define lista_h


#endif /* lista_h */
