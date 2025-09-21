#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        if (n <= 10)
            return {};
        unordered_set<string> seen, repeated;
        vector<string> result;
        for (int i = 0; i + 10 <= n; ++i)
        {
            string sub = s.substr(i, 10);
            if (seen.count(sub))
                repeated.insert(sub);
            else
                seen.insert(sub);
        }
        return vector<string>(repeated.begin(), repeated.end());
    }
};