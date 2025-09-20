#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i)
        {
            int a = i < v1.size() ? v1[i] : 0;
            int b = i < v2.size() ? v2[i] : 0;
            if (a < b)
                return -1;
            if (a > b)
                return 1;
        }
        return 0;
    }

private:
    vector<int> split(const string &s)
    {
        vector<int> res;
        int num = 0;
        for (int i = 0; i <= s.size(); ++i)
        {
            if (i == s.size() || s[i] == '.')
            {
                res.push_back(num);
                num = 0;
            }
            else
                num = num * 10 + (s[i] - '0');
        }
        return res;
    }
};