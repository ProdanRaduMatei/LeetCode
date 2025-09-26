#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression)
    {
        if (memo.count(expression))
            return memo[expression];
        vector<int> results;
        for (int i = 0; i < expression.size(); i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                string leftExp = expression.substr(0, i);
                string rightExp = expression.substr(i + 1);
                vector<int> left = diffWaysToCompute(leftExp);
                vector<int> right = diffWaysToCompute(rightExp);
                for (int l : left)
                {
                    for (int r : right)
                    {
                        if (c == '+')
                            results.push_back(l + r);
                        else if (c == '-')
                            results.push_back(l - r);
                        else if (c == '*')
                            results.push_back(l * r);
                    }
                }
            }
        }
        if (results.empty())
        {
            results.push_back(stoi(expression));
        }
        return memo[expression] = results;
    }
};