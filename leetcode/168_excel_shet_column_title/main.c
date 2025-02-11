#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* convertToTitle(int columnNumber)
{
    int numChars = (int)ceil(log(columnNumber) / log(26));
    char* column = (char*)malloc(sizeof(char) * numChars + 1);

    // TAREA
    // COMO CALCULAR LAS LETRAS?
    // EJ. COL 23 QUE LETRA REGRESA? SI 26 = Z, 23 = W
    // USAR % 26 ascii tiene relacion? puedes calcularlo?
    // ideas

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
    int column = 5;
    //result = convertToTitle(column);
    float x = log(23) / log(26);
    int y = ceil(x);
    printf("%i\n", (int)ceil(x));
    printf("%i\n", (int)ceil(log(500) / log(26)));
    printf("%i\n", (int)ceil(log(1500) / log(26)));
    printf("%i\n", (int)ceil(log(345838) / log(26)));

    result = convertToTitle(column);
    printf("\n%s\n", result);
    free(result);
    return 0;
}
