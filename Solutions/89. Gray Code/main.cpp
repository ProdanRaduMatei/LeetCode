#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        int total = 1 << n; // 2^n
        vector<int> res;
        res.reserve(total);
        for (int i = 0; i < total; ++i)
        {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};