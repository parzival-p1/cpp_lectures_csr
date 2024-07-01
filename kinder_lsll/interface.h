//
//  interface.h
//  kinder_lsll
//
//  Created by Paco Hdez on 16/11/23.


/** T  A  R  E  A
 * Interfaz para niños del kinder:
 * Add kid:
 * Print all kids:
 * Search kid:
 * Edit age (usa search kid)
 * Delete kid (usa search kid):
 * Sort kids:
 * Con menu, se manda llamar en main
 */

#ifndef interface_h
#define interface_h

#include "simpleLinkedList.h"

void Init();
void menu(Node *(&List));
void addKid(Node *(&List));
void printKid(Node *List);
void editKid(Node *List);
int searchList(Node *List);
int searchKid(Node *List);
void deleteKid(Node *(&List));
void menuKid();

/**
 * Init - inicializa el programa
 */
void Init()
{
    Node *List = NULL;  // Inicializamos la lista
    menu(List);
}

/**
 * menu - selecciona las opciones disponibles
 * @List: referencia puntero a Node
 */

void menu(Node *(&List))
{
    int opt;

    do {
        printf("1. Agregar estudiante\n");
        printf("2. Imprimir datos del estudiante\n");
        printf("3. Editar datos del estudiante\n");
        printf("4. Borrar estudiante\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%i", &opt);

        switch (opt)
        {
            case 1: addKid(List); break;
            case 2: printKid(List); break;
            case 3: editKid(List); break;
            case 4: deleteKid(List); break;
            case 5: printf("Gracias por utilizar el catalogo! 😇\n"); break;
            default: printf("La opcion ingresada no es valida\n"); break;
        }

    } while (opt != 5);
}

/**
 * addKid - Agrega un nuevo elemento al catalogo
 * @List: referencia puntero a Node
 */
void addKid(Node *(&List))
{
    Node *newNode = new Node;

    printf("Introduzca el nombre del estudiante: ");
    scanf("%s", newNode->name);

    printf("Introduzca la edad: ");
    scanf("%i", &newNode->age);

    insertLast(List, newNode); // aqui como va el ptr?
    printf("El infante se ha agregado con exito\n");
}

/**
 * printKid - imprime todos los elementos de la lista
 * @List: puntero a Node
 */
void printKid(Node *List)
{
    if (isEmpty(List))
        printf("No hay infantes para imprimir\n");
    else
        printList(List);
}

/**
 * editKid - edita las caracteristicas del alumno en la lista
 * @List: referencia puntero a Node
 */
void editKid(Node *List)
{
    Node *editNode = NULL;
    char name[20];

    printf("Introduzca el nombre del ninho a buscar: ");
    scanf("%s", name);

    editNode = searchList(List, name);

    if (editNode == NULL) // Pendiente
        printf("No se ha encontrado infante.\n");
    else
    {
        printf("Introduzca el nombre del infante: ");
        scanf("%s", editNode->name);

        printf("Introduzca la edad del infante: ");
        scanf("%i", &editNode->age);
    }
}

/**
 * deleteKid: elimina un alumno de la lista
 * @List: referencia puntero a Node
 */
void deleteKid(Node *(&List))
{
    Node *deleteNode;
    char name[20];

    printf("Introduzca el nombre del ninho: ");
    scanf("%s", name);

    deleteNode = searchList(List, name);

    if (deleteNode == NULL)
        printf("No se encontro al infante, no es posible eliminarlo\n");
    else
    {
        deleteCustom(List, deleteNode); // borra el nodo de la lista
        printf("El infante ha sido borrado de la lista!\n");
    }

}

#endif /* interface_h */
