#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
        backtrack(num, target, 0, 0, 0, "", res);
        return res;
    }

private:
    void backtrack(const string &num, long target, int pos, long val, long last, string expr, vector<string> &res)
    {
        if (pos == num.size())
        {
            if (val == target)
                res.push_back(expr);
            return;
        }
        for (int i = pos; i < num.size(); ++i)
        {
            if (i != pos && num[pos] == '0')
                break;
            string part = num.substr(pos, i - pos + 1);
            long cur = stol(part);
            if (pos == 0)
                backtrack(num, target, i + 1, cur, cur, part, res);
            else
            {
                backtrack(num, target, i + 1, val + cur, cur, expr + "+" + part, res);
                backtrack(num, target, i + 1, val - cur, -cur, expr + "-" + part, res);
                backtrack(num, target, i + 1, val - last + last * cur, last * cur, expr + "*" + part, res);
            }
        }
    }
};