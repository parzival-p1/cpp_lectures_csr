#include <iostream>

using namespace std;

#define MAX 10

class Son
{
    public:
        string name;
        int age;

};

class Pet
{
    public:
        string name;
        string cast;
        int age;
};

class Friend
{
    public:
        string name;
        int age;
        Son sons[MAX];
        Pet pets[MAX];
};

void orderFriendsByAge(Friend friends[])
{
    int i = 0, j;
    Friend aux;

    while (i < MAX)
    {
        j = i+1;
        while (j < MAX)
        {
            if (friends[i].age < friends[j].age)
            {
                aux = friends[i];
                friends[i] = friends[j];
                friends[j] = aux;
            }
            j++;
        }
        i++;
    }
}

void orderFriendsByName(Friend friends[])
{
    Friend aux;
    int i = 0, j;

    while (i < MAX)
    {
        j = i + 1;
        while (j < MAX)
        {
            if (friends[i].name < friends[j].name)
            {
                aux = friends[i];
                friends[i] = friends[j];
                friends[j]  = aux;
            }
            j++;
        }
        i++;
    }
}

void orderFriendsSonsByAge(Friend friends[])
{
    int i = 0, j, k;
    Son aux;

    while (i < MAX)  // recorre amigo por amigo
    {
        j = 0;
        while (j < MAX)
        {
            k = j+1;
            while(k < MAX)
            {
                if (friends[i].sons[j].age < friends[i].sons[k].age)
                {
                    aux = friends[i].sons[j];
                    friends[i].sons[j] = friends[i].sons[k];
                    friends[i].sons[k] = aux;
                }
            }
            k++;
        }
        j++;
    }
    i++;
}


























































































void orderFriendsSonsByName(Friend friends[])
{
    int i = 0, j, k;
    Son aux;

    while (i < MAX)
    {
        j = 0;
        while (j < MAX)
        {
            k = j+1;
            while (k < MAX)
            {
                if (friends[i].sons[j].name < friends[i].sons[j].name)
                {
                    aux = friends[i].sons[j];
                    friends[i].sons[j] = friends[i].sons[k];
                    friends[i].sons[k] = aux;
                }
            }
            k++;
        }
        j++;
    }
    i++;
}


int main()
{
    Friend friends[MAX]; // es un arr de tipo friend

    orderFriendsByAge(friends);
    orderFriendsByName(friends);

    orderFriendsSonsByAge(friends);
    orderFriendsSonsByName(friends);

    return 0;
}

