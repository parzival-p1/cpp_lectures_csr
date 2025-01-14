#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        int pCount = 0;
        int iSize = s.size();
        if (iSize >= 1)
        {
            char pila[iSize];
            bool check = false;

            while(i < iSize && !check)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                        pila[pCount] = s[i];
                        pCount++;
                }
                else if (pCount > 0) {
                    if (s[i] == ')' && pila[pCount - 1] == '(')
                        pCount--;
                    else if (s[i] == ']' && pila[pCount - 1] == '[')
                        pCount--;
                    else if (s[i] == '}' && pila[pCount - 1] == '{')
                        pCount--;
                    else
                        check = true;
                }
                else
                    check = true;
                i++;
            }
            if (pCount == 0 && check == false)
                return true;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    bool valid = solution.isValid("]");
    cout << valid << endl;
    return 0;
}
