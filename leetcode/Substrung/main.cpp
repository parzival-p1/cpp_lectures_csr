#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        int i = 0, j = 0, index = -1;
        bool reset = false;
        int haystackLen = haystack.size();
        int needleLen = needle.size();

        while (i < haystackLen && j < needleLen)
        { // h = edif n = dif
            if (haystack[i] == needle[j])
            {
                if (!reset)
                    index = i;
                j++;
                i++;
                reset = true;
            }
            else if(reset)
            {
                i = index + 1;
                index = -1;
                j = 0;
                reset = false;
            }
            else
                i++;
        }
        if (j < needleLen)
            return -1;
        return index;
    }
};

int main()
{
    string uno = "mississippi";
    string dos = "issip";
    Solution solution;
    int index = solution.strStr(uno, dos);
    cout<<"1: "<<uno<<endl<<"2: "<<dos<<endl<<"Indice: "<<index;
    return 0;
}
