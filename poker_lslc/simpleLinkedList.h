//
//  simpleLinkedList.h
//  kinder_lsll
//
//  Created by Paco Hdez on 16/11/23.
//

#ifndef simpleLinkedList_h
#define simpleLinkedList_h

#include <string.h>
#include <stdlib.h>
#include <time.h>

/** T A R E A
 * Modificar el Nodo
 * Modificar funciones que dependan del tippo de dato:
 * Modificar: print debe imprimir numero y palo
 * Ej. searchList(numero, Palo) // la busqueda debe ser por los dos
 * Ej. 2 de pica, comparar el str del palo y el str del numero es el criterio de busqueda buscarlos
*/

// asignar un numero para cada palo, 0-corazones, 1-diamantes, 2-picas, 3-trebol
// asiganr un numero de 1 a 13

struct Node
{
    int suit;
    int num;
    Node *next;
};

// Insert
bool isEmpty(Node *List);
void insertBegin(Node *(&List), Node *newNode);
void insertLast(Node *(&List), Node *newNode);
// Delete
void deleteBegin(Node *(&List));
void deleteLast(Node *(&List));
void deleteCustom(Node *(&List), Node *prevNode);
void deleteAll(Node *(&List));
void deleteIndex(Node *(&List), int pos);

void printList(Node *List); // estas se quedann para el poker
Node *searchList(Node *List, int num, int suit);

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
        insertBegin(List, newNode);
    else
    {
    //  for (aux = List; aux->next; aux = aux->next)
        while (aux->next != NULL) // mientras aux no sea el ultimo
            aux = aux->next; // camina
        aux->next = newNode;
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
    int cont = 1;
    char suit[20];

    for (Node *aux = List; aux != NULL; aux = aux->next)
    {
        switch(aux->suit)
        {
            case 0: sprintf(suit, "Hearts"); break;
            case 1: sprintf(suit, "Diamonds"); break;
            case 2: sprintf(suit, "Spades"); break;
            case 3: sprintf(suit, "Clubs"); break;
        }
        switch(aux->num)
        {
            case 1: printf("Carta %i: A %s\n", cont++, suit); break;
            case 2: printf("Carta %i: 2 %s\n", cont++, suit); break;
            case 3: printf("Carta %i: 3 %s\n", cont++, suit); break;
            case 4: printf("Carta %i: 4 %s\n", cont++, suit); break;
            case 5: printf("Carta %i: 5 %s\n", cont++, suit); break;
            case 6: printf("Carta %i: 6 %s\n", cont++, suit); break;
            case 7: printf("Carta %i: 7 %s\n", cont++, suit); break;
            case 8: printf("Carta %i: 8 %s\n", cont++, suit); break;
            case 9: printf("Carta %i: 9 %s\n", cont++, suit); break;
            case 10: printf("Carta %i: 10 %s\n", cont++, suit); break;
            case 11: printf("Carta %i: J %s\n", cont++, suit); break;
            case 12: printf("Carta %i: Q %s\n", cont++, suit); break;
            case 13: printf("Carta %i: K %s\n", cont++, suit); break;
        }

    }
}

Node *searchList(Node *List, int num, int suit)
{
    bool found = false;
    Node *aux = List;

    while (aux != NULL && !found)
    {
        if (num == aux->num && suit == aux->suit)
            found = true;
        else
            aux = aux->next;
    }
    return aux; // aux puede contener NULL o el nodo a buscar
}

void deleteIndex(Node *(&List), int pos)
{
    Node *deleteNode, *aux = List;

    int cont = 1;

    if (!isEmpty(List))
    {
        if (pos >= 1 && pos <= 5)
        {
            while (aux->next != NULL && cont < pos-1)
            {
                aux = aux->next;
                cont++;
            }
            if(aux->next != NULL)
            {
                if (aux != List)
                {
                    deleteNode = aux->next;
                    aux->next = deleteNode->next;
                    delete deleteNode;
                }
                else
                {
                    deleteNode = aux;
                    List = List->next;
                    delete deleteNode;
                }
            }
        }
    }
}


#endif /* simpleLinkedList_h */
