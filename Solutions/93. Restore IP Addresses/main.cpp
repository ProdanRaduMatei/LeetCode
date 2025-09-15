#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string &s, int start, vector<string> &path, vector<string> &result)
    {
        if (path.size() == 4)
        {
            if (start == s.size())
            {
                result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }
        for (int len = 1; len <= 3; len++)
        {
            if (start + len > s.size())
                break;
            string part = s.substr(start, len);
            if (part.size() > 1 && part[0] == '0')
                continue;
            int val = stoi(part);
            if (val > 255)
                continue;
            path.push_back(part);
            backtrack(s, start + len, path, result);
            path.pop_back();
        }
    }
};