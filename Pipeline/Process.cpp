#include "Process.h"

/*
 * Process - represnta un proceso dentro dl sistema de simulacion
*/
Process::Process()
{
    int id = monte_carlo_sample() * 10;
    pid = monte_carlo_sample() * 10000;

    fileName = "process/assembly" + to_string(id) + ".txt";
    // cout<<"Creando proceso con pid: "<<pid<<" "<<fileName<<endl;
    decoder = new Decoder(fileName);

    if (decoder->start(List))
    {
        active = true;
        instructionCount = List.GetInstructionCount();
        cpuReg.cleanRegisters();
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

    while (!exit)
    {
        // Generamos un candidato x de la distribuci�n uniforme g(x)
        x = random_uniform();
        // Generamos un n�mero y uniforme entre 0 y c (c=2 en este caso)
        y = random_uniform() * 2.0;
        // Si y est� por debajo de f(x), aceptamos x
        if (y <= f(x) && x >= 0.1)
            exit = true;
        // Sino, se repite el proceso
    }
    return x;
}

/* imprima los daatos del proceso: pid, activo, instrucciones */
void Process::printProcess()
{
    cout<<"PID: "<<pid;
    if (active)
        cout<<" -- Status: Active";
    else
        cout<<" -- Status: Inactive";
    cout<<" -- Total instruction count: "<<List.GetTotalCount()<<" -- Total instruction remaining: "<<List.GetInstructionCount()<<endl;
}

// Debe recibir x cantidad de instrucciones para rr
bool Process::execute(int maxInstructions)
{
    List.configListToExecute(maxInstructions);
    cout<<"\tExecuting PID: "<<pid<<endl;

    while (!List.instEndState())
    {
        List.changeInstructionState();
        List.print(myAlu, cpuReg);
        //cin.ignore(); // cada ve que se presione enter = ciclo de reloj
    }
    List.resetList();

    if (List.isEmpty())
        active = false;
    fflush(stdin);
    return List.isEmpty();
}
