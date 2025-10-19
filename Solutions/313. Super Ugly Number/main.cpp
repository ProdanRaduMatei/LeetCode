#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = (int)primes.size();
        vector<int> ugly(n);
        vector<int> idx(k, 0);
        vector<long long> cand(k);
        ugly[0] = 1;
        for (int j = 0; j < k; ++j)
            cand[j] = primes[j];
        for (int i = 1; i < n; ++i)
        {
            long long mn = cand[0];
            for (int j = 1; j < k; ++j)
                mn = min(mn, cand[j]);
            ugly[i] = (int)mn;
            for (int j = 0; j < k; ++j)
            {
                if (cand[j] == mn)
                {
                    ++idx[j];
                    cand[j] = (long long)primes[j] * ugly[idx[j]];
                }
            }
        }
        return ugly[n - 1];
    }
};