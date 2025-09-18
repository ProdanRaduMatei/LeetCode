#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return {};

        unordered_map<string, vector<string>> parents;
        unordered_set<string> curLevel{beginWord};
        bool found = false;

        while (!curLevel.empty() && !found)
        {
            for (auto &w : curLevel)
                dict.erase(w); // avoid revisiting
            unordered_set<string> nextLevel;
            for (auto &word : curLevel)
            {
                string cur = word;
                for (int i = 0; i < cur.size(); ++i)
                {
                    char old = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        if (c == old)
                            continue;
                        cur[i] = c;
                        if (dict.count(cur))
                        {
                            nextLevel.insert(cur);
                            parents[cur].push_back(word);
                            if (cur == endWord)
                                found = true;
                        }
                    }
                    cur[i] = old;
                }
            }
            curLevel.swap(nextLevel);
        }

        vector<vector<string>> res;
        if (found)
        {
            vector<string> path{endWord};
            backtrack(endWord, beginWord, parents, path, res);
        }
        return res;
    }

private:
    void backtrack(const string &word, const string &beginWord, unordered_map<string, vector<string>> &parents, vector<string> &path, vector<vector<string>> &res)
    {
        if (word == beginWord)
        {
            vector<string> seq = path;
            reverse(seq.begin(), seq.end());
            res.push_back(seq);
            return;
        }
        for (auto &p : parents[word])
        {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};