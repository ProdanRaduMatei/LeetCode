#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{

    int x = 0, count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[x] == nums[i] && count < 1)
        {
            count++;
            nums[++x] = nums[i];
        }
        else if (nums[x] != nums[i])
        {
            count = 0;
            nums[++x] = nums[i];
        }
    }

    return x + 1;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int newLength = removeDuplicates(nums);

    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; ++i)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}