#include "Process.h"

Process::Process()
{
    int id = monte_carlo_sample() * 10;
    pid = monte_carlo_sample() * 10000;

    fileName = "assembly" + to_string(id) + ".txt";
    cout<<"Creando proceso con pid: "<<pid<<" "<<fileName<<endl;
    decoder = new Decoder(fileName);

    if (decoder->start(List)) {
        active = true;
        instructionCount = List.GetInstructionCount();
    }
    else
        cout<<"ERROR al leer el archivo para el proceso "<<pid<<endl;
}

Process::~Process()
{
    delete decoder;
}

// Funci�n de densidad f(x) = 2x en [0,1]
double Process::f(double x) {
    return 2.0 * x;
}

// Genera un n�mero aleatorio uniformemente en el intervalo [0, 1]
double Process::random_uniform() {
    return (double)rand() / (double)RAND_MAX;
}

// Funci�n que usa el m�todo de aceptaci�n-rechazo para muestrear de f(x)
double Process::monte_carlo_sample() {
    double x, y;
    bool exit = false;

    while (!exit) {
        // Generamos un candidato x de la distribuci�n uniforme g(x)
        x = random_uniform();
        // Generamos un n�mero y uniforme entre 0 y c (c=2 en este caso)
        y = random_uniform() * 2.0;
        // Si y est� por debajo de f(x), aceptamos x
        if (y <= f(x))
            exit = true;
        // Sino, se repite el proceso
    }
    return x;
}

/* imprima los daatos del proceso: pid, activo, instrucciones */
void Process::printProcess()
{
    cout<<"PID: "<<pid<<endl;
    if (active)
        cout<<"Status: Active"<<endl;
    else
        cout<<"Status: Inactive"<<endl;
    cout<<"Instruction count: "<<instructionCount<<endl;
}
