#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        vector<string> units = {"", "Thousand", "Million", "Billion"};
        string result = "";
        int i = 0;
        while (num > 0)
        {
            if (num % 1000 != 0)
            {
                result = helper(num % 1000) + (units[i].empty() ? "" : " " + units[i]) + (result.empty() ? "" : " " + result);
            }
            num /= 1000;
            i++;
        }
        return result;
    }

private:
    string helper(int num)
    {
        vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                  "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                  "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        if (num >= 100)
        {
            res += below20[num / 100] + " Hundred";
            if (num % 100 != 0)
                res += " " + helper(num % 100);
        }
        else if (num >= 20)
        {
            res += tens[num / 10];
            if (num % 10 != 0)
                res += " " + below20[num % 10];
        }
        else
        {
            res += below20[num];
        }
        return res;
    }
};