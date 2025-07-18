#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> res;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                res.push(c);
            else
            {
                if (res.empty() || res.top() != match[c])
                    return false;
                res.pop();
            }
        }
        return res.empty();
    }
};