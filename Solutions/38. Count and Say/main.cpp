#include <string>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";
        for (int i = 2; i <= n; i++)
        {
            string current = "";
            int count = 1;
            for (int j = 1; j <= result.size(); j++)
            {
                if (j < result.size() && result[j] == result[j - 1])
                    count++;
                else
                {
                    current += to_string(count) + result[j - 1];
                    count = 1;
                }
            }
            result = current;
        }
        return result;
    }
};