#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        if (nums[mid] < target)
            return mid + 1;
        else
            return mid;
    }
};

int main()
{
    vector<int> v = {1, 3, 5, 6};
    int target = 2;
    Solution s;
    cout << s.searchInsert(v, target);
    return 0;
}
