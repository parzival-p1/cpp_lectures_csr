#ifndef EJEMPLO1_H_INCLUDED
#define EJEMPLO1_H_INCLUDED

#include <iostream>

using namespace std;
int cuadrado(int a)
{
    return a*a;
}

int cubo (int b)
{
    return b*b*b;
}

void run()
{
    int x, y;
    int (*ptrFunc)(int); // puntero a func

    ptrFunc = cuadrado; // ptrFunc toma la direccion de cuadrado
    x = ptrFunc(2); // a x se le asigna el valor que regresa la funciona asignada a ptrFunc
    ptrFunc = cubo; // ptrFunc toma la direccion de cubo
    y = ptrFunc(2); // y toma el valor que regresa la func asignada a ptrFunc
    cout<<x<<endl<<y;
}

#endif // EJEMPLO1_H_INCLUDED
