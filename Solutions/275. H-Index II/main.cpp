#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int left = 0, right = n - 1;
        int h = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int papers = n - mid;
            if (citations[mid] >= papers)
            {
                h = papers;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return h;
    }
};