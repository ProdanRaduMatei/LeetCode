#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        int n = num.size();
        for (int i = 1; i <= n / 2; ++i)
        {
            if (num[0] == '0' && i > 1)
                break;
            for (int j = i + 1; n - j >= max(i, j - i); ++j)
            {
                if (num[i] == '0' && j - i > 1)
                    break;
                string a = num.substr(0, i);
                string b = num.substr(i, j - i);
                if (isValid(a, b, num.substr(j)))
                    return true;
            }
        }
        return false;
    }

private:
    bool isValid(string a, string b, string rest)
    {
        while (!rest.empty())
        {
            string sum = addStrings(a, b);
            if (rest.substr(0, sum.size()) != sum)
                return false;
            rest = rest.substr(sum.size());
            a = b;
            b = sum;
        }
        return true;
    }

    string addStrings(string x, string y)
    {
        string res;
        int i = x.size() - 1, j = y.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += x[i--] - '0';
            if (j >= 0)
                sum += y[j--] - '0';
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};