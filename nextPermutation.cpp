#include <bits/stdc++.h>
using namespace std;

// for loop
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i, j;

    for (i = n - 2; i >= 0; i--)
        if (nums[i] < nums[i + 1])
            break;

    if (i < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (nums[j] > nums[i])
                break;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
}

// while loop
void nextPermutation1(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return;

    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0)
    {
        int j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
    else
        reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 2, 3};
    nextPermutation(nums);
    for (int x : nums)
        cout << x << " ";
    return 0;
}
