#include <string>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int p = 0;
        bool sign = false;
        while (s[p] == ' ')
            ++p;
        if (s[p] == '-')
        {
            sign = true;
            ++p;
        }
        else if (s[p] == '+')
            ++p;
        int result = 0;
        while (s[p] >= '0' && s[p] <= '9')
        {
            int d = s[p] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && d > 7))
            {
                if (sign == true)
                    return INT_MIN;
                return INT_MAX;
            }
            result = result * 10 + d;
            ++p;
        }
        if (sign == true)
            result *= -1;
        return result;
    }
};