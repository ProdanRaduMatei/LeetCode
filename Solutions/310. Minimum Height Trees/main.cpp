#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n <= 2)
        {
            vector<int> ans(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        adj.reserve(n);
        for (auto &e : edges)
        {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            ++deg[a];
            ++deg[b];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (deg[i] == 1)
                q.push(i);
        int remaining = n;
        while (remaining > 2)
        {
            int layer = q.size();
            remaining -= layer;
            while (layer--)
            {
                int leaf = q.front();
                q.pop();
                for (int nei : adj[leaf])
                {
                    if (--deg[nei] == 1)
                        q.push(nei);
                }
            }
        }
        vector<int> centers;
        while (!q.empty())
        {
            centers.push_back(q.front());
            q.pop();
        }
        return centers;
    }
};