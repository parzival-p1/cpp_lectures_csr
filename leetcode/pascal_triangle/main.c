#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    *returnSize = numRows;
    *returnColumnSizes = NULL;
    int **pascal = NULL;

    if (numRows > 0)
    {
        // Mem para almacenar las filas
        *returnColumnSizes = (int*)malloc(sizeof(int) * numRows); // se crea el array de columSizes con lo que traiga numRows
        pascal = (int**)malloc(sizeof(int*) * numRows); // aqui se crea la matriz

        int row = 1, col, count;

        while(row <= numRows)
        {
            pascal[row - 1] = (int*)malloc(sizeof(int) * row); // se crean las columnas de la fila o el array que va en la fila
            pascal[row - 1][0] = 1; // pon un 1 en la 1er pos
            if (row > 1)
            {
                count = 0;
                col = 1;
                while (col < row - 1) {
                    pascal[row - 1][col] = pascal[row - 2][count] + pascal[row - 2][count + 1];
                    col++;
                    count++;
                }
                pascal[row - 1][col] = 1; // pon un 1 la ultima pos
            }
            (*returnColumnSizes)[row - 1] = row;
            row++;
        }
    }
    return pascal;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    int **pascal = NULL;
    int *rowPascal = NULL;
    rowIndex++;

    if (rowIndex > 0)
    {
        // Mem para almacenar las filas
        pascal = (int**)malloc(sizeof(int*) * rowIndex); // aqui se crea la matriz

        int row = 1, col, count;

        while(row <= rowIndex)
        {
            pascal[row - 1] = (int*)malloc(sizeof(int) * row); // se crean las columnas de la fila o el array que va en la fila
            pascal[row - 1][0] = 1; // pon un 1 en la 1er pos
            if (row > 1)
            {
                count = 0;
                col = 1;
                while (col < row - 1) {
                    pascal[row - 1][col] = pascal[row - 2][count] + pascal[row - 2][count + 1];
                    col++;
                    count++;
                }
                pascal[row - 1][col] = 1; // pon un 1 la ultima pos
            }
            row++;
        }
        (*returnSize) = rowIndex;
        rowPascal = (int*)malloc(sizeof(int) * (rowIndex));
        memcpy(rowPascal, pascal[rowIndex - 1], rowIndex * sizeof(int));
        free(pascal);
    }
    return rowPascal;
}

int* getRow2(int rowIndex, int* returnSize)
{
    int i, k;
    int *result = (int*)malloc(sizeof(int) * rowIndex + 1);
    *returnSize = rowIndex + 1;
    long nfac = 1, kfac, nkfac;

    for (i = 2; i <= rowIndex; i++)
        nfac *= i;

    for (k = 0; k <= rowIndex; k++)
    {
        kfac = 1;
        for (i = 2; i <= k; i++)
            kfac *= i;
        nkfac = 1;

        for(i = 2; i <= (rowIndex - k); i++)
            nkfac *= i;

        result[k] = nfac / (kfac * nkfac);
    }
    return result;
}
/*
 * Tarea
 * Generar el triangulo de pascal completo hasta rowIndex, utilizando la formula del vato este
 * Crear nueva funciono con esta version para crear el triangulo de pascal
 *
 * Repasar colas de prioridad como son, como funcionan
 *
*/
int* getRow3(int rowIndex, int* returnSize)
{
    int *ptrArr = (int *)malloc((rowIndex + 1) * sizeof(int));
    *returnSize = rowIndex + 1;
    long int val=1;

    for(int i=0;i<=rowIndex;i++){
         //printf("%d",val);
         ptrArr[i]=val;
         val=val*(rowIndex-i)/(i+1);
         // 6 * (4 - 2) / (2  + 1);
    }
    return ptrArr;
}

int** generatePascal(int numRows, int* returnSize, int** returnColumnSizes)
{
    *returnSize = numRows;
    *returnColumnSizes = NULL;
    int **pascal = NULL; // Pascal es un conjunto de arreglos ptrArr

    if (numRows > 0)
    {
        // Mem para almacenar las filas
        *returnColumnSizes = (int*)malloc(sizeof(int) * numRows); // se crea el array de columSizes con lo que traiga numRows
        pascal = (int**)malloc(sizeof(int*) * numRows); // aqui se crea la matriz

        int row = 0;

        while(row < numRows)
        {
            pascal[row] = (int*)malloc(sizeof(int) * row + 1); // se crean las columnas de la fila o el array que va en la fila
            long int val = 1;

            for(int i = 0; i <= row; i++){
                 pascal[row][i] = val;
                 val = val * (row - i) / (i + 1); // se genera la fila
                 // 6 * (4 - 2) / (2  + 1);
            }
            (*returnColumnSizes)[row] = row + 1;
            row++;
        }
    }
    return pascal;
}

void printRow(int* result,int rowReturnSize)
{
    for (int i = 0; i < rowReturnSize; i++)
        printf("%i ", result[i]);
    printf("\n");

}

void print(int** result, int size, int* returnSizes)
{
    for (int i = 0; i < size; i++)
    {
        for (int j =0; j < returnSizes[i]; j++)
            printf("%i ", result[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int numRows = 10;
    // El triangulo de Pascal completo
    int returnSize;
    int* returnColumnSizes;
    int** result = generatePascal(numRows, &returnSize, &returnColumnSizes);
    print(result, returnSize, returnColumnSizes);
    // La ultima fila del triangulo de pascal
    int* rowResult = getRow3(9, &returnSize);

    printRow(rowResult, returnSize);
    free(result);
    free(returnColumnSizes);
    return 0;
}
