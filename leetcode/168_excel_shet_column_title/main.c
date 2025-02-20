#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* convertToTitle1(int columnNumber)
{
    int numChars = (columnNumber == 1) ? 1 : (int)floor(log(columnNumber - 1) / log(26)) + 1;
    char* column = (char*)malloc(sizeof(char) * numChars + 1);
    int chunk = columnNumber;

    // Como tratar todas las letras como si fueran la ultima, que todas apliquen lo mismo
    // que le tiene que pasar a chunk? para que la pos donde estoy se comporte como el ultimo char, si lo dividio o mod de 26 que da??

    // MUEVE CHUNK
    // columnNumber = 678; res = "AAB"
    // cuanto debe vale chunk para sacar la 1a A ?
    // cuanto debe valer chunk para sacar 2a A ?
    // cuanto debeb valer chunk para sacar la B?
    printf("numChars = %i\n", numChars);
    for (int i = numChars - 1; i >= 0; i--)
    {
        column[i] = 64 + (chunk - 1) % 26 + 1;
        chunk = (chunk - 1) / 26;
    }

    column[numChars] = '\0';
    return column;
}

char* convertToTitle(int columnNumber)
{
    char *column = (char *)malloc(sizeof(char) * 20);
    char *index = &column[19];
    char *result;
    column[19] = '\0';
    int chunk = columnNumber;

    while(chunk > 0)
    {
        index--;
        *index = 64 + (chunk - 1) % 26 + 1;
        chunk = (chunk - 1) / 26;
    }
    result = (char *)malloc(sizeof(char) * strlen(index));
    strcpy(result, index);
    free(column);
    return result;
}

int main()
{
    char* result;
    int column = 18279;
   //printf("%i\n", (26 -  1) % 26);

    result = convertToTitle(column);
    printf("\n%s\n", result);
    free(result);
    return 0;
}
