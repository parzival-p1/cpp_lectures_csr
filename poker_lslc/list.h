#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "simpleLinkedList.h"

struct Data
{
    char name[20];
    int bet;
    int totalMoney;
    int exchange;
    Node *Cards;  // lista simplemente ligada lineal
};

struct Element  // lista simplemente ligada circular
{
    Data data; // data no es ptr
    Element *next;
};

bool clrIsEmpty(Element *List);
void clrPrint(Element *List, bool showCards); // jugador y apuesta
Element *getLast(Element *List);
Element *getNext(Element *List, Element *currentNode);

// Insert
void clrInsertBegin(Element *(&List), Element *newNode);
void clrInsertLast(Element *(&List), Element *newNode);
void insertInPosition(Element *(&List), Element *newNode, int pos);

// Delete
void clrDeleteBegin(Element *(&List));
void clrDeleteLast(Element *(&List));
void clrDeleteNode(Element *(&List), Element *deleteNode);
bool clrDeletePosition(Element *(&List), int pos);

// Search
Element *searchPLayer(Element *(List), char name[]);

/**
 * clrIsEmpty -
 * @List: puntero a Nodo
 * Return: true si la lista esta vacia, false si la lista no esta vacia
 */
bool clrIsEmpty(Element *List)
{
    if (List)
        return false;
    else
        return true;
}

/**
 * print - imprime los elentos de la lista
 * @List: puntero a Data
 */
 void clrPrint(Element *List, bool showCards)
 {
    Element *aux;
    if (clrIsEmpty(List))
        printf("La lista esta vacia\n");
    else
    {
        for (aux = List; aux->next != List; aux = aux->next)
        {
            printf("%s %i\n", aux->data.name, aux->data.bet);
            if (showCards)
                printList(aux->data.Cards); // las cartas se impriman, esta en simpleLinkedList.h
        }
    }
}


Element *getLast(Element *List)
{
    Element *aux = List;

    if (clrIsEmpty(List))
        return NULL;
    else
    {
        while (aux->next != List) // para uno antes del ultimo
            aux = aux->next;
        return aux;
    }

}

void clrInsertBegin(Element *(&List), Element *newNode)
{
    Element *last;

    if (clrIsEmpty(List))
    {
        List = newNode;
        List->next = List; // apunta a si mismo en el sig
    }
    else
    {
        last = getLast(List);
        last->next = newNode;
        newNode->next = List;
        List = newNode;
    }
}


// esta funcion no considera que el ultimo nodo es dummy
void clrInsertLast(Element *(&List), Element *newNode)
{
    Element *last;

    if (clrIsEmpty(List))
    {
        List = newNode;
        List->next = List;
    }
    else
    {
        last = getLast(List);
        last->next = newNode;
        newNode->next = List;
    }
}


// esta funcion no considera que el ultimo nodo es dummy
void insertInPosition(Element *(&List), Element *newNode, int pos)
{
    int cont = 1;
    Element *aux = List;

    if (clrIsEmpty(List))
        clrInsertBegin(List, newNode);
    else
    {
        if (pos <= 0)
            clrInsertLast(List, newNode);
        else
        {
            while (aux->next != List && cont < pos -1)
            {
                aux = aux->next;
                ++cont;
            }

        }
    }
}

// esta funcion no considera que el ultimo nodo es dummy
void clrDeleteBegin(Element *(&List))
{
    Element *last, *aux = List;

    if(!clrIsEmpty(List))
    {
        if (List->next == List) // un nodo
        {
            delete aux;
            List = NULL;
        }
        else // dos o mas nodos
        {
            last = getLast(List);
            List = aux->next;
            delete aux;
            last->next = List;
        }
    }
}

// esta funcion no considera que el ultimo nodo es dummy
void clrDeleteLast(Element *(&List))
{
    Element *last, *aux = List;

    if(!clrIsEmpty(List))
    {
        if (List->next == List) // hay 1 solo nodo
        {
            delete aux;
            List = NULL;
        }
        else // dos o mas nodos
        {
            last = getLast(List);

            while (aux->next != last)
                aux = aux->next;
            delete last;
            aux->next = List;
        }
    }
}

// esta funcion no considera que el ultimo nodo es dummy
void clrDeleteNode(Element *(&List), Element *deleteNode)
{
    Element *aux = List;

    if(!clrIsEmpty(List))
    {
        if (deleteNode == List)
            clrDeleteBegin(List);
        else
        {
            while (aux->next != deleteNode)
                aux = aux->next;
            aux->next = deleteNode->next;
            delete deleteNode;
        }

    }
}

// esta funcion no considera que el ultimo nodo es dummy
bool clrDeletePosition(Element *(&List), int pos)
{
    Element *deleteNode, *aux = List;

    int cont = 1;

    if (!clrIsEmpty(List))
    {
        if (pos < 1)
            return false;
        else
        {
            while (aux->next != List && cont < pos-1)
            {
                aux = aux->next;
                cont++;
            }
            if (aux->next != List)
            {
                deleteNode = aux->next;
                aux->next = deleteNode->next;
                delete deleteNode;
                return true;
            }
            else
                return false;
        }

    }
    else
        return false; // no borro
}


Element *searchPlayer(Element *(List), char name[])
{
    Element *aux = List;
    bool found = false;

    if (!clrIsEmpty(List))
    {
        while(aux->next != List && !found)
        {
            if(strcmp(name, aux->data.name) == 0)
                found = true;
            else
                aux = aux->next; // si no lo encontro, sigue caminando
        }
        // verifica si lo encontro, si no lo encontro hace una verificacion extra.
        if(found)
            return aux; // regresa el nodo donde lo encontro
        else if(strcmp(name, aux->data.name) == 0) // verifica porque el while no toca el ultimo.
            return aux;
        else
            return NULL; // no se encontro nada
    }
    else
        return NULL;
}

// esta funcion no considera que el ultimo nodo es dummy
Element *getNext(Element *List, Element *currentNode)
{
    if(clrIsEmpty(List))
        return NULL;
    else
    {
        if (currentNode->next == List)
            return NULL;
        else
            return currentNode->next;
    }
}

#endif // LIST_H_INCLUDED
