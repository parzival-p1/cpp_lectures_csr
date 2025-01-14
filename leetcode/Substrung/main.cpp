#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int i = 0, j = 0, index = -1;
        bool found = true;

        while (i < haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                index = i;
                j++;
                i++;
            }
            else
            {
                index = -1;
                j = 0;
            }
        }
        return index;
    }
};

int main()
{
    string uno = "mimamamemima";
    string dos = "mama";
    Solution solution;
    int index = solution.strStr(uno, dos);
    return 0;
}
