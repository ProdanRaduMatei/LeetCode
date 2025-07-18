#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void backtrack(string &current, int index, const string &digits, const unordered_map<char, string> &phone, vector<string> &res)
    {
        if (index == digits.size())
        {
            res.push_back(current);
            return;
        }
        for (char c : phone.at(digits[index]))
        {
            current.push_back(c);
            backtrack(current, index + 1, digits, phone, res);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        unordered_map<char, string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        string current;
        backtrack(current, 0, digits, phone, res);
        return res;
    }
};