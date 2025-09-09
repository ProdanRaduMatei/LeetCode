#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        int n = s.size();
        int i = 0;
        if (i < n && (s[i] == '+' || s[i] == '-'))
            i++;
        bool isNumeric = false;
        while (i < n && isdigit(s[i]))
        {
            i++;
            isNumeric = true;
        }
        if (i < n && s[i] == '.')
        {
            i++;
            while (i < n && isdigit(s[i]))
            {
                i++;
                isNumeric = true;
            }
        }
        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E'))
        {
            i++;
            isNumeric = false;
            if (i < n && (s[i] == '+' || s[i] == '-'))
                i++;
            while (i < n && isdigit(s[i]))
            {
                i++;
                isNumeric = true;
            }
        }
        return isNumeric && i == n;
    }
};