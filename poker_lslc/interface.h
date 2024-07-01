#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "list.h"
#include "arrayList.h"

void createPlayer(Element *(&playerList));             // param por default van al final SIEMPRE
void placeBet(Element *playerList, int &moneyOnTable, bool startBet = false);
void dealCards(Element *playerList, Node *(&discardList), int &last, int &MAX, bool firstDeal = false);

int findCardIndex(Node *discardList, int last, int suit, int number);
void reviewGame(Element *playerList); // revisa las cartas del jugador, escoge las que va a eliminar, las borra de su lista, y regresa cuantas cartas quiere
void printPlayerGame(Element *player);

void Init()
{
    int players, moneyOnTable;
    char answer;
    char name[20];
    Element *playerList = NULL, *player;
    Element *dummyPlayer = new Element;
    int last = 0, MAX = 5;
    Node *discardList = new Node[MAX];
    printf("♠ ♥ ♣ ♦");

    do
    {
        clrInsertBegin(playerList, dummyPlayer);
        moneyOnTable = 0;
        srand(NULL);
        printf("Introduzca el numero de jugadores: ");
        scanf("%i", &players);

        for(int i = 0; i < players; i++)
            createPlayer(playerList);
        placeBet(playerList, moneyOnTable, true);
        dealCards(playerList, discardList, last, MAX, true);
        reviewGame(playerList);
        dealCards(playerList, discardList, last, MAX);
        placeBet(playerList, moneyOnTable);
        player = playerList;

        while(player->next != playerList)
        {
            printPlayerGame(player);
            player = player->next;
        }

        printf("Escribe el nombre del jugador que gano: ");
        scanf("%s", name);

        player = searchPlayer(playerList, name);
        if(player != NULL)
        {
            player->data.totalMoney += moneyOnTable;
            printf("Money on Table %i\n", moneyOnTable);
            printf("Se actualizo el monto total del jugador %s, monto nuevo: %i\n", name, player->data.totalMoney);
        }
        fflush(stdin);
        printf("Game Over, deseas volver a jugar?(s\\n): ");
        scanf("%c", &answer);

    } while(answer != 'n');
}

void createPlayer(Element *(&playerList))
{
    Element *player = NULL;
    player = new Element;
    player->data.Cards = NULL; // lista simplemente ligada (contiene las cartas)
    player->data.exchange = 0;

    printf("Introduzca el nombre del jugador: ");
    scanf("%s", player->data.name);

    printf("Introduzca su efectivo: ");
    scanf("%i", &player->data.totalMoney);

    clrInsertBegin(playerList, player);

    printf("Jugador creado con exito!\n");
}

void placeBet(Element *playerList, int &moneyOnTable, bool startBet)
{
    Element *aux = playerList;
    int bet = 20;

    if(!clrIsEmpty(playerList))
    {
        while(aux->next != playerList)
        {
            if(!startBet) // startbet == false
            {
                printf("Que cantidad desea apostar: ");
                scanf("%i", &bet);
            }

            if(aux->data.totalMoney - bet >0)
            {
                aux->data.bet = bet;
                aux->data.totalMoney -= bet;
                moneyOnTable += bet;
                printf("Jugador %s apuesta $%i\n", aux->data.name, aux->data.bet);
                aux = aux->next;
            }
        }
    }
    else
        printf("No hay jugadores\n");
}


void dealCards(Element *playerList, Node *(&discardList), int &last, int &MAX, bool firstDeal)
{
    int numCards = 5;
    int cont = 0;
    Element *player = playerList;


    if(!clrIsEmpty(playerList))
    {
        while(player->next != playerList)
        {
            if(!firstDeal)
            {
                printf("Repartiendo %i cartas al jugador %s \n", player->data.exchange, player->data.name);
                numCards = player->data.exchange;
            }

            cont = 0;
            while(cont < numCards) // reparte las cartas lo que diga numCards
            {
                // 1. GENERAR DE MANERA ALEATORIA UN PALO Y UN NUMERO con rand()
                int randomSuit = rand() % 4;
                int randomNum = rand() % 13 + 1;

                // 2. BUSCAR EN EL ARRAYLIST discardList(); EL PALO Y EL NUMERO GENERADO EN PASO 1
                int index = findCardIndex(discardList,last, randomSuit, randomNum);

                if (index == -1) // si la carta es nueva entonces agregala
                {
                    Node *newNode = new Node;
                    newNode->suit = randomSuit;
                    newNode->num = randomNum;
                    newNode->next = NULL;

                    ArrInsertLast(discardList, *newNode, last, MAX); // La carta no se encontró en discardList, agregarla a discardList;
                    insertLast(player->data.Cards, newNode); // inserta en la lista simplemente ligada del jugador
                    cont++;
                }
            }
            player = player->next;
        }
    }
    else
        printf("No hay jugadores en la lista\n");
}

/**
 *
 *
 */

int findCardIndex(Node *discardList, int last, int suit, int number)
{
    int index = 0;
    bool found = false;

    while(index < last && !found)
    {
        if(discardList[index].suit == suit && discardList[index].num == number)
            found = true;
        else
            index++;
    }

    if(found)
        return index;
    else
        return -1;
}

void reviewGame(Element *playerList)
{
    Element *player = playerList;
    int card;
    char answer;

    if(!clrIsEmpty(playerList))
    {
        while(player->next != playerList)
        {
            do
            {
                printPlayerGame(player);
                printf("Deseas cambiar alguna carta(s\\n): ");
                fflush(stdin);
                scanf("%c", &answer);
                if(answer == 's')
                {
                    printf("Que carta desea cambiar? ");
                    scanf("%i", &card);

                    if(player->data.Cards->next != NULL)
                    {
                        deleteIndex(player->data.Cards, card);
                        player->data.exchange++;
                    }
                    else
                        printf("El jugador debe quedarse al menos con una carta\n");
                }

            } while(answer != 'n');

            player = player->next;
        }
    }
    else
        printf("No hay jugadores\n");
}

void printPlayerGame(Element *player)
{
    if(player)
    {
        printf("--------------------------------------------------\n");
        printf("Nombre del jugador: %s\n", player->data.name);
        printf("Monto total del jugador: %i\n", player->data.totalMoney);
        printList(player->data.Cards);
        printf("--------------------------------------------------\n");
    }
    else
        printf("No hay jugador seleccionado.\n");

}


/** T a r e a
 * 1. Recorrer la lista de jugadores
 * 2. Por cada jugador asignar de manera aleatoria con while() 5 cartas a cada uno
 * 3. Generar 5 cartas distintas usando rand();
 * 4. si quiero generar 1-10 int i = rand() % 10 + 1;
 * 5. quiero generar 0-5 int i = rand() % 6;
 * 6. estudair rand()
 * 7. generar un  suit y un numero de manera aleatoria. Hay 4 suits y 13 numero
 *
 */

 /** Dudas Tarea
  * 1. en el paso es necesaria una nueva funcion de busqueda? ej. findCardaIndex()? que encuentre el palo y numero generados en el paso 1?
  * 2. si creo la funcion findCardIndex() para descartar palo y numero resolveria el paso 3 y 4 con esta misma funcion? o necesito crear funciones distintas?
  */


#endif // INTERFACE_H_INCLUDED
