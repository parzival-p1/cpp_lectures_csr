#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestCommonPrefix(char** strs, int strsSize) {

    char *prefix = (char *)malloc(sizeof(char) * 200);
    sprintf(prefix, "hola");

    for (int i = 0; i < strsSize; i++)
    {
        for (int j = 0; j < strlen(strs[i]); j++)
        {
            printf("strs[%i][%i] = %c", i, j, strs[i][j]);
        }
    }
    return prefix;
}

int main()
{
    char **words = {"flower","flow","flight"};
    char *prefix = longestCommonPrefix(words, 3);
    printf("El prefijo es: %s ", prefix);
    free(prefix);
    return 0;
}
