#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string t = s + "#" + rev;
        vector<int> pi(t.size(), 0);
        for (int i = 1; i < t.size(); ++i)
        {
            int j = pi[i - 1];
            while (j > 0 && t[i] != t[j])
                j = pi[j - 1];
            if (t[i] == t[j])
                ++j;
            pi[i] = j;
        }
        int palPerf = pi.back();
        string add = s.substr(palPerf);
        reverse(add.begin(), add.end());
        return add + s;
    }
};