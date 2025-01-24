#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    char *prefix = (char *)malloc(sizeof(char) * 200);

    if (strsSize == 1 || strlen(strs[0]) == 0)
        strcpy(prefix, strs[0]);
    else
    {
        int i = 1, j = 0;
        char c = strs[0][j];
        int exit = 0;

        while (i < strsSize && !exit)
        {
            if (c != strs[i][j])
                exit = 1;
            else if (i == strsSize - 1)
            {
                prefix[j] = c;
                i = 1;
                j++;
                if (j == strlen(strs[0]))
                    exit = 1;
                else
                    c = strs[0][j];
            }
            else
                i++;
        }
        prefix[j] = '\0';
    }
    return prefix;
}


int main()
{
    int wordSize = 3;
    char **words = (char **)malloc(wordSize * sizeof(char *));
    words[0] = (char *)malloc(strlen("") + 1);
    words[1] = (char *)malloc(strlen("") + 1);
    words[2] = (char *)malloc(strlen("") + 1);

    strcpy(words[0], "flower");
    strcpy(words[1], "flower");
    strcpy(words[2], "flower");

    char *prefix = longestCommonPrefix(words, wordSize);
    printf("El prefijo es: %s\n", prefix);
    free(words);
    free(prefix);
    return 0;
}
