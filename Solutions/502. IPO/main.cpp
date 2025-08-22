#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i)
        {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> maxProfitHeap;
        int i = 0;
        int W = w;
        for (int iter = 0; iter < k; ++iter)
        {
            while (i < n && projects[i].first <= W)
            {
                maxProfitHeap.push(projects[i].second);
                ++i;
            }
            if (maxProfitHeap.empty())
                break;
            W += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        return W;
    }
};