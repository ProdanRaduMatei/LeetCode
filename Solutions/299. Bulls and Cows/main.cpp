#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0;
        vector<int> sCount(10, 0), gCount(10, 0);
        for (int i = 0; i < secret.size(); i++)
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                sCount[secret[i] - '0']++;
                gCount[guess[i] - '0']++;
            }
        for (int d = 0; d < 10; d++)
            cows += min(sCount[d], gCount[d]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};