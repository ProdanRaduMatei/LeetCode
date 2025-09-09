#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long long res = 1;
        int N = m + n - 2;
        int k = min(m - 1, n - 1);
        for (int i = 1; i <= k; ++i)
            res = res * (N - k + i) / i;
        return (int)res;
    }
};