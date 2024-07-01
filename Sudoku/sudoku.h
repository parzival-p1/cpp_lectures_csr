#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <windows.h>

using namespace std;

class Sudoku {
    public:
        Sudoku();
        ~Sudoku();

        void run();
        void archivos();

    private:
        unsigned int **sudoku;
        const unsigned int sqrs = 9;
        const unsigned int limit = 3;

        unsigned int missingNumbers[9] = {0};
        unsigned int controlCount;

        string games[20];
        unsigned int gameCount;
        unsigned int totalZeros;
        float progress;

        void pause();

        void readSudoku(int currentGame); // insert data
        void printSudoku(); // print sudoku and solved sudoku
        void solveSudoku();
        void testSudoku();
        bool sudokuComplete();
        unsigned int getFstEmpty(unsigned int row, unsigned int column);
        void reviewRow(unsigned int row, unsigned int column);
        void reviewColumn(unsigned int row, unsigned int column);
        void reviewGrid(unsigned int row, unsigned int column);
        void printBar();

        // Files
        void readFile();

        unsigned int charToDigit(const char a);
};

#endif // SUDOKU_H_INCLUDED
