#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n;
        int globalMax = 1;
        for (int i = 0; i < n; ++i)
        {
            if (globalMax >= n - i)
                break;
            unordered_map<long long, int> slopeCount;
            int localMax = 0;
            for (int j = i + 1; j < n; ++j)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0)
                {
                    dy = 1;
                    dx = 0;
                }
                else if (dy == 0)
                {
                    dy = 0;
                    dx = 1;
                }
                else
                {
                    int g = gcd(abs(dy), abs(dx));
                    dy /= g;
                    dx /= g;
                    if (dx < 0)
                    {
                        dx = -dx;
                        dy = -dy;
                    }
                }
                long long key = (static_cast<long long>(dy) << 32) ^ (unsigned int)dx;
                localMax = max(localMax, ++slopeCount[key]);
            }
            globalMax = max(globalMax, localMax + 1);
        }
        return globalMax;
    }
};