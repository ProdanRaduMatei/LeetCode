#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return dfs(s, 0, dict, memo);
    }

private:
    vector<string> dfs(const string &s, int start, unordered_set<string> &dict, unordered_map<int, vector<string>> &memo)
    {
        if (memo.count(start))
            return memo[start];
        vector<string> res;
        if (start == s.size())
        {
            res.push_back("");
            return res;
        }
        for (int end = start + 1; end <= s.size(); ++end)
        {
            string word = s.substr(start, end - start);
            if (dict.count(word))
            {
                vector<string> suffixes = dfs(s, end, dict, memo);
                for (string &suffix : suffixes)
                {
                    if (suffix.empty())
                        res.push_back(word);
                    else
                        res.push_back(word + " " + suffix);
                }
            }
        }
        return memo[start] = res;
    }
};