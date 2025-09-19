#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }

private:
    void backtrack(const string &s, int start, vector<string> &path, vector<vector<string>> &res)
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int end = start; end < s.size(); ++end)
        {
            if (isPalindrome(s, start, end))
            {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};