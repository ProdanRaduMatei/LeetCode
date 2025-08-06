#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene))
            return -1;
        queue<string> q;
        unordered_set<string> visited;
        q.push(startGene);
        visited.insert(startGene);
        vector<char> choices = {'A', 'C', 'G', 'T'};
        int steps = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string gene = q.front();
                q.pop();
                if (gene == endGene)
                    return steps;
                for (int i = 0; i < 8; i++)
                {
                    char original = gene[i];
                    for (char c : choices)
                    {
                        if (c == original)
                            continue;
                        gene[i] = c;
                        if (bankSet.count(gene) && !visited.count(gene))
                        {
                            visited.insert(gene);
                            q.push(gene);
                        }
                    }
                    gene[i] = original;
                }
            }
            steps++;
        }
        return -1;
    }
};