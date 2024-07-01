//
//  simpleLinkedList.h
//  kinder_lsll
//
//  Created by Paco Hdez on 16/11/23.
//

#ifndef simpleLinkedList_h
#define simpleLinkedList_h

#include <string.h>

struct Node
{
    char name[20];
    int age;
    Node *next;
};

/**
 * H  A  C  E  R   L  A   F  U  N  C : insertBegin();
 *
 * C O P I A R  D E L  J  A  M
 */

// Insert
bool isEmpty(Node *List);
void insertBegin(Node *(&List), Node *newNode);
void insertLast(Node *(&List), Node *newNode);
void insertSorted(Node *(&List), Node *newNode);

// Delete
void deleteBegin(Node *(&List));
void deleteLast(Node *(&List));
void deleteCustom(Node *(&List), Node *prevNode);
void deleteAll(Node *(&List));

void printList(Node *List);
Node *searchList(Node *List, char name[]);

void sortList(Node *(&List)); // de manera descendente de Z-A

/**
 * isEmpty - valida si la lista esta vacia
 * @List: puntero a Node
 * Return: true si la lista esta vacia, false si la lista no esta vacia
 * que ha
 */
bool isEmpty(Node *List)
{
    if (List)
        return false;
    else
        return true;
}

/**
 * insertBegin - inserta al inicio de la lista
 * @List: puntero a Node
 * @newNode: puntero a nuevo Node
 */
void insertBegin(Node *(&List), Node *newNode)
{
    newNode->next = List;
    List = newNode;
}

/**
 * insertLast - inserta al final de la lista
 * @List: referencia al puntero a Node
 * @newNode: puntero a nuevo Node
 */
void insertLast(Node *(&List), Node *newNode)
{
    Node *aux = List; // en este caso el aux se inicializa en List

    if (isEmpty(List))
    {
        insertBegin(List, newNode);
    }
    else
    {
    //  for (aux = List; aux->next; aux = aux->next)
        while (aux->next != NULL) // mientras aux no sea el ultimo
            aux = aux->next; // camina
        aux->next = newNode;
    }
}

void insertSorted(Node *(&List), Node *newNode)
{
    Node *aux = List;

    if (isEmpty(List) || (strcmp(aux->name, newNode->name) > 0)) // el newNode es menor que el primer Node inserta al principio
        insertBegin(List, newNode);
    else
    {
        while(aux->next != NULL && strcmp(aux->next->name, newNode->name) < 0) // R E P A S A R   E S T E   B L O Q U E
            aux = aux->next; // aux camina a la derecha
        newNode->next = aux->next;
        aux->next =  newNode; // Inserta de manera ordenada ASCENDENTE abcdefgh...
    }
}

void deleteBegin(Node *(&List))
{
    Node *aux = List;

    if (!isEmpty(List))
    {
        List = aux->next; // es exactamente que: List = List->next
        delete aux;
    }

}

void deleteLast(Node *(&List))
{
    Node *aux = List;
    Node *prev = List;

    if(!isEmpty(List))
    {
        while(aux->next != NULL) // mueve el auxiliar al ultimo nodo
            aux = aux->next;

        if(aux == List) // este es el caso en que hay un solo nodo
        {
            List = NULL;
            delete aux;
        }
        else // si hay dos nodos o mas
        {
            while(prev->next != aux) // muevev prev al penultimo nodo
                prev = prev->next;

            delete aux;
            prev->next = NULL; // ahora prev es el ultimo
        }
    }
}


void deleteCustom(Node *(&List), Node *deleteNode)
{
    Node *prev = List;

    if (!isEmpty(List))
    {
        if(deleteNode == List) // Eres el primer nodo? a borrar?
        {
            List = List->next;
            delete deleteNode;
        }
        else // el nodo a borrar no es el primero, hay dos o mas nodos
        {
            while(prev->next != deleteNode) // quedate uno antes del nodo a borrar
                prev = prev->next; // siempre y cuando el nodo a borrar no sea el next

            prev->next = deleteNode->next;
            delete deleteNode;
        }
    }
}

void deleteAll(Node *(&List))
{
    Node *aux = List;

    if (!isEmpty(List))
    {
        while (aux->next != NULL)
        {
            aux = aux->next;
            delete List;
            List = aux;
        }
        delete aux;
        List = NULL; // reinicia la lista
    }
}

/*
 * Otras opciones para deleteAll()
 *
 *
void deleteAll(Node *(&List))
{
    Node *aux = List;

    if (!isEmpty(List))
    {
        while (aux != NULL)
        {
            aux = aux->next;
            delete List;
            List = aux;
        }
    }
}

void deleteAll(Node *(&List))
{
    while(List)
        deleteBegin(List);
}
*/

void printList(Node *List)
{
    for (Node *aux = List; aux != NULL; aux = aux->next)
        printf("%s %i\n", aux->name, aux->age);
}

Node *searchList(Node *List, char name[])
{
    bool found = false;
    Node *aux = List;

    while (aux != NULL && !found)
    {
        if (strcmp(name, aux->name) == 0)
            found = true;
        else
            aux = aux->next;
    }

    return aux; // aux puede contener NULL o el nodo a buscar
}


//  T  A   R  E  A  orden descendente Z-A
void sortList(Node *(&List))
{
    Node temp;

    for (Node *aux = List; aux != NULL; aux = aux->next)
    {
        for (Node *aux2 = aux->next; aux2 != NULL; aux2 = aux2->next)
        {
            if (strcmp(aux->name, aux2->name) < 0)
            {
                strcpy(temp.name, aux->name);
                temp.age = aux->age;

                strcpy(aux->name, aux2->name);
                aux->age = aux2->age;

                strcpy(aux2->name, temp.name);
                aux2->age = temp.age;
            }
        }
    }
}


/** T  A  R  E  A
 * Interfaz para ni�os del kinder:
 * Add kid:
 * Print all kids:
 * Search kid:
 * Edit age (usa search kid)
 * Delete kid (usa search kid):
 * Sort kids:
 * Con menu, se manda llamar en main
 */

#endif /* simpleLinkedList_h */
