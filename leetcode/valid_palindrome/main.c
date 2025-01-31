#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s)
{
    int i = 0, j = 0;
    int len = strlen(s);
    bool stop = false;
    char string [len + 1];

    while(i < len && !stop)
    {
        if (isupper(s[i]) > 0)
        {
            string[j] = tolower(s[i]);
            j++;
        }
        else if (isalnum(s[i]) != 0)
        {
            string[j] = s[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';
    printf("%s\n", string);

    i = 0;
    j = strlen(string) - 1;

    bool exit = false;

    while (i < j && !exit)
    {
        if (string[i] != string[j])
            exit = true;
        else {
            i++;
            j--;
        }
    }
    return !exit;
}

int main()
{
    if (isPalindrome("a"))
        printf("Si es palindromo");
    else
        printf("No es palindromo");

    return 0;
}
