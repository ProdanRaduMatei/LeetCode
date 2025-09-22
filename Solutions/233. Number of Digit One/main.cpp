#include <iostream>

using namespace std;

class Solution
{
public:
    int countDigitOne(int n)
    {
        long long count = 0;
        long long factor = 1;
        while (factor <= n)
        {
            long long lower = n % factor;
            long long current = (n / factor) % 10;
            long long higher = n / (factor * 10);
            if (current == 0)
                count += higher * factor;
            else if (current == 1)
                count += higher * factor + lower + 1;
            else
                count += (higher + 1) * factor;
            factor *= 10;
        }
        return count;
    }
};