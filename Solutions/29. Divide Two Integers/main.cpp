#include <climits>
#include <cstdlib>
#include <cmath>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long result = 0;
        while (a >= b)
        {
            long long temp = b, multiple = 1;
            while ((temp << 1) <= a)
            {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }
        if (negative)
            result = -result;
        if (result > INT_MAX)
            return INT_MAX;
        if (result < INT_MIN)
            return INT_MIN;
        return (int)result;
    }
};