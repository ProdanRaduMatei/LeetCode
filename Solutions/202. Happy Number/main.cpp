#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int sumOfSquares(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = sumOfSquares(n);
        while (slow != fast)
        {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
        return slow == 1;
    }
};