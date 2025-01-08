#include "Decoder.h"

Decoder::Decoder(string sFileName)
{
    this->sFileName = sFileName;
}

Decoder::~Decoder()
{
    //dtor
}

/*
 * Busca en el arr si es una palabra reservada o no
 *
 *
 *
*/

bool Decoder::isReservedWord(string sWord)
{
    string validCmd [] = {"JMP", "MOV", "ADD", "SUB", "IMUL", "AND", "OR", "XOR", "CMP"};
    int i = 0;
    bool found = false;

    while (i < 9 && !found)
    {
        if(validCmd[i] == sWord)
            found = true;
        else
            i++;
    }
    return found;
}

/*
 * validar que exista el comando en el arr validCmd
 * validar que el numero de palabras del cmd sean validas
 * return: true si las 2 validaciones anteriores son ciertas
 * return: false si las 2 previas validaciones previas
*/
bool Decoder::validComand(InstructionList &List, string sLine, int iCount)
{
    Instruction *node = new Instruction;
    string sWord;
    bool valid;
    istringstream ssConversion(sLine); // istringstream es un tipo de dato para que el str se comporte como un flujo (consola, arch, etc).
    getline(ssConversion, sWord, ' '); // necesita recibir un flujo en su 1er param.

    if (iCount == 1 && !isReservedWord(sWord)) // valida que sea una etiqueta
    {
        valid = true;
        node->SetsTag(sWord);
    }
    else if (iCount == 2 && sWord == "JMP")
    { // valida que el cmd sea JMP
        // count == 2 palabras && es JMP todo bien
        valid = true;
        node->SetsOpcode(sWord);
        getline(ssConversion, sWord, ' '); // ahora lee la sig palabra que es la etiqueta
        node->SetsTag(sWord);
    }
    else if (iCount == 3 && sWord != "JMP" && isReservedWord(sWord))
    { // valida el resto de los cmds que existen
        // que validCmd que sean 3 && que !JMP
        valid = true;
        node->SetsOpcode(sWord);
        getline(ssConversion, sWord, ' ');
        node->SetsSource(sWord);
        getline(ssConversion, sWord, ' ');
        node->SetsDestination(sWord);
    }
    else { // cacha todas las excepciones, todo lo que no cae arriba
        // toodo lo que no esta bien!  ESTO ES UN PARSER!
        valid = false;
    }

    if (valid)
    {
        List.insertLast(node); // inserta el nodo en la lista
    }
    return valid;
}

/*
* "MOV $EDX $ADX"
* cuenta cu�ntas palabras hay en sLine
* si hay un espacio he encontrado una palabra, y hasta llegar al final del str
* return: numero de palabras
*/
int Decoder::wordCount(string sLine)
{
    int len  = sLine.length(), icount = 0;

    for (int i = 0; i < len; i++) {
        if (sLine[i] == ' ')
            icount++;
    }
    icount++;
    return icount;
}

bool Decoder::start(InstructionList &List)
{
    ifstream file(sFileName);
    string sLine;
    int iCount;
    bool bError = true;

    if (!file.is_open()) {
        cout<<"no se pudo abrir el archivo!";
        return false;
    }
    else
    {
        while(getline(file, sLine) && bError)
        {
            iCount = wordCount(sLine);

            if (validComand(List, sLine, iCount)) {
                cout<<"El comando fue valido: "<<sLine<<endl;
            }

            else {
                cout<<"El comando no existe o hay un error de sintaxis: "<<sLine<<endl;
                bError = false;
            }
        }
        file.close();
        return bError;
    }
}
