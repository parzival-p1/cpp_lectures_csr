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
    char string [len];

    while(i < len && !stop)
    {
        if (isupper(s[i]) > 0)
        {
            string[j] = tolower(s[i]);
            j++;
        }
        else if (isalpha(s[i]) != 0)
        {
            string[j] = s[i];
            j++;
        }
        i++;
    }
    string[j] = '\0';
    printf("%s\n", string);
}

int main()
{
    if (isPalindrome("A man, a plan, a canal: Panama"))
        printf("Si es palindromo");
    else
        printf("No es palindromo");

    return 0;
}
