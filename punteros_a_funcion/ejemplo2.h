#ifndef EJEMPLO2_H_INCLUDED
#define EJEMPLO2_H_INCLUDED

#include <iostream>

using namespace std;

struct funcNames {
    /* suma, resta, multi, division */
    char op;
    double (*ptrFunc)(double, double);
};

double suma(double a, double b)
{
    return a + b;
}

double resta(double c, double d)
{
    return c - d;
}

double multi(double e, double f)
{
    return e * f;
}

double division(double g, double h)
{
    return h == 0 ? 0 : g / h;
}

/* Punteros a funcion como parametro */
double operacion (double (*ptrOp)(double, double), double a, double b)
{
    return ptrOp(a, b);
}

void run()
{
    /* Arreglo de punteros a funciones*/
    double x = 3, y = 4, z;

    double (*funcPtr[4])(double, double) = {suma, resta, multi, division};
    for (int i = 0; i < 4; i++) {
        z = funcPtr[i](x, y);
        cout<<z<<endl;
    }

    /* Arreglo de estructuras tipo diccionario */
    cout<<"-------------------------------------"<<endl;
    funcNames operations[4];

    operations[0].op = '+';
    operations[0].ptrFunc = suma;

    operations[1].op = '-';
    operations[1].ptrFunc = resta;

    operations[2].op = '*';
    operations[2].ptrFunc = multi;

    operations[3].op = '/';
    operations[3].ptrFunc = division;

    for (int i = 0; i < 4; i++) {
        cout<<x<<operations[i].op<<y<<"="<<operations[i].ptrFunc(x, y)<<endl;
    }

    /* Punteros a funcion como parametro */
    cout<<"-------------------------------------"<<endl;

    cout<<x<<" + "<<y<<" = "<<operacion(suma, x, y)<<endl;
    cout<<x<<" - "<<y<<" = "<<operacion(resta, x, y)<<endl;
    cout<<x<<" * "<<y<<" = "<<operacion(multi, x, y)<<endl;
    cout<<x<<" / "<<y<<" = "<<operacion(division, x, y)<<endl;
}

#endif // EJEMPLO2_H_INCLUDED
