#include "Alu.h"

Alu::Alu()
{
    //ctor
}

int Alu::cmdAdd(int a, int b)
{
    return a + b;
}

int Alu::cmdSub(int a, int b)
{
    return a - b;
}

int Alu::cmdMul(int a, int b)
{
    return a * b;
}

int Alu::cmdAnd(int a, int b)
{
    return a & b;
}

int Alu::cmdOr(int a, int b)
{
    return a | b;
}

int Alu::cmdXor(int a, int b)
{
    return a ^ b;
}

int Alu::cmdCmp(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

int Alu::execute(string sOpcode, string sSource, string sDestination) // 3 paramaetros sOpcode para el cmd a recibir, sSource para el origen del cmd y destination a donde va el cmd
{
    int isource = stoi(sSource, nullptr, 10); // convierte el str isource a entero
    int idestination = stoi(sDestination, nullptr, 10); // convierte el str destination a enterio
    int i = 0, res; // contador i para que recorra el array validCmd y encuentre el OpCode, usaremos la var entera res para guardar el resultado
    bool found = false; // la variable found se utilizara para detener el while una vez se haya encontrado el Opcode dentro del array validCmd

    while (i < cmdCount && !found) // el while va a iterar de 0 a 7 hasta que encuentre el OpCode requerido
    {
        if (validCmd[i] == sOpcode) // la condicion indica que el comando encontrado en el array validCmd en la posicion dada i debera ser igual al parametro sOpcode
            found = true; // una vez que el comando encontrado en el array validCmd en la posicion dada i sea igual al OpCode la variable found cambiara a true
        else // de no ser asi i debera seguir iterando hasta encontrar la condicion requerida.
            i++;
    }

    switch (i) { // se evaluaran distintos casos con un switch donde i itera sobre el array validCmd cuando encuentre un OpCode mandara a llamar la funcion requerida en cada caso del switch
        case 0: res = cmdAdd(isource, idestination); break; // caso 0: si validCmd en la posicion i es igual a "ADD" se mandara a llamar la funcion en el caso 0
        case 1: res = cmdSub(isource, idestination); break; // caso 1: si validCmd en la posicion i es igual a "SUB" se mandara a llamar la funcion en el caso 1
        case 2: res = cmdMul(isource, idestination); break; // caso 2: si validCmd en la posicion i es igual a "IMUL" se mandara a llamar la funcion en el caso 2
        case 3: res = cmdAnd(isource, idestination); break; // caso 3: si validCmd en la posicion i es igual a "AND" se mandara a llamar la funcion en el caso 3
        case 4: res = cmdOr(isource, idestination); break;  // caso 4:  si validCmd en la posicion i es igual a "OR" se mandara a llamar la funcion en el caso 4
        case 5: res = cmdXor(isource, idestination); break; // caso 5: si validCmd en la posicion i es igual a "XOR" se mandara a llamar la funcion en el caso 5
        case 6: res = cmdCmp(isource, idestination); break; // caso 6: si validCmd en la posicion i es igual a "CMP" se mandara a llamar la funcion en el caso 6
    }
    return res; // return el resultado de las funciones iteradas en el switch
}
