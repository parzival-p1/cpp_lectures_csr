#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* convertToTitle(int columnNumber)
{
    int numChars = (int)floor(log(columnNumber) / log(26)) + 1;
    char* column = (char*)malloc(sizeof(char) * numChars + 1);
    int chunk = columnNumber;
    // Como tratar todas las letras como si fueran la ultima, que todas apliquen lo mismo
    // que le tiene que pasar a chunk? para que la pos donde estoy se comporte como el ultimo char, si lo dividio o mod de 26 que da??

    // MUEVE CHUNK
    // columnNumber = 678; res = "AAB"
    // cuanto debe vale chunk para sacar la 1a A ?
    // cuanto debe valer chunk para sacar 2a A ?
    // cuanto debeb valer chunk para sacar la B?
    for (int i = 0; i < numChars; i++)
    {
        column[i] = 64 + chunk % 26;
    }

    column[numChars] = '\0';
    return column;
}

/*

func convertToTitle(columnNumber):
    resultado = ""  // String vacío para construir el resultado

    mientras columnNumber > 0:
        columnNumber = columnNumber - 1  // Ajuste por la base 1 en Excel
        residuo = columnNumber % 26  // Obtener la letra correspondiente
        letra = convertir residuo a carácter (residuo + 'A')  // 'A' = 0
        resultado = letra + resultado  // Agregar al inicio del resultado
        columnNumber = columnNumber % 26  // Reducir el número

    retornar resultado

 Z A Z
 Z B A
 T Z Z
 U A A
*/
int main()
{
    char* result;
    int column = 1;
    printf("%i\n", (26 -  1) % 26);

    result = convertToTitle(column);
    printf("\n%s\n", result);
    free(result);
    return 0;
}
