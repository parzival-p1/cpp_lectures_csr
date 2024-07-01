#include "Sudoku.h"

Sudoku::Sudoku()
{
    this->sudoku = new unsigned int*[sqrs]; // int sqrs[I][J]
    controlCount = 0;

    for (unsigned int i = 0; i < sqrs; i++)
        sudoku[i] = new unsigned int[sqrs];

    this->gameCount = 0;
    this->totalZeros = 0;

    // srand seed
    srand(time(nullptr));
}

Sudoku::~Sudoku()
{
    for (unsigned int i = 0; i < sqrs; i++)
        delete[] sudoku[i];
    delete [] sudoku;
}

void Sudoku::readFile()
{
    fstream file;

    file.open("sudoku_todo.txt");

    if (file.fail())
        cout<<"No pude abrir el archivo"<<endl;
    else
    {
        while(getline(file, games[gameCount]))
        {
            gameCount++;
        }
    }
}

void Sudoku::archivos()
{
    cout<<"Línea!"<<endl;
    fstream archivo;
    string linea;

    archivo.open("datos.txt");

    archivo << "Primera línea de texto" << endl;
    archivo << "MacOs over Windows always!!!" <<endl;
    archivo << "VSCode sucks just 4 cpp" <<endl;
    archivo << "Xcode sucks" <<endl;
    archivo << "i really hate Microsoft products" <<endl;

    archivo.close();

    archivo.open("datos.txt");

    while(getline(archivo, linea))
    {
        cout<<linea<<endl;
    }
    archivo.close();
}

unsigned int Sudoku::charToDigit(const char a)
{
    unsigned int b;

    switch (a)
    {
        case '0': b = 0; break;
        case '1': b = 1; break;
        case '2': b = 2; break;
        case '3': b = 3; break;
        case '4': b = 4; break;
        case '5': b = 5; break;
        case '6': b = 6; break;
        case '7': b = 7; break;
        case '8': b = 8; break;
        case '9': b = 9; break;
        default: b = 0;
    }
    return b;
}
void Sudoku::pause()
{
    cout<<"Press any key to continue ..."<<endl;
    fflush(stdin);
    getchar();
}

void Sudoku::run()
{
    int opt;
    int currentGame;

    readFile();

    do {
        currentGame = rand() % gameCount;
        system("cls");
        cout<<"1. New Game!"<<endl;
        cout<<"0. Exit Game!"<<endl;
        cout<<"Option: ";

        cin>>opt;
        if (opt == 1)
        {
            readSudoku(currentGame);
            //testSudoku();
            printSudoku();
            pause();
            solveSudoku();
            pause();
            system("cls");
            printSudoku();
        }
        else if (opt == 0)
            cout<<"Thank you, bye!"<<endl;
        else
            cout<<"Invalid option!"<<endl;
        pause();
    } while(opt != 0);
}

// D E BB U G G E A R  R E A D  S U D  O K U
void Sudoku::readSudoku(int currentGame) // insert data
{
    string data = games[currentGame]; // string -> int
    unsigned int a = 0, b = 0;
    totalZeros = 0;

//    cout<<"Enter Sudoku data: ";
//    fflush(stdin);
//    getline(cin, data);

    for (unsigned int i = 0; i < data.length(); i++) // "string"
    {
        if (isdigit(data.at(i)) != 0) { // checa el valor de la pos i en string data.
            // convertir str -> int

//            if (data.at(i) == '0')
//                totalZeros++;

            sudoku[a][b] = charToDigit(data.at(i));

            if (sudoku[a][b] == 0)
                totalZeros++;

            if (b == 8) {
                b = 0;
                a++;
            }
            else
                b++;
        }
    }
    progress = 0;

}

 // T A R E A  debuggear la func de abajo
//  T A R E A debuggear todas las funciones

//void Sudoku::printSudoku() // print sudoku and solved sudoku
//{
//    cout<<"Imprimiendo matriz..."<<endl;
//    for (unsigned int i = 1; i <= sqrs; i++)
//    {
//        for (unsigned int j = 1; j <= sqrs; j++)
//        {
//            cout<<sudoku[i-1][j-1]<<" ";
//            if (j % 3 == 0)
//                cout<<" ";
//        }
//
//        cout<<endl;
//        if (i % 3 == 0)
//            cout<<endl;
//    }
//}

void Sudoku::printSudoku() // print sudoku and solved sudoku
{
    int aux = 0, aux2 = 0;

    cout<<"Imprimiendo matriz..."<<endl;
    for (unsigned int i = 0; i < sqrs; i++)
    {
        for (unsigned int j = 0; j < sqrs; j++)
        {
            cout<<sudoku[i][j]<<" ";
            aux++;

            if (aux % 3 == 0)
                cout<<" "; // add space each 3 pos
        }
        cout<<endl;
        aux2++;

        if (aux2 % 3 == 0)
            cout<<endl; // add blank line each 3 rows
    }
}

void Sudoku::printBar()
{
    float partial = 0;

    partial = 100 / totalZeros;
    progress += partial;


    cout<<" [ ";

    int i = 0;
    int barSqrs = progress / 5;

    if (static_cast<int>(progress) % 5 != 0)
        barSqrs += 1;

    while (i < barSqrs)
    {
        cout << char(219)<<" ";
        i++;
    }

    i = 0;
    int emptySqrs = 20 - barSqrs;

    while (i < emptySqrs)
    {
        cout <<"  ";
        i++;
    }

    cout<<" ] "<< progress <<" %"<<endl;
}

void Sudoku::reviewRow(unsigned int row, unsigned int column)
{
    int presentNum[sqrs] = {0};

    // Paso 1: Recorrer la fila y busca los numeros que tengo
    for (unsigned int col = 0; col < sqrs; ++col)
        if (sudoku[row][col] != 0)
            presentNum[sudoku[row][col] -1] = sudoku[row][col]; // agrega a los numeros presentes

    for (unsigned int col = 0; col < sqrs; ++col)
        if (presentNum[col] == 0) {
            missingNumbers[controlCount] = col + 1;
            controlCount++;
        }
}

void Sudoku::reviewColumn(unsigned int row, unsigned int column)
{
    // recorrer la columna column del Sudoku y buscar los numeros que si se encuentran
    for (unsigned int index = 0; index < sqrs; ++index)
    {
        if (sudoku[index][column] != 0)
        {
            // recorre missing numbers comparando con la CASILLA actual del sudoku[index][column]
            for (unsigned int col = 0; col < controlCount; ++col)
            {
                if (sudoku[index][column] == missingNumbers[col]) { // revisa que la casilla actual sea igual a un numero faltante
                    // hace un corrimiento a la izq del array
                        for (unsigned int i = col; i < controlCount; i++)
                            missingNumbers[i] = missingNumbers[i + 1]; // reemplaza el numero actual por el siguiente
                        controlCount--;
                }
            }
        }
    }
}

void Sudoku::reviewGrid(unsigned int row, unsigned int column)
{
    unsigned int a = column - (column % 3), b = column - (column % 3) + 2;
    unsigned int x = row - (row % 3), y = row - (row % 3) + 2;

    for (unsigned int i = x; i <= y; i++)
    {
        for (unsigned int j = a; j <= b; j++)
        {
            if (sudoku[i][j] != 0)
            {
                for (unsigned int index = 0; index < controlCount; index++) {
                    if (sudoku[i][j] == missingNumbers[index]) {
                        for (unsigned int pos = index; pos < controlCount; pos++)
                            missingNumbers[pos] = missingNumbers[pos + 1];
                        controlCount--;
                    }
                }
            }
        }
    }
}

void Sudoku::solveSudoku()
{
    unsigned int row = 0, column;
    bool dataError = false;

    while (!sudokuComplete() && !dataError)
    {
        row = 0; // column = 0;  Reiniciamos la columna a 0 en cada iteración de fila
        column = -1;

        while (row < sqrs && !dataError)
        {
            Sleep(100);
            column = getFstEmpty(row, column + 1); // trae el 1er 0 de la fila
            if (column != 999)
            {
                reviewRow(row, column);
                if (controlCount == 0)
                    dataError = true;
                else if (controlCount > 1) {
                    reviewColumn(row, column);
                    if (controlCount == 0)
                        dataError = true;
                    else if (controlCount > 1) {
                        reviewGrid(row, column);
                        if (controlCount == 0)
                            dataError = true;
                        else if (controlCount == 1)
                        {
                            sudoku[row][column] = missingNumbers[0];
                            system("cls");
                            cout<<"encontre el numero: "<<sudoku[row][column]<<" fila: "<<row<<" columna: "<<column;
                            printBar();
                        }
                        else
                        {
                            //cout<<"No pude determinar el numero en la fila: "<<row<<" columna: "<<column<<endl;
                            //pause();
                        }

                    }
                    else
                    {
                        sudoku[row][column] = missingNumbers[0];
                        system("cls");
                        cout<<"encontre el numero: "<<sudoku[row][column]<<" fila: "<<row<<" columna: "<<column;
                        printBar();
                    }

                }
                else
                {
                    sudoku[row][column] = missingNumbers[0];
                    system("cls");
                    cout<<"encontre el numero: "<<sudoku[row][column]<<" fila: "<<row<<" columna: "<<column;
                    printBar();
                }

            }
            else
            {
                row++;
                column = -1;
            }
            controlCount = 0;
        }
        // row++  Incrementamos la fila para la siguiente iteración
    }
    if (dataError)
        cout<<"Los datos son erroneos, se encontro un problema en la fila: "<<row-1<<" y columna: "<<column<<endl;
}

bool Sudoku::sudokuComplete()
{
    bool found = false;
    unsigned int aux = 0, aux2;

    while (aux < sqrs && !found)
    {
        aux2 = 0;
        while (aux2 < sqrs && !found)
        {
            if (sudoku[aux][aux2] == 0)
                found = true;
            aux2++;
        }
        aux++;
    }
    return !found;
}



/*
    Primer casilla que encuentre vacia en una fila dada
    return -1: si la fila ya esta llena
 */
unsigned int Sudoku::getFstEmpty(unsigned int row, unsigned int column)
{
    bool found = false;

    while (column < sqrs && !found)
    {
        if (sudoku[row][column] == 0)
            found = true;
        else
            column++;
    }

    if (found)
        return column;
    else
        return 999;
}

void Sudoku::testSudoku()
{
    for (unsigned int i = 0; i < sqrs; i++)
    {
        for (unsigned int j = 0; j < sqrs; j++)
            sudoku[i][j] = 0;
    }
    printSudoku();
}
