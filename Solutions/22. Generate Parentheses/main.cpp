#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> sol;
        string rez = "";
        backtrack(rez, 0, 0, n, sol);
        return sol;
    }

private:
    void backtrack(string &rez, int open, int close, int n, vector<string> &sol)
    {
        if (rez.size() == 2 * n)
        {
            sol.push_back(rez);
            return;
        }

        if (open < n)
        {
            rez.push_back('(');
            backtrack(rez, open + 1, close, n, sol);
            rez.pop_back();
        }

        if (close < open)
        {
            rez.push_back(')');
            backtrack(rez, open, close + 1, n, sol);
            rez.pop_back();
        }
    }
};