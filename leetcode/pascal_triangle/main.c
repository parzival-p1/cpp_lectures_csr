#include <stdio.h>
#include <stdlib.h>

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


        if (numRows > 1)
        {
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
                *returnColumnSizes[row - 1] = row;
                row++;
            }
        }
    }
    return pascal;
}

void print(int** result, int size, int* returnSizes)
{
    for (int i = 0; i < size; i++)
    {
        for (int j =0; j < returnSizes[i]; j++)
            printf("%i ", result[i][j]);
        printf("\n");
    }
}

int main()
{
    int numRows = 6;
    int returnSize;
    int* returnColumnSizes;
    int** result = generate(numRows, &returnSize, &returnColumnSizes);

    print(result, returnSize, returnColumnSizes);
    free(result);
    free(returnColumnSizes);
    return 0;
}
