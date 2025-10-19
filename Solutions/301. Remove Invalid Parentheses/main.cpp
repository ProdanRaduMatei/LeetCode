#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> res;
        if (s.empty())
            return {""};
        auto isValid = [&](const string &t) -> bool
        {
            int bal = 0;
            for (char c : t)
            {
                if (c == '(')
                    ++bal;
                else if (c == ')')
                {
                    if (bal == 0)
                        return false;
                    --bal;
                }
            }
            return bal == 0;
        };
        queue<string> q;
        unordered_set<string> seen;
        q.push(s);
        seen.insert(s);
        bool found = false;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                string cur = q.front();
                q.pop();
                if (isValid(cur))
                {
                    res.push_back(cur);
                    found = true;
                }
                if (found)
                    continue;
                for (int j = 0; j < (int)cur.size(); ++j)
                {
                    if (cur[j] != '(' && cur[j] != ')')
                        continue;
                    string nxt = cur.substr(0, j) + cur.substr(j + 1);
                    if (!seen.count(nxt))
                    {
                        seen.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            if (found)
                break;
        }
        if (res.empty() && all_of(s.begin(), s.end(), [](char c)
                                  { return c != '(' && c != ')'; }))
            res.push_back(s);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};