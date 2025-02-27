#include "Process.h"

Process::Process()
{
    int id = monte_carlo_sample() * 10;
    pid = monte_carlo_sample() * 10000;

    fileName = "assembly" + to_string(id) + ".txt";
    cout<<"pid: "<<pid<<" "<<fileName<<endl;
    //decoder = new Decoder(sFileName);
}

// Función de densidad f(x) = 2x en [0,1]
double Process::f(double x) {
    return 2.0 * x;
}

// Genera un número aleatorio uniformemente en el intervalo [0, 1]
double Process::random_uniform() {
    return (double)rand() / (double)RAND_MAX;
}

// Función que usa el método de aceptación-rechazo para muestrear de f(x)
double Process::monte_carlo_sample() {
    double x, y;
    bool exit = false;

    while (!exit) {
        // Generamos un candidato x de la distribución uniforme g(x)
        x = random_uniform();
        // Generamos un número y uniforme entre 0 y c (c=2 en este caso)
        y = random_uniform() * 2.0;
        // Si y está por debajo de f(x), aceptamos x
        if (y <= f(x))
            exit = true;
        // Sino, se repite el proceso
    }
    return x;
}

/* imprima los daatos del proceso: pid, activo, instrucciones */
void Process::printProcess()
{
    Process p;
    cout<<"PID: "<<p.Getpid()<<endl;
    cout<<"Active: "<<p.Getactive()<<endl;
    cout<<"Instruction: "<<p.GetinstructionCount()<<endl;
}
